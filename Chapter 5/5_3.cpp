#include <iostream>
#include <string>
#include <algorithm> // для std::swap

template <typename T>
void selectionSort(T* array, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
    }
}

int main() {
    int intArray[] = {5, 3, 8, 6, 2};
    std::string strArray[] = {"banana", "apple", "orange", "grape"};

    selectionSort(intArray, 5);
    selectionSort(strArray, 4);

    std::cout << "Sorted intArray: ";
    for (int i : intArray) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted strArray: ";
    for (const std::string& s : strArray) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
