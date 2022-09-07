cmake_minimum_required(VERSION 3.23)
project(banking_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(banking_system src/main/cpp/main.cpp src/main/cpp/user/User.cpp src/main/cpp/user/User.h src/main/cpp/services/Deposit.cpp src/main/cpp/services/Deposit.h src/main/cpp/services/Withdrawal.cpp src/main/cpp/services/Withdrawal.h src/main/cpp/services/BalanceInfo.cpp src/main/cpp/services/BalanceInfo.h src/main/cpp/services/Menu.cpp src/main/cpp/services/Menu.h)
