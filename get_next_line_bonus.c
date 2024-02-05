#include "get_next_line_bonus.h"

char	*next_line(char *new_line)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	while (new_line[i] != '\0' && new_line[i] != '\n')
		i++;
	if (new_line[i] == '\0')
	{
		free(new_line);
		return (NULL);
	}
	aux = ft_calloc((ft_strlen(new_line) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (new_line[i] != '\0')
		aux[j++] = new_line[i++];
	free(new_line);
	if (aux[0] == '\0')
	{
		free(aux);
		return (NULL);
	}
	return (aux);
}

char	*clean_line(char *new_line)
{
	char	*aux;
	int		i;

	i = 0;
	if (new_line[i] == '\0')
		return (NULL);
	while (new_line[i] != '\0' && new_line[i] != '\n')
		i++;
	aux = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (new_line[i] != '\0' && new_line[i] != '\n')
	{
		aux[i] = new_line[i];
		i++;
	}
	if (new_line[i] != '\0' && new_line[i] == '\n')
		aux[i++] = '\n';
	return (aux);
}

char	*free_buffer(char *new_line, char *buf)
{
	char	*aux;

	aux = ft_strjoin(new_line, buf);
	free(new_line);
	return (aux);
}

char	*read_line(int fd, char *new_line)
{
	char	*tmp;
	int		buf;

	if (!new_line)
		new_line = ft_calloc(1, sizeof(char));
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	buf = 1;
	while (buf > 0)
	{
		buf = read(fd, tmp, BUFFER_SIZE);
		if (buf < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[buf] = '\0';
		new_line = free_buffer(new_line, tmp);
		if (ft_strchr_mod(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*new_line[10240];
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (new_line[fd] != NULL)
		{
			free(new_line[fd]);
			new_line[fd] = NULL;
		}
		return (NULL);
	}
	new_line[fd] = read_line(fd, new_line[fd]);
	return_line = clean_line(new_line[fd]);
	new_line[fd] = next_line(new_line[fd]);
	return (return_line);
}