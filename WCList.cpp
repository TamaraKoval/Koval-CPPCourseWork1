#include "WCList.h"
#include "TSList.h"
#include "Char.h"

void WCList::push_back(TomaString word) {
    if (!head) {
        head = new WordCounter(word);
        tail = head;
        length = 1;
    } else {
        tail->next = new WordCounter(word);
        tail = tail->next;
        length++;
    }
}

void WCList::deleteFirst() {
    if (head != nullptr) {
        WordCounter *temp = head;
        head = head->next;
        length--;
        delete temp;
    }
}

WCList::~WCList() {
    for (int i = 0; i < length; i++) {
        deleteFirst();
    }
}

void WCList::addCounter(TomaString str) {
    WordCounter *p = head;
    while (p != nullptr) {
        if (p->word == str) {
            p->increaseCounter();
            return;
        }
        p = p->next;
    }
    push_back(str);
}

void WCList::fillFromTSList(const TSList &tsList) {
    TomaString str;
    TomaString token;
    char ch;
    int tsListLength = tsList.getLength();
    for (int i = 0; i < tsListLength; i++) {
        str = tsList.getLine(i);
        int strLength = str.length();
        for (int j = 0; j < strLength; j++) {
            ch = str.get(j);
            if (!Char::isPunct(ch)) {
                token.append(ch);
            } else {
                if (token.length() > 1) {
                    addCounter(token.toLowerCase());
                    token = "";
                } else token = "";
            }
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const WCList &list) {
    WordCounter *p = list.head;
    for (int i = 0; i < list.length; i++) {
        stream << *p << "\n";
        p = p->next;
    }
    return stream;
}