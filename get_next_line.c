/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:24:39 by rhong             #+#    #+#             */
/*   Updated: 2022/06/24 19:31:31 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len != 0)
	{
		*(unsigned char *)(b + len - 1) = (unsigned char)c;
		len--;
	}
	return (b);
}

static int	ft_strchr(const char *s, int c)
{
	int	ret;

	ret = 0;
	while (s[ret])
	{
		if (s[ret] == c)
			return (ret);
		ret++;
	}
	if (c == 0)
		return (ret);
	return (-1);
}

static char	*update_pre_ret(char *pre[1], char *ret)
{
	char	*pre_temp;
	char	*ret_temp;
	int		n_index;

	pre_temp = pre[0];
	ret_temp = ret;
	n_index = ft_strchr(pre[0], '\n');
	if (n_index >= 0)
	{
		ret = ft_strjoin(ret, pre[0]);
		pre[0] = ft_substr(pre[0], n_index + 1);
	}
	else
	{
		ret = ft_strjoin(ret, pre[0]);
		pre[0] = 0;
	}
	if (pre_temp)
		free(pre_temp);
	if (ret_temp)
		free(ret_temp);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*pre[1];
	char		*ret;
	char		buff[BUFFER_SIZE + 1];
	int			read_flag;

	pre[0] = 0;
	ret = 0;
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	read_flag = read(fd, buff, BUFFER_SIZE);
	while (read_flag > 0)
	{
		pre[0] = ft_strjoin(pre[0], buff);
		if (ft_strchr(pre[0], '\n') >= 0)
			return (update_pre_ret(pre, ret));
		ret = update_pre_ret(pre, ret);
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		read_flag = read(fd, buff, BUFFER_SIZE);
	}
	return (ret);
}
