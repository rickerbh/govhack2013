govhack2013
===========
Our entry for [govhack2013](http://www.govhack.org).

Future Melbourne
===============

"Future Melbourne" is a musical compostion which is manipulated by the Victorian data set within the Department of Health and Ageing's Statistical Local Area Population Projections 2007-2027.

Melbourne, Victoria's capital, is the fastest growing city in numerical terms in Australia.  The population is predicted to reach 7 million by 2030.  Along with the high population growth, comes a high demand for housing. As such, Melbourne is undergoing a significant urban sprawl, and the urban footprint of Melbourne is increasing.  Melton, Wyndham and Casey, all part of the Melbourne statistical division, record some of the highest growth rates of all local government areas in Australia.

happtic's entry, Future Melbourne, is a musical representation of the continued population growth prediction for Melbourne, including the growth of the population into these "outer suburbs" and "satellite cities".  The data set is split by age and suburb, and variances in these figures will drive the manipulation of musical samples.

The population projections in the utilised data set were prepared by the ABS, with initial data based on the Estimated Resident Population (ERP) from the 2006 Census. Future years are projected based on the 2006-2101 issue of Population Projections, Australia from the ABS.  Assumptions of fertility, mortality and migration are primarily based on historical patterns and area trends.

Data Source
===========

We are using the Victorian data set for [Statistical Local Area Population Projections, 2007 to 2027, Revised](http://www.health.gov.au/internet/main/publishing.nsf/Content/BDE33326FE4D5460CA2576BD00833800?OpenDocument&SUBMITCHECK=on&SUBMIT=View+documents) from [health.gov.au](http://www.health.gov.au).

The source is being split into female/male data sets, and normalised between 0-1 based on region within Melbourne (Inner, Metro, Greater [North, South, East, West]). Check the [Source Data](https://github.com/rickerbh/govhack2013/tree/master/Source%20Data) directory for this. ruby scrips that perform this task are in the `Source Data/Normalised/` directory.

Installation
------------

You can extract and run the compiled application from the `futureMelbourne/bin/futureMelbourneApp.zip` file (it must be extracted to the location it's stored in, and run from that location), or follow the instructions below to compile it yourself.

You'll need [Xcode](https://itunes.apple.com/en/app/xcode/id497799835?mt=12). 

The main project is [openFrameworks](http://www.openframeworks.cc) based. To compile it, you'll need to install [openFrameworks](http://www.openframeworks.cc/download/) for your platform. Just download and install.

You'll also need the following addons:
- [ofxAudioUnit](https://github.com/admsyn/ofxAudioUnit)
- [ofxJSON](https://github.com/jefftimesten/ofxJSON)
- [ofxTimer](https://github.com/fx-lange/ofxTimer)

To install the addons, navigate to the root directory of openframeworks (`of_v0.7.4_osx_release` for me), and then...
    
    cd addons
    git clone https://github.com/admsyn/ofxAudioUnit.git
    git clone https://github.com/jefftimesten/ofxJSON.git
    git clone https://github.com/fx-lange/ofxTimer.git
    
To build the app, copy the `futureMelbourne` directory from this repo into the `of_v0.7.4_osx_release/apps/myapps/` directory, open the `futureMelbourne.xcodeproj` file, and Build & Run the futureMelboure - Release target. 

Results
-------

Aural pleasure. Maybe. Might just be noise.

Audio Help
----------

The way this app works is that it modifies the resonance and cutoff frequency for a low-pass filter, and alters volume of each sample independently.

- [Low-pass Filter](http://en.wikipedia.org/wiki/Low-pass_filter)

Licence
-------

All audio samples from [freesound.org](http://www.freesound.org), under Creative Commons Licence.
- [http://www.freesound.org/people/loofa/sounds/23580/](http://www.freesound.org/people/loofa/sounds/23580/)
- [http://www.freesound.org/people/bennstir/sounds/81804/](http://www.freesound.org/people/bennstir/sounds/81804/)
- [http://www.freesound.org/people/drriquet/sounds/85579/](http://www.freesound.org/people/drriquet/sounds/85579/)
- [http://www.freesound.org/people/carlos-vaquero/sounds/153610/](http://www.freesound.org/carlos-vaquero/sounds/153610/)
- [http://www.freesound.org/people/carlos-vaquero/sounds/154230/](http://www.freesound.org/people/carlos-vaquero/sounds/154230/)
- [http://www.freesound.org/people/archeos/sounds/174725/](http://www.freesound.org/people/archeos/sounds/174725/)

[![Creative Commons Licence][1]][2]  
This work is licensed under a [Creative Commons Attribution 3.0 Unported License][2]. 

   [1]: http://i.creativecommons.org/l/by/3.0/88x31.png
   [2]: http://creativecommons.org/licenses/by/3.0/
