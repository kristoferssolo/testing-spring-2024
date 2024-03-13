#include "./action.hh"

#include <string>

Action::Action(std::string name, bool has_target) {
    this->name = name;
    this->has_target = has_target;
}

bool Action::operator==(const Action &other) const {
    return this->name == other.name;
}
