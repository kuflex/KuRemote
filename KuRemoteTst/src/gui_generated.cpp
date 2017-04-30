#include "gui_generated.h"
//Auto-generated GUI file for ofxKuTextGui, 2017-04-29-14-13-30-021

Parameters params;
//--------------------------------------------------------------
Parameters::Parameters() {
	_remote_port_in_=12300;
	_scr_w_=400;
	_scr_h_=400;
	_scr_fps_=30;
	fps_=30;
	list=0;
	var_int=0;
	var_float=0;
}

//--------------------------------------------------------------
void Parameters::setup(ofxKuTextGui &gui, string fileName) {
	gui.addPage("Settings");
	gui.addInt("*remote_port_in",_remote_port_in_,12300,1,65535,1,50);
	gui.addInt("*scr_w",_scr_w_,400,1,10000,1,50);
	gui.addInt("*scr_h",_scr_h_,400,1,10000,1,50);
	gui.addInt("*scr_fps",_scr_fps_,30,0,100,1,10);
	gui.addInt("-fps",fps_,30,0,100,1,10);
	gui.addPage("Page1");
	gui.addStringList("list",list,0,3,"A","B","C");
	gui.addInt("var_int",var_int,0,0,100,1,10);
	gui.addFloat("var_float",var_float,0,-1,1,200,20);
	fileName_ = fileName;
	gui_ = &gui;
	gui.loadFromFile(fileName);
	remote_port_in = _remote_port_in_;
	scr_w = _scr_w_;
	scr_h = _scr_h_;
	scr_fps = _scr_fps_;
}

//--------------------------------------------------------------
void Parameters::save() {
	gui_->saveToFile(fileName_);
}

//--------------------------------------------------------------

