/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:12:22 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/05/04 23:12:24 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	unsigned int	nb;
	int				count;

	count = 1;
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb > 9)
		nb /= 10;
	nb += '0';
	return (nb);
}

static int	ft_pow(int n)
{
	int	i;
	int	pow;

	i = ft_nbrlen(n) - 1;
	pow = 10;
	if (i == 0)
		return (1);
	while (i != 1)
	{
		pow *= 10;
		i--;
	}
	return (pow);
}

static char	*ft_putstr(int n, char *str, int signe)
{
	int	i;
	int	x;
	int	nbzero;

	i = 0;
	x = ft_nbrlen(n);
	if (n < 0)
		str[i++] = '-';
	while (i - signe < x)
	{
		str[i++] = ft_putnbr(n);
		if (ft_nbrlen(n % ft_pow(n)) != ft_nbrlen(n) - 1)
		{
			nbzero = ft_nbrlen(n) - ft_nbrlen(n % ft_pow(n));
			while (--nbzero > 0)
				str[i++] = '0';
		}
		n = n % ft_pow(n);
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		signe;
	char	*str;

	signe = 0;
	if (n < 0)
		signe = 1;
	str = malloc(sizeof(char) * (signe + ft_nbrlen(n) + 1));
	if (!str)
		return (0);
	ft_putstr(n, str, signe);
	return (str);
}
