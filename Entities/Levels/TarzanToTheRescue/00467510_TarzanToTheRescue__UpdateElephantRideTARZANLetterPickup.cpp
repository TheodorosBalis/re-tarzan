#include "tarzan_ghidra_types.hpp"

// Address: 0x00467510
// Label: TarzanToTheRescue::UpdateElephantRideTARZANLetterPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateElephantRideTARZANLetterPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value2;
  ushort *dataCursor;
  int value;
  int *intCursor;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (value != 0) {
    value2 = (short *)(entity->sceneObjects + 0xa2);
    *value2 = *value2 + 0x38;
    dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
    *dataCursor = *dataCursor & 0xfff;
    if (*(int *)(value + 0x20) < -0xc) {
      if (*(short *)(entry + 0x48) != 0) {
        PlayAudioById(0x5d,(int *)0,(undefined4 *)0);
        g_HudCollectedTARZANslotSlideTicks = 0x5a;
        g_CollectedTARZANLetterMask6 = g_CollectedTARZANLetterMask6 | 1;
        value = entity->sceneObjects;
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                   ((EntitySceneObject *)value)->z,0x14,0x11);
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
    else if (*(short *)(entry + 0x48) != 0) {
      value = *(int *)(entry + 0x4c);
      *(int *)(entry + 0x4c) = value + -1;
      if (value < 0) {
        value = entity->sceneObjects;
        intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                  (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                                   ((EntitySceneObject *)value)->z,0x178,0x11);
        if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
          *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
          *(undefined2 *)(intCursor[0xe] + 0xc) = 0x201e;
          value = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
          if (value != 0) {
            ((EntitySceneObject *)value)->next = 0x80;
            ((EntitySceneObject *)value)->worldObject = 4;
            *(undefined4 *)(value + 0x38) = 0x180;
            *(undefined4 *)(value + 0x524) = 0x40;
            *(undefined4 *)(value + 0x20) = 0x1e;
            *(undefined4 *)(value + 0x52c) = 1;
          }
        }
        *(undefined4 *)(entry + 0x4c) = 2;
      }
      CEntities::AdvanceEntityBounceMotionAndReturnImpact(entry);
    }
  }
  return;
}

