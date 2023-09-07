/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:38:46 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 11:44:10 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
	: AForm(original), _target(original._target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	(void)src;
	return *this;
}	

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}	

///// Methods

std::string	ShrubberyCreationForm::getTarget() const {return _target;}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignatureStatus() == false)
	{
		std::cout << "Inside signature control flow" << std::endl;
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > this->getExecLimit())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "[[ Bureaucrat ]] " << executor.getName() << " executes " << this->getName() << std::endl;
		std::ofstream ofs;
		ofs.open((_target + "_shrubbery").c_str());
		ofs << "      /\\      " << std::endl;
		ofs << "     /\\*\\     " << std::endl;
		ofs << "    /\\O\\*\\    " << std::endl;
		ofs << "   /*/\\/\\/\\   " << std::endl;
		ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
		ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "    \\====/    " << std::endl;
		ofs << "     \\==/     " << std::endl;
		ofs << "      \\/      " << std::endl;
		ofs.close();
	}
}
