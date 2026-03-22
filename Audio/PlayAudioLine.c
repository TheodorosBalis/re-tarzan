/* Address: 0x004A8E70 */

void PlayAudioLine(void)

{
  DWORD DVar1;
  
  if ((AudioLinesPTR != (int *)0x0) && (DAT_009e4a7c == 0)) {
    DVar1 = timeGetTime();
    DAT_009e4a7c = DVar1 | 1;
    if (AudioLinesPTR != (int *)0x0) {
      (**(code **)(*AudioLinesPTR + 0x48))(AudioLinesPTR);
    }
  }
  return;
}

