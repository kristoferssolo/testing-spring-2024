#include "event.hh"

#include "action.hh"
#include "time.hh"

#include <initializer_list>
#include <string>
#include <vector>

Event::Event(std::string title,
             uint32_t created_at,
             uint32_t night_number,
             bool is_visible,
             std::vector<Action> prohibits,
             std::vector<Action> allows):
    title(title),
    created_at(create_utc_timestamp(created_at)),
    night_number(night_number),
    is_visible(is_visible),
    prohibits(prohibits),
    allows(allows) {
}

Event::Event(std::string title,
             uint32_t created_at,
             uint32_t night_number,
             bool is_visible,
             std::initializer_list<Action> prohibits,
             std::initializer_list<Action> allows):
    title(title),
    created_at(create_utc_timestamp(created_at)),
    night_number(night_number),
    is_visible(is_visible),
    prohibits(prohibits),
    allows(allows) {
}

bool Event::operator<(const Event &right) const {
    return this->created_at < right.created_at;
}

bool Event::operator==(const Event &right) const {
    return this->created_at == right.created_at;
}

bool Event::operator>(const Event &right) const {
    return this->created_at > right.created_at;
}
