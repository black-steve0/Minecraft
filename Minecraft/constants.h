#pragma once

#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <windows.h>
#include <random>
#include <chrono>

#define WHITE	stv::rgb(255,255,255)
#define RED		stv::rgb(255,0,0)
#define BLUE	stv::rgb(0,0,255)
#define GREEN	stv::rgb(0,255,0)
#define YELLOW  stv::rgb(255,255,0)
#define PURPLE  stv::rgb(255,0,255)

#define UC (unsigned char)
#define INT (int)
#define FLOAT (float)
#define DOUBLE (double)
#define BOOL (bool)
#define CHAR (char)
#define CCP const char*
#define VINT std::vector<int>

#define RAD / 57.2957795
#define second * 1000
#define default_texture SDL_Texture* texture = IMG_LoadTexture(ren, "FILE");
#define Arial "C:\\Users\\User\\source\\repos\\Minecraft\\Minecraft\\fonts\\arial.ttf"

#define AIR_ID			0
#define GRASS_ID		1
#define DIRT_ID			2
#define NOTHING_ID		15

#define AIR_TEX
#define GRASS_TEX
#define DIRT_TEX
#define NOTHING_TEX

static const int screen_width = 1920;
static const int screen_height = 1010;
static SDL_Window* win = SDL_CreateWindow("Minecraft", 0, 30, screen_width, screen_height, SDL_WINDOW_SHOWN);
static SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
