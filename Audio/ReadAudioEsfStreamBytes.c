// Address: 0x00498A70

void ReadAudioEsfStreamBytes(undefined4 *param_1,uint param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (((g_AudioEsfStreamHandle != 0) && (param_1 != (undefined4 *)0x0)) && (0 < (int)param_2)) {
    if ((int)(g_AudioEsfStreamFlagsAndSize & 0xfffffff) <
        (int)(g_AudioEsfStreamReadOffset + param_2)) {
      uVar2 = (undefined1)((~g_AudioEsfStreamFlagsAndSize >> 0x1c & 1) << 7);
      puVar5 = param_1;
      for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar5 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
        puVar5 = puVar5 + 1;
      }
      for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
        *(undefined1 *)puVar5 = uVar2;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      param_2 = (g_AudioEsfStreamFlagsAndSize & 0xfffffff) - g_AudioEsfStreamReadOffset;
    }
    g_AudioEsfStreamReadOffset = g_AudioEsfStreamReadOffset + param_2;
    if ((g_AudioEsfStreamFlagsAndSize & 0x10000000) == 0) {
      ReadVirtualGameFileIntoBuffer(param_1,param_2,1,g_AudioEsfStreamHandle);
      iVar3 = 0;
      if (0 < (int)param_2) {
        do {
          *(byte *)(iVar3 + (int)param_1) =
               *(byte *)(iVar3 + (int)param_1) ^ (byte)g_AudioEsfStreamXorKey;
          g_AudioEsfStreamXorKey = g_AudioEsfStreamXorKey + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)param_2);
      }
    }
    else {
      if ((g_AudioEsfStreamFlagsAndSize & 0x80000000) != 0) {
        iVar6 = (int)(param_2 + ((int)param_2 >> 0x1f & 3U)) >> 2;
        puVar1 = (undefined1 *)((int)param_1 + param_2 + (-1 - iVar6));
        ReadVirtualGameFileIntoBuffer(puVar1,iVar6,1,g_AudioEsfStreamHandle);
        iVar3 = 0;
        if (0 < iVar6) {
          do {
            puVar1[iVar3] = puVar1[iVar3] ^ (byte)g_AudioEsfStreamXorKey;
            g_AudioEsfStreamXorKey = g_AudioEsfStreamXorKey + 1;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar6);
        }
        FUN_00493be0(puVar1,param_1,param_2,&DAT_00719e60);
        return;
      }
      ReadVirtualGameFileIntoBuffer(param_1,param_2,1,g_AudioEsfStreamHandle);
      iVar3 = 0;
      if (0 < (int)param_2) {
        do {
          *(byte *)(iVar3 + (int)param_1) =
               *(byte *)(iVar3 + (int)param_1) ^ (byte)g_AudioEsfStreamXorKey;
          g_AudioEsfStreamXorKey = g_AudioEsfStreamXorKey + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)param_2);
        return;
      }
    }
  }
  return;
}


