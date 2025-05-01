#ifndef LAB7_CYCLE_BUFFER_H
#define LAB7_CYCLE_BUFFER_H

#include <stdexcept>

template<typename TT> class cycle_buffer;

template<typename T>
class iterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    cycle_buffer<T> *buff;
    int ind;
public:
    iterator(cycle_buffer<T> *buff, int ind): buff(buff), ind(ind){}

    iterator operator+(int n) const {
        return iterator(buff, ind + n);
    }

    iterator operator-(int n) const {
        return iterator(buff, ind-n);
    }

    int operator-(const iterator &other) const {
        return ind - other.ind;
    }

    iterator operator++(int) {
        ind++;
        return iterator(buff, ind - 1);
    }

    iterator operator--(int) {
        ind--;
        return iterator(buff, ind + 1);
    }

    iterator &operator++() {
        ind++;
        return *this;
    }

    iterator &operator--() {
        ind--;
        return *this;
    }

    iterator &operator+=(int n){
        ind += n;
        return *this;
    }

    iterator &operator-=(int n){
        ind -= n;
        return *this;
    }

    bool operator==(const iterator &other) const {
        return (buff == other.buff && ind == other.ind);
    }

    bool operator!=(const iterator &other) const {
        return !(*this == other);
    }

    T &operator*() const {
        return (*buff)[ind];
    }

    T *operator->() const {
        return &((*buff)[ind]);
    }

    T &operator[](int ind) const {
        return (*buff)[this->ind + ind];
    }

    bool operator<(const iterator &other) const {
        return ind < other.ind;
    }

    bool operator>(const iterator &other) const {
        return ind > other.ind;
    }

    bool operator<=(const iterator &other) const {
        return ind <= other.ind;
    }

    bool operator>=(const iterator &other) const {
        return ind >= other.ind;
    }
};

template<class T>
class cycle_buffer {
private:
    int count;
    int capacity;
    int head;
    int tail;
    T *buff;
public:

    iterator<T> begin() {
        return iterator<T>(this, 0);
    }

    iterator<T> end() {
        return iterator<T>(this, count);
    }

    cycle_buffer(int size): count(0), capacity(size), tail(0), head(0) {
        buff = new T[capacity];
        if (buff == nullptr) throw std::runtime_error("Memory error");
    }

    ~cycle_buffer() {
        delete[] buff;
    }

    int size() {
        return count;
    }

    T &operator[](int i) {
        if (i < 0 || i >= count) throw std::runtime_error("index out of bound");
        int index = (head + i + 1) % capacity;
        return buff[index];
    }

    void push_front(const T &value) {
        if (count == capacity) throw std::runtime_error("overflow");
        buff[head] = value;
        head = head - 1 < 0 ? capacity - 1 : head - 1;
        if (count == 0) tail = tail + 1 < capacity ? tail + 1 : 0;
        count++;
    }

    void push_back(const T &value) {
        if (count == capacity) throw std::runtime_error("overflow");
        buff[tail] = value;
        tail = tail + 1 < capacity ? tail + 1 : 0;
        if (count == 0) head = head - 1 < 0 ? capacity - 1 : head - 1;
        count++;
    }

    void pop_back() {
        if (count == 0) throw std::runtime_error("buffer is empty");
        tail--;
        if (tail < 0) tail = capacity - 1;

    }

    void pop_front() {
        if (count == 0) throw std::runtime_error("buffer is empty");
        head++;
        if (head == capacity) head = 0;
    }

    void resize(int n) {
        T* extra_mas = new T[n];
        if (extra_mas == nullptr) throw std::runtime_error("Memory error");
        int i = (head + 1) % capacity;
        int j = 0;
        while(i != tail && j < n) {
            extra_mas[j] = buff[i];
            i++;
            j++;
            i %= capacity;
        }
        delete buff;
        buff = extra_mas;
        count = j;
        capacity = n;
        head = capacity - 1;
        tail = j;
    }
};

template<typename T>
iterator<T> operator+(int n, const iterator<T> &iter){
    return iter + n;
}

#endif