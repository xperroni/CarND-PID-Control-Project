#!/bin/bash

wget -nc https://github.com/udacity/CarND-PID-Control-Project/releases/download/v0.1.1/udacity-sdc-selfdrivingcarsimulatoropensource-pid-project-linux-desktop-universal-8.zip
unzip udacity-sdc-selfdrivingcarsimulatoropensource-pid-project-linux-desktop-universal-8.zip
mv "PID Project Linux desktop Universal.x86_64" simulator
mv "PID Project Linux desktop Universal_Data" simulator_Data
rm "PID Project Linux desktop Universal.x86"
