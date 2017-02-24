/*
 * GameManager.cpp
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#include "GameManager.h"

GameManager *GameManager::_gameManager = NULL;

GameManager *GameManager::getInstance(){
	if (_gameManager == NULL) {
		_gameManager = new GameManager();
	}
	return _gameManager;
}

void GameManager::update(const float millis ) {
	std::list<Entity *>::iterator it = _entities.begin();
	while (it != _entities.end()) {
		(*it++)->update(millis);
	}
	processMessages();
}

void GameManager::addEntity(Entity *e) {
	_entities.push_back(e);
}

void GameManager::removeEntity(Entity *e) {
	_entities.remove(e);
}

void GameManager::sendMessage(Message *message, Entity *entity) {
	_messages[message] = entity;
}

void GameManager::broadcastMessage(Message *message) {
	_messages[message] = NULL;
}

void GameManager::processMessages() {
	if (!_messages.empty()) {
		std::map<Message*, Entity*>::iterator it = _messages.begin();
		while (it != _messages.end()) {
			Message *message = it->first;
			Entity *receiver = (it++)->second;
			if (receiver == NULL) {
				processMessage(message);
			}
			else {
				processMessage(message, receiver);
			}
			_messages.erase(message);
			delete message;
			delete receiver;
		}
	}
}

void GameManager::processMessage(Message *message) {
	std::list<Entity *>::iterator it = _entities.begin();
	while (it != _entities.end()) {
		processMessage(message, *it++);
	}
}

void GameManager::processMessage(Message *message, Entity* entity) {
	entity->processMessage(message);
}

GameManager::~GameManager() {
	if (!_entities.empty()) {
		std::list<Entity *>::iterator it = _entities.begin();
		while (it != _entities.end()) {
			delete (*it++);
		}
	}
	if (_gameManager) {
		delete _gameManager;
	}
	if (!_messages.empty()) {
		std::map<Message*, Entity*>::iterator it = _messages.begin();
		while (it != _messages.end()) {
			delete ((it)->first);
			delete ((it++)->second);
		}
	}
}

GameManager::GameManager() {
}
