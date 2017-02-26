/*
 * Scene.h
 *
 *  Created on: 19 feb. 2017
 *      Author: hedu
 */

#ifndef GRAPHICS_SCENE_H_
#define GRAPHICS_SCENE_H_

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <OgreCamera.h>
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreViewport.h>

#include <SdkCameraMan.h>

class Scene {
public:
	Scene(Ogre::Root *, Ogre::RenderWindow*);
	virtual ~Scene();

	Ogre::Camera* getCamera() {
		return _camera;
	}

	Ogre::SceneManager* getSceneManager() {
		return _sceneMgr;
	}

	OgreBites::SdkCameraMan* getCameraMan() {
		return _cameraMan;
	}

private:

	std::map<std::string, Ogre::Entity*> _entities;
	Ogre::Camera* _camera;
	Ogre::SceneManager* _sceneMgr;
	OgreBites::SdkCameraMan* _cameraMan;     // basic camera controller
};

#endif /* GRAPHICS_SCENE_H_ */
