/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:41:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/04 18:56:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

	// printf("cmd = %s\n", cmd);
	// printf("argv = %s\n", argv[2]);

// int	use_builtins(char *cmd, char **argv, char **env)
// {
	
// 	if (ft_strcmp(cmd, "echo"))
// 		ft_echo()
// }

// int	get_search_path(char *path)
// {
	
// }

// int	search_dir(char *name, char *path)
// {
// 	DIR	dir_path;

// 	dir_path = opendir(path);
// 	if (dir_path == NULL)
// 		return (1);
// }

// int	exector(char *cmd, char **argv, char **env)
// {
// 	// argv[0] ls
// 	// argv[1] -la
// 	if (ft_strcmp(cmd, "echo"))
// 	// 	use_builtins(cmd, argv, env);
// 	if (execve(cmd, &argv[2], env) == -1)
// 		perror("Command not executed\n");
// 	return (0);
// }

int	ft_execute_cmd(t_minishell *shell, char **args)
{
	/* Save the stdin and out into two fd.*/
	int	tmpin;
	int	tmpout;
	tmpin = dup(0);
	tmpout = dup(1);
	
	/* check for input redirection */
	int	fdin;
	if (infile)
		fdin = open(infile, O_READ);
	else
		fdin = dup(tmpin);

	/* Creates a process for every command */
	int id;
	int	fdout;
	int	i;
	
	i = 0;
	while(i < numofcmds)
	{
		// redirecting input
		dup2(fdin, 0);
		close(fdin);
	}
	if (i == numofcmds - 1)
	{
		// last command	
		if (outfile)
			fdout = open(outfile, );
	}
	else
	{
		fdout = dup(tmpout);
	}
	
	if (is_builtin_cmd(args[0]))
		exe_builtin(shell, args);
	else
	{
		id = fork();
		if (id == 0)
			exe_lib(shell);
		else
			waitpid(id, NULL, 0);
	}
	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	// char	*cmd;
// 	char	**option;
// 	int	i;

// 	(void)ac;
// 	(void)av;
// 	option = get_dir_path(env);
// 	i = 0;
// 	while (option[i])
// 	{
// 		printf("%s\n", option[i]);
// 		i++;
// 	}
// 	ft_free_substring(option);
// 	// cmd = av[1];
// 	// exector(cmd, option, env);
// 	return (0);
// }
