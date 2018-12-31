function ReseedOVN()
% This function resets the parameters and the seed.
% y = ReseedOVN()
%
% 2019/01/01: First version was released.

if nargin ~= 0
  error('Error: This function requires no input.');
end;
OVNPortal(0, 0);
