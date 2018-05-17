/*
 * shapes.c
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */
#include "shapes.h"
#include <stdlib.h>
#include <math.h>

//#include "pixelBuffer.h"
PixelBuffer* ppBuf;

uint8_t setShapesPixelBuffer(PixelBuffer* pb) {
	ppBuf = pb;
	return 0;
}

uint8_t drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
		uint8_t col = 250) {

	int dx = x2 - x1;
	int dy = y2 - y1;
	float rcx = 0;
	float rcy = 0;
	if (dx != 0)
		rcx = (float) dy / (float) dx;
	if (dy != 0)
		rcy = (float) dx / (float) dy;
	int x = x1;
	int y = y1;
	float error = 0;
	if (abs(dx) > abs(dy)) {
		if (x1 > x2) {
			drawLine(x2, y2, x1, y1, col);
		}
		for (x = x1; x <= x2; x++) {
			ppBuf->add(col, x, y);
			error = error + rcy;
			y = y1 + round(error);
		}

	} else {
		if (y1 > y2) {
			drawLine(x2, y2, x1, y1, col);
		}
		for (y = y1; y <= y2; y++) {
			ppBuf->add(col, x, y);
			error = error + rcx;
			x = x1 + round(error);
		}

	}

	return 0;
}

uint8_t drawRect(uint16_t x3, uint16_t y3, uint16_t x2, uint16_t y2,
		uint8_t col, uint16_t fill) {
	if (x3 == x2 || y3 == y2) {
		return 2;
	}
	if (x3 > x2) {
		uint16_t x = x3;
		x3 = x2;
		x2 = x;
	}
	if (y3 < y2) {
		uint16_t y = y3;
		y3 = y2;
		y2 = y;
	}

	if (drawLine(x3, y3, x2, y3, col)) {
		return 1;
	}
	if (drawLine(x3, y2, x3, y3, col)) {
		return 1;
	}
	if (drawLine(x2, y2, x2, y3, col)) {
		return 1;
	}
	if (drawLine(x2, y2, x3, y2, col)) {
		return 1;
	}
	if (fill) {
		if (x2 != x3 && y2 != y3)
			drawRect(x3 + 1, y3 - 1, x2 - 1, y2 + 1, col, 1);
	}
	return 0;
}

uint8_t drawTri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3,
		uint16_t y3, uint8_t col, uint16_t fill) {

	if (drawLine(x2, y2, x1, y1, col)) {
		return 1;
	}
	if (drawLine(x3, y3, x1, y1, col)) {
		return 1;
	}
	if (drawLine(x3, y3, x2, y2, col)) {
		return 1;
	}

	return 0;
}

/*uint8_t drawEllip(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad, uint8_t col, uint16_t fill){
	 //Region 1
	   p=yrad*yrad-xrad*xrad*yrad+xrad*xrad/4;
	   xp=0;
	   yp=yrad;
	   while(2.0*yrad*yrad*xp <= 2.0*xrad*xrad*yp)
	   {
		if(p < 0)
		{
			xp++;
			p = p+2*yrad*yrad*xp+yrad*yrad;
		}
		else
		{
			xp++;
			yp--;
			p = p+2*yrad*yrad*xp-2*xrad*xrad*y-yrad*yrad;
		}
		//UB_VGA_SetPixel(xc+x,yc+y,RED);
		//UB_VGA_SetPixel(xc+x,yc-y,RED);
		//UB_VGA_SetPixel(xc-x,yc+y,RED);
		//UB_VGA_SetPixel(xc-x,yc-y,RED);
		ppBuf->add(col, xc+x,yc+y);
		ppBuf->add(col, xc+x,yc-y);
		ppBuf->add(col, xc-x,yc+y);
		ppBuf->add(col, xc-x,yc-y);
	   }

	  //Region 2
	   p=yrad*yrad*(x+0.5)*(x+0.5)+xrad*xrad*(y-1)*(y-1)-xrad*xrad*yrad*yrad;
	   while(yp > 0)
	   {
		if(p <= 0)
		{
			xp++;
			yp--;
			p = p+2*yrad*yrad*xp-2*xrad*xrad*yp+xrad*xrad;
		}
		else
		{
			yp--;
			p = p-2*xrad*xrad*yp+xrad*xrad;
		}
		//putpixel(xc+x,yc+y,RED);
		//putpixel(xc+x,yc-y,RED);
		//putpixel(xc-x,yc+y,RED);
		//putpixel(xc-x,yc-y,RED);
		 ppBuf->add(col, xc+x,yc+y);
		 ppBuf->add(col, xc+x,yc-y);
		 ppBuf->add(col, xc-x,yc+y);
		 ppBuf->add(col, xc-x,yc-y);
	   }
}*/

uint8_t drawEllip(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad, uint8_t col, uint16_t fill){
uint16_t xp,yp;
float p;

   //Region 1
   p=yrad*yrad-xrad*xrad*yrad+xrad*xrad/4;
   xp=0;
   yp=yrad;
   while(2.0*yrad*yrad*xp <= 2.0*xrad*xrad*yp)
   {
	if(p < 0)
	{
		xp++;
		p = p+2*yrad*yrad*xp+yrad*yrad;
	}
	else
	{
		xp++;
		yp--;
		p = p+2*yrad*yrad*xp-2*xrad*xrad*yp-yrad*yrad;
	}
	//putpixel(x+xp,y+yp,RED);
	//putpixel(x+xp,y-yp,RED);
	//putpixel(x-xp,y+yp,RED);
	//putpixel(x-xp,y-yp,RED);

	ppBuf->add(col, x+xp,y+yp);
	ppBuf->add(col, x+xp,y-yp);
	ppBuf->add(col, x-xp,y+yp);
	ppBuf->add(col, x-xp,y-yp);

   }

  //Region 2
   p=yrad*yrad*(xp+0.5)*(xp+0.5)+xrad*xrad*(yp-1)*(yp-1)-xrad*xrad*yrad*yrad;
   while(yp > 0)
   {
	if(p <= 0)
	{
		xp++;
		yp--;
		p = p+2*yrad*yrad*xp-2*xrad*xrad*yp+xrad*xrad;
	}
	else
	{
		yp--;
		p = p-2*xrad*xrad*yp+xrad*xrad;
	}
	//putpixel(x+xp,y+yp,RED);
	//putpixel(x+xp,y-yp,RED);
	//putpixel(x-xp,y+yp,RED);
	//putpixel(x-xp,y-yp,RED);

	ppBuf->add(col, (x-1)+xp,y+yp);
	ppBuf->add(col, (x-1)+xp,y-yp);
	ppBuf->add(col, (x-1)-xp,y+yp);
	ppBuf->add(col, (x-1)-xp,y-yp);

   }

   if (fill == true && xrad != 1 && yrad != 1)
   {
	    return drawEllip(x,y,xrad-1,yrad-1,col, fill);
   }

   return 0;
}

uint8_t drawEllipfill(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad, uint8_t col)//metalleen fill
{
	for(int yp=-yrad; yp<=yrad; yp++)
	{
		    for(int xp=-xrad; xp<=xrad; xp++)
		    {
		        double dx = (double)xp / (double)xrad;
		        double dy = (double)yp / (double)yrad;
		        if(dx*dx+dy*dy <= 1)
		        	ppBuf->add(col, xp+x,yp+y);
		        	//setpixel(xp+x,yp+y,col);
		    }
	}
}
