#include <vector>
#include "vector.h"

class Mesh;

class Triangle {
  public:
    unsigned int vertices[3];
    const Mesh* mesh;
};

class Mesh {
  public:
    std::vector<Vector3> vertices;
    std::vector<Triangle> faces;
};
