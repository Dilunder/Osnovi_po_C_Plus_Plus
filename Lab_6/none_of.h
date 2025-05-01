#ifndef LAB_6_NONE_OF_H
#define LAB_6_NONE_OF_H

template<typename T, typename Predicate>
bool none_of(T container){
    Predicate predict;
    for (auto i = container.begin(); i != container.end() ; ++i) {
        if (predict(*i)) return false;
    }
    return true;
}

#endif
