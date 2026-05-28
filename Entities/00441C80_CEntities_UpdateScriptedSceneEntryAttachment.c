
undefined4 CEntities__UpdateScriptedSceneEntryAttachment(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  if (((*param_1 & 0x500) == 0x500) && (uVar1 = param_1[0xe], uVar1 != 0)) {
    puVar2 = (uint *)FindRuntimeEntityAttachmentByFlags(param_1,0x400);
    if (puVar2 != (uint *)0x0) {
      if ((*puVar2 & 0xff) == 1) {
        uVar3 = CEntities__UpdateSceneEntryScript(param_1,uVar1,puVar2);
        return uVar3;
      }
      if ((*puVar2 & 0xff) == 2) {
        uVar3 = CEntities__PlayTimedScriptedSceneEntryEffect(param_1,uVar1,puVar2);
        return uVar3;
      }
    }
  }
  return 1;
}

