cmake_minimum_required(VERSION 3.9)
project(progOS C)

set(CMAKE_C_STANDARD 11)


add_executable(week1age week1/age.c)
add_executable(week1calcul week1/calcul.c)
add_executable(week1intervalle week1/intervalle.c)
add_executable(week1intervalle2 week1/intervalle2.c)

add_executable(week2tables week2/01-tables.c)
add_executable(week2balls week2/02-balls.c)
add_executable(week2balls2 week2/03-balls.c)
add_executable(week2pret week2/04-pret.c)
add_executable(week2prime week2/05-prime.c)
add_executable(week2formulas week2/06-formulas.c)
add_executable(week2poly week2/07-polynomials.c)
add_executable(week2useless week2/08-useless.c)

add_executable(week3e1 week3/01-scalaire.c)
add_executable(week3e2 week3/02-mulmat.c)


target_link_libraries(week2prime m)
target_link_libraries(week2formulas m)
target_link_libraries(week2poly m)
