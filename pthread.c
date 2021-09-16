/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:01:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/16 12:49:29 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

// thread_void : 스레드로 호출할 함수 파라미터를 void 포인터로 안주면 warning이 뜬다.
static void	*routine(void *thread_void)
{
	int	*p;

	p = (void *)thread_void;
	printf("Hello Thread\n");
	usleep(2000000);
	printf("End thread\n");
	return (0);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
