/*
 * Application.h
 *
 *  Created on: 19 feb. 2017
 *      Author: hedu
 */
#ifndef __Application_h_
#define __Application_h_

#include "InputManager.h"

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>

class Application : public Ogre::FrameListener, public Ogre::WindowEventListener, OgreBites::SdkTrayListener
{
public:
    Application(void);
    virtual ~Application(void);

    virtual void go(void);

protected:
    virtual bool setup();
    virtual bool configure(void);
    virtual void createCamera(void);
    virtual void createFrameListener(void);
    virtual void createScene(void);
    virtual void destroyScene(void);
    virtual void createViewports(void);
    virtual void setupResources(void);
    virtual void createResourceListener(void);
    virtual void loadResources(void);

    // Ogre::FrameListener
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

    // Ogre::WindowEventListener
    //Adjust mouse clipping area
    virtual void windowResized(Ogre::RenderWindow* rw);
    //Unattach OIS before window shutdown (very important under Linux)
    virtual void windowClosed(Ogre::RenderWindow* rw);

    Ogre::Camera* mCamera;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Root *mRoot;
    Ogre::RenderWindow* mWindow;
    Ogre::String mResourcesCfg;
    Ogre::String mPluginsCfg;

    // OgreBites
    OgreBites::SdkTrayManager* mTrayMgr;
    OgreBites::SdkCameraMan* mCameraMan;     // basic camera controller
    OgreBites::ParamsPanel* mDetailsPanel;   // sample details panel
    bool mCursorWasVisible;                  // was cursor visible before dialog appeared
    bool mShutDown;

    kingdoms::InputManager* _inputManager;

};

#endif // #ifndef __Application_h_
