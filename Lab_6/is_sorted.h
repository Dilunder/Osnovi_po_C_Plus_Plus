#ifndef LAB_6_IS_SORTED_H
#define LAB_6_IS_SORTED_H

template<typename T, typename Comparator>
bool is_sorted(T container){
    Comparator compare;
    auto current = container.begin(), prev = container.begin();
    current++;
    for (; current != container.end(); ++current, ++prev) {
        if (compare(*current, *prev)) return false;
    }
    return true;
}

#endif
