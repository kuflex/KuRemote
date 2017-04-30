#include "gui_generated.h"
//Auto-generated GUI file for ofxKuTextGui, 2017-04-30-10-39-46-387

Parameters params;
//--------------------------------------------------------------
Parameters::Parameters() {
	_scr_w_=1024;
	_scr_h_=768;
	_scr_fps_=30;
	osc_in_port=12350;
}

//--------------------------------------------------------------
void Parameters::setup(ofxKuTextGui &gui, string fileName) {
	gui.addPage("Settings");
	gui.addInt("*scr_w",_scr_w_,1024,1,10000,1,50);
	gui.addInt("*scr_h",_scr_h_,768,1,10000,1,50);
	gui.addInt("*scr_fps",_scr_fps_,30,1,100,1,10);
	gui.addInt("osc_in_port",osc_in_port,12350,1,65535,1,50);
	fileName_ = fileName;
	gui_ = &gui;
	gui.loadFromFile(fileName);
	scr_w = _scr_w_;
	scr_h = _scr_h_;
	scr_fps = _scr_fps_;
}

//--------------------------------------------------------------
void Parameters::save() {
	gui_->saveToFile(fileName_);
}

//--------------------------------------------------------------

