/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:33:59 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 21:08:49 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

//error
# define ERR_STACK "stack error"

/**********************************  STRUCTS  *********************************/
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

//utils
void				free_stack(t_stack **stack);
void				ft_error(char *msg, t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *stack);
int					ft_issign(int c);
int					ft_is_digit_sign(char **str, int i);
// check_args
t_stack				*ft_check_args(int argc, char **argv);
int					ft_check_arg_dup(t_stack *stack_a);
//stack
t_stack				*stack_last(t_stack *lst);
t_stack				*stack_new(int value);
void				stack_add_bottom(t_stack **stack, t_stack *stack_new);
int					stack_size(t_stack *stack);
// sort algorithm
void				sort_three(t_stack **stack);
void				sort_all(t_stack **a, t_stack **b);
// sort algorithm utils
void				save_three_a(t_stack **a, t_stack **b, int size);
void				cost(t_stack **stack_a, t_stack **stack_b);
void				cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				final_offset(t_stack **stack_a);
//move
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
//position
int					lower_position(t_stack **stack);
void				target_position(t_stack **a, t_stack **b);

//rotate
void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);
//push
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);
//swap
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);
//reverse rotate
void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
