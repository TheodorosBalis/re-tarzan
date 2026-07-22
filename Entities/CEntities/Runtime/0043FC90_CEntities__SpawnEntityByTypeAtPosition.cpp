#include "tarzan_ghidra_types.hpp"

// Address: 0x0043FC90
// Label: CEntities::SpawnEntityByTypeAtPosition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::SpawnEntityByTypeAtPosition
                (undefined4 entry2,undefined4 sceneObject,undefined4 attachment,ushort flags,
                byte arg5)

{
  int *intCursor;
  uint value;
  int entry;
  int *intCursor2;
  int *intCursor3;
  int *localState;
  
  intCursor = g_FreeEntityListHead;
  localState = (int *)0x0;
  if ((flags != 0) && (value = (uint)flags, (int)value < g_EntityTypeCount)) {
    if (g_FreeEntityListHead == (int *)0x0) {
      return (int *)0x0;
    }
    g_FreeEntityListHead = (int *)g_FreeEntityListHead[4];
    if (g_FreeEntityListHead != (int *)0x0) {
      g_FreeEntityListHead[3] = 0;
    }
    localState = intCursor;
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
    *(ushort *)((int)intCursor + 0x46) = flags;
    intCursor[0xb] = *(int *)(g_EntityTypeCallbackTable + value * 8);
    intCursor[0xc] = *(int *)(g_EntityTypeCallbackTable + 4 + value * 8);
    if ((arg5 & 1) != 0) {
      entry = CreateEntityEntitySceneObject((uint *)intCursor,1);
      if (entry == 0) goto LAB_0043fd8b;
      *(undefined4 *)(entry + 0x18) = sceneObject;
      *(undefined4 *)(entry + 0x14) = entry2;
      *(undefined4 *)(entry + 0x1c) = attachment;
    }
    if ((arg5 & 2) != 0) {
      entry = CreateEntitySourceSceneRef(intCursor);
      if (entry == 0) {
LAB_0043fd8b:
        if ((arg5 & 0x10) != 0) {
          CEntities::ReleaseEntityToFreeList((byte *)intCursor);
        }
        return (int *)0x0;
      }
      *(undefined4 *)(entry + 0x10) = sceneObject;
      *(undefined4 *)(entry + 0xc) = entry2;
      *(undefined4 *)(entry + 0x14) = attachment;
    }
    (*(code *)intCursor[0xb])(intCursor);
    if (*intCursor == 0) {
      localState = (int *)0x0;
    }
  }
  return localState;
}

