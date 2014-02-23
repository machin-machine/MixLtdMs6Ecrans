#include "ofMain.h"
#include "testApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){

    ofAppGLFWWindow window;
    window.setMultiDisplayFullscreen(true);
    ofSetupOpenGL(&window,1024,768,OF_WINDOW);
	// can be OF_WINDOW or OF_FULLSCREEN
	ofRunApp(new testApp());
}


