#include "tarzan_ghidra_types.hpp"

// Address: 0x00435F50
// Label: CPlayerHero::BeginScriptedMotionSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::BeginScriptedMotionSequence
               (uint arg1,uint arg2,uint arg3,uint arg4,uint arg5,undefined2 arg6)

{
  uint value;
  
  *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) = *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) | 0x88;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x108) = 0;
  g_PlayerCurrentCollisionMode = 0;
  g_PlayerSequenceDelayTicks = arg6;
  value = (arg1 & 0xffff) - 0x400 & 0xfff;
  *(int *)(g_PlayerMotionState + 0x10) =
       (int)((int)(short)(&g_SinCosTable12Bit)[value] * (arg2 & 0xffff)) >> 0xc;
  *(int *)(g_PlayerMotionState + 0x30) =
       (int)((int)(short)(&g_SinCosTable12Bit)[arg1 & 0xfff] * (arg2 & 0xffff)) >> 0xc;
  *(int *)(g_PlayerMotionState + 0x18) =
       (int)((int)(short)(&g_SinCosTable12Bit)[value] * (arg3 & 0xffff)) >> 0xc;
  *(int *)(g_PlayerMotionState + 0x38) =
       (int)((int)(short)(&g_SinCosTable12Bit)[arg1 & 0xfff] * (arg3 & 0xffff)) >> 0xc;
  *(uint *)(g_PlayerMotionState + 0x28) = arg5 & 0xffff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = *(undefined4 *)(g_PlayerMotionState + 0x28);
  *(uint *)(g_PlayerMotionState + 0x20) = arg4 & 0xffff;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x80;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  CPlayerHero::HideGroundShadow();
  return;
}

