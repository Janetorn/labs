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
class Sales {
protected:
    float sales[3];
public:
    void getSalesData() {
        for (int i = 0; i < 3; i = i + 1) {
            cin >> sales[i];
        }
    }
    void putSalesData() {
        for (int i = 0; i < 3; i = i + 1) {
            cout << sales[i] << " ";
        }

    }
};
class book : public Publication, public Sales {
private:
    int pages;
public:
    void getdata() {
        getSalesData();
        cin >> name;
        cin >> price;
        cin >> pages;
    }
    void putdata() {
        cout << "book title " << name << endl;
        cout << "price of the book " << price << endl;
        cout << "number of pages " << pages << endl;
        putSalesData();
    }
};
class atype : public Publication, public Sales {
private:
    int time;
public:
    void getdata() {
        getSalesData();
        cin >> name;
        cin >> price;
        cin >> time;
    }

    void putdata() {
        cout << "book title " << name << endl;
        cout << "price of the book " << price << endl;
        cout << "listening time " << time << endl;
        putSalesData();
    }
};

int main() {
    book book1;
    atype audio1;
    book1.getdata();
    book1.putdata();
    audio1.getdata();
    audio1.putdata();
    return 0;
}
