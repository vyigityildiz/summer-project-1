#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Player.h"
#include "Level.h"
#include "Texture.h"
#include "Text.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 720, 0);
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
    bool downKeyPressed = false;
    bool shiftKeyPressed = false;

    std::vector<Character> instances;
    instances.push_back(Character());

    Player player(100, 100);

    // Textures and Text
    SDL_Texture* font = loadTexture("textures/font.bmp", renderer);
    if (font == nullptr) {
        std::cerr << "Failed to load font texture!" << std::endl;
        return -1;
    }

    std::unordered_map<char, int> charIndMap;
    for (int i = 65; i < 91; ++i) {
        charIndMap[static_cast<char>(i)] = i - 65;
    }

    for (int i = 97; i < 123; ++i) {
        charIndMap[static_cast<char>(i)] = i - 71;
    }

    for (int i = 49; i < 58; ++i) {
        charIndMap[static_cast<char>(i)] = i + 3;
    }

    charIndMap['.'] = 61;
    charIndMap[','] = 62;
    charIndMap[':'] = 63;
    charIndMap['\''] = 64;
    charIndMap['0'] = 65;


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
                        downKeyPressed = true;
                        break;
                    case SDLK_LSHIFT:
                        shiftKeyPressed = true;
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
                        downKeyPressed = false;
                        break;
                    case SDLK_LSHIFT:
                        shiftKeyPressed = false;
                        break;
                }
            }
        }

        // Update game state based on key presses
        if (leftKeyPressed) {
            player.moveLeft();
        }
        if (rightKeyPressed) {
            player.moveRight();
        }
        if (downKeyPressed) {
            player.moveDown();
        }
        if (upKeyPressed) {
            player.moveUp();
        }
        if (shiftKeyPressed) {
            player.speedBoost();
            player.decreaseStamina();
        } else {
            player.normalSpeed();
            player.increaseStamina();
        }

        // Game logic update

        // collision check between the player and other instances
        for (auto ins : instances) {
            if (ins.doesCollide(player)) {
                std::cout << "collision" << std::endl;
            } else {
                std::cout << "no collision" << std::endl;
            }
        }

        // Rendering

        // background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // instances other than the player
        for (auto ch : instances) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, ch.getRect());
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, player.getRect());

        // Text rendering
        player.renderHealth(font, 32, 32, renderer, charIndMap);

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