#ifndef BUILT_IN_H
# define BUILT_IN_H
# include <errno.h>
# include "../libft/libft.h"
# include "../minishell.h"
# define ECHO 20
# define CD 21
# define PWD 22
# define UNSET 23
# define EXPORT 24
# define ENV 25
# define EXIT 26

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

int			exec_builtin(t_cmd cmd, char **envp);
char			**remove_env(char *str, char **envp);

#endif
