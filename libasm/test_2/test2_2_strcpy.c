#include "test2.h"

/*************************
 *   1.2. test_strcpy    *
 * ***********************
 * test for ft_strcpy.
 * 
 * functions:
 * 1.2.1. logs_strcpy_strdup;
 */

void	test_strcpy(void)
{
	char	ft[31];
	char	orig[31];

	write(1, "|  ft_strcpy   |", 17);
	strcpy(orig, "hello");
	ft_strcpy(ft, "hello");
	if (logs_strcpy_strdup(!strcmp(orig, ft), orig, ft, "strcpy"))
		return ;
	strcpy(orig, "hi\n\0\\f##/#//@//ds''");
	ft_strcpy(ft, "hi\n\0\\f##/#//@//ds''");
	if (logs_strcpy_strdup(!strcmp(orig, ft), orig, ft, "strcpy"))
		return ;
	strcpy(orig, "hi\0gadfgdfgxfdfgfg");
	ft_strcpy(ft, "hi\0gadfgdfgxfdfgfg");
	if (logs_strcpy_strdup(!strcmp(orig, ft), orig, ft, "strcpy"))
		return ;
	strcpy(orig, "");
	ft_strcpy(ft, "");
	if (logs_strcpy_strdup(!strcmp(orig, ft), orig, ft, "strcpy"))
		return ;
	strcpy(orig, "djskfdkzxvmxzdkdfopg d  m md");
	ft_strcpy(ft, "djskfdkzxvmxzdkdfopg d  m md");
	if (logs_strcpy_strdup(!strcmp(orig, ft), orig, ft, "strcpy"))
		return ;
	test_strcmp(0, 0);
}

/********************************
 *  1.2.1. logs_strcpy_strdup   *
 * ******************************
 * write KO test results for ft_strcpy to file "./log_test.txt".
 * 
 * functions:
 * 	1.7. test_results;
 */

int	logs_strcpy_strdup(int flag, char *str_orig, char *str_ft, char *func)
{
	int	fd;

	if (flag)
	{
		test_results(1);
		return (0);
	}
	fd = open("./log_test.txt", O_APPEND | O_WRONLY);
	if (fd <= 0)
		return (1);
	write(fd, "_____________________\n   ", 26);
	write(fd, func, strlen(func));
	write(fd, ": |", 4);
	write(fd, str_orig, strlen(str_orig));
	write(fd, "|\nft_", 6);
	write(fd, func, strlen(func));
	write(fd, ": |", 4);
	write(fd, str_ft, strlen(str_ft));
	write(fd, "|\n_____________________\n", 25);
	close(fd);
	test_results(0);
	return (0);
}
