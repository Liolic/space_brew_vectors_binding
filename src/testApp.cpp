#include "testApp.h"

ofMesh mesh;

//--------------------------------------------------------------
void testApp::setup(){
        
    geode.loadMovie("geode2.mp4");
    geode.play();
    
    ofSetFrameRate(60);
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs capsense trial";
    string description = "It's amazing";
    
    spacebrew.addSubscribe("amebia_1_urchin", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("amebia_2", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("balloons", "range");// just typing "boolean" also works
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);

//something new here for git


}
//--------------------------------------------------------------
void testApp::update(){
    geode.update();
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 255, 255, 255);
    geode.draw(0, 0, ofGetWidth(), ofGetHeight());
    //ofSetColor(255, 255, 255, 255 );


    
    ofSetColor(255);

    
    //____initial attractor valuers/setup
    
    float a = 1.4;
    float b = 1.56;
    float c = 1.40 +sin(ofGetElapsedTimef());
    float d = -6.56;
    
    float x0, y0, x1, y1 = 0;
    x0 = y0 = x1 = y1 = 0;
    

    ///___options for key interaction with attractors-------
    
    
    
    if (A2Value > 100){
        
        a = 4.0+sin(ofGetElapsedTimef());
        b= 3.0;
        c= -1.2;
        d = -2.0;
        
    }
    
    //cout<<A2Value<<endl;
    
    if (A1Value > 140){
        
        a = 10;
        b= -10.0;
        c= -4.0 +sin(ofGetElapsedTimef());
        d = -10;
        
    }
    
    //cout<<A1Value<<endl;
    
    if(balloonValue > 20){
        
        ofSetColor(255, 0, 255);
        
        
    }
    
    cout<<balloonValue<<endl;
    
    if (balloonValue < 20){
        ofSetColor(255);
    }
    
    
	//----drawing the attractor------
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(150, 150, 200);
    
    for (int i=0; i<numPoints; i++) {
        x1 = sin(a * y0) - cos(b * x0);
        y1 = sin(c * x0) - cos(d * y0);
        
        ofFill(); 
        ofLine(x1, y1, x1+0.01, y1);

        
        x0 = x1;
        y0 = y1;
        
        
    }

}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    if ( m.name == "amebia_1_urchin" ){
        //int sliderXValue = m.valueRange();
        A1Value = ofToInt(m.value) / 1024.0 * 500;
        //cout << A1Value<< endl;
        
    }
    
    if ( m.name == "amebia_2" ){
        //int sliderXValue = m.valueRange();
        A2Value = ofToInt(m.value) / 1024.0 * 500;
        //cout << A2Value << endl;
        
    }
    
    if ( m.name == "balloons" ){
        //int sliderXValue = m.valueRange();
        balloonValue = ofToInt(m.value) / 1024.0 * 500;
        cout << balloonValue << endl;
        
    }
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key =='a'){
        
        flip = true;
        
    }
    
    else if(key == 'b'){
        
        add = true;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if (key =='a'){
        
        flip = false;
        
    }
    
    else if(key == 'b'){
        add = false;
    }
    
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
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
void testApp::dragEvent(ofDragInfo info){
 
}


