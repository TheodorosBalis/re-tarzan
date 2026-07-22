#include "tarzan_ghidra_types.hpp"

// Address: 0x004A7A10
// Label: LegacyAudioCheck_DoNothing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LegacyAudioCheck_DoNothing(undefined4 soundId)

{
  undefined4 localState;
  undefined4 localState4;
  undefined4 localState3;
  undefined4 localState2;
  
  if (g_DSound3DListener != (int *)0x0) {
    switch(soundId) {
    case 1:
      localState = 8;
      localState4 = 0x3f000000;
      localState3 = 0x4038b439;
      localState2 = 0x3fa6e979;
      (**(code **)(*g_DSound3DListener + 0x10))
                (g_DSound3DListener,&DAT_004ba430,0,0,0,&localState,0x10);
      return;
    case 2:
      localState = 0x16;
      localState4 = 0x3f800000;
      localState3 = 0x3fbfdf3b;
      localState2 = 0;
      (**(code **)(*g_DSound3DListener + 0x10))
                (g_DSound3DListener,&DAT_004ba430,0,0,0,&localState,0x10);
      return;
    case 3:
      localState = 0xf;
      localState4 = 0x3de353f8;
      localState3 = 0x404947ae;
      localState2 = 0x3ef1a9fc;
      (**(code **)(*g_DSound3DListener + 0x10))
                (g_DSound3DListener,&DAT_004ba430,0,0,0,&localState,0x10);
      return;
    case 4:
      localState = 2;
      localState4 = 0x3ed58106;
      localState3 = 0x3ecccccd;
      localState2 = 0x3f2a7efa;
      (**(code **)(*g_DSound3DListener + 0x10))
                (g_DSound3DListener,&DAT_004ba430,0,0,0,&localState,0x10);
      return;
    case 5:
      localState = 0x14;
      localState4 = 0x3e54fdf4;
      localState3 = 0x3fd374bc;
      localState2 = 0x3fc00000;
      (**(code **)(*g_DSound3DListener + 0x10))
                (g_DSound3DListener,&DAT_004ba430,0,0,0,&localState,0x10);
      return;
    case 6:
      localState = 0x19;
      localState4 = 0x3ef8d4fe;
      localState3 = 0x40f20419;
      localState2 = 0x3f4e5604;
      (**(code **)(*g_DSound3DListener + 0x10))
                (g_DSound3DListener,&DAT_004ba430,0,0,0,&localState,0x10);
      return;
    default:
      localState = 0;
      localState4 = 0;
      localState3 = 0;
      localState2 = 0;
      (**(code **)(*g_DSound3DListener + 0x10))
                (g_DSound3DListener,&DAT_004ba430,0,0,0,&localState,0x10);
    }
  }
  return;
}

