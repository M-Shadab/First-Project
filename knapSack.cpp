#include <iostream>
using namespace std;

//0-1 Knapsack :: Pick(=1)  and Not pick(=0)
int knapsack(int value[], int weight[], int size, int wt, int val){
	//No value is left or Knapsack wt is 0 or become 0
	if(size == 0 || wt == 0)	return val;

	//1. Pick 0th value if possible 1: case
	int defaultPossibleAns1 = INT_MIN;
	if(wt - weight[0] >= 0){
		defaultPossibleAns1 = knapsack(value + 1, weight + 1, size - 1, wt - weight[0], val + value[0]);
	}

	//2. don't pick 0th value 0:Case
	int ans2 = knapsack(value + 1, weight + 1, size - 1, wt, val);

	//return max of two options from ans1 or ans2
	return max(ans1, ans2);
}

int main(){
	int value[] = {60, 100, 120, 230};
	int weight[] = {10, 20, 30, 100};
	int wt = 50;

	int maxValue = knapsackNaive(value, weight, 3, wt, 0);
	
	cout << maxValue << endl;
	
	return 0;
}