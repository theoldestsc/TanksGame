#include <SDL2/SDL_image.h>
#include "DataStructures.h"
#define WIDTH 512
#define HEIGHT 384



//TODO: Make global object - Game Object, Tank inherits some properties (Think about it)
class Tank
{
    public:
        Tank(SDL_Renderer *renderer, Vector2 start_pos, const char* image_path);
        ~Tank();
        void update(float deltaTime);
        void change_direction(Direction dir);
        SDL_Rect tank_rect; //TODO: only avalable for reading - const methods
        SDL_Texture* texture; //TODO: only avalable for reading - const methods
        double mTankAngle;  //TODO: only avalable for reading - const methods
    private:
        Direction mTankDir;
        
        
        
};