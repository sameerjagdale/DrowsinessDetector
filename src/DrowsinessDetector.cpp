//============================================================================
// Name        : DrowsinessDetector.cpp
// Author      : Sameer Jagdale
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "cameraHandler.hpp"
#include "helper.hpp"
#include<fstream>
#define TEST
#define COMMENT "SAMEER:  drowsy eyes"
#define PIXELTHRESHOLD 100
#define NOEYESLIMIT 200
#define DISTANCE "10"
void raiseAlarm();
int main() {

	CameraHandler handle;
	EyeDetector detector;
	Mat eyeROI;
	detector.setFaceCascade("haarcascade_frontalface_alt.xml");
	detector.setEyeCascade("haarcascade_eye_tree_eyeglasses.xml");
	handle.initCamera(-1);
	cvNamedWindow("test");
	int numBlack = 0;
	int flag = 0;
	int count = 0;
	int noEyesCount;
	while (true) {
		Mat frame = handle.fetchFrame();
		Mat frame_gray;
		int faceIndx = 0;
		cvtColor(frame, frame_gray, CV_BGR2GRAY);
		equalizeHist(frame_gray, frame_gray);

		vector<Rect> faces = detector.detectFaces(frame_gray);
		vector<Rect> eyes;
		if (faces.size() > 0) {
			faceIndx = Helper::getMax(faces);

			detector.drawRect(frame,
					Point(faces[faceIndx].x, faces[faceIndx].y),
					Point(faces[faceIndx].x + faces[faceIndx].width,
							faces[faceIndx].y + faces[faceIndx].height),
					Scalar(255, 0, 0));

			eyes = detector.detectEyes(faces[faceIndx], frame_gray);

			cout << "size of eyes" << eyes.size() << endl;

			for (uint j = 0; j < eyes.size(); j++) {
				detector.drawRect(frame,
						Point(faces[faceIndx].x + eyes[j].x,
								faces[faceIndx].y + eyes[j].y),
						Point(faces[faceIndx].x + eyes[j].x + eyes[j].width,
								faces[faceIndx].y + eyes[j].y + eyes[j].height),
						Scalar(0, 255, 0));
				if (flag == 1&&eyes.size()>0) {
					numBlack += Helper::getBlackPixels(frame_gray(eyes[j]));
				}

			}

			if (flag == 1) {
				count++;
				cout << "black pixels" << numBlack / count << endl;
			}
#ifndef TEST
			if (numBlack / count < PIXELTHRESHOLD) {
				noEyesCount++;

				if (noEyesCount == NOEYESLIMIT) {
					raiseAlarm();
					noEyesCount = 0;
				}

			}
#endif
			//cout << "black pixels" << numBlack / count << endl;

		}
		imshow("test", frame);
		int c = waitKey(10);
		if ((char) c == 'c') {
			break;
		}
		if ((char) c == 'w') {
			Helper::writeFile("log.txt", COMMENT, (float) numBlack / count,
					faces[faceIndx].height, faces[faceIndx].width);
			numBlack = 0;
		}
		if ((char) c == 'r') {
			flag = 1;
		}
		if ((char) c == 's') {
			flag = 0;
		}

	}
	handle.releaseCamera();
	return 0;
}

void raiseAlarm() {
}

