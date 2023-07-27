#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int train[][3] = {
	{0,0,0},//OR gate (X1,X2,Y)
	{0,1,1},
	{1,0,1},
	{1,1,1}
};
float randfloat() {
	return (float)rand() / (float)RAND_MAX;
}
float sigmoidf(float x) {
	return 1.f /( 1.f + expf(-x));
}
float cost(float w1, float w2,float b) {
	float result = 0.0f;
	int count = sizeof(train) / sizeof(train[0]);
	for (size_t i = 0; i < count; i++) {
		float x1 = train[i][0];
		float x2 = train[i][1];
		float y = sigmoidf(x1 * w1 + x2 * w2+ b);
		float d = y - train[i][2];
		result += d * d;
	}
	return result / count;
}
int main() {
	srand(time(0));
	float w1 = randfloat();
	float w2 = randfloat();
	float b = randfloat();//bias
	float eps = 1e-1;
	for (size_t i = 0; i < 10000; i++) {
		float c = cost(w1, w2,b);
		printf("w1= %f      w2 = %f      bias = %f  cost =%f \n", w1, w2,b,c);
		
		float dw1 = (cost(w1 + eps, w2,b) - c) / eps;
		float dw2 = (cost(w1, w2 + eps,b) - c) / eps;
		float db = (cost(w1, w2, b+eps ) - c) / eps;
		w1 -= eps * dw1;
		w2 -= eps * dw2;
		b -= eps * db;
		c = cost(w1, w2,b);
		printf("THE NEW w1= %f      w2 = %f   bias =%f cost  = %f\n", w1, w2,b ,c);
	}
	for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < 2; j++) {
			printf("%zu | %zu | %f\n", i, j, sigmoidf(i * w1 + j * w2+b));
		}
	}
	return 0;
}