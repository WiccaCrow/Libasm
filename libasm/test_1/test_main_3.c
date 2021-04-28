#include "./test.h"

void	test_read_1(t_all *all, int fd1, int fd2)
{
	int		rax;
	int		rax_ft;
	char	buf[100000];

	test_read_2(all, &fd1, &fd2);
	rax = read(fd1, buf, 95);
	rax_ft = ft_read(fd2, buf, 95);
	printf("rcx    = %d\nrcx_ft = %d\n", rax, rax_ft);
	rax = read(fd1, buf, 95556);
	rax_ft = ft_read(fd2, buf, 95556);
	printf("rcx    = %d\nrcx_ft = %d\n", rax, rax_ft);
	close(fd1);
	close(fd2);
	rax = read(fd1, buf, 95556);
	rax_ft = ft_read(fd2, buf, 95556);
	printf("rcx    = %d\nrcx_ft = %d\n", rax, rax_ft);
	errno = 0;
	fd2 = open("./test_1/test_for_read.txt", O_RDONLY);
	if (fd2 < 0)
		write(1, "Error: test_read : can't open \"test_for_read.txt\".\n", 52);
	if (fd2 < 0)
		exit_clean(all);
	rax_ft = ft_read(fd1, buf, 1);
	printf("rax_ft = %d ernno:%d\n", rax_ft, errno);
	close(fd2);
}

void	test_read_2(t_all *all, int *fd1, int *fd2)
{
	*fd1 = open("./test_1/test_for_read.txt", O_RDONLY);
	if (*fd1 < 0)
	{
		write(1, "Error: can't open \"test_for_read.txt\".\n", 40);
		exit_clean(all);
	}
	*fd2 = open("./test_1/test_for_read.txt", O_RDONLY);
	if (*fd2 < 0)
	{
		close(*fd1);
		write(1, "Error: can't open \"test_for_read.txt\".\n", 40);
		exit_clean(all);
	}
	write(1, "==============================\n", 32);
	write(1, "| 5.        ft_read          |\n", 32);
	write(1, "==============================\n", 32);
}

void	test_strdup(t_all *all)
{
	char	*s;
	char	*s_ft;

	s = NULL;
	s_ft = NULL;
	s = strdup(all->space);
	s_ft = ft_strdup(all->space);
	if (!s || !s_ft)
	{
		if (s)
			free(s);
		if (s_ft)
			free(s_ft);
		write(1, "Error: test_strdup : malloc.\n", 30);
		exit_clean(all);
	}
	write(1, "==============================\n", 32);
	write(1, "| 6.      ft_strdup          |\n", 32);
	write(1, "==============================\n", 32);
	printf("   strdup: |%s|\nft_strdup: |%s|\n   string: |%s|\n",
		s, s_ft, all->space);
	free(s);
	free(s_ft);
}
