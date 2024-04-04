#ifndef PERFORMANCE_EVALUATION_H
#define PERFORMANCE_EVALUATION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <map>

namespace PerformanceEvaluation {
	float IoU_evaluation(cv::Mat pred_mask, cv::Mat ground_truth_mask);
	float AP_evaluation();
}


#endif  // !PERFORMANCE_EVALUATION_H