/*****************************************************************************
 *   Copyright (C) 2004-2009 The PaGMO development team,                     *
 *   Advanced Concepts Team (ACT), European Space Agency (ESA)               *
 *   http://apps.sourceforge.net/mediawiki/pagmo                             *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Developers  *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Credits     *
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

#include <iostream>
#include "src/pagmo.h"

using namespace pagmo;

int main()
{
// This instantiates a differential evolution algorithm that will run for 500 generations. Refer to the documentation to
// see what othert parameters do
pagmo::algorithm::de algo(500,0.8,0.8,3);

//This instantiate a 50 dimensional Rosenbrock problem
pagmo::problem::rosenbrock prob(10);

//This instantiate an island containing a population of 20 individuals initialized at random and having their fitness evaluated
//with respect to the Schwefel problem. The island will evolve its population using the instantiated algorithm
pagmo::island isl = island(algo,prob,20);

//This prints on screen the instantiated Rosenbrock problem
std::cout << prob << std::endl;

//Evolution is here started on the single island instantiated
for (int i=0; i< 200; ++i){
	isl.evolve();
	isl.join();
	std::cout << isl.get_population().champion().f[0] << " " << std::endl;
}

return 0;
}
