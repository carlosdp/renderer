#include <iostream>
#include <cstdlib>
#include "scene.h"
#include "window.h"

int main(int argc, char** argv) {
  Scene scene;

  if (argc > 1) {
    scene.LoadOBJ(argv[1]);
  }

  Window *window = new Window();

  bool success = window->initialize();
  if (!success)
    exit(EXIT_FAILURE);

  window->render();
}
