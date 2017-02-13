/*
 * Entity.cpp
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#include "Entity.h"

Entity::Entity() {
}

void Entity::update(const float millis) {
	std::list<Component *>::iterator it = _components.begin();
	while (it != _components.end()) {
		(*it++)->update(millis);
	}
}

void Entity::addComponent(Component *c) {
	_components.push_back(c);
}

void Entity::removeComponent(Component *c) {
	_components.remove(c);
}

Entity::~Entity() {
	if (!_components.empty()) {
		std::list<Component *>::iterator it = _components.begin();
		while (it++ != _components.end()) {
			delete (*it);
		}
	}
}

