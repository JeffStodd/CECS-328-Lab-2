//Jeffrey Stoddard
//CECS 328
//Lab 2

#include <iostream>

//Question 1: Estimate square root of n
void squareRoot()
{
	long int n = 0;
	std::cout << "Please enter a positive integer to estimate the square root of: ";
	std::cin >> n;

	long int low = 0;
	long int high = n;
	long int mid;
	bool found = false;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (mid * mid == n)
		{
			std::cout << "Result: " << mid << std::endl;
			found = true;
			break;
		}
		else if (mid * mid > n)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	if (!found)
	{
		if (mid * mid < n)
		{
			std::cout << "Result: " << double(mid + mid + 1) / 2 << std::endl;
		}
		else std::cout << "Result: " << double(mid + mid - 1) / 2 << std::endl;
	}

}

int *arr;
long int size = 0;
long int zeros = 0;

void InitArray()
{
	std::cout << "Please enter a positive integer for the array size: ";
	std::cin >> size;
	std::cout << size;
	arr = new int[size];
	std::cout << "Please enter a positive integer for the number of zeros: ";
	std::cin >> zeros;

	for (int i = 0; i < zeros; i++)
	{
		arr[i] = 0;
	}
	for (int i = zeros; i < size; i++)
	{
		arr[i] = 1;
	}
}

//Question 2: Locate index of break in binary array
void binaryArrSplit()
{
	InitArray();
	long int low = 0;
	long int mid;
	long int high = size - 1;
	bool found = false;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == 1 && arr[mid - 1] == 0)
		{
			std::cout << "Result: " << mid << std::endl;
			found = true;
			break;
		}
		else if (arr[mid] == 0)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	if (!found)
		std::cout << "No break found!" << std::endl;
}

int main()
{
	std::cout << "Testing Question 1:" << std::endl;
	squareRoot();
	std::cout << "Testing Question 2:" << std::endl;
	binaryArrSplit();
	system("pause");
	return 0;
}