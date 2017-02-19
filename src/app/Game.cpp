/*
 * Game.cpp
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#include "../logic/entities/Entity.h"
#include "../../test/logic/entities/components/TestComponent.h"
#include "../logic/GameManager.h"

#include <ctime>
#include <iostream>

//fakeMain includes
#include <map>
#include <string>

#define MILLIS_PER_FRAME (float)1000/60

float getCurrentMillis() {
	return (float)std::clock()* 1000/CLOCKS_PER_SEC;
}

void realMain() {
	float previousTime = getCurrentMillis();
	float diff = previousTime;

	GameManager *gm = GameManager::getInstance();
	Entity *e = new Entity();
	Component *cp = new TestComponent();

	e->addComponent(cp);
	gm->addEntity(e);

	while (true) {
		diff = getCurrentMillis() - previousTime;
		if (diff > MILLIS_PER_FRAME) {
			gm->update(diff);
			previousTime = getCurrentMillis();
		}
	}
}

void fakeMain() {
	std::map<std::string, std::string*> mapa;
	std::string *str = new std::string("adios");
	//mapa["hola"] = "adios";
	mapa["hola"] = str;
	//mapa.insert("hola", "Radios");
	std::cout << *(mapa.at("hola")) << std::endl;
	std::cout << mapa["adios"] << std::endl;
}

int main() {

	//realMain();
	fakeMain();
	return 0;
}
