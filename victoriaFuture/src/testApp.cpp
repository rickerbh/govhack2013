#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  
  json.open("Female.json");
  
  ofxJSONElement d2007 = json["2013"]["Ballarat"];
//  cout << d2007.getRawString(true);

  
	source1.setFile(ofFilePath::getAbsolutePath("81804__bennstir__violin-loop1.wav"));
	source2.setFile(ofFilePath::getAbsolutePath("153610__carlos-vaquero__violin-g-4-tenuto-vibrato.wav"));
	source3.setFile(ofFilePath::getAbsolutePath("23580__loofa__gong1.aif"));
	source4.setFile(ofFilePath::getAbsolutePath("174725__archeos__bell-sound-b.wav"));
	source5.setFile(ofFilePath::getAbsolutePath("85579__drriquet__electro-beat.wav"));
  
  distortion = ofxAudioUnit(kAudioUnitType_Effect,
                            kAudioUnitSubType_Distortion);
  filter = ofxAudioUnit(kAudioUnitType_Effect,
                        kAudioUnitSubType_LowPassFilter);
  timePitch = ofxAudioUnit(kAudioUnitType_Effect,
                           kAudioUnitSubType_TimePitch);
  
  source1.connectTo(filter).connectTo(tap1);
  source2.connectTo(timePitch).connectTo(distortion).connectTo(tap2);
  source3.connectTo(tap3);
  source4.connectTo(tap4);
  source5.connectTo(tap5);
  
	mixer.setInputBusCount(5);
	tap1.connectTo(mixer, 0);
  tap2.connectTo(mixer, 1);
  tap3.connectTo(mixer, 2);
  tap4.connectTo(mixer, 3);
  tap5.connectTo(mixer, 4);
  
	compressor = ofxAudioUnit(kAudioUnitType_Effect,
                            kAudioUnitSubType_DynamicsProcessor);
  
  mixer.connectTo(compressor).connectTo(output);
  
//  mixer.setInputVolume(1.0, 0);
//  mixer.setInputVolume(0.25, 1);
  
  output.start();
  
  source1.loop();
  source2.loop();
  source3.loop();
  source4.loop();
  source5.loop();
	
	ofSetVerticalSync(true);
  
  timer = ofxTimer();
  timer.setup(2000, true);
  
  resonance = 1.f;
  cutOff = 6900.f;
  ofAddListener(timer.TIMER_REACHED, this, &testApp::timerFired);
}

//--------------------------------------------------------------
void testApp::update(){
	tap1.getLeftWaveform(wave1, ofGetWidth(), ofGetHeight()/5);
	tap2.getLeftWaveform(wave2, ofGetWidth(), ofGetHeight()/5);
	tap3.getLeftWaveform(wave3, ofGetWidth(), ofGetHeight()/5);
	tap4.getLeftWaveform(wave4, ofGetWidth(), ofGetHeight()/5);
	tap5.getLeftWaveform(wave5, ofGetWidth(), ofGetHeight()/5);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	ofPushMatrix();
	{
		ofSetColor(0x65, 0xb4, 0xad);
		wave1.draw();
		ofSetColor(255);
//		ofDrawBitmapString("Press 'f' for filter UI", 20, 20);
    
    ofTranslate(0, ofGetHeight() / 5);
		ofSetColor(0x91, 0xc3, 0xae);
		wave2.draw();
		ofSetColor(255);
//		ofDrawBitmapString("Press 'd' for distortion UI", 20, 20);
//		ofDrawBitmapString("Press 't' for timepitch UI", 20, 40);

    ofTranslate(0, ofGetHeight() / 5);
		ofSetColor(0xdb, 0xd5, 0xa9);
		wave3.draw();
		ofSetColor(255);

    ofTranslate(0, ofGetHeight() / 5);
		ofSetColor(0xf1, 0xa5, 0xa2);
		wave4.draw();
		ofSetColor(255);

    ofTranslate(0, ofGetHeight() / 5);
		ofSetColor(0xea, 0x5b, 0xa6);
		wave5.draw();
		ofSetColor(255);

	
  
  }
	ofPopMatrix();
  
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == 'd') distortion.showUI();
	if(key == 'f') filter.showUI();
	if(key == 't') timePitch.showUI();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::timerFired(ofEventArgs &e) {
  return;
  if (resonance < 38.f) {
    resonance += 1.f;
  } else {
    resonance = 40.f;
  }
  printf("Setting resonance to %f\n", resonance);
  filter.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, resonance);
  
  if (cutOff > 10.f) {
    cutOff = cutOff * 0.8f;
  } else {
    cutOff = 10.f;
  }
  printf("Setting cutoff to %f\n", cutOff);
  filter.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, cutOff);

}
