#include "test2.h"

/*************************
 *          main         *
 * ***********************
 * functions:
 * 	1.1. test_strlen;
 * 	1.2. test_strcpy;
 * 	1.3. test_strcmp;
 * 	1.4. test_write;
 * 	1.5. test_read;
 * 	1.6. test_strdup;
 * 	1.7. test_results;
 * 	1.8. ft_strjoin;
 * 	1.9. write_title;
 */

int	main(void)
{
	int		fd;
	char	*path;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	path = ft_strjoin(tmp, "/log_test.txt", -1);
	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY,
			S_IRWXU | S_IRWXG | S_IRWXO);
	free(path);
	if (fd > 0)
	{
		close(fd);
		write_title();
		test_strlen(0, 0);
	}
	else
		write(1, "Error:\n cannot open or create file 'log_test.txt'\n", 51);
	return (0);
}

/*************************
 *   1.7. test_results   *
 * ***********************
 * write tests reults OK/KO to stdout.
*/

void	test_results(int flag)
{
	if (flag)
		write(1, " OK", 3);
	else
	{
		write(1, "\x1b[31m", 6);
		write(1, " KO", 3);
		write(1, "\x1b[0m", 5);
	}
	write(1, "|", 2);
}

/*************************
 *     1.8. ft_strjoin   *
 * ***********************
 * Join two strings. Return new string.
 */

char	*ft_strjoin(char *s1, char *s2, int j)
{
	char	*join;
	int		i;

	i = strlen(s1) + strlen(s2);
	join = calloc(i + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			join[i] = s1[i];
	if (s2)
		while ((s2)[++j])
			join[i + j] = (s2)[j];
	join[j + i + 1] = '\0';
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	i = strlen(s2);
	return (join);
}

/*****************************
 *     1.9. ft_write_title   *
 * ***************************
 * Write a title for stdout.
 */

void	write_title(void)
{
	write(1, "____________________________________\n", 38);
	write(1, "____________________________________\n", 38);
	write(1, "|   function   |        tests      |\n", 38);
	write(1, "|     name     |___________________|\n", 38);
	write(1, "|              | 1 | 2 | 3 | 4 | 5 |\n", 38);
	write(1, "|______________|___|___|___|___|___|\n", 38);
}

/* ANSI escape-code
* https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
* GREEN   "\x1b[32m"
* YELLOW  "\x1b[33m"
* BLUE    "\x1b[34m"
* MAGENTA "\x1b[35m"
* CYAN    "\x1b[36m"
* RESET   "\x1b[0m"
* 
* fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
*/
