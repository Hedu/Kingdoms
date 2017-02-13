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
}

void GameManager::addEntity(Entity *e) {
	_entities.push_back(e);
}

void GameManager::removeEntity(Entity *e) {
	_entities.remove(e);
}

GameManager::~GameManager() {
	if (!_entities.empty()) {
		std::list<Entity *>::iterator it = _entities.begin();
		while (it++ != _entities.end()) {
			delete (*it);
		}
	}
	if (_gameManager) {
		delete _gameManager;
	}
}

GameManager::GameManager() {
}
