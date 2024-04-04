# Food recognition and leftover estimation

## Group Members
| Surname   | Name                 |
| ----------| ---------------------|
| Osti      | Simone               |
| Russo     | Christian Francesco	 |
| Spinato   | Matteo               |

## Project description
The goal of this project is to develop a computer vision system capable of scanning a canteen consumer's food tray at the end of a meal to estimate the amount of leftovers for each type of food. Such a system must be able to analyze pairs of images: one of the tray before the meal and one of the tray at the end of the meal. From the first image, the system will recognize the various types of food ordered, keeping track of the initial quantity of each food; at the end of the meal, the system must analyze a new image of the tray, recognizing which types of food are still present and in what quantity.

In more detail, the system to be developed should be able to:
  1. recognize and localize all the food items in the tray images, considering the food categories detailed in the dataset;
  2. segment each food item in the tray image to compute the corresponding food quantity (i.e., amount of pixels);
  3. compare the “before meal” and “after meal” images to find which food among the initial ones was eaten and which was not. The leftovers quantity is then estimated as the difference in the number of pixels of the food item in the pair of images.

Example of the pair of images to be analyzed. On the left, the customer's tray before the meal, on the right the tray after the meal with some food leftovers:
<p align="center">
  <img src="https://github.com/ChrRus99/Computer-Vision/assets/164178391/c994f125-46c7-48ef-a35a-d1025000fe35" width="75%">
</p>

Example of the system outputs. From left to right: input image, food recognition and food segmentation:
<p align="center">
  <img src="https://github.com/ChrRus99/Computer-Vision/assets/164178391/113520a9-1451-4724-a0c7-4e432464c345" width="75%">
</p>
