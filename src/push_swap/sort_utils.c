/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:57:27 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 21:06:50 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_three_a(t_stack **a, t_stack **b, int size)
{
	while (stack_size(*b) < size / 2 && stack_size(*a) > 3)
	{
		if ((*a)->index <= size / 2)
			do_pb(a, b);
		else
			do_ra(a);
	}
	while (stack_size(*a) > 3)
		do_pb(a, b);
	sort_three(a);
}

void	cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > stack_size(*b) / 2)
			tmp->cost_b = (stack_size(*b) - tmp->pos) * -1;
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > stack_size(*a) / 2)
			tmp->cost_a = (stack_size(*a) - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
}

void	cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_iabs(tmp->cost_a) + ft_iabs(tmp->cost_b) < ft_iabs(cheapest))
		{
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
			cheapest = ft_iabs(cost_b) + ft_iabs(cost_a);
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}

void	final_offset(t_stack **a)
{
	int	lower_pos;

	lower_pos = lower_position(a);
	if (lower_pos > stack_size(*a) / 2)
	{
		while (lower_pos < stack_size(*a))
		{
			do_rra(a);
			lower_pos++;
		}
	}
	else
	{
		while (lower_pos > 0)
		{
			do_ra(a);
			lower_pos--;
		}
	}
}
