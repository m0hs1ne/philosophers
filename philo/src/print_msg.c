/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:17:20 by mel-hada          #+#    #+#             */
/*   Updated: 2022/05/19 07:51:41 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/philo.h>

static char	*get_clr(int msg)
{
	if (msg == MSG_FORK)
		return (YEL);
	if (msg == MSG_EAT)
		return (GRN);
	if (msg == MSG_SLP)
		return (BLU);
	if (msg == MSG_THK)
		return (CIA);
	if (msg == MSG_RIP)
		return (RED);
	return ("Error: not valid msg id");
}

static char	*get_msg(int msg)
{
	if (msg == MSG_FORK)
		return ("has taken a fork🍴");
	if (msg == MSG_EAT)
		return ("is eating🍕");
	if (msg == MSG_SLP)
		return ("is sleeping💤");
	if (msg == MSG_THK)
		return ("is thinking🤔");
	if (msg == MSG_RIP)
		return ("died💀");
	return ("Error: not valid msg id");
}

void	print_msg(t_philo *philo, int msg)
{
	size_t	t;

	t = get_time() - philo->tab->t_init;
	pthread_mutex_lock(&philo->tab->print);
	if (!philo->tab->dead && !philo->tab->eaten_all)
	{
		printf(DGRAY"%6ld ms", t);
		printf(MGN" %3d ", philo->id);
		printf("%s%s", get_clr(msg), get_msg(msg));
		if (msg == MSG_EAT)
			printf(" #%d", philo->eat_cnt);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->tab->print);
}
