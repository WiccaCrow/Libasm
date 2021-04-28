#ifndef TEST2_H
# define TEST2_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_write_read {
	int		orig;
	int		ft;
	char	flag_wr;
	int		flag_buf;
	char	buf1[31];
	char	buf2[31];
	int		err;
	int		fd1;
	int		fd2;
}	t_wr;

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
void	write_title(void);
void	test_results(int flag);
char	*ft_strjoin(char *s1, char *s2, int j);
void	test_strlen(int len_orig, int len_ft);
int		logs_strlen_strcmp(int len_orig, int len_ft, char *func, char *str);
void	logs_strlen_strcmp_part2(int fd, char *func, char *str, int orig);
void	ft_putnbr_fd(int n, int fd);
void	test_strcpy(void);
int		logs_strcpy_strdup(int flag, char *str_orig, char *str_ft, char *func);
void	test_strcmp(int orig, int ft);
void	test_write(void);
int		test_write_start(t_wr *wr);
int		test_write_str_gnl(t_wr *wr, int fd, int i);
void	test_write_str_gnl_results(t_wr *wr);
int		logs_write_read(t_wr *wr, char *buf1, char *buf2);
void	logs_write_read_2(int fd, t_wr *wr, char *str, char *buf);
void	write_or_read(t_wr *wr, int fd);
void	test_read(int i);
int		test_read_2(char *s, t_wr *wr, int size);
int		test_read_3(char *s, t_wr *wr, int size, int fd);
void	test_strdup(void);
int		test_strdup_do_strdup(char **str_orig, char **str_ft, char *str);
void	test_strdup_free(char **str_orig, char **str_ft);

#endif