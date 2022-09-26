#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

void setImageRed(cv::Mat img) {
	img = cv::Scalar(0, 0, 100);
	cv::imwrite("red.jpg", img);
}

void FillRed() {

	cv::Mat Image = cv::imread("C:\\Users\\hallgato\\Desktop\\kepf09_19\\ratpepega.jpg");

	cv::Mat BlankMatrix(Image.size(), CV_8UC3);

	for (int i = 0; i < Image.rows; ++i) {
		for (int j = 0; j < Image.cols; ++j) {
			cv::Vec3b currentPixelGroup = Image.at<cv::Vec3b>(i, j);
			currentPixelGroup[0] = 0;
			currentPixelGroup[1] = 0;
			BlankMatrix.at<cv::Vec3b>(i, j) = currentPixelGroup;
		}
	}

	cv::imshow("red", BlankMatrix);
	//cv::waitKey();

}

void decreaseBrightness()
{
	cv::Mat img = cv::imread("C:\\Users\\hallgato\\Desktop\\kepf09_19\\ratpepega.jpg");
	cv::Mat image;
	img.convertTo(image, -1, 1, -50); //decrease the brightness by 50
	cv::imshow("brightness", image);
}

void imageBlur()
{
	cv::Mat image = cv::imread("C:\\Users\\hallgato\\Desktop\\kepf09_19\\ratpepega.jpg");
	int x = 225;
	int y = 225;
	int w = 150;
	int h = 150;
	cv::Rect region(x, y, w, h);
	cv::GaussianBlur(image(region), image(region), cv::Size(0, 0), 20);
	cv::imshow("blur", image);
}

void ImgtoGray(cv::Mat &img) {
	cv::Mat GrayScale;
	cv::cvtColor(img, GrayScale, cv::COLOR_BGR2GRAY);
	cv::imwrite("szurke.jpg", GrayScale);
}

void convertRGBtoHSV(){
	cv::Mat Image = cv::imread("C:\\Users\\hallgato\\Desktop\\kepf09_19\\ratpepega.jpg");
	cv::Mat newImage;
	cv::cvtColor(Image, newImage, cv::COLOR_BGR2HSV);
	cv::imshow("newImage", newImage);
}

int main() {

	cv::Mat M(640, 480, CV_8UC3, cv::Scalar::all(0));
	cv::Mat Image = cv::imread("C:\\Users\\hallgato\\Desktop\\kepf09_19\\ratpepega.jpg");
	
	setImageRed(M);
	ImgtoGray(Image);
	FillRed();
	convertRGBtoHSV();
	decreaseBrightness();
	imageBlur();

	cv::imshow("M", M);
	cv::waitKey();

	return 0;
}
