// location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

class Location {
public:
    Location(const std::string& name, const std::vector<std::string>& monsters);
    std::string getName() const;
    std::vector<std::string> getMonsters() const;
private:
    std::string name;
    std::vector<std::string> monsters;
};

#endif // LOCATION_H