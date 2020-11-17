#include <iostream>
#include <algorithm>

int main()
{
	const int size = 6; // Amount of segments (We can change this value)

	int segments[size]; // Create segments
	double p; // Semi-perimeter for calculations

	while (true) // Loop out program
	{
		std::cout << "Please enter " << size << " segments:" << std::endl;

		for (int i = 0; i < size; i++)
			std::cin >> segments[i]; // Enter the segments

		system("CLS"); // Clean up our console for a better view

		std::sort(segments, segments + size); // Sort array of segments

		for (int i = 0; i < size - 2; i++)
		{
			if (segments[i] + segments[i + 1] > segments[i + 2]) // Сheck our possible triangle
			{
				p = (segments[i] + segments[i + 1] + segments[i + 2]) / 2.0; // Calculate semi-perimeter
				std::cout << "The area of triangle is: " << sqrt(p * (p - segments[i]) * (p - segments[i + 1]) * (p - segments[i + 2])) << std::endl; // Display area of triangle
			}
		}
		std::cout << std::endl;

		system("PAUSE"); // Pause console for user
		system("CLS"); // Clean console
	}

	return 0;
}
