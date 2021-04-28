#include "test2.h"

/*************************
 *   1.1. test_strlen    *
 * ***********************
 * test for ft_strlen.
 * functiions:
 * 1.1.1. logs_strlen_strcmp
 *   write KO test results for ft_strlen and ft_strcmp
 * 		to file "./log_test.txt".
 */

void	test_strlen(int len_orig, int len_ft)
{
	write(1, "|  ft_strlen   |", 17);
	len_orig = strlen("hello");
	len_ft = ft_strlen("hello");
	if (logs_strlen_strcmp(len_orig, len_ft, "strlen", "hello"))
		return ;
	len_orig = strlen("hi\n\0\\f##/#//@//ds''");
	len_ft = ft_strlen("hi\n\0\\f##/#//@//ds''");
	if (logs_strlen_strcmp(len_orig, len_ft, "strlen", "hi\n\0\\f##/#//@//ds''"))
		return ;
	len_orig = strlen("hi\0gadfgdfgxfdfgfg");
	len_ft = ft_strlen("hi\0gadfgdfgxfdfgfg");
	if (logs_strlen_strcmp(len_orig, len_ft, "strlen", "hi\0gadfgdfgxfdfgfg"))
		return ;
	len_orig = strlen("");
	len_ft = ft_strlen("");
	if (logs_strlen_strcmp(len_orig, len_ft, "strlen", ""))
		return ;
	len_orig = strlen("djskfdkzxvmxadfkvmzdkdfopgvz d  m md");
	len_ft = ft_strlen("djskfdkzxvmxadfkvmzdkdfopgvz d  m md");
	if (logs_strlen_strcmp(len_orig, len_ft, "strlen",
			"djskfdkzxvmxadfkvmzdkdfopgvz d  m md"))
		return ;
	write(1, "\n|______________|___|___|___|___|___|\n", 39);
	test_strcpy();
}

/*************************
 * 1.1.1.1. ft_putnbr_fd *
 * ***********************
 * convert integer to char and write number to file.
 */

void	ft_putnbr_fd(int n, int fd)
{
	long int		i;
	unsigned int	u_n;
	char			c_num;

	i = 1;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
		write(fd, "-", 1);
	u_n = n;
	if (n < 0)
		u_n = -n;
	while (n / i)
		i *= 10;
	while (i / 10)
	{
		i /= 10;
		c_num = u_n / i + '0';
		u_n = u_n % i;
		write(fd, &c_num, 1);
	}
}

/******************************
 *  1.1.1. logs_strlen_strcmp *
 * ****************************
 * write KO test results for ft_strlen and ft_strcmp
 * 	to file "./log_test.txt".
 * functions:
 * 1.1.1.1. ft_putnbr_fd;
 * 		convert integer to char and write number to file.
 * 1.1.1.2. logs_strlen_strcmp_part2;
 * 		write some part of logs_strlen_strcmp.
 * 1.7. test_results;
 */

int	logs_strlen_strcmp(int orig, int ft, char *func, char *str)
{
	int	fd;
	int	flag;

	flag = 0;
	if ((!strcmp(func, "strcmp") && ((ft < 0 && orig < 0)
				|| (ft > 0 && orig > 0) || ft == orig))
		|| (!strcmp(func, "strlen") && ft == orig))
		flag = 1;
	if (!flag)
	{
		fd = open("./log_test.txt", O_APPEND | O_WRONLY);
		if (fd > 0)
		{
			logs_strlen_strcmp_part2(fd, func, str, orig);
			ft_putnbr_fd(ft, fd);
			write(fd, "\n_____________________\n", 24);
			close(fd);
		}
		if (fd <= 0)
			write(1, "Error:\n cannot create file 'log_test.txt'\n", 43);
		if (fd <= 0)
			return (1);
	}
	test_results(flag);
	return (0);
}

/**************************************
 *  1.1.1.2. logs_strlen_strcmp_part2 *
 * ************************************
 * write some part of logs_strlen_strcmp.
 */

void	logs_strlen_strcmp_part2(int fd, char *func, char *str, int orig)
{
	write(fd, "_____________________\nstring:\n", 31);
	write(fd, str, strlen(str));
	write(fd, "\n   ", 4);
	write(fd, func, strlen(func));
	write(fd, ":", 1);
	ft_putnbr_fd(orig, fd);
	write(fd, "\nft_", 4);
	write(fd, func, strlen(func));
	write(fd, ":", 1);
}
