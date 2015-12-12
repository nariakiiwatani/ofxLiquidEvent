#pragma once

#include "ofEventUtils.h"
#include "ofxLiquidEvent.h"

namespace ofxLiquidEventUtils {
	ofxLiquidEvent<void>& getEvent(const string &key) {
		static map<string, ofxLiquidEvent<void>> event;
		return event[key];
	}
	template<class... ArgType>
	ofxLiquidEvent<ArgType...>& getEvent(const string &key) {
		static map<string, ofxLiquidEvent<ArgType...>> event;
		return event[key];
	}
	
	// ==========
	void addListener(const string &key, function<void()> func) {
		getEvent(key) += func;
	}
	template<class... ArgType>
	void addListener(const string &key, function<void(ArgType...)> func) {
		getEvent<ArgType...>(key) += func;
	}
	template<class... ArgType>
	void addListener(const string &key, function<void(ArgType&...)> func) {
		getEvent<ArgType...>(key) += func;
	}
	template<class... ArgType>
	void addListener(const string &key, function<void(ArgType&&...)> func) {
		getEvent<ArgType...>(key) += func;
	}
	
	template<class Listener>
	void addListener(const string &key, Listener *listener, void(Listener::*func)(void)) {
		getEvent(key) += [listener,func]() { (listener->*func)(); };
	}
	template<class Listener, class... ArgType>
	void addListener(const string &key, Listener *listener, void(Listener::*func)(ArgType...)) {
		getEvent<ArgType...>(key) += [listener,func](ArgType... arg) { (listener->*func)(arg...); };
	}
	template<class Listener, class... ArgType>
	void addListener(const string &key, Listener *listener, void(Listener::*func)(ArgType&...)) {
		getEvent<ArgType...>(key) += [listener,func](ArgType... arg) { (listener->*func)(arg...); };
	}
	template<class Listener, class... ArgType>
	void addListener(const string &key, Listener *listener, void(Listener::*func)(ArgType&&...)) {
		getEvent<ArgType...>(key) += [listener,func](ArgType... arg) { (listener->*func)(forward<ArgType>(arg)...); };
	}

	// ==========
	void notify(const string &key) {
		getEvent(key).notifyListeners();
	}
	template<class... ArgType>
	void notify(const string &key, ArgType&... arg) {
		getEvent<ArgType...>(key).notifyListeners(arg...);
	}
	template<class... ArgType>
	void notify(const string &key, ArgType&&... arg) {
		getEvent<ArgType...>(key).notifyListeners(arg...);
	}
	template<class... ArgType>
	void notify(const string &key, ArgType*... arg) {
		getEvent<ArgType*...>(key).notifyListeners(arg...);
	}
}

