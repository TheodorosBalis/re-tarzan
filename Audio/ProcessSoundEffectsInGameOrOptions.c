/* Address: 0x004A9190 */

void ProcessSoundEffectsInGameOrOptions(void)

{
  if (DAT_009e4a64 != 0) {
    if (DAT_009e4a30 != (int *)0x0) {
      (**(code **)(*DAT_009e4a30 + 0x44))(DAT_009e4a30);
    }
    FUN_004a91c0();
    FUN_004a8af0();
    return;
  }
  return;
}

