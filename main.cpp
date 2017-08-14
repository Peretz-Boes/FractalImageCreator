#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "bitmap.h"
#include "mandelbrot.h"
#include "zoom.h"
#include "zoom list.h"

using namespace std;
using namespace caveofprogramming;

int main()
{
    int const HEIGHT=800;
    int const WIDTH=600;
    Bitmap bitmap(WIDTH,HEIGHT);
    double min=999999;
    double max=-999999;
    ZoomList zoomList(WIDTH/HEIGHT);
    zoomList.add(Zoom(WIDTH/2,HEIGHT/2));
    unique_ptr<int[]>histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]>fractal(new int[WIDTH*HEIGHT]{0});
    bitmap.setPixel(WIDTH/2,HEIGHT/2,255,255,255);
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            pair<double,double>coords=zoomList.doZoom(x,y);
            double xFractal=(x-WIDTH/2)*2.0/WIDTH;
            double yFractal=(y-HEIGHT/2)*2.0/HEIGHT;
            int iterations=Mandelbrot::getInterations(coords.first,coords.second);
            fractal[y*WIDTH+x]=iterations;
            if(iterations!=Mandelbrot::MAX_ITERATIONS){
            histogram[iterations]++;
            }

        }

        int total=0;
        for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++){
            total+=histogram[i];
        }

        for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            uint8_t red=0;
            uint8_t green=pow(255,hue);
            uint8_t blue=0;
            int iterations=fractal[y*WIDTH+x];
            uint8_t colour=(uint8_t)255*(double)iterations/Mandelbrot::MAX_ITERATIONS;
            if(iterations!=Mandelbrot::MAX_ITERATIONS){
                double hue=0.0;
            for(int i=0;i<=iterations;i++){
                hue+=((double)histogram[i])/total;
            }
            }
            uint8_t red=0;
            uint8_t green=pow(255,hue);
            uint8_t blue=0;
            bitmap.setPixel(x,y,0,colour,0);
        }
        }

    }
    bitmap.write("test.bmp");
    cout<<"Finished"<<endl;
    return 0;
}
