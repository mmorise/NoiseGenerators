//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//
// Generate Gaussian white noise (GWN).
//-----------------------------------------------------------------------------
#include "noisegenerators/gaussianwhitenoise.h"

#include <stdint.h>

namespace {
// I have no idea to implement the functions without global variables.
static uint32_t g_randn_x = 123456789;
static uint32_t g_randn_y = 362436069;
static uint32_t g_randn_z = 521288629;
static uint32_t g_randn_w = 88675123;

}  // namespace

void ReseedGWN() {
  g_randn_x = 123456789;
  g_randn_y = 362436069;
  g_randn_z = 521288629;
  g_randn_w = 88675123;
}

double GenerateGWN() {
  uint32_t t;
  t = g_randn_x ^ (g_randn_x << 11);
  g_randn_x = g_randn_y;
  g_randn_y = g_randn_z;
  g_randn_z = g_randn_w;
  g_randn_w = (g_randn_w ^ (g_randn_w >> 19)) ^ (t ^ (t >> 8));

  uint32_t tmp = g_randn_w >> 4;
  for (int i = 0; i < 11; ++i) {
    t = g_randn_x ^ (g_randn_x << 11);
    g_randn_x = g_randn_y;
    g_randn_y = g_randn_z;
    g_randn_z = g_randn_w;
    g_randn_w = (g_randn_w ^ (g_randn_w >> 19)) ^ (t ^ (t >> 8));
    tmp += g_randn_w >> 4;
  }
  return tmp / 268435456.0 - 6.0;
}
