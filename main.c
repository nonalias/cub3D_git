#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned char BYTE;

typedef struct tagBITMAPFILEHEADER {    // 14 = 2+4+2+2+4 (byte)
   WORD    bfType;  // "BM"이라는 글자가 설정됨
   DWORD   bfSize;  // 비트맵 파일의 전체 크기
   WORD    bfReserved1;  // 예약변수(0으로 설정함)
   WORD    bfReserved2;  // 예약변수(0으로 설정함)
   DWORD   bfOffBits;  // 파일에서 비트맵 데이터가 있는 위치
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {  // 40 = 4+4+4+2+2+4+4+4+4+4+4 (byte)
   DWORD biSize;  // 구조체의 크기
   LONG biWidth;  // 비트맵의 가로 크기
   LONG biHeight;  // 비트맵의 세로 크기
   WORD biPlanes;  // Plane수(1로 설정함)
   WORD biBitCount;  // 한 픽셀당 비트수
   DWORD biCompression;  // 압축 유무 플래그
   DWORD biSizeImage;  // 그림 데이터의 크기
   LONG biXPelsPerMeter;  // 한 픽셀당 가로 미터
   LONG biYPelsPerMeter;  // 한 픽셀당 세로 미터
   DWORD biClrUsed;  // 그림에서 실제 사용되는 컬러 수
   DWORD biClrImportant;  // 중요하게 사용되는 컬러
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD { // 4
   BYTE rgbBlue;  // B성분 (파랑)
   BYTE rgbGreen; // G성분 (초록)
   BYTE rgbRed;   // R성분 (빨강)
   BYTE rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPINFO {
   BITMAPINFOHEADER bmiHeader;
   RGBQUAD bmiColors[1];
} BITMAPINFO;


int	main(void)
{
	int fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND ,
			S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP);


	// bitmapfileheader 먼저 설정
	// bitmapinfo 설정
	// // bitmapinfoheader 설정
	// // rgbquad 설정

	//위에 설정한 내용들을 적절해 세팅해주고, fd에 write를 적절히 해주면 됨.

	write(fd, "HELLO, WORLD!\n", 14);
}
