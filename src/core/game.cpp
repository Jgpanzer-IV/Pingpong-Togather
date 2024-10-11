#include "game.h"

Game::Game(){
    mIsRunning = true;
    mIsPaused = false;   
    mWindow = nullptr;
    mRenderer = nullptr;
    mTickCount = SDL_GetTicks();
    setTimeFrame(50);
}

Game::~Game(){
    destroy();  
}

bool Game::initialize(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("SDL-Linux-Based-Project", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        800, 
        600, 
        SDL_WINDOW_SHOWN
    );
    if (mWindow == nullptr){
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(
        mWindow,
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (mRenderer == nullptr){
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::run(){
    while (mIsRunning){
        processInput();
        if (!mIsPaused){
            updateLogic();
            renderOutput();
        }
    }
}

void Game::processInput(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        mIsRunning = false;
                        break;
                    case SDLK_p:
                        mIsPaused = !mIsPaused;
                        break;
                    // Add more key handling here as needed
                }
                break;
            // Add more event types here as needed
        }
    }
}

void Game::updateLogic(){

    // Wait for the next frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTickCount + mAwaitTime));
    // Get the current tick count
    Uint32 currentTick = SDL_GetTicks();
    // Calculate the delta time
    float deltaTime = (currentTick - mTickCount) / 1000.0f;
    // Limit the delta time to 0.06 seconds
    if (deltaTime > 0.06f){
        deltaTime = 0.06f;
    }
    // Update the tick count
    mTickCount = currentTick;

    // Use deltaTime for time-based updates
    // For example: position += velocity * deltaTime;
 

}

void Game::renderOutput(){
    
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);

}


void Game::setTimeFrame(Uint8 desiredFPS){
    mAwaitTime = 1000 / desiredFPS;
}

void Game::stop(){
    mIsRunning = false;
    clean();
}

int Game::getFPS(float deltaTime){
    return 1.0f/deltaTime;
}

void Game::clean(){
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
}

void Game::destroy(){
    clean();    
    SDL_Quit();
}

