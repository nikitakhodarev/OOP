#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

// Интерфейс для кормления животных
class IFeedable {
public:
    virtual void Feed() const = 0;
};

// Определение шаблонного класса Animal
template <typename T>
class Animal : public IFeedable {
protected:
    std::string name;
    int age;
    T weight;

public:
    Animal(const std::string &name, int age, T weight)
        : name(name), age(age), weight(weight) {}

    virtual void MakeSound() const = 0;
    virtual void DisplayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Weight: " << weight << std::endl;
    }

    void Feed() const override {
        std::cout << name << " is being fed." << std::endl;
    }
};

// Производный класс Mammal
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

// Производный класс Bird
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

// Класс Zoo
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

    ~Zoo() {
        for (auto &animal : animals) {
            delete animal;
        }
    }
};

// Функция для генерации случайных животных
Animal<double>* CreateRandomAnimal() {
    std::string names[] = {"Lion", "Tiger", "Elephant", "Parrot", "Eagle"};
    int age = rand() % 15 + 1; // Возраст от 1 до 15
    double weight = (rand() % 200 + 50) + static_cast<double>(rand()) / RAND_MAX; // Вес от 50 до 250

    int type = rand() % 2; // 0 для млекопитающих, 1 для птиц
    if (type == 0) {
        return new Mammal<double>(names[rand() % 3], age, weight); // Млекопитающие
    } else {
        return new Bird<double>(names[rand() % 2 + 3], age, weight); // Птицы
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    Zoo zoo;

    // Генерация 10 случайных животных
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

    return 0;
}