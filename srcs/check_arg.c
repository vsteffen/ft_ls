/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:46:10 by vsteffen          #+#    #+#             */
/*   Updated: 2016/03/30 19:57:08 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_arg_spe(char arg_tmp, t_data *data)
{
	if (arg_tmp == 'L')
		return (data->tab_arg[0] = 11);
	else if (arg_tmp == 'R')
		return (data->tab_arg[1] = 2);
	else if (arg_tmp == 'a')
		return (data->tab_arg[2] = 4);
	else if (arg_tmp == 'l')
		return (data->tab_arg[3] = 3);
	else if (arg_tmp == 'r')
		return (data->tab_arg[4] = 22);
	else if (arg_tmp == '1')
		return (data->tab_arg[5] = 2);
	else
	{
		printf("ls: illegal option -- %c\n", arg_tmp);
		printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
		printf("[file ...]\n");
		exit(0);
	}
	return (0);
}

void		check_arg(int ac, char **av, t_data *data, int *ac_var)
{
	int		i;

	i = 1;
	if (av[*ac_var][0] == '-' && av[*ac_var][1] == '\0')
		data->path = ft_strjoin(data->path, "- ");
	else if (av[*ac_var][0] == '-')
	{
		while (av[*ac_var][i] != '\0')
		{
			check_arg_spe(av[*ac_var][i], data);
			i++;
		}
	}
	else
	{
		data->path = ft_strjoin(data->path, av[*ac_var]);
		data->path = ft_strjoin(data->path, " ");
	}
}

void		tab_arg_display(t_data *data)
{
	int		ac_var;

	ac_var = 0;
	while (ac_var != 6)
	{
		printf("data->tab_arg[%d] = %d\n", ac_var, data->tab_arg[ac_var]);
		ac_var++;
	}
}
/*
void		ft_qsort_tab_int(int array[], int first, int last)
{
	int left;
	int right;
	int pivot;

	left = first - 1;
	right = last + 1;
	pivot = array[first];
	if (first >= last)
		return ;
	while (1)
	{
		right--;
		while (array[right] > pivot)
			right--;
		left++;
		while (array[left] < pivot)
			left++;
		if (left < right)
			ft_swap_int(&array[left], &array[right]);
		else
			break ;
	}
	ft_qsort_tab_int(array, first, right);
	ft_qsort_tab_int(array, right + 1, last);
}
*/

int			check_av(int ac, char **av, t_data *data)
{
	int		ac_var;
	char	*value1 = "POUETTE";
	char	*value2 = "CACA";
	int		nb1 = 2;
	int		nb2 = 3;
	int		*p1 = &nb1;
	int 	*p2 = &nb2;
	int		ret;

	if (ac == 1)
	{
		data->arg = 0;
		data->path = ".";
		return (0);
	}
	ac_var = 1;
	ret = 1;
	while (ac_var < ac)
	{
		check_arg(ac, av, data, &ac_var);
		ac_var++;
	}
	if (ft_strequ(data->path, "") == 1)
		data->path = ".";
	tab_arg_display(data);
	ft_putchar('\n');
	printf("\n\n");
	ft_qsort_tab_int(data->tab_arg, 0, 5);
	tab_arg_display(data);
	return (0);
}
