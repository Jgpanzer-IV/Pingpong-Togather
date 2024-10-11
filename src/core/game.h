#include <SDL2/SDL.h>

class Game{

    public:
        Game();
        ~Game();

    private:
        bool mIsRunning;
        bool mIsPaused;
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;
        Uint32 mTickCount;
        Uint8 mAwaitTime;

    public:
        bool initialize();
        void run();
        void stop();
        void setTimeFrame(Uint8 desiredFPS);
        int getFPS(float deltaTime);

    private:
        void processInput();
        void updateLogic();
        void renderOutput();
        void destroy();
        void clean();   
};