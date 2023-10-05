#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

class ASpell;
class ATarget;

class Warlock
{
	private:
		std::string		_name;
		std::string		_title;

		/* 01 */
		std::map<std::string, ASpell*>	spellBook;

		Warlock();
		Warlock(const Warlock& original);
		Warlock& operator=(const Warlock& src);

	public:
		Warlock(std::string const& name, std::string const& title);
		~Warlock();

		std::string const& getName() const;
		std::string const& getTitle() const;
		void setTitle(std::string const& new_title);
		void introduce() const;

		/* 01 */
		void	learnSpell(ASpell* spell_tolearn);
		void	forgetSpell(std::string const& spell_name);
		void	launchSpell(std::string const& spell_name, const ATarget& target);
};
