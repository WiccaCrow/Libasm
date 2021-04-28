#include "test2.h"

/*************************
 *   1.6. test_strdup    *
 * ***********************
 * Check your ft_strdup.
 * Populates data for tests. Starts function
 * 	checking (run function test_strdup_do_strdup). 
 * 
 * functions
 * 	1.6.1. test_strdup_do_strdup;
 */

void	test_strdup(void)
{
	char	*str_orig;
	char	*str_ft;

	str_orig = NULL;
	str_ft = NULL;
	write(1, "|  ft_strdup   |", 17);
	if (test_strdup_do_strdup(&str_orig, &str_ft, "hello"))
		return ;
	if (test_strdup_do_strdup(&str_orig, &str_ft, "hi\n\0\\f##/#//@//ds''"))
		return ;
	if (test_strdup_do_strdup(&str_orig, &str_ft, "hi\0gadfgdfgxfdfgfg"))
		return ;
	if (test_strdup_do_strdup(&str_orig, &str_ft, ""))
		return ;
	if (test_strdup_do_strdup(&str_orig, &str_ft,
			"djskfdkzxvmxadfkvmzdkdfopgvz d  m md"))
		return ;
	write(1, "\n|______________|___|___|___|___|___|\n", 39);
}

/*************************************
 *   1.6.1. test_strdup_do_strdup    *
 * ***********************************
 * Check your ft_strdup with datas from test_strdup.
 * 
 * functions
 * 	1.6.1.1. test_strdup_free;
 * 	1.2.1. logs_strcpy_strdup;
 */

int	test_strdup_do_strdup(char **str_orig, char **str_ft, char *str)
{
	*str_orig = strdup(str);
	if (*str_orig == NULL)
	{
		write(1, "\nError:\n strdup, malloc error\n", 31);
		return (1);
	}
	*str_ft = ft_strdup(str);
	if (*str_ft == NULL)
		write(1, "\nWarning:\n malloc error or error in ft_strdup\n", 47);
	if (logs_strcpy_strdup(!strcmp(*str_orig, *str_ft),
			*str_orig, *str_ft, "strdup"))
	{
		test_strdup_free(str_orig, str_ft);
		return (1);
	}
	test_strdup_free(str_orig, str_ft);
	return (0);
}

/**********************************
 *   1.6.1.1. test_strdup_free    *
 * ********************************
 * Frees allocated in 'test_strdup_do_strdup' memory.
 */

void	test_strdup_free(char **str_orig, char **str_ft)
{
	if (*str_orig != NULL)
	{
		free(*str_orig);
		*str_orig = NULL;
	}
	if (*str_ft != NULL)
	{
		free(*str_orig);
		*str_orig = NULL;
	}
}
