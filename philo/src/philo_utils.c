/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:17:04 by mel-hada          #+#    #+#             */
/*   Updated: 2022/06/24 11:29:40 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/philo.h>

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	hypnos(t_table *tab, size_t t_slp)
{
	size_t	t;

	t = get_time();
	while (!(tab->dead))
	{
		if (get_time() - t >= t_slp)
			break ;
		usleep(100);
	}
}
