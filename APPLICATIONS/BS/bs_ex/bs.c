/*##################################################
****************************************
Application: Binary Search
****************************************
Technique: BL - baseline
*****************************************
Date: 06/26/2023
Author: Daniela L. Catelan
UFMS - PhD in Computer Science
####################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct DATA {
  int  key;
  int  value;
}  ;


int binary_search(struct DATA *data, int x)//HOT
{
  int fvalue, mid, up, low ;

  low = 0;
  up = 500;
  fvalue = -1 /* all data are positive */ ;
  while (low <= up) {
    mid = (low + up) >> 1;
    if ( data[mid].key == x ) {  /*  found  */
      up = low - 1;
      fvalue = data[mid].value;
    }
    else  /* not found */
      if ( data[mid].key > x ) 	{
	up = mid - 1;
      }
      else   {
          low = mid + 1;
      }

  }
  
  return fvalue;
}

void run_in_itim(struct DATA *data, int *keys) {

    int res;
    for (int i = 0; i < 500; i++)//LP
    {
        res = binary_search(data, keys[i]);
        printf(" %d ",res);
        
     }

}


int main()
{
    struct DATA data[500] = {
        {1, -875751},{2, -976069},{3, -33389},{4, 728892},{5, -13597},{6, -655283},{7, 208387},{8, 247263},{9, 552173},{10, -396626},{11, -365866},{12, 22679},{13, 599562},{14, 258658},{15, 331702},{16, 646517},{17, 270585},{18, -97973},{19, -160599},{20, -531771},{21, 370030},{22, 320322},{23, -19909},{24, -380442},{25, -538439},{26, 552231},{27, -272624},{28, -205551},{29, 822320},{30, -674935},{31, -325728},{32, -230939},{33, 366147},{34, -598818},{35, 85041},{36, -215717},{37, 782491},{38, -126120},{39, 112679},{40, 361825},{41, 117684},{42, -545846},{43, -850000},{44, -116243},{45, 500357},{46, 793015},{47, -697456},{48, 143280},{49, -467740},{50, 113886},{51, 782025},{52, 307844},{53, 112214},{54, -790276},{55, 164914},{56, 421452},{57, -322233},{58, -423953},{59, 301485},{60, -253803},
        {61, 80815},{62, -459357},{63, -720219},{64, 86480},{65, 615417},{66, -597489},{67, -296547},{68, 375855},{69, -246879},{70, -362970},{71, -760040},{72, 390792},{73, -582061},{74, -311034},{75, 1017471},{76, -36968},{77, 85635},{78, 261005},{79, -436553},{80, 690672},{81, 608346},{82, 260453},{83, -218431},{84, -605459},{85, 686553},{86, -167992},{87, -798884},{88, 514964},{89, 119504},{90, -144574},{91, -733561},{92, -655463},{93, 738753},{94, -329066},{95, 458199},{96, 864745},{97, 118910},{98, 441277},{99, -729449},{100, 40402},{101, -875752}, {102, -976069},{103, -33389},{104, 728892},{105, -13597},{106, -655283},{107, 208387},{108, 247263},{109, 552173},{110, -396626},{111, -365866},{112, 22679}, {113, 599562},{114, 258658},{115, 331702},{116, 646517},{117, 270585},{118, -97973},{119, -160599},{120, -531771},{121, 370030}, {122, 320322},{123, -19909},{124, -380442},{125, -538439},{126, 552231},{127, -272624},{128, -205551},{129, 822320},{130, -674935},{131, -325728},{132, -230939}, {133, 366147},{134, -598818},{135, 85041},{136, -215717},{137, 782491},{138, -126120},{139, 112679},{140, 361825},
        {141, 117684},{142, -545846},{143, -850000},{144, -116243},{145, 500357},{146, 793015},{147, -697456},{148, 143280},{149, -467740},{150, 113886},{151, 782025},{152, 307844},{153, 112214},{154, -790276},{155, 164914},{156, 421452},{157, -322233},{158, -423953},{159, 301485},{160, -253803},{161, 80815},{162, -459357},{163, -720219},{164, 86480},{165, 615417},{166, -597489},{167, -296547},{168, 375855},{169, -246879},{170, -362970},{171, -760040},{72, 390792},{173, -582061},{174, -311034},{175, 1017471},{176, -36968},{177, 85635},{178, 261005},{179, -436553},{180, 690672},{181, 608346},{182, 260453},{183, -218431},{184, -605459},{185, 686553},{186, -167992},{187, -798884},{188, 514964},{189, 119504},{190, -144574},{191, -733561},{92, -655463},{193, 738753},{194, -329066},{195, 458199},{196, 864745},{197, 118910},{198, 441277},{199, -729449},{200, 40402},{201, -875751},{202, -976069},{203, -33389},{204, 728892},{205, -13597},{206, -655283},{207, 208387},{208, 247263},{209, 552173},{210, -396626},{211, -365866},{212, 22679},{213, 599562},{214, 258658},{215, 331702},{216, 646517},{217, 270585},{218, -97973},{219, -160599},{220, -531771},{221, 370030},{222, 320322},{223, -19909},{224, -380442},{225, -538439},{226, 552231},{227, -272624},{228, -205551},{229, 822320},{230, -674935},{31, -325728},{232, -230939},{233, 366147},{234, -598818},{235, 85041},{236, -215717},{237, 782491},{238, -126120},{239, 112679},{240, 361825},{241, 117684},{242, -545846},{243, -850000},{244, -116243},{245, 500357},{246, 793015},{247, -697456},{248, 143280},{249, -467740},{250, 113886},{251, 782025},{252, 307844},{253, 112214},{254, -790276},{255, 164914},{256, 421452},{257, -322233},{258, -423953},{259, 301485},{260, -253803},{261, 80815},{262, -459357},{263, -720219},{264, 86480},{265, 615417},{266, -597489},{267, -296547},{268, 375855},{269, -246879},{270, -362970},{271, -760040},{272, 390792},{273, -582061},{274, -311034},{275, 1017471},{276, -36968},{277, 85635},{278, 261005},{279, -436553},{280, 690672},{281, 608346},{282, 260453},{283, -218431},{284, -605459},{285, 686553},{286, -167992},{287, -798884},{288, 514964},{289, 119504},{290, -144574},{291, -733561},{292, -655463},{293, 738753},{294, -329066},{295, 458199},{296, 864745},{297, 118910},{298, 441277},{299, -729449},{300, 40402},{301, -875751},{302, -976069},{303, -33389},{304, 728892},{305, -13597},{306, -655283},{307, 208387},{308, 247263},{309, 552173},{310, -396626},{311, -365866},{312, 22679},{313, 599562},{314, 258658},{315, 331702},{316, 646517},{317, 270585},{318, -97973},{319, -160599},{320, -531771},{321, 370030},{322, 320322},{323, -19909},{324, -380442},{325, -538439},{326, 552231},{327, -272624},{328, -205551},{329, 822320},{330, -674935},{331, -325728},{332, -230939},{333, 366147},{334, -598818},{335, 85041},{336, -215717},{337, 782491},{338, -126120},{339, 112679},{340, 361825},{341, 117684},{342, -545846},{343, -850000},{344, -116243},{345, 500357},{346, 793015},{347, -697456},{348, 143280},{349, -467740},{350, 113886},{351, 782025},{352, 307844},{353, 112214},{354, -790276},{355, 164914},{356, 421452},{357, -322233},{358, -423953},{359, 301485},{360, -253803},{361, 80815},{362, -459357},{363, -720219},{364, 86480},{365, 615417},{366, -597489},{367, -296547},{368, 375855},{369, -246879},{370, -362970},{371, -760040},{372, 390792},{373, -582061},{374, -311034},{375, 1017471},{376, -36968},{377, 85635},{378, 261005},{379, -436553},{380, 690672},{381, 608346},{382, 260453},{383, -218431},{384, -605459},{385, 686553},{386, -167992},{387, -798884},{388, 514964},{389, 119504},{390, -144574},{391, -733561},{392, -655463},{393, 738753},{394, -329066},{395, 458199},{396, 864745},{397, 118910},{398, 441277},{399, -729449},{400, 40402},{401, -875751},{402, -976069},{403, -33389},{404, 728892},{405, -13597},{406, -655283},{407, 208387},{408, 247263},{409, 552173},{410, -396626},{411, -365866},{412, 22679},{413, 599562},{414, 258658},{415, 331702},{416, 646517},{417, 270585},{418, -97973},{419, -160599},{420, -531771},{421, 370030},{422, 320322},{423, -19909},{424, -380442},{425, -538439},{426, 552231},{427, -272624},{428, -205551},{429, 822320},{430, -674935},{431, -325728},{432, -230939},{433, 366147},{434, -598818},{435, 85041},{436, -215717},{437, 782491},{438, -126120},{439, 112679},{440, 361825},{441, 117684},{442, -545846},{443, -850000},{444, -116243},{445, 500357},{446, 793015},{447, -697456},{448, 143280},{449, -467740},{540, 113886},{451, 782025},{452, 307844},{453, 112214},{454, -790276},{455, 164914},{456, 421452},{457, -322233},{458, -423953},{459, 301485},{460, -253803},{461, 80815},{462, -459357},{463, -720219},{464, 86480},{465, 615417},{466, -597489},{467, -296547},{468, 375855},{469, -246879},{470, -362970},{471, -760040},{472, 390792},{473, -582061},{474, -311034},{475, 1017471},{476, -36968},{477, 85635},{478, 261005},{479, -436553},{480, 690672},{481, 608346},{482, 260453},{483, -218431},{484, -605459},{485, 686553},{486, -167992},{487, -798884},{488, 514964},{489, 119504},{490, -144574},{491, -733561},{492, -655463},{493, 738753},{494, -329066},{495, 458199},{496, 864745},{497, 118910},{498, 441277},{499, -729449},{500, 40402} };

    int keys[500] = { 319,	500,	 37,	475,	431,	495,	208,	408,	414,	100, 143,	253,	221,	 26,	350,	320,	 57,	122,	317,	483,  14,	 63,	199,	232,	150,	482,	 50,	 46,	248,	368, 477,	403,	101,	 32,	485,	 95,	396,	298,	235,	144, 272,	231,	240,	412,	 66,	126,	429,	323,	471,	 38,  74,	 40,	187,	102,	171,	188,	259,	181,	313,	246, 490,	277,	178,	250,	434,	382,	 43,	352,	398,	182,  77,	410,	141,	459,	121,	428,	207,	284,	 11,	452,  33,	464,	371,	389,	358,	190,	149,	295,	  2,	213,  51,	266,	418,	214,	131,	234,	328,	 71,	117,	 21, 176,	 18,	329,	159,	297,	 97,	200,	383,	 84,	438, 351,	466,	487,	 42,	 91,	430,	241,	388,	180,	244, 105,	120,	 56,	183,	177,	375,	264,	 83,	302,	155, 432,	 99,	488,	304,	194,	115,	334,	 85,	 62,	392,  52,	421,	367,	308,	 78,	271,	385,	273,	489,	325, 472,	158,	444,	 48,	 61,	133,	473,	252,	404,	256, 294,	230,	285,	175,	 67,	139,	423,	154,	 92,	 65, 493,	481,	247,	 53,	 20,	457,	209,	293,	411,	218, 311,	465,	274,	276,	455,	189,	204,	395,	 72,	 10, 419,	 24,	161,	289,	 87,	  7,	331,	 94,	442,	163,   5,	318,	 34,	123,	164,	173,	142,	433,	 88,	127, 215,	 90,	174,	165,	 17,	192,	405,	 96,	359,	390, 118,	  6,	399,	315,	353,	251,	347,	310,	322,	 23, 124,	153,	394,	287,	168,	167,	 81,	494,	462,	326, 195,	343,	265,	223,	186,	446,	309,	427,	496,	198, 440,	372,	299,	 13,	461,	129,	219,	362,	  4,	470, 211,	292,	112,	417,	420,	443,	409,	340,	379,	 12, 400,	 29,	332,	365,	498,	374,	184,	416,	338,	454, 138,	333,	137,	354,	290,	134,	 89,	422,	 98,	220, 225,	270,	499,	342,	 39,	135,	 31,	492,	243,	447, 157,	478,	283,	497,	476,	 70,	170,	152,	202,	449, 479,	348,	  3,	291,	300,	437,	436,	282,	376,	469, 279,	467,	255,	458,	110,	402,	217,	401,	286,	108, 236,	 86,	363,	222,	366,	324,	337,	450,	226,	 35, 448,	147,	254,	257,	132,	463,	196,	381,	130,	425, 193,	 16,	407,	269,	179,	233,	 59,	191,	185,	260, 441,	239,	356,	491,	 68,	453,	280,	113,	160,	364, 321,	229,	 15,	145,	306,	263,	357,	413,	484,	268, 119,	369,	140,	378,	327,	242,	109,	114,	 73,	227, 439,	237,	 47,	  1,	262,	336,	 82,	344,	460,	474, 125,	103,	169,	377,	349,	 93,	393,	  8,	212,	312, 201,	314,	486,	281,	228,	339,	  9,	116,	278,	 45, 445,	104,	301,	 44,	275,	341,	 79,	296,	 60,	303, 267,	205,	373,	238,	346,	197,	203,	424,	249,	345,  58,	210,	107,	435,	166,	415,	148,	111,	360,	391,  41,	 27,	 55,	386,	 28,	 54,	355,	206,	456,	335,  19,	136,	370,	384,	 69,	305,	330,	288,	106,	316}; 
    
        run_in_itim(data, keys);
    return 0;
}



