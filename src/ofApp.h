#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofPolyline polyline;
		ofxPanel gui;
		ofxIntSlider size;
		ofxColorSlider color;
		ofxVec3Slider background;
		ofxButton clear_button;

		int count;

		ofFbo fbo;
		int width = 600;
		int  height = 600;



		//Pendulum
		float r1 = 200;
		float r2 = 200;
		float m1 = 20;
		float m2 = 20;

		float a1 = PI/4;
		float a2 = PI/8;

		//change of position over time
		float a1_velocity = 0;
		float a2_velocity = 0;
		
		
		float g = 1;
		
};
