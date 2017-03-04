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
 155;
 -0.23955;0.61412;17.43395;,
 4.71217;1.75959;18.62609;,
 4.05792;3.26194;22.77962;,
 -1.26040;2.15158;22.21685;,
 -5.56362;2.20582;20.18670;,
 -4.81924;0.57917;15.00854;,
 -10.51346;2.48438;16.09895;,
 -9.25941;1.72090;12.32363;,
 -7.99889;2.90908;19.99210;,
 -8.90253;2.88093;19.55863;,
 7.66151;8.35749;17.41008;,
 6.38478;8.50301;18.56032;,
 7.49704;4.88306;18.03389;,
 8.64225;5.23429;15.98977;,
 1.01171;-0.74705;11.87652;,
 2.80228;-2.39407;5.82800;,
 6.73550;-1.04680;6.26182;,
 5.47418;0.00000;12.75949;,
 -3.64260;-0.81200;10.20508;,
 -1.83467;-2.54046;4.17261;,
 -7.78640;0.56495;7.55923;,
 -6.61013;-0.76000;2.97769;,
 10.13099;3.49003;10.62181;,
 13.21062;6.50316;13.39082;,
 10.71613;6.65867;16.13219;,
 9.06391;8.87401;17.52110;,
 8.02264;4.22130;1.85166;,
 8.89817;0.56978;6.97098;,
 7.39926;-0.47698;2.16989;,
 10.67812;6.90811;6.96587;,
 12.73505;9.69867;10.53991;,
 4.11430;4.32265;25.54908;,
 1.03090;6.77310;26.60189;,
 1.51279;4.30518;24.07291;,
 6.51202;5.80095;21.66126;,
 6.49928;7.09466;24.36222;,
 0.40374;3.97587;23.84139;,
 0.00473;6.37911;26.51367;,
 -2.37879;4.18485;26.05763;,
 -4.81905;5.43716;25.68645;,
 -3.75077;3.22650;23.08249;,
 -4.66018;2.98041;22.55681;,
 -5.47579;5.37661;25.21402;,
 -7.26657;3.13181;23.98297;,
 -9.38411;4.46482;22.78538;,
 -10.21038;4.85170;22.37324;,
 -12.39587;3.60990;20.34512;,
 -12.54398;3.85233;14.46735;,
 -11.17840;3.18595;10.95893;,
 -14.14679;5.14966;18.91843;,
 0.00473;6.37911;26.51367;,
 1.03090;6.77310;26.60189;,
 1.19544;8.61565;25.66362;,
 -0.35170;8.60036;25.66905;,
 3.11516;9.59585;24.01785;,
 -2.11833;8.94300;23.84465;,
 1.19544;8.61565;25.66362;,
 -4.49962;8.03657;24.53679;,
 -5.70691;7.75468;23.84964;,
 -5.47579;5.37661;25.21402;,
 -10.16783;1.88848;6.66246;,
 -12.38272;5.71317;14.00192;,
 -10.96132;4.89380;10.32265;,
 -13.89663;7.17650;18.87047;,
 -9.67145;4.08233;6.10231;,
 -10.21038;4.85170;22.37324;,
 -9.19195;7.29305;22.13498;,
 -10.87610;7.90888;21.22611;,
 5.88558;8.89950;20.90608;,
 5.42293;9.70335;23.51583;,
 2.85139;9.48491;19.59307;,
 3.11516;9.59585;24.01785;,
 2.85139;9.48491;19.59307;,
 -0.59339;8.86323;18.64805;,
 -7.18164;8.14560;21.70811;,
 -2.11833;8.94300;23.84465;,
 -14.56868;7.59071;20.26733;,
 -13.89663;7.17650;18.87047;,
 -14.14679;5.14966;18.91843;,
 -14.83518;5.60588;20.52953;,
 -12.39587;3.60990;20.34512;,
 -13.10871;5.29907;21.96881;,
 -11.38912;6.01026;23.01043;,
 -11.95964;8.32847;21.77538;,
 -12.30563;9.05798;18.81889;,
 -13.09931;8.91497;20.47826;,
 -9.19195;7.29305;22.13498;,
 -7.18164;8.14560;21.70811;,
 -0.59339;8.86323;18.64805;,
 -5.41839;8.29340;17.28894;,
 -5.41839;8.29340;17.28894;,
 -10.96093;7.59714;15.12209;,
 -12.38272;5.71317;14.00192;,
 6.38478;8.50301;18.56032;,
 7.66151;8.35749;17.41008;,
 6.55179;10.66694;15.19377;,
 4.73620;8.92735;16.06731;,
 -3.49869;7.87879;12.99610;,
 -9.33861;6.87492;11.13060;,
 -10.96132;4.89380;10.32265;,
 8.43280;10.81205;15.58221;,
 9.49163;11.76064;10.41320;,
 4.98967;11.52736;11.61987;,
 6.55179;10.66694;15.19377;,
 1.97663;8.42291;13.42704;,
 6.55179;10.66694;15.19377;,
 4.98967;11.52736;11.61987;,
 -3.08204;7.79637;8.46884;,
 0.33619;8.57779;9.18881;,
 0.19955;7.88194;4.81246;,
 -2.47134;7.32619;4.06352;,
 9.10680;5.54407;4.14690;,
 5.73364;9.06566;3.85815;,
 7.64511;11.08055;7.18280;,
 3.23172;11.28386;8.45534;,
 0.33619;8.57779;9.18881;,
 4.73620;8.92735;16.06731;,
 1.97663;8.42291;13.42704;,
 -5.41839;8.29340;17.28894;,
 8.61972;1.57428;11.83969;,
 -6.61732;1.63098;-0.04994;,
 -8.35234;1.38735;2.63161;,
 -6.62156;4.49760;2.24190;,
 -2.43719;5.37513;0.78840;,
 -1.26119;-2.67089;0.77804;,
 -5.94968;-1.19090;0.22779;,
 3.83451;-2.37873;1.46226;,
 9.06391;8.87401;17.52110;,
 8.43280;10.81205;15.58221;,
 6.38478;8.50301;18.56032;,
 3.31812;10.02038;5.11023;,
 0.19955;7.88194;4.81246;,
 -8.05196;6.55765;7.44597;,
 -5.47188;6.38342;4.73626;,
 -6.62156;4.49760;2.24190;,
 -9.67145;4.08233;6.10231;,
 5.73364;9.06566;3.85815;,
 2.80546;7.11069;1.50363;,
 9.86449;3.05495;7.32543;,
 -3.08204;7.79637;8.46884;,
 -3.49869;7.87879;12.99610;,
 -3.08204;7.79637;8.46884;,
 -8.05196;6.55765;7.44597;,
 7.64511;11.08055;7.18280;,
 3.23172;11.28386;8.45534;,
 5.73364;9.06566;3.85815;,
 3.31812;10.02038;5.11023;,
 9.49163;11.76064;10.41320;,
 12.73505;9.69867;10.53991;,
 9.10680;5.54407;4.14690;,
 8.02264;4.22130;1.85166;,
 9.10680;5.54407;4.14690;,
 2.80546;7.11069;1.50363;,
 -2.43719;5.37513;0.78840;,
 -2.43719;5.37513;0.78840;;
 
 91;
 4;0,1,2,3;,
 4;3,4,5,0;,
 4;4,6,7,5;,
 4;8,9,6,4;,
 4;10,11,12,13;,
 4;14,15,16,17;,
 4;18,19,15,14;,
 4;20,21,19,18;,
 4;22,23,24,13;,
 4;13,24,25,10;,
 4;26,27,16,28;,
 4;22,29,30,23;,
 4;31,32,33,2;,
 4;34,35,31,2;,
 4;2,33,36,3;,
 4;32,37,36,33;,
 4;3,36,37,38;,
 4;38,39,40,3;,
 4;4,3,40,41;,
 4;4,41,42,43;,
 4;39,42,41,40;,
 4;43,44,8,4;,
 4;44,45,9,8;,
 4;45,46,6,9;,
 4;6,47,48,7;,
 4;46,49,47,6;,
 4;50,51,52,53;,
 4;54,55,53,56;,
 4;39,57,58,59;,
 4;60,20,7,48;,
 4;20,18,5,7;,
 4;18,14,0,5;,
 4;47,61,62,48;,
 4;49,63,61,47;,
 4;48,62,64,60;,
 4;65,44,66,67;,
 4;34,68,69,35;,
 4;68,70,71,69;,
 4;72,73,55,54;,
 4;74,58,57,75;,
 4;76,77,78,79;,
 4;78,80,81,79;,
 4;80,65,82,81;,
 4;67,83,82,65;,
 4;84,85,83,67;,
 4;77,76,85,84;,
 4;86,87,84,67;,
 4;75,88,89,74;,
 4;87,90,91,84;,
 4;92,77,84,91;,
 4;93,94,95,96;,
 4;90,97,98,91;,
 4;91,98,99,92;,
 4;100,101,102,103;,
 4;104,96,105,106;,
 4;107,108,109,110;,
 4;29,111,112,113;,
 4;104,106,114,115;,
 4;72,116,117,73;,
 4;117,97,118,73;,
 4;96,70,68,93;,
 4;0,14,17,1;,
 4;12,1,17,119;,
 4;34,2,1,12;,
 4;16,27,119,17;,
 4;120,121,122,123;,
 4;124,19,21,125;,
 4;126,15,19,124;,
 4;28,16,15,126;,
 4;121,21,20,60;,
 4;127,128,105,94;,
 4;129,68,34,12;,
 4;114,130,131,115;,
 4;12,119,22,13;,
 4;132,133,134,135;,
 4;130,136,137,131;,
 4;27,138,22,119;,
 4;122,121,60,64;,
 4;139,140,104,115;,
 4;132,98,97,141;,
 4;135,99,98,142;,
 4;101,143,144,102;,
 4;143,145,146,144;,
 4;113,147,148,29;,
 4;149,150,137,136;,
 4;151,29,22,138;,
 4;27,26,151,138;,
 4;120,125,21,121;,
 4;110,109,152,153;,
 4;133,110,154,134;,
 4;132,141,110,133;;
 
 MeshMaterialList {
  1;
  91;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.588000;0.588000;0.588000;1.000000;;
   2.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  120;
  0.378244;-0.878413;0.292100;,
  -0.006347;-0.869862;0.493254;,
  0.324450;-0.815770;0.478802;,
  0.042201;-0.965665;0.256341;,
  -0.229836;-0.952715;0.198771;,
  -0.165469;-0.937302;0.306733;,
  -0.355398;-0.923311;0.145562;,
  -0.491622;-0.867259;0.078550;,
  0.621634;-0.435370;0.651171;,
  0.146423;-0.979585;0.137746;,
  -0.190178;-0.974951;0.115339;,
  -0.577884;-0.813931;-0.059722;,
  0.750929;-0.660066;0.020437;,
  0.508824;-0.178139;0.842238;,
  0.961290;-0.179592;0.208971;,
  0.957446;0.287943;-0.019645;,
  0.321668;-0.635646;0.701771;,
  0.143315;-0.397859;0.906184;,
  -0.156913;0.854183;0.495730;,
  -0.069975;-0.789154;0.610196;,
  -0.275867;-0.823385;0.495918;,
  0.976544;-0.172234;0.129221;,
  -0.023326;-0.763446;0.645450;,
  0.207273;-0.716467;0.666118;,
  -0.252702;-0.825260;0.505062;,
  -0.058962;-0.841097;0.537662;,
  -0.323194;-0.915601;0.239209;,
  -0.209172;-0.923184;0.322458;,
  -0.866195;-0.451306;-0.214543;,
  -0.599223;-0.800561;0.005863;,
  -0.094103;0.739171;0.666911;,
  0.820382;0.570661;0.036322;,
  0.433798;-0.828141;0.354968;,
  -0.872752;-0.455395;-0.175839;,
  -0.448707;-0.889367;0.087684;,
  -0.220864;-0.952512;0.209620;,
  0.009884;-0.957866;0.287046;,
  -0.840402;0.361517;-0.403770;,
  -0.031633;0.998602;0.042345;,
  -0.126997;0.974721;0.183822;,
  -0.298170;-0.805746;0.511730;,
  -0.456058;0.704165;0.544209;,
  0.028162;-0.835945;0.548090;,
  0.276176;-0.716694;0.640372;,
  -0.162303;0.979042;0.123024;,
  -0.401521;-0.880566;0.251761;,
  -0.262730;0.542539;0.797887;,
  -0.116867;-0.932378;0.342073;,
  -0.006462;-0.828146;0.560475;,
  -0.203125;-0.673240;0.710976;,
  -0.427005;-0.757046;0.494518;,
  0.529911;0.730241;0.431211;,
  -0.898510;0.081267;-0.431364;,
  -0.893560;-0.418224;-0.163214;,
  -0.814628;0.387995;-0.431093;,
  -0.827383;0.374599;-0.418466;,
  0.363534;0.918585;0.155065;,
  -0.406574;-0.844856;0.347730;,
  -0.226653;-0.836792;0.498405;,
  0.112385;0.968184;0.223585;,
  -0.053887;0.991288;-0.120186;,
  -0.344459;0.887351;-0.306524;,
  -0.854957;0.376628;-0.356649;,
  -0.128584;0.987190;-0.094457;,
  -0.417118;0.872186;-0.255546;,
  0.854865;-0.363436;-0.370298;,
  0.844212;0.138445;-0.517822;,
  0.177872;0.962839;-0.203231;,
  -0.798739;0.444636;-0.405358;,
  -0.415967;0.909320;-0.010397;,
  -0.325729;0.923874;0.200892;,
  -0.234378;0.917738;-0.320662;,
  0.034399;0.776405;-0.629295;,
  -0.376094;0.755353;-0.536652;,
  0.308344;0.812985;-0.493942;,
  -0.111047;0.989464;-0.092889;,
  0.033843;0.994253;-0.101569;,
  -0.313221;0.945782;0.085957;,
  -0.109191;0.978956;0.172400;,
  0.835529;-0.545883;-0.062475;,
  0.867570;-0.494236;0.055246;,
  0.859523;-0.298701;0.414727;,
  0.654647;-0.752404;-0.072977;,
  0.517791;-0.851016;0.087548;,
  -0.633259;-0.753765;-0.175563;,
  -0.147828;-0.988713;0.024343;,
  0.223531;-0.974498;0.019669;,
  -0.836356;0.104874;-0.538061;,
  0.895264;0.167031;0.413040;,
  -0.224193;0.853055;0.471205;,
  -0.351080;0.926561;-0.135011;,
  -0.308931;0.880665;-0.359153;,
  -0.305489;0.848321;-0.432466;,
  0.736996;-0.619691;0.269853;,
  -0.608398;0.588095;-0.532913;,
  -0.196185;0.975257;-0.101913;,
  0.825750;0.156292;-0.541950;,
  0.227776;0.730577;-0.643719;,
  0.931862;-0.315575;-0.179013;,
  0.884163;-0.385434;-0.264000;,
  -0.603650;0.497301;-0.623136;,
  -0.388098;0.840324;-0.378464;,
  -0.433869;0.858516;-0.273328;,
  0.766849;-0.592058;0.247811;,
  -0.102582;0.389623;0.915244;,
  -0.541978;0.388613;0.745144;,
  -0.907593;0.156678;-0.389522;,
  -0.366526;0.240611;0.898757;,
  0.117629;0.984257;-0.131918;,
  -0.606476;-0.762119;0.226631;,
  0.622412;0.440093;0.647241;,
  -0.648373;0.655489;-0.387230;,
  -0.646746;0.642555;-0.410905;,
  0.113095;0.972294;0.204582;,
  -0.143983;0.778512;0.610891;,
  -0.629239;-0.775112;-0.057094;,
  -0.246499;0.627472;0.738592;,
  0.553911;0.567937;-0.608795;,
  0.472763;0.518496;-0.712500;,
  -0.830060;-0.438613;-0.344410;;
  91;
  4;36,32,2,1;,
  4;1,5,35,36;,
  4;5,6,34,35;,
  4;26,27,6,5;,
  4;13,88,81,8;,
  4;3,9,83,0;,
  4;4,10,9,3;,
  4;7,11,10,4;,
  4;80,12,16,8;,
  4;8,16,17,13;,
  4;99,79,83,82;,
  4;80,66,65,12;,
  4;20,19,22,2;,
  4;14,21,103,2;,
  4;2,22,23,1;,
  4;19,43,23,22;,
  4;1,23,43,42;,
  4;42,40,24,1;,
  4;5,1,24,25;,
  4;5,25,48,47;,
  4;40,48,25,24;,
  4;47,45,26,5;,
  4;45,58,27,26;,
  4;58,57,6,27;,
  4;6,28,33,34;,
  4;57,53,28,6;,
  4;104,104,30,30;,
  4;38,44,30,30;,
  4;105,41,41,105;,
  4;29,7,34,33;,
  4;7,4,35,34;,
  4;4,3,36,35;,
  4;28,37,62,33;,
  4;53,55,37,28;,
  4;33,62,68,106;,
  4;107,107,46,46;,
  4;14,31,15,21;,
  4;108,76,38,108;,
  4;76,75,44,38;,
  4;39,41,41,44;,
  4;54,55,53,52;,
  4;53,57,50,109;,
  4;57,58,49,50;,
  4;51,51,110,110;,
  4;59,56,51,51;,
  4;55,54,111,112;,
  4;46,39,59,46;,
  4;44,75,60,39;,
  4;39,60,61,59;,
  4;37,55,112,61;,
  4;113,114,89,78;,
  4;60,63,64,61;,
  4;61,64,62,37;,
  4;18,67,70,89;,
  4;77,78,89,70;,
  4;95,69,91,71;,
  4;66,96,97,74;,
  4;77,70,90,69;,
  4;76,78,77,75;,
  4;77,63,60,75;,
  4;78,76,31,113;,
  4;36,3,0,32;,
  4;81,32,0,93;,
  4;14,2,32,81;,
  4;83,79,93,0;,
  4;100,87,94,73;,
  4;85,10,11,84;,
  4;86,9,10,85;,
  4;82,83,9,86;,
  4;115,11,7,29;,
  4;116,18,89,114;,
  4;88,31,14,81;,
  4;90,92,91,69;,
  4;81,93,80,8;,
  4;102,101,94,68;,
  4;92,97,72,91;,
  4;79,98,80,93;,
  4;94,87,106,68;,
  4;95,63,77,69;,
  4;102,64,63,95;,
  4;68,62,64,102;,
  4;67,74,90,70;,
  4;74,97,92,90;,
  4;74,67,117,66;,
  4;96,118,72,97;,
  4;96,66,80,98;,
  4;79,99,96,98;,
  4;119,84,11,87;,
  4;71,91,72,73;,
  4;101,71,73,94;,
  4;102,95,71,101;;
 }
 MeshTextureCoords {
  155;
  0.000000;0.475161;,
  1.000000;0.507243;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.470941;,
  0.000000;0.000000;,
  0.000000;0.476424;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.907229;,
  1.000000;0.795517;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.433594;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.394878;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.619676;0.000000;,
  0.622674;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.215995;0.000000;,
  0.396644;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.466057;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.621026;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.466057;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.806934;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.162203;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.410733;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.209760;,
  1.000000;1.238640;,
  1.000000;0.602062;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.748977;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.299561;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.464171;,
  1.000000;1.720240;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.741313;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.411220;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;-0.528682;,
  1.000000;0.978746;;
 }
}