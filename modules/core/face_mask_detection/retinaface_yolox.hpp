#pragma once
#include "core/face/cvtdl_face_types.h"
#include "core_internel.hpp"

#include "opencv2/opencv.hpp"

namespace cvitdl {

class RetinafaceYolox final : public Core {
 public:
  RetinafaceYolox();
  virtual ~RetinafaceYolox();
  int inference(VIDEO_FRAME_INFO_S *srcFrame, cvtdl_face_t *face_meta);
  virtual bool allowExportChannelAttribute() const override { return true; }

 private:
  virtual int setupInputPreprocess(std::vector<InputPreprecessSetup> *data) override;
  void outputParser(const int image_width, const int image_height, const int frame_width,
                    const int frame_height, cvtdl_face_t *face_meta);
};
}  // namespace cvitdl