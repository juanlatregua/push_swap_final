/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:31:03 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 18:45:16 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	position(t_stack *stack);
static int	target(t_stack **a, int b_index);
static int	botton_target(t_stack **a, int target_index, int target_pos);

/*lower_position localiza la posición del elemento con el valor más bajo */
int	lower_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lower_index;
	int		lower_pos;

	position(*stack);
	tmp = *stack;
	lower_index = INT_MAX;
	lower_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lower_index)
		{
			lower_index = tmp->index;
			lower_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lower_pos);
}
/*target_position: asigna la posición objetivo a cada elemento de b,
de modo que se pueda insertar en a en su posición correct*/
void	target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	position(*a);
	position(*b);
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->target_pos = target(a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}
/*position: asigna una posición a cada elemneto de la pila. Empiezo en -1 para asignar 0
a la primera*/
static void	position(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack)
	{
		stack->pos = ++i;
		stack = stack->next;
	}
}
/*target: busca la posición en a del elmento de b, en base al índice.
Si no encuentra un índice mayor llama a bottom_target para determinar 
la posición objetivo*/
static int	target(t_stack **a, int b_index)
{
	t_stack	*tmp_a;
	int		target_index;
	int		target_pos;

	tmp_a = *a;
	target_index = INT_MAX;
	target_pos = 0;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	else
		return (botton_target(a, target_index, target_pos));
}

static int	botton_target(t_stack **a, int target_index, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}
