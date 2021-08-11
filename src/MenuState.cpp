#include "MenuState.h"

const std::string MenuState::menuID = "MENU";

std::string MenuState::getStateID() const
{ 
    return menuID; 
}
    
void MenuState::Update()
{
    // nothing for now
}

void MenuState::Render()
{
    // nothing for now
}

bool MenuState::onEnter()
{
    std::cout << "entering MenuState\n";
    return true;
}

bool MenuState::onExit()
{
    std::cout << "exiting MenuState\n";
    return true;
}
