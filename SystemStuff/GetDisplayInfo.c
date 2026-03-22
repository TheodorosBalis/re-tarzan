/* Address: 0x004B0122 */

void GetDisplayInfo(void)

{
  if (SetupVfTableAndCPUcheck != (undefined *)0x0) {
    (*(code *)SetupVfTableAndCPUcheck)();
  }
  CallSetUpFunctions(&DAT_004bc024,&DAT_004bc030);
  CallSetUpFunctions(&DAT_004bc000,&DAT_004bc020);
  return;
}

