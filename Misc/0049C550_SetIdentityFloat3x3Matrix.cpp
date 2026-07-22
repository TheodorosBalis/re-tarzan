#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C550
// Label: SetIdentityFloat3x3Matrix
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetIdentityFloat3x3Matrix(undefined4 *arg1)

{
  arg1[8] = 0x3f800000;
  arg1[4] = 0x3f800000;
  *arg1 = 0x3f800000;
  arg1[7] = 0;
  arg1[6] = 0;
  arg1[5] = 0;
  arg1[3] = 0;
  arg1[2] = 0;
  arg1[1] = 0;
  return;
}

