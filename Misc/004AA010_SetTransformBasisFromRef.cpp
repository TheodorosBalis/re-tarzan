#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA010
// Label: SetTransformBasisFromRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetTransformBasisFromRef(undefined4 arg1)

{
  SetProjectionBasisMatrixFromFixed(arg1);
  SetProjectionTranslationFromTransform(arg1);
  return;
}

