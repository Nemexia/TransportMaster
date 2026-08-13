#include "game.hpp"

game::Game::Game() {
    const StationId station1 = world_.create_station({400, 300});
    const StationId station2 = world_.create_station({400, 400});
    const StationId station3 = world_.create_station({400, 200});
    const StationId station4 = world_.create_station({300, 300});
    const StationId station5 = world_.create_station({500, 300});

    const RouteId route1 = world_.create_route();

    world_.route(route1).add_station(station5);
    world_.route(route1).add_station(station2);
    world_.route(route1).add_station(station4);
    world_.route(route1).add_station(station3);
    world_.route(route1).add_station(station1);
}

void game::Game::update() {
    world_.update();
}

void game::Game::draw() {
    renderer_.draw(world_);
}
