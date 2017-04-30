#include "ofApp.h"

#include "ofxKuTextGui.h"
#include "ofxKuTextGuiGen.h"
#include "ofxKuTextGuiRemote.h"
#include "gui_generated.h"

ofxKuTextGui gui;
ofxKuTextGuiRemoteServer server;

//--------------------------------------------------------------
void ofApp::setup(){
	string title = "KuRemoteTst 1.01";
     ofSetWindowTitle( title );
	 cout << "--------------------------------" << endl;
	 cout << title << endl;
	 cout << "--------------------------------" << endl;
	 cout << "Keys: Esc, 1,2, cursor, [,],{,}" << endl;
    //ofSetEscapeQuitsApp( false );   

	//gui.draw_tabW = 180;
	PRM setup(gui,"param.ini"); 

	ofSetWindowShape(PRM scr_w, PRM scr_h);
	ofSetFrameRate( PRM scr_fps );   

	cout << "Starting receiving at port " << PRM remote_port_in << endl;
	server.setup(PRM remote_port_in, this, &gui);

}

//--------------------------------------------------------------
void ofApp::exit() {
	save();
}

//--------------------------------------------------------------
void ofApp::save() {
	PRM save();
}

//--------------------------------------------------------------
void ofApp::update(){
    server.update();
	PRM fps_ = ofGetFrameRate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(128);
    gui.draw(20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    gui.keyPressed(key);
	
	if (key == 'G') {   //Generate .H and .CPP files for parameters
        ofxKuTextGuiGen::generateCPP("gui/gui-script.ini",
                                     "../../src/", "gui_generated",
                                     "Parameters", "params", "PRM");
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
