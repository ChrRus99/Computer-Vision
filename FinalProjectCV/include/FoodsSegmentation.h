#ifndef FOODS_SEGMENTATION_H
#define FOODS_SEGMENTATION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace FoodsSegmentation {
	class FoodsSegmenter
	{
	private:
		/* MEMBER VARIABLES */
		cv::Mat food_ROI_img;
		cv::Rect food_bounding_box;
		cv::Mat food_mask;

		// Vectors to store the accumulated color ranges
		std::vector<cv::Scalar> min_food_color_values;
		std::vector<cv::Scalar> max_food_color_values;

		// For ensamble
		std::vector<cv::Mat> weak_masks;

		bool do_plot_steps;
		std::string window_name;

		/* SEGMENTATION TECHNIQUES FUNCTIONS */
		// Novel method 1
		void extraction_of_color_ranges(const cv::Mat& hsv_img, cv::Mat& algorithm_img, const cv::Point& starting_point, int num_circles, int circles_radius, int major_axis, int minor_axis);
		void thresholding_with_color_ranges(const cv::Mat& hsv_img, cv::Mat& filtered_img);
		void mask_enhancement_general_before(const cv::Mat& src_food_mask, cv::Mat& food_mask);		// for before meal: to enhance segmentation of foods
		void mask_enhancement_general_after(const cv::Mat& src_food_mask, cv::Mat& food_mask);		// for after meal: to remove dirty of leftovers

		void first_novel_method_segmentation(const cv::Point& starting_point, int num_circles, int circles_radius, int major_axis, int minor_axis, int kernel_size);
		void first_novel_method_segmentation_in_color_ranges(int kernel_size);

		// Novel method 2
		void fill_contours_with_color_ranges(const cv::Mat& hsv_img, cv::Mat& filtered_img, int min_votes);
		void mask_enhancement_morph_close_before(const cv::Mat& src_food_mask, cv::Mat& better_food_mask, int kernel_size);
		void mask_enhancement_morph_open_after(const cv::Mat& src_food_mask, cv::Mat& better_food_mask, int kernel_size);

		void second_novel_method_segmentation(const cv::Point& starting_point, int num_circles, int circles_radius, int major_axis, int minor_axis, int kernel_size, int min_votes);
		void second_novel_method_segmentation_in_color_ranges(int kernel_size, int min_votes);

		// Grabcut method 3
		void grabcut_segmentation(cv::Rect bounding_box);

		// Ensemble 
		void ensemble_segmentation();

	public:
		/* CONSTRUCTORS */
		inline FoodsSegmenter() : FoodsSegmenter(cv::Mat(), cv::Rect(), false) {}
		FoodsSegmenter(const cv::Mat& food_ROI_img, const cv::Rect& food_bounding_box, bool do_plot_steps)	// receive the ROI image of only 1 food detected by classifier!
			: food_ROI_img(food_ROI_img), food_bounding_box(food_bounding_box), do_plot_steps(do_plot_steps), window_name("Foods Segmenter") {}
		//~FoodsSegmenter();

		/* FOOD SEGMENTATION FUNCTIONS */	// Note: these functions return an istance of this class in order to allow train-of-functions pattern
		FoodsSegmenter& segment_food();
		FoodsSegmenter& segment_food_in_color_ranges(const std::pair<std::vector<cv::Scalar>, std::vector<cv::Scalar>>& food_color_ranges);

		/* GETTER FUNCIONS */
		inline cv::Mat& get_food_mask() { return food_mask; }
		inline std::pair<std::vector<cv::Scalar>, std::vector<cv::Scalar>> get_food_color_ranges() {
			return std::pair<std::vector<cv::Scalar>, std::vector<cv::Scalar>>(min_food_color_values, max_food_color_values); 
		}

		/* OTHER FUNCTIONS */
		inline FoodsSegmenter& enableImshow(bool do_plot_steps) { this->do_plot_steps = do_plot_steps; return *this; }
		inline FoodsSegmenter& setWindowName(const std::string& window_name) { this->window_name = window_name; return *this; };
	};

	/* HELPER FUNCTIONS */
	
}

#endif  // !FOODS_SEGMENTATION_H