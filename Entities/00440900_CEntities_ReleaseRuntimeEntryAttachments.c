
void CEntities__ReleaseRuntimeEntryAttachments(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar4 = (uint *)param_1[2];
  puVar2 = param_1;
  while (puVar3 = puVar4, puVar3 != (uint *)0x0) {
    puVar2 = puVar3;
    puVar4 = (uint *)puVar3[2];
  }
  uVar1 = puVar2[1];
  while (uVar1 != 0) {
    CEntities__FreeRuntimeEntryAttachment(puVar2);
    puVar2 = (uint *)puVar2[1];
    uVar1 = puVar2[1];
  }
  *param_1 = *param_1 & 0xff;
  return;
}

