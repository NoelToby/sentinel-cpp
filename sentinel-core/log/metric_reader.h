#pragma once

#include <string>
#include <vector>

#include "sentinel-core/log/metric/metric_node.h"

namespace Sentinel {
namespace Log {

class MetricReader {
 public:
  std::vector<Metric::MetricNode> ReadMetrics(
      std::vector<std::string> file_names, int pos, int64_t offset,
      int recommend_lines_);
  void ReadMetricsInOneFile(std::vector<Metric::MetricNode> &metric_vec,
                            std::string file_name, int64_t offset,
                            int recommend_lines);

  std::vector<Metric::MetricNode> ReadMetricsByEndTime(
      std::vector<std::string> file_names, int pos, int64_t offset,
      int64_t begin_time_ms, int64_t end_time_ms, std::string identity);
  bool ReadMetricsInOneFileByEndTime(
      std::vector<Metric::MetricNode> &metric_vec, std::string file_name,
      int64_t offset, int64_t begin_time_ms, int64_t end_time_ms,
      std::string identity);

 private:
  static const int kMaxLinesReturn = 100000;
};

}  // namespace Log
}  // namespace Sentinel
