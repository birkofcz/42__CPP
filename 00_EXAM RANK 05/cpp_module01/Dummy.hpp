#pragma once

#include "ASpell.hpp"
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

		ATarget*	clone() const;
};
