// Address: 0x004AF150

void Main(void)

{
  DWORD DVar1;
  undefined4 in_stack_00000010;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004ba4a8;
  puStack_10 = &LAB_004b033c;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  SetupAndRestoreSEHFrame();
  local_8 = 0;
  fileHandle = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,2,0,0x20,
                                  s_DITARZANAG_00518e60);
  DVar1 = GetLastError();
  if (DVar1 != 0) {
    ExitIfFailed2();
  }
  CreateShowUpdateWindow(in_stack_00000010);
  SetupGraphicsAudioEfGandECMFiles(mainWindowHandle);
  SetIsWindowActive();
  IsGameRunningOnCD();
  do {
    ProcessGameLogic();
    ProcessGameLogic();
    WinMessageLoop();
  } while( true );
}


