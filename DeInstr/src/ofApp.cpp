#include "ofApp.h"

#include "ofxKuTextGuiGen.h"
#include "gui_generated.h"

ofxKuTextGui gui;

int draw_gui = 0; //1;
float flash_ = -1000;	//flash time

string Title = "DeSampler 1.01";


//--------------------------------------------------------------
void ofApp::setup(){
	cout << "-----------------------------------------------------------------" << endl;
	cout << Title << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Keys: Esc - exit" << endl;
	cout << "Shift+1 - test generation" << endl;
/*	cout << " Return - hide / show GUI" << endl;
	cout << "Cursor,mouse click - choose parameter" << endl;
	cout << "[,], drag with LMB - change parameter slowly" << endl;
	cout << "{,}, drag with RMB - change parameter faster" << endl;
	cout << "F2, F3 - save/load params" << endl; */
	cout << "Shift+g - generate code using gui/gui-script.ini" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	ofSetWindowShape(1400, 800);

	//--------------------------------------
	//GUI
	PRM setup(gui, "param.ini");
	gui.set_dummy_color(255);

	//ofxKuPreset_load_vars_to_preset_system("gui/presetvars.ini", gui, presets);
	//presets.load("presets.ini");
	

	//--------------------------------------
	//Screen
	ofSetWindowTitle(Title);
	ofSetWindowShape(PRM scr_w, PRM scr_h);
	ofSetFrameRate(PRM FPS);

	//--------------------------------------
	app_.setup();

	//--------------------------------------
	

}

//--------------------------------------------------------------
void ofApp::load() {
	cout << "Load..." << endl;
	gui.loadFromFile("param.ini");
	flash();
}

//--------------------------------------------------------------
void ofApp::save() {
	cout << "Save..." << endl;
	gui.saveToFile("param.ini");
	flash();
}

//--------------------------------------------------------------
void ofApp::flash() {
	flash_ = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::exit() {
	app_.exit();
	// save();
}

//--------------------------------------------------------------
void ofApp::update(){

	//-----------------------
	//GUI
	// gui.update();
	//-----------------------
	app_.update();
	//-----------------------
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	float time = ofGetElapsedTimef();
	float W = ofGetWidth();
	float H = ofGetHeight();

	//-----------------------
	app_.draw();
	//-----------------------

	//GUI
	if (draw_gui) {
		gui.draw(20, 20);
	}
	float flash = ofMap(time, flash_, flash_ + 0.3, 0.3, 0, true);
	if (flash > 0) {
		ofSetColor(255, flash * 255);
		ofFill();
		ofDrawRectangle(0, 0, W, H);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// if (key == OF_KEY_RETURN) draw_gui = 1 - draw_gui;

	// if (key == OF_KEY_F2) save(); 
	// if (key == OF_KEY_F3) load();

	if (key == 'G') {   //Generate .H and .CPP files for parameters
		ofxKuTextGuiGen::generateCPP("gui/gui-script.ini",
			"../../src/", "gui_generated",
			"Parameters", "params", "PRM");
		flash();
		return;
	}
	// gui.keyPressed(key);

	app_.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	// gui.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	// gui.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	// gui.mouseReleased(x, y, button);
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
