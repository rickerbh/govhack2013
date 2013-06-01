#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  
  jsonF.open("Female.json");
  jsonM.open("Male.json");
  year = 2013;
  age = 0;
  
	s1.setFile(ofFilePath::getAbsolutePath("81804__bennstir__violin-loop1.wav"));
	s2.setFile(ofFilePath::getAbsolutePath("153610__carlos-vaquero__violin-g-4-tenuto-vibrato.wav"));
	s3.setFile(ofFilePath::getAbsolutePath("23580__loofa__gong1.aif"));
	s4.setFile(ofFilePath::getAbsolutePath("174725__archeos__bell-sound-b.wav"));
	s5.setFile(ofFilePath::getAbsolutePath("85579__drriquet__electro-beat.wav"));
  s6.setFile(ofFilePath::getAbsolutePath("154230__carlos-vaquero__transverse-flute-g-4-tenuto-non-vibrato.wav"));
  
  lp1 = ofxAudioUnit(kAudioUnitType_Effect,
                        kAudioUnitSubType_LowPassFilter);
  lp2 = ofxAudioUnit(kAudioUnitType_Effect,
                     kAudioUnitSubType_LowPassFilter);
  lp3 = ofxAudioUnit(kAudioUnitType_Effect,
                     kAudioUnitSubType_LowPassFilter);
  lp4 = ofxAudioUnit(kAudioUnitType_Effect,
                     kAudioUnitSubType_LowPassFilter);
  lp5 = ofxAudioUnit(kAudioUnitType_Effect,
                     kAudioUnitSubType_LowPassFilter);
  lp6 = ofxAudioUnit(kAudioUnitType_Effect,
                     kAudioUnitSubType_LowPassFilter);
  
  p1 = ofxAudioUnit(kAudioUnitType_Effect,
                           kAudioUnitSubType_TimePitch);  
  p2 = ofxAudioUnit(kAudioUnitType_Effect,
                    kAudioUnitSubType_TimePitch);
  p3 = ofxAudioUnit(kAudioUnitType_Effect,
                    kAudioUnitSubType_TimePitch);
  p4 = ofxAudioUnit(kAudioUnitType_Effect,
                    kAudioUnitSubType_TimePitch);
  p5 = ofxAudioUnit(kAudioUnitType_Effect,
                    kAudioUnitSubType_TimePitch);
  p6 = ofxAudioUnit(kAudioUnitType_Effect,
                    kAudioUnitSubType_TimePitch);
  
  s1.connectTo(lp1).connectTo(p1).connectTo(tap1);
  s2.connectTo(lp2).connectTo(p2).connectTo(tap2);
  s3.connectTo(lp3).connectTo(p3).connectTo(tap3);
  s4.connectTo(lp4).connectTo(p4).connectTo(tap4);
  s5.connectTo(lp5).connectTo(p5).connectTo(tap5);
  s6.connectTo(lp6).connectTo(p6).connectTo(tap6);
  
	mixer.setInputBusCount(6);
	tap1.connectTo(mixer, 0);
  tap2.connectTo(mixer, 1);
  tap3.connectTo(mixer, 2);
  tap4.connectTo(mixer, 3);
  tap5.connectTo(mixer, 4);
  tap6.connectTo(mixer, 5);
  
	compressor = ofxAudioUnit(kAudioUnitType_Effect,
                            kAudioUnitSubType_DynamicsProcessor);
  
  mixer.connectTo(compressor).connectTo(output);
  
//  mixer.setInputVolume(1.0, 0);
//  mixer.setInputVolume(0.25, 1);
  
  output.start();
  
  s1.loop();
  s2.loop();
  s3.loop();
  s4.loop();
  s5.loop();
  s6.loop();
	
	ofSetVerticalSync(true);
  
  timer = ofxTimer();
  timer.setup(1000, true);
  
  ofAddListener(timer.TIMER_REACHED, this, &testApp::timerFired);
}

//--------------------------------------------------------------
void testApp::update(){
	tap1.getLeftWaveform(wave1, ofGetWidth(), ofGetHeight() / 6);
	tap2.getLeftWaveform(wave2, ofGetWidth(), ofGetHeight() / 6);
	tap3.getLeftWaveform(wave3, ofGetWidth(), ofGetHeight() / 6);
	tap4.getLeftWaveform(wave4, ofGetWidth(), ofGetHeight() / 6);
	tap5.getLeftWaveform(wave5, ofGetWidth(), ofGetHeight() / 6);
	tap6.getLeftWaveform(wave6, ofGetWidth(), ofGetHeight() / 6);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	ofSetColor(255);
  ofSetLineWidth(2.0);
	ofPushMatrix();
	{
    //		ofDrawBitmapString("Press 'f' for filter UI", 20, 20);
		ofSetColor(0x65, 0xb4, 0xad);
		wave1.draw();
		ofSetColor(255);
    
    ofTranslate(0, ofGetHeight() / 6);
		ofSetColor(0x91, 0xc3, 0xae);
		wave2.draw();
		ofSetColor(255);

    ofTranslate(0, ofGetHeight() / 6);
		ofSetColor(0xdb, 0xd5, 0xa9);
		wave3.draw();
		ofSetColor(255);

    ofTranslate(0, ofGetHeight() / 6);
		ofSetColor(0xf1, 0xa5, 0xa2);
		wave4.draw();
		ofSetColor(255);

    ofTranslate(0, ofGetHeight() / 6);
		ofSetColor(0xea, 0x5b, 0xa6);
		wave5.draw();
		ofSetColor(255);

    ofTranslate(0, ofGetHeight() / 6);
		ofSetColor(0xb0, 0xd4, 0xb0);
		wave6.draw();
		ofSetColor(255);

  }
	ofPopMatrix();
  
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == '1') lp1.showUI();
	if(key == '\'') p1.showUI();
	if(key == '2') lp2.showUI();
	if(key == ',') p2.showUI();
	if(key == '3') lp3.showUI();
	if(key == '.') p3.showUI();
	if(key == '4') lp4.showUI();
	if(key == 'p') p4.showUI();
	if(key == '5') lp5.showUI();
	if(key == 'y') p5.showUI();
	if(key == '6') lp6.showUI();
	if(key == 'f') p6.showUI();
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
  if (age >= 85) {
    age = 0;
    year += 1;
  }
  
  cout << "Year: " << year << " Age: " << age << endl;
  
  float rm1 = jsonM[ofToString(year)]["Inner Melbourne"][ofToString(age)].asDouble();
  float rm2 = jsonM[ofToString(year)]["Metropolitan"][ofToString(age)].asDouble();
  float rm3 = jsonM[ofToString(year)]["Greater Metropolitan - North"][ofToString(age)].asDouble();
  float rm4 = jsonM[ofToString(year)]["Greater Metropolitan - South"][ofToString(age)].asDouble();
  float rm5 = jsonM[ofToString(year)]["Greater Metropolitan - East"][ofToString(age)].asDouble();
  float rm6 = jsonM[ofToString(year)]["Greater Metropolitan - West"][ofToString(age)].asDouble();

  float rf1 = jsonF[ofToString(year)]["Inner Melbourne"][ofToString(age)].asDouble();
  float rf2 = jsonF[ofToString(year)]["Metropolitan"][ofToString(age)].asDouble();
  float rf3 = jsonF[ofToString(year)]["Greater Metropolitan - North"][ofToString(age)].asDouble();
  float rf4 = jsonF[ofToString(year)]["Greater Metropolitan - South"][ofToString(age)].asDouble();
  float rf5 = jsonF[ofToString(year)]["Greater Metropolitan - East"][ofToString(age)].asDouble();
  float rf6 = jsonF[ofToString(year)]["Greater Metropolitan - West"][ofToString(age)].asDouble();

  age += 1;
  
  //  ofxJSONElement d2007 = json["2013"]["Ballarat"];
  //  cout << d2007.getRawString(true);

  float resonance_max = 40.f;
  float frequency_min = 192;
  float frequency_periods_max = 7; // max frequency is 21830, so that's 7 exponential growth periods from 192

  lp1.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, rm1 * resonance_max);
  lp2.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, rm2 * resonance_max);
  lp3.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, rm3 * resonance_max);
  lp4.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, rm4 * resonance_max);
  lp5.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, rm5 * resonance_max);
  lp6.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, rm6 * resonance_max);

  cout << "lp1 cutoff from " << rf1 << " - " << 192 * (pow(2, frequency_periods_max * rf1) - 1) << endl;

  lp1.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, frequency_min * (pow(2, frequency_periods_max * rf1) - 1));
  lp2.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, frequency_min * (pow(2, frequency_periods_max * rf2) - 1));
  lp3.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, frequency_min * (pow(2, frequency_periods_max * rf3) - 1));
  lp4.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, frequency_min * (pow(2, frequency_periods_max * rf4) - 1));
  lp5.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, frequency_min * (pow(2, frequency_periods_max * rf5) - 1));
  lp6.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, frequency_min * (pow(2, frequency_periods_max * rf6) - 1));

  
  
  return;

  if (resonance < 38.f) {
    resonance += 1.f;
  } else {
    resonance = 40.f;
  }
  printf("Setting resonance to %f\n", resonance);
//  filter.setParameter(kLowPassParam_Resonance, kAudioUnitScope_Global, resonance);
  
  if (cutOff > 10.f) {
    cutOff = cutOff * 0.8f;
  } else {
    cutOff = 10.f;
  }
  printf("Setting cutoff to %f\n", cutOff);
//filter.setParameter(kLowPassParam_CutoffFrequency, kAudioUnitScope_Global, cutOff);

}
