#include "Comp.h"
#include "gui_generated.h"

//--------------------------------------------------------------
Comp::Comp() {
	active_ = false;
}

//--------------------------------------------------------------
void Comp::link_gui(int id, ofxKuTextGui &gui) {
	id_ = id;
	string name = ofToString(id+1,2,'0');
	string prefix = name + "_";
	gui.addPage("Comp_" + name);

	int n = 2;
	address_.resize(n);
	port_.resize(n);
	gui.addString(prefix + "name", name_, "Comp" + name);
	gui.addStringList(prefix + "use_addr", use_address_, 0, 2, "A", "B");
	gui.addString(prefix + "addrA", address_[0], "localhost");
	gui.addInt(prefix + "portA", port_[0], 12300, 1, 65535, 1, 50);
	gui.addString(prefix + "addrB", address_[1], "localhost");
	gui.addInt(prefix + "portB", port_[1], 12300, 1, 65535, 1, 50);
	
}

//--------------------------------------------------------------
void Comp::setup() {
	active_ = false;
}

//--------------------------------------------------------------
void Comp::update(float dt) {
	if (active_) {
		
	}
}

//--------------------------------------------------------------
void Comp::draw() {

}

//--------------------------------------------------------------
void Comp::keyPressed(int key) {

}

//--------------------------------------------------------------
void Comp::activate(ofxKuTextGuiRemoteClient &client) {
	active_ = true;
	string addr = address_[use_address_];
	int port = port_[use_address_];
	cout << "Start connection " << id_+1 << " " << name_ << " " << addr << " : " << port << endl;
	client.setup(addr, port, PRM osc_in_port);
}

//--------------------------------------------------------------
void Comp::deactivate(ofxKuTextGuiRemoteClient &client) {
	active_ = false;	

}

//--------------------------------------------------------------
