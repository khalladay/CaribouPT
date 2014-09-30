CaribouPT
=========

A CPU based path tracer using OpenMP. 

Building / Running
---------------------
This project uses OpenMP®/Clang, in order to build this project you will need to install it on your system (well not really, but without OpenMP everything runs on one thread and it's already slow enough). 

Instructions for setting up OpenMP found here: [http://kylehalladay.com/all/blog/2014/07/15/Setting-Up-OpenMP-Mavericks.html](http://kylehalladay.com/all/blog/2014/07/15/Setting-Up-OpenMP-Mavericks.html)(only tested on Mavericks)

###Building from the Makefile: 
cd "location of project" <br>
make -f MAKEFILE 

###To build/debug from XCode:
Launch xcode from terminal with the following commands: <br>
source ~/.profile<br>
open -a "Xcode"

Then build from Xcode like normal
