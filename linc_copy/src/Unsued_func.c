/* 	A checker for the env list: prints out env values as table.
	ft_printenvlist_checker(&minishell);
void	ft_printenvlist_checker(t_minishell *minishell)
{
	t_envlist	*nodeprint;

	nodeprint = minishell->envlist;
	while (nodeprint)
	{
		ft_printf("var:\t %s \t \t content:\t %s \n",
			nodeprint->variable,
			nodeprint->content);
		nodeprint = nodeprint->next;
	}
	minishell->envlist = NULL;
} */

	int	i = 0;
	while (i < shell->executor->amt_of_cmds)
	{
		print_arr(shell->executor->process[i].cmd);
		ft_printf("index = %d\n", shell->executor->process[i].index);
		i++;
	}
