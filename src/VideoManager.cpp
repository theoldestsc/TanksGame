#include "VideoManager.h"


std::unique_ptr<VideoManager> VideoManager::VideoManagerInstance = nullptr;

VideoManager::VideoManager():mRenderer(nullptr),
                             mWindow(nullptr)
{
    
}

bool VideoManager::Initialize()
{
    SDL_DisplayMode dm;

    if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
    {
         SDL_Log("Failed to get desktop display mode: %s", SDL_GetError());
         return false;
    }

    mWindow = SDL_CreateWindow("TanksBattle", // Title
                                SDL_WINDOWPOS_UNDEFINED, // Top left x - coordinate of window
                                SDL_WINDOWPOS_UNDEFINED, // Top left y - coordinate of window
                                dm.w, // Width
                                dm.h, // Height
                                SDL_WINDOW_RESIZABLE // Flags //TODO:Made this optional
                                );
    if(!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;        
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!mRenderer)
    {
        SDL_Log("Failed to create render: %s", SDL_GetError());
        return false;        
    }    
    SDL_RenderSetLogicalSize(mRenderer, dm.w, dm.h);
    return true;
}

SDL_Renderer* VideoManager::GetRenderer() const 
{
    return mRenderer;
}

void VideoManager::GetWindowSize(int &w, int &h)
{
    return SDL_RenderGetLogicalSize(mRenderer, &w, &h); // AWFUl
}

std::unique_ptr<VideoManager>& VideoManager::Instance()
{
    if(!VideoManagerInstance)
    {
        VideoManagerInstance.reset(new VideoManager);
        return VideoManagerInstance;
    }
    return VideoManagerInstance;
}

VideoManager::~VideoManager()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);    
}