#include <array>
#include "../external/glm/glm.hpp"

constexpr glm::ivec2 size = { 101, 103 };

consteval auto get_input()
{
	std::array arr
	{

1,65,-5,-84
,14,63,-85,6
,49,81,71,14
,61,77,85,67
,58,37,42,47
,99,13,-4,-72
,50,29,58,96
,84,63,-93,-25
,77,90,-3,-70
,11,82,-74,54
,94,3,16,-96
,30,86,-29,96
,31,92,-70,97
,58,99,16,-89
,14,99,45,36
,42,25,-93,-16
,25,68,37,61
,55,100,4,-98
,34,95,-41,53
,40,86,37,-73
,55,7,50,-63
,76,19,30,-75
,98,73,55,-4
,92,0,37,-67
,66,75,98,-43
,96,54,14,-38
,74,16,26,-88
,37,36,72,-32
,59,95,34,91
,28,102,5,44
,46,21,-94,76
,51,34,-66,-66
,93,99,-40,70
,2,79,-18,9
,0,12,81,20
,85,25,-68,-77
,7,81,31,-28
,43,29,-68,-74
,45,33,15,50
,20,66,-57,38
,13,52,-55,35
,17,6,-47,-35
,31,93,80,99
,33,49,-86,8
,64,41,63,-16
,57,11,-45,80
,62,6,-96,-84
,35,2,71,-26
,36,51,95,-39
,88,3,90,57
,17,16,12,-82
,40,56,-64,90
,67,101,-89,4
,35,84,66,-68
,96,51,-84,-66
,99,14,96,-96
,44,55,14,-53
,8,61,-12,40
,16,2,52,-91
,39,35,94,13
,23,30,-64,-58
,18,90,87,34
,51,70,31,-23
,40,36,-80,-10
,100,102,-62,-46
,69,73,77,-81
,24,90,48,-82
,24,22,23,-96
,88,74,4,51
,71,42,-75,-26
,99,79,-62,-97
,41,9,59,-50
,99,42,-27,77
,77,36,-63,-60
,50,42,-38,-87
,21,21,29,26
,58,65,-52,-84
,67,42,-1,-66
,83,14,-68,-88
,86,83,-55,59
,10,33,31,-98
,52,27,-67,84
,55,73,78,35
,15,46,2,19
,19,51,-12,95
,15,58,-99,-71
,36,96,8,15
,95,15,32,-14
,54,98,38,-52
,78,85,19,-94
,16,70,95,35
,78,91,-47,-15
,92,29,25,-40
,69,77,48,-52
,30,44,-72,58
,3,86,-4,-97
,37,53,7,61
,69,60,-17,-47
,49,7,86,-80
,0,28,89,20
,42,90,26,-60
,17,91,-14,20
,75,48,62,-66
,12,15,-56,-72
,85,81,-18,91
,76,78,98,70
,89,13,-83,65
,55,24,-66,-24
,44,100,-65,33
,96,51,-99,48
,42,23,8,18
,37,84,-7,22
,19,7,-20,-88
,86,26,-32,18
,2,83,-12,46
,35,44,66,48
,93,101,10,49
,62,47,42,-50
,97,98,-40,25
,98,80,-97,-49
,97,72,-62,54
,74,6,-53,-46
,92,53,-32,72
,65,88,3,-94
,31,42,15,-45
,4,97,-98,70
,8,52,96,3
,35,31,-97,45
,32,4,51,-1
,44,68,50,-44
,50,42,-46,29
,20,99,37,12
,77,33,47,-38
,34,99,32,62
,17,75,88,75
,68,90,70,38
,94,33,-39,71
,50,97,-4,6
,36,29,98,84
,53,94,-15,-12
,64,64,-8,-81
,89,78,-17,-81
,99,59,68,61
,6,30,-85,-6
,95,0,38,68
,8,69,-12,-89
,84,12,41,-54
,26,73,58,40
,2,84,53,-36
,9,69,-18,-71
,88,56,83,-2
,89,78,61,80
,38,1,66,33
,94,72,-90,36
,74,61,-83,-23
,21,53,51,15
,55,91,-14,-49
,93,29,11,-95
,63,31,99,-78
,62,93,-81,-91
,37,101,46,18
,60,77,-33,89
,7,52,-98,87
,11,64,2,-97
,45,6,86,52
,13,82,36,90
,15,18,45,-64
,0,101,10,25
,13,49,-15,-71
,43,24,-22,-48
,54,8,95,-7
,33,101,-29,4
,0,32,-1,-38
,73,14,99,44
,94,64,54,-2
,36,93,22,-78
,72,98,12,-25
,77,62,-75,61
,58,83,42,83
,86,62,-83,45
,81,69,25,46
,87,73,-78,-1
,70,91,41,12
,21,12,-72,81
,9,87,-69,70
,33,72,36,-76
,10,10,-87,-44
,100,63,-4,83
,99,1,-69,12
,96,96,39,-70
,9,3,-12,94
,85,101,10,-20
,62,35,56,87
,76,79,-14,-2
,44,14,-51,-96
,81,15,68,-80
,83,63,60,-50
,91,66,90,80
,87,21,82,97
,62,58,-9,82
,12,79,16,-20
,98,92,-42,95
,44,53,94,-89
,21,96,95,17
,84,12,11,-30
,46,89,57,23
,69,18,-9,-90
,65,47,-60,-29
,30,39,1,-23
,46,62,-97,-70
,97,64,59,99
,54,95,-88,-41
,0,53,39,-63
,81,85,99,-54
,46,53,50,8
,17,51,-51,-56
,40,64,85,58
,38,21,63,66
,14,21,81,-98
,82,63,-25,56
,41,65,24,44
,75,9,51,31
,75,80,-21,-36
,70,99,19,75
,90,58,-90,24
,87,36,40,37
,84,65,26,56
,27,47,43,-18
,3,47,65,-31
,83,42,-82,-18
,52,54,78,46
,20,91,94,-1
,72,64,5,80
,95,38,-83,-82
,66,63,33,-34
,94,65,-40,-92
,31,57,-44,89
,63,68,57,80
,45,63,-22,11
,26,54,13,67
,17,14,-78,-22
,9,71,1,14
,31,34,94,58
,58,5,-52,-80
,61,36,-72,32
,95,102,90,31
,41,58,73,90
,27,42,15,-21
,40,99,37,71
,56,61,6,19
,0,62,-69,-58
,85,88,-76,47
,31,99,1,62
,42,80,9,7
,79,17,-38,-24
,99,74,-91,-23
,56,45,-80,58
,15,31,15,42
,77,57,-3,32
,76,87,-82,70
,53,43,23,-29
,73,98,-30,14
,92,98,-84,38
,41,21,-28,-30
,79,86,64,-85
,84,68,62,-47
,65,94,38,-64
,21,64,60,-47
,85,65,-91,14
,55,39,6,-34
,53,24,49,-35
,99,73,82,67
,33,56,29,53
,59,98,70,-14
,39,97,50,33
,20,24,-71,81
,3,93,2,54
,26,39,30,13
,37,2,15,49
,10,24,-86,-51
,5,53,68,-95
,15,95,16,-33
,34,49,-78,74
,91,81,54,-28
,91,18,61,-77
,36,27,-8,-14
,44,3,-69,82
,6,75,-76,-18
,53,38,34,-19
,95,69,-88,-28
,41,76,94,-89
,99,57,-19,-50
,20,77,23,-15
,73,95,-60,78
,91,66,-9,-88
,3,99,3,75
,44,51,-36,16
,53,32,99,-52
,25,87,-42,-78
,3,86,4,17
,93,96,-86,63
,51,54,42,-71
,12,20,9,-11
,100,59,-98,19
,83,26,-46,-15
,38,17,-14,60
,100,39,20,81
,75,22,-60,-28
,0,18,-55,9
,10,21,16,-30
,0,59,-54,89
,100,95,46,-91
,49,79,-8,9
,11,99,-34,94
,74,66,91,35
,2,78,83,54
,5,84,-9,-31
,62,50,63,32
,4,51,-24,-71
,8,27,74,-69
,72,26,-37,-56
,46,44,51,40
,27,31,8,-56
,33,0,15,63
,15,92,62,-36
,24,7,-85,57
,54,101,-26,-70
,83,12,62,83
,99,99,-26,99
,56,49,75,-96
,42,91,50,25
,93,64,-5,-71
,80,85,-97,20
,98,10,53,-30
,54,95,28,4
,53,59,99,-15
,29,60,29,-85
,47,79,21,22
,93,89,-5,-31
,74,21,-60,-30
,3,52,89,98
,35,9,-71,41
,10,85,45,-49
,23,12,-70,47
,97,61,-40,-92
,91,16,24,-1
,56,61,-9,77
,77,11,98,24
,18,41,-42,79
,96,16,2,-3
,48,15,-9,-54
,84,58,-25,93
,48,85,95,-41
,54,11,-37,-96
,76,95,90,-54
,33,59,-65,88
,30,32,22,-40
,4,5,53,94
,22,14,-36,65
,52,99,28,-4
,65,40,-3,-98
,100,65,-19,72
,25,49,-99,61
,94,51,31,-74
,65,34,34,-53
,62,16,-58,-45
,86,95,33,-86
,7,31,-63,-98
,76,40,83,3
,13,64,96,-92
,7,10,-85,25
,85,102,-46,-20
,30,76,-51,75
,38,95,-53,45
,13,44,99,-28
,37,20,15,39
,88,14,-9,-45
,20,77,98,97
,37,90,-14,9
,9,75,96,75
,83,52,66,-27
,20,51,-53,-70
,91,15,-11,-88
,21,98,-13,41
,80,38,4,95
,24,12,22,73
,72,15,5,68
,72,33,84,95
,91,92,83,-20
,74,43,-2,87
,19,101,58,-75
,0,61,-8,69
,81,64,-2,-55
,42,38,-15,-16
,99,102,-92,23
,54,98,81,11
,28,87,-22,-60
,38,7,66,-99
,13,76,74,-57
,79,85,-68,75
,16,70,74,59
,20,32,73,71
,15,97,-85,62
,68,67,-46,11
,42,37,55,-53
,92,98,18,25
,39,101,5,-79
,91,60,-51,-65
,78,11,-90,81
,12,14,89,-22
,45,58,79,93
,4,78,-98,-84
,16,101,-85,94
,41,9,-28,-72
,59,53,13,-31
,87,30,-54,-90
,86,68,90,85
,55,86,-34,77
,66,90,48,51
,60,53,-74,-95
,45,78,-68,26
,90,86,25,46
,41,38,-29,50
,40,22,43,-40
,30,92,-85,-56
,35,27,-29,37
,54,49,-96,16
,46,9,21,-9
,24,50,-34,-37
,92,45,68,34
,7,58,13,27
,2,82,31,1
,79,59,-10,48
,7,102,-34,12
,59,29,-88,-8
,16,59,-59,55
,72,17,41,89
,9,25,53,-27
,15,23,-27,-8
,66,84,-24,-36
,68,62,-66,-7
,90,31,19,-64
,0,96,24,-91
,47,86,36,57
,58,23,88,88
,58,56,-45,40
,68,70,-53,-76
,21,57,23,32
,91,26,16,98
,51,84,-73,99
,40,34,28,-86
,26,82,-75,41
,40,38,-65,-3
,50,85,63,-57
,8,62,-35,-9
,37,49,42,-11
,100,60,-7,29
,14,100,-21,60
,35,3,23,-16
,67,57,34,-39
,71,69,12,-31
,64,91,56,33
,72,68,48,61
,38,9,57,92
,65,93,-70,-99
,2,70,44,59
,14,47,-53,87
,61,72,42,-60
,48,88,-58,67
,15,72,66,-76
,26,60,46,78
,73,24,34,59
,64,55,92,95
,29,24,-89,-37
,40,98,65,-91
,91,65,76,-26
,88,59,-60,-2
,80,73,-48,51
,85,41,83,95
,87,11,76,68
,17,65,15,63
,88,96,-18,-1
,7,6,24,-19
,3,18,-89,56
,41,74,-59,-23
,20,44,38,87
,60,96,-71,-27
,5,33,54,49
,55,68,97,44
,22,60,-57,19
,89,18,39,-38
,96,27,61,-14
,57,16,-15,42
,0,95,-26,72
,58,39,-59,-58
,44,67,14,6
,100,48,-14,67
,26,28,22,47
,24,60,19,53
,31,39,16,34
			};
			return arr;
}
