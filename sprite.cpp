
#include <opencv2/opencv.hpp>

using namespace cv;

#include <string>

int main(){
Mat image = imread("psykokwak.png");
namedWindow("Sample Window");
imshow("Sample Window", image);
waitKey(0);
return 0; 
}