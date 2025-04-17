#include "PmergeMe.hpp"
#include <typeinfo>

// void FordJohnson<Container, Pair>::printContainer()
// {
//     size_t i = 0;
//     typename Container::iterator it;
//     for (it = numbers.begin(); it != numbers.end(); ++it , i++)
//     {
//         std::cout << "numbers[" << i << "]: " << *it << " ";
//     }
//     std::cout << std::endl;
// }

// template <class Container, class Pair>
// void FordJohnson<Container, Pair>::printPairs(Pair &pairs)
// {
//     size_t i = 0;
//     typename Pair::iterator it;
//     for (it = pairs.begin(); it != pairs.end(); ++it , i++)
//     {
//         std::cout << "pairs[" << i << "] " << it->first << " " << it->second << std::endl;
//     }
//     std::cout << std::endl;
// }

template <class Container, class Pair>
FordJohnson<Container, Pair>::FordJohnson()
{
}

template <class Container, class Pair>
FordJohnson<Container, Pair>::~FordJohnson()
{
}

template <class Container, class Pair>
FordJohnson<Container, Pair>::FordJohnson(const FordJohnson &other)
{
    numbers = other.numbers;
   
}
template <class Container, class Pair>
FordJohnson<Container, Pair> &FordJohnson<Container, Pair>::operator=(const FordJohnson &other)
{
    if (this != &other)
    {
        numbers = other.numbers;
      
    }
    return *this;
}

template <class Container, class Pair>
Container const &FordJohnson<Container, Pair>::getSequence() const
{
    return numbers;
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::printBefore()
{
    typename Container::const_iterator it;
    std::cout << "Before : ";
    for (it = getSequence().begin(); it != getSequence().end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::printAfter()
{
    typename Container::const_iterator it;
    std::cout << "After : ";
    for (it = sortedSequence.begin(); it != sortedSequence.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::parseInputArguments(int ac, char **av)
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
        numbers.push_back(num);
    }
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::groupPairs(Pair &pairs)
{
    typename Container::const_iterator it = numbers.begin();
    while (it != numbers.end())
    {
        int first = *it;
        ++it;
        if (it != numbers.end())
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

template <class Container, class Pair>
void FordJohnson<Container, Pair>::sortPairs(Pair &pairs)
{
    mergeSort(pairs.begin(), pairs.end());
    // std::cout << "after merge sort pairs: " << std::endl;
    // printPairs(pairs);

    typename Pair::const_iterator it = pairs.begin();


    for (; it != pairs.end(); ++it)
    {
        sortedSequence.push_back(it->first);
        toInsert.push_back(it->second);
    }
    // std::cout << "sortedSequence: ";
    // for (typename Container::const_iterator it = sortedSequence.begin(); it != sortedSequence.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "toInsert: ";
    // for (typename Container::const_iterator it = toInsert.begin(); it != toInsert.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::merge(typename Pair::iterator begin, typename Pair::iterator mid, typename Pair::iterator end)
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

template <class Container, class Pair>
void FordJohnson<Container, Pair>::mergeSort(typename Pair::iterator begin, typename Pair::iterator end)
{
    if (std::distance(begin, end) <= 1)
        return;

    typename Pair::iterator mid = begin + (end - begin) / 2;
    FordJohnson<Container, Pair>::mergeSort(begin, mid);
    FordJohnson<Container, Pair>::mergeSort(mid, end);
    FordJohnson<Container, Pair>::merge(begin, mid, end);
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::fordJohnson()
{
    if (this->numbers.empty())
    {             
        throw EmptyContainerException();
    }
    groupPairs(pairs);
    sortPairs(pairs);
    insertionSort();
}

template <class Container, class Pair>
Container FordJohnson<Container, Pair>::generateJacobsthalPositions(unsigned int size)
{
    Container positions;
    Container jacobsthalBase;
    unsigned int j = 2;

    if (size < 3)
    {
        j = 0;
        while (j < size)
        {
            positions.push_back(j);
            j++;
        }
        return (positions);
    }
    positions.push_back(1);
    positions.push_back(3);
    jacobsthalBase.push_back(1);
    jacobsthalBase.push_back(3);

    while (true)
    {
        unsigned int nextValue = (positions[j - 1]) + (positions[j - 2] * 2);
        if (nextValue > size)
            break;
        jacobsthalBase.push_back(nextValue);
        positions.push_back(nextValue);
        j++;
    }
    j = 0;
    while (j < jacobsthalBase.size())
    {
        jacobsthalBase[j] -= 1;
        positions[j] -= 1;
        j++;
    }
    
    j = 0;
    while (j < size)
    {
        if (std::find(jacobsthalBase.begin(), jacobsthalBase.end(), j) == jacobsthalBase.end())
            positions.push_back(j);
        j++;
    }
    return (positions);

}

template <class Container, class Pair>
typename Container::iterator FordJohnson<Container, Pair>::binarySearch(Container& numbers, int value)
{
    typename Container::iterator left = numbers.begin();
    typename Container::iterator right = numbers.end();

    while (left < right)
    {
        typename Container::iterator mid = left + (right - left) / 2;
        if (value < *mid)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::insertionSort()
{
    if (this->toInsert.empty())
        return;

    this->positions = generateJacobsthalPositions(toInsert.size());

    for (typename Container::iterator posIt = positions.begin(); posIt != positions.end(); ++posIt)
    {
        unsigned int index = *posIt;

        if (index >= toInsert.size())
            continue;

        int valueToInsert = toInsert[index];

        typename Container::iterator insertPos = binarySearch(sortedSequence, valueToInsert);
        sortedSequence.insert(insertPos, valueToInsert);
    }
    if (numbers.size() % 2 != 0)
    {
        int lastValue = getSequence().back();
        typename Container::iterator insertPos = binarySearch(sortedSequence, lastValue);
        sortedSequence.insert(insertPos, lastValue);
    }
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::printTime(size_t elementCount, clock_t duration)
{
    std::string containerType;

    if (typeid(Container) == typeid(std::vector<int>))
        containerType = "std::vector";
    else if (typeid(Container) == typeid(std::deque<int>))
        containerType = "std::deque";
    std::cout << "Time to process a range of " << elementCount << " elements with " << containerType << " : " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
}

template <class Container, class Pair>
void FordJohnson<Container, Pair>::run(int ac, char **av)
{
    parseInputArguments(ac, av);
    clock_t start = clock();
    fordJohnson();
    clock_t duration = clock() - start;
    printTime(ac - 1, duration);
}
