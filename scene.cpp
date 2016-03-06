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
    Mesh *mesh = new Mesh();

    for (int n = 0; n < shapes[i].mesh.positions.size(); n+=3) {
      mesh->vertices.push_back(Vector3(shapes[i].mesh.positions[n],
                                      shapes[i].mesh.positions[n+1],
                                      shapes[i].mesh.positions[n+2]));
    }

    for (int n = 0; n < shapes[i].mesh.indices.size(); n+=3) {
      Triangle triangle;
      triangle.mesh = mesh;
      triangle.vertices[0] = shapes[i].mesh.indices[n];
      triangle.vertices[1] = shapes[i].mesh.indices[n+1];
      triangle.vertices[2] = shapes[i].mesh.indices[n+2];
    }

    this->meshes.push_back(mesh);
  }


  std::cout << "# of shapes : " << shapes.size() << std::endl;
  std::cout << "# of materials : " << materials.size() << std::endl;

  std::cout << "# of shapes : " << this->meshes.size() << std::endl;
  if (this->meshes.size() > 0)
    std::cout << "# of faces : " << this->meshes[0]->faces.size() << std::endl;
}
