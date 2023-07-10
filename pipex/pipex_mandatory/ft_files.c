/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:18:47 by rrimonte          #+#    #+#             */
/*   Updated: 2023/05/09 19:14:25 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_files(t_data *g_data, int argc, char **argv, char **envp)
{
	g_data->b_env = 0;
	if (envp[0] == NULL)
		g_data->b_env = 1;
	ft_infile(g_data, argv);
	ft_outfile(g_data, argv, argc);
	if (g_data->b_env == 0)
	{
		while (*envp != NULL && ft_strncmp("PATH", *envp, 4))
			envp++;
		if (*envp == NULL)
		{
			g_data->b_env = 1;
			return ;
		}
		if (ft_strncmp("", (*envp + 5), 1) != 0)
		{
			g_data->paths = *envp + 5;
			g_data->cmd_paths = ft_split(g_data->paths, ':');
		}
	}
}

/**
 * The function opens a file for reading and sets an error flag if the file
 * cannot be opened.
 */
void	ft_infile(t_data *g_data, char **argv)
{
	g_data->infl = open(argv[1], O_RDONLY);
	if (g_data->infl < 0)
	{
		g_data->berrorinf = 1;
		ft_error(1);
	}
}

/**
 * The function opens a file for writing or appending based on the presence
 * of a here document flag.
 */
void	ft_outfile(t_data *g_data, char **argv, int argc)
{
	g_data->outfl = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0664);
	if (g_data->outfl < 0)
		ft_error(2);
}
