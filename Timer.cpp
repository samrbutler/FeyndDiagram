#include "Timer.h"

double Timer::elapsed() const
{
	return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}

void Timer::lap(std::string prefix) {
	double time{ elapsed() };
	std::cout << prefix << time << std::endl;
	reset();
}