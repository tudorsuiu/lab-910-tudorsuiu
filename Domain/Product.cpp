//
// Created by Tudor on 4/18/2022.
//

#include <iostream>
#include "Product.h"

Product::Product() {
    this->index = 0;
    this->code = 0;
    this->price = 0;
}

Product::Product(std::string args, char sep){
    this->loadFromString(args, sep);
}

Product::Product(unsigned int index, unsigned int code, std::string name, unsigned int price) {
    this->index = index;
    this->code = code;
    this->name = name;
    this->price = price;
}

Product::Product(const Product &product) {
    this->index = product.index;
    this->code = product.code;
    this->name = product.name;
    this->price = product.price;
}

Product::~Product() = default;

unsigned int Product::getIndex() {
    return this->index;
}

void Product::setIndex(unsigned int index) {
    this->index = index;
}

unsigned int Product::getCode() {
    return this->code;
}

void Product::setCode(unsigned int code) {
    this->code = code;
}

std::string Product::getName() {
    return this->name;
}

void Product::setName(std::string name) {
    this->name = name;
}

unsigned int Product::getPrice() {
    return this->price;
}

std::string Product::toStringDelimiter(char sep) {
    return std::to_string(this->index) + sep +std::to_string(this->code) +
    sep + this->name + sep + std::to_string(this->price);
}

void Product::loadFromString(std::string args, char sep) {
    std::vector<std::string> elements;
    std::stringstream ss (args);
    std::string object;
    while (getline (ss, object, sep)) {
        elements.push_back(object);
    }
    if(elements.size() == 4) {
        std::stringstream i(elements[0]);
        i >> this->index;
        std::stringstream c(elements[1]);
        c >> this->code;
        this->name = elements[2];
        std::stringstream p(elements[3]);
        p >> this->price;
    }
}

void Product::setPrice(unsigned int price) {
    this->price = price;
}

Product &Product::operator=(const Product &product) {
    this->index = product.index;
    this->code = product.code;
    this->name = product.name;
    this->price = product.price;

    return *this;
}

bool Product::operator<(const Product &product) const {
    if(this->name == product.name) {
        if(this->price < product.price) {
            return true;
        }
        if(this->price > product.price) {
            return false;
        }
    }
    return false;
}

bool Product::operator>(const Product &product) const {
    return product < *this;
}

bool Product::operator<=(const Product &product) const {
    return !(product < *this);
}

bool Product::operator>=(const Product &product) const {
    return !(*this < product);
}

bool Product::operator==(const Product &product) const {
    return this->code == product.code && this->name == product.name && this->price == product.price;
}

bool Product::operator!=(const Product &product) const {
    return !(*this == product);
}

std::istream &operator>>(std::istream &is, Product &product) {
    unsigned int index;
    std::cout << "Enter product index:"; is >> index;
    product.index = index;

    unsigned int code;
    std::cout << "Enter product code:"; is >> code;
    product.code = code;

    std::string name;
    std::cout << "Enter product name:"; is >> name;
    product.name = name;

    unsigned int price;
    std::cout << "Enter product price:"; is >> price;
    product.price = price;

    return is;
}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << "Product index: " << product.index << '\n' <<
    "Product code: " << product.code << '\n' <<
    "Product name: " << product.name << '\n' <<
    "Product price: " << product.price << '\n';

    return os;
}
