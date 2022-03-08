cmake_minimum_required(VERSION 3.21)
project(acm)

set(CMAKE_CXX_STANDARD 14)

#add_executable(acm "main.cpp" codelist/tmp.cpp codelist/other/2022-队内练习赛01/A.cpp codelist/other/2022-队内练习赛01/B.cpp codelist/other/2022-队内练习赛01/C.cpp codelist/other/2022-队内练习赛01/D.cpp codelist/other/2022-队内练习赛01/E.cpp)
add_executable(acm "main.cpp" "codelist/Codeforces/Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)/A.cpp" "codelist/Codeforces/Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)/B.cpp" "codelist/Codeforces/Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)/C.cpp" "codelist/Codeforces/Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)/D.cpp")
#add_executable(acm "main.cpp")