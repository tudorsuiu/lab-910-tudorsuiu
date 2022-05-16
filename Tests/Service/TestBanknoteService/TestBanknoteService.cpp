//
// Created by Tudor on 5/9/2022.
//

#include <cassert>
#include <iostream>
#include "TestBanknoteService.h"
#include "../../../Repository/Repository.h"
#include "../../../Domain/Banknote/Banknote.h"
#include "../../../Service/BanknoteService.h"

void TestBanknoteService::testBanknoteService() {
    Repository<Banknote> repository;
    BanknoteService service(repository);

    Banknote b1(1, 500, 10);
    Banknote b2(2, 200, 10);
    Banknote b3(3, 100, 10);
    Banknote b4(4, 50, 10);
    Banknote b5(5, 10, 10);
    Banknote b6(6, 5, 10);
    Banknote b7(7, 1, 10);
    Banknote b8(8, 0.5, 10);
    Banknote b9(9, 0.1, 10);
    Banknote b10(10, 0.05, 10);
    Banknote b11(11, 0.01, 10);

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    service.create(b6);
    service.create(b7);
    service.create(b8);
    service.create(b9);
    service.create(b10);
    service.create(b11);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);
    assert(service.read()[5] == b6);
    assert(service.read()[6] == b7);
    assert(service.read()[7] == b8);
    assert(service.read()[8] == b9);
    assert(service.read()[9] == b10);
    assert(service.read()[10] == b11);

    service.del(1);
    service.del(3);
    service.del(4);
    assert(service.read().size() == 8);

    service.update(2, Banknote(2, 50, 20));
    service.update(5, Banknote(5, 1, 20));
    assert(service.read()[0] == Banknote(2, 50, 20));
    assert(service.read()[1] == Banknote(5, 1, 20));

    service.del(2);
    service.del(5);
    service.del(6);
    service.del(7);
    service.del(8);
    service.del(9);
    service.del(10);
    service.del(11);
    assert(service.read().empty());

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    service.create(b6);
    service.create(b7);
    service.create(b8);
    service.create(b9);
    service.create(b10);
    service.create(b11);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);
    assert(service.read()[5] == b6);
    assert(service.read()[6] == b7);
    assert(service.read()[7] == b8);
    assert(service.read()[8] == b9);
    assert(service.read()[9] == b10);
    assert(service.read()[10] == b11);

    std::vector<Banknote> result = service.change(23, 100);
    assert(result[0] == Banknote(1, 500, 0));
    assert(result[1] == Banknote(2, 200, 0));
    assert(result[2] == Banknote(3, 100, 0));
    assert(result[3] == Banknote(4, 50, 1));
    assert(result[4] == Banknote(5, 10, 2));
    assert(result[5] == Banknote(6, 5, 1));
    assert(result[6] == Banknote(7, 1, 2));
    assert(result[7] == Banknote(8, 0.5, 0));
    assert(result[8] == Banknote(9, 0.1, 0));
    assert(result[9] == Banknote(10, 0.05, 0));
    assert(result[10] == Banknote(11, 0.01, 0));

    assert(service.read()[0] == Banknote(1, 500, 10));
    assert(service.read()[1] == Banknote(2, 200, 10));
    assert(service.read()[2] == Banknote(3, 100, 10));
    assert(service.read()[3] == Banknote(4, 50, 9));
    assert(service.read()[4] == Banknote(5, 10, 8));
    assert(service.read()[5] == Banknote(6, 5, 9));
    assert(service.read()[6] == Banknote(7, 1, 8));
    assert(service.read()[7] == Banknote(8, 0.5, 10));
    assert(service.read()[8] == Banknote(9, 0.1, 10));
    assert(service.read()[9] == Banknote(10, 0.05, 10));
    assert(service.read()[10] == Banknote(11, 0.01, 10));
}

void TestBanknoteService::all() {
    testBanknoteService();
}
