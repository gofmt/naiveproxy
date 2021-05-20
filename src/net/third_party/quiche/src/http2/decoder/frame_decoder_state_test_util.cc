// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "http2/decoder/frame_decoder_state_test_util.h"

#include "http2/decoder/http2_structure_decoder_test_util.h"
#include "http2/http2_structures.h"
#include "http2/http2_structures_test_util.h"
#include "http2/platform/api/http2_logging.h"
#include "http2/test_tools/http2_random.h"
#include "http2/tools/random_decoder_test.h"

namespace http2 {
namespace test {

// static
void FrameDecoderStatePeer::Randomize(FrameDecoderState* p, Http2Random* rng) {
  HTTP2_VLOG(1) << "FrameDecoderStatePeer::Randomize";
  ::http2::test::Randomize(&p->frame_header_, rng);
  p->remaining_payload_ = rng->Rand32();
  p->remaining_padding_ = rng->Rand32();
  Http2StructureDecoderPeer::Randomize(&p->structure_decoder_, rng);
}

// static
void FrameDecoderStatePeer::set_frame_header(const Http2FrameHeader& header,
                                             FrameDecoderState* p) {
  HTTP2_VLOG(1) << "FrameDecoderStatePeer::set_frame_header " << header;
  p->frame_header_ = header;
}

}  // namespace test
}  // namespace http2
