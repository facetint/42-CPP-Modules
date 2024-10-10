/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:46:33 by facetint          #+#    #+#             */
/*   Updated: 2024/10/10 19:46:34 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string ft_replace(std::string src, std::string find, std::string rep)
{
    size_t pos = src.find(find);
    std::string ret_val;

    while (pos != std::string::npos)
    {
        ret_val = src.substr(0, pos);
        ret_val += rep;
        ret_val += src.substr(pos + find.length(), src.length() - (pos + find.length()));
        src = ret_val;
        pos = src.find(find);
    }
    if (ret_val.length() == 0 && ret_val.empty())
        return (src);
    return (ret_val);
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string s1 = av[2];
        std::ifstream in_file(av[1]);
        if (!in_file)
        {
            std::cout << "File not found" << std::endl;
            return 1;
        }
        std::string s2 = av[3];
        std::string file = av[1];
        std::string line;
        std::ofstream output_file(file + ".replace");
        if (!in_file)
        {
            std::cout << "File not found" << std::endl;
            return 1;
        }
        while (std::getline(in_file, line))
        {
            line = ft_replace(line, s1, s2);
            output_file << line << std::endl;
        }
        in_file.close();
        output_file.close();
    }
    else
        std::cout << "Wrong Arguments" << std::endl;
}