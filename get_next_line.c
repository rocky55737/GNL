#include "get_next_line.h"

int ft_strchr(const char *s, int c)
{
    int  ret;

    ret = 0;
    while (s[ret])
    {
        if ((unsigned char)s[ret] == (unsigned char)c)
        {
            return (ret);
        }
        ret++;
    }
    if (c == 0)
    {
        return (ret);
    }
    return (-1);
}

char *update_pre_ret(char *pre[1], char *ret)
{
    char *pre_temp;
    char *ret_temp;
    int n_index;

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
    free(pre_temp);
    free(ret_temp);
    return (ret);
}

char *get_next_line(int fd)
{
    static char *pre[1];
    char *ret;
    char buff[BUFFER_SIZE + 1];
    int read_flag;

    while (1)
    {
        if (pre[0])
        {
            ret = update_pre_ret(pre, ret);
            if (ft_strchr(ret, '\n') >= 0)
            {
                return (ret);
            }
        }
        read_flag = read(fd, buff, BUFFER_SIZE);
        if (read_flag < 0)
        {
            free(ret);
            return (0);
        }
        else if (read_flag == 0)
        {
            return (ret);
        }
        pre[0] = ft_strjoin(pre[0], buff);
    }
}