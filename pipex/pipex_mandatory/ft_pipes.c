/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:16:59 by rrimonte          #+#    #+#             */
/*   Updated: 2023/05/11 19:13:44 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * The function creates pipes and forks child processes to execute commands
 * in a linked list.
 */
void	create_pipes(t_data *g_data, int argc)
{
	ft_backward_node(g_data);
	pipe(g_data->fd);
	g_data->pid = fork();
	if (g_data->pid == 0)
		child(g_data);
	else
	{
		g_data->i++;
		if (g_data->berrorinf == 1)
			g_data->berrorinf = 0;
		g_data->cmd_lst = g_data->cmd_lst->next;
		close(g_data->fd[WRITE_O]);
		second_child(g_data);
		close (g_data->fd[READ_O]);
		close(g_data->fd[WRITE_O]);
		g_data->i++;
	}
	close(g_data->infl);
	close(g_data->outfl);
	wait(&g_data->status);
	wait(&g_data->status);
	ft_free_all(g_data, argc);
}

void	child(t_data *g_data)
{
	g_data->cmd_rute = get_cmd_path(g_data);
	dup2(g_data->infl, STDIN_FILENO);
	close(g_data->infl);
	close (g_data->fd[READ_O]);
	dup2(g_data->fd[WRITE_O], STDOUT_FILENO);
	close (g_data->fd[WRITE_O]);
	if (g_data->berrorinf == 1)
		exit(0);
	execve(g_data->cmd_rute, g_data->cmd_lst->cmd, NULL);
	ft_error(4);
}

void	second_child(t_data *g_data)
{
	g_data->pid = fork();
	if (g_data->pid == 0)
	{
		g_data->cmd_rute = get_cmd_path(g_data);
		dup2(g_data->fd[READ_O], STDIN_FILENO);
		close(g_data->fd[READ_O]);
		dup2(g_data->outfl, STDOUT_FILENO);
		execve(g_data->cmd_rute, g_data->cmd_lst->cmd, NULL);
		ft_error(4);
	}
	close(g_data->fd[WRITE_O]);
}

char	*get_cmd_path(t_data *g_data)
{
	char	*tmp;
	char	*command;

	if(g_data->cmd_lst->cmd[0] == 0)
		ft_error(3);
	if (access(g_data->cmd_lst->cmd[0], X_OK) && g_data->b_env == 1)
		return (g_data->cmd_lst->cmd[0]);
	else if (g_data->b_env == 1)
	{
		ft_error(3);
		exit (0);
	}
	while (g_data->cmd_paths && g_data->cmd_paths[0] != NULL)
	{
		tmp = ft_strjoin(g_data->cmd_paths[0], "/");
		command = ft_strjoin(tmp, g_data->cmd_lst->cmd[0]);
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		g_data->cmd_paths++;
	}
	ft_error(3);
	return (NULL);
}
