#include <iostream>
#include <vector>
#include "none_of.h"
#include "is_sorted.h"
#include "find_not.h"

template<typename T>
class positive_predicate{
public:
    bool operator()(T num){
        return num > 0;
    }
};

template<typename T>
class less_comparator{
public:
    bool operator()(T num1, T num2){
        return num1 < num2;
    }
};

using namespace std;

int main() {
    vector<int> G;
    int num;
    for (int i = 0; i < 5; ++i) {
        cin >> num;
        G.push_back(num);
    }
    int extra = rand() % 10;
    if (none_of<vector<int>, positive_predicate<int>>(G)) cout << "YES" << endl;
    else cout << "NO" << endl;
    if (is_sorted<vector<int>, less_comparator<int>>(G)) cout << "YES" << endl;
    else cout << "NO" << endl;
    cout << extra << ' ' << find_not<vector<int>, less_comparator<int>, int>(G, extra) << endl;
    return 0;
}
