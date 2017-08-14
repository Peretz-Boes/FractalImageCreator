#ifndef ZOOMLIST_H
#define ZOOMLIST_H
#include <vector>
#include <utility>
using namespace std;
namespace caveofprogramming{
class ZoomList{
private:
    double xCenter{0};
    double yCenter{0};
    double scale{0.0};
    int width{0};
    int height{0};
    vector<Zoom>zooms;
public:
    ZoomList(width,height);
    void zoom(const Zoom& zoom);
    pair<double,double>doZoom(int x,int y);
};

}

#endif // ZOOMLIST_H
