/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:03:58 by rrimonte          #+#    #+#             */
/*   Updated: 2023/05/11 19:12:58 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define RUTE "/usr/bin/whereis"
# define WRITE_O 1
# define READ_O 0
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include <errno.h>

typedef struct s_c_list
{
	struct s_c_list		*previous;
	struct s_c_list		*next;
	char				**cmd;
}	t_c_list;

typedef struct t_g_data
{
	struct s_c_list		*cmd_lst;
	int					fd[2];
	int					status;
	int					pid;
	int					infl;
	int					outfl;
	int					berror;
	int					berrorinf;
	int					b_env;
	int					i;
	int					x;
	char				*paths;
	char				**cmd_paths;
	char				*cmd_rute;
}	t_data;

void		ft_parse(t_data *g_data, int argc, char **argv);
void		inicialize_a_list(t_data *g_data);
void		find_rute(t_data *g_data);
void		create_pipes(t_data *g_data, int argc);
void		ft_backward_node(t_data *g_data);
void		ft_forward_node(t_data *g_data);
void		child(t_data *g_data);
void		second_child(t_data *g_data);
void		ft_deletenod(t_data *g_data);
void		ft_free_all(t_data *g_data, int argc);
void		ft_infile(t_data *g_data, char **argv);
void		ft_outfile(t_data *g_data, char **argv, int argc);
void		ft_error(int err);
void		ft_check_files(t_data *g_data, int argc, char **argv, char **envp);
char		*get_cmd_path(t_data *g_data);
void		ft_free_matrix(t_data *g_data, int n);

#endif
