
undefined4
CEntities__IsPlayerWithinPickupTriggerBounds(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  uVar2 = g_PlayerSpecialAttachmentPosX - *(int *)(param_1 + 0x14);
  uVar3 = (int)uVar2 >> 0x1f;
  iVar5 = (uVar2 ^ uVar3) - uVar3;
  uVar2 = ((g_PlayerSpecialAttachmentPosY - *(int *)(param_1 + 0x40)) - *(int *)(param_1 + 0x18)) +
          0x70;
  uVar3 = (int)uVar2 >> 0x1f;
  iVar4 = (uVar2 ^ uVar3) - uVar3;
  uVar2 = g_PlayerSpecialAttachmentPosZ - *(int *)(param_1 + 0x1c);
  uVar3 = (int)uVar2 >> 0x1f;
  iVar6 = (uVar2 ^ uVar3) - uVar3;
  if (param_3 != 0) {
    param_3 = param_3 + 0xe0;
  }
  if ((g_PlayerSpecialAttachmentFlags & 0x800) == 0) {
    param_3 = param_3 / 2;
  }
  if (param_4 == 0) {
    if ((((*(int *)(param_1 + 0x108) == 1) && (*(int *)(g_PlayerSceneEntry + 0x108) == 1)) &&
        (*(int *)(g_PlayerSceneEntry + 0x110) == *(int *)(param_1 + 0x110))) &&
       (uVar2 = *(int *)(g_PlayerSceneEntry + 0x10c) - *(int *)(param_1 + 0x10c),
       uVar3 = (int)uVar2 >> 0x1f, (int)((uVar2 ^ uVar3) - uVar3) <= param_2)) {
      if (param_3 == 0) {
        return 1;
      }
      if (iVar4 <= param_3) {
        return 1;
      }
    }
    if (g_PlayerCurrentCollisionMode == 5) {
      local_c = *(int *)(param_1 + 0x14);
      local_4 = *(undefined4 *)(param_1 + 0x1c);
      local_8 = *(int *)(param_1 + 0x18) + -0x50;
      cVar1 = CEntities__IsWorldPointInsideSceneEntryBounds(g_PlayerSceneEntry,&local_c);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (iVar6 * iVar6 + iVar5 * iVar5 < param_2 * param_2) {
      if (param_3 == 0) {
        if (iVar4 < 0x801) {
          return 1;
        }
      }
      else if (iVar4 <= param_3) {
        return 1;
      }
    }
  }
  else if (param_4 == 1) {
    if (iVar5 <= param_2) {
      return 1;
    }
  }
  else if (param_4 == 2) {
    if (iVar4 <= param_2) {
      return 1;
    }
  }
  else if ((param_4 == 3) && (iVar6 <= param_2)) {
    return 1;
  }
  return 0;
}

