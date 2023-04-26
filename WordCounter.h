#ifndef KOVAL_COURSEWORK1_WORDCOUNTER_H
#define KOVAL_COURSEWORK1_WORDCOUNTER_H

#include "TomaString.h"

class WordCounter {
public:
    TomaString word;
    int count;
    WordCounter *next;
    WordCounter(TomaString str, WordCounter *next = nullptr) { word = str; count = 1; this->next = next;}
    void increaseCounter();
    friend std::ostream &operator<<(std::ostream &stream, const WordCounter &counter);
};

#endif //KOVAL_COURSEWORK1_WORDCOUNTER_H
