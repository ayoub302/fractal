/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sai <aben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:31:33 by aben-sai          #+#    #+#             */
/*   Updated: 2025/01/21 16:33:14 by aben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractal.h"

void	error_message(char *text, int mode);
void	ft_strlower(char *str);
void	print(char *str, int fd);
void	show_help(void);

#endif
