#include <iostream>
#include "massive.h"
#include "max_number.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    int mas1[n];
    double  mas2[n];
    for (int i = 0; i < n; ++i) {
        mas1[i] = rand() % 10;
        mas2[i] = rand() % 10;
    }
    for (int i = 0; i < n; ++i)
        cout << mas1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << mas2[i] << " ";
    cout << endl;
    cout << max_value(mas1, n) << " " << max_value(mas2, n) << endl;

    massive<int, 5> mas3;
    for (int i = 0; i < mas3.size(); ++i)
        mas3[i] = rand() % 10;
    cout << mas3[5] << endl;
    return 0;
}
