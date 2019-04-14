/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:02:37 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/12 00:30:33 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

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

static char					*ft_line_rest(char *tab)
{
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

/*int							get_next_line(int const fd, char **line)
{
	char					*tmp;
	char					buff[BUFF_SIZE + 1];
	static	char			tab; // *tab[256]
	int						ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(tab[fd], '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strnjoin(tmp, buff, ret);
		free(tmp);
	}
	*line = ft_strsub(tab[fd], 0, ft_linelen(tab[fd]));
	if (ft_line(tab[fd]) == NULL)
		return (0);
	return (1);
}*/

int		main(int ac, char **av)
{
	int		len;
	int 	fd;
	int 	i;
	int 	ret;
	char	tab[BUFF_SIZE];
	char	tmp[BUFF_SIZE] = {};

	if (ac == 2)
	{

		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			printf("can't open the folder %s\n", av[1]);
		read(fd, tab, BUFF_SIZE);
		printf("*len of the line readed	:%d\n", ft_line_len(tab));
		printf("*all the line 		:%s\n", tab);
		printf("*line get 		:%s\n", ft_line_get(ft_strdup(tab)));
		tmp = ft_strcat(tmp, ft_line_rest(ft_strdup(tab)));
		printf("*line rest		:%s\n", ft_line_rest(ft_strdup(tab)));

		/*
		
		printf("ft_strchr 		:%s\n", ft_strchr(ft_strdup(av[1]), 32));
		*/
		//printf("ft_strchr 		:%s\n", ft_strchr(ft_strdup(av[1]), 32));
		

		/*if (ft_strchr(tab, '\n') == NULL)
		{
			printf("pas ligne\n");
		}
		else
		{
			// ft_line_get(ft_strdup(tab));
			// write(1, tab, ft_strlen(tab));
			write(1, ft_line_get(tab), ft_strlen(tab));
			printf("ligne\n");
		}*/
		/*
		write(1, tab, BUFF_SIZE);
		i = 1;
		while (++i < BUFF_SIZE)
			tab[i] = '\0';
			*/
		close(fd);
	}
	else 
		printf("File name missing\n");
	return (0);
}