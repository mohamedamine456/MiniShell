# include "structs_functions.h"

void	add_output_back(t_output **output, t_output *new)
{
	t_output *tmp;

	if (*output == NULL)
		*output = new;
	else
	{
		tmp = *output;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		clear_outputs(t_output **outputs)
{
	t_output *output1;
	t_output *output2;

	output1 = *outputs;
	while (output1 != NULL)
	{
		output2 = output1->next;
		if (output1->file != NULL)
			free(output1->file);
		free(output1);
		output1 = NULL;
		output1 = output2;
	}
	outputs = NULL;
}

t_output		*last_outputs(t_output *outputs)
{
	if (outputs != NULL)
	{
		while (outputs->next != NULL)
		   outputs = outputs->next;
	}
	return (outputs);
}

t_output      *new_output()
{
    t_output *output;

    output = (t_output *)malloc(sizeof(t_output));
    output->file = NULL;
    return (output);
}

int		size_outputs(t_output *outputs)
{
	int i;

	i = 0;
	while (outputs != NULL)
	{
		i++;
		outputs = outputs->next;
	}
	return (i);
}
