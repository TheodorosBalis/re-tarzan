
void WelcomeToTheJungle__InitProximityTakeoffBird(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  WelcomeToTheJungle__InitBirdCommon(param_1);
  CEntities__MoveSceneEntryAndSnapFacingAngles(param_1,0);
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 != 0) {
    iVar1 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000);
    if (iVar1 != 0) {
      *(code **)(iVar1 + 0xc) = WelcomeToTheJungle__BirdProximityTakeoffCallback;
      *(undefined2 *)(iVar1 + 0x10) = 0;
      *(undefined2 *)(iVar1 + 0x14) = 0x28;
      *(undefined2 *)(iVar1 + 0x16) = 0;
      *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0xf;
      *(undefined2 *)(param_1 + 0x48) = 0;
      iVar2 = RandomModulo(0x28);
      *(int *)(param_1 + 0x4c) = iVar2 + 0x1e;
      switch(*(undefined2 *)(iVar1 + 0x20)) {
      case 0:
      case 2:
      case 5:
        *(undefined4 *)(iVar3 + 0x70) = 1;
        break;
      case 1:
      case 3:
        *(undefined4 *)(iVar3 + 0x70) = 3;
        break;
      case 4:
        *(undefined4 *)(iVar3 + 0x70) = 0;
        break;
      case 6:
        *(undefined4 *)(iVar3 + 0x70) = 4;
        break;
      case 7:
        *(undefined4 *)(iVar3 + 0x70) = 5;
      }
    }
    iVar3 = FindRuntimeEntityAttachmentByFlags(param_1,0x400);
    if (iVar3 != 0) {
      CEntities__SelectScriptAttachmentSequence(iVar3,1);
    }
  }
  return;
}

