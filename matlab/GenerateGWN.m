function y = GenerateGWN(N)
% This function generates the Gaussian white noise (GWN).
% y = GenerateGWN(N)
%
% Input
%   N  : Number of requried samples
%
% Output
%   y  : Generated noise
%
% 2019/01/01: First version was released.

if nargin ~= 1
  error('Error: This function requires one input.');
end;
if N <= 0
  error('Error: N must be a non-negative integer.');
end;
y = double(GWNPortal(N));
