#ifndef LAB_5_MAX_NUMBER_H
#define LAB_5_MAX_NUMBER_H

template<typename T>
T max_value(const T* massive, int size){
    T max_number = massive[0];
    for (int i = 0; i < size; ++i) {
        if (max_number < massive[i])
            max_number = massive[i];
    }
    return max_number;
}

#endif
