// Address: 0x004A7C00

/* WARNING: Type propagation algorithm not settling */

void InitSoundAndNewGameStateFile(uint param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  bool bVar12;
  int local_13c;
  uint local_138;
  int local_134;
  undefined2 local_130;
  undefined2 local_12e;
  int local_12c;
  int local_128;
  ushort local_124;
  ushort uStack_122;
  undefined2 local_120;
  int local_11c [4];
  undefined4 local_10c;
  undefined2 *local_108;
  int local_104;
  undefined1 local_100 [256];
  
  iVar9 = 0;
  local_13c = 0;
  local_138 = 0;
  if (g_IsDSoundInitialized != 0) {
    if ((ushort)param_1 < 2000) {
      iVar8 = (int)(short)(ushort)param_1;
      iVar10 = iVar8 * 0x2c;
      if (((&DAT_009cf246)[iVar10] & 2) != 0) {
        (&DAT_009cf246)[iVar10] = (&DAT_009cf246)[iVar10] & 0xfd;
        return;
      }
      piVar1 = &DAT_009cf220 + iVar8 * 0xb;
      if ((&DAT_009cf220)[iVar8 * 0xb] == 0) {
        piVar11 = piVar1;
        for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar11 = 0;
          piVar11 = piVar11 + 1;
        }
        if (100 < DAT_009e4a44) {
          DAT_009e4a44 = 0;
        }
        DrawGraphicsTextinMem_2(local_100,s_t__win_sound_sfx_pc__04d_esf_0051761c,param_1 & 0xffff);
        uVar6 = OpenAudioEsfStream(local_100,&local_104,&local_134,local_11c);
        *(undefined4 *)(&DAT_009cf240 + iVar10) = uVar6;
        *(undefined2 *)(&DAT_009cf244 + iVar10) = 0;
        local_130 = 1;
        local_12e = 1;
        (&DAT_009cf246)[iVar10] =
             (local_11c[0] != 0 ^ (&DAT_009cf246)[iVar10] & 0xf9) & 1 ^
             (&DAT_009cf246)[iVar10] & 0xf9;
        local_12c = (-(uint)(local_134 != 0x2b11) & 0x2b11) + 0x2b11;
        local_11c[3] = *(int *)(&DAT_009cf240 + iVar10);
        local_120 = 0;
        uVar4 = (-(ushort)(local_104 != 8) & 8) + 8;
        uVar5 = uVar4 >> 3;
        _local_124 = CONCAT22(uVar4,uVar5);
        local_128 = (uint)uVar5 * local_12c;
        local_108 = &local_130;
        local_11c[1] = 0x14;
        local_11c[2] = 0x92;
        local_10c = 0;
        if (g_DirectSound != (int *)0x0) {
          (**(code **)(*g_DirectSound + 0xc))(g_DirectSound,local_11c + 1,piVar1,0);
        }
        piVar11 = (int *)*piVar1;
        if (piVar11 != (int *)0x0) {
          DAT_009e4a54 = DAT_009e4a54 + *(int *)(&DAT_009cf240 + iVar10);
          DAT_009e4a58 = DAT_009e4a58 + 1;
          (**(code **)(*piVar11 + 0x2c))
                    (piVar11,0,*(int *)(&DAT_009cf240 + iVar10),&local_13c,&local_138,0,0,0);
          if ((local_13c != 0) && (*(uint *)(&DAT_009cf240 + iVar10) <= local_138)) {
            LoadUnknownFileOnNewGameState(local_13c);
          }
          piVar11 = (int *)*piVar1;
          if (piVar11 != (int *)0x0) {
            (**(code **)(*piVar11 + 0x4c))(piVar11,local_13c,local_138,0,0);
          }
          do {
            piVar11 = g_DirectSound;
            if (iVar9 != 0) {
              piVar3 = &DAT_009cf220 + iVar8 * 0xb + iVar9;
              bVar12 = g_DirectSound != (int *)0x0;
              *piVar3 = 0;
              if (bVar12) {
                (**(code **)(*piVar11 + 0x14))(piVar11,*piVar1,piVar3);
              }
              if (*piVar3 == 0) {
                FUN_004a7f10(param_1);
                break;
              }
            }
            iVar10 = iVar8 * 0xb + iVar9;
            piVar11 = (int *)(&DAT_009cf230 + iVar10 * 4);
            *piVar11 = 0;
            puVar2 = (undefined4 *)(&DAT_009cf220)[iVar10];
            if (puVar2 != (undefined4 *)0x0) {
              (**(code **)*puVar2)(puVar2,&DAT_004ba3e0,piVar11);
            }
            piVar3 = (int *)(&DAT_009cf220)[iVar10];
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 0x34))(piVar3,0);
            }
            piVar3 = (int *)(&DAT_009cf220)[iVar10];
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 0x3c))(piVar3,0);
            }
            piVar3 = (int *)*piVar11;
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 0x4c))(piVar3,0,0,0,0);
            }
            piVar11 = (int *)*piVar11;
            if (piVar11 != (int *)0x0) {
              (**(code **)(*piVar11 + 0x50))(piVar11,0,0,0,0);
            }
            iVar9 = iVar9 + 1;
            if (3 < iVar9) {
              CloseAudioEsfStream();
              return;
            }
          } while( true );
        }
        CloseAudioEsfStream();
      }
    }
  }
  return;
}


