
void WelcomeToTheJungle__BirdProximityTakeoffCallback(int param_1,int param_2)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if (((((*(byte *)(param_1 + 0x4a) & 0x40) == 0) &&
       (iVar3 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000), iVar3 != 0)) &&
      (iVar4 = CEntities__ComputeSceneEntryDataDistance3D(param_2 + 0xc,g_PlayerSceneEntryData),
      iVar4 < *(int *)(iVar3 + 0x1c))) &&
     (iVar4 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar4 != 0)) {
    switch(*(undefined2 *)(iVar3 + 0x20)) {
    case 0:
    case 2:
    case 5:
      *(undefined4 *)(param_2 + 0x70) = 0;
      break;
    case 1:
    case 3:
    case 6:
      *(undefined4 *)(param_2 + 0x70) = 2;
      break;
    case 4:
      *(undefined4 *)(param_2 + 0x70) = 1;
      break;
    case 7:
      *(undefined4 *)(param_2 + 0x70) = 3;
    }
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x40;
    CEntities__SelectScriptAttachmentSequence(iVar4,0);
    uVar1 = RandomModulo(0xf);
    *(undefined2 *)(iVar3 + 0x10) = uVar1;
    sVar2 = RandomModulo(4);
    *(undefined2 *)(iVar3 + 0x14) = 0x28;
    *(short *)(iVar3 + 0x12) = sVar2 + 1;
    *(undefined2 *)(param_1 + 0x48) = 5;
    iVar3 = RandomModulo(3);
    if (iVar3 == 0) {
      PlayAudioById(0xe2,param_2 + 0x104,param_2 + 0x14);
    }
    else {
      if (iVar3 == 1) {
        PlayAudioById(0xe3,param_2 + 0x104,param_2 + 0x14);
        return;
      }
      if (iVar3 == 2) {
        PlayAudioById(0xe4,param_2 + 0x104,param_2 + 0x14);
        return;
      }
    }
  }
  return;
}

