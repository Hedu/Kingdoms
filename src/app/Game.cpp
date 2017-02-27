/*
 * Game.cpp
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#include "Application.h"
#include "../graphics/GraphicManager.h"
#include "../graphics/Scene.h"
#include "../logic/GameManager.h"
#include "../logic/entities/Entity.h"
#include "../logic/entities/components/GraphicComponent.h"
#include "../../test/logic/entities/components/TestComponent.h"

#include <ctime>
#include <iostream>

//fakeMain includes

#define MILLIS_PER_FRAME (float)1000/60

float getCurrentMillis() {
	return (float) std::clock() * 1000 / CLOCKS_PER_SEC;
}

void realMain() {
	float previousTime = getCurrentMillis();
	float diff = previousTime;

	Application app;
	app.init();

	GraphicManager *graphicManager = GraphicManager::getInstance();
	graphicManager->addScene("main", new Scene(app.getRoot(), app.getWindow()));

	GameManager *gm = GameManager::getInstance();
	Entity *e = new Entity();
	Component *cp = new TestComponent(e);
	Component *gcp = new GraphicComponent(e, "objeto1", "ninja.mesh");

	e->addComponent(cp);
	e->addComponent(gcp);
	gm->addEntity(e);

	gm->broadcastMessage(new Message(NULL));

	gm->init();
	app.go();
	while (true) {
		diff = getCurrentMillis() - previousTime;
		if (diff > MILLIS_PER_FRAME) {
			gm->update(diff);
			previousTime = getCurrentMillis();
		}
	}
}

void fakeMain() {
	std::cout << "Fake Main" << std::endl;
}

int main() {

	realMain();
	//fakeMain();
	return 0;
}
