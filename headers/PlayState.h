#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"

class PlayState : public GameState
{
    public:
        virtual void Update() override;
        virtual void Render() override;
        virtual bool onEnter() override;
        virtual bool onExit() override;
        virtual std::string getStateID() const override;
    private:
        static const std::string playID;
};

#endif
