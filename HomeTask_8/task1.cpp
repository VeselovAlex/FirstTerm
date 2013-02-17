#include <iostream>

void bubbleSort(int *arr, int &size)
{
	for (int i = 0; i < size; i++)
		for (int j = 1 ; j < size - i; j++)
			if (arr[j-1] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr [j - 1];
				arr[j - 1] = temp;
			}
}

int main()
{
	const int multi =13;
	
	int size = 0;
	std::cout << "Enter the size of array: \n";
	std::cin >> size;
	int *myArray = new int[size];
	
	std::cout << "Enter the first number: \n";
	std::cin >> myArray[0];
	std::cout << "Unsorted array: \n";
	std::cout << myArray[0] << " ";

	for (int i = 1; i < size; i++)
	{
		myArray[i] = (myArray[i-1] * multi) % 100;
		std::cout << myArray[i] << " "; 
	}

	bubbleSort(myArray,size);
	
	std::cout << "\nSorted array: \n";
	for (int i = 0; i < size; i++)
		std::cout << myArray[i] << " ";
	
	std::cin >> size;
	delete[] myArray;
}