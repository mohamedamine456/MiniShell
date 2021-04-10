#ifndef BUILT_IN_H
# define BUILT_IN_H
# include <errno.h>
# include "../libft/libft.h"

typedef struct	s_builtin_vars
{
	 char	**args;
	 char	*option;
	 char	**envp;
}				t_builtin_vars;

void			ft_echo(t_builtin_vars var, int *retv);
void			ft_pwd(t_builtin_vars var, int *retv);
void			ft_cd(t_builtin_vars var, int *retv);
void			ft_exit(t_builtin_vars var, int *retv);
void			ft_unset(t_builtin_vars var, int *retv);
void			ft_env(t_builtin_vars var, int *retv);
void			ft_export(t_builtin_vars var, int *retv);

char			**remove_env(char *str, char **envp);

#endif
