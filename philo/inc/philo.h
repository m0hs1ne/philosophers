/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:15:02 by mel-hada          #+#    #+#             */
/*   Updated: 2022/06/24 11:29:50 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define NOCOL "\033[0m"
# define RED "\033[1;31m"
# define YEL "\033[1;33m"
# define ORG "\033[0;33m"
# define GRN "\033[1;32m"
# define CIA "\033[1;36m"
# define DGRAY "\033[1;90m"
# define BLU "\033[1;34m"
# define MGN "\033[1;35m"

enum e_msg {
	MSG_FORK = 0,
	MSG_EAT,
	MSG_SLP,
	MSG_THK,
	MSG_RIP
};

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	size_t			last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*r_philo;
	struct s_philo	*l_philo;
	struct s_table	*tab;
}	t_philo;

typedef struct s_table
{
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				n_eat;
	int				n_philos;
	int				eaten_all;
	int				dead;
	size_t			t_init;
	t_philo			*philos;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
}	t_table;

/* utils.c */
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_putnbr_fd(int n, int fd);
int		handle_args(int argc, char *argv[], t_table *tab);
void	print_msg(t_philo *philo, int msg);
void	*philo_life(void *arg);
int		check_dead(t_table *tab);
size_t	get_time(void);
void	hypnos(t_table *tab, size_t t_slp);

#endif
