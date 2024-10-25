#include <iostream>

class Animal {
public:
    virtual void sound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void sound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; ++i) {
        animals[i]->sound();
    }

    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    return 0;
}
