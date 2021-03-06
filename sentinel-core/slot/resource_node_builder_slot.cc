#include <memory>
#include <string>

#include "sentinel-core/slot/resource_node_builder_slot.h"

namespace Sentinel {
namespace Slot {

const std::string& ResourceNodeBuilderSlot::Name() const { return name_; }

TokenResultSharedPtr ResourceNodeBuilderSlot::Entry(
    const EntrySharedPtr& entry, const ResourceWrapperSharedPtr& resource,
    Stat::NodeSharedPtr& node, int count, int flag) {
  auto cluster_node = node_storage_.GetOrCreateClusterNode(resource->name());

  entry->set_cur_node(cluster_node);
  node = cluster_node;
  return TokenResult::Ok();
}

void ResourceNodeBuilderSlot::Exit(const EntrySharedPtr& entry,
                                   const ResourceWrapperSharedPtr& resource,
                                   int count) {
  // Do nothing.
}

}  // namespace Slot
}  // namespace Sentinel