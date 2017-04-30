#include "ofApp.h"

#include "ofxKuTextGui.h"
#include "ofxKuTextGuiGen.h"
#include "ofxKuTextGuiRemote.h"

#include "gui_generated.h"



//--------------------------------------------------------------
void ofApp::setup(){
	string title = "KuRemote 02";
    ofSetWindowTitle( title );
	cout << "--------------------------------" << endl;
	cout << title << endl;
	cout << "--------------------------------" << endl;
	cout << "Keys: Esc, 1,2, cursor, [,],{,}, Backspace" << endl;
	//ofSetEscapeQuitsApp( false );   

	//comps 
 	n_ = 16;		//number of comps
	comp_.resize(n_);

	gui.set_tab_w(200,10);
	PRM setup(gui,""); 
	for (int i=0; i<n_; i++) {
		comp_[i].link_gui(i, gui);
	}
	gui.loadFromFile("param.ini");
	

	//screen
	ofSetWindowShape(PRM _scr_w_, PRM _scr_h_);
	ofSetFrameRate( PRM _scr_fps_ );   

	//comps again
	for (int i=0; i<n_; i++) {
		comp_[i].setup();
	}

	flash_ = 0;
	time_ = 0;
	mode_ = 0;
	id_ = -1;

	
}

//--------------------------------------------------------------
void ofApp::exit() {
	save();
	
}

//--------------------------------------------------------------
void ofApp::save() {
	gui.saveToFile("param.ini");
	flash();
}

//--------------------------------------------------------------
void ofApp::flash() {
	flash_ = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
	float time = ofGetElapsedTimef();
	float dt = ofClamp( time - time_, 0.01, 0.1 );
	time_ = time;
	if (flash_>0) flash_ -= dt/0.5;

	for (int i=0; i<n_; i++) {
		comp_[i].update(dt);
	}

	if (mode_ == MODE_COMP) {
		Comp &comp = comp_[id_];
		comp.update(dt);
		client_.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (mode_ == MODE_SETUP) {
		ofBackground(128);

	    gui.draw(20, 20);
		//client.draw(20, 150);

		if (flash_>0) {
			ofSetColor(255, 255*flash_);
			ofFill();
			ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
		}
	}
	if (mode_ == MODE_COMP) {
		ofBackground(64);
		Comp &comp = comp_[id_];
		ofDrawBitmapStringHighlight("COMP: " + ofToString(comp.id()+1,2,'0') + " " + comp.name(), 20, 20);
		client_.draw(20,50);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//Backspace - go to edit/back to comp list
	if (mode_ == MODE_SETUP) {
		if (key == OF_KEY_BACKSPACE) {
			int id = gui.pageIndex()-1;
			if (id>=0 && id<n_) {
				activate(id);
			}
			return;
		}

		if (gui.keyPressed(key)) return;

		if (key == 's') save();
	
		if (key == 'G') {   //Generate .H and .CPP files for parameters
		    ofxKuTextGuiGen::generateCPP("gui/gui-script.ini",
			                             "../../src/", "gui_generated",
				                         "Parameters", "params", "PRM");
			flash();
		}
		return;
	}
	if (mode_ ==  MODE_COMP) {
		if (key == OF_KEY_BACKSPACE) {
			deactivate();
			return;
		}
		client_.keyPressed(key);
		return;
	}
}

//--------------------------------------------------------------
void ofApp::activate(int id) {
	deactivate();
	mode_ = MODE_COMP;
	id_ = id;
	comp_[id_].activate(client_);
	client_.askGuiRequest();

}

//--------------------------------------------------------------
void ofApp::deactivate() {
	mode_ = MODE_SETUP;
	if (id_>=0) {
		comp_[id_].deactivate(client_);
		id_ = -1;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//client.keyReleased(key);
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
