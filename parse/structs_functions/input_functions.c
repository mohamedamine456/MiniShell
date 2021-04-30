#include "structs_functions.h"

void	add_input_back(t_input **input, t_input *new)
{
	t_input	*tmp;

	if (*input == NULL)
		*input = new;
	else
	{
		tmp = *input;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	clear_inputs(t_input **inputs)
{
	t_input	*input1;
	t_input	*input2;

	input1 = *inputs;
	while (input1 != NULL)
	{
		input2 = input1->next;
		if (input1->file != NULL)
			free(input1->file);
		free(input1);
		input1 = NULL;
		input1 = input2;
	}
	inputs = NULL;
}

t_input	*new_input(void)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	input->file = NULL;
	return (input);
}

int	size_inputs(t_input *inputs)
{
	int	i;

	i = 0;
	while (inputs != NULL)
	{
		i++;
		inputs = inputs->next;
	}
	return (i);
}
