#ifndef LAB_5_MASSIVE_H
#define LAB_5_MASSIVE_H

#include "exception.h"

template<typename T, int N>
class massive {
private:
    T mas[N];
public:
    T& operator[](int ind);
    int size() const;
};

template<typename T, int N>
T& massive<T, N>::operator[](int ind){
    if(ind >= N || ind < 0)
        throw out_of_bound_exception("Ind_out_of_bound");
    return mas[ind];
}

template<typename T, int N>
int massive<T, N>::size() const{
    return N;
}

#endif
