#include "world.hpp"

void game::World::update() {}

game::StationId game::World::create_station(game::Position position) {
    StationId id{next_station_id_++};
    station_.emplace_back(id, position);
    return id;
}

game::Station& game::World::station(game::StationId id) {
    return station_.at(id.value);
}
const game::Station& game::World::station(game::StationId id) const {
    return station_.at(id.value);
}
