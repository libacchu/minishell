/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:25:51 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/15 19:07:24 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	char *cmd1[4] = {"/bin/ls","ls", "-la", NULL};
	char *cmd2[4] = {"/usr/bin/grep", "grep", "pi", NULL};
	// char *cmd3[4] = {"/bin/cat", "cat", "pipes.c", NULL};
	char *cmd4[4] = {"/usr/bin/grep", "grep", "pipes.c", NULL};
	
	char **cmd[4] = {cmd1, cmd2, cmd4, NULL};
	// char **cmd[3] = {cmd1, cmd2, NULL};
	// char **cmd[4] = {cmd1, NULL};
	int i = 0;
	
	int tmpin = dup(STDIN_FILENO);
	int tmpout = dup(STDOUT_FILENO);
	int fdin = dup(tmpin);
	
	int id;
	int fdout = 0;
	
	int fdpipe[2];
	
	while (cmd[i])
	{
		dup2(fdin, STDIN_FILENO);
		close(fdin);
		
		if (cmd[i + 1] == NULL)
		{
			fdout = dup(tmpout);
		}
		else
		{
			pipe(fdpipe);
			fdout = fdpipe[1];
			fdin = fdpipe[0];
		}
		
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
		
		id = fork();
		if (id == 0)
		{
			execve(cmd[i][0], &cmd[i][1], NULL);
		}
		// else
		// 	waitpid(id, NULL, 0);
		
		dup2(tmpin, STDIN_FILENO);
		dup2(tmpout, STDOUT_FILENO);
		close(tmpin);
		close(tmpout);

		if (id != 0)
			waitpid(id, NULL, 0);
		i++;
	}
	return (0);
}

// int main()
// {
// 	int x = 5;
	
// 	write(1, &x, sizeof(int));
// 	return 0;
// }