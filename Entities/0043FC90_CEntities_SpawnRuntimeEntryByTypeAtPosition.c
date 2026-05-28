
int * CEntities__SpawnRuntimeEntryByTypeAtPosition
                (undefined4 param_1,undefined4 param_2,undefined4 param_3,ushort param_4,
                byte param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *local_4;
  
  piVar1 = g_FreeRuntimeEntryListHead;
  local_4 = (int *)0x0;
  if ((param_4 != 0) && (uVar2 = (uint)param_4, (int)uVar2 < g_RuntimeEntityTypeCount)) {
    if (g_FreeRuntimeEntryListHead == (int *)0x0) {
      return (int *)0x0;
    }
    g_FreeRuntimeEntryListHead = (int *)g_FreeRuntimeEntryListHead[4];
    if (g_FreeRuntimeEntryListHead != (int *)0x0) {
      g_FreeRuntimeEntryListHead[3] = 0;
    }
    local_4 = piVar1;
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    piVar4 = &g_RuntimeEntryDefaultTemplate;
    piVar5 = piVar1;
    for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    *piVar1 = 1;
    g_ActiveRuntimeEntryListTail[4] = (int)piVar1;
    piVar1[3] = (int)g_ActiveRuntimeEntryListTail;
    g_ActiveRuntimeEntryListTail = piVar1;
    *(ushort *)((int)piVar1 + 0x46) = param_4;
    piVar1[0xb] = *(int *)(g_RuntimeEntityTypeCallbackTable + uVar2 * 8);
    piVar1[0xc] = *(int *)(g_RuntimeEntityTypeCallbackTable + 4 + uVar2 * 8);
    if ((param_5 & 1) != 0) {
      iVar3 = CreateRuntimeEntitySceneEntry(piVar1,1);
      if (iVar3 == 0) goto LAB_0043fd8b;
      *(undefined4 *)(iVar3 + 0x18) = param_2;
      *(undefined4 *)(iVar3 + 0x14) = param_1;
      *(undefined4 *)(iVar3 + 0x1c) = param_3;
    }
    if ((param_5 & 2) != 0) {
      iVar3 = CreateRuntimeEntitySourceSceneRef(piVar1);
      if (iVar3 == 0) {
LAB_0043fd8b:
        if ((param_5 & 0x10) != 0) {
          CEntities__ReleaseRuntimeEntryToFreeList(piVar1);
        }
        return (int *)0x0;
      }
      *(undefined4 *)(iVar3 + 0x10) = param_2;
      *(undefined4 *)(iVar3 + 0xc) = param_1;
      *(undefined4 *)(iVar3 + 0x14) = param_3;
    }
    (*(code *)piVar1[0xb])(piVar1);
    if (*piVar1 == 0) {
      local_4 = (int *)0x0;
    }
  }
  return local_4;
}

