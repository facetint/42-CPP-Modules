/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:49:53 by fatmanurcet       #+#    #+#             */
/*   Updated: 2024/10/05 20:50:50 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>

int main(int ac, char **av)
{
    int     i;
    int     j;

    if (ac == 1)
    {
        std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE " << std::endl;
        return (1);
    }
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            av[i][j] = toupper(av[i][j]);
            j++;
        }
        std::cout << av[i] << std::flush;
        i++;
    }
    std::cout << std::endl;
    return (0);
}
