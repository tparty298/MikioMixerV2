#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {

	//premovie

	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();

	part[0].load("movies/test.mov");
	part[1].load("movies/gakucho0001-0060_hap.mov");
	part[2].load("movies/fingers_hap.mov");
	//part[4].load("dancing_hap.mov");

	ofSetVerticalSync(true);


	for (int i = 0; i < 5; i++) {
		premovies.push_back(&part[i]);
	}

	/*premovies.push_back(&part[1]);//0
	premovies.push_back(&part[2]);//1
	premovies.push_back(&part[3]);//2
	premovies.push_back(&part[4]);//3*/


	ofxSubscribeOsc(PORT, "/premovie/seek", [&](const int partnumber, const float seek) {

		part[partnumber].setLoopState(OF_LOOP_NONE);
		part[partnumber].setPosition(seek / part[partnumber].getDuration() / 100);
		part[partnumber].play();

		cout << "pn" <<partnumber << endl;
		cout << "seek" << seek << endl;
		cout << part[partnumber].getDuration() << endl;
		cout << (seek / part[partnumber].getDuration())/ 100 << endl;

		});

	
	//camera
	
	camWidth = 1920;
	camHeight = 1080;

	vector<ofVideoDevice> devices = cam[0].listDevices();

	for (size_t i = 0; i < devices.size(); i++) {
		if (devices[i].bAvailable) {
			ofLogNotice() << devices[i].id << ":" << devices[i].deviceName;
		}
		else {
			ofLogNotice() << devices[i].id << ";" << devices[i].deviceName << " - unavailable ";
		}
	}
	
	for (int i = 0; i < 3; i++) {
		cam[i].setDeviceID(i);//–¼‘O‚É‚àiŽg‚Á‚Ä‚æ‚³‚°
		cam[i].setDesiredFrameRate(60);
		cam[i].initGrabber(camWidth, camHeight);
	}


	//‡¬

	ofxSubscribeOsc(PORT, "/left/premovie_source", partnumber_l);
	ofxSubscribeOsc(PORT, "/right/premovie_source", partnumber_r);

	ofxSubscribeOsc(PORT, "/left/cam_source", camnumber_l);
	ofxSubscribeOsc(PORT, "/right/cam_source", camnumber_r);

	for (int i = 0; i < 3; i++) {

		cam[i].setDeviceID(i);
		cam[i].setDesiredFrameRate(60);
		cam[i].initGrabber(camWidth, camHeight);

	}

	ofxSubscribeOsc(PORT, "/left/alpha", alpha_l);
	ofxSubscribeOsc(PORT, "/right/alpha", alpha_r);

}

//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));

	//vidGrabber.update();
	for (int i = 0; i < 3; i++) {
		cam[i].update();
	}

	

}

//--------------------------------------------------------------
void ofApp::draw() {

	//monitor

	//premovie

	for (int i = 0; i < 5; i++) {
		part[i].draw(400 * i, 0, 400, 300);
	}


	//camera

	for (int i = 0; i < 3; i++) {
		cam[i].draw(400 * i, 300, 400, 300);
	}



	//vidGrabber.draw(200, 302, 400, 300);//“§‰ß‚·‚é‚Æ‚«Žg‚Á‚½
	/*ofSetColor(255, 255, 255, Alpha0);
	part[1].draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha1);
	part[2].draw(200, 302, 400, 300);

	//ofEnableBlendMode(OF_BLENDMODE_ALPHA)
	ofSetColor(255, 255, 255, Alpha2);
	//cout << mouseX  << endl;

	ofSetColor(255, 255, 255, Alpha3);
	part[3].draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha4);
	//part[4].draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255);*/


	



}
//--------------------------------------------------------------
void ofApp::setupw2() {

}

//--------------------------------------------------------------
void ofApp::draww2(ofEventArgs& args) {

	//‡¬right
	part[partnumber_r].draw(0, 0, ofGetWidth(), ofGetHeight());
	
	ofSetColor(255, 255, 255, alpha_r);
	cam[camnumber_r].draw(0, 0, ofGetWidth(), ofGetHeight());
	ofDrawCircle(20, 20, 20);
	ofSetColor(255, 255, 255);
}
//--------------------------------------------------------------
void ofApp::setupw3(){

}

//--------------------------------------------------------------
void ofApp::draww3(ofEventArgs& args) {

	//‡¬left
	part[partnumber_l].draw(0, 0, ofGetWidth(), ofGetHeight());
	
	ofSetColor(255, 255, 255, alpha_l);
	cam[camnumber_l].draw(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255, 255, 255);
}

/*
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
*/
void ofApp::mouseMoved(int x, int y ){

}

/*//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}*/
