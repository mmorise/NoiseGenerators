function SetAverageDistanceOVN(td)
% This function can change the parameter "T_d".
% y = SetAverageDistanceOVN(fs)
%
% Input
%   td : Average distance of impulses [sample]
%
% 2019/01/01: First version was released.

if nargin ~= 1
  error('Error: This function requires one input.');
end;
if td < 2
  error('Error: td must be above 2.');
end;
OVNPortal(0, td);
