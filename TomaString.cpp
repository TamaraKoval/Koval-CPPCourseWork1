#include "TomaString.h"

TomaString::TomaString(const char *str) {
    int i;
    for(i = 0; str[i]; i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    curMarkPos = i;
}

int TomaString::length() {
    return curMarkPos;
}

void TomaString::append(char ch) {
    curMarkPos++;
    tomaString[curMarkPos] = MARK;
    tomaString[curMarkPos - 1] = ch;
}

TomaString TomaString::toLowerCase() {
    for (int i = 0; i < curMarkPos; i++) {
        tomaString[i] |= 32;

    }
    return *this;
}

bool TomaString::isOdd() {
    return (curMarkPos % 2 == 1);
}

bool TomaString::middleVowel() {
    char vowels[] = "aeiouy";
    for (int i = 1; i < (curMarkPos - 1); i++) {
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
    if (index < curMarkPos && index >= 0) {
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
    curMarkPos = i;
    if (curMarkPos < N) {
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
    curMarkPos = i;
    if (curMarkPos < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

bool TomaString::operator==(TomaString str) {
    for (int i = 0; i < curMarkPos; i++) {
        if (tomaString[i] != str[i]) {
            return false;
        }
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

bool TomaString::operator>=(TomaString str) {
    if (this->curMarkPos == str.curMarkPos) {
        for (int i = 0; i < curMarkPos; i++) {
            if (tomaString[i] > str[i]) {
                return true;
            } else if (tomaString[i] < str[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &stream, const TomaString &str) {
    for (int i = 0; i < str.curMarkPos; i++) {
        stream << str.tomaString[i];
    }
    return stream;
}