
void WelcomeToTheJungle__InitProjectileDropBird(int param_1)

{
  short sVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 4;
  if ((*(byte *)(param_1 + 0x43) & 0x80) == 0) {
    WelcomeToTheJungle__InitBirdCommon(param_1);
    iVar2 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000);
    if (iVar2 != 0) {
      *(code **)(iVar2 + 0xc) = WelcomeToTheJungle__BirdProjectileDropCallback;
      *(undefined2 *)(iVar2 + 0x10) = 0x28;
      sVar1 = RandomModulo(3);
      *(short *)(iVar2 + 0x12) = sVar1 + 1;
      *(undefined2 *)(iVar2 + 0x14) = 0x28;
      *(undefined2 *)(iVar2 + 0x16) = 0;
      *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 9;
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
  }
  else {
    iVar2 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x28) != 0)) {
      CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(*(int *)(iVar2 + 0x28));
      return;
    }
  }
  return;
}

