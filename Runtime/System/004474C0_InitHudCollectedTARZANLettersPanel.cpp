#include "tarzan_ghidra_types.hpp"

// Address: 0x004474C0
// Label: InitHudCollectedTARZANLettersPanel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudCollectedTARZANLettersPanel(void)

{
  int value;
  short shortValue;
  undefined4 value2;
  undefined4 value3;
  undefined2 *dataCursor;
  short *value4;
  
  value3 = g_HudCollectedTARZANScene_Field2C;
  value = g_WorldEntitySceneObjectArrayBase + 0x68;
  g_HudCollectedTARZANslotScene = &DAT_00532e14;
  _g_HudCollectedTARZANScene_Field0C = 0;
  _g_HudCollectedTARZANScene_Field0E = 0x121;
  _g_HudCollectedTARZANScene_Field54 = 0x10000;
  _g_HudCollectedTARZANScene_Field58 = 0x5000;
  _g_HudCollectedTARZANScene_Field1C = 0;
  _g_HudCollectedTARZANScene_Field30 = 0x400;
  _g_HudCollectedTARZANScene_FieldA6 = 1;
  _g_HudTARZANLetterQuadList_Field0C = 6;
  value4 = &DAT_004f0334;
  dataCursor = &g_HudTARZANLetterQuad0Flags;
  _g_HudCollectedTARZANScene_Field10 = value;
  do {
    value2 = g_HudCollectedTARZANScene_Field20;
    shortValue = *value4;
    *(int *)(dataCursor + 1) = value;
    *dataCursor = 0x8521;
    *(int *)(dataCursor + 3) = (int)shortValue;
    *(undefined4 *)(dataCursor + 5) = 0;
    *(undefined4 *)(dataCursor + 7) = 0;
    value4 = value4 + 1;
    *(undefined4 *)(dataCursor + 9) = value2;
    *(undefined4 *)(dataCursor + 0xb) = g_HudCollectedTARZANScene_Field24;
    *(undefined4 *)(dataCursor + 0xd) = g_HudCollectedTARZANScene_Field28;
    *(undefined4 *)(dataCursor + 0xf) = value3;
    *(undefined4 *)(dataCursor + 0x11) = 0x400;
    dataCursor = dataCursor + 0x14;
  } while ((int)value4 < 0x4f0340);
  _g_HudTARZANLetterQuadList_Field10 = 0x2005;
  _g_HudTARZANLetterQuadList_Field38 = 0x2006;
  _g_HudTARZANLetterQuadList_Field60 = 0x2007;
  _g_HudTARZANLetterQuadList_Field88 = 0x2008;
  _g_HudTARZANLetterQuadList_FieldB0 = 0x2006;
  _g_HudTARZANLetterQuadList_FieldD8 = 0x2009;
  g_CollectedTARZANLetterMask6 = 0;
  g_HudCollectedTARZANslotSlideTicks = 0x78;
  return;
}

