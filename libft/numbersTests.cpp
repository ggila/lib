// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   numbersTests.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/28 17:24:22 by ngoguey           #+#    #+#             //
/*   Updated: 2016/01/30 19:13:23 by ggilaber         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

// compile with -std=c++14 and -lboost_unit_test_framework

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <iostream>
#include <string.h>
#include "libft.h"
BOOST_AUTO_TEST_CASE(first_test)
{
  int i = 1;
  BOOST_TEST(i);
  //  BOOST_TEST(i == 2);
}
namespace bdata = boost::unit_test::data;

BOOST_DATA_TEST_CASE(int8_all, bdata::xrange<int16_t>(
						      (bdata::begin=0, bdata::end=12, bdata::step=1)))
{
  unsigned char buffer[sample];
  unsigned char ref[sample];

  memset(buffer, '1', sample);
  memset(ref, '1', sample);

  memset(ref, 0, sample);
  ft_bzero(buffer, sample);
  BOOST_TEST_CONTEXT("LOL0") {
    BOOST_TEST_CONTEXT("LOL1") {
      BOOST_TEST_INFO("LOL2");
      BOOST_TEST_INFO("LOL3");
      BOOST_TEST(memcmp(ref, buffer, sample) == 0);
    };
  };


  std::cout << sample << "\n";
}

// ------------------------------------------------------------------------------ //

auto const str1 = {
    "", "abcE", "abcd"
};

auto const sizes = {
    0, 1, 2, 3, 4, 5
};

#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
namespace bdata = boost::unit_test::data;

struct BordelFixture
{
    int truc;

};

BOOST_FIXTURE_TEST_SUITE(supersuite, BordelFixture)

BOOST_AUTO_TEST_CASE(noinstr)
{
    truc = 42;
    std::cout << "SALUT" << std::endl;

}

BOOST_DATA_TEST_CASE(
    lol, bdata::make(str1) * bdata::make(str1) * bdata::xrange(5)
    // lol, bdata::make(str1) * bdata::make(str1) * bdata::make(sizes)
    , dst, src, size
    // bdata::xrange<int16_t>(
    //   (bdata::begin=0, bdata::end=12, bdata::step=1))
    )
{

    // truc = 42;

    std::cout
        << '"' << dst << '"' << ", "
        << '"' << src << '"' << ", "
        << '(' << size << ')' << ", "

        <<  std::endl;

}
