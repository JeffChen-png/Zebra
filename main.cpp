#include <iostream>
#include "AVL.h"

using namespace avl;
using namespace std;
using namespace atl;
using namespace avs;

int main() {

    Image img;

    LoadImage("/home/rustam/Рабочий стол/zebra1.jpg",false, img);

    Image img_gray;
    AverageChannels(img,NIL,img_gray);
    SaveImage(img_gray,NIL,"/home/rustam/Рабочий стол/zebra1_grey.jpg",false);

    //Image img_equalized;
    //EqualizeImageHistogram(img,NIL,0.0,0.0,img_equalized);
    //SaveImage(img_equalized,NIL,"/home/rustam/Рабочий стол/zebra2_equalized.jpg",false);

    Image img_Threshold;
    ThresholdImage(img_gray,NIL,128.0f,NIL,0.3,img_Threshold);
    SaveImage(img_Threshold,NIL,"/home/rustam/Рабочий стол/zebra1_Threshold.jpg",false);

    Image img_erode;

    ErodeImage(img_Threshold,NIL,NIL,NIL,KernelShape::Box,1,NIL,img_erode);
    SaveImage(img_erode,NIL,"/home/rustam/Рабочий стол/zebra1_erode.jpg",false);

    /////////////////////////////////////////////////////////////////
    /*
     * нахождение контуров с последующей отрисовкой (не работает без лицензии) terminate called after throwing an instance of 'avl::AvlLicenseError'
     *
    Image img_det;
    LoadImage("/home/rustam/Рабочий стол/zebra1.jpg",false, img_det);

    Pixel pixel;
    AvsFilter_MakePixel(1,1,1,1,pixel);

    Array<Path> out;
    DetectEdges_AsPaths_Mask(img_Threshold,NIL,EdgeMaskFilter::Sobel,35.0f,15.0f,NIL,30.0f,0.0f,NIL,0.0f,out);

    DrawPath(img_det,out[1],NIL,pixel,DrawingStyle ( DrawingMode:: HighQuality, 1.0f,1.0f, 0, NIL, 1.0f ));
     */
    ////////////////////////////////////////////////////////////////

    Array<Segment2D> out1;
    Image img_lines;
    Image img_color;
    //DetectSegments(img_erode,NIL,1.0f,20.0f,20.0f,20.0f,20.0f,10.0f,out1,img_lines,img_color );

    ////////////////////////////////////////////////////////////////

    /*
     * перевод изображения в hsv
     *
    Image hsv_img;
    RgbToHsv(img, hsv_img);
     */

    return 0;
}