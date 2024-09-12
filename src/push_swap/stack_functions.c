/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:19 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 19:11:02 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*stack_last: devuelve el último nodo de la lista*/
t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*stack_new crea un nuevo nodo con un valor dado*/
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(*new));
	new->value = value;
	new->next = NULL;
	return (new);
}

/*stack_add_bottom: añade el nodo al final */
void	stack_add_bottom(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!(*stack))
		*stack = stack_new;
	else
		stack_last(*stack)->next = stack_new;
}

/*stack_size: calcula y devuelve el tamaño de la lista*/
int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
