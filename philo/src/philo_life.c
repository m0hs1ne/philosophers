/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:16:42 by mel-hada          #+#    #+#             */
/*   Updated: 2022/06/23 10:42:25 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/philo.h>

void	check_meals(t_table *tab)
{
	int	i;

	i = 0;
	while (tab->n_eat != -1 && i < tab->n_philos
		&& tab->philos[i].eat_cnt >= tab->n_eat)
		i++;
	if (i == tab->n_philos)
		tab->eaten_all = 1;
}

int	check_dead(t_table *tab)
{
	int	i;

	while (!tab->eaten_all)
	{
		i = -1;
		pthread_mutex_lock(&tab->check);
		while (!tab->dead && ++i < tab->n_philos)
		{
			if (get_time() - tab->philos[i].last_eat > (size_t)tab->t_die)
			{
				print_msg(&tab->philos[i], MSG_RIP);
				tab->dead = 1;
				return (0);
			}
		}
		if (tab->dead)
			break ;
		check_meals(tab);
		pthread_mutex_unlock(&tab->check);
		usleep(300);
	}
	return (1);
}

static void	philo_eat(t_philo *philo)
{
	t_table	*tab;

	tab = philo->tab;
	pthread_mutex_lock(&philo->fork);
	print_msg(philo, MSG_FORK);
	if (philo->tab->n_philos == 1)
	{
		hypnos(tab, tab->t_die);
		print_msg(philo, MSG_RIP);
		pthread_mutex_unlock(&philo->fork);
		tab->dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->r_philo->fork);
	print_msg(philo, MSG_FORK);
	pthread_mutex_lock(&tab->check);
	philo->eat_cnt++;
	print_msg(philo, MSG_EAT);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&tab->check);
	hypnos(tab, tab->t_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_philo->fork);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	t_table	*tab;

	philo = (t_philo *)arg;
	tab = philo->tab;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!tab->dead && !tab->eaten_all)
	{
		philo_eat(philo);
		print_msg(philo, MSG_SLP);
		hypnos(tab, tab->t_slp);
		print_msg(philo, MSG_THK);
	}
	return (NULL);
}
