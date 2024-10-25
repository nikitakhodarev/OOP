#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair { 
    private: 
        T1 first;
        T2 second; 
    public: 
        void setFirst(T1 value) { 
            first = value; 
        } 
        void setSecond(T2 value) {
            second = value; 
        } 
        T1 getFirst() const { 
            return first; 
        } 
        T2 getSecond() const { 
            return second; 
        } 
}; 

int main() { 
    Pair<int, double> p1; 
    p1.setFirst(1); 
    p1.setSecond(2.5);
    
    std::cout << "First: " << p1.getFirst() << ", Second: " << p1.getSecond() << std::endl;
    
    Pair<std::string, char> p2; 
    p2.setFirst("Hello"); 
    p2.setSecond('A'); 
    
    std::cout << "First: " << p2.getFirst() << ", Second: " << p2.getSecond() << std::endl; 
    
    return 0; 
} 
