#include "tarzan_ghidra_types.hpp"

// Address: 0x00440550
// Label: CEntities::CreateRuntimeMotionStateAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::CreateRuntimeMotionStateAttachment(uint *entry)

{
  undefined4 *stateFlags;
  int value;
  undefined4 *stateFlags2;
  
  stateFlags = (undefined4 *)
           CEntities::AllocEntityAttachment
                     (entry,0x4c,0x800,&g_RuntimeMotionStateAttachmentTemplate);
  if (stateFlags != (undefined4 *)0x0) {
    *entry = *entry | 0x800;
    stateFlags2 = &g_RuntimeMotionStateAttachmentTemplate;
    for (value = 0x13; value != 0; value = value + -1) {
      *stateFlags = *stateFlags2;
      stateFlags2 = stateFlags2 + 1;
      stateFlags = stateFlags + 1;
    }
  }
  return 0;
}

