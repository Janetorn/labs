#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string name;
    float price;
public:
    void getdata() {
        cin >> name;
        cin >> price;
    }
    void putdata() {
        cout << name << endl;
        cout << price << endl;
    }
};
class book : public Publication {
private:
    int pages;
public:
    void getdata() {
        cin >> name;
        cin >> price;
        cin >> pages;
    }
    void putdata() {
        cout << "book title " << name << endl;
        cout << "price of the book " << price << endl;
        cout << "number of pages " << pages << endl;
    }
};
class atype : public Publication {
private:
    int time;
public:
    void getdata() {
        cin >> name;
        cin >> price;
        cin >> time;
    }

    void putdata() {
        cout << "book title " << name << endl;
        cout << "price of the book " << price << endl;
        cout << "listening time " << time << endl;
    }
};

main() {
    book book1;
    atype audio1;
    book1.getdata();
    book1.putdata();
    audio1.getdata();
    audio1.putdata();
    return 0;
}
