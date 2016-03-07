#include <GLFW/glfw3.h>
#ifdef __APPLE__
  #include <OpenGL/glu.h>
#else
  #include <GL/glu.h>
#endif

class Window {
  public:
    bool initialize();
    void render();

  private:
    GLFWwindow* window;
};
