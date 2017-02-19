/*
 * InputManager.cpp
 *
 *  Created on: 19 feb. 2017
 *      Author: hedu
 */

#include "InputManager.h"

namespace kingdoms {

InputManager::InputManager(Ogre::RenderWindow* window) {

	Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
	OIS::ParamList pl;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;

	window->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

	_oisInputManager = OIS::InputManager::createInputSystem( pl );

	_keyboard = static_cast<OIS::Keyboard*>(_oisInputManager->createInputObject( OIS::OISKeyboard, true ));
	_mouse = static_cast<OIS::Mouse*>(_oisInputManager->createInputObject( OIS::OISMouse, true ));

	_mouse->setEventCallback(this);
	_keyboard->setEventCallback(this);

}

InputManager::~InputManager() {
	if(_oisInputManager ) {
		_oisInputManager->destroyInputObject(_mouse );
		_oisInputManager->destroyInputObject(_keyboard );

		OIS::InputManager::destroyInputSystem(_oisInputManager);
		_oisInputManager = 0;
	}
}


//-------------------------------------------------------------------------------------
bool InputManager::keyPressed( const OIS::KeyEvent &arg )
{
    /*if (mTrayMgr->isDialogVisible()) return true;   // don't process any more keys if dialog is up

    if (arg.key == OIS::KC_F)   // toggle visibility of advanced frame stats
    {
        mTrayMgr->toggleAdvancedFrameStats();
    }
    else if (arg.key == OIS::KC_G)   // toggle visibility of even rarer debugging details
    {
        if (mDetailsPanel->getTrayLocation() == OgreBites::TL_NONE)
        {
            mTrayMgr->moveWidgetToTray(mDetailsPanel, OgreBites::TL_TOPRIGHT, 0);
            mDetailsPanel->show();
        }
        else
        {
            mTrayMgr->removeWidgetFromTray(mDetailsPanel);
            mDetailsPanel->hide();
        }
    }
    else if (arg.key == OIS::KC_T)   // cycle polygon rendering mode
    {
        Ogre::String newVal;
        Ogre::TextureFilterOptions tfo;
        unsigned int aniso;

        switch (mDetailsPanel->getParamValue(9).asUTF8()[0])
        {
        case 'B':
            newVal = "Trilinear";
            tfo = Ogre::TFO_TRILINEAR;
            aniso = 1;
            break;
        case 'T':
            newVal = "Anisotropic";
            tfo = Ogre::TFO_ANISOTROPIC;
            aniso = 8;
            break;
        case 'A':
            newVal = "None";
            tfo = Ogre::TFO_NONE;
            aniso = 1;
            break;
        default:
            newVal = "Bilinear";
            tfo = Ogre::TFO_BILINEAR;
            aniso = 1;
        }

        Ogre::MaterialManager::getSingleton().setDefaultTextureFiltering(tfo);
        Ogre::MaterialManager::getSingleton().setDefaultAnisotropy(aniso);
        mDetailsPanel->setParamValue(9, newVal);
    }
    else if (arg.key == OIS::KC_R)   // cycle polygon rendering mode
    {
        Ogre::String newVal;
        Ogre::PolygonMode pm;

        switch (mCamera->getPolygonMode())
        {
        case Ogre::PM_SOLID:
            newVal = "Wireframe";
            pm = Ogre::PM_WIREFRAME;
            break;
        case Ogre::PM_WIREFRAME:
            newVal = "Points";
            pm = Ogre::PM_POINTS;
            break;
        default:
            newVal = "Solid";
            pm = Ogre::PM_SOLID;
        }

        mCamera->setPolygonMode(pm);
        mDetailsPanel->setParamValue(10, newVal);
    }
    else if(arg.key == OIS::KC_F5)   // refresh all textures
    {
        Ogre::TextureManager::getSingleton().reloadAll();
    }
    else if (arg.key == OIS::KC_SYSRQ)   // take a screenshot
    {
        mWindow->writeContentsToTimestampedFile("screenshot", ".jpg");
    }
    else if (arg.key == OIS::KC_ESCAPE)
    {
        mShutDown = true;
    }

    mCameraMan->injectKeyDown(arg);*/
    return true;
}

bool InputManager::keyReleased( const OIS::KeyEvent &arg )
{
    /*mCameraMan->injectKeyUp(arg);*/
    return true;
}

bool InputManager::mouseMoved( const OIS::MouseEvent &arg )
{
    /*if (mTrayMgr->injectMouseMove(arg)) return true;
    mCameraMan->injectMouseMove(arg);*/
    return true;
}

bool InputManager::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    /*if (mTrayMgr->injectMouseDown(arg, id)) return true;
    mCameraMan->injectMouseDown(arg, id);*/
    return true;
}

bool InputManager::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    /*if (mTrayMgr->injectMouseUp(arg, id)) return true;
    mCameraMan->injectMouseUp(arg, id);*/
    return true;
}

} /* namespace kingdoms */
