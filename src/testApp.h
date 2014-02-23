#ifndef TESTAPP
#define TESTAPP

#include "ofMain.h"
//#include "ofxTimeline.h"
//#include "ofxTLAudioTrack.h"
#include "ofxUI.h"
#include "ofxMidi.h"

#include "ofxGLWarper.h"
#include "ofxOpenCv.h"

#define MAX_N_PTS         1500
#include "ofxOsc.h"
#define RPORT 12347 //incoming
#define SPORT 12348 //outgoing
#define NUM_MSG_STRINGS 100
//#define HOST "192.168.1.255"
#define HOST "localhost"

class testApp : public ofBaseApp, public ofxMidiListener
{
public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void newMidiMessage(ofxMidiMessage& eventArgs);





//----------------------------------

//	bool hideGUI;
//
//	float red, green, blue;
//	bool bdrawGrid;
//	bool bdrawPadding;
//
//
//    ofxUIMovingGraph *mg;
//    float *buffer;
//    ofImage *img;
    //---------------

    stringstream text;

    ofxMidiIn midiIn;
    ofxMidiIn   midiIn2;
    ofxMidiOut midiOut;
    ofxMidiMessage midiMessage;

    float    vol2,vol3, vol4,vol5,vol6, background_C  ;
    float   vit1;
    int vol1, volume_1;

    //AUDIO--------------
    void audioRequested(float *buf, int size, int ch);
    void audioReceived(float *buf, int size, int ch);

    //SETUP-------
    ofVideoPlayer PlayerA1,PlayerB1,PlayerC1,PlayerD1,PlayerE1,PlayerF1,PlayerG1,PlayerH1;
    float TotalNumFramesA1,TotalNumFramesB1,TotalNumFramesC1,TotalNumFramesD1,TotalNumFramesE1,TotalNumFramesF1,TotalNumFramesG1,TotalNumFramesH1;

    //AUDIO-------
    ofSoundStream       soundStream;
    float *audioInput;
    int sampleRate, bufferSize;
    float rms;
    vector<float> rms_values;

//        //OSC-------
    ofxOscReceiver receiver;
    ofxOscSender    sender;
    string getOscMsgAsString(ofxOscMessage m);

    int current_msg_string;
    string msg_strings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];

    string movieAdress;


    //DRAW---------
    ofBlendMode blendMode;


    //GUI---------
    void setGUI1();
    void setGUI2();
    void setGUI3();
    void setGUI4();

    ofxUICanvas *gui1;
    ofxUICanvas *gui2;
	ofxUIScrollableCanvas *gui3;
    ofxUICanvas *gui4;
    void guiEvent(ofxUIEventArgs &e);

    float Gain_A1,Gain_B1,Gain_C1,Gain_G1,Y_G1,Mix_G1,Fade_G;
    float Cont_A1,Lum_A1,Satu_A1;
    float Cont_B1,Lum_B1,Satu_B1;
    float Cont_C1,Lum_C1,Satu_C1;
    float Cont_D1,Lum_D1,Satu_D1;
    float Cont_E1,Lum_E1,Satu_E1;
    float Cont_F1,Lum_F1,Satu_F1;
    float Cont_G1,Lum_G1,Satu_G1;



    float R_Lect3,R_Lect1,Lum_x6,LumX6,Lum_1, R_L1,R_L2,R_L3,R_L4,R_L5,R_L6,R_F1,R_F2;
    float R_Open1 ,R_Open2 ,R_Open3 ,R_Open4 ,R_Open5 ,R_Open6, R_Open7, R_Open8;



    float backgroundColor;

    //TEXT--------
    ofTexture   textPlayerA1;
    ofTexture   textPlayerA2;
    ofTexture   textPlayerA3;
    ofxGLWarper warperPlayerA1;


    ofTexture   textPlayerB1;
    ofTexture   textPlayerB2;
    ofTexture   textPlayerB3;
    ofxGLWarper warperPlayerB1;

    ofTexture   textPlayerC1;
    ofTexture   textPlayerC2;
    ofTexture   textPlayerC3;
    ofxGLWarper warperPlayerC1;

    ofTexture   textPlayerD1;
    ofTexture   textPlayerD2;
    ofTexture   textPlayerD3;
    ofxGLWarper warperPlayerD1;

    ofTexture   textPlayerE1;
    ofTexture   textPlayerE2;
    ofTexture   textPlayerE3;
    ofxGLWarper warperPlayerE1;

    ofTexture   textPlayerF1;
    ofTexture   textPlayerF2;
    ofTexture   textPlayerF3;
    ofxGLWarper warperPlayerF1;

    ofxGLWarper warperTV1;
    ofxGLWarper warperTV2;
    ofxGLWarper warperTV3;
    ofxGLWarper warperTV4;
    ofxGLWarper warperTV5;
    ofxGLWarper warperTV6;

    float   activateA1,activateB1,activateC1,activateD1,activateE1,activateF1;

    //SHADER--------
    ofTexture textA1;
    ofTexture textB1;
    ofTexture textC1;
    ofTexture textD1;
    ofTexture textE1;
    ofTexture textF1;
    ofTexture textG1;

    ofFbo       chromaFbo;      //For storing the FBO contents of the chromatic abberation shader

    ofFbo       brcosaFboA1;      //For storing the FBO contents of brcosa shader
    ofFbo       brcosaFboB1;      //For storing the FBO contents of brcosa shader
    ofFbo       brcosaFboC1;      //For storing the FBO contents of brcosa shader
    ofFbo       brcosaFboD1;      //For storing the FBO contents of brcosa shader
    ofFbo       brcosaFboE1;      //For storing the FBO contents of brcosa shader
    ofFbo       brcosaFboF1;      //For storing the FBO contents of brcosa shader

    ofFbo       brcosaFboG1;

    ofShader bloomShader;       //Bloom shader (from OF forums)
    ofShader blurShader;        //So-so Gaussian Blur
    ofShader brcosaShaderA1;      //Brightness, Contrast, Saturation adjustments
    ofShader brcosaShaderB1;      //Brightness, Contrast, Saturation adjustments
    ofShader brcosaShaderC1;
    ofShader brcosaShaderD1;
    ofShader brcosaShaderE1;
    ofShader brcosaShaderF1;
    ofShader brcosaShaderG1;

    ofShader chromaShader;      //Poor mans chromatic abberation
    ofShader fishShader;        //Fisheye
    ofShader rotaShader;        //Shader from jit.rota allowing you to zoom, rotate, offset a texture
    ofShader carToPolShader;    //Cartesian to polar shader
    ofShader wobbleShader;      //Wobbulation displacement
    ofShader lumaShader;        //Luma Keying
    ofShader radialShader;      //RadialBlur

    ofShader shader;
//SLIDER-----------------------------------------------------------
    float In, Out, TimeF, Fade1,Sens, frameP1, frameP2, timestart1,  Fade2, frameP3, frameP4, timestart2,  Fade3, frameP5, frameP6, timestart3,  Fade4, frameP7, frameP8, timestart4,  Fade5, frameP9, frameP10, timestart5,  Fade6, frameP11, frameP12, timestart6;
    float   B1, B2, B3,B4,B5,B6,B9,timer,rrr,Limite,LimiteC, BangC,OpaCercle;
    float   Op1,Op2,Op3,Op4,Op5,Op6;
    int C1, C2 ,C3,C4,C5,C6,C7,Rand,Rand1 ;
    int    Opacity;
//        Crop-------------------------------------------------------------------------------------

    float   carreA1, xcarreA1, ycarreA1;
    float   carreB1, xcarreB1, ycarreB1;
    float   carreC1, xcarreC1, ycarreC1;
    float   carreD1, xcarreD1, ycarreD1;
    float   carreE1, xcarreE1, ycarreE1;
    float   carreF1, xcarreF1, ycarreF1;
    float   carreG1, xcarreG1, ycarreG1;
    float   PlaceImg, xPlaceImg, yPlaceImg;

    ofVideoGrabber 		vidGrabber;


//		unsigned char * 	videoInverted;
//		ofTexture			videoTexture;
    int 				camWidth;
    int 				camHeight;
    ofImage tv1;
    ofImage tv2;
    ofImage tv3;
    ofImage tv4;
    ofImage tv5;
    ofImage tv6;
    ofImage reflet;

    float   TV1,TV2,TV3,TV4,TV5,TV6,LumTV,OpacTV,F_1,F_2,WebCam,OpacityX6;
    float   Vid,SendOsc,NoOsc;
    string   SelVid,SelVidA,SelVidB,SelVidC,SelVidD,SelVidE,SelVidF;
    ofxXmlSettings XML;
    float   Sel;
    string  Adress;


    float Timer, startTime, endTime;

    int   xT,yT;
    float  Larg, Haut;


    float Xmouse, Ymouse;

    bool bPosition;
    ofxXmlSettings PositionWarp;
    float positionX, positionY, RectX,RectY;
    bool bWarp, bNbrLect;
    float fOpen1,fDirSize;
    ofImage 	img;

    int Sel1,A,B,C,D,E,F,G,H,I,J,K,L,M,N,Eb,Fb,Gb,Hb,Ib,Jb;
    float  LargSel, HautSel;
    int   Lect1,Lect2,Lect3,Lect4,Lect,Lect5,Lect6,Lect7,Lect8;
    int iR_Open1;

    string  sDirName;
    ofFile fDir;
    string fileName;
    string  dossierV;
    ofDirectory dir,dirData;
    int iClic,iClic2;
    bool bClic,bClic2,bAudio,bVideoGrid;

    ofxXmlSettings XmlSvg;




};

#endif
