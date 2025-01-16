#pragma once
#include <array>

consteval auto get_input()
{
	using line_type = std::array<char, 131>;
	std::array arr{
line_type{ "....#.................#......................#..........................#..................#....##..#...........#................." }, 
line_type{ "...................................#...............................#......#..#...............................#...................." }, 
line_type{ "..........................#................#......##.....#.....................................#...............#..#..............." }, 
line_type{ ".......................................................................................................#.........................." }, 
line_type{ "...................#....#.........................#..............#.....#......................................................#..." }, 
line_type{ ".....#.........................................................................................................#.................." }, 
line_type{ ".........................................................#....................#..#............#................#.................." }, 
line_type{ "..............#...............#..................................................................#......#........................." }, 
line_type{ ".........#.....#.......#......#.......................#.............#..#........#.......#............#.......#....#..#.......#...." }, 
line_type{ "........................#....#...............................................#...#.#.........................................#...." }, 
line_type{ ".........................#........................................................................#.....................#........." }, 
line_type{ ".#..........#...#...............#..................#...#......#.................................#....................#.......#...." }, 
line_type{ "............................................................#......#.........................................................#...." }, 
line_type{ ".......................#...#..................#.#.............#......................#.............#.............................." }, 
line_type{ "............................................................................................................#.........#..........." }, 
line_type{ "....#..................###........#.............................#.#....................#..........#.....................#........." }, 
line_type{ "................................................................................................#.......................#.#......." }, 
line_type{ "..........................................................................#........#...#.................#.......#................" }, 
line_type{ "..........................#.#..#.#...............................................#..........#..............................#......" }, 
line_type{ "..............#........#.#...............#............................#..........#....................................#........#.#" }, 
line_type{ "#..................................................................................................#...........#................#." }, 
line_type{ "...............................................#........................................#.................................#......." }, 
line_type{ ".....#..#......#.......#..............#........#........#...........................................................#............." }, 
line_type{ ".......#..........#.......#.#...........#................#.................................................#......................" }, 
line_type{ "....#.....#...............#....#.......#...#.............................................................#...................#...." }, 
line_type{ "............................................#....#.......#................................#......#......................#.....#..." }, 
line_type{ ".....................#...................................#....#...........................................................#......." }, 
line_type{ "..#..............................#...........#...........................#.................................#......................" }, 
line_type{ "........#.............................##...................#.....................#................................................" }, 
line_type{ "................#.#.#......#...............................................#...###.........#....#................................." }, 
line_type{ ".......#.............#.............#...........#..#...............................#..................................#.....#.....#" },
line_type{ ".....#...#.......#.........................................#..............................#........................#.............#" },
line_type{ "...............................................#.....#..............................................................#............." },
line_type{ ".........#.......................................#.......................#...........#............................................" },
line_type{ ".......................#.....#.....................................................#....................................#........." },
line_type{ ".............................#......................#.....................#..............#..#.......................#............." },
line_type{ "......#......................................#.......#.....................#.....#...........#..........#.....................#..." },
line_type{ "..................................................#....................#.......#....#.......#...#................................." },
line_type{ "......................................#......#........#.....#........................................#.............#.............." },
line_type{ "#......................#.#..............#.....#.........#...............................#...............................#........." },
line_type{ "#......#...............#.........................................................................................#..#............." },
line_type{ ".#..............................................#.................#.......#......................................................." },
line_type{ "...#.......#.....#.............#...................................................................................#.............." },
line_type{ "..........................#........#........#.....................................#........................#..............#..#...." },
line_type{ ".......#..........#.......#...................................................#.##.....#.#.........#....#.................#......." },
line_type{ "..##...................#.......................................#..............#.#........#........................................" },
line_type{ "#.......#..............#...........#.....#....#....#............#........#..................................#.#.........#........." },
line_type{ "..................#.......................................................................................................#......." },
line_type{ "............................#.........#....................#...............................#..........#..........................." },
line_type{ ".............#.....................................................................#.....#.................#......................" },
line_type{ "...#...#............#..........................#..........................................#......................................." },
line_type{ "..#.............#.#........................#...#.......................#.........#....................##....#....................." },
line_type{ "...........................................................................................................#.........#...#........" },
line_type{ ".............................#.#..........................................................................................#......." },
line_type{ "....................#........................#.#......#...............#......#.............................#......................" },
line_type{ "....#...#.......#..................#..........................................................#........................#.........." },
line_type{ ".#...........#..............................................#...........................................#........................." },
line_type{ "..............................#...........#...........................................#.........#...........................#....#" },
line_type{ "............#.......#......#....#.......................................................................#........................." },
line_type{ ".........................................#...#..................#..................#.....................................#........" },
line_type{ "................#..................#........#.........................#...................#......................................#" },
line_type{ "............................................................#.....#........#......................................................" },
line_type{ "..............................#............#.........................................#.............#.......#..#..................." },
line_type{ "...#............#........................................................................#..................................#....#" },
line_type{ "..............................#.......#.............#.................................................#..........................." },
line_type{ ".....#.................................................#..........#...............................#..##..........................#" },
line_type{ ".............#.........................................................#.............................#..#..............#........#." },
line_type{ "....................#...............#................................................................................#....#......#" },
line_type{ "........#....#..#...........................................................................#................#..............#....." },
line_type{ "....#......................#...............#..........#......#.........#..^....#..........#..................#.......#............" },
line_type{ "...........................#.#...................................................#...............................#................" },
line_type{ "#..#.........................................................#.....#........................#....................................." },
line_type{ ".#.#....#.......................................#......#..........#................#..#..........................................." },
line_type{ "...#.....#..........#...................#.......#............................#...................................................." },
line_type{ ".............#......................................................#............#.....................#.....................#...." },
line_type{ "...................#.............................................................................................#................" },
line_type{ "...................#.....#...................................................................................................#...." },
line_type{ "................#............#......................#.......#..................#..#.....................#..............#........#." },
line_type{ "#....#...................................................................#.......##....#..........#..............................." },
line_type{ ".........................................#............#......#.......................#........#..............#.#.................." },
line_type{ ".##........#.....#...........................................................................................#..............#....." },
line_type{ "#...........................................................#.......#....#......#..#...................................#..#.#....." },
line_type{ ".............#........................................#...............................#..........................................." },
line_type{ "......................#..................................................................#..................................#....." },
line_type{ "...#.#........................................#.................................................................................#." },
line_type{ ".............#.......................#............................#.#................................#.......#..#...........#....." },
line_type{ "...#..#...............................................................................#................#.........................." },
line_type{ ".......#.............................#............#..#........#.....#.........................#..................#................" },
line_type{ "......#...............................................................................##.................................#....#..." },
line_type{ "........#..................#.......................................................................#......#..........#............" },
line_type{ "...........#.......#........#..........................................#........#..............#.................#.........#......" },
line_type{ "...................#..............................#...............................#.....................#.....#..................." },
line_type{ ".............#..#..................#.#..#.....#..#..........................................................................#....." },
line_type{ "..............................#...................................................#.......................#..............#........" },
line_type{ ".......#......................#.............................#...........................#.....#...#.................#........#...." },
line_type{ ".........#.......#....##.........................................................................................................." },
line_type{ "........................................................................#......................#.................................." },
line_type{ ".......................#..........##.#................................................#..#.....#......#......#.................#.." },
line_type{ "......................................#......................................................................#...................." },
line_type{ ".....................................#....#...............................................#...#.....#.......#...#...........#....." },
line_type{ "...................#..#................................................................................#.........................." },
line_type{ "..............#.................#..............................#..............#...........#.#..................#...#.............#" },
line_type{ "................#..#......#.........................#.....#.....#..............#..#.........................................#....." },
line_type{ ".....#.........................#........................................#.....#.......#...........#...................#..........." },
line_type{ "......#....................##......................................................................................#.............." },
line_type{ "............................................................................###...............................#..................." },
line_type{ "#..................................#......#..............................................................................#.......#" },
line_type{ ".....#...................#.....#............................................................#.....................#...#..........." },
line_type{ ".......#......#........................#.....................#.#..##............#......#.................#.....................#.." },
line_type{ ".....#..............#.................#........#..................#..#..........................##.....#..#...................#..." },
line_type{ "........#................#................#...........#.........................................#....................#............" },
line_type{ ".........#.........#....#................#........#........#...............#....#................................................." },
line_type{ "...........#...#............#..................#.............................#.#..#....................#.#........................" },
line_type{ ".#............#..#..#................#.#................................................................##.............#.........." },
line_type{ "...........#.......................#.........................................................#...................................." },
line_type{ "..#..........................#...........#......#................................#.#.............................................." },
line_type{ "............................................................#..................#...........#.....##.................#............." },
line_type{ "....#.........#............................##..........................................#.....#....#..........#...................." },
line_type{ "..................#..............#........#........#....................#..............#....................#....................." },
line_type{ "....#...................................#.....................................................#.............#...................#." },
line_type{ ".........#...........#...#.............................#.............##..#................................................#.#....." },
line_type{ "............................##..............#................#..#........................................#....................#..." },
line_type{ ".............................#.#......................................................##.....#..................................#." },
line_type{ ".............................................................................#..................#...#.................#..........." },
line_type{ "........................#...........#..................#......#..................................................................." },
line_type{ ".....#.......................#......#................#............#..................#.................................#.........." },
line_type{ "#..........#...................................................................#...................#...#...............#.........." },
line_type{ "....................#............................................#...............#........................##....#..#.............." },
line_type{ ".#.....#............................#...............#.#.#..........................#.........#..............#....................." },
line_type{ ".............................#....................................#..#......#........................#............................" },
	};
return arr;
}