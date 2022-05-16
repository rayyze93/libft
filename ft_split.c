/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:14:47 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/05/10 19:15:47 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tablen(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i])
		j = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	return (j);
}

static int	ft_slen(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

static char	*ft_stab(char const *s, char c, int i)
{
	int		j;
	char	*stab;

	j = 0;
	stab = malloc(sizeof(char) * (ft_slen(s, c, i) + 1));
	if (!stab)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		stab[j] = s[i];
		i++;
		j++;
	}
	stab[j] = '\0';
	return (stab);
}

static char	**ft_tab(char **tab, char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_stab(s, c, i);
			j++;
			i += ft_slen(s, c, i);
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	if (!s)
		return (0);
	if (s[0] == '\0')
	{
		tab = malloc(sizeof(char *));
		tab[0] = 0;
		return (tab);
	}
	i = 0;
	tab = malloc(sizeof(char *) * (ft_tablen(s, c) + 1));
	if (!tab)
		return (0);
	while (s[i] == c)
		i++;
	return (ft_tab(tab, s, c, i));
}
