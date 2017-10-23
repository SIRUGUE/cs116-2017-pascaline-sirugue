#include <iostream>
#include "neuron.hpp"
#include "gtest/gtest.h"

TEST (NeuronTest, MembranePotential) {
Neuron neuron (1.0) ; 
neuron.updateMembranePotential();

EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), neuron.getMembranePotential());
}

int main (int argc, char **arg) {
	::testing :: InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS(); 
	}
