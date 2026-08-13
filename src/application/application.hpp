#pragma once
namespace game {
class Application {
  public:
    int run();

  private:
    void initialize();
    void shutdown();
};
}  // namespace game