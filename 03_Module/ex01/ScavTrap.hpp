#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
	public:
		// methods
		void	guardGate();

		//my additional methods for testing purposes
		void	report() const;
		// Constructors
		ScavTrap();
		ScavTrap(std::string trap_name);
		ScavTrap(const ScavTrap &original);
		ScavTrap & operator=(const ScavTrap &src);
		~ScavTrap();	
};

#endif