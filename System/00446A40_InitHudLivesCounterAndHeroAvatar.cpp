#include "tarzan_ghidra_types.hpp"

// Address: 0x00446A40
// Label: InitHudLivesCounterAndHeroAvatar
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudLivesCounterAndHeroAvatar(void)

{
  short shortValue;
  undefined4 value;
  undefined4 value2;
  undefined4 value3;
  undefined2 *dataCursor;
  short *value4;
  
  value3 = g_HudLivesCounterScene_Field2C;
  value2 = g_HudLivesCounterScene_Field28;
  _g_HudLifeGainPortraitScene_Field10 = g_WorldEntitySceneObjectArrayBase + 0x68;
  g_HudLivesCounterScene = &DAT_00533468;
  g_HudLivesCounterScene_Field0E = 0x8100;
  _g_HudLivesCounterScene_Field54 = 0x1d400;
  _g_HudLivesCounterScene_Field58 = 0xde00;
  _g_HudLivesCounterScene_Field5C = 0;
  _g_HudLivesCounterScene_Field0C = 0x200c;
  _g_HudLivesCounterScene_Field38 = &DAT_005320e0;
  _g_HudLivesDigitList_Field0C = 3;
  value4 = &DAT_004f0276;
  dataCursor = &g_HudLivesDigitList_Field12;
  _g_HudLivesCounterScene_Field10 = _g_HudLifeGainPortraitScene_Field10;
  do {
    shortValue = value4[-1];
    *(int *)(dataCursor + 1) = _g_HudLifeGainPortraitScene_Field10;
    *dataCursor = 0;
    value = g_HudLivesCounterScene_Field20;
    *(int *)(dataCursor + 3) = (int)shortValue;
    *(int *)(dataCursor + 5) = (int)*value4;
    *(undefined4 *)(dataCursor + 7) = 0xffffffc4;
    value4 = value4 + 2;
    *(undefined4 *)(dataCursor + 9) = value;
    *(undefined4 *)(dataCursor + 0xb) = g_HudLivesCounterScene_Field24;
    *(undefined4 *)(dataCursor + 0xd) = value2;
    *(undefined4 *)(dataCursor + 0xf) = value3;
    dataCursor = dataCursor + 0x14;
  } while ((int)value4 < 0x4f0282);
  _g_HudLivesOnesDigitSprite = *( undefined1 *)((int)&g_LevelTransitionContext + 3) + 0x200f;
  _g_HudLivesAvatarScene_Field58 = 0xde00;
  _g_HudLivesAvatarScene_Field10 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
  _g_HudLifeGainPortraitScene_Field58 = 0xde00;
  g_HudHeroRewardSetIndex = 0;
  _g_HudLifeGainPortraitScene_Field5C = 0;
  g_HudLivesDigitList_Field12 = 0x8100;
  _g_HudLivesTensDigitSprite = 0x200f;
  g_HudLivesAvatarScene = &DAT_005335ac;
  g_HudLivesAvatarScene_Field0E = 0x8100;
  _g_HudLivesAvatarScene_Field54 = 0x3000;
  _g_HudLivesAvatarScene_Field5C = 0xffffffc4;
  _g_HudLivesAvatarScene_Field0C = 0x202a;
  _g_HudLivesAvatarScene_FieldA6 = 1;
  _g_HudLivesAvatarScene_Field6C = 0xffffffce;
  _g_HudLifeGainPortraitScene = &DAT_005336f0;
  _g_HudLifeGainPortraitScene_FieldA6 = 1;
  _g_HudLifeGainPortraitScene_Field0E = 0x8100;
  _g_HudLifeGainPortraitScene_Field54 = 0x3200;
  _g_HudLifeGainPortraitScene_Field6C = 0xffffffe2;
  _g_HudLifeGainPortraitScene_Field0C = 0x200b;
  g_HudLifeGainPortraitFrameIndex = 0xffffffff;
  return;
}

