#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1C6C
// Label: _lock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _lock(int arg1)

{
  int *intCursor;
  LPCRITICAL_SECTION lpCriticalSection;
  
  intCursor = (int *)(&g_CrtLockCriticalSectionTable + arg1 * 4);
  if (*(int *)(&g_CrtLockCriticalSectionTable + arg1 * 4) == 0) {
    lpCriticalSection = malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    _lock(0x11);
    if (*intCursor == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *intCursor = (int)lpCriticalSection;
    }
    else {
      free();
    }
    _unlock(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*intCursor);
  return;
}

