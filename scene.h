#include <vector>
#include "model.h"

class Scene {
  public:
    std::vector<Model> models;

    void LoadOBJ(char *filepath);
};
