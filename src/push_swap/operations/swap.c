/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:58:33 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 20:09:47 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap: the 2 element of a stack. Do nothing if there is only
one or no elements*/
static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/*do_sa: swaps the top 2 elements of stack a.
Prints "sa"*/
void	do_sa(t_stack	**stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

/*do_sb: swap the top 2 elements of stack b. 
Prints "sb"*/
void	do_sb(t_stack	**stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

/*do_ss: swap the top 2 elements of stack a and the top 2 elements
of stack b. */
void	do_ss(t_stack	**stack_a, t_stack	**stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
