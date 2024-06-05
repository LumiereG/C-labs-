#pragma once

#include "WalkingAnimal.h"
#include <iostream>
using namespace std;


class Elephant : public WalkingAnimal
{
public:
	Elephant(int size, int energy) : WalkingAnimal(size, energy) {}
	virtual string name() const
	{
		return "Elephant";
	}
	virtual std::string make_sound() const
	{
		return "TOOOOOOT!";
	}
	virtual void write(ostream& out) const
	{
		cout << "[" << this->name() << "]";
		this->Animal::write(out);
	}
	virtual void eat(Food food, int amount)
	{
		if (food == Food::Fruit) energy *= 2;
		else WalkingAnimal::eat(food, amount);
	}
	
};