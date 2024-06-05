
#pragma once

#include "FlyingAnimal.h" 
#include <string>
#include <iostream>

using namespace std;

class Parrot : public FlyingAnimal
{
	string* learnt_phrases;
	int number_of_learnt_phrases;
public:
	Parrot(int size, int energy) : FlyingAnimal(size, energy) {
		learnt_phrases = nullptr;
		number_of_learnt_phrases = 0;
	}
	virtual string name() const
	{
		return "Parrot";
	}
	virtual std::string make_sound() const
	{
		if(number_of_learnt_phrases == 0) return "Give me a cracker!";
		else 
		{
			string sound;
			for(int i = 0; i < number_of_learnt_phrases; i++)
			{
				sound+=learnt_phrases[i];
				sound+='\n';
			}
			return sound;
		}

	}
	virtual void write(ostream& out) const
	{
		cout << "[" << this->name() << "]";
		this->Animal::write(out);
	}
	void learn_new_phrase(string new_phrase)
	{
		string* new_learnt_phrase = new string[number_of_learnt_phrases + 1];
		for(int i = 0; i < number_of_learnt_phrases; i++)
		{
			new_learnt_phrase[i] = learnt_phrases[i];
		}
		new_learnt_phrase[number_of_learnt_phrases] = new_phrase;
		delete[] learnt_phrases;
		learnt_phrases = new_learnt_phrase;
		number_of_learnt_phrases++;
	}
	void learn_new_phrase(Animal* animal)
	{
		Parrot* pp = dynamic_cast<Parrot*>(animal);
		if (pp != nullptr)
		{
			return;
		}
		learn_new_phrase(animal->make_sound());
	}
	Parrot(const Parrot& p) : FlyingAnimal(p)
	{
		number_of_learnt_phrases = p.number_of_learnt_phrases;
		learnt_phrases = new string [number_of_learnt_phrases];
		for(int i = 0; i < number_of_learnt_phrases; i++)
		{
			learnt_phrases[i] = p.learnt_phrases[i];
		}
	}
	Parrot& operator= (const Parrot& p)
	{
		if(this == &p) return *this;
		FlyingAnimal::operator = (p);
		delete [] this->learnt_phrases;
		number_of_learnt_phrases = p.number_of_learnt_phrases;
		for(int i = 0; i < number_of_learnt_phrases; i++)
			learnt_phrases[i] = p.learnt_phrases[i];
		return *this;
	}

	virtual ~Parrot() override
	{
		delete[] this->learnt_phrases;
	}
};