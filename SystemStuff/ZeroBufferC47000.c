/* Address: 0x004B77D9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ZeroBufferC47000(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00c47120;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00c46ff0 = 0;
  _DAT_00c4700c = 0;
  DAT_00c47224 = 0;
  DAT_00c47000 = 0;
  DAT_00c47004 = 0;
  DAT_00c47008 = 0;
  return;
}

