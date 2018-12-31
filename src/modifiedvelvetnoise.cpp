//-----------------------------------------------------------------------------
// Copyright 2019 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2019/01/01
//
// Generate modified velvet noise (MVN).
//-----------------------------------------------------------------------------
#include "noisegenerators/modifiedvelvetnoise.h"

#include <stdint.h>

namespace {
// I have no idea to implement the functions without global variables.
// If you want to know the reason how to obtain the valuables,
// please see the paper.
static int base_fs = 48000;
static int length_list[] = { 152, 400 };
static int current_position = 152;
static int chunk_length = 152;
static int count = 0;
static uint64_t g_randi_mvn = 88172645463325252ULL;

// Note: Behavior of this function is different from that of MATLAB.
// MATLAB: 1 ... imax
// C++   : 0 ... imax - 1
int randi(int imax) {
  g_randi_mvn = g_randi_mvn ^ (g_randi_mvn << 7);
  g_randi_mvn = g_randi_mvn ^ (g_randi_mvn >> 9);
  return g_randi_mvn % imax;
}

void UpdateChunk(int *chunk, int *amplitude) {
  // Determination of the chunk_length.
  // td = 4;
  chunk_length = length_list[randi(2)];
  int number_of_pulses = chunk_length / 4;

  // Amplitude of pulse is 2 or -2.
  for (int i = 0; i < number_of_pulses / 2; ++i) amplitude[i] = 2;
  for (int i = number_of_pulses / 2; i < number_of_pulses; ++i)
    amplitude[i] = -2;

  // Randomization of the amplitudes
  int tmp_index, tmp;
  for (int i = 0; i < number_of_pulses; ++i) {
    tmp_index = randi(number_of_pulses);
    tmp = amplitude[tmp_index];
    amplitude[tmp_index] = amplitude[i];
    amplitude[i] = tmp;
  }

  // Temporal positions with an amplitude other than zero are determined.
  for (int i = 0; i < number_of_pulses; ++i) chunk[i] = i * 4 + randi(4);

  // Reset the current_position.
  current_position = 0;
  count = 0;
}

}  // namespace

void ReseedMVN() {
  g_randi_mvn = 88172645463325252ULL;
  base_fs = 48000;
  length_list[0] = 152;
  length_list[1] = 400;
  current_position = 152;
  chunk_length = 152;
  count = 0;
}

void SetSamplingFrequencyMVN(int fs) {
  if (base_fs == fs) return;
  g_randi_mvn = 88172645463325252ULL;
  base_fs = fs;
  length_list[0] = static_cast<int>(152.0 * base_fs / 384000.0) * 8;
  length_list[1] = static_cast<int>(400.0 * base_fs / 384000.0) * 8;
  current_position = length_list[0];
  chunk_length = length_list[0];
  count = 0;
}

int GenerateMVN() {
  // initialization
  static int chunk[200];
  static int amplitude[200];

  if (current_position == chunk_length)
    UpdateChunk(chunk, amplitude);

  return chunk[count] == current_position++ ? amplitude[count++] : 0;
}
