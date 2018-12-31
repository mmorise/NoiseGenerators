function ReseedGWN()
% This function resets the seed.
% y = ReseedGWN()
%
% 2019/01/01: First version was released.

if nargin ~= 0
  error('Error: This function requires no input.');
end;
GWNPortal(0, 0);
