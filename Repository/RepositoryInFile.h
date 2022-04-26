//
// Created by Tudor on 4/24/2022.
//

#ifndef LAB_910_TUDORSUIU_REPOSITORYINFILE_H
#define LAB_910_TUDORSUIU_REPOSITORYINFILE_H


#include <fstream>
#include <vector>
#include "IRepository.h"

template<class T> class RepositoryInFile {
private:
    std::vector<T> elements;
    std::string fileName;
public:
    RepositoryInFile(std::string name) {
        this->fileName = name;
    }

    ~RepositoryInFile() = default;

    virtual void addEntity(T entity) {
        this->elements.push_back(entity);
        this->saveToFile();
    }

    virtual std::vector<T> getAll() {
        return this->elements;
    }

    virtual void updateEntity(unsigned int code, T newEntity) {
        for(int i = 0; i < elements.size(); i++) {
            if(elements[i].getCode() == code) {
                elements[i] = newEntity;
            }
        }
        this->saveToFile();
    }

    virtual void deleteEntity(unsigned int code) {
        int index;
        for(int i = 0; i < elements.size(); i++) {
            if(elements[i].getCode() == code) {
                index = i;
            }
        }
        elements.erase(elements.begin() + index);
        this->saveToFile();
    }

    void saveToFile()
    {
        std::ofstream f(this->fileName);
        for (T object : this->elements) {
            f << object.toStringDelimiter(' ') << '\n';
        }
        f.close();
    }

    void loadFromFile()
    {
        std::string line;
        std::ifstream f(this->fileName);
        while (std::getline(f, line)) {
            T object(line, ' ');
            this->elements.push_back(object);
        }
    }
};


#endif //LAB_910_TUDORSUIU_REPOSITORYINFILE_H
