#include "tarzan_ghidra_types.hpp"

// Address: 0x00440AD0
// Label: CEntities::ResetEntityTemplates
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::ResetEntityTemplates(void)

{
  _g_EntityDefaultTemplate_Field2C = CEntities::NoOpEntityCallback;
  _g_EntityDefaultTemplate_Field30 = CEntities::NoOpEntityCallback;
  _g_EntityDefaultTemplate_Field4C = g_EntityDefaultTemplate_Field50;
  g_EntityDefaultTemplate = 0;
  g_EntityDefaultTemplate_Field04 = 0;
  _g_EntityDefaultTemplate_Field08 = 0;
  _g_EntityDefaultTemplate_Field28 = 2;
  _g_EntityDefaultTemplate_Field0C = 0;
  _g_EntityDefaultTemplate_Field10 = 0;
  _g_EntityDefaultTemplate_Field14 = 0;
  _g_EntityDefaultTemplate_Field18 = 0;
  _g_EntityDefaultTemplate_Field1C = 0;
  _g_EntityDefaultTemplate_Field20 = 0;
  _g_EntityDefaultTemplate_Field24 = 0;
  _g_EntityDefaultTemplate_Field34 = 0;
  _g_EntityDefaultTemplate_Field38 = 0;
  g_EntityDefaultTemplate_Field3C = 0x80;
  g_EntityDefaultTemplate_Field3D = 0;
  _g_EntityDefaultTemplate_Field3E = 0xff;
  _g_EntityDefaultTemplate_Field42 = 0;
  _g_EntityDefaultTemplate_Field44 = 0;
  _g_EntityDefaultTemplate_Field46 = 0;
  _g_EntityDefaultTemplate_Field48 = 0;
  _g_EntityDefaultTemplate_Field4A = 0;
  g_HudEntitySceneObjectTemplate = 0;
  _g_HudEntitySceneObjectTemplate_Field08 = 0;
  g_HudEntitySceneObjectTemplate_Field04 = 0;
  g_ChildSceneObjectTemplateValue2 = 0;
  g_ChildSceneObjectTemplateValue1 = 0;
  g_ChildSceneObjectTemplateValue0 = 0;
  _g_HudEntitySceneObjectTemplate_Field50 = 0;
  _g_HudEntitySceneObjectTemplate_Field4C = 0;
  _g_HudEntitySceneObjectTemplate_Field48 = 0;
  _g_HudEntitySceneObjectTemplate_Field44 = 0;
  _g_HudEntitySceneObjectTemplate_Field40 = 0;
  _g_HudEntitySceneObjectTemplate_Field3C = 0;
  _g_HudEntitySceneObjectTemplate_Field5C = 0;
  _g_HudEntitySceneObjectTemplate_Field58 = 0;
  _g_HudEntitySceneObjectTemplate_Field54 = 0;
  _g_HudEntitySceneObjectTemplate_Field34 = 0;
  _g_HudEntitySceneObjectTemplate_Field38 = 0;
  _g_HudEntitySceneObjectTemplate_Field60 = 0;
  _g_HudEntitySceneObjectTemplate_Field64 = 0;
  g_ChildSceneObjectTemplatePosZ = 0x1000;
  g_ChildSceneObjectTemplatePosY = 0x1000;
  g_ChildSceneObjectTemplatePosX = 0x1000;
  g_ChildSceneObjectTemplateSceneRef = 0;
  g_HudEntitySceneObjectTemplate_Field75 = 0;
  g_ChildSceneObjectTemplateType = 0;
  _g_HudEntitySceneObjectTemplate_Field6C = 0;
  _g_HudEntitySceneObjectTemplate_Field70 = 0;
  _g_HudEntitySceneObjectTemplate_Field76 = 0;
  _g_HudEntitySceneObjectTemplate_Field78 = 0;
  _g_HudEntitySceneObjectTemplate_Field7A = 0;
  _g_HudEntitySceneObjectTemplate_Field7C = 0xffff;
  _g_HudEntitySceneObjectTemplate_Field7E = 0;
  g_ChildSceneObjectTemplateFlags = 0x8000;
  _g_HudEntitySceneObjectTemplate_Field84 = 0;
  _g_HudEntitySceneObjectTemplate_Field82 = 0;
  _g_HudEntitySceneObjectTemplate_Field80 = 0;
  _g_HudEntitySceneObjectTemplate_Field9C = 0;
  _g_HudEntitySceneObjectTemplate_Field98 = 0;
  _g_HudEntitySceneObjectTemplate_Field94 = 0;
  _g_HudEntitySceneObjectTemplate_Field90 = 0;
  _g_HudEntitySceneObjectTemplate_Field8C = 0;
  _g_HudEntitySceneObjectTemplate_Field88 = 0;
  InitLoadGamePreviewTransform(&g_HudEntitySceneObjectTemplate);
  _g_HudSceneObjectTemplate_Field08 = 0;
  _g_HudSceneObjectTemplate_Field04 = 0;
  _g_HudSceneObjectTemplate_Field00 = 0;
  _g_HudSceneObjectTemplate_Field0C = 0;
  _g_HudSceneObjectTemplate_Field10 = 0;
  _g_HudSceneObjectTemplate_Field1C = 0xffff;
  _g_EntityScriptAttachmentTemplate_Field14 = 0xffff;
  _g_EntityScriptAttachmentTemplate_Field16 = 0xffff;
  _g_EntityScriptAttachmentTemplate_Field18 = 0xffff;
  _g_HudSceneObjectTemplate_Field14 = 0;
  _g_HudSceneObjectTemplate_Field1E = 0;
  _g_HudSceneObjectTemplate_Field24 = 0;
  _g_HudSceneObjectTemplate_Field26 = 0;
  _g_HudSceneObjectTemplate_Field28 = 0;
  g_EntityScriptAttachmentTemplate = 0;
  _g_EntityScriptAttachmentTemplate_Field08 = 0;
  g_EntityScriptAttachmentTemplate_Field04 = 0;
  _g_EntityScriptAttachmentTemplate_Field0C = 0;
  _g_EntityScriptAttachmentTemplate_Field10 = 0;
  _g_EntityScriptAttachmentTemplate_Field1A = 0;
  g_RuntimeMotionStateAttachmentTemplate = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field08 = 0;
  g_RuntimeMotionStateAttachmentTemplate_Field04 = 0;
  g_RuntimeMotionStateAttachmentTemplate_Field0F = 0;
  g_RuntimeMotionStateAttachmentTemplate_Field0E = 0;
  g_RuntimeMotionStateAttachmentTemplate_Field0D = 0;
  g_RuntimeMotionStateAttachmentTemplate_Field0C = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field1C = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field18 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field14 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field10 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field2C = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field28 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field24 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field20 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field3C = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field38 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field34 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field30 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field48 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field44 = 0;
  _g_RuntimeMotionStateAttachmentTemplate_Field40 = 0;
  _g_HudSceneObjectTemplate_Field2A = 0x8000;
  return;
}

