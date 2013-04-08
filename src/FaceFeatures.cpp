#include "FaceFeatures.hpp"
bool checkEyes(vector<Rect> eyes) {

	if (eyes.size() == 0)
		return false;
	if (eyes.size() == 1)
		return false;
	if (eyes.size() == 2) {
		if (abs(eyes[0].x - eyes[1].x) >= 100)
			return true;
		else
			return false;
	}
	return true;

}

void drawFaceRect(EyeDetector detector, Mat frame, Rect facesI) {
	cout << "Checkpoint 3.5.1" << endl;

	detector.drawRect(frame, Point(facesI.x, facesI.y),
			Point(facesI.x + facesI.width, facesI.y + facesI.height),
			Scalar(255, 0, 0));
	cout << "Checkpoint 3.5.2" << endl;

}

void drawEyesRect(EyeDetector detector, Mat frame, Rect facesI, Rect eyesJ){
						detector.drawRect(frame,
								Point(facesI.x + eyesJ.x,
										facesI.y + eyesJ.y),
								Point(facesI.x + eyesJ.x + eyesJ.width,
										facesI.y + eyesJ.y
												+ eyesJ.height),
								Scalar(0, 255, 0));
}
