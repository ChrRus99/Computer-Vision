#ifndef FOODS_DETECTION_H
#define FOODS_DETECTION_H

#include "DatasetCategories.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <map>

namespace FoodsDetection {
	class FoodsDetector
	{
		private:
			// Model parameters
			FoodCourse type_of_model;
			MealModality meal_modality;
			std::string root_path;
			std::vector<std::string> foods_class_labels;
			cv::dnn::Net net;

			// Food detected parameters
			cv::Mat foods_img;
			std::map<FoodCategory, std::tuple<cv::Rect, cv::Mat>> foods_detected_map;	// tuples (food_label, {bounding_box, food_ROI})
			bool do_plot_steps;
			std::string window_name;

			/* CLASSIFIER FUNCTIONS */
			void load_YOLO_model();
			
		public:
			/* CONSTRUCTORS */
			FoodsDetector() : FoodsDetector("") {}
			FoodsDetector(std::string root_path) : FoodsDetector(cv::Mat(), FoodCourse::FIRST_COURSE, MealModality::BEFORE_MEAL, root_path, false) {}
			FoodsDetector(const cv::Mat& foods_img, FoodCourse type_of_model, MealModality meal_modality, std::string root_path, bool do_plot_steps)
				: foods_img(foods_img), type_of_model(type_of_model), meal_modality(meal_modality), root_path(root_path), do_plot_steps(do_plot_steps), window_name("Foods Detector") {
				load_YOLO_model();
			}
			//~FoodsDetector()

			/* FOODs DETECTION FUNCTIONS */		// Note: these functions return an istance of this class in order to allow train-of-functions pattern
			FoodsDetector& detect_foods();

			/* GETTER FUNCIONS */
			inline std::map<FoodCategory, std::tuple<cv::Rect, cv::Mat>>& get_foods_map() { return foods_detected_map; }

			/* OTHER FUNCTIONS */
			inline FoodsDetector& enable_plot_steps(bool do_plot_steps) { this->do_plot_steps = do_plot_steps; return *this; }
			inline FoodsDetector& set_window_name(const std::string& window_name) { this->window_name = window_name; return *this; };
	};

	/* HELPER FUNCTIONS */
	void draw_label(cv::Mat& input_image, std::string label, int left, int top);
}

#endif  // !FOODS_DETECTION_H