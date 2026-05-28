
void CEntities__FreeRuntimeEntryAttachment(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined *puVar8;
  uint uVar9;
  
  if ((g_RuntimeEntryAttachmentHeapStart < param_1) && (param_1 < g_RuntimeEntryAttachmentHeapEnd))
  {
    puVar6 = (uint *)param_1[-1];
    puVar7 = param_1 + -6;
    uVar9 = param_1[-2];
    if (puVar6 != (uint *)0x0) {
      *puVar6 = *puVar6 & (uint)((*param_1 & 0xffffff00) == 0);
    }
    uVar1 = param_1[1];
    if ((uVar1 != 0) && (uVar2 = param_1[2], *(uint *)(uVar1 + 8) = uVar2, uVar2 != 0)) {
      *(uint *)(param_1[2] + 4) = uVar1;
    }
    puVar6 = (uint *)param_1[-5];
    puVar8 = &g_RuntimeEntryAttachmentHeapSentinel;
    if ((puVar6 != (uint *)0x0) && ((puVar6[4] & 1) != 0)) {
      uVar9 = uVar9 + 0x18 + (puVar6[4] & 0xfffffffc);
      *(uint *)(puVar6[2] + 0xc) = puVar6[3];
      if (*(int *)(puVar6[2] + 0xc) != 0) {
        *(uint *)(puVar6[3] + 8) = puVar6[2];
      }
      puVar8 = (undefined *)puVar6[2];
      puVar6 = (uint *)puVar6[1];
    }
    puVar3 = (uint *)*puVar7;
    if ((puVar3 != (uint *)0x0) && ((puVar3[4] & 1) != 0)) {
      uVar9 = uVar9 + 0x18 + (puVar3[4] & 0xfffffffc);
      *(uint *)(puVar3[2] + 0xc) = puVar3[3];
      if (*(int *)(puVar3[2] + 0xc) != 0) {
        *(uint *)(puVar3[3] + 8) = puVar3[2];
      }
      puVar8 = (undefined *)puVar3[2];
      puVar7 = puVar3;
    }
    puVar7[4] = uVar9 | 1;
    puVar5 = *(undefined **)(puVar8 + 0xc);
    while ((puVar4 = puVar5, puVar4 != (undefined *)0x0 && (*(uint *)(puVar4 + 0x10) <= uVar9))) {
      puVar8 = puVar4;
      puVar5 = *(undefined **)(puVar4 + 0xc);
    }
    puVar7[1] = (uint)puVar6;
    if (puVar6 != (uint *)0x0) {
      *puVar6 = (uint)puVar7;
    }
    uVar9 = *(uint *)(puVar8 + 0xc);
    puVar7[3] = uVar9;
    if (uVar9 != 0) {
      *(uint **)(uVar9 + 8) = puVar7;
    }
    *(uint **)(puVar8 + 0xc) = puVar7;
    puVar7[2] = (uint)puVar8;
  }
  return;
}

