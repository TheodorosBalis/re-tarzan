#include "tarzan_ghidra_types.hpp"

// Address: 0x00494A40
// Label: LoadAndVerifyTarzanCFG
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadAndVerifyTarzanCFG(void)

{
  int value;
  int value2;
  
  value = BuildTarzanCFGPath();
  if ((value != 0) && (value = fopen(value,&s_FileModeReadBinary), value != 0)) {
    value2 = fread(&tarzanCFGbuffer,0xbc,1,value);
    if (value2 != 1) {
      fclose(value);
      ResetTarzanCFGToDefaults();
      g_TarzanCfgLoaded = 1;
      return;
    }
    fclose(value);
    DecodeCfgBuffer();
    value = CalcCfgChecksum();
    if (tarzanCFGbuffer == value) {
      g_TarzanCfgLoaded = 1;
      return;
    }
    if (tarzanCFGbuffer == -1) {
      g_TarzanCfgLoaded = 1;
      return;
    }
  }
  ResetTarzanCFGToDefaults();
  g_TarzanCfgLoaded = 1;
  return;
}

