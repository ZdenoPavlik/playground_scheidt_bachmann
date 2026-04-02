#include <chrono>
#include <iostream>

class Benchmark
{
public:
	void startBenchmark()
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	void stopAndEvaluateBenchmark(const std::string operationName)
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start);

		std::cout << "Operation [" << operationName << "] took " << elapsed << " milliseconds" << std::endl;
	}

	void stopAndEvaluateBenchmarkMicroseconds(const std::string operationName)
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - m_start);

		std::cout << "Operation [" << operationName << "] took " << elapsed << " MICROSECONDS" << std::endl;
	}

private:
	std::chrono::high_resolution_clock::time_point m_start{};
};