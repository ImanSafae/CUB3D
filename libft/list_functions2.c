/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:40:53 by abelhadi          #+#    #+#             */
/*   Updated: 2022/03/09 20:17:52 by abelhadi         ###   ########.fr       */
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

void	reverse_rotate_list(t_list *racine)
{
	t_list	*tmpfirst;
	t_list	*tmplast;
	t_list	*tmpsecond;

	tmplast = racine->precedelem;
	tmpfirst = racine->nextelem;
	tmpsecond = racine->precedelem->precedelem;
	tmplast->precedelem = racine;
	tmplast->nextelem = tmpfirst;
	racine->precedelem = tmpsecond;
	racine->nextelem = tmplast;
	tmpfirst->precedelem = tmplast;
	tmpsecond->nextelem = racine;
}

void	swap_2_first(t_list *racine)
{
	t_list	*tmpfirst;
	t_list	*tmpsecond;
	t_list	*tmpthird;

	if (racine->nextelem == racine)
		exit(1);
	if (racine->nextelem->nextelem == racine)
		exit(1);
	tmpfirst = racine->nextelem;
	tmpsecond = racine->nextelem->nextelem;
	tmpthird = tmpsecond->nextelem;
	tmpthird->precedelem = tmpfirst;
	tmpfirst->nextelem = tmpthird;
	tmpfirst->precedelem = tmpsecond;
	tmpsecond->nextelem = tmpfirst;
	tmpsecond->precedelem = racine;
	racine->nextelem = tmpsecond;
}
