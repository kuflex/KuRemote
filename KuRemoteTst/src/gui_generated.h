#pragma once
//Auto-generated GUI file for ofxKuTextGui, 2017-04-29-14-13-30-009

#include "ofMain.h"
#include "ofxKuTextGui.h"

struct Parameters {
	int remote_port_in;
	int _remote_port_in_;
	int scr_w;
	int _scr_w_;
	int scr_h;
	int _scr_h_;
	int scr_fps;
	int _scr_fps_;
	int fps_;
	int list;
	int var_int;
	float var_float;
    Parameters();
    void setup(ofxKuTextGui &gui, string fileName);
    void save();
    string fileName_;
    ofxKuTextGui *gui_;
};

extern Parameters params;
#define PRM params.
