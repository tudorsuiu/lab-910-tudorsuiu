//
// Created by Tudor on 4/24/2022.
//

#ifndef LAB_910_TUDORSUIU_REPOSITORYINFILE_H
#define LAB_910_TUDORSUIU_REPOSITORYINFILE_H


#include <fstream>
#include <vector>
#include "IRepository.h"

template<class T> class RepositoryInFile : public IRepository<T> {
private:
    std::vector<T> elements;
    std::string fileName;
public:
    /**
     * Read from file
     * @param name: string - file name
     */
    RepositoryInFile(std::string name) {
        this->fileName = name;
        this->loadFromFile();
    }

    /**
     * Destructor
     */
    ~RepositoryInFile() = default;

    /**
     * Add entity to file
     * @param entity: T class object
     */
    virtual void addEntity(T entity) override {
        this->elements.push_back(entity);
        this->saveToFile();
    }

    /**
     * Get all entities from file
     * @return: Vector<class T> - all entities stored in file
     */
    virtual std::vector<T> getAll() override {
        return this->elements;
    }

    /**
     * Update an entity from file
     * @param index: unsigned int - entity index
     * @param newEntity: T class object - updated entity
     */
    virtual void updateEntity(unsigned int index, T newEntity) override {
        for(int i = 0; i < elements.size(); i++) {
            if(elements[i].getIndex() == index) {
                elements[i] = newEntity;
            }
        }
        this->saveToFile();
    }

    /**
     * Delete an entity from file
     * @param code: unsigned int - entity code
     */
    virtual void deleteEntity(unsigned int index) override {
        int position;
        for(int i = 0; i < elements.size(); i++) {
            if(elements[i].getIndex() == index) {
                position = i;
            }
        }
        elements.erase(elements.begin() + position);
        this->saveToFile();
    }

    /**
     * Get position by object index
     * @param index: unsigned int - object index
     * @return: int - object position
     */
    int getPosByIndex(unsigned int index) {
        for(int i = 0; i < elements.size(); i++) {
            if(elements[i].getIndex() == index) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Saves the elements from vector "elements" in file
     */
    void saveToFile()
    {
        std::ofstream f(this->fileName);
        for(T object : this->elements) {
            f << object.toStringDelimiter(' ') << '\n';
        }
        f.close();
    }


    /**
     * Loads the elements from file into "elements" vector
     */
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
