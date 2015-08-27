#include "scene.hpp"

#include <iostream>
#include <string>
#include "tiny_obj_loader.h"

void Scene::LoadOBJ(char *filepath) {
  std::vector<tinyobj::shape_t> shapes;
  std::vector<tinyobj::material_t> materials;

  std::string err = tinyobj::LoadObj(shapes, materials, filepath);

  if (!err.empty()) {
    std::cerr << err << std::endl;
    return;
  }

  std::cout << "# of shapes : " << shapes.size() << std::endl;
  std::cout << "# of materials : " << materials.size() << std::endl;
}
