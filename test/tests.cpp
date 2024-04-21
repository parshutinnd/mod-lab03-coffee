// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include <Automata.h>


TEST(testMethod, On_test) {
    Automata test = Automata();
    test.on();
    EXPECT_EQ(states::Wait, test.getState());
}
TEST(testMethod, Off_test) {
    Automata test = Automata();
    test.on();
    test.off();
    EXPECT_EQ(states::Off, test.getState());
}
TEST(testMethod, finish_test) {
    Automata test = Automata();
    test.on();
    test.finish();
    EXPECT_EQ(states::Wait, test.getState());
}
TEST(testMethod, Coin_test) {
    Automata test = Automata();
    test.on();
    test.coin(50);
    test.coin(20);
    EXPECT_EQ(70, test.getCash());
}
TEST(testMethod, check_fail_test) {
    std::map<std::string,unsigned> menu;
    menu["coffee"] = 20;
    menu["tea"] = 15;
    Automata test = Automata(menu);
    test.on();
    test.coin(10);
    test.check("coffee");
    EXPECT_EQ(10, test.getCash());
}
TEST(testMethod, check_success_test) {
    std::map<std::string,unsigned> menu;
    menu["coffee"] = 20;
    menu["tea"] = 15;
    Automata test = Automata(menu);
    test.on();
    test.coin(20);
    test.check("coffee");
    EXPECT_EQ(0, test.getCash());
}
TEST(testMethod, Accept_state_test) {
    Automata test = Automata();
    test.on();
    test.coin(50);
    test.coin(20);
    EXPECT_EQ(states::Accept, test.getState());
}
TEST(testMethod, canscel_test) {
    Automata test = Automata();
    test.on();
    test.coin(50);
    test.coin(20);
    test.canscel();
    EXPECT_EQ(states::Wait, test.getState());
}
TEST(testMethod, start_test) {
    std::map<std::string,unsigned> menu;
    menu["coffee"] = 20;
    menu["tea"] = 15;
    Automata test = Automata(menu);
    test.start();
    EXPECT_EQ(0, test.getCash());
}
TEST(testMethod, cook_test) {
    Automata test = Automata();
    test.on();
    test.cook();
    EXPECT_EQ(states::Wait, test.getState());
}
