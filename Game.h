#include <SDL.h>

#include <vector>
#define WIDTH 512
#define HEIGHT 384
#include "Tank.h"

/*struct Bullet
{
    Vector2 mBallVel;
    Vector2 mBallPos;
};*/


class Game
{
    public:
        Game();
        bool initialize();
        void RunLoop();
        void ShutDown();
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();
        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;

        bool mIsRunning;
        Uint32 mTicksCount;
        Tank* tank_obj;
};