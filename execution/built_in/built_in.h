/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:19:42 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 13:43:45 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# define B_ECHO 20
# define B_CD 21
# define B_PWD 22
# define B_UNSET 23
# define B_EXPORT 24
# define B_ENV 25
# define B_EXIT 26
# include "../../parse/parse.h"
# include "../execution.h"

typedef struct s_builtin_vars
{
	 char	**args;
	 char	*option;
	 char	***envp;
	 void	(*ft_builtin[7])(struct s_builtin_vars var, int *retv);

}				t_builtin_vars;

/*
 * ft_echo.c prototypes
 */

void			ft_echo(t_builtin_vars var, int *retv);

/*
 * ft_pwd.c prototypes
 */

void			ft_pwd(t_builtin_vars var, int *retv);

/*
 * ft_cd.c prototypes
 */

void			ft_cd(t_builtin_vars var, int *retv);
void			ft_cd_normal_case(t_builtin_vars var,
					char *dest_path, int *retv);
int				change_oldpwd(char ***envp);
int				change_pwd(char ***envp);
void			ft_cd_oldpwd(t_builtin_vars var, int *retv);

/*
 * ft_exit.c prototypes
 */

void			ft_exit(t_builtin_vars var, int *retv);
void			ft_exit_helper(t_builtin_vars var, int *retv);
int				check_exit_arg(char *str);
void			ft_free_builtin_vars(t_builtin_vars *var);

/*
 * ft_unset.c prototypes
 */

void			ft_unset(t_builtin_vars var, int *retv);
char			**remove_env(char *str, char **envp);
int				valid_identifier(char *identifier);
void			not_valid_identifier(char *identifier);

/*
 * ft_env.c prototypes
 */

void			ft_env(t_builtin_vars var, int *retv);

/*
 * ft_export.c prototypes
 */

void			ft_export(t_builtin_vars var, int *retv);

/*
 * ft_builtin_errors.c prototypes
 */

void			ft_builtin_errors(const char *name, int err, int *retv);

/*
 * ft_builtin_errors.c prototypes
 */

int				exec_builtin(t_cmd *cmd, char ***envp);

int				isbuilt_in(char *cmd);
int				exec_builtin(t_cmd *cmd, char ***envp);
int				is_simple_cmd(t_cmd *cmd);
int				ft_execute(t_cmd *cmd, char ***envp);

#endif
