#include "ofApp.h"
#include "ofxLiquidEventUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){

	int i = 0;
	const int ci = 0;
	int &ir = i;
	const int &cir = ci;

	std::cout << "===== single value =====" << std::endl;
	ofxLiquidEventUtils::addListener("app", std::function<void(int)>([](int){std::cout << "int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int)>([](const int){std::cout << "const int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&)>([](int&){std::cout << "int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&)>([](const int&){std::cout << "const int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&&)>([](int&&){std::cout << "int rvalue called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&&)>([](const int&&){std::cout << "const int rvalue called." << std::endl;}));
	
	std::cout << "--- rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", 0);
	std::cout << "--- lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", i);
	std::cout << "--- const lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ci);
	std::cout << "--- lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ir);
	std::cout << "--- const lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", cir);
	std::cout << "--- const rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", std::move(ci));
	
	std::cout << "===== multi value =====" << std::endl;
	ofxLiquidEventUtils::addListener("app", std::function<void(int,int)>([](int,int){std::cout << "int,int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int,const int)>([](int,const int){std::cout << "int,const int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int,int&)>([](int,int&){std::cout << "int,int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int,const int&)>([](int,const int&){std::cout << "int,const int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int,int&&)>([](int,int&&){std::cout << "int,int rvalue called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int,const int&&)>([](int,const int&&){std::cout << "int,const int rvalue called." << std::endl;}));
	
	ofxLiquidEventUtils::addListener("app", std::function<void(const int,int)>([](const int,int){std::cout << "const int,int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int,const int)>([](const int,const int){std::cout << "const int,const int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int,int&)>([](const int,int&){std::cout << "const int,int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int,const int&)>([](const int,const int&){std::cout << "const int,const int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int,int&&)>([](const int,int&&){std::cout << "const int,int rvalue called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int,const int&&)>([](const int,const int&&){std::cout << "const int,const int rvalue called." << std::endl;}));
	
	ofxLiquidEventUtils::addListener("app", std::function<void(int&,int)>([](int&,int){std::cout << "int reference,int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&,const int)>([](int&,const int){std::cout << "int reference,const int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&,int&)>([](int&,int&){std::cout << "int reference,int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&,const int&)>([](int&,const int&){std::cout << "int reference,const int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&,int&&)>([](int&,int&&){std::cout << "int reference,int rvalue called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&,const int&&)>([](int&,const int&&){std::cout << "int reference,const int rvalue called." << std::endl;}));
	
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&,int)>([](const int&,int){std::cout << "const int reference,int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&,const int)>([](const int&,const int){std::cout << "const int reference,const int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&,int&)>([](const int&,int&){std::cout << "const int reference,int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&,const int&)>([](const int&,const int&){std::cout << "const int reference,const int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&,int&&)>([](const int&,int&&){std::cout << "const int reference,int rvalue called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&,const int&&)>([](const int&,const int&&){std::cout << "const int reference,const int rvalue called." << std::endl;}));
	
	ofxLiquidEventUtils::addListener("app", std::function<void(int&&,int)>([](int&&,int){std::cout << "int rvalue,int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&&,const int)>([](int&&,const int){std::cout << "int rvalue,const int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&&,int&)>([](int&&,int&){std::cout << "int rvalue,int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&&,const int&)>([](int&&,const int&){std::cout << "int rvalue,const int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&&,int&&)>([](int&&,int&&){std::cout << "int rvalue,int rvalue called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(int&&,const int&&)>([](int&&,const int&&){std::cout << "int rvalue,const int rvalue called." << std::endl;}));
	
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&&,int)>([](const int&&,int){std::cout << "const int rvalue,int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&&,const int)>([](const int&&,const int){std::cout << "const int rvalue,const int called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&&,int&)>([](const int&&,int&){std::cout << "const int rvalue,int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&&,const int&)>([](const int&&,const int&){std::cout << "const int rvalue,const int reference called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&&,int&&)>([](const int&&,int&&){std::cout << "const int rvalue,int rvalue called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const int&&,const int&&)>([](const int&&,const int&&){std::cout << "const int rvalue,const int rvalue called." << std::endl;}));
		
	std::cout << "--- rvalue,rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", 0, 0);
	std::cout << "--- rvalue,lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", 0, i);
	std::cout << "--- rvalue,const lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", 0, ci);
	std::cout << "--- rvalue,lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", 0, ir);
	std::cout << "--- rvalue,const lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", 0, cir);
	std::cout << "--- rvalue,const rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", 0, std::move(ci));
	
	std::cout << "--- lvalue,rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", i, 0);
	std::cout << "--- lvalue,lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", i, i);
	std::cout << "--- lvalue,const lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", i, ci);
	std::cout << "--- lvalue,lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", i, ir);
	std::cout << "--- lvalue,const lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", i, cir);
	std::cout << "--- lvalue,const rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", i, std::move(ci));
	
	std::cout << "--- const lvalue,rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ci, 0);
	std::cout << "--- const lvalue,lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ci, i);
	std::cout << "--- const lvalue,const lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ci, ci);
	std::cout << "--- const lvalue,lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ci, ir);
	std::cout << "--- const lvalue,const lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ci, cir);
	std::cout << "--- const lvalue,const rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ci, std::move(ci));
	
	std::cout << "--- lvalue reference,rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ir, 0);
	std::cout << "--- lvalue reference,lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ir, i);
	std::cout << "--- lvalue reference,const lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ir, ci);
	std::cout << "--- lvalue reference,lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ir, ir);
	std::cout << "--- lvalue reference,const lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ir, cir);
	std::cout << "--- lvalue reference,const rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", ir, std::move(ci));
	
	std::cout << "--- const lvalue reference,rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", cir, 0);
	std::cout << "--- const lvalue reference,lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", cir, i);
	std::cout << "--- const lvalue reference,const lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", cir, ci);
	std::cout << "--- const lvalue reference,lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", cir, ir);
	std::cout << "--- const lvalue reference,const lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", cir, cir);
	std::cout << "--- const lvalue reference,const rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", cir, std::move(ci));
	
	std::cout << "--- const rvalue,rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), 0);
	std::cout << "--- const rvalue,lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), i);
	std::cout << "--- const rvalue,const lvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), ci);
	std::cout << "--- const rvalue,lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), ir);
	std::cout << "--- const rvalue,const lvalue reference ---" << std::endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), cir);
	std::cout << "--- const rvalue,const rvalue ---" << std::endl;
	ofxLiquidEventUtils::notify("app", std::move(ci), std::move(ci));
	
	std::cout << "===== be careful! =====" << std::endl;
	ofxLiquidEventUtils::addListener("app", std::function<void(string)>([](string){std::cout << "string called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(const char*)>([](const char*){std::cout << "const char* called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(char*)>([](char*){std::cout << "char* called." << std::endl;}));
	
	ofxLiquidEventUtils::notify("app", "this is not string");
	ofxLiquidEventUtils::notify("app", string("this is string"));

	ofxLiquidEventUtils::addListener("app", std::function<void(float)>([](float){std::cout << "float called." << std::endl;}));
	ofxLiquidEventUtils::addListener("app", std::function<void(double)>([](double){std::cout << "double called." << std::endl;}));
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
	std::cout << "mouse moved: " << x << "," << y << std::endl;
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
