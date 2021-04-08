#ifndef OPEN_FILES_H
# define OPEN_FILES_H
# include "../libft/libft.h"
# include "../parse/cmd.h"
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

int		open_inputs(t_input *inputs);

#endif
