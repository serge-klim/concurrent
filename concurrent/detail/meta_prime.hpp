// Copyright (c) 2017-2018 Serge Klimov serge.klim@outlook.com

#pragma once

template<size_t N> struct PrimeGreateOrEqual 
{
	static_assert(N<7927, "requested number is too big");
	using type = size_t;
	constexpr static size_t const value =  PrimeGreateOrEqual<N+1>::value;
};

template<> struct PrimeGreateOrEqual<2> {
 using type = size_t; constexpr static size_t const value = 2; };
template<> struct PrimeGreateOrEqual<3> {
 using type = size_t; constexpr static size_t const value = 3; };
template<> struct PrimeGreateOrEqual<5> {
 using type = size_t; constexpr static size_t const value = 5; };
template<> struct PrimeGreateOrEqual<7> {
 using type = size_t; constexpr static size_t const value = 7; };
template<> struct PrimeGreateOrEqual<11> {
 using type = size_t; constexpr static size_t const value = 11; };
template<> struct PrimeGreateOrEqual<13> {
 using type = size_t; constexpr static size_t const value = 13; };
template<> struct PrimeGreateOrEqual<17> {
 using type = size_t; constexpr static size_t const value = 17; };
template<> struct PrimeGreateOrEqual<19> {
 using type = size_t; constexpr static size_t const value = 19; };
template<> struct PrimeGreateOrEqual<23> {
 using type = size_t; constexpr static size_t const value = 23; };
template<> struct PrimeGreateOrEqual<29> {
 using type = size_t; constexpr static size_t const value = 29; };
template<> struct PrimeGreateOrEqual<31> {
 using type = size_t; constexpr static size_t const value = 31; };
template<> struct PrimeGreateOrEqual<37> {
 using type = size_t; constexpr static size_t const value = 37; };
template<> struct PrimeGreateOrEqual<41> {
 using type = size_t; constexpr static size_t const value = 41; };
template<> struct PrimeGreateOrEqual<43> {
 using type = size_t; constexpr static size_t const value = 43; };
template<> struct PrimeGreateOrEqual<47> {
 using type = size_t; constexpr static size_t const value = 47; };
template<> struct PrimeGreateOrEqual<53> {
 using type = size_t; constexpr static size_t const value = 53; };
template<> struct PrimeGreateOrEqual<59> {
 using type = size_t; constexpr static size_t const value = 59; };
template<> struct PrimeGreateOrEqual<61> {
 using type = size_t; constexpr static size_t const value = 61; };
template<> struct PrimeGreateOrEqual<67> {
 using type = size_t; constexpr static size_t const value = 67; };
template<> struct PrimeGreateOrEqual<71> {
 using type = size_t; constexpr static size_t const value = 71; };
template<> struct PrimeGreateOrEqual<73> {
 using type = size_t; constexpr static size_t const value = 73; };
template<> struct PrimeGreateOrEqual<79> {
 using type = size_t; constexpr static size_t const value = 79; };
template<> struct PrimeGreateOrEqual<83> {
 using type = size_t; constexpr static size_t const value = 83; };
template<> struct PrimeGreateOrEqual<89> {
 using type = size_t; constexpr static size_t const value = 89; };
template<> struct PrimeGreateOrEqual<97> {
 using type = size_t; constexpr static size_t const value = 97; };
template<> struct PrimeGreateOrEqual<101> {
 using type = size_t; constexpr static size_t const value = 101; };
template<> struct PrimeGreateOrEqual<103> {
 using type = size_t; constexpr static size_t const value = 103; };
template<> struct PrimeGreateOrEqual<107> {
 using type = size_t; constexpr static size_t const value = 107; };
template<> struct PrimeGreateOrEqual<109> {
 using type = size_t; constexpr static size_t const value = 109; };
template<> struct PrimeGreateOrEqual<113> {
 using type = size_t; constexpr static size_t const value = 113; };
template<> struct PrimeGreateOrEqual<127> {
 using type = size_t; constexpr static size_t const value = 127; };
template<> struct PrimeGreateOrEqual<131> {
 using type = size_t; constexpr static size_t const value = 131; };
template<> struct PrimeGreateOrEqual<137> {
 using type = size_t; constexpr static size_t const value = 137; };
template<> struct PrimeGreateOrEqual<139> {
 using type = size_t; constexpr static size_t const value = 139; };
template<> struct PrimeGreateOrEqual<149> {
 using type = size_t; constexpr static size_t const value = 149; };
template<> struct PrimeGreateOrEqual<151> {
 using type = size_t; constexpr static size_t const value = 151; };
template<> struct PrimeGreateOrEqual<157> {
 using type = size_t; constexpr static size_t const value = 157; };
template<> struct PrimeGreateOrEqual<163> {
 using type = size_t; constexpr static size_t const value = 163; };
template<> struct PrimeGreateOrEqual<167> {
 using type = size_t; constexpr static size_t const value = 167; };
template<> struct PrimeGreateOrEqual<173> {
 using type = size_t; constexpr static size_t const value = 173; };
template<> struct PrimeGreateOrEqual<179> {
 using type = size_t; constexpr static size_t const value = 179; };
template<> struct PrimeGreateOrEqual<181> {
 using type = size_t; constexpr static size_t const value = 181; };
template<> struct PrimeGreateOrEqual<191> {
 using type = size_t; constexpr static size_t const value = 191; };
template<> struct PrimeGreateOrEqual<193> {
 using type = size_t; constexpr static size_t const value = 193; };
template<> struct PrimeGreateOrEqual<197> {
 using type = size_t; constexpr static size_t const value = 197; };
template<> struct PrimeGreateOrEqual<199> {
 using type = size_t; constexpr static size_t const value = 199; };
template<> struct PrimeGreateOrEqual<211> {
 using type = size_t; constexpr static size_t const value = 211; };
template<> struct PrimeGreateOrEqual<223> {
 using type = size_t; constexpr static size_t const value = 223; };
template<> struct PrimeGreateOrEqual<227> {
 using type = size_t; constexpr static size_t const value = 227; };
template<> struct PrimeGreateOrEqual<229> {
 using type = size_t; constexpr static size_t const value = 229; };
template<> struct PrimeGreateOrEqual<233> {
 using type = size_t; constexpr static size_t const value = 233; };
template<> struct PrimeGreateOrEqual<239> {
 using type = size_t; constexpr static size_t const value = 239; };
template<> struct PrimeGreateOrEqual<241> {
 using type = size_t; constexpr static size_t const value = 241; };
template<> struct PrimeGreateOrEqual<251> {
 using type = size_t; constexpr static size_t const value = 251; };
template<> struct PrimeGreateOrEqual<257> {
 using type = size_t; constexpr static size_t const value = 257; };
template<> struct PrimeGreateOrEqual<263> {
 using type = size_t; constexpr static size_t const value = 263; };
template<> struct PrimeGreateOrEqual<269> {
 using type = size_t; constexpr static size_t const value = 269; };
template<> struct PrimeGreateOrEqual<271> {
 using type = size_t; constexpr static size_t const value = 271; };
template<> struct PrimeGreateOrEqual<277> {
 using type = size_t; constexpr static size_t const value = 277; };
template<> struct PrimeGreateOrEqual<281> {
 using type = size_t; constexpr static size_t const value = 281; };
template<> struct PrimeGreateOrEqual<283> {
 using type = size_t; constexpr static size_t const value = 283; };
template<> struct PrimeGreateOrEqual<293> {
 using type = size_t; constexpr static size_t const value = 293; };
template<> struct PrimeGreateOrEqual<307> {
 using type = size_t; constexpr static size_t const value = 307; };
template<> struct PrimeGreateOrEqual<311> {
 using type = size_t; constexpr static size_t const value = 311; };
template<> struct PrimeGreateOrEqual<313> {
 using type = size_t; constexpr static size_t const value = 313; };
template<> struct PrimeGreateOrEqual<317> {
 using type = size_t; constexpr static size_t const value = 317; };
template<> struct PrimeGreateOrEqual<331> {
 using type = size_t; constexpr static size_t const value = 331; };
template<> struct PrimeGreateOrEqual<337> {
 using type = size_t; constexpr static size_t const value = 337; };
template<> struct PrimeGreateOrEqual<347> {
 using type = size_t; constexpr static size_t const value = 347; };
template<> struct PrimeGreateOrEqual<349> {
 using type = size_t; constexpr static size_t const value = 349; };
template<> struct PrimeGreateOrEqual<353> {
 using type = size_t; constexpr static size_t const value = 353; };
template<> struct PrimeGreateOrEqual<359> {
 using type = size_t; constexpr static size_t const value = 359; };
template<> struct PrimeGreateOrEqual<367> {
 using type = size_t; constexpr static size_t const value = 367; };
template<> struct PrimeGreateOrEqual<373> {
 using type = size_t; constexpr static size_t const value = 373; };
template<> struct PrimeGreateOrEqual<379> {
 using type = size_t; constexpr static size_t const value = 379; };
template<> struct PrimeGreateOrEqual<383> {
 using type = size_t; constexpr static size_t const value = 383; };
template<> struct PrimeGreateOrEqual<389> {
 using type = size_t; constexpr static size_t const value = 389; };
template<> struct PrimeGreateOrEqual<397> {
 using type = size_t; constexpr static size_t const value = 397; };
template<> struct PrimeGreateOrEqual<401> {
 using type = size_t; constexpr static size_t const value = 401; };
template<> struct PrimeGreateOrEqual<409> {
 using type = size_t; constexpr static size_t const value = 409; };
template<> struct PrimeGreateOrEqual<419> {
 using type = size_t; constexpr static size_t const value = 419; };
template<> struct PrimeGreateOrEqual<421> {
 using type = size_t; constexpr static size_t const value = 421; };
template<> struct PrimeGreateOrEqual<431> {
 using type = size_t; constexpr static size_t const value = 431; };
template<> struct PrimeGreateOrEqual<433> {
 using type = size_t; constexpr static size_t const value = 433; };
template<> struct PrimeGreateOrEqual<439> {
 using type = size_t; constexpr static size_t const value = 439; };
template<> struct PrimeGreateOrEqual<443> {
 using type = size_t; constexpr static size_t const value = 443; };
template<> struct PrimeGreateOrEqual<449> {
 using type = size_t; constexpr static size_t const value = 449; };
template<> struct PrimeGreateOrEqual<457> {
 using type = size_t; constexpr static size_t const value = 457; };
template<> struct PrimeGreateOrEqual<461> {
 using type = size_t; constexpr static size_t const value = 461; };
template<> struct PrimeGreateOrEqual<463> {
 using type = size_t; constexpr static size_t const value = 463; };
template<> struct PrimeGreateOrEqual<467> {
 using type = size_t; constexpr static size_t const value = 467; };
template<> struct PrimeGreateOrEqual<479> {
 using type = size_t; constexpr static size_t const value = 479; };
template<> struct PrimeGreateOrEqual<487> {
 using type = size_t; constexpr static size_t const value = 487; };
template<> struct PrimeGreateOrEqual<491> {
 using type = size_t; constexpr static size_t const value = 491; };
template<> struct PrimeGreateOrEqual<499> {
 using type = size_t; constexpr static size_t const value = 499; };
template<> struct PrimeGreateOrEqual<503> {
 using type = size_t; constexpr static size_t const value = 503; };
template<> struct PrimeGreateOrEqual<509> {
 using type = size_t; constexpr static size_t const value = 509; };
template<> struct PrimeGreateOrEqual<521> {
 using type = size_t; constexpr static size_t const value = 521; };
template<> struct PrimeGreateOrEqual<523> {
 using type = size_t; constexpr static size_t const value = 523; };
template<> struct PrimeGreateOrEqual<541> {
 using type = size_t; constexpr static size_t const value = 541; };
template<> struct PrimeGreateOrEqual<547> {
 using type = size_t; constexpr static size_t const value = 547; };
template<> struct PrimeGreateOrEqual<557> {
 using type = size_t; constexpr static size_t const value = 557; };
template<> struct PrimeGreateOrEqual<563> {
 using type = size_t; constexpr static size_t const value = 563; };
template<> struct PrimeGreateOrEqual<569> {
 using type = size_t; constexpr static size_t const value = 569; };
template<> struct PrimeGreateOrEqual<571> {
 using type = size_t; constexpr static size_t const value = 571; };
template<> struct PrimeGreateOrEqual<577> {
 using type = size_t; constexpr static size_t const value = 577; };
template<> struct PrimeGreateOrEqual<587> {
 using type = size_t; constexpr static size_t const value = 587; };
template<> struct PrimeGreateOrEqual<593> {
 using type = size_t; constexpr static size_t const value = 593; };
template<> struct PrimeGreateOrEqual<599> {
 using type = size_t; constexpr static size_t const value = 599; };
template<> struct PrimeGreateOrEqual<601> {
 using type = size_t; constexpr static size_t const value = 601; };
template<> struct PrimeGreateOrEqual<607> {
 using type = size_t; constexpr static size_t const value = 607; };
template<> struct PrimeGreateOrEqual<613> {
 using type = size_t; constexpr static size_t const value = 613; };
template<> struct PrimeGreateOrEqual<617> {
 using type = size_t; constexpr static size_t const value = 617; };
template<> struct PrimeGreateOrEqual<619> {
 using type = size_t; constexpr static size_t const value = 619; };
template<> struct PrimeGreateOrEqual<631> {
 using type = size_t; constexpr static size_t const value = 631; };
template<> struct PrimeGreateOrEqual<641> {
 using type = size_t; constexpr static size_t const value = 641; };
template<> struct PrimeGreateOrEqual<643> {
 using type = size_t; constexpr static size_t const value = 643; };
template<> struct PrimeGreateOrEqual<647> {
 using type = size_t; constexpr static size_t const value = 647; };
template<> struct PrimeGreateOrEqual<653> {
 using type = size_t; constexpr static size_t const value = 653; };
template<> struct PrimeGreateOrEqual<659> {
 using type = size_t; constexpr static size_t const value = 659; };
template<> struct PrimeGreateOrEqual<661> {
 using type = size_t; constexpr static size_t const value = 661; };
template<> struct PrimeGreateOrEqual<673> {
 using type = size_t; constexpr static size_t const value = 673; };
template<> struct PrimeGreateOrEqual<677> {
 using type = size_t; constexpr static size_t const value = 677; };
template<> struct PrimeGreateOrEqual<683> {
 using type = size_t; constexpr static size_t const value = 683; };
template<> struct PrimeGreateOrEqual<691> {
 using type = size_t; constexpr static size_t const value = 691; };
template<> struct PrimeGreateOrEqual<701> {
 using type = size_t; constexpr static size_t const value = 701; };
template<> struct PrimeGreateOrEqual<709> {
 using type = size_t; constexpr static size_t const value = 709; };
template<> struct PrimeGreateOrEqual<719> {
 using type = size_t; constexpr static size_t const value = 719; };
template<> struct PrimeGreateOrEqual<727> {
 using type = size_t; constexpr static size_t const value = 727; };
template<> struct PrimeGreateOrEqual<733> {
 using type = size_t; constexpr static size_t const value = 733; };
template<> struct PrimeGreateOrEqual<739> {
 using type = size_t; constexpr static size_t const value = 739; };
template<> struct PrimeGreateOrEqual<743> {
 using type = size_t; constexpr static size_t const value = 743; };
template<> struct PrimeGreateOrEqual<751> {
 using type = size_t; constexpr static size_t const value = 751; };
template<> struct PrimeGreateOrEqual<757> {
 using type = size_t; constexpr static size_t const value = 757; };
template<> struct PrimeGreateOrEqual<761> {
 using type = size_t; constexpr static size_t const value = 761; };
template<> struct PrimeGreateOrEqual<769> {
 using type = size_t; constexpr static size_t const value = 769; };
template<> struct PrimeGreateOrEqual<773> {
 using type = size_t; constexpr static size_t const value = 773; };
template<> struct PrimeGreateOrEqual<787> {
 using type = size_t; constexpr static size_t const value = 787; };
template<> struct PrimeGreateOrEqual<797> {
 using type = size_t; constexpr static size_t const value = 797; };
template<> struct PrimeGreateOrEqual<809> {
 using type = size_t; constexpr static size_t const value = 809; };
template<> struct PrimeGreateOrEqual<811> {
 using type = size_t; constexpr static size_t const value = 811; };
template<> struct PrimeGreateOrEqual<821> {
 using type = size_t; constexpr static size_t const value = 821; };
template<> struct PrimeGreateOrEqual<823> {
 using type = size_t; constexpr static size_t const value = 823; };
template<> struct PrimeGreateOrEqual<827> {
 using type = size_t; constexpr static size_t const value = 827; };
template<> struct PrimeGreateOrEqual<829> {
 using type = size_t; constexpr static size_t const value = 829; };
template<> struct PrimeGreateOrEqual<839> {
 using type = size_t; constexpr static size_t const value = 839; };
template<> struct PrimeGreateOrEqual<853> {
 using type = size_t; constexpr static size_t const value = 853; };
template<> struct PrimeGreateOrEqual<857> {
 using type = size_t; constexpr static size_t const value = 857; };
template<> struct PrimeGreateOrEqual<859> {
 using type = size_t; constexpr static size_t const value = 859; };
template<> struct PrimeGreateOrEqual<863> {
 using type = size_t; constexpr static size_t const value = 863; };
template<> struct PrimeGreateOrEqual<877> {
 using type = size_t; constexpr static size_t const value = 877; };
template<> struct PrimeGreateOrEqual<881> {
 using type = size_t; constexpr static size_t const value = 881; };
template<> struct PrimeGreateOrEqual<883> {
 using type = size_t; constexpr static size_t const value = 883; };
template<> struct PrimeGreateOrEqual<887> {
 using type = size_t; constexpr static size_t const value = 887; };
template<> struct PrimeGreateOrEqual<907> {
 using type = size_t; constexpr static size_t const value = 907; };
template<> struct PrimeGreateOrEqual<911> {
 using type = size_t; constexpr static size_t const value = 911; };
template<> struct PrimeGreateOrEqual<919> {
 using type = size_t; constexpr static size_t const value = 919; };
template<> struct PrimeGreateOrEqual<929> {
 using type = size_t; constexpr static size_t const value = 929; };
template<> struct PrimeGreateOrEqual<937> {
 using type = size_t; constexpr static size_t const value = 937; };
template<> struct PrimeGreateOrEqual<941> {
 using type = size_t; constexpr static size_t const value = 941; };
template<> struct PrimeGreateOrEqual<947> {
 using type = size_t; constexpr static size_t const value = 947; };
template<> struct PrimeGreateOrEqual<953> {
 using type = size_t; constexpr static size_t const value = 953; };
template<> struct PrimeGreateOrEqual<967> {
 using type = size_t; constexpr static size_t const value = 967; };
template<> struct PrimeGreateOrEqual<971> {
 using type = size_t; constexpr static size_t const value = 971; };
template<> struct PrimeGreateOrEqual<977> {
 using type = size_t; constexpr static size_t const value = 977; };
template<> struct PrimeGreateOrEqual<983> {
 using type = size_t; constexpr static size_t const value = 983; };
template<> struct PrimeGreateOrEqual<991> {
 using type = size_t; constexpr static size_t const value = 991; };
template<> struct PrimeGreateOrEqual<997> {
 using type = size_t; constexpr static size_t const value = 997; };
template<> struct PrimeGreateOrEqual<1009> {
 using type = size_t; constexpr static size_t const value = 1009; };
template<> struct PrimeGreateOrEqual<1013> {
 using type = size_t; constexpr static size_t const value = 1013; };
template<> struct PrimeGreateOrEqual<1019> {
 using type = size_t; constexpr static size_t const value = 1019; };
template<> struct PrimeGreateOrEqual<1021> {
 using type = size_t; constexpr static size_t const value = 1021; };
template<> struct PrimeGreateOrEqual<1031> {
 using type = size_t; constexpr static size_t const value = 1031; };
template<> struct PrimeGreateOrEqual<1033> {
 using type = size_t; constexpr static size_t const value = 1033; };
template<> struct PrimeGreateOrEqual<1039> {
 using type = size_t; constexpr static size_t const value = 1039; };
template<> struct PrimeGreateOrEqual<1049> {
 using type = size_t; constexpr static size_t const value = 1049; };
template<> struct PrimeGreateOrEqual<1051> {
 using type = size_t; constexpr static size_t const value = 1051; };
template<> struct PrimeGreateOrEqual<1061> {
 using type = size_t; constexpr static size_t const value = 1061; };
template<> struct PrimeGreateOrEqual<1063> {
 using type = size_t; constexpr static size_t const value = 1063; };
template<> struct PrimeGreateOrEqual<1069> {
 using type = size_t; constexpr static size_t const value = 1069; };
template<> struct PrimeGreateOrEqual<1087> {
 using type = size_t; constexpr static size_t const value = 1087; };
template<> struct PrimeGreateOrEqual<1091> {
 using type = size_t; constexpr static size_t const value = 1091; };
template<> struct PrimeGreateOrEqual<1093> {
 using type = size_t; constexpr static size_t const value = 1093; };
template<> struct PrimeGreateOrEqual<1097> {
 using type = size_t; constexpr static size_t const value = 1097; };
template<> struct PrimeGreateOrEqual<1103> {
 using type = size_t; constexpr static size_t const value = 1103; };
template<> struct PrimeGreateOrEqual<1109> {
 using type = size_t; constexpr static size_t const value = 1109; };
template<> struct PrimeGreateOrEqual<1117> {
 using type = size_t; constexpr static size_t const value = 1117; };
template<> struct PrimeGreateOrEqual<1123> {
 using type = size_t; constexpr static size_t const value = 1123; };
template<> struct PrimeGreateOrEqual<1129> {
 using type = size_t; constexpr static size_t const value = 1129; };
template<> struct PrimeGreateOrEqual<1151> {
 using type = size_t; constexpr static size_t const value = 1151; };
template<> struct PrimeGreateOrEqual<1153> {
 using type = size_t; constexpr static size_t const value = 1153; };
template<> struct PrimeGreateOrEqual<1163> {
 using type = size_t; constexpr static size_t const value = 1163; };
template<> struct PrimeGreateOrEqual<1171> {
 using type = size_t; constexpr static size_t const value = 1171; };
template<> struct PrimeGreateOrEqual<1181> {
 using type = size_t; constexpr static size_t const value = 1181; };
template<> struct PrimeGreateOrEqual<1187> {
 using type = size_t; constexpr static size_t const value = 1187; };
template<> struct PrimeGreateOrEqual<1193> {
 using type = size_t; constexpr static size_t const value = 1193; };
template<> struct PrimeGreateOrEqual<1201> {
 using type = size_t; constexpr static size_t const value = 1201; };
template<> struct PrimeGreateOrEqual<1213> {
 using type = size_t; constexpr static size_t const value = 1213; };
template<> struct PrimeGreateOrEqual<1217> {
 using type = size_t; constexpr static size_t const value = 1217; };
template<> struct PrimeGreateOrEqual<1223> {
 using type = size_t; constexpr static size_t const value = 1223; };
template<> struct PrimeGreateOrEqual<1229> {
 using type = size_t; constexpr static size_t const value = 1229; };
template<> struct PrimeGreateOrEqual<1231> {
 using type = size_t; constexpr static size_t const value = 1231; };
template<> struct PrimeGreateOrEqual<1237> {
 using type = size_t; constexpr static size_t const value = 1237; };
template<> struct PrimeGreateOrEqual<1249> {
 using type = size_t; constexpr static size_t const value = 1249; };
template<> struct PrimeGreateOrEqual<1259> {
 using type = size_t; constexpr static size_t const value = 1259; };
template<> struct PrimeGreateOrEqual<1277> {
 using type = size_t; constexpr static size_t const value = 1277; };
template<> struct PrimeGreateOrEqual<1279> {
 using type = size_t; constexpr static size_t const value = 1279; };
template<> struct PrimeGreateOrEqual<1283> {
 using type = size_t; constexpr static size_t const value = 1283; };
template<> struct PrimeGreateOrEqual<1289> {
 using type = size_t; constexpr static size_t const value = 1289; };
template<> struct PrimeGreateOrEqual<1291> {
 using type = size_t; constexpr static size_t const value = 1291; };
template<> struct PrimeGreateOrEqual<1297> {
 using type = size_t; constexpr static size_t const value = 1297; };
template<> struct PrimeGreateOrEqual<1301> {
 using type = size_t; constexpr static size_t const value = 1301; };
template<> struct PrimeGreateOrEqual<1303> {
 using type = size_t; constexpr static size_t const value = 1303; };
template<> struct PrimeGreateOrEqual<1307> {
 using type = size_t; constexpr static size_t const value = 1307; };
template<> struct PrimeGreateOrEqual<1319> {
 using type = size_t; constexpr static size_t const value = 1319; };
template<> struct PrimeGreateOrEqual<1321> {
 using type = size_t; constexpr static size_t const value = 1321; };
template<> struct PrimeGreateOrEqual<1327> {
 using type = size_t; constexpr static size_t const value = 1327; };
template<> struct PrimeGreateOrEqual<1361> {
 using type = size_t; constexpr static size_t const value = 1361; };
template<> struct PrimeGreateOrEqual<1367> {
 using type = size_t; constexpr static size_t const value = 1367; };
template<> struct PrimeGreateOrEqual<1373> {
 using type = size_t; constexpr static size_t const value = 1373; };
template<> struct PrimeGreateOrEqual<1381> {
 using type = size_t; constexpr static size_t const value = 1381; };
template<> struct PrimeGreateOrEqual<1399> {
 using type = size_t; constexpr static size_t const value = 1399; };
template<> struct PrimeGreateOrEqual<1409> {
 using type = size_t; constexpr static size_t const value = 1409; };
template<> struct PrimeGreateOrEqual<1423> {
 using type = size_t; constexpr static size_t const value = 1423; };
template<> struct PrimeGreateOrEqual<1427> {
 using type = size_t; constexpr static size_t const value = 1427; };
template<> struct PrimeGreateOrEqual<1429> {
 using type = size_t; constexpr static size_t const value = 1429; };
template<> struct PrimeGreateOrEqual<1433> {
 using type = size_t; constexpr static size_t const value = 1433; };
template<> struct PrimeGreateOrEqual<1439> {
 using type = size_t; constexpr static size_t const value = 1439; };
template<> struct PrimeGreateOrEqual<1447> {
 using type = size_t; constexpr static size_t const value = 1447; };
template<> struct PrimeGreateOrEqual<1451> {
 using type = size_t; constexpr static size_t const value = 1451; };
template<> struct PrimeGreateOrEqual<1453> {
 using type = size_t; constexpr static size_t const value = 1453; };
template<> struct PrimeGreateOrEqual<1459> {
 using type = size_t; constexpr static size_t const value = 1459; };
template<> struct PrimeGreateOrEqual<1471> {
 using type = size_t; constexpr static size_t const value = 1471; };
template<> struct PrimeGreateOrEqual<1481> {
 using type = size_t; constexpr static size_t const value = 1481; };
template<> struct PrimeGreateOrEqual<1483> {
 using type = size_t; constexpr static size_t const value = 1483; };
template<> struct PrimeGreateOrEqual<1487> {
 using type = size_t; constexpr static size_t const value = 1487; };
template<> struct PrimeGreateOrEqual<1489> {
 using type = size_t; constexpr static size_t const value = 1489; };
template<> struct PrimeGreateOrEqual<1493> {
 using type = size_t; constexpr static size_t const value = 1493; };
template<> struct PrimeGreateOrEqual<1499> {
 using type = size_t; constexpr static size_t const value = 1499; };
template<> struct PrimeGreateOrEqual<1511> {
 using type = size_t; constexpr static size_t const value = 1511; };
template<> struct PrimeGreateOrEqual<1523> {
 using type = size_t; constexpr static size_t const value = 1523; };
template<> struct PrimeGreateOrEqual<1531> {
 using type = size_t; constexpr static size_t const value = 1531; };
template<> struct PrimeGreateOrEqual<1543> {
 using type = size_t; constexpr static size_t const value = 1543; };
template<> struct PrimeGreateOrEqual<1549> {
 using type = size_t; constexpr static size_t const value = 1549; };
template<> struct PrimeGreateOrEqual<1553> {
 using type = size_t; constexpr static size_t const value = 1553; };
template<> struct PrimeGreateOrEqual<1559> {
 using type = size_t; constexpr static size_t const value = 1559; };
template<> struct PrimeGreateOrEqual<1567> {
 using type = size_t; constexpr static size_t const value = 1567; };
template<> struct PrimeGreateOrEqual<1571> {
 using type = size_t; constexpr static size_t const value = 1571; };
template<> struct PrimeGreateOrEqual<1579> {
 using type = size_t; constexpr static size_t const value = 1579; };
template<> struct PrimeGreateOrEqual<1583> {
 using type = size_t; constexpr static size_t const value = 1583; };
template<> struct PrimeGreateOrEqual<1597> {
 using type = size_t; constexpr static size_t const value = 1597; };
template<> struct PrimeGreateOrEqual<1601> {
 using type = size_t; constexpr static size_t const value = 1601; };
template<> struct PrimeGreateOrEqual<1607> {
 using type = size_t; constexpr static size_t const value = 1607; };
template<> struct PrimeGreateOrEqual<1609> {
 using type = size_t; constexpr static size_t const value = 1609; };
template<> struct PrimeGreateOrEqual<1613> {
 using type = size_t; constexpr static size_t const value = 1613; };
template<> struct PrimeGreateOrEqual<1619> {
 using type = size_t; constexpr static size_t const value = 1619; };
template<> struct PrimeGreateOrEqual<1621> {
 using type = size_t; constexpr static size_t const value = 1621; };
template<> struct PrimeGreateOrEqual<1627> {
 using type = size_t; constexpr static size_t const value = 1627; };
template<> struct PrimeGreateOrEqual<1637> {
 using type = size_t; constexpr static size_t const value = 1637; };
template<> struct PrimeGreateOrEqual<1657> {
 using type = size_t; constexpr static size_t const value = 1657; };
template<> struct PrimeGreateOrEqual<1663> {
 using type = size_t; constexpr static size_t const value = 1663; };
template<> struct PrimeGreateOrEqual<1667> {
 using type = size_t; constexpr static size_t const value = 1667; };
template<> struct PrimeGreateOrEqual<1669> {
 using type = size_t; constexpr static size_t const value = 1669; };
template<> struct PrimeGreateOrEqual<1693> {
 using type = size_t; constexpr static size_t const value = 1693; };
template<> struct PrimeGreateOrEqual<1697> {
 using type = size_t; constexpr static size_t const value = 1697; };
template<> struct PrimeGreateOrEqual<1699> {
 using type = size_t; constexpr static size_t const value = 1699; };
template<> struct PrimeGreateOrEqual<1709> {
 using type = size_t; constexpr static size_t const value = 1709; };
template<> struct PrimeGreateOrEqual<1721> {
 using type = size_t; constexpr static size_t const value = 1721; };
template<> struct PrimeGreateOrEqual<1723> {
 using type = size_t; constexpr static size_t const value = 1723; };
template<> struct PrimeGreateOrEqual<1733> {
 using type = size_t; constexpr static size_t const value = 1733; };
template<> struct PrimeGreateOrEqual<1741> {
 using type = size_t; constexpr static size_t const value = 1741; };
template<> struct PrimeGreateOrEqual<1747> {
 using type = size_t; constexpr static size_t const value = 1747; };
template<> struct PrimeGreateOrEqual<1753> {
 using type = size_t; constexpr static size_t const value = 1753; };
template<> struct PrimeGreateOrEqual<1759> {
 using type = size_t; constexpr static size_t const value = 1759; };
template<> struct PrimeGreateOrEqual<1777> {
 using type = size_t; constexpr static size_t const value = 1777; };
template<> struct PrimeGreateOrEqual<1783> {
 using type = size_t; constexpr static size_t const value = 1783; };
template<> struct PrimeGreateOrEqual<1787> {
 using type = size_t; constexpr static size_t const value = 1787; };
template<> struct PrimeGreateOrEqual<1789> {
 using type = size_t; constexpr static size_t const value = 1789; };
template<> struct PrimeGreateOrEqual<1801> {
 using type = size_t; constexpr static size_t const value = 1801; };
template<> struct PrimeGreateOrEqual<1811> {
 using type = size_t; constexpr static size_t const value = 1811; };
template<> struct PrimeGreateOrEqual<1823> {
 using type = size_t; constexpr static size_t const value = 1823; };
template<> struct PrimeGreateOrEqual<1831> {
 using type = size_t; constexpr static size_t const value = 1831; };
template<> struct PrimeGreateOrEqual<1847> {
 using type = size_t; constexpr static size_t const value = 1847; };
template<> struct PrimeGreateOrEqual<1861> {
 using type = size_t; constexpr static size_t const value = 1861; };
template<> struct PrimeGreateOrEqual<1867> {
 using type = size_t; constexpr static size_t const value = 1867; };
template<> struct PrimeGreateOrEqual<1871> {
 using type = size_t; constexpr static size_t const value = 1871; };
template<> struct PrimeGreateOrEqual<1873> {
 using type = size_t; constexpr static size_t const value = 1873; };
template<> struct PrimeGreateOrEqual<1877> {
 using type = size_t; constexpr static size_t const value = 1877; };
template<> struct PrimeGreateOrEqual<1879> {
 using type = size_t; constexpr static size_t const value = 1879; };
template<> struct PrimeGreateOrEqual<1889> {
 using type = size_t; constexpr static size_t const value = 1889; };
template<> struct PrimeGreateOrEqual<1901> {
 using type = size_t; constexpr static size_t const value = 1901; };
template<> struct PrimeGreateOrEqual<1907> {
 using type = size_t; constexpr static size_t const value = 1907; };
template<> struct PrimeGreateOrEqual<1913> {
 using type = size_t; constexpr static size_t const value = 1913; };
template<> struct PrimeGreateOrEqual<1931> {
 using type = size_t; constexpr static size_t const value = 1931; };
template<> struct PrimeGreateOrEqual<1933> {
 using type = size_t; constexpr static size_t const value = 1933; };
template<> struct PrimeGreateOrEqual<1949> {
 using type = size_t; constexpr static size_t const value = 1949; };
template<> struct PrimeGreateOrEqual<1951> {
 using type = size_t; constexpr static size_t const value = 1951; };
template<> struct PrimeGreateOrEqual<1973> {
 using type = size_t; constexpr static size_t const value = 1973; };
template<> struct PrimeGreateOrEqual<1979> {
 using type = size_t; constexpr static size_t const value = 1979; };
template<> struct PrimeGreateOrEqual<1987> {
 using type = size_t; constexpr static size_t const value = 1987; };
template<> struct PrimeGreateOrEqual<1993> {
 using type = size_t; constexpr static size_t const value = 1993; };
template<> struct PrimeGreateOrEqual<1997> {
 using type = size_t; constexpr static size_t const value = 1997; };
template<> struct PrimeGreateOrEqual<1999> {
 using type = size_t; constexpr static size_t const value = 1999; };
template<> struct PrimeGreateOrEqual<2003> {
 using type = size_t; constexpr static size_t const value = 2003; };
template<> struct PrimeGreateOrEqual<2011> {
 using type = size_t; constexpr static size_t const value = 2011; };
template<> struct PrimeGreateOrEqual<2017> {
 using type = size_t; constexpr static size_t const value = 2017; };
template<> struct PrimeGreateOrEqual<2027> {
 using type = size_t; constexpr static size_t const value = 2027; };
template<> struct PrimeGreateOrEqual<2029> {
 using type = size_t; constexpr static size_t const value = 2029; };
template<> struct PrimeGreateOrEqual<2039> {
 using type = size_t; constexpr static size_t const value = 2039; };
template<> struct PrimeGreateOrEqual<2053> {
 using type = size_t; constexpr static size_t const value = 2053; };
template<> struct PrimeGreateOrEqual<2063> {
 using type = size_t; constexpr static size_t const value = 2063; };
template<> struct PrimeGreateOrEqual<2069> {
 using type = size_t; constexpr static size_t const value = 2069; };
template<> struct PrimeGreateOrEqual<2081> {
 using type = size_t; constexpr static size_t const value = 2081; };
template<> struct PrimeGreateOrEqual<2083> {
 using type = size_t; constexpr static size_t const value = 2083; };
template<> struct PrimeGreateOrEqual<2087> {
 using type = size_t; constexpr static size_t const value = 2087; };
template<> struct PrimeGreateOrEqual<2089> {
 using type = size_t; constexpr static size_t const value = 2089; };
template<> struct PrimeGreateOrEqual<2099> {
 using type = size_t; constexpr static size_t const value = 2099; };
template<> struct PrimeGreateOrEqual<2111> {
 using type = size_t; constexpr static size_t const value = 2111; };
template<> struct PrimeGreateOrEqual<2113> {
 using type = size_t; constexpr static size_t const value = 2113; };
template<> struct PrimeGreateOrEqual<2129> {
 using type = size_t; constexpr static size_t const value = 2129; };
template<> struct PrimeGreateOrEqual<2131> {
 using type = size_t; constexpr static size_t const value = 2131; };
template<> struct PrimeGreateOrEqual<2137> {
 using type = size_t; constexpr static size_t const value = 2137; };
template<> struct PrimeGreateOrEqual<2141> {
 using type = size_t; constexpr static size_t const value = 2141; };
template<> struct PrimeGreateOrEqual<2143> {
 using type = size_t; constexpr static size_t const value = 2143; };
template<> struct PrimeGreateOrEqual<2153> {
 using type = size_t; constexpr static size_t const value = 2153; };
template<> struct PrimeGreateOrEqual<2161> {
 using type = size_t; constexpr static size_t const value = 2161; };
template<> struct PrimeGreateOrEqual<2179> {
 using type = size_t; constexpr static size_t const value = 2179; };
template<> struct PrimeGreateOrEqual<2203> {
 using type = size_t; constexpr static size_t const value = 2203; };
template<> struct PrimeGreateOrEqual<2207> {
 using type = size_t; constexpr static size_t const value = 2207; };
template<> struct PrimeGreateOrEqual<2213> {
 using type = size_t; constexpr static size_t const value = 2213; };
template<> struct PrimeGreateOrEqual<2221> {
 using type = size_t; constexpr static size_t const value = 2221; };
template<> struct PrimeGreateOrEqual<2237> {
 using type = size_t; constexpr static size_t const value = 2237; };
template<> struct PrimeGreateOrEqual<2239> {
 using type = size_t; constexpr static size_t const value = 2239; };
template<> struct PrimeGreateOrEqual<2243> {
 using type = size_t; constexpr static size_t const value = 2243; };
template<> struct PrimeGreateOrEqual<2251> {
 using type = size_t; constexpr static size_t const value = 2251; };
template<> struct PrimeGreateOrEqual<2267> {
 using type = size_t; constexpr static size_t const value = 2267; };
template<> struct PrimeGreateOrEqual<2269> {
 using type = size_t; constexpr static size_t const value = 2269; };
template<> struct PrimeGreateOrEqual<2273> {
 using type = size_t; constexpr static size_t const value = 2273; };
template<> struct PrimeGreateOrEqual<2281> {
 using type = size_t; constexpr static size_t const value = 2281; };
template<> struct PrimeGreateOrEqual<2287> {
 using type = size_t; constexpr static size_t const value = 2287; };
template<> struct PrimeGreateOrEqual<2293> {
 using type = size_t; constexpr static size_t const value = 2293; };
template<> struct PrimeGreateOrEqual<2297> {
 using type = size_t; constexpr static size_t const value = 2297; };
template<> struct PrimeGreateOrEqual<2309> {
 using type = size_t; constexpr static size_t const value = 2309; };
template<> struct PrimeGreateOrEqual<2311> {
 using type = size_t; constexpr static size_t const value = 2311; };
template<> struct PrimeGreateOrEqual<2333> {
 using type = size_t; constexpr static size_t const value = 2333; };
template<> struct PrimeGreateOrEqual<2339> {
 using type = size_t; constexpr static size_t const value = 2339; };
template<> struct PrimeGreateOrEqual<2341> {
 using type = size_t; constexpr static size_t const value = 2341; };
template<> struct PrimeGreateOrEqual<2347> {
 using type = size_t; constexpr static size_t const value = 2347; };
template<> struct PrimeGreateOrEqual<2351> {
 using type = size_t; constexpr static size_t const value = 2351; };
template<> struct PrimeGreateOrEqual<2357> {
 using type = size_t; constexpr static size_t const value = 2357; };
template<> struct PrimeGreateOrEqual<2371> {
 using type = size_t; constexpr static size_t const value = 2371; };
template<> struct PrimeGreateOrEqual<2377> {
 using type = size_t; constexpr static size_t const value = 2377; };
template<> struct PrimeGreateOrEqual<2381> {
 using type = size_t; constexpr static size_t const value = 2381; };
template<> struct PrimeGreateOrEqual<2383> {
 using type = size_t; constexpr static size_t const value = 2383; };
template<> struct PrimeGreateOrEqual<2389> {
 using type = size_t; constexpr static size_t const value = 2389; };
template<> struct PrimeGreateOrEqual<2393> {
 using type = size_t; constexpr static size_t const value = 2393; };
template<> struct PrimeGreateOrEqual<2399> {
 using type = size_t; constexpr static size_t const value = 2399; };
template<> struct PrimeGreateOrEqual<2411> {
 using type = size_t; constexpr static size_t const value = 2411; };
template<> struct PrimeGreateOrEqual<2417> {
 using type = size_t; constexpr static size_t const value = 2417; };
template<> struct PrimeGreateOrEqual<2423> {
 using type = size_t; constexpr static size_t const value = 2423; };
template<> struct PrimeGreateOrEqual<2437> {
 using type = size_t; constexpr static size_t const value = 2437; };
template<> struct PrimeGreateOrEqual<2441> {
 using type = size_t; constexpr static size_t const value = 2441; };
template<> struct PrimeGreateOrEqual<2447> {
 using type = size_t; constexpr static size_t const value = 2447; };
template<> struct PrimeGreateOrEqual<2459> {
 using type = size_t; constexpr static size_t const value = 2459; };
template<> struct PrimeGreateOrEqual<2467> {
 using type = size_t; constexpr static size_t const value = 2467; };
template<> struct PrimeGreateOrEqual<2473> {
 using type = size_t; constexpr static size_t const value = 2473; };
template<> struct PrimeGreateOrEqual<2477> {
 using type = size_t; constexpr static size_t const value = 2477; };
template<> struct PrimeGreateOrEqual<2503> {
 using type = size_t; constexpr static size_t const value = 2503; };
template<> struct PrimeGreateOrEqual<2521> {
 using type = size_t; constexpr static size_t const value = 2521; };
template<> struct PrimeGreateOrEqual<2531> {
 using type = size_t; constexpr static size_t const value = 2531; };
template<> struct PrimeGreateOrEqual<2539> {
 using type = size_t; constexpr static size_t const value = 2539; };
template<> struct PrimeGreateOrEqual<2543> {
 using type = size_t; constexpr static size_t const value = 2543; };
template<> struct PrimeGreateOrEqual<2549> {
 using type = size_t; constexpr static size_t const value = 2549; };
template<> struct PrimeGreateOrEqual<2551> {
 using type = size_t; constexpr static size_t const value = 2551; };
template<> struct PrimeGreateOrEqual<2557> {
 using type = size_t; constexpr static size_t const value = 2557; };
template<> struct PrimeGreateOrEqual<2579> {
 using type = size_t; constexpr static size_t const value = 2579; };
template<> struct PrimeGreateOrEqual<2591> {
 using type = size_t; constexpr static size_t const value = 2591; };
template<> struct PrimeGreateOrEqual<2593> {
 using type = size_t; constexpr static size_t const value = 2593; };
template<> struct PrimeGreateOrEqual<2609> {
 using type = size_t; constexpr static size_t const value = 2609; };
template<> struct PrimeGreateOrEqual<2617> {
 using type = size_t; constexpr static size_t const value = 2617; };
template<> struct PrimeGreateOrEqual<2621> {
 using type = size_t; constexpr static size_t const value = 2621; };
template<> struct PrimeGreateOrEqual<2633> {
 using type = size_t; constexpr static size_t const value = 2633; };
template<> struct PrimeGreateOrEqual<2647> {
 using type = size_t; constexpr static size_t const value = 2647; };
template<> struct PrimeGreateOrEqual<2657> {
 using type = size_t; constexpr static size_t const value = 2657; };
template<> struct PrimeGreateOrEqual<2659> {
 using type = size_t; constexpr static size_t const value = 2659; };
template<> struct PrimeGreateOrEqual<2663> {
 using type = size_t; constexpr static size_t const value = 2663; };
template<> struct PrimeGreateOrEqual<2671> {
 using type = size_t; constexpr static size_t const value = 2671; };
template<> struct PrimeGreateOrEqual<2677> {
 using type = size_t; constexpr static size_t const value = 2677; };
template<> struct PrimeGreateOrEqual<2683> {
 using type = size_t; constexpr static size_t const value = 2683; };
template<> struct PrimeGreateOrEqual<2687> {
 using type = size_t; constexpr static size_t const value = 2687; };
template<> struct PrimeGreateOrEqual<2689> {
 using type = size_t; constexpr static size_t const value = 2689; };
template<> struct PrimeGreateOrEqual<2693> {
 using type = size_t; constexpr static size_t const value = 2693; };
template<> struct PrimeGreateOrEqual<2699> {
 using type = size_t; constexpr static size_t const value = 2699; };
template<> struct PrimeGreateOrEqual<2707> {
 using type = size_t; constexpr static size_t const value = 2707; };
template<> struct PrimeGreateOrEqual<2711> {
 using type = size_t; constexpr static size_t const value = 2711; };
template<> struct PrimeGreateOrEqual<2713> {
 using type = size_t; constexpr static size_t const value = 2713; };
template<> struct PrimeGreateOrEqual<2719> {
 using type = size_t; constexpr static size_t const value = 2719; };
template<> struct PrimeGreateOrEqual<2729> {
 using type = size_t; constexpr static size_t const value = 2729; };
template<> struct PrimeGreateOrEqual<2731> {
 using type = size_t; constexpr static size_t const value = 2731; };
template<> struct PrimeGreateOrEqual<2741> {
 using type = size_t; constexpr static size_t const value = 2741; };
template<> struct PrimeGreateOrEqual<2749> {
 using type = size_t; constexpr static size_t const value = 2749; };
template<> struct PrimeGreateOrEqual<2753> {
 using type = size_t; constexpr static size_t const value = 2753; };
template<> struct PrimeGreateOrEqual<2767> {
 using type = size_t; constexpr static size_t const value = 2767; };
template<> struct PrimeGreateOrEqual<2777> {
 using type = size_t; constexpr static size_t const value = 2777; };
template<> struct PrimeGreateOrEqual<2789> {
 using type = size_t; constexpr static size_t const value = 2789; };
template<> struct PrimeGreateOrEqual<2791> {
 using type = size_t; constexpr static size_t const value = 2791; };
template<> struct PrimeGreateOrEqual<2797> {
 using type = size_t; constexpr static size_t const value = 2797; };
template<> struct PrimeGreateOrEqual<2801> {
 using type = size_t; constexpr static size_t const value = 2801; };
template<> struct PrimeGreateOrEqual<2803> {
 using type = size_t; constexpr static size_t const value = 2803; };
template<> struct PrimeGreateOrEqual<2819> {
 using type = size_t; constexpr static size_t const value = 2819; };
template<> struct PrimeGreateOrEqual<2833> {
 using type = size_t; constexpr static size_t const value = 2833; };
template<> struct PrimeGreateOrEqual<2837> {
 using type = size_t; constexpr static size_t const value = 2837; };
template<> struct PrimeGreateOrEqual<2843> {
 using type = size_t; constexpr static size_t const value = 2843; };
template<> struct PrimeGreateOrEqual<2851> {
 using type = size_t; constexpr static size_t const value = 2851; };
template<> struct PrimeGreateOrEqual<2857> {
 using type = size_t; constexpr static size_t const value = 2857; };
template<> struct PrimeGreateOrEqual<2861> {
 using type = size_t; constexpr static size_t const value = 2861; };
template<> struct PrimeGreateOrEqual<2879> {
 using type = size_t; constexpr static size_t const value = 2879; };
template<> struct PrimeGreateOrEqual<2887> {
 using type = size_t; constexpr static size_t const value = 2887; };
template<> struct PrimeGreateOrEqual<2897> {
 using type = size_t; constexpr static size_t const value = 2897; };
template<> struct PrimeGreateOrEqual<2903> {
 using type = size_t; constexpr static size_t const value = 2903; };
template<> struct PrimeGreateOrEqual<2909> {
 using type = size_t; constexpr static size_t const value = 2909; };
template<> struct PrimeGreateOrEqual<2917> {
 using type = size_t; constexpr static size_t const value = 2917; };
template<> struct PrimeGreateOrEqual<2927> {
 using type = size_t; constexpr static size_t const value = 2927; };
template<> struct PrimeGreateOrEqual<2939> {
 using type = size_t; constexpr static size_t const value = 2939; };
template<> struct PrimeGreateOrEqual<2953> {
 using type = size_t; constexpr static size_t const value = 2953; };
template<> struct PrimeGreateOrEqual<2957> {
 using type = size_t; constexpr static size_t const value = 2957; };
template<> struct PrimeGreateOrEqual<2963> {
 using type = size_t; constexpr static size_t const value = 2963; };
template<> struct PrimeGreateOrEqual<2969> {
 using type = size_t; constexpr static size_t const value = 2969; };
template<> struct PrimeGreateOrEqual<2971> {
 using type = size_t; constexpr static size_t const value = 2971; };
template<> struct PrimeGreateOrEqual<2999> {
 using type = size_t; constexpr static size_t const value = 2999; };
template<> struct PrimeGreateOrEqual<3001> {
 using type = size_t; constexpr static size_t const value = 3001; };
template<> struct PrimeGreateOrEqual<3011> {
 using type = size_t; constexpr static size_t const value = 3011; };
template<> struct PrimeGreateOrEqual<3019> {
 using type = size_t; constexpr static size_t const value = 3019; };
template<> struct PrimeGreateOrEqual<3023> {
 using type = size_t; constexpr static size_t const value = 3023; };
template<> struct PrimeGreateOrEqual<3037> {
 using type = size_t; constexpr static size_t const value = 3037; };
template<> struct PrimeGreateOrEqual<3041> {
 using type = size_t; constexpr static size_t const value = 3041; };
template<> struct PrimeGreateOrEqual<3049> {
 using type = size_t; constexpr static size_t const value = 3049; };
template<> struct PrimeGreateOrEqual<3061> {
 using type = size_t; constexpr static size_t const value = 3061; };
template<> struct PrimeGreateOrEqual<3067> {
 using type = size_t; constexpr static size_t const value = 3067; };
template<> struct PrimeGreateOrEqual<3079> {
 using type = size_t; constexpr static size_t const value = 3079; };
template<> struct PrimeGreateOrEqual<3083> {
 using type = size_t; constexpr static size_t const value = 3083; };
template<> struct PrimeGreateOrEqual<3089> {
 using type = size_t; constexpr static size_t const value = 3089; };
template<> struct PrimeGreateOrEqual<3109> {
 using type = size_t; constexpr static size_t const value = 3109; };
template<> struct PrimeGreateOrEqual<3119> {
 using type = size_t; constexpr static size_t const value = 3119; };
template<> struct PrimeGreateOrEqual<3121> {
 using type = size_t; constexpr static size_t const value = 3121; };
template<> struct PrimeGreateOrEqual<3137> {
 using type = size_t; constexpr static size_t const value = 3137; };
template<> struct PrimeGreateOrEqual<3163> {
 using type = size_t; constexpr static size_t const value = 3163; };
template<> struct PrimeGreateOrEqual<3167> {
 using type = size_t; constexpr static size_t const value = 3167; };
template<> struct PrimeGreateOrEqual<3169> {
 using type = size_t; constexpr static size_t const value = 3169; };
template<> struct PrimeGreateOrEqual<3181> {
 using type = size_t; constexpr static size_t const value = 3181; };
template<> struct PrimeGreateOrEqual<3187> {
 using type = size_t; constexpr static size_t const value = 3187; };
template<> struct PrimeGreateOrEqual<3191> {
 using type = size_t; constexpr static size_t const value = 3191; };
template<> struct PrimeGreateOrEqual<3203> {
 using type = size_t; constexpr static size_t const value = 3203; };
template<> struct PrimeGreateOrEqual<3209> {
 using type = size_t; constexpr static size_t const value = 3209; };
template<> struct PrimeGreateOrEqual<3217> {
 using type = size_t; constexpr static size_t const value = 3217; };
template<> struct PrimeGreateOrEqual<3221> {
 using type = size_t; constexpr static size_t const value = 3221; };
template<> struct PrimeGreateOrEqual<3229> {
 using type = size_t; constexpr static size_t const value = 3229; };
template<> struct PrimeGreateOrEqual<3251> {
 using type = size_t; constexpr static size_t const value = 3251; };
template<> struct PrimeGreateOrEqual<3253> {
 using type = size_t; constexpr static size_t const value = 3253; };
template<> struct PrimeGreateOrEqual<3257> {
 using type = size_t; constexpr static size_t const value = 3257; };
template<> struct PrimeGreateOrEqual<3259> {
 using type = size_t; constexpr static size_t const value = 3259; };
template<> struct PrimeGreateOrEqual<3271> {
 using type = size_t; constexpr static size_t const value = 3271; };
template<> struct PrimeGreateOrEqual<3299> {
 using type = size_t; constexpr static size_t const value = 3299; };
template<> struct PrimeGreateOrEqual<3301> {
 using type = size_t; constexpr static size_t const value = 3301; };
template<> struct PrimeGreateOrEqual<3307> {
 using type = size_t; constexpr static size_t const value = 3307; };
template<> struct PrimeGreateOrEqual<3313> {
 using type = size_t; constexpr static size_t const value = 3313; };
template<> struct PrimeGreateOrEqual<3319> {
 using type = size_t; constexpr static size_t const value = 3319; };
template<> struct PrimeGreateOrEqual<3323> {
 using type = size_t; constexpr static size_t const value = 3323; };
template<> struct PrimeGreateOrEqual<3329> {
 using type = size_t; constexpr static size_t const value = 3329; };
template<> struct PrimeGreateOrEqual<3331> {
 using type = size_t; constexpr static size_t const value = 3331; };
template<> struct PrimeGreateOrEqual<3343> {
 using type = size_t; constexpr static size_t const value = 3343; };
template<> struct PrimeGreateOrEqual<3347> {
 using type = size_t; constexpr static size_t const value = 3347; };
template<> struct PrimeGreateOrEqual<3359> {
 using type = size_t; constexpr static size_t const value = 3359; };
template<> struct PrimeGreateOrEqual<3361> {
 using type = size_t; constexpr static size_t const value = 3361; };
template<> struct PrimeGreateOrEqual<3371> {
 using type = size_t; constexpr static size_t const value = 3371; };
template<> struct PrimeGreateOrEqual<3373> {
 using type = size_t; constexpr static size_t const value = 3373; };
template<> struct PrimeGreateOrEqual<3389> {
 using type = size_t; constexpr static size_t const value = 3389; };
template<> struct PrimeGreateOrEqual<3391> {
 using type = size_t; constexpr static size_t const value = 3391; };
template<> struct PrimeGreateOrEqual<3407> {
 using type = size_t; constexpr static size_t const value = 3407; };
template<> struct PrimeGreateOrEqual<3413> {
 using type = size_t; constexpr static size_t const value = 3413; };
template<> struct PrimeGreateOrEqual<3433> {
 using type = size_t; constexpr static size_t const value = 3433; };
template<> struct PrimeGreateOrEqual<3449> {
 using type = size_t; constexpr static size_t const value = 3449; };
template<> struct PrimeGreateOrEqual<3457> {
 using type = size_t; constexpr static size_t const value = 3457; };
template<> struct PrimeGreateOrEqual<3461> {
 using type = size_t; constexpr static size_t const value = 3461; };
template<> struct PrimeGreateOrEqual<3463> {
 using type = size_t; constexpr static size_t const value = 3463; };
template<> struct PrimeGreateOrEqual<3467> {
 using type = size_t; constexpr static size_t const value = 3467; };
template<> struct PrimeGreateOrEqual<3469> {
 using type = size_t; constexpr static size_t const value = 3469; };
template<> struct PrimeGreateOrEqual<3491> {
 using type = size_t; constexpr static size_t const value = 3491; };
template<> struct PrimeGreateOrEqual<3499> {
 using type = size_t; constexpr static size_t const value = 3499; };
template<> struct PrimeGreateOrEqual<3511> {
 using type = size_t; constexpr static size_t const value = 3511; };
template<> struct PrimeGreateOrEqual<3517> {
 using type = size_t; constexpr static size_t const value = 3517; };
template<> struct PrimeGreateOrEqual<3527> {
 using type = size_t; constexpr static size_t const value = 3527; };
template<> struct PrimeGreateOrEqual<3529> {
 using type = size_t; constexpr static size_t const value = 3529; };
template<> struct PrimeGreateOrEqual<3533> {
 using type = size_t; constexpr static size_t const value = 3533; };
template<> struct PrimeGreateOrEqual<3539> {
 using type = size_t; constexpr static size_t const value = 3539; };
template<> struct PrimeGreateOrEqual<3541> {
 using type = size_t; constexpr static size_t const value = 3541; };
template<> struct PrimeGreateOrEqual<3547> {
 using type = size_t; constexpr static size_t const value = 3547; };
template<> struct PrimeGreateOrEqual<3557> {
 using type = size_t; constexpr static size_t const value = 3557; };
template<> struct PrimeGreateOrEqual<3559> {
 using type = size_t; constexpr static size_t const value = 3559; };
template<> struct PrimeGreateOrEqual<3571> {
 using type = size_t; constexpr static size_t const value = 3571; };
template<> struct PrimeGreateOrEqual<3581> {
 using type = size_t; constexpr static size_t const value = 3581; };
template<> struct PrimeGreateOrEqual<3583> {
 using type = size_t; constexpr static size_t const value = 3583; };
template<> struct PrimeGreateOrEqual<3593> {
 using type = size_t; constexpr static size_t const value = 3593; };
template<> struct PrimeGreateOrEqual<3607> {
 using type = size_t; constexpr static size_t const value = 3607; };
template<> struct PrimeGreateOrEqual<3613> {
 using type = size_t; constexpr static size_t const value = 3613; };
template<> struct PrimeGreateOrEqual<3617> {
 using type = size_t; constexpr static size_t const value = 3617; };
template<> struct PrimeGreateOrEqual<3623> {
 using type = size_t; constexpr static size_t const value = 3623; };
template<> struct PrimeGreateOrEqual<3631> {
 using type = size_t; constexpr static size_t const value = 3631; };
template<> struct PrimeGreateOrEqual<3637> {
 using type = size_t; constexpr static size_t const value = 3637; };
template<> struct PrimeGreateOrEqual<3643> {
 using type = size_t; constexpr static size_t const value = 3643; };
template<> struct PrimeGreateOrEqual<3659> {
 using type = size_t; constexpr static size_t const value = 3659; };
template<> struct PrimeGreateOrEqual<3671> {
 using type = size_t; constexpr static size_t const value = 3671; };
template<> struct PrimeGreateOrEqual<3673> {
 using type = size_t; constexpr static size_t const value = 3673; };
template<> struct PrimeGreateOrEqual<3677> {
 using type = size_t; constexpr static size_t const value = 3677; };
template<> struct PrimeGreateOrEqual<3691> {
 using type = size_t; constexpr static size_t const value = 3691; };
template<> struct PrimeGreateOrEqual<3697> {
 using type = size_t; constexpr static size_t const value = 3697; };
template<> struct PrimeGreateOrEqual<3701> {
 using type = size_t; constexpr static size_t const value = 3701; };
template<> struct PrimeGreateOrEqual<3709> {
 using type = size_t; constexpr static size_t const value = 3709; };
template<> struct PrimeGreateOrEqual<3719> {
 using type = size_t; constexpr static size_t const value = 3719; };
template<> struct PrimeGreateOrEqual<3727> {
 using type = size_t; constexpr static size_t const value = 3727; };
template<> struct PrimeGreateOrEqual<3733> {
 using type = size_t; constexpr static size_t const value = 3733; };
template<> struct PrimeGreateOrEqual<3739> {
 using type = size_t; constexpr static size_t const value = 3739; };
template<> struct PrimeGreateOrEqual<3761> {
 using type = size_t; constexpr static size_t const value = 3761; };
template<> struct PrimeGreateOrEqual<3767> {
 using type = size_t; constexpr static size_t const value = 3767; };
template<> struct PrimeGreateOrEqual<3769> {
 using type = size_t; constexpr static size_t const value = 3769; };
template<> struct PrimeGreateOrEqual<3779> {
 using type = size_t; constexpr static size_t const value = 3779; };
template<> struct PrimeGreateOrEqual<3793> {
 using type = size_t; constexpr static size_t const value = 3793; };
template<> struct PrimeGreateOrEqual<3797> {
 using type = size_t; constexpr static size_t const value = 3797; };
template<> struct PrimeGreateOrEqual<3803> {
 using type = size_t; constexpr static size_t const value = 3803; };
template<> struct PrimeGreateOrEqual<3821> {
 using type = size_t; constexpr static size_t const value = 3821; };
template<> struct PrimeGreateOrEqual<3823> {
 using type = size_t; constexpr static size_t const value = 3823; };
template<> struct PrimeGreateOrEqual<3833> {
 using type = size_t; constexpr static size_t const value = 3833; };
template<> struct PrimeGreateOrEqual<3847> {
 using type = size_t; constexpr static size_t const value = 3847; };
template<> struct PrimeGreateOrEqual<3851> {
 using type = size_t; constexpr static size_t const value = 3851; };
template<> struct PrimeGreateOrEqual<3853> {
 using type = size_t; constexpr static size_t const value = 3853; };
template<> struct PrimeGreateOrEqual<3863> {
 using type = size_t; constexpr static size_t const value = 3863; };
template<> struct PrimeGreateOrEqual<3877> {
 using type = size_t; constexpr static size_t const value = 3877; };
template<> struct PrimeGreateOrEqual<3881> {
 using type = size_t; constexpr static size_t const value = 3881; };
template<> struct PrimeGreateOrEqual<3889> {
 using type = size_t; constexpr static size_t const value = 3889; };
template<> struct PrimeGreateOrEqual<3907> {
 using type = size_t; constexpr static size_t const value = 3907; };
template<> struct PrimeGreateOrEqual<3911> {
 using type = size_t; constexpr static size_t const value = 3911; };
template<> struct PrimeGreateOrEqual<3917> {
 using type = size_t; constexpr static size_t const value = 3917; };
template<> struct PrimeGreateOrEqual<3919> {
 using type = size_t; constexpr static size_t const value = 3919; };
template<> struct PrimeGreateOrEqual<3923> {
 using type = size_t; constexpr static size_t const value = 3923; };
template<> struct PrimeGreateOrEqual<3929> {
 using type = size_t; constexpr static size_t const value = 3929; };
template<> struct PrimeGreateOrEqual<3931> {
 using type = size_t; constexpr static size_t const value = 3931; };
template<> struct PrimeGreateOrEqual<3943> {
 using type = size_t; constexpr static size_t const value = 3943; };
template<> struct PrimeGreateOrEqual<3947> {
 using type = size_t; constexpr static size_t const value = 3947; };
template<> struct PrimeGreateOrEqual<3967> {
 using type = size_t; constexpr static size_t const value = 3967; };
template<> struct PrimeGreateOrEqual<3989> {
 using type = size_t; constexpr static size_t const value = 3989; };
template<> struct PrimeGreateOrEqual<4001> {
 using type = size_t; constexpr static size_t const value = 4001; };
template<> struct PrimeGreateOrEqual<4003> {
 using type = size_t; constexpr static size_t const value = 4003; };
template<> struct PrimeGreateOrEqual<4007> {
 using type = size_t; constexpr static size_t const value = 4007; };
template<> struct PrimeGreateOrEqual<4013> {
 using type = size_t; constexpr static size_t const value = 4013; };
template<> struct PrimeGreateOrEqual<4019> {
 using type = size_t; constexpr static size_t const value = 4019; };
template<> struct PrimeGreateOrEqual<4021> {
 using type = size_t; constexpr static size_t const value = 4021; };
template<> struct PrimeGreateOrEqual<4027> {
 using type = size_t; constexpr static size_t const value = 4027; };
template<> struct PrimeGreateOrEqual<4049> {
 using type = size_t; constexpr static size_t const value = 4049; };
template<> struct PrimeGreateOrEqual<4051> {
 using type = size_t; constexpr static size_t const value = 4051; };
template<> struct PrimeGreateOrEqual<4057> {
 using type = size_t; constexpr static size_t const value = 4057; };
template<> struct PrimeGreateOrEqual<4073> {
 using type = size_t; constexpr static size_t const value = 4073; };
template<> struct PrimeGreateOrEqual<4079> {
 using type = size_t; constexpr static size_t const value = 4079; };
template<> struct PrimeGreateOrEqual<4091> {
 using type = size_t; constexpr static size_t const value = 4091; };
template<> struct PrimeGreateOrEqual<4093> {
 using type = size_t; constexpr static size_t const value = 4093; };
template<> struct PrimeGreateOrEqual<4099> {
 using type = size_t; constexpr static size_t const value = 4099; };
template<> struct PrimeGreateOrEqual<4111> {
 using type = size_t; constexpr static size_t const value = 4111; };
template<> struct PrimeGreateOrEqual<4127> {
 using type = size_t; constexpr static size_t const value = 4127; };
template<> struct PrimeGreateOrEqual<4129> {
 using type = size_t; constexpr static size_t const value = 4129; };
template<> struct PrimeGreateOrEqual<4133> {
 using type = size_t; constexpr static size_t const value = 4133; };
template<> struct PrimeGreateOrEqual<4139> {
 using type = size_t; constexpr static size_t const value = 4139; };
template<> struct PrimeGreateOrEqual<4153> {
 using type = size_t; constexpr static size_t const value = 4153; };
template<> struct PrimeGreateOrEqual<4157> {
 using type = size_t; constexpr static size_t const value = 4157; };
template<> struct PrimeGreateOrEqual<4159> {
 using type = size_t; constexpr static size_t const value = 4159; };
template<> struct PrimeGreateOrEqual<4177> {
 using type = size_t; constexpr static size_t const value = 4177; };
template<> struct PrimeGreateOrEqual<4201> {
 using type = size_t; constexpr static size_t const value = 4201; };
template<> struct PrimeGreateOrEqual<4211> {
 using type = size_t; constexpr static size_t const value = 4211; };
template<> struct PrimeGreateOrEqual<4217> {
 using type = size_t; constexpr static size_t const value = 4217; };
template<> struct PrimeGreateOrEqual<4219> {
 using type = size_t; constexpr static size_t const value = 4219; };
template<> struct PrimeGreateOrEqual<4229> {
 using type = size_t; constexpr static size_t const value = 4229; };
template<> struct PrimeGreateOrEqual<4231> {
 using type = size_t; constexpr static size_t const value = 4231; };
template<> struct PrimeGreateOrEqual<4241> {
 using type = size_t; constexpr static size_t const value = 4241; };
template<> struct PrimeGreateOrEqual<4243> {
 using type = size_t; constexpr static size_t const value = 4243; };
template<> struct PrimeGreateOrEqual<4253> {
 using type = size_t; constexpr static size_t const value = 4253; };
template<> struct PrimeGreateOrEqual<4259> {
 using type = size_t; constexpr static size_t const value = 4259; };
template<> struct PrimeGreateOrEqual<4261> {
 using type = size_t; constexpr static size_t const value = 4261; };
template<> struct PrimeGreateOrEqual<4271> {
 using type = size_t; constexpr static size_t const value = 4271; };
template<> struct PrimeGreateOrEqual<4273> {
 using type = size_t; constexpr static size_t const value = 4273; };
template<> struct PrimeGreateOrEqual<4283> {
 using type = size_t; constexpr static size_t const value = 4283; };
template<> struct PrimeGreateOrEqual<4289> {
 using type = size_t; constexpr static size_t const value = 4289; };
template<> struct PrimeGreateOrEqual<4297> {
 using type = size_t; constexpr static size_t const value = 4297; };
template<> struct PrimeGreateOrEqual<4327> {
 using type = size_t; constexpr static size_t const value = 4327; };
template<> struct PrimeGreateOrEqual<4337> {
 using type = size_t; constexpr static size_t const value = 4337; };
template<> struct PrimeGreateOrEqual<4339> {
 using type = size_t; constexpr static size_t const value = 4339; };
template<> struct PrimeGreateOrEqual<4349> {
 using type = size_t; constexpr static size_t const value = 4349; };
template<> struct PrimeGreateOrEqual<4357> {
 using type = size_t; constexpr static size_t const value = 4357; };
template<> struct PrimeGreateOrEqual<4363> {
 using type = size_t; constexpr static size_t const value = 4363; };
template<> struct PrimeGreateOrEqual<4373> {
 using type = size_t; constexpr static size_t const value = 4373; };
template<> struct PrimeGreateOrEqual<4391> {
 using type = size_t; constexpr static size_t const value = 4391; };
template<> struct PrimeGreateOrEqual<4397> {
 using type = size_t; constexpr static size_t const value = 4397; };
template<> struct PrimeGreateOrEqual<4409> {
 using type = size_t; constexpr static size_t const value = 4409; };
template<> struct PrimeGreateOrEqual<4421> {
 using type = size_t; constexpr static size_t const value = 4421; };
template<> struct PrimeGreateOrEqual<4423> {
 using type = size_t; constexpr static size_t const value = 4423; };
template<> struct PrimeGreateOrEqual<4441> {
 using type = size_t; constexpr static size_t const value = 4441; };
template<> struct PrimeGreateOrEqual<4447> {
 using type = size_t; constexpr static size_t const value = 4447; };
template<> struct PrimeGreateOrEqual<4451> {
 using type = size_t; constexpr static size_t const value = 4451; };
template<> struct PrimeGreateOrEqual<4457> {
 using type = size_t; constexpr static size_t const value = 4457; };
template<> struct PrimeGreateOrEqual<4463> {
 using type = size_t; constexpr static size_t const value = 4463; };
template<> struct PrimeGreateOrEqual<4481> {
 using type = size_t; constexpr static size_t const value = 4481; };
template<> struct PrimeGreateOrEqual<4483> {
 using type = size_t; constexpr static size_t const value = 4483; };
template<> struct PrimeGreateOrEqual<4493> {
 using type = size_t; constexpr static size_t const value = 4493; };
template<> struct PrimeGreateOrEqual<4507> {
 using type = size_t; constexpr static size_t const value = 4507; };
template<> struct PrimeGreateOrEqual<4513> {
 using type = size_t; constexpr static size_t const value = 4513; };
template<> struct PrimeGreateOrEqual<4517> {
 using type = size_t; constexpr static size_t const value = 4517; };
template<> struct PrimeGreateOrEqual<4519> {
 using type = size_t; constexpr static size_t const value = 4519; };
template<> struct PrimeGreateOrEqual<4523> {
 using type = size_t; constexpr static size_t const value = 4523; };
template<> struct PrimeGreateOrEqual<4547> {
 using type = size_t; constexpr static size_t const value = 4547; };
template<> struct PrimeGreateOrEqual<4549> {
 using type = size_t; constexpr static size_t const value = 4549; };
template<> struct PrimeGreateOrEqual<4561> {
 using type = size_t; constexpr static size_t const value = 4561; };
template<> struct PrimeGreateOrEqual<4567> {
 using type = size_t; constexpr static size_t const value = 4567; };
template<> struct PrimeGreateOrEqual<4583> {
 using type = size_t; constexpr static size_t const value = 4583; };
template<> struct PrimeGreateOrEqual<4591> {
 using type = size_t; constexpr static size_t const value = 4591; };
template<> struct PrimeGreateOrEqual<4597> {
 using type = size_t; constexpr static size_t const value = 4597; };
template<> struct PrimeGreateOrEqual<4603> {
 using type = size_t; constexpr static size_t const value = 4603; };
template<> struct PrimeGreateOrEqual<4621> {
 using type = size_t; constexpr static size_t const value = 4621; };
template<> struct PrimeGreateOrEqual<4637> {
 using type = size_t; constexpr static size_t const value = 4637; };
template<> struct PrimeGreateOrEqual<4639> {
 using type = size_t; constexpr static size_t const value = 4639; };
template<> struct PrimeGreateOrEqual<4643> {
 using type = size_t; constexpr static size_t const value = 4643; };
template<> struct PrimeGreateOrEqual<4649> {
 using type = size_t; constexpr static size_t const value = 4649; };
template<> struct PrimeGreateOrEqual<4651> {
 using type = size_t; constexpr static size_t const value = 4651; };
template<> struct PrimeGreateOrEqual<4657> {
 using type = size_t; constexpr static size_t const value = 4657; };
template<> struct PrimeGreateOrEqual<4663> {
 using type = size_t; constexpr static size_t const value = 4663; };
template<> struct PrimeGreateOrEqual<4673> {
 using type = size_t; constexpr static size_t const value = 4673; };
template<> struct PrimeGreateOrEqual<4679> {
 using type = size_t; constexpr static size_t const value = 4679; };
template<> struct PrimeGreateOrEqual<4691> {
 using type = size_t; constexpr static size_t const value = 4691; };
template<> struct PrimeGreateOrEqual<4703> {
 using type = size_t; constexpr static size_t const value = 4703; };
template<> struct PrimeGreateOrEqual<4721> {
 using type = size_t; constexpr static size_t const value = 4721; };
template<> struct PrimeGreateOrEqual<4723> {
 using type = size_t; constexpr static size_t const value = 4723; };
template<> struct PrimeGreateOrEqual<4729> {
 using type = size_t; constexpr static size_t const value = 4729; };
template<> struct PrimeGreateOrEqual<4733> {
 using type = size_t; constexpr static size_t const value = 4733; };
template<> struct PrimeGreateOrEqual<4751> {
 using type = size_t; constexpr static size_t const value = 4751; };
template<> struct PrimeGreateOrEqual<4759> {
 using type = size_t; constexpr static size_t const value = 4759; };
template<> struct PrimeGreateOrEqual<4783> {
 using type = size_t; constexpr static size_t const value = 4783; };
template<> struct PrimeGreateOrEqual<4787> {
 using type = size_t; constexpr static size_t const value = 4787; };
template<> struct PrimeGreateOrEqual<4789> {
 using type = size_t; constexpr static size_t const value = 4789; };
template<> struct PrimeGreateOrEqual<4793> {
 using type = size_t; constexpr static size_t const value = 4793; };
template<> struct PrimeGreateOrEqual<4799> {
 using type = size_t; constexpr static size_t const value = 4799; };
template<> struct PrimeGreateOrEqual<4801> {
 using type = size_t; constexpr static size_t const value = 4801; };
template<> struct PrimeGreateOrEqual<4813> {
 using type = size_t; constexpr static size_t const value = 4813; };
template<> struct PrimeGreateOrEqual<4817> {
 using type = size_t; constexpr static size_t const value = 4817; };
template<> struct PrimeGreateOrEqual<4831> {
 using type = size_t; constexpr static size_t const value = 4831; };
template<> struct PrimeGreateOrEqual<4861> {
 using type = size_t; constexpr static size_t const value = 4861; };
template<> struct PrimeGreateOrEqual<4871> {
 using type = size_t; constexpr static size_t const value = 4871; };
template<> struct PrimeGreateOrEqual<4877> {
 using type = size_t; constexpr static size_t const value = 4877; };
template<> struct PrimeGreateOrEqual<4889> {
 using type = size_t; constexpr static size_t const value = 4889; };
template<> struct PrimeGreateOrEqual<4903> {
 using type = size_t; constexpr static size_t const value = 4903; };
template<> struct PrimeGreateOrEqual<4909> {
 using type = size_t; constexpr static size_t const value = 4909; };
template<> struct PrimeGreateOrEqual<4919> {
 using type = size_t; constexpr static size_t const value = 4919; };
template<> struct PrimeGreateOrEqual<4931> {
 using type = size_t; constexpr static size_t const value = 4931; };
template<> struct PrimeGreateOrEqual<4933> {
 using type = size_t; constexpr static size_t const value = 4933; };
template<> struct PrimeGreateOrEqual<4937> {
 using type = size_t; constexpr static size_t const value = 4937; };
template<> struct PrimeGreateOrEqual<4943> {
 using type = size_t; constexpr static size_t const value = 4943; };
template<> struct PrimeGreateOrEqual<4951> {
 using type = size_t; constexpr static size_t const value = 4951; };
template<> struct PrimeGreateOrEqual<4957> {
 using type = size_t; constexpr static size_t const value = 4957; };
template<> struct PrimeGreateOrEqual<4967> {
 using type = size_t; constexpr static size_t const value = 4967; };
template<> struct PrimeGreateOrEqual<4969> {
 using type = size_t; constexpr static size_t const value = 4969; };
template<> struct PrimeGreateOrEqual<4973> {
 using type = size_t; constexpr static size_t const value = 4973; };
template<> struct PrimeGreateOrEqual<4987> {
 using type = size_t; constexpr static size_t const value = 4987; };
template<> struct PrimeGreateOrEqual<4993> {
 using type = size_t; constexpr static size_t const value = 4993; };
template<> struct PrimeGreateOrEqual<4999> {
 using type = size_t; constexpr static size_t const value = 4999; };
template<> struct PrimeGreateOrEqual<5003> {
 using type = size_t; constexpr static size_t const value = 5003; };
template<> struct PrimeGreateOrEqual<5009> {
 using type = size_t; constexpr static size_t const value = 5009; };
template<> struct PrimeGreateOrEqual<5011> {
 using type = size_t; constexpr static size_t const value = 5011; };
template<> struct PrimeGreateOrEqual<5021> {
 using type = size_t; constexpr static size_t const value = 5021; };
template<> struct PrimeGreateOrEqual<5023> {
 using type = size_t; constexpr static size_t const value = 5023; };
template<> struct PrimeGreateOrEqual<5039> {
 using type = size_t; constexpr static size_t const value = 5039; };
template<> struct PrimeGreateOrEqual<5051> {
 using type = size_t; constexpr static size_t const value = 5051; };
template<> struct PrimeGreateOrEqual<5059> {
 using type = size_t; constexpr static size_t const value = 5059; };
template<> struct PrimeGreateOrEqual<5077> {
 using type = size_t; constexpr static size_t const value = 5077; };
template<> struct PrimeGreateOrEqual<5081> {
 using type = size_t; constexpr static size_t const value = 5081; };
template<> struct PrimeGreateOrEqual<5087> {
 using type = size_t; constexpr static size_t const value = 5087; };
template<> struct PrimeGreateOrEqual<5099> {
 using type = size_t; constexpr static size_t const value = 5099; };
template<> struct PrimeGreateOrEqual<5101> {
 using type = size_t; constexpr static size_t const value = 5101; };
template<> struct PrimeGreateOrEqual<5107> {
 using type = size_t; constexpr static size_t const value = 5107; };
template<> struct PrimeGreateOrEqual<5113> {
 using type = size_t; constexpr static size_t const value = 5113; };
template<> struct PrimeGreateOrEqual<5119> {
 using type = size_t; constexpr static size_t const value = 5119; };
template<> struct PrimeGreateOrEqual<5147> {
 using type = size_t; constexpr static size_t const value = 5147; };
template<> struct PrimeGreateOrEqual<5153> {
 using type = size_t; constexpr static size_t const value = 5153; };
template<> struct PrimeGreateOrEqual<5167> {
 using type = size_t; constexpr static size_t const value = 5167; };
template<> struct PrimeGreateOrEqual<5171> {
 using type = size_t; constexpr static size_t const value = 5171; };
template<> struct PrimeGreateOrEqual<5179> {
 using type = size_t; constexpr static size_t const value = 5179; };
template<> struct PrimeGreateOrEqual<5189> {
 using type = size_t; constexpr static size_t const value = 5189; };
template<> struct PrimeGreateOrEqual<5197> {
 using type = size_t; constexpr static size_t const value = 5197; };
template<> struct PrimeGreateOrEqual<5209> {
 using type = size_t; constexpr static size_t const value = 5209; };
template<> struct PrimeGreateOrEqual<5227> {
 using type = size_t; constexpr static size_t const value = 5227; };
template<> struct PrimeGreateOrEqual<5231> {
 using type = size_t; constexpr static size_t const value = 5231; };
template<> struct PrimeGreateOrEqual<5233> {
 using type = size_t; constexpr static size_t const value = 5233; };
template<> struct PrimeGreateOrEqual<5237> {
 using type = size_t; constexpr static size_t const value = 5237; };
template<> struct PrimeGreateOrEqual<5261> {
 using type = size_t; constexpr static size_t const value = 5261; };
template<> struct PrimeGreateOrEqual<5273> {
 using type = size_t; constexpr static size_t const value = 5273; };
template<> struct PrimeGreateOrEqual<5279> {
 using type = size_t; constexpr static size_t const value = 5279; };
template<> struct PrimeGreateOrEqual<5281> {
 using type = size_t; constexpr static size_t const value = 5281; };
template<> struct PrimeGreateOrEqual<5297> {
 using type = size_t; constexpr static size_t const value = 5297; };
template<> struct PrimeGreateOrEqual<5303> {
 using type = size_t; constexpr static size_t const value = 5303; };
template<> struct PrimeGreateOrEqual<5309> {
 using type = size_t; constexpr static size_t const value = 5309; };
template<> struct PrimeGreateOrEqual<5323> {
 using type = size_t; constexpr static size_t const value = 5323; };
template<> struct PrimeGreateOrEqual<5333> {
 using type = size_t; constexpr static size_t const value = 5333; };
template<> struct PrimeGreateOrEqual<5347> {
 using type = size_t; constexpr static size_t const value = 5347; };
template<> struct PrimeGreateOrEqual<5351> {
 using type = size_t; constexpr static size_t const value = 5351; };
template<> struct PrimeGreateOrEqual<5381> {
 using type = size_t; constexpr static size_t const value = 5381; };
template<> struct PrimeGreateOrEqual<5387> {
 using type = size_t; constexpr static size_t const value = 5387; };
template<> struct PrimeGreateOrEqual<5393> {
 using type = size_t; constexpr static size_t const value = 5393; };
template<> struct PrimeGreateOrEqual<5399> {
 using type = size_t; constexpr static size_t const value = 5399; };
template<> struct PrimeGreateOrEqual<5407> {
 using type = size_t; constexpr static size_t const value = 5407; };
template<> struct PrimeGreateOrEqual<5413> {
 using type = size_t; constexpr static size_t const value = 5413; };
template<> struct PrimeGreateOrEqual<5417> {
 using type = size_t; constexpr static size_t const value = 5417; };
template<> struct PrimeGreateOrEqual<5419> {
 using type = size_t; constexpr static size_t const value = 5419; };
template<> struct PrimeGreateOrEqual<5431> {
 using type = size_t; constexpr static size_t const value = 5431; };
template<> struct PrimeGreateOrEqual<5437> {
 using type = size_t; constexpr static size_t const value = 5437; };
template<> struct PrimeGreateOrEqual<5441> {
 using type = size_t; constexpr static size_t const value = 5441; };
template<> struct PrimeGreateOrEqual<5443> {
 using type = size_t; constexpr static size_t const value = 5443; };
template<> struct PrimeGreateOrEqual<5449> {
 using type = size_t; constexpr static size_t const value = 5449; };
template<> struct PrimeGreateOrEqual<5471> {
 using type = size_t; constexpr static size_t const value = 5471; };
template<> struct PrimeGreateOrEqual<5477> {
 using type = size_t; constexpr static size_t const value = 5477; };
template<> struct PrimeGreateOrEqual<5479> {
 using type = size_t; constexpr static size_t const value = 5479; };
template<> struct PrimeGreateOrEqual<5483> {
 using type = size_t; constexpr static size_t const value = 5483; };
template<> struct PrimeGreateOrEqual<5501> {
 using type = size_t; constexpr static size_t const value = 5501; };
template<> struct PrimeGreateOrEqual<5503> {
 using type = size_t; constexpr static size_t const value = 5503; };
template<> struct PrimeGreateOrEqual<5507> {
 using type = size_t; constexpr static size_t const value = 5507; };
template<> struct PrimeGreateOrEqual<5519> {
 using type = size_t; constexpr static size_t const value = 5519; };
template<> struct PrimeGreateOrEqual<5521> {
 using type = size_t; constexpr static size_t const value = 5521; };
template<> struct PrimeGreateOrEqual<5527> {
 using type = size_t; constexpr static size_t const value = 5527; };
template<> struct PrimeGreateOrEqual<5531> {
 using type = size_t; constexpr static size_t const value = 5531; };
template<> struct PrimeGreateOrEqual<5557> {
 using type = size_t; constexpr static size_t const value = 5557; };
template<> struct PrimeGreateOrEqual<5563> {
 using type = size_t; constexpr static size_t const value = 5563; };
template<> struct PrimeGreateOrEqual<5569> {
 using type = size_t; constexpr static size_t const value = 5569; };
template<> struct PrimeGreateOrEqual<5573> {
 using type = size_t; constexpr static size_t const value = 5573; };
template<> struct PrimeGreateOrEqual<5581> {
 using type = size_t; constexpr static size_t const value = 5581; };
template<> struct PrimeGreateOrEqual<5591> {
 using type = size_t; constexpr static size_t const value = 5591; };
template<> struct PrimeGreateOrEqual<5623> {
 using type = size_t; constexpr static size_t const value = 5623; };
template<> struct PrimeGreateOrEqual<5639> {
 using type = size_t; constexpr static size_t const value = 5639; };
template<> struct PrimeGreateOrEqual<5641> {
 using type = size_t; constexpr static size_t const value = 5641; };
template<> struct PrimeGreateOrEqual<5647> {
 using type = size_t; constexpr static size_t const value = 5647; };
template<> struct PrimeGreateOrEqual<5651> {
 using type = size_t; constexpr static size_t const value = 5651; };
template<> struct PrimeGreateOrEqual<5653> {
 using type = size_t; constexpr static size_t const value = 5653; };
template<> struct PrimeGreateOrEqual<5657> {
 using type = size_t; constexpr static size_t const value = 5657; };
template<> struct PrimeGreateOrEqual<5659> {
 using type = size_t; constexpr static size_t const value = 5659; };
template<> struct PrimeGreateOrEqual<5669> {
 using type = size_t; constexpr static size_t const value = 5669; };
template<> struct PrimeGreateOrEqual<5683> {
 using type = size_t; constexpr static size_t const value = 5683; };
template<> struct PrimeGreateOrEqual<5689> {
 using type = size_t; constexpr static size_t const value = 5689; };
template<> struct PrimeGreateOrEqual<5693> {
 using type = size_t; constexpr static size_t const value = 5693; };
template<> struct PrimeGreateOrEqual<5701> {
 using type = size_t; constexpr static size_t const value = 5701; };
template<> struct PrimeGreateOrEqual<5711> {
 using type = size_t; constexpr static size_t const value = 5711; };
template<> struct PrimeGreateOrEqual<5717> {
 using type = size_t; constexpr static size_t const value = 5717; };
template<> struct PrimeGreateOrEqual<5737> {
 using type = size_t; constexpr static size_t const value = 5737; };
template<> struct PrimeGreateOrEqual<5741> {
 using type = size_t; constexpr static size_t const value = 5741; };
template<> struct PrimeGreateOrEqual<5743> {
 using type = size_t; constexpr static size_t const value = 5743; };
template<> struct PrimeGreateOrEqual<5749> {
 using type = size_t; constexpr static size_t const value = 5749; };
template<> struct PrimeGreateOrEqual<5779> {
 using type = size_t; constexpr static size_t const value = 5779; };
template<> struct PrimeGreateOrEqual<5783> {
 using type = size_t; constexpr static size_t const value = 5783; };
template<> struct PrimeGreateOrEqual<5791> {
 using type = size_t; constexpr static size_t const value = 5791; };
template<> struct PrimeGreateOrEqual<5801> {
 using type = size_t; constexpr static size_t const value = 5801; };
template<> struct PrimeGreateOrEqual<5807> {
 using type = size_t; constexpr static size_t const value = 5807; };
template<> struct PrimeGreateOrEqual<5813> {
 using type = size_t; constexpr static size_t const value = 5813; };
template<> struct PrimeGreateOrEqual<5821> {
 using type = size_t; constexpr static size_t const value = 5821; };
template<> struct PrimeGreateOrEqual<5827> {
 using type = size_t; constexpr static size_t const value = 5827; };
template<> struct PrimeGreateOrEqual<5839> {
 using type = size_t; constexpr static size_t const value = 5839; };
template<> struct PrimeGreateOrEqual<5843> {
 using type = size_t; constexpr static size_t const value = 5843; };
template<> struct PrimeGreateOrEqual<5849> {
 using type = size_t; constexpr static size_t const value = 5849; };
template<> struct PrimeGreateOrEqual<5851> {
 using type = size_t; constexpr static size_t const value = 5851; };
template<> struct PrimeGreateOrEqual<5857> {
 using type = size_t; constexpr static size_t const value = 5857; };
template<> struct PrimeGreateOrEqual<5861> {
 using type = size_t; constexpr static size_t const value = 5861; };
template<> struct PrimeGreateOrEqual<5867> {
 using type = size_t; constexpr static size_t const value = 5867; };
template<> struct PrimeGreateOrEqual<5869> {
 using type = size_t; constexpr static size_t const value = 5869; };
template<> struct PrimeGreateOrEqual<5879> {
 using type = size_t; constexpr static size_t const value = 5879; };
template<> struct PrimeGreateOrEqual<5881> {
 using type = size_t; constexpr static size_t const value = 5881; };
template<> struct PrimeGreateOrEqual<5897> {
 using type = size_t; constexpr static size_t const value = 5897; };
template<> struct PrimeGreateOrEqual<5903> {
 using type = size_t; constexpr static size_t const value = 5903; };
template<> struct PrimeGreateOrEqual<5923> {
 using type = size_t; constexpr static size_t const value = 5923; };
template<> struct PrimeGreateOrEqual<5927> {
 using type = size_t; constexpr static size_t const value = 5927; };
template<> struct PrimeGreateOrEqual<5939> {
 using type = size_t; constexpr static size_t const value = 5939; };
template<> struct PrimeGreateOrEqual<5953> {
 using type = size_t; constexpr static size_t const value = 5953; };
template<> struct PrimeGreateOrEqual<5981> {
 using type = size_t; constexpr static size_t const value = 5981; };
template<> struct PrimeGreateOrEqual<5987> {
 using type = size_t; constexpr static size_t const value = 5987; };
template<> struct PrimeGreateOrEqual<6007> {
 using type = size_t; constexpr static size_t const value = 6007; };
template<> struct PrimeGreateOrEqual<6011> {
 using type = size_t; constexpr static size_t const value = 6011; };
template<> struct PrimeGreateOrEqual<6029> {
 using type = size_t; constexpr static size_t const value = 6029; };
template<> struct PrimeGreateOrEqual<6037> {
 using type = size_t; constexpr static size_t const value = 6037; };
template<> struct PrimeGreateOrEqual<6043> {
 using type = size_t; constexpr static size_t const value = 6043; };
template<> struct PrimeGreateOrEqual<6047> {
 using type = size_t; constexpr static size_t const value = 6047; };
template<> struct PrimeGreateOrEqual<6053> {
 using type = size_t; constexpr static size_t const value = 6053; };
template<> struct PrimeGreateOrEqual<6067> {
 using type = size_t; constexpr static size_t const value = 6067; };
template<> struct PrimeGreateOrEqual<6073> {
 using type = size_t; constexpr static size_t const value = 6073; };
template<> struct PrimeGreateOrEqual<6079> {
 using type = size_t; constexpr static size_t const value = 6079; };
template<> struct PrimeGreateOrEqual<6089> {
 using type = size_t; constexpr static size_t const value = 6089; };
template<> struct PrimeGreateOrEqual<6091> {
 using type = size_t; constexpr static size_t const value = 6091; };
template<> struct PrimeGreateOrEqual<6101> {
 using type = size_t; constexpr static size_t const value = 6101; };
template<> struct PrimeGreateOrEqual<6113> {
 using type = size_t; constexpr static size_t const value = 6113; };
template<> struct PrimeGreateOrEqual<6121> {
 using type = size_t; constexpr static size_t const value = 6121; };
template<> struct PrimeGreateOrEqual<6131> {
 using type = size_t; constexpr static size_t const value = 6131; };
template<> struct PrimeGreateOrEqual<6133> {
 using type = size_t; constexpr static size_t const value = 6133; };
template<> struct PrimeGreateOrEqual<6143> {
 using type = size_t; constexpr static size_t const value = 6143; };
template<> struct PrimeGreateOrEqual<6151> {
 using type = size_t; constexpr static size_t const value = 6151; };
template<> struct PrimeGreateOrEqual<6163> {
 using type = size_t; constexpr static size_t const value = 6163; };
template<> struct PrimeGreateOrEqual<6173> {
 using type = size_t; constexpr static size_t const value = 6173; };
template<> struct PrimeGreateOrEqual<6197> {
 using type = size_t; constexpr static size_t const value = 6197; };
template<> struct PrimeGreateOrEqual<6199> {
 using type = size_t; constexpr static size_t const value = 6199; };
template<> struct PrimeGreateOrEqual<6203> {
 using type = size_t; constexpr static size_t const value = 6203; };
template<> struct PrimeGreateOrEqual<6211> {
 using type = size_t; constexpr static size_t const value = 6211; };
template<> struct PrimeGreateOrEqual<6217> {
 using type = size_t; constexpr static size_t const value = 6217; };
template<> struct PrimeGreateOrEqual<6221> {
 using type = size_t; constexpr static size_t const value = 6221; };
template<> struct PrimeGreateOrEqual<6229> {
 using type = size_t; constexpr static size_t const value = 6229; };
template<> struct PrimeGreateOrEqual<6247> {
 using type = size_t; constexpr static size_t const value = 6247; };
template<> struct PrimeGreateOrEqual<6257> {
 using type = size_t; constexpr static size_t const value = 6257; };
template<> struct PrimeGreateOrEqual<6263> {
 using type = size_t; constexpr static size_t const value = 6263; };
template<> struct PrimeGreateOrEqual<6269> {
 using type = size_t; constexpr static size_t const value = 6269; };
template<> struct PrimeGreateOrEqual<6271> {
 using type = size_t; constexpr static size_t const value = 6271; };
template<> struct PrimeGreateOrEqual<6277> {
 using type = size_t; constexpr static size_t const value = 6277; };
template<> struct PrimeGreateOrEqual<6287> {
 using type = size_t; constexpr static size_t const value = 6287; };
template<> struct PrimeGreateOrEqual<6299> {
 using type = size_t; constexpr static size_t const value = 6299; };
template<> struct PrimeGreateOrEqual<6301> {
 using type = size_t; constexpr static size_t const value = 6301; };
template<> struct PrimeGreateOrEqual<6311> {
 using type = size_t; constexpr static size_t const value = 6311; };
template<> struct PrimeGreateOrEqual<6317> {
 using type = size_t; constexpr static size_t const value = 6317; };
template<> struct PrimeGreateOrEqual<6323> {
 using type = size_t; constexpr static size_t const value = 6323; };
template<> struct PrimeGreateOrEqual<6329> {
 using type = size_t; constexpr static size_t const value = 6329; };
template<> struct PrimeGreateOrEqual<6337> {
 using type = size_t; constexpr static size_t const value = 6337; };
template<> struct PrimeGreateOrEqual<6343> {
 using type = size_t; constexpr static size_t const value = 6343; };
template<> struct PrimeGreateOrEqual<6353> {
 using type = size_t; constexpr static size_t const value = 6353; };
template<> struct PrimeGreateOrEqual<6359> {
 using type = size_t; constexpr static size_t const value = 6359; };
template<> struct PrimeGreateOrEqual<6361> {
 using type = size_t; constexpr static size_t const value = 6361; };
template<> struct PrimeGreateOrEqual<6367> {
 using type = size_t; constexpr static size_t const value = 6367; };
template<> struct PrimeGreateOrEqual<6373> {
 using type = size_t; constexpr static size_t const value = 6373; };
template<> struct PrimeGreateOrEqual<6379> {
 using type = size_t; constexpr static size_t const value = 6379; };
template<> struct PrimeGreateOrEqual<6389> {
 using type = size_t; constexpr static size_t const value = 6389; };
template<> struct PrimeGreateOrEqual<6397> {
 using type = size_t; constexpr static size_t const value = 6397; };
template<> struct PrimeGreateOrEqual<6421> {
 using type = size_t; constexpr static size_t const value = 6421; };
template<> struct PrimeGreateOrEqual<6427> {
 using type = size_t; constexpr static size_t const value = 6427; };
template<> struct PrimeGreateOrEqual<6449> {
 using type = size_t; constexpr static size_t const value = 6449; };
template<> struct PrimeGreateOrEqual<6451> {
 using type = size_t; constexpr static size_t const value = 6451; };
template<> struct PrimeGreateOrEqual<6469> {
 using type = size_t; constexpr static size_t const value = 6469; };
template<> struct PrimeGreateOrEqual<6473> {
 using type = size_t; constexpr static size_t const value = 6473; };
template<> struct PrimeGreateOrEqual<6481> {
 using type = size_t; constexpr static size_t const value = 6481; };
template<> struct PrimeGreateOrEqual<6491> {
 using type = size_t; constexpr static size_t const value = 6491; };
template<> struct PrimeGreateOrEqual<6521> {
 using type = size_t; constexpr static size_t const value = 6521; };
template<> struct PrimeGreateOrEqual<6529> {
 using type = size_t; constexpr static size_t const value = 6529; };
template<> struct PrimeGreateOrEqual<6547> {
 using type = size_t; constexpr static size_t const value = 6547; };
template<> struct PrimeGreateOrEqual<6551> {
 using type = size_t; constexpr static size_t const value = 6551; };
template<> struct PrimeGreateOrEqual<6553> {
 using type = size_t; constexpr static size_t const value = 6553; };
template<> struct PrimeGreateOrEqual<6563> {
 using type = size_t; constexpr static size_t const value = 6563; };
template<> struct PrimeGreateOrEqual<6569> {
 using type = size_t; constexpr static size_t const value = 6569; };
template<> struct PrimeGreateOrEqual<6571> {
 using type = size_t; constexpr static size_t const value = 6571; };
template<> struct PrimeGreateOrEqual<6577> {
 using type = size_t; constexpr static size_t const value = 6577; };
template<> struct PrimeGreateOrEqual<6581> {
 using type = size_t; constexpr static size_t const value = 6581; };
template<> struct PrimeGreateOrEqual<6599> {
 using type = size_t; constexpr static size_t const value = 6599; };
template<> struct PrimeGreateOrEqual<6607> {
 using type = size_t; constexpr static size_t const value = 6607; };
template<> struct PrimeGreateOrEqual<6619> {
 using type = size_t; constexpr static size_t const value = 6619; };
template<> struct PrimeGreateOrEqual<6637> {
 using type = size_t; constexpr static size_t const value = 6637; };
template<> struct PrimeGreateOrEqual<6653> {
 using type = size_t; constexpr static size_t const value = 6653; };
template<> struct PrimeGreateOrEqual<6659> {
 using type = size_t; constexpr static size_t const value = 6659; };
template<> struct PrimeGreateOrEqual<6661> {
 using type = size_t; constexpr static size_t const value = 6661; };
template<> struct PrimeGreateOrEqual<6673> {
 using type = size_t; constexpr static size_t const value = 6673; };
template<> struct PrimeGreateOrEqual<6679> {
 using type = size_t; constexpr static size_t const value = 6679; };
template<> struct PrimeGreateOrEqual<6689> {
 using type = size_t; constexpr static size_t const value = 6689; };
template<> struct PrimeGreateOrEqual<6691> {
 using type = size_t; constexpr static size_t const value = 6691; };
template<> struct PrimeGreateOrEqual<6701> {
 using type = size_t; constexpr static size_t const value = 6701; };
template<> struct PrimeGreateOrEqual<6703> {
 using type = size_t; constexpr static size_t const value = 6703; };
template<> struct PrimeGreateOrEqual<6709> {
 using type = size_t; constexpr static size_t const value = 6709; };
template<> struct PrimeGreateOrEqual<6719> {
 using type = size_t; constexpr static size_t const value = 6719; };
template<> struct PrimeGreateOrEqual<6733> {
 using type = size_t; constexpr static size_t const value = 6733; };
template<> struct PrimeGreateOrEqual<6737> {
 using type = size_t; constexpr static size_t const value = 6737; };
template<> struct PrimeGreateOrEqual<6761> {
 using type = size_t; constexpr static size_t const value = 6761; };
template<> struct PrimeGreateOrEqual<6763> {
 using type = size_t; constexpr static size_t const value = 6763; };
template<> struct PrimeGreateOrEqual<6779> {
 using type = size_t; constexpr static size_t const value = 6779; };
template<> struct PrimeGreateOrEqual<6781> {
 using type = size_t; constexpr static size_t const value = 6781; };
template<> struct PrimeGreateOrEqual<6791> {
 using type = size_t; constexpr static size_t const value = 6791; };
template<> struct PrimeGreateOrEqual<6793> {
 using type = size_t; constexpr static size_t const value = 6793; };
template<> struct PrimeGreateOrEqual<6803> {
 using type = size_t; constexpr static size_t const value = 6803; };
template<> struct PrimeGreateOrEqual<6823> {
 using type = size_t; constexpr static size_t const value = 6823; };
template<> struct PrimeGreateOrEqual<6827> {
 using type = size_t; constexpr static size_t const value = 6827; };
template<> struct PrimeGreateOrEqual<6829> {
 using type = size_t; constexpr static size_t const value = 6829; };
template<> struct PrimeGreateOrEqual<6833> {
 using type = size_t; constexpr static size_t const value = 6833; };
template<> struct PrimeGreateOrEqual<6841> {
 using type = size_t; constexpr static size_t const value = 6841; };
template<> struct PrimeGreateOrEqual<6857> {
 using type = size_t; constexpr static size_t const value = 6857; };
template<> struct PrimeGreateOrEqual<6863> {
 using type = size_t; constexpr static size_t const value = 6863; };
template<> struct PrimeGreateOrEqual<6869> {
 using type = size_t; constexpr static size_t const value = 6869; };
template<> struct PrimeGreateOrEqual<6871> {
 using type = size_t; constexpr static size_t const value = 6871; };
template<> struct PrimeGreateOrEqual<6883> {
 using type = size_t; constexpr static size_t const value = 6883; };
template<> struct PrimeGreateOrEqual<6899> {
 using type = size_t; constexpr static size_t const value = 6899; };
template<> struct PrimeGreateOrEqual<6907> {
 using type = size_t; constexpr static size_t const value = 6907; };
template<> struct PrimeGreateOrEqual<6911> {
 using type = size_t; constexpr static size_t const value = 6911; };
template<> struct PrimeGreateOrEqual<6917> {
 using type = size_t; constexpr static size_t const value = 6917; };
template<> struct PrimeGreateOrEqual<6947> {
 using type = size_t; constexpr static size_t const value = 6947; };
template<> struct PrimeGreateOrEqual<6949> {
 using type = size_t; constexpr static size_t const value = 6949; };
template<> struct PrimeGreateOrEqual<6959> {
 using type = size_t; constexpr static size_t const value = 6959; };
template<> struct PrimeGreateOrEqual<6961> {
 using type = size_t; constexpr static size_t const value = 6961; };
template<> struct PrimeGreateOrEqual<6967> {
 using type = size_t; constexpr static size_t const value = 6967; };
template<> struct PrimeGreateOrEqual<6971> {
 using type = size_t; constexpr static size_t const value = 6971; };
template<> struct PrimeGreateOrEqual<6977> {
 using type = size_t; constexpr static size_t const value = 6977; };
template<> struct PrimeGreateOrEqual<6983> {
 using type = size_t; constexpr static size_t const value = 6983; };
template<> struct PrimeGreateOrEqual<6991> {
 using type = size_t; constexpr static size_t const value = 6991; };
template<> struct PrimeGreateOrEqual<6997> {
 using type = size_t; constexpr static size_t const value = 6997; };
template<> struct PrimeGreateOrEqual<7001> {
 using type = size_t; constexpr static size_t const value = 7001; };
template<> struct PrimeGreateOrEqual<7013> {
 using type = size_t; constexpr static size_t const value = 7013; };
template<> struct PrimeGreateOrEqual<7019> {
 using type = size_t; constexpr static size_t const value = 7019; };
template<> struct PrimeGreateOrEqual<7027> {
 using type = size_t; constexpr static size_t const value = 7027; };
template<> struct PrimeGreateOrEqual<7039> {
 using type = size_t; constexpr static size_t const value = 7039; };
template<> struct PrimeGreateOrEqual<7043> {
 using type = size_t; constexpr static size_t const value = 7043; };
template<> struct PrimeGreateOrEqual<7057> {
 using type = size_t; constexpr static size_t const value = 7057; };
template<> struct PrimeGreateOrEqual<7069> {
 using type = size_t; constexpr static size_t const value = 7069; };
template<> struct PrimeGreateOrEqual<7079> {
 using type = size_t; constexpr static size_t const value = 7079; };
template<> struct PrimeGreateOrEqual<7103> {
 using type = size_t; constexpr static size_t const value = 7103; };
template<> struct PrimeGreateOrEqual<7109> {
 using type = size_t; constexpr static size_t const value = 7109; };
template<> struct PrimeGreateOrEqual<7121> {
 using type = size_t; constexpr static size_t const value = 7121; };
template<> struct PrimeGreateOrEqual<7127> {
 using type = size_t; constexpr static size_t const value = 7127; };
template<> struct PrimeGreateOrEqual<7129> {
 using type = size_t; constexpr static size_t const value = 7129; };
template<> struct PrimeGreateOrEqual<7151> {
 using type = size_t; constexpr static size_t const value = 7151; };
template<> struct PrimeGreateOrEqual<7159> {
 using type = size_t; constexpr static size_t const value = 7159; };
template<> struct PrimeGreateOrEqual<7177> {
 using type = size_t; constexpr static size_t const value = 7177; };
template<> struct PrimeGreateOrEqual<7187> {
 using type = size_t; constexpr static size_t const value = 7187; };
template<> struct PrimeGreateOrEqual<7193> {
 using type = size_t; constexpr static size_t const value = 7193; };
template<> struct PrimeGreateOrEqual<7207> {
 using type = size_t; constexpr static size_t const value = 7207; };
template<> struct PrimeGreateOrEqual<7211> {
 using type = size_t; constexpr static size_t const value = 7211; };
template<> struct PrimeGreateOrEqual<7213> {
 using type = size_t; constexpr static size_t const value = 7213; };
template<> struct PrimeGreateOrEqual<7219> {
 using type = size_t; constexpr static size_t const value = 7219; };
template<> struct PrimeGreateOrEqual<7229> {
 using type = size_t; constexpr static size_t const value = 7229; };
template<> struct PrimeGreateOrEqual<7237> {
 using type = size_t; constexpr static size_t const value = 7237; };
template<> struct PrimeGreateOrEqual<7243> {
 using type = size_t; constexpr static size_t const value = 7243; };
template<> struct PrimeGreateOrEqual<7247> {
 using type = size_t; constexpr static size_t const value = 7247; };
template<> struct PrimeGreateOrEqual<7253> {
 using type = size_t; constexpr static size_t const value = 7253; };
template<> struct PrimeGreateOrEqual<7283> {
 using type = size_t; constexpr static size_t const value = 7283; };
template<> struct PrimeGreateOrEqual<7297> {
 using type = size_t; constexpr static size_t const value = 7297; };
template<> struct PrimeGreateOrEqual<7307> {
 using type = size_t; constexpr static size_t const value = 7307; };
template<> struct PrimeGreateOrEqual<7309> {
 using type = size_t; constexpr static size_t const value = 7309; };
template<> struct PrimeGreateOrEqual<7321> {
 using type = size_t; constexpr static size_t const value = 7321; };
template<> struct PrimeGreateOrEqual<7331> {
 using type = size_t; constexpr static size_t const value = 7331; };
template<> struct PrimeGreateOrEqual<7333> {
 using type = size_t; constexpr static size_t const value = 7333; };
template<> struct PrimeGreateOrEqual<7349> {
 using type = size_t; constexpr static size_t const value = 7349; };
template<> struct PrimeGreateOrEqual<7351> {
 using type = size_t; constexpr static size_t const value = 7351; };
template<> struct PrimeGreateOrEqual<7369> {
 using type = size_t; constexpr static size_t const value = 7369; };
template<> struct PrimeGreateOrEqual<7393> {
 using type = size_t; constexpr static size_t const value = 7393; };
template<> struct PrimeGreateOrEqual<7411> {
 using type = size_t; constexpr static size_t const value = 7411; };
template<> struct PrimeGreateOrEqual<7417> {
 using type = size_t; constexpr static size_t const value = 7417; };
template<> struct PrimeGreateOrEqual<7433> {
 using type = size_t; constexpr static size_t const value = 7433; };
template<> struct PrimeGreateOrEqual<7451> {
 using type = size_t; constexpr static size_t const value = 7451; };
template<> struct PrimeGreateOrEqual<7457> {
 using type = size_t; constexpr static size_t const value = 7457; };
template<> struct PrimeGreateOrEqual<7459> {
 using type = size_t; constexpr static size_t const value = 7459; };
template<> struct PrimeGreateOrEqual<7477> {
 using type = size_t; constexpr static size_t const value = 7477; };
template<> struct PrimeGreateOrEqual<7481> {
 using type = size_t; constexpr static size_t const value = 7481; };
template<> struct PrimeGreateOrEqual<7487> {
 using type = size_t; constexpr static size_t const value = 7487; };
template<> struct PrimeGreateOrEqual<7489> {
 using type = size_t; constexpr static size_t const value = 7489; };
template<> struct PrimeGreateOrEqual<7499> {
 using type = size_t; constexpr static size_t const value = 7499; };
template<> struct PrimeGreateOrEqual<7507> {
 using type = size_t; constexpr static size_t const value = 7507; };
template<> struct PrimeGreateOrEqual<7517> {
 using type = size_t; constexpr static size_t const value = 7517; };
template<> struct PrimeGreateOrEqual<7523> {
 using type = size_t; constexpr static size_t const value = 7523; };
template<> struct PrimeGreateOrEqual<7529> {
 using type = size_t; constexpr static size_t const value = 7529; };
template<> struct PrimeGreateOrEqual<7537> {
 using type = size_t; constexpr static size_t const value = 7537; };
template<> struct PrimeGreateOrEqual<7541> {
 using type = size_t; constexpr static size_t const value = 7541; };
template<> struct PrimeGreateOrEqual<7547> {
 using type = size_t; constexpr static size_t const value = 7547; };
template<> struct PrimeGreateOrEqual<7549> {
 using type = size_t; constexpr static size_t const value = 7549; };
template<> struct PrimeGreateOrEqual<7559> {
 using type = size_t; constexpr static size_t const value = 7559; };
template<> struct PrimeGreateOrEqual<7561> {
 using type = size_t; constexpr static size_t const value = 7561; };
template<> struct PrimeGreateOrEqual<7573> {
 using type = size_t; constexpr static size_t const value = 7573; };
template<> struct PrimeGreateOrEqual<7577> {
 using type = size_t; constexpr static size_t const value = 7577; };
template<> struct PrimeGreateOrEqual<7583> {
 using type = size_t; constexpr static size_t const value = 7583; };
template<> struct PrimeGreateOrEqual<7589> {
 using type = size_t; constexpr static size_t const value = 7589; };
template<> struct PrimeGreateOrEqual<7591> {
 using type = size_t; constexpr static size_t const value = 7591; };
template<> struct PrimeGreateOrEqual<7603> {
 using type = size_t; constexpr static size_t const value = 7603; };
template<> struct PrimeGreateOrEqual<7607> {
 using type = size_t; constexpr static size_t const value = 7607; };
template<> struct PrimeGreateOrEqual<7621> {
 using type = size_t; constexpr static size_t const value = 7621; };
template<> struct PrimeGreateOrEqual<7639> {
 using type = size_t; constexpr static size_t const value = 7639; };
template<> struct PrimeGreateOrEqual<7643> {
 using type = size_t; constexpr static size_t const value = 7643; };
template<> struct PrimeGreateOrEqual<7649> {
 using type = size_t; constexpr static size_t const value = 7649; };
template<> struct PrimeGreateOrEqual<7669> {
 using type = size_t; constexpr static size_t const value = 7669; };
template<> struct PrimeGreateOrEqual<7673> {
 using type = size_t; constexpr static size_t const value = 7673; };
template<> struct PrimeGreateOrEqual<7681> {
 using type = size_t; constexpr static size_t const value = 7681; };
template<> struct PrimeGreateOrEqual<7687> {
 using type = size_t; constexpr static size_t const value = 7687; };
template<> struct PrimeGreateOrEqual<7691> {
 using type = size_t; constexpr static size_t const value = 7691; };
template<> struct PrimeGreateOrEqual<7699> {
 using type = size_t; constexpr static size_t const value = 7699; };
template<> struct PrimeGreateOrEqual<7703> {
 using type = size_t; constexpr static size_t const value = 7703; };
template<> struct PrimeGreateOrEqual<7717> {
 using type = size_t; constexpr static size_t const value = 7717; };
template<> struct PrimeGreateOrEqual<7723> {
 using type = size_t; constexpr static size_t const value = 7723; };
template<> struct PrimeGreateOrEqual<7727> {
 using type = size_t; constexpr static size_t const value = 7727; };
template<> struct PrimeGreateOrEqual<7741> {
 using type = size_t; constexpr static size_t const value = 7741; };
template<> struct PrimeGreateOrEqual<7753> {
 using type = size_t; constexpr static size_t const value = 7753; };
template<> struct PrimeGreateOrEqual<7757> {
 using type = size_t; constexpr static size_t const value = 7757; };
template<> struct PrimeGreateOrEqual<7759> {
 using type = size_t; constexpr static size_t const value = 7759; };
template<> struct PrimeGreateOrEqual<7789> {
 using type = size_t; constexpr static size_t const value = 7789; };
template<> struct PrimeGreateOrEqual<7793> {
 using type = size_t; constexpr static size_t const value = 7793; };
template<> struct PrimeGreateOrEqual<7817> {
 using type = size_t; constexpr static size_t const value = 7817; };
template<> struct PrimeGreateOrEqual<7823> {
 using type = size_t; constexpr static size_t const value = 7823; };
template<> struct PrimeGreateOrEqual<7829> {
 using type = size_t; constexpr static size_t const value = 7829; };
template<> struct PrimeGreateOrEqual<7841> {
 using type = size_t; constexpr static size_t const value = 7841; };
template<> struct PrimeGreateOrEqual<7853> {
 using type = size_t; constexpr static size_t const value = 7853; };
template<> struct PrimeGreateOrEqual<7867> {
 using type = size_t; constexpr static size_t const value = 7867; };
template<> struct PrimeGreateOrEqual<7873> {
 using type = size_t; constexpr static size_t const value = 7873; };
template<> struct PrimeGreateOrEqual<7877> {
 using type = size_t; constexpr static size_t const value = 7877; };
template<> struct PrimeGreateOrEqual<7879> {
 using type = size_t; constexpr static size_t const value = 7879; };
template<> struct PrimeGreateOrEqual<7883> {
 using type = size_t; constexpr static size_t const value = 7883; };
template<> struct PrimeGreateOrEqual<7901> {
 using type = size_t; constexpr static size_t const value = 7901; };
template<> struct PrimeGreateOrEqual<7907> {
 using type = size_t; constexpr static size_t const value = 7907; };
template<> struct PrimeGreateOrEqual<7919> {
 using type = size_t; constexpr static size_t const value = 7919; };
