/*
 * Application.cpp
 *
 *  Created on: 19 feb. 2017
 *      Author: hedu
 */
#include "Application.h"

//-------------------------------------------------------------------------------------
Application::Application(void) :
		mRoot(0), mWindow(0), mResourcesCfg(Ogre::StringUtil::BLANK), mPluginsCfg(
				Ogre::StringUtil::BLANK), mTrayMgr(0), mDetailsPanel(0), mShutDown(
				false) {
}

//-------------------------------------------------------------------------------------
Application::~Application(void) {
	if (mTrayMgr)
		delete mTrayMgr;

	//Remove ourself as a Window listener
	Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
	windowClosed(mWindow);
	delete mRoot;
}

//-------------------------------------------------------------------------------------
bool Application::configure(void) {
	// Show the configuration dialog and initialise the system
	// You can skip this and use root.restoreConfig() to load configuration
	// settings if you were sure there are valid ones saved in ogre.cfg
	if (mRoot->restoreConfig() || mRoot->showConfigDialog()) {
		// If returned true, user clicked OK so initialise
		// Here we choose to let the system create a default rendering window by passing 'true'
		mWindow = mRoot->initialise(true, "Kingdoms");

		return true;
	} else {
		return false;
	}
}
//-------------------------------------------------------------------------------------
void Application::createFrameListener(void) {

	_inputManager = new kingdoms::InputManager(mWindow);
	//Set initial mouse clipping size
	windowResized(mWindow);

	//Register as a Window listener
	Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

	mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", mWindow,
			_inputManager->getMouse(), this);
	mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	mTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
	mTrayMgr->hideCursor();

	// create a params panel for displaying sample details
	Ogre::StringVector items;
	items.push_back("cam.pX");
	items.push_back("cam.pY");
	items.push_back("cam.pZ");
	items.push_back("");
	items.push_back("cam.oW");
	items.push_back("cam.oX");
	items.push_back("cam.oY");
	items.push_back("cam.oZ");
	items.push_back("");
	items.push_back("Filtering");
	items.push_back("Poly Mode");

	mDetailsPanel = mTrayMgr->createParamsPanel(OgreBites::TL_NONE,
			"DetailsPanel", 200, items);
	mDetailsPanel->setParamValue(9, "Bilinear");
	mDetailsPanel->setParamValue(10, "Solid");
	mDetailsPanel->hide();

	mRoot->addFrameListener(this);
}
//-------------------------------------------------------------------------------------
void Application::setupResources(void) {
	// Load resource paths from config file
	Ogre::ConfigFile cf;
	cf.load(mResourcesCfg);

	// Go through all sections & settings in the file
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

	Ogre::String secName, typeName, archName;
	while (seci.hasMoreElements()) {
		secName = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i) {
			typeName = i->first;
			archName = i->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
					archName, typeName, secName);
		}
	}
}
//-------------------------------------------------------------------------------------
void Application::createResourceListener(void) {

}
//-------------------------------------------------------------------------------------
void Application::loadResources(void) {
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
//-------------------------------------------------------------------------------------
void Application::go(void) {
#ifdef _DEBUG
	mResourcesCfg = "resources_d.cfg";
	mPluginsCfg = "plugins_d.cfg";
#else
	mResourcesCfg = "resources.cfg";
	mPluginsCfg = "plugins.cfg";
#endif

	if (!setup())
		return;

	mRoot->startRendering();

}
//-------------------------------------------------------------------------------------
bool Application::setup(void) {
	mRoot = new Ogre::Root(mPluginsCfg);

	setupResources();

	bool carryOn = configure();
	if (!carryOn)
		return false;

	// Set default mipmap level (NB some APIs ignore this)
	Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

	// Create any resource listeners (for loading screens)
	createResourceListener();
	// Load resources
	loadResources();

	createFrameListener();

	return true;
}
;
//-------------------------------------------------------------------------------------
bool Application::frameRenderingQueued(const Ogre::FrameEvent& evt) {
	if (mWindow->isClosed())
		return false;

	if (mShutDown)
		return false;

	//Need to capture/update each device
	_inputManager->getKeyboard()->capture();
	_inputManager->getMouse()->capture();

	mTrayMgr->frameRenderingQueued(evt);

	if (!mTrayMgr->isDialogVisible()) {
		GraphicManager::getInstance()->getActiveScene()->getCameraMan()->frameRenderingQueued(
				evt);   // if dialog isn't up, then update the camera
		if (mDetailsPanel->isVisible()) // if details panel is visible, then update its contents
		{
			Ogre::Camera* cam =
					GraphicManager::getInstance()->getActiveScene()->getCamera();
			mDetailsPanel->setParamValue(0,
					Ogre::StringConverter::toString(
							cam->getDerivedPosition().x));
			mDetailsPanel->setParamValue(1,
					Ogre::StringConverter::toString(
							cam->getDerivedPosition().y));
			mDetailsPanel->setParamValue(2,
					Ogre::StringConverter::toString(
							cam->getDerivedPosition().z));
			mDetailsPanel->setParamValue(4,
					Ogre::StringConverter::toString(
							cam->getDerivedOrientation().w));
			mDetailsPanel->setParamValue(5,
					Ogre::StringConverter::toString(
							cam->getDerivedOrientation().x));
			mDetailsPanel->setParamValue(6,
					Ogre::StringConverter::toString(
							cam->getDerivedOrientation().y));
			mDetailsPanel->setParamValue(7,
					Ogre::StringConverter::toString(
							cam->getDerivedOrientation().z));
		}
	}

	return true;
}

//Adjust mouse clipping area
void Application::windowResized(Ogre::RenderWindow* rw) {
	unsigned int width, height, depth;
	int left, top;
	rw->getMetrics(width, height, depth, left, top);

	const OIS::MouseState &ms = _inputManager->getMouse()->getMouseState();
	ms.width = width;
	ms.height = height;
}

//Unattach OIS before window shutdown (very important under Linux)
void Application::windowClosed(Ogre::RenderWindow* rw) {
	//Only close for window that created OIS (the main window in these demos)
	if (rw == mWindow) {
		delete _inputManager;
	}
}
