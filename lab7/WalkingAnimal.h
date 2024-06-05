#pragma once

#include "Animal.h"

class WalkingAnimal : public Animal
{
private:
	const static int acceptable_food_length = 5;
	const static Food acceptable_food[acceptable_food_length];
public:
	WalkingAnimal(int size, int energy) : Animal(size, energy) {}
	virtual void write(ostream& out) const = 0;
	virtual string name() const = 0;
	virtual std::string make_sound() const = 0;
	virtual void eat(Food food, int amount)
	{
		for (int i = 0; i < acceptable_food_length; i++)
		{
			if (food == acceptable_food[i]) energy += amount;
		}
	}
};

const Food WalkingAnimal::acceptable_food[] = { Food::Water, Food::Grass, Food::Leaves, Food::Insects, Food::Fruit };