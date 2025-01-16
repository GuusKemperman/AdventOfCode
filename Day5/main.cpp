#include <array>
#include <vector>

auto get_page_order()
{
	std::array<std::vector<int>, 100> arr{};
	arr[48].emplace_back(17);
	arr[38].emplace_back(73);
	arr[38].emplace_back(78);
	arr[72].emplace_back(63);
	arr[72].emplace_back(95);
	arr[72].emplace_back(54);
	arr[39].emplace_back(56);
	arr[39].emplace_back(64);
	arr[39].emplace_back(42);
	arr[39].emplace_back(57);
	arr[22].emplace_back(27);
	arr[22].emplace_back(44);
	arr[22].emplace_back(64);
	arr[22].emplace_back(72);
	arr[22].emplace_back(21);
	arr[84].emplace_back(14);
	arr[84].emplace_back(12);
	arr[84].emplace_back(99);
	arr[84].emplace_back(81);
	arr[84].emplace_back(38);
	arr[84].emplace_back(61);
	arr[63].emplace_back(64);
	arr[63].emplace_back(89);
	arr[63].emplace_back(96);
	arr[63].emplace_back(73);
	arr[63].emplace_back(24);
	arr[63].emplace_back(54);
	arr[63].emplace_back(71);
	arr[74].emplace_back(17);
	arr[74].emplace_back(84);
	arr[74].emplace_back(42);
	arr[74].emplace_back(45);
	arr[74].emplace_back(39);
	arr[74].emplace_back(54);
	arr[74].emplace_back(97);
	arr[74].emplace_back(51);
	arr[95].emplace_back(14);
	arr[95].emplace_back(34);
	arr[95].emplace_back(43);
	arr[95].emplace_back(17);
	arr[95].emplace_back(51);
	arr[95].emplace_back(54);
	arr[95].emplace_back(94);
	arr[95].emplace_back(24);
	arr[95].emplace_back(74);
	arr[13].emplace_back(61);
	arr[13].emplace_back(56);
	arr[13].emplace_back(57);
	arr[13].emplace_back(38);
	arr[13].emplace_back(75);
	arr[13].emplace_back(28);
	arr[13].emplace_back(21);
	arr[13].emplace_back(63);
	arr[13].emplace_back(95);
	arr[13].emplace_back(64);
	arr[12].emplace_back(93);
	arr[12].emplace_back(74);
	arr[12].emplace_back(34);
	arr[12].emplace_back(29);
	arr[12].emplace_back(78);
	arr[12].emplace_back(19);
	arr[12].emplace_back(28);
	arr[12].emplace_back(73);
	arr[12].emplace_back(75);
	arr[12].emplace_back(27);
	arr[12].emplace_back(38);
	arr[24].emplace_back(39);
	arr[24].emplace_back(13);
	arr[24].emplace_back(97);
	arr[24].emplace_back(99);
	arr[24].emplace_back(84);
	arr[24].emplace_back(27);
	arr[24].emplace_back(61);
	arr[24].emplace_back(68);
	arr[24].emplace_back(51);
	arr[24].emplace_back(22);
	arr[24].emplace_back(57);
	arr[24].emplace_back(82);
	arr[64].emplace_back(96);
	arr[64].emplace_back(38);
	arr[64].emplace_back(93);
	arr[64].emplace_back(43);
	arr[64].emplace_back(19);
	arr[64].emplace_back(73);
	arr[64].emplace_back(54);
	arr[64].emplace_back(24);
	arr[64].emplace_back(77);
	arr[64].emplace_back(48);
	arr[64].emplace_back(89);
	arr[64].emplace_back(34);
	arr[64].emplace_back(71);
	arr[28].emplace_back(51);
	arr[28].emplace_back(39);
	arr[28].emplace_back(27);
	arr[28].emplace_back(19);
	arr[28].emplace_back(17);
	arr[28].emplace_back(93);
	arr[28].emplace_back(74);
	arr[28].emplace_back(84);
	arr[28].emplace_back(45);
	arr[28].emplace_back(83);
	arr[28].emplace_back(54);
	arr[28].emplace_back(69);
	arr[28].emplace_back(24);
	arr[28].emplace_back(22);
	arr[82].emplace_back(19);
	arr[82].emplace_back(43);
	arr[82].emplace_back(72);
	arr[82].emplace_back(12);
	arr[82].emplace_back(96);
	arr[82].emplace_back(38);
	arr[82].emplace_back(28);
	arr[82].emplace_back(73);
	arr[82].emplace_back(77);
	arr[82].emplace_back(74);
	arr[82].emplace_back(17);
	arr[82].emplace_back(75);
	arr[82].emplace_back(14);
	arr[82].emplace_back(85);
	arr[82].emplace_back(48);
	arr[96].emplace_back(19);
	arr[96].emplace_back(94);
	arr[96].emplace_back(45);
	arr[96].emplace_back(69);
	arr[96].emplace_back(84);
	arr[96].emplace_back(22);
	arr[96].emplace_back(27);
	arr[96].emplace_back(13);
	arr[96].emplace_back(97);
	arr[96].emplace_back(24);
	arr[96].emplace_back(56);
	arr[96].emplace_back(98);
	arr[96].emplace_back(17);
	arr[96].emplace_back(33);
	arr[96].emplace_back(57);
	arr[96].emplace_back(71);
	arr[89].emplace_back(29);
	arr[89].emplace_back(75);
	arr[89].emplace_back(19);
	arr[89].emplace_back(77);
	arr[89].emplace_back(17);
	arr[89].emplace_back(93);
	arr[89].emplace_back(38);
	arr[89].emplace_back(94);
	arr[89].emplace_back(24);
	arr[89].emplace_back(96);
	arr[89].emplace_back(95);
	arr[89].emplace_back(71);
	arr[89].emplace_back(22);
	arr[89].emplace_back(14);
	arr[89].emplace_back(28);
	arr[89].emplace_back(34);
	arr[89].emplace_back(51);
	arr[81].emplace_back(63);
	arr[81].emplace_back(82);
	arr[81].emplace_back(71);
	arr[81].emplace_back(73);
	arr[81].emplace_back(77);
	arr[81].emplace_back(21);
	arr[81].emplace_back(95);
	arr[81].emplace_back(75);
	arr[81].emplace_back(14);
	arr[81].emplace_back(74);
	arr[81].emplace_back(96);
	arr[81].emplace_back(43);
	arr[81].emplace_back(38);
	arr[81].emplace_back(19);
	arr[81].emplace_back(34);
	arr[81].emplace_back(48);
	arr[81].emplace_back(89);
	arr[81].emplace_back(29);
	arr[85].emplace_back(19);
	arr[85].emplace_back(14);
	arr[85].emplace_back(24);
	arr[85].emplace_back(48);
	arr[85].emplace_back(96);
	arr[85].emplace_back(34);
	arr[85].emplace_back(73);
	arr[85].emplace_back(77);
	arr[85].emplace_back(89);
	arr[85].emplace_back(28);
	arr[85].emplace_back(95);
	arr[85].emplace_back(38);
	arr[85].emplace_back(22);
	arr[85].emplace_back(71);
	arr[85].emplace_back(74);
	arr[85].emplace_back(12);
	arr[85].emplace_back(93);
	arr[85].emplace_back(98);
	arr[85].emplace_back(54);
	arr[99].emplace_back(75);
	arr[99].emplace_back(12);
	arr[99].emplace_back(17);
	arr[99].emplace_back(73);
	arr[99].emplace_back(29);
	arr[99].emplace_back(21);
	arr[99].emplace_back(43);
	arr[99].emplace_back(34);
	arr[99].emplace_back(71);
	arr[99].emplace_back(14);
	arr[99].emplace_back(72);
	arr[99].emplace_back(85);
	arr[99].emplace_back(48);
	arr[99].emplace_back(38);
	arr[99].emplace_back(77);
	arr[99].emplace_back(82);
	arr[99].emplace_back(89);
	arr[99].emplace_back(28);
	arr[99].emplace_back(95);
	arr[99].emplace_back(74);
	arr[14].emplace_back(24);
	arr[14].emplace_back(71);
	arr[14].emplace_back(17);
	arr[14].emplace_back(38);
	arr[14].emplace_back(34);
	arr[14].emplace_back(28);
	arr[14].emplace_back(94);
	arr[14].emplace_back(77);
	arr[14].emplace_back(51);
	arr[14].emplace_back(48);
	arr[14].emplace_back(54);
	arr[14].emplace_back(73);
	arr[14].emplace_back(75);
	arr[14].emplace_back(98);
	arr[14].emplace_back(78);
	arr[14].emplace_back(93);
	arr[14].emplace_back(43);
	arr[14].emplace_back(96);
	arr[14].emplace_back(27);
	arr[14].emplace_back(22);
	arr[14].emplace_back(74);
	arr[42].emplace_back(82);
	arr[42].emplace_back(61);
	arr[42].emplace_back(72);
	arr[42].emplace_back(95);
	arr[42].emplace_back(48);
	arr[42].emplace_back(99);
	arr[42].emplace_back(68);
	arr[42].emplace_back(56);
	arr[42].emplace_back(28);
	arr[42].emplace_back(57);
	arr[42].emplace_back(89);
	arr[42].emplace_back(77);
	arr[42].emplace_back(21);
	arr[42].emplace_back(63);
	arr[42].emplace_back(12);
	arr[42].emplace_back(43);
	arr[42].emplace_back(29);
	arr[42].emplace_back(38);
	arr[42].emplace_back(34);
	arr[42].emplace_back(64);
	arr[42].emplace_back(14);
	arr[42].emplace_back(85);
	arr[19].emplace_back(45);
	arr[19].emplace_back(99);
	arr[19].emplace_back(98);
	arr[19].emplace_back(13);
	arr[19].emplace_back(42);
	arr[19].emplace_back(54);
	arr[19].emplace_back(39);
	arr[19].emplace_back(83);
	arr[19].emplace_back(27);
	arr[19].emplace_back(97);
	arr[19].emplace_back(56);
	arr[19].emplace_back(24);
	arr[19].emplace_back(44);
	arr[19].emplace_back(22);
	arr[19].emplace_back(61);
	arr[19].emplace_back(33);
	arr[19].emplace_back(94);
	arr[19].emplace_back(51);
	arr[19].emplace_back(69);
	arr[19].emplace_back(84);
	arr[19].emplace_back(93);
	arr[19].emplace_back(57);
	arr[19].emplace_back(78);
	arr[93].emplace_back(57);
	arr[93].emplace_back(22);
	arr[93].emplace_back(44);
	arr[93].emplace_back(98);
	arr[93].emplace_back(33);
	arr[93].emplace_back(42);
	arr[93].emplace_back(39);
	arr[93].emplace_back(94);
	arr[93].emplace_back(56);
	arr[93].emplace_back(99);
	arr[93].emplace_back(82);
	arr[93].emplace_back(84);
	arr[93].emplace_back(45);
	arr[93].emplace_back(61);
	arr[93].emplace_back(24);
	arr[93].emplace_back(69);
	arr[93].emplace_back(78);
	arr[93].emplace_back(27);
	arr[93].emplace_back(81);
	arr[93].emplace_back(83);
	arr[93].emplace_back(97);
	arr[93].emplace_back(68);
	arr[93].emplace_back(13);
	arr[93].emplace_back(51);
	arr[94].emplace_back(22);
	arr[94].emplace_back(81);
	arr[94].emplace_back(99);
	arr[94].emplace_back(57);
	arr[94].emplace_back(42);
	arr[94].emplace_back(83);
	arr[94].emplace_back(68);
	arr[94].emplace_back(27);
	arr[94].emplace_back(78);
	arr[94].emplace_back(39);
	arr[94].emplace_back(13);
	arr[94].emplace_back(63);
	arr[94].emplace_back(51);
	arr[94].emplace_back(45);
	arr[94].emplace_back(56);
	arr[94].emplace_back(44);
	arr[94].emplace_back(33);
	arr[94].emplace_back(72);
	arr[94].emplace_back(61);
	arr[94].emplace_back(69);
	arr[94].emplace_back(97);
	arr[94].emplace_back(21);
	arr[94].emplace_back(82);
	arr[94].emplace_back(84);
	arr[97].emplace_back(82);
	arr[97].emplace_back(61);
	arr[97].emplace_back(83);
	arr[97].emplace_back(57);
	arr[97].emplace_back(56);
	arr[97].emplace_back(14);
	arr[97].emplace_back(64);
	arr[97].emplace_back(38);
	arr[97].emplace_back(85);
	arr[97].emplace_back(13);
	arr[97].emplace_back(95);
	arr[97].emplace_back(99);
	arr[97].emplace_back(42);
	arr[97].emplace_back(12);
	arr[97].emplace_back(68);
	arr[97].emplace_back(72);
	arr[97].emplace_back(63);
	arr[97].emplace_back(89);
	arr[97].emplace_back(21);
	arr[97].emplace_back(44);
	arr[97].emplace_back(84);
	arr[97].emplace_back(69);
	arr[97].emplace_back(81);
	arr[97].emplace_back(45);
	arr[61].emplace_back(14);
	arr[61].emplace_back(82);
	arr[61].emplace_back(12);
	arr[61].emplace_back(63);
	arr[61].emplace_back(89);
	arr[61].emplace_back(75);
	arr[61].emplace_back(74);
	arr[61].emplace_back(77);
	arr[61].emplace_back(29);
	arr[61].emplace_back(68);
	arr[61].emplace_back(96);
	arr[61].emplace_back(48);
	arr[61].emplace_back(34);
	arr[61].emplace_back(72);
	arr[61].emplace_back(95);
	arr[61].emplace_back(85);
	arr[61].emplace_back(64);
	arr[61].emplace_back(81);
	arr[61].emplace_back(21);
	arr[61].emplace_back(73);
	arr[61].emplace_back(43);
	arr[61].emplace_back(99);
	arr[61].emplace_back(38);
	arr[61].emplace_back(28);
	arr[27].emplace_back(56);
	arr[27].emplace_back(64);
	arr[27].emplace_back(97);
	arr[27].emplace_back(69);
	arr[27].emplace_back(99);
	arr[27].emplace_back(33);
	arr[27].emplace_back(45);
	arr[27].emplace_back(81);
	arr[27].emplace_back(21);
	arr[27].emplace_back(72);
	arr[27].emplace_back(95);
	arr[27].emplace_back(89);
	arr[27].emplace_back(61);
	arr[27].emplace_back(44);
	arr[27].emplace_back(85);
	arr[27].emplace_back(82);
	arr[27].emplace_back(68);
	arr[27].emplace_back(83);
	arr[27].emplace_back(57);
	arr[27].emplace_back(63);
	arr[27].emplace_back(39);
	arr[27].emplace_back(84);
	arr[27].emplace_back(42);
	arr[27].emplace_back(13);
	arr[57].emplace_back(34);
	arr[57].emplace_back(77);
	arr[57].emplace_back(48);
	arr[57].emplace_back(74);
	arr[57].emplace_back(28);
	arr[57].emplace_back(89);
	arr[57].emplace_back(12);
	arr[57].emplace_back(21);
	arr[57].emplace_back(63);
	arr[57].emplace_back(82);
	arr[57].emplace_back(61);
	arr[57].emplace_back(99);
	arr[57].emplace_back(85);
	arr[57].emplace_back(95);
	arr[57].emplace_back(68);
	arr[57].emplace_back(72);
	arr[57].emplace_back(38);
	arr[57].emplace_back(14);
	arr[57].emplace_back(29);
	arr[57].emplace_back(73);
	arr[57].emplace_back(64);
	arr[57].emplace_back(75);
	arr[57].emplace_back(81);
	arr[57].emplace_back(43);
	arr[78].emplace_back(56);
	arr[78].emplace_back(69);
	arr[78].emplace_back(97);
	arr[78].emplace_back(33);
	arr[78].emplace_back(72);
	arr[78].emplace_back(39);
	arr[78].emplace_back(99);
	arr[78].emplace_back(45);
	arr[78].emplace_back(21);
	arr[78].emplace_back(13);
	arr[78].emplace_back(64);
	arr[78].emplace_back(84);
	arr[78].emplace_back(61);
	arr[78].emplace_back(42);
	arr[78].emplace_back(82);
	arr[78].emplace_back(81);
	arr[78].emplace_back(83);
	arr[78].emplace_back(44);
	arr[78].emplace_back(63);
	arr[78].emplace_back(85);
	arr[78].emplace_back(68);
	arr[78].emplace_back(27);
	arr[78].emplace_back(89);
	arr[78].emplace_back(57);
	arr[43].emplace_back(45);
	arr[43].emplace_back(33);
	arr[43].emplace_back(24);
	arr[43].emplace_back(74);
	arr[43].emplace_back(78);
	arr[43].emplace_back(93);
	arr[43].emplace_back(22);
	arr[43].emplace_back(17);
	arr[43].emplace_back(51);
	arr[43].emplace_back(34);
	arr[43].emplace_back(39);
	arr[43].emplace_back(96);
	arr[43].emplace_back(27);
	arr[43].emplace_back(54);
	arr[43].emplace_back(94);
	arr[43].emplace_back(73);
	arr[43].emplace_back(69);
	arr[43].emplace_back(44);
	arr[43].emplace_back(19);
	arr[43].emplace_back(71);
	arr[43].emplace_back(77);
	arr[43].emplace_back(97);
	arr[43].emplace_back(98);
	arr[43].emplace_back(28);
	arr[29].emplace_back(43);
	arr[29].emplace_back(94);
	arr[29].emplace_back(51);
	arr[29].emplace_back(71);
	arr[29].emplace_back(24);
	arr[29].emplace_back(98);
	arr[29].emplace_back(44);
	arr[29].emplace_back(54);
	arr[29].emplace_back(96);
	arr[29].emplace_back(45);
	arr[29].emplace_back(77);
	arr[29].emplace_back(93);
	arr[29].emplace_back(74);
	arr[29].emplace_back(17);
	arr[29].emplace_back(97);
	arr[29].emplace_back(73);
	arr[29].emplace_back(27);
	arr[29].emplace_back(19);
	arr[29].emplace_back(33);
	arr[29].emplace_back(78);
	arr[29].emplace_back(34);
	arr[29].emplace_back(28);
	arr[29].emplace_back(39);
	arr[29].emplace_back(22);
	arr[56].emplace_back(72);
	arr[56].emplace_back(99);
	arr[56].emplace_back(38);
	arr[56].emplace_back(14);
	arr[56].emplace_back(77);
	arr[56].emplace_back(34);
	arr[56].emplace_back(85);
	arr[56].emplace_back(82);
	arr[56].emplace_back(21);
	arr[56].emplace_back(64);
	arr[56].emplace_back(81);
	arr[56].emplace_back(89);
	arr[56].emplace_back(75);
	arr[56].emplace_back(57);
	arr[56].emplace_back(61);
	arr[56].emplace_back(12);
	arr[56].emplace_back(29);
	arr[56].emplace_back(43);
	arr[56].emplace_back(95);
	arr[56].emplace_back(73);
	arr[56].emplace_back(48);
	arr[56].emplace_back(28);
	arr[56].emplace_back(63);
	arr[56].emplace_back(68);
	arr[69].emplace_back(57);
	arr[69].emplace_back(64);
	arr[69].emplace_back(83);
	arr[69].emplace_back(82);
	arr[69].emplace_back(72);
	arr[69].emplace_back(29);
	arr[69].emplace_back(63);
	arr[69].emplace_back(61);
	arr[69].emplace_back(56);
	arr[69].emplace_back(48);
	arr[69].emplace_back(95);
	arr[69].emplace_back(99);
	arr[69].emplace_back(89);
	arr[69].emplace_back(75);
	arr[69].emplace_back(85);
	arr[69].emplace_back(68);
	arr[69].emplace_back(42);
	arr[69].emplace_back(21);
	arr[69].emplace_back(84);
	arr[69].emplace_back(13);
	arr[69].emplace_back(14);
	arr[69].emplace_back(12);
	arr[69].emplace_back(81);
	arr[69].emplace_back(38);
	arr[75].emplace_back(94);
	arr[75].emplace_back(96);
	arr[75].emplace_back(27);
	arr[75].emplace_back(98);
	arr[75].emplace_back(17);
	arr[75].emplace_back(73);
	arr[75].emplace_back(77);
	arr[75].emplace_back(39);
	arr[75].emplace_back(74);
	arr[75].emplace_back(71);
	arr[75].emplace_back(33);
	arr[75].emplace_back(22);
	arr[75].emplace_back(28);
	arr[75].emplace_back(34);
	arr[75].emplace_back(19);
	arr[75].emplace_back(29);
	arr[75].emplace_back(97);
	arr[75].emplace_back(93);
	arr[75].emplace_back(44);
	arr[75].emplace_back(51);
	arr[75].emplace_back(43);
	arr[75].emplace_back(24);
	arr[75].emplace_back(54);
	arr[75].emplace_back(78);
	arr[45].emplace_back(85);
	arr[45].emplace_back(89);
	arr[45].emplace_back(42);
	arr[45].emplace_back(48);
	arr[45].emplace_back(99);
	arr[45].emplace_back(69);
	arr[45].emplace_back(75);
	arr[45].emplace_back(61);
	arr[45].emplace_back(95);
	arr[45].emplace_back(14);
	arr[45].emplace_back(57);
	arr[45].emplace_back(68);
	arr[45].emplace_back(81);
	arr[45].emplace_back(82);
	arr[45].emplace_back(38);
	arr[45].emplace_back(13);
	arr[45].emplace_back(83);
	arr[45].emplace_back(56);
	arr[45].emplace_back(72);
	arr[45].emplace_back(63);
	arr[45].emplace_back(12);
	arr[45].emplace_back(64);
	arr[45].emplace_back(21);
	arr[45].emplace_back(84);
	arr[98].emplace_back(21);
	arr[98].emplace_back(68);
	arr[98].emplace_back(22);
	arr[98].emplace_back(61);
	arr[98].emplace_back(56);
	arr[98].emplace_back(57);
	arr[98].emplace_back(94);
	arr[98].emplace_back(69);
	arr[98].emplace_back(84);
	arr[98].emplace_back(44);
	arr[98].emplace_back(27);
	arr[98].emplace_back(51);
	arr[98].emplace_back(45);
	arr[98].emplace_back(97);
	arr[98].emplace_back(24);
	arr[98].emplace_back(82);
	arr[98].emplace_back(78);
	arr[98].emplace_back(13);
	arr[98].emplace_back(81);
	arr[98].emplace_back(39);
	arr[98].emplace_back(99);
	arr[98].emplace_back(42);
	arr[98].emplace_back(83);
	arr[98].emplace_back(33);
	arr[71].emplace_back(84);
	arr[71].emplace_back(39);
	arr[71].emplace_back(45);
	arr[71].emplace_back(69);
	arr[71].emplace_back(68);
	arr[71].emplace_back(97);
	arr[71].emplace_back(57);
	arr[71].emplace_back(56);
	arr[71].emplace_back(44);
	arr[71].emplace_back(93);
	arr[71].emplace_back(94);
	arr[71].emplace_back(83);
	arr[71].emplace_back(61);
	arr[71].emplace_back(98);
	arr[71].emplace_back(33);
	arr[71].emplace_back(54);
	arr[71].emplace_back(78);
	arr[71].emplace_back(13);
	arr[71].emplace_back(22);
	arr[71].emplace_back(27);
	arr[71].emplace_back(24);
	arr[71].emplace_back(42);
	arr[71].emplace_back(19);
	arr[71].emplace_back(51);
	arr[68].emplace_back(21);
	arr[68].emplace_back(14);
	arr[68].emplace_back(64);
	arr[68].emplace_back(43);
	arr[68].emplace_back(75);
	arr[68].emplace_back(99);
	arr[68].emplace_back(89);
	arr[68].emplace_back(96);
	arr[68].emplace_back(77);
	arr[68].emplace_back(85);
	arr[68].emplace_back(38);
	arr[68].emplace_back(34);
	arr[68].emplace_back(29);
	arr[68].emplace_back(12);
	arr[68].emplace_back(28);
	arr[68].emplace_back(48);
	arr[68].emplace_back(63);
	arr[68].emplace_back(73);
	arr[68].emplace_back(95);
	arr[68].emplace_back(82);
	arr[68].emplace_back(17);
	arr[68].emplace_back(74);
	arr[68].emplace_back(72);
	arr[68].emplace_back(81);
	arr[73].emplace_back(97);
	arr[73].emplace_back(69);
	arr[73].emplace_back(45);
	arr[73].emplace_back(22);
	arr[73].emplace_back(33);
	arr[73].emplace_back(71);
	arr[73].emplace_back(39);
	arr[73].emplace_back(13);
	arr[73].emplace_back(17);
	arr[73].emplace_back(19);
	arr[73].emplace_back(96);
	arr[73].emplace_back(94);
	arr[73].emplace_back(54);
	arr[73].emplace_back(98);
	arr[73].emplace_back(84);
	arr[73].emplace_back(44);
	arr[73].emplace_back(83);
	arr[73].emplace_back(74);
	arr[73].emplace_back(27);
	arr[73].emplace_back(78);
	arr[73].emplace_back(42);
	arr[73].emplace_back(93);
	arr[73].emplace_back(24);
	arr[73].emplace_back(51);
	arr[83].emplace_back(75);
	arr[83].emplace_back(42);
	arr[83].emplace_back(48);
	arr[83].emplace_back(43);
	arr[83].emplace_back(84);
	arr[83].emplace_back(13);
	arr[83].emplace_back(12);
	arr[83].emplace_back(82);
	arr[83].emplace_back(68);
	arr[83].emplace_back(63);
	arr[83].emplace_back(21);
	arr[83].emplace_back(38);
	arr[83].emplace_back(29);
	arr[83].emplace_back(95);
	arr[83].emplace_back(85);
	arr[83].emplace_back(56);
	arr[83].emplace_back(61);
	arr[83].emplace_back(99);
	arr[83].emplace_back(64);
	arr[83].emplace_back(81);
	arr[83].emplace_back(89);
	arr[83].emplace_back(14);
	arr[83].emplace_back(72);
	arr[83].emplace_back(57);
	arr[54].emplace_back(33);
	arr[54].emplace_back(24);
	arr[54].emplace_back(69);
	arr[54].emplace_back(93);
	arr[54].emplace_back(13);
	arr[54].emplace_back(84);
	arr[54].emplace_back(99);
	arr[54].emplace_back(68);
	arr[54].emplace_back(42);
	arr[54].emplace_back(97);
	arr[54].emplace_back(83);
	arr[54].emplace_back(22);
	arr[54].emplace_back(98);
	arr[54].emplace_back(45);
	arr[54].emplace_back(51);
	arr[54].emplace_back(81);
	arr[54].emplace_back(78);
	arr[54].emplace_back(61);
	arr[54].emplace_back(27);
	arr[54].emplace_back(94);
	arr[54].emplace_back(56);
	arr[54].emplace_back(39);
	arr[54].emplace_back(57);
	arr[54].emplace_back(44);
	arr[33].emplace_back(44);
	arr[33].emplace_back(81);
	arr[33].emplace_back(82);
	arr[33].emplace_back(89);
	arr[33].emplace_back(42);
	arr[33].emplace_back(72);
	arr[33].emplace_back(12);
	arr[33].emplace_back(84);
	arr[33].emplace_back(61);
	arr[33].emplace_back(63);
	arr[33].emplace_back(69);
	arr[33].emplace_back(45);
	arr[33].emplace_back(64);
	arr[33].emplace_back(97);
	arr[33].emplace_back(57);
	arr[33].emplace_back(99);
	arr[33].emplace_back(85);
	arr[33].emplace_back(83);
	arr[33].emplace_back(39);
	arr[33].emplace_back(21);
	arr[33].emplace_back(13);
	arr[33].emplace_back(68);
	arr[33].emplace_back(95);
	arr[33].emplace_back(56);
	arr[77].emplace_back(39);
	arr[77].emplace_back(27);
	arr[77].emplace_back(73);
	arr[77].emplace_back(54);
	arr[77].emplace_back(96);
	arr[77].emplace_back(24);
	arr[77].emplace_back(34);
	arr[77].emplace_back(98);
	arr[77].emplace_back(97);
	arr[77].emplace_back(44);
	arr[77].emplace_back(78);
	arr[77].emplace_back(69);
	arr[77].emplace_back(93);
	arr[77].emplace_back(51);
	arr[77].emplace_back(33);
	arr[77].emplace_back(94);
	arr[77].emplace_back(83);
	arr[77].emplace_back(28);
	arr[77].emplace_back(71);
	arr[77].emplace_back(19);
	arr[77].emplace_back(22);
	arr[77].emplace_back(45);
	arr[77].emplace_back(74);
	arr[77].emplace_back(17);
	arr[51].emplace_back(57);
	arr[51].emplace_back(69);
	arr[51].emplace_back(33);
	arr[51].emplace_back(27);
	arr[51].emplace_back(97);
	arr[51].emplace_back(56);
	arr[51].emplace_back(85);
	arr[51].emplace_back(78);
	arr[51].emplace_back(45);
	arr[51].emplace_back(42);
	arr[51].emplace_back(61);
	arr[51].emplace_back(44);
	arr[51].emplace_back(81);
	arr[51].emplace_back(39);
	arr[51].emplace_back(72);
	arr[51].emplace_back(13);
	arr[51].emplace_back(64);
	arr[51].emplace_back(21);
	arr[51].emplace_back(99);
	arr[51].emplace_back(83);
	arr[51].emplace_back(82);
	arr[51].emplace_back(68);
	arr[51].emplace_back(84);
	arr[51].emplace_back(63);
	arr[17].emplace_back(45);
	arr[17].emplace_back(39);
	arr[17].emplace_back(19);
	arr[17].emplace_back(69);
	arr[17].emplace_back(61);
	arr[17].emplace_back(78);
	arr[17].emplace_back(98);
	arr[17].emplace_back(56);
	arr[17].emplace_back(94);
	arr[17].emplace_back(51);
	arr[17].emplace_back(93);
	arr[17].emplace_back(24);
	arr[17].emplace_back(33);
	arr[17].emplace_back(42);
	arr[17].emplace_back(44);
	arr[17].emplace_back(22);
	arr[17].emplace_back(84);
	arr[17].emplace_back(27);
	arr[17].emplace_back(13);
	arr[17].emplace_back(54);
	arr[17].emplace_back(71);
	arr[17].emplace_back(83);
	arr[17].emplace_back(57);
	arr[17].emplace_back(97);
	arr[34].emplace_back(96);
	arr[34].emplace_back(71);
	arr[34].emplace_back(84);
	arr[34].emplace_back(39);
	arr[34].emplace_back(51);
	arr[34].emplace_back(97);
	arr[34].emplace_back(13);
	arr[34].emplace_back(17);
	arr[34].emplace_back(45);
	arr[34].emplace_back(83);
	arr[34].emplace_back(27);
	arr[34].emplace_back(78);
	arr[34].emplace_back(24);
	arr[34].emplace_back(33);
	arr[34].emplace_back(74);
	arr[34].emplace_back(19);
	arr[34].emplace_back(93);
	arr[34].emplace_back(69);
	arr[34].emplace_back(44);
	arr[34].emplace_back(98);
	arr[34].emplace_back(22);
	arr[34].emplace_back(54);
	arr[34].emplace_back(73);
	arr[34].emplace_back(94);
	arr[44].emplace_back(63);
	arr[44].emplace_back(42);
	arr[44].emplace_back(83);
	arr[44].emplace_back(64);
	arr[44].emplace_back(81);
	arr[44].emplace_back(85);
	arr[44].emplace_back(57);
	arr[44].emplace_back(95);
	arr[44].emplace_back(89);
	arr[44].emplace_back(48);
	arr[44].emplace_back(61);
	arr[44].emplace_back(84);
	arr[44].emplace_back(13);
	arr[44].emplace_back(21);
	arr[44].emplace_back(56);
	arr[44].emplace_back(12);
	arr[44].emplace_back(38);
	arr[44].emplace_back(69);
	arr[44].emplace_back(72);
	arr[44].emplace_back(68);
	arr[44].emplace_back(14);
	arr[44].emplace_back(82);
	arr[44].emplace_back(45);
	arr[44].emplace_back(99);
	arr[21].emplace_back(71);
	arr[21].emplace_back(75);
	arr[21].emplace_back(63);
	arr[21].emplace_back(19);
	arr[21].emplace_back(34);
	arr[21].emplace_back(74);
	arr[21].emplace_back(73);
	arr[21].emplace_back(89);
	arr[21].emplace_back(54);
	arr[21].emplace_back(96);
	arr[21].emplace_back(93);
	arr[21].emplace_back(77);
	arr[21].emplace_back(95);
	arr[21].emplace_back(29);
	arr[21].emplace_back(14);
	arr[21].emplace_back(72);
	arr[21].emplace_back(64);
	arr[21].emplace_back(12);
	arr[21].emplace_back(48);
	arr[21].emplace_back(38);
	arr[21].emplace_back(17);
	arr[21].emplace_back(43);
	arr[21].emplace_back(85);
	arr[21].emplace_back(28);
	arr[48].emplace_back(97);
	arr[48].emplace_back(39);
	arr[48].emplace_back(73);
	arr[48].emplace_back(54);
	arr[48].emplace_back(28);
	arr[48].emplace_back(33);
	arr[48].emplace_back(74);
	arr[48].emplace_back(94);
	arr[48].emplace_back(51);
	arr[48].emplace_back(43);
	arr[48].emplace_back(29);
	arr[48].emplace_back(93);
	arr[48].emplace_back(27);
	arr[48].emplace_back(98);
	arr[48].emplace_back(78);
	arr[48].emplace_back(34);
	arr[48].emplace_back(71);
	arr[48].emplace_back(22);
	arr[48].emplace_back(77);
	arr[48].emplace_back(24);
	arr[48].emplace_back(75);
	arr[48].emplace_back(96);
	arr[48].emplace_back(19);
	arr[38].emplace_back(77);
	arr[38].emplace_back(93);
	arr[38].emplace_back(94);
	arr[38].emplace_back(48);
	arr[38].emplace_back(29);
	arr[38].emplace_back(19);
	arr[38].emplace_back(33);
	arr[38].emplace_back(54);
	arr[38].emplace_back(17);
	arr[38].emplace_back(28);
	arr[38].emplace_back(75);
	arr[38].emplace_back(39);
	arr[38].emplace_back(71);
	arr[38].emplace_back(27);
	arr[38].emplace_back(22);
	arr[38].emplace_back(96);
	arr[38].emplace_back(98);
	arr[38].emplace_back(51);
	arr[38].emplace_back(43);
	arr[38].emplace_back(74);
	arr[38].emplace_back(24);
	arr[38].emplace_back(34);
	arr[72].emplace_back(29);
	arr[72].emplace_back(38);
	arr[72].emplace_back(14);
	arr[72].emplace_back(19);
	arr[72].emplace_back(71);
	arr[72].emplace_back(43);
	arr[72].emplace_back(89);
	arr[72].emplace_back(28);
	arr[72].emplace_back(64);
	arr[72].emplace_back(77);
	arr[72].emplace_back(34);
	arr[72].emplace_back(85);
	arr[72].emplace_back(75);
	arr[72].emplace_back(12);
	arr[72].emplace_back(48);
	arr[72].emplace_back(17);
	arr[72].emplace_back(96);
	arr[72].emplace_back(93);
	arr[72].emplace_back(74);
	arr[72].emplace_back(73);
	arr[72].emplace_back(98);
	arr[39].emplace_back(89);
	arr[39].emplace_back(12);
	arr[39].emplace_back(21);
	arr[39].emplace_back(84);
	arr[39].emplace_back(63);
	arr[39].emplace_back(44);
	arr[39].emplace_back(45);
	arr[39].emplace_back(85);
	arr[39].emplace_back(69);
	arr[39].emplace_back(72);
	arr[39].emplace_back(13);
	arr[39].emplace_back(83);
	arr[39].emplace_back(61);
	arr[39].emplace_back(14);
	arr[39].emplace_back(81);
	arr[39].emplace_back(95);
	arr[39].emplace_back(82);
	arr[39].emplace_back(68);
	arr[39].emplace_back(99);
	arr[39].emplace_back(97);
	arr[22].emplace_back(51);
	arr[22].emplace_back(99);
	arr[22].emplace_back(69);
	arr[22].emplace_back(39);
	arr[22].emplace_back(33);
	arr[22].emplace_back(82);
	arr[22].emplace_back(61);
	arr[22].emplace_back(13);
	arr[22].emplace_back(42);
	arr[22].emplace_back(45);
	arr[22].emplace_back(97);
	arr[22].emplace_back(78);
	arr[22].emplace_back(83);
	arr[22].emplace_back(56);
	arr[22].emplace_back(57);
	arr[22].emplace_back(84);
	arr[22].emplace_back(81);
	arr[22].emplace_back(68);
	arr[22].emplace_back(63);
	arr[84].emplace_back(77);
	arr[84].emplace_back(63);
	arr[84].emplace_back(72);
	arr[84].emplace_back(43);
	arr[84].emplace_back(85);
	arr[84].emplace_back(29);
	arr[84].emplace_back(48);
	arr[84].emplace_back(56);
	arr[84].emplace_back(82);
	arr[84].emplace_back(42);
	arr[84].emplace_back(13);
	arr[84].emplace_back(89);
	arr[84].emplace_back(21);
	arr[84].emplace_back(95);
	arr[84].emplace_back(68);
	arr[84].emplace_back(64);
	arr[84].emplace_back(75);
	arr[84].emplace_back(57);
	arr[63].emplace_back(12);
	arr[63].emplace_back(38);
	arr[63].emplace_back(34);
	arr[63].emplace_back(14);
	arr[63].emplace_back(93);
	arr[63].emplace_back(95);
	arr[63].emplace_back(17);
	arr[63].emplace_back(48);
	arr[63].emplace_back(29);
	arr[63].emplace_back(43);
	arr[63].emplace_back(77);
	arr[63].emplace_back(28);
	arr[63].emplace_back(19);
	arr[63].emplace_back(98);
	arr[63].emplace_back(74);
	arr[63].emplace_back(85);
	arr[63].emplace_back(75);
	arr[74].emplace_back(96);
	arr[74].emplace_back(22);
	arr[74].emplace_back(98);
	arr[74].emplace_back(93);
	arr[74].emplace_back(19);
	arr[74].emplace_back(24);
	arr[74].emplace_back(83);
	arr[74].emplace_back(56);
	arr[74].emplace_back(69);
	arr[74].emplace_back(78);
	arr[74].emplace_back(27);
	arr[74].emplace_back(13);
	arr[74].emplace_back(71);
	arr[74].emplace_back(44);
	arr[74].emplace_back(94);
	arr[74].emplace_back(33);
	arr[95].emplace_back(93);
	arr[95].emplace_back(75);
	arr[95].emplace_back(73);
	arr[95].emplace_back(29);
	arr[95].emplace_back(19);
	arr[95].emplace_back(48);
	arr[95].emplace_back(71);
	arr[95].emplace_back(38);
	arr[95].emplace_back(77);
	arr[95].emplace_back(78);
	arr[95].emplace_back(28);
	arr[95].emplace_back(12);
	arr[95].emplace_back(98);
	arr[95].emplace_back(22);
	arr[95].emplace_back(96);
	arr[13].emplace_back(43);
	arr[13].emplace_back(12);
	arr[13].emplace_back(85);
	arr[13].emplace_back(82);
	arr[13].emplace_back(48);
	arr[13].emplace_back(89);
	arr[13].emplace_back(81);
	arr[13].emplace_back(14);
	arr[13].emplace_back(68);
	arr[13].emplace_back(99);
	arr[13].emplace_back(42);
	arr[13].emplace_back(72);
	arr[13].emplace_back(29);
	arr[13].emplace_back(77);
	arr[12].emplace_back(51);
	arr[12].emplace_back(98);
	arr[12].emplace_back(54);
	arr[12].emplace_back(22);
	arr[12].emplace_back(24);
	arr[12].emplace_back(94);
	arr[12].emplace_back(14);
	arr[12].emplace_back(17);
	arr[12].emplace_back(96);
	arr[12].emplace_back(77);
	arr[12].emplace_back(71);
	arr[12].emplace_back(48);
	arr[12].emplace_back(43);
	arr[24].emplace_back(94);
	arr[24].emplace_back(44);
	arr[24].emplace_back(56);
	arr[24].emplace_back(72);
	arr[24].emplace_back(33);
	arr[24].emplace_back(78);
	arr[24].emplace_back(69);
	arr[24].emplace_back(21);
	arr[24].emplace_back(42);
	arr[24].emplace_back(83);
	arr[24].emplace_back(81);
	arr[24].emplace_back(45);
	arr[64].emplace_back(28);
	arr[64].emplace_back(95);
	arr[64].emplace_back(85);
	arr[64].emplace_back(29);
	arr[64].emplace_back(75);
	arr[64].emplace_back(14);
	arr[64].emplace_back(17);
	arr[64].emplace_back(94);
	arr[64].emplace_back(12);
	arr[64].emplace_back(98);
	arr[64].emplace_back(74);
	arr[28].emplace_back(73);
	arr[28].emplace_back(71);
	arr[28].emplace_back(34);
	arr[28].emplace_back(33);
	arr[28].emplace_back(96);
	arr[28].emplace_back(78);
	arr[28].emplace_back(97);
	arr[28].emplace_back(98);
	arr[28].emplace_back(94);
	arr[28].emplace_back(44);
	arr[82].emplace_back(21);
	arr[82].emplace_back(89);
	arr[82].emplace_back(54);
	arr[82].emplace_back(95);
	arr[82].emplace_back(64);
	arr[82].emplace_back(71);
	arr[82].emplace_back(34);
	arr[82].emplace_back(63);
	arr[82].emplace_back(29);
	arr[96].emplace_back(78);
	arr[96].emplace_back(54);
	arr[96].emplace_back(51);
	arr[96].emplace_back(93);
	arr[96].emplace_back(42);
	arr[96].emplace_back(44);
	arr[96].emplace_back(39);
	arr[96].emplace_back(83);
	arr[89].emplace_back(98);
	arr[89].emplace_back(74);
	arr[89].emplace_back(48);
	arr[89].emplace_back(12);
	arr[89].emplace_back(73);
	arr[89].emplace_back(54);
	arr[89].emplace_back(43);
	arr[81].emplace_back(28);
	arr[81].emplace_back(72);
	arr[81].emplace_back(64);
	arr[81].emplace_back(12);
	arr[81].emplace_back(17);
	arr[81].emplace_back(85);
	arr[85].emplace_back(29);
	arr[85].emplace_back(94);
	arr[85].emplace_back(75);
	arr[85].emplace_back(43);
	arr[85].emplace_back(17);
	arr[99].emplace_back(96);
	arr[99].emplace_back(63);
	arr[99].emplace_back(64);
	arr[99].emplace_back(81);
	arr[14].emplace_back(29);
	arr[14].emplace_back(19);
	arr[14].emplace_back(33);
	arr[42].emplace_back(81);
	arr[42].emplace_back(75);
	arr[19].emplace_back(68);
	return arr;
}

auto get_updates()
{
	std::array arr{

std::vector<int>{ 51,78,33,39,97,44,45,69,83,84,13,42,56,57,61,68,99,81,82,21,72,63,64 },
std::vector<int>{ 78,34,43,71,33,77,93,22,17,74,73,75,97 },
std::vector<int>{ 99,98,27,57,84,61,39,51,24,81,33 },
std::vector<int>{ 96,98,51,27,97,13,42 },
std::vector<int>{ 99,81,82,72,63,89,12,14,38,75,29,43,28,34,73,96,17 },
std::vector<int>{ 96,71,54,93,98,24,22,78,27,33,97,69,83,84,13,42,56 },
std::vector<int>{ 94,22,78,97,45,69,56,57,99 },
std::vector<int>{ 34,73,74,96,17,19,54,93,98,24,22,78,27,39,97,45,69,83,84 },
std::vector<int>{ 93,98,22,51,78,39,97,45,69,84,13,56,57,61,68,99,81 },
std::vector<int>{ 77,28,17,71,19,93,22,51,78,27,39,97,45 },
std::vector<int>{ 12,14,75,29,43,77,73,74,96,71,19,54,93,94,22,51,78 },
std::vector<int>{ 28,73,98,22,51,44,83 },
std::vector<int>{ 95,12,14,48,75,43,77,96,17,71,54,98,24,94,51 },
std::vector<int>{ 96,71,19,54,93,24,94,22,27,33,39,97,69,83,84,42,56 },
std::vector<int>{ 24,94,22,51,78,27,33,39,97,44,45,69,83,84,13,42,56,57,68,99,81,82,21 },
std::vector<int>{ 21,72,64,85,89,12,14,38,48,29,43,28,34,17,71,19,54 },
std::vector<int>{ 13,56,33,78,96,44,94 },
std::vector<int>{ 28,98,39,51,83,78,97,24,54,93,69,94,73,71,27,34,74 },
std::vector<int>{ 99,81,82,72,64,85,89,12,14,48,75,77,34,74,17 },
std::vector<int>{ 56,57,61,68,99,81,82,21,72,63,64,95,12,14,38,48,75,29,43,28,34 },
std::vector<int>{ 73,96,71,19,54,93,98,24,94,22,51,27,33,39,97,44,45,69,83,84,13 },
std::vector<int>{ 27,39,84,68,72 },
std::vector<int>{ 82,72,61,69,38,64,63,45,42,83,48,85,99,13,89 },
std::vector<int>{ 83,84,13,56,57,61,68,99,81,82,21,72,64,85,89,12,38,48,29 },
std::vector<int>{ 19,93,27,33,42,57,68 },
std::vector<int>{ 57,72,81,21,27,97,13,84,78,68,85,63,83,61,45 },
std::vector<int>{ 38,48,96,17,19 },
std::vector<int>{ 13,42,56,57,61,68,81,82,21,72,63,64,85,89,95,12,14,38,48,75,29,43,77 },
std::vector<int>{ 13,56,21,95,75,29,77 },
std::vector<int>{ 34,93,78,48,22,98,71,29,39,24,17 },
std::vector<int>{ 42,57,61,68,82,21,72,63,64,85,95,12,14,38,48,75,29,77,28 },
std::vector<int>{ 68,27,99,69,85,61,64,97,56 },
std::vector<int>{ 77,75,24,34,19,17,71,94,43,48,73,28,98,96,33,51,78,93,29,39,27,74,22 },
std::vector<int>{ 93,75,95,63,98,74,96 },
std::vector<int>{ 61,78,94,99,97,82,42,98,24 },
std::vector<int>{ 54,93,94,27,33,45,69,83,42,61,99 },
std::vector<int>{ 77,28,96,71,54,93,24,94,22,51,78,33,44,45,69 },
std::vector<int>{ 89,95,12,14,38,48,75,29,77,28,34,73,74,96,17,71,19,54,93,98,24,94,22 },
std::vector<int>{ 38,29,96,24,94 },
std::vector<int>{ 43,77,28,73,74,19,54,24,94,51,78,27,39,97,45 },
std::vector<int>{ 44,45,83,13,42,56,57,68,99,81,82,21,63,64,85,89,95,14,38 },
std::vector<int>{ 38,43,73,71,54,51,33 },
std::vector<int>{ 14,38,48,75,77,54,27 },
std::vector<int>{ 51,78,33,97,69,83,13,57,61,68,81,82,21,63,64 },
std::vector<int>{ 34,74,96,17,71,19,54,93,24,94,22,27,33,39,45,83,84 },
std::vector<int>{ 33,57,51,98,82,81,97,44,22 },
std::vector<int>{ 54,94,51,78,27,33,45,83,13,61,99 },
std::vector<int>{ 22,19,38,43,73,28,77,78,75,29,96,98,17,54,94,48,74 },
std::vector<int>{ 33,61,69,42,71,97,98,45,13 },
std::vector<int>{ 29,43,77,28,34,73,74,96,17,71,19,93,98,24,94,22,51,78,33,97,44 },
std::vector<int>{ 28,77,99,29,14,21,72,75,43,48,64,42,57,89,81,85,82 },
std::vector<int>{ 85,74,89,34,71,48,63,19,82,28,12,17,96,14,75,64,43,38,21,77,29 },
std::vector<int>{ 99,12,83,61,68,82,13,81,56,63,89,42,85,21,97,57,64,44,95,69,84,45,14 },
std::vector<int>{ 45,61,69,99,33,56,68 },
std::vector<int>{ 69,99,13,63,89,38,64,21,12,42,84,57,83,68,14,81,95,61,45 },
std::vector<int>{ 45,74,98,24,84,94,39,69,51,19,83,44,54,96,27,78,17,33,42,93,22 },
std::vector<int>{ 77,28,73,74,17,71,54,98,24,22,51,78,27,33,39,97,44,45,69 },
std::vector<int>{ 61,68,99,81,82,21,72,63,85,89,95,12,14,38,48,29,43,77,28,34,74 },
std::vector<int>{ 43,42,61,72,38,68,99,29,81,12,84 },
std::vector<int>{ 54,93,98,24,94,22,78,39,97,45,69,56,57,68,99 },
std::vector<int>{ 64,85,12,14,48,75,43,77,28,34,74,96,17,19,93,98,24 },
std::vector<int>{ 73,17,54,93,33,39,97 },
std::vector<int>{ 14,38,48,75,29,77,28,34,73,96,17,19,54,24,94,22,51,78,27 },
std::vector<int>{ 82,21,72,64,85,89,95,12,14,38,48,75,29,43,28,34,17,71,19 },
std::vector<int>{ 93,17,34,72,48,38,14,75,74,85,71,19,28,96,95 },
std::vector<int>{ 95,14,38,48,75,29,43,28,73,17,54,98,24,94,51 },
std::vector<int>{ 73,77,19,78,75,24,94,39,96,48,27 },
std::vector<int>{ 96,17,71,19,54,93,98,24,94,22,51,78,27,33,39,97,44,45,69,83,84,42,56 },
std::vector<int>{ 19,22,33,97,44,45,69,42,56,57,68 },
std::vector<int>{ 29,43,77,28,34,73,17,71,19,54,98,24,94,22,51,78,27,33,39,97,44 },
std::vector<int>{ 72,89,95,38,43,28,34,17,93 },
std::vector<int>{ 74,96,71,19,54,93,98,24,94,22,51,78,27,39,44,45,69 },
std::vector<int>{ 27,97,84,68,82,21,63,85,89 },
std::vector<int>{ 69,84,13,72,64,12,38 },
std::vector<int>{ 28,17,89,81,99,63,74,73,75,77,43,29,14,96,95 },
std::vector<int>{ 82,21,72,63,64,85,89,12,14,29,43,28,34,73,74,96,17,71,19 },
std::vector<int>{ 27,73,39,71,96,78,51,54,74,97,22 },
std::vector<int>{ 39,13,21,27,81,56,89,72,68,85,69,63,84,99,83,44,33 },
std::vector<int>{ 29,43,77,34,74,96,17,71,19,54,93,98,24,22,51,78,27,33,39,97,44 },
std::vector<int>{ 84,24,56,51,27,93,97,13,22,94,98,78,83,81,33,69,44 },
std::vector<int>{ 13,56,57,68,99,82,72,63,64,85,89,95,12,14,38,48,75 },
std::vector<int>{ 33,97,45,69,83,84,13,42,56,68,99,81,82,21,72,63,85,89,95 },
std::vector<int>{ 71,93,24,94,97,83,61 },
std::vector<int>{ 57,61,68,99,81,21,63,85,95,12,38,48,29 },
std::vector<int>{ 78,27,33,97,44,45,69,83,84,56,57,68,82,21,85 },
std::vector<int>{ 74,21,81,63,12,75,89,95,96,64,17 },
std::vector<int>{ 34,93,28,94,19,73,97,43,75,17,54,27,22,98,51,39,77,96,78,71,33,24,29 },
std::vector<int>{ 89,95,12,38,75,29,28,73,71,19,54,24,94 },
std::vector<int>{ 95,74,48,73,14,77,28,17,85,89,63,21,82,81,43,75,29,34,38 },
std::vector<int>{ 27,33,61,68,99,81,21,63,85 },
std::vector<int>{ 96,17,71,19,54,93,98,24,94,22,51,27,33,39,97,44,45,69,83,84,13,42,56 },
std::vector<int>{ 89,95,12,38,75,29,43,77,28,34,74,96,17,71,19,93,98,24,22 },
std::vector<int>{ 44,98,84,61,51,69,45,57,78 },
std::vector<int>{ 57,68,72,89,75,77,73 },
std::vector<int>{ 77,24,12,17,54,93,85,43,29 },
std::vector<int>{ 97,45,44,72,84,21,81,63,68,64,78,39,51,56,57,42,61 },
std::vector<int>{ 38,48,43,74,17,19,78 },
std::vector<int>{ 69,42,68,99,72,14,75 },
std::vector<int>{ 54,93,98,78,27,33,97,44,45,69,84,56,61,68,99 },
std::vector<int>{ 12,42,38,82,81,89,45,56,21,85,95,64,83,99,13,61,14,44,63 },
std::vector<int>{ 99,83,82,21,68,14,63,75,42,89,61,12,56,95,57,29,64,85,84,48,38 },
std::vector<int>{ 99,73,48,89,95,74,68,77,29,21,72,12,64,34,96 },
std::vector<int>{ 82,21,72,85,12,48,29,28,34,96,19 },
std::vector<int>{ 56,57,61,68,99,81,82,21,72,63,64,85,89,95,12,14,38,75,29,43,77,28,34 },
std::vector<int>{ 34,63,43,72,89,95,54,93,85,64,73,17,19,96,38 },
std::vector<int>{ 54,24,22,51,97 },
std::vector<int>{ 29,43,94,28,24,34,19,74,95,38,77,89,48,14,75 },
std::vector<int>{ 84,78,63,83,82,68,39,99,81,57,72,69,56,27,22 },
std::vector<int>{ 42,57,48,14,95 },
std::vector<int>{ 33,13,57,61,81 },
std::vector<int>{ 83,57,27,33,64,69,61,72,39,68,42,97,89,85,82,56,99,84,45,44,13 },
std::vector<int>{ 78,69,94,98,22,17,97,39,84,24,34,51,83,54,33 },
std::vector<int>{ 96,71,19,93,98,24,94,22,78 },
std::vector<int>{ 71,19,54,93,98,94,22,27,33,39,44,45,83,84,13,42,56,57,61 },
std::vector<int>{ 93,98,29,43,19,22,96,71,24,73,74 },
std::vector<int>{ 75,43,77,34,17,71,19,54,98,94,22,27,97 },
std::vector<int>{ 54,98,24,94,97,69,84,57,61,68,99 },
std::vector<int>{ 43,77,34,74,96,71,54,98,24,94,22,51,78,27,33,39,45 },
std::vector<int>{ 77,34,96,17,71,54,93,94,22,27,33,39,69 },
std::vector<int>{ 22,33,97,44,45,83,13,42,56,57,61,68,99,81,63 },
std::vector<int>{ 42,57,61,68,99,81,82,21,72,63,64,95,12,38,48,29,43,77,28 },
std::vector<int>{ 57,21,64,89,14,75,29 },
std::vector<int>{ 61,81,82,21,72,64,89,14,48,29,43,77,74 },
std::vector<int>{ 85,89,81,75,38,13,48,83,14,29,82 },
std::vector<int>{ 45,69,83,84,13,42,56,57,61,99,82,21,64,85,89,12,14,38,48 },
std::vector<int>{ 28,34,73,96,17,71,19,54,98,94,22,78,27,39,97,44,45,69,83 },
std::vector<int>{ 71,38,17,29,96,95,19,85,48,74,93,54,28,34,14,94,43 },
std::vector<int>{ 75,77,28,34,73,74,96,19,54,98,24,51,78,27,33,39,97 },
std::vector<int>{ 72,85,95,68,57,75,84,64,42,29,81,89,14,63,48,56,82,12,83,61,38,13,99 },
std::vector<int>{ 51,13,21,81,84 },
std::vector<int>{ 33,39,97,44,69,83,13,42,56,57,61,68,21,72,64,85,95 },
std::vector<int>{ 71,24,97,83,42 },
std::vector<int>{ 42,63,75,95,77,21,85,56,13 },
std::vector<int>{ 89,95,14,29,43,28,74,96,17,71,54,93,98 },
std::vector<int>{ 33,39,97,44,69,84,13,42,56,57,61,82,72,63,64,89,95 },
std::vector<int>{ 57,61,68,99,81,82,21,72,63,64,85,89,95,12,14,38,48,75,29,77,28,34,73 },
std::vector<int>{ 68,82,21,72,85,89,95,12,14,38,48,29,28,73,96 },
std::vector<int>{ 12,38,29,28,96,19,93 },
std::vector<int>{ 29,43,28,34,73,74,54,93,98,24,94,51,78,27,33,39,44 },
std::vector<int>{ 56,68,21,63,89,12,48,75,34 },
std::vector<int>{ 77,12,73,93,29,95,89,28,72,19,71,63,96,34,74,38,75,54,64 },
std::vector<int>{ 78,33,19,51,73,22,39,93,74,84,13 },
std::vector<int>{ 93,51,83,57,39,17,71,22,24 },
std::vector<int>{ 98,73,71,48,17,63,64,29,93,96,89 },
std::vector<int>{ 21,13,69,44,94,84,45,82,56,72,57,61,99 },
std::vector<int>{ 48,77,28,34,94,22,39 },
std::vector<int>{ 39,69,22,81,24,56,44,13,94,98,83,33,51,68,97,82,61,42,45 },
std::vector<int>{ 43,77,28,34,73,74,96,17,71,19,54,93,98,24,22,51,78,27,33,39,97,44,45 },
std::vector<int>{ 17,54,93,94,22,51,78,27,33,97,84,56,57 },
std::vector<int>{ 97,42,82,63,95 },
std::vector<int>{ 34,68,61,72,38,85,29,77,43,75,12,99,89,28,64,82,73,81,74,95,48,14,63 },
std::vector<int>{ 64,29,72,75,43,38,13,84,99 },
std::vector<int>{ 93,28,77,43,48,38,74,71,73,34,27,96,24,14,29,51,17,22,54,75,19,98,78 },
std::vector<int>{ 45,39,56,95,21,84,99,97,72,83,63,85,42,44,61,64,68,13,81,89,57,12,69 },
std::vector<int>{ 63,85,19,71,43,29,77,93,54,14,95,73,64,74,12,28,96,34,98 },
std::vector<int>{ 27,33,69,21,84,72,99,63,13,57,89,44,83,82,42 },
std::vector<int>{ 94,78,71,51,22,93,44,19,96,39,54,27,74,73,98,34,69,28,45,83,33,24,97 },
std::vector<int>{ 45,83,42,68,81,21,72,64,85,95,12,14,48 },
std::vector<int>{ 69,57,22,44,99,33,27,39,51,81,13,97,56,61,68,83,42,94,82,84,24 },
std::vector<int>{ 42,56,57,68,21,72,64,14,48,43,28 },
std::vector<int>{ 84,13,56,57,68,82,21,72,12,75,43 },
std::vector<int>{ 73,74,96,17,19,54,93,98,24,22,78,27,33,39,97,44,45,69,83,84,13 },
std::vector<int>{ 39,97,44,84,42,56,57,61,81,72,64,85,89,95,12 },
std::vector<int>{ 19,64,43,54,63,75,71,38,93,73,72,14,28,17,34,48,95 },
std::vector<int>{ 28,95,74,72,14,34,81 },
std::vector<int>{ 73,96,17,71,19,54,93,98,24,94,22,51,78,27,33,39,97,44,45,69,83,84,13 },
std::vector<int>{ 42,83,63,21,89,38,68,75,69,64,82 },
std::vector<int>{ 96,51,27,93,98,39,44,13,45 },
std::vector<int>{ 28,14,72,12,21,82,63,56,57,89,77,43,38,61,64,68,85,48,34,81,95 },
std::vector<int>{ 97,45,83,13,56,61,81,72,63,64,89,12,14 },
std::vector<int>{ 64,85,89,95,12,14,48,43,28,34,73,74,96,71,54,98,24 },
std::vector<int>{ 61,69,42,63,78 },
std::vector<int>{ 56,57,81,89,14,38,48,75,34 },
std::vector<int>{ 22,51,78,27,33,39,97,44,45,69,83,84,13,42,56,57,61,68,99,82,21,72,63 },
std::vector<int>{ 89,38,34,73,48,29,93,28,17,95,77,74,72 },
std::vector<int>{ 75,29,43,77,28,34,73,74,96,17,71,19,93,98,24,94,22,51,78,27,33,39,97 },
std::vector<int>{ 74,96,17,71,54,98,24,22,51,27,33,39,45,69,84,13,42 },
std::vector<int>{ 75,28,73,74,54,93,24,94,78,27,33,39,97 },
std::vector<int>{ 81,72,63,64,85,89,12,48,75,29,43,77,28,34,73,74,96,17,71 },
std::vector<int>{ 97,44,45,69,83,84,42,56,57,61,68,99,81,82,21,72,63,64,85,89,95,12,14 },
std::vector<int>{ 71,28,77,75,96,63,81,85,21 },
std::vector<int>{ 83,42,39,61,45,97,27,84,72 },
std::vector<int>{ 95,85,77,96,73,89,71 },
std::vector<int>{ 57,68,99,82,21,72,64,85,95,14,48,75,29,43,77,28,73 },
std::vector<int>{ 21,64,85,89,38,75,29,43,28,73,74,17,71,19,54 },
std::vector<int>{ 48,75,29,43,28,34,74,71,19,54,24,22,78 },
std::vector<int>{ 82,21,72,63,64,85,89,95,12,14,38,48,75,29,43,77,28,34,73,74,96,71,19 },
std::vector<int>{ 69,22,94,39,33,83,44,24,13,54,93,45,73 },
	};
	return arr;
}

int check_updates()
{
	int total{};
	auto ordering = get_page_order();
	auto updates = get_updates();

	for (const auto& update : updates)
	{
		bool valid = true;
		for (auto it = update.begin(); it != update.end() && valid; ++it)
		{
			{
				const auto& pages_that_are_only_allowed_to_exist_after_current = ordering[*it];

				for (auto previous_page = update.begin(); previous_page != it && valid; ++previous_page)
				{
					// We check against each previous number
					// If there's a rule that says that the previous number should be after us,
					// it's invalid
					if (std::ranges::find(pages_that_are_only_allowed_to_exist_after_current, *previous_page)
						!= pages_that_are_only_allowed_to_exist_after_current.end())
					{
						valid = false;
						break;
					}
				}
			}
		}

		if (!valid)
		{
			continue;
		}

		int middle_num = update[update.size() / 2];
		total += middle_num;
	}
	return total;
}

int fix_check_updates()
{
	int total{};
	auto ordering = get_page_order();
	auto updates = get_updates();

	for (auto& update : updates)
	{
		bool valid = true;
		bool started_as_invalid = false;
		do
		{
			valid = true;
			for (auto it = update.begin(); it != update.end() && valid; ++it)
			{
				const auto& pages_that_are_only_allowed_to_exist_after_current = ordering[*it];

				for (auto previous_page = update.begin(); previous_page != it && valid; ++previous_page)
				{
					// We check against each previous number
					// If there's a rule that says that the previous number should be after us,
					// it's invalid
					if (std::ranges::find(pages_that_are_only_allowed_to_exist_after_current, *previous_page)
						!= pages_that_are_only_allowed_to_exist_after_current.end())
					{
						valid = false;
						std::swap(*previous_page, *it);
						started_as_invalid = true;
						break;
					}
				}
			}

		} while (!valid);

		if (!started_as_invalid)
		{
			continue;
		}

		int middle_num = update[update.size() / 2];
		total += middle_num;
	}
	return total;
}

int main()
{
	return fix_check_updates();
}
