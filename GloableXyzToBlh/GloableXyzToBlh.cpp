// GloablexyzToblh.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

const double  LONG_RADIUS =6378137;//单位m
const double  SHORT_RADIUS=6356752.3142;//m
const double  E_SQUARE=0.00669437999013;
const double  PI      =3.14159265358979;

int main(int argc, char* argv[])
{
	double x,y,z;
	double l,b,h,b0,R,N;
	printf("input the x of coordinate!\n");
	scanf("%lf",&x);
	printf("input the y of coordinate!\n");
	scanf("%lf",&y);
	printf("input the Z of coordinate!\n");
	scanf("%lf",&z);

	//根据xy值确定经度的角度值
	if( x > 0 )
		l = atan(y / x);
	else if( x < 0 )
		l = atan(y / x) + PI;
	else if( (x == 0) & (y > 0) )
		l = PI / 2;
	else if( (x == 0) & (y < 0) )
		l = - PI / 2;
	else
		l = 0;
	//
	R=sqrt(x*x+y*y);
	b0=atan(z/R);
    while(1)//迭代法	迭代公式：??
	{
		N = LONG_RADIUS/ sqrt(1 - E_SQUARE* sin(b0) * sin(b0));		
		b = atan((z + N * E_SQUARE * sin(b0)) / R);
		
		if(fabs(b - b0) <= 0.000001)
			break;
		b0=b;
	}
	h = R/ cos(b0) - N;

	l = l*180.0/PI;
	b = b*180.0/PI;

	printf("The longitude is %lf \n",l);
	printf("The  latitude is %lf \n",b);
	printf("The  height   is %lf \n",h);


	return 0;
}

