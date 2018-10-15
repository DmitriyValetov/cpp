#include <math.h>
#include <iostream>


class C{

	private:
		double re;
		double im;

	public:
		//Constructors
		C(){
			re=0.0;
			im=0.0;
		}
		C(double x, double y){
			re=x;
			im=y;
		}
		C(double x){
			re=x;
			im=0.0;
		}


		//Methods
		double abs(){
			double y=sqrt(re*re+im*im);
			return y;
		}


		//Operators	
		C operator+(const C &x){
			return C(re+x.re,im+x.im);
		}

		C operator+(double &x){
			return C(re+x,im);
		}

		C operator-(const C &x){
			return C(re-x.re,im-x.im);
		}

		C operator-(double &x){
			return C(re-x,im);
		}

		C operator*(const C &x){
			return C(re*x.re-im*x.im,re*x.im+im*x.re);
		}

		C operator*(double &x){
			return C(re*x,im*x);
		}

		friend C operator/(const C &y, const C &x){
			double re2=(y.re*x.re+y.im*x.im)/(x.re*x.re+x.im*x.im);
			double im2=(y.im*x.re-y.re*x.im)/(x.re*x.re+x.im*x.im);
			return C(re2,im2);
		}

		friend C operator/(const C &y, double &x){
			return C(y.re/x,y.im/x);
		}

		friend C operator/(double &x, const C &y){
			double re2=(x*y.re)/(y.re*y.re+y.im*y.im);
			double im2=(x*y.re)/(y.re*y.re+y.im*y.im);
			return C(re2,im2);
		}

		friend C operator/(int &x, const C &y){
			double re2=(x*y.re)/(y.re*y.re+y.im*y.im);
			double im2=(x*y.re)/(y.re*y.re+y.im*y.im);
			return C(re2,im2);
		}

		bool operator==(C &y){
			bool result=false;
			if((re==y.re)&&(im==y.im)){
				result=true;
			}
			return result;
		}

		bool operator!=(C &y){
			bool result=false;
			if((re!=y.re)||(im!=y.im)){
				result=true;
			}
			return result;
		}

		friend std::ostream& operator<<(std::ostream &os, const C &x){
			os<< x.re << (x.im>0 ? '+' : ' ') << x.im << "*i";
			return (os);
		}
};
