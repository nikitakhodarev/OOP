#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>  


class IFeedable {
public:
    virtual void Feed() const = 0;
};

template <typename T>
class Animal : public IFeedable {
protected:
    std::string name;
    int age;
    T weight;
bool isFed = false; // Добавляем флаг для отслеживания сытости

public:
    Animal(const std::string &name, int age, T weight)
        : name(name), age(age), weight(weight) {}

    virtual void MakeSound() const = 0;
    virtual void DisplayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Weight: " << weight << std::endl;
    }

    void Feed() const override {
        std::cout << name << " is being fed." << std::endl;
isFed = true; // Помечаем животное как сытое
    }
};


template <typename T>
class Mammal : public Animal<T> {
public:
    Mammal(const std::string &name, int age, T weight)
        : Animal<T>(name, age, weight) {}

    void MakeSound() const override {
        if (this->name == "Lion") {
            std::cout << this->name << " says: Roar!" << std::endl;
        } else if (this->name == "Tiger") {
            std::cout << this->name << " says: Growl!" << std::endl;
        } else if (this->name == "Elephant") {
            std::cout << this->name << " says: Trumpet!" << std::endl;
        } else {
            std::cout << this->name << " says: Mammal sound!" << std::endl;
        }
    }

    void DisplayInfo() const override {
        std::cout << "Mammal - ";
        Animal<T>::DisplayInfo();
    }
};


template <typename T>
class Bird : public Animal<T> {
public:
    Bird(const std::string &name, int age, T weight)
        : Animal<T>(name, age, weight) {}

    void MakeSound() const override {
        if (this->name == "Parrot") {
            std::cout << this->name << " says: Squawk!" << std::endl;
        } else if (this->name == "Eagle") {
            std::cout << this->name << " says: Screech!" << std::endl;
        } else {
            std::cout << this->name << " says: Chirp!" << std::endl;
        }
    }

    void DisplayInfo() const override {
        std::cout << "Bird - ";
        Animal<T>::DisplayInfo();
    }
};


class Zoo {
private:
    std::vector<Animal<double>*> animals;

public:
    void AddAnimal(Animal<double>* animal) {
        animals.push_back(animal);
    }

    void DisplayAllAnimals() const {
        for (const auto &animal : animals) {
            animal->DisplayInfo();
        }
    }

    void MakeSounds() const {
        for (const auto &animal : animals) {
            animal->MakeSound();
        }
    }

    void FeedAllAnimals() const {
        for (const auto &animal : animals) {
            animal->Feed();
        }
    }
// Новая функция для вывода информации о сытости
void DisplayFeedingStatus() const {
int fedCount = 0;
std::cout << "Feeding status:" << std::endl;
for (size_t i = 0; i < animals.size(); ++i) {
if (animals[i]->isFed) {
std::cout << "Animal " << i << " (" << animals[i]->name << ") is fed." << std::endl;
fedCount++;
} else {
std::cout << "Animal " << i << " (" << animals[i]->name << ") needs to be fed." << std::endl;
}
}
std::cout << "Total fed animals: " << fedCount << std::endl;
}

    ~Zoo() {
        for (auto &animal : animals) {
            delete animal;
        }
    }
};


Animal<double>* CreateRandomAnimal() {
    std::string names[] = {"Lion", "Tiger", "Elephant", "Parrot", "Eagle"};
    int age = rand() % 15 + 1;
    double weight = (rand() % 200 + 50) + static_cast<double>(rand()) / RAND_MAX;

    int type = rand() % 2;
    if (type == 0) {
        return new Mammal<double>(names[rand() % 3], age, weight);
    } else {
        return new Bird<double>(names[rand() % 2 + 3], age, weight);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Zoo zoo;

   
    for (int i = 0; i < 10; ++i) {
        Animal<double>* animal = CreateRandomAnimal();
        zoo.AddAnimal(animal);
    }

    std::cout << "Animals in the zoo:" << std::endl;
    zoo.DisplayAllAnimals();

    std::cout << "\nAnimals making sounds:" << std::endl;
    zoo.MakeSounds();

    std::cout << "\nFeeding animals:" << std::endl;
    zoo.FeedAllAnimals();

// Вывод информации о сытости
zoo.DisplayFeedingStatus();

    return 0;
}
