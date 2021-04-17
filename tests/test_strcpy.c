/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:01:45 by wbertoni          #+#    #+#             */
/*   Updated: 2021/04/17 16:03:16 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "main.h"

static void	test_strcpy2(char *src)
{
	char		dest_strcpy[1024];
	char		dest_ft_strcpy[1024];
	static int	count;

	count = count + 1;
	printf("\033[1;34mTest #%d\033[0m\n", count);
	printf("String SRC            : >|%s|<\n", src);
	strcpy(dest_strcpy, src);
	ft_strcpy(dest_ft_strcpy, src);
	printf("String DEST strcpy    : >|%s|<\n", dest_strcpy);
	printf("String DEST ft_strcpy : >|%s|<\n", dest_ft_strcpy);
	if (!strcmp(dest_strcpy, dest_ft_strcpy))
		printf("\033[1;32mPassed\033[0m\n\n");
	else
		printf("\033[1;31mFailed\033[0m\n\n");
}

void		test_strcpy(void)
{
	char long_str[1024];

	printf("\n\033[1;32m<----------- Test ft_strcpy ----------->\033[0m\n\n");
	memset(long_str, 48, 1024);
	long_str[1023] = '\0';
	test_strcpy2("Hello World!");
	test_strcpy2("Otters are carnivorous mammals in the subfamily Lutrinae.");
	test_strcpy2("42");
	test_strcpy2("Cheese is life");
	test_strcpy2("Life is\tcheese");
	test_strcpy2("\0");
	test_strcpy2(" ");
	test_strcpy2("\t");
	test_strcpy2("\0hello");
	test_strcpy2("DOGE\0COIN");
	test_strcpy2("你好世界!");
	test_strcpy2(long_str);
}
