#ifndef ROIS_DETECTOR_H
#define ROIS_DETECTOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace ROIsDetection {
	class ROIsDetector
	{
		private:
			/* MEMBER VARIABLES */
			cv::Mat src_img;
			cv::Mat tray_mask, dishes_mask;
			cv::Mat tray_ROI, dishes_ROI;

			std::vector<cv::Point> tray_polygon;
			std::vector<cv::Vec3f> dishes_circles;

			bool do_plot_steps;
			std::string window_name;

		public:
			/* CONSTRUCTORS */
			ROIsDetector() : ROIsDetector(cv::Mat(), true) {}
			ROIsDetector(const cv::Mat& src_img) : ROIsDetector(src_img, true) {}
			ROIsDetector(const cv::Mat& src_img, bool do_plot_steps) 
				: src_img(src_img), do_plot_steps(do_plot_steps), window_name("ROIs Detector") {}
			//~ROIsDetector();

			/* ROIs DETECTION FUNCTIONS */	// Note: these functions return an istance of this class in order to allow train-of-functions pattern
			ROIsDetector& detect_tray();
			ROIsDetector& detect_dishes();

			/* GETTER FUNCIONS */
			cv::Mat get_first_dish_ROI();
			cv::Mat get_second_dish_ROI();
			cv::Mat get_sidedish_and_sidefood_ROI();

			/* OTHER FUNCTIONS */
			inline ROIsDetector& enable_plot_steps(bool do_plot_steps) { this->do_plot_steps = do_plot_steps; return *this; }
			inline ROIsDetector& set_window_name(const std::string& window_name) { this->window_name = window_name; return *this; };
	};

	/* HELPER FUNCTIONS */
}

#endif  // !ROIS_DETECTOR_H