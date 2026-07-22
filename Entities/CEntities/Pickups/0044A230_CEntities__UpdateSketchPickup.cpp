#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A230
// Label: CEntities::UpdateSketchPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSketchPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  undefined2 upperWord;
  byte flagByte;
  undefined4 value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    shortValue = *(short *)(entry + 0x50) + 0x44;
    *(int *)(entry + 0x50) = (int)shortValue;
    *(int *)(value + 0x40) =
         -0x80 - (((int)(short)(&g_SinCosTable12Bit)
                               [(CONCAT22(upperWord,shortValue) >> 1) - 0x400U & 0xfff] +
                  (int)(short)(&g_SinCosTable12Bit)[(int)shortValue & 0xfff]) * 0x40 >> 0xc);
    resultFlag = CEntities::IsPlayerWithinPickupTriggerBounds
                      (value,g_PlayerPickupTriggerRadius,
                       (int)*(short *)(g_PlayerEntitySceneObject + 0x142),0);
    if (resultFlag != '\0') {
      resultFlag = CEntities::CanStartPickupCollection(entry);
      if (resultFlag != '\0') {
        flagByte = g_CollectedSketchPieceMask4 |
                '\x01' << ((byte)*(undefined4 *)(entry + 0x4c) & 0x1f);
        g_CollectedSketchPieceMask4 = flagByte;
        (&g_HudSketchPieceQuad0Flags)[*(int *)(entry + 0x4c) * 0x14] =
             (&g_HudSketchPieceQuad0Flags)[*(int *)(entry + 0x4c) * 0x14] & 0xfbde;
        if (flagByte == 0xf) {
          value2 = 0xbf;
        }
        else {
          value2 = 0xb4;
        }
        PlayAudioById(value2,(int *)0,(undefined4 *)0);
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + *(int *)(value + 0x40) * 2
                   ,((EntitySceneObject *)value)->z,0x14,0x11);
        g_HudCollectedSketchSlideTicks = 0xb4;
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

