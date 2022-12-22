/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_var.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:05:28 by mluik             #+#    #+#             */
/*   Updated: 2022/10/12 20:58:28 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_VAR_H
# define GL_VAR_H

/* Declaring only global variable in program. 
	Used to store exit status for signals. */
extern volatile sig_atomic_t		g_shutdown_flag;

#endif