#pragma once
namespace game {
class World;
class Renderer {
  public:
    void draw(const World& world);
};
}  // namespace game