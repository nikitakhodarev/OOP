#include <iostream>
#include <string>

template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Пример с типом int
    int a = 5;
    int b = 10;
    std::cout << "До обмена (int): a = " << a << ", b = " << b << std::endl;
    swapValues(a, b);
    std::cout << "После обмена (int): a = " << a << ", b = " << b << std::endl;

    // Пример с типом double
    double c = 3.14;
    double d = 2.71;
    std::cout << "До обмена (double): c = " << c << ", d = " << d << std::endl;
    swapValues(c, d);
    std::cout << "После обмена (double): c = " << c << ", d = " << d << std::endl;

    // Пример с типом std::string
    std::string e = "Hello";
    std::string f = "World";
    std::cout << "До обмена (std::string): e = " << e << ", f = " << f << std::endl;
    swapValues(e, f);
    std::cout << "После обмена (std::string): e = " << e << ", f = " << f << std::endl;

    return 0;
}
