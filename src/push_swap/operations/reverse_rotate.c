/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:00:38 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 20:04:42 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*reverse&rotate: bring the botton to the top*/
static void	rev_rotate(t_stack	**stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = stack_last(*stack);
	before_last = *stack;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	*stack = last;
	(*stack)->next = tmp;
	before_last->next = NULL;
}

/*do_rra: brings the bottom element of stack a to the top
prints rra*/
void	do_rra(t_stack	**stack_a)
{
	rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

/*do_rrb: brings the bottom element of stack b to the top
prints rrb*/
void	do_rrb(t_stack	**stack_b)
{
	rev_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

/*do_rrr: bring the bottom of both stacks to the top
prints both*/
void	do_rrr(t_stack	**stack_a, t_stack	**stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
