#include "Parser.h"
#include "Hallgato.h"
#include "Oktato.h"
#include "gtest_lite.h"

int main() {
  TEST(Hallgato, KonstruktorAlap) {
    Hallgato h("Mernokinf", 1, 5);
    EXPECT_TRUE(true);
  } END
  
  TEST(Oktato, KonstruktorAlap) {
    Oktato o("PhD", "IIT", "I-100", "Algo", "", 3);
    EXPECT_TRUE(true);
  } END
  
  TEST(Parser, UresKonstruktor) {
    Parser p;
    EXPECT_TRUE(true);
  } END
  
  return 0;
}