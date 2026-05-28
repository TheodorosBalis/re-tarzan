
void CEntities__CreateSceneEntryScriptAttachment(uint *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)
           CEntities__AllocRuntimeEntryAttachment
                     (param_1,0x20,0x400,&g_RuntimeEntryScriptAttachmentTemplate);
  if (puVar1 != (undefined4 *)0x0) {
    *param_1 = *param_1 | 0x400;
    puVar3 = &g_RuntimeEntryScriptAttachmentTemplate;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar1 = puVar1 + 1;
    }
  }
  return;
}

