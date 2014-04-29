#pragma once

#include "ofxSpacebrew.h"

#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void gotMessage(ofMessage msg);
    void dragEvent(ofDragInfo dragInfo);
    
    
    float a;
    float b;
    float c;
    float d;
    
    bool flip = false;
    bool add = false;
    
    void ofAppRunnner();
    
    ofVideoPlayer geode;
    
    // create your spacebrew object
    Spacebrew::Connection spacebrew;
    
    // listen to spacebrew Messages
    void onMessage( Spacebrew::Message & m );
    
    int A1Value;
    int A2Value;
    int balloonValue;
    
    int numPoints = 100000;    
    
    
};
