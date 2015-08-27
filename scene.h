#include <vector>
#include "model.h"

class Scene {
  public:
    std::vector<Model> models;

    Scene LoadOBJ(char *filepath);
};
