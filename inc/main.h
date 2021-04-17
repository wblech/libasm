/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:38:57 by wbertoni          #+#    #+#             */
/*   Updated: 2021/04/17 17:40:28 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libasm.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

typedef void	(*t_array_tests)(void);
void			test_strcpy(void);
void			test_strcmp(void);
void			test_write(void);
void			test_read(void);
void			test_strdup(void);
void			test_strlen(void);

#endif
