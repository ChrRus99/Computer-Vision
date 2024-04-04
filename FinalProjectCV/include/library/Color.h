#ifndef COLORS_HPP
#define COLORS_HPP

#include <opencv2/core/core.hpp>

namespace Color {
    const cv::Scalar BLACK(0, 0, 0);
    const cv::Scalar WHITE(255, 255, 255);
    const cv::Scalar RED(0, 0, 255);
    const cv::Scalar GREEN(0, 255, 0);
    const cv::Scalar BLUE(255, 0, 0);
    const cv::Scalar YELLOW(0, 255, 255);
    const cv::Scalar MAGENTA(255, 0, 255);
    const cv::Scalar CYAN(255, 255, 0);
}

#endif // !COLORS_HPP