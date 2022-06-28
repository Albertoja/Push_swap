/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:27:03 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/28 20:06:43 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

void	ft_swap(t_list **stack, char a);
void	ft_push(t_list **desde, t_list **hasta, char a);
void	ft_rotate(t_list **stack, char a);
void	ft_revrotate(t_list **stack, char a);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_sort_undo_five(t_list *stack_a, t_list *stack_b);
t_list	*ft_min(t_list *stack);
t_list	*ft_max(t_list *stack);
int		check_list_order(t_list *stack);
int		ft_check_list(t_list *stack_a);
int		ft_num_same(t_list *stack_a);
void	ft_size_3(t_list **stack_a);
size_t	ft_min_int(t_list *stack);
t_list	*next_min(t_list *stack, t_list *pre_min);
void	ft_lstclear(t_list **lst);
size_t	ft_place(t_list *stack, t_list *content);
t_list	*ft_copylst(t_list *stack);
t_list	*ft_trasform_num(t_list *stack_a);
int		ft_middle_int(t_list *stack, int middle);
int		ft_search_less(t_list *stack, int num);
void	ft_pre_order(t_list **stack_a, t_list **stack_b);
void	ft_size_3_pre(t_list **stack_a);
t_list	*ft_copy_list(t_list *stack);
void	ft_create_lst(t_list **stack_a, int argc, char **argv);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, char const *s2);
void	ft_check_letters(char **str);
int		ft_isnumber(char *s);
void	ft_free(char **numbers);
void	ft_gnl(int fd);
int		ft_isdigit(int a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	ft_check_letters(char **numbers);
void	ft_order(t_list **stack_a, t_list **stack_b);
void	ft_rotate_two(t_list **stack_a, t_list **stack_b);
void	ft_elcomeback(t_list **stack_a, t_list **stack_b);
int		ft_atoi_check(const char *str, char **numbers);
#endif