/*
 Rendering the first window using GLFW
 */

#include <GLFW/glfw3.h>

#include <iostream>

#define WIDTH 1280
#define HEIGHT 720
#define TITLE "FirstWindow"

int main(void){
  
  // initialize glfw
  if(glfwInit()<0){
    std::cerr<<"ERROR: Failed to initialize glfw"<<std::endl;
    return -1;
  }
  else
    std::cout<<"INFO: Successfully initialized glfw"<<std::endl;

  // setting window hints
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

  // create a window object
  GLFWwindow *window = glfwCreateWindow(WIDTH,
                                        HEIGHT,
                                        TITLE,
                                        NULL,
                                        NULL);
  if(!window){
    std::cerr<<"ERROR: Failed to create a window"<<std::endl;
    glfwTerminate();
    return -1;
  }
  else
    std::cout<<"INFO: Successfully created a window"<<std::endl;

  // set the window context to current
  glfwMakeContextCurrent(window);

  // the main loop
  while(!glfwWindowShouldClose(window)){
    // game logic + Rendering
    
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  // cleanup
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
