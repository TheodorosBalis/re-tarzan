#include "tarzan_ghidra_types.hpp"

// Address: 0x004468D0
// Label: InitHudCollectedSketchPanel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudCollectedSketchPanel(void)

{
  int value;
  undefined4 value2;
  undefined4 value3;
  undefined4 value4;
  undefined2 *dataCursor;
  undefined2 *dataCursor2;
  
  value4 = g_HudCollectedSketchScene_Field2C;
  value3 = g_HudCollectedSketchScene_Field28;
  value = g_WorldEntitySceneObjectArrayBase + 0x68;
  g_HudCollectedSketchScene = &DAT_00532cd0;
  _g_HudCollectedSketchScene_Field0C = 0;
  _g_HudCollectedSketchScene_Field38 = &DAT_00532830;
  _g_HudCollectedSketchScene_Field0E = 0x521;
  _g_HudCollectedSketchScene_Field54 = 0x10000;
  _g_HudCollectedSketchScene_Field58 = 0xfffff100;
  _g_HudCollectedSketchScene_Field5C = 0;
  _g_HudCollectedSketchScene_Field30 = 0x600;
  _g_HudSketchPieceQuadList_Field0C = 4;
  dataCursor = &g_HudSketchPieceQuad0Flags;
  _g_HudCollectedSketchScene_Field10 = value;
  do {
    value2 = g_HudCollectedSketchScene_Field20;
    *(int *)(dataCursor + 1) = value;
    *dataCursor = 0x8521;
    *(undefined4 *)(dataCursor + 3) = 0;
    *(undefined4 *)(dataCursor + 5) = 0;
    *(undefined4 *)(dataCursor + 7) = 0;
    dataCursor2 = dataCursor + 0x14;
    *(undefined4 *)(dataCursor + 9) = value2;
    *(undefined4 *)(dataCursor + 0xb) = g_HudCollectedSketchScene_Field24;
    *(undefined4 *)(dataCursor + 0xd) = value3;
    *(undefined4 *)(dataCursor + 0xf) = value4;
    *(undefined4 *)(dataCursor + 0x11) = 0x600;
    dataCursor = dataCursor2;
  } while ((int)dataCursor2 < 0x5328e2);
  _g_HudSketchPieceQuadList_Field10 = 0x2000;
  _g_HudSketchPieceQuadList_Field38 = 0x2001;
  _g_HudSketchPieceQuadList_Field60 = 0x2002;
  _g_HudSketchPieceQuadList_Field88 = 0x2003;
  g_CollectedSketchPieceMask4 = 0;
  g_HudCollectedSketchSlideTicks = 0x78;
  return;
}

