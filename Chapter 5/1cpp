#include <iostream>

template <typename T>
T average(T* array, size_t size) { 
    T sum = 0;
    for (size_t i = 0; i < size; ++i) { 
        sum += array[i]; 
    } 
    return sum / size; 
} 
    
int main() { 
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.0f, 2.5f, 3.5f, 4.0f};

    std::cout << "Average of intArray: " << average(intArray, 5) << std::endl;
    std::cout << "Average of floatArray: " << average(floatArray, 4) << std::endl; 

    return 0; 
} 
