/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 15:07:50 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/20 16:54:19 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		operation(int a, int b, char c)
{
	int	resultat;

	if (c == '+')
		resultat = a + b;
	if (c == '-')
		resultat = a - b;
	if (c == '*')
		resultat = a * b;
	if (c == '/')
		resultat = a / b;
	if (c == '%')
		resultat = a % b;
	return (resultat);
}
