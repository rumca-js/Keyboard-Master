/*
 * GameScene.h
 *
 *  Created on: 4 mar 2018
 *      Author: hunter
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_


#include <vector>
#include <SDL2/SDL_mixer.h>

#include "../Letter.h"

#include "../SceneInterface.h"
#include "../MainConfiguration.h"



class GameScene : public SceneInterface {
	/*!
	 * \brief SDL Renderer pointer.
	 */
    SDL_Renderer *renderer = NULL;
    /*!
	 * \brief Configuration instance pointer.
	 */
    MainConfiguration * config;
    /*!
     * \brief Font for game.
     */
    TTF_Font* Sans = NULL;
    /*!
     * \brief The background texture.
     */
    SDL_Texture *wall = NULL;
    /*!
     * \brief The letter fall timer.
     */
    SDL_TimerID my_timer_id;
    /*!
     * The letters placeholder.
     */
    std::vector<Letter> letters;
    /*!
     * \brief defines how fast the letter counter is updated.
     */
    unsigned int timer_delay;
    /*!
     * \brief defines how the consecutive letter speed up.
     */
    unsigned int speed_factor;
    /*!
     * \brief Piano notes A-G.
     */
	Mix_Chunk* notes[7];
	/*!
	 * \brief Sound for the end of the game.
	 */
	Mix_Chunk* note_eog;
    /*!
     * \brief Resets to a default state.
     */
	void reset();
public:

	GameScene(SDL_Renderer *ren, SDL_Window * window);
	/**
	 * @brief Performs initialization
	 */
	void init();
	/**
	 * @brief Writes scene on the window
	 */
	int write();
	/**
	 * @brief Updates letter positions. Every timer event.
	 */
	bool move_letters();
	/**
	 * @brief Displays the letters on the renderer
	 */
	void display_letters();
	/**
	 * @brief Checks if letter should be destroyed.
	 */
	bool check_if_killed(char key);
	/**
	 * @brief Closes the scene, disposes elements.
	 */
	void close();

	virtual ~GameScene();
};

#endif /* GAMESCENE_H_ */
