#include "tarzan_ghidra_types.hpp"

// Address: 0x00494810
// Label: SaveTarzanCFGFile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaveTarzanCFGFile(void)

{
  LPCSTR lpFileName;
  int value;
  
  if (g_TarzanCfgLoaded != 0) {
    lpFileName = (LPCSTR)BuildTarzanCFGPath();
    if (lpFileName != (LPCSTR)0x0) {
      SetFileAttributesA(lpFileName,0x80);
      value = fopen(lpFileName,&s_FileModeWriteBinary);
      if (value != 0) {
        tarzanCFGbuffer = CalcCfgChecksum();
        DecodeCfgBuffer();
        fwrite(&tarzanCFGbuffer,0xbc,1,value);
        DecodeCfgBuffer();
        fflush(value);
        fclose(value);
      }
    }
  }
  return;
}

