/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:13:02 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/05/06 14:41:08 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*s1;
	const char	*s2;
	char		*revs1;
	const char	*revs2;

	i = 0;
	s1 = dest;
	s2 = src;
	revs1 = dest + (n - 1);
	revs2 = src + (n - 1);
	if (s1 < s2)
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else
	{
		while (n--)
			*revs1-- = *revs2--;
	}
	return (dest);
}
