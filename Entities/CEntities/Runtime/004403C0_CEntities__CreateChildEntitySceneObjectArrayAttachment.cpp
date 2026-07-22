#include "tarzan_ghidra_types.hpp"

// Address: 0x004403C0
// Label: CEntities::CreateChildEntitySceneObjectArrayAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::CreateChildEntitySceneObjectArrayAttachment(uint *entry4,uint sceneObject,short attachment)

{
  int entry;
  int entry2;
  undefined4 *dataCursor;
  undefined2 *dataCursor2;
  int entry3;
  
  if (attachment != 0) {
    entry = CEntities::FindEntityAttachmentByFlags(entry4,CONCAT11(1,(char)sceneObject));
    if ((entry != 0) && (*(int *)(entry + 0x38) == 0)) {
      entry2 = CEntities::AllocEntityAttachment
                        (entry4,(uint)(ushort)(attachment - 1) * 0x28 + 0x38,sceneObject | 0x1000,0);
      if (entry2 != 0) {
        entry3 = (ushort)(attachment - 1) + 1;
        *entry4 = *entry4 | 0x1000;
        *(short *)(entry2 + 0xc) = attachment;
        *(int *)(entry + 0x38) = entry2;
        dataCursor2 = (undefined2 *)(entry2 + 0x10);
        if (entry3 != 0) {
          dataCursor = (undefined4 *)(entry2 + 0x18);
          do {
            *dataCursor2 = g_ChildSceneObjectTemplateType;
            *(undefined2 *)((int)dataCursor + -6) = g_ChildSceneObjectTemplateFlags;
            dataCursor2 = dataCursor2 + 0x14;
            *dataCursor = g_ChildSceneObjectTemplateValue0;
            dataCursor[1] = g_ChildSceneObjectTemplateValue1;
            dataCursor[2] = g_ChildSceneObjectTemplateValue2;
            dataCursor[-1] = g_ChildSceneObjectTemplateSceneRef;
            entry3 = entry3 + -1;
            dataCursor[3] = g_ChildSceneObjectTemplatePosX;
            dataCursor[4] = g_ChildSceneObjectTemplatePosY;
            dataCursor[5] = g_ChildSceneObjectTemplatePosZ;
            dataCursor[6] = g_ChildSceneObjectTemplateExtra;
            dataCursor = dataCursor + 10;
          } while (entry3 != 0);
        }
      }
      return entry2;
    }
  }
  return 0;
}

