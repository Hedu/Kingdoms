/*
 * GraphicComponent.h
 *
 *  Created on: 24 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_ENTITIES_COMPONENTS_GRAPHICCOMPONENT_H_
#define LOGIC_ENTITIES_COMPONENTS_GRAPHICCOMPONENT_H_

#include "Component.h"
#include "../Entity.h"
#include "../../../graphics/GraphicManager.h"

#include <string>

class GraphicComponent: public Component {
public:
	GraphicComponent(Entity *,std::string, std::string);
	virtual ~GraphicComponent();
	virtual void init();
	virtual void update(const float millis);
	virtual void processMessage(const Message *);

private:
	std::string _alias;
	std::string _mesh;
};

#endif /* LOGIC_ENTITIES_COMPONENTS_GRAPHICCOMPONENT_H_ */
