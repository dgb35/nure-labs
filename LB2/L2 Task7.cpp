#include <iostream>
#include <time.h>
#include <iomanip>
#include <functional>

float** CreateArray(size_t);
void FillArray(float**, size_t, size_t);
void PrintArray(float**, size_t);
void Task(float**, size_t);
void QuickSort(float*, int, int, std::function<bool(float, float)>);
void DeleteArray(float** arr, size_t);

int main()
{
	// Enable random() function
	srand(time(nullptr));
	size_t n;
	// Entering N
	std::cout << "Enter N (values in our array will be random numbers from [-N - 15] to [N + 15]): ";
	std::cin >> n;
	n += 15;

	// Creating array with size K + 10
	float** arr = CreateArray(n);
	//Filling with random numbers
	FillArray(arr, n, n);
	// Printing array on the console
	std::cout << std::endl <<  "Array: " << std::endl;
	PrintArray(arr, n);
	// Printing result of our caluclations
	Task(arr, n);
	
	std::cout << "Array after sorting: " << std::endl;
	// Printing array on the console
	PrintArray(arr, n);
	// Deleting array 
	DeleteArray(arr, n);
}

// Allocating memory for our array
float** CreateArray(size_t size)
{
	float** temp = new float*[size];
	for (size_t i = 0; i < size; i++)
		temp[i] = new float[size];
	return temp;
}

// Filling array with random numbers from [-N-K] to [N+K]
void FillArray(float** arr, size_t range, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			arr[i][j] = (int)(rand() % (2 * range + 1) - range);
}

//Print array
void PrintArray(float** arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
			std::cout << std::setw(4) << arr[i][j] ;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Completing task
void Task(float** arr, size_t size)
{
	float* tmp = new float[size];

	for (size_t j = 0; j < size; ++j)
	{
		for (size_t i = 0; i < size; ++i)
			tmp[i] = arr[i][j];

		// Sorting column of our matrix 
		// Adding lambdas as arguments of our QuickSort function to sort values in necessary order
		if (j % 2 == 0) QuickSort(tmp, 0, size - 1, [](const float& a, const float& b) {return a <= b; });
		else QuickSort(tmp, 0, size - 1, [](const float& a, const float& b) {return a >= b; });

		for (size_t i = 0; i < size; ++i)
			arr[i][j] = tmp[i];
	}

}

// I add a comparator with type std::function<bool(float, float)> to sort array in different orders
void QuickSort(float* arr, int l, int r, std::function<bool(float, float)> compare)
{
	if (l >= r) return;

	size_t position = l - 1;
	for (size_t i = l; i <= r; ++i)
		if (compare(arr[i], arr[r])) // Using our comparator
			std::swap(arr[++position], arr[i]);

	QuickSort(arr, l, position - 1, compare);
	QuickSort(arr, position + 1, r, compare);
}

// Deleting the array to avoid memory leak
void DeleteArray(float** arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		delete[] arr[i];
	delete[] arr;
}