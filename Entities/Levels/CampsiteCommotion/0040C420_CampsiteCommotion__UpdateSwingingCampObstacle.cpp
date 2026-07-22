#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C420
// Label: CampsiteCommotion::UpdateSwingingCampObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateSwingingCampObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  uint value2;
  char resultFlag;
  uint value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value3 = ((int)(short)(&g_SinCosTable12Bit)
                         [(TotalGameLoopTicks + -0x20) * 0x20 + *(int *)(entry + 0x4c) & 0xfff] <<
            9) >> 0xc;
    *(short *)(value + 0xa0) = (short)value3;
    value2 = *(uint *)(entry + 0x50);
    *(uint *)(entry + 0x50) = value3;
    if (((value2 ^ value3) & 0x800) != 0) {
      if (*(int *)(entry + 0x4c) == 0) {
        PlayAudioById(0x2d0,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      }
      if (*(int *)(entry + 0x4c) == 0x800) {
        PlayAudioById(0x2d1,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      }
    }
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,10);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

