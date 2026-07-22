#include "tarzan_ghidra_types.hpp"

// Address: 0x0043FDD0
// Label: InstantiateEntityFromDescriptor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int * InstantiateEntityFromDescriptor(undefined4 *arg1)

{
  ushort value;
  short shortValue;
  bool flagByte;
  bool flagByte2;
  int *intCursor;
  uint value2;
  int entry;
  int *intCursor2;
  int *intCursor3;
  
  intCursor = g_FreeEntityListHead;
  value = *(ushort *)(arg1 + 6);
  value2 = (uint)value;
  if (value2 == 0) {
    return (int *)0x0;
  }
  if (g_EntityTypeCount <= (int)value2) {
    return (int *)0x0;
  }
  if (g_FreeEntityListHead != (int *)0x0) {
    g_FreeEntityListHead = (int *)g_FreeEntityListHead[4];
    if (g_FreeEntityListHead != (int *)0x0) {
      g_FreeEntityListHead[3] = 0;
    }
    if (intCursor == (int *)0x0) {
      return (int *)0x0;
    }
    intCursor2 = &g_EntityDefaultTemplate;
    intCursor3 = intCursor;
    for (entry = 0x15; entry != 0; entry = entry + -1) {
      *intCursor3 = *intCursor2;
      intCursor2 = intCursor2 + 1;
      intCursor3 = intCursor3 + 1;
    }
    *intCursor = 1;
    g_ActiveEntityListTail[4] = (int)intCursor;
    intCursor[3] = (int)g_ActiveEntityListTail;
    g_ActiveEntityListTail = intCursor;
    *(ushort *)((int)intCursor + 0x46) = value;
    intCursor[0xd] = (int)arg1;
    *(ushort *)((int)arg1 + 0x1a) = *(ushort *)((int)arg1 + 0x1a) | 1;
    intCursor[0xb] = *(int *)(g_EntityTypeCallbackTable + value2 * 8);
    intCursor[0xc] = *(int *)(g_EntityTypeCallbackTable + 4 + value2 * 8);
    shortValue = *(short *)((int)arg1 + 0x16);
    if ((shortValue == 1) || ((shortValue != 2 && (shortValue != 3)))) {
      flagByte2 = false;
      flagByte = true;
    }
    else {
      flagByte2 = true;
      flagByte = false;
    }
    if (flagByte) {
      entry = CreateEntityEntitySceneObject((uint *)intCursor,1);
      if (entry == 0) {
        CEntities::ReleaseEntityToFreeList((byte *)intCursor);
        return (int *)0x0;
      }
      *(undefined4 *)(entry + 0x14) = *arg1;
      *(undefined4 *)(entry + 0x18) = arg1[1];
      *(undefined4 *)(entry + 0x1c) = arg1[2];
      *(char *)(entry + 0x75) = -((*(byte *)((int)arg1 + 0x1a) & 0x20) != 0);
      *(uint *)(entry + 0x110) = arg1[3] & 0x1ff;
      *(uint *)(entry + 0x10c) = (uint)arg1[3] >> 9;
      if (*(short *)((int)arg1 + 0x16) == 1) {
        *(undefined4 *)(entry + 0x108) = 1;
      }
      else {
        *(undefined4 *)(entry + 0x108) = 0;
      }
      UpdateEntityEntitySceneObjectTransformFromPlacement(entry);
    }
    if (flagByte2) {
      intCursor2 = (int *)arg1[3];
      entry = CreateEntitySourceSceneRef(intCursor);
      if (entry == 0) {
        CEntities::ReleaseEntityToFreeList((byte *)intCursor);
        return (int *)0x0;
      }
      *(undefined4 *)(entry + 0xc) = *arg1;
      *(undefined4 *)(entry + 0x10) = arg1[1];
      *(undefined4 *)(entry + 0x14) = arg1[2];
      if (*(short *)((int)arg1 + 0x16) == 2) {
        *(int *)(entry + 0x18) = *intCursor2 + (int)intCursor2;
      }
      else if (*(short *)((int)arg1 + 0x16) == 3) {
        *(int *)(entry + 0x18) = *intCursor2 + (int)intCursor2;
        *(short *)(entry + 0x30) = (short)intCursor2[2];
        *(short *)(entry + 0x32) = (short)intCursor2[1];
        *(undefined2 *)(entry + 0x34) = *(undefined2 *)((int)intCursor2 + 6);
      }
    }
    (*(code *)intCursor[0xb])(intCursor);
    if (*intCursor != 0) {
      return intCursor;
    }
  }
  return (int *)0x0;
}

