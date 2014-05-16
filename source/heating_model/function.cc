/*
  Copyright (C) 2011 - 2014 by the authors of the ASPECT code.

  This file is part of ASPECT.

  ASPECT is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  ASPECT is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with ASPECT; see the file doc/COPYING.  If not see
  <http://www.gnu.org/licenses/>.
*/
/*  $Id$  */


#include <aspect/heating_model/function.h>
#include <aspect/global.h>

namespace aspect
{
  namespace HeatingModel
  {
    template <int dim>
    Function<dim>::Function ()
      :
      heating_model_function (1)
    {}



    template <int dim>
    double
    Function<dim>::
    specific_heating_rate (const double,
        const double,
        const std::vector<double> &,
        const Point<dim> &p) const
    {
      return heating_model_function.value(p);
    }


    template <int dim>
    void
    Function<dim>::update ()
    {
      const double time = this->get_time();
      // we get time passed as seconds (always) but may want
      // to reinterpret it in years
      if (this->convert_output_to_years())
        heating_model_function.set_time (time / year_in_seconds);
      else
        heating_model_function.set_time (time);
    }


    template <int dim>
    void
    Function<dim>::declare_parameters (ParameterHandler &prm)
    {
      prm.enter_subsection("Heating model");
      {
        prm.enter_subsection("Function");
        {
          Functions::ParsedFunction<dim>::declare_parameters (prm, dim);
        }
        prm.leave_subsection();
      }
      prm.leave_subsection();
    }


    template <int dim>
    void
    Function<dim>::parse_parameters (ParameterHandler &prm)
    {
      prm.enter_subsection("Heating model");
      {
        prm.enter_subsection("Function");
        {
          heating_model_function.parse_parameters (prm);
        }
        prm.leave_subsection();
      }
      prm.leave_subsection();
    }

  }
}

// explicit instantiations
namespace aspect
{
  namespace HeatingModel
  {
    ASPECT_REGISTER_HEATING_MODEL(Function,
                                                 "function",
                                                 "Implementation of a model in which the heating "
                                                 "rate is given in terms of an explicit formula "
                                                 "that is elaborated in the parameters in section "
                                                 "``Heating model|Function''. "
                                                 "\n\n"
                                                 "The formula is interpreted as having units "
                                                 "W/kg."
                                                 "\n\n"
                                                 "Since the symbol $t$ indicating time "
                                                 "may appear in the formulas for the heating rate"
                                                 ", it is interpreted as having units "
                                                 "seconds unless the global parameter ``Use "
                                                 "years in output instead of seconds'' is set.")
  }
}
