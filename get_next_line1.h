
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 20

//int					get_next_line(const int fd, char **line);
typedef	struct 		s_file
{
	int				fd;
	char			*content_rest;
	struct t_file	*next;
}					t_file;


#endif