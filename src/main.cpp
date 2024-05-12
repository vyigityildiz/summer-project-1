#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Game loop variables
    bool quit = false;
    SDL_Event event;

    int x = 0;
    int y = 0;

    bool leftKeyPressed = false;
    bool rightKeyPressed = false;
    bool upKeyPressed = false;
    bool downKeyPresses = false;

    // Main game loop
    while (!quit) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                // Handle key presses
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        leftKeyPressed = true;
                        break;
                    case SDLK_RIGHT:
                        rightKeyPressed = true;
                        break;
                    case SDLK_UP:
                        upKeyPressed = true;
                        break;
                    case SDLK_DOWN:
                        downKeyPresses = true;
                        break;
                }
            }
            else if (event.type == SDL_KEYUP) {
                // Handle key releases
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        leftKeyPressed = false;
                        break;
                    case SDLK_RIGHT:
                        rightKeyPressed = false;
                        break;
                    case SDLK_UP:
                        upKeyPressed = false;
                        break;
                    case SDLK_DOWN:
                        downKeyPresses = false;
                        break;
                }
            }
        }

        // Update game state based on key presses
        if (leftKeyPressed) {
            --x;
        }
        if (rightKeyPressed) {
            ++x;
        }
        if (downKeyPresses) {
            ++y;
        }
        if (upKeyPressed) {
            --y;
        }

        // Game logic update
        std::vector<Character> instances;
        instances.push_back(Character());

        // Rendering
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_Rect rect = {100 + x, 100 + y, 30, 30};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        // Render game objects, background, etc.
        SDL_RenderPresent(renderer);

        std::cout << x << " " << y << std::endl;

        // Add a delay to control frame rate (optional)
        SDL_Delay(16); // Aim for ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}