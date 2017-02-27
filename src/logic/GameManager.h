/*
 * GameManager.h
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_GAMEMANAGER_H_
#define LOGIC_GAMEMANAGER_H_

#include "entities/Entity.h"
#include "messages/Message.h"

#include <list>
#include <map>
#include <iostream>

typedef kingdoms::Message Message;

class GameManager {
public:
	static GameManager *getInstance();
	virtual ~GameManager();
	void init();
	void update(const float);
	void addEntity(Entity *);
	void removeEntity(Entity *);

	void sendMessage(Message *, Entity *);
	void broadcastMessage(Message *);

private:
	GameManager();
	void processMessages();
	void processMessage(Message *, Entity*);
	void processMessage(Message *);

	static GameManager *_gameManager;
	std::list<Entity *> _entities;
	std::map<Message *, Entity *> _messages;
};

#endif /* LOGIC_GAMEMANAGER_H_ */
