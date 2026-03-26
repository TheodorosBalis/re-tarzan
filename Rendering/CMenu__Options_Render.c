// Address: 0x004460B0

void CMenu__Options_Render(undefined4 param_1)

{
  RenderMenuFontBlockAndChildText(param_1);
  CMenu__Options_UpdateIdleBehavior(param_1);
  FUN_00446110();
  RenderMenuSceneHierarchy(&g_PorterMenuScene);
  return;
}


