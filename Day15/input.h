#pragma once
#include <array>
#include <string_view>
#include "../external/glm/glm.hpp"

constexpr glm::ivec2 size = { 50, 50 };

consteval auto get_map()
{
	std::array<char, size.x * size.y + 1> arr{
"##################################################"
"#...O.#O#O..OO.O.#..O....O...#.O....OOO.O.O...#..#"
"#O.O.OO.##O.....O....#....#.O#O...O.....O...O..#.#"
"#.O..OOO..OO.O..O..##O..O....OO..O..OO..#..O.....#"
"#...O...OO............#...OO....O.#O...O....OO..##"
"#....#O.O....O.OO....OO..#OOO.OO...O.O.........O.#"
"#.......O.#O...O.#.O#O..OOO.O..#.O.#........#..O.#"
"#..O.....O...O....#......O.##OOO#...O.#.........O#"
"#.#OO.O...#OOO#...O...#O.....OOO..O.........##..O#"
"#O.O.OO.#O....OO.OO.............#..O.OO.....O..O.#"
"#..OO...OOO..#....OO.OOO..O.......O.#..#..#....O.#"
"#.O.......O.....O.O.O.O.................#OOOOO.#.#"
"#.#O....#.O#O....O#....OO...OO.O.....O.....#.O##.#"
"#.#O.#..O.OOO.......O.OO#...O.O.O.#O.....O..O#...#"
"#..O#...O.O....O.............OOOO....OO.O..#.....#"
"#.O#.OO#O.O..O#OOO...#......#.......O...OOO#.OO..#"
"#...OO.O.O.O#..OO#....O#.OOO.OO#O......#.#.O.OO..#"
"#...O....O#O..O..O.#..OO....O.O.O......#..OO.#.O.#"
"#O.O#OO.OO.O.#...............O....O........OO....#"
"#.....O......O...O.O.O.OOO...O..OO.OOO.OO.OO..#..#"
"#.##...O....O.......OO..#OOO.....O....O#.........#"
"#.OO..O.O...#O..OOO..O..O..O......O........#..OOO#"
"#OOO...OOOO#...OO....OO.....O#...O....O.OO..OO...#"
"#..O...O...#.O.##OO.......OOO#...OO....O..O..O...#"
"#..O.#O.#O...#.OO.......@O.....O....#...O....O.O.#"
"#...OO.OOO...O.O..O.....O.O...O.O.OOO.#.OOO.O#...#"
"#.....OO.O...O.O#O...........O....OO#...#..O.#OO.#"
"#.O....O..O..O..#OO#.........OO.#..#....O...OO.OO#"
"#...O#.OO.O....OO............O.O.O..#.......O...O#"
"#.....O#.....O.....O...O.O..OOO..OOO...#.....OOO.#"
"#..O....#.O...O......O..OOO.O...O.O..O..OOOOOO#..#"
"#O#.O.O..#.....O...O..O...O..OOO.O..OO....O.O..O.#"
"#.#.O..O.O.....#...O.O...OO.OO..#O.O......O..O.OO#"
"##..O.O...............#.....OO...O...#O.O.....O..#"
"#..O.O..#.#..O...O..O..........#.O#O.....O..#..#.#"
"#..#....O.##...OO..O.....O...OO.O#....#O..O#O...O#"
"#O.O...O#O.O.....#.O...O...O.......#.#OO....O.O#.#"
"#.#O...O..O....O...O.............#..O.#.#.#......#"
"#.#...O..#.#...#OO.....O..OO......O...OO.........#"
"#....OOOO...O.....O.OOO......O.##..O...O.O.O.O.O.#"
"#....O.O..#...O.O.....#OO.OO.....#...O#O#......O.#"
"#...#.O......O..O..#...O##OO.#...#.O.........O..O#"
"#O.OO..O....OOO...O.O.OO.#........O.OO#O..#.O.#.O#"
"##..#.....O.#O....O#.........O.O....O..O..O..O.#.#"
"#..OO...O.....O.O.....O..OO..O.OO..OO.OO.O...OO..#"
"#..............O#OO......##..#OO#...#.O#.OO..O...#"
"#OO..O....O#.O..O..O......OOO.....#.O.......OO...#"
"#.O.#O.#.#.O.........O#..O........O.O.#.OO.......#"
"#........OOOO....OO..O#.O..O.##OO..O...OOOO.OO...#"
"##################################################"
};
return arr;
}

std::string_view robot_program = {
"^<<<^^^vv>^^<^^^v<<^^<<>^>>vv^>^vv<><vvv<vv>><v>v<>^^v^>v^<<>><<<v<<^>>>v>>^^vvv>vvv<v>vv>><v<<<<v^^>>^>vvvv<<>v^>vv<<<v^vv><>^^^<v>^^<vv>v>>>>>>v<><^<>^<^^><<^vv<vv<><^^>v>^^v^v^^^^>^^<v^v>^><^>>v>vvv<^<v>v>^v><^^<<^v>v^>^^v>^<<^^>vv^vv>^>vvv<>v<<>^v>vvv><>^<v>^>>vv>>vv<^>^<>v<^<>>^<^>v>>>vvvv<><<>v<>^><>>v>^<><v>v><v<>vv>>><v>v><v^^>vv^<>v^^^<vvv<^<<vv^<^vv<v<>v<<>^>>^>v>v<v<v><>v>v<><v>^^v<^>^v><>><^v<<<v^<^><^<^vv^^<^<^>^v><^^>^<<<v>><>vvv<v<<vv>>v>^<v^>v<^>v^v>v<^^^v^^vv<^^v>v^>^vv^^^v>>>vv^<^^>><<^^^v^>>>>^^v<vvv>v>^<^><v<<>>>v<><^<^<><>^<^^^><>v^v<><vv>>>v^^^^v^v<>^<<^>>^^vvvv<v^v^<<>v<^<<><v>v^<<^v<<v^v<>^<>>>v>><vvv>^<^^^>^v>v<v^>vvvvv^><v><v>>>>><^>>>vv^vv^<>>>^v><vv<^v>>>>v<v^>>^^<^<<v^<v<^<<>><<^><<vv^v^^<^<><v><^<^><v^^v<<^v><v><><<>><v<<^v^<<^<>vvvv^<^^^<<>^>><<<<><^^^^<^><v><^<^^^<v><v>v<^<^^^^<>>vv^v>^v>>><^<v>v^v^vv<<>^^^vvvv<<vv<>^^vv<<vvv<v^v^<>v<<^^^>><vv>^^<>>v^v^v<^^<v^vvvv^<>^<v^^^v>^^vv^^^^v><vv<<<>^<v^v^>>vvv^>>^v>><v>^>><^<^<<>^>v>>v^^vv>^><^v<vv><<>^><<^><v><"
">^<v^^>^<<v^^^v><>><<v>^<^v<^v^^^^^<<>^v^^>^v^^v>v^^<<>>v<><^^<>>>^v<^v<>vv>v><v>><>v^v>vvv<><^vv<^v>><<^v<^>v<^<<>^vv<><v<><<<<^v^^v^><^v^>v<<><^^^^^<>v^>v<>v>>v^>>vv<v><vvv<vvv<v>>v>>^>^^v<^v^>^><^vv<^>^>^><v>>^^<<v>v^><<<<^^<<v>>>^><>^<v>><<^><<><<^<^^^<<>^^vv<>vv><>v^><<v^^v^>v>>>^<^<v>v>^^<^<^v^v^<v<>^v<>><><>v^v^v>vvv<<<^<^v>^<^><>>><<^v>><<<<^^vv^^^<<^>^vv<<^v^vv^v>^><>v^v><<>><>>v^^>v^>><>^vv^^^^>^v>^><^><^vv>>v^<^<>>>v><v>v>><<^>v<<<^>^>^>^<><^^^<^>>>^<vv><v^vv>^<<>^^^><^<<v^^<v>v>v^><vv<v<<vv^^<>><v><vvvv^^<<<v^<>>^>^<^^<^<^v^<v^<>^^<vv>^v<<>^v>><^>>vv<^<vv<><v^<<^><^<vv^>v><^<v<>>^vv^<v<>v<vv^>^<vv>>v^<<>v<><<>v<>>>^v>^<v^<^^<v^^>vv><v^<^vv><<^>>>^>>><><^v^v>^^vv>>^<v<vv>><<v^><<>>v>^^><^>>v><<vvv<<^v^<>v<>><v^>v><^v>v<^^<>^>^><<>>^>>>^<vv^^v>v>^^<v^^<v<>v>v<v^>^^^>>><<>>^v<vv>^>vvv>>v><v<v^^<>vv^<<<v>^<<^v>^><v<>>^^<<^v^>v>>v<>vv<^v>>v^>^<^^^<<^v<^v<^<^v^vv<<>^v><<>^<<>v^>>>>>>^vv>>^<^<^>>v^>>^v<v><^v<>>^^vvvv^<<>v>>><^vv^><^vv><>v<<vvv^^>vv><^^>^^<<>>v>v<>>^<v^<v^^v^<<<>^^"
">^^^<v<^v<^^><<<^>v>><v<>vv>><v^v^^>^^<^<<<v<^>v<<^<<<<<^>^v>v>v><vv>^vv><><><^^v^><<<>vvv^<^<><<^^v>vv>>v^^<^v><v><>vvv^><<<>v^>^<>>^<<<^<v>^v><^<^<>vv<<>^^<^^vv^><v^^vvvvv>^^<^<<^v^^<<v>^vv<^<vv<>>v>>^<^>><>><^^>vvv>vv^v^v><><>^v^>>vv>v^v^<^><^>^>^^^^><><^>^^>^>^<<<>>^>^v>v<v<^vv><v^^>>v<^<<<<>v><<v^^<v>>^<^<<>>v>>><>v>>><v><^<<<v^<v<v^^v<^^v^<<>>v>^^><>^^<>>vv<<<<>><^v<><^^<v^>^>>>>^>><>v<v><>^v<<><><<>v^>^v>^<v>><^^v>vvv^v^v^><>^v><v^v<>><<^v><v<^v<^<v^v<v><^^<vv<v>><<><<<^^^^^v^<v^^vv>^>v^v>^v<<^vv^<^^<^>^<>><>v<>^>v<<>>v>>v<<^^^^^<^<v>vv>><^v^vv<<vv^^<^v^<><<<v><><v><<<>v<><<v><^<<v>v^<<^><^<^>vv^^<<^<>v>>^^<^>vv>v<><v>v^<>>^>><^><^<^>v>v>^vv^^<^v^><<>>>^<<>v^>vv>v<>><>v^>>^^<v>^^v^^<<><^^v<^^v^v^<><v<^v>^><>v>^^<<v<v<v^v^v<<^^>>>>^^^v<>^><^><v^<^><>v>^>>^>^><<>><^v>v>v>vv<>^^^v^><v<<^^^^v>>vv<>vvv><><^>^><^^v<v>^>^^vvv^>^><^><<^v^vvv>v<^<vv^>^v^^><v^<^^^>^vv<^>>>v<v>>vv<<<^^<v<<<^vvvvv^v<<<v^<<<><>v<<<^><<^v<>v><vv<^>v>^<^<>^<>^<^^v<<<^v>v>>^v^>>^<v<^^v<v^^vvv>v^<^v<vv^^><><v^<^"
">^v^^<vv>v<<>^^<><^><v<vv<<^^>>v^^><><^>vv<^>v<^<^>v^<vv^<>>>v^vv^><>v>>>>>>>^^^v<vv>v<>><<v^<^v^v^vv><<>v<<><><^vv>^v>^<^<<v^>^<>^<v^v^^^^<<^>>^vv^>>^<vv<^>vv^<<>>^<^<vv^>v^^v^>><<><>>^>vv<v>>>^>>^<>>v>v<^^v>^^^v<>>^<vv<<v^^^v><^<<v<^^^<^><^^vv<vv>v><v><><vv<>><<<>^<<<^^>v<<^<vvv>v>>v^>v<v<v><<<v^^v<^v^<^<^><<^vv^><v^>>><v>^>^<>>vv^^>^^v<v>^^<vv<v<vv><<<><vv^<<v>^><v>v<<>^v^><<<^>vv^vv<^^^v><^><v^<^<>^v><v^v^^^^>^^<^v^><v>^^^>><^^^v>v>vv<<^<^v<^<vvvv^vv<vv<^^^^^v<<^<<<v^v^>><>v^>v>v>^<^<^>>>v<<v^>>^vvv<<^^<^^>^v<>^^>^<<>v^v^>>^vvv>><v^>>^v>^>>^v>^^v>^><v^<<vv><>^><^>^>v>^^^><v<v<<>>v<>>^v<>v^>vv>v^>^v<v>>^>><v><<<v>v<^<<>vv>^^^v<<<><v^>vv^<<>v^><>vvvv^^>>><^^v^vv<^>>>><^<^^>><^>v><^^^<>vvvv^<<<v>><v^^<<^^><^^^<<><<<vv<^^<v^<vv^>^^>>v<^^<><><^>^v>>>v^>><v<vv>^>^^><><^v<>>v>^^v^vv>vv><>vv<<^<>v>v>v<^>^^^v^>v^^><^^^v><>v^^<>>>^<v^^>>^<<v<<^^v^<<><>^^>>v>>><v<^>v^>^v<<<>^>^><<<>v^^>>>v^v^v<v^>vvv^<>>v>^^^<>><>>^>^^^^<>^v<>>v^<>>>>v<^>^^v><^^^<v<<v^<^^<^^^^<>^<<vv>^vv^^<><^v^><v^>>^><^<<v>"
"^^<v<vv><<<>^^^^<<^>><vv>^>v^v<v^v<<>>^vv><>v^>>>><^>v<v<v^<><<<<<v^<<^><v^>v<^^<>^vv<<^^>>>^^vv<^>>>^v><><><^v>^^>>^>v<vv<v^vv<^>^v>vvv>v>>^>><<>v>^v><><><<<>v^>^^^><^>><^vv><>^v^v^>>vv^<>>v<<^>v><<^vv>>>>v><><<<<^<<>v<<v>vv^<<>>^^>^^v^>>^^<v>>v><v<>v><^^<v>>v>v^v^^<^v<vvvvv<^v^>>v^><>><^<v^<<>v^<><<>^<^<^><>v^>^<<<^<^<^vv<^<<v<v^^v<<>^<^^<^<<v>^>><^^v><v>><vv>>^<v^^v<^^vv^><^^>^<<vv><>^vv^^^^>v^^vv^>^^>v><^>vv<>v<^<^<vv^^>^<<>v<v>v<v^v>v^>><>v>^<><^><<<^>^v^<^^>^<>><<<^v>v^>v<^v^<vv<>>v>>>v>^>v>^v><<vv<><^><<><^<>>v<v^^^>vvv<^<<v>^<v^v^<vv<^>>>^^>v^v^^><^v>v^<><v>><vv>v>^^vv^<^>vv<^>>^<<v<><>v<^v>v>^>^>v<^v>^v<<v^^^>>^<^><<<>>v>^v>^v<v<v<vv^v<>^^v>^<<<<^^<^>^<>>^vv>v<^^vv>><^vv<>v>>v<>^>>>>><^^<^<>vv^>^<v><<^>vvvv^>v^v^<^^^v><>v<v^^^v>^><v>>v>vv>^^<^^v>^^<><>>vvvvvv<>vv>>^<^v>^><<^>^>v^v<^vv^<>v><^<<^vv^><v<vv<^>><vvv>>^^^>v<<v^<>vv<v^v<<<^>><v<<>v<^<<^<<>v<^>v^^<^<^^vv^^^^^^vv>><<^^>>>>>>^^>^<>^<vv>><<>><<v>>v^^v<^^^<^<^vv^<v<^<<>>>v<v>v>v<v<>^<v^v>>^^v<<<>^^><^^v<>>v<<<^v><v<vv<v>>"
"^^>vv^^^>v^vv^^<<v^v<<^^^vv^v<><>>>>^v^v>^^<<<^>>>v^>v>>>v<>v^>^^><>>>^>>>^<>vv<<v>v^^v<v^^>>v^>><<^v<vvv^^v>><<vv^>>>^v^v<>><^<^<v^<<v^^>^v<<<>>^^>^>>v><v^^v>>v>^<>^^v>vv<v>^<^>^v>>^><<^<><vv<>><<>v>>><>^v^^v<^>>v>vv^v<<vv>^v^v^>v^>>><>^^^vvv^^^>>>>^^<^v^<><v>v^^vvv>><<<vv>><v>v><><v^><v^^v<<<^<^^^>v>><<^^^<v>v><<<><<>v^^<<<<^^v<^<<>^<vv<^>^>^<<^<^^>v^v<><vvvv>vv<vvv<>^<<v^^<<<>^><<^v<v^^v<><v<v>v^><v>vv>^vv>><>>>>v>>>><<<><v><^><>>v><<>^>^>^^^v^vv^>^^<^>>>>>><<^<v<v^v<<>>^>><<>v>v^v>^<>>>^^<v<<vv<^<v^<<v<v>v>v<<<<^<v<>v^<<<v>v<vv<^v>v>^>v<v<^><<>v<v^<>v^v^^<>v>v^>v^^^<>>vv>>>>v<^^>^>^^<^^^>v<<v^><v<^vvv^v>^v>v<>v^v<v>>vv<^^vvv^vv^<v^>^>^>v>vv^>v<v>^<v>^<>v<<<>>v><>^^v><^v^v<v><<>^><<^<vv>vv>><<>><<><^<>^<^<v<<v>>^v<^^<<<>^^<vv<<v^<^v^>>^^v>^>v<>v><<<>v>^v>^vv^^^><<>v^v>>^v^v<v^<<<^<<^><><v>^<<^>v<><>><<v^<<>><<>v>vvv^^>^<<<><>>><><>>^<<<^v^>>>>^><v>><v^^^v><<^vv><>^v>^^>^^vv^v>>vv<>>^><v<v^<<<>>^>^v>v<vvv<>v>^<^<v>v^>><v^<<<v<^v<^vvv>v<^><<<<<<<<v^>><^>>v><vvvv><v^<<>^>^vvv>>>v<v<<v<"
"v>>>>v<^v>^>vv>>>><^^>><>v>><^^^><>v^^<>><>>^<>^^^><v<><^><<^vvvvv>>^v>^v<<v^><v>^<<<<^<>^<v^>>^^^>v^<^>^<v><<<>>v<v^^v<<>>v^<>>^v<>>^>^<>>vv><<<<>>v<v><<><>>vv<>^v^vv><^>^^^<^><><<v<><<><vv^^><<v^<^^><v^>>>^<^v^^>v^<v<<v^v<vv<>^^^><<v<<>>^>><^^v>v<><><v<v<<>^<><<v^^<^<vvv><v>><><^>^>^v<vvvv>>^<><^v><^<>><v<>v<<>v>^><v^<^v<v^vvvv^>v<>^<<>vvv><<>^^<^>^^<<<^^>^v<vv<v^^<v<^v>>v^>^<^<v^<<<>>^^^^v>>>><v>vvvv>><^<^><>>>vv<>v^<^^<v<v><>vv>v>v^v>v>>>v<^vv^^<>v>v^v<>^vv<<v>>^>^v^vv^<v^vv>v^vv^>v>^^^>vv>>><>v>>^^<^^>^>vv<^>vv>^>^v>>^v<>v>v>>^>^<<^v<<^><^v<v^^<^vv<<<><^v^>>vvv^^^>>>>^>vv<<v>>>>v<<^^<><vv<v<<v>v>^<><^^v<<v<^v<v<^<<><v^v<^<<v^<<v<<^<v>^<>><<>^>^^>>v<v<<>^v^^v<vv<<<>><v<>^<vv>v>v<^v<^^^v<>^>><^>^<^><vv<<^>vv<^^^vv><<^v<<vv^v^v^v^>v>v>^vv<>>^<^^v^^><<<><v^^^<v<<>v^<^>v<>^^vv<<>vvvv^^^<>>v<<<<v<<<v^>vv>^^<^>>v<>>>><^<><<v>^>^<v>><<^^>v<>vvv>v>>^>v>^>>^><<^>^<<^v>><<^<<^<<v>^<>v<<<<^><><^^^<><^v<<v<<^v<>><^<vv><vv>^^v^v>v^<^^>v^>>^>^>^^v^v^^><<v<<>vv^vvvv^v^<v>>^vv^^v<<v<<<v>v>^vvv><>>"
"^^^<v^>v>^vv>>^v>>vv<>^^<^v>^><v>vv^v<^^^vv>>^vv><<^<><^<^^>vv>v>^>v^<>v^v^>^v<<vv>^v<v^<vv<<^<>>>^^^^>v>vv>^>^>^^^^^>>v<<>>^>>vvvvv>vv<vv>^>><^v^>^vv^<v^^^^v<v<<<<vv^v><^><<<^^^^^<^v>vv^^^><<^><>^<^v>^>>v<>v<^>^v<<^<^v^vv<v^v<vvv<^v^<^>^^^v^<v<<^^v><>><^^<^v<>>^<v>^v^<v><<<^v^<>^vv><v^>^vv^v^^^<v>><<^<>vv><><<>^>v<v<<v>v<>^<v<vv^<^^v>^v>>^^<<v^<v<v>v^>^^><v^v^^v><^^v<><><^>v>v^>>v>>^>^<>><^^<<>>^v><^<^>^^>^<<>><<^><>>^^v^^^v^vvvv^^>>v>><>^<vv<^v^^^>>v<v<>><><vv<^^<^<v<<<<<>v><vv>vv>v><>>^v><<^^<v>v^>^^^<^>v<>v<>>>>^vv<>v^v^^^>^<^>^<<><v^<<><<vv^^v<<<^<^vvv>>><^>vv>v<v>>v>v>v^v<>v>v^^v>^>><^vv<<^><<>^vv>v<>^>>vv>v^>>^>^><^vv<<^<^v>><^<^<v<>^v><v<^^v>v<v<^<^<vvv>v^^v<>v>>^^>^>v<>>v^^<><v^^v^^vv<><<><>vvv<^>^vv^<v><v<<<^^vvv^<^>vv^^^<^<v>^^v<^^>v^vvv^<vv^v>v^<<<v^<<<<<v<>>^<v^>v>^<v>^>^<^v>^<^^<<v<>v>v^v<^<<><>vv^vv<v>>><^v>v^<>><v>^v>v<<^>^v<>v>vv>>^vv^v^<v<>>>v^vvv^^>v><^v<^^<<v^^v<^v^^v<^><<<<><>^>^vv>v^>>^<>vv>><^v<>><<<v^vvv^<^>v<<^vv>v<<>^>^<v>>^^^^><><>v<^v<^>^<v<<>vv<>><>^>^<>^<^"
"<^>>>v<^>v>^><v<>^>>v>v><^v<<<v^<^<v>^>>^<^^^^<v^vvv>^^<^^vv<^^>^<^^v<<<v^v>v>v<^><<<>vvv>v<v>><>^^vv<^<<<v>>v>^^^^>><v^<<v<<<><><v^<v^<>v^v^><v><v<<v<v>v^<v^<><<v>^vv^v^<>^<<<v<^^<vv>v^^<<v>v<>>>^<^><>>v<>^>^v^vvvvvvv<v<<<^><v><v<><v<v>^<v><><>>^^vv<>^v^<^><<^<^vv>>>^^>v<><><^v><>^<vv>>^v<vv>v^^v^>v^<<>><^<^^<>vv<^<<<>vvvvv>>^><v><><^>^>>^^<v<v><>vv<vvv<<^>^vv<^>v<<vv<<>^^><>><<^^<>^v<<^<v^>^v<>vvv<^>^^>>^v^<^>^>vv<v>v^v>v<>vv^v^^<^<v>>v<v><^vv>v<<><^v^v>><^^<v<^^<>^<^^^<^>><^v^>vv>>^>^>>vv>>v<^<^<<>^^>^v^v^vv>v>^><<><<^v>^v>v<<>^><>v>^<^>^<>><<>vv<^^^vv><^^v<^^<v>>^v><vv<>^^v<v<<><v<>vv<^<>>>vv^>><v>>>>^<>v><>^>><v>>v^<<^><<^^>vvv^^^>v<vv>v<^>>vv<v<>>v^^>v>>><<v^>>^vv><^^<>v>v>^<^^^v^<^v^>><v><v<<>^<<<v>>><^^>>v>v^^v^vvv>>vv>>v^v>v<>vv>v<v<^vv<^^>^^<^vvv<>>^v<vv>^<><^v^^v^><<vv>v^><v>^>^<<v<^<>^>v<v>v<<v>>>v<vvv^><^v>>><<><v>v^^><^><<v>vv^^<<<^>>^<<^v><v^<>><><^v<<v<>vv><>^><^v<vv^><^><<<^vv<v<>>^<<<<v>>^^^<v^>>><>><vvv^^vvv<>><>>><^^>>^^<^v<v^<<<<>><vv><<vv>v>>>^^v<>v^v<<v<^vv><^v<>"
"^>v>^^>>^<vvvvv>vvv<^<v^<<v<^^<>^v<<^>v^>v<v>>v><^^v<><v^v^v^<>>vv<<^<v><^^<^><>><^^>v^^v>^<>vv^v^v<^v<<<vv^>>>>^^vvv^>>vvvv<<><<>>^v<^>vv<>>>^<v^vvvv<>>^>vv<>v<^^v^>>v<v^<>v<><<>v^>^v^^>^<^v^<>v^<^<>^<>^^>v>v<>v<<>>^v>>><vv>vv>^>v><v<^v<<vvvv<v<v>><<^>>vv^^v<<<^v^<v<v<vvv<>^vv><^>v<vv<^^^><vvvv<<>>>>^vv^v>^<<<>^>^<<v^^>^vv>v^><vv>>v<^^v^v^<<<^><<<^<^>><>vv><^^>v>>^<v^>v<v><^v^>>>v>^<^<^>>v<v^^>v^<>>^^v<<><<v<v^^^v^<^<v^^<<>v><^^>vvv^><vv^^v^<<>v>><^v^<vv>vv^^v>v<^<^>^vv^v<<^^<><>><>^vv<>><^^v^<<^<^>>v>v^v>v><^^<<^><<<>>^^<><v<^v><><v<>^<<v<<>^^v>^<><><><>>vv^<vv<v<vvv<<^<v^v<v^^<>^vv<^>>v^^><^<^<<v>>>><<<>^<v<v<<>^v><>^>v>>vv^<<<<vv^^^v<<<><^<<v<>vvv<^>>vvv<<><>^<v<v^^<^^v><<>>>^<vv<v<<<>>>v^<<<v>><>><<vv>>v^>v<>><>vv^^<v>v<>>^><^v>>^^^>>><vv<v>^v<><^>>^<<>v<^^>><<<^^<><><>^vvvv<<<>vv>>v<>>v<vv<^><><><<<<><<^^v>>>><<^^v><vv>^v><<^<><^vv>>>><<><<<vv><^<>v^>^<<^v>^<<<^<<>>>^>>>^v^>>v^vv^><^<>v^<^>^<^^vv>^<v>^>>^>>v<^v>^>><v<<<v>v><><<>v<>>vv>vvvv<v^<^v><^v><^vv^><>><v>v^^v^^vvvv>v<^>v>>"
"<<^><<>>v^<><>vv<<^<><<v<<vvv^v<<v>>><>^^<v<^<^>^>><<>^v<>>^><<v><^<>>v>v>^<^v<<^>^vvv>>>vv>vv>vvv^v^^vv>^^^<<^>v><^>>v<<^v<v^<><vvvv><v>vvv<^vvv<<<<>v^><^v>><v^>^^v><v>vv^>v>v^v>v^^^<^>>>vv>vv<vvv><>^><v<><v<><<^<<<<><<v^>>>v><^vv>v>>v<^^<>v><>^><>v<vvv<<<^v>v><v^^^^v^>>v><v^<vv<>^<^<^>>>^vv^<v>v<<^><><>>v<v<><v<<^^v<^<<<vv<<>>v>>^<<>>v><<<>>>v^^<>^>>>^<^v>vv^><<^><^>>vv^<<>v^<^v>^^^^<<><^>^><^^^^<^vv<v^^v<<v^vvvv>vvv^vv<v>v<>^vvvv>v^v><>>>^<^<><<<<v<<>v>^vvv^><^vv^v<>v^v>>>>v^<>vv><>v^v<<v>>><v>v>vv^^><><^v^>>vvv^^>v^v<<>>>v<^v<^^v<<vv^><vv>^<v>v^<v>><>^><vvv^vv>>v>v<v<>vv^v<>>^>v><^<^>v>^>^^^v<<>^^^v><>>^<^<v>>v<<>v^^v<<^v^<<v<>vv>><^vv>^<v^v^<<^><<^^<><>^<^<<v<v>vv<^<vv^<><v^><^<v>><><^v><vv<<^v^^>>v>^^>>v>>vv>^>vv^>v^^<>>>>^<>>>v^^^^>vv><^<^^^<><v>^^v>><v^^<^>>>v^><><^<^>^<v^>v^vv<v<^^v<<v^>v^>>^>vv^^v<>><^>>^^<^v^<v<^v>><v^>v<>^vvv^v^^^v>>>vv>>>><>>^><v^><<>^^><><>v>^v<^vv<>^vv<<vvv<<v<>>v>>^v><<<><^^><<v^vv<>^><>v^<<v>vvvv^<<vv<v<v>^>>>^<^<>>v>><<><<^><<>^<^>v<>>>vv^<vvvv<<>><<>"
"<vvv<v>^<<>>v^v^^^<<vv<<<v^>>>^>^><>v>>^^>vv>^<><<^v^<<<v<v^>v^v>^v>>>v<^>^^>v><>^<<^v>^>>^^<>^<v^<^vv><<>v><^vv>>^v>>^^v<><^><^^v>v^v>>v><<<^v<^><^<^<<^<<>^><^v>>>v^<>>v>^^^<v<>v<<<><^^^v<v>v>^^>^><>><<^><>vv>^^>><<<<^<<v^>v<<v<>>>>>v>vvvv<>^>v^>v>>^<<^^v>><>v>^>>v^<vv<<<v>v^^<>>vv^v><^>^vv<>^<>v>>^v>v>v>v><^v<^^><v<<^>>>vv^^>vvv>vv>vv<^v<<v><><^>v<^v^vv<<>><v^^^vvv<v>v>^><<v>v^v>>^^>^^>>>^v<v^>>^v><^>^vv>^v^>v><>v<v>^^^^<^v>^>^^^>v>v><^><^v^^^>v>v<>v<v>vv<<^vv^^v<><vv>><^>>>^<>vvv<^v>v<v<<<^vv^<^<<<<><<v^<v<>^v^>v>v^^v^>>^v><^^v><vv^<v<^<^v^vvv><^<<>^>vv^^v<^^v<vv<^<<v<^^^<^v^v><^>>^^>v<^^<^<^^<^>v^vv>>v>vv^<^v><^^><<<<v^>v^v<v<<^^v<^^v<v^vv<>v^>vv<v<^><^v<v<v><^vv<<vv<<^v>vv>><^v^<<><^>>>v<^v<vv^^<<<>><>v<^^^<v<^^^^<<v>v^^vv>>^^>^<^<<<vv^<<>^^<><^^<><^^><v<<v<><^v<>>^^>>>v^^^<>^<<<<><^^<vv>^v^^>vv^<>^^^<<<<^^><><>v^^>>>^>v>vv^<v^<><v^<<>><<v^<<v>>^>v>>vvv><<v<>^v^vvv<<^<><<<<v^v>v<<^^>v<vv<^^^vv^<^vv>^<>^<^v^<<v^>^vv<>>vv^>v^<>><><><><^v^>v<<vvv>>^v>v><<v<><vv^>>>^^><<<^^^^v<>v^<>>>"
"^vv>>>><v^v<><v>^<<vv>^<^>v>^<^v^v<^v>><v^>><<><>^<v<v<>^<v><v<><<<v><^>>^^>v<<v<<v^vv^>^^>>>^<<v^v>v^vv>vv>>vv<^^<><<^^^<<v>>v^>>^>><v<v^v<^>>v<^<vv>v^vv^<<<v<^<<<><v>^^v>^v^>>vv^v<>v^v<<<^^^>^v^vv^^>>>^>v<><^><<v<>>^v<^v<<^<<><>>^vv>^^>>>v>v<<vvv^v<>vv>^>>v<<>^vv<<<>vv><>>^<^<>^^^v^^v^v^<<^>v<^<<^><>v^<<<v<><<<vv>^>>>v^v<><v>^v>v>v^^vv^vv^>^^^>^v^<^v>>><^vvv<^>^<^vv><v<<>>^^^>v>v<>v^v<v^^<^^vv>>v^<^v^<>vv<<v<>>vv>^><<>^^>>^>^v<^>^<>><>v>v<^^^<<^<>><^^v>>^>v<v<^>^^vv>>^<>>><<v>^^^<^>^^^>v^>>^^><>v^^v^^^^><<><^^<v^>>^>vv<^>vv>><>v<^>>^<^v><v^<<vv>^<vvv^<<^^v^>^v<vv>^><<<<>v>^>>vv>^>v^>^v>^<v^>>>v^^<^<v<<^<v<><v<vv^v>^^vvvv^v>^v<v>^>^^^vvvv^>^>v^>>vv>^<v^<^v><<v^>>^>^>^>^^^v><v><<>v>^>^^v>>>^>><>>^<^v<vvv^^<>>vv^^v^^v<<<v>^<^>vv>>v<^<^vv>>^^>v<>v><v^>v><<>^v>^v<<^<<>v^><v^>^^^><><vvv^<^^^^>v^v^<^^v><^>vv^>>>><<^<><v>^><><<>v^v^<<<^^<<<v^^>^^v>><>><v^>^<v>^^<^^<v>v^<>>^><^<^>v^vv<^<>^<<v><<<>>^>v^v>>^^v>v><v^<^^^v>>v<^<^v>^<>v>v<<>>>v<<<^>v^^<<^v<<v><^vv^>>^>>^<<v<v>^<^<^>^^^v><^>>v<vv<<"
"^<v^<<^<vv^^v^v>><v>>v<>v>^><>^v>>v<>v<v^<<><>^v<<><^>vv<><^>>v><vvv<><^^<^v<<^^^<^<<>><^>^v><^<<>^^>v>vv^>^vv>><v<<^<<<<^<v^vvvvv><^^<^^>^^><>>^><>vv<^>^<<>v<^^v>><<<^v<^^>>^<^>v<vv^><^vv<>^^>v<>^v><<^<><>^vvv<^<v>^^>^^v<^><<v^>v<<<^^v<v<v>v<^>>v^v>^^^<^^<v>>><<<<^v<>vv<v<v^v<v>^^v<^>v>v^>v<^>^^<><v<v<^^v^^>>^^><>^^v<v^^>^^v>^>v^v>>^v^v^>v<^><>>>^<vv^^<^>^<v^>^<><<vv><^^^<>v^v<v>^^v>^v><^>>vv><<v<<<>v<vv<<^>><>>^<^^>^<<vv^^><<v>><>><>v^^^>^<^v<^<^v^v^v>^<^^>^^v<^><<<v>>>^vv>>v>v<v<><<vv<vv<^v^<>^<>vv^^^v^v^v^<>>>v<vv>>>^>><^<<^>vvv<^>>>>>>>v^>>^^>>^v>^>^>v^>^^^^<^>>v^>v^<v><v^^<^^v>><><<^^^<v^<v>v<^<><<>^<<v<^<v<<<>v><>vv^<v>v>>v>>^>^<>>^>^><^^v^v^^<^>^^<v>v^<^<<>^<>><<v<v><^^>v><^>^v<^>v^<v<><<>><><<^^v>>v>^<^v<v^>v>><^^^^v>^<v>>>^>v^^<v>><vvv<<^^<vvvv<^v^v>^v^><v>><<^^^<<v><^^<>v><<<v<>v^^<v<^^<vv^^>><>v^v<^^>v>>>v<^<><^><<<vvv><><v^v^<>>v<<v<<v^<^><>^v^vv<>v<^<<^<^>v><^<v^^^<^^v^<^<v^^^^vv^^^<><^><vvv>^>>v^<v^^><v^^v^<<<<<<<v<^^v>vv^^^<v<>vv^^v>>>vv<<vv>vv>^v>^><v^^^>>v>><>^v^<><>>"
"v^v>^<>><<<<>>>>v<v^^v^<^v><<>^>><>^<v>v<>vvv^>><vv>^v<<<>vv>^<v^^<^^<><>v^<>v^>><>v<^><<>^<v<v<^<<v<<<^v<<v<>v<<^^<v^v><^vv^^v<><^<>v<<<<^>><><v<<>^^^<>>^^^<v>>v^<<^>^<vvv<^<v<><v^<<<<^><v<v<v<<v<<v^<v>vv>^^v><>v><>><<<v^^vv<><^<>vv>^^v>^>v<vvv<v^v^^<^v^v^<^vvv>>^v><v<<<>^><<<^^<^>v>vv>v>vvv><<^<<vv<>v>^<v<><<<>>^vv>^v<v>^<>>>^<vv^v>><v<<><^>^^>v>>>^v<>^><><^v^^<^<>^<v^v<v<<<><^>vv^v^><v<^<<<^>vv^><<^^<^>><v^<>>v<><<<><v^^v>>^v^v<v^^>>^^>>>>v><<>^v^^>^>v^^<>>>^^<v^<v><>>>v^<^>^v<^v<^>^><<>vv<v^>^>><vv<v<vvv>^v<>^>^^v^>^<^^v>v<v>>^<<>><<<<^vvv^v^^>vv><<^v^^<>>^<<<^<v><<<<>>><^^<>v^v^vv^<<<<<^>><><^^<<v^v^^>^vv><>^><<>^vv<v<<^^>>v^v><>>>v<v<^v^^>><v<^v^^^vvv<>v><<v^<<vv<<^>>v<^v<vv^v^>^<<<>v^>>>>^>^><<><vv^^v><^^^v^^^<<><<<^^>^>^v>><<><^<>vvv>v^>^^><^>v>><^v^vv^>>^^>>v>v<<>^^<<<v<>>^vv>^v^>>v<<>><<<>^>>^>^vv<>^^^vv<<<vvv^<vv^^<<v^^^^<^^v^v>vv>v<v^^vv^<v<>vv>>>^<^^>>^^<><v<v><vv^vv<>^vv<^vvv^>vvv<v<v^v>>><v><<vv^<^vv<^^vv<^>>^>>><^>v^vv^v<^^^>>><vvv>v>vvv>v^v<vv^<v^vv^^<>v^>v^^^^^<<v<><>"
"v^<>^v>^>v<^>^<^<v^^^vv^<^<<<<<<^^^<v^<>>>vv^<>>vvvvv<>vv>vv<v<><^<<^^>^vv<<v><v^^^<<v><<^^vv<^^>>><<<>^><<^^<>vv^>^>^vvv^v><vv^v>^^<v^^^^<>^<v<>^<^>v<>>>^>^^v<<>><v><><vv>v<>>v^vv<>vv^^v<>^v^>^^^^^^<>><v>>^<^<v><^vv^<>>>>^^><v<^v<^^^>v<<vv><><><<<vv^<<^<>>>^><vv>vv^<>>v^<^vv^v^^^><v^vv>><^>^<^>>>>v>vvv^^^>vvv^>>>v<<<>^^<<<^<^<v^>><^<<>vv>^v><^^^v<<>>>^><vvv<>>^v^<^<^^><>^^^<^^<>^^vv<^v><^>>v^>^>v^<vv>>>>vv><^^<^vv<^<^^v>>v^^<v>>>^v<v^>^^>^v>>v<>^>^<^<^^^^<^>>^>v<v>^^><>>^<v^vv><^v<>><<>^<<><<v>v>^^<v>>>>v^><>^^<>>vv<^>^v>>v><<v>^v><^>v<<v^>v<<<<>^v<^<<>^><v^<v<^>^v^<^^^><<^<vvv>v>><<v>v>v><^v<^<^>^>^><<<>^>^>^<^v>v^^><<>^vvv^<<vv^<^<v<>v<vvv>^<><>>><<<>v<^>>>v><>><vv<v>^v^v><<<>vvv>^^<^^<v>^>>v<^><^v<>v^v>^^<<<^>v>^v<>v^^<^<>><<v<v>v<<v^>v^<^^<<<<v^v><>v>vv^^^>^vv>>>>v>vv^<v^><<^<^>>v^^v<<>v><^v>^v<<><><v<^>v^v^vv^<^v<<<^>><v^>^>><v<>>^^vv><<<^<<v<^>^>^<>^>v<^>v<^<^^<>v<<v><v>^^><<<><><<<><^>vv<^^>>^<<v^<^<^>^^v>v<^^v><v><^^v>>^>>vv^^v>^>>>v<<v>>^<^v^^><v<><v<>>v>v^v>v<^^>v^><v<<v><>^"
"<>>>^<^<<v<>^<v^^^^vv^<>>^v<v^vv^>>^vv>^<v>^vvvvv>^>^<<vv>>vvvv^><^<><<<v^>v<>^>^>v<vv<<v>v^vv^>vv^v>>^vvv<>^<<v^<v>>^<v^<^v>v^><^^^>v^<<^^<<vvv>v<<^>v^v>^^vv<^<<<vvv><>>v^<^^><v<^v<>^>v>v<<<^<^^^>^>vv<<<><^v<>^<v^<vv^^v>v^^v>>^<vv<>^>^>>^^<v>v^<<>^>>v^v<>><<vv^><<>^<^>^<v>^>>vvv^<vv^^^><vvv<v^v^<>>^^v>>^^<<<><>v^v><<>>^vvvv<vv<v^>>>v>v><<>>^v^^>v<<^v><<^v<^vv>v^<<<^v<><^>^>v^><<<v<^<<<^><<v>><^^v>><<>v<v<^<v>^^<<v^v<>>>>v>v^>^^^v<v<<v><^^^^^^<>vv><v<^<v>>^<v<<<v<v^<^><>>v>v<^^^vv<^v^<v<><>>>^><^<<<vv^>><^>>v<>v<>^<>v^<^><<><^<><<v^<>v>^<>^><v^><<^>^<<v><<<>><>v><<>v<^>v<v<<^^<<<^<>>>^>>^>v^>^<>>><<><^>^^>^vv<^><^<^<<>vv<<<^v<^^<<^<v><<<^<<^vv>v^v>^v<^>^vvv><vvvv>v<>>^^vvvvv^^v<v<<><><<>^>>>vv<^^v>^<vv^<>v^v<>>>>>>^>>v<^<>><<<^v>>v^<vv><>><<^<^^^>v<v^><>v^>>vv><^vv>vv>v^^><<>vv>v>>^>v<v^v>>^^v<^>><>^vvv>^>>^<v<v^^v^^><>>>^<>v^<><^><v^v<^^>>^<>><v><v^<><^^^v>^^^>^><<v^vv>>v>v^vv<v^v>>><<>^^v><<v<v<vv>><^><vv<>v>^<<^>^vvv^>>>>vv<<v<<>v^^>>^vvvv>v>^^^<<<^v<^>>v><^v^v^v><<<^^<^<^^v<^>><^v^"
"^<v^^v^<><>^<^^^^v<vvvv<>>v^v<v<<>>^^<<v>v<<v<v>>><^>v^^v>>v^^v^v^>>><<^<>v^v>^^^v^^>^>><^>>v^><v^v><^>>>vvv><v>v<><^<v<<>^<<><^<^><^^<<^<v<>^><^><^><<>v>><>v^>vvvv><<^><v>^^<v>><v><>^v<^^<>^v>v^>^<^v>^^>^>^^v>^>>v<v>><^^>>v><<<^v^>>^vvv<^v>vv<v^<v^vv^<<^^v^^v^^>>>^<>v>^<>v^>^vv>^<^>>vv><vv><vv<<^<>v^>^v^^<><<<v<<<><<>v^v^v<v<>>><^<v^<^>v<<^><>>vvv<^>>vv>v^<^^<^^<>>^<<^><^<^v>v^v<<>v^^^^<>v>>^v^<<^<v^v>^><>>><>><v<<^<>v^<^^^>^^v^^<<>^v<<><>^v>>^v<<^>^v^v<v<^^^v>><v<^><v^v<>v<<^<vv^<><vv><>>^>>^>>>^^^v^v>vvvvv>>^>>v^>v<>v><><><>v>v^>v>vv^^<^>^><^<v^^v><>v<<<^v>>^>vv>v<v^<^v<^v<><vv<^^^<<v>v<v^v^>>v<^v^^^v<v>^<^^><v>v^<<<>^<v>>^<vvv^v^^><v^>>>vv>>^<^>vv><v^^><<>v^v^^>v^^>^v<<vv><^><^^>^^<^<<>>^>v<vv^><^vv^vv^^vv>^>^><>><<^><<^<><^^<<^<><v>v^^^^><vv>^vvv<<v<>^^><<^vv<^>^<^<<<v<^vv<>>v<vv^>^^<^<>^>^><^>>^<^>>v<>v^^vv<<vv^>v<><>><^>^><<<>>^v<>>v^^^>v^^<^>^^v>><<>v^<vv<>^^^<>^^<>>>v^>^vv<>vv><vvv^><v>><^<v>>>v<<v>^><<v<>v><vv<v^vv<^>><>^v^^^>>>>^^v>v>^>>^v><v>^<<<v^>v<>v<v<v^v^>><^>>^>>v^^>v"
"v<<>v<<v><<>vv^v><<^<v><^^<>>>><vv>>v<vv^v>v^vv<^^><^v^^>^vv>v>^<><<^<>>v^>>>^^>^^<v><v^>><^><<^v>v><v<v^>^>^^>v>><>^<<<<v^>>v^v>vv><v<v>^^>v><^>v^vv<v^>><<^><^^v><^<<>v^^vv<<>>^^<^vv^<<^>>^v^><v^^>>^^vv^>v<v>><vv<v<<<v<>><^>>^<<^<>^>>>v>v^v>v>^^>vv^<v>>><v^<><<v^>v^^<>><<v^^v>v^vv>>>><v>v<<<<^>^^^v>vv>v>v<v>^^<v^^^^<>^<<v^>^<>^<>v<vv<>v^v>v>v>^v<>^v<<^><^v>v^v<v>>>>vv>v^>v<<^vv^<>^<^v^vvv>>v><<^>v>v>vv>^<^>>^<^v><v<<^<v<>^v<>^^>><>^>v><<^^v^v^v<<<<v><v>>>>>^^<>>v<>^>^<v>>>v^^v^>>v>^<<<<<><<vv>vv>>>><^>>vv^^^<^<><^>^<vv>><<^^^>^<v<><v<^>v<^<^>vv^vv<^<v<^<>^v^>>>v>>v^<<>^v<^^^>^v<v>>><<>vv<<>>>>v><<><v^<<^<><^^vvv<<<<^^>^<>><>^v^><<><^^<<^<>^^>v^<<>>^v^^>><<^vvv<^>><>^^<<>^<^>>>^^<>^<<<<>><v<v^<^>^<v<^>>>^v^v^^v<><<<v>>v^^vv>v>v<>>v>><v<>>>^v><v^>^v^<<><>^^<>>>vv>^<>^^vv<<^v<v<^>>><<><v^vv^vv<>^>^>>>v>v><<v^>^>><v><<^^><^>^<vv><<v<>v^<>v>^^<<>>v>^^^^v>>><v>^>v<^^^<<v><vv<v>vvv<>vv>vv^><^<<v<>>^v<<^^v^>v<>>>^^vvv^<^<>^>>^<>^<<><^>>v>>>v<<><<v>v>^^^>>v<<>>>vv>>^^>><><>>^<vv>v^>>>>v>>vvv<>"
"<<><><^^>v>><<^^vvv>^<>>><v>^v>^^^v^<v>>v>>^<^^<<<<v<>>vvv>^^>>vv><><>^>>><><^<^v^vv>>v<v<<^v>>>v^>v<><^^v>>^v^v<>><><vv>>v<<>vv^^^>v^<<v<<^v^^v^v<<^>>^vv^^v><><<<<^>>vv^^<v<<<><<<^^^v^vv^<<><v^^v^v^^>^v<<>^v>^>^<^^<<>>^v^>v<<>^>v>><<>vv>>^^v><^<^<>>^^>^^^<v<^>><^^>v<^<>v^^<>>v>^v<<v<<^>^>v><<>>^<>>v<<><>^vv<vv<><v<^v>vv<>>vvv^<<>v<>>>v^^^^^^<^^>v>^<^^>vv>vv<v<^v^>^^<v^^>^>v^v>^^<vvv>v^v^^v^>v^<>^<v>v>vv<<^v^<^^>>v^^v><><^><<^vv^v^>>^>>>vv^<^^v<>>^^^v<<v^^><v<v^vv<v>^><<>v<vvv><>vv^>vvvv<v<v>>>^v^<<^v>^^^>v<v^>>vvvv><>^^vv^^v>^>vv^vv^<v^<^^vv^^^><<>vv^v>^vv<v>^v<<^<^^>>vvv>v><^<>><vv^<<>vv^v^<^>^<<vv^<<^v><^<<v>^v><vv^<^^>v>vvv<><^v<vvv<>><^^<^>^v<^><<^v<^^^<>^>v^^>^^vv><^<>>v^v>v^>v<<^<>>vv>^v><^v^<^<v^vv<^^>v>>^<vv<<vvv^><vv<v>>v<^>>v^<^v<v<<v^>><vv><>v^v<<^v<v<>^><^^v^<^^>>>v<^<v<<v<>><^<^^vv<<v>><<<v<<>^vv^<>><>^^<v><>^^v<v>vv>^<>^<<>^^v<^^<<^v<<^^><^v<v>vvvvv>^v<^^>>>>^vvv<v>^><v^<><>^<<<^^^<<>vvv>><^^<<^^v^>v^<^v<>v><v^^^v>v>>>vv>^>>v<v>v><><^v^>v<>^<^^v>^<>>^<v>^>^^v>v^v<^^>><<>"
};