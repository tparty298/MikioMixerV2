#include "ofApp.h"
//場合分けするよ！
//--------------------------------------------------------------
void ofApp::setup() {
	//ofSetWindowShape(ofGetWindowHeight(),ofGetWindowWidth());
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	gakuchoMovie.load("movies/test.mov");
	gakuku.load("movies/gakucho0001-0060_hap.mov");
	finger.load("movies/fingers_hap.mov");
	//dancing.load("dancing_hap.mov");

	camWidth = 1920;
	camHeight = 1080;

	vector<ofVideoDevice> devices = vidGrabber.listDevices();

	for (size_t i = 0; i < devices.size(); i++) {
	if (devices[i].bAvailable) {
		ofLogNotice() << devices[i].id << ":" << devices[i].deviceName;
	}
	else {
		ofLogNotice() << devices[i].id << ";" << devices[i].deviceName << " - unavailable ";
	}
}

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);

	//videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	//videoTexture.allocate(videoInverted);
	ofSetVerticalSync(true);

	//ofxSubscribeOsc(PORT, "/mouse/position", in1, in2);

	ofxSubscribeOsc(PORT, "/premovie/seek", [&](const int partnumber,const float seek) {
	
		if (partnumber == 1) {
		gakuchoMovie.setLoopState(OF_LOOP_NONE);
		gakuchoMovie.setPosition(seek/gakuchoMovie.getDuration()/100);
		cout << gakuchoMovie.getPosition() << endl;
		gakuchoMovie.play();

		//gakuchoMovie.setFrame((int)(seek * (gakuchoMovie.getTotalNumFrames() / gakuchoMovie.getDuration())));//framepersecond
		
		//gakuchoMovie.setFrame(100);
		
		cout << gakuchoMovie.getPosition() << endl;
		cout << "current" << gakuchoMovie.getCurrentFrame() << endl;
		cout << "frame" << (int)(seek * (gakuchoMovie.getTotalNumFrames() / gakuchoMovie.getDuration())) << endl;
		cout << gakuchoMovie.getTotalNumFrames() << endl;
		cout << seek << endl;
		cout << partnumber << endl;

		} else if (partnumber == 2) {
		gakuku.setLoopState(OF_LOOP_NONE);
		gakuku.setPosition(seek / gakuku.getDuration()/100);
		gakuku.play();
		
		} else if (partnumber == 3){
		finger.setLoopState(OF_LOOP_NONE);
		finger.setPosition(seek / finger.getDuration()/100);
		finger.play();
		cout << "rarara" << endl;
		
		} else if (partnumber == 4) {
		//dancing.setLoopState(OF_LOOP_NONE);
		//dancing.play();
		dancing.setPosition(seek / dancing.getDuration()/100);
		
		} else {
		/*gakuchoMovie.setPosition(0);
		gakuku.setPosition(0);
		finger.setPosition(0);
		dancing.setPosition(0);*/
		}
	});


}
//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));


	/*else {
		gakuchoMovie.setPosition(0);
		gakuku.setPosition(0);
		finger.setPosition(0);
		dancing.setPosition(0);
	}*/

	//gakuchoMovie.update();
	//cout << gakuchoMovie.isPlaying() << endl; 

	vidGrabber.update();

	/*if (vidGrabber.isFrameNew()) {
		ofPixels& pixels = vidGrabber.getPixels();
		for (size_t i = 0; i < pixels.size(); i++) {
			videoInverted[i] = 255 - pixels[i];
		}
		videoTexture.loadData(videoInverted);
	}*/
	//透明度の変更
	 //とりま条件分岐が必要なくなる
	ofxSubscribeOsc(PORT, "/alpha", [&](const float Alpha1,const float Alpha2,const float Alpha3,const float Alpha4) {

	}

	/*if (in2 == 0) {
		Alpha0 = in1;
	}
	if (in2 == 1) {
		Alpha1 = in1;
	}
	if (in2 == 2) {
		Alpha2 = in1;
	}
	if (in2 == 3) {
		Alpha3 = in1;
	}
	if (in2 == 4) {
		Alpha4 = in1;
	}
	/*f (in2 == 5) {
		yeahhh = 
	}*/


}

//--------------------------------------------------------------
void ofApp::draw() {
	gakuchoMovie.draw(0, 0, 400, 300);
	vidGrabber.draw(1608, 0, 400, 300);
	gakuku.draw(402, 0, 400, 300);
	finger.draw(804, 0, 400, 300);
	//dancing.draw(1206, 0, 400, 300);

	ofSetColor(255, 255, 255, Alpha0);
	gakuchoMovie.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha1);
	gakuku.draw(200, 302, 400, 300);

	//ofEnableBlendMode(OF_BLENDMODE_ALPHA)
	ofSetColor(255, 255, 255, Alpha2);
	//cout << mouseX  << endl;

	vidGrabber.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha3);
	finger.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha4);
	//dancing.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255);

	//videoTexture.draw(20 + camWidth, 20, camWidth, camHeight);
}
//--------------------------------------------------------------
void ofApp::setupw2() {

}

//--------------------------------------------------------------
void ofApp::draww2(ofEventArgs& args) {
	gakuchoMovie.draw(0, 0, 400, 300);

	vidGrabber.draw(402, 0, 400, 300);
	gakuku.draw(804, 0, 400, 300);
	finger.draw(1206, 0, 400, 300);
	//dancing.draw(1608, 0, 400, 300);

	ofSetColor(255, 255, 255, Alpha0);
	gakuchoMovie.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha1);
	gakuku.draw(200, 302, 400, 300);

	//ofEnableBlendMode(OF_BLENDMODE_ALPHA)
	ofSetColor(255, 255, 255, Alpha2);
	//cout << mouseX  << endl;

	vidGrabber.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha3);
	finger.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha4);
	//dancing.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255);

	//videoTexture.draw(20 + camWidth, 20, camWidth, camHeight);
}
//--------------------------------------------------------------
void ofApp::setupw3(){

}

//--------------------------------------------------------------
void ofApp::draww3(ofEventArgs&args) {
	gakuchoMovie.draw(0, 0, 400, 300);
	vidGrabber.draw(402, 0, 400, 300);
	gakuku.draw(804, 0, 400, 300);
	finger.draw(1206, 0, 400, 300);
	//dancing.draw(1608, 0, 400, 300);

	ofSetColor(255, 255, 255, Alpha0);
	gakuchoMovie.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha1);
	gakuku.draw(200, 302, 400, 300);

	//ofEnableBlendMode(OF_BLENDMODE_ALPHA)
	ofSetColor(255, 255, 255, Alpha2);
	//cout << mouseX  << endl;

	vidGrabber.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha3);
	finger.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255, Alpha4);
	//dancing.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255);

	//videoTexture.draw(20 + camWidth, 20, camWidth, camHeight);
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
