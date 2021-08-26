#include "PlayState.h"

const std::string PlayState::playID = "PLAY";

std::string PlayState::getStateID() const
{ 
    return playID; 
}
    
void PlayState::ProcessInput()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
    {
        (*it)->ProcessInput();
    }

}

void PlayState::Render()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
    {
        (*it)->Draw();
    }

}

void PlayState::Update(float deltaTime)
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
    {
        (*it)->Update(deltaTime);
    }
}

bool PlayState::onEnter()
{
    if(!TextureManager::Instance()->Load(std::string("../Sprites/tankScaled.png"),
                               std::string("Tank"),
                               VideoManager::Instance()->GetRenderer()))
        return false;
    if(!TextureManager::Instance()->Load(std::string("../Sprites/Bullet_Red.png"), 
                               std::string("Bullet"), 
                               VideoManager::Instance()->GetRenderer()))
        return false;
    /*TODO: Not a good approach, 
            size depends on 
            screen resolution/window size 
    */
    LoaderParams pParams(5, 100,
                         52, 64, 
                         std::string("Tank"));
    GameObject* tankObj = new Tank(&pParams);
    
    m_gameObjects.push_back(tankObj);
    return true;
}

bool PlayState::onExit()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end();)
    {
        delete *it;
        it = m_gameObjects.erase(it);
    }
    /*TODO: I Don't know, i guess would't be better 
            search every texture in game when it contains all textures(like now).
            Maybe clean correctly and load as needed?
            Now it cleans only in destroing app by SDL_DestroyRender()

            TextureManager::Instance()->clearFromTextureMap("Tank2");
    */
    return true;
}

PlayState::~PlayState()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end();)
    {
        delete *it;
        it = m_gameObjects.erase(it);
    }
}