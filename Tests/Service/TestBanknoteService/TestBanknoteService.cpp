//
// Created by Tudor on 5/9/2022.
//

#include <cassert>
#include "TestBanknoteService.h"
#include "../../../Repository/Repository.h"
#include "../../../Domain/Banknote/Banknote.h"
#include "../../../Service/BanknoteService.h"

void TestBanknoteService::testBanknoteService() {
    Repository<Banknote> repository;
    BanknoteService service(repository);

    Banknote b1(1, 100, 10);
    Banknote b2(2, 50, 10);
    Banknote b3(3, 10, 10);
    Banknote b4(4, 5, 10);
    Banknote b5(5, 1, 10);

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);

    service.del(1);
    service.del(3);
    service.del(4);
    assert(service.read().size() == 2);

    service.update(2, Banknote(2, 50, 20));
    service.update(5, Banknote(5, 1, 20));
    assert(service.read()[0] == Banknote(2, 50, 20));
    assert(service.read()[1] == Banknote(5, 1, 20));

    service.del(2);
    service.del(5);
    assert(service.read().empty());

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);

    std::vector<Banknote> result = service.change(23, 100);
    assert(result[0] == Banknote(1, 100, 0));
    assert(result[1] == Banknote(2, 50, 1));
    assert(result[2] == Banknote(3, 10, 2));
    assert(result[3] == Banknote(4, 5, 1));
    assert(result[4] == Banknote(5, 1, 2));

    assert(service.read()[0] == Banknote(1, 100, 10));
    assert(service.read()[1] == Banknote(2, 50, 9));
    assert(service.read()[2] == Banknote(3, 10, 8));
    assert(service.read()[3] == Banknote(4, 5, 9));
    assert(service.read()[4] == Banknote(5, 1, 8));
}

void TestBanknoteService::all() {
    testBanknoteService();
}
