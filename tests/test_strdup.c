/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:18:44 by wbertoni          #+#    #+#             */
/*   Updated: 2021/04/17 16:19:01 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "main.h"

static void	test_strdup2(char *src)
{
	char		*dest_strdup;
	char		*dest_ft_strdup;
	static int	count;

	count = count + 1;
	printf("\033[1;34mTest #%d\033[0m\n", count);
	printf("String SRC            : >|%s|<\n", src);
	dest_strdup = strdup(src);
	dest_ft_strdup = ft_strdup(src);
	printf("String DEST strdup    : >|%s|<\n", dest_strdup);
	printf("String DEST ft_strdup : >|%s|<\n", dest_ft_strdup);
	if (!strcmp(dest_strdup, dest_ft_strdup))
		printf("\033[1;32mPassed\033[0m\n\n");
	else
		printf("\033[1;31mFailed\033[0m\n\n");
	free(dest_strdup);
	free(dest_ft_strdup);
}

void		test_strdup(void)
{
	char long_str[1024];

	printf("\n\033[1;32m<----------- Test ft_strdup ----------->\033[0m\n\n");
	memset(long_str, 48, 1024);
	long_str[1023] = '\0';
	test_strdup2("Hello World!");
	test_strdup2("Otters are carnivorous mammals in the subfamily Lutrinae.");
	test_strdup2("42");
	test_strdup2("Cheese is life");
	test_strdup2("Life is\tcheese");
	test_strdup2("\0");
	test_strdup2(" ");
	test_strdup2("\t");
	test_strdup2("\0hello");
	test_strdup2("hello\0");
	test_strdup2("你好世界!");
	test_strdup2(long_str);
}
