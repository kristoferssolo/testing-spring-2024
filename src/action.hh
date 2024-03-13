#ifndef ACTION_HH
#define ACTION_HH
#include <string>

struct Action {
    std::string name;
    bool has_target;

    Action(std::string name, bool has_target);
    bool operator==(const Action &other) const;
};

#endif  // !ACTION_HH
