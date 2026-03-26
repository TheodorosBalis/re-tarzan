// Address: 0x0049B440

void PresentBackBufferWithGdi(void)

{
  if (isGraphicsInitialized != 0) {
    SetZeroFlagIfGraphicsAreInitialized();
    SetDIBitsToDevice(BitMapInfo_Struct,0,0,0x140,0xf0,0,0,0,0xf0,lpvBitsColorDataPTR,
                      (BITMAPINFO *)&DAT_00722830,0);
                    /* WARNING: Could not recover jumptable at 0x0049b481. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    GdiFlush();
    return;
  }
  return;
}


