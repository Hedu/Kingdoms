/*
 * GameManager.h
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_GAMEMANAGER_H_
#define LOGIC_GAMEMANAGER_H_

#include "entities/Entity.h"

#include <list>
#include <iostream>

class GameManager {
public:
	static GameManager *getInstance();
	virtual ~GameManager();
	void update(const float);
	void addEntity(Entity *);
	void removeEntity(Entity *);
private:
	GameManager();

	static GameManager *_gameManager;
	std::list<Entity *> _entities;
};


#endif /* LOGIC_GAMEMANAGER_H_ */
