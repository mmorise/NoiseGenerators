//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//
// Note: We obtain three noises (MVN, OVN, and GWN).
//       MVN: Modified velvet noise [1]
//       OVN: Original velvet noise [2]
//       GWN: Gaussian white noise
//
// Reference:
// [1] M. Morise: Modification of velvet noise for speech waveform generation
// by using vocoder-based speech synthesizer, IEICE transactions on information
// and systems, vol. E102-D, no. 3, pp. xxx-xxx, March 2019.
// [2] M. Karjalainen and H. Järveläien: Reverberation modeling using velvet
// noise, in Proc. AES 2007, 9-page, 2007.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "noisegenerators/modifiedvelvetnoise.h"
#include "noisegenerators/originalvelvetnoise.h"
#include "noisegenerators/gaussianwhitenoise.h"

#if (defined (__WIN32__) || defined (_WIN32)) && !defined (__MINGW32__)
#pragma warning(disable : 4996)
#endif

int main() {
  int N = 1000;
  //---------------------------------------------------------------------------
  // Test for generating modified velvet noise (MVN)
  //---------------------------------------------------------------------------
  FILE *fp = fopen("output_mvn.txt", "w");
  // Default fs is set to 48000.
  SetSamplingFrequencyMVN(48000);
  ReseedMVN();
  for (int i = 0; i < N; ++i) {
    fprintf(fp, "%d\n", GenerateMVN());
  }
  fclose(fp);

  //---------------------------------------------------------------------------
  // Test for generating original velvet noise (OVN)
  //---------------------------------------------------------------------------
  fp = fopen("output_ovn.txt", "w");
  // Default td is set to 4 sample.
  SetAverageDistanceOVN(4);
  ReseedOVN();
  for (int i = 0; i < N; ++i) {
    fprintf(fp, "%d\n", GenerateOVN());
  }
  fclose(fp);

  //---------------------------------------------------------------------------
  // Test for generating Gaussian white noise (GWN)
  //---------------------------------------------------------------------------
  fp = fopen("output_gwn.txt", "w");
  ReseedGWN();
  for (int i = 0; i < N; ++i) {
    fprintf(fp, "%.10f\n", GenerateGWN());
  }
  fclose(fp);

  return 0;
}