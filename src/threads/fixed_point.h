#define F (1 << 14) // fixed point 1
#define INT_MAX ((1 << 31) -1)
#define INT_MIN (-(1<<31))

//x and y denote fixed_point number in 17.14 format
// n is an integer

int int_to_fp(int n);		/* changing integer to fixed point */
int fp_to_int_round(int x);     /* Converting FP to integer (round up) */
int fp_to_int(int x);		/* Converting FP to integer (round down) */
int add_fp(int x,int y);	/* adding of FP */
int add_mixed(int x,int n);	/* adding FP with integer */
int sub_fp(int x,int y);	/* substracting of FP (x - y) */
int sub_mixed(int x,int n);	/* substracting FP with integer (x-n) */
int mult_fp(int x,int y);	/* multiplying FPs */
int mult_mixed(int x,int y);	/* multiplying FPs and integer */
int div_fp(int x,int y);	/* dividing fps (x/y) */
int div_mixed(int x,int b);	/* dividing FPs (x/n) */


int int_to_fp(int n){
	return n * F;
}
int fp_to_int_round(int x){
	if(x >= 0) return (x + F/2) /F;
	else return (x - F/2)/F;
}
int fp_to_int(int x){
	return x / F;
}
int add_fp(int x,int y){
	return x + y;
}
int add_mixed(int x,int n){
	return x+int_to_fp(n);	
}
int sub_fp(int x,int y){
	return x - y;
}
int sub_mixed(int x,int n){
	return x-int_to_fp(n);
}
int mult_fp(int x,int y){
	return ((long long)x) * y /F;
}
int mult_mixed(int x,int y){
	return mult_fp(x,int_to_fp(y));
}
int div_fp(int x,int y){
	return (long long)x * F / y;
}
int div_mixed(int x,int b){
	return x/b;
}

