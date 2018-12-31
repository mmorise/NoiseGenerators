clear;
clc;

%------------------------------------------------------------------------------
% Test for generating modified velvet noise.
%------------------------------------------------------------------------------
SetSamplingFrequencyMVN(48000);
ReseedMVN();
mvn_sample = GenerateMVN(1000);

%------------------------------------------------------------------------------
% Test for generating original velvet noise.
%------------------------------------------------------------------------------
SetAverageDistanceOVN(4);
ReseedOVN();
ovn_sample = GenerateOVN(1000);

%------------------------------------------------------------------------------
% Test for generating Gaussian white noise.
%------------------------------------------------------------------------------
ReseedGWN();
gwn_sample = GenerateGWN(1000);

