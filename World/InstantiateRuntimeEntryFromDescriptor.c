// 0043fdd0

int * InstantiateRuntimeEntryFromDescriptor(undefined4 *param_1)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  piVar5 = g_FreeRuntimeEntryListHead;
  uVar1 = *(ushort *)(param_1 + 6);
  uVar6 = (uint)uVar1;
  if (uVar6 == 0) {
    return (int *)0x0;
  }
  if (DAT_00531b60 <= (int)uVar6) {
    return (int *)0x0;
  }
  if (g_FreeRuntimeEntryListHead != (int *)0x0) {
    g_FreeRuntimeEntryListHead = (int *)g_FreeRuntimeEntryListHead[4];
    if (g_FreeRuntimeEntryListHead != (int *)0x0) {
      g_FreeRuntimeEntryListHead[3] = 0;
    }
    if (piVar5 == (int *)0x0) {
      return (int *)0x0;
    }
    piVar8 = &DAT_00531b08;
    piVar9 = piVar5;
    for (iVar7 = 0x15; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar9 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar9 = piVar9 + 1;
    }
    *piVar5 = 1;
    DAT_00531afc[4] = (int)piVar5;
    piVar5[3] = (int)DAT_00531afc;
    DAT_00531afc = piVar5;
    *(ushort *)((int)piVar5 + 0x46) = uVar1;
    piVar5[0xd] = (int)param_1;
    *(ushort *)((int)param_1 + 0x1a) = *(ushort *)((int)param_1 + 0x1a) | 1;
    piVar5[0xb] = *(int *)(DAT_00531cac + uVar6 * 8);
    piVar5[0xc] = *(int *)(DAT_00531cac + 4 + uVar6 * 8);
    sVar2 = *(short *)((int)param_1 + 0x16);
    if ((sVar2 == 1) || ((sVar2 != 2 && (sVar2 != 3)))) {
      bVar4 = false;
      bVar3 = true;
    }
    else {
      bVar4 = true;
      bVar3 = false;
    }
    if (bVar3) {
      iVar7 = CreateRuntimeEntitySceneEntry(piVar5,1);
      if (iVar7 == 0) {
        ReleaseRuntimeEntryToFreeList(piVar5);
        return (int *)0x0;
      }
      *(undefined4 *)(iVar7 + 0x14) = *param_1;
      *(undefined4 *)(iVar7 + 0x18) = param_1[1];
      *(undefined4 *)(iVar7 + 0x1c) = param_1[2];
      *(char *)(iVar7 + 0x75) = -((*(byte *)((int)param_1 + 0x1a) & 0x20) != 0);
      *(uint *)(iVar7 + 0x110) = param_1[3] & 0x1ff;
      *(uint *)(iVar7 + 0x10c) = (uint)param_1[3] >> 9;
      if (*(short *)((int)param_1 + 0x16) == 1) {
        *(undefined4 *)(iVar7 + 0x108) = 1;
      }
      else {
        *(undefined4 *)(iVar7 + 0x108) = 0;
      }
      UpdateRuntimeEntitySceneEntryTransformFromPlacement(iVar7);
    }
    if (bVar4) {
      piVar8 = (int *)param_1[3];
      iVar7 = CreateRuntimeEntitySourceSceneRef(piVar5);
      if (iVar7 == 0) {
        ReleaseRuntimeEntryToFreeList(piVar5);
        return (int *)0x0;
      }
      *(undefined4 *)(iVar7 + 0xc) = *param_1;
      *(undefined4 *)(iVar7 + 0x10) = param_1[1];
      *(undefined4 *)(iVar7 + 0x14) = param_1[2];
      if (*(short *)((int)param_1 + 0x16) == 2) {
        *(int *)(iVar7 + 0x18) = *piVar8 + (int)piVar8;
      }
      else if (*(short *)((int)param_1 + 0x16) == 3) {
        *(int *)(iVar7 + 0x18) = *piVar8 + (int)piVar8;
        *(short *)(iVar7 + 0x30) = (short)piVar8[2];
        *(short *)(iVar7 + 0x32) = (short)piVar8[1];
        *(undefined2 *)(iVar7 + 0x34) = *(undefined2 *)((int)piVar8 + 6);
      }
    }
    (*(code *)piVar5[0xb])(piVar5);
    if (*piVar5 != 0) {
      return piVar5;
    }
  }
  return (int *)0x0;
}