/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:07:37 by wbertoni          #+#    #+#             */
/*   Updated: 2021/04/17 16:34:15 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "main.h"

#define STR_TEST "1234567"

static void	test_all(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
}

static void	select_function(char c)
{
	int						i;
	static t_array_tests	func[7] = {test_strlen, test_strcpy, test_strcmp,
		test_write, test_read, test_strdup, test_all};

	i = 0;
	while (c != STR_TEST[i])
		i++;
	(*func[i])();
}

static void	doc_args(void)
{
	printf("\n\033[1;33mEvaluation Libasm of wbertoni\033[0m\n\n");
	printf("1 : ft_strlen\n");
	printf("2 : ft_strcpy\n");
	printf("3 : ft_strcmp\n");
	printf("4 : ft_write\n");
	printf("5 : ft_read\n");
	printf("6 : ft_strdup\n");
	printf("7 : all tests\n");
	printf("8 : exit\n");
	printf("Select a test : ");
}

int			main(void)
{
	int c;

	c = '0';
	system("clear");
	while (!strchr("12345678", c))
	{
		doc_args();
		c = getchar();
		if (!strchr("12345678", c))
		{
			printf("\n\n\033[1;31mInvalid selection\033[0m\n");
			while ((c = getchar()) != '\n' && c != EOF)
				;
		}
	}
	if (c == '8')
		return (0);
	select_function(c);
	return (0);
}
