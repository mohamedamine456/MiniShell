#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "../libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# define O_ECHO 20
# define O_CD 21
# define O_PWD 22
# define O_UNSET 23
# define O_EXPORT 24
# define O_ENV 25
# define O_EXIT 26

typedef struct	s_builtin_vars
{
	 char	**args;
	 char	*option;
	 char	***envp;
}				t_builtin_vars;

void			ft_echo(t_builtin_vars var, int *retv);
void			ft_pwd(t_builtin_vars var, int *retv);
void			ft_cd(t_builtin_vars var, int *retv);
void			ft_exit(t_builtin_vars var, int *retv);
void			ft_unset(t_builtin_vars var, int *retv);
void			ft_env(t_builtin_vars var, int *retv);
void			ft_export(t_builtin_vars var, int *retv);

int				change_pwdenv(char ***envp);
int				exec_builtin(t_cmd cmd, char **envp);
char			**remove_env(char *str, char **envp);
int				ft_look_path(char **envp);
void			ft_builtin_errors(const char *name,int err, int *retv);

#endif
