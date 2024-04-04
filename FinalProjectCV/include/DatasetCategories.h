#ifndef DATASET_CATEGORIES_H
#define DATASET_CATEGORIES_H

#include <string>
#include <vector>
#include <opencv2/core/core.hpp>


/* TRAY ENUM */
enum class Tray {
	TRAY_1,
	TRAY_2,
	TRAY_3,
	TRAY_4,
	TRAY_5,
	TRAY_6,
	TRAY_7,
	TRAY_8
};

const char* toString(Tray tray);
int index(Tray tray);
Tray toTray(int tray_index);
Tray toTray(const std::string tray_string);


/* IMAGE TYPE ENUM */
enum class ImageType {
	SOURCE,
	BOUNDING_BOX,
	MASK
};

const char* toString(ImageType image_type);
int index(ImageType image_type);
ImageType toImageType(int image_type_index);
ImageType toImageType(const std::string image_type_string);


/* KIND ENUM */
enum class Kind {
	PREDICTED,
	GROUND_TRUTH
};

const char* toString(Kind kind);
int index(Kind kind);
Kind toKind(int kind_index);
Kind toKind(std::string kind_string);


/* MEAL MODALITY ENUM */
enum class MealModality {
	BEFORE_MEAL,
	AFTER_MEAL_LEFTOVER_1,
	AFTER_MEAL_LEFTOVER_2,
	AFTER_MEAL_LEFTOVER_3
};

const char* toString(MealModality meal_modality);
int index(MealModality meal_modality);
MealModality toMealModality(int meal_modality_index);
MealModality toMealModality(std::string meal_modality_string);


/* FOOD COURSE ENUM */
enum class FoodCourse {
	FIRST_COURSE,
	SECOND_COURSE,
	SIDE_DISH_AND_SIDE_FOODS
};

const char* toString(FoodCourse food_course);
int index(FoodCourse food_course);
FoodCourse toFoodCourse(int food_course_index);
FoodCourse toFoodCourse(std::string food_course_string);


/* FOOD CATEGORY ENUM */
enum class FoodCategory {
	BACKGROUND,
	PASTA_WITH_PESTO,
	PASTA_WITH_TOMATO_SAUCE,
	PASTA_WITH_MEAT_SAUCE,
	PASTA_WITH_CLAMS_AND_MUSSELS,
	PILAW_RICE_WITH_PEPPERS_AND_PEAS,
	GRILLED_PORK_CUTLET,
	FISH_CUTLET,
	RABBIT,
	SEAFOOD_SALAD,
	BEANS,
	BASIL_POTATOES,
	SALAD,
	BREAD
};

const char* toString(FoodCategory food_category);
int index(FoodCategory food_category);
FoodCategory toFoodCategory(int food_category_index);
FoodCategory toFoodCategory(std::string food_category_string);

cv::Scalar toColor(FoodCategory food_category);

std::vector<FoodCategory> getFoodCategories(FoodCourse food_course);
FoodCourse getFoodCourse(FoodCategory food_category);

#endif // !DATASET_CATEGORIES_H