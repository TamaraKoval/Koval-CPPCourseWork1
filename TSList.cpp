#include "TSList.h"

void TSList::deleteFirst() {
    if (head != nullptr) {
        TSElem *temp = head;
        head = head->next;
        length--;
        delete temp;
    }
}

TSList::~TSList() {
    for (int i = 0; i < length; i++) {
        deleteFirst();
    }
}

TomaString TSList::getLine(int index) const {
    if (index >= length) {
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
    for (p = head; p != nullptr; p = p->next) {
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
        length = 1;
    } else {
        tail->next = new TSElem(str);
        tail = tail->next;
        length++;
    }
}

void TSList::pushAndSort(TomaString str) {
    if (!head) {
        head = new TSElem(str);
        tail = head;
        length = 1;
    } else {
        if (isInList(str)) return;
        TSElem *q, *pr, *p;
        q = new TSElem(str);
        for (p = head, pr = nullptr; p != nullptr && (str > p->str); pr = p, p = p->next);
        if (pr == nullptr) {
            q->next = head;
            head = q;
            length++;
        } else {
            q->next = p;
            if (p == nullptr) {
                tail = q;
            }
            pr->next = q;
            length++;
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const TSList &list) {
    TSElem *p = list.head;
    for (int i = 0; i < list.length; i++) {
        stream << *p << "\n";
        p = p->next;
    }
    return stream;
}