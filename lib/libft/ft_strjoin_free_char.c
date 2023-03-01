#include "libft.h"
#include "../ft_printf/ft_printf.h"

static void	free_strs(char const *s1, int free_s1)
{
	if (free_s1)
		free((char *)s1);
}

static	int	ft_strlen_int(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin_free_char(char const *s1, int const c, int free_s1)
{
	char	*r_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r_string = (char *) malloc (ft_strlen_int(s1) + 2);
	if (r_string == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		r_string[j] = s1[i];
		i++;
		j++;
	}
	r_string[j] = c;
	j++;
	r_string[j] = '\0';
	return (free_strs(s1, free_s1), r_string);
}
