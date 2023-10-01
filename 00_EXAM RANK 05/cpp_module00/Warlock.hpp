#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string		_name;
		std::string		_title;

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
};


