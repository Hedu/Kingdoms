/*
 * InputManager.h
 *
 *  Created on: 19 feb. 2017
 *      Author: hedu
 */

#ifndef APP_INPUTMANAGER_H_
#define APP_INPUTMANAGER_H_

#include <OgreLogManager.h>
#include <OgreRenderWindow.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

namespace kingdoms {

class InputManager: public OIS::KeyListener, public OIS::MouseListener {
public:
	InputManager(Ogre::RenderWindow*);
	virtual ~InputManager();

	//OIS Input devices
	OIS::InputManager* _oisInputManager;
	OIS::Mouse* _mouse;
	OIS::Keyboard* _keyboard;

private:
	// OIS::KeyListener
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);
	// OIS::MouseListener
	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	virtual bool mousePressed(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);

};

} /* namespace kingdoms */

#endif /* APP_INPUTMANAGER_H_ */
