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

#include "get_next_line.h"

int main(int ac, char **av)
{
	int 	fd;
	int 	i;
	int 	ret;
	char	tab[BUFF_SIZE];

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			printf("can't open the folder %s", av[1]);
		while (read(fd, tab, BUFF_SIZE) > 0)
		{
			if (ft_strchr(tab, '\n') != NULL)
			{
				tab = ft_strch(tab, '\n');
				ret = ft_strlen(tab);
				write (1, tab, ret);
			}
			else
			{
				write(1, tab, BUFF_SIZE);
			}
			i = 1;
			while (++i < BUFF_SIZE)
				tab[i] = '\0';
		}
		close(fd);
	}
	if (ac == 1 )
		printf("File name missing\n");
	return (0);
}
