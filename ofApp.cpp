#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	//ofNoFill();

	this->particle_size = 18;
	bool flg = true;
	for (float y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += this->particle_size + this->particle_size / 2) {
		for (float x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += this->particle_size * sqrt(3)) {

			if (flg) {
				this->particles.push_back(Particle(ofVec3f(x, y, 0), this->particle_size));
			}
			else {
				this->particles.push_back(Particle(ofVec3f(x + (this->particle_size * sqrt(3) / 2), y, 0), this->particle_size));
			}
		}
		flg = !flg;
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (Particle& p : this->particles) {
		p.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	float noise_step = 0.005;
	float noise_value;

	for (Particle& p : this->particles) {
		noise_value = ofNoise(p.location.x * noise_step, p.location.y * noise_step, p.location.z * noise_step, ofGetFrameNum() * noise_step * 2);
		p.setRadius(this->particle_size * noise_value * 1.1);
		p.draw(0);
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}