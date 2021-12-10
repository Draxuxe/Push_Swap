/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:21:04 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 18:49:04 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"

/* Fonction principale */

char	*get_next_line(int fd);

/* Fonctions utiles */

int		ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy_gnl(char	*dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif
