#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C690
// Label: LoadLanguageFontAssetSet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadLanguageFontAssetSet(void)

{
  ResetMenuModelSet(&g_LanguageFontAssetSet);
  LoadNecessaryGSXFontsAndModels(&g_LanguageFontAssetSet);
  return;
}

