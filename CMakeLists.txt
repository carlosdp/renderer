cmake_minimum_required (VERSION 2.6)
project (render) 

find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

set(ADDITIONAL_LIBS 
  -pthread
  -lrt
  -lXinerama
  -lXrandr
  -lXxf86vm
  -lXi
  )

add_executable(render scene.cpp tiny_obj_loader.cc main.cpp)
target_link_libraries(render ${GLFW_STATIC_LIBRARIES})
target_link_libraries(render ${OPENGL_LIBRARIES})
# target_link_libraries(Renderer ${ADDITIONAL_LIBS})
