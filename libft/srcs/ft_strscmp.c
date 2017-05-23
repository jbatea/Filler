/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:13:16 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/23 17:13:18 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strscmp(char *str, char *cmp1, char *cmp2)
{
	if (!ft_strcmp(str, cmp1) || !ft_strcmp(str, cmp2))
		return (0);
	return (1);
}
