#include "test2.h"

/*************************
 *   1.4. test_write     *
 * ***********************
 * Check your ft_write. For this test you can choose strings
 * 		with max length 30 symbols.
 * functions:
 * 1.4.1. test_write_start
 * 		Start check write.
 * 1.4.2. test_write_str_gnl
 */

void	test_write(void)
{
	t_wr	wr;

	if (test_write_start(&wr))
		return ;
	wr.orig = write(wr.fd1, "hello\n12345", strlen("hello\n12345"));
	wr.err = errno;
	wr.ft = ft_write(wr.fd2, "hello\n12345", strlen("hello\n12345"));
	if (test_write_str_gnl(&wr, 0, 0))
		return ;
	close(wr.fd1);
	close(wr.fd2);
	wr.fd1 = open("./test_2/write1.txt", O_CREAT |O_TRUNC |O_RDWR, 0000777);
	wr.fd2 = open("./test_2/write2.txt", O_CREAT |O_TRUNC |O_RDWR, 0000777);
	wr.orig = write(wr.fd1, "hi\n1\\f##/#//@//ds''", 20);
	wr.err = errno;
	wr.ft = ft_write(wr.fd2, "hi\n1\\f##/#//@//ds''", 20);
	if (test_write_str_gnl(&wr, 0, 0))
		return ;
	wr.orig = write(42, "hi\n1\\f##/#//@//ds''", 20);
	wr.err = errno;
	wr.ft = ft_write(42, "hi\n1\\f##/#//@//ds''", 20);
	if (test_write_str_gnl(&wr, 0, 0))
		return ;
	write(1, "\n|______________|___|___|___|________\n", 39);
	test_read(0);
}

/******************************
 *   1.4.1. test_write_start  *
 * ****************************
 * Start check write.
 */

int	test_write_start(t_wr *wr)
{
	write(1, "|  ft_write    |", 17);
	errno = 0;
	wr->flag_wr = 'w';
	wr->fd1 = open("./test_2/write1.txt", O_CREAT |O_TRUNC |O_RDWR, 0000777);
	if (wr->fd1 < 0)
	{
		write(1, "Error:\n cannot open/create file 'write1.txt'\n", 53);
		return (1);
	}
	wr->fd2 = open("./test_2/write2.txt", O_CREAT |O_TRUNC |O_RDWR, 0000777);
	if (wr->fd2 < 0)
	{
		close(wr->fd1);
		write(1, "Error:\n cannot open/create file 'write2.txt'\n", 53);
		return (1);
	}
	return (0);
}

/***********************************
 *   1.4.2. test_write_str_gnl     *
 * *********************************
 * Compare two strings (from original write
 * 	and from your ft_write).
 * functions:
 * 	1.4.2.1. logs_write_read;
 * 		write KO test results for ft_write
 * 			to file "./log_test.txt".
 * 	1.4.2.2. test_write_str_gnl_results
 * 		write test results to stdout.
 */

int	test_write_str_gnl(t_wr *wr, int fd, int i)
{
	while (i < 31)
	{
		wr->buf1[i] = 0;
		wr->buf2[i++] = 0;
	}
	fd = open("./test_2/write1.txt", O_RDONLY);
	if (fd <= 0)
		write(1, "Error:\n cannot open file 'write1.txt'\n", 46);
	if (fd <= 0)
		return (1);
	read(fd, wr->buf1, 31);
	close(fd);
	fd = open("./test_2/write2.txt", O_RDONLY);
	if (fd <= 0)
		write(1, "Error:\n cannot open file 'write2.txt'\n", 46);
	if (fd <= 0)
		return (1);
	read(fd, wr->buf2, 31);
	close(fd);
	if (wr->ft == wr->orig && wr->err == errno && !strcmp(wr->buf1, wr->buf2))
		test_write_str_gnl_results(wr);
	else
		if (logs_write_read(wr, wr->buf1, wr->buf2))
			return (1);
	return (0);
}

/******************************************
 *   1.4.2.2. test_write_str_gnl_results  *
 * ****************************************
 * Write test results to stdout.
 * 
 * functions:
 * 	1.7.test_results;
 */

void	test_write_str_gnl_results(t_wr *wr)
{
	errno = 0;
	wr->err = 0;
	test_results(1);
}

/******************************
 *  1.4.2.1. logs_write_read  *
 * ****************************
 * write KO test results for ft_write to file "./log_test.txt".
 *
 * functions:
 * 1.4.2.1.1. logs_write_read_2;
 * 			write text "   write"/"   read" or "ft_write"/"ft_read" to logs file
 * 				(depend of calling function).
 * 1.1.1.1. ft_putnbr_fd;
 * 			write numbers to file.
 */

int	logs_write_read(t_wr *wr, char *buf1, char *buf2)
{
	int	fd;

	fd = open("./log_test.txt", O_APPEND | O_WRONLY);
	if (fd <= 0)
		return (1);
	write(fd, "_____________________\n", 23);
	logs_write_read_2(fd, wr, "   ", buf1);
	logs_write_read_2(fd, wr, "ft_", buf2);
	write(fd, "return    ", 11);
	write_or_read(wr, fd);
	ft_putnbr_fd(wr->orig, fd);
	write(fd, "\n errno: ", 10);
	ft_putnbr_fd(wr->err, fd);
	write(fd, "\n\nreturn ft_", 13);
	write_or_read(wr, fd);
	ft_putnbr_fd(wr->ft, fd);
	write(fd, "\n errno: ", 10);
	ft_putnbr_fd(errno, fd);
	write(fd, "\n_____________________\n", 24);
	close(fd);
	errno = 0;
	wr->err = 0;
	test_results(0);
	return (0);
}
