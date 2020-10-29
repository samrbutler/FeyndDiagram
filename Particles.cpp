/*Particles.cpp :
*/

#include "Particles.h"

#include "Model.h"

#include <iostream>
#include <vector>

//Initialise the unique point ID counter
int Point::next_id{ 0 };

Particle Particle::addLoop(const std::vector<int> loop_ids) {
	for (const int loop_id : loop_ids) {
		std::vector<int>::iterator loc{ std::find(m_loops.begin(),m_loops.end(), -loop_id) };
		if (loc == m_loops.end()) m_loops.push_back(loop_id);
		else m_loops.erase(loc);
	}
	return *this;
}

Particle Particle::setActive(const bool act) {
	m_active = act;
	return *this;
}

Particle Particle::toggleAntiPart() {
	m_ptype = getAntiParticle(m_ptype);
	return *this;
}

//Overload operator< to compare point IDs
bool operator<(const Point& point1, const Point& point2) { return (point1.getID() < point2.getID()); }
//Overload operator> to compare point IDs
bool operator>(const Point& point1, const Point& point2) { return (point1.getID() > point2.getID()); }
//Overload operator== to compare point IDs
bool operator==(const Point& point1, const Point& point2) { return (point1.getID() == point2.getID()); }
//Overload operator!= to compare point IDs
bool operator!=(const Point& point1, const Point& point2) { return (point1.getID() != point2.getID()); }

//Overload operator < to sort particle vectors by their first elements
bool operator<(const std::vector<Particle>& vec1, const std::vector<Particle>& vec2) { return (vec1[0] < vec2[0]); }

//Overload inequality operator for particle vectors
bool operator!=(const std::vector<Particle>& part1, const std::vector<Particle>& part2) {
	//Return unequal if there are different numbers of particles
	if (part1.size() != part2.size()) return true;

	//Return unequal if any of the particles are different
	for (size_t i{}; i < part1.size(); ++i) {
		if (part1[i] != part2[i]) return true;
	}

	//They must now be equal
	return false;
}
