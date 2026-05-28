
void WelcomeToTheJungle__UpdateChameleon(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    iVar3 = FindRuntimeEntityAttachmentByFlags(param_1,0x400);
    if (iVar3 != 0) {
      CEntities__UpdateScriptedSceneEntryAttachment(param_1);
      CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar1,8,8);
      if ((*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar1 + 0x110) * 4) + 8 +
                    *(int *)(iVar1 + 0x110) * 4 + g_CollisionSurfaceTable) - *(int *)(iVar1 + 0x10c)
           < 0x14) && (*(char *)(iVar1 + 0x75) == '\0')) {
        *(undefined1 *)(iVar1 + 0x75) = 0xff;
      }
      else if ((*(int *)(iVar1 + 0x10c) < 0x14) && (*(char *)(iVar1 + 0x75) == -1)) {
        *(undefined1 *)(iVar1 + 0x75) = 0;
      }
    }
  }
  cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar2 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

