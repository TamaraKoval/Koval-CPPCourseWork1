#include "Char.h"

bool Char::isPunct(char ch) {
    char punctArray[] = " .,!?:;()\n\t\r\v";
    for (char p : punctArray) {
        if (ch == p) {
            return true;
        }
    }
    return false;
}
