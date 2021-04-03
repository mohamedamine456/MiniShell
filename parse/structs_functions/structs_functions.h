#ifndef STRUCTS_FUNCTIONS_H
# define STRUCTS_FUNCTIONS_H
# include "../parse.h"

void		add_back_cmd(t_cmd **cmds, t_cmd *new);
void		clear_cmds(t_cmd **cmds);
t_cmd		*last_cmd(t_cmd *cmd);
t_cmd		*new_cmd();
int			size_cmds(t_cmd *cmds);

void		add_input_back(t_input **input, t_input *new);
void		clear_inputs(t_input **inputs);
t_input		*last_inputs(t_input *inputs);
t_input		*new_input();
int			size_inputs(t_input *inputs);

void		add_output_back(t_output **output, t_output *new);
void		clear_outputs(t_output **outputs);
t_output	*last_outputs(t_output *outputs);
t_output	*new_output();
int			size_outputs(t_output *outputs);

#endif
