#include "PmergeMe.hpp"
#include <typeinfo>
template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::printContainer()
{
    size_t i = 0;
    typename NumberContainer::iterator it;
    for (it = container.begin(); it != container.end(); ++it , i++)
    {
        std::cout << "container[" << i << "]: " << *it << " ";
    }
    std::cout << std::endl;
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::printPairs(Pair &pairs)
{
    size_t i = 0;
    typename Pair::iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it , i++)
    {
        std::cout << "pairs[" << i << "] " << it->first << " " << it->second << std::endl;
    }
    std::cout << std::endl;
}

template <class NumberContainer, class Pair>
FordJhonson<NumberContainer, Pair>::FordJhonson()
{
}

template <class NumberContainer, class Pair>
FordJhonson<NumberContainer, Pair>::~FordJhonson()
{
}

template <class NumberContainer, class Pair>
FordJhonson<NumberContainer, Pair>::FordJhonson(const FordJhonson &other)
{
    container = other.container;
   
}
template <class NumberContainer, class Pair>
FordJhonson<NumberContainer, Pair> &FordJhonson<NumberContainer, Pair>::operator=(const FordJhonson &other)
{
    if (this != &other)
    {
        container = other.container;
      
    }
    return *this;
}

template <class NumberContainer, class Pair>
NumberContainer const &FordJhonson<NumberContainer, Pair>::getSequence() const
{
    return container;
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::printBefore()
{
    typename NumberContainer::const_iterator it;
    std::cout << "Before : ";
    for (it = getSequence().begin(); it != getSequence().end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::printAfter()
{
    typename NumberContainer::const_iterator it;
    std::cout << "After : ";
    for (it = mainChain.begin(); it != mainChain.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::parseAndSetSequence(int ac, char **av)
{
    int num;
    char *ptr;

    if (ac < 2)
    {
        throw EmptyContainerException();
    }

    for (int i = 1; i < ac; i++)
    {
        num = std::strtol(av[i], &ptr, 10);
        if (*ptr != '\0' || num < 0)
        {
            throw InvalidInputException();
        }
        container.push_back(num);
    }
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::groupPairs(Pair &pairs)
{
    typename NumberContainer::const_iterator it = container.begin();
    while (it != container.end())
    {
        int first = *it;
        ++it;
        if (it != container.end())
        {
            int second = *it;
            ++it;

            if (first < second)
                std::swap(first, second);

            pairs.push_back(std::make_pair(first, second));
        }
    }
    //printPairs(pairs);
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::sortPairs(Pair &pairs)
{
    mergeSort(pairs.begin(), pairs.end());
    // std::cout << "after merge sort pairs: " << std::endl;
    // printPairs(pairs);

    typename Pair::const_iterator it = pairs.begin();


    for (; it != pairs.end(); ++it)
    {
        mainChain.push_back(it->first);
        pend.push_back(it->second);
    }
    // std::cout << "mainChain: ";
    // for (typename NumberContainer::const_iterator it = mainChain.begin(); it != mainChain.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "pend: ";
    // for (typename NumberContainer::const_iterator it = pend.begin(); it != pend.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::merge(typename Pair::iterator begin, typename Pair::iterator mid, typename Pair::iterator end)
{
    Pair temp;

    typename Pair::iterator left = begin;
    typename Pair::iterator right = mid;

    while (left != mid && right != end)
    {
        if (left->first < right->first)
        {
            temp.push_back(*left);
            ++left;
        }
        else
        {
            temp.push_back(*right);
            ++right;
        }
    }

    while (left != mid)
    {
        temp.push_back(*left);
        ++left;
    }
    while (right != end)
    {
        temp.push_back(*right);
        ++right;
    }

    typename Pair::iterator it = begin;
    typename Pair::iterator temp_it = temp.begin();
    while (temp_it != temp.end())
    {
        *it = *temp_it;
        ++it;
        ++temp_it;
    }
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::mergeSort(typename Pair::iterator begin, typename Pair::iterator end)
{
    if (std::distance(begin, end) < 1)
        return;
    typename Pair::iterator mid = begin + std::distance(begin, end) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::fordJohnson()
{
    if (this->container.empty())
    {             
        throw EmptyContainerException();
    }
    groupPairs(pairs);
    sortPairs(pairs);
    insertionSort();
}

template <class NumberContainer, class Pair>
NumberContainer FordJhonson<NumberContainer, Pair>::generateJacobsthalNumbers(unsigned int size)
{
    NumberContainer retVal;
    NumberContainer jacobsthalList;
    unsigned int j = 2;

    if (size < 3)
    {
        j = 0;
        while (j < size)
        {
            retVal.push_back(j);
            j++;
        }
        return (retVal);
    }
    retVal.push_back(1);
    retVal.push_back(3);
    jacobsthalList.push_back(1);
    jacobsthalList.push_back(3);

    while (true)
    {
        unsigned int val = (retVal[j - 1]) + (retVal[j - 2] * 2); // retval[2 -1] = retval[1] = 3 retvsl[0] = 1 *2 2, 2 + 3 = 5
        if (val > size)
            break;
        jacobsthalList.push_back(val);
        retVal.push_back(val);
        std::cout << val << std::endl;
        j++;
    }
    j = 0;
    while (j < jacobsthalList.size())
    {
        jacobsthalList[j] -= 1;
        retVal[j] -= 1;
        j++;
    }
    
    j = 0;
    while (j < size)
    {
        if (std::find(jacobsthalList.begin(), jacobsthalList.end(), j) == jacobsthalList.end())
            retVal.push_back(j);
        j++;
    }
    return (retVal);

}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::insertionSort()
{
    if (container.size() % 2 != 0)
    {
        pend.push_back(container.back());
    }
    this->positions = generateJacobsthalNumbers(pend.size());

    for (typename NumberContainer::iterator it = positions.begin(); it != positions.end(); ++it)
    {
        //std::cout << "position: " << *it << std::endl;  // 
        if (*it >= (int)pend.size())
            continue;
    
        int value = pend[*it];
        int left = 0;
        int right = mainChain.size();

        //std::cout << "value: " << value << std::endl;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (value < mainChain[mid])
                right = mid;
            else
                left = mid + 1;
        }
    
        mainChain.insert(mainChain.begin() + left, value);
    }
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::printTime(size_t elementCount, clock_t end)
{
    std::string containerType;

    if (typeid(NumberContainer) == typeid(std::vector<int>))
        containerType = "std::vector";
    else if (typeid(NumberContainer) == typeid(std::deque<int>))
        containerType = "std::deque";
    std::cout << "Time to process a range of " << elementCount << " elements with " << containerType << " : " << (float)end * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
}

template <class NumberContainer, class Pair>
void FordJhonson<NumberContainer, Pair>::process(int ac, char **av)
{
    parseAndSetSequence(ac, av);
    clock_t start = clock();
    fordJohnson();
    clock_t end = clock() - start;
    printTime(ac - 1, end);
}
