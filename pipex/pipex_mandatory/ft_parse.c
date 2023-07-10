/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:08:21 by rrimonte          #+#    #+#             */
/*   Updated: 2023/05/11 18:41:00 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * The function parses the command line arguments, initializes a list, splits
 * the command, sets the arguments.
 */
void	ft_parse(t_data *g_data, int argc, char **argv)
{
	g_data->i = 2;
	while (g_data->i < argc - 1)
	{
		inicialize_a_list(g_data);
		g_data->cmd_lst->cmd = ft_split(argv[g_data->i], ' ');
		g_data->i++;
	}
	g_data->i = 1;
}
