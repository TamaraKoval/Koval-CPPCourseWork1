#include "WordCounter.h"

void WordCounter::increaseCounter() {
    count++;
}

std::ostream &operator<<(std::ostream &stream, const WordCounter &counter) {
    stream << counter.word << ": " << counter.count;
    return stream;
}