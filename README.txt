in order to implement the gauge you must follow these steps:

go to C:\dev\glist\glistplugins\gipGauge\images and find the gauge folder
copy the gauge folder into your projects images folder inside the assets

on the class file where you want to draw the gauges, you must load the images after the setup. for example:

gauge.setup();
gaugebg.loadImage("gauge/GaugeBG.png");
gaugestick.loadImage("gauge/GaugeStick.png");
gaugebgptr = &gaugebg;
gaugestickptr = &gaugestick;

gauge.setGaugeImage(gaugebgptr, gaugestickptr);
