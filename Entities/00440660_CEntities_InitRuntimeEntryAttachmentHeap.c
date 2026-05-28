
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities__InitRuntimeEntryAttachmentHeap(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = param_1 + 3U & 0xfffffffc;
  puVar1 = (undefined4 *)CompactAndAllocModelHeapBlock(uVar2,&g_ModelLoadHeapState);
  if (puVar1 != (undefined4 *)0x0) {
    _g_RuntimeEntryAttachmentHeapSentinel = 0;
    _DAT_00531d90 = uVar2 | 2;
    _DAT_00531d88 = 0;
    g_RuntimeEntryAttachmentHeapEnd = (int)puVar1 + uVar2;
    _DAT_00531d94 = 0;
    _DAT_00531d84 = puVar1;
    g_RuntimeEntryAttachmentFreeBlockHead = puVar1;
    g_RuntimeEntryAttachmentHeapStart = puVar1;
    puVar1[4] = uVar2 - 0x18 | 1;
    *puVar1 = &g_RuntimeEntryAttachmentHeapSentinel;
    puVar1[1] = 0;
    puVar1[2] = &g_RuntimeEntryAttachmentHeapSentinel;
    puVar1[3] = 0;
    puVar1[5] = 0;
    uVar2 = uVar2 - 0x30 >> 2;
    puVar1 = puVar1 + 6;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

