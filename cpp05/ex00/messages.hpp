/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:30 by eduribei          #+#    #+#             */
/*   Updated: 2025/11/15 20:14:32 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_HPP
# define MESSAGES_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "AForm.hpp"

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

void message_bureau_defa_ctor(Bureaucrat& b);
void message_bureau_para_ctor(Bureaucrat& b);
void message_bureau_deft_dtor(Bureaucrat& b);
void message_bureau_copy_ctor(Bureaucrat& b);
void message_bureau_assg_oper(Bureaucrat& b);

void message_form_defa_ctor(Form& f);
void message_form_para_ctor(Form& f);
void message_form_deft_dtor(Form& f);
void message_form_copy_ctor(Form& f);
void message_form_assg_oper(Form& f);

void message_Aform_defa_ctor(AForm& af);
void message_Aform_para_ctor(AForm& af);
void message_Aform_deft_dtor(AForm& af);
void message_Aform_copy_ctor(AForm& af);
void message_Aform_assg_oper(AForm& af);


#endif
