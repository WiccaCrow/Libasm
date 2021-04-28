#ifndef TEST_H
# define TEST_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include "../gnl/get_next_line.h"

typedef struct s_all {
	char	*dst;
	char	*line;
	char	*line_copy;
	int		fd;
	char	*space;
	int		gnl;
	int		i;
}	t_all;

/*************************
 * functions in libasm.a *
 * ***********************
 */
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fd, void *s, int s_len);
int		ft_read(int fd, void *buf, int buf_size);
char	*ft_strdup(const char *s1);
/*************************
 * functions for testing *
 * ***********************
 */
void	start_all(t_all *all);
void	parser_func_name(t_all *all);
void	main_free(t_all *all);
void	test_strlen(t_all *all);
void	test_strcpy(t_all *all);
void	test_strcmp(t_all *all);
void	test_write(t_all *all);
void	test_read_1(t_all *all, int fd1, int fd2);
void	test_read_2(t_all *all, int *fd1, int *fd2);
void	test_strdup(t_all *all);
void	exit_clean(t_all *all);

#endif