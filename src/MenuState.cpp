#include "MenuState.h"

const std::string MenuState::menuID = "MENU";

std::string MenuState::getStateID() const
{ 
    return menuID; 
}
    
void MenuState::Update()
{
    float deltaTime = 0;
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->Update(deltaTime);
    }

}

void MenuState::Render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->Draw();
    }

}

bool MenuState::onEnter()
{
    if(!TextureManager::Instance()->Load("../Sprites/playbutton.png", "playbutton", 
                          Game::Instance()->GetRenderer()))
    {
        return false;
    }
    if(!TextureManager::Instance()->Load("../Sprites/exitbutton.png", 
                                            "exitbutton", Game::Instance()->GetRenderer()))
    {
        return false;
    }
    LoaderParams params2 = LoaderParams(100, 100, 400, 100, "playbutton");
    LoaderParams params1 = LoaderParams(100, 300, 400, 100, "exitbutton");

    m_gameObjects.push_back(new MenuButton(&params2));
    m_gameObjects.push_back(new MenuButton(&params1));
    return true;

}

bool MenuState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->Clean();
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");
    delete this; //TODO:Fix and test this later
    return true;
}
