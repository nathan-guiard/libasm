/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:12:39 by nguiard           #+#    #+#             */
/*   Updated: 2023/04/24 18:24:32 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stddef.h>

long int	ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_write(int fd, char *addr, int count);
size_t		ft_read(int fd, char *addr, int count);
char 		*ft_strdup(const char *src);

#endif