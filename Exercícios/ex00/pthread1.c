/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:57:35 by hmateque          #+#    #+#             */
/*   Updated: 2024/09/15 00:22:47 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Compilador C: cc -lpthread pthread1.c
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*print_message_function(void *ptr);

int	main(void)
{
	char	*message1;
	char	*message2;

	pthread_t thread1, thread2;
	message1 = "Thread 1";
	message2 = "Thread 2";
	int iret1, iret2;
	/* Cria threads independentes, cada uma das quais executará a função */
	iret1 = pthread_create(&thread1, NULL, print_message_function,
			(void *)message1);
	iret2 = pthread_create(&thread2, NULL, print_message_function,
			(void *)message2);
	/* Aguarda até que as threads sejam concluídas antes que o main continue. A menos que */
	/* esperemos, corremos o risco de executar um exit que encerrará */
	/* o processo e todas as threads antes que elas sejam concluídas. */
	pthread_join(thread2, NULL);
	pthread_join(thread1, NULL);
	printf("Thread 1 retorna: %d\n", iret1);
	printf("Thread 2 retorna: %d\n", iret2);
	exit(0);
	return (0);
}

void	*print_message_function(void *ptr)
{
	char *message;
	message = (char *)ptr;
	printf("%s \n", message);
}