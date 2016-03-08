#include "window.h"

bool Window::initialize() {
  if (!glfwInit())
    return false;

  this->window = glfwCreateWindow(640, 480, "Carlos' Renderer", NULL, NULL);

  if (!window) {
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window);

  return true;
}

void Window::render(Scene *scene) {
  for (int i = 0; i < scene->meshes.size(); i++) {
    GLuint positionBuffer = GL_NONE;
    glGenBuffers(1, &positionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
  }

  while (!glfwWindowShouldClose(window))
  {
    float ratio;
    int width = 800, height = 600;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}
