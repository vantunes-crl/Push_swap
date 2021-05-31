/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:23:44 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/02 11:29:19 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

int				get_next_line(const int fd, char **line);
int				check_line(char *str);
int				ft_len(const char *str);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*str_join(char const *s1, char const *s2);

#endif
