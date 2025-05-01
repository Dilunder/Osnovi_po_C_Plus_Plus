#include <iostream>
#include <algorithm>
#include "cycle_buffer.h"

using namespace std;

class comparator{
public:
    bool operator()(const int &lo, const int &ro){
        return lo < ro;
    }
};

int main() {
    cycle_buffer<int> buff(10);
    buff.push_back(4);
    buff.push_front(7);
    buff.push_back(19);
    buff.push_front(3);
    buff.push_back(23);
    buff.push_front(8);

    for (int i = 0; i < buff.size(); ++i)
        cout << buff[i] << ' ';
    cout << '\n';
    for (auto i = buff.begin(); i < buff.end(); i = 1 + i) {
        cout << *i << ' ';
    }
    cout << endl;
    sort(buff.begin(), buff.end(), comparator());
    for (auto i = buff.begin(); i < buff.end(); i = 1 + i) {
        cout << *i << ' ';
    }
    cout << endl;
    return 0;
}
