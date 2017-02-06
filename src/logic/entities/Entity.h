/*
 * Entity.h
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_ENTITIES_ENTITY_H_
#define LOGIC_ENTITIES_ENTITY_H_

#include "components/Component.h"

#include <list>

class Entity {
public:
	Entity();
	virtual ~Entity();

	void update(const long millis);
	void addComponent(Component *);
	void removeComponent(Component *);

private:
	std::list<Component *> _components;
};

#endif /* LOGIC_ENTITIES_ENTITY_H_ */
