#ifndef FOOD_RECOGNIZER_AND_LEFTOVER_ESTIMATOR_H
#define FOOD_RECOGNIZER_AND_LEFTOVER_ESTIMATOR_H

#include "ROIsDetection.h"
#include "FoodsDetection.h"
#include "FoodsSegmentation.h"
#include "PerformanceEvaluation.h"
#include "DatasetCategories.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <map>

struct Food {
	// Predicted food
	cv::Mat pred_food_ROI_img;
	cv::Rect pred_food_boundingbox_rect;
	cv::Mat pred_food_boundingbox_img;
	cv::Mat pred_food_mask_img;
	std::pair<std::vector<cv::Scalar>, std::vector<cv::Scalar>> food_color_ranges;	// stored only for pred_image before
	float pred_food_leftover_ratio;													// stored for each pred_food_mask after w.r.t. pred_food_mask before

	// Ground truth food
	cv::Rect gt_food_boundingbox_rect;
	cv::Mat gt_food_boundingbox_img;
	cv::Mat gt_food_mask_img;
	float gt_food_leftover_ratio;													// stored for each gt_food_mask after w.r.t. gt_food_mask before
};

struct Images {
	// Source images
	cv::Mat src_img;

	// Predicted images
	cv::Mat pred_boundingbox_img;
	cv::Mat pred_mask_img;
	float pred_total_leftover_ratio;												// stored for each pred_mask after w.r.t. pred_mask before

	// Ground truth images
	cv::Mat gt_boundingbox_img;
	cv::Mat gt_mask_img;
	float gt_total_leftover_ratio;													// stored for each gt_mask after w.r.t. gt_mask before
};

class FoodRecognizer_and_LeftoverEstimator
{
	private:
		/* MEMBER VARIABLES */
		std::string root_path;
		Tray tray;

		std::map<MealModality, std::map<FoodCategory, Food>> foods_table;			// Table of foods: map(meal_modality, map(label, food_struct))
		std::map<MealModality, Images> images_table;								// Table of images: map(meal_modality, images_struct)

		ROIsDetection::ROIsDetector rois_detector;
		FoodsDetection::FoodsDetector foods_detector = FoodsDetection::FoodsDetector(root_path);	// Initialize root path to load the model
		FoodsSegmentation::FoodsSegmenter foods_segmenter;
		
		/* BEFORE MEAL FUNCTIONS */
		void detect_foods(MealModality modality, bool do_plot_steps);
		void segment_foods(MealModality modality, bool do_plot_steps);

		/* AFTER MEAL FUNCTIONS */
		void compute_and_store_leftover_estimations();

		/* STRUCTS HANDLERS FUNCTIONS */
		void load_and_store_img_from_dataset(ImageType image_type, MealModality meal_modality, std::string root_path);
		void store_detected_food(const std::pair<FoodCategory, std::tuple<cv::Rect, cv::Mat>>& food_detected, MealModality meal_modality, Kind food_kind);
		void store_segmented_food(const std::pair<FoodCategory, cv::Mat>& food_segmented, MealModality meal_modality, Kind food_kind);
		void build_and_store_pred_boundingboxes_mask(MealModality meal_modality);
		void build_and_store_pred_mask(MealModality meal_modality);
	public:
		/* CONSTRUCTORS */
		FoodRecognizer_and_LeftoverEstimator(std::string root_path, Tray tray);
		//~FoodRecognizer();

		/* FOOD RECOGNITION AND LEFTOVER ESTIMATION FUNCTIONS */	// Note: these functions return an istance of this class in order to allow train-of-functions pattern
		FoodRecognizer_and_LeftoverEstimator& process_before_meal();
		FoodRecognizer_and_LeftoverEstimator& process_after_meal();
		FoodRecognizer_and_LeftoverEstimator& estimate_leftovers();
		FoodRecognizer_and_LeftoverEstimator& evaluate_performances();

		/* PRINT/PLOT OUTPUT RESULTS */
		void plot_images_table_masks();
		void plot_images_table_overlapped_ROIs();
		void plot_images_table_filtered_ROIs();
		void plot_foods_table();
		void print_leftovers_table();
};

#endif // !FOOD_RECOGNIZER_AND_LEFTOVER_ESTIMATOR_H