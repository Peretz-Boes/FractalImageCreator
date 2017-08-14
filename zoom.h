#ifndef ZOOM_H
#define ZOOM_H
namespace caveofprogramming{

struct Zoom{
public:
    int x{0};
    int y{0};
    double scale{1.0};
    Zoom(int x,int y,double scale):x(x),y(y),scale(scale){};
};

}

#endif // ZOOM_H
