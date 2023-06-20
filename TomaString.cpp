#include "TomaString.h"

int TomaString::length() const {
    int i;
    for (i = 0; tomaString[i] != MARK; i++);
    return i;
}

void TomaString::append(char ch) {
    int length = this->length();
    if (length < N) {
        tomaString[length] = ch;
        tomaString[length + 1] = MARK;
    }
}

TomaString TomaString::toLowerCase() {
    for (int i = 0; tomaString[i] != MARK; i++) {
        tomaString[i] |= 32;
    }
    return *this;
}

bool TomaString::isOdd() {
    int length = this->length();
    return (length % 2 == 1);
}

bool TomaString::middleVowel() {
    char vowels[] = "aeiouy";
    for (int i = 1; tomaString[i + 1] != MARK; i++) {
        for (char v : vowels) {
            if (tomaString[i] == v) {
                return true;
            }
        }
    }
    return false;
}

char & TomaString::operator[](unsigned index) {
    return tomaString[index];
}

char TomaString::get(int index) {
    if (index < this->length() && index >= 0) {
        return tomaString[index];
    } else {
        throw std::out_of_range("there is no char for given index. Bye!");
    }
}

TomaString & TomaString::operator=(const char *str) {
    int i;
    for (i = 0; str[i] && i < N - 1; i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    if (i < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

TomaString & TomaString::operator=(TomaString str) {
    int i;
    for (i = 0; i < str.length(); i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    if (i < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

bool TomaString::operator==(TomaString str) {
    int i;
    for (i = 0; tomaString[i] != MARK; i++) {
        if (tomaString[i] != str[i]) {
            return false;
        }
    }
    if (str[i] != MARK) {
        return false;
    }
    return true;
}

bool TomaString::operator>(TomaString str) {
    int testLength = this->length() < str.length() ? this->length() : str.length();
    for (int i = 0; i < testLength; i++) {
        if (tomaString[i] > str[i]) {
            return true;
        } else if (tomaString[i] < str[i]) {
            return false;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &stream, const TomaString &str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        stream << str.tomaString[i];
    }
    return stream;
}