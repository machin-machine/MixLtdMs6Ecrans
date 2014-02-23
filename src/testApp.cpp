#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofEnableSmoothing();
    ofSetVerticalSync(true);
//        <<ofGetScreenWidth()<<"x"<<ofGetScreenHeight()<<endl;
    //--------------------------OSC------------------------------
    // listen on the given port
    cout << "listening for osc messages on port " << RPORT << "\n";
    receiver.setup(RPORT); //set up receiver
    sender.setup(HOST, SPORT); //set up sender

//--------------------------SCREEN---------------------------
    ofSetWindowTitle("Mix-ltdMs");
    ofSetVerticalSync(true);
//    ofSetFrameRate(25);
    ofSetFrameRate(50);

//   	ofEnableAntiAliasing(true);
    ofBackground(0,0,0);
    backgroundColor =0;

//--------------------------AUDIO---------------------------
    // setup the sound
    soundStream.setDeviceID(0);
    soundStream.listDevices();
    sampleRate = 44100;
    bufferSize = 256;
    soundStream.setup(this, 2, 2, 44100, 256, 4);
    // a variable to store our audio
    audioInput = new float[bufferSize];
    rms_values.push_back(0);


    //--------------------------Player---------------------------

//    PlayerA1.loadMovie("v/video1.mov");
//
//    PlayerA1.play();
//
////    PlayerA1.setPaused(true);
    PlayerA1.setVolume(0.00);
    PlayerA1.setSpeed(1);
    PlayerA1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesA1 = PlayerA1.getTotalNumFrames();
////
//    PlayerB1.loadMovie("v/video1.mov");


//    PlayerB1.play();

//    PlayerB1.setPaused(true);
    PlayerB1.setVolume(0.00);
    PlayerB1.setSpeed(1);
    PlayerB1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesB1 = PlayerB1.getTotalNumFrames();

//
//    PlayerC1.loadMovie("v/video2.mov");

    PlayerC1.play();

//    PlayerC1.setPaused(true);
    PlayerC1.setVolume(0.00);
    PlayerC1.setSpeed(1);
    PlayerC1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesC1 = PlayerC1.getTotalNumFrames();
    //
//    PlayerD1.loadMovie("v/video3.mov");
//    if (!bNbrLect)
//    {
//        PlayerD1.play();
//    }
//    PlayerD1.setPaused(true);
    PlayerD1.setVolume(0.00);
    PlayerD1.setSpeed(1);
    PlayerD1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesD1 = PlayerD1.getTotalNumFrames();
//
//


//    PlayerE1.loadMovie("v/video4.mov");
//    if (!bNbrLect)
//    {
//        PlayerE1.play();
//    }
//    PlayerE1.setPaused(true);
    PlayerE1.setVolume(0.00);
    PlayerE1.setSpeed(1);
    PlayerE1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesE1 = PlayerE1.getTotalNumFrames();
    //

//    PlayerF1.loadMovie("v/video5.mov");
//    if (!bNbrLect)
//    {
//        PlayerF1.play();
//    }
//    PlayerF1.setPaused(true);
    PlayerF1.setVolume(0.00);
    PlayerF1.setSpeed(1);
    PlayerF1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesF1 = PlayerF1.getTotalNumFrames();


//    PlayerG1.loadMovie("v/video6.mov");
//    PlayerG1.play();
//    PlayerG1.setPaused(true);
    PlayerG1.setVolume(0.00);
    PlayerG1.setSpeed(1);
    PlayerG1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesG1 = PlayerG1.getTotalNumFrames();
//    Y_G1 = -10;

//    PlayerH1.loadMovie("v/video2.mov");
//    PlayerH1.play();
//    PlayerH1.setPaused(true);
    PlayerH1.setVolume(0.00);
    PlayerH1.setSpeed(1);
    PlayerH1.setLoopState(OF_LOOP_NORMAL);
//    TotalNumFramesH1 = PlayerH1.getTotalNumFrames();
//--------------------------GUI---------------------------

    setGUI1();
    setGUI2();
    setGUI3();


    gui1->setDrawBack(false);
    gui2->setDrawBack(false);
    gui3->setDrawBack(false);

    ((ofxUISlider*)gui1->getWidget("Lum_A1"))->setValue(127);
    ((ofxUISlider*)gui1->getWidget("Lum_B1"))->setValue(127);
    ((ofxUISlider*)gui1->getWidget("Lum_C1"))->setValue(127);
    ((ofxUISlider*)gui1->getWidget("Lum_D1"))->setValue(127);
    ((ofxUISlider*)gui1->getWidget("Lum_E1"))->setValue(127);
    ((ofxUISlider*)gui1->getWidget("Lum_F1"))->setValue(127);


    ((ofxUISlider*)gui1->getWidget("Op1"))->setValue(255);
    ((ofxUISlider*)gui1->getWidget("Op2"))->setValue(255);
    ((ofxUISlider*)gui1->getWidget("Op3"))->setValue(255);
    ((ofxUISlider*)gui1->getWidget("Op4"))->setValue(255);
    ((ofxUISlider*)gui1->getWidget("Op5"))->setValue(255);
    ((ofxUISlider*)gui1->getWidget("Op6"))->setValue(255);
    ((ofxUISlider*)gui1->getWidget("Cont_G1"))->setValue(127);
    ((ofxUISlider*)gui1->getWidget("Satu_G1"))->setValue(127);
    ((ofxUISlider*)gui2->getWidget("Sens"))->setValue(127);
    ((ofxUISlider*)gui2->getWidget("In"))->setValue(127);
    ((ofxUISlider*)gui2->getWidget("Out"))->setValue(127);
    ((ofxUISlider*)gui2->getWidget("TimeF"))->setValue(127);

    ((ofxUISlider*)gui2->getWidget("Rand"))->setValue(2);

    frameP1= frameP3= frameP5=frameP7=frameP9=frameP11=127;
    frameP2 =frameP4=frameP6=frameP8=frameP10=frameP12=255;

    Lum_A1=127;
    Lum_B1=127;
    Lum_C1=127;
    Lum_D1=127;
    Lum_E1=127;
    Lum_F1=127;
    Cont_G1=127;
    Satu_G1=127;
    Sens=127;
    In=127;
    Out=127;
    TimeF=127;
    Rand=2;
    Rand1=2;
    F_2=255;
    F_1=0;
    Op1=Op2=Op3=Op4=Op5=Op6=127;
    OpacityX6=127;
    Fade_G=255;


//--------------------------------------------Midi-------------
    midiIn.listPorts(); // via instance
    midiIn.openPort(1);
//    midiIn2.listPorts(); // via instance
//    midiIn2.openPort(2);
//            midiIn.openPort(2);
    midiIn.ignoreTypes(false, false, false);
    midiIn.addListener(this);
    midiIn.setVerbose(true);
    midiOut.listPorts();

//     midiIn2.ignoreTypes(false, false, false);
//    midiIn2.addListener(this);
//    midiIn2.setVerbose(true);
//	midiOut.openPort(0);	// by number
//    midiOut.openPort(1);	// by name

//-------------------------- TEXT_A1
    blendMode = OF_BLENDMODE_ALPHA;

    textA1.allocate(640,480,GL_RGB);
    textB1.allocate(640,480,GL_RGB);
    textC1.allocate(640,480,GL_RGB);
    textD1.allocate(640,480,GL_RGB);
    textE1.allocate(640,480,GL_RGB);
    textF1.allocate(640,480,GL_RGB);

    warperPlayerA1.setup();
    warperPlayerA1.load("warpConfigA1.xml");

    warperPlayerB1.setup();
    warperPlayerB1.load("warpConfigB1.xml");

    warperPlayerC1.setup();
    warperPlayerC1.load("warpConfigC1.xml");

    warperPlayerD1.setup();
    warperPlayerD1.load("warpConfigD1.xml");

    warperPlayerE1.setup();
    warperPlayerE1.load("warpConfigE1.xml");

    warperPlayerF1.setup();
    warperPlayerF1.load("warpConfigF1.xml");

    warperTV1.setup();
    warperTV1.load("warpConfigA1.xml");
    warperTV2.setup();
    warperTV2.load("warpConfigB1.xml");
    warperTV3.setup();
    warperTV3.load("warpConfigC1.xml");
    warperTV4.setup();
    warperTV4.load("warpConfigD1.xml");
    warperTV5.setup();
    warperTV5.load("warpConfigE1.xml");
    warperTV6.setup();
    warperTV6.load("warpConfigF1.xml");

//-------------------------- SHADER
    brcosaFboA1.allocate(160, 240, GL_RGBA);
    brcosaFboA1.begin();
    ofClear(0, 0, 0,0); //Clear the FBO
    brcosaFboA1.end();

    brcosaFboB1.allocate(160, 240, GL_RGBA);
    brcosaFboB1.begin();
    ofClear(0, 0, 0,0); //Clear the FBO
    brcosaFboB1.end();

    brcosaFboC1.allocate(160, 240, GL_RGBA);
    brcosaFboC1.begin();
    ofClear(0, 0, 0,0); //Clear the FBO
    brcosaFboC1.end();

    brcosaFboD1.allocate(160, 240, GL_RGBA);
    brcosaFboD1.begin();
    ofClear(0, 0, 0,0); //Clear the FBO
    brcosaFboD1.end();

    brcosaFboE1.allocate(160, 240, GL_RGBA);
    brcosaFboE1.begin();
    ofClear(0, 0, 0,0); //Clear the FBO
    brcosaFboE1.end();

    brcosaFboF1.allocate(160, 240, GL_RGBA);
    brcosaFboF1.begin();
    ofClear(0, 0, 0,0); //Clear the FBO
    brcosaFboF1.end();

    brcosaFboG1.allocate(160, 240, GL_RGBA);
    brcosaFboG1.begin();
    ofClear(0, 0, 0,0); //Clear the FBO
    brcosaFboG1.end();

    cout<<"Load BRCOSA"<<endl;
    brcosaShaderA1.load( "shaders/brcosa_GLSL");
    brcosaShaderB1.load( "shaders/brcosa_GLSL");
    brcosaShaderC1.load( "shaders/brcosa_GLSL");
    brcosaShaderD1.load( "shaders/brcosa_GLSL");
    brcosaShaderE1.load( "shaders/brcosa_GLSL");
    brcosaShaderF1.load( "shaders/brcosa_GLSL");

    brcosaShaderG1.load( "shaders/brcosa_GLSL");

    xcarreA1 =  20+620+60;
    ycarreA1 =  20+60;
    xcarreB1 =  20+620+213+60;
    ycarreB1 =  20+60;
    xcarreC1 =  20+620+213+213+60;
    ycarreC1 =  20+60;
    xcarreD1 =  20+620+60;
    ycarreD1 =  20+160+60;
    xcarreE1 =  20+620+213+60;
    ycarreE1 =  20+160+60;
    xcarreF1 =  20+620+213+213+60;
    ycarreF1 =  20+160+60;
    xcarreG1 =  640+60;
    ycarreG1 =  20;

    tv1.loadImage("tv1.png");
    tv2.loadImage("tv2.png");
    tv3.loadImage("tv3.png");
    tv4.loadImage("tv4.png");
    tv5.loadImage("tv5.png");
    tv6.loadImage("tv6.png");

    XML.loadFile("mySettings.xml");

    Larg=640;
    Haut=480;
    xPlaceImg=225;
    yPlaceImg=480;

//    img.loadImage("ScreenCapture.png");
    LargSel=120;
    HautSel=70;
    fDirSize = XML.getValue("dirSize",24,0);
    iClic =0;
    bNbrLect=false;



    bVideoGrid  =   true;

    string path = "v/";
    ofDirectory dir(path);
    dir.listDir();
    XmlSvg.loadFile("XmlSvg.xml");
    sDirName = XmlSvg.getValue("XmlSvg:sDirName","sDirName");
    fDirSize = XmlSvg.getValue("XmlSvg:fDirSize",32);
    fileName = XmlSvg.getValue("XmlSvg:fileName","fileName");

    fileName = sDirName+".png";
    img.loadImage("v/"+sDirName+"/.data/"+fileName);
    XML.loadFile("v/"+sDirName+"/.data/"+sDirName+".xml");
    cout<<"sDirName/"<< sDirName<<"-fDirSize/"<<fDirSize <<"-fileName/"<<"v/"+sDirName+"/.data/"+fileName <<endl;


    movieAdress =   XmlSvg.getValue("XmlSvg:PlayerA1","PlayerA1");
    PlayerA1.loadMovie(movieAdress);
    PlayerA1.play();
    TotalNumFramesA1 = PlayerA1.getTotalNumFrames();
    PlayerA1.setLoopState(OF_LOOP_NORMAL);


    movieAdress =   XmlSvg.getValue("XmlSvg:PlayerB1","PlayerB1");

    PlayerB1.loadMovie(movieAdress);
    PlayerB1.play();
    TotalNumFramesB1 = PlayerB1.getTotalNumFrames();
    PlayerB1.setLoopState(OF_LOOP_NORMAL);

    movieAdress =   XmlSvg.getValue("XmlSvg:PlayerC1","PlayerC1");


    PlayerC1.loadMovie(movieAdress);
    PlayerC1.play();
    TotalNumFramesC1 = PlayerC1.getTotalNumFrames();
    PlayerC1.setLoopState(OF_LOOP_NORMAL);
     movieAdress =   XmlSvg.getValue("XmlSvg:PlayerD1","PlayerD1");

    PlayerD1.loadMovie(movieAdress);
    PlayerD1.play();
    TotalNumFramesD1 = PlayerD1.getTotalNumFrames();
    PlayerD1.setLoopState(OF_LOOP_NORMAL);

     movieAdress =   XmlSvg.getValue("XmlSvg:PlayerE1","PlayerE1");

    PlayerE1.loadMovie(movieAdress);
    PlayerE1.play();
    TotalNumFramesE1 = PlayerE1.getTotalNumFrames();
    PlayerE1.setLoopState(OF_LOOP_NORMAL);

     movieAdress =   XmlSvg.getValue("XmlSvg:PlayerF1","PlayerF1");


    PlayerF1.loadMovie(movieAdress);
    PlayerF1.play();
    TotalNumFramesF1 = PlayerF1.getTotalNumFrames();
    PlayerF1.setLoopState(OF_LOOP_NORMAL);

     movieAdress =   XmlSvg.getValue("XmlSvg:PlayerG1","PlayerG1");

    PlayerG1.loadMovie(movieAdress);
    PlayerG1.play();
    TotalNumFramesG1 = PlayerG1.getTotalNumFrames();
    PlayerG1.setLoopState(OF_LOOP_NORMAL);

    PlayerH1.loadMovie(movieAdress);
    PlayerH1.play();
    TotalNumFramesH1 = PlayerH1.getTotalNumFrames();
    PlayerH1.setLoopState(OF_LOOP_NORMAL);

     ofToggleFullscreen();
     bWarp  =true;







}

//--------------------------------------------------------------
void testApp::update()
{
//--------------------------Player---------------------------
    cout<<"sDirName/"<< sDirName<<"-fDirSize/"<<fDirSize <<"-fileName/"<<fileName <<endl;

    PlayerA1.update();
    PlayerB1.update();
    PlayerC1.update();

    if (bNbrLect)
    {
        PlayerD1.update();
        PlayerE1.update();
        PlayerF1.update();
    }


    PlayerG1.update();
    PlayerH1.update();

    while(receiver.hasWaitingMessages())
    {
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        cout<<"m.getAddress() "<<m.getAddress() <<endl;
        cout<<"movieAdress"<<movieAdress<<endl;

        if(m.getAddress() == "/LoadXmySettings")
        {
            cout<<"XML.loadFileMySettings.xml"<<endl;
            XML.loadFile("mySettings.xml");
            fDirSize = XML.getValue("dirSize",24,0);
            img.loadImage("ScreenCapture.png");
        }


        if(m.getAddress() == "/Open1")
        {
            PlayerA1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerA1.loadMovie(movieAdress);
            PlayerA1.play();
            TotalNumFramesA1 = PlayerA1.getTotalNumFrames();
            PlayerA1.setLoopState(OF_LOOP_NORMAL);
        }

        if(m.getAddress() == "/Open2")
        {
            PlayerB1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerB1.loadMovie(movieAdress);
            PlayerB1.play();
            TotalNumFramesB1 = PlayerB1.getTotalNumFrames();
            PlayerB1.setLoopState(OF_LOOP_NORMAL);
        }
        else if(m.getAddress() == "/Open3" )
        {
            PlayerC1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerC1.loadMovie(movieAdress);
            PlayerC1.play();
            TotalNumFramesC1 = PlayerC1.getTotalNumFrames();
            PlayerC1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/Open2")
        {
            PlayerD1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerD1.loadMovie(movieAdress);
            PlayerD1.play();
            TotalNumFramesD1 = PlayerD1.getTotalNumFrames();
            PlayerD1.setLoopState(OF_LOOP_NORMAL);
        }
        else if(m.getAddress() == "/Open1")
        {
            PlayerE1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerE1.loadMovie(movieAdress);
            PlayerE1.play();
            TotalNumFramesE1 = PlayerE1.getTotalNumFrames();
            PlayerE1.setLoopState(OF_LOOP_NORMAL);
        }
        else if(m.getAddress() == "/Open3" )
        {
            PlayerF1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerF1.loadMovie(movieAdress);
            PlayerF1.play();
            TotalNumFramesF1 = PlayerF1.getTotalNumFrames();
            PlayerF1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/Open4"  )
        {
            PlayerG1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerG1.loadMovie(movieAdress);
            PlayerG1.play();
            TotalNumFramesG1 = PlayerG1.getTotalNumFrames();
            PlayerG1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/Open5"  )
        {
            PlayerH1.closeMovie();
            movieAdress = XML.getValue("ajout:adres",Adress,m.getArgAsFloat(0)-1);
            cout<<"movieAdress"<<movieAdress<<endl;
            PlayerH1.loadMovie(movieAdress);
            PlayerH1.play();
            TotalNumFramesH1 = PlayerH1.getTotalNumFrames();
            PlayerH1.setLoopState(OF_LOOP_NORMAL);
        }

        if(m.getAddress() == "/SendOsc"  )
        {
            SendOsc = m.getArgAsFloat(0);
        }
        if(m.getAddress() == "/Vid"  )
        {
            Vid = m.getArgAsFloat(0);
            if(Vid==1)
            {
                B1 = 1;
                frameP2  = In;
            }
            if(Vid==2)
            {
                B2 = 1;
                frameP4  = In;
            }
            if(Vid==3)
            {
                B3 = 1;
                frameP6  = In;
            }
            if(Vid==4)
            {
                B4 = 1;
                frameP8  = In;
            }
            if(Vid==5)
            {
                B5 = 1;
                frameP10  = In;
            }
            if(Vid==6)
            {
                B6 = 1;
                frameP12  = In;
            }
        }
        if(m.getAddress() == "/SelVid"  )
        {
            SelVid = m.getArgAsString(0);
            PlayerG1.loadMovie(SelVid);
            PlayerG1.play();
            PlayerG1.setLoopState(OF_LOOP_NORMAL);

            cout<<"SelVid"<<"-"<<SelVid<<endl;
        }
        if(m.getAddress() == "/SelVidA"  )
        {
            SelVidA = m.getArgAsString(0);
            PlayerA1.loadMovie(SelVidA);
            PlayerA1.play();
            PlayerA1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/SelVidB"  )
        {
            SelVidB = m.getArgAsString(0);
            PlayerB1.loadMovie(SelVidB);
            PlayerB1.play();
            PlayerB1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/SelVidC"  )
        {
            SelVidC = m.getArgAsString(0);
            PlayerC1.loadMovie(SelVidC);
            PlayerC1.play();
            PlayerC1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/SelVidD"  )
        {
            SelVidD= m.getArgAsString(0);
            PlayerD1.loadMovie(SelVidD);
            PlayerD1.play();
            PlayerD1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/SelVidE"  )
        {
            SelVidE = m.getArgAsString(0);
            PlayerE1.loadMovie(SelVidE);
            PlayerE1.play();
            PlayerE1.setLoopState(OF_LOOP_NORMAL);
        }
        if(m.getAddress() == "/SelVidF"  )
        {
            SelVidF = m.getArgAsString(0);
            PlayerF1.loadMovie(SelVidF);
            PlayerF1.play();
            PlayerF1.setLoopState(OF_LOOP_NORMAL);
        }


        if(SendOsc==1)
        {
            if(m.getAddress() == "/Mix_G1"  )
            {
                Mix_G1 = m.getArgAsFloat(0)*255;
                ((ofxUISlider*)gui1->getWidget("Mix_G1"))->setValue(Mix_G1);
            }
            if(m.getAddress() == "/TV1"  )
            {
                TV1 = m.getArgAsFloat(0)*255;
                ((ofxUICircleSlider*)gui1->getWidget("TV1"))->setValue(TV1);
            }

            if(m.getAddress() == "/Sens"  )
            {
                Sens = m.getArgAsFloat(0)*255;
                ((ofxUISlider*)gui2->getWidget("Sens"))->setValue(Sens);
            }
            if(m.getAddress() == "/Rand"  )
            {
                Rand = m.getArgAsFloat(0)*30;
            }
            if(m.getAddress() == "/In"  )
            {
                In = m.getArgAsFloat(0)*255;
            }
            if(m.getAddress() == "/Out"  )
            {
                Out = m.getArgAsFloat(0)*255;
            }
            if(m.getAddress() == "/TimeF"  )
            {
                TimeF = m.getArgAsFloat(0)*60;
            }
        }
    }
//    }
//



    ((ofxUISlider*)gui2->getWidget("Sens"))->setValue(Sens);
    ((ofxUISlider*)gui2->getWidget("In"))->setValue(In);
    ((ofxUISlider*)gui2->getWidget("Out"))->setValue(Out);
    ((ofxUISlider*)gui2->getWidget("TimeF"))->setValue(TimeF);
//    ((ofxUIToggle*)gui2->getWidget("SendOsc"))->setValue(SendOsc);
//    ((ofxUIToggle*)gui2->getWidget("NoOsc"))->setValue(NoOsc);



//////////        }




//--------------------------AUDIO---------------------------
    rms_values.push_back(rms);
    if (rms_values.size() > 25)
    {
        rms_values.erase(rms_values.begin(), rms_values.begin() + 1);
    }

//-------------------------SLIDERS--------------------------
    if(B1 == 1 )
    {
        if(frameP2 > Out)
        {
            Fade1  =   In;
            frameP1  =   In;
            frameP1  =   frameP2;
            frameP2 = frameP1 - TimeF;
            if(Fade1 < Out)
            {
                B1 = 0;
                frameP2 = Out;
//            ((ofxUIButton*)gui->getWidget("B1"))->setValue(0);
            }
        }
        if(frameP2 < Out)
        {
            Fade1  =   In;
            frameP1  =   In;
            frameP1  =   frameP2;
            frameP2 = frameP1 + TimeF;
            if(Fade1 > Out)
            {
                B1 = 0;
                frameP2 = Out;
//                ((ofxUIButton*)gui->getWidget("B1"))->setValue(0);

            }
        }
        if(Opacity==0)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_A1"))->setValue(frameP2);
            Fade1 = frameP2;
            Lum_A1 = frameP2;

        }
        if(Opacity==1)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_A1"))->setValue(127);
            ((ofxUISlider*)gui1->getWidget("Op1"))->setValue(frameP2);
            Fade1 = frameP2;
            Op1 = frameP2;
        }

    }

//---------------------------------------------------------------------------
    if(B2 == 1 )
    {
        if(frameP4 > Out)
        {
            Fade2  =   In;
            frameP3  =   In;
            frameP3  =   frameP4;
            frameP4 = frameP3 - TimeF;
            if(Fade2 < Out)
            {
                B2 = 0;
                frameP4 = Out;
//                ((ofxUIButton*)gui->getWidget("B2"))->setValue(0);
            }
        }
        if(frameP4 < Out)
        {
            Fade2  =   In;
            frameP3  =   In;
            frameP3  =   frameP4;
            frameP4 = frameP3 + TimeF;
            if(Fade2 > Out)
            {
                B2 = 0;
                frameP4 = Out;
//                ((ofxUIButton*)gui->getWidget("B2"))->setValue(0);
            }
        }

        if(Opacity==0)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_B1"))->setValue(frameP4);
            Fade2 = frameP4;
            Lum_B1 = frameP4;
        }
        if(Opacity==1)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_B1"))->setValue(127);
            ((ofxUISlider*)gui1->getWidget("Op2"))->setValue(frameP4);
            Fade2 = frameP4;
            Op2 = frameP4;
        }
    }
//---------------------------------------------------------------------------
    if(B3 == 1   )
    {
        if(frameP6 > Out)
        {
            Fade3  =   In;
            frameP5  =   In;
            frameP5  =   frameP6;
            frameP6 = frameP5 - TimeF;
            if(Fade3 < Out)
            {
                B3 = 0;
                frameP6 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);
            }
        }

        if(frameP6 < Out)
        {
            Fade3  =   In;
            frameP5  =   In;
            frameP5  =   frameP6;
            frameP6 = frameP5 + TimeF;
            if(Fade3 > Out)
            {
                B3 = 0;
                frameP6 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);

            }
        }
        if(Opacity==0)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_C1"))->setValue(frameP6);
            Fade3 = frameP6;
            Lum_C1 = frameP6;
        }
        if(Opacity==1)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_C1"))->setValue(127);
            ((ofxUISlider*)gui1->getWidget("Op3"))->setValue(frameP6);
            Fade3 = frameP6;
            Op3 = frameP6;
        }

    }

    //---------------------------------------------------------------------------
    if(B4 == 1   )
    {
        if(frameP8 > Out)
        {
            Fade4  =   In;
            frameP7  =   In;
            frameP7 =   frameP8;
            frameP8 = frameP7 - TimeF;
            if(Fade4 < Out)
            {
                B4 = 0;
                frameP8 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);
            }
        }
        if(frameP8 < Out)
        {
            Fade4  =   In;
            frameP7  =   In;
            frameP7  =   frameP8;
            frameP8 = frameP7 + TimeF;
            if(Fade4 > Out)
            {
                B4 = 0;
                frameP8 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);
            }
        }
        if(Opacity==0)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_D1"))->setValue(frameP8);
            Fade4 = frameP8;
            Lum_D1 = frameP8;
        }
        if(Opacity==1)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_D1"))->setValue(127);
            ((ofxUISlider*)gui1->getWidget("Op4"))->setValue(frameP8);
            Fade4 = frameP8;
            Op4 = frameP8;
        }
    }
//-------------------------------------------------------------
//---------------------------------------------------------------------------
    if(B5 == 1   )
    {
        if(frameP10 > Out)
        {
            Fade5  =   In;
            frameP9  =   In;
            frameP9  =   frameP10;
            frameP10 = frameP9 - TimeF;
            if(Fade5 < Out)
            {
                B5 = 0;
                frameP10 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);
            }
        }
        if(frameP10 < Out)
        {
            Fade5  =   In;
            frameP9  =   In;
            frameP9  =   frameP10;
            frameP10 = frameP9 + TimeF;
            if(Fade5 > Out)
            {
                B5 = 0;
                frameP10 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);

            }
        }

        if(Opacity==0)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_E1"))->setValue(frameP10);
            Fade5 = frameP10;
            Lum_E1 = frameP10;
        }
        if(Opacity==1)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_E1"))->setValue(127);
            ((ofxUISlider*)gui1->getWidget("Op5"))->setValue(frameP10);
            Fade5 = frameP10;
            Op5 = frameP10;
        }
    }
//-------------------------------------------------------------
    if(B6 == 1   )
    {
        if(frameP12 > Out)
        {
            Fade6  =   In;
            frameP11  =   In;
            frameP11  =   frameP12;
            frameP12 = frameP11 - TimeF;
            if(Fade6 < Out)
            {
                B6 = 0;
                frameP10 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);
            }
        }
        if(frameP12 < Out)
        {
            Fade6  =   In;
            frameP11  =   In;
            frameP11  =   frameP12;
            frameP12 = frameP11 + TimeF;
            if(Fade6 > Out)
            {
                B6 = 0;
                frameP12 = Out;
//                        ((ofxUIButton*)gui->getWidget("B3"))->setValue(0);

            }
        }

        if(Opacity==0)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_F1"))->setValue(frameP12);
            Fade6 = frameP12;
            Lum_F1 = frameP12;
        }
        if(Opacity==1)
        {
            ((ofxUISlider*)gui1->getWidget("Lum_F1"))->setValue(127);
            ((ofxUISlider*)gui1->getWidget("Op6"))->setValue(frameP12);
            Fade6 = frameP12;
            Op6 = frameP12;
        }
    }

    Rand    =   Rand1;

//-------------------------------------------------------------
    Cont_A1 =   Cont_G1 ;
    Satu_A1 =   Satu_G1 ;
    Cont_B1 =   Cont_G1 ;
    Satu_B1 =   Satu_G1 ;
    Cont_C1 =   Cont_G1 ;
    Satu_C1 =   Satu_G1 ;
    Cont_D1 =   Cont_G1 ;
    Satu_D1 =   Satu_G1 ;
    Cont_E1 =   Cont_G1 ;
    Satu_E1 =   Satu_G1 ;
    Cont_F1 =   Cont_G1 ;
    Satu_F1 =   Satu_G1 ;


    ofSoundUpdate();

    vidGrabber.update();
    //---------------------------------------
    Timer = ofGetElapsedTimeMillis() - startTime;
    endTime = 40;
//    cout<<"timer"<< Timer <<"startTime"<< startTime<<"startTime"<< "endTime"<<endTime<<endl;
    if(timer>=endTime)
    {
        cout<<"Bang4"<<endl;
    }


//    if(Lect2==1 && Sel1 <=fDirSize)
//    {
////        Lect2=0;
//        PlayerB1.closeMovie();
//        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
//        cout<<"movieAdress"<<movieAdress<<endl;
//        PlayerB1.loadMovie(movieAdress);
//        PlayerB1.play();
//        TotalNumFramesB1 = PlayerB1.getTotalNumFrames();
//        PlayerB1.setLoopState(OF_LOOP_NORMAL);
//
//        if(PlayerB1.isLoaded())
//        {
//            PlayerE1.closeMovie();
//            movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
//
//            cout<<"movieAdress"<<movieAdress<<"PlayerB1.isLoaded()"<<endl;
//            PlayerE1.loadMovie(movieAdress);
//            PlayerE1.play();
//            TotalNumFramesE1 = PlayerE1.getTotalNumFrames();
//            PlayerE1.setLoopState(OF_LOOP_NORMAL);
//        }
//        Sel1 = 33;
//
//    }
//    if(Lect3==1 && Sel1 <=fDirSize)
//    {
////        Lect3=0;
//        PlayerC1.closeMovie();
//        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
//        cout<<"movieAdress"<<movieAdress<<endl;
//        PlayerC1.loadMovie(movieAdress);
//        PlayerC1.play();
//        TotalNumFramesC1 = PlayerC1.getTotalNumFrames();
//        PlayerC1.setLoopState(OF_LOOP_NORMAL);
//        if(PlayerC1.isPlaying())
//
//        {
//            PlayerF1.closeMovie();
//            movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
//
//            cout<<"movieAdress"<<movieAdress<<"PlayerC1.isPlaying"<<endl;
//            PlayerF1.loadMovie(movieAdress);
//            PlayerF1.play();
//            TotalNumFramesF1 = PlayerF1.getTotalNumFrames();
//            PlayerF1.setLoopState(OF_LOOP_NORMAL);
//        }
//        Sel1 = 33;
//    }
}

//--------------------------------------------------------------
void testApp::draw()
{



//--------------------------SCREEN---------------------------
    ofBackground(backgroundColor,backgroundColor,backgroundColor);
//    ofEnableNormalizedTexCoords();
    ofEnableSmoothing();

//--------------------------Player---------------------------
//

    ofSetColor(0,0,0);
    ofFill();
    ofRect(xcarreG1,ycarreG1,Larg,Haut);


    ofEnableAlphaBlending();
//        ofSetColor(255,255,255,TV1* (Mix_G1/127) );
    ofSetColor(255,255,255,F_2) ;
    PlayerH1.draw(xcarreG1,ycarreG1,Larg,Haut);
    ofDisableAlphaBlending();

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,F_1);
    PlayerG1.draw(xcarreG1,ycarreG1,Larg,Haut);
//        PlayerG1.draw(320+640,20,640,480);
    ofDisableAlphaBlending();

//        PlayerH1.draw(320+640,20,640,480);
    //Si  webcam------------

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,WebCam) ;
    if (bNbrLect)
    {
        vidGrabber.draw(xcarreD1, ycarreD1,213,160);
        vidGrabber.draw(xcarreE1, ycarreE1,213,160);
        vidGrabber.draw(xcarreF1, ycarreF1,213,160);
    }
    vidGrabber.draw(xcarreA1, ycarreA1,213,160);
    vidGrabber.draw(xcarreB1, ycarreB1,213,160);
    vidGrabber.draw(xcarreC1, ycarreC1,213,160);


    ofDisableAlphaBlending();

    ofEnableBlendMode(blendMode);
    ofSetColor(255,255,255,Op1);
    PlayerA1.draw(xcarreA1,ycarreA1,213,160);
    ofDisableBlendMode();

    ofEnableBlendMode(blendMode);
    ofSetColor(255,255,255,Op2);
    PlayerB1.draw(xcarreB1,ycarreB1,213,160);
    ofDisableBlendMode();

    ofEnableBlendMode(blendMode);
    ofSetColor(255,255,255,Op3);
    PlayerC1.draw(xcarreC1,ycarreC1,213,160);
    ofDisableBlendMode();

    if (bNbrLect)
    {
        ofEnableBlendMode(blendMode);
        ofSetColor(255,255,255,Op4);
        PlayerD1.draw(xcarreD1,ycarreD1,213,160);
        ofDisableBlendMode();

        ofEnableBlendMode(blendMode);
        ofSetColor(255,255,255,Op5);
        PlayerE1.draw(xcarreE1,ycarreE1,213,160);
        ofDisableBlendMode();

        ofEnableBlendMode(blendMode);
        ofSetColor(255,255,255,Op6);
        PlayerF1.draw(xcarreF1,ycarreF1,213,160);
        ofDisableBlendMode();

    }





//////////////////////////////////////        ofSetColor(backgroundColor,backgroundColor,backgroundColor);
//////////////////////////////////////        ofFill();
//////////////////////////////////////        ofRect(50,0,1280,20);
//////////////////////////////////////        ofSetColor(backgroundColor,backgroundColor,backgroundColor);
//////////////////////////////////////        ofRect(50,180,1280,800);


////////    ofSetColor(60,60,60);
////////    ofRect(340,180,640,320);


//    ofNoFill();//rect-----1/3
//    ofSetColor(250,0,0,255);
//	ofRect(5,1024-260,700,400);
//	ofRect(5+233,1024-260,233,400);

    if(bWarp)
    {
//----------------------------------WARPING
        textA1.loadScreenData(xcarreA1, ycarreA1,213,160);
//    textA1.loadScreenData(xcarreA1, ycarreA1,213,160);

        warperPlayerA1.begin();
        warperPlayerA1.draw();
        glPushMatrix();
        ofSetColor(255,255,255,255);
        textA1.bind();
        brcosaShaderA1.begin();
        brcosaShaderA1.setUniformTexture("tex0", textA1, 0);
        brcosaShaderA1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderA1.setUniform1f("contrast", Cont_A1/127);
        brcosaShaderA1.setUniform1f("brightness", Lum_A1/127);
        brcosaShaderA1.setUniform1f("saturation", Satu_A1/127);
        ofDisableAlphaBlending();
        brcosaShaderA1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,768,0);
        glTexCoord2f(213,0);
        glVertex3f(1024,768,0);
        glTexCoord2f(213,160);
        glVertex3f(1024,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderA1.end();
        textA1.unbind();
        glPopMatrix();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(0,0,0,Fade_G);
        ofFill();
        ofRect(0,0,1024,768);

        warperPlayerA1.end();

        warperTV1.begin();
        warperTV1.draw();
        ofEnableAlphaBlending();
        ofSetColor(LumTV,LumTV,LumTV,OpacTV);
        tv1.draw(0, 0,1024,768);
        ofSetColor(255,255,255,255);
        reflet.draw(0, 0,1024,768);
        ofDisableAlphaBlending();
        warperTV1.end();

        textB1.loadScreenData(xcarreB1, ycarreB1,213,160);
        warperPlayerB1.begin();
        warperPlayerB1.draw();
        glPushMatrix();
        ofSetColor(255,255,255,255);
        textB1.bind();
        brcosaShaderB1.begin();
        brcosaShaderB1.setUniformTexture("tex0", textB1, 0);
        brcosaShaderB1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderB1.setUniform1f("contrast", Cont_B1/127);
        brcosaShaderB1.setUniform1f("brightness", Lum_B1/127);
        brcosaShaderB1.setUniform1f("saturation", Satu_B1/127);
        ofDisableAlphaBlending();
        brcosaShaderB1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,768,0);
        glTexCoord2f(213,0);
        glVertex3f(1024,768,0);
        glTexCoord2f(213,160);
        glVertex3f(1024,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderB1.end();
        textB1.unbind();
        glPopMatrix();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(0,0,0,Fade_G);
        ofFill();
        ofRect(0,0,1024,768);
        ofDisableBlendMode();
        warperPlayerB1.end();

        warperTV2.begin();
        warperTV2.draw();
        ofEnableAlphaBlending();
        ofSetColor(LumTV,LumTV,LumTV,OpacTV);
        tv2.draw(0, 0,1024,768);
        ofDisableAlphaBlending();
        warperTV2.end();

        textC1.loadScreenData(xcarreC1, ycarreC1,213,160);
        warperPlayerC1.begin();

        warperPlayerC1.draw();
        glPushMatrix();
        ofSetColor(255,255,255,255);
        textC1.bind();
        brcosaShaderC1.begin();
        brcosaShaderC1.setUniformTexture("tex0", textC1, 0);
        brcosaShaderC1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderC1.setUniform1f("contrast", Cont_C1/127);
        brcosaShaderC1.setUniform1f("brightness", Lum_C1/127);
        brcosaShaderC1.setUniform1f("saturation", Satu_C1/127);
        ofDisableAlphaBlending();
        brcosaShaderC1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,768,0);
        glTexCoord2f(213,0);
        glVertex3f(1024,768,0);
        glTexCoord2f(213,160);
        glVertex3f(1024,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderC1.end();
        textC1.unbind();
        glPopMatrix();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(0,0,0,Fade_G);
        ofFill();
        ofRect(0,0,1024,768);
        ofDisableBlendMode();
        warperPlayerC1.end();

        warperTV3.begin();
        warperTV3.draw();
        ofEnableAlphaBlending();
        ofSetColor(LumTV,LumTV,LumTV,OpacTV);
        tv3.draw(0, 0,1024,768);
        ofDisableAlphaBlending();
        warperTV3.end();

        textD1.loadScreenData(xcarreD1, ycarreD1,213,160);
        warperPlayerD1.begin();

        warperPlayerD1.draw();
        glPushMatrix();
        ofSetColor(255,255,255,255);
        textD1.bind();
        brcosaShaderD1.begin();
        brcosaShaderD1.setUniformTexture("tex0", textD1, 0);
        brcosaShaderD1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderD1.setUniform1f("contrast", Cont_D1/127);
        brcosaShaderD1.setUniform1f("brightness", Lum_D1/127);
        brcosaShaderD1.setUniform1f("saturation", Satu_D1/127);
        ofDisableAlphaBlending();
        brcosaShaderD1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,768,0);
        glTexCoord2f(213,0);
        glVertex3f(1024,768,0);
        glTexCoord2f(213,160);
        glVertex3f(1024,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderD1.end();
        textD1.unbind();
        glPopMatrix();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(0,0,0,Fade_G);
        ofFill();
        ofRect(0,0,1024,768);
        ofDisableBlendMode();
        warperPlayerD1.end();

        warperTV4.begin();
        warperTV4.draw();
        ofEnableAlphaBlending();
        ofSetColor(LumTV,LumTV,LumTV,OpacTV);
        tv4.draw(0, 0,1024,768);
        ofDisableAlphaBlending();
        warperTV4.end();

        textE1.loadScreenData(xcarreE1, ycarreE1,213,160);
        warperPlayerE1.begin();

        warperPlayerE1.draw();
        glPushMatrix();
        ofSetColor(255,255,255,255);
        textE1.bind();
        brcosaShaderE1.begin();
        brcosaShaderE1.setUniformTexture("tex0", textE1, 0);
        brcosaShaderE1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderE1.setUniform1f("contrast", Cont_E1/127);
        brcosaShaderE1.setUniform1f("brightness", Lum_E1/127);
        brcosaShaderE1.setUniform1f("saturation", Satu_E1/127);
        ofDisableAlphaBlending();
        brcosaShaderE1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,768,0);
        glTexCoord2f(213,0);
        glVertex3f(1024,768,0);
        glTexCoord2f(213,160);
        glVertex3f(1024,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderE1.end();
        textE1.unbind();
        glPopMatrix();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(0,0,0,Fade_G);
        ofFill();
        ofRect(0,0,1024,768);
        ofDisableBlendMode();
        warperPlayerE1.end();

        warperTV5.begin();
        warperTV5.draw();
        ofEnableAlphaBlending();
        ofSetColor(LumTV,LumTV,LumTV,OpacTV);
        tv5.draw(0, 0,1024,768);
        ofDisableAlphaBlending();
        warperTV5.end();

        textF1.loadScreenData(xcarreF1, ycarreF1,213,160);
        warperPlayerF1.begin();

        warperPlayerF1.draw();
        glPushMatrix();
        ofSetColor(255,255,255,255);
        textF1.bind();
        brcosaShaderF1.begin();
        brcosaShaderF1.setUniformTexture("tex0", textF1, 0);
        brcosaShaderF1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderF1.setUniform1f("contrast", Cont_F1/127);
        brcosaShaderF1.setUniform1f("brightness", Lum_F1/127);
        brcosaShaderF1.setUniform1f("saturation", Satu_F1/127);
        ofDisableAlphaBlending();
        brcosaShaderF1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,768,0);
        glTexCoord2f(213,0);
        glVertex3f(1024,768,0);
        glTexCoord2f(213,160);
        glVertex3f(1024,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderF1.end();
        textF1.unbind();
        glPopMatrix();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(0,0,0,Fade_G);
        ofFill();
        ofRect(0,0,1024,768);
        ofDisableBlendMode();
        warperPlayerF1.end();

        warperTV6.begin();
        warperTV6.draw();
        ofEnableAlphaBlending();
        ofSetColor(LumTV,LumTV,LumTV,OpacTV);
        tv6.draw(0, 0,1024,768);
        ofDisableAlphaBlending();
        warperTV6.end();
//////////------------------------------------------------PREVIEW
        ofSetColor(255,255,255);
//       textA1.draw(255,20+160,213,160);
        textA1.bind();
        brcosaShaderA1.begin();
        brcosaShaderA1.setUniformTexture("tex0", textA1, 0);
        brcosaShaderA1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderA1.setUniform1f("contrast", Cont_A1/127);
        brcosaShaderA1.setUniform1f("brightness", Lum_A1/127);
        brcosaShaderA1.setUniform1f("saturation", Satu_A1/127);
        ofDisableAlphaBlending();
        brcosaShaderA1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(420,216);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,160/3,0);
        glTexCoord2f(213,0);
        glVertex3f(213/3,160/3,0);
        glTexCoord2f(213,160);
        glVertex3f(213/3,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderA1.end();
        textA1.unbind();

        ofSetColor(255,255,255);
//        textB1.draw(255+213,20+160,213,160);
        textB1.bind();
        brcosaShaderB1.begin();
        brcosaShaderB1.setUniformTexture("tex0", textB1, 0);
        brcosaShaderB1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderB1.setUniform1f("contrast", Cont_B1/127);
        brcosaShaderB1.setUniform1f("brightness", Lum_B1/127);
        brcosaShaderB1.setUniform1f("saturation", Satu_B1/127);
        ofDisableAlphaBlending();
        brcosaShaderB1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(420+71,216);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,160/3,0);
        glTexCoord2f(213,0);
        glVertex3f(213/3,160/3,0);
        glTexCoord2f(213,160);
        glVertex3f(213/3,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderB1.end();
        textB1.unbind();

        textC1.bind();
        brcosaShaderC1.begin();
        brcosaShaderC1.setUniformTexture("tex0", textC1, 0);
        brcosaShaderC1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderC1.setUniform1f("contrast", Cont_C1/127);
        brcosaShaderC1.setUniform1f("brightness", Lum_C1/127);
        brcosaShaderC1.setUniform1f("saturation", Satu_C1/127);
        ofDisableAlphaBlending();
        brcosaShaderC1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(420+71+71,216);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,160/3,0);
        glTexCoord2f(213,0);
        glVertex3f(213/3,160/3,0);
        glTexCoord2f(213,160);
        glVertex3f(213/3,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderC1.end();
        textC1.unbind();

        textD1.bind();
        brcosaShaderD1.begin();
        brcosaShaderD1.setUniformTexture("tex0", textD1, 0);
        brcosaShaderD1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderD1.setUniform1f("contrast", Cont_D1/127);
        brcosaShaderD1.setUniform1f("brightness", Lum_D1/127);
        brcosaShaderD1.setUniform1f("saturation", Satu_D1/127);
        ofDisableAlphaBlending();
        brcosaShaderD1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(420,216+54);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,160/3,0);
        glTexCoord2f(213,0);
        glVertex3f(213/3,160/3,0);
        glTexCoord2f(213,160);
        glVertex3f(213/3,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);;
        glEnd();
        ofPopMatrix();
        brcosaShaderD1.end();
        textD1.unbind();

        textE1.bind();
        brcosaShaderE1.begin();
        brcosaShaderE1.setUniformTexture("tex0", textE1, 0);
        brcosaShaderE1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderE1.setUniform1f("contrast", Cont_E1/127);
        brcosaShaderE1.setUniform1f("brightness", Lum_E1/127);
        brcosaShaderE1.setUniform1f("saturation", Satu_E1/127);
        ofDisableAlphaBlending();
        brcosaShaderE1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(420+71,216+54);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,160/3,0);
        glTexCoord2f(213,0);
        glVertex3f(213/3,160/3,0);
        glTexCoord2f(213,160);
        glVertex3f(213/3,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderE1.end();
        textE1.unbind();

        textF1.bind();
        brcosaShaderF1.begin();
        brcosaShaderF1.setUniformTexture("tex0", textF1, 0);
        brcosaShaderF1.setUniform3f("avgluma", 0.62,0.62,0.62);
        brcosaShaderF1.setUniform1f("contrast", Cont_F1/127);
        brcosaShaderF1.setUniform1f("brightness", Lum_F1/127);
        brcosaShaderF1.setUniform1f("saturation", Satu_F1/127);
        ofDisableAlphaBlending();
        brcosaShaderF1.setUniform1f("alpha", 1);
        ofPushMatrix();
        ofTranslate(420+71+71,216+54);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(0,160/3,0);
        glTexCoord2f(213,0);
        glVertex3f(213/3,160/3,0);
        glTexCoord2f(213,160);
        glVertex3f(213/3,0,0);
        glTexCoord2f(0,160);
        glVertex3f(0,0,0);
        glEnd();
        ofPopMatrix();
        brcosaShaderF1.end();
        textF1.unbind();
    }
    ofNoFill();
    ofSetColor(255, 255,255);
    ofRect(420,24+85+106, 213, 106);



////////        //----------------------------------------------------PetitePreview


    ofSetColor(255,255,255,255);

//        ofPushMatrix();
//        ofTranslate(0,20+60);

    PlayerA1.draw(420,20+85,71,53);
    PlayerB1.draw(420+71,20+85,71,53);
    PlayerC1.draw(420+71+71,20+85,71,53);
    PlayerD1.draw(420,20+85+53,71,53);
    PlayerE1.draw(420+71,20+85+53,71,53);
    PlayerF1.draw(420+71+71,20+85+53,71,53);
    ofDisableAlphaBlending();

    ofNoFill();
    ofSetColor(255, 255,255);
    ofRect(420,20+85, 213,106);

//        ofPopMatrix();


    ofEnableAlphaBlending();
    ofSetColor(255,255,255,255);
    PlayerG1.draw(420,20,106,80);
    PlayerH1.draw(420+107,20,106,80);
    ofDisableAlphaBlending();
    ofSetColor(255,125,0);
//        ofNoFill();
//        ofRect(20,20+(Y_G1/-3),212,53.333);
//        ofRect(20,286+(Y_G1/-3),212,53.333);
    ofSetColor(255,255,255);
    ofRect(420,20,213,80);
    ofEnableAlphaBlending();
    //MenuScroll--------------
    ofSetColor(255,255,255);
    ofRect(20+200, 350, 190, 100);
    ofEnableAlphaBlending();




    ofNoFill();
    ofSetColor(255, 125, 0,255);
    ofRect(xcarreA1, ycarreA1,213,160);
    ofDrawBitmapString("1",xcarreA1+10,ycarreA1+20);
    ofRect(xcarreB1, ycarreB1,213,160);
    ofDrawBitmapString("2",xcarreB1+10,ycarreB1+20);
    ofRect(xcarreC1, ycarreC1,213,160);
    ofDrawBitmapString("3",xcarreC1+10,ycarreC1+20);
    ofRect(xcarreD1, ycarreD1,213,160);
    ofDrawBitmapString("4",xcarreD1+10,ycarreD1+20);
    ofRect(xcarreE1, ycarreE1,213,160);
    ofDrawBitmapString("5",xcarreE1+10,ycarreE1+20);
    ofRect(xcarreF1, ycarreF1,213,160);
    ofDrawBitmapString("6",xcarreF1+10,ycarreF1+20);


//        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
//        ofSetColor(0,0,0,Fade_G);
//        ofFill();
//        ofRect(340,20,640,160);
//        ofDisableBlendMode();

    ofPopStyle();

//--------------------------AUDIO---------------------------
    if(bAudio)
    {
        ofPushMatrix();
        ofTranslate(420,20+217);
        ofSetColor(255,255,255);
        ofRect(0, 113, 213, 100);
        ofEnableAlphaBlending();
//    ofSetColor(255, 125, 0);
//    ofLine(0, 173, 213, 173);
        ofSetColor(150, 150, 150);
        float amplitude = 100.0f;
        for (int i = 1; i < 213; i++)
        {
            float x1 = (float)i / 213.0;
            float y1 = amplitude * audioInput[i];   //amplitude * sin( x1 * 2.0*PI );
            float x2 = (float)(i - 1) / 213.0;
            float y2 = amplitude * audioInput[i-1]; //amplitude * sin( x2 * 2.0*PI );
//        ofLine(x1 * 213.0f, -y1 + 175,
//               x2 * 213.0f, -y2 + 175);
        }
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofNoFill();
        ofCircle(125, 175, rms * 213);
        ofSetRectMode(OF_RECTMODE_CORNER);

        for (int i = 1; i < rms_values.size(); i++)
        {
            ofLine((i  ) * 213.0/25.0, -rms_values[i  ]*1000.0 + 213.0,
                   (i-1) * 213.0/25.0, -rms_values[i-1]*1000.0 + 213.0);
        }
        float average_rms = 0.0f;
        for (int i = 0; i < rms_values.size(); i++)
        {
            average_rms = average_rms + rms_values[i];
        }
        average_rms = average_rms / rms_values.size();
        float var_rms = 0.0f;
        for (int i = 0; i < rms_values.size(); i++)
        {
            var_rms = var_rms + abs(rms_values[i] - average_rms);
//         cout<<rms_values[i] - average_rms<<endl;
        }
        var_rms = var_rms / rms_values.size();
        if (rms_values.back() > (average_rms + (Sens/68.5)*var_rms))
        {

//--------------------------------------------------------



            startTime = ofGetElapsedTimeMillis();


            //--------------------------------------------------------

            if(R_Open1==1   &&  Timer>endTime)
            {
                ofxOscMessage m;
                m.setAddress("/R_Open1");
                sender.sendMessage(m);
                iR_Open1    =   ofRandom(0,3);
                fDirSize = XML.getValue("dirSize",24,0);

                if(iR_Open1 == 0 )
                {
                    Lect1 = 1;
                    Sel1 = ofRandom(1,fDirSize);

//                Sel1=33;
                }
                if(iR_Open1 == 1 )
                {
                    Lect2 = 1;
                    Sel1 = ofRandom(1,fDirSize);
//                Sel1=33;
                }
                if(iR_Open1 == 2 )
                {
                    Lect3 = 1;
                    Sel1 = ofRandom(1,fDirSize);
//                Sel1=33;
                }
                cout<<"-iR_Open1-"<<iR_Open1<<"-fDirSize-"<<fDirSize<<"-Sel1-"<<Sel1<<endl;

            }
            if(R_Open2==1   &&  Timer>endTime)
            {
                ofxOscMessage m;
                m.setAddress("/R_Open2");
                sender.sendMessage(m);
            }
            if(R_Open3==1   &&  Timer>endTime)
            {
                ofxOscMessage m;
                m.setAddress("/R_Open3");
                sender.sendMessage(m);
            }
            if(R_Open4==1   &&  Timer>endTime)
            {
                ofxOscMessage m;
                m.setAddress("/R_Open4");
                sender.sendMessage(m);
            }
            if(R_Open5==1   &&  Timer>endTime)
            {
                ofxOscMessage m;
                m.setAddress("/R_Open5");
                sender.sendMessage(m);
            }

            if(R_Open6==1  &&  Timer>endTime)
            {
                ofxOscMessage m;
                m.setAddress("/R_Open6");
                sender.sendMessage(m);
            }
            if(Lum_x6  ==1 &&  Timer>endTime)
            {
                C1  =  ofRandom(0,Rand);
                if(B1!=1)
                {
                    B1 = C1;
                    frameP2  = In;
                    cout<<"bang1---"<<C1<<endl;
                }

                C2  =  ofRandom(0,Rand);
                if(B2!=1)
                {
                    B2  =   C2;
                    frameP4  = In;
                    cout<<"bang2---"<<C2<<endl;
                }

                C3  =  ofRandom(0,Rand);
                if(B3!=1)
                {
                    B3  =   C3;
                    frameP6  = In;
                    cout<<"bang3---"<<C3<<endl;
                }
                C4  =  ofRandom(0,Rand);
                if(B4!=1)
                {
                    B4  =   C4;
                    frameP8  = In;
                    cout<<"bang4---"<<C4<<endl;
                }
                C5  =  ofRandom(0,Rand);
                if(B5!=1)
                {
                    B5  =   C5;
                    frameP10  = In;
                    cout<<"bang5---"<<C5<<endl;
                }
                C6  =  ofRandom(0,Rand);
                if(B6!=1)
                {
                    B6  =   C6;
                    frameP12  = In;
                    cout<<"bang6---"<<C6<<endl;
                }
            }

            if(Opacity  ==1 &&  Timer>endTime)
            {
                C1  =  ofRandom(0,Rand);
                if(B1!=1)
                {
                    B1 = C1;
                    frameP2  = In;
                    cout<<Opacity<<C1<<endl;
                }

                C2  =  ofRandom(0,Rand);
                if(B2!=1)
                {
                    B2  =   C2;
                    frameP4  = In;
                    cout<<"bang2---"<<C2<<endl;
                }

                C3  =  ofRandom(0,Rand);
                if(B3!=1)
                {
                    B3  =   C3;
                    frameP6  = In;
                    cout<<"bang3---"<<C3<<endl;
                }
                C4  =  ofRandom(0,Rand);
                if(B4!=1)
                {
                    B4  =   C4;
                    frameP8  = In;
                    cout<<"bang4---"<<C4<<endl;
                }
                C5  =  ofRandom(0,Rand);
                if(B5!=1)
                {
                    B5  =   C5;
                    frameP10  = In;
                    cout<<"bang5---"<<C5<<endl;
                }
                C6  =  ofRandom(0,Rand);
                if(B6!=1)
                {
                    B6  =   C6;
                    frameP12  = In;
                    cout<<"bang6---"<<C6<<endl;
                }
            }


            if(R_Lect3==1 &&  Timer>endTime)
            {
                PlayerA1.setFrame(ofRandom(TotalNumFramesA1) );
                PlayerB1.setFrame(ofRandom(TotalNumFramesB1) );
                PlayerC1.setFrame(ofRandom(TotalNumFramesC1) );
                PlayerD1.setFrame(ofRandom(TotalNumFramesC1) );
                PlayerE1.setFrame(ofRandom(TotalNumFramesC1) );
                PlayerF1.setFrame(ofRandom(TotalNumFramesC1) );


            }

            if(R_L1==1 &&  Timer>endTime)
            {
                PlayerA1.setFrame(ofRandom(TotalNumFramesA1) );
            }
            if(R_L2==1 &&  Timer>endTime)
            {
                PlayerB1.setFrame(ofRandom(TotalNumFramesB1) );
            }
            if(R_L3==1 &&  Timer>endTime)
            {
                PlayerC1.setFrame(ofRandom(TotalNumFramesC1) );
            }
            if(R_L4==1 &&  Timer>endTime)
            {
                PlayerD1.setFrame(ofRandom(TotalNumFramesD1) );
            }
            if(R_L5==1 &&  Timer>endTime)
            {
                PlayerE1.setFrame(ofRandom(TotalNumFramesE1) );
            }
            if(R_L6==1 &&  Timer>endTime)
            {
                PlayerF1.setFrame(ofRandom(TotalNumFramesF1) );
            }
            if(R_F1==1 &&  Timer>endTime)
            {
                PlayerG1.setFrame(ofRandom(TotalNumFramesG1) );
            }
            if(R_F2==1 &&  Timer>endTime)
            {
                PlayerH1.setFrame(ofRandom(TotalNumFramesH1) );
                cout<<"R_F2"<<endl;
            }

            OpaCercle   =   255;

        }
        else
        {
            OpaCercle   =   0;
        }

        ofEnableAlphaBlending();
        ofSetColor(255,125,0,OpaCercle) ;
        ofFill();
        ofCircle(125, 175, 10);
        ofDisableAlphaBlending();
        ofPopMatrix();

    }

    ofSetColor(255,125,0);
    ofNoFill();
    ofRect(xcarreG1-2,ycarreG1-2,Larg+4,Haut+4);







    ofSetColor(255,125,0) ;
    ofFill();
    ofCircle(xcarreG1-2,ycarreG1+(Haut/2), 4);
    //----------------------------------------------------------------------------SelClip
    if(bVideoGrid)
    {
        ofSetColor(255,255,255,255);
        img.draw(xPlaceImg,yPlaceImg);
        ofSetColor(255,125,0);
        ofNoFill();
        ofRect(xPlaceImg-2,yPlaceImg-2,img.getWidth()+4,img.getHeight()+4);
        ofFill();
        ofCircle(xPlaceImg-2,yPlaceImg-2, 4);

        ofEnableAlphaBlending();


        ofFill();
        if(Lect1==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(E+xPlaceImg ,F+yPlaceImg ,LargSel,4);
        ofRect(E+xPlaceImg ,F+yPlaceImg+4 ,4,HautSel-8);
        ofRect(E+xPlaceImg ,F+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(E+xPlaceImg+LargSel-4 ,F+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(E+xPlaceImg+14 ,F+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "1", E+xPlaceImg+10 ,F+yPlaceImg+20);

        ofFill();
        if(Lect4==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(Eb+xPlaceImg ,Fb+yPlaceImg ,LargSel,4);
        ofRect(Eb+xPlaceImg ,Fb+yPlaceImg+4 ,4,HautSel-8);
        ofRect(Eb+xPlaceImg ,Fb+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(Eb+xPlaceImg+LargSel-4 ,Fb+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(Eb+xPlaceImg+34 ,Fb+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "4", Eb+xPlaceImg+30 ,Fb+yPlaceImg+20);


        ofFill();
        if(Lect2==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(G+xPlaceImg ,H+yPlaceImg ,LargSel,4);
        ofRect(G+xPlaceImg ,H+yPlaceImg+4 ,4,HautSel-8);
        ofRect(G+xPlaceImg ,H+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(G+xPlaceImg+LargSel-4 ,H+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(G+xPlaceImg+14 ,H+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "2", G+xPlaceImg+10 ,H+yPlaceImg+20);

        ofFill();
        if(Lect5==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(Gb+xPlaceImg ,Hb+yPlaceImg ,LargSel,4);
        ofRect(Gb+xPlaceImg ,Hb+yPlaceImg+4 ,4,HautSel-8);
        ofRect(Gb+xPlaceImg ,Hb+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(Gb+xPlaceImg+LargSel-4 ,Hb+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(Gb+xPlaceImg+34 ,Hb+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "5", Gb+xPlaceImg+30 ,Hb+yPlaceImg+20);



        ofFill();
        if(Lect3==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(I+xPlaceImg ,J+yPlaceImg ,LargSel,4);
        ofRect(I+xPlaceImg ,J+yPlaceImg+4 ,4,HautSel-8);
        ofRect(I+xPlaceImg ,J+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(I+xPlaceImg+LargSel-4 ,J+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(I+xPlaceImg+14 ,J+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "3", I+xPlaceImg+10 ,J+yPlaceImg+20);

        ofFill();
        if(Lect6==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(Ib+xPlaceImg ,Jb+yPlaceImg ,LargSel,4);
        ofRect(Ib+xPlaceImg ,Jb+yPlaceImg+4 ,4,HautSel-8);
        ofRect(Ib+xPlaceImg ,Jb+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(Ib+xPlaceImg+LargSel-4 ,Jb+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(Ib+xPlaceImg+34 ,Jb+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "6", Ib+xPlaceImg+30 ,Jb+yPlaceImg+20);


        ofFill();
        if(Lect7==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(K+xPlaceImg ,L+yPlaceImg ,LargSel,4);
        ofRect(K+xPlaceImg ,L+yPlaceImg+4 ,4,HautSel-8);
        ofRect(K+xPlaceImg ,L+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(K+xPlaceImg+LargSel-4 ,L+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(K+xPlaceImg+14 ,L+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "7", K+xPlaceImg+10 ,L+yPlaceImg+20);


        ofFill();
        if(Lect8==1)
        {
            ofSetColor(255,125,0);
        }
        else
        {
            ofSetColor(255,255,255,170);
        }
        ofRect(M+xPlaceImg ,N+yPlaceImg ,LargSel,4);
        ofRect(M+xPlaceImg ,N+yPlaceImg+4 ,4,HautSel-8);
        ofRect(M+xPlaceImg ,N+yPlaceImg+HautSel-4 ,LargSel,4);
        ofRect(M+xPlaceImg+LargSel-4 ,N+yPlaceImg+4 ,4,HautSel-8);
        ofSetColor(40,40,40);
        ofCircle(M+xPlaceImg+14 ,N+yPlaceImg+15 ,8);
        ofSetColor(255,125,0);
        ofDrawBitmapString( "8", M+xPlaceImg+10 ,N+yPlaceImg+20);

        ofDisableAlphaBlending();

        ofSetColor(255,125,0);
        ofDrawBitmapString(movieAdress, 200,20);
        ofDrawBitmapString(XML.getValue("dirSize",""), 20,20);
        ofDrawBitmapString(ofToString(iClic), 50,20);
        ofDrawBitmapString(ofToString(iClic2), 100,20);
    }

}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)


{
    cout << "value: " <<e.widget->getName()<< endl;

    string name = e.widget->getName();
    int kind = e.widget->getKind();

    if(name == "Vol_1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
//		vol1 = slider->getScaledValue();
        cout << "Vol_1: " << slider->getScaledValue() << endl;
    }

    //--------------------------SCREEN---------------------------
    if(name == "background")
    {
        ofxUISlider *rslider = (ofxUISlider *) e.widget;
        backgroundColor = rslider->getScaledValue();
    }
    else
    {
    }
//--------------------------Player---------------------------

    if(name == "Gain_A1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Gain_A1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Cont_A1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Cont_A1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Lum_A1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Lum_A1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Op1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Op1 = slider->getScaledValue();
    }
    if(name == "Op2")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Op2 = slider->getScaledValue();
    }
    if(name == "Op3")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Op3 = slider->getScaledValue();
    }
    if(name == "Op4")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Op4 = slider->getScaledValue();
    }
    if(name == "Op5")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Op5 = slider->getScaledValue();
    }
    if(name == "Op6")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Op6 = slider->getScaledValue();
    }
    else
    {
    }

    if(name == "OpacityX6")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        OpacityX6 = slider->getScaledValue();
        ((ofxUISlider*)gui1->getWidget("Op1"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op2"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op3"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op4"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op5"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op6"))->setValue(OpacityX6);
        Op1=Op2=Op3=Op4=Op5=Op6=OpacityX6;
    }
    else
    {
    }

    if(name == "Satu_A1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Satu_A1 = slider->getScaledValue();
    }
    else
    {
    }

    if(name == "Gain_B1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Gain_B1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Cont_B1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Cont_B1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Lum_B1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Lum_B1 = slider->getScaledValue();
    }
    else
    {
    }

    if(name == "Satu_B1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Satu_B1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Gain_C1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Gain_C1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Cont_C1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Cont_C1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Lum_C1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Lum_C1 = slider->getScaledValue();
    }
    else
    {
    }



    if(name == "Satu_C1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Satu_C1 = slider->getScaledValue();
    }
    else
    {
    }

    if(name == "Lum_D1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Lum_D1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Lum_E1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Lum_E1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Lum_F1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Lum_F1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Mix_G1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Mix_G1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Cont_G1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Cont_G1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Lum_G1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Lum_G1 = slider->getScaledValue();
    }
    else
    {
    }

    if(name == "Satu_G1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Satu_G1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Y_G1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Y_G1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "Fade_G")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Fade_G = slider->getScaledValue();
    }
    else
    {
    }

    if(name == "LumX6")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        LumX6 = slider->getScaledValue();
        ((ofxUISlider*)gui1->getWidget("Lum_A1"))->setValue(LumX6);
        ((ofxUISlider*)gui1->getWidget("Lum_B1"))->setValue(LumX6);
        ((ofxUISlider*)gui1->getWidget("Lum_C1"))->setValue(LumX6);
        ((ofxUISlider*)gui1->getWidget("Lum_D1"))->setValue(LumX6);
        ((ofxUISlider*)gui1->getWidget("Lum_E1"))->setValue(LumX6);
        ((ofxUISlider*)gui1->getWidget("Lum_F1"))->setValue(LumX6);
        Lum_A1=LumX6;
        Lum_B1=LumX6;
        Lum_C1=LumX6;
        Lum_D1=LumX6;
        Lum_E1=LumX6;
        Lum_F1=LumX6;
    }
    else
    {
    }


//---------------------------
    if(e.widget->getName()  == "Sens")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Sens = slider->getScaledValue();
        cout << "Sens: " << slider->getScaledValue() << endl;
    }
    else if(e.widget->getName()  == "Rand")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Rand1 = slider->getScaledValue();
        cout << "Rand: " << slider->getScaledValue() << endl;
    }
    else if(e.widget->getName()  == "In")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        In = slider->getScaledValue();
        cout << "In: " << slider->getScaledValue() << endl;
    }
    if(e.widget->getName()  == "Out")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Out = slider->getScaledValue();
        cout << "Out: " << slider->getScaledValue() << endl;
    }
    if(e.widget->getName()  == "TimeF")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        TimeF = slider->getScaledValue();
        cout << "TimeF: " << slider->getScaledValue() << endl;
    }

    if(e.widget->getName()  == "Fade2")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Fade2 = slider->getScaledValue();
        cout << "Fade2: " << slider->getScaledValue() << endl;
    }
    else if(e.widget->getName()  == "Fade3")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        Fade3 = slider->getScaledValue();
        cout << "Fade23: " << slider->getScaledValue() << endl;
    }
    else if(e.widget->getName()  == "PAD")
    {
        ofxUI2DPad *pad = (ofxUI2DPad *) e.widget;

        cout << "value x: " << pad->getScaledValue().x << endl;
        cout << "value y: " << pad->getScaledValue().y << endl;
    }
    if(e.widget->getName()  == "B1")
    {
        ofxUIButton *button = (ofxUIButton *) e.widget;
        cout <<"ofGetFrameNum()_"<<ofGetFrameNum()<< "\n";
        if(button->getValue() == 1 )
        {
            B1  =   1;
            frameP2  = In;
            if(button->getValue() == 0 )
            {
                B1  =   0;
                frameP2  = Out;
            }
            cout << e.widget->getName()  << "\t value: " << button->getValue() << endl;


        }
    }
    if(e.widget->getName()  == "B2")
    {
        ofxUIButton *button = (ofxUIButton *) e.widget;
        cout <<"ofGetFrameNum()_"<<ofGetFrameNum()<< "\n";
        if(button->getValue() == 1 )
        {
            B2  =   1;
            frameP4  = In;
            if(button->getValue() == 0 )
            {
                B2  =   0;
                frameP4  = Out;

                cout << e.widget->getName()  << "\t value: " << button->getValue() << endl;

            }
        }
    }
    if(e.widget->getName()  == "B3")
    {
        ofxUIButton *button = (ofxUIButton *) e.widget;
        cout <<"ofGetFrameNum()_"<<ofGetFrameNum()<< "\n";
        if(button->getValue() == 1 )
        {
            B3  =   1;
            frameP6  = In;
            if(button->getValue() == 0 )
            {
                B3  =   0;
                frameP6  = Out;

                cout << e.widget->getName()  << "\t value: " << button->getValue() << endl;

            }
        }
    }
    if(e.widget->getName()  == "R_Open3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_Open3  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_Open1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_Open1  =   toggle->getValue();
    }

    if(e.widget->getName()  == "R_Lect3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_Lect3  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_Lect1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_Lect1  =   toggle->getValue();
    }

    if(e.widget->getName()  == "R_L1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_L1  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_L2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_L2  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_L3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_L3  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_L4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_L4  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_L5")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_L5  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_L6")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_L6  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_F1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_F1  =   toggle->getValue();
    }
    if(e.widget->getName()  == "R_F2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        R_F2  =   toggle->getValue();
    }


    if(e.widget->getName()  == "Lum_x6")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        Lum_x6  =   toggle->getValue();
        LumX6 = Out;

        midiOut.sendControlChange(1, 5,  toggle->getValue());
        if(Lum_x6==0);
        {
            ((ofxUISlider*)gui1->getWidget("LumX6"))->setValue(Out);
//            LumX6 = Out;
            ((ofxUISlider*)gui1->getWidget("Lum_A1"))->setValue(LumX6);
            ((ofxUISlider*)gui1->getWidget("Lum_B1"))->setValue(LumX6);
            ((ofxUISlider*)gui1->getWidget("Lum_C1"))->setValue(LumX6);
            ((ofxUISlider*)gui1->getWidget("Lum_D1"))->setValue(LumX6);
            ((ofxUISlider*)gui1->getWidget("Lum_E1"))->setValue(LumX6);
            ((ofxUISlider*)gui1->getWidget("Lum_F1"))->setValue(LumX6);

            Lum_A1=LumX6;
            Lum_B1=LumX6;
            Lum_C1=LumX6;
            Lum_D1=LumX6;
            Lum_E1=LumX6;
            Lum_F1=LumX6;

//        B1=B2=B3=B4=B5=B6=1;
//        B1=B2=B3=B4=B5=B6=0;

        }

    }
    if(e.widget->getName()  == "Lum_1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        Lum_1  =   toggle->getValue();
        midiOut.sendControlChange(1, 6,  toggle->getValue());

    }

//        ----------------------TV
    if(name == "WebCam")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        TV1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "LumTV")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        LumTV = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "OpacTV")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        OpacTV = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "F_1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        F_1 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "F_2")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        F_2 = slider->getScaledValue();
    }
    else
    {
    }
    if(name == "WebCam")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        WebCam = slider->getScaledValue();
    }
    else
    {
    }
    if(e.widget->getName() == "Cam")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            vidGrabber.setVerbose(true);
            vidGrabber.initGrabber(640,480);
            vidGrabber.setDeviceID(0);
        }
        if(toggle->getValue() ==  0)
        {
            vidGrabber.close();
        }
    }
    if(e.widget->getName() == "Opacity")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            Opacity=1;
        }
        if(toggle->getValue() ==  0)
        {
            Opacity=0;
        }
    }

    if(e.widget->getName() == "800x600")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            Larg    =   800;
            Haut    =   600;
        }
        if(toggle->getValue() ==  0)
        {
            Larg    =   640;
            Haut    =   480;
        }
    }
    if(e.widget->getName() == "VideoGrid")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            ofxOscMessage m;
            m.setAddress("/bWindow");
            sender.sendMessage(m);
        }
        else
        {

        }
    }
    if(e.widget->getName() == "Audio")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            bAudio= true;
        }
        else
        {
            bAudio= false;
        }
    }
    if(e.widget->getName() == "VideoGrid")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            bVideoGrid= true;
        }
        else
        {
            bVideoGrid= false;
        }
    }

    if(e.widget->getName() == "TimeLine")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            ofxOscMessage m;
            m.setAddress("/TimeLine");
            sender.sendMessage(m);
        }
        else
        {

        }
    }
    if(e.widget->getName() == "Warp")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            bWarp = true;
        }
        else
        {
            bWarp = false;
        }
    }
    if(e.widget->getName() == "3/6Lect")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue() ==  1)
        {
            bNbrLect = true;
        }
        else
        {
            bNbrLect = false;
        }
    }

    string path = "v/";
    ofDirectory dir(path);
    dir.listDir();
    for(int i = 0; i < dir.numFiles(); i++)
    {
        ofLogNotice(dir.getPath(i));
        if(e.widget->getName() == dir.getPath(i))
        {
            cout<<"fileName"<< dir.getOriginalDirectory()+"/.data/"+fileName <<"sDirName"<< dir.getOriginalDirectory()+"/.data/"+sDirName+".xml" <<"dossierV"<< dossierV<<endl;

            dir.listDir(e.widget->getName() );
            dossierV    =e.widget->getName();
            fDir    =e.widget->getName();
            sDirName  = fDir.getBaseName();

            fileName = sDirName+".png";
            img.loadImage(dir.getOriginalDirectory()+"/.data/"+fileName);


            dirData = dir.getOriginalDirectory()+"/.data";
            sDirName  = fDir.getBaseName();
            XML.loadFile(dir.getOriginalDirectory()+"/.data/"+sDirName+".xml");
            fDirSize = XML.getValue("dirSize",32,0);

            XmlSvg.setValue("XmlSvg:sDirName",sDirName);
            XmlSvg.setValue("XmlSvg:fDirSize",fDirSize);
            XmlSvg.setValue("XmlSvg:fileName",fileName);
            XmlSvg.saveFile("XmlSvg.xml");



        }
    }

//////////    string path = "v/";
//////////    ofDirectory dir(path);
//////////    dir.listDir();
//////////    for(int i = 0; i < dir.numFiles(); i++)
//////////    {
//////////        ofLogNotice(dir.getPath(i));
//////////        if(e.widget->getName() == dir.getPath(i))
//////////        {
//////////
//////////            dir.listDir(e.widget->getName() );
//////////            dossierV    =e.widget->getName();
//////////            fDir    =e.widget->getName();
//////////            dir.allowExt("mov");
//////////            dir.sort();
//////////                         cout << "dossierV: " <<e.widget->getName()<< endl;
//////////        }
//////////    }


}


//--------------------------------------------------------------
void testApp::audioRequested(float *buf, int size, int ch)
{

}
//--------------------------------------------------------------
void testApp::audioReceived(float *buf, int size, int ch)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        total = total + (buf[i] * buf[i]);
    }
    total = total / (float)size;
    rms = sqrt(total);
}//--------------------------------------------------------------
void testApp::exit()
{
    delete gui1;
    delete gui2;
    delete gui3;
    delete gui4;
}
//--------------------------------------------------------------
void testApp::newMidiMessage(ofxMidiMessage& msg)
{

    // make a copy of the latest message
    midiMessage = msg;







    if(midiMessage.control  ==  1)
    {
        ((ofxUIToggle*)gui2->getWidget("R_L1"))->setValue(midiMessage.value);
        ((ofxUIToggle*)gui2->getWidget("R_L2"))->setValue(midiMessage.value);
        ((ofxUIToggle*)gui2->getWidget("R_L3"))->setValue(midiMessage.value);
        ((ofxUIToggle*)gui2->getWidget("R_L4"))->setValue(midiMessage.value);
        ((ofxUIToggle*)gui2->getWidget("R_L5"))->setValue(midiMessage.value);
        ((ofxUIToggle*)gui2->getWidget("R_L6"))->setValue(midiMessage.value);

        if(midiMessage.value == 0)
        {
            R_L1=0;
            R_L2=0;
            R_L3=0;
            R_L4=0;
            R_L5=0;
            R_L6=0;
        }
        if(midiMessage.value != 0)
        {
            R_L1=1;
            R_L2=1;
            R_L3=1;
            R_L4=1;
            R_L5=1;
            R_L6=1;

        }
    }
    if(midiMessage.control  ==  2)
    {
        ((ofxUIToggle*)gui2->getWidget("R_F1"))->setValue(midiMessage.value);
        if(midiMessage.value == 0)
        {
            R_F1=0;
        }
        if(midiMessage.value != 0)
        {
            R_F1 = 1;

        }
    }
    if(midiMessage.control  ==  3)
    {
        ((ofxUIToggle*)gui2->getWidget("R_F2"))->setValue(midiMessage.value);
        if(midiMessage.value == 0)
        {
            R_F2=0;
            R_F1=0;

        }
        if(midiMessage.value != 0)
        {
            R_F1 = 1;
            R_F2 = 1;

        }
    }

    if(midiMessage.control  ==  5)
    {
        ((ofxUIToggle*)gui1->getWidget("VideoGrid"))->setValue(midiMessage.value);
        if(midiMessage.value == 0)
        {
            bVideoGrid=0;
        }
        if(midiMessage.value != 0)
        {
            bVideoGrid= 1;
        }

    }
    if(midiMessage.control  ==  6)
    {
        ((ofxUIToggle*)gui1->getWidget("Audio"))->setValue(midiMessage.value);
        if(midiMessage.value == 0)
        {
            bAudio=0;
        }

        if(midiMessage.value != 0)
        {
            bAudio = 1;

        }

    }
    if(midiMessage.control  ==  7)
    {
        ((ofxUIToggle*)gui1->getWidget("Lum_x6"))->setValue(midiMessage.value);
        if(midiMessage.value == 0)
        {
            Lum_x6=0;
        }
        if(midiMessage.value != 0)
        {
            Lum_x6 = 1;

        }

    }
    if(midiMessage.control  ==  8)
    {
        ((ofxUIToggle*)gui1->getWidget("Opacity"))->setValue(midiMessage.value);
        if(midiMessage.value == 0)
        {
            Opacity=0;
        }
        if(midiMessage.value != 0)
        {
            Opacity= 1;

        }
    }
    //--------------------------------------------------------------------------------------
    if(midiMessage.control  ==  9)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Lum_A1"))->setValue(midiMessage.value* 2.0);
        ((ofxUICircleSlider*)gui1->getWidget("Lum_B1"))->setValue(midiMessage.value* 2.0);
        ((ofxUICircleSlider*)gui1->getWidget("Lum_C1"))->setValue(midiMessage.value*2.0);
        ((ofxUICircleSlider*)gui1->getWidget("Lum_D1"))->setValue(midiMessage.value*2.0);
        ((ofxUICircleSlider*)gui1->getWidget("Lum_E1"))->setValue(midiMessage.value*2.0);
        ((ofxUICircleSlider*)gui1->getWidget("Lum_F1"))->setValue(midiMessage.value*2.0);
////                ((ofxUICircleSlider*)gui1->getWidget("Lum_G1"))->setValue(midiMessage.value*2.0);
        Lum_A1=midiMessage.value*2;
        Lum_B1=midiMessage.value*2;
        Lum_C1=midiMessage.value*2;
        Lum_D1=midiMessage.value*2;
        Lum_E1=midiMessage.value*2;
        Lum_F1=midiMessage.value*2;
        Lum_G1=midiMessage.value*2;
    }



    if(midiMessage.control  ==  10)
    {
        ((ofxUICircleSlider*)gui1->getWidget("F_1"))->setValue(midiMessage.value* 2.0);
        F_1   =  (midiMessage.value*2);
    }
    if(midiMessage.control  ==  11)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Lum_E1"))->setValue(midiMessage.value* 2.0);
        Lum_E1=midiMessage.value*2;
    }
    if(midiMessage.control  ==  12)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Lum_F1"))->setValue(midiMessage.value* 2.0);
        Lum_F1=midiMessage.value*2;
    }

    if(midiMessage.control  ==  13)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Lum_A1"))->setValue(midiMessage.value* 2.0);
        Lum_A1=midiMessage.value*2;
    }
    if(midiMessage.control  ==  14)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Lum_B1"))->setValue(midiMessage.value* 2.0);
        Lum_B1=midiMessage.value*2;
    }
    if(midiMessage.control  ==  15)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Lum_C1"))->setValue(midiMessage.value* 2.0);
        Lum_C1=midiMessage.value*2;
    }
    if(midiMessage.control  ==  16)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Lum_D1"))->setValue(midiMessage.value* 2.0);
        Lum_D1=midiMessage.value*2;
    }

//--------------------------------------------------------------------------------------------
    if(midiMessage.control  ==  17)
    {
        if(midiMessage.value == 0)
        {
//            Lect7=0;
        }
        if(midiMessage.value != 0)
        {
            Lect7=1;

        }
    }
    if(midiMessage.control  ==  18)
    {
        if(midiMessage.value == 0)
        {
//            Lect8=0;
        }
        if(midiMessage.value != 0)
        {
            Lect8=1;

        }
    }
    if(midiMessage.control  ==  19)
    {
        if(midiMessage.value == 0)
        {
        }
        if(midiMessage.value != 0)
        {

        }
    }
    if(midiMessage.control  ==  20)
    {
        if(midiMessage.value == 0)
        {
            Lect1=0;
        }
        if(midiMessage.value != 0)
        {
            Lect1=1;

        }
    }
    if(midiMessage.control  ==  21)
    {
        if(midiMessage.value == 0)
        {
//            Lect1=0;
        }
        if(midiMessage.value != 0)
        {
            bClic = true;
            iClic==1;
        }
    }
    if(midiMessage.control  ==  22)
    {
        if(midiMessage.value == 0)
        {
        }
        if(midiMessage.value != 0)
        {
            bClic2 = true;
            iClic2==1;

        }
    }
    if(midiMessage.control  ==  23)
    {
        if(midiMessage.value == 0)
        {
            Lect1=0;
        }
        if(midiMessage.value != 0)
        {
            Lect1=1;

        }
    }
    if(midiMessage.control  ==  24)
    {
        if(midiMessage.value == 0)
        {
            Lect1=0;
        }
        if(midiMessage.value != 0)
        {
            Lect1=1;

        }
    }
//--------------------------------------------------------------------------------------------
////////////    if(midiMessage.control  ==  17)
////////////    {
//////////////                ((ofxUIToggle*)gui2->getWidget("Lum_x6"))->setValue(midiMessage.value);
////////////        if(midiMessage.value == 0)
////////////        {
//////////////                    B1=0;
////////////        }
////////////        if(midiMessage.value != 0)
////////////        {
////////////
////////////            B1 = 1;
////////////            frameP2  = In;
////////////
////////////        }
////////////    }
////////////    if(midiMessage.control  ==  21)
////////////    {
//////////////                ((ofxUIToggle*)gui2->getWidget("Lum_x6"))->setValue(midiMessage.value);
////////////        if(midiMessage.value == 0)
////////////        {
//////////////                B2=0;
////////////        }
////////////        if(midiMessage.value != 0)
////////////        {
////////////
////////////            B2 = 1;
////////////            frameP4  = In;
////////////        }
////////////    }
////////////    if(midiMessage.control  == 22 )
////////////    {
////////////        if(midiMessage.value == 0)
////////////        {
////////////        }
////////////        if(midiMessage.value != 0)
////////////        {
////////////            B3 = 1;
////////////            frameP6  = In;
////////////        }
////////////    }
//////////////
////////////    if(midiMessage.control  == 23 )
////////////    {
////////////        if(midiMessage.value == 0)
////////////        {
////////////        }
////////////        if(midiMessage.value != 0)
////////////        {
////////////            B4 = 1;
////////////            frameP8  = In;
////////////        }
////////////    }
////////////    if(midiMessage.control  ==  24)
////////////    {
////////////        if(midiMessage.value == 0)
////////////        {
////////////        }
////////////        if(midiMessage.value != 0)
////////////        {
////////////            B5 = 1;
////////////            frameP10  = In;
////////////        }
////////////    }
////////////    if(midiMessage.control  ==  18)
////////////    {
////////////        if(midiMessage.value == 0)
////////////        {
////////////        }
////////////        if(midiMessage.value != 0)
////////////        {
////////////            B6 = 1;
////////////            frameP12  = In;
////////////        }
////////////    }
//////////////            if(midiMessage.control  ==  17){
//////////////                if(midiMessage.value == 0) {
//////////////                    NoOsc=0;
//////////////                }
//////////////                if(midiMessage.value != 0) {
//////////////                          NoOsc=1;
//////////////                }
//////////////            }
////////////    if(midiMessage.control  ==  19)
////////////    {
////////////        if(midiMessage.value == 0)
////////////        {
////////////
////////////        }
////////////        if(midiMessage.value != 0)
////////////        {
////////////            B1 = 1;
////////////            frameP2  = In;
////////////            B2 = 1;
////////////            frameP4  = In;
////////////            B3 = 1;
////////////            frameP6  = In;
////////////            B4 = 1;
////////////            frameP8  = In;
////////////            B5 = 1;
////////////            frameP10  = In;
////////////            B6 = 1;
////////////            frameP12  = In;
////////////        }
////////////    }
//
//////////           if(midiMessage.control  ==  3){
//////////                if(midiMessage.value == 0) {
//////////                }
//////////                if(midiMessage.value != 0) {
//////////                          B3 = 1;
//////////                    frameP6  = In;
//////////                }
//////////            }
////////////
//////////           if(midiMessage.control  ==  3){
//////////                if(midiMessage.value == 0) {
//////////                }
//////////                if(midiMessage.value != 0) {
//////////                          B3 = 1;
//////////                    frameP6  = In;
//////////                }
//////////            }
////////////

    if(midiMessage.control  ==  29)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Fade_G"))->setValue(midiMessage.value* 2.0);
        Fade_G   =  (midiMessage.value*-2)+255;
    }

    if(midiMessage.control  ==  30)
    {
        ((ofxUICircleSlider*)gui1->getWidget("OpacityX6"))->setValue(midiMessage.value* 2.0);
        OpacityX6   =  midiMessage.value*2;
        ((ofxUISlider*)gui1->getWidget("Op1"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op2"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op3"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op4"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op5"))->setValue(OpacityX6);
        ((ofxUISlider*)gui1->getWidget("Op6"))->setValue(OpacityX6);
        Op1=Op2=Op3=Op4=Op5=Op6=OpacityX6;

    }
    if(midiMessage.control  ==  32)
    {
        ((ofxUICircleSlider*)gui1->getWidget("Cont_G1"))->setValue(midiMessage.value* 2.0);
        Cont_G1 =    midiMessage.value* 2.0;
    }



    if(midiMessage.control  ==  25)
    {
        ((ofxUICircleSlider*)gui2->getWidget("Sens"))->setValue(midiMessage.value* 2.0);
        Sens =    midiMessage.value* 2.0;
    }
    if(midiMessage.control  ==  26)
    {
        ((ofxUICircleSlider*)gui2->getWidget("In"))->setValue(midiMessage.value* 2.0);
        In =    midiMessage.value* 2.0;
    }
    if(midiMessage.control  ==  27)
    {
        ((ofxUICircleSlider*)gui2->getWidget("Out"))->setValue(midiMessage.value* 2.0);
        Out =    midiMessage.value* 2.0;
    }
    if(midiMessage.control  ==  28)
    {
        ((ofxUICircleSlider*)gui2->getWidget("TimeF"))->setValue ((( (midiMessage.value* -2.0)+255)/4)+1);
        TimeF =   (( (midiMessage.value* -2.0)+255)/4)+1;
    }

}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key)
    {
    case 'u':
    {
        gui1->toggleVisible();
        gui2->toggleVisible();
    }
    break;

    case 'F':
    {
        ofToggleFullscreen();
    }
    break;



//    case 'p':// press 'l' to load the warp coordinates from an XML file.
//        ofSetWindowPosition(-20,50);
////        ofSetWindowShape(200,768);
////        ofSetWindowPosition(1500,100);
//        ofSetWindowShape(ofGetScreenWidth()+20,2800);
////        ofSetWindowShape(ofGetScreenWidth(),ofGetScreenHeight()-1330);
//        cout <<ofGetScreenWidth()<<ofGetScreenHeight()<<endl;

    break;
    case 'a':
        blendMode = OF_BLENDMODE_ALPHA;
        break;
    case 'z':
        blendMode = OF_BLENDMODE_ADD;
        break;
    case 'e':
        blendMode = OF_BLENDMODE_MULTIPLY;
        break;
    case 'r':
        blendMode = OF_BLENDMODE_SUBTRACT;
        break;
    case 't':
        blendMode = OF_BLENDMODE_SCREEN;
        break;
    case 'y':
        blendMode = OF_BLENDMODE_DISABLED;
        break;
    case 'w': // press 's' to save the warp coordinates to an XML file.
        if(activateA1 == 0   )
        {
            warperPlayerA1.activate();
            warperTV1.activate();
            activateA1  =  1;
        }
        else
        {
            activateA1  =  0;
            warperPlayerA1.deactivate();
            warperTV1.deactivate();
        }
        break;
    case 'x': // press 's' to save the warp coordinates to an XML file.
        if(activateB1 == 0   )
        {
            warperPlayerB1.activate();
            warperTV2.activate();
            activateB1  =  1;
        }
        else
        {
            activateB1  =  0;
            warperPlayerB1.deactivate();
            warperTV2.deactivate();
        }
        break;
    case 'c': // press 's' to save the warp coordinates to an XML file.
        if(activateC1 == 0   )
        {
            warperPlayerC1.activate();
            warperTV3.activate();

            activateC1  =  1;
        }
        else
        {
            activateC1  = 0;
            warperPlayerC1.deactivate();
            warperTV3.deactivate();
        }
        break;
    case 'v': // press 's' to save the warp coordinates to an XML file.
        if(activateD1 == 0   )
        {
            warperPlayerD1.activate();
            warperTV4.activate();
            activateD1  =  1;
        }
        else
        {
            activateD1  = 0;
            warperPlayerD1.deactivate();
            warperTV4.deactivate();
        }
        break;
    case 'b': // press 's' to save the warp coordinates to an XML file.
        if(activateE1 == 0   )
        {
            warperPlayerE1.activate();
            warperTV5.activate();
            activateE1  =  1;
        }
        else
        {
            activateE1  = 0;
            warperPlayerE1.deactivate();
            warperTV5.deactivate();
        }
        break;
    case 'n': // press 's' to save the warp coordinates to an XML file.
        if(activateF1 == 0   )
        {
            warperPlayerF1.activate();
            warperTV6.activate();
            activateF1  =  1;
        }
        else
        {
            activateF1  = 0;
            warperPlayerF1.deactivate();
            warperTV6.deactivate();
        }
        break;
    case 'S': // press 's' to save the warp coordinates to an XML file.
        warperPlayerA1.save("warpConfigA1.xml");
        warperPlayerB1.save("warpConfigB1.xml");
        warperPlayerC1.save("warpConfigC1.xml");
        warperPlayerD1.save("warpConfigD1.xml");
        warperPlayerE1.save("warpConfigE1.xml");
        warperPlayerF1.save("warpConfigF1.xml");
        gui1->saveSettings("GUI1/guiSettings.xml");
//        XML.setValue("XML:xcarreA1", xcarreA1);
//        XML.setValue("XML:ycarreA1", ycarreA1);
        XML.saveFile("XML.xml");
        break;
    case 'D': // press 's' to save the warp coordinates to an XML file.
        warperPlayerA1.save("warpConfig2A1.xml");
        warperPlayerB1.save("warpConfig2B1.xml");
        warperPlayerC1.save("warpConfig2C1.xml");
        warperPlayerD1.save("warpConfig2D1.xml");
        warperPlayerE1.save("warpConfig2E1.xml");
        warperPlayerF1.save("warpConfig2F1.xml");
        gui1->saveSettings("GUI1/guiSettings.xml");
//        XML.setValue("XML:xcarreA1", xcarreA1);
//        XML.setValue("XML:ycarreA1", ycarreA1);
        XML.saveFile("XML.xml");
        break;
    case 'L':// press 'l' to load the warp coordinates from an XML file.
        warperPlayerA1.load("warpConfigA1.xml");
        warperPlayerB1.load("warpConfigB1.xml");
        warperPlayerC1.load("warpConfigC1.xml");
        warperPlayerD1.load("warpConfigD1.xml");
        warperPlayerE1.load("warpConfigE1.xml");
        warperPlayerF1.load("warpConfigF1.xml");
        warperTV1.load("warpConfigA1.xml");
        warperTV2.load("warpConfigB1.xml");
        warperTV3.load("warpConfigC1.xml");
        warperTV4.load("warpConfigD1.xml");
        warperTV5.load("warpConfigE1.xml");
        warperTV6.load("warpConfigF1.xml");
        gui2->loadSettings("GUI2/guiSettings.xml");
//        xcarreA1 =  XML.getValue("XML:xcarreA1", 1);
//        ycarreA1 =  XML.getValue("XML:ycarreA1", 1);
        break;
    case 'M':// press 'l' to load the warp coordinates from an XML file.
        warperPlayerA1.load("warpConfig2A1.xml");
        warperPlayerB1.load("warpConfig2B1.xml");
        warperPlayerC1.load("warpConfig2C1.xml");
        warperPlayerD1.load("warpConfig2D1.xml");
        warperPlayerE1.load("warpConfig2E1.xml");
        warperPlayerF1.load("warpConfig2F1.xml");
        warperTV1.load("warpConfig2A1.xml");
        warperTV2.load("warpConfig2B1.xml");
        warperTV3.load("warpConfig2C1.xml");
        warperTV4.load("warpConfig2D1.xml");
        warperTV5.load("warpConfig2E1.xml");
        warperTV6.load("warpConfig2F1.xml");
        gui2->loadSettings("GUI2/guiSettings.xml");
//        xcarreA1 =  XML.getValue("XML:xcarreA1", 1);
//        ycarreA1 =  XML.getValue("XML:ycarreA1", 1);
        break;

//        case 'p':// press 'l' to load the warp coordinates from an XML file.
//        ofSetWindowPosition(-5,300);
//        ofSetWindowShape(1024,768);
//        ofSetWindowShape(ofGetScreenWidth(),ofGetScreenHeight()-300);
//        	cout <<ofGetScreenWidth()<<ofGetScreenHeight()<<endl;
//
//        break;


    default:
        break;
    }
//////    if( key == 'g' )
//////    {
//////        carreA1= 1;
//////    }
//////    else
//////    {
//////        carreA1= 0;
//////    }
//////    if( key == 'h' )
//////    {
//////        carreB1= 1;
//////    }
//////    else
//////    {
//////        carreB1= 0;
//////    }
//////    if( key == 'j' )
//////    {
//////        carreC1= 1;
//////    }
//////    else
//////    {
//////        carreC1= 0;
//////    }
//////    if( key == 'k' )
//////    {
//////        carreD1= 1;
//////    }
//////    else
//////    {
//////        carreD1= 0;
//////    }
//////    if( key == 'l' )
//////    {
//////        carreE1= 1;
//////    }
//////    else
//////    {
//////        carreE1= 0;
//////    }
//////    if( key == 'm' )
//////    {
//////        carreF1= 1;
//////    }
//////    else
//////    {
//////        carreF1= 0;
//////    }
////////    	if( key == 'm' ){
////////    	    XML.loadFile("mySettings.xml");
////////        	movieAdress = XML.getValue("ajout:adres",Adress,5);
////////			cout<<"movieAdress"<<movieAdress<<"Adress"<<XML.getValue("ajout:adres",Adress,5)<<endl;
////////
////////
////////
////////
////////    	}
//    if( key == 'q' )
//    {
//        if(!bPosition)
//        {
//            bPosition = true;
//        }
//        else
//        {
//            bPosition = false;
//        }
//    }
    if( key == ' ' )
    {
        fOpen1 =   fOpen1+1;
        fDirSize = XML.getValue("dirSize",24,0);
        if(fOpen1 >=fDirSize)
        {
            fOpen1 = 0;
        }

        PlayerH1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,fOpen1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerH1.loadMovie(movieAdress);
        PlayerH1.play();
        TotalNumFramesH1 = PlayerH1.getTotalNumFrames();
        PlayerH1.setLoopState(OF_LOOP_NORMAL);

    }

    if ((key =='1')   ||(key =='9') )
    {
        Lect1 = 1;
        cout<<Sel1<<Lect1<<endl;

    }
    else
    {
        Lect1 = 0;
    }
    if ((key =='2') ||(key =='9') )
    {
        Lect2 = 1;
        cout<<Sel1<<Lect2<<endl;
    }
    else
    {
        Lect2 = 0;

    }
    if ((key =='3')||(key =='9')  )
    {
        Lect3 = 1;
        cout<<Sel1<<Lect3<<endl;
    }
    else
    {
        Lect3 = 0;
    }
    if ((key =='4') ||(key =='9'))
    {
        Lect4 = 1;
    }
    else
    {
        Lect4 = 0;
    }
    if ((key =='5') ||(key =='9')  )
    {
        Lect5 = 1;
    }
    else
    {
        Lect5 = 0;
    }
    if ((key =='6') ||(key =='9')  )
    {
        Lect6 = 1;
    }
    else
    {
        Lect6 = 0;
    }
    if ((key =='7') ||(key =='9')  )
    {
        Lect7 = 1;
    }
    else
    {
        Lect7 = 0;
    }
    if ((key =='8') ||(key =='9')  )
    {
        Lect8 = 1;
    }
    else
    {
        Lect8 = 0;
    }
    if ((key =='h')   )
    {
        bClic = true;
        iClic==1;
    }
    else
    {
        bClic = false;
        iClic==0;
    }
    if ((key =='j')   )
    {
        bClic2 = true;
        iClic2==1;

    }
    else
    {
        bClic2 = false;
        iClic2==0;
    }

    if ((key =='0')   )
    {


        movieAdress = XML.getValue("ajout:adres",Adress,0);
        cout<<"movieAdress"<<movieAdress<<endl;

        PlayerA1.loadMovie(movieAdress);
        PlayerB1.loadMovie(movieAdress);
        PlayerC1.loadMovie(movieAdress);
        PlayerD1.loadMovie(movieAdress);
        PlayerE1.loadMovie(movieAdress);
        PlayerF1.loadMovie(movieAdress);
        PlayerG1.loadMovie(movieAdress);
        PlayerH1.loadMovie(movieAdress);

        PlayerA1.play();
        PlayerC1.play();
        PlayerB1.play();
        PlayerC1.play();
        PlayerD1.play();
        PlayerE1.play();
        PlayerF1.play();
        PlayerG1.play();
        PlayerH1.play();

        PlayerA1.setLoopState(OF_LOOP_NORMAL);
        PlayerC1.setLoopState(OF_LOOP_NORMAL);
        PlayerB1.setLoopState(OF_LOOP_NORMAL);
        PlayerC1.setLoopState(OF_LOOP_NORMAL);
        PlayerD1.setLoopState(OF_LOOP_NORMAL);
        PlayerE1.setLoopState(OF_LOOP_NORMAL);
        PlayerF1.setLoopState(OF_LOOP_NORMAL);
        PlayerG1.setLoopState(OF_LOOP_NORMAL);
        PlayerH1.setLoopState(OF_LOOP_NORMAL);



        TotalNumFramesA1 = PlayerA1.getTotalNumFrames();
        TotalNumFramesB1 = PlayerB1.getTotalNumFrames();
        TotalNumFramesC1 = PlayerC1.getTotalNumFrames();
        TotalNumFramesD1 = PlayerD1.getTotalNumFrames();
        TotalNumFramesE1 = PlayerE1.getTotalNumFrames();
        TotalNumFramesF1 = PlayerF1.getTotalNumFrames();
        TotalNumFramesG1 = PlayerG1.getTotalNumFrames();
        TotalNumFramesH1 = PlayerH1.getTotalNumFrames();

    }
    else
    {

    }
//    if ((key =='o')   )
//    {
//         midiIn.openPort(2);
//    }
//    else
//    {
//    }
//    if ((key =='i')   )
//    {
//         midiIn.openPort(1);
//    }
//    else
//    {
//    }


//----------------------

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

    carreA1= 0;
    carreB1= 0;
    carreC1= 0;
    carreD1= 0;
    carreE1= 0;
    carreF1= 0;
    carreG1= 0;
    PlaceImg= 0;

//    PositionWarp.saveFile("warpConfigA1.xml");
//    warperPlayerA1.load("warpConfigA1.xml");

    if ((key =='0')   )
    {


    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

    if(bPosition)
    {
        positionX=x;
        positionY=y;
        PositionWarp.clear();
        PositionWarp.addTag("corners");
        PositionWarp.pushTag("corners");
        PositionWarp.setValue("corner:x",positionX/ofGetWidth());
        PositionWarp.setValue("y",positionY/ofGetHeight());
//            PositionWarp.addTag("corner");
        PositionWarp.addValue("x",(positionX/ofGetWidth())+0.1);
        PositionWarp.addValue("y",(positionY/ofGetHeight())+0.0);
//                PositionWarp.popTag();
        PositionWarp.addTag("corner");
        PositionWarp.addValue("x",(positionX/ofGetWidth())+0.1);
        PositionWarp.addValue("y",(positionY/ofGetHeight())+0.05);
//           PositionWarp.addTag("corner");
        PositionWarp.addValue("x",(positionX/ofGetWidth())+0.0);
        PositionWarp.addValue("y",(positionY/ofGetHeight())+0.05);
        PositionWarp.popTag(); //pop position


        //    bPosition   =   false;
    }

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    if(carreA1== 1)
    {
        xcarreA1  =x;
        ycarreA1 =y;
    }
    if(carreB1== 1)
    {
        xcarreB1  =x;
        ycarreB1 =y;
    }
    if(carreC1== 1)
    {
        xcarreC1  =x;
        ycarreC1 =y;
    }
    if(carreD1== 1)
    {
        xcarreD1  =x;
        ycarreD1 =y;
    }
    if(carreE1== 1)
    {
        xcarreE1  =x;
        ycarreE1 =y;
    }
    if(carreF1== 1)
    {
        xcarreF1  =x;
        ycarreF1 =y;
    }
    if(carreG1== 1)
    {
        xcarreG1  =x;
        ycarreG1 =y-(Haut/2);
    }
    if(PlaceImg== 1)
    {
        xPlaceImg  =x;
        yPlaceImg =y;
    }

//    carreA1=0;


}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    if(bClic)
    {
        iClic   = iClic+1;
    }
    if(bClic2)
    {
        iClic2   = iClic2+1;
    }


//    {


    if(x>=xcarreA1-10 &&    x<=xcarreA1+10 && y>=ycarreA1-10 &&    y<=ycarreA1+10 )
    {
        carreA1= 1;
    }
    else
    {
        carreA1= 0;

    }
    if(x>=xcarreB1-10 &&    x<=xcarreB1+10 && y>=ycarreB1-10 &&    y<=ycarreB1+10 )
    {
        carreB1= 1;
    }
    else
    {
        carreB1= 0;

    }
    if(x>=xcarreC1-10 &&    x<=xcarreC1+10 && y>=ycarreC1-10 &&    y<=ycarreC1+10 )
    {
        carreC1= 1;
    }
    else
    {
        carreC1= 0;

    }
    if(x>=xcarreD1-10 &&    x<=xcarreD1+10 && y>=ycarreD1-10 &&    y<=ycarreD1+10 )
    {
        carreD1= 1;
    }
    else
    {
        carreD1= 0;

    }
    if(x>=xcarreE1-10 &&    x<=xcarreE1+10 && y>=ycarreE1-10 &&    y<=ycarreE1+10 )
    {
        carreE1= 1;
    }
    else
    {
        carreE1= 0;

    }
    if(x>=xcarreF1-20 &&    x<=xcarreF1+10 && y>=ycarreF1-10 &&    y<=ycarreF1+10 )
    {
        carreF1= 1;
    }
    else
    {
        carreF1= 0;

    }
    if(x>=xcarreG1-40 &&    x<=xcarreG1+0 && y>=ycarreG1+(Haut/2)-10 &&    y<=ycarreG1+(Haut/2)+10 )
    {
        carreG1= 1;
    }
    else
    {
        carreG1= 0;

    }
    if(x>=xPlaceImg-10 &&    x<=xPlaceImg+10 && y>=yPlaceImg-10 &&    y<=yPlaceImg+10 )
    {
        PlaceImg= 1;
    }
    else
    {
        PlaceImg= 0;
    }

    //------------------------------------------------------------------------Selection
    A  =   0;
    B  =   1;
    C  =   0;
    D  =   1;
    if((x >xPlaceImg+ A*LargSel ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        Sel1 =   1;
        cout<<Sel1<<endl;

    }

    A  =   1;
    B  =   2;
    C  =   0;
    D  =   1;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   2;
    }

    A  =   2;
    B  =   3;
    C  =   0;
    D  =   1;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   3;
    }
    A  =   3;
    B  =   4;
    C  =   0;
    D  =   1;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   4;
    }
    A  =   4;
    B  =   5;
    C  =   0;
    D  =   1;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   5;
    }
    A  =   5;
    B  =   6;
    C  =   0;
    D  =   1;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   6;
    }
    A  =   6;
    B  =   7;
    C  =   0;
    D  =   1;;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   7;
    }
    A  =   7;
    B  =   8;
    C  =   0;
    D  =   1;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   8;
    }
    A  =   0;
    B  =   1;
    C  =   1;
    D  =   2;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   9;
    }
    A  =   1;
    B  =   2;
    C  =   1;
    D  =   2;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   10;
    }

    A  =   2;
    B  =   3;
    C  =   1;
    D  =   2;
    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        Sel1 =   11;
        cout<<Sel1<<endl;
    }

    A  =   3;
    B  =   4;
    C  =   1;
    D  =   2;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   12;
    }

    A  =   4;
    B  =   5;
    C  =   1;
    D  =   2;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   13;
    }
    A  =   5;
    B  =   6;
    C  =   1;
    D  =   2;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   14;
    }
    A  =   6;
    B  =   7;
    C  =   1;
    D  =   2;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   15;
    }
    A  =   7;
    B  =   8;
    C  =   1;
    D  =   2;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 = 16;
    }
    //---------------------
    A  =   0;
    B  =   1;
    C  =   2;
    D  =   3;
    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        Sel1 =   17;
        cout<<Sel1<<endl;
    }

    A  =   1;
    B  =   2;
    C  =   2;
    D  =   3;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   18;
    }

    A  =   2;
    B  =   3;
    C  =   2;
    D  =   3;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   19;
    }
    A  =   3;
    B  =   4;
    C  =   2;
    D  =   3;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   20;
    }
    A  =   4;
    B  =   5;
    C  =   2;
    D  =   3;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   21;
    }
    A  =   5;
    B  =   6;
    C  =   2;
    D  =   3;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   22;
    }
    A  =   6;
    B  =   7;
    C  =   2;
    D  =   3;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   23;
    }
    A  =   7;
    B  =   8;
    C  =   2;
    D  =   3;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   24;
    }
    A  =   0;
    B  =   1;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   25;
    }
    A  =   1;
    B  =   2;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   26;
    }

    A  =   2;
    B  =   3;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        Sel1 =   27;
        cout<<Sel1<<endl;
    }

    A  =   3;
    B  =   4;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   28;
    }

    A  =   4;
    B  =   5;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   29;
    }
    A  =   5;
    B  =   6;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   30;
    }
    A  =   6;
    B  =   7;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =   31;
    }
    A  =   7;
    B  =   8;
    C  =   3;
    D  =   4;

    if((x > xPlaceImg+ A*LargSel  ) && (x < xPlaceImg+B*LargSel  ) &&  (y > yPlaceImg+C*HautSel  ) && (y < yPlaceImg+D*HautSel  ))
    {
        cout<<Sel1<<endl;
        Sel1 =  32;
    }

//    }


//    if(Lect1==1 && Sel1 <=fDirSize )
//    {
////        Lect1=0;
//        PlayerA1.closeMovie();
//        PlayerD1.closeMovie();
//        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
//
//        cout<<"movieAdress"<<movieAdress<<endl;
//        PlayerA1.loadMovie(movieAdress);
//        PlayerA1.play();
//        TotalNumFramesA1 = PlayerA1.getTotalNumFrames();
//        PlayerA1.setLoopState(OF_LOOP_NORMAL);
//
//
//            cout<<"movieAdress2"<<movieAdress<<endl;
//            PlayerD1.loadMovie(movieAdress);
//            PlayerD1.play();
//            TotalNumFramesD1 = PlayerD1.getTotalNumFrames();
//            PlayerD1.setLoopState(OF_LOOP_NORMAL);
//
//    }



    if(iClic==1 && Sel1 <=fDirSize )
    {
        Lect1=1;
        PlayerA1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerA1.loadMovie(movieAdress);
        PlayerA1.play();
        TotalNumFramesA1 = PlayerA1.getTotalNumFrames();
        PlayerA1.setLoopState(OF_LOOP_NORMAL);

        XmlSvg.setValue("XmlSvg:PlayerA1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");



    }
    if(iClic==2 && Sel1 <=fDirSize )
    {
        Lect1=0;
        Lect2=1;
        PlayerB1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerB1.loadMovie(movieAdress);
        PlayerB1.play();
        TotalNumFramesB1 = PlayerB1.getTotalNumFrames();
        PlayerB1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerB1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");


    }
    if(iClic==3 && Sel1 <=fDirSize )
    {

        Lect2=0;
        Lect3=1;
        PlayerC1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerC1.loadMovie(movieAdress);
        PlayerC1.play();
        TotalNumFramesC1 = PlayerC1.getTotalNumFrames();
        PlayerC1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerC1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");


    }




    cout<<"iClic :"<<iClic<<"bClic :"<<bClic<<"Sel1 :"<<Sel1<<endl;
//    if(iClic==4)
//    {
//        iClic =0;
//        Lect3=0;
//        bClic = false;
//    }
    //-------------------------------------------------------------------------------------
    if(iClic2==1 && Sel1 <=fDirSize )
    {
        Lect4=1;
        PlayerD1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerD1.loadMovie(movieAdress);
        PlayerD1.play();
        TotalNumFramesD1 = PlayerD1.getTotalNumFrames();
        PlayerD1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerD1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");


    }
    if(iClic2==2 && Sel1 <=fDirSize )
    {
        Lect4=0;
        Lect5=1;
        PlayerE1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerE1.loadMovie(movieAdress);
        PlayerE1.play();
        TotalNumFramesE1 = PlayerE1.getTotalNumFrames();
        PlayerE1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerE1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");


    }
    if(iClic2==3 && Sel1 <=fDirSize )
    {

        Lect5=0;
        Lect6=1;
        PlayerF1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerF1.loadMovie(movieAdress);
        PlayerF1.play();
        TotalNumFramesF1 = PlayerF1.getTotalNumFrames();
        PlayerF1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerF1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");


    }



    //--------------------------------------------------
    if(Lect1==1 && Sel1 <=fDirSize &&  iClic==0)
    {

//        PlayerA1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerA1.loadMovie(movieAdress);
        PlayerA1.play();
        TotalNumFramesA1 = PlayerA1.getTotalNumFrames();
        PlayerA1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerA1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");
    }
    if(Lect2==1 && Sel1 <=fDirSize &&  iClic==0)
    {

        PlayerB1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerB1.loadMovie(movieAdress);
        PlayerB1.play();
        TotalNumFramesB1 = PlayerB1.getTotalNumFrames();
        PlayerB1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerB1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");



    }
    if(Lect3==1 && Sel1 <=fDirSize &&  iClic==0)
    {

        PlayerC1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerC1.loadMovie(movieAdress);
        PlayerC1.play();
        TotalNumFramesC1 = PlayerC1.getTotalNumFrames();
        PlayerC1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerC1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");

    }
    //-------------------------------------------------------------
    if(Lect4==1 && Sel1 <=fDirSize &&  iClic2==0)
    {

        PlayerD1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerD1.loadMovie(movieAdress);
        PlayerD1.play();
        TotalNumFramesD1 = PlayerD1.getTotalNumFrames();
        PlayerD1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerD1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");


    }
    if(Lect5==1 && Sel1 <=fDirSize &&  iClic2==0)
    {

        PlayerE1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerE1.loadMovie(movieAdress);
        PlayerE1.play();
        TotalNumFramesE1 = PlayerE1.getTotalNumFrames();
        PlayerE1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerE1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");


    }
    if(Lect6==1 && Sel1 <=fDirSize &&  iClic2==0)
    {
        PlayerF1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerF1.loadMovie(movieAdress);
        PlayerF1.play();
        TotalNumFramesF1 = PlayerF1.getTotalNumFrames();
        PlayerF1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerF1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");

    }
    //----------------------------------------------------
    if(Lect7==1 && Sel1 <=fDirSize )
    {


        PlayerG1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerG1.loadMovie(movieAdress);
        PlayerG1.play();
        TotalNumFramesG1 = PlayerG1.getTotalNumFrames();
        PlayerG1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerG1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");
    }
    if(Lect8==1 && Sel1 <=fDirSize )
    {


        PlayerH1.closeMovie();
        movieAdress = XML.getValue("ajout:adres",Adress,Sel1-1);
        cout<<"movieAdress"<<movieAdress<<endl;
        PlayerH1.loadMovie(movieAdress);
        PlayerH1.play();
        TotalNumFramesH1 = PlayerH1.getTotalNumFrames();
        PlayerH1.setLoopState(OF_LOOP_NORMAL);
        XmlSvg.setValue("XmlSvg:PlayerH1",movieAdress);
        XmlSvg.saveFile("XmlSvg.xml");
    }



//--------------------------------------------------------------------------------------
    if((Sel1==1) && (Lect1==1) )
    {
        E=0;
        F=0;

    }
    if((Sel1==2)&& (Lect1==1) )
    {
        E=LargSel;
        F=0;
    }
    if((Sel1==3)&& (Lect1==1) )
    {
        E=2*LargSel;
        F=0;
    }
    if((Sel1==4)&& (Lect1==1) )
    {
        E=3*LargSel;
        F=0;
    }
    if((Sel1==5)&& (Lect1==1) )
    {
        E=4*LargSel;
        F=0;
    }
    if((Sel1==6)&& (Lect1==1) )
    {
        E=5*LargSel;
        F=0;
    }
    if((Sel1==7)&& (Lect1==1) )
    {
        E=6*LargSel;
        F=0;
    }
    if((Sel1==8)&& (Lect1==1) )
    {
        E=7*LargSel;
        F=0;
    }
    if((Sel1==9)&& (Lect1==1) )
    {
        E=0;
        F=HautSel;
    }
    if((Sel1==10)&& (Lect1==1) )
    {
        E=LargSel;
        F=HautSel;
    }
    if((Sel1==11)&& (Lect1==1) )
    {
        E=2*LargSel;
        F=HautSel;
    }
    if((Sel1==12)&& (Lect1==1) )
    {
        E=3*LargSel;
        F=HautSel;
    }
    if((Sel1==13)&& (Lect1==1) )
    {
        E=4*LargSel;
        F=HautSel;
    }
    if((Sel1==14)&& (Lect1==1) )
    {
        E=5*LargSel;
        F=HautSel;
    }
    if((Sel1==15)&& (Lect1==1) )
    {
        E=6*LargSel;
        F=HautSel;
    }
    if((Sel1==16)&& (Lect1==1) )
    {
        E=7*LargSel;
        F=HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect1==1))
    {
        E=0;
        F=2*HautSel;

    }
    if((Sel1==18)&& (Lect1==1) )
    {
        E=LargSel;
        F=2*HautSel;
    }
    if((Sel1==19)&& (Lect1==1) )
    {
        E=2*LargSel;
        F=2*HautSel;
    }
    if((Sel1==20)&& (Lect1==1) )
    {
        E=3*LargSel;
        F=2*HautSel;
    }
    if((Sel1==21)&& (Lect1==1) )
    {
        E=4*LargSel;
        F=2*HautSel;
    }
    if((Sel1==22)&& (Lect1==1) )
    {
        E=5*LargSel;
        F=2*HautSel;
    }
    if((Sel1==23)&& (Lect1==1) )
    {
        E=6*LargSel;
        F=2*HautSel;
    }
    if((Sel1==24)&& (Lect1==1) )
    {
        E=7*LargSel;
        F=2*HautSel;
    }
    if((Sel1==25)&& (Lect1==1) )
    {
        E=0;
        F=3*HautSel;
    }
    if((Sel1==26)&& (Lect1==1) )
    {
        E=LargSel;
        F=3*HautSel;
    }
    if((Sel1==27)&& (Lect1==1) )
    {
        E=2*LargSel;
        F=3*HautSel;
    }
    if((Sel1==28)&& (Lect1==1) )
    {
        E=3*LargSel;
        F=3*HautSel;
    }
    if((Sel1==29)&& (Lect1==1) )
    {
        E=4*LargSel;
        F=3*HautSel;
    }
    if((Sel1==30)&& (Lect1==1) )
    {
        E=5*LargSel;
        F=3*HautSel;
    }
    if((Sel1==31)&& (Lect1==1) )
    {
        E=6*LargSel;
        F=3*HautSel;
    }
    if((Sel1==32)&& (Lect1==1) )
    {
        E=7*LargSel;
        F=3*HautSel;
    }

    //--------------------------------------------------------------------------------------
    if((Sel1==1) && (Lect4==1) )
    {
        Eb=0;
        Fb=0;

    }
    if((Sel1==2)&& (Lect4==1) )
    {
        Eb=LargSel;
        Fb=0;
    }
    if((Sel1==3)&& (Lect4==1) )
    {
        Eb=2*LargSel;
        Fb=0;
    }
    if((Sel1==4)&& (Lect4==1) )
    {
        Eb=3*LargSel;
        Fb=0;
    }
    if((Sel1==5)&& (Lect4==1) )
    {
        Eb=4*LargSel;
        Fb=0;
    }
    if((Sel1==6)&& (Lect4==1) )
    {
        Eb=5*LargSel;
        Fb=0;
    }
    if((Sel1==7)&& (Lect4==1) )
    {
        Eb=6*LargSel;
        Fb=0;
    }
    if((Sel1==8)&& (Lect4==1) )
    {
        Eb=7*LargSel;
        Fb=0;
    }
    if((Sel1==9)&& (Lect4==1) )
    {
        Eb=0;
        Fb=HautSel;
    }
    if((Sel1==10)&& (Lect4==1) )
    {
        Eb=LargSel;
        Fb=HautSel;
    }
    if((Sel1==11)&& (Lect4==1) )
    {
        Eb=2*LargSel;
        Fb=HautSel;
    }
    if((Sel1==12)&& (Lect4==1) )
    {
        Eb=3*LargSel;
        Fb=HautSel;
    }
    if((Sel1==13)&& (Lect4==1) )
    {
        Eb=4*LargSel;
        Fb=HautSel;
    }
    if((Sel1==14)&& (Lect4==1) )
    {
        Eb=5*LargSel;
        Fb=HautSel;
    }
    if((Sel1==15)&& (Lect4==1) )
    {
        Eb=6*LargSel;
        Fb=HautSel;
    }
    if((Sel1==16)&& (Lect4==1) )
    {
        Eb=7*LargSel;
        Fb=HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect4==1))
    {
        Eb=0;
        Fb=2*HautSel;

    }
    if((Sel1==18)&& (Lect4==1) )
    {
        Eb=LargSel;
        Fb=2*HautSel;
    }
    if((Sel1==19)&& (Lect4==1) )
    {
        Eb=2*LargSel;
        Fb=2*HautSel;
    }
    if((Sel1==20)&& (Lect4==1) )
    {
        Eb=3*LargSel;
        Fb=2*HautSel;
    }
    if((Sel1==21)&& (Lect4==1) )
    {
        Eb=4*LargSel;
        Fb=2*HautSel;
    }
    if((Sel1==22)&& (Lect4==1) )
    {
        Eb=5*LargSel;
        Fb=2*HautSel;
    }
    if((Sel1==23)&& (Lect4==1) )
    {
        Eb=6*LargSel;
        Fb=2*HautSel;
    }
    if((Sel1==24)&& (Lect4==1) )
    {
        Eb=7*LargSel;
        Fb=2*HautSel;
    }
    if((Sel1==25)&& (Lect4==1) )
    {
        Eb=0;
        Fb=3*HautSel;
    }
    if((Sel1==26)&& (Lect4==1) )
    {
        Eb=LargSel;
        Fb=3*HautSel;
    }
    if((Sel1==27)&& (Lect4==1) )
    {
        Eb=2*LargSel;
        Fb=3*HautSel;
    }
    if((Sel1==28)&& (Lect4==1) )
    {
        Eb=3*LargSel;
        Fb=3*HautSel;
    }
    if((Sel1==29)&& (Lect4==1) )
    {
        Eb=4*LargSel;
        Fb=3*HautSel;
    }
    if((Sel1==30)&& (Lect4==1) )
    {
        Eb=5*LargSel;
        Fb=3*HautSel;
    }
    if((Sel1==31)&& (Lect4==1) )
    {
        Eb=6*LargSel;
        Fb=3*HautSel;
    }
    if((Sel1==32)&& (Lect4==1) )
    {
        Eb=7*LargSel;
        Fb=3*HautSel;
    }



    //------------------------------------------------------
    if((Sel1==1) && (Lect2==1) )
    {
        G=0;
        H=0;

    }
    if((Sel1==2)&& (Lect2==1) )
    {
        G=LargSel;
        H=0;
    }
    if((Sel1==3)&& (Lect2==1) )
    {
        G=2*LargSel;
        H=0;
    }
    if((Sel1==4)&& (Lect2==1) )
    {
        G=3*LargSel;
        H=0;
    }
    if((Sel1==5)&& (Lect2==1) )
    {
        G=4*LargSel;
        H=0;
    }
    if((Sel1==6)&& (Lect2==1) )
    {
        G=5*LargSel;
        H=0;
    }
    if((Sel1==7)&& (Lect2==1) )
    {
        G=6*LargSel;
        H=0;
    }
    if((Sel1==8)&& (Lect2==1) )
    {
        G=7*LargSel;
        H=0;
    }
    if((Sel1==9)&& (Lect2==1) )
    {
        G=0;
        H=HautSel;
    }
    if((Sel1==10)&& (Lect2==1) )
    {
        G=LargSel;
        H=HautSel;
    }
    if((Sel1==11)&& (Lect2==1) )
    {
        G=2*LargSel;
        H=HautSel;
    }
    if((Sel1==12)&& (Lect2==1) )
    {
        G=3*LargSel;
        H=HautSel;
    }
    if((Sel1==13)&& (Lect2==1) )
    {
        G=4*LargSel;
        H=HautSel;
    }
    if((Sel1==14)&& (Lect2==1) )
    {
        G=5*LargSel;
        H=HautSel;
    }
    if((Sel1==15)&& (Lect2==1) )
    {
        G=6*LargSel;
        H=HautSel;
    }
    if((Sel1==16)&& (Lect2==1) )
    {
        G=7*LargSel;
        H=HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect2==1))
    {
        G=0;
        H=2*HautSel;

    }
    if((Sel1==18)&& (Lect2==1) )
    {
        G=LargSel;
        H=2*HautSel;
    }
    if((Sel1==19)&& (Lect2==1) )
    {
        G=2*LargSel;
        H=2*HautSel;
    }
    if((Sel1==20)&& (Lect2==1) )
    {
        G=3*LargSel;
        H=2*HautSel;
    }
    if((Sel1==21)&& (Lect2==1) )
    {
        G=4*LargSel;
        H=2*HautSel;
    }
    if((Sel1==22)&& (Lect2==1) )
    {
        G=5*LargSel;
        H=2*HautSel;
    }
    if((Sel1==23)&& (Lect2==1) )
    {
        G=6*LargSel;
        H=2*HautSel;
    }
    if((Sel1==24)&& (Lect2==1) )
    {
        G=7*LargSel;
        H=2*HautSel;
    }
    if((Sel1==25)&& (Lect2==1) )
    {
        G=0;
        H=3*HautSel;
    }
    if((Sel1==26)&& (Lect2==1) )
    {
        G=LargSel;
        H=3*HautSel;
    }
    if((Sel1==27)&& (Lect2==1) )
    {
        G=2*LargSel;
        H=3*HautSel;
    }
    if((Sel1==28)&& (Lect2==1) )
    {
        G=3*LargSel;
        H=3*HautSel;
    }
    if((Sel1==29)&& (Lect2==1) )
    {
        G=4*LargSel;
        H=3*HautSel;
    }
    if((Sel1==30)&& (Lect2==1) )
    {
        G=5*LargSel;
        H=3*HautSel;
    }
    if((Sel1==31)&& (Lect2==1) )
    {
        G=6*LargSel;
        H=3*HautSel;
    }
    if((Sel1==32)&& (Lect2==1) )
    {
        G=7*LargSel;
        H=3*HautSel;
    }



//------------------------------------------------------
    if((Sel1==1) && (Lect5==1) )
    {
        Gb=0;
        Hb=0;

    }
    if((Sel1==2)&& (Lect5==1) )
    {
        Gb=LargSel;
        Hb=0;
    }
    if((Sel1==3)&& (Lect5==1) )
    {
        Gb=2*LargSel;
        Hb=0;
    }
    if((Sel1==4)&& (Lect5==1) )
    {
        Gb=3*LargSel;
        Hb=0;
    }
    if((Sel1==5)&& (Lect5==1) )
    {
        Gb=4*LargSel;
        Hb=0;
    }
    if((Sel1==6)&& (Lect5==1) )
    {
        Gb=5*LargSel;
        Hb=0;
    }
    if((Sel1==7)&& (Lect5==1) )
    {
        Gb=6*LargSel;
        Hb=0;
    }
    if((Sel1==8)&& (Lect5==1) )
    {
        Gb=7*LargSel;
        Hb=0;
    }
    if((Sel1==9)&& (Lect5==1) )
    {
        Gb=0;
        Hb=HautSel;
    }
    if((Sel1==10)&& (Lect5==1) )
    {
        Gb=LargSel;
        Hb=HautSel;
    }
    if((Sel1==11)&& (Lect5==1) )
    {
        Gb=2*LargSel;
        Hb=HautSel;
    }
    if((Sel1==12)&& (Lect5==1) )
    {
        Gb=3*LargSel;
        Hb=HautSel;
    }
    if((Sel1==13)&& (Lect5==1) )
    {
        Gb=4*LargSel;
        Hb=HautSel;
    }
    if((Sel1==14)&& (Lect5==1) )
    {
        Gb=5*LargSel;
        Hb=HautSel;
    }
    if((Sel1==15)&& (Lect5==1) )
    {
        Gb=6*LargSel;
        Hb=HautSel;
    }
    if((Sel1==16)&& (Lect5==1) )
    {
        Gb=7*LargSel;
        Hb=HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect5==1))
    {
        Gb=0;
        Hb=2*HautSel;

    }
    if((Sel1==18)&& (Lect5==1) )
    {
        Gb=LargSel;
        Hb=2*HautSel;
    }
    if((Sel1==19)&& (Lect5==1) )
    {
        Gb=2*LargSel;
        Hb=2*HautSel;
    }
    if((Sel1==20)&& (Lect5==1) )
    {
        Gb=3*LargSel;
        Hb=2*HautSel;
    }
    if((Sel1==21)&& (Lect5==1) )
    {
        Gb=4*LargSel;
        Hb=2*HautSel;
    }
    if((Sel1==22)&& (Lect5==1) )
    {
        Gb=5*LargSel;
        Hb=2*HautSel;
    }
    if((Sel1==23)&& (Lect5==1) )
    {
        Gb=6*LargSel;
        Hb=2*HautSel;
    }
    if((Sel1==24)&& (Lect5==1) )
    {
        Gb=7*LargSel;
        Hb=2*HautSel;
    }
    if((Sel1==25)&& (Lect5==1) )
    {
        Gb=0;
        Hb=3*HautSel;
    }
    if((Sel1==26)&& (Lect5==1) )
    {
        Gb=LargSel;
        Hb=3*HautSel;
    }
    if((Sel1==27)&& (Lect5==1) )
    {
        Gb=2*LargSel;
        Hb=3*HautSel;
    }
    if((Sel1==28)&& (Lect5==1) )
    {
        Gb=3*LargSel;
        Hb=3*HautSel;
    }
    if((Sel1==29)&& (Lect5==1) )
    {
        Gb=4*LargSel;
        Hb=3*HautSel;
    }
    if((Sel1==30)&& (Lect5==1) )
    {
        Gb=5*LargSel;
        Hb=3*HautSel;
    }
    if((Sel1==31)&& (Lect5==1) )
    {
        Gb=6*LargSel;
        Hb=3*HautSel;
    }
    if((Sel1==32)&& (Lect5==1) )
    {
        Gb=7*LargSel;
        Hb=3*HautSel;
    }


    //-----------------------------------------------------------------------
    if((Lect3==1) && (Sel1==1) )
    {
        I=0;
        J=0;

    }
    if((Sel1==2)&& (Lect3==1) )
    {
        I=LargSel;
        J=0;
    }
    if((Sel1==3)&& (Lect3==1) )
    {
        I=2*LargSel;
        J=0;
    }
    if((Sel1==4)&& (Lect3==1) )
    {
        I=3*LargSel;
        J=0;
    }
    if((Sel1==5)&& (Lect3==1) )
    {
        I=4*LargSel;
        J=0;
    }
    if((Sel1==6)&& (Lect3==1) )
    {
        I=5*LargSel;
        J=0;
    }
    if((Sel1==7)&& (Lect3==1) )
    {
        I=6*LargSel;
        J=0;
    }
    if((Sel1==8)&& (Lect3==1) )
    {
        I=7*LargSel;
        J=0;
    }
    if((Sel1==9)&& (Lect3==1) )
    {
        I=0;
        J=HautSel;
    }
    if((Sel1==10)&& (Lect3==1) )
    {
        I=LargSel;
        J=HautSel;
    }
    if((Sel1==11)&& (Lect3==1) )
    {
        I=2*LargSel;
        J=HautSel;
    }
    if((Sel1==12)&& (Lect3==1) )
    {
        I=3*LargSel;
        J=HautSel;
    }
    if((Sel1==13)&& (Lect3==1) )
    {
        I=4*LargSel;
        J=HautSel;
    }
    if((Sel1==14)&& (Lect3==1) )
    {
        I=5*LargSel;
        J=HautSel;
    }
    if((Sel1==15)&& (Lect3==1) )
    {
        I=6*LargSel;
        J=HautSel;
    }
    if((Sel1==16)&& (Lect3==1) )
    {
        I=7*LargSel;
        J=HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect3==1))
    {
        I=0;
        J=2*HautSel;

    }
    if((Sel1==18)&& (Lect3==1) )
    {
        I=LargSel;
        J=2*HautSel;
    }
    if((Sel1==19)&& (Lect3==1) )
    {
        I=2*LargSel;
        J=2*HautSel;
    }
    if((Sel1==20)&& (Lect3==1) )
    {
        I=3*LargSel;
        J=2*HautSel;
    }
    if((Sel1==21)&& (Lect3==1) )
    {
        I=4*LargSel;
        J=2*HautSel;
    }
    if((Sel1==22)&& (Lect3==1) )
    {
        I=5*LargSel;
        J=2*HautSel;
    }
    if((Sel1==23)&& (Lect3==1) )
    {
        I=6*LargSel;
        J=2*HautSel;
    }
    if((Sel1==24)&& (Lect3==1) )
    {
        I=7*LargSel;
        J=2*HautSel;
    }
    if((Sel1==25)&& (Lect3==1) )
    {
        I=0;
        J=3*HautSel;
    }
    if((Sel1==26)&& (Lect3==1) )
    {
        I=LargSel;
        J=3*HautSel;
    }
    if((Sel1==27)&& (Lect3==1) )
    {
        I=2*LargSel;
        J=3*HautSel;
    }
    if((Sel1==28)&& (Lect3==1) )
    {
        I=3*LargSel;
        J=3*HautSel;
    }
    if((Sel1==29)&& (Lect3==1) )
    {
        I=4*LargSel;
        J=3*HautSel;
    }
    if((Sel1==30)&& (Lect3==1) )
    {
        I=5*LargSel;
        J=3*HautSel;
    }
    if((Sel1==31)&& (Lect3==1) )
    {
        I=6*LargSel;
        J=3*HautSel;
    }
    if((Sel1==32)&& (Lect3==1) )
    {
        I=7*LargSel;
        J=3*HautSel;
    }
    //----------------------------------------------------------------
    if((Lect6==1) && (Sel1==1) )
    {
        Ib=0;
        Jb=0;

    }
    if((Sel1==2)&& (Lect6==1) )
    {
        Ib=LargSel;
        Jb=0;
    }
    if((Sel1==3)&& (Lect6==1) )
    {
        Ib=2*LargSel;
        Jb=0;
    }
    if((Sel1==4)&& (Lect6==1) )
    {
        Ib=3*LargSel;
        Jb=0;
    }
    if((Sel1==5)&& (Lect6==1) )
    {
        Ib=4*LargSel;
        Jb=0;
    }
    if((Sel1==6)&& (Lect6==1) )
    {
        Ib=5*LargSel;
        Jb=0;
    }
    if((Sel1==7)&& (Lect6==1) )
    {
        Ib=6*LargSel;
        Jb=0;
    }
    if((Sel1==8)&& (Lect6==1) )
    {
        Ib=7*LargSel;
        Jb=0;
    }
    if((Sel1==9)&& (Lect6==1) )
    {
        Ib=0;
        Jb=HautSel;
    }
    if((Sel1==10)&& (Lect6==1) )
    {
        Ib=LargSel;
        Jb=HautSel;
    }
    if((Sel1==11)&& (Lect6==1) )
    {
        Ib=2*LargSel;
        Jb=HautSel;
    }
    if((Sel1==12)&& (Lect6==1) )
    {
        Ib=3*LargSel;
        Jb=HautSel;
    }
    if((Sel1==13)&& (Lect6==1) )
    {
        Ib=4*LargSel;
        Jb=HautSel;
    }
    if((Sel1==14)&& (Lect6==1) )
    {
        Ib=5*LargSel;
        Jb=HautSel;
    }
    if((Sel1==15)&& (Lect6==1) )
    {
        Ib=6*LargSel;
        Jb=HautSel;
    }
    if((Sel1==16)&& (Lect6==1) )
    {
        Ib=7*LargSel;
        Jb=HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect6==1))
    {
        Ib=0;
        Jb=2*HautSel;

    }
    if((Sel1==18)&& (Lect6==1) )
    {
        Ib=LargSel;
        Jb=2*HautSel;
    }
    if((Sel1==19)&& (Lect6==1) )
    {
        Ib=2*LargSel;
        Jb=2*HautSel;
    }
    if((Sel1==20)&& (Lect6==1) )
    {
        Ib=3*LargSel;
        Jb=2*HautSel;
    }
    if((Sel1==21)&& (Lect6==1) )
    {
        Ib=4*LargSel;
        Jb=2*HautSel;
    }
    if((Sel1==22)&& (Lect6==1) )
    {
        Ib=5*LargSel;
        Jb=2*HautSel;
    }
    if((Sel1==23)&& (Lect6==1) )
    {
        Ib=6*LargSel;
        Jb=2*HautSel;
    }
    if((Sel1==24)&& (Lect6==1) )
    {
        Ib=7*LargSel;
        Jb=2*HautSel;
    }
    if((Sel1==25)&& (Lect6==1) )
    {
        Ib=0;
        Jb=3*HautSel;
    }
    if((Sel1==26)&& (Lect6==1) )
    {
        Ib=LargSel;
        Jb=3*HautSel;
    }
    if((Sel1==27)&& (Lect6==1) )
    {
        Ib=2*LargSel;
        Jb=3*HautSel;
    }
    if((Sel1==28)&& (Lect6==1) )
    {
        Ib=3*LargSel;
        Jb=3*HautSel;
    }
    if((Sel1==29)&& (Lect6==1) )
    {
        Ib=4*LargSel;
        Jb=3*HautSel;
    }
    if((Sel1==30)&& (Lect6==1) )
    {
        Ib=5*LargSel;
        Jb=3*HautSel;
    }
    if((Sel1==31)&& (Lect6==1) )
    {
        Ib=6*LargSel;
        Jb=3*HautSel;
    }
    if((Sel1==32)&& (Lect6==1) )
    {
        Ib=7*LargSel;
        Jb=3*HautSel;
    }


    //--------------------------------------------------------------------

    //------------------------
    if((Lect7==1) && (Sel1==1) )
    {
        K=0;
        L=0;

    }
    if((Sel1==2)&& (Lect7==1) )
    {
        K=LargSel;
        L=0;
    }
    if((Sel1==3)&& (Lect7==1) )
    {
        K=2*LargSel;
        L=0;
    }
    if((Sel1==4)&& (Lect7==1) )
    {
        K=3*LargSel;
        L=0;
    }
    if((Sel1==5)&& (Lect7==1) )
    {
        K=4*LargSel;
        L=0;
    }
    if((Sel1==6)&& (Lect7==1) )
    {
        K=5*LargSel;
        L=0;
    }
    if((Sel1==7)&& (Lect7==1) )
    {
        K=6*LargSel;
        L=0;
    }
    if((Sel1==8)&& (Lect7==1) )
    {
        K=7*LargSel;
        L=0;
    }
    if((Sel1==9)&& (Lect7==1) )
    {

        K=0;
        L=HautSel;
    }
    if((Sel1==10)&& (Lect7==1) )
    {
        K=LargSel;
        L=HautSel;
    }
    if((Sel1==11)&& (Lect7==1) )
    {
        K=2*LargSel;
        L=HautSel;
    }
    if((Sel1==12)&& (Lect7==1) )
    {
        K=3*LargSel;
        L=HautSel;
    }
    if((Sel1==13)&& (Lect7==1) )
    {
        K=4*LargSel;
        L=HautSel;
    }
    if((Sel1==14)&& (Lect7==1) )
    {
        K=5*LargSel;
        L=HautSel;
    }
    if((Sel1==15)&& (Lect7==1) )
    {
        K=6*LargSel;
        L=HautSel;
    }
    if((Sel1==16)&& (Lect7==1) )
    {
        K=7*LargSel;
        L=HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect7==1))
    {
        K=0;
        L=2*HautSel;

    }
    if((Sel1==18)&& (Lect7==1) )
    {
        K=LargSel;
        L=2*HautSel;
    }
    if((Sel1==19)&& (Lect7==1) )
    {
        K=2*LargSel;
        L=2*HautSel;
    }
    if((Sel1==20)&& (Lect7==1) )
    {
        K=3*LargSel;
        L=2*HautSel;
    }
    if((Sel1==21)&& (Lect7==1) )
    {
        K=4*LargSel;
        L=2*HautSel;
    }
    if((Sel1==22)&& (Lect7==1) )
    {
        K=5*LargSel;
        L=2*HautSel;
    }
    if((Sel1==23)&& (Lect7==1) )
    {
        K=6*LargSel;
        L=2*HautSel;
    }
    if((Sel1==24)&& (Lect7==1) )
    {
        K=7*LargSel;
        L=2*HautSel;
    }
    if((Sel1==25)&& (Lect7==1) )
    {
        K=0;
        L=3*HautSel;
    }
    if((Sel1==26)&& (Lect7==1) )
    {
        K=LargSel;
        L=3*HautSel;
    }
    if((Sel1==27)&& (Lect7==1) )
    {
        K=2*LargSel;
        L=3*HautSel;
    }
    if((Sel1==28)&& (Lect7==1) )
    {
        K=3*LargSel;
        L=3*HautSel;
    }
    if((Sel1==29)&& (Lect7==1) )
    {
        K=4*LargSel;
        L=3*HautSel;
    }
    if((Sel1==30)&& (Lect7==1) )
    {
        K=5*LargSel;
        L=3*HautSel;
    }
    if((Sel1==31)&& (Lect7==1) )
    {
        K=6*LargSel;
        L=3*HautSel;
    }
    if((Sel1==32)&& (Lect7==1) )
    {
        K=7*LargSel;
        L=3*HautSel;
    }


    //------------------------

    //------------------------

//------------------------
    if((Lect8==1) && (Sel1==1) )
    {
        M=0;
        N=0;

    }
    if((Sel1==2)&& (Lect8==1) )
    {
        M=1*LargSel;
        N=0;
    }
    if((Sel1==3)&& (Lect8==1) )
    {
        M=2*LargSel;
        N=0;
    }
    if((Sel1==4)&& (Lect8==1) )
    {
        M=3*LargSel;
        N=0;
    }
    if((Sel1==5)&& (Lect8==1) )
    {
        M=4*LargSel;
        N=0;
    }
    if((Sel1==6)&& (Lect8==1) )
    {
        M=5*LargSel;
        N=0;
    }
    if((Sel1==7)&& (Lect8==1) )
    {
        M=6*LargSel;
        N=0;
    }
    if((Sel1==8)&& (Lect8==1) )
    {
        M=7*LargSel;
        N=0;
    }
    if((Sel1==9)&& (Lect8==1) )
    {
        M=0;
        N=1*HautSel;
    }
    if((Sel1==10)&& (Lect8==1) )
    {
        M=1*LargSel;
        N=1*HautSel;
    }
    if((Sel1==11)&& (Lect8==1) )
    {
        M=2*LargSel;
        N=1*HautSel;
    }
    if((Sel1==12)&& (Lect8==1) )
    {
        M=3*LargSel;
        N=1*HautSel;
    }
    if((Sel1==13)&& (Lect8==1) )
    {
        M=4*LargSel;
        N=1*HautSel;
    }
    if((Sel1==14)&& (Lect8==1) )
    {
        M=5*LargSel;
        N=1*HautSel;
    }
    if((Sel1==15)&& (Lect8==1) )
    {
        M=6*LargSel;
        N=1*HautSel;
    }
    if((Sel1==16)&& (Lect8==1) )
    {
        M=7*LargSel;
        N=1*HautSel;
    }
    //------------------------

    if   ((Sel1==17) && (Lect8==1))
    {
        M=0;
        N=2*HautSel;

    }
    if((Sel1==18)&& (Lect8==1) )
    {
        M=1*LargSel;
        N=2*HautSel;
    }
    if((Sel1==19)&& (Lect8==1) )
    {
        M=2*LargSel;
        N=2*HautSel;
    }
    if((Sel1==20)&& (Lect8==1) )
    {
        M=3*LargSel;
        N=2*HautSel;
    }
    if((Sel1==21)&& (Lect8==1) )
    {
        M=4*LargSel;
        N=2*HautSel;
    }
    if((Sel1==22)&& (Lect8==1) )
    {
        M=5*LargSel;
        N=2*HautSel;
    }
    if((Sel1==23)&& (Lect8==1) )
    {
        M=6*LargSel;
        N=2*HautSel;
    }
    if((Sel1==24)&& (Lect8==1) )
    {
        M=7*LargSel;
        N=2*HautSel;
    }
    if((Sel1==25)&& (Lect8==1) )
    {
        M=0;
        N=3*HautSel;
    }
    if((Sel1==26)&& (Lect8==1) )
    {
        M=1*LargSel;
        N=3*HautSel;
    }
    if((Sel1==27)&& (Lect8==1) )
    {
        M=2*LargSel;
        N=3*HautSel;
    }
    if((Sel1==28)&& (Lect8==1) )
    {
        M=3*LargSel;
        N=3*HautSel;
    }
    if((Sel1==29)&& (Lect8==1) )
    {
        M=4*LargSel;
        N=3*HautSel;
    }
    if((Sel1==30)&& (Lect8==1) )
    {
        M=5*LargSel;
        N=3*HautSel;
    }
    if((Sel1==31)&& (Lect8==1) )
    {
        M=6*LargSel;
        N=3*HautSel;
    }
    if((Sel1==32)&& (Lect8==1) )
    {
        M=7*LargSel;
        N=3*HautSel;
    }


}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
//iClic   = 0;
//bClic = false;

    if(iClic==3)
    {
        bClic = false;
        iClic =0;
        Lect3=0;
    }
    if(iClic2==3)
    {
        bClic2 = false;
        iClic2 =0;
        Lect6=0;
    }
    Lect1=0;
    Lect1=0;
    Lect3=0;
    Lect4=0;
    Lect5=0;
    Lect6=0;
    Lect7=0;
    Lect8=0;

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{


}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}



void testApp::setGUI1()
{

    float dim =8;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 190-xInit;

    gui1 = new ofxUICanvas(20, 20, 200, 600);


//-------------------------- Player_G1_gui1

//    gui1->addSlider("Mix_G1", 0.0, 255.0, Mix_G1, length,dim*3);
//    gui1->addSpacer(length-xInit, 2);
//    gui1->addWidgetDown(new ofxUILabel("V SLIDERS", OFX_UI_FONT_SMALL));
//	gui1->addSlider("0", 0.0, 255.0, 150, dim, 160);
//	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
//	gui1->addSlider("1", 0.0, 255.0, 150, dim, 160);
//	gui1->addSlider("2", 0.0, 255.0, 150, dim, 160);
//	gui1->addSlider("3", 0.0, 255.0, 150, dim, 160);
//	gui1->addSlider("4", 0.0, 255.0, 150, dim, 160);
//	gui1->addSlider("5", 0.0, 255.0, 150, dim, 160);
//	gui1->addSlider("6", 0.0, 255.0, 150, dim, 160);
//	gui1->addSlider("7", 0.0, 255.0, 150, dim, 160);
//	gui1->addSlider("8", 0.0, 255.0, 150, dim, 160);
//	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

    gui1->addSpacer(1);
//    gui1->addWidgetDown(new ofxUIButton("TimeLine",false, dim*1.5, dim*1.5));
    gui1->addWidgetDown(new ofxUIToggle("VideoGrid",true, dim*1.5, dim*1.5));
    gui1->addWidgetRight(new ofxUIToggle("Audio",false, dim*1.5, dim*1.5));
    gui1->addSpacer(1);

//-------------------------- Player_A1_gui1
//    gui1->addWidgetDown(new ofxUILabel("PlayerA1", OFX_UI_FONT_SMALL));

    gui1->addWidgetDown(new ofxUICircleSlider(dim*3, 0.0, 255.0, Lum_A1, "Lum_A1", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, Lum_B1, "Lum_B1", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, Lum_C1, "Lum_C1", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, Lum_D1, "Lum_D1", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, Lum_E1, "Lum_E1", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, Lum_F1, "Lum_F1", OFX_UI_FONT_SMALL));
    gui1->addSlider("LumX6", 0.0, 255.0, 127, length,dim*2);
    gui1->addWidgetDown(new ofxUIToggle("Lum_x6",false,dim*1.5, dim*1.5,   OFX_UI_FONT_SMALL));


    gui1->addSpacer(1);

    gui1->addWidgetDown(new ofxUICircleSlider(dim*3, 0.0, 255.0, Cont_G1, "Cont_G1", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, Satu_G1, "Satu_G1", OFX_UI_FONT_SMALL));
    gui1->addSpacer(1);
//    gui1->addWidgetDown(new ofxUICircleSlider(dim*5, 0.0, 255.0, TV1, "TV1", OFX_UI_FONT_SMALL));
//    gui1->addWidgetRight(new ofxUICircleSlider(dim*5, 0.0, 255.0, LumTV, "LumTV", OFX_UI_FONT_SMALL));
//    gui1->addWidgetRight(new ofxUICircleSlider(dim*5, 0.0, 255.0, OpacTV, "OpacTV", OFX_UI_FONT_SMALL));
    gui1->addWidgetDown(new ofxUICircleSlider(dim*3, 0.0, 255.0, 127, "Op1", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, 127, "Op2", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, 127, "Op3", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, 127, "Op4", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, 127, "Op5", OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUICircleSlider(dim*3, 0.0, 255.0, 127, "Op6", OFX_UI_FONT_SMALL));
    gui1->addSlider("OpacityX6", 0.0, 255.0, 127, length,dim*2);

    gui1->addWidgetDown(new ofxUIToggle("Opacity",false,dim*1.5, dim*1.5,   OFX_UI_FONT_SMALL));



    gui1->addSpacer(1);
//        gui1->addSlider("Cont_G1", 0.0, 255.0, Cont_G1, length,dim*2,127);
//    gui1->addSlider("Lum_G1", 0.0, 255.0, Lum_G1, length,dim,127);
//    gui1->addSlider("Satu_G1", 0.0, 255.0, Satu_G1, length,dim,255);

//    gui1->addSlider("Y_G1", -320.0, 0.0, Y_G1, length,dim*1);
//    gui1->addSpacer();
    gui1->addWidgetDown(new ofxUIToggle("Cam",false,dim*1.5, dim*1.5,   OFX_UI_FONT_SMALL));

    gui1->addSlider("WebCam", 0.0, 255.0, WebCam, length,dim*2);

    gui1->addSlider("F_1", 0.0, 255.0, F_1, length,dim*2);
    gui1->addSlider("F_2", 0.0, 255.0, 255, length,dim*2);
    gui1->addSlider("Fade_G", 255.0, 0.0,255, length,dim*2);
    gui1->addSpacer();
//    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "TimeLine"));
//    gui1->addWidgetRight(new ofxUIButton(dim*2, dim*2,  false, "VideoGrid"));
    gui1->addWidgetDown(new ofxUIToggle("800x600",false,dim*1.5, dim*1.5,   OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUIToggle("Warp",true,dim*1.5, dim*1.5,   OFX_UI_FONT_SMALL));
    gui1->addWidgetRight(new ofxUIToggle("3/6Lect",false,dim*1.5, dim*1.5,   OFX_UI_FONT_SMALL));
    gui1->addSpacer();

    gui1->addSlider("background", 0.0, 255.0, backgroundColor, length,dim,60);


    gui1->addSpacer();
    gui1->addSlider("LumTV",  0.0, 255.0, LumTV, length,dim*2);
    gui1->addSlider("OpacTV", 0.0, 255.0, OpacTV, length,dim*2);
    gui1->addSpacer();

    ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
}
//--------------------------

void testApp::setGUI2()
{
    float dim = 8;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 190-xInit;


    gui2 = new ofxUICanvas(20+200, 20, 200, 400);


    gui2->addSpacer();
    gui2->addWidgetDown(new ofxUILabel("Random Tete Lect", OFX_UI_FONT_SMALL));
    gui2->addSpacer();
    gui2->addWidgetDown(new ofxUIToggle("R_L1",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetRight(new ofxUIToggle("R_L2",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetRight(new ofxUIToggle("R_L3",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetDown(new ofxUIToggle("R_L4",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetRight(new ofxUIToggle("R_L5",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetRight(new ofxUIToggle("R_L6",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetDown(new ofxUIToggle("R_F1",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetRight(new ofxUIToggle("R_F2",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addSpacer();
    gui2->addWidgetDown(new ofxUILabel("Random Open", OFX_UI_FONT_SMALL));
    gui2->addSpacer();
    gui2->addWidgetDown(new ofxUIToggle("R_Open1",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetRight(new ofxUIToggle("R_Open2",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
    gui2->addWidgetRight(new ofxUIToggle("R_Open3",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
//    gui2->addWidgetRight(new ofxUIToggle("R_Open4",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
//    gui2->addWidgetDown(new ofxUIToggle("R_Open5",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
//    gui2->addWidgetRight(new ofxUIToggle("R_Open6",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
//    gui2->addWidgetRight(new ofxUIToggle("R_Open7",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));
//    gui2->addWidgetRight(new ofxUIToggle("R_Open8",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL));

//    gui2->addWidgetRight(new ofxUIToggle(dim*1.5, dim*1.5, false, "R_Lect3" ));
//    gui2->addWidgetRight(new ofxUIToggle(dim*1.5, dim*1.5, false, "R_Lect1" ));
    gui2->addSpacer();
    gui2->addWidgetRight(new ofxUIToggle("Lum_1",false, dim*1.5, dim*1.5,OFX_UI_FONT_SMALL ));
    gui2->addSpacer();
    gui2->addSlider("Sens", 0.0, 255.0, 0.0, dim*2, 120);
    gui2->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
    gui2->addSlider("Rand", 2.0, 30.0, 2.0, dim*2, 120);
    gui2->addSlider("In", 0.0, 255.0, 0.0, dim*2, 120);
    gui2->addSlider("Out", 0.0, 255.0, 0.0, dim*2, 120);
    gui2->addSlider("TimeF", 60.0, 1.001, 0.0, dim*2, 120);
//    gui2->addWidgetDown(new ofxUIToggle("SendOsc"));
//    gui2->addWidgetDown(new ofxUIToggle("NoOsc"));
    gui2->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
//    gui2->addWidgetDown(new ofxUILabel("FPS SLIDER", OFX_UI_FONT_MEDIUM));
    gui2->addFPSSlider("FPS SLIDER", length-xInit, dim);


    ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);
}


void testApp::setGUI3()
{
    gui3 = new ofxUIScrollableCanvas(20+200, 350, 200, 100);
    gui3->setScrollableDirections(false, true);
    gui3->setSnapping(false);
    gui3->setName("gui3");
    float dim = 8;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 190-xInit;

    gui3->addSpacer(length-xInit, 1);
    string path = "v/";
    ofDirectory dir(path);
//        dir.allowExt("mov");
    dir.listDir();
    dir.sort();
    for(int i = 0; i < dir.size(); i++)
    {
        ofLogNotice(dir.getPath(i));
        gui3->addWidgetDown(new ofxUIButton( dir.getPath(i), false,dim*0.5, dim*0.5));
        gui3->addSpacer(length-xInit+20, 0);
    }

//
    ofAddListener(gui3->newGUIEvent,this,&testApp::guiEvent);
}

void testApp::setGUI4()
{
//	float dim = 16;
//	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
//    float length = 255-xInit;
//	gui4 = new ofxUICanvas(length*3+xInit*3+6+800, 20, length+xInit, ofGetHeight());
//    gui4->addWidgetDown(new ofxUILabel("PANEL 4", OFX_UI_FONT_SMALL));
//
//    gui4->addSpacer(length-xInit, 2);
//
//    gui4->addWidgetDown(new ofxUILabel("CIRCLE SLIDER", OFX_UI_FONT_SMALL));
//    gui4->addWidgetDown(new ofxUICircleSlider((length-xInit)*.5, 0, 100, 50.0, "", OFX_UI_FONT_SMALL));
//
//    ofAddListener(gui4->newGUIEvent,this,&testApp::guiEvent);
}
