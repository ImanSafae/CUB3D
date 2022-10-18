/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:59:59 by abelhadi          #+#    #+#             */
/*   Updated: 2022/04/20 13:54:28 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*free2(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

void	add_to_start(t_list *racine, int newvalue, char **cmd_args, t_list *red)
{
	add_elem_after(racine, newvalue, cmd_args, red);
}

void	add_to_end(t_list *racine, int newvalue, char **cmd_args, t_list *red)
{
	add_elem_before(racine, newvalue, cmd_args, red);
}

void	tok_start(t_list *racine, int newvalue, char *token, int type)
{
	add_token_after(racine, newvalue, token, type);
}

void	tok_end(t_list *racine, int newvalue, char *token, int type)
{
	add_token_before(racine, newvalue, token, type);
}

void	delete_elem(t_list *elem)
{
	elem->precedelem->nextelem = elem->nextelem;
	elem->nextelem->precedelem = elem->precedelem;
	elem = free_node(elem);
}

void	delete_first_elem(t_list *racine)
{
	if (racine->nextelem != racine)
	{
		delete_elem(racine->nextelem);
	}
}

t_list	*free_node(t_list *elem)
{
	int	i;

	printf("\no=========\nFUNCTION: free_node()\n=========o\n");
	i = 0;
	while (elem->cmd_args)
	{
		printf("coucou in loop\n");
		free(elem->cmd_args[i]);
		elem->cmd_args[i] = NULL;
		i++;
	}
	free(elem->cmd_args);
	printf("coucou\n");

	if (elem->path)
		elem->path = free2(elem->path);
	if (elem->token)
		elem->token = free2(elem->token);
	if (elem->redirections)
		delete_list(&elem->redirections);
			printf("coucou\n");

	free(elem);
		printf("coucou\n");

	elem = NULL;
	printf("\no=========\nFUNCTION: end of free_node()\n=========o\n");
	return (elem);
}



/*
int	main(int ac, char	**argv)
{
	t_list	*a;
	t_list	*elem;
	int		i;
	int		num;

	i = ac;
	num = 0;
	a = init_list();
	while (--i > 0)
	{
		num = ft_atoi(argv[i]);
		add_to_start(a, num);
	}
	printf("Add to end test : we add 555, 666, 777\n");
	add_to_end(a, 555);
	add_to_end(a, 666);
	add_to_end(a, 777);

	printf("Stack a :\n");
	elem = a->nextelem;
	while (elem != a)
	{
		printf("%ld\n", elem->value);
		elem = elem->nextelem;
	}
	rotate_list(a);
	elem = a->nextelem;
	printf("\nRotate function test :\n");
	while (elem != a)
	{
		printf("%ld\n", elem->value);
		elem = elem->nextelem;
	}
	reverse_rotate_list(a);
	elem = a->nextelem;
	printf("\nReverse rotate function test :\n");
	while (elem != a)
	{
		printf("%ld\n", elem->value);
		elem = elem->nextelem;
	}
	i = count_elements(a);
	printf("Count_elements test : %d\n", i);
	printf("a : %p\n", a);
	printf("a->nextelem : %d\n", a->nextelem);
	printf("a->precedelm : %d\n", a->precedelem);

	printf("Delete first element test : \n");

	delete_first_elem(a);
	elem = a->nextelem;
	while (elem != a)
	{
		printf("%ld\n", elem->value);
		elem = elem->nextelem;
	}	
	delete_last_elem(a);
	printf("Delete last element test : \n");
	elem = a->nextelem;
	while (elem != a)
	{
		printf("%ld\n", elem->value);
		elem = elem->nextelem;
	}
	rotate_list(a);
	elem = a->nextelem;
	printf("\nRotate function test :\n");
	while (elem != a)
	{
		printf("%ld\n", elem->value);
		elem = elem->nextelem;
	}
	swap_2_first(a);
	elem = a->nextelem;
	printf("\nSwap function test :\n");
	while (elem != a)
	{
		printf("%ld\n", elem->value);
		elem = elem->nextelem;
	}

	return (0);
}*/
