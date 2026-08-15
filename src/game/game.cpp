#include "game.hpp"
namespace game {
Game::Game() {
    const StationId station1 = world_.add_station({400, 300});
    const StationId station2 = world_.add_station({400, 400});
    const StationId station3 = world_.add_station({400, 200});
    const StationId station4 = world_.add_station({300, 300});
    const StationId station5 = world_.add_station({500, 300});

    const RouteId route1 = world_.add_route();

    world_.add_station_to_route(route1, station5);
    world_.add_station_to_route(route1, station2);
    world_.add_station_to_route(route1, station4);
    world_.add_station_to_route(route1, station3);
    world_.add_station_to_route(route1, station1);

    const BusId bus1 = world_.add_bus(route1);
}

void Game::update() {
    world_.update();
}

void Game::draw() {
    renderer_.draw(world_);
}
}  // namespace game