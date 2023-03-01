/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:35:49 by anrodri2          #+#    #+#             */
/*   Updated: 2023/03/01 23:57:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_strs(char const *s1, char const *s2, int free_s1, int free_s2)
{
	if (free_s1 == 1)
		free((char *)s1);
	if (free_s2 == 1)
		free((char *)s2);
}

static	int	ft_strlen_int(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin_free(char const *s1, char const *s2,
	int free_s1, int free_s2)
{
	char	*r_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r_string = (char *) malloc (ft_strlen_int(s1) + ft_strlen_int(s2) + 1);
	if (r_string == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		r_string[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		r_string[j] = s2[i];
		i++;
		j++;
	}
	r_string[j] = '\0';
	return (free_strs(s1, s2, free_s1, free_s2), r_string);
}
