#include "tarzan_ghidra_types.hpp"

// Address: 0x00447D50
// Label: InitHudTokenCounter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudTokenCounter(void)

{
  int count;
  undefined4 value;
  undefined2 *dataCursor;
  undefined4 *dataCursor2;
  
  count = g_WorldEntitySceneObjectArrayBase + 0x68;
  g_HudTokenCounterScene = &DAT_00533834;
  _g_HudTokenCounterScene_Field10 = &g_LanguageFontAssetSet;
  _g_HudTokenCounterScene_Field0C = 0x2000;
  _g_HudTokenCounterScene_Field38 = &DAT_005329a8;
  _g_HudTokenCounterScene_Field0E = 0x8121;
  _g_HudTokenCounterScene_Field54 = 0x1cc00;
  _g_HudTokenCounterScene_Field58 = 0x2800;
  _g_HudTokenCounterScene_Field1C = 0;
  _g_HudTokenCounterScene_Field30 = 0x600;
  _g_HudTokenDigitList_Field0C = 3;
  dataCursor2 = &DAT_004f0268;
  dataCursor = &DAT_005329ba;
  do {
    value = *dataCursor2;
    *(int *)(dataCursor + 1) = count;
    *dataCursor = 0x8100;
    *(undefined4 *)(dataCursor + 3) = value;
    *(undefined4 *)(dataCursor + 5) = 0;
    *(undefined4 *)(dataCursor + 7) = 0xffffffc4;
    dataCursor2 = dataCursor2 + 1;
    dataCursor = dataCursor + 0x14;
  } while ((int)dataCursor2 < 0x4f0274);
  g_HudTokenCounterSpinFrame = 0;
  _g_HudExtraLifeAwardScene_Field1C = 0;
  _g_HudTokenOnesDigitSprite = 0x200f;
  _g_HudTokenTensDigitSprite = 0x200f;
  _g_HudTokenHundredsDigitSprite = 0x200f;
  g_HudTokenCounterSlideTicks = 0x78;
  g_HudExtraLifeAwardScene = &DAT_00533978;
  _g_HudExtraLifeAwardScene_Field10 = &g_LanguageFontAssetSet;
  _g_HudExtraLifeAwardScene_Field0C = 0x2000;
  _g_HudExtraLifeAwardScene_Field0E = 0x100;
  _g_HudExtraLifeAwardScene_Field54 = 0x1cc00;
  _g_HudExtraLifeAwardScene_Field58 = 0x2800;
  _g_HudExtraLifeAwardScene_Field30 = 0x600;
  _g_HudExtraLifeAwardScene_Field6C = 0xffffffc4;
  return;
}

