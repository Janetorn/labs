#include <iostream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
using namespace std;

class Person {
public:
    Person(const string& name, int age) : name(name), age(age) {}
    virtual void info() const {
        cout << "Person name: " << name << " age: " << age << endl;
    }

protected:
    string name;
    int age;
};

class Preschooler : public Person {
public:
    Preschooler(const string& name, int age, const string& group)
        : Person(name, age), group(group) {}
    void info() const {
        cout << "Preschooler name: " << name << " age:" << age << " group: " << group << endl;
    }

private:
    string group;
};

class Schoolboy : public Person {
public:
    Schoolboy(const string& name, int age, const string& school)
        : Person(name, age), school(school) {}

    void info() const {
        cout << "Schoolboy name: " << name << " age: " << age << " school: " << school << endl;
    }

private:
    string school;
};

class Student : public Person {
public:
    Student(const string& name, int age, const string& department)
        : Person(name, age), department(department) {}

    void info() const {
        cout << "Student name: " << name << " age: " << age << " department: " << department << endl;
    }

private:
    string department;
};

class Working : public Person {
public:
    Working(const string& name, int age, const string& company)
        : Person(name, age), company(company) {}

    void info() const {
        cout << "Working name: " << name << " age: " << age << " company: " << company << endl;
    }

private:
    string company;
};

template<typename T>
class PointerArray {
private:
    T** array;
    size_t size;
    size_t capacity;

public:
    PointerArray(size_t cap) : size(0), capacity(cap) {
        array = new T * [capacity];
    }

    ~PointerArray() {
        for (size_t i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;
    }

    void add(T* item) {
        if (size < capacity) {
            array[size++] = item;
        }
        else {
            cout << "Array is full! Cannot add more elements." << endl;
            delete item;
        }
    }

    void displayAll() const {
        for (size_t i = 0; i < size; ++i) {
            array[i]->info();
        }
    }
};

int main() {
    const size_t capacity = 10;
    PointerArray<Person> people(capacity);

    people.add(new Preschooler("Isolda", 6, "A"));
    people.add(new Schoolboy("Ayana", 14, "#347"));
    people.add(new Student("Keira", 20, "15.03"));
    people.add(new Working("Kan", 35, "Pand"));
    people.add(new Schoolboy("Luka", 16, "#928"));
    people.add(new Student("Rosa", 23, "03.01"));
    people.displayAll();
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
    return 0;
}
