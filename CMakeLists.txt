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
add_executable(week3e3 week3/03-recouvrement.c)
add_executable(week3e4 week3/04-complexes.c)
add_executable(week3e5 week3/05-complexes2.c)

add_executable(week4e1 week4/01-ecriture.c)
add_executable(week4e2 week4/02-lecture.c)
add_executable(week4e3 week4/03-stat.c)

add_executable(week5e1 week5/01-echange.c)
add_executable(week5e2 week5/02-selecteur.c)
add_executable(week5e3 week5/03-explore.c)

target_link_libraries(week2prime m)
target_link_libraries(week2formulas m)
target_link_libraries(week2poly m)
target_link_libraries(week3e5 m)
