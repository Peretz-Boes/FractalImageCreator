#ifndef BITMAP_H
#define BITMAP_H
#include <string>
#include <cstdint>
using namespace std;
namespace caveofprogramming{

class Bitmap{

private imageWidth{0};
private imageHeight{0};
unique ptr<uint8_t[]>pPixels{nullptr};

public:
    Bitmap(int width,int height);
    void setPixel(int x,int y,uint8_t red,uint8_t green,uint8_t blue);
    bool write(string filename);
    virtual ~Bitmap();

};

}


#endif // BITMAP_H
