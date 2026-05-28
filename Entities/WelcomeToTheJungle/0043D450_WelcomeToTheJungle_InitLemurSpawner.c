
void WelcomeToTheJungle__InitLemurSpawner(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x10) = g_WorldSceneEntryArrayBase + 0x478;
    CEntities__AcquireSceneEntryResourceSet(iVar1);
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) & 0x7fff;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
      *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(iVar1 + 0xc);
      *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar1 + 0x10);
    }
    if (*(short *)(param_1 + 0x4a) == 0) {
      *(undefined2 *)(param_1 + 0x4a) = 0x3c;
    }
    if (*(int *)(param_1 + 0x50) == 0) {
      *(undefined4 *)(param_1 + 0x50) = 0x3c;
    }
  }
  return;
}

