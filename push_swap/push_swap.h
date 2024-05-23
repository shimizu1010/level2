/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/10/10 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/23 18:14:24 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <libc.h>
#include "libft/libft.h"

#define ERROR "Error\n" 

typedef struct s_stacks
{
    int *a;
    int *b;
    int a_size;
    int b_size;
    char *join_args;
}t_stacks;

void free_and_exit_with_message(t_stacks *s, char *msg);
void swap(char *str, int *array, int size);
void push_a(t_stacks *s);
void push_b(t_stacks *s);
void rotate_up(int *array, int size, char *list);
void rotate_down(int *array, int size, char *list);
void exit_if_sorted_or_has_duplicate(t_stacks *s, int i);
int ft_atol(const char *n, t_stacks *s);
void parse_numbers(t_stacks *s);
void initialize_stacks(int argc, char **argv, t_stacks *s);
void create_index(t_stacks *s);
int	count_words(char const *s, char c);
void parse_numbers(t_stacks *s);
void sort_three_elements(t_stacks *s);
void sort_four_to_five_elements(t_stacks *s);
int	is_array_sorted(t_stacks *s);
void radix_sort(t_stacks *s);

#endif