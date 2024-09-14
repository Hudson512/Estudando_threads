/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:40:16 by hmateque          #+#    #+#             */
/*   Updated: 2024/09/15 00:41:48 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Compilar: cc -lpthread join1.c
*/
#include <pthread.h>
#include <stdio.h>

#define NTHREADS 10

void			*thread_function(void *);
pthread_mutex_t	mutex1 = PTHREAD_MUTEX_INITIALIZER;
int				counter = 0;

int	main(void)
{
	pthread_t	thread_id[NTHREADS];

	int i, j;
	for (i = 0; i < NTHREADS; i++)
	{
		pthread_create(&thread_id[i], NULL, thread_function, NULL);
	}
	for (j = 0; j < NTHREADS; j++)
	{
		pthread_join(thread_id[j], NULL);
	}
	/* Agora que todas as threads estão completas,
		posso imprimir o resultado final. */
	/* Sem a junção, eu poderia imprimir um valor antes que todas as threads */
	/* fossem concluídas. */
	printf("Valor final do contador: %d\n", counter);
	return (0);
}

void	*thread_function(void *dummyPtr)
{
	printf("Número do thread %ld\n", pthread_self());
	pthread_mutex_lock(&mutex1);
	counter++;
	pthread_mutex_unlock(&mutex1);
}