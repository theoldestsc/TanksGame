#include <SDL.h>
#include <memory>

class VideoManager final
{
    public:
        bool Initialize();
        SDL_Renderer* GetRenderer() const;
        void GetWindowSize(int& w, int& h);
        static std::unique_ptr<VideoManager>& Instance();
        ~VideoManager();
    private:
        SDL_Renderer* mRenderer;
        SDL_Window* mWindow;
        static std::unique_ptr<VideoManager> VideoManagerInstance;
        
        VideoManager();
        VideoManager(VideoManager &other) = delete;
        void operator=(const VideoManager&) = delete;

};