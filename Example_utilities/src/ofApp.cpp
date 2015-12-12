#include "ofApp.h"
#include "ofxLiquidEventUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){

	int i = 0;
	const int ci = 0;
	int &ir = i;
	const int &cir = ci;

	cout << "===== single value =====" << endl;
	ofxLiquidEventUtils::addListener("app", function<void(int)>([](int){cout << "int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int)>([](const int){cout << "const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&)>([](int&){cout << "int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&)>([](const int&){cout << "const int reference called." << endl;}));
	
	cout << "--- value ---" << endl;
	ofxLiquidEventUtils::notify("app", 0);
	cout << "--- int ---" << endl;
	ofxLiquidEventUtils::notify("app", i);
	cout << "--- const int ---" << endl;
	ofxLiquidEventUtils::notify("app", ci);
	cout << "--- int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ir);
	cout << "--- const int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", cir);
	
	cout << "===== multi value =====" << endl;
	ofxLiquidEventUtils::addListener("app", function<void(int,int)>([](int,int){cout << "int,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,const int)>([](int,const int){cout << "int,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,int&)>([](int,int&){cout << "int,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,const int&)>([](int,const int&){cout << "int,const int reference called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(int,int&&)>([](int,int&&){cout << "int,int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(const int,int)>([](const int,int){cout << "const int,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,const int)>([](const int,const int){cout << "const int,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,int&)>([](const int,int&){cout << "const int,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,const int&)>([](const int,const int&){cout << "const int,const int reference called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(const int,int&&)>([](const int,int&&){cout << "const int,int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(int&,int)>([](int&,int){cout << "int reference,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,const int)>([](int&,const int){cout << "int reference,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,int&)>([](int&,int&){cout << "int reference,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,const int&)>([](int&,const int&){cout << "int reference,const int reference called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(int&,int&&)>([](int&,int&&){cout << "int reference,int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(const int&,int)>([](const int&,int){cout << "const int reference,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,const int)>([](const int&,const int){cout << "const int reference,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,int&)>([](const int&,int&){cout << "const int reference,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,const int&)>([](const int&,const int&){cout << "const int reference,const int reference called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(const int&,int&&)>([](const int&,int&&){cout << "const int reference,int rvalue called." << endl;}));
	
//	ofxLiquidEventUtils::addListener("app", function<void(int&&,int)>([](int&&,int){cout << "int rvalue,int called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(int&&,const int)>([](int&&,const int){cout << "int rvalue,const int called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(int&&,int&)>([](int&&,int&){cout << "int rvalue,int reference called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(int&&,const int&)>([](int&&,const int&){cout << "int rvalue,const int reference called." << endl;}));
//	ofxLiquidEventUtils::addListener("app", function<void(int&&,int&&)>([](int&&,int&&){cout << "int rvalue,int rvalue called." << endl;}));
		
	cout << "--- value,value ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, 0);
	cout << "--- value,int ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, i);
	cout << "--- value,const int ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, ci);
	cout << "--- value,int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, ir);
	cout << "--- value,const int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, cir);
	
	cout << "--- int,value ---" << endl;
	ofxLiquidEventUtils::notify("app", i, 0);
	cout << "--- int,int ---" << endl;
	ofxLiquidEventUtils::notify("app", i, i);
	cout << "--- int,const int ---" << endl;
	ofxLiquidEventUtils::notify("app", i, ci);
	cout << "--- int,int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", i, ir);
	cout << "--- int,const int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", i, cir);
	
	cout << "--- const int,value ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, 0);
	cout << "--- const int,int ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, i);
	cout << "--- const int,const int ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, ci);
	cout << "--- const int,int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, ir);
	cout << "--- const int,const int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, cir);
	
	cout << "--- int reference,value ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, 0);
	cout << "--- int reference,int ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, i);
	cout << "--- int reference,const int ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, ci);
	cout << "--- int reference,int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, ir);
	cout << "--- int reference,const int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, cir);
	
	cout << "--- const int reference,value ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, 0);
	cout << "--- const int reference,int ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, i);
	cout << "--- const int reference,const int ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, ci);
	cout << "--- const int reference,int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, ir);
	cout << "--- const int reference,const int reference ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, cir);
	
	cout << "===== be careful! =====" << endl;
	ofxLiquidEventUtils::addListener("app", function<void(string)>([](string){cout << "string called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const char*)>([](const char*){cout << "const char* called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(char*)>([](char*){cout << "char* called." << endl;}));
	ofxLiquidEventUtils::notify("app", "this is const char*");
	ofxLiquidEventUtils::notify("app", string("this is string"));

	ofxLiquidEventUtils::addListener("app", function<void(float)>([](float){cout << "float called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(double)>([](double){cout << "double called." << endl;}));
	ofxLiquidEventUtils::notify("app", 0);	// int 
	ofxLiquidEventUtils::notify("app", 0.);	// double
	ofxLiquidEventUtils::notify("app", 0.f);// float
	
	// you can also call existing functions with even less code like that!
	ofxLiquidEventUtils::addListener("mouseMoved", this, &ofApp::mouseMoved);
	ofxLiquidEventUtils::notify("mouseMoved", 100, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	cout << "mouse moved: " << x << "," << y << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
