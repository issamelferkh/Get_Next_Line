#include "../libft/libft.h"
#include "get_next_line.h"

void	ft_listnew(int	fd, char *content_rest, t_file **new)
{

 	(*new)->fd = fd;
 	(*new)->content_rest = ft_strnew(ft_strlen(content_rest));
 	(*new)->content_rest = ft_strcpy((*new)->content_rest, content_rest);
 	(*new)->next = NULL;
}

static	unsigned	int		ft_line_len(char *tab)
{
	unsigned int			i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	return (i);
}

char					*ft_line_get(char *tab)
{
	tab = ft_strrev(tab);
	if (ft_strchr(tab, '\n') != NULL)
	{
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1); // +1 pour (pas cpy)eviter \n 
		tab = ft_strrev(tab);
		return (tab);
	}
	if (ft_line_len(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		tab = ft_strrev(tab);
		return (tab);
	}
	return (NULL);
}

char					*ft_line_rest(char *tab)
{
	//char *tmp;

	//tmp = (char *)malloc(sizeof(tab) * ft_strlen(tab));
	if (ft_strchr(tab, '\n') != NULL)
	{
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1); // +1 pour (pas cpy)eviter \n 
		return (tab);
	}
	if (ft_line_len(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		return (tab);
	}
	return (NULL);
}


int	 get_next_line(int const fd, char **line) // is int not void + **line
{
	t_file 	*new;
	char 	*tab;
	int 	re;

	tab = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	// while (!(ft_strchr(tab[fd], '\n')) && (re = read(fd, tab, BUFF_SIZE)) > 0)
	// {
	// 	tab[re] = '\0';
	// }
	re = read(fd, tab, BUFF_SIZE);
	tab[re] = '\0';

	new = (t_file*)malloc(sizeof(t_file));
	//check malloc error 
	ft_listnew(fd, ft_line_rest(ft_strdup(tab)),&new);
	printf("all the line 	:%s\n",tab);
	printf("fd 		:%d\n",new->fd);
	printf("line readed 	:%s \n",ft_line_get(ft_strdup(tab)));
	printf("line rest 	:%s \n",new->content_rest);

	if (fd == 3) // check fd is t_file
	{
		new = (t_file*)malloc(sizeof(t_file));
		//check malloc error 
		tab = ft_strjoin(new->content_rest, tab);
		printf("all the line 	:%s\n",tab);
		printf("fd 		:%d\n",new->fd);
		printf("line readed 	:%s \n",ft_line_get(ft_strdup(tab)));
		printf("line rest 	:%s \n",new->content_rest);
	}
	else // creat new list
	{
		new = (t_file*)malloc(sizeof(t_file));
		//check malloc error 
		ft_listnew(fd, ft_line_rest(ft_strdup(tab)),&new);
		printf("all the line 	:%s\n",tab);
		printf("fd 		:%d\n",new->fd);
		printf("line readed 	:%s \n",ft_line_get(ft_strdup(tab)));
		printf("line rest 	:%s \n",new->content_rest);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int 	fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			printf("can't open the folder %s\n", av[1]);

		get_next_line(fd, &line);
		get_next_line(fd, &line);
		close(fd);
	}
	else 
		printf("File name missing\n");
	return (0);
}