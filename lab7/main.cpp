#include <iostream>

#include "Animal.h"
#include "Kangaroo.h"
#include "Elephant.h"
#include "Robin.h"
#include "Parrot.h"
#include "Food.h"

// MOŻNA EDYTOWAĆ TYLKO TE 3 LINIJKI
#define ETAP_1
#define ETAP_2
#define ETAP_3

int main() {

#ifdef ETAP_1
    std::cout << "\n***************** ETAP_1 *****************\n\n";

    Kangaroo* k = new Kangaroo(5, 10);
    Elephant* e = new Elephant(10, 10);
    Parrot* p = new Parrot(2, 10);
    Robin* r = new Robin(1, 10);

    Animal* animals[] {
            k, e, p, r
    };

    for (Animal* animal : animals) {
        std::cout << *animal << "Sound: " << animal->make_sound() << "\n\n";
    }
#endif

#ifdef ETAP_2
    std::cout << "***************** ETAP_2 *****************\n\n";

    k->eat(Food::Worms, 999);
    k->eat(Food::Insects, 4);
    k->eat(Food::Leaves, 3);

    e->eat(Food::Crackers, 999);
    e->eat(Food::Water, 12);
    e->eat(Food::Fruit, 12);

    p->eat(Food::Fruit, 999);
    p->eat(Food::Seeds, 2);
    p->eat(Food::Crackers, 3);

    r->eat(Food::Grass, 999);
    r->eat(Food::Seeds, 3);
    r->eat(Food::Worms, 1);

    for (Animal* animal : animals) {
        std::cout << *animal << std::endl;
    }
#endif

#ifdef ETAP_3
    std::cout << "\n***************** ETAP_3 *****************\n\n";

    std::cout << p->make_sound() << "\n\n";

    p->learn_new_phrase("Give me two crackers!");
    p->learn_new_phrase("I'm serious!");

    std::cout << p->make_sound() << "\n";

    p->learn_new_phrase(e);
    p->learn_new_phrase(k);
    p->learn_new_phrase(p);
    p->learn_new_phrase("The end");

    std::cout << p->make_sound() << "\n";

    std::cout << "Copy 1" << "\n";
    Parrot copy1{*p};
    std::cout << copy1.make_sound() << "\n";

    std::cout << "Copy 2" << "\n";
    Parrot copy2{2, 2};
    copy2 = copy1;
    std::cout << copy2.make_sound() << "\n";

#endif

#ifdef ETAP_1
    for (Animal* animal : animals) {
        delete animal;
    }
#endif

    return 0;
}
