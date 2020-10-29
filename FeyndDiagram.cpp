/*FeyndDiagram.cpp
* 
*/

#include "FeyndDiagram.h"

#include "Diagram.h"
#include "Groups.h"
#include "Interactions.h"
#include "Loops.h"
#include "Model.h"
#include "Particles.h"
#include "Timer.h"

#include <iostream>
#include <set>

int main()
{

	//TEST CODE

	Particle p1{ P::phi };
	Particle p2{ P::phi };

	Timer t;
	auto returns{ connect1PI(std::vector<Particle> {p1, p2},1) };
	auto time{ t.elapsed() };

	for (LoopDiagram& ld : returns) {
		std::cout << ld << '\n';
	}

	std::cout << "\n\nCompleted in " << time << " seconds.\n\n";
}