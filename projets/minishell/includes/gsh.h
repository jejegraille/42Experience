/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:44:26 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/22 19:13:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GSH_H
# define GSH_H

# include <libft.h>
# include <unistd.h>
# include <termios.h>

typedef struct		s_cmd
{
	char			c;
	struct s_cmd	*next;
	struct s_cmd	*back;
}					t_cmd;

typedef struct		s_gsh
{
	char	*cmd;
	int		ok;
	int		child;
	int		exit;
	int		error;
	pid_t	process;
	char	*serror;
	char	*serror2;
	char	**env;
}					t_gsh;

void				gsh_exec(t_gsh *data, char **av);
int					gsh_fonct(t_gsh *data, char **av);
int					gsh_cd(t_gsh *data, char *path);
void				gsh_error(t_gsh *data);
void				gsh_echo(t_gsh *data, char **tab);
char				*get_var(char **env, char *var);
void				set_var(char ***env, char *var, char *value);
int					del_var(char ***env, char *var);
void				put_env(char **env);
void				gsh_read(char *cmd);
void				gsh_setenv(t_gsh *data, char **av);
void				gsh_addpath(t_gsh *data, char **av);
int					gsh_unsetenv(t_gsh *data, char **av);
int					gsh_path(t_gsh *data, char **path);
char				**conv_arg(t_gsh *data, char *str);

#endif
