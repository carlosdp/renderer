#include <GLFW/glfw3.h>
#include <GL/glu.h>

class Window {
  public:
    bool initialize();
    void render();

  private:
    GLFWwindow* window;
};
