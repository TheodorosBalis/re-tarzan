#include "tarzan_ghidra_types.hpp"

// Address: 0x004B9550
// Label: RtlUnwind
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x004b9550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}

