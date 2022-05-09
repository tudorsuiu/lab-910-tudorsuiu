//
// Created by Tudor on 5/9/2022.
//

#include <cassert>
#include "TestBanknoteDomain.h"
#include "../../../Domain/Banknote/Banknote.h"

void TestBanknoteDomain::testBanknoteDomain() {
    Banknote banknote;
    assert(banknote.getIndex() == 0);
    assert(banknote.getValue() == 0);
    assert(banknote.getNoOccurrences() == 0);

    banknote.setIndex(1);
    banknote.setValue(1);
    banknote.setNoOccurrences(10);
    assert(banknote.getIndex() == 1);
    assert(banknote.getValue() == 1);
    assert(banknote.getNoOccurrences() == 10);


    Banknote banknote1(2, 5, 10);
    assert(banknote1.getIndex() == 2);
    assert(banknote1.getValue() == 5);
    assert(banknote1.getNoOccurrences() == 10);

    banknote = banknote1;
    assert(banknote1.getIndex() == 2);
    assert(banknote1.getValue() == 5);
    assert(banknote1.getNoOccurrences() == 10);
}

void TestBanknoteDomain::all() {
    testBanknoteDomain();
}
