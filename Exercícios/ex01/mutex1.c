/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:31:43 by hmateque          #+#    #+#             */
/*   Updated: 2024/09/15 00:36:18 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Compilar: cc -lpthread mutex1.c
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

void *functionC(); 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; 
int counter = 0; 

int main(void) 
{ 
   int rc1, rc2; 
   pthread_t thread1, thread2; 

   /* Cria threads independentes, cada uma das quais executará functionC */ 

   if( (rc1=pthread_create( &thread1, NULL, &functionC, NULL)) ) 
   { 
      printf("Falha na criação da thread: %d\n", rc1); 
   } 

   if( (rc2=pthread_create( &thread2, NULL, &functionC, NULL)) ) 
   { 
      printf("Falha na criação da thread: %d\n", rc2); 
   } 

   /* Aguarda até que as threads sejam concluídas antes que main continue. A menos que */ 
   /* esperemos, corremos o risco de executar uma saída que encerrará */ 
   /* o processo e todos os threads antes que eles sejam concluídos. */ 

   pthread_join( thread1, NULL); 
   pthread_join( thread2, NULL); 

   exit(0);
   return (0);
} 

void *functionC() 
{ 
   pthread_mutex_lock ( &mutex1 ); 
   counter++; 
   printf("Valor do contador: %d\n",counter); 
   pthread_mutex_unlock ( &mutex1 ); 
}