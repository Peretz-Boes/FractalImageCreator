#include "zoom list.h"
using namespace std;
namespace caveofprogramming{

ZoomList::ZoomList(int width,int height):width(width),height(height){

}

void zoom(const Zoom& zoom){
zooms.push_back(zoom);
xCenter+=(zoom.x-width/2)*scale;
yCenter+=(zoom.x-height/2)*scale;
scale*=zoom.scale;
cout<<xCenter<<", "<<yCenter<<endl;
}

pair<double,double>doZoom(int x,int y){
double xFractal=(x-width/2)*scale+xCenter;
double yFractal=(y-height/2)*scale+yCenter;
return pair<double,double>(xFractal,yFractal);
}

}
