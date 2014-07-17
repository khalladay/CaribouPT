CaribouPT
=========

A Progressive Path Tracer using OpenMP. Named after the brand of coffee I was drinking when I created the repo.

Building / Running
---------------------
This project uses OpenMP®/Clang, in order to build this project you will need to install it on your system. 

Instructions for setting up OpenMP found here: [http://kylehalladay.com/all/blog/2014/07/15/Setting-Up-OpenMP-Mavericks.html](http://kylehalladay.com/all/blog/2014/07/15/Setting-Up-OpenMP-Mavericks.html)(only tested on Mavericks)

###To Build: 

To build from Makefile: 
cd &lt;location of project&gt;
make -f MAKEFILE

###To build/debug from XCode:

Launch xcode from terminal with the following commands:
source ~/.profile
open -a "Xcode"

Then build from Xcode like normal
