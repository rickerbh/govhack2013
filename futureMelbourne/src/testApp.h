#pragma once

#ifndef _TEST_APP
#define _TEST_APP

#define MACOSX

#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "ofxTimer.h"
#include "ofxJSONElement.h"

class testApp : public ofBaseApp{
public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
  void timerFired(ofEventArgs &e);
  
  float resonance;
  float cutOff;
  float numberOfInputs;
  
  int year;
  int age;
  
  ofxTimer timer;
  
  ofxAudioUnit compressor;
  ofxAudioUnit p1, p2, p3, p4, p5, p6;
  ofxAudioUnit lp1, lp2, lp3, lp4, lp5, lp6;
  
  ofxAudioUnitFilePlayer s1, s2, s3, s4, s5, s6;
  ofxAudioUnitMixer mixer;
  ofxAudioUnitOutput output;
  
  ofxAudioUnitTap tap1, tap2, tap3, tap4, tap5, tap6;
  ofPolyline wave1, wave2, wave3, wave4, wave5, wave6;
  
  ofxJSONElement jsonF, jsonM;
  
};

#endif