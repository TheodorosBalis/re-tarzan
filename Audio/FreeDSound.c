/* Address: 0x004A8A20 */

void FreeDSound(void)

{
  DAT_009e4a60 = 1;
  FUN_004a8e40();
  FUN_004a89f0();
  DAT_009e4a60 = 0;
  FUN_004a8930();
  CheckForLegacyLib_stub();
  if (DAT_009e4a30 != (int *)0x0) {
    (**(code **)(*DAT_009e4a30 + 8))(DAT_009e4a30);
  }
  if (DAT_009e4a2c != (int *)0x0) {
    (**(code **)(*DAT_009e4a2c + 8))(DAT_009e4a2c);
  }
  if (DAT_009e4a28 != (int *)0x0) {
    (**(code **)(*DAT_009e4a28 + 8))(DAT_009e4a28);
  }
  if (DAT_009e4a24 != (HMODULE)0x0) {
    FreeLibrary(DAT_009e4a24);
  }
  SetupAudioBuffers();
  return;
}

