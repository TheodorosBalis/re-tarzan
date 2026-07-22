#include "tarzan_ghidra_types.hpp"

// Address: 0x0043AC50
// Label: WelcomeToTheJungle::CreateCombatBaboonAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int WelcomeToTheJungle::CreateCombatBaboonAttachment(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  int value3;
  
  value2 = 0;
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::CreateEntityAttachment(arg1,0x18,0x10000000);
    if (value2 == 0) {
      CEntities::ReleaseEntityToFreeList((byte *)arg1);
    }
    else {
      *(undefined4 *)(value2 + 0xc) = 0;
      *(undefined4 *)(value2 + 0x10) = 0;
      *(undefined4 *)(value2 + 0x14) = 0;
      *(undefined2 *)(arg1 + 0x48) = 0;
      *(undefined2 *)(arg1 + 0x4a) = 0;
      if (((entity->descriptor != 0) &&
          (value3 = *(int *)(entity->descriptor + 0x10), value3 != 0)) &&
         (*(int *)(value3 + 0x10) != 0)) {
        *(undefined4 *)(value + 0xb4) = 1;
        value3 = *(int *)(value3 + 0x10) << 4;
        *(int *)(value + 0xb0) = value3;
        *(int *)(value + 0xac) = value3;
        *(int *)(value + 0xa8) = value3;
        return value2;
      }
    }
  }
  return value2;
}

