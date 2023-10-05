#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string	_type;

	public:
		ATarget(std::string const& type);
		virtual ~ATarget();

		std::string const& getType() const;

		virtual ATarget* clone() const = 0;

		void getHitBySpell(const ASpell& spell) const;
};