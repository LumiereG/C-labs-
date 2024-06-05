#pragma once

#include "Animal.h"

class FlyingAnimal : public Animal
{
private:
	const static int acceptable_food_length = 3;
	const static Food acceptable_food[acceptable_food_length];
public:
	FlyingAnimal(int size, int energy) : Animal(size, energy) {}
	virtual void write(ostream& out) const = 0;
	virtual string name() const = 0;
	virtual std::string make_sound() const = 0;
	virtual void eat(Food food, int amount)
	{
		for (int i = 0; i < acceptable_food_length; i++)
		{
			if (food == acceptable_food[i]) energy += 2*amount;
		}
	}
};
const Food FlyingAnimal::acceptable_food[] = { Food::Seeds, Food::Crackers, Food::Worms};