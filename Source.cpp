#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat setImageRed(cv::Mat img) {
	img = cv::Scalar(0, 0, 100);
	return img;
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

void ImgtoGray(cv::Mat &img) {
	cv::Mat GrayScale;
	cv::cvtColor(img, GrayScale, cv::COLOR_BGR2GRAY);
	cv::imwrite("szurke.jpg", GrayScale);
}

int main() {

	cv::Mat M(640, 480, CV_8UC3, cv::Scalar::all(0));
	cv::Mat Image = cv::imread("C:\\Users\\hallgato\\Desktop\\kepf09_19\\ratpepega.jpg");

	setImageRed(M);

	cv::imwrite("red.jpg", M);

	ImgtoGray(Image);
	FillRed();
	cv::imshow("M", M);
	cv::waitKey();

	return 0;
}
