#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams):
                            GameObject(pParams)
{
    x = pParams->getX();
    y = pParams->getY();
    width = pParams->getWidth();
    height = pParams->getHeight();
    textureID = pParams->getTextureID();
    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::Draw()
{
    TextureManager::Instance()->DrawFrame(textureID, x, y,
                                          width, height, 
                                          currentRow, currentFrame,
                                          Game::Instance()->GetRenderer());
}
