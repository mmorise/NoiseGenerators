clear;
clc;

mex  -c ../src/modifiedvelvetnoise.cpp
mex MVNPortal.cpp modifiedvelvetnoise.obj
delete modifiedvelvetnoise.obj
mex  -c ../src/originalvelvetnoise.cpp
mex OVNPortal.cpp originalvelvetnoise.obj
delete originalvelvetnoise.obj
mex  -c ../src/gaussianwhitenoise.cpp
mex GWNPortal.cpp gaussianwhitenoise.obj
delete gaussianwhitenoise.obj
