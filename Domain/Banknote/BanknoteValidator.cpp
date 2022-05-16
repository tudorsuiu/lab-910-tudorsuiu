//
// Created by Tudor on 5/9/2022.
//

#include "BanknoteValidator.h"
#include "../MyException.h"

void BanknoteValidator::validate(Banknote banknote) {
    if(banknote.getIndex() <= 0) {
        throw MyException("Banknote ID must be positive.");
    }
    else if(banknote.getValue() != 0.01 && banknote.getValue() != 0.05 && banknote.getValue() != 0.10 && banknote.getValue() != 0.50 && banknote.getValue() != 1 && banknote.getValue() != 5 &&
    banknote.getValue() != 10 && banknote.getValue() != 50 && banknote.getValue() != 100 && banknote.getValue() != 200 && banknote.getValue() != 500) {
        throw MyException("This vending machine only accepts banknotes with a value of 0.01, 0.05, 0.10, 0.5, 1, 5, 10, 50 or 100 RON.");
    }
    else if(banknote.getNoOccurrences() < 0) {
        throw MyException("The number of occurrences of a banknote must be positive!");
    }
}
