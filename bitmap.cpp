#include "bitmap.h"
#include "bitmap info header.h"
using namespace std;
using namespace caveofprogramming;
namespace caveofprogramming{
Bitmap::Bitmap(int width,int height):imageWidth(width),imageHeight(height),pPixels(new uint8_t[width*height*3]{}){

}
bool Bitmap::write(string filename){
BitmapFileHeader fileHeader;
BitmapInfoHeader infoHeader;
fileHeader.fileSize=sizeof(BitmapFileHeader)+sizeof(BitmapInfoHeader)+imageWidth*imageHeight*3;
fileHeader.dataOffset=sizeof(BitmapFileHeader)+sizeof(BitmapInfoHeader);
infoHeader.width=imageWidth;
infoHeader.height=imageHeight;
ofstream file;
file.open(filename,ios::out|ios::binary);
if(!file){
    return false;
}
file.write((char*)&fileHeader,sizeof(fileHeader));
file.write((char*)&infoHeader,sizeof(infoHeader));
file.write((char*)pPixels.get(),imageWidth*imageHeight*3);
file.close();
if(!file){
    return false;
}
return true;
}

void setPixel(int x,int y,uint8_t red,uint8_t green,uint8_t blue){
uint8_t *pPixel=pPixels.get();
pPixels+=y*imageWidth+x;
pPixel[0]=blue;
pPixel[1]=green;
pPixel[2]=red;
}

}
