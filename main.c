/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:23:33 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/09/15 00:38:14 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int 	fd;
	char	*line;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n",line );
		free(line);
	}
	free(line); //for free last line
	return (0);
}
