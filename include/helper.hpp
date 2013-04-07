/*
 * helper.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: sameer
 */
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include<fstream>
#include <stdio.h>
#define THRESHOLD 50

using namespace cv;
using namespace std;
class Helper {
public:
	static int getMax(vector<Rect> faces);
	static int getBlackPixels(Mat Roi);
	static void writeFile(const char* fileName, String key, int value,
			int height, int width);

};

