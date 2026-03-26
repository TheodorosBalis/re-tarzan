// Address: 0x0049B5D0

void SetZeroFlagIfGraphicsAreInitialized(void)

{
  if ((isGraphicsInitialized != 0) && (DAT_00722864 != 0)) {
    DAT_00722864 = 0;
  }
  return;
}


