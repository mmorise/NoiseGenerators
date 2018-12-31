//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//
// Generate original velvet noise (OVN).
//-----------------------------------------------------------------------------
#include "noisegenerators/originalvelvetnoise.h"

#include <stdint.h>

namespace {
// I have no idea to implement the functions without global variables.
static int current_position = 4;
static int base_td = 4;
static uint64_t g_randi_ovn = 88172645463325252ULL;

// Note: Behavior of this function is different from that of MATLAB.
// MATLAB: 1 ... imax
// C++   : 0 ... imax - 1
int randi(int imax) {
  g_randi_ovn = g_randi_ovn ^ (g_randi_ovn << 7);
  g_randi_ovn = g_randi_ovn ^ (g_randi_ovn >> 9);
  return g_randi_ovn % imax;
}

}  // namespace

void ReseedOVN() {
  g_randi_ovn = 88172645463325252ULL;
  current_position = 0;
}

void SetAverageDistanceOVN(int td) {
  base_td = td;
  current_position = base_td;
}

int GenerateOVN() {
  // initialization
  static int chunk = 0;

  if (base_td <= current_position) {
    current_position = 0;
    chunk = randi(base_td);
  }
  int answer = 0;
  if (current_position == chunk) {
    answer = randi(2) == 0 ? -1 : 1;
  }
  current_position++;

  return answer;
}
