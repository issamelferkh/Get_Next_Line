/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:11:45 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/09 20:11:49 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static	unsigned	int	ft_line_len(char *tab)
{
	unsigned int			i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	return (i);
}

static char	*ft_line_rest(char *tab)
{
	if (ft_strchr(tab, '\n'))
	{
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1);
		return (tab);
	}
	if (ft_line_len(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		return (tab);
	}
	return (NULL);
}

// static char	*ft_line_get(char *tab)
// {
// 	tab = ft_strrev(tab);
// 	if (ft_strchr(tab, '\n') != NULL)
// 	{
// 		ft_strcpy(tab, ft_strchr(tab, '\n') + 1); // +1 pour (pas cpy)eviter \n 
// 		tab = ft_strrev(tab);
// 		return (tab);
// 	}
// 	if (ft_line_len(tab) > 0)
// 	{
// 		ft_strcpy(tab, ft_strchr(tab, '\0'));
// 		tab = ft_strrev(tab);
// 		return (tab);
// 	}
// 	return (NULL);
// }

int							get_next_line(int const fd, char **line)
{
	char					*tmp;
	char					buff[BUFF_SIZE + 1];
	static	char			*tab[4867]; 
	int						ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while ((ft_strchr(tab[fd], '\n') == NULL) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0'; //for test
		printf("i am buff --> |%s|\n", buff);
		tmp = tab[fd];
		tab[fd] = ft_strnjoin(tmp, buff, ret);
		printf("i am tab[fd] --> |%s|\n", tab[fd]);
		free(tmp);
	}
	*line = ft_strsub(tab[fd], 0, ft_line_len(tab[fd]));
	if (ft_line_rest(tab[fd]) == NULL)
		return (0);
	return (1);
}
/*******************************************************/
// char 	*tab[3] = "0\0" 
// char 	buff = "12345\0"
// while ((ya pas "\n" in tab[3] && (read(fd, buff, BUFF_SIZE)) > 0)
// {
// char	*tmp = tab[3] = "0\0"
// tab[3] = ft_strnjoin(tmp, buff, ret) = "0\0" + "12345\0" = "12345\0"
// free(tmp); = tmp = NULL
// So
// 	char			*tmp = NULL
// 	char			buff[BUFF_SIZE + 1] = "12345\0"
// 	static	char	*tab[100] = "12345\0"
// }

/*******************************************************/
int	main(int ac, char **av)
{
	int 	fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n",line );
		//printf("%d\n",get_next_line(fd, &line));
		free(line);
	}
	return (0);
}