#include "scene.h"

#include <iostream>
#include <string>
#include "tiny_obj_loader.h"

Scene Scene::LoadOBJ(char *filepath) {
  std::vector<tinyobj::shape_t> shapes;
  std::vector<tinyobj::material_t> materials;

  std::string err = tinyobj::LoadObj(shapes, materials, filepath);

  Scene scene;

  if (!err.empty()) {
    std::cerr << err << std::endl;
    return scene;
  }

  for (int i = 0; i < shapes.size(); i++) {
    Model model;

    for (int n = 0; n < shapes[i].mesh.indices.size(); n += 3) {
      Triangle triangle;
      triangle.v1 = shapes[i].mesh.positions[shapes[i].mesh.indices[n]];
      triangle.v2 = shapes[i].mesh.positions[shapes[i].mesh.indices[n+1]];
      triangle.v3 = shapes[i].mesh.positions[shapes[i].mesh.indices[n+2]];
      model.faces.push_back(triangle);
    }

    scene.models.push_back(model);
  }


  std::cout << "# of shapes : " << shapes.size() << std::endl;
  std::cout << "# of materials : " << materials.size() << std::endl;

  std::cout << "# of shapes : " << scene.models.size() << std::endl;
  if (scene.models.size() > 0)
    std::cout << "# of faces : " << scene.models[0].faces.size() << std::endl;

  return scene;
}
