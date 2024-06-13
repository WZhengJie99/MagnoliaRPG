// location.cpp
#include "location.h"

Location::Location(const std::string& name, const std::vector<std::string>& monsters)
    : name(name), monsters(monsters) {}

std::string Location::getName() const {
    return name;
}

std::vector<std::string> Location::getMonsters() const {
    return monsters;
}
