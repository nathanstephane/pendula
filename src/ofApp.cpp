#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//ofEnableAntiAliasing();
	ofEnableSmoothing();
	gui.setup();
	gui.add(size.setup("size", 3, 1, 8));
	gui.add(color.setup("color", ofColor(255, 255, 255, 255), ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
	gui.add(background.setup("background",ofVec3f(0,0,0), ofVec3f(0,0,0),ofVec3f(255,255,255)));
	
	fbo.allocate(width, height);
	fbo.begin();
	ofClear(255);
	fbo.end();


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float en1 = -g * (2 * m1 + m2) * sinf(a1);
	float en2 = -m2*g*sinf(a1-2*a2);
	float en3 = -2 * sinf(a1 - a2) * m2;
	float en4 = (a2_velocity*a2_velocity*r2+a1_velocity*a1_velocity*r1*cosf(a1-a2));

	float dn = r1 * (2 * m1 + m2 - m2 * cosf(2 * a1 - 2 * a2));  //denominator

	//a1_velocity or theta1 change of velocity over time
	float a1_acceleration = (en1+en2+en3*en4) / dn;


	en1 = 2 * sinf(a1 - a2);
	en2 = (a1_velocity * a1_velocity * r1 * (m1 + m2) + g * (m1 + m2) * cosf(a1) + a2_velocity * a2_velocity * r2 * m2 * cos(a1 - a2));
	dn = r2 * (2 * m1 + m2 - m2 * cosf(2 * a1 - 2 * a2));  //denominator

	//
	float a2_acceleration = (en1*en2)/dn;

	//ofBackground(ofColor::black);
	fbo.draw(0, 0);
	
	ofPushMatrix();
	ofTranslate(300.0f,50.0f);

	float x1 = r1 * sinf(a1);
	float y1 = r1 * cosf(a1);

	float x2 = x1 + r2 * sinf(a2);
	float y2 = y1 + r2 * cosf(a2);



	ofDrawLine(0,0,x1,y1); //draws the line begining from (300, 50) because of the tranlst
	ofDrawCircle(x1,y1,m1);

	ofDrawLine(x1, y1, x2, y2);
	ofDrawCircle(x2, y2, m2);
	ofPopMatrix();

	fbo.begin();
		ofPushMatrix();
		ofTranslate(300.0f, 50.0f);
		ofSetLineWidth(2);
		ofSetColor(ofColor::white);
	
			polyline.addVertex(ofPoint(x2, y2));
			polyline.draw();

		ofPopMatrix();
	fbo.end();

	a1_velocity += a1_acceleration;
	a2_velocity += a2_acceleration;
	a1 += a1_velocity;
	a2 += a2_velocity;

	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
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

}
