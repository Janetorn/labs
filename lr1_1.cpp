#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int* M = new int[n];
    for (int i = 0; i < n; i = i + 1) {
        cin >> M[i];
    }
    for (int i = 0; i < n;i = i + 1) {
        cout << M[i] << " " << &M[i] << " " << (&M[i] - M) << endl;
    }
    cout << M;
    delete[]M;
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
    return 0;
}
