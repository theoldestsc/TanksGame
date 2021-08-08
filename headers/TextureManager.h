#ifndef TextureManager_H
#define TextureManager_H

#include <string>
#include <map>
#include <SDL2/SDL_image.h>

class TextureManager
{
    public:
        bool Load(std::string imagePath, std::string id, SDL_Renderer* rendrer);
        void Draw(std::string id, 
                  int x, int y, 
                  int width, int height, 
                  SDL_Renderer* renderer, double angle = 0,
                  SDL_RendererFlip flip = SDL_FLIP_NONE);
        void DrawFrame(std::string id,
                       int x, int y,
                       int width, int height,
                       int currentRow, int currentFrame,
                       SDL_Renderer* rendrer,
                       SDL_RendererFlip flip = SDL_FLIP_NONE);
        ~TextureManager();
        static TextureManager* Instance();
        TextureManager(TextureManager &other) = delete;
        void operator=(const TextureManager&) = delete;
    private:
        std::map<std::string, SDL_Texture*> textureMap;
        static TextureManager* textureManagerInstance;
    protected:
        TextureManager(){};
};
#endif