cmake_minimum_required(VERSION 3.21)
project(lab_910_tudorsuiu)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_910_tudorsuiu main.cpp Domain/Product.cpp Domain/Product.h Repository/Repository.h Service/Service.cpp Service/Service.h UserInterface/Console.cpp UserInterface/Console.h Tests/Test.cpp Tests/Test.h Repository/RepositoryInFile.h Repository/IRepository.h)
