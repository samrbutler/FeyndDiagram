#pragma once

#include "Grouping.h"
#include "Interactions.h"
#include "Model.h"
#include "Particle.h"
#include "Vertex.h"

#include <iostream>
#include <iterator>
#include <vector>

//Define a class for a diagram
class Diagram
{
protected:

	//External particles
	std::vector<Particle> m_externs;
	//Internal vertices
	std::vector<Vertex> m_vertices;

public:

	//Return the external particles
	const std::vector<Particle>& getExterns() const { return m_externs; }
	//Return the vertices of the diagram
	const std::vector<Vertex>& getVertices() const { return m_vertices; }

	//Default constructor of any empty diagram
	Diagram() = default;

	//Construct a diagram from a vector of particles
	Diagram(const std::vector<Particle>& externs) : m_externs{ externs }, m_vertices{ } {}

	Diagram(const std::vector<Particle>& externs, const Vertex& vertex);

	virtual ~Diagram() {}

	//Add a vertex to the diagram
	void addVertex(const Vertex& vert) { m_vertices.push_back(vert); }

	void addVertices(const std::vector<Vertex>& verts);

	bool isVertex(const n0dict& dictionary = Model::n_to_0) const;

	Diagram& cleanup();

};

std::ostream& operator<<(std::ostream& out, const Diagram& diag);