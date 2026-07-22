#include "tarzan_ghidra_types.hpp"

// Address: 0x00495D50
// Label: SetGlideGammaEnvironmentVariables
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetGlideGammaEnvironmentVariables(void)

{
  SetEnvironmentVariableA(s_FX_GLIDE_NO_SPLASH_005157d8,&DAT_005157ec);
  SetEnvironmentVariableA(s_SST_GAMMA_005157c8,&DAT_005157d4);
  SetEnvironmentVariableA(s_SST_RGAMMA_005157bc,&DAT_005157d4);
  SetEnvironmentVariableA(s_SST_GGAMMA_005157b0,&DAT_005157d4);
  SetEnvironmentVariableA(s_SST_BGAMMA_005157a4,&DAT_005157d4);
  SetEnvironmentVariableA(s_SSTV2_GAMMA_00515798,&DAT_005157d4);
  SetEnvironmentVariableA(s_SSTV2_RGAMMA_00515788,&DAT_005157d4);
  SetEnvironmentVariableA(s_SSTV2_GGAMMA_00515778,&DAT_005157d4);
  SetEnvironmentVariableA(s_SSTV2_BGAMMA_00515768,&DAT_005157d4);
  return;
}

