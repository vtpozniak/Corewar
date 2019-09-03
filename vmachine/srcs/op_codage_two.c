/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_codage_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:51:06 by vpelivan          #+#    #+#             */
/*   Updated: 2019/09/01 15:51:07 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

short	op_codage_and_or_xor(t_carr *carriage)
{
	if (carriage->codage == REG_REG_REG || carriage->codage == REG_IND_REG
		|| carriage->codage == REG_DIR_REG || carriage->codage == DIR_REG_REG
		|| carriage->codage == DIR_IND_REG || carriage->codage == DIR_DIR_REG
		|| carriage->codage == IND_REG_REG || carriage->codage == IND_IND_REG
		|| carriage->codage == IND_DIR_REG)
		return (1);
	return (0);
}

short	op_codage_ldi_lldi(t_carr *carriage)
{
	if (carriage->codage == REG_DIR_REG || carriage->codage == REG_REG_REG
		|| carriage->codage == DIR_DIR_REG || carriage->codage == DIR_REG_REG
		|| carriage->codage == IND_DIR_REG || carriage->codage == IND_REG_REG)
		return (1);
	return (0);
}

short	op_codage_sti(t_carr *carriage)
{
	if (carriage->codage == REG_REG_DIR || carriage->codage == REG_DIR_DIR
		|| carriage->codage == REG_IND_DIR || carriage->codage == REG_REG_REG
		|| carriage->codage == REG_DIR_REG || carriage->codage == REG_IND_REG)
		return (1);
	return (0);
}

short	op_codage_aff(t_carr *carriage)
{
	if (carriage->codage == REG)
		return (1);
	return (0);
}
