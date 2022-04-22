/*****************************************************************************

      Pot.h
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/FloatRange.h"



namespace erb
{



template <FloatRange Range>
class Pot
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   static constexpr float ValueMin = FloatRangeTrait <Range>::Min;
   static constexpr float ValueMax = FloatRangeTrait <Range>::Max;

   inline         Pot (const float & data);
   virtual        ~Pot () = default;

   inline         operator float () const;



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   const float &  impl_data;
   inline void    impl_preprocess () {}
   inline void    impl_postprocess () {}



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

protected:



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Pot () = delete;
                  Pot (const Pot & rhs) = delete;
                  Pot (Pot && rhs) = delete;
   Pot &          operator = (const Pot & rhs) = delete;
   Pot &          operator = (Pot && rhs) = delete;
   bool           operator == (const Pot & rhs) const = delete;
   bool           operator != (const Pot & rhs) const = delete;



}; // class Pot



}  // namespace erb



#include "erb/Pot.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
