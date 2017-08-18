// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_TRAITS_ALWAYS_STRING_VIEW_HPP
#define TAOCPP_JSON_INCLUDE_TRAITS_ALWAYS_STRING_VIEW_HPP

#include "traits.hpp"

namespace tao
{
   namespace json
   {
      template< typename T, typename = void >
      struct traits_always_string_view
         : traits< T >
      {
      };

      template<>
      struct traits_always_string_view< std::string >
         : traits< std::string >
      {
         template< template< typename... > class Traits >
         static void assign( basic_value< Traits >& v, const string_view sv )
         {
            v.unsafe_assign_string_view( sv );
         }
      };

      template<>
      struct traits_always_string_view< string_view >
         : traits< string_view >
      {
         template< template< typename... > class Traits >
         static void assign( basic_value< Traits >& v, const string_view sv )
         {
            v.unsafe_assign_string_view( sv );
         }
      };

   }  // namespace json

}  // namespace tao

#endif
