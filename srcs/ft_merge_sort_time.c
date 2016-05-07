/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:49:06 by vsteffen          #+#    #+#             */
/*   Updated: 2016/05/07 20:16:33 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		partition_t(node_ptr head, node_ptr *front, node_ptr *back)
{
	node_ptr		fast;
	node_ptr		slow;

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

node_ptr	merge_list_t(node_ptr a, node_ptr b)
{
	node_ptr merged_list;

	merged_list = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((ft_strcmp(a->name, b->name) <= 0 && a->stat.st_mtime
				== b->stat.st_mtime) || a->stat.st_mtime > b->stat.st_mtime)
	{
		merged_list = a;
		merged_list->next = merge_list_t(a->next, b);
	}
	else
	{
		merged_list = b;
		merged_list->next = merge_list_t(a, b->next);
	}
	return (merged_list);
}

void		ft_merge_sort_time(node_ptr *source)
{
	node_ptr		head;
	node_ptr		a;
	node_ptr		b;

	head = *source;
	a = NULL;
	b = NULL;
	if (head == NULL || head->next == NULL)
		return ;
	partition_t(head, &a, &b);
	ft_merge_sort_time(&a);
	ft_merge_sort_time(&b);
	*source = merge_list_t(a, b);
}
