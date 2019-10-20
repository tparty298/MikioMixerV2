#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024*2,768*2,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

	ofGLFWWindowSettings settings;
	settings.setSize(1600, 600);
	settings.setPosition(ofVec2f(300, 200));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	settings.setSize(1600, 600);
	settings.setPosition(ofVec2f(0, 200));
	settings.resizable = false;
	// uncomment next line to share main's OpenGL resources with gui
	settings.shareContextWith = mainWindow;	
	shared_ptr<ofAppBaseWindow> Window2 = ofCreateWindow(settings);
	Window2->setVerticalSync(false);

	settings.setSize(1600, 600);
	settings.setPosition(ofVec2f(600, 200));
	settings.resizable = false;
	// uncomment next line to share main's OpenGL resources with gui
	settings.shareContextWith = mainWindow;
	shared_ptr<ofAppBaseWindow> Window3 = ofCreateWindow(settings);
	Window3->setVerticalSync(false);


	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->setupw2();
	ofAddListener(Window2->events().draw, mainApp.get(), &ofApp::draww2);
	mainApp->setupw3();
	ofAddListener(Window3->events().draw, mainApp.get(), &ofApp::draww3);

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}
