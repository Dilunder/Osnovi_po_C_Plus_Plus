#ifndef LAB_3_SUBSET_0_9_H
#define LAB_3_SUBSET_0_9_H

#include <iostream>

class subset_0_9{
public:
    static const int max_item = 10;
private:
    int subset[max_item] = {0};
public:
    subset_0_9();
    subset_0_9(const subset_0_9& ro);
    int get_num_of_subset(int num) const;
    bool operator==(const subset_0_9& ro) const;
    bool operator!=(const subset_0_9& ro) const;
    subset_0_9 operator+(const subset_0_9& ro) const;
    subset_0_9& operator+=(int ro);
    subset_0_9& operator-=(int ro);
};

std::ostream& operator<<(std::ostream& out,const subset_0_9& ro);

#endif
