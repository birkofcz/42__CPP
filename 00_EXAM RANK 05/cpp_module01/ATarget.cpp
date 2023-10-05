#include "ATarget.hpp"

ATarget::ATarget(std::string const& type)
	: _type(type)
{

}

ATarget::~ATarget()
{

}

/* Methods */
std::string const&
ATarget::getType() const
{
	return _type;
}

void
ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << std::endl;
}