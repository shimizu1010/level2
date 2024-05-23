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

#include "minitalk.h"

static int64_t	ft_atoi(const char *str)
{
	int64_t	i;
	int64_t	sign;
	int64_t	result;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

static void	send_signal(pid_t pid, char *message)
{
	unsigned char	c;
	int64_t			bit_len;

	while (*message)
	{
		c = *message;
		bit_len = 8;
		while (bit_len--)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
			c <<= 1;
		}
		message++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		if (server_id <= 0)
		{
			write(1, "invalid server_id by kawamoto", 30);
			return (-1);
		}
		send_signal(server_id, argv[2]);
	}
	else
		write(1, "invalid number of argv", 30);
	return (0);
}
