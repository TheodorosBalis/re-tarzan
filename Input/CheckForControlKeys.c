/* Address: 0x0049E500 */

void CheckForControlKeys(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0049e060(0x26);
  if (iVar1 != 0) {
    *(uint *)PTR_DAT_0051621c = *(uint *)PTR_DAT_0051621c | DAT_00516218;
  }
  iVar1 = FUN_0049e060(0x28);
  if (iVar1 != 0) {
    *(uint *)PTR_DAT_00516224 = *(uint *)PTR_DAT_00516224 | DAT_00516220;
  }
  iVar1 = FUN_0049e060(0x25);
  if (iVar1 != 0) {
    *(uint *)PTR_DAT_0051622c = *(uint *)PTR_DAT_0051622c | DAT_00516228;
  }
  iVar1 = FUN_0049e060(0x27);
  if (iVar1 != 0) {
    *(uint *)PTR_DAT_00516234 = *(uint *)PTR_DAT_00516234 | DAT_00516230;
  }
  iVar1 = FUN_0049e060(0x20);
  if (iVar1 != 0) {
    *(uint *)PTR_DAT_0051628c = *(uint *)PTR_DAT_0051628c | DAT_00516288;
  }
  iVar1 = FUN_0049e060(0xd);
  if (iVar1 != 0) {
    *(uint *)PTR_DAT_0051628c = *(uint *)PTR_DAT_0051628c | DAT_00516288;
  }
  iVar1 = FUN_0049e060(0x1b);
  if (iVar1 != 0) {
    *(uint *)PTR_DAT_00516284 = *(uint *)PTR_DAT_00516284 | DAT_00516280;
  }
  uVar2 = CheckForJoystickInputs(0);
  if ((uVar2 & 0x40000000) != 0) {
    *(uint *)PTR_DAT_0051621c = *(uint *)PTR_DAT_0051621c | DAT_00516218;
  }
  if ((uVar2 & 0x80000000) != 0) {
    *(uint *)PTR_DAT_00516224 = *(uint *)PTR_DAT_00516224 | DAT_00516220;
  }
  if ((uVar2 & 0x10000000) != 0) {
    *(uint *)PTR_DAT_0051622c = *(uint *)PTR_DAT_0051622c | DAT_00516228;
  }
  if ((uVar2 & 0x20000000) != 0) {
    *(uint *)PTR_DAT_00516234 = *(uint *)PTR_DAT_00516234 | DAT_00516230;
  }
  if ((uVar2 & 0xfffffff) != 0) {
    *(uint *)PTR_DAT_0051628c = *(uint *)PTR_DAT_0051628c | DAT_00516288;
  }
  return;
}

