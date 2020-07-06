//
// Created by rgrandia on 10.06.20.
//

#include "convex_plane_decomposition_ros/ParameterLoading.h"

namespace convex_plane_decomposition {

template <typename T>
void loadParameter(const ros::NodeHandle& nodeHandle, const std::string& prefix, const std::string& param, T& value) {
  if (!nodeHandle.getParam(prefix + param, value)) {
    ROS_ERROR_STREAM("[ConvexPlaneExtractionROS] Could not read parameter `"
                     << param << "`. Setting parameter to default value : " << std::to_string(value));
  }
}

PreprocessingParameters loadPreprocessingParameters(const ros::NodeHandle& nodeHandle, const std::string& prefix) {
  PreprocessingParameters preprocessingParameters;
  loadParameter(nodeHandle, prefix, "kernelSize", preprocessingParameters.kernelSize);
  loadParameter(nodeHandle, prefix, "numberOfRepeats", preprocessingParameters.numberOfRepeats);
  loadParameter(nodeHandle, prefix, "increasing", preprocessingParameters.increasing);
  loadParameter(nodeHandle, prefix, "inpaintRadius", preprocessingParameters.inpaintRadius);
  return preprocessingParameters;
}

contour_extraction::ContourExtractionParameters loadContourExtractionParameters(const ros::NodeHandle& nodeHandle,
                                                                                const std::string& prefix) {
  contour_extraction::ContourExtractionParameters contourParams;
  loadParameter(nodeHandle, prefix, "offsetSize", contourParams.offsetSize);
  return contourParams;
}

ransac_plane_extractor::RansacPlaneExtractorParameters loadRansacPlaneExtractorParameters(const ros::NodeHandle& nodeHandle,
                                                                                          const std::string& prefix) {
  ransac_plane_extractor::RansacPlaneExtractorParameters ransacParams;
  loadParameter(nodeHandle, prefix, "probability", ransacParams.probability);
  loadParameter(nodeHandle, prefix, "min_points", ransacParams.min_points);
  loadParameter(nodeHandle, prefix, "epsilon", ransacParams.epsilon);
  loadParameter(nodeHandle, prefix, "cluster_epsilon", ransacParams.cluster_epsilon);
  loadParameter(nodeHandle, prefix, "normal_threshold", ransacParams.normal_threshold);
  return ransacParams;
}

sliding_window_plane_extractor::SlidingWindowPlaneExtractorParameters loadSlidingWindowPlaneExtractorParameters(
    const ros::NodeHandle& nodeHandle, const std::string& prefix) {
  sliding_window_plane_extractor::SlidingWindowPlaneExtractorParameters swParams;
  loadParameter(nodeHandle, prefix, "kernel_size", swParams.kernel_size);
  loadParameter(nodeHandle, prefix, "plane_inclination_threshold_degrees", swParams.plane_inclination_threshold_degrees);
  loadParameter(nodeHandle, prefix, "plane_patch_error_threshold", swParams.plane_patch_error_threshold);
  loadParameter(nodeHandle, prefix, "min_number_points_per_label", swParams.min_number_points_per_label);
  loadParameter(nodeHandle, prefix, "connectivity", swParams.connectivity);
  loadParameter(nodeHandle, prefix, "include_ransac_refinement", swParams.include_ransac_refinement);
  loadParameter(nodeHandle, prefix, "global_plane_fit_distance_error_threshold", swParams.global_plane_fit_distance_error_threshold);
  loadParameter(nodeHandle, prefix, "global_plane_fit_angle_error_threshold_degrees",
                swParams.global_plane_fit_angle_error_threshold_degrees);
  return swParams;
}

}  // namespace convex_plane_decomposition
