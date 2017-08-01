/******************************************************************************
  * Copyright 2017 The Apollo Authors. All Rights Reserved.
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  * http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *****************************************************************************/

#ifndef BAIDU_ADU_ROUTING_TOPO_CREATOR_NODE_CREATOR_H
#define BAIDU_ADU_ROUTING_TOPO_CREATOR_NODE_CREATOR_H

#include "map_lane.pb.h"
#include "topo_graph.pb.h"

namespace adu {
namespace routing {

class NodeCreator {
 public:
  static void get_pb_node(const ::adu::common::hdmap::Lane& lane,
                          const std::string& road_id,
                          ::adu::routing::common::Node* pb_node);

 private:
  static void add_out_boundary(
      const ::adu::common::hdmap::LaneBoundary& bound, double lane_length,
      ::google::protobuf::RepeatedPtrField<
          ::adu::routing::common::CurveRange>* const out_range);

  static void init_node_info(const ::adu::common::hdmap::Lane& lane,
                             const std::string& road_id,
                             ::adu::routing::common::Node* const node);
  static void init_node_cost(const ::adu::common::hdmap::Lane& lane,
                             ::adu::routing::common::Node* const node);
};

}  // namespace routing
}  // namespace adu

#endif  // BAIDU_ADU_ROUTING_TOPO_CREATOR_NODE_CREATOR_H
