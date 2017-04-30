#pragma once

#include "ofMain.h"
#include "ofxKuTextGui.h"
#include "ofxKuTextGuiGen.h"
#include "ofxKuTextGuiRemote.h"
#include "Comp.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void save();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void flash();

	int n_;
	vector<Comp> comp_;

	ofxKuTextGui gui;


	float flash_;
	float time_;

	
	ofxKuTextGuiRemoteClient client_;
	int mode_;		//0 - choose comp, 1 - connection
	static const int MODE_SETUP = 0;
	static const int MODE_COMP = 1;
	
	int id_;		//current connection
	
	void activate(int id);
	void deactivate();
};
