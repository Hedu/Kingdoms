/*
 * Component.h
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_ENTITIES_COMPONENTS_COMPONENT_H_
#define LOGIC_ENTITIES_COMPONENTS_COMPONENT_H_

class Component {
public:
	virtual ~Component();

	virtual void update(const float millis) = 0;
};

#endif /* LOGIC_ENTITIES_COMPONENTS_COMPONENT_H_ */
