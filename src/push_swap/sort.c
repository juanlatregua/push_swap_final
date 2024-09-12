/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:23 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 17:45:09 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;
	int		highest;

	tmp = *stack;
	highest = tmp->value;
	while (tmp)
	{
		if (tmp->value > highest)
			highest = tmp->value;
		tmp = tmp->next;
	}
	if ((*stack)->value == highest)
		do_ra(stack);
	else if ((*stack)->next->value == highest)
		do_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		do_sa(stack);
}

void	sort_all(t_stack **a, t_stack **b)
{
	save_three_a(a, b, stack_size(*a));
	while (*b)
	{
		target_position(a, b);
		cost(a, b);
		cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		final_offset(a);
}

