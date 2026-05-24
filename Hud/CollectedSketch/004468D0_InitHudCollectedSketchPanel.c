
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudCollectedSketchPanel(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  uVar4 = DAT_00532cfc;
  uVar3 = DAT_00532cf8;
  iVar1 = g_WorldSceneEntryArrayBase + 0x68;
  g_HudCollectedSketchScene = &DAT_00532cd0;
  _DAT_00532cdc = 0;
  _DAT_00532d08 = &DAT_00532830;
  _DAT_00532cde = 0x521;
  _DAT_00532d24 = 0x10000;
  _DAT_00532d28 = 0xfffff100;
  _DAT_00532d2c = 0;
  _DAT_00532d00 = 0x600;
  _DAT_0053283c = 4;
  puVar5 = &DAT_00532842;
  _DAT_00532ce0 = iVar1;
  do {
    uVar2 = DAT_00532cf0;
    *(int *)(puVar5 + 1) = iVar1;
    *puVar5 = 0x8521;
    *(undefined4 *)(puVar5 + 3) = 0;
    *(undefined4 *)(puVar5 + 5) = 0;
    *(undefined4 *)(puVar5 + 7) = 0;
    puVar6 = puVar5 + 0x14;
    *(undefined4 *)(puVar5 + 9) = uVar2;
    *(undefined4 *)(puVar5 + 0xb) = DAT_00532cf4;
    *(undefined4 *)(puVar5 + 0xd) = uVar3;
    *(undefined4 *)(puVar5 + 0xf) = uVar4;
    *(undefined4 *)(puVar5 + 0x11) = 0x600;
    puVar5 = puVar6;
  } while ((int)puVar6 < 0x5328e2);
  _DAT_00532840 = 0x2000;
  _DAT_00532868 = 0x2001;
  _DAT_00532890 = 0x2002;
  _DAT_005328b8 = 0x2003;
  g_CollectedSketchPieceMask4 = 0;
  g_HudCollectedSketchSlideTicks = 0x78;
  return;
}

