//
// Created by Tudor on 4/30/2022.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "Banknote.h"

Banknote::Banknote() {
    this->index = 0;
    this->value = 0;
    this->noOccurrences = 0;
}

Banknote::Banknote(std::string args, char sep) {
    this->loadFromString(args, sep);
}

Banknote::Banknote(unsigned int index, unsigned int value, unsigned int noOccurrences) {
    this->index = index;
    this->value = value;
    this->noOccurrences = noOccurrences;
}

Banknote::Banknote(const Banknote &banknote) {
    this->index = banknote.index;
    this->value = banknote.value;
    this->noOccurrences = banknote.noOccurrences;
}

Banknote::~Banknote() = default;

unsigned int Banknote::getIndex() {
    return this->index;
}

void Banknote::setIndex(unsigned int index) {
    this->index = index;
}

unsigned int Banknote::getValue() {
    return this->value;
}

void Banknote::setValue(unsigned int value) {
    this->value = value;
}

unsigned int Banknote::getNoOccurrences() {
    return this->noOccurrences;
}

void Banknote::getNoOccurrences(unsigned int noOccurrences) {
    this->noOccurrences = noOccurrences;
}

std::string Banknote::toStringDelimiter(char sep) {
    return std::to_string(this->index) + sep + std::to_string(this->value) + sep + std::to_string(this->noOccurrences);
}

void Banknote::loadFromString(std::string args, char sep) {
    std::vector<std::string> elements;
    std::stringstream ss(args);
    std::string object;
    while (getline(ss, object, sep)) {
        elements.push_back(object);
    }
    if(elements.size() == 3) {
        std::stringstream i(elements[0]);
        i >> this->index;
        std::stringstream v(elements[1]);
        v >> this->value;
        std::stringstream o(elements[2]);
        o >> this->noOccurrences;
    }
}

Banknote &Banknote::operator=(const Banknote &banknote) {
    this->index = banknote.index;
    this->value = banknote.value;
    this->noOccurrences = banknote.noOccurrences;
    return *this;
}

std::istream &operator>>(std::istream &is, Banknote &banknote) {
    unsigned int index;
    std::cout << "Enter banknote index:"; is >> index;
    banknote.index = index;

    unsigned int value;
    std::cout << "Banknote value:"; is >> value;
    banknote.value = value;

    unsigned int noOccurrences;
    std::cout << "Number of banknotes:"; is >> noOccurrences;
    banknote.noOccurrences = noOccurrences;

    return is;
}

std::ostream &operator<<(std::ostream &os, const Banknote &banknote) {
    std::cout << "Banknote index:" << banknote.index << '\n' << "Banknote value: " << banknote.value << '\n' << "Number of occurrences: " << banknote.noOccurrences << '\n';
    return os;
}
