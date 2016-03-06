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

void Window::render() {
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
    /* glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f); */
    gluPerspective(50.0, 1.0, 3.0, 7.0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}
