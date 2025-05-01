#ifndef LAB_5_EXCEPTION_H
#define LAB_5_EXCEPTION_H

#include <string>

using namespace std;

class out_of_bound_exception: public exception{
private:
    string message;
public:
    out_of_bound_exception(const string& message);
    string get_message() const;
};

#endif
