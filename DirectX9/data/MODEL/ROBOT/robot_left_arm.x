xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 173;
 -6.33393;-15.73635;-5.24884;,
 -5.89383;-16.20012;-4.64075;,
 -5.77098;-16.97678;-4.97820;,
 -7.20345;-17.03073;-6.32410;,
 -6.24116;-17.67680;-6.32410;,
 -8.30297;-14.58210;-4.64075;,
 -7.70735;-14.81396;-5.24884;,
 -8.57662;-16.10817;-6.32410;,
 -9.06849;-14.76186;-4.97820;,
 -9.53869;-15.46186;-6.32410;,
 -6.15375;-17.54660;-1.98740;,
 -6.22678;-16.69582;-2.03981;,
 -6.82261;-16.46367;-1.43172;,
 -7.86631;-18.01767;-1.14390;,
 -6.90424;-18.66398;-1.14390;,
 -8.63592;-15.07758;-2.03981;,
 -9.45129;-15.33171;-1.98740;,
 -9.23968;-17.09514;-1.14390;,
 -8.19578;-15.54133;-1.43172;,
 -10.20174;-16.44904;-1.14391;,
 -11.08694;-17.76660;-1.08634;,
 -7.78939;-19.98154;-1.08634;,
 -9.45129;-15.33171;-1.98740;,
 -10.70417;-17.19675;-4.07735;,
 -10.20174;-16.44904;-1.14391;,
 -11.08694;-17.76660;-1.08634;,
 -11.86939;-18.93163;-1.83038;,
 -7.78939;-19.98154;-1.08634;,
 -7.40664;-19.41166;-4.07735;,
 -6.90424;-18.66398;-1.14390;,
 -8.57190;-21.14659;-1.83038;,
 -11.86939;-18.93163;-1.83038;,
 -8.57190;-21.14659;-1.83038;,
 -9.06849;-14.76186;-4.97820;,
 -9.03630;-14.71418;-3.39087;,
 -11.20637;-17.94465;-7.01058;,
 -10.32120;-16.62692;-7.06815;,
 -9.53869;-15.46186;-6.32410;,
 -12.33964;-19.63183;-3.17629;,
 -12.37184;-19.67954;-4.76383;,
 -11.95683;-19.06203;-6.16730;,
 -5.73898;-16.92914;-3.39087;,
 -5.77098;-16.97678;-4.97820;,
 -6.24116;-17.67680;-6.32410;,
 -7.02387;-18.84186;-7.06815;,
 -6.15375;-17.54660;-1.98740;,
 -9.04231;-21.84684;-3.17629;,
 -9.07431;-21.89454;-4.76383;,
 -8.65953;-21.27696;-6.16730;,
 -7.90884;-20.15961;-7.01058;,
 -9.04231;-21.84684;-3.17629;,
 -12.33964;-19.63183;-3.17629;,
 -10.32120;-16.62692;-7.06815;,
 -7.02387;-18.84186;-7.06815;,
 -7.90884;-20.15961;-7.01058;,
 -11.20637;-17.94465;-7.01058;,
 -8.65953;-21.27696;-6.16730;,
 -11.95683;-19.06203;-6.16730;,
 -12.37184;-19.67954;-4.76383;,
 -9.07431;-21.89454;-4.76383;,
 -9.04231;-21.84684;-3.17629;,
 -12.33964;-19.63183;-3.17629;,
 -5.73898;-16.92914;-3.39087;,
 -6.22678;-16.69582;-2.03981;,
 -5.89383;-16.20012;-4.64075;,
 1.41433;-5.31987;-1.63235;,
 1.08161;-5.81562;0.96860;,
 0.48577;-5.58347;1.57668;,
 -6.82261;-16.46367;-1.43172;,
 1.41433;-5.31987;-1.63235;,
 -5.89383;-16.20012;-4.64075;,
 -6.33393;-15.73635;-5.24884;,
 0.97443;-4.85620;-2.24043;,
 -0.88742;-4.66113;1.57668;,
 -8.19578;-15.54133;-1.43172;,
 -9.03630;-14.71418;-3.39087;,
 -1.32753;-4.19741;0.96860;,
 -8.63592;-15.07758;-2.03981;,
 -0.39897;-3.93386;-2.24043;,
 -7.70735;-14.81396;-5.24884;,
 -0.99460;-3.70170;-1.63235;,
 -8.30297;-14.58210;-4.64075;,
 1.49229;-5.20417;-2.24043;,
 1.41433;-5.31987;-1.63235;,
 0.97443;-4.85620;-2.24043;,
 -1.00168;-3.71215;2.69340;,
 -0.88742;-4.66113;1.57668;,
 0.48577;-5.58347;1.57668;,
 1.40745;-5.33044;2.69340;,
 1.46780;-0.03578;3.71002;,
 3.87693;-1.65405;3.71002;,
 -1.28113;-3.26091;2.22987;,
 -1.53178;-3.63395;1.53652;,
 -1.40550;-4.31320;1.57668;,
 -1.32753;-4.19741;0.96860;,
 1.07022;0.23968;3.19774;,
 -1.28113;-3.26091;2.22987;,
 -2.15426;-4.56083;-3.70146;,
 -1.08052;-2.96237;-1.98912;,
 -1.53178;-3.63395;1.53652;,
 -2.85514;-5.60427;1.77473;,
 -1.28113;-3.26091;2.22987;,
 -2.19444;-4.62055;3.66599;,
 -1.09986;-2.99086;-4.88648;,
 -0.68637;-2.37546;-2.41699;,
 1.66478;1.12498;-1.44912;,
 1.95367;1.55501;-3.62950;,
 2.61437;2.53875;-1.73845;,
 1.91544;1.49783;-0.76221;,
 1.91350;1.49529;3.73773;,
 1.46264;0.82386;2.77545;,
 0.85908;-0.07463;4.92297;,
 1.07022;0.23968;3.19774;,
 -3.30814;-1.50778;-4.88648;,
 -1.09986;-2.99086;-4.88648;,
 -2.15426;-4.56083;-3.70146;,
 -4.36256;-3.07746;-3.70146;,
 0.40630;4.02191;-1.73845;,
 2.61437;2.53875;-1.73845;,
 1.95367;1.55501;-3.62950;,
 -0.25464;3.03819;-3.62950;,
 -1.34923;1.40875;4.92297;,
 0.85908;-0.07463;4.92297;,
 1.91350;1.49529;3.73773;,
 -0.29457;2.97850;3.73773;,
 -5.06345;-4.12094;1.77472;,
 -2.85514;-5.60427;1.77473;,
 -2.19444;-4.62055;3.66599;,
 -4.40275;-3.13723;3.66599;,
 -4.36256;-3.07746;-3.70146;,
 -2.15426;-4.56083;-3.70146;,
 -2.65991;1.24456;-1.72019;,
 -3.17948;0.47093;-1.93413;,
 -4.12524;-0.93683;-0.87133;,
 -2.06728;2.12676;-0.02418;,
 -4.24442;-1.11445;0.06045;,
 -2.18650;1.94935;0.90760;,
 -3.30814;-1.50778;-4.88648;,
 -4.36256;-3.07746;-3.70146;,
 0.40630;4.02191;-1.73845;,
 -0.25464;3.03819;-3.62950;,
 -3.13224;0.54141;1.97040;,
 -1.34923;1.40875;4.92297;,
 -0.29457;2.97850;3.73773;,
 -5.06345;-4.12094;1.77472;,
 -4.40275;-3.13723;3.66599;,
 -3.65181;-0.23232;1.75668;,
 5.00117;0.01990;-0.80367;,
 4.59650;-0.58261;-1.91330;,
 2.18759;1.03568;-1.91330;,
 2.59203;1.63817;-0.80367;,
 2.10166;0.90799;3.02805;,
 4.51080;-0.71017;3.02805;,
 2.12702;-4.25905;-2.92970;,
 1.49229;-5.20417;-2.24043;,
 0.97443;-4.85620;-2.24043;,
 -0.39897;-3.93386;-2.24043;,
 -0.28213;-2.64077;-2.92970;,
 -1.08052;-2.96237;-1.98912;,
 -0.91684;-3.58586;-2.24043;,
 -0.99460;-3.70170;-1.63235;,
 -0.91684;-3.58586;-2.24043;,
 -1.08052;-2.96237;-1.98912;,
 -0.68637;-2.37546;-2.41699;,
 -0.39897;-3.93386;-2.24043;,
 1.46264;0.82386;2.77545;,
 1.07022;0.23968;3.19774;,
 1.91544;1.49783;-0.76221;,
 1.46264;0.82386;2.77545;,
 1.66478;1.12498;-1.44912;,
 1.91544;1.49783;-0.76221;,
 -0.68637;-2.37546;-2.41699;,
 1.66478;1.12498;-1.44912;;
 
 110;
 4;0,1,2,3;,
 3;3,2,4;,
 4;5,6,7,8;,
 3;9,8,7;,
 4;0,3,7,6;,
 4;10,11,12,13;,
 3;14,10,13;,
 4;15,16,17,18;,
 3;17,16,19;,
 4;18,17,13,12;,
 3;17,19,20;,
 3;21,14,13;,
 3;22,23,24;,
 3;24,23,25;,
 3;25,23,26;,
 3;27,28,29;,
 3;30,28,27;,
 4;13,17,20,21;,
 4;21,20,31,32;,
 3;33,23,34;,
 3;35,23,36;,
 3;36,23,37;,
 3;37,23,33;,
 3;34,23,22;,
 3;26,23,38;,
 3;38,23,39;,
 3;39,23,40;,
 3;40,23,35;,
 3;41,28,42;,
 3;43,28,44;,
 3;42,28,43;,
 3;45,28,41;,
 3;29,28,45;,
 3;46,28,30;,
 3;47,28,46;,
 3;48,28,47;,
 3;49,28,48;,
 3;44,28,49;,
 4;50,32,31,51;,
 3;52,9,7;,
 3;3,4,53;,
 4;54,55,52,53;,
 4;52,7,3,53;,
 4;54,56,57,55;,
 4;58,59,60,61;,
 4;57,56,59,58;,
 3;11,10,62;,
 3;62,2,1;,
 3;62,1,11;,
 4;63,64,65,66;,
 4;66,67,68,63;,
 4;69,70,71,72;,
 4;67,73,74,68;,
 3;5,8,75;,
 3;75,16,15;,
 3;75,15,5;,
 4;74,73,76,77;,
 4;78,72,71,79;,
 4;76,80,81,77;,
 4;81,80,78,79;,
 3;82,83,84;,
 4;85,86,87,88;,
 4;89,85,88,90;,
 4;91,92,93,85;,
 3;93,94,86;,
 4;95,96,85,89;,
 3;85,93,86;,
 4;97,98,99,100;,
 4;101,102,100,99;,
 4;98,97,103,104;,
 4;105,104,103,106;,
 4;105,106,107,108;,
 4;108,107,109,110;,
 4;111,102,101,112;,
 4;110,109,111,112;,
 4;113,114,115,116;,
 4;117,118,119,120;,
 4;121,122,123,124;,
 4;125,126,127,128;,
 4;129,130,126,125;,
 4;119,114,113,120;,
 4;123,118,117,124;,
 4;121,128,127,122;,
 4;131,132,133,134;,
 4;134,133,135,136;,
 4;132,137,138,133;,
 4;134,139,140,131;,
 4;141,142,143,136;,
 4;135,144,145,146;,
 4;136,135,146,141;,
 4;143,139,134,136;,
 4;140,137,132,131;,
 4;133,138,144,135;,
 4;141,146,145,142;,
 4;147,148,149,150;,
 4;151,89,90,152;,
 4;147,150,151,152;,
 3;153,154,155;,
 4;156,157,153,155;,
 4;153,157,149,148;,
 3;158,159,160;,
 4;158,160,94,92;,
 3;94,93,92;,
 4;161,162,163,157;,
 3;164,160,159;,
 3;156,161,157;,
 4;151,165,166,89;,
 4;150,167,168,151;,
 4;149,169,170,150;,
 4;157,171,172,149;;
 
 MeshMaterialList {
  1;
  110;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Robot_Color.tga";
   }
  }
 }
 MeshNormals {
  121;
  0.520802;0.171483;-0.836276;,
  0.966830;0.025326;-0.254160;,
  0.818433;0.402085;-0.410481;,
  0.439452;0.457604;-0.772969;,
  0.379655;0.565475;-0.732188;,
  -0.342042;0.904667;-0.254136;,
  -0.038197;0.547021;-0.836247;,
  0.257421;0.579921;-0.772933;,
  0.062797;0.909743;-0.410395;,
  0.379819;0.565382;-0.732175;,
  0.674542;0.187847;0.713938;,
  0.873750;-0.113162;0.473028;,
  0.293276;-0.167145;0.941303;,
  0.216676;0.125861;0.968096;,
  0.163741;0.243735;0.955920;,
  -0.435125;0.766104;0.473024;,
  -0.081173;0.695504;0.713923;,
  0.034573;0.248196;0.968093;,
  -0.265654;0.208315;0.941293;,
  0.163709;0.243769;0.955917;,
  -0.075883;-0.112969;0.990697;,
  -0.075881;-0.112970;0.990697;,
  -0.830109;0.557601;-0.000010;,
  -0.830148;0.557543;-0.000012;,
  0.830109;-0.557601;0.000001;,
  0.830126;-0.557576;-0.000016;,
  -0.441057;0.890315;0.113169;,
  -0.830128;0.557573;-0.000041;,
  -0.830111;0.557598;-0.000060;,
  -0.830139;0.557557;0.000036;,
  -0.830118;0.557588;-0.000020;,
  -0.830130;0.557570;-0.000074;,
  0.990979;-0.071789;0.113166;,
  0.830120;-0.557585;0.000011;,
  0.830122;-0.557582;-0.000004;,
  0.830129;-0.557571;0.000002;,
  0.830108;-0.557604;0.000028;,
  0.830124;-0.557578;0.000053;,
  0.814665;-0.444084;-0.372974;,
  0.719169;-0.586214;0.373026;,
  -0.035846;-0.537278;0.842643;,
  0.063353;-0.267022;-0.961606;,
  -0.494527;-0.374938;0.784133;,
  -0.986338;0.126400;0.105643;,
  -0.271191;-0.042309;-0.961595;,
  -0.935809;0.201590;-0.289177;,
  -0.451985;-0.672650;-0.585876;,
  -0.319711;-0.475967;0.819293;,
  0.087363;0.130067;0.987649;,
  -0.607396;-0.332864;0.721298;,
  -0.248510;0.346160;0.904664;,
  -0.824611;0.066486;0.561779;,
  -0.983026;-0.181164;0.028959;,
  -0.831800;-0.530678;0.162759;,
  -0.533081;0.499972;0.682534;,
  0.830125;-0.557577;-0.000024;,
  0.830118;-0.557587;-0.000012;,
  0.830119;-0.557586;-0.000015;,
  0.830130;-0.557570;-0.000039;,
  0.830093;-0.557625;-0.000032;,
  0.830132;-0.557567;-0.000005;,
  0.830170;-0.557511;0.000052;,
  0.830127;-0.557574;0.000037;,
  -0.092728;-0.138050;-0.986075;,
  -0.454351;-0.676423;-0.579670;,
  0.549817;0.818561;-0.166312;,
  0.323196;0.481194;-0.814860;,
  0.092748;0.138074;0.986070;,
  0.454369;0.676434;0.579643;,
  -0.549834;-0.818558;0.166271;,
  -0.323231;-0.481209;0.814837;,
  -0.752039;0.636011;-0.172993;,
  -0.825060;0.527296;-0.203066;,
  -0.892663;0.443304;-0.081452;,
  -0.735405;0.677422;-0.016729;,
  -0.905238;0.424575;0.016762;,
  -0.747979;0.658703;0.081474;,
  -0.800172;0.564347;0.203067;,
  -0.873199;0.455623;0.173005;,
  -0.161420;-0.240276;-0.957189;,
  0.318799;0.474577;-0.820454;,
  0.548912;0.817170;-0.175866;,
  0.451183;0.671705;0.587576;,
  -0.036906;0.661316;-0.749199;,
  0.176118;0.970513;-0.164583;,
  0.085682;0.835806;0.542298;,
  -0.397788;-0.020646;-0.917245;,
  -0.741837;-0.396563;-0.540755;,
  -0.830088;0.557633;-0.000001;,
  -0.830087;0.557633;0.000041;,
  -0.830103;0.557610;0.000005;,
  0.830104;-0.557609;-0.000014;,
  0.830095;-0.557622;-0.000039;,
  -0.379765;-0.565361;0.732220;,
  -0.830085;0.557637;0.000034;,
  -0.830108;0.557603;-0.000042;,
  0.830097;-0.557620;0.000017;,
  0.830087;-0.557634;0.000013;,
  0.830106;-0.557606;-0.000030;,
  -0.533030;-0.793512;0.293630;,
  0.172627;0.256963;-0.950879;,
  0.172583;0.256979;-0.950882;,
  -0.163695;-0.243695;-0.955938;,
  -0.408265;-0.607785;-0.681114;,
  -0.543477;-0.809066;-0.223706;,
  -0.543606;-0.809002;-0.223624;,
  -0.543376;-0.809121;-0.223754;,
  -0.809331;0.503606;-0.302266;,
  -0.934402;0.317403;-0.161703;,
  -0.622248;0.782115;-0.033231;,
  -0.700642;0.665427;-0.257503;,
  -0.772278;0.558785;0.302235;,
  -0.647193;0.744985;0.161677;,
  -0.959351;0.280255;0.033226;,
  -0.880981;0.396953;0.257489;,
  -0.936996;-0.112664;-0.330673;,
  -0.665527;0.303515;-0.681874;,
  -0.543626;-0.808986;-0.223633;,
  -0.278395;0.865713;0.415977;,
  -0.208783;0.969470;-0.128599;,
  -0.373828;0.737267;-0.562752;;
  110;
  4;0,1,2,3;,
  3;3,2,4;,
  4;5,6,7,8;,
  3;9,8,7;,
  4;0,3,7,6;,
  4;10,11,12,13;,
  3;14,10,13;,
  4;15,16,17,18;,
  3;17,16,19;,
  4;18,17,13,12;,
  3;17,19,20;,
  3;21,14,13;,
  3;88,22,89;,
  3;89,22,90;,
  3;90,22,23;,
  3;91,24,92;,
  3;25,24,91;,
  4;13,17,20,21;,
  4;21,20,93,93;,
  3;94,22,26;,
  3;27,22,28;,
  3;28,22,95;,
  3;95,22,94;,
  3;26,22,88;,
  3;23,22,29;,
  3;29,22,30;,
  3;30,22,31;,
  3;31,22,27;,
  3;32,24,96;,
  3;97,24,33;,
  3;96,24,97;,
  3;98,24,32;,
  3;92,24,98;,
  3;34,24,25;,
  3;35,24,34;,
  3;36,24,35;,
  3;37,24,36;,
  3;33,24,37;,
  4;99,93,93,99;,
  3;100,9,7;,
  3;3,4,101;,
  4;102,102,100,101;,
  4;100,7,3,101;,
  4;102,103,103,102;,
  4;104,104,99,99;,
  4;103,103,104,104;,
  3;11,10,32;,
  3;32,2,1;,
  3;32,1,11;,
  4;11,1,38,39;,
  4;39,40,12,11;,
  4;38,1,0,41;,
  4;40,42,18,12;,
  3;5,8,26;,
  3;26,16,15;,
  3;26,15,5;,
  4;18,42,43,15;,
  4;44,41,0,6;,
  4;43,45,5,15;,
  4;5,45,44,6;,
  3;46,105,105;,
  4;49,42,40,47;,
  4;50,49,47,48;,
  4;51,52,53,49;,
  3;53,106,106;,
  4;54,51,49,50;,
  3;49,53,42;,
  4;55,55,56,56;,
  4;57,57,56,56;,
  4;55,55,58,58;,
  4;59,58,58,59;,
  4;59,59,60,60;,
  4;60,60,61,61;,
  4;62,57,57,62;,
  4;61,61,62,62;,
  4;63,63,64,64;,
  4;65,65,66,66;,
  4;67,67,68,68;,
  4;69,69,70,70;,
  4;64,64,69,69;,
  4;66,63,63,66;,
  4;68,65,65,68;,
  4;67,70,70,67;,
  4;71,72,73,74;,
  4;74,73,75,76;,
  4;72,107,108,73;,
  4;74,109,110,71;,
  4;77,111,112,76;,
  4;75,113,114,78;,
  4;76,75,78,77;,
  4;112,109,74,76;,
  4;110,107,72,71;,
  4;73,108,113,75;,
  4;77,78,114,111;,
  4;81,80,83,84;,
  4;85,50,48,82;,
  4;81,84,85,82;,
  3;79,46,41;,
  4;44,86,79,41;,
  4;79,86,83,80;,
  3;115,87,45;,
  4;115,45,43,52;,
  3;43,53,52;,
  4;87,115,116,86;,
  3;117,117,87;,
  3;44,87,86;,
  4;85,118,54,50;,
  4;84,119,118,85;,
  4;83,120,119,84;,
  4;86,116,120,83;;
 }
 MeshTextureCoords {
  173;
  0.604000;0.968700;,
  0.599700;0.962600;,
  0.604200;0.956700;,
  0.617500;0.967000;,
  0.618400;0.956700;,
  0.599700;0.986100;,
  0.604000;0.980100;,
  0.617500;0.981700;,
  0.604200;0.992000;,
  0.618400;0.992000;,
  0.575900;0.956700;,
  0.581000;0.962600;,
  0.577300;0.968700;,
  0.563300;0.967000;,
  0.561800;0.956700;,
  0.581000;0.986100;,
  0.575900;0.992000;,
  0.563300;0.981700;,
  0.577300;0.980100;,
  0.561800;0.992000;,
  0.547700;0.992000;,
  0.547700;0.956700;,
  0.425800;0.941000;,
  0.418700;0.967200;,
  0.411700;0.941000;,
  0.399600;0.948000;,
  0.392500;0.960200;,
  0.461900;0.948000;,
  0.481100;0.967200;,
  0.454900;0.960200;,
  0.474100;0.941000;,
  0.533500;0.992000;,
  0.533500;0.956700;,
  0.444900;0.960200;,
  0.437900;0.948000;,
  0.425800;0.993400;,
  0.437900;0.986400;,
  0.444900;0.974200;,
  0.392500;0.974200;,
  0.399600;0.986400;,
  0.411700;0.993400;,
  0.461900;0.986400;,
  0.474100;0.993400;,
  0.488100;0.993400;,
  0.500300;0.986400;,
  0.454900;0.974200;,
  0.488100;0.941000;,
  0.500300;0.948000;,
  0.507300;0.960200;,
  0.507300;0.974200;,
  0.519400;0.956700;,
  0.519400;0.992000;,
  0.632500;0.992000;,
  0.632500;0.956700;,
  0.646600;0.956700;,
  0.646600;0.992000;,
  0.660800;0.956700;,
  0.660800;0.992000;,
  0.674900;0.992000;,
  0.674900;0.956700;,
  0.689000;0.956700;,
  0.689000;0.992000;,
  0.590100;0.956700;,
  0.073400;0.127500;,
  0.049800;0.127500;,
  0.049800;0.008600;,
  0.073400;0.008600;,
  0.081200;0.008600;,
  0.081200;0.127500;,
  0.157400;0.008600;,
  0.157400;0.127500;,
  0.149600;0.127500;,
  0.149600;0.008600;,
  0.095800;0.008600;,
  0.095800;0.127500;,
  0.590100;0.992000;,
  0.103600;0.008600;,
  0.103600;0.127500;,
  0.135000;0.008600;,
  0.135000;0.127500;,
  0.127200;0.008600;,
  0.127200;0.127500;,
  0.188500;0.963100;,
  0.193800;0.963100;,
  0.188500;0.968600;,
  0.232000;0.988700;,
  0.221600;0.983200;,
  0.221600;0.968600;,
  0.231900;0.963000;,
  0.272400;0.988700;,
  0.272300;0.963000;,
  0.228000;0.993000;,
  0.221600;0.993000;,
  0.221700;0.988700;,
  0.216400;0.988700;,
  0.271400;0.993000;,
  0.232900;0.993000;,
  0.782500;0.189900;,
  0.769800;0.183000;,
  0.769800;0.162600;,
  0.782500;0.158300;,
  0.766500;0.159400;,
  0.773600;0.149500;,
  0.773600;0.198800;,
  0.766500;0.186200;,
  0.742200;0.186200;,
  0.742100;0.198800;,
  0.733200;0.189900;,
  0.738800;0.183000;,
  0.733200;0.158300;,
  0.738800;0.162600;,
  0.742100;0.149500;,
  0.742200;0.159400;,
  0.966700;0.265900;,
  0.990200;0.265900;,
  0.990200;0.285700;,
  0.966700;0.285700;,
  0.966700;0.196500;,
  0.990200;0.196500;,
  0.990200;0.216300;,
  0.966700;0.216300;,
  0.966700;0.127100;,
  0.990200;0.127100;,
  0.990200;0.146900;,
  0.966700;0.146900;,
  0.966700;0.057700;,
  0.990200;0.057700;,
  0.990200;0.077500;,
  0.966700;0.077500;,
  0.966700;0.008100;,
  0.990200;0.008100;,
  0.858700;0.053700;,
  0.858600;0.045300;,
  0.870900;0.033000;,
  0.870800;0.065900;,
  0.879300;0.033100;,
  0.879100;0.066100;,
  0.835300;0.024100;,
  0.849600;0.009700;,
  0.849700;0.089100;,
  0.835300;0.074700;,
  0.891500;0.053800;,
  0.914900;0.074900;,
  0.900400;0.089300;,
  0.900400;0.009600;,
  0.914900;0.023900;,
  0.891600;0.045400;,
  0.318900;0.963000;,
  0.330600;0.963000;,
  0.330700;0.988700;,
  0.318900;0.988700;,
  0.284100;0.988700;,
  0.284100;0.963100;,
  0.371100;0.963000;,
  0.382900;0.963000;,
  0.382900;0.968500;,
  0.382900;0.983100;,
  0.371100;0.988700;,
  0.191000;0.993000;,
  0.188500;0.988700;,
  0.193800;0.988700;,
  0.382900;0.988700;,
  0.380800;0.993000;,
  0.373500;0.993000;,
  0.188500;0.983200;,
  0.282000;0.993000;,
  0.274700;0.993000;,
  0.317600;0.993000;,
  0.285500;0.993000;,
  0.328300;0.992900;,
  0.321000;0.992900;,
  0.370200;0.993000;,
  0.331600;0.993000;;
 }
}
