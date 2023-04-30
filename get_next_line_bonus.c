/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:38:05 by myagiz            #+#    #+#             */
/*   Updated: 2022/11/28 16:46:27 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (0);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

/*
int	main()
{
	int fd = open("a", O_RDONLY);
	int fd2 = open("b", O_RDONLY);

 	char  *line;
			line = get_next_line(fd);
 		write(1, line, ft_strlen(line));
			line = get_next_line(fd2);
 		write(1, line, ft_strlen(line));

}
*/
