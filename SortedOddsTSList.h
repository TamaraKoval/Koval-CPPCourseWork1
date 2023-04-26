#ifndef KOVAL_COURSEWORK1_SORTEDODDSTSLIST_H
#define KOVAL_COURSEWORK1_SORTEDODDSTSLIST_H

#include "TSList.h"

class SortedOddsTSList : public TSList {
public:
    void fillSortedOddsList(const TSList &tsList);
    friend std::ostream &operator<<(std::ostream &stream, const SortedOddsTSList &list);
};

#endif //KOVAL_COURSEWORK1_SORTEDODDSTSLIST_H
