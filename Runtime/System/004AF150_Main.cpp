#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF150
// Label: Main
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int Main(HANDLE appInstance,HANDLE previousInstance,LPSTR commandLine,int showCommand)

{
  DWORD apiResult;
  undefined4 incomingStackArg;
  void *localState4;
  code *localState2;
  undefined *localState3;
  undefined4 localState;
  
  localState = 0xffffffff;
  localState3 = &DAT_004ba4a8;
  localState2 = (code *)(undefined4 (__cdecl *)(...))_except_handler3;
  localState4 = ExceptionList;
  ExceptionList = &localState4;
  ProbeMmxCpuSupport();
  localState = 0;
  fileHandle = (int)CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,2,0,0x20,
                                       s_DITARZANAG_00518e60);
  apiResult = GetLastError();
  if (apiResult != 0) {
    ExitIfFailed2();
  }
  CreateShowUpdateWindow(incomingStackArg);
  SetupGraphicsAudioEfGandECMFiles(mainWindowHandle);
  UpdateMainWindowActiveState();
  IsGameRunningOnCD();
  do {
    ProcessGameLogic();
    ProcessGameLogic();
    WinMessageLoop();
  } while( true );
}

