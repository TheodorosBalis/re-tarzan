#include "tarzan_ghidra_types.hpp"

// Address: 0x00488140
// Label: TrashingTheCamp::UpdateTantor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateTantor(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  bool flagByte;
  bool flagByte2;
  char resultFlag;
  short shortValue;
  int value3;
  uint value4;
  undefined4 value5;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
    if (value3 != 0) {
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value4 = CEntities::ComputeSignedPlayerFacingDistanceXZ(&((EntitySceneObject *)value)->x);
      if (*(char *)(value + 0x75) != '\0') {
        value4 = ~value4 + 1;
      }
      resultFlag = '\0';
      if (*(char *)(value + 0x74) == '\0') {
        resultFlag = CEntities::CheckPlayerDamageContact(value);
      }
      else {
        *(char *)(value + 0x74) = *(char *)(value + 0x74) + -1;
      }
      if ((-1 < (int)value4) || (flagByte2 = true, (int)value4 < -999)) {
        flagByte2 = false;
      }
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(undefined4 *)(entry + 0x50));
      if (*(char *)(value + 0x75) == '\0') {
        flagByte = 0x1518 < ((EntitySceneObject *)value)->surfaceIndex;
      }
      else {
        flagByte = ((EntitySceneObject *)value)->surfaceIndex < 600;
      }
      value2 = *(int *)(entry + 0x4c);
      if (value2 == 1) {
        *(undefined4 *)(entry + 0x50) = 0;
        if ((shortValue != 8) && (resultFlag == '\0')) goto LAB_004882bb;
        if (flagByte2) {
          if (flagByte) goto LAB_004882bb;
          value5 = 1;
          *(undefined4 *)(entry + 0x4c) = 2;
        }
        else {
          if (flagByte) {
            *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
          }
          value5 = 1;
          *(undefined4 *)(entry + 0x4c) = 2;
        }
      }
      else {
        if (value2 != 2) {
          if ((value2 == 3) && (*(undefined4 *)(entry + 0x50) = 0, shortValue == 4)) {
            *(undefined4 *)(entry + 0x4c) = 1;
          }
          goto LAB_004882bb;
        }
        *(undefined4 *)(entry + 0x50) = 0x20;
        if (resultFlag != '\0') {
          *(undefined1 *)(value + 0x74) = 0x10;
          *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
          goto LAB_004882bb;
        }
        if (!flagByte) goto LAB_004882bb;
        if (!flagByte2) {
          *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
          goto LAB_004882bb;
        }
        value5 = 3;
        *(undefined4 *)(entry + 0x4c) = 3;
        *(undefined4 *)(entry + 0x50) = 0;
      }
      CEntities::SelectScriptAttachmentSequence(value3,value5);
    }
  }
LAB_004882bb:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

