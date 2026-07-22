#include "tarzan_ghidra_types.hpp"

// Address: 0x00452F18
// Label: ExitOptions
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __fastcall ExitOptions(uint arg1)

{
  code *stringCursor;
  undefined **dataCursor;
  int value;
  int savedEsi;
  
  if (*(int *)(savedEsi + 0x14) != 0) {
    PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
    (**(code **)(savedEsi + 0x14))(*(undefined4 *)(savedEsi + 0x18));
    arg1 = g_InputCurrentMask;
  }
  if ((arg1 & g_InputEdgeMask & 0x4008) != 0) {
    stringCursor = *(code **)(*(int *)(savedEsi + 8) + 0x10 + *(int *)(savedEsi + 0x24) * 0x18);
    if (stringCursor != (code *)0x0) {
      dataCursor = *(undefined ***)(*(int *)(savedEsi + 8) + *(int *)(savedEsi + 0x24) * 0x18 + 0x14)
      ;
      if ((((dataCursor != &PTR_Options_Difficulty_004eff98) &&
           (dataCursor != &PTR_Options_Controller_004efff8)) &&
          (dataCursor != &PTR_Options_Sound_004f00d8)) &&
         ((dataCursor != &PTR_Options_SFXunused_004f0130 &&
          (dataCursor != &PTR_Options_OptionsSelections_004f0188)))) {
        PlayAudioById(0xac,(int *)0,(undefined4 *)0);
      }
      value = *(int *)(*(int *)(savedEsi + 8) + 0xc + *(int *)(savedEsi + 0x24) * 0x18);
      if (value != -1) {
        PlayAudioById(value,(int *)0,(undefined4 *)0);
      }
      (*stringCursor)(*(undefined4 *)(*(int *)(savedEsi + 8) + 0x14 + *(int *)(savedEsi + 0x24) * 0x18))
      ;
    }
  }
  return;
}

