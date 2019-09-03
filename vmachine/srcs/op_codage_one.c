/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_codage_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:51:17 by vpelivan          #+#    #+#             */
/*   Updated: 2019/09/01 15:51:18 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

short	op_codage_ld_lld(t_carr *carriage)
{
	if (carriage->codage == IND_REG || carriage->codage == DIR_REG)
		return (1);
	return (0);
}

short	op_codage_st(t_carr *carriage)
{
	if (carriage->codage == REG_REG || carriage->codage == REG_IND)
		return (1);
	return (0);
}

short	op_codage_add_sub(t_carr *carriage)
{
	if (carriage->codage == REG_REG_REG)
		return (1);
	return (0);
}
