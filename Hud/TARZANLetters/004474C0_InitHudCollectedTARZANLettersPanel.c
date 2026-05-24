
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudCollectedTARZANLettersPanel(void)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  short *psVar6;
  
  uVar4 = DAT_00532e40;
  iVar1 = g_WorldSceneEntryArrayBase + 0x68;
  g_HudCollectedTARZANslotScene = &DAT_00532e14;
  _DAT_00532e20 = 0;
  _DAT_00532e22 = 0x121;
  _DAT_00532e68 = 0x10000;
  _DAT_00532e6c = 0x5000;
  _DAT_00532e30 = 0;
  _DAT_00532e44 = 0x400;
  _DAT_00532eba = 1;
  _DAT_0053271c = 6;
  psVar6 = &DAT_004f0334;
  puVar5 = &g_HudTARZANLetterQuad0Flags;
  _DAT_00532e24 = iVar1;
  do {
    uVar3 = DAT_00532e34;
    sVar2 = *psVar6;
    *(int *)(puVar5 + 1) = iVar1;
    *puVar5 = 0x8521;
    *(int *)(puVar5 + 3) = (int)sVar2;
    *(undefined4 *)(puVar5 + 5) = 0;
    *(undefined4 *)(puVar5 + 7) = 0;
    psVar6 = psVar6 + 1;
    *(undefined4 *)(puVar5 + 9) = uVar3;
    *(undefined4 *)(puVar5 + 0xb) = DAT_00532e38;
    *(undefined4 *)(puVar5 + 0xd) = DAT_00532e3c;
    *(undefined4 *)(puVar5 + 0xf) = uVar4;
    *(undefined4 *)(puVar5 + 0x11) = 0x400;
    puVar5 = puVar5 + 0x14;
  } while ((int)psVar6 < 0x4f0340);
  _DAT_00532720 = 0x2005;
  _DAT_00532748 = 0x2006;
  _DAT_00532770 = 0x2007;
  _DAT_00532798 = 0x2008;
  _DAT_005327c0 = 0x2006;
  _DAT_005327e8 = 0x2009;
  g_CollectedTARZANLetterMask6 = 0;
  g_HudCollectedTARZANslotSlideTicks = 0x78;
  return;
}

