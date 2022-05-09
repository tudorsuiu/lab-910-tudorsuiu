//
// Created by Tudor on 5/9/2022.
//

#include "BanknoteValidator.h"
#include "../MyException.h"

void BanknoteValidator::validate(Banknote banknote) {
    if(banknote.getIndex() <= 0) {
        throw MyException("Banknote ID must be positive.");
    }
    else if(banknote.getValue() != 1 && banknote.getValue() != 5 &&
    banknote.getValue() != 10 && banknote.getValue() != 50 && banknote.getValue() != 100) {
        throw MyException("This vending machine only accepts banknotes with a value of 1, 5, 10, 50 or 100 RON.");
    }
    else if(banknote.getNoOccurrences() < 0) {
        throw MyException("The number of occurrences of a banknote must be positive!");
    }
}
