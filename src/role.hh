#ifndef ROLE_HH
#define ROLE_HH

#include "action.hh"

#include <initializer_list>
#include <vector>

struct Role {
    std::vector<Action> actions;
    Role(std::initializer_list<Action> actions);
    Role(std::vector<Action> actions);
};

#endif  // ROLE_HH
