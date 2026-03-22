/* Address: 0x0049A580 */

undefined1 * LocateMenuEgfFile(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_1 == (byte *)0x0) || (*param_1 == 0)) {
    return (undefined1 *)0x0;
  }
  uVar3 = 0;
  iVar4 = (int)&DAT_00721ecc - (int)param_1;
  do {
    if (0x3fe < uVar3) break;
    bVar2 = *param_1;
    if ((0x60 < bVar2) && (bVar2 < 0x7b)) {
      bVar2 = bVar2 - 0x20;
    }
    param_1[iVar4] = bVar2;
    pbVar1 = param_1 + 1;
    uVar3 = uVar3 + 1;
    param_1 = param_1 + 1;
  } while (*pbVar1 != 0);
  (&DAT_00721ecc)[uVar3] = 0;
  if ((((DAT_00721ecc == '\0') || (DAT_00721ecd != ':')) || (DAT_00721ece != '\\')) ||
     (DAT_00721ecf == '\0')) {
    InternalError(s_Partial_filename_00515c1c);
  }
  return &DAT_00721ecc;
}

