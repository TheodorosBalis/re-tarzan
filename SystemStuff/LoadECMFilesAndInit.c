// Address: 0x00493F70

undefined4 LoadECMFilesAndInit(void)

{
  int iVar1;
  undefined1 *puVar2;
  MCIERROR MVar3;
  undefined1 local_28;
  undefined1 uStack_27;
  undefined1 local_26;
  undefined1 local_24 [8];
  undefined4 local_1c;
  undefined4 local_14;
  MCIDEVICEID local_10;
  undefined4 local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  if (DAT_0053a2fc != 0) {
LAB_00494041:
    local_1c = 5;
    mciSendCommandA(DAT_0053a2f8,0x814,0x100,(DWORD_PTR)local_24);
    return 1;
  }
  local_10 = 0;
  local_14 = 0;
  local_c = 0x204;
  local_8 = (undefined1 *)0x0;
  local_4 = 0;
  iVar1 = LoadECMfile(s_stranger_ecm_005156dc);
  if (iVar1 != 0) {
    iVar1 = LoadECMfile(s_disney_ecm_005156d0);
    if (iVar1 != 0) {
      puVar2 = (undefined1 *)LoadECMfile(s_eurocom_ecm_005156c4);
      if (puVar2 != (undefined1 *)0x0) {
        local_26 = DAT_005156c2;
        local_8 = &local_28;
        _local_28 = CONCAT11((char)((ushort)DAT_005156c0 >> 8),*puVar2);
        MVar3 = mciSendCommandA(0,0x803,0x3302,(DWORD_PTR)&local_14);
        DAT_0053a2fc = (uint)(MVar3 == 0);
        DAT_0053a2f8 = local_10;
        goto LAB_00494041;
      }
    }
  }
  return 0;
}


