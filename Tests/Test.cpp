//
// Created by Tudor on 4/18/2022.
//

#include "Test.h"
#include "../Domain/Product/Product.h"
#include "../Repository/Repository.h"
#include "../Service/ProductService.h"
#include "../Domain/Banknote/Banknote.h"
#include "../Service/BanknoteService.h"
#include "Domain/TestBanknoteDomain/TestBanknoteDomain.h"
#include "Domain/TestProductDomain/TestProductDomain.h"
#include "Repository/TestProductRepository/TestProductRepository.h"
#include "Repository/TestProductRepositoryInFile/TestProductRepositoryInFile.h"
#include "Service/TestBanknoteService/TestBanknoteService.h"
#include "Service/TestProductService/TestProductService.h"
#include <cassert>
#include <iostream>

void Test::all() {
    TestBanknoteDomain testBanknoteDomain;
    testBanknoteDomain.all();
    TestProductDomain testProductDomain;
    testProductDomain.all();
    TestProductRepository testProductRepository;
    testProductRepository.all();
    TestProductRepositoryInFile testProductRepositoryInFile;
    testProductRepositoryInFile.all();
    TestBanknoteService testBanknoteService;
    testBanknoteService.all();
    TestProductService testProductService;
    testProductService.all();
}
