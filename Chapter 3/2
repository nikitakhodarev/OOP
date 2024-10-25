#include <iostream>
#include <vector>
#include <string>

class Student {
protected:
    std::string name;
public:
    Student(std::string name) : name(name) {}
    virtual void display() const {
        std::cout << "Student: " << name << std::endl;
    }
};

class InternationalStudent : public Student {
private:
    std::string country;
public:
    InternationalStudent(std::string name, std::string country) : Student(name), country(country) {}
    void display() const override {
        std::cout << "International Student: " << name << " from " << country << std::endl;
    }
};

class Course {
private:
    std::vector<Student*> students;
public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void displayStudents() const {
        for (const auto& student : students) {
            student->display();
        }
    }

    ~Course() {
        for (auto& student : students) {
            delete student;
        }
    }
};

int main() {
    Course course;
    course.addStudent(new Student("John"));
    course.addStudent(new InternationalStudent("Alice", "Canada"));

    course.displayStudents();
    return 0;
}
