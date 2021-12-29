//  main.cpp
//  OpenCVtest
//
//  Created by Vrushank Gunjur on 7/19/21.


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>



int textSize(cv::Rect rt)
{
    int textSize = 1;
    
    /*
    int topLeftx = rt.tl().x;
    int topLefty = rt.tl().y;
    
    int botRightx = rt.br().x;
    int botRighty = rt.br().y;
    */
    
    int width = rt.br().x - rt.tl().x;
    
    textSize = width/40;
    
    return textSize;
}

int main(int argc, const char * argv[]) {
    //IMAGE
    /*
    std::string path = "/Users/vrushankgunjur/Documents/OCV/OpenCVtest/OpenCVtest/image.JPG";
    cv::Mat img = cv::imread(path);
    cv::Mat imgGray;
    cv::Mat imgBlur;
    cv::Mat imgCanny;
    
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(img, imgBlur, cv::Size(7,7),10,0);
    cv::Canny(imgBlur, imgCanny, 20, 150);
    
    imshow("Columbia River Expedition", img);
    imshow("Columbia River Expedition Grayscale", imgGray);
    imshow("Edges", imgCanny);
    cv::waitKey(0);
    */
    
    
    //FACE DETECTION IMG
    /*
    std::string path = "/Users/vrushankgunjur/Documents/OCV/OpenCVtest/OpenCVtest/faces.JPG";
    cv::Mat img = cv::imread(path);
    
    cv::CascadeClassifier faceCascade;
    faceCascade.load("/Users/vrushankgunjur/Documents/OCV/OpenCVtest/OpenCVtest/haarcascade_frontalface_default.xml");
    
    if(faceCascade.empty()) std::cout << "XML File Unloaded" << std::endl;
    
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 15);
    
    for(int idx = 0; idx < faces.size(); idx++)
    {
        rectangle(img, faces[idx].tl(), faces[idx].br(), cv::Scalar(255,255,255), 3);
        cv::putText(img, "Face", cv::Point(faces[idx].tl().x, faces[idx].tl().y), 1, 5, cv::Scalar(255,0,255),3);
    }
    
    
    imshow("Faces", img);
    cv::waitKey(0);
    */
    
    //FACE DETECTION VIDEO
    
    std::string path = "/Users/vrushankgunjur/Documents/OCV/OpenCVtest/OpenCVtest/kawhi.mov";
    cv::VideoCapture cap(path);
    cv::Mat img;
    
    cv::CascadeClassifier faceCascade;
    faceCascade.load("/Users/vrushankgunjur/Documents/OCV/OpenCVtest/OpenCVtest/haarcascade_frontalface_default.xml");
    
    if(faceCascade.empty()) std::cout << "XML File Unloaded" << std::endl;
    
    while(cap.read(img))
    {
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 15);
    
    for(int idx = 0; idx < faces.size(); idx++)
    {
        rectangle(img, faces[idx].tl(), faces[idx].br(), cv::Scalar(255,255,255), 3);
        int tSize = textSize(faces[idx]);
        cv::putText(img, "Face", cv::Point(faces[idx].tl().x, faces[idx].tl().y), 1, tSize, cv::Scalar(255,0,255),3);
    }
    
    
        
        
    imshow("Faces", img);
    cv::waitKey(1);
    }
    
    
    //VIDEO
    /*
    std::string path = "/Users/vrushankgunjur/Documents/OCV/OpenCVtest/OpenCVtest/rain.mov";
    cv::VideoCapture cap(path);
    cv::Mat img;
    
    while(cap.read(img))
    {
        imshow("video", img);
        cv::waitKey(20);
    }
    */
    
    return 0;
    
}


