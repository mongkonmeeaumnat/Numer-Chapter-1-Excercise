#include<stdio.h>
#include<math.h>

// Function Declaration
double F(double x) ;
 
// main function
int main() {
	int n ; printf("Input Number of range\n");
	scanf("%d",&n) ;
	if(n > 10000) {
    	printf("Maximum n is 10000\n");
    	return 1;
    	
	} 
	if(n%2 == 1) {
		printf("n must be an even integer");
		return 2;
	}
	
	double a , b , x[10001] , fx[10001] , ex ;
	printf("Input Value of x(0) and x(n)\n") ;
	scanf("%lf %lf",&a,&b);
	printf("Input Exact Value\n") ;
	scanf("%lf",&ex) ;
	double h = (b - a) / n ;
	for(int i=0;i<=n;i++) {
		x[i] = a + i*h ; // compute x(i) ;
	}
	for(int i=0;i<=n;i++) {
		fx[i] = F(x[i]) ; // compute f(x) ;
	}
	double sum1 = 0 ; // compute 4*(fx(1) to fx (n-1) ) ;
	for(int i=1;i<n;i+=2) {
		sum1 += 4 * fx[i] ;
	}
	double sum2 = 0 ; // compute 2*(fx(2) to fx (n-2) ) ;
	for(int i=2;i<n-1;i+=2) {
		sum2 += 2 * fx[i] ;
	}
	
	double I = h/3.0 * (fx[0] + fx[n] + sum1 + sum2 ) ;
	printf("I = %lf\n",I);
	
	double e = ( ( ex - I ) / ex ) * 100;
	printf("Error is %lf percentage",e) ;
	
}
 
// Function Definition 
double F(double x) {
 	x = pow(x,7) + 2*pow(x,3) - 1 ;
 	return x ;
 }
