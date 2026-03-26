// Address: 0x004984F0

void StopAndSynchronizeStreamedWork(void)

{
  DAT_00719d94 = DAT_00719d94 + 1;
  if (DAT_00719d8c != (int *)0x0) {
    (**(code **)(*DAT_00719d8c + 0x48))(DAT_00719d8c);
  }
  SynchronizeWithStreamedThread(0);
  return;
}


