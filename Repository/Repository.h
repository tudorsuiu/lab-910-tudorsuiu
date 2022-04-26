//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_REPOSITORY_H
#define LAB_910_TUDORSUIU_REPOSITORY_H

#include <vector>

template<class T> class Repository {
private:
    std::vector<T> entities;
public:
    /**
     * Constructor
     */
    Repository() = default;

    /**
     * Copy-constructor
     * @param repository: Repository object
     */
    Repository(const Repository<T> &repository) {
        this->entities = repository.entities;
    }

    /**
     * Destructor
     */
    ~Repository() = default;

    /**
     * Add entity to repository
     * @param entity: T class object
     */
    void addEntity(T entity) {
        this->entities.push_back(entity);
    }

    /**
     * Update an entity from repository
     * @param index: int - entity location in repository
     * @param newEntity: T class object
     */
    void updateEntity(int index, T newEntity) {
        entities[index] = newEntity;
    }

    /**
     * Delete an entity from repository
     * @param index: int - entity location in repository
     */
    void deleteEntity(int index) {
        entities.erase(entities.begin() + index);
    }

    /**
     * Get all entities and returns them
     * @return: Vector<class T> - all entities stored in repository
     */
    std::vector<T> getAll() {
        return this->entities;
    }

    /**
     * Get position by product code
     * @param code: unsigned int - product code
     * @return: int - product position
     */
    int getPosByCode(unsigned int code) {
        for(int i = 0; i < entities.size(); i++) {
            if(entities[i].getCode() == code) {
                return i;
            }
        }
        return -1;
    }

    friend std::ostream &operator<<(std::ostream &os, const Repository<T> &repository) {
        for(int i = 0; i < repository.entities.size(); i++) {
            os << repository.entities[i] << '\n';
        }
        return os;
    }
};

#endif //LAB_910_TUDORSUIU_REPOSITORY_H