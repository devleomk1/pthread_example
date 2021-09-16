/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:01:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/16 14:33:53 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

// void *thread_void : pthread_create()함수의 스레드로 분기할 함수는 void* 타입만 사용가능하고,
// 매개변수도 void* 이어야만 사용 가능하다. ! 중요 !
static void	*routine(void *thread_void)
{
	int	*p;

	p = (void *)thread_void;
	printf("Hello Thread\n");
	usleep(200000);
	printf("End thread\n");
	return (0);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	//pthread를 생성하는 순간 main문과는 별도로 routine()함수가 돌아간다.
	usleep(1000000);
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
	pthread_detach(t1);
	pthread_detach(t2);

	printf("THE END\n");
	return (0);
}
