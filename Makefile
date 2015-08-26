all:
	clang++ `pkg-config --cflags glfw3` -o render tiny_obj_loader.cc obj_import.cpp main.cpp `pkg-config --static --libs glfw3`
