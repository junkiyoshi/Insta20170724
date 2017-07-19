
#pragma once

#include "ofMain.h"

class Particle {
public:
	Particle();
	Particle(ofVec3f l, float r);
	~Particle();
	void update();
	void draw(float color_value);
	ofVec3f location;

	void setRadius(float r);
private:
	float radius;
	ofColor body_color;
};