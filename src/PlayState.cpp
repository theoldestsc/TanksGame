#include "PlayState.h"

const std::string PlayState::playID = "PLAY";

std::string PlayState::getStateID() const
{ 
    return playID; 
}
    
void PlayState::Update()
{
    // nothing for now
}

void PlayState::Render()
{
    // nothing for now
}

bool PlayState::onEnter()
{
    std::cout << "entering PlayState\n";
    return true;
}

bool PlayState::onExit()
{
    std::cout << "exiting PlayState\n";
    return true;
}
