#pragma once
#include <bitset>
#include "core/object/cvtdl_object_types.h"
#include "core_internel.hpp"

namespace cvitdl {

class YoloX final : public Core {
 public:
  YoloX();
  virtual ~YoloX();
  YoloPreParam get_preparam();
  void set_preparam(YoloPreParam pre_param);
  YoloAlgParam get_algparam();
  void set_algparam(YoloAlgParam alg_param);
  int inference(VIDEO_FRAME_INFO_S *srcFrame, cvtdl_object_t *obj_meta);
  virtual bool allowExportChannelAttribute() const override { return true; }

 private:
  virtual int onModelOpened() override;
  virtual int setupInputPreprocess(std::vector<InputPreprecessSetup> *data) override;
  void outputParser(const int image_width, const int image_height, const int frame_width,
                    const int frame_height, cvtdl_object_t *obj_meta);
  void generate_yolox_proposals(Detections &detections);

  YoloPreParam p_preprocess_cfg_;
  YoloAlgParam p_alg_param_;

  std::vector<int> strides_;
  std::map<int, std::string> class_out_names_;
  std::map<int, std::string> object_out_names_;
  std::map<int, std::string> box_out_names_;
};
}  // namespace cvitdl