#include "minishell.h"

void	add_back_hist(t_history **hists, t_history *new)
{
	t_history *hist;
	
	hist = *hists;
	if (hist == NULL)
		*hists = new;
	else
	{
		hist = last_hist(*hists);
		new->previous = hist;
		hist->next = new;
	}
}


void	clear_hist(t_history **hists)
{
	t_history	*hist1;
	t_history	*hist2;

	hist1 = *hists;
	while (hist1 != NULL)
	{
		hist2 = hist1->next;
		if (hist1->line_orig != NULL)
			free(hist1->line_orig);
		if (hist1->line_chngd != NULL)
			free(hist1->line_chngd);
		free(hist1);
		hist1 = NULL;
		hist2->previous = NULL;
		hist1 = hist2;
	}
	hists = NULL;
}

t_history	*last_hist(t_history *hist)
{
	if (hist != NULL)
	{
		while (hist->next != NULL)
			hist = hist->next;
	}
	return (hist);
}

t_history	*first_hist(t_history *hist)
{
	if (hist != NULL)
	{
		while (hist->previous != NULL)
			hist = hist->previous;
	}
	return (hist);
}

t_history	*new_hist(void)
{
	t_history	*hist;

	hist = (t_history *)malloc(sizeof(t_history));
	hist->line_orig = NULL;
	hist->line_chngd = NULL;
	hist->next = NULL;
	hist->previous = NULL;
	return (hist);
}
