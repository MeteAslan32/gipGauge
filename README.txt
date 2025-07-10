in order to implement the gauge you must follow these steps:

go to C:\dev\glist\glistplugins\gipGauge\images and find the gauge folder
copy the gauge folder into your projects images folder inside the assets

on you gCanvas.cpp file you must load the images after the setup:

gauge.setup();
gaugebg.loadImage("gauge/GaugeBG.png");
gaugestick.loadImage("gauge/GaugeStick.png");
gaugebgptr = &gaugebg;
gaugestickptr = &gaugestick;

gauge.setGaugeImage(gaugebgptr, gaugestickptr);

If you cant see the gauge on the screen, try to rerun.