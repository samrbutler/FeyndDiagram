/*Loops.h :
*
*/

#pragma once

#include "Diagram.h"
#include "Model.h"
#include "Interactions.h"

#include <set>

struct LoopyVertex {
	std::multiset<P> external_particles_in;
	std::multiset<P> external_particles_out;
	std::multiset<P> internal_particles;
	std::multiset<std::multiset<P>> internal_connections;
	int num_loops;

	bool is_null{ false };
};

static inline const LoopyVertex LV_null{ {},{},{},{},0,true };

class LoopDiagram : public Diagram {

public:
	LoopDiagram(const Diagram& diag) : Diagram(diag) {}

	LoopDiagram(const std::vector<Particle>& externs) : Diagram(externs) {}

	LoopDiagram(const std::vector<Particle>& externs, const Vertex& vertex) : Diagram(externs, vertex) {}

	//Override function connect to include connection with loops

	void addLoopyVertex(const LoopyVertex& lv, const std::vector<Particle>& inbound_parts);
};

bool operator==(const LoopyVertex& lv1, const LoopyVertex& lv2);

std::vector<LoopyVertex> getLoopyVertices(const int max_loops, const loopdict& dictionary = Model::n_to_many);

std::vector<int> getLoopSignature(const std::vector<Particle>& inbound);

std::vector<int> invertLoopSignature(const std::vector<int>& sig);

namespace Model {
	inline const std::vector<LoopyVertex> loopy_vertices{ getLoopyVertices(Model::max_legs) };
}

/*List of pairs containing:
*	std::multiset<P> - the new outbound particle types
*	LoopyVertex   - pointer to the LoopyVertex responsible (or nullptr if not)
*/

using newloopprofiles = std::vector<std::pair<std::multiset<P>, LoopyVertex>>;
using newloopvalues = std::vector<std::pair<std::vector<Particle>, LoopyVertex>>;

newloopvalues spawnLoops(const std::vector<Particle>& inbound, const int max_loops, const std::vector<LoopyVertex>& loopyvs = Model::loopy_vertices);

std::vector<LoopDiagram> connect1PI(const LoopDiagram& diag, const int num_loops, const std::vector<LoopyVertex>& loopyvs = Model::loopy_vertices,
	const n0dict& nto0 = Model::n_to_0, const n1dict& nto1 = Model::n_to_1, const bool debug = false);

std::vector<LoopDiagram> connectSubdiagram(LoopDiagram& diag, const int num_loops, const std::vector<LoopyVertex>& loopyvs = Model::loopy_vertices,
	const n0dict& nto0 = Model::n_to_0, const n1dict& nto1 = Model::n_to_1, const bool debug = false);

std::vector<LoopDiagram> connectZero(LoopDiagram& diag, const n0dict& nto0 = Model::n_to_0, const n1dict& nto1 = Model::n_to_1, const bool debug = false);