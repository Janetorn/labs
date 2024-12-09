#include <iostream>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;

class LibBooks {
private:
    string Author;
    string Title;
    string Type;
public:
    LibBooks(const string& writer, const string& name, const string& category) : Author(writer), Title(name), Type(category) {
        if (writer.empty()) {
            cout << "author is not specified" << endl;
            return;
        }
        if (name.empty()) {
            cout << "title is not specified" << endl;
            return;
        }
    }
    void sBook() {
        cin >> Author;
        cin >> Title;
        cin >> Type;
    }
    void gBook() {
        cout << Author << " " << Title << " " << Type << endl;
    }
};

int main() {
    string Writer;
    string Name;
    string Category;
    LibBooks book_ei(" ", " ", " ");
    book_ei.sBook();
    LibBooks book_zw(" ", " ", " ");
    book_zw.sBook();
    LibBooks book_dr(" ", " ", " ");
    book_dr.sBook();
    book_ei.gBook();
    book_zw.gBook();
    book_dr.gBook();
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
    return 0;
}
