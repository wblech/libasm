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
