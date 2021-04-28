#include "./test.h"

void	test_strlen(t_all *all)
{
	write(1, "==============================\n", 32);
	write(1, "| 1.        ft_strlen        |\n", 32);
	write(1, "==============================\n", 32);
	printf("   strlen: |%lu|\nft_strlen: |%d|\n   string: |%s|\n",
		strlen(all->space), ft_strlen(all->space), all->space);
}

void	test_strcpy(t_all *all)
{
	write(1, "==============================\n", 32);
	write(1, "| 2.        ft_strcpy        |\n", 32);
	write(1, "==============================\n", 32);
	all->dst = malloc(strlen(all->space) + 3);
	if (!all->dst)
	{
		write(1, "Error: test_strcpy : malloc.\n", 30);
		exit_clean(all);
	}
	printf("   strcpy: |%s|", strcpy(all->dst, all->space));
	all->dst[0] = 'a';
	all->dst[1] = 'b';
	all->dst[2] = '\0';
	printf("   new dst: |%s|\n", all->dst);
	printf("ft_strcpy: |%s|\n      src: |%s|\n", ft_strcpy(all->dst,
			all->space), all->space);
	free(all->dst);
	all->dst = NULL;
}

void	test_strcmp(t_all *all)
{
	char	*s1;
	char	*s2;

	write(1, "==============================\n", 32);
	write(1, "| 3.        ft_strcmp        |\n", 32);
	write(1, "==============================\n", 32);
	s1 = all->space;
	s2 = strchr(all->space, '*');
	if (s2 == NULL)
	{
		write(1, "Warning: test_strcmp : Correct filling: function name, ", 56);
		write(1, "space, parameter 1, separator '*', parameter 2.\n", 49);
		return ;
	}
	*s2++ = '\0';
	printf("   strcmp: |%d|\n", strcmp(s1, s2));
	printf("ft_strcmp: |%d|\n", ft_strcmp(s1, s2));
	printf("s1 |%s|\n", s1);
	printf("s2 |%s|\n", s2);
}

void	test_write(t_all *all)
{
	int	rax;
	int	rax_ft;

	write(1, "==============================\n", 32);
	write(1, "| 4.        ft_write         |\n", 32);
	write(1, "==============================\n", 32);
	write(1, "|", 1);
	rax = write(1, all->space, strlen(all->space));
	write(1, "|", 1);
	write(1, "\n", 1);
	write(1, "|", 1);
	rax_ft = ft_write(1, all->space, strlen(all->space));
	write(1, "|", 1);
	write(1, "\n", 1);
	printf("rcx    = %d\nrcx_ft = %d\n", rax, rax_ft);
}
