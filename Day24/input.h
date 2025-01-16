#pragma once

#include <array>
#include <utility>
#include <string_view>

//#define EXAMPLE


#ifdef EXAMPLE


consteval auto get_initial_states()
{
	std::array arr
	{
std::pair<std::string_view, bool>{ "x00", 0 },
std::pair<std::string_view, bool>{ "x01", 1 },
std::pair<std::string_view, bool>{ "x02", 0 },
std::pair<std::string_view, bool>{ "x03", 1 },
std::pair<std::string_view, bool>{ "x04", 0 },
std::pair<std::string_view, bool>{ "x05", 1 },
std::pair<std::string_view, bool>{ "y00", 0 },
std::pair<std::string_view, bool>{ "y01", 0 },
std::pair<std::string_view, bool>{ "y02", 1 },
std::pair<std::string_view, bool>{ "y03", 1 },
std::pair<std::string_view, bool>{ "y04", 0 },
std::pair<std::string_view, bool>{ "y05", 1 },
	};
	return arr;
}

consteval std::string_view get_program()
{
	return

		"x00ANDy00z05"
		"x01ANDy01z02"
		"x02ANDy02z01"
		"x03ANDy03z03"
		"x04ANDy04z04"
		"x05ANDy05z00";
}

#else

consteval auto get_initial_states()
{
	std::array arr
	{
std::pair<std::string_view, bool>{ "x00", 1 },
std::pair<std::string_view, bool>{ "x01", 1 },
std::pair<std::string_view, bool>{ "x02", 0 },
std::pair<std::string_view, bool>{ "x03", 0 },
std::pair<std::string_view, bool>{ "x04", 0 },
std::pair<std::string_view, bool>{ "x05", 1 },
std::pair<std::string_view, bool>{ "x06", 0 },
std::pair<std::string_view, bool>{ "x07", 1 },
std::pair<std::string_view, bool>{ "x08", 1 },
std::pair<std::string_view, bool>{ "x09", 0 },
std::pair<std::string_view, bool>{ "x10", 1 },
std::pair<std::string_view, bool>{ "x11", 0 },
std::pair<std::string_view, bool>{ "x12", 0 },
std::pair<std::string_view, bool>{ "x13", 1 },
std::pair<std::string_view, bool>{ "x14", 0 },
std::pair<std::string_view, bool>{ "x15", 0 },
std::pair<std::string_view, bool>{ "x16", 1 },
std::pair<std::string_view, bool>{ "x17", 0 },
std::pair<std::string_view, bool>{ "x18", 1 },
std::pair<std::string_view, bool>{ "x19", 0 },
std::pair<std::string_view, bool>{ "x20", 0 },
std::pair<std::string_view, bool>{ "x21", 1 },
std::pair<std::string_view, bool>{ "x22", 1 },
std::pair<std::string_view, bool>{ "x23", 0 },
std::pair<std::string_view, bool>{ "x24", 0 },
std::pair<std::string_view, bool>{ "x25", 1 },
std::pair<std::string_view, bool>{ "x26", 1 },
std::pair<std::string_view, bool>{ "x27", 0 },
std::pair<std::string_view, bool>{ "x28", 0 },
std::pair<std::string_view, bool>{ "x29", 1 },
std::pair<std::string_view, bool>{ "x30", 0 },
std::pair<std::string_view, bool>{ "x31", 0 },
std::pair<std::string_view, bool>{ "x32", 1 },
std::pair<std::string_view, bool>{ "x33", 0 },
std::pair<std::string_view, bool>{ "x34", 1 },
std::pair<std::string_view, bool>{ "x35", 1 },
std::pair<std::string_view, bool>{ "x36", 1 },
std::pair<std::string_view, bool>{ "x37", 1 },
std::pair<std::string_view, bool>{ "x38", 0 },
std::pair<std::string_view, bool>{ "x39", 0 },
std::pair<std::string_view, bool>{ "x40", 1 },
std::pair<std::string_view, bool>{ "x41", 1 },
std::pair<std::string_view, bool>{ "x42", 1 },
std::pair<std::string_view, bool>{ "x43", 1 },
std::pair<std::string_view, bool>{ "x44", 1 },
std::pair<std::string_view, bool>{ "y00", 1 },
std::pair<std::string_view, bool>{ "y01", 0 },
std::pair<std::string_view, bool>{ "y02", 1 },
std::pair<std::string_view, bool>{ "y03", 1 },
std::pair<std::string_view, bool>{ "y04", 0 },
std::pair<std::string_view, bool>{ "y05", 0 },
std::pair<std::string_view, bool>{ "y06", 1 },
std::pair<std::string_view, bool>{ "y07", 1 },
std::pair<std::string_view, bool>{ "y08", 0 },
std::pair<std::string_view, bool>{ "y09", 1 },
std::pair<std::string_view, bool>{ "y10", 1 },
std::pair<std::string_view, bool>{ "y11", 1 },
std::pair<std::string_view, bool>{ "y12", 1 },
std::pair<std::string_view, bool>{ "y13", 1 },
std::pair<std::string_view, bool>{ "y14", 0 },
std::pair<std::string_view, bool>{ "y15", 0 },
std::pair<std::string_view, bool>{ "y16", 0 },
std::pair<std::string_view, bool>{ "y17", 1 },
std::pair<std::string_view, bool>{ "y18", 0 },
std::pair<std::string_view, bool>{ "y19", 1 },
std::pair<std::string_view, bool>{ "y20", 0 },
std::pair<std::string_view, bool>{ "y21", 1 },
std::pair<std::string_view, bool>{ "y22", 1 },
std::pair<std::string_view, bool>{ "y23", 0 },
std::pair<std::string_view, bool>{ "y24", 1 },
std::pair<std::string_view, bool>{ "y25", 0 },
std::pair<std::string_view, bool>{ "y26", 1 },
std::pair<std::string_view, bool>{ "y27", 1 },
std::pair<std::string_view, bool>{ "y28", 0 },
std::pair<std::string_view, bool>{ "y29", 0 },
std::pair<std::string_view, bool>{ "y30", 1 },
std::pair<std::string_view, bool>{ "y31", 1 },
std::pair<std::string_view, bool>{ "y32", 1 },
std::pair<std::string_view, bool>{ "y33", 1 },
std::pair<std::string_view, bool>{ "y34", 1 },
std::pair<std::string_view, bool>{ "y35", 0 },
std::pair<std::string_view, bool>{ "y36", 1 },
std::pair<std::string_view, bool>{ "y37", 0 },
std::pair<std::string_view, bool>{ "y38", 0 },
std::pair<std::string_view, bool>{ "y39", 1 },
std::pair<std::string_view, bool>{ "y40", 1 },
std::pair<std::string_view, bool>{ "y41", 0 },
std::pair<std::string_view, bool>{ "y42", 1 },
std::pair<std::string_view, bool>{ "y43", 0 },
std::pair<std::string_view, bool>{ "y44", 1 },

	};
	return arr;
}

consteval std::string_view get_program()
{
	return
		"x36XORy36bbk"
		"sfcXORsdvz15"
		"ncjXORgdcz43"
		"vvrANDggfrqg"
		"stpOR qwrkbw"
		"x25XORy25vbw"
		"wjmOR ghgjtc"
		"x23ANDy23rks"
		"drwOR kbqbtn"
		"hccANDkqpjkc"
		"y08XORx08kgn"
		"btnXORsgvz02"
		"kbwXORjnvz18"
		"mqhOR vkhjds"
		"vvrXORggfz09"
		"nrrXORqwgz30"
		"y07XORx07cnk"
		"kbkXORhbwz37"
		"sghOR hfnmjn"
		"y15ANDx15gms"
		"tpfXORsftz11"
		"qvnXORsgrz01"
		"kbvANDcsvsdp"
		"x32XORy32tkt"
		"y22XORx22fhn"
		"qdfOR qbjbrn"
		"y14ANDx14wgj"
		"cqcOR rnrksv"
		"gwsOR tfbvst"
		"brnXORjkvz33"
		"tmhXORqchz44"
		"fcqOR qhswwt"
		"vngANDgfsrpk"
		"y24XORx24hkf"
		"x39ANDy39vkh"
		"y06XORx06srn"
		"fhnXORfvqz22"
		"y42XORx42jdf"
		"x38XORy38jjj"
		"rksOR rdhkpb"
		"qvfXORjmmz41"
		"y01ANDx01kbq"
		"jskANDpkqgdh"
		"mmsOR gdhfvq"
		"fpwANDjjjfdd"
		"bbkXORfcnz36"
		"x43ANDy43dfg"
		"nprXORhfvz19"
		"y08ANDx08ctv"
		"jkcOR vvbbkk"
		"y26ANDx26pwf"
		"nnnOR cvngdc"
		"vpdOR dtbz45"
		"x44XORy44tmh"
		"pbjOR dfgqch"
		"y41ANDx41gmm"
		"x25ANDy25sfh"
		"y40XORx40gqd"
		"y20ANDx20kvs"
		"nmqOR jmnrjb"
		"pkqXORjskz21"
		"x04XORy04gbh"
		"x04ANDy04scp"
		"pcfOR mqttpf"
		"x31ANDy31cps"
		"fhnANDfvqwdf"
		"y11XORx11sft"
		"srnANDfhbcqc"
		"bpqOR crphbw"
		"gvjOR kvsjsk"
		"kmdANDvvvrdh"
		"y16ANDx16rnq"
		"thkANDwnkz39"
		"sfhOR qggbhv"
		"y02XORx02sgv"
		"qvnANDsgrdrw"
		"x34ANDy34sgh"
		"y42ANDx42nnn"
		"qvfANDjmmpgm"
		"sckOR kmshcc"
		"msfXORtktz32"
		"rjbANDbtjwts"
		"y18ANDx18mgt"
		"jdfANDnmwcvn"
		"kqpXORhccz12"
		"qpgOR csrdjn"
		"x12XORy12kqp"
		"x19XORy19hfv"
		"gpsANDbkkjvj"
		"x14XORy14vng"
		"x13ANDy13rqn"
		"wwtXORvbwz25"
		"gghOR pwfnct"
		"nmwXORjdfz42"
		"y23XORx23vvv"
		"gbhXORwhqz04"
		"vtjOR fpnnrr"
		"x05ANDy05gdk"
		"kpbANDhkffcq"
		"x10ANDy10pcf"
		"jtcXORsngz03"
		"vvvXORkmdz23"
		"gpsXORbkkz13"
		"x09XORy09ggf"
		"y03XORx03sng"
		"kwvOR ctvz08"
		"y03ANDx03fcv"
		"y18XORx18jnv"
		"y39XORx39wnk"
		"x27XORy27njn"
		"jnvANDkbwhrv"
		"y09ANDx09nbb"
		"x31XORy31btj"
		"gmsOR ngfpvv"
		"rpkOR wgjsdv"
		"bhvXORwnfz26"
		"wnkXORthkmqh"
		"pgnOR qswfpw"
		"y15XORx15sfc"
		"x35XORy35qgs"
		"djnXORptktfb"
		"pvvXORrnqz16"
		"cnkANDksvtss"
		"x38ANDy38fkp"
		"y26XORx26wnf"
		"sdpOR gdkfhb"
		"x00ANDy00qvn"
		"x37ANDy37qsw"
		"dpgOR mqpjpb"
		"btnANDsgvghg"
		"jpbXORkpmz34"
		"y34XORx34kpm"
		"kpbXORhkfz24"
		"qgsANDmjnckr"
		"hfvANDnprtvp"
		"y10XORx10vkt"
		"gvwANDkgnkwv"
		"ncjANDgdcpbj"
		"y05XORx05kbv"
		"x24ANDy24qhs"
		"gbhANDwhqjgs"
		"kbgXORhthz17"
		"gvwXORkgnvvr"
		"ksvXORcnkz07"
		"pvvANDrnqmcc"
		"x40ANDy40vnr"
		"x17ANDy17qwr"
		"mgtOR hrvnpr"
		"gwpANDvstfpn"
		"tvpOR cqbtbr"
		"y41XORx41qvf"
		"x21ANDy21mms"
		"nctANDnjnqpg"
		"tmhANDqchvpd"
		"y37XORx37kbk"
		"x20XORy20pkb"
		"nbbOR rqgnsm"
		"x21XORy21pkq"
		"y00XORx00z00"
		"kpmANDjpbhfn"
		"y11ANDx11sck"
		"qwgANDnrrnmq"
		"x43XORy43ncj"
		"jvjOR rqngfs"
		"scpOR jgscsv"
		"y01XORx01sgr"
		"fcnANDbbkbpq"
		"y22ANDx22mmc"
		"y36ANDx36crp"
		"x13XORy13gps"
		"hjmOR tssgvw"
		"fcvOR wmtwhq"
		"wdgOR vnrjmm"
		"mccOR bkrkbg"
		"pgmOR gmmnmw"
		"jkvANDbrnmqp"
		"kbkANDhbwpgn"
		"jdsXORgqdz40"
		"fkpOR fddthk"
		"nsmXORvktz10"
		"bhvANDwnfggh"
		"x29ANDy29vtj"
		"y32ANDx32qbj"
		"jgrOR ckrfcn"
		"x35ANDy35jgr"
		"wtsOR cpsmsf"
		"x27ANDy27csr"
		"y16XORx16bkr"
		"y28XORx28ptk"
		"qgsXORmjnz35"
		"vktANDnsmmqt"
		"rjbXORbtjz31"
		"x30XORy30qwg"
		"y07ANDx07hjm"
		"srnXORfhbz06"
		"x12ANDy12vvb"
		"y19ANDx19cqb"
		"hthANDkbgstp"
		"vbwANDwwtqgg"
		"mmcOR wdfkmd"
		"vngXORgfsz14"
		"gqdANDjdswdg"
		"x33XORy33jkv"
		"kbvXORcsvz05"
		"pkbXORtbrz20"
		"y30ANDx30jmn"
		"x06ANDy06rnr"
		"gwpXORvstz29"
		"sfcANDsdvngf"
		"x33ANDy33dpg"
		"pkbANDtbrgvj"
		"tktANDmsfqdf"
		"tpfANDsftkms"
		"jjjXORfpwz38"
		"sngANDjtcwmt"
		"ptkANDdjngws"
		"x29XORy29gwp"
		"y44ANDx44dtb"
		"nctXORnjnz27"
		"x17XORy17hth"
		"y28ANDx28z28"
		"x02ANDy02wjm";
}
#endif