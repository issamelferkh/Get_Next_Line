static int		ft_read(char **str, int fd)
{
	int		ret;
	char	*s;
	char	buf[BUFF_SIZE + 1];

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	s = *str;
	*str = ft_strjoin(*str, buf);
	if (*s != 0)
		free(s);
	return (ret);
}

static	int		ft_read(char **str, int fd)