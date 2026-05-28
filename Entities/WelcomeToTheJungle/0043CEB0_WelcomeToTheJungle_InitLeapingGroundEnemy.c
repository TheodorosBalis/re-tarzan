
void WelcomeToTheJungle__InitLeapingGroundEnemy(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x1000;
  iVar2 = g_WorldSceneEntryArrayBase;
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(undefined2 *)(iVar1 + 0x140) = 0;
    *(int *)(iVar1 + 0x10) = iVar2 + 0x12b0;
    if (g_LevelTransitionContext._2_1_ != '\n') {
      CEntities__AcquireSceneEntryResourceSet(iVar1);
    }
    CEntities__SetSceneEntryScriptAttachment(param_1,&g_LeapingGroundEnemyScriptAttachmentDesc);
    *(undefined2 *)(param_1 + 0x48) = 0;
    *(undefined2 *)(param_1 + 0x4a) = 0;
  }
  return;
}

