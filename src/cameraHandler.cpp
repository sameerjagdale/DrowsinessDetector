/*
 * cameraHandler.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: sameer
 */
#include "cameraHandler.hpp"

using namespace std;
using namespace cv;

void EyeDetector::setFaceCascade(CascadeClassifier face) {
	faceCascade = face;
}

void EyeDetector::setEyeCascade(CascadeClassifier eye) {
	eyesCascade = eye;
}

int EyeDetector::setFaceCascade(String faceStr) {
	return faceCascade.load(faceStr);
}

int EyeDetector::setEyeCascade(String eyeStr) {
	return eyesCascade.load(eyeStr);
}

void EyeDetector::drawRect(Mat frame, Point top, Point bottom, Scalar color) {
	rectangle(frame, top, bottom, color, 4, 8, 0);
}
vector<Rect> EyeDetector::detectFaces(Mat frame_gray) {
	vector<Rect> faceVector;

	//-- Detect faces
	faceCascade.detectMultiScale(frame_gray, faceVector, 1.1, 2,
			0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	return faceVector;
}
vector<Rect> EyeDetector::detectEyes(Rect face, Mat frame_gray) {
	//Mat frame_gray;
	vector<Rect> eyeVector;
	Mat faceROI = frame_gray(face);
	eyesCascade.detectMultiScale(faceROI, eyeVector, 1.1, 2,
			0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	return eyeVector;
}
int CameraHandler::initCamera(int indx) {
	capture = cvCaptureFromCAM(indx);
	if (!capture) {
		return -1;
	} else
		return 1;
}
Mat CameraHandler::fetchFrame() {
	return cvQueryFrame(capture);

}

Mat CameraHandler::getFrame() {
	return frame;
}
