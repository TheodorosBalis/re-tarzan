
void CEntities__InitThrowableFromPlayer(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  short sVar3;
  char cVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  iVar10 = *(int *)(param_1 + 0x38);
  if (iVar10 == 0) goto LAB_0048aeb9;
  piVar1 = (int *)(iVar10 + 0x14);
  *(int *)(iVar10 + 0x10) = g_WorldSceneEntryArrayBase + 0x3a8;
  GetSceneAttachmentWorldPositionByMask(g_PlayerSceneEntry,0x100,piVar1);
  *(undefined2 *)(iVar10 + 0x140) = 0;
  *(uint *)(iVar10 + 0x13c) = *(uint *)(iVar10 + 0x13c) | 1;
  *(undefined2 *)(iVar10 + 0xa6) = 1;
  uVar2 = *(undefined1 *)(g_PlayerSceneEntry + 0x75);
  *(byte *)(iVar10 + 0xe) = *(byte *)(iVar10 + 0xe) | 0x10;
  *(undefined1 *)(iVar10 + 0x75) = uVar2;
  (&g_PowerFruitAmmoType0)[g_SelectedThrowablePowerFruitType] =
       (&g_PowerFruitAmmoType0)[g_SelectedThrowablePowerFruitType] + -1;
  *(undefined1 *)(iVar10 + 0x74) = 0x7f;
  iVar6 = CEntities__CreateRuntimeMotionStateAttachment(param_1);
  if (iVar6 != 0) {
    if (g_PlayerCurrentCollisionMode == 1) {
      *(undefined2 *)(param_1 + 0x46) = 0x10;
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(g_RuntimeEntityTypeCallbackTable + 0x84);
      iVar7 = FUN_0042f520();
      if (iVar7 == 0) {
        *(int *)(param_1 + 0x4c) = (int)*(short *)(g_PlayerSceneEntry + 0xa2);
        *(undefined4 *)(iVar6 + 0x20) = 0;
      }
      else {
        sVar3 = *(short *)(g_PlayerSceneEntry + 0xa2);
        iVar7 = GetAngleFromXZVector12Bit
                          (*(int *)(iVar7 + 0x14) - *piVar1,
                           *(int *)(iVar7 + 0x1c) - *(int *)(iVar10 + 0x1c));
        uVar8 = iVar7 - 0x800U & 0xfff;
        if ((((sVar3 + -0x180) * 0x100000 >> 0x14 & 0xfffU) < uVar8) &&
           (uVar8 < ((sVar3 + 0x180) * 0x100000 >> 0x14 & 0xfffU))) {
          *(uint *)(param_1 + 0x4c) = uVar8;
          *(undefined4 *)(iVar6 + 0x20) = 0;
        }
        else {
          *(int *)(param_1 + 0x4c) = (int)*(short *)(g_PlayerSceneEntry + 0xa2);
          *(undefined4 *)(iVar6 + 0x20) = 0;
        }
      }
    }
    else {
      iVar7 = FUN_0048a9d0(piVar1);
      if (iVar7 != 0) {
        *(int *)(param_1 + 0x50) = iVar7;
      }
      uVar8 = (int)*(uint *)(g_PlayerSceneEntry + 0x58) >> 0x1f;
      if ((int)((*(uint *)(g_PlayerSceneEntry + 0x58) ^ uVar8) - uVar8) < 0x41) {
        if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
          uVar5 = 0x400 - *(short *)(g_PlayerSceneEntry + 0x130);
        }
        else {
          uVar5 = *(short *)(g_PlayerSceneEntry + 0x130) - 0x400;
        }
        *(int *)(iVar6 + 0x20) =
             (short)(&g_SinCosTable12Bit)[(uVar5 & 0xfff) - 0x400 & 0xfff] * 0x50 >> 0xc;
      }
      else if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x38), iVar7 != 0)) {
        uVar8 = *(int *)(g_PlayerSceneEntryData + 8) - *(int *)(iVar7 + 0x14);
        uVar9 = (int)uVar8 >> 0x1f;
        iVar7 = GetAngleFromXZVector12Bit
                          ((uVar8 ^ uVar9) - uVar9,
                           *(int *)(g_PlayerSceneEntryData + 0xc) - *(int *)(iVar7 + 0x18));
        *(int *)(iVar6 + 0x20) =
             (short)(&g_SinCosTable12Bit)[(iVar7 - 0x400U & 0xfff) - 0x400 & 0xfff] * 0x50 >> 0xc;
      }
    }
  }
  if (g_SelectedThrowablePowerFruitType == 1) {
    *(undefined2 *)(iVar10 + 0xc) = 0x202b;
    *(undefined2 *)(param_1 + 0x4a) = 8;
    if (iVar6 != 0) {
      if (g_PlayerThrowLowArcSelected == '\0') {
        *(undefined4 *)(iVar6 + 0x1c) = 0;
        *(undefined4 *)(iVar6 + 0x10) = 0x60;
        *(undefined4 *)(iVar6 + 0x14) = 0;
        *(undefined4 *)(iVar6 + 0x18) = 0;
        *(undefined4 *)(iVar6 + 0x20) = 0x60;
        goto LAB_0048ae9f;
      }
      *(undefined4 *)(iVar6 + 0x10) = 0x10;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      *(undefined4 *)(iVar6 + 0x14) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(undefined4 *)(iVar6 + 0x20) = 0xffffffa0;
      *(undefined4 *)(iVar6 + 0x2c) = 0x80;
      *(undefined4 *)(iVar6 + 0x28) = 8;
    }
  }
  else if (g_SelectedThrowablePowerFruitType == 2) {
    *(undefined2 *)(iVar10 + 0xc) = 0x202c;
    *(undefined2 *)(param_1 + 0x4a) = 4;
    cVar4 = RandomModulo(4);
    *(char *)(iVar10 + 0x74) = cVar4 + '\x03';
    if (iVar6 != 0) {
      *(undefined4 *)(iVar6 + 0x10) = 0x60;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      *(undefined4 *)(iVar6 + 0x14) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
LAB_0048ae9f:
      *(undefined4 *)(iVar6 + 0x2c) = 0x80;
      *(undefined4 *)(iVar6 + 0x28) = 0;
    }
  }
  else if (g_SelectedThrowablePowerFruitType == 3) {
    *(undefined2 *)(iVar10 + 0xc) = 0x2026;
    iVar7 = CreateRuntimeEntitySceneEntry(param_1,0x16);
    if (iVar7 != 0) {
      *(int *)(iVar7 + 0x14) = *piVar1;
      *(undefined4 *)(iVar7 + 0x18) = *(undefined4 *)(iVar10 + 0x18);
      *(undefined4 *)(iVar7 + 0x1c) = *(undefined4 *)(iVar10 + 0x1c);
      iVar10 = g_WorldSceneEntryArrayBase + 0x3a8;
      *(ushort *)(iVar7 + 0xe) = *(ushort *)(iVar7 + 0xe) | 0x1421;
      *(int *)(iVar7 + 0x10) = iVar10;
      *(undefined2 *)(iVar7 + 0xc) = 0x2032;
      *(undefined4 *)(iVar7 + 0x30) = 0x800;
    }
    *(undefined2 *)(param_1 + 0x4a) = 3;
    if (iVar6 != 0) {
      *(undefined4 *)(iVar6 + 0x10) = 0x60;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      *(undefined4 *)(iVar6 + 0x14) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + -8;
      *(undefined4 *)(iVar6 + 0x2c) = 0x80;
      *(undefined4 *)(iVar6 + 0x28) = 2;
    }
  }
  else {
    *(undefined2 *)(iVar10 + 0xc) = 0x202e;
    *(undefined2 *)(param_1 + 0x4a) = 1;
    if (iVar6 != 0) {
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      *(undefined4 *)(iVar6 + 0x14) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(undefined4 *)(iVar6 + 0x10) = 0x60;
      *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + -8;
      *(undefined4 *)(iVar6 + 0x2c) = 0x80;
      *(undefined4 *)(iVar6 + 0x28) = 3;
    }
  }
  CEntities__LinkRuntimeEntryIntoProcessingList(&g_ActiveThrowableRuntimeEntryList,param_1);
LAB_0048aeb9:
  *(undefined2 *)(param_1 + 0x48) = 5;
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    g_PlayerHeldThrowableRuntimeEntry = param_1;
    return;
  }
  CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  return;
}

