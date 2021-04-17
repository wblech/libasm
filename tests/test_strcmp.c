/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:07:32 by wbertoni          #+#    #+#             */
/*   Updated: 2021/04/17 16:47:26 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libasm.h"

static void	test_strcmp2(char *str1, char *str2)
{
	int			ret1;
	int			ret2;
	static int	count;

	count = count + 1;
	printf("\033[1;34mTest #%d\033[0m\n", count);
	printf("String #1 : >|%s|<\n", str1);
	printf("String #2 : >|%s|<\n", str2);
	ret1 = strcmp(str1, str2);
	ret2 = ft_strcmp(str1, str2);
	printf("strcmp    ret : %d\n", ret1);
	printf("ft_strcmp ret : %d\n", ret2);
	if ((ret1 == ret2) || (ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0))
		printf("\033[1;32mPassed\033[0m\n\n");
	else
		printf("\033[1;31mFailed\033[0m\n\n");
}

void		test_strcmp(void)
{
	char long_str1[1024];
	char long_str2[1024];

	printf("\n\033[1;32m<----------- Test ft_strcmp ----------->\033[0m\n\n");
	memset(long_str1, 48, 1024);
	memset(long_str2, 48, 1024);
	long_str1[1023] = '\0';
	long_str2[1023] = '\0';
	test_strcmp2("Hello World!", "Hello Zorld!");
	test_strcmp2("Fromage", "Fromage");
	test_strcmp2("43", "42");
	test_strcmp2("42", "43");
	test_strcmp2("Ornitorinc", "Ornitorincus");
	test_strcmp2("", "Z");
	test_strcmp2("Z", "");
	test_strcmp2("\t", "Tab");
	test_strcmp2("\0", "\0");
	test_strcmp2("\0", "NULL");
	test_strcmp2("NULL", "\0");
	test_strcmp2(long_str1, long_str2);
	long_str2[512] = 'X';
	test_strcmp2(long_str1, long_str2);
	test_strcmp2(long_str2, long_str1);
	test_strcmp2("ɸ", "ɸ");
	test_strcmp2("ɸ", "۩");
}
