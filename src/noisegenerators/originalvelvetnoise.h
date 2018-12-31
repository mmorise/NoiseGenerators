//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//-----------------------------------------------------------------------------
#ifndef NOISEGENERATORS_ORIGINALVELVETNOISE_H_
#define NOISEGENERATORS_ORIGINALVELVETNOISE_H_

//-----------------------------------------------------------------------------
// ReseedOVN() resets the internal parameters
//-----------------------------------------------------------------------------
void ReseedOVN();

//-----------------------------------------------------------------------------
// SetAverageDistanceOVN() can change the parameter "T_d".
// Internal parameters are reset.
//
// Input:
//   td             : Average distance of impulses [sample]
//
// Note: Default parameter is four.
//-----------------------------------------------------------------------------
void SetAverageDistanceOVN(int td);

//-----------------------------------------------------------------------------
// GenerateOVN() generates the original velvet noise.
//
// Output:
//   Generated noise (1 sample).
//-----------------------------------------------------------------------------
int GenerateOVN();

#endif  // NOISEGENERATORS_ORIGINALVELVETNOISE_H_
