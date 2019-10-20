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
		ofPixels videoInverted;
		ofTexture videoTexture;
		
		
		//void load(std::string gakuchomovie);
		vector<ofxHapPlayer*> premovies;
		ofxHapPlayer gakuchoMovie,gakuku,finger,dancing;
		ofxHapPlayer part[5];


		//camera

		int camWidth;
		int camHeight;

		ofVideoGrabber cam[3];


		void dumpOSC(ofxOscMessage m);

		float Alpha[4];
		float Alpha0, Alpha1, Alpha2, Alpha3, Alpha4;
		

		int partnumber_r = 0;
		int partnumber_l = 0;

		int camnumber_r = 0;
		int camnumber_l = 0;

		int alpha_r = 0;
		int alpha_l = 0;

	

};
