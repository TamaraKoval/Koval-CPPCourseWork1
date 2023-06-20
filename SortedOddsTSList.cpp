#include "SortedOddsTSList.h"
#include "Char.h"

void SortedOddsTSList::fillSortedOddsList(const TSList &tsList) {
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
                if (token.length() > 2 && token.isOdd() && token.middleVowel()) {
                    pushAndSort(token.toLowerCase());
                    token = "";
                } else token = "";
            }
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const SortedOddsTSList &list) {
    TSElem *p;
    for (p = list.head; p != nullptr; p = p->next) {
        stream << *p << " : " << p->str.length() << "\n";
    }
    return stream;
}