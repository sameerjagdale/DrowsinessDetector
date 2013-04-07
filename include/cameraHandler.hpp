/*
 * cameraHandler.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: sameer
 */

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

class CameraHandler {
private:
	CvCapture* capture;
	Mat frame;
	//String face_cascade_name = "haarcascade_frontalface_alt.xml";
	//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";

public:

	int initCamera(int indx);
	Mat fetchFrame();
	Mat getFrame();
	static void dispFrame(Mat frame, String windowName) {
		imshow(windowName, frame);
	}
	void releaseCamera() {
		cvReleaseCapture(&capture);
	}
};

class EyeDetector {
private:
	CascadeClassifier faceCascade;
	CascadeClassifier eyesCascade;
public:
	void setFaceCascade(CascadeClassifier face);
	void setEyeCascade(CascadeClassifier eye);
	int setFaceCascade(String faceStr);
	int setEyeCascade(String eyeStr);
	vector<Rect> detectFaces(Mat frame);
	vector<Rect> detectEyes(Rect face, Mat frame_gray);
	void drawRect(Mat frame, Point top, Point bottom, Scalar color);

};

