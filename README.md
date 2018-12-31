# NoiseGenerators

We provide noise generators for three kinds of noise (Gaussian white noise, velvet noise [1] (We call it original velvet noise), and modified velvet noise [2]). These functions have the compatibility between C++ and MATLAB. The modified velvet noise will be used for WORLD (https://github.com/mmorise/World) in the future.

[1] M. Karjalainen and H. Järveläien: Reverberation modeling using velvet noise, in Proc. AES 2007, 9-page, 2007.  
[2] M. Morise: Modification of velvet noise for speech waveform generation by using vocoder-based speech synthesizer, IEICE transactions on information and systems, vol. E102-D, no. 3, pp. xxx-xxx, March 2019.  

## Installation
### C++
You can use makefile for compile.

### MATLAB
You can use the script setup.m  for installation after adding a path to the folder ./matlab. You must not change the file composition until executing the setup script. Please see the script test_script.m for the test.

## Please give me the information
If you have the information whether there is a patent in velvet noise, please contact me. In cases where there is the patent, I will add it in README.md.
