#pragma once

#include <string>
#include <iostream>
#include "Food.h"
using namespace std;

class Animal {

protected:
    int size;
    int energy;

public:
    Animal(int size, int energy) : size(size), energy(energy) {}

    virtual std::string make_sound() const = 0;
    virtual void eat(Food food, int amount) = 0;
    virtual void write(ostream& out) const
    {
        cout << " Size: " << this->size;
        cout << " Energy: " << this->energy << endl;
    }
    friend ostream& operator<<(ostream& out, const Animal& a)
    {
        a.write(out);
        return out;;
    }
    virtual string name() const = 0;
    virtual ~Animal() {};
};
