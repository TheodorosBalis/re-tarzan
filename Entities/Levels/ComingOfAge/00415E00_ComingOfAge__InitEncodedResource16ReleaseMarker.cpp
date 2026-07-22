#include "tarzan_ghidra_types.hpp"

// Address: 0x00415E00
// Label: ComingOfAge::InitEncodedResource16ReleaseMarker
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitEncodedResource16ReleaseMarker(undefined4 entry)

{
  ReleaseEncodedResourceId(0x16);
  CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  return;
}

