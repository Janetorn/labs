#include <iostream>
#include <vector>
using namespace std;

class Assembly {
private:
    friend class F;
protected:
    Assembly() {}
public:
    void get() {
        cout << "Assembly" << endl;
    }
};

class Part : public Assembly {
private:
    friend class F;
protected:
    Part() {}
public:
    void get() {
        cout << "Part" << endl;
    }
};

class F {
public:
    static Assembly* createAssembly() {
        return nullptr;
    }

    static Part* createPart() {
        return new Part();
    }
};

void s() {
    vector<Assembly*> storage;
    storage.push_back(F::createAssembly());
    storage.push_back(F::createPart());
    for (size_t i = 0; i < storage.size(); i++) {
        if (storage[i] != nullptr) {
            storage[i]->get();
        }
    }

    Part* p = F::createPart();
    p->get();

    for (auto& item : storage) {
        delete item;
    }
    delete p;
}

int main() {
    s();
    return 0;
}
