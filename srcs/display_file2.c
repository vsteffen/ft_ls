/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:37:42 by vsteffen          #+#    #+#             */
/*   Updated: 2016/05/12 14:20:37 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_time_file(t_stat stat)
{
	char	*time_str;
	int		pos;

	ft_putchar(' ');
	time_str = ctime(&stat.st_mtime);
	pos = 4;
	while (pos < 10)
		get_time_print(time_str, &pos);
	if (stat.st_mtime > time(NULL) - 157788000)
	{
		while (pos < 16)
			get_time_print(time_str, &pos);
	}
	else
	{
		pos = 19;
		while (pos < 24)
			get_time_print(time_str, &pos);
	}
	ft_putchar(' ');
}

void	read_link_file(char *path, int c_type)
{
	char		buf[1024];
	ssize_t		len;

	if (c_type == 'l')
	{
		if ((len = readlink(path, buf, sizeof(buf) - 1)) != -1)
			buf[len] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

void	display_size_file(t_d *d, t_stat stat)
{
	char		type;
	float		nb;

	if (d->tab_option[10] == 0)
	{
		ft_putnbr(stat.st_size);
		ft_putchar(' ');
		return ;
	}
	else
	{
		nb = stat.st_size;
		type = human_function(&nb);
		ft_putnbr(nb);
		ft_putchar(type);
	}
}

void	long_list_format_file(t_d *d, char *path)
{
	t_stat	stat;
	char	c_type;

	c_type = type_file_file(&stat, path);
	ft_putchar(c_type);
	left_side_file(&stat);
	ft_putchar(' ');
	if (c_type == 'c' || c_type == 'b')
		major_minor_file(&stat);
	else
	{
		display_size_file(d, stat);
	}
	get_time_file(stat);
	print_elem_in_color_file(stat, path, c_type);
	read_link_file(path, c_type);
	ft_putchar('\n');
	return ;
}

void	display_file(t_d *d, char *path, int arg_pos)
{
	if (d->tab_option[4] == 1)
		long_list_format_file(d, path);
	else if (d->tab_option[6] == 1)
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr(path);
		if (d->arg_true > 1 && d->arg_true > arg_pos + 1)
			ft_putchar(' ');
	}
	if (d->arg_true == arg_pos + 1 && d->tab_option[4] != 1 &&
			d->tab_option[6] != 1)
		ft_putchar('\n');
	if (arg_pos + 1 < d->arg_true)
		if (d->tab_arg[arg_pos + 1].dir == 1)
			ft_putstr("\n\n");
}
