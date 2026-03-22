/* Address: 0x004A9140 */

void InitAudioLine(void)

{
  if (AudioLinesPTR != (int *)0x0) {
    (**(code **)(*AudioLinesPTR + 0x3c))(AudioLinesPTR,(int)DAT_009cf150);
    if (AudioLinesPTR != (int *)0x0) {
      (**(code **)(*AudioLinesPTR + 0x48))(AudioLinesPTR);
      if (AudioLinesPTR != (int *)0x0) {
        (**(code **)(*AudioLinesPTR + 8))(AudioLinesPTR);
      }
    }
  }
  AudioLinesPTR = (int *)0x0;
  FUN_00498c10();
  DAT_009e4a7c = 0;
  return;
}

