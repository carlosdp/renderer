#include <GLFW/glfw3.h>
#ifdef __APPLE__
  #include <OpenGL/glu.h>
#else
  #include <GL/glu.h>
#endif

#include "scene.h"

class Window {
  public:
    bool initialize();
    void render(Scene *scene);

  private:
    GLFWwindow* window;
};
