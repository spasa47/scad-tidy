//
// Created by janm on 13.7.24.
//

#ifndef SCAD_TIDY_COMBINE_ENUM_HPP
#define SCAD_TIDY_COMBINE_ENUM_HPP
#include <gsl/gsl>
#include <scad_utility/scad_utility_export.h>
#include <variant>
namespace SCAD_UTILITY_EXPORT scad_utility
{
  template<typename... Enums>
  class CombineEnum
  {
   public:
    constexpr CombineEnum() = default;

    template<typename EnumT>
      requires( std::is_same_v<EnumT, Enums> || ... )
    constexpr explicit CombineEnum( EnumT p_enum ) : m_enum( p_enum )
    {
    }


   private:
    std::variant<Enums...> m_enum;
  };

}  // namespace SCAD_UTILITY_EXPORT scad_utility

#endif  // SCAD_TIDY_COMBINE_ENUM_HPP
