
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/10/10 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/16 09:57:31 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//#19 2147483648 -2147483649

void free_and_exit_with_message(t_stacks *s, char *msg)
{
    if(msg)
        write(2, msg, ft_strlen(msg));
    if(s != NULL)
    {
        if (s->a != NULL)
            free(s->a);
        if(s->b != NULL)
            free(s->b);
        if(s->join_args != NULL)
            free(s->join_args);
        if(s != NULL)
            free(s);
    }
    exit(1);
}

static void validate_arguments(int argc, char **argv)
{
    int i;
    int j;
    i = 0;
    if(argc < 2)
        free_and_exit_with_message(NULL, "");
    while(++i < argc)
    {
        j = 0;
        if(!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
            free_and_exit_with_message(NULL, "Error\n");
        while(argv[i][j] != '\0')
        {
            if((!ft_isdigit(argv[i][j]) && (argv[i][j] != ' ')
            && (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
            || (argv[i][j] == '-' && argv[i][j + 1] == '\0')
            || (argv[i][j] == '+' && argv[i][j + 1] == '\0')
            || (argv[i][j] == '-' && argv[i][j + 1] == ' ')
            || (argv[i][j] == '+' && argv[i][j + 1] == ' '))
            free_and_exit_with_message(NULL, "Error\n");
            j++;
        }
    }
}

// static void join_args(int argc, char **argv, t_stacks *s)
// {
//     char *tmp;
//     char *tmp2;
//     int i;

//     i = 0;
//     tmp2 = ft_strdup("");
//     while(++i < argc && argv[i] != NULL)
//     {
//         tmp = ft_strjoin(tmp2, argv[i]);
//         if(tmp2)
//             free(tmp2);
//         if(i != argc - 1)
//         {
//             tmp = ft_strjoin(tmp, " ");
//             if(tmp)
//                 free(tmp);
//             tmp = tmp2;
//         }
//     }
//     s->join_args = ft_strdup(tmp);
//     if(s->join_args == NULL)
//         free_and_exit_with_message(s, "Error\n");
//     if(tmp)
//         free(tmp);
// }

static void join_args(int argc, char **argv, t_stacks *s)
{
    char *tmp2 = ft_strdup("");
    char *tmp;
    int i = 0;

    while (++i < argc && argv[i] != NULL) {
        tmp = ft_strjoin(tmp2, argv[i]);
        free(tmp2); // 前のメモリを確実に解放
        tmp2 = tmp; // 新しいメモリへのポインタを更新

        if (i != argc - 1) {
            tmp = ft_strjoin(tmp2, " ");
            free(tmp2); // 再度、前のメモリを解放
            tmp2 = tmp; // 新しいメモリへのポインタを更新
        }
    }
    s->join_args = tmp2; // 最終的な文字列を構造体に設定
}

int main(int argc, char **argv)
{
    t_stacks *s;

    //print function usage
    validate_arguments(argc, argv);
    s = malloc(sizeof * s);
    if(s == NULL)
        exit(1);
    initialize_stacks(argc, argv, s);
    join_args(argc, argv, s);
    parse_numbers(s);//what is this function
    exit_if_sorted_or_has_duplicate(s, 0);
    create_index(s);
    if(s->a_size == 2 && s->a[0] > s->a[1])
        swap("sa", s->a, s->a_size);
    else if(s->a_size == 3)
        sort_three_elements(s);
    else if(s->a_size >= 4 && s->a_size <= 5)
        sort_four_to_five_elements(s);
    else
        radix_sort(s);
    exit_if_sorted_or_has_duplicate(s, 1);
    free_and_exit_with_message(s, "Error\n");
    return 0;
}