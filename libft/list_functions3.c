/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:42:16 by abelhadi          #+#    #+#             */
/*   Updated: 2022/04/20 14:32:54 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*init_list(void)
{
	t_list	*origin;

	origin = malloc(sizeof(t_list));
	if (origin == NULL)
	{
		ft_putstr_fd("error malloc list origin", 1);
		return (NULL);
	}
	origin->nextelem = origin;
	origin->precedelem = origin;
	origin->cmd_args = NULL;
	origin->path = NULL;
	origin->token = NULL;
	origin->redirections = NULL;
	origin->value = 0;
	origin->t_type = 0;
	return (origin);
}

void	empty_list(t_list *list)
{
	t_list	*elem;
	t_list	*next;

	elem = list->nextelem;
	while (elem != list)
	{	
		next = elem->nextelem;
		elem = free_node(elem);
		elem = next;
	}
	list->nextelem = list;
	list->precedelem = list;
}

void	delete_list(t_list **list)
{
	empty_list(*list);
	free(*list);
	*list = NULL;
}

int	add_elem_before(t_list *element, int newvalue, char **cmd_args, t_list *red)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return (0);
	new_element->value = newvalue;
	new_element->redirections = red;
	new_element->cmd_args = cmd_args;
	new_element->precedelem = element->precedelem;
	new_element->nextelem = element;
	element->precedelem->nextelem = new_element;
	element->precedelem = new_element;
	return (1);
}

int	add_token_before(t_list *element, int newvalue, char *token, int type)
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
	new_element->precedelem = element->precedelem;
	new_element->nextelem = element;
	element->precedelem->nextelem = new_element;
	element->precedelem = new_element;
	return (1);
}

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
