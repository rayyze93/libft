/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:16:32 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/05/04 23:30:05 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_founded(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && little[j] && i < len)
			{
				i++;
				j++;
			}
			if (j == ft_strlen(little))
				return ((char *)&big[i - j]);
			else
			{
				i = i - j;
				j = 0;
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (len < i)
		len = ft_strlen(big);
	return (ft_founded(big, little, len));
}
