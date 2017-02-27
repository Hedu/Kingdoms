/*
 * GraphicComponent.cpp
 *
 *  Created on: 24 feb. 2017
 *      Author: hedu
 */

#include "GraphicComponent.h"

GraphicComponent::GraphicComponent(Entity *e, std::string name, std::string meshName):
	Component(e), _alias(name), _mesh(meshName){
}

GraphicComponent::~GraphicComponent() {
	// TODO Auto-generated destructor stub
}

void GraphicComponent::init() {
	GraphicManager::getInstance()->addMesh(_alias, _self->getPosition(), _mesh);
}

void GraphicComponent::update(const float millis) {

}

void GraphicComponent::processMessage(const Message *) {

}
