#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("car.jpg");

	//ת����HSV
	Mat img_h, img_s, img_v,imghsv;
	vector<Mat> hsv_vec;
	cvtColor(src, hsv_vec, COLOR_BGR2GRAY);
	imshow("hsv�ռ�ͼ��", hsv_vec);
	waitKey(0);

	//�ָ�HSVͨ��
	split(imghsv, hsv_vec);
	img_h = hsv_vec[0];
	img_s = hsv_vec[1];
	img_v = hsv_vec[2];

	//��������ת��
	img_h.convertTo(img_h, CV_32F);
	img_s.convertTo(img_s, CV_32F);
	img_v.convertTo(img_v, CV_32F);

	//����ÿ��ͨ�������ֵ
	double max_h, max_s, max_v;
	minMaxIdx(img_h, NULL, &max_h);
	minMaxIdx(img_s, NULL, &max_s);
	minMaxIdx(img_v, NULL, &max_v);
}