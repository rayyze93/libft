/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:17:02 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/05/09 23:55:40 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_endlen(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > j && ft_charset(s1[i], set) == 1)
	{
		i--;
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		endl;
	char	*str;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] && ft_charset(s1[i], set) == 1)
		i++;
	endl = ft_endlen(s1, set);
	if (i == (int)ft_strlen(s1))
		endl = 0;
	str = malloc(sizeof(char) * ((ft_strlen(s1) - (i + endl)) + 1));
	if (!str)
		return (0);
	endl = ft_strlen(s1) - (i + endl);
	while (endl--)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
