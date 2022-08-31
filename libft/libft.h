/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:12:46 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/18 14:02:21 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

// STRUCT DEFENITION FOT LISTS TO CUSTOMISE
typedef struct s_list
{
	int				value;
	int				t_type;
	int				e_type;
	char			*token;
	char			*path;
	char			**cmd_args;			// cmd_args[0] = "ls" | cmd_args[1] = " -la" | cmd_args[2] = "-e" par ex.
	struct s_list	*redirections;
	struct s_list	*nextelem;
	struct s_list	*precedelem;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_trim(char *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_split_c(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// LIST FUNCTIONS 
t_list	*init_list(void);
void	empty_list(t_list *list);
void	delete_list(t_list **list);
int		add_elem_before(t_list *elem, int value, char **cmd_args, t_list *red);
int		add_elem_after(t_list *elem, int value, char **cmd_args, t_list *red);
void	add_to_start(t_list *racine, int newvalue, char **cmd_args, t_list *red);
void	add_to_end(t_list *racine, int newvalue, char **cmd_args, t_list *red);
void	delete_elem(t_list *elem);
void	delete_first_elem(t_list *racine);
void	delete_last_elem(t_list *racine);
int		count_elements(t_list *list);
void	rotate_list(t_list *racine);
void	reverse_rotate_list(t_list *racine);
void	swap_2_first(t_list *racine);
// FREE FUNCTIONS
t_list	   *free_node(t_list *elem);
char	*free2(char *str); // in list_functions.c
// TOKEN FUNCTIONS
int		add_token_before(t_list *element, int newvalue, char *token, int type);
int		add_token_after(t_list *element, int newvalue, char *token, int type);
void	tok_end(t_list *racine, int newvalue, char *token, int type);

//SPLIT function // used in  get_tokens -> get_token()
char	*ft_strdupcustom(const char *src, int sizeword);

#endif
