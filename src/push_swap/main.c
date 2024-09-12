/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:03:19 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 18:02:52 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_index(t_stack *stack);
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

/* get_index: asigno los índices de los elementos en función de su valor*/
static void	get_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	while (current)
	{
		tmp = stack;
		current->index = 1;
		while (tmp)
		{
			if (tmp->value < current->value)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}
/*push_swap determina el tamaño de la pila. Verifica si está ordenada y 
en relación del tamaño utiliza una función u otra*/
static void	push_swap(t_stack **a, t_stack **b, int size_a)
{
	if (is_sorted(*a))
		return ;
	if (size_a == 2)
		do_sa(a);
	else if (size_a == 3)
		sort_three(a);
	else if (size_a > 3)
		sort_all(a, b);
}
/*inicializamos la pila b a null y a verificamos los argumentos que se pasan
asignamos el índice, realizamos la ordenación y liberamos todo*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = ft_check_args(argc, argv);
	if (!stack_a || ft_check_arg_dup(stack_a))
		ft_error("Error: duplicate arguments", &stack_a, NULL);
	get_index(stack_a);
	push_swap(&stack_a, &stack_b, stack_size(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}