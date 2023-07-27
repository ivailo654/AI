#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float train[][2] = {
	{0,0},
	{1,2},
	{2,4},
	{3,6},
	{4,8},
};// given inputs (0,1,2,3,4)  expected outputs(0,2,4,6,8)
int trainCount = sizeof(train) / sizeof(train[0]);
float randfloat() {
	return (float)rand() / (float)RAND_MAX;
}
float cost(float w) {
	float result = 0.0f;
	for (size_t i = 0; i < trainCount; i++)
	{
		float x = train[i][0];
		float y = x * w;
		float d = y - train[i][1];
		result += d * d;
	}
	return result / trainCount;
}
//y=x*w
int main() {
	srand(69);
	float w = randfloat() * 10.0f;
	float eps = 1e-3;
	printf(" % f\n", cost(w));
	//printf(" % f", cost(w + eps));
	for (int i = 0; i < 500; i++) {
		float dcost = (cost(w + eps) - cost(w)) / eps;
		w -= eps * dcost;
		printf(" % f \n", cost(w));
	}
	printf("-----------------\n");
	printf("%f", w);// => y=x*2
	return 0;
}