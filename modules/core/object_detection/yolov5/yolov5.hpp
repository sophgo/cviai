#pragma once
#include <bitset>
#include "core/core/cvtdl_core_types.h"
#include "core/object/cvtdl_object_types.h"
#include "core_internel.hpp"

namespace cvitdl {

class Yolov5 final : public Core {
 public:
  Yolov5();
  virtual ~Yolov5();
  int inference(VIDEO_FRAME_INFO_S *srcFrame, cvtdl_object_t *obj_meta);
  YoloPreParam get_preparam();
  void set_preparam(YoloPreParam pre_param);
  YoloAlgParam get_algparam();
  void set_algparam(YoloAlgParam alg_param);
  uint32_t set_roi(Point_t &roi);

 private:
  virtual int onModelOpened() override;
  // int vpssPreprocess(VIDEO_FRAME_INFO_S *srcFrame, VIDEO_FRAME_INFO_S *dstFrame,
  //                    VPSSConfig &vpss_config) override;
  virtual int setupInputPreprocess(std::vector<InputPreprecessSetup> *data) override;
  // cvtdl_bbox_t yolov5_box_rescale(int frame_width, int frame_height, int width, int height,
  //                                cvtdl_bbox_t bbox);
  // void getYolov5Detections(int8_t *ptr_int8, float *ptr_float, int num_per_pixel,
  //                                float qscale, int stride_x, int stride_y, int grid_x_len,
  //                                int grid_y_len, uint32_t *anchor, int nn_height, int nn_width,
  //                                Detections &vec_obj);
  void generate_yolov5_proposals(Detections &vec_obj);
  void outputParser(const int image_width, const int image_height, const int frame_width,
                    const int frame_height, cvtdl_object_t *obj_meta);
  void Yolov5PostProcess(Detections &dets, int frame_width, int frame_height,
                         cvtdl_object_t *obj_meta);

  std::map<int, std::string> class_out_names_;
  std::map<int, std::string> conf_out_names_;
  std::map<int, std::string> box_out_names_;
  std::vector<int> strides_;
  YoloPreParam p_preprocess_cfg_;
  YoloAlgParam p_yolov5_param_;
  cvtdl_bbox_t yolo_box;
  bool roi_flag = false;
};
}  // namespace cvitdl
