/* Address: 0x004987E0 */

int SetupAndLoadMenuEfgFile(undefined4 param_1)

{
  int iVar1;
  
  FUN_00498930();
  DAT_00719db8 = LocateAndSetBufferForEgfObject(param_1,&DAT_005156bc);
  if ((DAT_00719db8 != 0) &&
     (LoadAndCopyEfgToBuffer(&DAT_00719dc0,0x48,1,DAT_00719db8), DAT_00719dc0 == 0x2464745)) {
    DAT_00719e08 = 0;
    iVar1 = 0x48;
    do {
      if ((&DAT_00719dc8)[DAT_00719e08] == 0) {
        return DAT_00719e08;
      }
      (&DAT_00719e0c)[DAT_00719e08] = iVar1;
      iVar1 = iVar1 + (&DAT_00719dc8)[DAT_00719e08];
      DAT_00719e08 = DAT_00719e08 + 1;
    } while (DAT_00719e08 < 0x10);
    return DAT_00719e08;
  }
  FUN_00498930();
  return 0;
}

