#include <iostream>
#include "triangle.h"
#include "subset_0_9.h"

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    vector a(x, y);
    cin >> x >> y;
    vector b(x, y);
    cin >> x >> y;
    vector c(x, y);
    triangle abc(a, b, c);
    cin >> x >> y;
    vector a1(x, y);
    cin >> x >> y;
    vector b1(x, y);
    cin >> x >> y;
    vector c1(x, y);
    triangle a1b1c1(a1, b1, c1);
    if (abc < a1b1c1) cout << "First triangle is smaller than second" << endl;
    if (abc > a1b1c1) cout << "First triangle is bigger than second" << endl;
    if (abc == a1b1c1) cout << "They are equal!" << endl;
    if (abc.operator<(a1b1c1)) cout << "First triangle is smaller than second" << endl;
    if (abc.operator>(a1b1c1)) cout << "First triangle is bigger than second" << endl;
    if (abc.operator==(a1b1c1)) cout << "They are equal!" << endl;
    subset_0_9 first_subset;
    subset_0_9 second_subset;
    int num, quantity;
    cout << "Vvedite colichestvo elementov 1 mnojestva: ";
    cin >> quantity;
    for (int i = 0; i < quantity; ++i) {
        cin >> num;
        first_subset += num;
    }
    cout << "Vvedite colichestvo elementov 2 mnojestva: ";
    cin >> quantity;
    for (int i = 0; i < quantity; ++i) {
        cin >> num;
        second_subset += num;
    }
    if (first_subset.operator==(second_subset)) cout << "They are equal!" << endl;
    if (first_subset.operator!=(second_subset)) cout << "They are not equal!" << endl;

    subset_0_9 extra;
    extra = first_subset + second_subset;
    cout << extra;
    return 0;
}
