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
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1); //leak
		return (tab);
	}
	if (ft_line_len(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		//*tab = '\0';
		return (tab);
	}
	return (NULL);
}

int							get_next_line(int const fd, char **line)
{
	char					*tmp;
	char					buff[BUFF_SIZE + 1];
	static	char			*tab[4867]; 
	int						r;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL) //leak
		return (-1);
	while (!(ft_strchr(tab[fd], '\n')) && (r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0'; //for test
		// printf("i am buff --> |%s|\n", buff);
		tmp = tab[fd];
		tab[fd] = ft_strnjoin(tmp, buff, r); // look to strjoin
		// printf("i am tab[fd] --> |%s|\n", tab[fd]);
		free(tmp);
	}
	*line = ft_strsub(tab[fd], 0, ft_line_len(tab[fd]));
	tmp = ft_line_rest(tab[fd]);
	//free(tab[fd]);
	return (tmp ? 1 : 0);
}

int	main(int ac, char **av)
{
	int 	fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		//printf("%s\n",line );
		//printf("%d\n",get_next_line(fd, &line));
		free(line);
	}
	return (0);
}