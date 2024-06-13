/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:00:00 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/06 20:08:34 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_resources(t_stacks *s)
{
	if (!s)
		return ;
	free(s->a);
	free(s->b);
	free(s->join_args);
	free(s);
}

void	exit_success(t_stacks *s)
{
	free_resources(s);
	exit(0);
}

void	exit_failure(t_stacks *s)
{
	write(2, "Error\n", 6);
	free_resources(s);
	exit(1);
}

static void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		// free_and_exit_with_message(NULL, "");
		exit(1);
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			// free_and_exit_with_message(NULL, "Error\n");
			exit_failure(NULL);
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
					&& (argv[i][j] != '-' && argv[i][j] != '+'
						&& argv[i][j] != ' ')) || (argv[i][j] == '-'
					&& argv[i][j + 1] == '\0') || (argv[i][j] == '+'
					&& argv[i][j + 1] == '\0') || (argv[i][j] == '-'
					&& argv[i][j + 1] == ' ') || (argv[i][j] == '+' && argv[i][j
					+ 1] == ' '))
				exit_failure(NULL);
			// free_and_exit_with_message(NULL, "Error\n");
			j++;
		}
	}
}

static void	join_args(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (s->join_args == NULL)
		exit_failure(s);
	// free_and_exit_with_message(s, "Error\n");
	if (tmp)
		free(tmp);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	validate_arguments(argc, argv);
	s = malloc(sizeof *s);
	if (s == NULL)
		exit(1);
	initialize_stacks(argc, argv, s);
	join_args(argc, argv, s);
	parse_numbers(s);
	exit_if_sorted_or_has_duplicate(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_to_five_elements(s);
	else
		radix_sort(s);
	exit_if_sorted_or_has_duplicate(s, 1);
	exit_failure(s);
	// free_and_exit_with_message(s, "Error\n");
	return (0);
}
