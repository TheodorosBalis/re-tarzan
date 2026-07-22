#include "tarzan_ghidra_types.hpp"

// Address: 0x0047C400
// Label: JourneyToTheTreeHouse::UpdateCrocodile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void JourneyToTheTreeHouse::UpdateCrocodile(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  uint value3;
  int value2;
  undefined4 value4;
  
  value = entity->sceneObjects;
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (0 < g_JourneyCrocodileAmbientSfxCooldown) {
    g_JourneyCrocodileAmbientSfxCooldown = g_JourneyCrocodileAmbientSfxCooldown + -1;
    goto LAB_0047c485;
  }
  value3 = NextRandomValue();
  if ((value3 & 0xf) != 0) goto LAB_0047c485;
  value3 = NextRandomValue();
  switch(value3 & 3) {
  case 1:
    value4 = 0x10b;
    break;
  case 2:
    value4 = 0x10c;
    break;
  case 3:
    value4 = 0x10d;
    break;
  default:
    goto switchD_0047c43a_default;
  }
  PlayAudioById(value4,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
switchD_0047c43a_default:
  g_JourneyCrocodileAmbientSfxCooldown = 0xf;
LAB_0047c485:
  if ((((*(short *)(entry + 0x48) != 0x2b) && (g_PlayerDamageInvulnerabilityTicks == 0)) &&
      (value2 = ComputeEntityHorizontalDistanceSqToPlayer(entry), value2 < 0x33a90)) &&
     (((EntitySceneObject *)value)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc) < 100)) {
    _g_JourneyCrocodileSavedActionState = (uint)*(ushort *)(entry + 0x48);
    *(undefined2 *)(entry + 0x48) = 0x2b;
    CEntities::SelectEntityAnimationAttachmentState(entry,1);
    QueuePlayerDamageEvent(entry,0x1008);
  }
  if (*(short *)(entry + 0x48) == 0x15) {
    if (*(char *)(value + 0x75) == '\0') {
      value4 = 10;
    }
    else {
      value4 = 0xfffffff6;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(value4,0,value);
    ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + *(int *)(value + 0x54);
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
    ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + *(int *)(value + 0x5c);
    ((EntitySceneObject *)value)->yaw = *(ushort *)(value + 0x132);
    if (*(char *)(value + 0x75) == '\0') {
      ((EntitySceneObject *)value)->yaw = *(ushort *)(value + 0x132) ^ 0x800;
      *(ushort *)(value + 0xa0) = 0x400U - *(short *)(value + 0x130) & 0xfff;
    }
    else {
      *(ushort *)(value + 0xa0) = *(short *)(value + 0x130) - 0x400U & 0xfff;
    }
    if ((*(byte *)(value + 0x13c) & 2) != 0) {
      *(undefined2 *)(entry + 0x48) = 0x29;
      *(undefined4 *)(entry + 0x50) = 0x80;
    }
  }
  else if (*(short *)(entry + 0x48) == 0x29) {
    ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x10;
    value2 = *(int *)(entry + 0x50) + -1;
    *(int *)(entry + 0x50) = value2;
    if (value2 == 0) {
      *(undefined2 *)(entry + 0x48) = 0x15;
      *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
    }
  }
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if ((shortValue != 0) && (*(short *)(entry + 0x48) == 0x2b)) {
    *(undefined2 *)(entry + 0x48) = g_JourneyCrocodileSavedActionState;
    CEntities::SelectEntityAnimationAttachmentState(entry,0);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

