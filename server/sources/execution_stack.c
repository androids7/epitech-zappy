/*
** execution_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Mon Jun  7 22:05:23 2010 alban roux
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "x.h"

void		display_stack(t_stack *execution)
{
  t_stack	*stack;
  int		i;

  i = 0;
  stack = execution;
  printf("--- Stack Begin ---\n");
  while (stack)
    {
      printf("[%d] Timestamp(%d) ", i++, (int)stack->timestamp.tv_sec);
      printf("Id Commande (%d) FD Player (%d)\n", 
	     stack->id_cmd, stack->fd_player);
      stack = stack->next;
    }
  printf("--- Stack End ---\n");
}

void			add_cmd_onstack(t_env *e, int fd_player, int id_cmd)
{
  struct timeval	timestamp;
  t_stack		*newcmd;
  t_stack		*current;

  current = e->execution;
  gettimeofday(&timestamp, NULL);
  newcmd = Xmalloc(sizeof(*newcmd));
  newcmd->timestamp = timestamp;
  newcmd->id_cmd = id_cmd;
  newcmd->fd_player = fd_player;
  if (e->execution == NULL)
    newcmd->next = NULL;
  else
    newcmd->next = current;
  e->execution = newcmd;
  display_stack(e->execution);
}
