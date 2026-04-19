// 004464b0

void CWorld::UpdateBonusLevelTimer(void)

{
  uint uVar1;
  undefined2 *puVar2;
  short sVar3;
  ushort *puVar4;
  byte bVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int local_4;
  
  if (g_HudCountdownScene != 0) {
    if ((DAT_00534010 & 0x800) == 0) {
      if ((g_HudCountdownFlags & 0x20) != 0) {
        uVar8 = (uint)(char)(g_HudCountdownBcdTime >> 8);
        uVar9 = uVar8 & 0x8000000f;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffff0) + 1;
        }
        uVar1 = (uint)(char)(g_HudCountdownBcdTime >> 0x10);
        iVar12 = uVar9 + ((int)(uVar8 + ((int)uVar8 >> 0x1f & 0xfU)) >> 4) * 10;
        uVar8 = uVar1 & 0x8000000f;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffff0) + 1;
        }
        iVar6 = uVar8 + ((int)(uVar1 + ((int)uVar1 >> 0x1f & 0xfU)) >> 4) * 10;
        uVar8 = (uint)(char)g_HudCountdownBcdTime;
        uVar9 = uVar8 & 0x8000000f;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffff0) + 1;
        }
        iVar10 = uVar9 + 2 + ((int)(uVar8 + ((int)uVar8 >> 0x1f & 0xfU)) >> 4) * 10;
        if (DAT_00533fee < iVar10) {
          iVar12 = iVar12 + 1;
          iVar10 = iVar10 - DAT_00533fee;
        }
        if (0x3b < iVar12) {
          iVar6 = iVar6 + 1;
          iVar12 = iVar12 + -0x3c;
        }
        if (0x3b < iVar6) {
          iVar6 = iVar6 + -0x3c;
        }
        g_HudCountdownBcdTime =
             ((char)((((char)(iVar6 / 10) + (char)(iVar6 >> 0x1f)) -
                     (char)((longlong)iVar6 * 0x66666667 >> 0x3f)) * '\x10' + (char)(iVar6 % 10)) *
              0x100 + (int)(char)((((char)(iVar12 / 10) + (char)(iVar12 >> 0x1f)) -
                                  (char)((longlong)iVar12 * 0x66666667 >> 0x3f)) * '\x10' +
                                 (char)(iVar12 % 10))) * 0x100 +
             (int)(char)((((char)(iVar10 / 10) + (char)(iVar10 >> 0x1f)) -
                         (char)((longlong)iVar10 * 0x66666667 >> 0x3f)) * '\x10' +
                        (char)(iVar10 % 10));
      }
      if ((g_HudCountdownFlags & 0x40) != 0) {
        uVar8 = (uint)(char)(g_HudCountdownBcdTime >> 8);
        uVar9 = uVar8 & 0x8000000f;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffff0) + 1;
        }
        iVar12 = uVar9 + ((int)(uVar8 + ((int)uVar8 >> 0x1f & 0xfU)) >> 4) * 10;
        uVar8 = (uint)(char)(g_HudCountdownBcdTime >> 0x10);
        uVar9 = uVar8 & 0x8000000f;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffff0) + 1;
        }
        uVar1 = (uint)(char)g_HudCountdownBcdTime;
        iVar6 = uVar9 + ((int)(uVar8 + ((int)uVar8 >> 0x1f & 0xfU)) >> 4) * 10;
        uVar8 = uVar1 & 0x8000000f;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffff0) + 1;
        }
        iVar10 = (uVar8 - 2) + ((int)(uVar1 + ((int)uVar1 >> 0x1f & 0xfU)) >> 4) * 10;
        if (iVar10 < 0) {
          iVar12 = iVar12 + -1;
          iVar10 = iVar10 + DAT_00533fee;
        }
        if (iVar12 < 0) {
          iVar6 = iVar6 + -1;
          iVar12 = iVar12 + 0x3c;
        }
        if (iVar6 < 0) {
          iVar6 = iVar6 + 0x3c;
        }
        g_HudCountdownBcdTime =
             ((char)((((char)(iVar6 / 10) + (char)(iVar6 >> 0x1f)) -
                     (char)((longlong)iVar6 * 0x66666667 >> 0x3f)) * '\x10' + (char)(iVar6 % 10)) *
              0x100 + (int)(char)((((char)(iVar12 / 10) + (char)(iVar12 >> 0x1f)) -
                                  (char)((longlong)iVar12 * 0x66666667 >> 0x3f)) * '\x10' +
                                 (char)(iVar12 % 10))) * 0x100 +
             (int)(char)((((char)(iVar10 / 10) + (char)(iVar10 >> 0x1f)) -
                         (char)((longlong)iVar10 * 0x66666667 >> 0x3f)) * '\x10' +
                        (char)(iVar10 % 10));
      }
    }
    uVar8 = g_HudCountdownBcdTime;
    uVar9 = g_HudCountdownBcdTime >> 8;
    bVar5 = (byte)g_HudCountdownFlags;
    if (((g_HudCountdownFlags & 0x100) != 0) && (uVar9 == 0)) {
      g_LoadTransitionFlags._0_2_ = (ushort)g_LoadTransitionFlags | 0x8001;
      g_PlayerSequenceFlags._1_1_ = g_PlayerSequenceFlags._1_1_ | 0x40;
      g_HudCountdownFlags = CONCAT22(g_HudCountdownFlags._2_2_,0x8000);
      bVar5 = 0;
      g_HudCountdownBcdTime = 0;
    }
    if ((bVar5 & 0x80) != 0) {
      if (uVar9 < 6) {
        if ((DAT_005329a0 & 0xffff) != uVar9) {
          PlayAudioById(1099,0,0);
          DAT_005329a0 = CONCAT22(DAT_005329a0._2_2_,(short)(uVar8 >> 8));
          bVar5 = (byte)g_HudCountdownFlags;
        }
      }
      else {
        DAT_005329a0 = CONCAT22(DAT_005329a0._2_2_,99);
      }
    }
    if ((bVar5 & 0x10) != 0) {
      *(ushort *)(g_HudCountdownScene + 0xe) = *(ushort *)(g_HudCountdownScene + 0xe) & 0x7fff;
      bVar5 = (byte)g_HudCountdownFlags;
      if ((g_HudCountdownFlags & 2) == 0) {
        *(ushort *)(g_HudCountdownScene + 0xe) =
             *(ushort *)(g_HudCountdownScene + 0xe) |
             (-(ushort)(0x1c < ((byte)g_HudCountdownBcdTime & 0x70)) & 0x8000) + 0x8000;
        bVar5 = (byte)g_HudCountdownFlags;
      }
    }
    uVar1 = g_HudCountdownBcdTime;
    uVar8 = g_HudCountdownFlags & 4;
    uVar11 = -(uint)((g_HudCountdownFlags & 4) != 0) & 0xfffffffe;
    local_4 = uVar11 + 4;
    if (0 < local_4) {
      psVar7 = &DAT_005328f8;
      do {
        sVar3 = (short)(uVar9 & 0xf);
        if (9 < (uVar9 & 0xf)) {
          sVar3 = 0;
        }
        *psVar7 = sVar3 + 0x200f;
        uVar9 = uVar9 >> 4;
        psVar7 = psVar7 + 0x14;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
    if ((bVar5 & 1) != 0) {
      uVar9 = (byte)~bVar5 >> 1 & 1;
      uVar8 = (-(uint)(uVar8 != 0) & 0xff10f000) + 0xf00000;
      iVar12 = uVar11 + 3;
      if ((int)uVar9 < iVar12) {
        puVar4 = &DAT_005328fa + iVar12 * 0x14;
        while ((uVar8 & uVar1) == 0) {
          *puVar4 = *puVar4 & 0x7fff;
          puVar4 = puVar4 + -0x14;
          uVar8 = uVar8 >> 4;
          iVar12 = iVar12 + -1;
          if (iVar12 <= (int)uVar9) {
            return;
          }
        }
        if ((int)uVar9 < iVar12) {
          iVar6 = iVar12 - uVar9;
          puVar2 = &DAT_005328fa + iVar12 * 0x14;
          do {
            *(byte *)((int)puVar2 + 1) = *(byte *)((int)puVar2 + 1) | 0x80;
            puVar2 = puVar2 + -0x14;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
  }
  return;
}