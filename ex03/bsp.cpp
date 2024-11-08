/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:59:22 by facetint          #+#    #+#             */
/*   Updated: 2024/10/22 13:59:23 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed determinant(Point a, Point b, Point c)
{
    return a.getX() * (b.getY() - c.getY()) +
           b.getX() * (c.getY() - a.getY()) +
           c.getX() * (a.getY() - b.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed det = determinant(a, b, c);
    Fixed det1 = determinant(point, a, b);
    Fixed det2 = determinant(point, b, c);
    Fixed det3 = determinant(point, c, a);

    return (det == 0) || ((det1 > 0 && det2 > 0 && det3 > 0) || (det1 < 0 && det2 < 0 && det3 < 0));
}
