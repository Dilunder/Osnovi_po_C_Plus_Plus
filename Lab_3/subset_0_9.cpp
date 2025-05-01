#include "subset_0_9.h"

subset_0_9::subset_0_9(){}

subset_0_9::subset_0_9(const subset_0_9& ro){
    for (int i = 0; i < max_item; ++i) {
         subset[i] = ro.subset[i];
    }
}

int subset_0_9::get_num_of_subset(int num)const{
    return subset[num];
}

bool subset_0_9::operator==(const subset_0_9& ro) const{
    for (int i = 0; i < max_item; ++i) {
        if(get_num_of_subset(i) != ro.get_num_of_subset(i)) return false;
    }
    return true;
}
bool subset_0_9::operator!=(const subset_0_9& ro) const{
    for (int i = 0; i < max_item; ++i) {
        if(get_num_of_subset(i) != ro.get_num_of_subset(i)) return true;
    }
    return false;
}
subset_0_9 subset_0_9::operator+(const subset_0_9& ro) const{
    subset_0_9 extra(*this);
    for (int i = 0; i < max_item; ++i) {
        if (ro.get_num_of_subset(i) == 1 || get_num_of_subset(i) == 1) extra.subset[i] = 1;
    }
    return extra;
}
subset_0_9& subset_0_9::operator+=(int ro){
    if (ro >= 0 && ro < max_item){
        subset[ro] = 1;
    }
    return *this;
}
subset_0_9& subset_0_9::operator-=(int ro){
    if (ro >= 0 && ro < max_item){
        subset[ro] = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out,const subset_0_9& ro){
    for (int i = 0; i < subset_0_9::max_item; ++i) {
        if (ro.get_num_of_subset(i))
            out << i << ' ';
    }
    return out;
}
