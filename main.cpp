#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void horizontal(Mat input,Mat output,int scaler)
{
    float scale = scaler/10.0;
    float scale1 = 1/(scale - 1);
//    std::cout << std::fixed << std::setprecision(10) << scale1 << std::endl;
//    cout << scale;
//    cout << input.cols <<endl;
    for(int y=0; y<input.rows; y++)
    {
        int c = 1;
        int v=0;
        float a = 0.0;
        a = a + scale1;
        for(int x=0; x<input.cols; x++)
        {
            Vec3b pixel = input.at<Vec3b>(y,x);
            output.at<Vec3b>(y,v) = pixel;
//            if(y==0)
//                cout << x <<endl;
            while(c == round(a))
            {
//                if(y==0){
//                cout<<"c=" << c <<endl;
//                cout<<"a=" << round(a) <<endl;
//                }
                a = a + scale1;
                v++;
                output.at<Vec3b>(y,v) = pixel;
            }
            c++;
            v++;
        }
//        cout << v <<endl;
    }
}

void vertical(Mat input,Mat output,int scaler)
{
    float scale = scaler/10.0;
    float scale1 = 1/(scale - 1.0);
    float a=0;
    int v=0;
    int c =1;
//    cout << scale1 << endl;
     a = a + scale1;
    for(int y=0; y<input.rows; y++)
    {
        for(int x=0; x<input.cols; x++)
        {
            Vec3b pixel = input.at<Vec3b>(y,x);
            output.at<Vec3b>(v,x) = pixel;
        }
//        cout << a << " ";
        while( c == round(a))
        {
            a = a + scale1;
            v++;
            for(int x=0; x<input.cols; x++)
            {
                Vec3b pixel = input.at<Vec3b>(y,x);
                output.at<Vec3b>(v,x) = pixel;
            }
//            cout << a << " ";
        }
//        if( y == input.rows-1)
//        {
//            for(int x=0; x<input.cols; x++)
//            {
//                Vec3b pixel = input.at<Vec3b>(y,x);
//                output.at<Vec3b>(v+1,x) = pixel;
//            }
//        }
        v++;
        c++;
    }
}
int main()
{
    Mat input = imread("C:\\Users\\Diwakar\\Documents\\New folder\\CLAHE_live\\img_640x480.png");
    int scaler = 0;
    cout << "Enter the scaling value: ";
    cin >> scaler;
    int cols = (input.cols * scaler)/10;
    int rows = (input.rows * scaler)/10;
    cout << cols <<endl;
    Mat output = Mat(rows,input.cols,input.type());
    Mat final_output = Mat(rows,cols,input.type());
    vertical(input,output,scaler);
    horizontal(output,final_output,scaler);
    imshow("output",final_output);
    waitKey(0);
    return 0;
}
