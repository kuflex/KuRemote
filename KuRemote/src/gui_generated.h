#pragma once
//Auto-generated GUI file for ofxKuTextGui, 2017-04-30-10-39-46-378

#include "ofMain.h"
#include "ofxKuTextGui.h"

struct Parameters {
	int scr_w;
	int _scr_w_;
	int scr_h;
	int _scr_h_;
	int scr_fps;
	int _scr_fps_;
	int osc_in_port;
    Parameters();
    void setup(ofxKuTextGui &gui, string fileName);
    void save();
    string fileName_;
    ofxKuTextGui *gui_;
};

extern Parameters params;
#define PRM params.
