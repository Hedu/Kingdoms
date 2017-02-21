/*
 * Scene.cpp
 *
 *  Created on: 19 feb. 2017
 *      Author: hedu
 */

#include "Scene.h"

Scene::Scene(Ogre::Root *mRoot, Ogre::RenderWindow* mWindow) {
	_sceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

	_camera = _sceneMgr->createCamera("PlayerCam");

	// Position it at 500 in Z direction
	_camera->setPosition(Ogre::Vector3(0,0,80));
	// Look back along -Z
	_camera->lookAt(Ogre::Vector3(0,0,-300));
	_camera->setNearClipDistance(5);

	_cameraMan = new OgreBites::SdkCameraMan(_camera);   // create a default camera controller

	Ogre::Viewport* vp = mWindow->addViewport(_camera);
	vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

	// Alter the camera aspect ratio to match the viewport
	_camera->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}

Scene::~Scene() {
	if (_cameraMan) {
		delete _cameraMan;
	}
}
