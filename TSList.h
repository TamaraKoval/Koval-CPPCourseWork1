#ifndef KOVAL_COURSEWORK1_TSLIST_H
#define KOVAL_COURSEWORK1_TSLIST_H

#include "TSElem.h"

class TSList {
protected:
    TSElem *tail;
    TSElem *head;
    int length;
public:
    TSList() { head = nullptr; tail = nullptr; length = 0;}
    ~TSList();
    void deleteFirst();
    int getLength() const { return length; }
    TomaString getLine(int i) const;
    bool isInList(TomaString str);
    void pushBack(TomaString str);
    void pushAndSort(TomaString str);
    friend std::ostream &operator<<(std::ostream &stream, const TSList &list);
};

#endif //KOVAL_COURSEWORK1_TSLIST_H
