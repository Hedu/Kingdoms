/*
 * Entity.cpp
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#include "Entity.h"

Entity::Entity(const Vector3 &position, const Vector3 &orientation) :
		_position(position), _orientation(orientation) {
}

void Entity::init() {
	std::list<Component *>::iterator it = _components.begin();
	while (it != _components.end()) {
		(*it++)->init();
	}
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

void Entity::processMessage(Message *message) {
	std::list<Component *>::iterator it = _components.begin();
	while (it != _components.end()) {
		(*it++)->processMessage(message);
	}
}

Entity::~Entity() {
	if (!_components.empty()) {
		std::list<Component *>::iterator it = _components.begin();
		while (it != _components.end()) {
			delete (*it++);
		}
	}
}

