add_library(banking_utils bank_account.cpp bank_user_group.cpp user.cpp utility_functions.cpp)
target_include_directories(banking_utils PUBLIC ../include)

