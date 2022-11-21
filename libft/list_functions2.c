/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:40:53 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/21 18:52:43 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete_last_elem(t_list *racine)
{
	if (racine->precedelem != racine)
		delete_elem(racine->precedelem);
}

int	count_elements(t_list *list)
{
	t_list	*elem;
	int		i;

	elem = list->nextelem;
	i = 0;
	while (elem != list)
	{
		i++;
		elem = elem->nextelem;
	}
	return (i);
}

void	rotate_list(t_list *racine)
{
	t_list	*tmpfirst;
	t_list	*tmplast;
	t_list	*tmpsecond;

	tmplast = racine->precedelem;
	tmpfirst = racine->nextelem;
	tmpsecond = racine->nextelem->nextelem;
	tmpsecond->precedelem = racine;
	tmplast->nextelem = tmpfirst;
	racine->precedelem = tmpfirst;
	racine->nextelem = tmpsecond;
	tmpfirst->precedelem = tmplast;
	tmpfirst->nextelem = racine;
}
