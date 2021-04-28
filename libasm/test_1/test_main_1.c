#include "test.h"

/*************************
 *          main         *
 * ***********************
 */
int	main(void)
{
	t_all	all;

	start_all(&all);
	while (all.gnl > 0)
	{
		printf("\n%d. \n", ++(all.i));
		all.gnl = get_next_line(all.fd, &(all.line));
		if (*(all.line))
			all.line_copy = strdup(all.line);
		else
			continue ;
		if (!all.line_copy)
			write(1, "Error: main : malloc.\n", 23);
		if (!all.line_copy)
			exit_clean(&all);
		all.space = strchr(all.line_copy, ' ');
		if (all.space == NULL)
		{
			write(1, "ERROR: wrong string in file. Correct filling:", 46);
			write(1, " function name, space, function parameters.\n", 45);
			continue ;
		}
		parser_func_name(&all);
	}
	return (0);
}

void	main_free(t_all *all)
{
	if (all->line_copy)
		free(all->line_copy);
	all->line_copy = NULL;
	if (all->line)
		free(all->line);
	all->line = NULL;
}

void	start_all(t_all *all)
{
	(*all).dst = NULL;
	(*all).fd = open("./test_1/test.txt", O_RDONLY);
	if ((*all).fd < 0)
	{
		write(1, "Error: start_all: can't open file test.txt\n", 44);
		exit (1);
	}
	(*all).gnl = 1;
	(*all).i = 0;
}

void	parser_func_name(t_all *all)
{
	*(all->space)++ = '\0';
	if (!strcmp(all->line_copy, "ft_strlen"))
		test_strlen(all);
	else if (!strcmp(all->line_copy, "ft_strcpy"))
		test_strcpy(all);
	else if (!strcmp(all->line_copy, "ft_strcmp"))
		test_strcmp(all);
	else if (!strcmp(all->line_copy, "ft_write"))
		test_write(all);
	else if (!strcmp(all->line_copy, "ft_read"))
		test_read_1(all, 0, 0);
	else if (!strcmp(all->line_copy, "ft_strdup"))
		test_strdup(all);
	else
	{
		write(1, "ERROR: wrong string in file. Correct filling: ", 47);
		write(1, "function name, space, function parameters.\n", 44);
	}
	main_free(all);
}

void	exit_clean(t_all *all)
{
	main_free(all);
	exit (1);
}
