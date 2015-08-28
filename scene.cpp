#include "scene.h"

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

  for (int i = 0; i < shapes.size(); i++) {
    Model model;

    for (int n = 0; n < shapes[i].mesh.indices.size(); n += 3) {
      Triangle triangle;
      triangle.v1.x = shapes[i].mesh.positions[shapes[i].mesh.indices[n]];
      triangle.v1.y = shapes[i].mesh.positions[shapes[i].mesh.indices[n]+1];
      triangle.v1.z = shapes[i].mesh.positions[shapes[i].mesh.indices[n]+2];
      triangle.v2.x = shapes[i].mesh.positions[shapes[i].mesh.indices[n+1]];
      triangle.v2.y = shapes[i].mesh.positions[shapes[i].mesh.indices[n+1]+1];
      triangle.v2.z = shapes[i].mesh.positions[shapes[i].mesh.indices[n+1]+2];
      triangle.v3.x = shapes[i].mesh.positions[shapes[i].mesh.indices[n+2]];
      triangle.v3.y = shapes[i].mesh.positions[shapes[i].mesh.indices[n+2]+1];
      triangle.v3.z = shapes[i].mesh.positions[shapes[i].mesh.indices[n+2]+2];
      model.faces.push_back(triangle);
    }

    this->models.push_back(model);
  }


  std::cout << "# of shapes : " << shapes.size() << std::endl;
  std::cout << "# of materials : " << materials.size() << std::endl;

  std::cout << "# of shapes : " << this->models.size() << std::endl;
  if (this->models.size() > 0)
    std::cout << "# of faces : " << this->models[0].faces.size() << std::endl;
}
