/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:14:05 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/19 15:48:31 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t	mutex;

static void	*routine(void *thread_void)
{
	pthread_mutex_lock(&mutex);
	printf("Hello Thread\n");
	usleep(20000);
	printf("End thread\n");
	pthread_mutex_unlock(&mutex);
	return (0);
}

int	main(void)
{
	pthread_t		t1;
	pthread_t		t2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}
