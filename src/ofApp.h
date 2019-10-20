#pragma once

#include "ofMain.h"
#include "ofxHapPlayer.h"
#include "ofxOsc.h"
#include "ofxPubSubOsc.h"

#define PORT 8000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void setupw2();
		void draww2(ofEventArgs&args);

		void setupw3();
		void draww3(ofEventArgs&args);

		/*void keyPressed(int key);
		void keyReleased(int key);*/
		void mouseMoved(int x, int y );/*
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);*/
		
		//ofVideoPlayer gakuchoMovie;
		ofVideoGrabber vidGrabber;
		ofPixels videoInverted;
		ofTexture videoTexture;
		
		int camWidth;
		int camHeight;

		//void load(std::string gakuchomovie);
		ofxHapPlayer gakuchoMovie;
		ofxHapPlayer gakuku,finger,dancing;

		ofPoint remoteMouse;
		float in1,in2,Alpha0,Alpha1,Alpha2,Alpha3,Alpha4,yeahhh;

		void dumpOSC(ofxOscMessage m);

		

};
