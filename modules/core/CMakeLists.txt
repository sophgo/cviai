if(DEFINED NO_OPENCV)
  message("core no opencv")
  add_subdirectory(core)
  add_subdirectory(custom)
  add_subdirectory(utils)
  add_subdirectory(ive)
  add_subdirectory(retina_face)
  add_subdirectory(object_detection/mobiledetv2)
  add_subdirectory(motion_detection)
  add_subdirectory(object_detection/yolov8)
  add_subdirectory(object_detection/yolov3)
  add_subdirectory(object_detection/yolov5)
  add_subdirectory(object_detection/yolov6)
  add_subdirectory(object_detection/yolo)
  add_subdirectory(object_detection/yolox)
  add_subdirectory(object_detection/ppyoloe)
  add_subdirectory(sound_classification)
  add_subdirectory(deepsort)
  add_subdirectory(face_attribute)
  if ("${ENABLE_CVI_TDL_CV_UTILS}" STREQUAL "ON")
    add_compile_definitions(ENABLE_CVI_TDL_CV_UTILS)
  endif()
  set(CORE_INTERFACE cvi_tdl_core_noopencv.cpp)
else()
    add_subdirectory(core)
    add_subdirectory(custom)
    add_subdirectory(utils)
    add_subdirectory(face_attribute)
    add_subdirectory(face_quality)
    add_subdirectory(liveness)
    add_subdirectory(mask_classification)
    add_subdirectory(hand_classification)
    add_subdirectory(hand_keypoint)
    add_subdirectory(hand_keypoint_classification)
    add_subdirectory(osnet)
    add_subdirectory(retina_face)
    add_subdirectory(object_detection/yolov8)
    add_subdirectory(object_detection/yolov3)
    add_subdirectory(object_detection/yolov5)
    add_subdirectory(object_detection/yolov6)
    add_subdirectory(object_detection/yolo)
    add_subdirectory(object_detection/yolox)
    add_subdirectory(object_detection/ppyoloe)
    add_subdirectory(thermal_face_detection)
    add_subdirectory(thermal_person_detection)
    add_subdirectory(object_detection/mobiledetv2)
    add_subdirectory(mask_face_recognition)
    add_subdirectory(deepsort)
    add_subdirectory(sound_classification)
    add_subdirectory(segmentation)
    add_subdirectory(license_plate_recognition)
    add_subdirectory(license_plate_detection)
    add_subdirectory(alphapose)
    add_subdirectory(fall_detection)
    add_subdirectory(eye_classification)
    add_subdirectory(yawn_classification)
    add_subdirectory(face_landmarker)
    add_subdirectory(incar_object_detection)
    add_subdirectory(smoke_classification)
    add_subdirectory(ive)
    add_subdirectory(tamper_detection)
    add_subdirectory(motion_detection)
    add_subdirectory(face_mask_detection)
    add_subdirectory(human_keypoints_detection/yolov8_pose)
    add_subdirectory(human_keypoints_detection/simcc)
    add_subdirectory(human_keypoints_detection/hrnet)
    add_subdirectory(image_classification)
    add_subdirectory(raw_image_classification)
    add_subdirectory(license_plate_recognitionv2)
    add_subdirectory(clip)
    set(CORE_INTERFACE cvi_tdl_core.cpp)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core
                    ${CMAKE_CURRENT_SOURCE_DIR}/utils
                    ${CMAKE_CURRENT_SOURCE_DIR}/ive)
set(CORE_SRCS cvi_tdl_types_mem.cpp
              cvi_tdl_rescale_bbox.cpp
              cvi_tdl_utils.cpp
              cvi_tdl_custom.cpp
              ${CORE_INTERFACE})

project(cvi_tdl_core)
add_library(${PROJECT_NAME} OBJECT ${CORE_SRCS})
