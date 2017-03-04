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
 42;
 0.00000;-2.06543;1.60334;,
 -0.72842;-0.09019;3.46409;,
 -2.73774;-0.55695;3.68447;,
 -2.02044;-2.98695;1.67526;,
 -0.35184;-0.41071;0.04132;,
 -1.23065;0.98676;1.65767;,
 -4.58788;-0.07329;2.61092;,
 -3.99073;-2.19260;0.83421;,
 -3.61125;0.90698;1.14711;,
 -3.21010;-0.75316;-0.26640;,
 -0.88565;0.55241;3.88005;,
 -2.91656;0.06895;4.20121;,
 -1.42854;1.54441;2.10220;,
 -4.70584;0.59233;3.17231;,
 -3.86449;1.52216;1.64403;,
 -0.98904;1.13512;4.23990;,
 -3.03047;0.64045;4.50823;,
 -1.53059;2.10382;2.57913;,
 -4.74896;1.30872;3.41584;,
 -3.89301;2.12363;2.15981;,
 -1.40430;2.96023;5.01979;,
 -3.24168;1.72640;5.03611;,
 -1.83966;3.75647;3.90739;,
 -4.95346;2.71366;4.45015;,
 -4.38439;3.60170;3.36092;,
 -2.83400;5.55417;5.44074;,
 -2.12109;4.84254;6.32466;,
 -5.17768;4.71392;5.78920;,
 -4.58195;5.35585;5.19562;,
 -3.60265;5.93866;5.20980;,
 -2.87228;4.18420;3.09670;,
 -2.69431;2.35505;1.99747;,
 -2.57328;1.81811;1.54997;,
 -2.43417;1.19829;1.03553;,
 -1.89545;-0.02666;-0.44117;,
 -3.84135;5.40604;6.62184;,
 -3.44390;2.79982;5.51948;,
 -4.51574;3.17361;5.34292;,
 -2.36658;3.38865;5.70105;,
 -3.93333;5.35992;7.21576;,
 -4.78957;5.17615;6.64488;,
 -2.89815;5.24576;6.98200;;
 
 38;
 4;0,1,2,3;,
 4;4,5,1,0;,
 4;3,2,6,7;,
 4;7,6,8,9;,
 4;1,10,11,2;,
 4;5,12,10,1;,
 4;2,11,13,6;,
 4;6,13,14,8;,
 4;10,15,16,11;,
 4;12,17,15,10;,
 4;11,16,18,13;,
 4;13,18,19,14;,
 4;15,20,21,16;,
 4;17,22,20,15;,
 4;16,21,23,18;,
 4;18,23,24,19;,
 4;22,25,26,20;,
 4;23,27,28,24;,
 4;29,30,24,28;,
 4;31,19,24,30;,
 4;32,14,19,31;,
 4;33,8,14,32;,
 4;34,9,8,33;,
 4;29,35,26,25;,
 4;23,21,36,37;,
 4;36,21,20,38;,
 4;39,35,27,40;,
 4;39,36,38,41;,
 4;40,37,36,39;,
 4;40,27,23,37;,
 4;20,26,41,38;,
 4;22,30,29,25;,
 4;17,31,30,22;,
 4;12,32,31,17;,
 4;5,33,32,12;,
 4;4,34,33,5;,
 4;27,35,29,28;,
 4;26,35,39,41;;
 
 MeshMaterialList {
  1;
  38;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  58;
  0.259547;-0.588573;0.765648;,
  -0.133768;-0.664701;0.735037;,
  0.725767;0.646037;-0.236428;,
  -0.505489;-0.633527;0.585769;,
  0.246775;-0.561393;0.789899;,
  -0.143326;-0.644941;0.750672;,
  0.743694;0.590588;-0.313250;,
  -0.510152;-0.624901;0.590969;,
  -0.651899;0.413585;-0.635591;,
  -0.628912;0.402911;-0.664930;,
  0.233599;-0.493513;0.837780;,
  -0.168823;-0.545260;0.821091;,
  0.759001;0.510663;-0.403906;,
  -0.546289;-0.506390;0.667186;,
  -0.606184;0.421553;-0.674414;,
  0.228591;-0.409328;0.883287;,
  -0.186525;-0.467306;0.864195;,
  0.781945;0.460580;-0.420034;,
  -0.569134;-0.442952;0.692734;,
  -0.623522;0.400647;-0.671344;,
  0.286039;-0.414848;0.863761;,
  -0.156448;-0.520741;0.839257;,
  0.769793;0.532587;-0.351809;,
  -0.568440;-0.523503;0.634682;,
  -0.654834;0.418034;-0.629635;,
  0.644912;0.762066;-0.057818;,
  0.511896;0.856367;0.067804;,
  -0.628400;0.767741;-0.125248;,
  -0.685690;0.656587;-0.314201;,
  0.105023;0.776458;-0.621356;,
  0.134277;0.679164;-0.721600;,
  0.145106;0.617406;-0.773146;,
  0.129102;0.653663;-0.745693;,
  0.077201;0.702601;-0.707384;,
  0.025031;0.753060;-0.657476;,
  -0.066145;0.992256;0.105136;,
  -0.497347;-0.546870;0.673483;,
  -0.114639;-0.561672;0.819379;,
  0.258786;-0.471642;0.842961;,
  -0.235988;0.955835;-0.175183;,
  -0.019242;0.990856;-0.133543;,
  0.285274;-0.479454;0.829905;,
  0.934919;0.354848;-0.002998;,
  0.925384;0.371807;0.073653;,
  -0.878092;0.153263;-0.453282;,
  -0.879345;0.137292;-0.455963;,
  0.945585;0.305632;-0.111614;,
  -0.884184;0.159722;-0.438984;,
  0.948060;0.282137;-0.146903;,
  -0.888709;0.164552;-0.427924;,
  0.908573;0.394563;-0.137166;,
  -0.886337;0.192881;-0.420956;,
  -0.112656;0.927148;0.357358;,
  -0.105807;-0.559917;0.821765;,
  -0.526341;-0.516928;0.675093;,
  -0.685628;-0.458471;0.565436;,
  0.423313;-0.416561;0.804539;,
  0.198466;0.976395;-0.085233;;
  38;
  4;0,4,5,1;,
  4;2,6,42,43;,
  4;1,5,7,3;,
  4;44,45,9,8;,
  4;4,10,11,5;,
  4;6,12,46,42;,
  4;5,11,13,7;,
  4;45,47,14,9;,
  4;10,15,16,11;,
  4;12,17,48,46;,
  4;11,16,18,13;,
  4;47,49,19,14;,
  4;15,20,21,16;,
  4;17,22,50,48;,
  4;16,21,23,18;,
  4;49,51,24,19;,
  4;22,25,26,50;,
  4;51,27,28,24;,
  4;29,30,24,28;,
  4;31,19,24,30;,
  4;32,14,19,31;,
  4;33,9,14,32;,
  4;34,8,9,33;,
  4;52,35,26,25;,
  4;23,21,37,36;,
  4;37,21,20,38;,
  4;40,35,27,39;,
  4;53,37,38,41;,
  4;54,36,37,53;,
  4;54,55,23,36;,
  4;20,56,41,38;,
  4;22,30,29,25;,
  4;17,31,30,22;,
  4;12,32,31,17;,
  4;6,33,32,12;,
  4;2,34,33,6;,
  4;27,35,52,28;,
  4;26,35,40,57;;
 }
 MeshTextureCoords {
  42;
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
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;;
 }
}
