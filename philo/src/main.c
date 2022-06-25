/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:16:17 by mel-hada          #+#    #+#             */
/*   Updated: 2022/06/24 11:29:10 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/philo.h>

static int	usage(void)
{
	write(STDERR_FILENO, "Error: invalid arguments (must be integers)\n", 44);
	write(STDERR_FILENO, "Usage: ./philo [N PHILOS] [DIE TIME] [EAT TIME]", 47);
	write(STDERR_FILENO, " [SLEEP TIME] (OPT)[PHILO EAT N TIMES]\n", 39);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_table		*tab;
	pthread_t	*tid;

	tab = (t_table *)malloc(sizeof(t_table));
	if ((argc < 5 || argc > 6) || handle_args(argc, argv, tab))
		return (usage());
	tid = (pthread_t *)malloc(tab->n_philos * sizeof(pthread_t));
	tab->t_init = get_time();
	i = -1;
	while (++i < tab->n_philos)
	{
		tab->philos[i].last_eat = tab->t_init;
		if (pthread_create(&tid[i], NULL, &philo_life, &tab->philos[i]))
		{
			write(STDERR_FILENO, "Error: cannot create thread\n", 28);
			return (EXIT_FAILURE);
		}
		pthread_detach(tid[i]);
	}
	check_dead(tab);
	return (EXIT_SUCCESS);
}
