#include "cameraHandler.hpp"
bool checkEyes(vector<Rect> eyes);

void drawFaceRect(EyeDetector detector, Mat frame, Rect facesI);

void drawEyesRect(EyeDetector detector, Mat frame, Rect facesI, Rect eyesJ);
