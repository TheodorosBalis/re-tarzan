
void WelcomeToTheJungle__InitCivetCubSpawner(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x38);
  iVar3 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x10) = g_WorldSceneEntryArrayBase + 0xb60;
    CEntities__AcquireSceneEntryResourceSet(iVar2);
    *(ushort *)(iVar2 + 0xe) = *(ushort *)(iVar2 + 0xe) & 0x7fff;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    sVar1 = *(short *)(iVar3 + 0xc);
    *(short *)(param_1 + 0x4a) = sVar1;
    if (sVar1 == 0) {
      *(undefined2 *)(param_1 + 0x4a) = 0x3c;
    }
    iVar2 = *(int *)(iVar3 + 0x10);
    *(int *)(param_1 + 0x50) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x50) = 0x3c;
    }
  }
  return;
}

