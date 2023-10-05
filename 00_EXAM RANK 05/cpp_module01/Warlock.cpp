#include "Warlock.hpp"

/* Constructors */
Warlock::Warlock(std::string const& name, std::string const& title) 
	: _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

/* Methods */
std::string const&
Warlock::getName() const
{
	return _name;
}

std::string const&
Warlock::getTitle() const
{
	return _title;
}

void
Warlock::setTitle(std::string const& new_title)
{
	_title = new_title;
}

void
Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

/* Methods 01 */
void
Warlock::learnSpell(ASpell* spell_tolearn)
{
	if (spell_tolearn)
		spellBook[spell_tolearn->getName()] = spell_tolearn;
}

void
Warlock::forgetSpell(std::string const& spell_name)
{
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spell_name);

	if (it != spellBook.end())
		spellBook.erase(it);
}

void
Warlock::launchSpell(std::string const& spell_name, const ATarget& target)
{
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spell_name);

	if (it != spellBook.end())
		it->second->launch(target);
}