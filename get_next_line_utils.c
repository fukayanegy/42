#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;
	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_copy_newline_after(const char *s)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (s == NULL)
		return ("");
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	j = ft_strlen(s) - i;
	result = malloc(sizeof(char) * (j + 1));
	if (result == NULL)
		return (NULL);
	if (j < 1)
		return ("");
	j = 0;
	i++;
	while (i < ft_strlen(s))
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}

bool	ft_exist_newline(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (false);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

char	*ft_copy_newline_before(const char *s)
{
	char	*newline;
	size_t	i;
	size_t	j;
	if (s == NULL)
		return ("");
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			newline = malloc(sizeof(char) * (i + 1));
			if (newline == NULL)
				return (NULL);
			j = 0;
			while (j < i)
			{
				newline[j] = s[j];
				j++;
			}
			newline[j] = '\0';
			return (newline);
		}
		i++;
	}
	return ((char *)s);
}

static void	ft_strjoin_support(char const *s1, char const *s2, char *res)
{
	size_t	i;
	size_t	s_1_len;
	size_t	s_2_len;
	s_1_len = ft_strlen(s1);
	s_2_len = ft_strlen(s2);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[s_1_len + i] = s2[i];
		i++;
	}
	res[s_1_len + s_2_len] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s_1_len;
	size_t		s_2_len;
	char		*res;
	const char	*empty_str = "";
	if (s1 == NULL && s2 != NULL)
		return (ft_strjoin(s2, empty_str));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strjoin(s1, empty_str));
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	s_1_len = ft_strlen(s1);
	s_2_len = ft_strlen(s2);
	res = malloc((sizeof(char)) * (s_1_len + s_2_len + 1));
	if (res == NULL)
		return (NULL);
	ft_strjoin_support(s1, s2, res);
	return (res);
}

int	ft_copy_newline_before_test(const char *original_s, char *copy_s)
{
	char	*newline;
	size_t	i;
	size_t	j;
	if (original_s == NULL)
	{
		return (2);
	}
	i = 0;
	while (original_s[i] != '\0')
	{
		if (original_s[i] == '\n')
		{
			newline = malloc(sizeof(char) * (i + 1));
			if (newline == NULL)
			{
				return (3);
			}
			j = 0;
			while (j < i)
			{
				newline[j] = original_s[j];
				j++;
			}
			newline[j] = '\0';
			copy_s = newline;
			return (0);
		}
		i++;
	}
	return (1);
}
