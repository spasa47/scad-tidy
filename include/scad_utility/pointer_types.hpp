//
// Created by janm on 26.6.24.
//

#ifndef SCAD_TIDY_POINTER_TYPES_HPP
#define SCAD_TIDY_POINTER_TYPES_HPP

#include <scad_utility/scad_utility_export.h>
namespace SCAD_UTILITY_EXPORT scad_utility
{
  template<typename T>
  using ptr = T *;
}
#endif  // SCAD_TIDY_POINTER_TYPES_HPP
