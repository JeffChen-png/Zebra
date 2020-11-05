#include <iostream>
#include "AVL.h"
#include "STD.h"

using namespace avl;
using namespace std;
using namespace atl;
using namespace avs;

int main() {

    Image img;
    LoadImage("/home/rustam/Рабочий стол/zebra1.jpg",false, img);

    Image img_gray;
    AverageChannels(img,NIL,img_gray);

    Image img_Threshold;
    ThresholdImage(img_gray,NIL,140.0f,NIL,0.3,img_Threshold);
    
    Image img_erode;
    ErodeImage(img_Threshold,NIL,NIL,NIL,KernelShape::Box,1,NIL,img_erode);

    Image img_det = img;

    Pixel pixel;
    AvsFilter_MakePixel(255,120,120,255,pixel);
    Array<Path> out_path_array;

    int w = img.Width();
    int h = img.Height();

    Region rec_region;
    Rectangle2D box({0,h/2},0,w,h/2);
    CreateRectangleRegion(box,NIL,w,h,rec_region,NIL);

    DetectEdges_AsPaths_Mask(img_erode,rec_region,EdgeMaskFilter::Prewitt,10.0f,5.0f,NIL,100,0.5f,NIL,0.0f,out_path_array);

    for (int i = 0; i < out_path_array.Size();i++) {
        DrawPath(img_det, out_path_array[i], NIL, pixel, DrawingStyle(DrawingMode::HighQuality, 1.0f, 1.0f, false, PointShape::Type::Circle, 1.0f));
    }

     SaveImage(img_det,NIL,"/home/rustam/Рабочий стол/zebra.jpg",false);

     ////////////////////////////////////////////////////////////////
     /*
     Image img_det;
     LoadImage("/home/rustam/Рабочий стол/zebra1.jpg",false, img_det);

     Pixel pixel;
     AvsFilter_MakePixel(1,1,1,1,pixel);

     Array<Segment2D> out;
     Image img_lines;
     Image img_color;
     DetectSegments(img_erode,NIL,1.0f,20.0f,20.0f,20.0f,20.0f,10.0f,out,img_lines,img_color );

     DrawSegments_SingleColor(img_det, {как перейти от out к conditional out}, NIL, pixel,DrawingStyle(DrawingMode::Fast, 0.5f, 3.0f, false, PointShape::Type::Circle, 3.0f),MarkerType::None, 5.0f, 1, img_det);
     SaveImage(img_det,NIL,"/home/rustam/Рабочий стол/zebra1_ris.jpg",false);
      */
    ////////////////////////////////////////////////////////////////

    /*
     * перевод изображения в hsv
     *
    Image hsv_img;
    RgbToHsv(img, hsv_img);
     */

    return 0;
}