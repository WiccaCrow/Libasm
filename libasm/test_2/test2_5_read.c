#include "test2.h"

/*************************
 *   1.5. test_read      *
 * ***********************
 * Check your ft_read. For this test you can choose
 * 		buffer with max length 30 symbols.
 * Push datas for test and call test function test_read_2.
 * 
 * functions:
 * 	1.5.1. test_read_2
 */

void	test_read(int i)
{
	t_wr	wr;

	errno = 0;
	wr.err = 0;
	while (i < 31)
	{
		wr.buf1[i] = 0;
		wr.buf2[i++] = 0;
	}
	wr.flag_wr = 'r';
	wr.flag_buf = 1;
	write(1, "|  ft_read     |", 17);
	if (test_read_2("./test_2/write2.txt", &wr, 30))
		return ;
	if (test_read_2("./test_2/test_for_read.txt", &wr, 30))
		return ;
	if (test_read_2("./test_2/test_for_read.txt", &wr, 0))
		return ;
	if (test_read_2(NULL, &wr, 30))
		return ;
	wr.flag_buf = 0;
	if (test_read_2("./test_2/test_for_read.txt", &wr, 30))
		return ;
	write(1, "\n|______________|___|___|___|___|___|\n", 39);
	test_strdup();
}

/*************************
 *   1.5.2. test_read_2  *
 * ***********************
 * Сhecks your function for reading a real file,
 * 		and calls function "test_read_3" to check
 * 		reading with zero buffer size.
 * 
 * functions:
 * 	1.5.2.1. test_read_3;
 * 		Check reading from real file and from
 * 			NULL with good buffer size.
 * 	1.7. test_results;
 * 	1.4.1.1. logs_write_read;
 */

int	test_read_2(char *s, t_wr *wr, int size)
{
	int		fd;

	if (s)
	{
		if (test_read_3(s, wr, size, 0))
			return (1);
	}
	else
	{
		fd = 42;
		wr->orig = read(fd, wr->buf1, size);
		wr->err = errno;
		wr->ft = ft_read(fd, wr->buf2, size);
	}
	if (wr->orig == wr->ft && wr->err == errno
		&& !strcmp(wr->buf1, wr->buf2))
	{
		errno = 0;
		wr->err = 0;
		test_results(1);
	}
	else
		if (logs_write_read(wr, wr->buf1, wr->buf2))
			return (1);
	return (0);
}

/*************************
 *  1.5.2.1. test_read_3 *
 * ***********************
 * Check reading from real file and from NULL with good buffer size.
 */

int	test_read_3(char *s, t_wr *wr, int size, int fd)
{
	fd = open(s, O_RDONLY);
	if (fd < 0)
		write(1, "Error:\n cannot open file to test ft_read\n", 42);
	if (fd < 0)
		return (1);
	if (wr->flag_buf == 1)
		wr->orig = read(fd, wr->buf1, size);
	if (wr->flag_buf == 1)
		wr->err = errno;
	if (wr->flag_buf != 1)
		wr->orig = read(fd, NULL, size);
	if (wr->flag_buf != 1)
		wr->err = errno;
	close(fd);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		write(1, "Error:\n cannot open file to test ft_read\n", 42);
	if (fd < 0)
		return (1);
	if (wr->flag_buf == 1)
		wr->ft = ft_read(fd, wr->buf2, size);
	else
		wr->ft = ft_read(fd, NULL, size);
	close(fd);
	return (0);
}

/******************************
 *   1.4.2.1.1. logs_write_read_2  *
 * ****************************
 * write text "   " or "ft_" to logs file
 * 		(depend of calling function).
 * functions:
 * 	1.4.2.1.1.1. write_or_read
 * 		write text "write" or "read" to logs file
 * 			(depend of calling function).
 */

void	logs_write_read_2(int fd, t_wr *wr, char *str, char *buf)
{
	write(fd, str, strlen(str));
	write_or_read(wr, fd);
	write(fd, "|", 1);
	write(fd, buf, strlen(buf));
	write(fd, "|\n\n", 3);
}

/*********************************
 *   1.4.2.1.1.1. write_or_read  *
 * *******************************
 * write text "write" or "read" to logs file
 * 		(depend of calling function).
 */

void	write_or_read(t_wr *wr, int fd)
{
	if (wr->flag_wr == 'w')
		write(fd, "write", 6);
	else
		write(fd, "read", 5);
	write(fd, ": ", 2);
}
