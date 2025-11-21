/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:30 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/20 23:12:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_HPP
# define MESSAGES_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define RED	"\001\033[31m\002"
# define GRN	"\001\033[32m\002"
# define YEL	"\001\033[33m\002"
# define BLU	"\001\033[34m\002"
# define MAG	"\001\033[35m\002"
# define CYN	"\001\033[36m\002"
# define WHT	"\001\033[37m\002"
# define BRED	"\001\033[1;31m\002"
# define BGRN	"\001\033[1;32m\002"
# define BYEL	"\001\033[1;33m\002"
# define BBLU	"\001\033[1;34m\002"
# define RST	"\001\033[0m\002"

//------------------------------------------------------------------------------
void message_bureau_defa_ctor(Bureaucrat& b);
void message_bureau_para_ctor(Bureaucrat& b);
void message_bureau_deft_dtor(Bureaucrat& b);
void message_bureau_copy_ctor(Bureaucrat& b);
void message_bureau_assg_oper(Bureaucrat& b);
//------------------------------------------------------------------------------
void message_AForm_defa_ctor(AForm& af);
void message_AForm_para_ctor(AForm& af);
void message_AForm_deft_dtor(AForm& af);
void message_AForm_copy_ctor(AForm& af);
void message_AForm_assg_oper(AForm& af);
//------------------------------------------------------------------------------
void message_scf_defa_ctor(ShrubberyCreationForm& s);
void message_scf_para_ctor(ShrubberyCreationForm& s);
void message_scf_deft_dtor(ShrubberyCreationForm& s);
void message_scf_copy_ctor(ShrubberyCreationForm& s);
void message_scf_assg_oper(ShrubberyCreationForm& s);
//------------------------------------------------------------------------------
void message_rrf_defa_ctor(RobotomyRequestForm& r);
void message_rrf_para_ctor(RobotomyRequestForm& r);
void message_rrf_deft_dtor(RobotomyRequestForm& r);
void message_rrf_copy_ctor(RobotomyRequestForm& r);
void message_rrf_assg_oper(RobotomyRequestForm& r);
//------------------------------------------------------------------------------
void message_ppf_defa_ctor(PresidentialPardonForm& r);
void message_ppf_para_ctor(PresidentialPardonForm& r);
void message_ppf_deft_dtor(PresidentialPardonForm& r);
void message_ppf_copy_ctor(PresidentialPardonForm& r);
void message_ppf_assg_oper(PresidentialPardonForm& r);
//------------------------------------------------------------------------------
void message_intrn_defa_ctor();
void message_intrn_deft_dtor();
void message_intrn_copy_ctor();
void message_intrn_assg_oper();

#endif
