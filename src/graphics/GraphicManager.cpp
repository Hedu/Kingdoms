/*
 * GraphicManager.cpp
 *
 *  Created on: 14 feb. 2017
 *      Author: hedu
 */

#include "GraphicManager.h"

GraphicManager *GraphicManager::_graphicManager = NULL;

GraphicManager *GraphicManager::getInstance() {
	if (_graphicManager == NULL) {
		_graphicManager = new GraphicManager();
	}
	return _graphicManager;
}

Scene* GraphicManager::getActiveScene() {
	return _activeScene;
}

Scene* GraphicManager::setActiveScene(std::string name) {
	if (_scenes.find(name) != _scenes.end()) {
		Scene *scene = _scenes.at(name);
		_activeScene = scene;
		return scene;
	} else {
		return NULL;
	}
}

void GraphicManager::addScene(std::string name, Scene *scene) {
	removeScene(name);
	if (_scenes.empty()) {
		_activeScene = scene;
	}
	_scenes[name] = scene;
}

void GraphicManager::removeScene(std::string name) {
	if (_scenes.find(name) != _scenes.end()) {
		Scene *oldScene = _scenes.at(name);
		_scenes.erase(name);
		delete oldScene;
	}
}

GraphicManager::~GraphicManager() {
	if (!_scenes.empty()) {
		std::map<std::string, Scene*>::iterator it = _scenes.begin();
		while (it != _scenes.end()) {
			delete ((it++)->second);
		}
	}
}

GraphicManager::GraphicManager() {
	_activeScene = NULL;

}
