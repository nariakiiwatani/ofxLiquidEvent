ofxLiquidEvent
==============
forked from [elliotwoods](https://github.com/elliotwoods/ofxLiquidEvent)  

## What can I do with it?
you can add functions with various types of arguments
```C++
// ----- lambda functions with single argument -----
ofxLiquidEventUtils::addListener("app", function<void(int)>([](int){cout << "int called." << endl;}));
ofxLiquidEventUtils::addListener("app", function<void(const int)>([](const int){cout << "const int called." << endl;}));
ofxLiquidEventUtils::addListener("app", function<void(int&)>([](int&){cout << "int reference called." << endl;}));
ofxLiquidEventUtils::addListener("app", function<void(const int&)>([](const int&){cout << "const int reference called." << endl;}));

// ----- lambda functions with multi arguments -----
ofxLiquidEventUtils::addListener("app", function<void(int,int)>([](int,int){cout << "int,int called." << endl;}));
ofxLiquidEventUtils::addListener("app", function<void(int,const int)>([](int,const int){cout << "int,const int called." << endl;}));
ofxLiquidEventUtils::addListener("app", function<void(int,int&)>([](int,int&){cout << "int,int reference called." << endl;}));
ofxLiquidEventUtils::addListener("app", function<void(int,const int&)>([](int,const int&){cout << "int,const int reference called." << endl;}));

// ----- member functions -----
ofxLiquidEventUtils::addListener("app", this, &ofApp::mouseMoved);

// ----- static functions -----
/* 
// declared in somewhere...
void staticfunc1(){}
void staticfunc2(int i){}
void staticfunc3(int i, float y){}
*/
// functions with argument(s) need to cast by std::function<>
ofxLiquidEventUtils::addListener("app", staticfunc1);
ofxLiquidEventUtils::addListener("app", function<void(int)>(staticfunc2));
ofxLiquidEventUtils::addListener("app", function<void(int,float)>(staticfunc3));

```
then call
```C++
int i = 0;
ofxLiquidEventUtils::notify("app", i);
ofxLiquidEventUtils::notify("app", 0);
ofxLiquidEventUtils::notify("app", 0, 0);
ofxLiquidEventUtils::notify("app", 0, 0.f);
``` 

## What is the first string argument "app"?
Event address.  
Event functions are grouped by thier arguments type and this string.  
```C++
// these three functions are in dufferent groups.
ofxLiquidEventUtils::addListener("foo", function<void(int)>([](int){});
ofxLiquidEventUtils::addListener("bar", function<void(int)>([](int){});
ofxLiquidEventUtils::addListener("bar", function<void(int)>([](float){});

ofxLiquidEventUtils::notify("foo", 0);		// foo int
ofxLiquidEventUtils::notify("bar", 0);		// bar int
ofxLiquidEventUtils::notify("bar", 0.f);	// bar float
```

It works like OSC address.  
I think it is familiar with OSC messages. :)

## Is it tested well?
No. Be careful.

## How can I remove listener functions?
Currently there is no royal way.  
Just get the event object by rvalue syntax and use original ofxLiquidEvent fucntion `clear()`.
```C++
ofxLiquidEventUtils::getEvent<int>("app").clear(); // probably doesn't work
ofxLiquidEventUtils::getEvent<int&&>("app").clear();
```

## Why doesn't `notify` call my function?
Maybe the argument(s) you passed to `notify` are wrong.  
There are strict but weird rules for binding functions to event objects that you have to know.  
Run example_utilities and see console.
