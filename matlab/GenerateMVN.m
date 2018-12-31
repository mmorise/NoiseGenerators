function y = GenerateMVN(N)
% This function generates the modified velvet noise (MVN).
% y = GenerateMVN(N)
%
% Input
%   N  : Number of requried samples
%
% Output
%   y  : Generated noise
%
% Note: Default sampling frequency has been set to 48 kHz.
%
% 2019/01/01: First version was released.

if nargin ~= 1
  error('Error: This function requires one input.');
end;
if N <= 0
  error('Error: N must be a non-negative integer.');
end;
y = double(MVNPortal(N));
