//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//
// MEX file for Gaussian white noise generation.
//-----------------------------------------------------------------------------
#include <stdint.h>

#include "mex.h"

#include "../src/noisegenerators/gaussianwhitenoise.h"

namespace {
void NoiseGeneration(mwSize N, double *y) {
  for (mwSize i = 0; i < N; ++i)
    y[i] = GenerateGWN();
}

void Reseed() {
  ReseedGWN();
}

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
  mwSize N;
  double *outMatrix;
  
  if (nrhs == 2) {
    Reseed();
    return;
  }

  // Get the number of samples required for noise generation.
  N = static_cast<mwSize>(mxGetScalar(prhs[0]));

  // Get a pointer to the output matrix.
  plhs[0] = mxCreateDoubleMatrix(1, N, mxREAL);
  outMatrix = mxGetPr(plhs[0]);

  NoiseGeneration(N, outMatrix);
}
