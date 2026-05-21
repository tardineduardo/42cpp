/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:00:30 by eduribei          #+#    #+#             */
/*   Updated: 2026/05/20 19:16:39 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T& a, T& b)
{
    T placeholder;
    placeholder = a;
    a = b;
    b = placeholder;
}

template <typename T>
T min(T a, T b)
{
    if(a < b)
        return a;
    return b;
}

template <typename T>
T max(T a, T b)
{
    if(a > b)
        return a;
    return b;
}