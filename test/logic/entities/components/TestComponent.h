/*
 * TestComponent.h
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_ENTITIES_COMPONENTS_TESTCOMPONENT_H_
#define LOGIC_ENTITIES_COMPONENTS_TESTCOMPONENT_H_

#include "../../../../src/logic/entities/components/Component.h"

#include  <iostream>

class TestComponent: public Component {
public:
	TestComponent(Entity *);
	virtual ~TestComponent();
	void init();
	void update(const float millis);
	virtual void processMessage(const Message *) {
	}
};

#endif /* LOGIC_ENTITIES_COMPONENTS_TESTCOMPONENT_H_ */
