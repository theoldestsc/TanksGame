#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams): 
                            position(pParams->getX(), 
                            pParams->getY())
                            //velocity(0, 0)
{
    width = pParams->getWidth();
    height = pParams->getHeight();
    textureID = pParams->getTextureID();
    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::Draw()
{
    TextureManager::Instance()->DrawFrame(textureID, (int)position.getX(), (int)position.getY(),
                                          width, height, 
                                          currentRow, currentFrame,
                                          Game::Instance()->GetRenderer());
}
