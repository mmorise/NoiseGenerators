function SetSamplingFrequencyMVN(fs)
% This function can set the sampling frequency used for MVN.
% y = SetSamplingFrequencyMVN(fs)
%
% Input
%   fs : sampling frequency
%
% 2019/01/01: First version was released.

if nargin ~= 1
  error('Error: This function requires one input.');
end;
if fs < 8000 || fs > 96000
  error('Error: fs must be in the range (8000-96000 Hz).');
end;
MVNPortal(0, fs);
