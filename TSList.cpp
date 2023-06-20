#include "TSList.h"

int TSList::getLength() const {
    if (head) {
        TSElem *p;
        int i;
        for (i = 0, p = head; p!= nullptr; p=p->next, i++);
        return i;
    }
    return 0;
}

void TSList::deleteFirst() {
    if (head != nullptr) {
        TSElem *temp = head;
        head = head->next;
        delete temp;
    }
}

TSList::~TSList() {
    while (head != nullptr) {
        deleteFirst();
    }
}

TomaString TSList::getLine(int index) const {
    if (index >= this->getLength()) {
        throw std::out_of_range("there is no line for given index. Bye!");
    }
    TSElem *p;
    p = head;
    while (index) {
        p = p->next;
        index--;
    }
    return p->str;
}

bool TSList::isInList(TomaString str) {
    TSElem *p;
    for (p = head;  p != nullptr; p = p->next) {
        if (p->str == str) {
            return true;
        }
    }
    return false;
}

void TSList::pushBack(TomaString str) {
    if (!head) {
        head = new TSElem(str);
        tail = head;
    } else {
        tail->next = new TSElem(str);
        tail = tail->next;
    }
}

void TSList::pushAndSort(TomaString str) {
    if (!head) {
        head = new TSElem(str);
        tail = head;
    } else {
        if (isInList(str)) return;
        TSElem *q, *pr, *p;
        q = new TSElem(str);
        for (p = head, pr = nullptr; p != nullptr && (str > p->str); pr = p, p = p->next);
        if (!pr) {
            q->next = head;
            head = q;
        } else {
            q->next = p;
            if (!p) {
                tail = q;
            }
            pr->next = q;
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const TSList &list) {
    TSElem *p;
    for (p = list.head; p != nullptr; p = p->next) {
        stream << *p << "\n";
    }
    return stream;
}