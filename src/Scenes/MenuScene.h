/*
 * InitScene.h
 *
 *  Created on: 11 mar 2018
 *      Author: hunter
 */

#ifndef MENUSCENE_H_
#define MENUSCENE_H_

#include <SDL2/SDL_ttf.h>

#include "../SceneInterface.h"
#include "../MainConfiguration.h"

#define TEXT_FULL_SCREEN "Press 'f' to toggle full screen"
#define TEXT_ENTER "Press 'Enter' for to start"
#define TEXT_ESCAPE "Press 'Escape' for to exit"

class MenuScene : public SceneInterface {
	/*!
	 * \brief SDL Renderer pointer.
	 */
	SDL_Renderer* renderer;
	/*!
	 * \brief SDL window pointer.
	 */
	SDL_Window* win;
	/*!
	 * \brief Configuration instance pointer.
	 */
	MainConfiguration * config;

	TTF_Font* Sans;
	SDL_Texture* wall;
	SDL_Texture* mFull;
	SDL_Texture* mEnter;
	SDL_Texture* mExit;
	bool fullscreen;

public:
	MenuScene(SDL_Renderer *ren, SDL_Window * window);

	void init();
	int write();
	void close();

	virtual ~MenuScene();
};

#endif /* MENUSCENE_H_ */
