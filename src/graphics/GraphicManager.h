/*
 * GraphicManager.h
 *
 *  Created on: 14 feb. 2017
 *      Author: hedu
 */

#ifndef GRAPHICS_GRAPHICMANAGER_H_
#define GRAPHICS_GRAPHICMANAGER_H_

#include "../utils/Vector3.h"

#include <iostream>
#include <map>
#include <string>

class Scene;

class GraphicManager {
public:
	static GraphicManager *getInstance();
	virtual ~GraphicManager();

	Scene* getActiveScene();
	Scene* setActiveScene(std::string);
	void addScene(std::string, Scene*);
	void removeScene(std::string);
	void addMesh(Vector3 position, std::string mesh);
	void removeMesh(std::string mesh);
private:
	GraphicManager();

	static GraphicManager *_graphicManager;
	std::map<std::string, Scene*> _scenes;
	Scene *_activeScene;
};

#endif /* GRAPHICS_GRAPHICMANAGER_H_ */
