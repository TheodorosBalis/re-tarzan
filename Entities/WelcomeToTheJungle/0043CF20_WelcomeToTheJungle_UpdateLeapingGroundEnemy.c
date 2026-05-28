
void WelcomeToTheJungle__UpdateLeapingGroundEnemy(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = *(int *)(param_1 + 0x38);
  if (iVar7 == 0) goto LAB_0043d0fe;
  iVar6 = FindRuntimeEntityAttachmentByFlags(param_1,0x400);
  if (iVar6 == 0) goto LAB_0043d0fe;
  sVar5 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar7,0x50,0x50);
  CEntities__HandleAnimalScriptEvent(param_1,iVar7,(int)sVar5);
  iVar8 = *(int *)(iVar7 + 0x10c);
  iVar3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar7 + 0x110) * 4) + 8 +
                   *(int *)(iVar7 + 0x110) * 4 + g_CollisionSurfaceTable);
  cVar4 = CEntities__CheckPlayerDamageContact(iVar7);
  if (cVar4 != '\0') {
    QueuePlayerDamageEvent(param_1,2);
  }
  CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if (*(short *)(param_1 + 0x3e) < 1) {
    iVar6 = CEntities__SpawnRuntimeEntryByTypeAtPosition
                      (*(undefined4 *)(iVar7 + 0x14),*(undefined4 *)(iVar7 + 0x18),
                       *(undefined4 *)(iVar7 + 0x1c),0x13,0x11);
    if (iVar6 != 0) {
      *(undefined4 *)(*(int *)(iVar6 + 0x38) + 0x30) = 0;
      pbVar1 = (byte *)(*(int *)(iVar6 + 0x38) + 0xf);
      *pbVar1 = *pbVar1 | 4;
      *(undefined4 *)(*(int *)(iVar6 + 0x38) + 0x20) = 0;
      *(undefined4 *)(*(int *)(iVar6 + 0x38) + 0x28) = 0;
      *(undefined4 *)(*(int *)(iVar6 + 0x38) + 0x24) = 0x800;
    }
    PlayAudioById(0x157,0,iVar7 + 0x14);
    CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
    return;
  }
  sVar5 = *(short *)(param_1 + 0x48);
  if (sVar5 == 0) {
    iVar7 = RandomModulo(0xc);
    *(int *)(param_1 + 0x4c) = iVar7 + 2;
    *(undefined2 *)(param_1 + 0x48) = 1;
    CEntities__SelectScriptAttachmentSequence(iVar6,0);
    goto LAB_0043d0fe;
  }
  if (sVar5 != 1) {
    if (sVar5 == 2) {
      if ((*(byte *)(param_1 + 0x4a) & 2) == 0) {
        *(undefined4 *)(iVar7 + 0x40) = 0;
      }
      else {
        *(int *)(iVar7 + 0x40) =
             *(int *)(&g_LeapingGroundEnemyHopYOffsetTable + *(int *)(param_1 + 0x50) * 4) * -8;
        *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
      }
      if (*(short *)(iVar6 + 0x18) == 0) {
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
    }
    goto LAB_0043d0fe;
  }
  bVar2 = *(byte *)(iVar7 + 0x75);
  if (bVar2 == 0) {
LAB_0043d07d:
    if (iVar3 - iVar8 < 0x201) {
      if ((*(byte *)(param_1 + 0x4b) & 2) != 0) {
        CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
        return;
      }
      *(undefined1 *)(iVar7 + 0x75) = 0xff;
      goto LAB_0043d0fe;
    }
  }
  else {
    if (iVar8 < 0x201) {
      *(byte *)(iVar7 + 0x75) = ~bVar2;
      goto LAB_0043d0fe;
    }
    if (bVar2 == 0) goto LAB_0043d07d;
  }
  iVar8 = *(int *)(param_1 + 0x4c) + -1;
  *(int *)(param_1 + 0x4c) = iVar8;
  if (iVar8 < 1) {
    CEntities__SelectScriptAttachmentSequence(iVar6,1);
    *(undefined2 *)(param_1 + 0x48) = 2;
    *(undefined4 *)(param_1 + 0x50) = 0;
    PlayAudioById(0x109,0,iVar7 + 0x14);
  }
LAB_0043d0fe:
  cVar4 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar4 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

