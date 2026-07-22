#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AB00
// Label: InitDefaultGraphicsLookupTable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitDefaultGraphicsLookupTable(void)

{
  byte *value3;
  int value;
  uint value2;
  undefined4 *dataCursor;
  byte localState [67];
  
  dataCursor = &graphicsRelatedBuffer;
  for (value = 0x40; value != 0; value = value + -1) {
    *dataCursor = 0xffffffff;
    dataCursor = dataCursor + 1;
  }
  localState[0] = 0x25;
  localState[1] = 0x27;
  localState[2] = 0x28;
  localState[3] = 0x29;
  localState[4] = 0x2b;
  localState[5] = 0x2c;
  localState[6] = 0x2d;
  localState[7] = 0x2e;
  localState[8] = 0x30;
  localState[9] = 0x31;
  localState[10] = 0x32;
  localState[0xb] = 0x33;
  localState[0xc] = 0x34;
  localState[0xd] = 0x35;
  localState[0xe] = 0x36;
  localState[0xf] = 0x37;
  localState[0x10] = 0x38;
  localState[0x11] = 0x39;
  localState[0x12] = 0x3a;
  localState[0x13] = 0x3f;
  localState[0x14] = 0x41;
  localState[0x15] = 0x42;
  localState[0x16] = 0x43;
  localState[0x17] = 0x44;
  localState[0x18] = 0x45;
  localState[0x19] = 0x46;
  localState[0x1a] = 0x47;
  localState[0x1b] = 0x48;
  localState[0x1c] = 0x49;
  localState[0x1d] = 0x4a;
  localState[0x1e] = 0x4b;
  localState[0x1f] = 0x4c;
  localState[0x20] = 0x4d;
  localState[0x21] = 0x4e;
  localState[0x22] = 0x4f;
  localState[0x23] = 0x50;
  localState[0x24] = 0x51;
  localState[0x25] = 0x52;
  localState[0x26] = 0x53;
  localState[0x27] = 0x54;
  localState[0x28] = 0x55;
  localState[0x29] = 0x56;
  localState[0x2a] = 0x57;
  localState[0x2b] = 0x58;
  localState[0x2c] = 0x59;
  localState[0x2d] = 0x5a;
  localState[0x2e] = 0xc0;
  localState[0x2f] = 0xc1;
  localState[0x30] = 0xc4;
  localState[0x31] = 0xc5;
  localState[0x32] = 0xc6;
  localState[0x33] = 200;
  localState[0x34] = 0xc9;
  localState[0x35] = 0xca;
  localState[0x36] = 0xcd;
  localState[0x37] = 0xce;
  localState[0x38] = 0xcf;
  localState[0x39] = 0xd3;
  localState[0x3a] = 0xd4;
  localState[0x3b] = 0xd6;
  localState[0x3c] = 0xd9;
  localState[0x3d] = 0xda;
  localState[0x3e] = 0xdc;
  localState[0x3f] = 0;
  value = 0;
  value2 = 0x21;
  do {
    *(char *)((int)&graphicsRelatedBuffer + value2) = (char)value;
    value3 = localState + value;
    value2 = (uint)*value3;
    value = value + 1;
  } while (*value3 != 0);
  *( undefined1 *)((int)&g_GraphicsTextScratchBuffer + 0) = 0;
  return;
}

