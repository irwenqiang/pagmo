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

#ifndef PAGMO_ALGORITHMS_H
#define PAGMO_ALGORITHMS_H

// Header including all algorithms implemented in PaGMO.

#include "algorithm/base.h"
#include "algorithm/cs.h"
#include "algorithm/de.h"
#include "algorithm/ihs.h"
#include "algorithm/monte_carlo.h"
#include "algorithm/null.h"
#include "algorithm/pso.h"
#include "algorithm/sa_corana.h"
#include "algorithm/sga.h"


//SNOPT algorithm
#ifdef PAGMO_ENABLE_SNOPT
#include "algorithm/snopt.h"
#endif

// GSL algorithms.
#ifdef PAGMO_ENABLE_GSL
	#include "algorithm/base_gsl.h"
	#include "algorithm/gsl_bfgs.h"
	#include "algorithm/gsl_bfgs2.h"
	#include "algorithm/gsl_fr.h"
	#include "algorithm/gsl_nm.h"
	#include "algorithm/gsl_pr.h"
#endif

#endif