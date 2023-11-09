/*
Steering Problem
  
A controls engineer has collected test data for a black box steering system to
determine the amount of voltage that needs to be applied to hold the vehicle at a
given steering angle. The data below shows that the voltage (V)
required is a function of the steering angle (a).
  
Test Data:
a = -22,  -11, 0, 10,  20 degrees
V = -1.5, -1,  0, 1.2, 1.8 volts
  
The controls engineer would like to use this data as a feed forward term for the
steering controller. Your job is to write a function to determine
the best estimate for voltage (V) given a steering angle (a). aka. V = f(a).
 
Example output:
For a = 10; V = 1.2
For a = 5; V = 0.6
For a = 15; V = 1.5

This problem uses a unit test framework called Catch. Use the example tests at the
bottom of the file to test voltageEstimate, and feel free to add your own as well.
*/

// Unit testing framework
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Standard includes
#include <iostream>
#include <stdint.h>

float voltageEstimate(const float a, const float* a_data, const float* v_data, const int size) {
  // Need to find where a is located inside a_data
  //Can we imply that a_data[]  is always in order
  // is a contained?  in the array? if not answer undefined?
  
  // if (i == 0 && a_data[i] > a) {
  //     return 0;//unknown?
  //   } else {

  //   }
  for (int i =0; i< size; i++) {
    if (a_data[i] == a) {
      printf("%d %f", i, a_data);
      return v_data[i];
    } else {
      if (i < size-1 && a_data[i+1] < a) {
        // we can calculate the proportion
        float angle_proprotion = (a_data[i+1] - a)/(a_data[i+1] - a_data[i]),
        voltage_delta = angle_proprotion * (v_data[i+1] - v_data[i]); 
        return  v_data[i] + voltage_delta;
      }
    }
      
  }
}

TEST_CASE( "Steering Problem Test" ) {
  const float a_data[]  =  {-22,  -11, 0, 10,  20}; // x-axis data
  const float v_data[] =   {-1.5, -1,  0, 1.2, 1.8}; // y-axis data
  const int size = 5;
  float a, v_expected, v_test;

  SECTION( "Example 1" ) {
    // input angle
    a = 10.0;
    // expected output voltage
    v_expected = 1.2;
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  SECTION( "Example 2" ) {
    // input angle
    a = 15.0;
    // expected output voltage
    v_expected = 1.5;
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }

SECTION( "Example 3" ) {
    // input angle
    a = 55.0;
    // expected output voltage
    v_expected = 1.8;
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }



SECTION( "Example 3" ) {
    // input angle
    a = 55.0;
    // expected output voltage
    v_expected = 0;
    // call function under test
    v_test = voltageEstimate(a, {}, {}, 0);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }


SECTION( "Example 4" ) {
    // input angle
    a = 55.0;
    // expected output voltage
    v_expected = 0; // an exception?
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, 25);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }


SECTION( "Example 5" ) {
    // input angle
    a = 55.0;
    // expected output voltage
    v_expected = 0; // an exception?
    // call function under test
    v_test = voltageEstimate(-23, a_data, v_data, 25);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  // TODO: Add any new test sections here
}
