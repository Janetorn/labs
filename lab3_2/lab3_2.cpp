#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Base {
public:
    virtual void write() {
        cout << "Guten Tag" << endl;
    }

    virtual ~Base() { }
};

class Derived : public Base {
public:
    void write() override {
        cout << "good afternoon" << endl;
    }
    ~Derived() { }
};

void add(vector<Base*>& storage, Base* obj) {
    storage.push_back(obj);
}

int main() {
    vector<Base*> storage;
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 5; i++) {
        int ranNum = rand();
        if (ranNum % 2 == 0) {
            add(storage, new Base());
        }
        else {
            add(storage, new Derived());
        }
    }

    for (size_t i = 0; i < storage.size(); i++) {
        storage[i]->write();
    }

    for (size_t i = 0; i < storage.size(); i++) {
        delete storage[i];
    }

    return 0;
}
