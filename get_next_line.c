#include "../libft/libft.h"
#include "get_next_line.h"

void	ft_listnew(int	fd, char *content_rest, t_file **content)
{

 	(*content)->fd = fd;
 	(*content)->content_rest = ft_strnew(ft_strlen(content_rest));
 	(*content)->content_rest = ft_strcpy((*content)->content_rest, content_rest);
 	(*content)->next = NULL;
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


void						get_next_line(int const fd, char **line) // is int not void + **line
{
	t_file *content;

	content= (t_file*)malloc(sizeof(t_file));
	//check nmalloc error 
	ft_listnew(fd, ft_line_rest(ft_strdup(*line)),&content);
	printf("fd %d:\n",content->fd);
	printf("line get %s:\n",content->content_rest);


}

int		main(int ac, char **av)
{
	int 	fd;
	char	*tab;

	tab = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	tab[BUFF_SIZE] = '\0';
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			printf("can't open the folder %s\n", av[1]);
		read(fd, tab, BUFF_SIZE);
		get_next_line(fd, &tab);
		close(fd);
	}
	else 
		printf("File name missing\n");
	return (0);
}