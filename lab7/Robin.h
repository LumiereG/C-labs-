
#pragma once

#include "FlyingAnimal.h" 

#include <iostream>
using namespace std;

using namespace std;

class Robin : public FlyingAnimal
{
public:
	Robin(int size, int energy) : FlyingAnimal(size, energy) {}
	virtual string name() const
	{
		return "Robin";
	}
	virtual std::string make_sound() const
	{
		return "chirp chirp chirp";
	}
	virtual void write(ostream& out) const
	{
		cout << "[" << this->name() << "]";
		this->Animal::write(out);
	}
	virtual void eat(Food food, int amount)
	{
		if (food == Food::Worms) energy += 3;
		FlyingAnimal::eat(food, amount);
	}
};