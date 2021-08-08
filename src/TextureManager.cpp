#include "TextureManager.h"


TextureManager* TextureManager::textureManagerInstance = nullptr;

bool TextureManager::Load(std::string fileName, std::string
                          id, SDL_Renderer* renderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(pTempSurface == 0)
    {
        return false;
    }
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if(pTexture != 0)
    {
        textureMap[id] = pTexture;
        return true;
    }
    return false;
}

void TextureManager::Draw(std::string id, int x, int y, 
                          int width, int height, 
                          SDL_Renderer* renderer, double angle,
                          SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, 
                     &destRect, 
                     angle, 
                     NULL, 
                     flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int
                               width, int height, int currentRow, int currentFrame, SDL_Renderer
                               *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
    &destRect, 0, 0, flip);
}

TextureManager* TextureManager::Instance()
{
    if(!textureManagerInstance)
    {
        textureManagerInstance = new TextureManager();
        return textureManagerInstance;
    }
    return textureManagerInstance;
}
TextureManager::~TextureManager()
{
    delete textureManagerInstance;
}
