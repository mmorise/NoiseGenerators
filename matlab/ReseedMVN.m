function ReseedMVN()
% This function resets the parameters and the seed.
% y = ReseedMVN()
%
% 2019/01/01: First version was released.

if nargin ~= 0
  error('Error: This function requires no input.');
end;
MVNPortal(0, 0);
