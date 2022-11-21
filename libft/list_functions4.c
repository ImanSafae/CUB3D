/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:52:10 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/21 18:53:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	add_token_after(t_list *element, int newvalue, char *token, int type)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return (0);
	new_element->value = newvalue;
	new_element->t_type = type;
	new_element->path = NULL;
	new_element->token = token;
	new_element->redirections = NULL;
	new_element->cmd_args = NULL;
	new_element->precedelem = element;
	new_element->nextelem = element->nextelem;
	element->nextelem->precedelem = new_element;
	element->nextelem = new_element;
	return (1);
}

int	add_elem_after(t_list *elem, int value, char **cmd_args, t_list *red)
{	
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return (0);
	new_element->value = value;
	new_element->redirections = red;
	new_element->cmd_args = cmd_args;
	new_element->precedelem = elem;
	new_element->nextelem = elem->nextelem;
	elem->nextelem->precedelem = new_element;
	elem->nextelem = new_element;
	return (1);
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

void	delete_first_elem(t_list *racine)
{
	if (racine->nextelem != racine)
	{
		delete_elem(racine->nextelem);
	}
}
