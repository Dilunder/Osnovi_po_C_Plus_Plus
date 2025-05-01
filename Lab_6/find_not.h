#ifndef LAB_6_FIND_NOT_H
#define LAB_6_FIND_NOT_H

template<typename T,typename Comparator, typename T_Value>
T_Value find_not(T container, T_Value element){
    Comparator compair;
    for (auto i = container.begin(); i != container.end(); ++i) {
        if (compair(*i, element) || compair(element, *i)){
            return *i;
        }
    }
    return 0;
}
#endif
