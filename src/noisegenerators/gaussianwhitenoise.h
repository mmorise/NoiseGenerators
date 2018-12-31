//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//-----------------------------------------------------------------------------
#ifndef NOISEGENERATORS_GAUSSIANWHITENOISE_H_
#define NOISEGENERATORS_GAUSSIANWHITENOISE_H_

//-----------------------------------------------------------------------------
// ReseedGWN() resets the random seed.
//-----------------------------------------------------------------------------
void ReseedGWN();

//-----------------------------------------------------------------------------
// GenerateGWN() generates the Gaussian white noise.
//
// Output:
//   Generated noise (1 sample).
//-----------------------------------------------------------------------------
double GenerateGWN();

#endif  // NOISEGENERATORS_GAUSSIANWHITENOISE_H_
