#include <fstream>
#include <iostream> 
#include <stdint.h>
using namespace std;

#pragma pack(1)
struct BitMapFileHeader{
    uint16_t bfType;     
    uint32_t bfSize;     
    uint16_t bfReserved1;
    uint16_t bfReserved2; 
    uint32_t bfOffBits;
};

struct BitMapInfoHeader{
	uint32_t biSize;          
    int32_t biWidth;         
    int32_t biHeight;         
    uint16_t biPlanes;        
    uint16_t biBitCount;     
    uint32_t biCompression;   
    uint32_t biSizeImages;    
    int32_t biXPelsPerMeter; 
    int32_t biYPelsPerMeter;  
    uint32_t biClrUsed;      
    uint32_t biClrImportant;
};

struct Pixel {
    uint8_t blue;
    uint8_t red;
    uint8_t green;
};

int main() 
{
	BitMapFileHeader BitMapFileHeader1 = 
	{0x4D42,480054,0,0,54}; 
    BitMapInfoHeader BitMapInfoHeader1 =
	{40,400,400,1,24,0,480000,1000,1000,0,0};
	Pixel pic[400][400];
	ifstream input;
	input.open("input.txt");
    ofstream output("output.bmp",ios::binary);
    output.write((char*)(&BitMapFileHeader1),sizeof(BitMapFileHeader1));
    output.write((char*)(&BitMapInfoHeader1),sizeof(BitMapInfoHeader1));
    int x,y,r;
    input >> x >> y >> r;
	input.close();   
    for(int i = 0;i < 400;i++)
    {
    	for(int j = 0;j < 400;j++)
    	{
    		if((j - x) * (j - x) + (i - y) * (i - y) < r * r)
    		{
    			pic[i][j].blue = 255;
    			pic[i][j].red = 255;
    			pic[i][j].green = 255;
			}
			else
			{
				pic[i][j].blue = 0;
				pic[i][j].red = 0;
    			pic[i][j].green = 0;
			}
		}
	}
    output.write((char*)(&pic),sizeof(pic));
	output.close();	   
    return 0;
}
