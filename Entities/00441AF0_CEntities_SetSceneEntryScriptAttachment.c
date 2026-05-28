
uint * CEntities__SetSceneEntryScriptAttachment(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = param_2[2];
  if ((uVar1 & 0x400) == 0) {
    return (uint *)0x0;
  }
  puVar2 = (uint *)FindRuntimeEntityAttachmentByFlags(param_1,0x400);
  if ((puVar2 == (uint *)0x0) &&
     (puVar2 = (uint *)CEntities__CreateSceneEntryScriptAttachment(param_1), puVar2 == (uint *)0x0))
  {
    return (uint *)0x0;
  }
  *puVar2 = *puVar2 ^ (*puVar2 ^ uVar1) & 0xff;
  puVar2[3] = *param_2;
  puVar2[4] = param_2[1];
  CEntities__AdvanceScriptAttachmentSequence(puVar2);
  return puVar2;
}

