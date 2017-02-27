/*
 * Component.h
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_ENTITIES_COMPONENTS_COMPONENT_H_
#define LOGIC_ENTITIES_COMPONENTS_COMPONENT_H_

class Entity;

namespace kingdoms {
	class Message;
}

typedef kingdoms::Message Message;

class Component {
public:
	Component(Entity *);
	virtual ~Component();
	virtual void init() = 0;
	virtual void update(const float millis) = 0;
	virtual void processMessage(const Message *) = 0;
protected:
	Entity *_self;
};

#endif /* LOGIC_ENTITIES_COMPONENTS_COMPONENT_H_ */
