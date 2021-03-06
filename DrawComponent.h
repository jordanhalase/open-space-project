#ifndef DRAWCOMPONENT_H
#define DRAWCOMPONENT_H

#include <string>

#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#elif __linux__
#include <SDL2/SDL_image.h>
#endif

class DrawComponent
{
public:
  DrawComponent(SDL_Renderer* renderer);
  ~DrawComponent();

  int load(std::string texName);
  void draw(int texID, int x, int y, int w, int h);


private:
  SDL_Renderer* renderer_;
  enum returnValues{TEX_NOT_FOUND, UNABLE_TO_ADD};
  int addTexture(SDL_Texture* texture);
  // number of textures held in Renderer
  const int size_ = 64;
  // array of stored textures
  SDL_Texture** textures_;
  // allow only one to be instantiated
  static bool inst_;

};

#endif
