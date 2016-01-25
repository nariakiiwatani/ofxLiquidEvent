#pragma once

#include "ofEventUtils.h"
#include "ofxLiquidEvent.h"

namespace ofxLiquidEventUtils {
	inline ofxLiquidEvent<void>& getEvent(const std::string &key) {
		static std::map<std::string, ofxLiquidEvent<void>> event;
		return event[key];
	}
	template<class... ArgType>
	inline ofxLiquidEvent<ArgType...>& getEvent(const std::string &key) {
		static std::map<std::string, ofxLiquidEvent<ArgType...>> event;
		return event[key];
	}
	
	// ==========
	inline void addListener(const std::string &key, std::function<void()> func) {
		getEvent(key) += func;
	}
	template<class... ArgType>
	inline void addListener(const std::string &key, std::function<void(ArgType...)> func) {
		getEvent<ArgType&&...>(key) += func;
	}
	template<class... ArgType>
	void addListener(const std::string &key, std::function<void(ArgType&&...)> func) {
		getEvent<ArgType&&...>(key) += [func](ArgType&&... arg) { func(std::forward<ArgType>(arg)...); };
	}
	
	template<class Listener>
	inline void addListener(const std::string &key, Listener *listener, void(Listener::*func)(void)) {
		getEvent(key) += [listener,func]() { (listener->*func)(); };
	}
	template<class Listener, class... ArgType>
	inline void addListener(const std::string &key, Listener *listener, void(Listener::*func)(ArgType...)) {
		getEvent<ArgType&&...>(key) += [listener,func](ArgType&&... arg) { (listener->*func)(std::forward<ArgType>(arg)...); };
	}
	template<class Listener, class... ArgType>
	void addListener(const std::string &key, Listener *listener, void(Listener::*func)(ArgType&&...)) {
		getEvent<ArgType&&...>(key) += [listener,func](ArgType&&... arg) { (listener->*func)(std::forward<ArgType>(arg)...); };
	}

	// ==========
	inline void notify(const std::string &key) {
		getEvent(key).notifyListeners();
	}
	template<class... ArgType>
	void notify(const std::string &key, ArgType&&... arg) {
		getEvent<ArgType&&...>(key).notifyListeners(std::forward<ArgType>(arg)...);
	}
	template<class... ArgType>
	inline void notify(const std::string &key, ArgType*... arg) {
		getEvent<ArgType*&&...>(key).notifyListeners(std::forward<ArgType*>(arg)...);
	}
}

