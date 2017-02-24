/*
 * Entity.h
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_ENTITIES_ENTITY_H_
#define LOGIC_ENTITIES_ENTITY_H_

#include "components/Component.h"
#include "../../utils/Vector3.h"

#include <list>

namespace kingdoms{
	class Message;
}

typedef kingdoms::Message Message;

class Entity {
public:
	Entity(const Vector3 & = Vector3::ZERO, const Vector3 & = Vector3::ZERO);

	virtual ~Entity();

	void update(const float millis);

	void addComponent(Component *);
	void removeComponent(Component *);

	const Vector3& getOrientation() const {
		return _orientation;
	}

	void setOrientation(const Vector3& orientation) {
		this->_orientation = orientation;
	}

	const Vector3& getPosition() const {
		return _position;
	}

	void setPosition(const Vector3& position) {
		this->_position = position;
	}

	void processMessage(Message *);

private:
	std::list<Component *> _components;
	Vector3 _position;
	Vector3 _orientation;
};

#endif /* LOGIC_ENTITIES_ENTITY_H_ */
