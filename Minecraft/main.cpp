#include "engine.h"

using namespace stv;
using namespace geo;
using namespace gme;

Vector3 rot(0,-25,0);

void gameloop() {
	rot.x++;
	cube(Vector3(0, 0, 0), Vector3(500, 500, 500), rgb(0, 0, 0), rot);
}

void renderloop() {
	/* default render objects, always a rectangle. Final object is going to be on top. */
	objects = {};
	texts = {};
	for (auto x : objects) x->draw();
	for (auto x : texts) Write(*x);

	/* solid background color */
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}

int main(int argc, char* argv[]) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) > 0 or TTF_Init() < 0) {
		abort();
	}

	bool running = true;

	SDL_Event event = SDL_Event();

	while (running) {
		
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}

			switch (event.type) {
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym) {
				case SDLK_e: rot.z += 15; break;
				case SDLK_q: rot.z -= 15; break;

				default: break;
				}
			}
			break;
			default:
				break;
			}
		}

		SDL_RenderClear(ren);
		gameloop();
		renderloop();
		SDL_RenderPresent(ren);

		Sleep(1 second/60); // number on the right is the max fps

	}
	
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();

	return 0;
}