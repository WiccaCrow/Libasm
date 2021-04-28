#include "test2.h"

/*************************
 *   1.3. test_strcmp    *
 * ***********************
 * test for ft_strcmp.
 * functiions:
 * 1.1.1. logs_strlen_strcmp
 * 1.7. test_results;
 */

void	test_strcmp(int orig, int ft)
{
	write(1, "\n|______________|___|___|___|___|___|\n", 39);
	write(1, "|  ft_strcmp   |", 17);
	orig = strcmp("", "12345");
	ft = ft_strcmp("", "12345");
	if (logs_strlen_strcmp(orig, ft, "strcmp", "||\n|12345|"))
		return ;
	orig = strcmp("§", "");
	ft = ft_strcmp("§", "");
	if (logs_strlen_strcmp(orig, ft, "strcmp", "|§|\n||"))
		return ;
	orig = strcmp("good", "good");
	ft = ft_strcmp("good", "good");
	if (logs_strlen_strcmp(orig, ft, "strcmp", "|good|\n|good|"))
		return ;
	orig = strcmp("qqwerty", "q12345");
	ft = ft_strcmp("qqwerty", "q12345");
	if (logs_strlen_strcmp(orig, ft, "strcmp", "|qqwerty|\n|q12345|"))
		return ;
	orig = strcmp("qqwe\0r1ty", "qqwe\0rty");
	ft = ft_strcmp("qqwe\0r1ty", "qqwe\0rty");
	if (logs_strlen_strcmp(orig, ft, "strcmp", "|qqwe\\0r1ty|\n|qqwe\\0rty|"))
		return ;
	write(1, "\n|______________|___|___|___|___|___|\n", 39);
	test_write();
}
