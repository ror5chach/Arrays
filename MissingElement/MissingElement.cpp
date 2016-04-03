#include "MissingElement.h"




int FindMissingNumber(int* arr, int len)
{
	int sum = 0;
	for (int i = 0; i < len; ++i)
		sum += arr[i];

	int nums = len + 1;
	int expected = nums * (nums + 1) / 2;
	
	return (expected - sum);
}


vector<int> FindMissingNumbers(vector<int> input)
{
	vector<int> result;
	int nums = 10;
	bitset<11> myBitset;			// initialized to 0, by default
	
	for (int i = 0; i < (int)input.size(); ++i)
		myBitset[input[i]] = 1;
	// cout << myBitset << endl;

	// find number of elements in input array
	int inputNums = myBitset.count();
	int missingNums = nums - inputNums;
	cout << missingNums << " elements missing" << endl;

	for (int i = 1; i <= nums; ++i)
	{
		if (!myBitset.test(i))
			result.push_back(i);
	}
	return result;
}




int main()
{
	int arr[9] = { 1,2,3,4,5,7,8,9,10 };
	int length = 9;

	int result = FindMissingNumber(arr, 9);
	cout << result << endl;

	cout << endl;
	vector<int> nums = { 10,6,5,3,1,2 };
	vector<int> res = FindMissingNumbers(nums);
	for (int i = 0; i < (int)res.size(); ++i)
		cout << res[i] << " ";
	cout << endl;

	getchar();
	return 0;
}