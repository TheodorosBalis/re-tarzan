// Address: 0x004A1A10

void StopActiveStreamedWork(void)

{
  if (DAT_00724ed0 != 0) {
    DAT_00724ed8 = 0;
    StopAndSynchronizeStreamedWork();
    return;
  }
  return;
}


