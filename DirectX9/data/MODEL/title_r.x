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
 212;
 21.89187;61.19084;-8.20300;,
 65.53416;37.64935;-8.20300;,
 66.39062;36.26834;-8.20300;,
 39.05866;61.19084;-8.20300;,
 64.71068;38.96107;-8.20300;,
 63.92019;40.20351;-8.20300;,
 63.16280;41.37670;-8.20300;,
 61.72914;43.52724;-8.20300;,
 61.01683;44.52869;-8.20300;,
 60.30149;45.48499;-8.20300;,
 59.58314;46.39608;-8.20300;,
 58.13143;48.08271;-8.20300;,
 57.38591;48.85826;-8.20300;,
 50.35349;53.66198;-8.20300;,
 40.92756;61.24808;-8.20300;,
 42.73923;61.41977;-8.20300;,
 50.35349;53.96239;-8.20300;,
 44.49358;61.70592;-8.20300;,
 71.58665;3.81539;-8.20300;,
 86.64597;3.81539;-8.20300;,
 53.51557;34.08415;-8.20300;,
 52.52774;35.72109;-8.20300;,
 51.55193;37.25867;-8.20300;,
 50.58814;38.69684;-8.20300;,
 49.63633;40.03564;-8.20300;,
 47.75834;42.42110;-8.20300;,
 46.81109;43.47974;-8.20300;,
 45.85477;44.45106;-8.20300;,
 44.88948;45.33500;-8.20300;,
 42.92133;46.84380;-8.20300;,
 41.89735;47.47474;-8.20300;,
 40.84328;48.02438;-8.20300;,
 39.75912;48.49274;-8.20300;,
 37.48685;49.19155;-8.20300;,
 36.27160;49.43401;-8.20300;,
 34.99914;49.60723;-8.20300;,
 33.66938;49.71117;-8.20300;,
 32.28238;49.74578;-8.20300;,
 21.89187;49.74578;-8.20300;,
 46.19073;62.10657;-8.20300;,
 49.39816;63.24368;-8.20300;,
 52.50846;54.58166;-8.20300;,
 41.46815;111.78995;-8.20300;,
 21.89187;100.34490;-8.20300;,
 9.24209;111.78995;-8.20300;,
 39.20887;100.34490;-8.20300;,
 43.25552;100.15065;-8.20300;,
 44.25576;111.71924;-8.20300;,
 46.95603;111.50681;-8.20300;,
 46.90155;99.56789;-8.20300;,
 49.56892;111.15296;-8.20300;,
 54.57610;55.29418;-8.20300;,
 50.87842;63.96508;-8.20300;,
 56.55635;56.09994;-8.20300;,
 52.27144;64.78588;-8.20300;,
 58.44939;56.99898;-8.20300;,
 53.57706;65.70604;-8.20300;,
 61.96591;59.07384;-8.20300;,
 55.91888;67.84306;-8.20300;,
 63.57430;60.24388;-8.20300;,
 52.09440;110.65742;-8.20300;,
 50.14706;98.59647;-8.20300;,
 56.86373;109.23883;-8.20300;,
 52.99188;97.23674;-8.20300;,
 59.06839;108.30960;-8.20300;,
 61.14651;107.23286;-8.20300;,
 57.45565;93.39377;-8.20300;,
 63.09805;106.00854;-8.20300;,
 66.60797;103.12014;-8.20300;,
 68.13950;101.46223;-8.20300;,
 69.51743;99.66275;-8.20300;,
 59.02643;90.99487;-8.20300;,
 70.74187;97.72180;-8.20300;,
 72.70752;93.41240;-8.20300;,
 60.14837;88.29189;-8.20300;,
 73.40338;91.03773;-8.20300;,
 60.82156;85.28471;-8.20300;,
 73.90045;88.51543;-8.20300;,
 74.19870;85.84552;-8.20300;,
 61.04594;81.97337;-8.20300;,
 74.29810;83.02793;-8.20300;,
 74.23035;80.80638;-8.20300;,
 60.97963;80.08344;-8.20300;,
 74.02699;78.66022;-8.20300;,
 73.68811;76.58948;-8.20300;,
 60.78086;78.26884;-8.20300;,
 73.21367;74.59413;-8.20300;,
 60.44948;76.52946;-8.20300;,
 71.86869;70.83260;-8.20300;,
 59.98554;74.86537;-8.20300;,
 71.01933;69.07227;-8.20300;,
 58.67511;71.77361;-8.20300;,
 70.05552;67.39314;-8.20300;,
 68.97731;65.79523;-8.20300;,
 66.48368;62.84624;-8.20300;,
 57.85879;70.36703;-8.20300;,
 56.94005;69.05685;-8.20300;,
 65.08019;61.50134;-8.20300;,
 9.24209;3.81539;-8.20300;,
 21.89187;3.81539;-8.20300;,
 51.40889;53.16653;-8.20300;,
 56.62536;49.58862;-8.20300;,
 52.40715;52.64400;-8.20300;,
 55.84976;50.27378;-8.20300;,
 54.23222;51.51760;-8.20300;,
 53.34822;52.09436;-8.20300;,
 66.39062;36.26834;8.20300;,
 65.53416;37.64935;8.20300;,
 21.89187;61.19084;8.20300;,
 39.05866;61.19084;8.20300;,
 64.71068;38.96107;8.20300;,
 63.92019;40.20351;8.20300;,
 63.16280;41.37670;8.20300;,
 61.72914;43.52724;8.20300;,
 61.01683;44.52869;8.20300;,
 60.30149;45.48499;8.20300;,
 59.58314;46.39608;8.20300;,
 58.13143;48.08271;8.20300;,
 57.38591;48.85826;8.20300;,
 50.35349;53.66198;8.20300;,
 40.92756;61.24808;8.20300;,
 42.73923;61.41977;8.20300;,
 50.35349;53.96239;8.20300;,
 44.49358;61.70592;8.20300;,
 86.64597;3.81539;8.20300;,
 71.58665;3.81539;8.20300;,
 53.51557;34.08415;8.20300;,
 52.52774;35.72109;8.20300;,
 51.55193;37.25867;8.20300;,
 50.58814;38.69684;8.20300;,
 49.63633;40.03564;8.20300;,
 47.75834;42.42110;8.20300;,
 46.81109;43.47974;8.20300;,
 45.85477;44.45106;8.20300;,
 44.88948;45.33500;8.20300;,
 42.92133;46.84380;8.20300;,
 41.89735;47.47474;8.20300;,
 40.84328;48.02438;8.20300;,
 39.75912;48.49274;8.20300;,
 37.48685;49.19155;8.20300;,
 36.27160;49.43401;8.20300;,
 34.99914;49.60723;8.20300;,
 33.66938;49.71117;8.20300;,
 32.28238;49.74578;8.20300;,
 21.89187;49.74578;8.20300;,
 46.19073;62.10657;8.20300;,
 49.39816;63.24368;8.20300;,
 52.50846;54.58166;8.20300;,
 9.24209;111.78995;8.20300;,
 21.89187;100.34490;8.20300;,
 41.46815;111.78995;8.20300;,
 39.20887;100.34490;8.20300;,
 43.25552;100.15065;8.20300;,
 44.25576;111.71924;8.20300;,
 46.95603;111.50681;8.20300;,
 46.90155;99.56789;8.20300;,
 49.56892;111.15296;8.20300;,
 54.57610;55.29418;8.20300;,
 50.87842;63.96508;8.20300;,
 56.55635;56.09994;8.20300;,
 52.27144;64.78588;8.20300;,
 58.44939;56.99898;8.20300;,
 53.57706;65.70604;8.20300;,
 61.96591;59.07384;8.20300;,
 55.91888;67.84306;8.20300;,
 63.57430;60.24388;8.20300;,
 52.09440;110.65742;8.20300;,
 50.14706;98.59647;8.20300;,
 56.86373;109.23883;8.20300;,
 52.99188;97.23674;8.20300;,
 59.06839;108.30960;8.20300;,
 61.14651;107.23286;8.20300;,
 57.45565;93.39377;8.20300;,
 63.09805;106.00854;8.20300;,
 66.60797;103.12014;8.20300;,
 68.13950;101.46223;8.20300;,
 69.51743;99.66275;8.20300;,
 59.02643;90.99487;8.20300;,
 70.74187;97.72180;8.20300;,
 72.70752;93.41240;8.20300;,
 60.14837;88.29189;8.20300;,
 73.40338;91.03773;8.20300;,
 60.82156;85.28471;8.20300;,
 73.90045;88.51543;8.20300;,
 74.19870;85.84552;8.20300;,
 61.04594;81.97337;8.20300;,
 74.29810;83.02793;8.20300;,
 74.23035;80.80638;8.20300;,
 60.97963;80.08344;8.20300;,
 74.02699;78.66022;8.20300;,
 73.68811;76.58948;8.20300;,
 60.78086;78.26884;8.20300;,
 73.21367;74.59413;8.20300;,
 60.44948;76.52946;8.20300;,
 71.86869;70.83260;8.20300;,
 59.98554;74.86537;8.20300;,
 71.01933;69.07227;8.20300;,
 58.67511;71.77361;8.20300;,
 70.05552;67.39314;8.20300;,
 68.97731;65.79523;8.20300;,
 66.48368;62.84624;8.20300;,
 57.85879;70.36703;8.20300;,
 56.94005;69.05685;8.20300;,
 65.08019;61.50134;8.20300;,
 9.24209;3.81539;8.20300;,
 21.89187;3.81539;8.20300;,
 51.40889;53.16653;8.20300;,
 56.62536;49.58862;8.20300;,
 52.40715;52.64400;8.20300;,
 55.84976;50.27378;8.20300;,
 54.23222;51.51760;8.20300;,
 53.34822;52.09436;8.20300;;
 
 318;
 3;0,1,2;,
 3;3,1,0;,
 3;3,4,1;,
 3;3,5,4;,
 3;3,6,5;,
 3;3,7,6;,
 3;3,8,7;,
 3;3,9,8;,
 3;3,10,9;,
 3;3,11,10;,
 3;3,12,11;,
 3;3,13,12;,
 3;14,13,3;,
 3;15,13,14;,
 3;15,16,13;,
 3;17,16,15;,
 3;18,2,19;,
 3;20,2,18;,
 3;21,2,20;,
 3;22,2,21;,
 3;23,2,22;,
 3;24,2,23;,
 3;25,2,24;,
 3;26,2,25;,
 3;27,2,26;,
 3;28,2,27;,
 3;29,2,28;,
 3;29,0,2;,
 3;30,0,29;,
 3;31,0,30;,
 3;32,0,31;,
 3;33,0,32;,
 3;34,0,33;,
 3;35,0,34;,
 3;36,0,35;,
 3;37,0,36;,
 3;38,0,37;,
 3;39,16,17;,
 3;40,16,39;,
 3;40,41,16;,
 3;42,43,44;,
 3;42,45,43;,
 3;42,46,45;,
 3;47,46,42;,
 3;48,46,47;,
 3;48,49,46;,
 3;50,49,48;,
 3;40,51,41;,
 3;52,51,40;,
 3;52,53,51;,
 3;54,53,52;,
 3;54,55,53;,
 3;56,55,54;,
 3;56,57,55;,
 3;58,57,56;,
 3;58,59,57;,
 3;60,49,50;,
 3;60,61,49;,
 3;62,61,60;,
 3;62,63,61;,
 3;64,63,62;,
 3;65,63,64;,
 3;65,66,63;,
 3;67,66,65;,
 3;68,66,67;,
 3;69,66,68;,
 3;70,66,69;,
 3;70,71,66;,
 3;72,71,70;,
 3;73,71,72;,
 3;73,74,71;,
 3;75,74,73;,
 3;75,76,74;,
 3;77,76,75;,
 3;78,76,77;,
 3;78,79,76;,
 3;80,79,78;,
 3;81,79,80;,
 3;81,82,79;,
 3;83,82,81;,
 3;84,82,83;,
 3;84,85,82;,
 3;86,85,84;,
 3;86,87,85;,
 3;88,87,86;,
 3;88,89,87;,
 3;90,89,88;,
 3;90,91,89;,
 3;92,91,90;,
 3;93,91,92;,
 3;94,91,93;,
 3;94,95,91;,
 3;94,96,95;,
 3;97,96,94;,
 3;59,96,97;,
 3;96,59,58;,
 3;43,98,44;,
 3;0,98,43;,
 3;38,98,0;,
 3;98,38,99;,
 3;100,12,13;,
 3;100,101,12;,
 3;102,101,100;,
 3;102,103,101;,
 3;102,104,103;,
 3;104,102,105;,
 3;106,107,108;,
 3;108,107,109;,
 3;107,110,109;,
 3;110,111,109;,
 3;111,112,109;,
 3;112,113,109;,
 3;113,114,109;,
 3;114,115,109;,
 3;115,116,109;,
 3;116,117,109;,
 3;117,118,109;,
 3;118,119,109;,
 3;109,119,120;,
 3;120,119,121;,
 3;119,122,121;,
 3;121,122,123;,
 3;124,106,125;,
 3;125,106,126;,
 3;126,106,127;,
 3;127,106,128;,
 3;128,106,129;,
 3;129,106,130;,
 3;130,106,131;,
 3;131,106,132;,
 3;132,106,133;,
 3;133,106,134;,
 3;134,106,135;,
 3;106,108,135;,
 3;135,108,136;,
 3;136,108,137;,
 3;137,108,138;,
 3;138,108,139;,
 3;139,108,140;,
 3;140,108,141;,
 3;141,108,142;,
 3;142,108,143;,
 3;143,108,144;,
 3;123,122,145;,
 3;145,122,146;,
 3;122,147,146;,
 3;148,149,150;,
 3;149,151,150;,
 3;151,152,150;,
 3;150,152,153;,
 3;153,152,154;,
 3;152,155,154;,
 3;154,155,156;,
 3;147,157,146;,
 3;146,157,158;,
 3;157,159,158;,
 3;158,159,160;,
 3;159,161,160;,
 3;160,161,162;,
 3;161,163,162;,
 3;162,163,164;,
 3;163,165,164;,
 3;156,155,166;,
 3;155,167,166;,
 3;166,167,168;,
 3;167,169,168;,
 3;168,169,170;,
 3;170,169,171;,
 3;169,172,171;,
 3;171,172,173;,
 3;173,172,174;,
 3;174,172,175;,
 3;175,172,176;,
 3;172,177,176;,
 3;176,177,178;,
 3;178,177,179;,
 3;177,180,179;,
 3;179,180,181;,
 3;180,182,181;,
 3;181,182,183;,
 3;183,182,184;,
 3;182,185,184;,
 3;184,185,186;,
 3;186,185,187;,
 3;185,188,187;,
 3;187,188,189;,
 3;189,188,190;,
 3;188,191,190;,
 3;190,191,192;,
 3;191,193,192;,
 3;192,193,194;,
 3;193,195,194;,
 3;194,195,196;,
 3;195,197,196;,
 3;196,197,198;,
 3;198,197,199;,
 3;199,197,200;,
 3;197,201,200;,
 3;201,202,200;,
 3;200,202,203;,
 3;203,202,165;,
 3;164,165,202;,
 3;148,204,149;,
 3;149,204,108;,
 3;108,204,144;,
 3;205,144,204;,
 3;119,118,206;,
 3;118,207,206;,
 3;206,207,208;,
 3;207,209,208;,
 3;209,210,208;,
 3;211,208,210;,
 4;1,107,106,2;,
 4;0,108,109,3;,
 4;4,110,107,1;,
 4;5,111,110,4;,
 4;6,112,111,5;,
 4;7,113,112,6;,
 4;8,114,113,7;,
 4;9,115,114,8;,
 4;10,116,115,9;,
 4;11,117,116,10;,
 4;12,118,117,11;,
 4;3,109,120,14;,
 4;14,120,121,15;,
 4;16,122,119,13;,
 4;15,121,123,17;,
 4;2,106,124,19;,
 4;19,124,125,18;,
 4;18,125,126,20;,
 4;20,126,127,21;,
 4;21,127,128,22;,
 4;22,128,129,23;,
 4;23,129,130,24;,
 4;24,130,131,25;,
 4;25,131,132,26;,
 4;26,132,133,27;,
 4;27,133,134,28;,
 4;28,134,135,29;,
 4;29,135,136,30;,
 4;30,136,137,31;,
 4;31,137,138,32;,
 4;32,138,139,33;,
 4;33,139,140,34;,
 4;34,140,141,35;,
 4;35,141,142,36;,
 4;36,142,143,37;,
 4;37,143,144,38;,
 4;17,123,145,39;,
 4;39,145,146,40;,
 4;41,147,122,16;,
 4;44,148,150,42;,
 4;45,151,149,43;,
 4;46,152,151,45;,
 4;42,150,153,47;,
 4;47,153,154,48;,
 4;49,155,152,46;,
 4;48,154,156,50;,
 4;51,157,147,41;,
 4;40,146,158,52;,
 4;53,159,157,51;,
 4;52,158,160,54;,
 4;55,161,159,53;,
 4;54,160,162,56;,
 4;57,163,161,55;,
 4;56,162,164,58;,
 4;59,165,163,57;,
 4;50,156,166,60;,
 4;61,167,155,49;,
 4;60,166,168,62;,
 4;63,169,167,61;,
 4;62,168,170,64;,
 4;64,170,171,65;,
 4;66,172,169,63;,
 4;65,171,173,67;,
 4;67,173,174,68;,
 4;68,174,175,69;,
 4;69,175,176,70;,
 4;71,177,172,66;,
 4;70,176,178,72;,
 4;72,178,179,73;,
 4;74,180,177,71;,
 4;73,179,181,75;,
 4;76,182,180,74;,
 4;75,181,183,77;,
 4;77,183,184,78;,
 4;79,185,182,76;,
 4;78,184,186,80;,
 4;80,186,187,81;,
 4;82,188,185,79;,
 4;81,187,189,83;,
 4;83,189,190,84;,
 4;85,191,188,82;,
 4;84,190,192,86;,
 4;87,193,191,85;,
 4;86,192,194,88;,
 4;89,195,193,87;,
 4;88,194,196,90;,
 4;91,197,195,89;,
 4;90,196,198,92;,
 4;92,198,199,93;,
 4;93,199,200,94;,
 4;95,201,197,91;,
 4;96,202,201,95;,
 4;94,200,203,97;,
 4;97,203,165,59;,
 4;58,164,202,96;,
 4;98,204,148,44;,
 4;43,149,108,0;,
 4;38,144,205,99;,
 4;99,205,204,98;,
 4;13,119,206,100;,
 4;101,207,118,12;,
 4;100,206,208,102;,
 4;103,209,207,101;,
 4;104,210,209,103;,
 4;102,208,211,105;,
 4;105,211,210,104;;
 
 MeshMaterialList {
  1;
  318;
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
    "C:\\Users\\haosheng\\Desktop\\titlemodel.jpg";
   }
  }
 }
 MeshNormals {
  106;
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.848390;0.529371;0.000000;,
  0.849083;0.528260;0.000000;,
  0.000000;1.000000;0.000000;,
  -0.015307;0.999883;0.000000;,
  0.845327;0.534250;0.000000;,
  0.841928;0.539590;0.000000;,
  0.836119;0.548549;0.000000;,
  0.823569;0.567216;0.000000;,
  0.807881;0.589346;0.000000;,
  0.793077;0.609121;0.000000;,
  0.771774;0.635896;0.000000;,
  0.739703;0.672934;0.000000;,
  0.706928;0.707285;0.000000;,
  -0.062511;0.998044;0.000000;,
  -0.127736;0.991808;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.195489;0.980706;0.000000;,
  0.848324;0.529477;0.000000;,
  0.000000;-1.000000;0.000000;,
  -0.493653;-0.869659;-0.000000;,
  -0.857403;-0.514645;-0.000000;,
  -0.850304;-0.526291;-0.000000;,
  -0.837582;-0.546312;-0.000000;,
  -0.822945;-0.568121;-0.000000;,
  -0.800611;-0.599184;-0.000000;,
  -0.765856;-0.643012;-0.000000;,
  -0.729115;-0.684391;-0.000000;,
  -0.694201;-0.719782;-0.000000;,
  -0.642487;-0.766296;-0.000000;,
  -0.567227;-0.823562;-0.000000;,
  -0.493784;-0.869584;-0.000000;,
  -0.429755;-0.902946;-0.000000;,
  -0.345785;-0.938314;-0.000000;,
  -0.245121;-0.969493;-0.000000;,
  -0.165350;-0.986235;-0.000000;,
  -0.106448;-0.994318;-0.000000;,
  -0.051457;-0.998675;-0.000000;,
  -0.012477;-0.999922;-0.000000;,
  -0.282371;0.959305;0.000000;,
  -0.386733;0.922192;0.000000;,
  0.301098;-0.953593;0.000000;,
  0.276189;-0.961103;0.000000;,
  0.012680;0.999920;0.000000;,
  -0.023981;-0.999712;-0.000000;,
  -0.103047;-0.994676;-0.000000;,
  0.051910;0.998652;0.000000;,
  0.106355;0.994328;0.000000;,
  -0.222774;-0.974870;-0.000000;,
  0.163445;0.986553;0.000000;,
  0.351477;-0.936196;0.000000;,
  -0.473240;0.880934;0.000000;,
  0.403108;-0.915153;0.000000;,
  -0.542313;0.840177;0.000000;,
  0.469056;-0.883169;0.000000;,
  -0.626310;0.779574;0.000000;,
  0.548851;-0.835920;0.000000;,
  -0.721203;0.692723;0.000000;,
  0.614954;-0.788563;0.000000;,
  0.239092;0.970997;0.000000;,
  -0.360072;-0.932924;-0.000000;,
  0.337253;0.941414;0.000000;,
  -0.546630;-0.837374;-0.000000;,
  0.424554;0.905403;0.000000;,
  0.496161;0.868231;0.000000;,
  -0.751894;-0.659284;-0.000000;,
  0.584634;0.811297;0.000000;,
  0.686587;0.727048;0.000000;,
  0.765070;0.643947;0.000000;,
  0.820709;0.571346;0.000000;,
  -0.883935;-0.467610;-0.000000;,
  0.879795;0.475353;0.000000;,
  0.937125;0.348995;0.000000;,
  -0.953295;-0.302040;-0.000000;,
  0.971382;0.237524;0.000000;,
  -0.989658;-0.143447;-0.000000;,
  0.988332;0.152316;0.000000;,
  0.997318;0.073190;0.000000;,
  -0.999867;-0.016293;-0.000000;,
  0.999997;0.002389;0.000000;,
  0.998049;-0.062440;0.000000;,
  -0.997403;0.072025;0.000000;,
  0.991775;-0.127992;0.000000;,
  0.980496;-0.196539;0.000000;,
  -0.988967;0.148137;0.000000;,
  0.958695;-0.284435;0.000000;,
  -0.973649;0.228051;0.000000;,
  0.922428;-0.386168;0.000000;,
  -0.943952;0.330081;0.000000;,
  0.884528;-0.466487;0.000000;,
  -0.894550;0.446969;0.000000;,
  0.848670;-0.528923;0.000000;,
  0.797440;-0.603398;0.000000;,
  0.728737;-0.684794;0.000000;,
  -0.842600;0.538540;0.000000;,
  -0.792750;0.609547;0.000000;,
  0.666802;-0.745235;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.424947;0.905218;0.000000;,
  0.444455;0.895801;0.000000;,
  0.677500;0.735523;0.000000;,
  0.484176;0.874971;0.000000;,
  0.636186;0.771536;0.000000;,
  0.578433;0.815730;0.000000;,
  0.525542;0.850768;0.000000;;
  318;
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  4;2,2,3,3;,
  4;4,4,5,5;,
  4;6,6,2,2;,
  4;7,7,6,6;,
  4;8,8,7,7;,
  4;9,9,8,8;,
  4;10,10,9,9;,
  4;11,11,10,10;,
  4;12,12,11,11;,
  4;13,13,12,12;,
  4;14,14,13,13;,
  4;5,5,15,15;,
  4;15,15,16,16;,
  4;17,17,17,17;,
  4;16,16,18,18;,
  4;3,3,19,19;,
  4;20,20,21,21;,
  4;21,21,22,22;,
  4;22,22,23,23;,
  4;23,23,24,24;,
  4;24,24,25,25;,
  4;25,25,26,26;,
  4;26,26,27,27;,
  4;27,27,28,28;,
  4;28,28,29,29;,
  4;29,29,30,30;,
  4;30,30,31,31;,
  4;31,31,32,32;,
  4;32,32,33,33;,
  4;33,33,34,34;,
  4;34,34,35,35;,
  4;35,35,36,36;,
  4;36,36,37,37;,
  4;37,37,38,38;,
  4;38,38,39,39;,
  4;39,39,20,20;,
  4;18,18,40,40;,
  4;40,40,41,41;,
  4;42,42,43,43;,
  4;4,4,44,44;,
  4;45,45,20,20;,
  4;46,46,45,45;,
  4;44,44,47,47;,
  4;47,47,48,48;,
  4;49,49,46,46;,
  4;48,48,50,50;,
  4;51,51,42,42;,
  4;41,41,52,52;,
  4;53,53,51,51;,
  4;52,52,54,54;,
  4;55,55,53,53;,
  4;54,54,56,56;,
  4;57,57,55,55;,
  4;56,56,58,58;,
  4;59,59,57,57;,
  4;50,50,60,60;,
  4;61,61,49,49;,
  4;60,60,62,62;,
  4;63,63,61,61;,
  4;62,62,64,64;,
  4;64,64,65,65;,
  4;66,66,63,63;,
  4;65,65,67,67;,
  4;67,67,68,68;,
  4;68,68,69,69;,
  4;69,69,70,70;,
  4;71,71,66,66;,
  4;70,70,72,72;,
  4;72,72,73,73;,
  4;74,74,71,71;,
  4;73,73,75,75;,
  4;76,76,74,74;,
  4;75,75,77,77;,
  4;77,77,78,78;,
  4;79,79,76,76;,
  4;78,78,80,80;,
  4;80,80,81,81;,
  4;82,82,79,79;,
  4;81,81,83,83;,
  4;83,83,84,84;,
  4;85,85,82,82;,
  4;84,84,86,86;,
  4;87,87,85,85;,
  4;86,86,88,88;,
  4;89,89,87,87;,
  4;88,88,90,90;,
  4;91,91,89,89;,
  4;90,90,92,92;,
  4;92,92,93,93;,
  4;93,93,94,94;,
  4;95,95,91,91;,
  4;96,96,95,95;,
  4;94,94,97,97;,
  4;97,97,59,59;,
  4;58,58,96,96;,
  4;98,98,98,98;,
  4;17,17,17,17;,
  4;17,17,17,17;,
  4;20,20,20,20;,
  4;99,99,100,100;,
  4;101,101,14,14;,
  4;100,100,102,102;,
  4;103,103,101,101;,
  4;104,104,103,103;,
  4;102,102,105,105;,
  4;105,105,104,104;;
 }
 MeshTextureCoords {
  212;
  0.609459;0.194046;,
  0.827671;0.311753;,
  0.831953;0.318658;,
  0.695293;0.194046;,
  0.823553;0.305195;,
  0.819601;0.298982;,
  0.815814;0.293117;,
  0.808646;0.282364;,
  0.805084;0.277357;,
  0.801507;0.272575;,
  0.797916;0.268020;,
  0.790657;0.259586;,
  0.786930;0.255709;,
  0.751767;0.231690;,
  0.704638;0.193760;,
  0.713696;0.192901;,
  0.751767;0.230188;,
  0.722468;0.191470;,
  0.857933;0.480923;,
  0.933230;0.480923;,
  0.767578;0.329579;,
  0.762639;0.321395;,
  0.757760;0.313707;,
  0.752941;0.306516;,
  0.748182;0.299822;,
  0.738792;0.287895;,
  0.734055;0.282601;,
  0.729274;0.277745;,
  0.724447;0.273325;,
  0.714607;0.265781;,
  0.709487;0.262626;,
  0.704216;0.259878;,
  0.698796;0.257536;,
  0.687434;0.254042;,
  0.681358;0.252830;,
  0.674996;0.251964;,
  0.668347;0.251444;,
  0.661412;0.251271;,
  0.609459;0.251271;,
  0.730954;0.189467;,
  0.746991;0.183782;,
  0.762542;0.227092;,
  0.707341;-0.058950;,
  0.609459;-0.001724;,
  0.546210;-0.058950;,
  0.696044;-0.001724;,
  0.716278;-0.000753;,
  0.721279;-0.058596;,
  0.734780;-0.057534;,
  0.734508;0.002161;,
  0.747845;-0.055765;,
  0.772880;0.223529;,
  0.754392;0.180175;,
  0.782782;0.219500;,
  0.761357;0.176071;,
  0.792247;0.215005;,
  0.767885;0.171470;,
  0.809830;0.204631;,
  0.779594;0.160785;,
  0.817871;0.198781;,
  0.760472;-0.053287;,
  0.750735;0.007018;,
  0.784319;-0.046194;,
  0.764959;0.013816;,
  0.795342;-0.041548;,
  0.805733;-0.036164;,
  0.787278;0.033031;,
  0.815490;-0.030043;,
  0.833040;-0.015601;,
  0.840697;-0.007311;,
  0.847587;0.001686;,
  0.795132;0.045026;,
  0.853709;0.011391;,
  0.863538;0.032938;,
  0.800742;0.058541;,
  0.867017;0.044811;,
  0.804108;0.073576;,
  0.869502;0.057423;,
  0.870993;0.070772;,
  0.805230;0.090133;,
  0.871490;0.084860;,
  0.871152;0.095968;,
  0.804898;0.099583;,
  0.870135;0.106699;,
  0.868441;0.117053;,
  0.803904;0.108656;,
  0.866068;0.127029;,
  0.802247;0.117353;,
  0.859343;0.145837;,
  0.799928;0.125673;,
  0.855097;0.154639;,
  0.793376;0.141132;,
  0.850278;0.163034;,
  0.844887;0.171024;,
  0.832418;0.185769;,
  0.789294;0.148165;,
  0.784700;0.154716;,
  0.825401;0.192493;,
  0.546210;0.480923;,
  0.609459;0.480923;,
  0.757044;0.234167;,
  0.783127;0.252057;,
  0.762036;0.236780;,
  0.779249;0.248631;,
  0.771161;0.242412;,
  0.766741;0.239528;,
  0.831953;0.318658;,
  0.827671;0.311753;,
  0.609459;0.194046;,
  0.695293;0.194046;,
  0.823553;0.305195;,
  0.819601;0.298982;,
  0.815814;0.293117;,
  0.808646;0.282364;,
  0.805084;0.277357;,
  0.801507;0.272575;,
  0.797916;0.268020;,
  0.790657;0.259586;,
  0.786930;0.255709;,
  0.751767;0.231690;,
  0.704638;0.193760;,
  0.713696;0.192901;,
  0.751767;0.230188;,
  0.722468;0.191470;,
  0.933230;0.480923;,
  0.857933;0.480923;,
  0.767578;0.329579;,
  0.762639;0.321395;,
  0.757760;0.313707;,
  0.752941;0.306516;,
  0.748182;0.299822;,
  0.738792;0.287895;,
  0.734055;0.282601;,
  0.729274;0.277745;,
  0.724447;0.273325;,
  0.714607;0.265781;,
  0.709487;0.262626;,
  0.704216;0.259878;,
  0.698796;0.257536;,
  0.687434;0.254042;,
  0.681358;0.252830;,
  0.674996;0.251964;,
  0.668347;0.251444;,
  0.661412;0.251271;,
  0.609459;0.251271;,
  0.730954;0.189467;,
  0.746991;0.183782;,
  0.762542;0.227092;,
  0.546210;-0.058950;,
  0.609459;-0.001724;,
  0.707341;-0.058950;,
  0.696044;-0.001724;,
  0.716278;-0.000753;,
  0.721279;-0.058596;,
  0.734780;-0.057534;,
  0.734508;0.002161;,
  0.747845;-0.055765;,
  0.772880;0.223529;,
  0.754392;0.180175;,
  0.782782;0.219500;,
  0.761357;0.176071;,
  0.792247;0.215005;,
  0.767885;0.171470;,
  0.809830;0.204631;,
  0.779594;0.160785;,
  0.817871;0.198781;,
  0.760472;-0.053287;,
  0.750735;0.007018;,
  0.784319;-0.046194;,
  0.764959;0.013816;,
  0.795342;-0.041548;,
  0.805733;-0.036164;,
  0.787278;0.033031;,
  0.815490;-0.030043;,
  0.833040;-0.015601;,
  0.840697;-0.007311;,
  0.847587;0.001686;,
  0.795132;0.045026;,
  0.853709;0.011391;,
  0.863538;0.032938;,
  0.800742;0.058541;,
  0.867017;0.044811;,
  0.804108;0.073576;,
  0.869502;0.057423;,
  0.870993;0.070772;,
  0.805230;0.090133;,
  0.871490;0.084860;,
  0.871152;0.095968;,
  0.804898;0.099583;,
  0.870135;0.106699;,
  0.868441;0.117053;,
  0.803904;0.108656;,
  0.866068;0.127029;,
  0.802247;0.117353;,
  0.859343;0.145837;,
  0.799928;0.125673;,
  0.855097;0.154639;,
  0.793376;0.141132;,
  0.850278;0.163034;,
  0.844887;0.171024;,
  0.832418;0.185769;,
  0.789294;0.148165;,
  0.784700;0.154716;,
  0.825401;0.192493;,
  0.546210;0.480923;,
  0.609459;0.480923;,
  0.757044;0.234167;,
  0.783127;0.252057;,
  0.762036;0.236780;,
  0.779249;0.248631;,
  0.771161;0.242412;,
  0.766741;0.239528;;
 }
}
