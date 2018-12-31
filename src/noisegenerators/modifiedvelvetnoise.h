//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//-----------------------------------------------------------------------------
#ifndef NOISEGENERATORS_MODIFIEDVELVETNOISE_H_
#define NOISEGENERATORS_MODIFIEDVELVETNOISE_H_

//-----------------------------------------------------------------------------
// ReseedMVN() resets the internal parameters.
//-----------------------------------------------------------------------------
void ReseedMVN();

//-----------------------------------------------------------------------------
// SetSamplingFrequency() can set the sampling frequency of MVN.
// Internal parameters are reset.
//
// Input:
//   fs             : Sampling frequency [Hz]
//
// Note: Default falue is 48 kHz.
//-----------------------------------------------------------------------------
void SetSamplingFrequencyMVN(int fs);

//-----------------------------------------------------------------------------
// GenerateMVN() generates the modified velvet noise.
//
// Output:
//   Generated noise (1 sample).
//-----------------------------------------------------------------------------
int GenerateMVN();

#endif  // NOISEGENERATORS_MODIFIEDVELVETNOISE_H_
