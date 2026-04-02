#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include "NamedClass.hpp"
#include "Benchmark.hpp"

// cls ; cmake --build build --parallel ; .\build\chapter_edu_03_containers\chapter_edu_03_containers.exe

std::vector<NamedClass> container;
const uint16_t numberOfElements{10000};
// const uint16_t numberOfElements{32768}; // 2 na 15, //32768

void addElementsIntoContainer()
{
	for(uint16_t i = 0; i < numberOfElements; i++)
	{
		container.emplace_back("testObject" + std::to_string(i));
	}
}

void iterateOverElementsInContainer()
{
	for(auto& i : container)
	{
		i.whoAmI();
	}
}

// Primary template (generic implementation for random-access containers)
template <typename T>
void randomAccessLastElement(T& cont)
{
	const auto elementIndex{cont.size() - 1};

	if constexpr(std::is_same_v<T, std::vector<NamedClass>>)
	{
		// Vector: O(1) random access
		if(elementIndex < cont.size())
		{
			cont[elementIndex].whoAmI();
		}
	}
	else if constexpr(std::is_same_v<T, std::deque<NamedClass>>)
	{
		// Deque: O(1) random access
		if(elementIndex < cont.size())
		{
			cont[elementIndex].whoAmI();
		}
	}
	else if constexpr(std::is_same_v<T, std::list<NamedClass>>)
	{
		// List: O(n) - must iterate to find element
		if(elementIndex < cont.size())
		{
			auto it = std::begin(cont);
			std::advance(it, elementIndex);
			it->whoAmI();
		}
	}
}

template <typename T>
void addElementToTheMiddle(T& cont)
{
	const long long middleElementIndex = cont.size() / 2;

	if constexpr(std::is_same_v<T, std::vector<NamedClass>> || std::is_same_v<T, std::deque<NamedClass>>)
	{
		// Vector and Deque: O(n) insert in middle
		cont.insert(cont.begin() + middleElementIndex, NamedClass{"Middle class"});
	}
	else if constexpr(std::is_same_v<T, std::list<NamedClass>>)
	{
		// List: O(1) insert if iterator known, O(n) here due to finding position
		auto it = std::begin(cont);
		std::advance(it, middleElementIndex);
		cont.insert(it, NamedClass{"Middle class"}); // Insert before iterator
	}
}

int main()
{
	// VECTOR
	// container.reserve(numberOfElementsGlobal*2);
	//  #1 Vector has to grow. Use .reserve function
	// container.at(2).whoAmI();

	// LIST

	NamedClass obj1{"Object 1"};
	container.push_back(obj1);

	std::cout << "---------------" << std::endl;
	NamedClass obj2{"Object 2"};
	container.push_back(obj2);

	std::cout << "---------------" << std::endl;
	NamedClass obj3{"Object 3"};
	container.push_back(obj3);

	std::cout << "---------------" << std::endl;
	Benchmark benchmark;
	benchmark.startBenchmark();
	addElementsIntoContainer();
	benchmark.stopAndEvaluateBenchmark("Creating");

	benchmark.startBenchmark();
	iterateOverElementsInContainer();
	benchmark.stopAndEvaluateBenchmarkMicroseconds("Iterating");

	benchmark.startBenchmark();
	randomAccessLastElement(container);
	benchmark.stopAndEvaluateBenchmarkMicroseconds("Accessing to last element");

	benchmark.startBenchmark();
	addElementToTheMiddle(container);
	benchmark.stopAndEvaluateBenchmarkMicroseconds("Adding element in the middle");

	std::cout << "---------------" << std::endl;

	return 0;
}
