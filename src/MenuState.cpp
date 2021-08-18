#include "MenuState.h"
#include "MenuButton.h"

const std::string MenuState::menuID = "MENU";

std::string MenuState::getStateID() const
{ 
    return menuID; 
}
    
void MenuState::ProcessInput()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
    {
        (*it)->ProcessInput();
    }

}

void MenuState::Render()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
    {
        (*it)->Draw();
    }

}

bool MenuState::onEnter()
{
    if(!TextureManager::Instance()->Load("../Sprites/playbutton.png", "playbutton", 
                                        Game::Instance()->GetRenderer()))
        return false;
    if(!TextureManager::Instance()->Load("../Sprites/exitbutton.png", 
                                        "exitbutton", Game::Instance()->GetRenderer()))
        return false;

    LoaderParams params2 = LoaderParams(100, 100, 400, 100, "playbutton");
    LoaderParams params1 = LoaderParams(100, 300, 400, 100, "exitbutton");

    m_gameObjects.push_back(new MenuButton(&params2, s_menuToPlay, "PLAY"));
    m_gameObjects.push_back(new MenuButton(&params1, s_exitFromMenu, "EXIT"));
    return true;

}

void MenuState::Update(float deltatime)
{
    /*Some animation*/

}

void MenuState::s_menuToPlay(const MenuButton& button)
{
    Game::Instance()->getStateMachine()->setNextState(button.eventID);
}

void MenuState::s_exitFromMenu(const MenuButton& button)
{
    Game::Instance()->Quit();
}

MenuState::~MenuState()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end();)
    {
        delete *it;
        it = m_gameObjects.erase(it);
    }
}


bool MenuState::onExit()
{
    for(auto it = m_gameObjects.begin(); it != m_gameObjects.end();)
    {
        delete *it;
        it = m_gameObjects.erase(it);
    }
    /*TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");*/
    return true;
}
