/*****************************************************************************
 *   Copyright (C) 2008, 2009 Advanced Concepts Team (European Space Agency) *
 *   act@esa.int                                                             *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************/

// 04/01/2009: Initial version by Francesco Biscani.

#include "../../exceptions.h"
#include "../problems/GOproblem.h"
#include "../algorithms/go_algorithm.h"
#include "archipelago.h"
#include "island.h"

archipelago::archipelago(const GOProblem &p):m_gop(p.clone()) {}

archipelago::archipelago(const GOProblem &p, const go_algorithm &a, int N, int M):m_gop(p.clone())
{
	for (int i = 0; i < N; ++i) {
		push_back(island(p,a,M));
	}
}

archipelago::archipelago(const archipelago &a):m_container(a.m_container),m_gop(a.m_gop->clone())
{
	const iterator it_f = end();
	for (iterator it = begin(); it != it_f; ++it) {
		it->set_archipelago(this);
	}
}

island &archipelago::operator[](int n)
{
	return *it_from_index<iterator>(n);
}

size_t archipelago::size() const
{
	return m_container.size();
}

void archipelago::check_island(const island &isl) const
{
	if (typeid(isl.problem()) != typeid(problem())) {
		pagmo_throw(type_error, "island's problem type is not compatible with archipelago's problem type");
	}
}

void archipelago::push_back(const island &isl)
{
	check_island(isl);
	m_container.push_back(isl);
	m_container.back().set_archipelago(this);
}

void archipelago::insert(int n, const island &isl)
{
	check_island(isl);
	iterator it = it_from_index<iterator>(n);
	m_container.insert(it,isl);
	--it;
	it->set_archipelago(this);
}

const GOProblem &archipelago::problem() const
{
	return *m_gop;
}

void archipelago::join() const
{
	const const_iterator it_f = m_container.end();
	for (const_iterator it = m_container.begin(); it != it_f; ++it) {
		it->join();
	}
}

bool archipelago::busy() const
{
	const const_iterator it_f = m_container.end();
	for (const_iterator it = m_container.begin(); it != it_f; ++it) {
		if (it->busy()) {
			return true;
		}
	}
	return false;
}

void archipelago::evolve(int n)
{
	const iterator it_f = m_container.end();
	for (iterator it = m_container.begin(); it != it_f; ++it) {
		it->evolve(n);
	}
}

void archipelago::evolve_t(const size_t &t)
{
	const iterator it_f = m_container.end();
	for (iterator it = m_container.begin(); it != it_f; ++it) {
		it->evolve_t(t);
	}
}

std::ostream &operator<<(std::ostream &s, const archipelago &a) {
	s << "Problem type:    " << a.m_gop->id_name() << "\n\n";
	const archipelago::const_iterator it_f = a.m_container.end();
	size_t i = 0;
	for (archipelago::const_iterator it = a.m_container.begin(); it != it_f; ++it) {
		s << "Island #:        " << i << '\n';
		s << "ID:              " << it->id() << '\n';
		s << "Population size: " << it->size() << '\n';
		s << "Evolution time:  " << it->evo_time() << '\n';
		s << "Algorithm type:  " << it->algorithm().id_name() << "\n\n";
		++i;
	}
	return s;
}