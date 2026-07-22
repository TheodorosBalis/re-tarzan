#include "tarzan_ghidra_types.hpp"

// Address: 0x004980E0
// Label: SynchronizeWithStreamedThread
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SynchronizeWithStreamedThread(char arg1)

{
  HANDLE value2;
  DWORD apiResult;
  int value;
  
  if (arg1 == '\0') {
    if (g_StreamingPriorityBoostActive != 0) {
      apiResult = g_SavedProcessPriorityClass;
      value2 = GetCurrentProcess();
      SetPriorityClass(value2,apiResult);
      value = g_SavedThreadPriority;
      value2 = GetCurrentThread();
      SetThreadPriority(value2,value);
      g_StreamingPriorityBoostActive = 0;
    }
  }
  else if (g_StreamingPriorityBoostActive == 0) {
    value2 = GetCurrentProcess();
    g_SavedProcessPriorityClass = GetPriorityClass(value2);
    value2 = GetCurrentThread();
    g_SavedThreadPriority = GetThreadPriority(value2);
    apiResult = 0x80;
    value2 = GetCurrentProcess();
    SetPriorityClass(value2,apiResult);
    value = 2;
    value2 = GetCurrentThread();
    SetThreadPriority(value2,value);
    if (g_StreamingThreadHandle != (HANDLE)0x0) {
      SetThreadPriority(g_StreamingThreadHandle,-2);
    }
    g_StreamingPriorityBoostActive = 1;
    return;
  }
  return;
}

