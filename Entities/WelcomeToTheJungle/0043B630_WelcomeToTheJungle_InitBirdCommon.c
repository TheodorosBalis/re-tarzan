
void WelcomeToTheJungle__InitBirdCommon(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int local_8;
  int local_4;
  
  local_4 = 0;
  local_8 = 0;
  if ((*(int *)(param_1 + 0x34) != 0) &&
     (local_4 = *(int *)(*(int *)(param_1 + 0x34) + 0x10), local_4 != 0)) {
    local_8 = *(int *)(local_4 + 4);
  }
  if (local_8 == 0x61) {
    uVar4 = 4;
LAB_0043b682:
    local_8 = RandomModulo(uVar4);
  }
  else if (local_8 == 0x62) {
    local_8 = RandomModulo(4);
    local_8 = local_8 + 4;
  }
  else if (local_8 == 99) {
    uVar4 = 8;
    goto LAB_0043b682;
  }
  iVar3 = *(int *)(param_1 + 0x38);
  *(undefined2 *)(param_1 + 0x4a) = 0;
  if (iVar3 == 0) {
    return;
  }
  switch(local_8) {
  case 0:
    puVar5 = &g_BirdScriptAttachmentDesc_Variant0;
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x7b8;
    goto LAB_0043b827;
  case 1:
    puVar5 = &g_BirdScriptAttachmentDesc_Variant0;
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x7b8;
    goto LAB_0043b711;
  case 2:
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x6e8;
    goto LAB_0043b822;
  case 3:
    puVar5 = &g_BirdScriptAttachmentDesc_Variant2;
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x6e8;
LAB_0043b711:
    iVar2 = CEntities__SetSceneEntryScriptAttachment(param_1,puVar5);
    *(ushort *)(iVar3 + 0xe) = *(ushort *)(iVar3 + 0xe) | 0x200;
    *(undefined4 *)(iVar3 + 0x70) = 2;
    break;
  case 4:
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x750;
    iVar2 = CEntities__SetSceneEntryScriptAttachment(param_1,&g_BirdScriptAttachmentDesc_Variant4);
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x10;
    break;
  case 5:
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x820;
    iVar2 = CEntities__SetSceneEntryScriptAttachment(param_1,&g_BirdScriptAttachmentDesc_Variant5);
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x10;
    break;
  case 6:
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x750;
    iVar2 = CEntities__SetSceneEntryScriptAttachment(param_1,&g_BirdScriptAttachmentDesc_Variant4);
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x10;
    *(ushort *)(iVar3 + 0xe) = *(ushort *)(iVar3 + 0xe) | 0x200;
    *(undefined4 *)(iVar3 + 0x70) = 2;
    break;
  case 7:
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x750;
    iVar2 = CEntities__SetSceneEntryScriptAttachment(param_1,&g_BirdScriptAttachmentDesc_Variant4);
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x10;
    *(ushort *)(iVar3 + 0xe) = *(ushort *)(iVar3 + 0xe) | 0x200;
    *(undefined4 *)(iVar3 + 0x70) = 3;
    break;
  default:
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x6e8;
LAB_0043b822:
    puVar5 = &g_BirdScriptAttachmentDesc_Variant2;
    goto LAB_0043b827;
  case 0x10:
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x958;
    iVar2 = CEntities__SetSceneEntryScriptAttachment(param_1,&g_BirdScriptAttachmentDesc_Variant16);
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x10;
    break;
  case 0x11:
    puVar5 = &g_BirdScriptAttachmentDesc_Variant17;
    *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x888;
LAB_0043b827:
    iVar2 = CEntities__SetSceneEntryScriptAttachment(param_1,puVar5);
  }
  *(undefined2 *)(iVar3 + 0xa6) = 2;
  *(undefined4 *)(iVar3 + 0x40) = 0;
  if (iVar2 == 0) goto LAB_0043b952;
  if (local_8 == 0x10) {
    sVar1 = RandomModulo(0x10);
    *(short *)(iVar2 + 0x16) = sVar1;
    if (7 < sVar1) {
LAB_0043b880:
      *(short *)(iVar2 + 0x16) = sVar1 + 2;
    }
  }
  else if (local_8 != 0x11) {
    sVar1 = RandomModulo(8);
    *(short *)(iVar2 + 0x16) = sVar1;
    if (4 < sVar1) goto LAB_0043b880;
  }
  iVar3 = CEntities__CreateRuntimeEntryAttachment(param_1,0x2c,0x10000000);
  if (iVar3 != 0) {
    *(short *)(iVar3 + 0x20) = (short)local_8;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(undefined4 *)(iVar3 + 0x1c) = 1000;
    *(undefined2 *)(iVar3 + 0x14) = 0x10;
    *(undefined2 *)(iVar3 + 0x10) = 0;
    *(undefined2 *)(iVar3 + 0x12) = 1;
    *(undefined2 *)(iVar3 + 0x16) = 0;
    *(undefined2 *)(iVar3 + 0x18) = 0;
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(undefined2 *)(iVar3 + 0x22) = 0xfa;
    *(undefined4 *)(iVar3 + 0x24) = 0;
    iVar2 = *(int *)(param_1 + 0x34);
    *(undefined2 *)(param_1 + 0x48) = 1;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if (iVar2 != 0) {
      if ((*(byte *)(*(int *)(iVar2 + 0x10) + 3) & 1) != 0) {
        *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 8;
      }
      if ((*(byte *)(*(int *)(iVar2 + 0x10) + 2) & 0x20) != 0) {
        *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) | 2;
      }
      if ((*(byte *)(*(int *)(iVar2 + 0x10) + 2) & 0x40) != 0) {
        *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) | 0x20;
      }
    }
    *(undefined4 *)(iVar3 + 0x1c) = 1000;
    if (local_4 != 0) {
      *(undefined2 *)(iVar3 + 0x14) = *(undefined2 *)(local_4 + 8);
      *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(local_4 + 0xc);
      if (*(int *)(local_4 + 0xc) == 0) {
        *(undefined4 *)(iVar3 + 0x1c) = 1000;
      }
      if (*(int *)(local_4 + 0xc) == 1) {
        *(undefined4 *)(iVar3 + 0x1c) = 100000;
      }
    }
    if (*(short *)(iVar3 + 0x14) != 0) {
      return;
    }
    *(undefined2 *)(iVar3 + 0x14) = 0x10;
    return;
  }
LAB_0043b952:
  CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  return;
}

