#include "TSElem.h"

std::ostream &operator<<(std::ostream &stream, const TSElem &elem) {
    stream << elem.str;
    return stream;
}