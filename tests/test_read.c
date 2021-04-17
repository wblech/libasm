/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:13:27 by wbertoni          #+#    #+#             */
/*   Updated: 2021/04/17 16:18:00 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "main.h"

static void	read_stdin(void)
{
	char buff[1024];

	memset(buff, 0, 1024);
	printf("Test STDIN, Please write some characters to run the test.\n");
	ft_read(STDIN_FILENO, buff, 1024);
	printf("%s\n", buff);
}

static void	print_result(int ret_read, int ret_ft_read, int errno_read)
{
	if (ret_read == ret_ft_read)
		printf("\033[1;32mPassed\033[0m\n\n");
	if (ret_ft_read == -1 && ret_read == -1)
	{
		printf("Both functions return an error.\n");
		printf("Errno read    : %d\n", errno_read);
		printf("Errno ft_read : %d\n\n", errno);
	}
	if (ret_read != ret_ft_read)
		printf("\033[1;31mFailed\033[0m\n\n");
}

static void	test_read3(char *buff_read, char *buff_ft_read, int fd)
{
	int			ret_read;
	int			ret_ft_read;
	int			errno_read;
	static int	count;

	count = count + 1;
	printf("\033[1;34mTest #%d\033[0m\n", count);
	ret_read = read(fd, buff_read, 128);
	lseek(fd, 0, SEEK_SET);
	ret_ft_read = ft_read(fd, buff_ft_read, 128);
	errno_read = errno;
	printf("read buff       : >|%s|<\n", buff_read);
	printf("read return    : %d\n\n", ret_read);
	printf("ft_read buff    : >|%s|<\n", buff_ft_read);
	printf("ft_read return : %d\n", ret_ft_read);
	print_result(ret_read, ret_ft_read, errno_read);
}

static void	test_read2(char *file, bool create_error)
{
	char	buff_write[128];
	char	buff_ft_write[128];
	int		fd;

	memset(buff_write, 0, 128);
	memset(buff_ft_write, 0, 128);
	if (create_error)
	{
		test_read3(buff_write, buff_ft_write, -3);
		return ;
	}
	if (!(fd = open(file, O_RDONLY)))
	{
		printf("Open() has return an error.\n\n");
		return ;
	}
	test_read3(buff_write, buff_ft_write, fd);
	close(fd);
}

void		test_read(void)
{
	printf("\n\033[1;32m<----------- Test ft_read ----------->\033[0m\n\n");
	test_read2("tests_read/test_1_read.txt", 0);
	test_read2("tests_read/test_2_read.txt", 0);
	test_read2("test error", 1);
	test_read2("tests_read/test_4_read.txt", 0);
	test_read2("tests_read/test_5_read.txt", 0);
	test_read2("tests_read/test_6_read.txt", 0);
	test_read2("tests_read/test_7_read.txt", 0);
	read_stdin();
}
