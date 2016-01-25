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
	ofxLiquidEventUtils::addListener("app", function<void(int&&)>([](int&&){cout << "int rvalue called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&&)>([](const int&&){cout << "const int rvalue called." << endl;}));
	
	cout << "--- rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", 0);
	cout << "--- lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", i);
	cout << "--- const lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ci);
	cout << "--- lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ir);
	cout << "--- const lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", cir);
	cout << "--- const rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", std::move(ci));
	
	cout << "===== multi value =====" << endl;
	ofxLiquidEventUtils::addListener("app", function<void(int,int)>([](int,int){cout << "int,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,const int)>([](int,const int){cout << "int,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,int&)>([](int,int&){cout << "int,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,const int&)>([](int,const int&){cout << "int,const int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,int&&)>([](int,int&&){cout << "int,int rvalue called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int,const int&&)>([](int,const int&&){cout << "int,const int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(const int,int)>([](const int,int){cout << "const int,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,const int)>([](const int,const int){cout << "const int,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,int&)>([](const int,int&){cout << "const int,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,const int&)>([](const int,const int&){cout << "const int,const int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,int&&)>([](const int,int&&){cout << "const int,int rvalue called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int,const int&&)>([](const int,const int&&){cout << "const int,const int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(int&,int)>([](int&,int){cout << "int reference,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,const int)>([](int&,const int){cout << "int reference,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,int&)>([](int&,int&){cout << "int reference,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,const int&)>([](int&,const int&){cout << "int reference,const int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,int&&)>([](int&,int&&){cout << "int reference,int rvalue called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&,const int&&)>([](int&,const int&&){cout << "int reference,const int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(const int&,int)>([](const int&,int){cout << "const int reference,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,const int)>([](const int&,const int){cout << "const int reference,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,int&)>([](const int&,int&){cout << "const int reference,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,const int&)>([](const int&,const int&){cout << "const int reference,const int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,int&&)>([](const int&,int&&){cout << "const int reference,int rvalue called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&,const int&&)>([](const int&,const int&&){cout << "const int reference,const int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(int&&,int)>([](int&&,int){cout << "int rvalue,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&&,const int)>([](int&&,const int){cout << "int rvalue,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&&,int&)>([](int&&,int&){cout << "int rvalue,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&&,const int&)>([](int&&,const int&){cout << "int rvalue,const int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&&,int&&)>([](int&&,int&&){cout << "int rvalue,int rvalue called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(int&&,const int&&)>([](int&&,const int&&){cout << "int rvalue,const int rvalue called." << endl;}));
	
	ofxLiquidEventUtils::addListener("app", function<void(const int&&,int)>([](const int&&,int){cout << "const int rvalue,int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&&,const int)>([](const int&&,const int){cout << "const int rvalue,const int called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&&,int&)>([](const int&&,int&){cout << "const int rvalue,int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&&,const int&)>([](const int&&,const int&){cout << "const int rvalue,const int reference called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&&,int&&)>([](const int&&,int&&){cout << "const int rvalue,int rvalue called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const int&&,const int&&)>([](const int&&,const int&&){cout << "const int rvalue,const int rvalue called." << endl;}));
		
	cout << "--- rvalue,rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, 0);
	cout << "--- rvalue,lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, i);
	cout << "--- rvalue,const lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, ci);
	cout << "--- rvalue,lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, ir);
	cout << "--- rvalue,const lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, cir);
	cout << "--- rvalue,const rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", 0, std::move(ci));
	
	cout << "--- lvalue,rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", i, 0);
	cout << "--- lvalue,lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", i, i);
	cout << "--- lvalue,const lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", i, ci);
	cout << "--- lvalue,lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", i, ir);
	cout << "--- lvalue,const lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", i, cir);
	cout << "--- lvalue,const rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", i, std::move(ci));
	
	cout << "--- const lvalue,rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, 0);
	cout << "--- const lvalue,lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, i);
	cout << "--- const lvalue,const lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, ci);
	cout << "--- const lvalue,lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, ir);
	cout << "--- const lvalue,const lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, cir);
	cout << "--- const lvalue,const rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ci, std::move(ci));
	
	cout << "--- lvalue reference,rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, 0);
	cout << "--- lvalue reference,lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, i);
	cout << "--- lvalue reference,const lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, ci);
	cout << "--- lvalue reference,lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, ir);
	cout << "--- lvalue reference,const lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, cir);
	cout << "--- lvalue reference,const rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", ir, std::move(ci));
	
	cout << "--- const lvalue reference,rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, 0);
	cout << "--- const lvalue reference,lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, i);
	cout << "--- const lvalue reference,const lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, ci);
	cout << "--- const lvalue reference,lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, ir);
	cout << "--- const lvalue reference,const lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, cir);
	cout << "--- const lvalue reference,const rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", cir, std::move(ci));
	
	cout << "--- const rvalue,rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), 0);
	cout << "--- const rvalue,lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), i);
	cout << "--- const rvalue,const lvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), ci);
	cout << "--- const rvalue,lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), ir);
	cout << "--- const rvalue,const lvalue reference ---" << endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), cir);
	cout << "--- const rvalue,const rvalue ---" << endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), std::move(ci));
	
	cout << "===== be careful! =====" << endl;
	ofxLiquidEventUtils::addListener("app", function<void(string)>([](string){cout << "string called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(const char*)>([](const char*){cout << "const char* called." << endl;}));
	ofxLiquidEventUtils::addListener("app", function<void(char*)>([](char*){cout << "char* called." << endl;}));
	
	ofxLiquidEventUtils::notify("app", "this is not string");
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
