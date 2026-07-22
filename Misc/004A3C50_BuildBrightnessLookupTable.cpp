#include "tarzan_ghidra_types.hpp"

// Address: 0x004A3C50
// Label: BuildBrightnessLookupTable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildBrightnessLookupTable(uint arg1)

{
  int value;
  int value2;
  int value3;
  int value4;
  
  value4 = (arg1 ^ (int)arg1 >> 0x1f) - ((int)arg1 >> 0x1f);
  if (value4 < 0x3d) {
    if (value4 < 10) {
      value4 = 10;
    }
  }
  else {
    value4 = 0x46;
  }
  value = 0;
  value3 = 0;
  do {
    value2 = value3 / 0x32;
    if (0xfe < value2) {
      value2 = 0xff;
    }
    (&g_BrightnessLookupTable)[value] = (char)value2;
    value = value + 1;
    value3 = value3 + value4;
  } while (value < 0x100);
  g_IsBrightnessLookupIdentity = (uint)(value4 == 0x32);
  return;
}

