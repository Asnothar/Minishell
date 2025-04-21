/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:50:21 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:50:10 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Ajoute un nouvel élément à la fin d'une liste chaînée.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst)
		lst = &(*lst)->next;
	*lst = new;
}
