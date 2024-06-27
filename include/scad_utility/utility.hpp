//
// Created by janm on 26.6.24.
//

#ifndef SCAD_TIDY_UTILITY_HPP
#define SCAD_TIDY_UTILITY_HPP

#include <scad_utility/scad_utility_export.h>
#include <tuple>
#include <utility>
namespace SCAD_UTILITY_EXPORT scad_utility
{
  template<class T, std::size_t N>
  concept has_tuple_element = requires( T t ) {
    typename std::tuple_element_t<N, std::remove_const_t<T>>;
    {
      get<N>( t )
    } -> std::convertible_to<const std::tuple_element_t<N, T> &>;
  };

  template<class T>
  concept tuple_like = !std::is_reference_v<T> && requires( T t ) {
    typename std::tuple_size<T>::type;
    requires std::derived_from<std::tuple_size<T>,
                               std::integral_constant<std::size_t, std::tuple_size_v<T>>>;
  } && []<std::size_t... N>( std::index_sequence<N...> ) {
    return ( has_tuple_element<T, N> && ... );
  }( std::make_index_sequence<std::tuple_size_v<T>>() );
}  // namespace SCAD_UTILITY_EXPORT scad_utility
#endif  // SCAD_TIDY_UTILITY_HPP
