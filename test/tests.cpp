// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include <Automata.h>


TEST(test, On_test) {
    Automata test = Automata();
    test.on();
    EXPECT_EQ(states::Wait, test.getState());
}

TEST(test, Off_test) {
    Automata test = Automata();
    test.on();
    test.off();
    EXPECT_EQ(states::Off, test.getState());
}

TEST(test, Coin_test) {
    Automata test = Automata();
    test.on();
    test.coin(50);
    test.coin(20);
    EXPECT_EQ(70, test.getCash());
}



