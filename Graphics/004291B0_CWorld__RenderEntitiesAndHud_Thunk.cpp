#include "tarzan_ghidra_types.hpp"

// Address: 0x004291B0
// Label: CWorld::RenderEntitiesAndHud_Thunk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::RenderEntitiesAndHud_Thunk(void)

{
  uint value2;
  byte *value4;
  int value;
  undefined *dataCursor;
  uint *dataCursor2;
  undefined4 value3;
  
  value4 = g_EntityEntryPool;
  if ((g_DeathRespawnFadeState & 0x10) == 0) {
    for (; value4 != (byte *)0x0; value4 = *(byte **)(value4 + 0x10)) {
      value = *(int *)(value4 + 0x38);
      if ((value != 0) && ((*value4 & 1) != 0)) {
        do {
          if ((*(uint *)(value4 + 0x28) & 0x10000) == 0) {
            *(undefined4 *)(value + 0x48) = *(undefined4 *)(value + 0x14);
            *(undefined4 *)(value + 0x4c) = *(undefined4 *)(value + 0x18);
            *(undefined4 *)(value + 0x50) = *(undefined4 *)(value + 0x1c);
          }
          if (*(int *)(value + 0x10) != 0) {
            RenderSceneHierarchy(value);
          }
          value = *(int *)(value + 0x34);
        } while (value != 0);
      }
    }
    if ((g_HudCountdownScene != 0) && ((g_HudCountdownFlags & 0x8000) != 0)) {
      RenderSceneHierarchy(g_HudCountdownScene);
    }
    if (g_HudCollectedSketchScene != 0) {
      RenderSceneHierarchy(g_HudCollectedSketchScene);
    }
    if (g_HudCollectedTARZANslotScene != 0) {
      RenderSceneHierarchy(g_HudCollectedTARZANslotScene);
    }
    if (g_HudPowerFruitSelectorScene != 0) {
      RenderSceneHierarchy(g_HudPowerFruitSelectorScene);
      if (g_HudPowerFruitSelectorBackScene != 0) {
        RenderSceneHierarchy(g_HudPowerFruitSelectorBackScene);
      }
      if (g_HudPowerFruitLeftAmmoDigitsScene != 0) {
        RenderSceneHierarchy(g_HudPowerFruitLeftAmmoDigitsScene);
      }
      if (g_HudPowerFruitRightAmmoDigitsScene != 0) {
        RenderSceneHierarchy(g_HudPowerFruitRightAmmoDigitsScene);
      }
    }
    dataCursor = &DAT_00533468;
    do {
      if ((*(ushort *)(dataCursor + 0xe) & 0x8000) != 0) {
        RenderSceneHierarchy(dataCursor);
      }
      dataCursor = dataCursor + 0x144;
    } while ((int)dataCursor < 0x533abc);
    dataCursor2 = &g_HudPartialHealthFillQuad;
    do {
      value2 = *dataCursor2;
      if ((value2 & 0x8000) != 0) {
        if ((short)dataCursor2[3] < 0x100) {
          value3 = 0x200;
          if ((value2 & 0x8002) == 0) {
LAB_0044483c:
            RenderHudSpriteQuad(dataCursor2,value3);
          }
          else {
            RenderHudSpriteQuadDefault();
          }
        }
        else {
          value3 = 0;
          if ((value2 & 0x8002) == 0) goto LAB_0044483c;
          RenderHudSpriteQuadDefault(dataCursor2,0);
        }
      }
      dataCursor2 = dataCursor2 + 0xe;
    } while ((int)dataCursor2 < 0x532469);
    dataCursor2 = &g_HudExtraLifeMeterIconQuad;
    do {
      if ((*dataCursor2 & 0x8000) != 0) {
        if ((*dataCursor2 & 0x8002) == 0) {
          RenderHudSpriteQuad(dataCursor2,0);
        }
        else {
          RenderHudSpriteQuadDefault();
        }
      }
      dataCursor2 = dataCursor2 + 0xe;
    } while ((int)dataCursor2 < 0x532708);
  }
  return;
}

