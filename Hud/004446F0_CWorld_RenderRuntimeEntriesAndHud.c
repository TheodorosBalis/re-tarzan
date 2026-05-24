
void CWorld_RenderRuntimeEntriesAndHud(void)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  undefined *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  
  pbVar2 = DAT_005314e0;
  if ((g_DeathRespawnFadeState & 0x10) == 0) {
    for (; pbVar2 != (byte *)0x0; pbVar2 = *(byte **)(pbVar2 + 0x10)) {
      iVar3 = *(int *)(pbVar2 + 0x38);
      if ((iVar3 != 0) && ((*pbVar2 & 1) != 0)) {
        do {
          if ((*(uint *)(pbVar2 + 0x28) & 0x10000) == 0) {
            *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(iVar3 + 0x14);
            *(undefined4 *)(iVar3 + 0x4c) = *(undefined4 *)(iVar3 + 0x18);
            *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(iVar3 + 0x1c);
          }
          if (*(int *)(iVar3 + 0x10) != 0) {
            RenderSceneHierarchy(iVar3);
          }
          iVar3 = *(int *)(iVar3 + 0x34);
        } while (iVar3 != 0);
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
    puVar4 = &DAT_00533468;
    do {
      if ((*(ushort *)(puVar4 + 0xe) & 0x8000) != 0) {
        RenderSceneHierarchy(puVar4);
      }
      puVar4 = puVar4 + 0x144;
    } while ((int)puVar4 < 0x533abc);
    puVar5 = &g_HudPartialHealthFillQuad;
    do {
      uVar1 = *puVar5;
      if ((uVar1 & 0x8000) != 0) {
        if ((short)puVar5[3] < 0x100) {
          uVar6 = 0x200;
          if ((uVar1 & 0x8002) == 0) {
LAB_0044483c:
            RenderHudSpriteQuad(puVar5,uVar6);
          }
          else {
            RenderHudSpriteQuadDefault();
          }
        }
        else {
          uVar6 = 0;
          if ((uVar1 & 0x8002) == 0) goto LAB_0044483c;
          RenderHudSpriteQuadDefault(puVar5,0);
        }
      }
      puVar5 = puVar5 + 0xe;
    } while ((int)puVar5 < 0x532469);
    puVar5 = &g_HudExtraLifeMeterIconQuad;
    do {
      if ((*puVar5 & 0x8000) != 0) {
        if ((*puVar5 & 0x8002) == 0) {
          RenderHudSpriteQuad(puVar5,0);
        }
        else {
          RenderHudSpriteQuadDefault();
        }
      }
      puVar5 = puVar5 + 0xe;
    } while ((int)puVar5 < 0x532708);
  }
  return;
}

