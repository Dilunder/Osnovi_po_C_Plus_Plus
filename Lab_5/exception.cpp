#include "exception.h"

out_of_bound_exception::out_of_bound_exception(const string& message)
    :message(message)
{}

string out_of_bound_exception::get_message() const{
    return message;
}
