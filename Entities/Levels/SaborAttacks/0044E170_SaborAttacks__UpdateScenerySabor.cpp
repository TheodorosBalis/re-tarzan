#include "tarzan_ghidra_types.hpp"

// Address: 0x0044E170
// Label: SaborAttacks::UpdateScenerySabor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::UpdateScenerySabor(int entry5)

{
  Entity *entity = (Entity *)entry5;
  int entry;
  int entry2;
  bool flagByte;
  char resultFlag;
  short shortValue;
  uint value2;
  int entry3;
  int entry4;
  uint value3;
  undefined4 value;
  
  entry = entity->sceneObjects;
  CEntities::FindEntityAttachmentByFlags(entry5,0x10000001);
  CEntities::FindEntityAttachmentByFlags(entry5,0x800);
  entry2 = *(int *)(entry5 + 0x4c);
  value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x18) - ((EntitySceneObject *)entry)->y;
  entry4 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) - ((EntitySceneObject *)entry)->x;
  value3 = (int)value2 >> 0x1f;
  flagByte = false;
  entry3 = (value2 ^ value3) - value3;
  if (entry2 == 1) {
    if ((-0x6a4 < entry4) && (entry3 < 0x4d0)) goto LAB_0044e1df;
  }
  else if ((0x200 < entry4) && (entry3 < 0x330)) {
LAB_0044e1df:
    flagByte = true;
  }
  if (entry2 == 1) {
    switch(*(undefined4 *)(entry5 + 0x50)) {
    case 0:
      goto switchD_0044e1fb_caseD_0;
    case 1:
      SaborAttacks::AdvanceSaborEncounterMovement(entry5,0x40);
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
      if ((shortValue == 0) ||
         (*(short *)(entry5 + 0x48) = *(short *)(entry5 + 0x48) + 1,
         *(ushort *)(entry5 + 0x48) < 4)) goto switchD_0044e1fb_default;
      PlayAudioById(500,(int *)0,(undefined4 *)&((EntitySceneObject *)entry)->x);
      value = 2;
      break;
    case 2:
switchD_0044e1fb_caseD_4:
      SaborAttacks::AdvanceSaborEncounterMovement(entry5,0x40);
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
      if (shortValue != 0) {
        SetSaborAnimationStateAndAdvance(entry5,1);
        *(int *)(entry5 + 0x50) = *(int *)(entry5 + 0x50) + 1;
      }
      goto switchD_0044e1fb_default;
    case 3:
      goto switchD_0044e1fb_caseD_5;
    default:
      goto switchD_0044e1fb_default;
    }
LAB_0044e2cb:
    SetSaborAnimationStateAndAdvance(entry5,value);
    *(int *)(entry5 + 0x50) = *(int *)(entry5 + 0x50) + 1;
  }
  else {
    if (entry2 == 2) {
      switch(*(undefined4 *)(entry5 + 0x50)) {
      case 0:
        goto switchD_0044e1fb_caseD_0;
      case 1:
        SaborAttacks::AdvanceSaborEncounterMovement(entry5,0x40);
        shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
        if ((shortValue == 0) ||
           (*(short *)(entry5 + 0x48) = *(short *)(entry5 + 0x48) + 1,
           *(ushort *)(entry5 + 0x48) < 4)) goto switchD_0044e1fb_default;
        value = 10;
        break;
      case 2:
        SaborAttacks::AdvanceSaborEncounterMovement(entry5,0);
        shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
        if (shortValue == 0) goto switchD_0044e1fb_default;
        value = 4;
        break;
      case 3:
        SaborAttacks::AdvanceSaborEncounterMovement(entry5,0);
        shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
        if (shortValue == 0) goto switchD_0044e1fb_default;
        value = 9;
        break;
      case 4:
        SaborAttacks::AdvanceSaborEncounterMovement(entry5,0x40);
        shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
        if (shortValue == 0) goto switchD_0044e1fb_default;
        value = 1;
        break;
      case 5:
        goto switchD_0044e1fb_caseD_5;
      default:
        goto switchD_0044e1fb_default;
      }
      SetSaborAnimationStateAndAdvance(entry5,value);
      *(int *)(entry5 + 0x50) = *(int *)(entry5 + 0x50) + 1;
      goto switchD_0044e1fb_default;
    }
    switch(*(undefined4 *)(entry5 + 0x50)) {
    case 0:
switchD_0044e1fb_caseD_0:
      if (!flagByte) break;
      PlayAudioById(0x1fa,(int *)0,(undefined4 *)&((EntitySceneObject *)entry)->x);
      value = 1;
      goto LAB_0044e2cb;
    case 1:
      SaborAttacks::AdvanceSaborEncounterMovement(entry5,0x40);
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
      if ((shortValue != 0) &&
         (*(short *)(entry5 + 0x48) = *(short *)(entry5 + 0x48) + 1,
         3 < *(ushort *)(entry5 + 0x48))) {
        SetSaborAnimationStateAndAdvance(entry5,10);
        *(int *)(entry5 + 0x50) = *(int *)(entry5 + 0x50) + 1;
      }
      break;
    case 2:
      SaborAttacks::AdvanceSaborEncounterMovement(entry5,0);
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
      if (shortValue != 0) {
        SetSaborAnimationStateAndAdvance(entry5,4);
        *(int *)(entry5 + 0x50) = *(int *)(entry5 + 0x50) + 1;
      }
      break;
    case 3:
      SaborAttacks::AdvanceSaborEncounterMovement(entry5,0);
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
      if (shortValue != 0) {
        SetSaborAnimationStateAndAdvance(entry5,9);
        *(int *)(entry5 + 0x50) = *(int *)(entry5 + 0x50) + 1;
      }
      break;
    case 4:
      goto switchD_0044e1fb_caseD_4;
    case 5:
switchD_0044e1fb_caseD_5:
      resultFlag = SaborAttacks::AdvanceSaborEncounterMovement(entry5,0x40);
      if (resultFlag != '\0') {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed();
        return;
      }
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry5);
    }
  }
switchD_0044e1fb_default:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry5);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry5);
  }
  return;
}

