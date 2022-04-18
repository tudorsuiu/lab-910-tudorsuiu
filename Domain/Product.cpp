//
// Created by Tudor on 4/18/2022.
//

#include <iostream>
#include "Product.h"

Product::Product() {
    this->code = 0;
    this->price = 0;
}

Product::Product(unsigned int code, std::string name, unsigned int price) {
    this->code = code;
    this->name = name;
    this->price = price;
}

Product::Product(const Product &product) {
    this->code = product.code;
    this->name = product.name;
    this->price = product.price;
}

Product::~Product() = default;

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

void Product::setPrice(unsigned int price) {
    this->price = price;
}

Product &Product::operator=(const Product &product) {
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
    os << "Product code: " << product.code << '\n' <<
    "Product name: " << product.name << '\n' << "Product price: " <<
    product.price << '\n';

    return os;
}
