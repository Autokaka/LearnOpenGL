#include <SDL.h>
#include <glad/glad.h>
#include <iostream>

int main() {
  bool quit = false;
  SDL_Window* window;
  SDL_GLContext glContext;
  SDL_Event sdlEvent;

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL2: Failed to initialize!" << std::endl;
    return 0;
  }

  window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 600,
                            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cout << "SDL2: Failed to create window!" << std::endl;
    return 0;
  }

  glContext = SDL_GL_CreateContext(window);
  if (glContext == nullptr) {
    std::cout << "SDL2: Failed to create OpenGL context! Error: "
              << SDL_GetError() << std::endl;
    return 0;
  }

  if (!gladLoadGLLoader(static_cast<GLADloadproc>(SDL_GL_GetProcAddress))) {
    std::cout << "SDL2: Failed to load proc from GLAD" << std::endl;
    return 0;
  }

  while (!quit) {
    while (SDL_PollEvent(&sdlEvent) != 0) {
      if (sdlEvent.type == SDL_QUIT) {
        quit = true;
      }
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
  }

  SDL_DestroyWindow(window);
  window = nullptr;
  SDL_Quit();

  return 0;
}
