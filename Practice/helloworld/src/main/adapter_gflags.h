#pragma once

#include "gflags/gflags.h"

// vehicle params
DECLARE_string(vehicle_prob);

// local target generator params
DECLARE_double(change_lane_ds);

// change_solid 0: vehicle can't compaction line;  1:vehicle can compaction line
DECLARE_uint32(change_solid);



