/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 00:27:55 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/25 15:07:25 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	char	*join;
	size_t	len;
	size_t	i;
	size_t	start;

	join = NULL;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_strdel(&s1);
		return (NULL);
	}
	ft_strcpy(join, s1);
	start = ft_strlen(s1);
	while (i + start < len)
	{
		join[start + i] = s2[i];
		i++;
	}
	ft_strdel(&s1);
	join[start + i] = '\0';
	return (join);
}
