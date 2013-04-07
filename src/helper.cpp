/*
 * helper.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: sameer
 */
#include "helper.hpp"

using namespace std;
using namespace cv;
int Helper::getMax(vector<Rect> faces) {
	int indx;
	int max = -1;
	indx = 0;
	for (uint i = 0; i < faces.size(); i++) {
		if (faces[i].height > max) {
			max = faces[i].height;
			indx = i;
		}
	}
	return indx;
}
void Helper::writeFile(const char* fileName, String key, int value, int height,
		int width) {
	ofstream fout;
	fout.open(fileName, ios::app | ios::out);
	fout << key << " " << value << " " << height << " " << width << "\n";
	fout.close();
}

int Helper::getBlackPixels(Mat Roi) {
	int count = 0;
	cout << "size of Roi" << sizeof(Roi) / sizeof(char) << endl;
	for (int i = 0; i < Roi.rows; i++) {
		const uchar *row = Roi.ptr<uchar>(i);
		for (int j = 0; j < Roi.cols; j++) {
			if ((int) row[j] <= THRESHOLD) {
				count++;
			}
		}
	}
	return count;
}
