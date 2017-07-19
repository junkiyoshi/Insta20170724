#include "particle.h"

Particle::Particle() : Particle(ofVec3f(0, 0, 0), 10) {

}

Particle::Particle(ofVec3f l, float r) {
	this->location = l;
	this->radius = r;
}

Particle::~Particle() {

}

void Particle::update() {

}

void Particle::draw(float color_value) {
	ofPushMatrix();
	ofTranslate(this->location);

	this->body_color = ofColor(color_value);
	ofSetColor(this->body_color);
	//ofNoFill();

	ofBeginShape();
	float x, y;
	for (int i = 0; i < 360; i += 60) {
		x = this->radius * cos(DEG_TO_RAD * (i + 90));
		y = this->radius * sin(DEG_TO_RAD * (i + 90));
		ofVertex(x, y, 0);
	}
	ofEndShape(true);

	ofPopMatrix();
}

void Particle::setRadius(float r){
	this->radius = r;
}