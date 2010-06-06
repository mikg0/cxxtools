/*
 * Copyright (C) 2010 Tommi Maekitalo
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * As a special exception, you may use this file as part of a free
 * software library without restriction. Specifically, if other files
 * instantiate templates or use macros or inline functions from this
 * file, or you compile this file and link it with other files to
 * produce an executable, this file does not by itself cause the
 * resulting executable to be covered by the GNU General Public
 * License. This exception does not however invalidate any other
 * reasons why the executable file might be covered by the GNU Library
 * General Public License.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "cxxtools/convert.h"
#include "cxxtools/unit/testsuite.h"
#include "cxxtools/unit/registertest.h"
#include "cxxtools/string.h"

class ConvertTest : public cxxtools::unit::TestSuite
{
    public:
        ConvertTest()
        : cxxtools::unit::TestSuite("cxxtools-convert-Test")
        {
            registerMethod("successTest", *this, &ConvertTest::successTest);
            registerMethod("failTest", *this, &ConvertTest::failTest);
        }

        void successTest()
        {
          std::string s(" -15 ");
          int n = 0;
          CXXTOOLS_UNIT_ASSERT_NOTHROW(n = cxxtools::convert<int>(s));
          CXXTOOLS_UNIT_ASSERT_EQUALS(n, -15);

          cxxtools::String S(L" -42 ");
          CXXTOOLS_UNIT_ASSERT_NOTHROW(n = cxxtools::convert<int>(S));
          CXXTOOLS_UNIT_ASSERT_EQUALS(n, -42);

        }

        void failTest()
        {
          std::string s(" -15 a");
          int n = 0;
          CXXTOOLS_UNIT_ASSERT_THROW(n = cxxtools::convert<int>(s), cxxtools::ConversionError);

          cxxtools::String S(L" -42 a");
          CXXTOOLS_UNIT_ASSERT_THROW(n = cxxtools::convert<int>(S), cxxtools::ConversionError);

        }
};

cxxtools::unit::RegisterTest<ConvertTest> register_ConvertTest;