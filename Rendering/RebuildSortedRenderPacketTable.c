// Address: 0x004A9380

void RebuildSortedRenderPacketTable(void)

{
  ushort *puVar1;
  ushort uVar2;
  short *psVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar6 = g_RenderPacketCount;
  if (0 < g_RenderPacketCount) {
    puVar5 = &DAT_00a0899e;
    iVar4 = g_RenderPacketCount;
    do {
      iVar4 = iVar4 + -1;
      *puVar5 = (&DAT_009e4a80)[*puVar5];
      puVar5 = puVar5 + 0x1e;
    } while (iVar4 != 0);
  }
  puVar7 = &DAT_00a04a80;
  for (iVar4 = 0x400; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  if (0 < iVar6) {
    puVar5 = &DAT_00a0899e;
    iVar4 = iVar6;
    do {
      uVar2 = *puVar5;
      puVar5 = puVar5 + 0x1e;
      psVar3 = (short *)((int)&DAT_00a04a80 + (uint)uVar2 * 2);
      *psVar3 = *psVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  psVar3 = (short *)((int)&DAT_00a04a80 + 2);
  do {
    *psVar3 = *psVar3 + psVar3[-1];
    psVar3 = psVar3 + 1;
  } while ((int)psVar3 < 0xa05a80);
  if (-1 < iVar6 + -1) {
    puVar5 = &DAT_00a0899e + (iVar6 + -1) * 0x1e;
    do {
      puVar1 = puVar5 + -0x1b;
      uVar2 = *puVar5;
      puVar5 = puVar5 + -0x1e;
      psVar3 = (short *)((int)&DAT_00a04a80 + (uint)uVar2 * 2);
      *psVar3 = *psVar3 + -1;
      iVar6 = iVar6 + -1;
      *(ushort **)(&DAT_00a05a84 + (uint)*(ushort *)((int)&DAT_00a04a80 + (uint)uVar2 * 2) * 4) =
           puVar1;
    } while (iVar6 != 0);
  }
  return;
}


