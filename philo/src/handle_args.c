/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:15:52 by mel-hada          #+#    #+#             */
/*   Updated: 2022/06/22 19:22:22 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/philo.h>

static int	check_nbrs_valid(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '-')
			return (1);
		else if (argv[i][0] == '+')
			j++;
		if (!ft_isdigit(argv[i][j + 1]))
			return (1);
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

static int	check_is_int(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (*s == '+' && s++)
		len--;
	while (*s == '0' && *s && len--)
		s++;
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	if (ft_strncmp(s, "2147483648", 10) >= 0)
		return (1);
	return (0);
}

static int	check_args(int argc, char *argv[])
{
	int	i;

	if (check_nbrs_valid(argc, argv))
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (check_is_int(argv[i]))
			return (1);
	}
	return (0);
}

static void	initialise_tab(t_table *tab)
{
	int	i;

	tab->dead = 0;
	tab->eaten_all = 0;
	tab->philos = (t_philo *)malloc(tab->n_philos * sizeof(t_philo));
	i = -1;
	while (++i < tab->n_philos)
	{
		tab->philos[i].id = i + 1;
		tab->philos[i].tab = tab;
		tab->philos[i].eat_cnt = 0;
		if (i + 1 == tab->n_philos)
			tab->philos[i].r_philo = &tab->philos[0];
		else
			tab->philos[i].r_philo = &tab->philos[i + 1];
		if (i == 0)
			tab->philos[i].l_philo = &tab->philos[tab->n_philos - 1];
		else
			tab->philos[i].l_philo = &tab->philos[i - 1];
		pthread_mutex_init(&tab->philos[i].fork, NULL);
	}
	pthread_mutex_init(&tab->print, NULL);
	pthread_mutex_init(&tab->check, NULL);
}

int	handle_args(int argc, char *argv[], t_table *tab)
{
	if (check_args(argc, argv))
		return (1);
	tab->n_philos = ft_atoi(argv[1]);
	tab->t_die = ft_atoi(argv[2]);
	tab->t_eat = ft_atoi(argv[3]);
	tab->t_slp = ft_atoi(argv[4]);
	tab->n_eat = -1;
	if (argc == 6)
		tab->n_eat = ft_atoi(argv[5]);
	initialise_tab(tab);
	return (0);
}
