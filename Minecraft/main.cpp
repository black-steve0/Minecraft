#include "SSDLmain.h"

using namespace stv;
using namespace geo;
using namespace gme;

void startup() {
	createChunk();
	for (int i = 0; i < chunks.size(); i++)
		chunks[i].updateOrder(0, Vector3(15, 15, 15));
}

void gameloop() {
	loadChunk();
	for (int i = 0; i < chunks.size(); i++)
		chunks[i].updateOrder(NULL, Vector3(15, 0, 15));
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

	startup();

	while (running) {
		
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}

			switch (event.type) {
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym) {
				case SDLK_e: prespective.z -= 5; break;
				case SDLK_q: prespective.z += 5; break;
				case SDLK_w: prespective.y -= 5; break;
				case SDLK_s: prespective.y += 5; break;
				case SDLK_a: prespective.x -= 5; break;
				case SDLK_d: prespective.x += 5; break;

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