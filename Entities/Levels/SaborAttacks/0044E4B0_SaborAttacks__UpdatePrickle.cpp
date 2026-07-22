#include "tarzan_ghidra_types.hpp"

// Address: 0x0044E4B0
// Label: SaborAttacks::UpdatePrickle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::UpdatePrickle(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  int value;
  
  if (*(short *)(entry + 0x48) == 0) {
    if ((*(uint *)(entry + 0x4c) & (int)g_SaborEncounterCleanupFlags) != 0) {
      value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
      if (value != 0) {
        DecodeEncodedEntitySceneObjectIdToSourceRef(((EntitySceneObject *)value)->y,0x200a);
        CEntities::SpawnSmashableDustEmitterAtEntryOffset(entry,0,0xfffffe80,0);
        value = entity->sceneObjects;
        *(undefined2 *)(entry + 0x48) = 1;
        if (value != 0) {
          value = CEntities::SpawnEntityByTypeAtPosition
                            (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + -0x180,
                             ((EntitySceneObject *)value)->z,0x178,0x11);
          if (value != 0) {
            *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2013;
            *(undefined4 *)(*(int *)(value + 0x38) + 0x10) = g_CurrentWorldSceneContext;
            *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
            *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 0x2000;
            *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 0x2000;
            *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 0x2000;
            value = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
            if (value != 0) {
              ((EntitySceneObject *)value)->next = 0x7fff;
              *(undefined4 *)(value + 0x524) = 0x200;
            }
          }
        }
      }
    }
  }
  else {
    value = entity->sceneObjects;
    if (value != 0) {
      CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
      resultFlag = CEntities::CheckPlayerDamageContact(value);
      if (resultFlag != '\0') {
        QueuePlayerDamageEvent(entry,4);
        g_PlayerDamageContactEntitySceneObject = value;
      }
    }
  }
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

