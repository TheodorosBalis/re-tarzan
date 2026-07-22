#include "tarzan_ghidra_types.hpp"

// Address: 0x00487960
// Label: TrashingTheCamp::UpdatePlankMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdatePlankMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  undefined2 value4;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  if ((value != 0) &&
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 != 0)) {
    value4 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    switch(value4) {
    case 4:
      ((EntitySceneObject *)value)->surfaceIndex = 0;
      UpdateEntityEntitySceneObjectTransformFromPlacement(value);
      ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + *(int *)(value + 0x54);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
      ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + *(int *)(value + 0x5c);
      *(undefined2 *)(entry + 0x48) = 0;
      break;
    case 9:
      value3 = RandomModulo(5);
      if (value3 == 1) {
        CEntities::SelectScriptAttachmentSequence(value2,1);
      }
      else if (value3 == 2) {
        CEntities::SelectScriptAttachmentSequence(value2,4);
      }
      break;
    case 10:
      PlayAudioById(0xd7,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      *(undefined2 *)(entry + 0x48) = 8;
    case 0xc:
      ComputeEntitySceneObjectCollisionMoveDelta(0xf,0,value);
      ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + *(int *)(value + 0x54);
      ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + *(int *)(value + 0x5c);
    }
    if ((*(short *)(entry + 0x48) == 1) && (0x20 < g_PlayerTerkPlankMonkeyInteractionState)) {
      *(undefined2 *)(entry + 0x48) = 2;
      PlayAudioById(0x2a2,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::SelectScriptAttachmentSequence(value2,7);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

