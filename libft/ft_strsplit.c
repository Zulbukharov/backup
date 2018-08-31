/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:51:28 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/27 19:23:46 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char *s, char c)
{
	unsigned int w;

	w = 0;
	if (*s == c)
		s++;
	while (*s)
	{
		if ((*(s) != c && *(s - 1) == c))
			w++;
		else if (w == 0 && *s != c && *s)
			w = 1;
		s++;
	}
	return (w);
}

static int			len(char *s, char c, unsigned int j)
{
	unsigned int k;
	unsigned int i;

	i = j;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k++;
			i++;
		}
		else
			break ;
	}
	return (k);
}

static void			ft_word_ret(char *s, char c, unsigned int *j, char *word)
{
	unsigned int	w;

	w = 0;
	while (s[*j] && s[*j] != c)
	{
		word[w] = s[*j];
		w++;
		(*j)++;
	}
	word[w] = '\0';
}

char				**ft_strsplit(char *s, char c)
{
	char			**p;
	unsigned int	j;
	unsigned int	i;
	char			*word;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!p)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		word = (char *)malloc(sizeof(char) * (len(s, c, j)));
		ft_word_ret(s, c, &j, word);
		p[i] = word;
		i++;
	}
	p[i] = NULL;
	return (p);
}
