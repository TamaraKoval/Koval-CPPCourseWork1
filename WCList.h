#ifndef KOVAL_COURSEWORK1_WCLIST_H
#define KOVAL_COURSEWORK1_WCLIST_H

#include "WordCounter.h"
#include "TSList.h"

class WCList {
    WordCounter *head;
    WordCounter *tail;
    void push_back(TomaString word);
public:
    WCList() { head = nullptr; tail = nullptr; }
    ~WCList();
    void deleteFirst();
    void addCounter(TomaString word);
    void fillFromTSList(const TSList &tsList);
    friend std::ostream &operator<<(std::ostream &stream, const WCList &list);
};

#endif //KOVAL_COURSEWORK1_WCLIST_H
