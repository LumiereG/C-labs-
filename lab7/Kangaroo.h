#pragma once

#include "WalkingAnimal.h"
#include <iostream>
using namespace std;

class Kangaroo : public WalkingAnimal
{
public:
	Kangaroo(int size, int energy) : WalkingAnimal(size, energy) {}
	virtual string name() const override
	{
		return "Kangaroo";
	}
	virtual std::string make_sound() const override
	{
		return "*boing* *boing*";
	}
	virtual void write(ostream& out) const override
	{
		cout << "[" << this->name() << "]";
		this->Animal::write(out);
	}
	virtual void eat(Food food, int amount)
	{
		WalkingAnimal::eat(food, amount);
	}
};