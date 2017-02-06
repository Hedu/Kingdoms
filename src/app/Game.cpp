/*
 * Game.cpp
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#include "../logic/entities/Entity.h"
#include "../../test/logic/entities/components/TestComponent.h"
#include "../logic/GameManager.h"

#include <iostream>

int main() {
	GameManager *gm = GameManager::getInstance();
	Entity *e = new Entity();
	Component *cp = new TestComponent();

	e->addComponent(cp);
	gm->addEntity(e);

	gm->update(5);
	return 0;
}



