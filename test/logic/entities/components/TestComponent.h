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
	TestComponent();
	virtual ~TestComponent();
	void update(const long millis);
};

#endif /* LOGIC_ENTITIES_COMPONENTS_TESTCOMPONENT_H_ */
