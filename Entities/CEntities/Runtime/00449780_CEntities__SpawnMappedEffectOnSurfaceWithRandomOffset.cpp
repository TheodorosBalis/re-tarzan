#include "tarzan_ghidra_types.hpp"

// Address: 0x00449780
// Label: CEntities::SpawnMappedEffectOnSurfaceWithRandomOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::SpawnMappedEffectOnSurfaceWithRandomOffset
               (undefined4 entry,undefined4 sceneObject,int attachment,int flags,int arg5,
               int arg6)

{
  short shortValue;
  int offset;
  int offset2;
  int offset3;
  
  offset = CEntities::SpawnEntityByTypeAtPosition(0,0,0,entry,0x11);
  if ((offset != 0) && (offset3 = *(int *)(offset + 0x38), offset3 != 0)) {
    *(undefined4 *)(offset3 + 0x108) = 1;
    *(undefined4 *)(offset3 + 0x110) = sceneObject;
    offset2 = RandomModulo(arg5 * 2);
    *(int *)(offset3 + 0x10c) = (attachment + arg5) - offset2;
    UpdateEntityEntitySceneObjectTransformFromPlacement(offset3);
    *(int *)(offset3 + 0x14) = *(int *)(offset3 + 0x14) + *(int *)(offset3 + 0x54);
    *(int *)(offset3 + 0x1c) = *(int *)(offset3 + 0x1c) + *(int *)(offset3 + 0x5c);
    *(int *)(offset3 + 0x18) = *(int *)(offset3 + 0x18) + *(int *)(offset3 + 0x58) + flags;
    shortValue = RandomModulo(arg6 * 2);
    *(int *)(offset3 + 0x6c) = *(int *)(offset3 + 0x6c) + -0x100;
    offset3 = CEntities::CreateEntityAttachment(offset,0x20,0x40000063);
    if (offset3 != 0) {
      *(undefined2 *)(offset3 + 0x10) = 0;
      *(undefined2 *)(offset3 + 0x12) = 8;
      *(undefined2 *)(offset3 + 0xc) = 0;
      *(undefined2 *)(offset3 + 0xe) = 0;
      *(undefined2 *)(offset3 + 0x14) = 0;
      *(undefined2 *)(offset3 + 0x16) = 0;
      *(undefined2 *)(offset3 + 0x18) = 0;
      *(short *)(offset3 + 0x1a) = (short)arg6 - shortValue;
      *(undefined1 *)(offset3 + 0x1e) = 0x84;
      *(undefined2 *)(offset3 + 0x1c) = 0x46;
      *(undefined1 *)(offset3 + 0x1f) = 3;
    }
  }
  if (*(short *)(offset + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)offset);
  }
  return;
}

