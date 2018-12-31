//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//
// MEX file for original velvet noise generation.
//-----------------------------------------------------------------------------
#include <stdint.h>

#include "mex.h"

#include "../src/noisegenerators/originalvelvetnoise.h"

namespace {
void NoiseGeneration(mwSize N, int *y) {
  for (mwSize i = 0; i < N; ++i)
    y[i] = GenerateOVN();
}

void Reseed() {
  ReseedOVN();
}

void SetAverageDistance(mwSize td) {
  SetAverageDistanceOVN(td);
}

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
  mwSize N;
  int *outMatrix;
  
  if (nrhs == 2) {
    int td = static_cast<int>(mxGetScalar(prhs[1]));
    if (td == 0) Reseed();
    else SetAverageDistance(td);
    return;
  }

  // Get the number of samples required for noise generation.
  N = static_cast<mwSize>(mxGetScalar(prhs[0]));

  // Get a pointer to the output matrix.
  plhs[0] = mxCreateNumericMatrix(1, N, mxINT32_CLASS, mxREAL);
  outMatrix = reinterpret_cast<int *>(mxGetPr(plhs[0]));

  NoiseGeneration(N, outMatrix);
}
