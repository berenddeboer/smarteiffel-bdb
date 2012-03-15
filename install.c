#ifdef __cplusplus
extern"C"{
#endif
#ifdef __cplusplus
}
#endif
#include"install.h"
#ifdef __cplusplus
extern"C"{
#endif
void Ze(const Z7*src,Z7*Zf,int Zg){while(Zg--){*Zf++=(*src<<8)|(*src>>8);src++;}}void*Zh(Zi Zj){void*Zm=Zn(Zj);if(Zm==Zo){
#ifdef SE_EXCEPTIONS
Zp(Zq);
#elif !defined(SE_BOOST)
Zr("No more memory.",Zo);
#else
Zs(Zt,"No more memory.\n");Zu();Zv(Zw);
#endif
}return Zm;}void*Zk(Zi Zl,Zi Zj){void*Zm=Zx(Zl,Zj);if(Zm==Zo){
#ifdef SE_EXCEPTIONS
Zp(Zq);
#elif !defined(SE_BOOST)
Zr("No more memory.",Zo);
#else
Zs(Zt,"No more memory.\n");Zu();Zv(Zw);
#endif
}return Zm;}void*Zy(void*src,Zi Zj){void*Zm=Zz(src,Zj);if(Zm==Zo){
#ifdef SE_EXCEPTIONS
Zp(Zq);
#elif !defined(SE_BOOST)
Zr("No more memory.",Zo);
#else
Zs(Zt,"No more memory.\n");Zu();Zv(Zw);
#endif
}return Zm;}int ZT(T74 o1,T74 o2){return ZU(&o1,&o2,sizeof(o1));}int ZX(T92 o1,T92 o2){return ZU(&o1,&o2,sizeof(o1));}int Z_(T48 o1,T48
o2){return ZU(&o1,&o2,sizeof(o1));}T74 M74={Zo,Zo,0};T22 M22=Zo;T54 M54=0;T62 M62={62,Zo,0,0,0,Zo,0,Zo};T81 M81=Zo;T83 M83={0};T86 M86=0;
T85 M85={Zo,0,0,0,Zo,0};T37 M37={0,0,0,Zo,0,0,0,0};T82 M82={Zo,Zo};T91 M91={{Zo,Zo,0},Zo};T67 M67={Zo,Zo,Zo};ZD Zn1={Zo,0,0};T73 M73={0,0,0};
T12 M12={{Zo,Zo},Zo,0,0,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,0,0};ZH ZQ1={Zo,0,0,0};T75 M75={Zo,0,0};T34 M34=0;T47
M47={47,Zo,0,0};T49 M49={0};T55 M55={Zo,0,0,0,Zo,Zo,0,0,0,0};T92 M92={{Zo,Zo,0},Zo};T38 M38={Zo,Zo,Zo,Zo,Zo,0,Zo,Zo,{Zo,Zo},0,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo};
T87 M87={0,Zo,Zo};T70 M70={70,Zo,0};T7 M7={Zo,0,0};ZJ Z92={110,Zo,0};T96 M96={Zo,0,0};T48 M48={Zo,Zo};T84 M84={0,0,0};T35 M35=0;T66 M66={66,Zo,0,0,0,Zo,0};
T72 M72={Zo,Zo,0,Zo};T45 M45={Zo,0,{Zo,Zo},Zo};T99 M99={Zo,0,0};T53 M53={0};T95 M95={Zo,0,0,Zo,Zo};T51 M51={0,0,Zo,0,Zo,0,0,0,{{Zo,Zo,0},Zo},Zo,0,Zo,Zo,Zo,Zo,Zo};
ZF ZT2={Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,0,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,0,0};ZB ZU2={Zo,Zo,Zo};T42 M42={42,Zo,0,0,0};T61 M61={Zo,0,0,0,Zo};
T89 M89=Zo;T64 M64={Zo,Zo,Zo};T36 M36={Zo,Zo,0,0,0};ZL ZZ2={Zo,Zo,0,0,Zo};T93 M93={{Zo,Zo,0},0,0,Zo};T31 M31={0,Zo,0};T50 M50=Zo;char*Z23="";
char*Z33=".";char*Z43="compile_to_c";char*Z53="@";char*Z63="Cygwin";char*Z73=" (";char*Z83="\n---------------------------------------------------------------------------\n\n";
char*Z93=".\n";char*Za3=", ";char*Zb3="..";char*Zc3=": ";char*Zd3=".c";char*Ze3="-s";char*Zf3="-pipe -O2";char*Zg3="UNIX";char*Zh3="Windows";
char*Zi3="install";char*Zj3="\\SE.CFG";char*Zk3="\".\n";char*Zl3="/etc/serc";char*Zm3="                ";char*Zn3="Please enter a number between 1 and 7.\n";
char*Zo3="cc/warning=disable=(embedcomment,longextern) ";char*Zp3="-x none";char*Zq3="Amiga";char*Zr3="DOS";char*Zs3="short";char*Zt3="-pipe";
char*Zu3="OS2";char*Zv3="/.serc";char*Zw3="]: ";char*Zx3="-x c";char*Zy3="SmartEiffel options";char*Zz3="/fe=";char*ZA3="...This is a local once buffer...";
char*ZB3="bin";char*ZC3="OpenVMS";char*ZD3="\n\n---------------------------------------------------------------------------\n\n";char*ZE3="SmartEiffel";
char*ZF3=" key.\n\n";char*ZG3="sys";char*ZH3="undefined";char*ZI3="Elate";char*ZJ3="C:\\SE.CFG";char*ZK3="/sys/rc";char*ZL3="compile";
char*ZM3="clean";char*ZN3=" /link";char*ZO3="\nThe RC file ";char*ZP3="BeOS";char*ZQ3="-x \'c++\'";char*ZR3="*** This file does not exist or is not readable.\n";
char*ZS3="Macintosh";char*ZT3="\n*** Please enter a number between 1 and ";char*ZU3=" -o ";char*ZV3="/lang/eiffel/.serc";void Zu(void){
Zs(Zt,"Eiffel program crash at run time.\n");Zs(Zt,"No trace when using option \"-boost\"\n");}void ZW3(int sig){ZX3("Received signal %d.\n",sig);
Zu();Zv(Zw);}
#ifdef WIN32
#define SIMULATED_MODE
typedef struct Zc4{Zd4 Ze4;Zf4 Zg4;int Zh4;char*Zi4;}Zj4;static Zj4*Zk4(char*Z_3){int len=Zl4((char*)Z_3);char*Zi4=Zh(len+5);Zj4*Zm=Zh(sizeof(Zj4));
Zi4=Zm4(Zi4,(char*)Z_3);if(Zi4[len-1]!='\\')Zi4[len++]='\\';Zi4[len++]='*';Zi4[len++]='.';Zi4[len++]='*';Zi4[len++]=0;Zm->Ze4=Zn4(Zi4,&(Zm->Zg4));
if(Zm->Ze4==Zo4){Zp4(Zi4);Zp4(Zm);return Zo;}else{Zm->Zi4=Zi4;}Zm->Zh4=0;return Zm;}static void*Zq4(Zj4*Z14){if(Z14->Zh4){if(Zr4(Z14->Ze4,&(Z14->Zg4))){
Z14->Zh4=1;return Z14;}else{return Zo;}}else{Z14->Zh4=1;return Z14;}}
#define simulated_get_entry_name(x) ((x)->data.cFileName)
static int Zs4(Zj4*Z14){Zt4(Z14->Ze4);Zp4(Z14->Zi4);Zp4(Z14);return 0;}char*Zu4(char*Zv4,int Zw4);int Zx4(const char*Zv4);int Zy4(const
char*Za4);int Zz4(const char*Za4);
#define simulated_getcwd(x, y) getcwd(x, y)
#define simulated_chdir(x) chdir(x)
#define simulated_rmdir(x) rmdir(x)
int ZA4(const char*Za4,int ZB4){Zy4(Za4);return 0;}
#endif
#ifdef AMIGA
#define SIMULATED_MODE
#include <exec/types.h>
#include <dos/dos.h>
#include <dos/dostags.h>
#include <proto/exec.h>
#include <proto/dos.h>
typedef struct Zc4{struct ZC4*ZD4;ZE4 ZF4;}Zj4;static void ZG4(Zj4*dir){if(dir!=Zo){if(dir->ZF4!=Zo){ZH4(dir->ZF4);}if(dir->ZD4!=Zo){
ZI4(ZJ4,dir->ZD4);}Zp4(dir);}}static Zj4*Zk4(char*Z_3){ZK4 ok=ZL4;Zj4*Zm=Zh(sizeof(Zj4));if(Zm!=Zo){Zm->ZF4=Zo;Zm->ZD4=(struct ZC4*)ZM4(ZJ4,Zo);
if(Zm->ZD4!=Zo){Zm->ZF4=ZN4(Z_3,ZO4);if(Zm->ZF4!=Zo){ok=(ZP4(Zm->ZF4,Zm->ZD4)!=ZQ4);if(ok){ok=(Zm->ZD4->ZR4>=0)&&(Zm->ZD4->ZR4!=ZS4);
}}}}if(!ok){ZG4(Zm);Zm=Zo;}return Zm;}static void*Zq4(Zj4*Z14){ZK4 ok;Zj4*Zm=Zo;ok=(ZT4(Z14->ZF4,Z14->ZD4)!=ZQ4);if(ok){Zm=Z14;}return(void*)Zm;
}
#define simulated_get_entry_name(entry) ((entry)->info->fib_FileName)
static int Zs4(Zj4*Z14){ZG4(Z14);return 0;}static ZZ3 ZU4(char*Zv4,Zi ZV4){ZZ3 Zm=Zo;ZE4 ZF4=ZN4("",ZO4);if(ZF4!=Zo){if(ZW4(ZF4,Zv4,ZV4)!=ZQ4){
Zm=(ZZ3)Zv4;}ZH4(ZF4);}return Zm;}static int ZX4(char*ZY4){int Zm=-1;ZE4 ZF4=ZN4(ZY4,ZO4);if(ZF4!=Zo){ZE4 ZZ4=Z_4(ZF4);if(Z05(ZY4)){ZH4(ZZ4);
Zm=0;}else{Z_4(ZZ4);}}return Zm;}static void Z15(char*Z_3,Zi*Z25,ZK4*Z35){*Z25=Zl4(Z_3);if((*Z25>0)&&(Z_3[*Z25-1]=='/')){*Z35=Z45;Z_3[*Z25-1]='\0';
}else{*Z35=ZL4;}}static void Z55(char*Z_3,Zi*Z25,ZK4*Z35){if(*Z35){Z_3[*Z25-1]='/';}}static int ZA4(char*Za4,int Z65){ZE4 ZF4;int Zm=-1;
Zi Z75;ZK4 Z85;Z15(Za4,&Z75,&Z85);ZF4=Z95(Za4);if(ZF4!=Zo){ZH4(ZF4);Zm=0;}Z55(Za4,&Z75,&Z85);return Zm;}static int Za5(char*Za4){int Zm=-1;
Zi Z75;ZK4 Z85;Z15(Za4,&Z75,&Z85);if(Zb5(Za4)){Zm=0;}Z55(Za4,&Z75,&Z85);return Zm;}
#endif
ZZ3 ZY3(ZZ3 Z_3){
#ifndef SIMULATED_MODE
return(Zc5(((char*)Z_3)));
#else
return(Zk4(((char*)Z_3)));
#endif
}ZZ3 Z04(ZZ3 Z14){
#ifndef SIMULATED_MODE
return Zd5((DIR*)Z14);
#else
return Zq4((Zj4*)Z14);
#endif
}ZZ3 Z24(ZZ3 Z34){
#ifndef SIMULATED_MODE
return(((struct Ze5*)Z34)->Zf5);
#else
return Zg5((Zj4*)Z34);
#endif
}Z44 Z54(ZZ3 Z14){int Zh5;
#ifndef SIMULATED_MODE
Zh5=(Zi5((DIR*)Z14)==0);
#else
Zh5=(Zs4((Zj4*)Z14)==0);
#endif
return((Z44)(Zh5?1:0));}ZZ3 Z64(void){static char*buf=Zo;
#ifdef WIN32
static int Zj=0;
#else
static Zi Zj=0;
#endif
int Zh5;if(buf==Zo){Zj=256;buf=(char*)Zh(Zj);}
#ifndef SIMULATED_MODE
Zh5=(Zu4(buf,Zj)!=Zo);
#else
Zh5=(ZU4(buf,Zj)!=Zo);
#endif
if(Zh5){return buf;}else{Zp4(buf);Zj=Zj*2;buf=(char*)Zh(Zj);return Z64();}}Z44 Z74(ZZ3 Z84){int Zh5;
#ifndef SIMULATED_MODE
Zh5=(Zx4((char*)Z84));
#else
Zh5=ZX4((char*)Z84);
#endif
return((Z44)(Zh5==0?1:0));}Z44 Z94(ZZ3 Za4){int Zh5;
#ifndef SIMULATED_MODE
Zh5=(Zy4((char*)Za4,0777));
#else
Zh5=ZA4((char*)Za4,0777);
#endif
return((Z44)(Zh5==0?1:0));}Z44 Zb4(ZZ3 Za4){int Zh5;
#ifndef SIMULATED_MODE
Zh5=Zz4((char*)Za4);
#else
Zh5=Za5((char*)Za4);
#endif
return((Z44)(Zh5==0?1:0));}
#if defined __USE_POSIX || defined __unix__ || defined _POSIX_C_SOURCE
#else
int Zj5(char*Zv4,int Zj){int c;c=Zk5(Zl5);if(c==EOF)return 0;*Zv4=(char)c;return 1;}
#endif
void Zm5(ZZ3 Zn5,ZZ3 Zo5){Zi Zp5=Zl4((char*)Zn5);Zi Zq5=Zl4((char*)Zo5);char*v;v=Zh(Zp5+Zq5+2);Zr5(v,((char*)Zn5),Zp5);v[Zp5]='=';Zr5(v+Zp5+1,((char*)Zo5),Zq5);
v[Zp5+1+Zq5]='\0';Zs5(v);}T6 Zt5(T8 C){T6 R=0;R=((T6)(!((Zo!=C))));return R;}T6 Zu5(T6 C,T6 a1){T6 R=0;R=((T6)((T6)((C)&&((T6)(a1)))));
return R;}T6 Zv5(T6 C){T6 R=0;R=((T6)((C)==(0)));return R;}T6 Zw5(T3 C){T6 R=0;if((((unsigned)((C)))>=((unsigned)(((T3)'0'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'9'))))));
}return R;}T6 Zx5(T3 C){T6 R=0;{int z1=(C);switch(z1){case 0:case 9:case 10:case 12:case 13:case 32:R=((T6)(1));break;}}return R;}T6 Zy5(T3
C){T6 R=0;if(Zw5(C)){R=((T6)(1));}else if((((unsigned)((C)))>=((unsigned)(((T3)'a'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'f'))))));
}else if((((unsigned)((C)))>=((unsigned)(((T3)'A'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'F'))))));}return R;}T6 Zz5(T3 C){
T6 R=0;if((((unsigned)((C)))>=((unsigned)(((T3)'0'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'9'))))));}return R;}T6 ZA5(T3 C,T3
a1){T6 R=0;R=((T6)((Z2)((ZB5(C))<=(ZB5(a1)))));return R;}T1 ZC5(T3 C){T1 R=0;R=(Z1)(((((ZD5)(ZB5(C)))))-(ZE5(48)));return R;}T6 ZF5(T3
C){T6 R=0;if((((unsigned)((C)))>=((unsigned)(((T3)'a'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'z'))))));}else if((((unsigned)((C)))>=((unsigned)(((T3)'A'))))){
R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'Z'))))));}return R;}T6 ZG5(T3 C,T3 a1){T6 R=0;if(((C))==(a1)){R=((T6)(1));}else{{int z1=ZB5(C);
switch(z1){case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case
80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:R=((T6)((ZB5(C))==((Z2)(((ZB5(a1)))-(ZE5(32))))));
break;case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case
111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:R=((T6)((ZB5(C))==((Z2)(((ZB5(a1)))+(ZE5(32))))));
break;}}}return R;}T1 ZH5(T3 C){T1 R=0;R=(Z1)(((((ZD5)(ZB5(C)))))-(ZE5(48)));return R;}T3 ZI5(T3 C){T3 R=0;if((Z2)((ZB5(C))<(ZE5(97)))){
R=(C);}else if((Z2)((ZB5(C))>(ZE5(122)))){R=(C);}else{R=((T3)((Z2)(((ZB5(C)))-(ZE5(32)))));}return R;}T6 ZJ5(T3 C,T3 a1){T6 R=0;R=((T6)((Z2)((ZB5(C))>=(ZB5(a1)))));
return R;}T3 ZK5(T3 C){T3 R=0;if((Z2)((ZB5(C))<(ZE5(65)))){R=(C);}else if((Z2)((ZB5(C))>(ZE5(90)))){R=(C);}else{R=((T3)((Z2)(((ZB5(C)))+(ZE5(32)))));
}return R;}T1 ZL5(T3 C){T1 R=0;R=((ZD5)(ZB5(C)));if((Z2)((ZB5(C))<(ZB5(((T3)'A'))))){R=(Z1)(((R))-(ZE5(48)));}else if((Z2)((ZB5(C))<(ZB5(((T3)'a'))))){
R=(Z1)(((R))-(ZE5(55)));}else{R=(Z1)(((R))-(ZE5(87)));}return R;}T3 ZM5(T1 C){T3 R=0;R=((T3)((Z2)((((T10)((C))))+(ZB5(((T3)'0'))))));
return R;}void ZN5(T1 C,T0*a1){T1 ZO5=0;T2 _i=0;T2 ZP5=0;if(((C))==(ZE5(0))){ZQ5(((T7*)a1),((T3)'0'));}else{if((Z1)(((C))>(ZE5(0)))){
_i=(Z3)(((((((T7*)a1))->Z21)))+(ZE5(1)));ZO5=(C);while(!((ZO5)==(ZE5(0)))){ZQ5(((T7*)a1),ZM5((Z1)((ZO5)%(ZE5(10)))));ZO5=(Z1)((ZO5)/(ZE5(10)));
}}else{ZQ5(((T7*)a1),((T3)'\055'));_i=(Z3)(((((((T7*)a1))->Z21)))+(ZE5(1)));ZO5=(C);while(!((ZO5)==(ZE5(0)))){ZQ5(((T7*)a1),ZM5(-((Z1)((ZO5)%(ZE5(10))))));
ZO5=(Z1)((ZO5)/(ZE5(10)));}}ZP5=((((T7*)a1))->Z21);while(!((Z3)((_i)>=(ZP5)))){ZR5(((T7*)a1),_i,ZP5);ZP5=(Z3)(((ZP5))-(ZE5(1)));_i=(Z3)(((_i))+(ZE5(1)));
}}}T6 ZS5(T2 C,T1 a1){T6 R=0;R=((T6)((((((C))>>(a1))&ZE5(1)))!=(ZE5(0))));return R;}T2 ZT5(T2 C,T2 a1){T2 R=0;if((Z3)((C)>=(a1))){R=C;
}else{R=a1;}return R;}T6 ZU5(T2 C,T2 a1,T2 a2){T6 R=0;R=((T6)((T6)(((Z3)((C)>=(a1)))&&((T6)((Z3)((C)<=(a2)))))));return R;}T2 ZV5(T2 C,T2
a1){T2 R=0;if((Z3)((C)<=(a1))){R=C;}else{R=a1;}return R;}T6 ZW5(T2 C){T6 R=0;R=((T6)((((C)&ZE5(1)))!=(ZE5(0))));return R;}T3 ZX5(T2 C){
T3 R=0;R=((T3)((Z3)((((C)))+((T2)(ZB5(((T3)'0')))))));return R;}void ZY5(T2 C,T0*a1){T2 ZO5=0;T2 _i=0;T2 ZP5=0;if(((C))==(ZE5(0))){ZQ5(((T7*)a1),((T3)'0'));
}else{if((Z3)(((C))>(ZE5(0)))){_i=(Z3)(((((((T7*)a1))->Z21)))+(ZE5(1)));ZO5=(C);while(!((ZO5)==(ZE5(0)))){ZQ5(((T7*)a1),ZX5((Z3)((ZO5)%((T2)(ZE5(10))))));
ZO5=(Z3)((ZO5)/(ZE5(10)));}}else{ZQ5(((T7*)a1),((T3)'\055'));_i=(Z3)(((((((T7*)a1))->Z21)))+(ZE5(1)));ZO5=(C);while(!((ZO5)==(ZE5(0))))
{ZQ5(((T7*)a1),ZX5(-((Z3)((ZO5)%((T2)(ZE5(10)))))));ZO5=(Z3)((ZO5)/(ZE5(10)));}}ZP5=((((T7*)a1))->Z21);while(!((Z3)((_i)>=(ZP5)))){ZR5(((T7*)a1),_i,ZP5);
ZP5=(Z3)(((ZP5))-(ZE5(1)));_i=(Z3)(((_i))+(ZE5(1)));}}}T6 ZZ5(T2 C){T6 R=0;R=((T6)((((C)&ZE5(1)))==(ZE5(0))));return R;}T3 Z_5(T11 C){
T3 R=0;R=((T3)((Z5)((((C)))+((T11)(ZB5(((T3)'0')))))));return R;}void Z06(T11 C,T0*a1){T11 ZO5=0;T2 _i=0;T2 ZP5=0;if(((C))==(ZE5(0))){
ZQ5(((T7*)a1),((T3)'0'));}else{if((Z5)(((C))>(ZE5(0)))){_i=(Z3)(((((((T7*)a1))->Z21)))+(ZE5(1)));ZO5=(C);while(!((ZO5)==(ZE5(0)))){ZQ5(((T7*)a1),Z_5((Z5)((ZO5)%((T11)(ZE5(10))))));
ZO5=(Z5)((ZO5)/(ZE5(10)));}}else{ZQ5(((T7*)a1),((T3)'\055'));_i=(Z3)(((((((T7*)a1))->Z21)))+(ZE5(1)));ZO5=(C);while(!((ZO5)==(ZE5(0))))
{ZQ5(((T7*)a1),Z_5(-((Z5)((ZO5)%((T11)(ZE5(10)))))));ZO5=(Z5)((ZO5)/(ZE5(10)));}}ZP5=((((T7*)a1))->Z21);while(!((Z3)((_i)>=(ZP5)))){ZR5(((T7*)a1),_i,ZP5);
ZP5=(Z3)(((ZP5))-(ZE5(1)));_i=(Z3)(((_i))+(ZE5(1)));}}}T10 Z16(T10 C,T10 a1){T10 R=0;if((Z2)((C)>=(a1))){R=C;}else{R=a1;}return R;}ZO
Z26(ZO C,T2 a1,T2 a2){ZO R=Zo;R=((ZO)(Zk(a2,sizeof(T0*))));Z36(R,C,(Z3)(((a1))-((T2)(ZE5(1)))));return R;}void Z46(ZO C,T2 a1){T2 _i=0;
while(!((_i)==(a1))){(C)[_i]=((C)[(Z3)(((_i))+((T2)(ZE5(1))))]);_i=(Z3)(((_i))+(ZE5(1)));}}void Z56(ZO C,T2 a1,T2 a2){T0*_v=Zo;T2 _i=0;
_i=a1;while(!((Z3)((_i)>(a2)))){(C)[_i]=(_v);_i=(Z3)(((_i))+(ZE5(1)));}}void Z36(ZO C,ZO a1,T2 a2){T2 _i=0;_i=a2;while(!((Z3)((_i)<(ZE5(0)))))
{(C)[_i]=((a1)[_i]);_i=(Z3)(((_i))-(ZE5(1)));}}void Z66(T98 C,T2 a1){T10 _v=0;T2 _i=0;_i=a1;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=(_v);
_i=(Z3)(((_i))-(ZE5(1)));}}T98 Z76(T98 C,T2 a1,T2 a2){T98 R=Zo;R=((T98)(Zk(a2,sizeof(T10))));Z86(R,C,(Z3)(((a1))-((T2)(ZE5(1)))));return
R;}void Z86(T98 C,T98 a1,T2 a2){T2 _i=0;_i=a2;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=((a1)[_i]);_i=(Z3)(((_i))-(ZE5(1)));}}T6 Z96(T0*a1,T0*a2){
T6 R=0;if((a1)==((void*)(a2))){R=((T6)(1));}else if((a1)==((void*)(Zo))){}else if((a2)==((void*)(Zo))){}else{R=((T6)(Za6(((T7*)a1),a2)));
}return R;}T43 Zb6(T43 C,T2 a1,T2 a2){T43 R=Zo;R=((T43)(Zk(a2,sizeof(T0*))));Zc6(R,C,(Z3)(((a1))-((T2)(ZE5(1)))));return R;}T2 Zd6(T43
C,T0*a1,T2 a2){T2 R=0;while(!((T6)(((Z3)((R)>(a2)))||((T6)(Z96(a1,(C)[R])))))){R=(Z3)(((R))+(ZE5(1)));}return R;}void Ze6(T43 C,T2 a1,T2
a2){T2 _i=0;_i=a1;while(!((_i)==(a2))){(C)[_i]=((C)[(Z3)(((_i))+((T2)(ZE5(1))))]);_i=(Z3)(((_i))+(ZE5(1)));}}void Zf6(T43 C,T0*a1,T2 a2){
T2 _i=0;_i=a2;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=(a1);_i=(Z3)(((_i))-(ZE5(1)));}}void Zg6(T43 C,T2 a1,T2 a2){T0*_v=Zo;T2 _i=0;_i=a1;
while(!((Z3)((_i)>(a2)))){(C)[_i]=(_v);_i=(Z3)(((_i))+(ZE5(1)));}}T2 Zh6(T43 C,T0*a1,T2 a2){T2 R=0;while(!((T6)(((Z3)((R)>(a2)))||((T6)((a1)==((void*)((C)[R])))))))
{R=(Z3)(((R))+(ZE5(1)));}return R;}void Zc6(T43 C,T43 a1,T2 a2){T2 _i=0;_i=a2;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=((a1)[_i]);_i=(Z3)(((_i))-(ZE5(1)));
}}void Zi6(T9 C,T2 a1,T9 a2,T2 a3,T2 a4){T2 _i1=0;T2 _i2=0;_i1=a1;_i2=a3;while(!((Z3)((_i2)>(a4)))){(C)[_i1]=((a2)[_i2]);_i2=(Z3)(((_i2))+(ZE5(1)));
_i1=(Z3)(((_i1))+(ZE5(1)));}}T9 Zj6(T9 C,T2 a1,T2 a2){T9 R=Zo;R=((T9)(Zk(a2,sizeof(T3))));Zk6(R,C,(Z3)(((a1))-((T2)(ZE5(1)))));return
R;}void Zl6(T9 C,T3 a1,T2 a2){T2 _i=0;_i=a2;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=(a1);_i=(Z3)(((_i))-(ZE5(1)));}}T6 Zm6(T9 C,T9 a1,T2
a2){T6 R=0;T2 _i=0;_i=(Z3)(((a2))-(ZE5(1)));while(!((T6)(((Z3)((_i)<(ZE5(0))))||((T6)(((C)[_i])!=((a1)[_i])))))){_i=(Z3)(((_i))-(ZE5(1)));
}R=((T6)((Z3)((_i)<(ZE5(0)))));return R;}T6 Zn6(T9 C,T3 a1,T2 a2){T6 R=0;T2 _i=0;_i=a2;while(!((T6)(((Z3)((_i)<(ZE5(0))))||((T6)((a1)==((C)[_i]))))))
{_i=(Z3)(((_i))-(ZE5(1)));}R=((T6)((Z3)((_i)>=(ZE5(0)))));return R;}void Zo6(T9 C,T2 a1,T9 a2,T2 a3){T2 Zp6=0;T2 Zq6=0;Zq6=(Z3)(((a3))-(ZE5(1)));
Zp6=(Z3)(((a1))+(Zq6));while(!((Z3)((Zq6)<(ZE5(0))))){(C)[Zp6]=((a2)[Zq6]);Zq6=(Z3)(((Zq6))-(ZE5(1)));Zp6=(Z3)(((Zp6))-(ZE5(1)));}}void
Zr6(T9 C,T2 a1,T2 a2){T3 _v=0;T2 _i=0;_i=a1;while(!((Z3)((_i)>(a2)))){(C)[_i]=(_v);_i=(Z3)(((_i))+(ZE5(1)));}}void Zk6(T9 C,T9 a1,T2 a2){
T2 _i=0;_i=a2;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=((a1)[_i]);_i=(Z3)(((_i))-(ZE5(1)));}}T77 Zs6(T77 C,T2 a1,T2 a2){T77 R=Zo;R=((T77)(Zk(a2,sizeof(T74))));
Zt6(R,C,(Z3)(((a1))-((T2)(ZE5(1)))));return R;}void Zu6(T77 C,T2 a1){T2 _i=0;while(!((_i)==(a1))){{T74 Zv6;{T74 Zw6=(*(Zv6=(C)[(Z3)(((_i))+((T2)(ZE5(1))))],&Zv6));
Zx6((C)+(_i),&(Zw6),sizeof(T74));}}_i=(Z3)(((_i))+(ZE5(1)));}}void Zy6(T77 C,T2 a1,T2 a2){T2 _i=0;_i=a1;while(!((_i)==(a2))){{T74 Zv6;
{T74 Zw6=(*(Zv6=(C)[(Z3)(((_i))+((T2)(ZE5(1))))],&Zv6));Zx6((C)+(_i),&(Zw6),sizeof(T74));}}_i=(Z3)(((_i))+(ZE5(1)));}}void Zz6(T77 C,T2
a1,T2 a2){T74 _v={Zo,Zo,0};T2 _i=0;_i=a1;while(!((Z3)((_i)>(a2)))){{T74 Zw6=_v;Zx6((C)+(_i),&(Zw6),sizeof(T74));}_i=(Z3)(((_i))+(ZE5(1)));
}}T2 ZA6(T77 C,T74 a1,T2 a2){T2 R=0;{T74 Zv6;while(!((T6)(((Z3)((R)>(a2)))||((T6)(!ZT((a1),((*(Zv6=(C)[R],&Zv6))))))))){R=(Z3)(((R))+(ZE5(1)));
}}return R;}void Zt6(T77 C,T77 a1,T2 a2){T2 _i=0;_i=a2;while(!((Z3)((_i)<(ZE5(0))))){{T74 Zv6;{T74 Zw6=(*(Zv6=(a1)[_i],&Zv6));Zx6((C)+(_i),&(Zw6),sizeof(T74));
}}_i=(Z3)(((_i))-(ZE5(1)));}}void ZB6(ZP C,T2 a1){T2 _v=0;T2 _i=0;_i=a1;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=(_v);_i=(Z3)(((_i))-(ZE5(1)));
}}ZP ZC6(ZP C,T2 a1,T2 a2){ZP R=Zo;R=((ZP)(Zk(a2,sizeof(T2))));ZD6(R,C,(Z3)(((a1))-((T2)(ZE5(1)))));return R;}T2 ZE6(ZP C,T2 a1,T2 a2){
T2 R=0;while(!((T6)(((Z3)((R)>(a2)))||((T6)((a1)==((C)[R])))))){R=(Z3)(((R))+(ZE5(1)));}return R;}void ZD6(ZP C,ZP a1,T2 a2){T2 _i=0;
_i=a2;while(!((Z3)((_i)<(ZE5(0))))){(C)[_i]=((a1)[_i]);_i=(Z3)(((_i))-(ZE5(1)));}}T2 ZF6(T7*C,T3 a1){T2 R=0;R=ZG6(C,a1,(T2)(ZE5(1)));
return R;}void ZH6(T7*C,T0*a1){T2 _c=0;_c=((((T7*)a1))->Z21);if((Z3)((_c)>(ZE5(0)))){if((Z3)((((C)->Z11))<(_c))){(C->Zl1)=((T9)(Zk(_c,sizeof(T3))));
(C->Z11)=_c;}Zk6(((C)->Zl1),((((T7*)a1))->Zl1),(Z3)(((_c))-((T2)(ZE5(1)))));}(C->Z21)=_c;}T0*ZI6(T7*C,T2 a1,T2 a2){T0*R=Zo;T2 _c=0;_c=(Z3)((((Z3)(((a2))-(a1))))+(ZE5(1)));
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,_c);R=((T0*)n);}((((T7*)(((T7*)R))))->Z21)=(_c);Zi6(((((T7*)R))->Zl1),(T2)(ZE5(0)),((C)->Zl1),(Z3)(((a1))-((T2)(ZE5(1)))),(Z3)(((a2))-((T2)(ZE5(1)))));
return R;}T3 ZK6(T7*C){T3 R=0;R=(((C)->Zl1))[(Z3)(((((C)->Z21)))-(ZE5(1)))];return R;}void ZL6(T7*C,T2 a1){if((Z3)((a1)>(((C)->Z21)))){
(C->Z21)=ZE5(0);}else{if((Z3)((a1)>(ZE5(0)))){ZM6(C,(T2)(ZE5(1)),a1);}}}void ZM6(T7*C,T2 a1,T2 a2){T2 _i=0;T2 ZN6=0;ZN6=(Z3)((((Z3)(((a2))-(a1))))+(ZE5(1)));
if((Z3)((ZN6)>(ZE5(0)))){_i=(Z3)(((a2))+(ZE5(1)));while(!((Z3)((_i)>(((C)->Z21))))){(((C)->Zl1))[((Z3)(((_i))-(ZN6)))-(ZE5(1))]=((((C)->Zl1))[(_i)-(ZE5(1))]);
_i=(Z3)(((_i))+(ZE5(1)));}(C->Z21)=(Z3)(((((C)->Z21)))-(ZN6));}}T6 Za6(T7*C,T0*a1){T6 R=0;if((((C)->Z21))==(((((T7*)a1))->Z21))){R=((T6)(Zm6(((C)->Zl1),((((T7*)a1))->Zl1),((C)->Z21))));
}return R;}T0*ZO6=Zo;T0*ZP6=Zo;T0*ZQ6(T7*C){T0*R=Zo;if((Z3)((((C)->Z21))>(ZE5(0)))){ZR6((T42*)(ZP6));ZS6(C,ZP6);if(!(ZT6((T42*)(ZP6)))){
R=ZU6((T42*)(ZP6));}}return R;}void ZV6(T7*C,T0*a1){T2 ZW6=0;T2 ZX6=0;T2 ZY6=0;ZW6=((((T7*)a1))->Z21);ZX6=(Z3)(((((C)->Z21)))+(ZW6));
if((Z3)((ZX6)>(((C)->Z11)))){if((((C)->Z11))==(ZE5(0))){(C->Zl1)=((T9)(Zk(ZX6,sizeof(T3))));(C->Z11)=ZX6;}else{ZY6=ZT5((Z3)(((ZE5(2)))*(((C)->Z11))),ZX6);
(C->Zl1)=Zj6(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;}}Zo6(((C)->Zl1),((C)->Z21),((((T7*)a1))->Zl1),ZW6);(C->Z21)=ZX6;}T6 ZZ6(T7*C,T0*a1){
T6 R=0;R=((T6)((Z_6(C,a1,(T2)(ZE5(1))))!=(ZE5(0))));return R;}T2 ZG6(T7*C,T3 a1,T2 a2){T2 R=0;R=a2;while(!((T6)(((Z3)((R)>(((C)->Z21))))||((T6)((a1)==((((C)->Zl1))[(R)-(ZE5(1))]))))))
{R=(Z3)(((R))+(ZE5(1)));}if((Z3)((R)>(((C)->Z21)))){R=ZE5(0);}return R;}T6 Z07(T7*C,T0*a1){T6 R=0;T2 _i1=0;T2 _i2=0;if((Z3)((((((T7*)a1))->Z21))<=(((C)->Z21)))){
_i1=(Z3)((((Z3)(((((C)->Z21)))-(((((T7*)a1))->Z21)))))+(ZE5(1)));_i2=ZE5(1);while(!((T6)(((Z3)((_i1)>(((C)->Z21))))||((T6)(((((C)->Zl1))[(_i1)-(ZE5(1))])!=((((((T7*)a1))->Zl1))[(_i2)-(ZE5(1))]))))))
{_i1=(Z3)(((_i1))+(ZE5(1)));_i2=(Z3)(((_i2))+(ZE5(1)));}R=((T6)((Z3)((_i1)>(((C)->Z21)))));}return R;}T6 Z17(T7*C){T6 R=0;T2 _i=0;T2 Z27=0;
T2 Z37=0;T6 Z47=0;T3 _cc=0;_i=ZE5(1);while(!((T6)(((Z27)==(ZE5(4)))||((T6)((Z3)((_i)>(((C)->Z21)))))))){_cc=(((C)->Zl1))[(_i)-(ZE5(1))];
{int z1=Z27;switch(z1){case 0:if(Zx5(_cc)){}else if((_cc)==(((T3)'\053'))){Z27=ZE5(1);}else if((_cc)==(((T3)'\055'))){Z47=((T6)(1));Z27=ZE5(1);
}else if(Zw5(_cc)){Z37=(T2)(ZH5(_cc));Z27=ZE5(2);}else{Z27=ZE5(4);}break;case 1:if(Zw5(_cc)){Z37=(T2)(ZH5(_cc));if(Z47){Z37=(Z3)(((ZE5(-1)))*(Z37));
}Z27=ZE5(2);}else{Z27=ZE5(4);}break;case 2:if(Zw5(_cc)){if(Z47){Z37=(Z3)((((Z3)(((ZE5(10)))*(Z37))))-((T2)(ZH5(_cc))));}else{Z37=(Z3)((((Z3)(((ZE5(10)))*(Z37))))+((T2)(ZH5(_cc))));
}if((T6)(((T6)((Z47)&&((T6)((Z3)((Z37)>(ZE5(0)))))))||((T6)((T6)((!(Z47))&&((T6)((Z3)((Z37)<(ZE5(0)))))))))){Z27=ZE5(4);}}else if(Zx5(_cc)){
Z27=ZE5(3);}else{Z27=ZE5(4);}break;default:;if(Zx5(_cc)){}else{Z27=ZE5(4);}}}_i=(Z3)(((_i))+(ZE5(1)));}if((T6)(((Z27)==(ZE5(2)))||((T6)((Z27)==(ZE5(3)))))){
R=((T6)(1));}return R;}void ZJ6(T7*C,T2 a1){if((Z3)((a1)>(ZE5(0)))){if((Z3)((((C)->Z11))<(a1))){(C->Zl1)=((T9)(Zk(a1,sizeof(T3))));(C->Z11)=a1;
}}(C->Z21)=ZE5(0);}T6 Z57(T7*C,T0*a1){T6 R=0;T2 _i=0;if((Z3)((((((T7*)a1))->Z21))<=(((C)->Z21)))){_i=((((T7*)a1))->Z21);while(!((T6)(((_i)==(ZE5(0)))||((T6)(((((C)->Zl1))[(_i)-(ZE5(1))])!=((((((T7*)a1))->Zl1))[(_i)-(ZE5(1))]))))))
{_i=(Z3)(((_i))-(ZE5(1)));}R=((T6)((_i)==(ZE5(0))));}return R;}void Z67(T7*C,T0*a1){T2 ZW6=0;T2 ZX6=0;T2 ZY6=0;ZW6=((((T7*)a1))->Z21);
ZX6=(Z3)(((((C)->Z21)))+(ZW6));if((Z3)((ZX6)>(((C)->Z11)))){if((((C)->Z11))==(ZE5(0))){(C->Zl1)=((T9)(Zk(ZX6,sizeof(T3))));(C->Z11)=ZX6;
}else{ZY6=ZT5((Z3)(((ZE5(2)))*(((C)->Z11))),ZX6);(C->Zl1)=Zj6(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;}}Zo6(((C)->Zl1),((C)->Z21),((((T7*)a1))->Zl1),ZW6);
(C->Z21)=ZX6;}void Z77(T7*C,T3 a1,T2 a2){ZJ6(C,a2);(C->Z21)=a2;{T7*C1=C;T3 b1=a1;Zl6(((C1)->Zl1),b1,(Z3)(((((C1)->Z21)))-((T2)(ZE5(1)))));
}}void ZQ5(T7*C,T3 a1){T2 ZY6=0;if((Z3)((((C)->Z11))>(((C)->Z21)))){}else if((((C)->Z11))==(ZE5(0))){ZY6=ZE5(32);(C->Zl1)=((T9)(Zk(ZY6,sizeof(T3))));
(C->Z11)=ZY6;}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));(C->Zl1)=Zj6(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;}(((C)->Zl1))[((C)->Z21)]=(a1);
(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));}T2 Z87(T7*C){T2 R=0;T2 _i=0;T2 _j=0;_j=((C)->Z21);_i=ZE5(1);while(!((Z3)((_j)<=(ZE5(0))))){R=(Z3)(((Z3)((ZE5(5))*(R)))+((T2)(ZB5((((C)->Zl1))[(_i)-(ZE5(1))]))));
_i=(Z3)(((_i))+(ZE5(1)));_j=(Z3)(((_j))-(ZE5(1)));}if((Z3)((R)<(ZE5(0)))){R=~(R);}return R;}void Z97(T7*C,T2 a1){if((Z3)((a1)>(((C)->Z21)))){
(C->Z21)=ZE5(0);}else{(C->Z21)=(Z3)(((((C)->Z21)))-(a1));}}T6 Za7(T7*C,T3 a1){T6 R=0;R=((T6)(Zn6(((C)->Zl1),a1,(Z3)(((((C)->Z21)))-((T2)(ZE5(1)))))));
return R;}void Zb7(T7*C,T2 a1){if((Z3)((a1)<(((C)->Z21)))){Z97(C,(Z3)(((((C)->Z21)))-(a1)));}}T2 Zc7(T7*C){T2 R=0;T2 _i=0;T2 Z27=0;T3
_cc=0;T6 Z47=0;_i=ZE5(1);while(!((Z3)((_i)>(((C)->Z21))))){_cc=(((C)->Zl1))[(_i)-(ZE5(1))];{int z1=Z27;switch(z1){case 0:if(Zx5(_cc)){
}else if((_cc)==(((T3)'\053'))){Z27=ZE5(1);}else if((_cc)==(((T3)'\055'))){Z47=((T6)(1));Z27=ZE5(1);}else{R=(T2)(ZC5(_cc));Z27=ZE5(2);
}break;case 1:R=(T2)(ZC5(_cc));if(Z47){R=(Z3)(((ZE5(-1)))*(R));}Z27=ZE5(2);break;case 2:if(Zw5(_cc)){if(Z47){R=(Z3)((((Z3)(((ZE5(10)))*(R))))-((T2)(ZH5(_cc))));
}else{R=(Z3)((((Z3)(((ZE5(10)))*(R))))+((T2)(ZH5(_cc))));}}else{Z27=ZE5(3);}break;default:;_i=((C)->Z21);}}_i=(Z3)(((_i))+(ZE5(1)));}
return R;}void Zd7(T7*C,T3 a1){T2 ZY6=0;if((Z3)((((C)->Z11))>(((C)->Z21)))){}else if((((C)->Z11))==(ZE5(0))){ZY6=ZE5(32);(C->Zl1)=((T9)(Zk(ZY6,sizeof(T3))));
(C->Z11)=ZY6;}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));(C->Zl1)=Zj6(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;}(((C)->Zl1))[((C)->Z21)]=(a1);
(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));}void Ze7(T7*C,T3 a1){if((T6)(((((C)->Z21))==(ZE5(0)))||((T6)(((((C)->Zl1))[(((C)->Z21))-(ZE5(1))])!=(a1))))){
Zd7(C,a1);}}T6 Zf7(T7*C,T0*a1){T6 R=0;T9 _s1=Zo;T9 _s2=Zo;T2 _i=0;_i=((C)->Z21);if((_i)==(((((T7*)a1))->Z21))){if(Zm6(((C)->Zl1),((((T7*)a1))->Zl1),_i)){
R=((T6)(1));}else{_i=(Z3)(((_i))-(ZE5(1)));_s1=((C)->Zl1);_s2=((((T7*)a1))->Zl1);R=((T6)(1));while(!((Z3)((_i)<(ZE5(0))))){if(ZG5((_s1)[_i],(_s2)[_i])){
_i=(Z3)(((_i))-(ZE5(1)));}else{_i=ZE5(-1);R=((T6)(0));}}}}return R;}void Zg7(T7*C,T3 a1){T2 ZY6=0;if((Z3)((((C)->Z11))>(((C)->Z21)))){
}else if((((C)->Z11))==(ZE5(0))){ZY6=ZE5(32);(C->Zl1)=((T9)(Zk(ZY6,sizeof(T3))));(C->Z11)=ZY6;}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));
(C->Zl1)=Zj6(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;}(((C)->Zl1))[((C)->Z21)]=(a1);(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));}void Zh7(T7*C,T2
a1){T9 _s=Zo;if((Z3)((a1)<=(((C)->Z21)))){}else if((Z3)((((C)->Z11))<(a1))){if((((C)->Z11))==(ZE5(0))){(C->Zl1)=((T9)(Zk(a1,sizeof(T3))));
}else{(C->Zl1)=Zj6(((C)->Zl1),((C)->Z11),a1);}(C->Z11)=a1;}else{Zr6(((C)->Zl1),((C)->Z21),(Z3)(((a1))-((T2)(ZE5(1)))));}(C->Z21)=a1;}
void Zi7(T7*C){T2 _i=0;_i=((C)->Z21);while(!((_i)==(ZE5(0)))){(((C)->Zl1))[(_i)-(ZE5(1))]=(ZI5((((C)->Zl1))[(_i)-(ZE5(1))]));_i=(Z3)(((_i))-(ZE5(1)));
}}T2 Z_6(T7*C,T0*a1,T2 a2){T2 R=0;T2 _i=0;T2 _s=0;_s=a2;while(!((T6)(((R)!=(ZE5(0)))||((T6)((Z3)(((Z3)((((Z3)(((_s))+(((((T7*)a1))->Z21)))))-(ZE5(1))))>(((C)->Z21))))))))
{_i=ZE5(1);while(!((T6)(((Z3)((_i)>(((((T7*)a1))->Z21))))||((T6)(((((C)->Zl1))[((Z3)((((Z3)(((_s))+(_i))))-(ZE5(1))))-(ZE5(1))])!=((((((T7*)a1))->Zl1))[(_i)-(ZE5(1))]))))))
{_i=(Z3)(((_i))+(ZE5(1)));}if((Z3)((_i)>(((((T7*)a1))->Z21)))){R=_s;}else{_s=(Z3)(((_s))+(ZE5(1)));}}return R;}void Zj7(T7*C,T8 a1){T9
_s=Zo;T2 _i=0;_s=a1;(C->Z21)=ZE5(0);while(!(((_s)[_i])==(((T3)'\000')))){Zd7(C,(_s)[_i]);_i=(Z3)(((_i))+(ZE5(1)));}}void Zk7(T7*C){while(!((T6)(((((C)->Z21))==(ZE5(0)))||((T6)(((((C)->Zl1))[(((C)->Z21))-(ZE5(1))])!=(((T3)'\040')))))))
{(C->Z21)=(Z3)(((((C)->Z21)))-(ZE5(1)));}}T8 Zl7(T7*C){T8 R=Zo;if((Z3)((((C)->Z11))>(((C)->Z21)))){(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));
if(((((C)->Zl1))[(((C)->Z21))-(ZE5(1))])!=(((T3)'\000'))){(((C)->Zl1))[(((C)->Z21))-(ZE5(1))]=(((T3)'\000'));}}else{Zd7(C,((T3)'\000'));
}(C->Z21)=(Z3)(((((C)->Z21)))-(ZE5(1)));R=((void*)(((C)->Zl1)));return R;}void Zm7(T7*C){T2 _i=0;_i=((C)->Z21);while(!((_i)==(ZE5(0))))
{(((C)->Zl1))[(_i)-(ZE5(1))]=(ZK5((((C)->Zl1))[(_i)-(ZE5(1))]));_i=(Z3)(((_i))-(ZE5(1)));}}T0*Zn7(T7*C){T0*R=Zo;R=Zh(sizeof(*C));*((T7*)R)=M7;
ZH6(((T7*)R),((T0*)C));return R;}T0*Zo7(T7*C,T0*a1){T0*R=Zo;{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(Z3)(((((C)->Z21)))+(((((T7*)a1))->Z21))));
R=((T0*)n);}ZV6(((T7*)R),(T0*)C);ZV6(((T7*)R),a1);return R;}T6 Zp7(T7*C){T6 R=0;int Zq7=0;R=((T6)(Zr7(Zq7,(T0*)C)));return R;}void Zs7(T7*C){
T2 _i=0;_i=ZE5(1);while(!((T6)(((Z3)((_i)>(((C)->Z21))))||((T6)(((((C)->Zl1))[(_i)-(ZE5(1))])!=(((T3)'\040'))))))){_i=(Z3)(((_i))+(ZE5(1)));
}ZL6(C,(Z3)(((_i))-((T2)(ZE5(1)))));}void ZS6(T7*C,T0*a1){T2 Z27=0;T2 _i=0;T3 _c=0;if((Z3)((((C)->Z21))>(ZE5(0)))){_i=ZE5(1);while(!((Z3)((_i)>(((C)->Z21)))))
{_c=(((C)->Zl1))[(_i)-(ZE5(1))];if((Z27)==(ZE5(0))){if(!(Zx5(_c))){((((T7*)((T7*)(ZO6))))->Z21)=(ZE5(0));Zd7((T7*)(ZO6),_c);Z27=ZE5(1);
}}else{if(!(Zx5(_c))){Zd7((T7*)(ZO6),_c);}else{Zt7(a1,Zn7((T7*)(ZO6)));Z27=ZE5(0);}}_i=(Z3)(((_i))+(ZE5(1)));}if((Z27)==(ZE5(1))){Zt7(a1,Zn7((T7*)(ZO6)));
}}}void ZR5(T7*C,T2 a1,T2 a2){T3 Zu7=0;Zu7=(((C)->Zl1))[(a1)-(ZE5(1))];(((C)->Zl1))[(a1)-(ZE5(1))]=((((C)->Zl1))[(a2)-(ZE5(1))]);(((C)->Zl1))[(a2)-(ZE5(1))]=(Zu7);
}void Zv7(ZD*C){ZO Zw7=Zo;if((((C)->Zm1))==(ZE5(0))){(C->Zl1)=Zw7;(C->Z11)=ZE5(0);(C->Zm1)=ZE5(-1);}else{Z46(((C)->Zl1),((C)->Zm1));(C->Zm1)=(Z3)(((((C)->Zm1)))-(ZE5(1)));
}}void Zx7(ZD*C,T0*a1){T2 ZY6=0;if((Z3)(((Z3)(((((C)->Zm1)))+(ZE5(1))))<=((Z3)(((((C)->Z11)))-(ZE5(1)))))){(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));
}else if((((C)->Z11))==(ZE5(0))){(C->Zl1)=((ZO)(Zk(ZE5(2),sizeof(T0*))));(C->Z11)=ZE5(2);(C->Zm1)=ZE5(0);}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));
(C->Zl1)=Z26(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));}(((C)->Zl1))[((C)->Zm1)]=(a1);}void Zy7(ZD*C,T2
a1){if((Z3)((((C)->Z11))<(a1))){(C->Zl1)=((ZO)(Zk(a1,sizeof(T0*))));(C->Z11)=a1;}else if((Z3)((((C)->Z11))>(a1))){Z56(((C)->Zl1),(T2)(ZE5(0)),((C)->Zm1));
}(C->Zm1)=ZE5(-1);}void Zz7(T75*C){T77 Zw7=Zo;if((((C)->Zm1))==(ZE5(0))){(C->Zl1)=Zw7;(C->Z11)=ZE5(0);(C->Zm1)=ZE5(-1);}else{Zu6(((C)->Zl1),((C)->Zm1));
(C->Zm1)=(Z3)(((((C)->Zm1)))-(ZE5(1)));}}T6 ZA7(T75*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZE5(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->Zm1))))))));
return R;}void ZB7(T75*C,T2 a1){Zy6(((C)->Zl1),a1,((C)->Zm1));(C->Zm1)=(Z3)(((((C)->Zm1)))-(ZE5(1)));}void ZC7(T75*C,T74 a1){T2 ZY6=0;
if((Z3)(((Z3)(((((C)->Zm1)))+(ZE5(1))))<=((Z3)(((((C)->Z11)))-(ZE5(1)))))){(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));}else if((((C)->Z11))==(ZE5(0))){
(C->Zl1)=((T77)(Zk(ZE5(2),sizeof(T74))));(C->Z11)=ZE5(2);(C->Zm1)=ZE5(0);}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));(C->Zl1)=Zs6(((C)->Zl1),((C)->Z11),ZY6);
(C->Z11)=ZY6;(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));}{T74 Zw6=a1;Zx6((((C)->Zl1))+(((C)->Zm1)),&(Zw6),sizeof(T74));}}T74 ZD7(T75*C){T74
R={Zo,Zo,0};{T74 Zv6;R=(*(Zv6=(((C)->Zl1))[ZE5(0)],&Zv6));}return R;}T2 ZE7(T75*C,T74 a1){T2 R=0;R=ZA6(((C)->Zl1),a1,((C)->Zm1));return
R;}void ZF7(T75*C,T2 a1){if((Z3)((((C)->Z11))<(a1))){(C->Zl1)=((T77)(Zk(a1,sizeof(T74))));(C->Z11)=a1;}else if((Z3)((((C)->Z11))>(a1))){
Zz6(((C)->Zl1),(T2)(ZE5(0)),((C)->Zm1));}(C->Zm1)=ZE5(-1);}T0*ZG7(T47*C){T0*R=Zo;R=(((C)->Zl1))[((C)->Zm1)];return R;}T6 ZH7(T47*C,T2
a1){T6 R=0;R=((T6)((T6)(((Z3)((ZE5(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->Zm1))))))));return R;}void ZI7(T47*C,T2 a1){Ze6(((C)->Zl1),a1,((C)->Zm1));
(C->Zm1)=(Z3)(((((C)->Zm1)))-(ZE5(1)));}T0*ZJ7(T47*C){T0*R=Zo;{ZJ*n=((ZJ*)Zh(sizeof(*n)));*n=Z92;ZK7(n,(T0*)C);R=((T0*)n);}return R;}
void ZL7(T47*C,T0*a1){T2 ZY6=0;if((Z3)(((Z3)(((((C)->Zm1)))+(ZE5(1))))<=((Z3)(((((C)->Z11)))-(ZE5(1)))))){(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));
}else if((((C)->Z11))==(ZE5(0))){(C->Zl1)=((T43)(Zk(ZE5(2),sizeof(T0*))));(C->Z11)=ZE5(2);(C->Zm1)=ZE5(0);}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));
(C->Zl1)=Zb6(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));}(((C)->Zl1))[((C)->Zm1)]=(a1);}void ZM7(T47*C,T2
a1){if((Z3)((((C)->Z11))<(a1))){(C->Zl1)=((T43)(Zk(a1,sizeof(T0*))));(C->Z11)=a1;}else if((Z3)((((C)->Z11))>(a1))){Zg6(((C)->Zl1),(T2)(ZE5(0)),((C)->Zm1));
}(C->Zm1)=ZE5(-1);}void ZN7(T96*C,T2 a1){if((Z3)((a1)>(((C)->Z11)))){(C->Zl1)=((T98)(Zk(a1,sizeof(T10))));(C->Z11)=a1;}else if((Z3)((((C)->Z11))>(ZE5(0)))){
(C->Zm1)=ZT5(((C)->Zm1),(Z3)(((a1))-(ZE5(1))));if((Z3)((((C)->Zm1))>=(ZE5(0)))){Z66(((C)->Zl1),((C)->Zm1));}}(C->Zm1)=(Z3)(((a1))-(ZE5(1)));
}void ZO7(T96*C,T10 a1){T2 ZY6=0;if((Z3)(((Z3)(((((C)->Zm1)))+(ZE5(1))))<=((Z3)(((((C)->Z11)))-(ZE5(1)))))){(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));
}else if((((C)->Z11))==(ZE5(0))){(C->Zl1)=((T98)(Zk(ZE5(2),sizeof(T10))));(C->Z11)=ZE5(2);(C->Zm1)=ZE5(0);}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));
(C->Zl1)=Z76(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));}(((C)->Zl1))[((C)->Zm1)]=(a1);}void ZP7(T99*C,T2
a1){if((Z3)((a1)>(((C)->Z11)))){(C->Zl1)=((ZP)(Zk(a1,sizeof(T2))));(C->Z11)=a1;}else if((Z3)((((C)->Z11))>(ZE5(0)))){(C->Zm1)=ZT5(((C)->Zm1),(Z3)(((a1))-(ZE5(1))));
if((Z3)((((C)->Zm1))>=(ZE5(0)))){ZB6(((C)->Zl1),((C)->Zm1));}}(C->Zm1)=(Z3)(((a1))-(ZE5(1)));}void ZQ7(T99*C,T2 a1){T2 ZY6=0;if((Z3)(((Z3)(((((C)->Zm1)))+(ZE5(1))))<=((Z3)(((((C)->Z11)))-(ZE5(1)))))){
(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));}else if((((C)->Z11))==(ZE5(0))){(C->Zl1)=((ZP)(Zk(ZE5(2),sizeof(T2))));(C->Z11)=ZE5(2);(C->Zm1)=ZE5(0);
}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));(C->Zl1)=ZC6(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));}
(((C)->Zl1))[((C)->Zm1)]=(a1);}T2 ZR7(T99*C,T2 a1){T2 R=0;R=ZE6(((C)->Zl1),a1,((C)->Zm1));return R;}void ZS7(T42*C,T0*a1){T2 ZX6=0;(C->ZV2)=((((T42*)a1))->ZV2);
(C->Zm1)=((((T42*)a1))->Zm1);ZX6=(Z3)((((Z3)(((((C)->Zm1)))-(((C)->ZV2)))))+(ZE5(1)));if((Z3)((((C)->Z11))<(ZX6))){(C->Zl1)=((T43)(Zk(ZX6,sizeof(T0*))));
(C->Z11)=ZX6;}if((Z3)((ZX6)>(ZE5(0)))){Zc6(((C)->Zl1),((((T42*)a1))->Zl1),(Z3)(((ZX6))-((T2)(ZE5(1)))));}}T2 ZT7(T42*C){T2 R=0;R=(Z3)((((Z3)(((((C)->Zm1)))-(((C)->ZV2)))))+(ZE5(1)));
return R;}T0*ZU7(T42*C,T2 a1){T0*R=Zo;R=(((C)->Zl1))[(Z3)(((a1))-(((C)->ZV2)))];return R;}T6 ZV7(T42*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((((C)->ZV2))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->Zm1))))))));
return R;}T2 ZW7(T42*C,T0*a1){T2 R=0;R=(Z3)(((((C)->ZV2)))+(Zd6(((C)->Zl1),a1,(Z3)(((((C)->Zm1)))-(((C)->ZV2))))));return R;}void ZX7(T42*C,T2
a1,T2 a2){T2 ZY7=0;(C->ZV2)=a1;(C->Zm1)=a2;ZY7=(Z3)((((Z3)(((a2))-(a1))))+(ZE5(1)));if((Z3)((ZY7)>(ZE5(0)))){if((Z3)((((C)->Z11))<(ZY7))){
(C->Zl1)=((T43)(Zk(ZY7,sizeof(T0*))));(C->Z11)=ZY7;}else{{T42*C1=C;T0*ZZ7=Zo;{T42*C2=C1;T0*c1=ZZ7;Zf6(((C2)->Zl1),c1,(Z3)(((((C2)->Zm1)))-(((C2)->ZV2))));
}}}}}void Z_7(T42*C,T0*a1){if((Z3)((((C)->Zm1))<(((C)->ZV2)))){Z08(C,a1);}else{Z08(C,a1);Z18(C,((C)->ZV2),(Z3)(((((C)->Zm1)))-((T2)(ZE5(1)))),(T2)(ZE5(1)));
{T42*C1=C;T0*b1=a1;T2 b2=((C)->ZV2);(((C1)->Zl1))[(Z3)(((b2))-(((C1)->ZV2)))]=(b1);}}}T6 ZT6(T42*C){T6 R=0;R=((T6)((Z3)((((C)->Zm1))<(((C)->ZV2)))));
return R;}void Z18(T42*C,T2 a1,T2 a2,T2 a3){T0*Z28=Zo;T2 _i=0;if((a3)==(ZE5(0))){}else if((Z3)((a3)<(ZE5(0)))){_i=a1;while(!((Z3)((_i)>(a2))))
{{T42*C1=C;T0*b1=ZU7(C,_i);T2 b2=(Z3)(((_i))+(a3));(((C1)->Zl1))[(Z3)(((b2))-(((C1)->ZV2)))]=(b1);}{T42*C1=C;T0*b1=Z28;T2 b2=_i;(((C1)->Zl1))[(Z3)(((b2))-(((C1)->ZV2)))]=(b1);
}_i=(Z3)(((_i))+(ZE5(1)));}}else{_i=a2;while(!((Z3)((_i)<(a1)))){{T42*C1=C;T0*b1=ZU7(C,_i);T2 b2=(Z3)(((_i))+(a3));(((C1)->Zl1))[(Z3)(((b2))-(((C1)->ZV2)))]=(b1);
}{T42*C1=C;T0*b1=Z28;T2 b2=_i;(((C1)->Zl1))[(Z3)(((b2))-(((C1)->ZV2)))]=(b1);}_i=(Z3)(((_i))-(ZE5(1)));}}}T6 Z38(T42*C,T0*a1){T6 R=0;
R=((T6)(ZV7(C,ZW7(C,a1))));return R;}T6 Z48(T42*C,T0*a1){T6 R=0;R=((T6)(ZV7(C,Z58(C,a1))));return R;}void Z08(T42*C,T0*a1){T2 ZY6=0;if((Z3)((((C)->Z11))<((Z3)(((ZT7(C)))+(ZE5(1)))))){
if((((C)->Z11))==(ZE5(0))){ZY6=ZE5(16);(C->Zl1)=((T43)(Zk(ZY6,sizeof(T0*))));(C->Z11)=ZY6;}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));(C->Zl1)=Zb6(((C)->Zl1),((C)->Z11),ZY6);
(C->Z11)=ZY6;}}(C->Zm1)=(Z3)(((((C)->Zm1)))+(ZE5(1)));{T42*C1=C;T0*b1=a1;T2 b2=((C)->Zm1);(((C1)->Zl1))[(Z3)(((b2))-(((C1)->ZV2)))]=(b1);
}}void ZR6(T42*C){(C->Zm1)=(Z3)(((((C)->ZV2)))-(ZE5(1)));}T2 Z58(T42*C,T0*a1){T2 R=0;R=(Z3)(((((C)->ZV2)))+(Zh6(((C)->Zl1),a1,(Z3)(((((C)->Zm1)))-(((C)->ZV2))))));
return R;}T0*ZU6(T42*C){T0*R=Zo;R=Zh(sizeof(*C));*((T42*)R)=M42;ZS7(((T42*)R),((T0*)C));return R;}void Z68(T42*C,T2 a1,T2 a2){if((Z3)((((C)->Z11))<(a1))){
(C->Zl1)=((T43)(Zk(a1,sizeof(T0*))));(C->Z11)=a1;}(C->ZV2)=a2;(C->Zm1)=(Z3)(((a2))-(ZE5(1)));}T62*Z78(void){T62*n;n=((T62*)Zh(sizeof(*n)));
*n=M62;{T62*C1=n;Z88(C1,Z98(193));}return n;}T6 Za8(T0*a1,T0*a2){T6 R=0;if((a1)==((void*)(a2))){R=((T6)(1));}else if((a1)==((void*)(Zo))){
}else if((a2)==((void*)(Zo))){}else{R=((T6)(Za6(((T7*)a1),a2)));}return R;}T2 Zb8(T62*C,T0*a1){T2 R=0;T2 _i=0;_i=ZE5(1);while(!((Z3)((_i)>(((C)->Z21)))))
{if(Za8(a1,Zc8(C,_i))){R=(Z3)(((R))+(ZE5(1)));}_i=(Z3)(((_i))+(ZE5(1)));}return R;}T0*Zd8(T62*C,T2 a1){T0*R=Zo;Ze8(C,a1);R=(((T67*)(((C)->Z41)))->Zj1);
return R;}T0*Zf8(T62*C,T0*a1){T0*R=Zo;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));Zg8=(((C)->Z01))[ZP5];while(!(Za6((T7*)(((((T67*)Zg8))->Zj1)),a1)))
{Zg8=((((T67*)Zg8))->Zk1);}R=((((T67*)Zg8))->Zi1);return R;}T0*Zc8(T62*C,T2 a1){T0*R=Zo;Ze8(C,a1);R=(((T67*)(((C)->Z41)))->Zi1);return
R;}void Ze8(T62*C,T2 a1){if((a1)==((Z3)(((((C)->Z31)))+(ZE5(1))))){(C->Z31)=a1;(C->Z41)=(((T67*)(((C)->Z41)))->Zk1);while(!((((C)->Z41))!=((void*)(Zo))))
{(C->Z51)=(Z3)(((((C)->Z51)))+(ZE5(1)));(C->Z41)=(((C)->Z01))[((C)->Z51)];}}else if((a1)==(((C)->Z31))){}else if((a1)==(ZE5(1))){(C->Z31)=ZE5(1);
(C->Z51)=ZE5(0);(C->Z41)=(((C)->Z01))[((C)->Z51)];while(!((((C)->Z41))!=((void*)(Zo)))){(C->Z51)=(Z3)(((((C)->Z51)))+(ZE5(1)));(C->Z41)=(((C)->Z01))[((C)->Z51)];
}}else{Ze8(C,(T2)(ZE5(1)));while(!((((C)->Z31))==(a1))){Ze8(C,(Z3)(((((C)->Z31)))+((T2)(ZE5(1)))));}}}void Zh8(T62*C,T0*a1,T0*a2){T2 ZP5=0;
T0*Zg8=Zo;(C->Z31)=ZE5(-1);if((((C)->Z11))==(((C)->Z21))){Zi8(C);}ZP5=(Z3)((Z87(((T7*)a2)))%(((C)->Z11)));{T67*n=((T67*)Zh(sizeof(*n)));
*n=M67;Zj8(n,a1,a2,(((C)->Z01))[ZP5]);Zg8=((T0*)n);}(((C)->Z01))[ZP5]=(Zg8);(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));}T0*Zk8(T62*C,T0*a1){
T0*R=Zo;T2 _i=0;_i=ZE5(1);while(!(Za8(a1,Zc8(C,_i)))){_i=(Z3)(((_i))+(ZE5(1)));}R=(((T67*)(((C)->Z41)))->Zj1);return R;}void Zl8(T62*C,T2
a1){T2 ZY6=0;int Zm8=0;ZY6=Zn8(a1);(C->Z01)=((T68)(Zk(ZY6,sizeof(T0*))));(C->Z11)=ZY6;(C->Z31)=ZE5(-1);(C->Z21)=ZE5(0);}void Zi8(T62*C){
T2 _i=0;T2 ZP5=0;T2 ZY6=0;T68 Zo8=Zo;T0*Zp8=Zo;T0*Zq8=Zo;int Zm8=0;ZY6=Zn8((Z3)(((((C)->Z11)))+(ZE5(1))));Zo8=((C)->Z01);(C->Z01)=((T68)(Zk(ZY6,sizeof(T0*))));
_i=(Z3)(((((C)->Z11)))-(ZE5(1)));(C->Z11)=ZY6;while(!((Z3)((_i)<(ZE5(0))))){Zp8=(Zo8)[_i];while(!((Zp8)==((void*)(Zo)))){Zq8=((((T67*)Zp8))->Zk1);
ZP5=(Z3)((Z87((T7*)(((((T67*)Zp8))->Zj1))))%(((C)->Z11)));((((T67*)(((T67*)Zp8))))->Zk1)=((((C)->Z01))[ZP5]);(((C)->Z01))[ZP5]=(Zp8);
Zp8=Zq8;}_i=(Z3)(((_i))-(ZE5(1)));}(C->Z31)=ZE5(-1);}T6 Zr8(T62*C,T0*a1){T6 R=0;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));
Zg8=(((C)->Z01))[ZP5];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((T67*)Zg8))->Zj1)),a1)))))){Zg8=((((T67*)Zg8))->Zk1);}R=((T6)((Zg8)!=((void*)(Zo))));
return R;}void Zs8(T62*C,T0*a1,T0*a2){Zh8(C,a1,a2);ZL7((T47*)(((C)->Z61)),a2);}void Zt8(T62*C,T0*a1){T0*Zg8=Zo;T2 _i=0;T2 ZP5=0;_i=((C)->Z21);
Zg8=(((C)->Z01))[ZP5];while(!((Z3)((_i)<=(ZE5(0))))){while(!((Zg8)!=((void*)(Zo)))){ZP5=(Z3)(((ZP5))+(ZE5(1)));Zg8=(((C)->Z01))[ZP5];
}Zt7(a1,((((T67*)Zg8))->Zi1));Zg8=((((T67*)Zg8))->Zk1);_i=(Z3)(((_i))-(ZE5(1)));}}void Z88(T62*C,T2 a1){Zl8(C,a1);{T47*n=((T47*)Zh(sizeof(*n)));
*n=M47;ZM7(n,a1);(C->Z61)=((T0*)n);}}T0*Zu8(T62*C,T0*a1){T0*R=Zo;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));Zg8=(((C)->Z01))[ZP5];
while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((T67*)Zg8))->Zj1)),a1)))))){Zg8=((((T67*)Zg8))->Zk1);}if((Zg8)!=((void*)(Zo))){
R=((((T67*)Zg8))->Zi1);}return R;}void Zv8(T85*C,T10 a1,T0*a2){T2 _h=0;T2 ZP5=0;T0*Zg8=Zo;_h=Z87(((T7*)a2));ZP5=(Z3)((_h)%(((C)->Z11)));
Zg8=(((C)->Z01))[ZP5];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((T87*)Zg8))->Zj1)),a2)))))){Zg8=((((T87*)Zg8))->Zk1);}if((Zg8)==((void*)(Zo))){
if((((C)->Z11))==(((C)->Z21))){Zw8(C);ZP5=(Z3)((_h)%(((C)->Z11)));}{T87*n=((T87*)Zh(sizeof(*n)));*n=M87;Zx8(n,a1,a2,(((C)->Z01))[ZP5]);
Zg8=((T0*)n);}(((C)->Z01))[ZP5]=(Zg8);(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));(C->Z31)=ZE5(-1);}else{((((T87*)(((T87*)Zg8))))->Zi1)=(a1);
}}T0*Zy8(T85*C,T10 a1){T0*R=Zo;T2 _i=0;_i=ZE5(1);while(!((a1)==(Zz8(C,_i)))){_i=(Z3)(((_i))+(ZE5(1)));}R=(((T87*)(((C)->Z41)))->Zj1);
return R;}T10 Zz8(T85*C,T2 a1){T10 R=0;ZA8(C,a1);R=(((T87*)(((C)->Z41)))->Zi1);return R;}void ZA8(T85*C,T2 a1){if((a1)==((Z3)(((((C)->Z31)))+(ZE5(1))))){
(C->Z31)=a1;(C->Z41)=(((T87*)(((C)->Z41)))->Zk1);while(!((((C)->Z41))!=((void*)(Zo)))){(C->Z51)=(Z3)(((((C)->Z51)))+(ZE5(1)));(C->Z41)=(((C)->Z01))[((C)->Z51)];
}}else if((a1)==(((C)->Z31))){}else if((a1)==(ZE5(1))){(C->Z31)=ZE5(1);(C->Z51)=ZE5(0);(C->Z41)=(((C)->Z01))[((C)->Z51)];while(!((((C)->Z41))!=((void*)(Zo))))
{(C->Z51)=(Z3)(((((C)->Z51)))+(ZE5(1)));(C->Z41)=(((C)->Z01))[((C)->Z51)];}}else{ZA8(C,(T2)(ZE5(1)));while(!((((C)->Z31))==(a1))){ZA8(C,(Z3)(((((C)->Z31)))+((T2)(ZE5(1)))));
}}}void Zw8(T85*C){T2 _i=0;T2 ZP5=0;T2 ZY6=0;T88 Zo8=Zo;T0*Zp8=Zo;T0*Zq8=Zo;int Zm8=0;ZY6=Zn8((Z3)(((((C)->Z11)))+(ZE5(1))));Zo8=((C)->Z01);
(C->Z01)=((T88)(Zk(ZY6,sizeof(T0*))));_i=(Z3)(((((C)->Z11)))-(ZE5(1)));(C->Z11)=ZY6;while(!((Z3)((_i)<(ZE5(0))))){Zp8=(Zo8)[_i];while(!((Zp8)==((void*)(Zo))))
{Zq8=((((T87*)Zp8))->Zk1);ZP5=(Z3)((Z87((T7*)(((((T87*)Zp8))->Zj1))))%(((C)->Z11)));((((T87*)(((T87*)Zp8))))->Zk1)=((((C)->Z01))[ZP5]);
(((C)->Z01))[ZP5]=(Zp8);Zp8=Zq8;}_i=(Z3)(((_i))-(ZE5(1)));}(C->Z31)=ZE5(-1);}void ZB8(T85*C,T2 a1){T2 ZY6=0;int Zm8=0;ZY6=Zn8(a1);(C->Z01)=((T88)(Zk(ZY6,sizeof(T0*))));
(C->Z11)=ZY6;(C->Z31)=ZE5(-1);(C->Z21)=ZE5(0);}void Zj8(T67*C,T0*a1,T0*a2,T0*a3){(C->Zi1)=a1;(C->Zj1)=a2;(C->Zk1)=a3;}T0*ZC8(ZH*C,T0*a1){
T0*R=Zo;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));Zg8=(((C)->Z01))[ZP5];while(!(Za6((T7*)(((((ZB*)Zg8))->Zj1)),a1)))
{Zg8=((((ZB*)Zg8))->Zk1);}R=((((ZB*)Zg8))->Zi1);return R;}void ZD8(ZH*C,T0*a1,T0*a2){T2 _h=0;T2 ZP5=0;T0*Zg8=Zo;_h=Z87(((T7*)a2));ZP5=(Z3)((_h)%(((C)->Z11)));
Zg8=(((C)->Z01))[ZP5];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((ZB*)Zg8))->Zj1)),a2)))))){Zg8=((((ZB*)Zg8))->Zk1);}if((Zg8)==((void*)(Zo))){
if((((C)->Z11))==(((C)->Z21))){ZE8(C);ZP5=(Z3)((_h)%(((C)->Z11)));}{ZB*n=((ZB*)Zh(sizeof(*n)));*n=ZU2;ZF8(n,a1,a2,(((C)->Z01))[ZP5]);
Zg8=((T0*)n);}(((C)->Z01))[ZP5]=(Zg8);(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));(C->Z31)=ZE5(-1);}else{((((ZB*)(((ZB*)Zg8))))->Zi1)=(a1);
}}void ZE8(ZH*C){T2 _i=0;T2 ZP5=0;T2 ZY6=0;ZN Zo8=Zo;T0*Zp8=Zo;T0*Zq8=Zo;int Zm8=0;ZY6=Zn8((Z3)(((((C)->Z11)))+(ZE5(1))));Zo8=((C)->Z01);
(C->Z01)=((ZN)(Zk(ZY6,sizeof(T0*))));_i=(Z3)(((((C)->Z11)))-(ZE5(1)));(C->Z11)=ZY6;while(!((Z3)((_i)<(ZE5(0))))){Zp8=(Zo8)[_i];while(!((Zp8)==((void*)(Zo))))
{Zq8=((((ZB*)Zp8))->Zk1);ZP5=(Z3)((Z87((T7*)(((((ZB*)Zp8))->Zj1))))%(((C)->Z11)));((((ZB*)(((ZB*)Zp8))))->Zk1)=((((C)->Z01))[ZP5]);(((C)->Z01))[ZP5]=(Zp8);
Zp8=Zq8;}_i=(Z3)(((_i))-(ZE5(1)));}(C->Z31)=ZE5(-1);}T6 ZG8(ZH*C,T0*a1){T6 R=0;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));
Zg8=(((C)->Z01))[ZP5];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((ZB*)Zg8))->Zj1)),a1)))))){Zg8=((((ZB*)Zg8))->Zk1);}R=((T6)((Zg8)!=((void*)(Zo))));
return R;}void ZH8(ZH*C,T2 a1){T2 ZY6=0;int Zm8=0;ZY6=Zn8(a1);(C->Z01)=((ZN)(Zk(ZY6,sizeof(T0*))));(C->Z11)=ZY6;(C->Z31)=ZE5(-1);(C->Z21)=ZE5(0);
}void Zx8(T87*C,T10 a1,T0*a2,T0*a3){(C->Zi1)=a1;(C->Zj1)=a2;(C->Zk1)=a3;}void ZI8(T70*C){(C->Z72)=(Z3)(((((C)->Z72)))+(ZE5(1)));}T0*ZJ8(T70*C){
T0*R=Zo;R=ZK8(((C)->Z62),((C)->Z72));return R;}void ZL8(T70*C,T0*a1){(C->Z62)=a1;(C->Z72)=ZE5(1);}T6 ZM8(T70*C){T6 R=0;R=((T6)((Z3)((((C)->Z72))>((((T62*)(((C)->Z62)))->Z21)))));
return R;}void ZN8(ZJ*C){(C->Z72)=(Z3)(((((C)->Z72)))+(ZE5(1)));}T0*ZO8(ZJ*C){T0*R=Zo;R=ZP8(((C)->Z82),((C)->Z72));return R;}void ZK7(ZJ*C,T0*a1){
(C->Z82)=a1;(C->Z72)=ZQ8(((C)->Z82));}T6 ZR8(ZJ*C){T6 R=0;R=((T6)(!(ZS8(((C)->Z82),((C)->Z72)))));return R;}void ZT8(ZJ*C){(C->Z72)=ZQ8(((C)->Z82));
}T6 ZU8(T0*a1,T0*a2){T6 R=0;if((a1)==((void*)(a2))){R=((T6)(1));}else if((a1)==((void*)(Zo))){}else if((a2)==((void*)(Zo))){}else{R=((T6)(Za6(((T7*)a1),a2)));
}return R;}T0*ZV8(T66*C){T0*R=Zo;{T70*n=((T70*)Zh(sizeof(*n)));*n=M70;ZL8(n,(T0*)C);R=((T0*)n);}return R;}T2 ZW8(T66*C,T0*a1){T2 R=0;
T2 _i=0;_i=ZE5(1);while(!((Z3)((_i)>(((C)->Z21))))){if(ZU8(a1,ZX8(C,_i))){R=(Z3)(((R))+(ZE5(1)));}_i=(Z3)(((_i))+(ZE5(1)));}return R;
}T0*ZY8(T66*C,T2 a1){T0*R=Zo;ZZ8(C,a1);R=(((T67*)(((C)->Z41)))->Zj1);return R;}T0*Z_8(T66*C,T0*a1){T0*R=Zo;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));
Zg8=(((C)->Z01))[ZP5];while(!(Za6((T7*)(((((T67*)Zg8))->Zj1)),a1))){Zg8=((((T67*)Zg8))->Zk1);}R=((((T67*)Zg8))->Zi1);return R;}T0*ZX8(T66*C,T2
a1){T0*R=Zo;ZZ8(C,a1);R=(((T67*)(((C)->Z41)))->Zi1);return R;}void ZZ8(T66*C,T2 a1){if((a1)==((Z3)(((((C)->Z31)))+(ZE5(1))))){(C->Z31)=a1;
(C->Z41)=(((T67*)(((C)->Z41)))->Zk1);while(!((((C)->Z41))!=((void*)(Zo)))){(C->Z51)=(Z3)(((((C)->Z51)))+(ZE5(1)));(C->Z41)=(((C)->Z01))[((C)->Z51)];
}}else if((a1)==(((C)->Z31))){}else if((a1)==(ZE5(1))){(C->Z31)=ZE5(1);(C->Z51)=ZE5(0);(C->Z41)=(((C)->Z01))[((C)->Z51)];while(!((((C)->Z41))!=((void*)(Zo))))
{(C->Z51)=(Z3)(((((C)->Z51)))+(ZE5(1)));(C->Z41)=(((C)->Z01))[((C)->Z51)];}}else{ZZ8(C,(T2)(ZE5(1)));while(!((((C)->Z31))==(a1))){ZZ8(C,(Z3)(((((C)->Z31)))+((T2)(ZE5(1)))));
}}}T0*Z09(T66*C,T0*a1){T0*R=Zo;T2 _i=0;_i=ZE5(1);while(!(ZU8(a1,ZX8(C,_i)))){_i=(Z3)(((_i))+(ZE5(1)));}R=(((T67*)(((C)->Z41)))->Zj1);
return R;}void Z19(T66*C){Z29(C,Z98(193));}void Z39(T66*C){T2 _i=0;T2 ZP5=0;T2 ZY6=0;T68 Zo8=Zo;T0*Zp8=Zo;T0*Zq8=Zo;int Zm8=0;ZY6=Zn8((Z3)(((((C)->Z11)))+(ZE5(1))));
Zo8=((C)->Z01);(C->Z01)=(((void)(((C)->Z01))),((T68)(Zk(ZY6,sizeof(T0*)))));_i=(Z3)(((((C)->Z11)))-(ZE5(1)));(C->Z11)=ZY6;while(!((Z3)((_i)<(ZE5(0)))))
{Zp8=(Zo8)[_i];while(!((Zp8)==((void*)(Zo)))){Zq8=((((T67*)Zp8))->Zk1);ZP5=(Z3)((Z87((T7*)(((((T67*)Zp8))->Zj1))))%(((C)->Z11)));((((T67*)(((T67*)Zp8))))->Zk1)=((((C)->Z01))[ZP5]);
(((C)->Z01))[ZP5]=(Zp8);Zp8=Zq8;}_i=(Z3)(((_i))-(ZE5(1)));}(C->Z31)=ZE5(-1);}void Z49(T66*C,T0*a1,T0*a2){T2 ZP5=0;T0*Zg8=Zo;(C->Z31)=ZE5(-1);
if((((C)->Z11))==(((C)->Z21))){Z39(C);}ZP5=(Z3)((Z87(((T7*)a2)))%(((C)->Z11)));{T67*n=((T67*)Zh(sizeof(*n)));*n=M67;Zj8(n,a1,a2,(((C)->Z01))[ZP5]);
Zg8=((T0*)n);}(((C)->Z01))[ZP5]=(Zg8);(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));}void Z59(T66*C,T0*a1){T0*Zg8=Zo;T2 _i=0;T2 ZP5=0;_i=((C)->Z21);
Zg8=(((C)->Z01))[ZP5];while(!((Z3)((_i)<=(ZE5(0))))){while(!((Zg8)!=((void*)(Zo)))){ZP5=(Z3)(((ZP5))+(ZE5(1)));Zg8=(((C)->Z01))[ZP5];
}Zt7(a1,((((T67*)Zg8))->Zi1));Zg8=((((T67*)Zg8))->Zk1);_i=(Z3)(((_i))-(ZE5(1)));}}void Z29(T66*C,T2 a1){T2 ZY6=0;int Zm8=0;ZY6=Zn8(a1);
(C->Z01)=(((void)(((C)->Z01))),((T68)(Zk(ZY6,sizeof(T0*)))));(C->Z11)=ZY6;(C->Z31)=ZE5(-1);(C->Z21)=ZE5(0);}T0*Z69(T66*C,T0*a1){T0*R=Zo;
T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));Zg8=(((C)->Z01))[ZP5];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((T67*)Zg8))->Zj1)),a1))))))
{Zg8=((((T67*)Zg8))->Zk1);}if((Zg8)!=((void*)(Zo))){R=((((T67*)Zg8))->Zi1);}return R;}void ZF8(ZB*C,T0*a1,T0*a2,T0*a3){(C->Zi1)=a1;(C->Zj1)=a2;
(C->Zk1)=a3;}T0*Z79(T61*C,T0*a1){T0*R=Zo;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));Zg8=(((C)->Z01))[ZP5];while(!(Za6((T7*)(((((T64*)Zg8))->Zj1)),a1)))
{Zg8=((((T64*)Zg8))->Zk1);}R=((((T64*)Zg8))->Zi1);return R;}void Z89(T61*C,T0*a1,T0*a2){T2 ZP5=0;T0*Zg8=Zo;(C->Z31)=ZE5(-1);if((((C)->Z11))==(((C)->Z21))){
Z99(C);}ZP5=(Z3)((Z87(((T7*)a2)))%(((C)->Z11)));{T64*n=((T64*)Zh(sizeof(*n)));*n=M64;Za9(n,a1,a2,(((C)->Z01))[ZP5]);Zg8=((T0*)n);}(((C)->Z01))[ZP5]=(Zg8);
(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));}void Zb9(T61*C,T2 a1){T2 ZY6=0;int Zm8=0;ZY6=Zn8(a1);(C->Z01)=((T65)(Zk(ZY6,sizeof(T0*))));(C->Z11)=ZY6;
(C->Z31)=ZE5(-1);(C->Z21)=ZE5(0);}void Z99(T61*C){T2 _i=0;T2 ZP5=0;T2 ZY6=0;T65 Zo8=Zo;T0*Zp8=Zo;T0*Zq8=Zo;int Zm8=0;ZY6=Zn8((Z3)(((((C)->Z11)))+(ZE5(1))));
Zo8=((C)->Z01);(C->Z01)=((T65)(Zk(ZY6,sizeof(T0*))));_i=(Z3)(((((C)->Z11)))-(ZE5(1)));(C->Z11)=ZY6;while(!((Z3)((_i)<(ZE5(0))))){Zp8=(Zo8)[_i];
while(!((Zp8)==((void*)(Zo)))){Zq8=((((T64*)Zp8))->Zk1);ZP5=(Z3)((Z87((T7*)(((((T64*)Zp8))->Zj1))))%(((C)->Z11)));((((T64*)(((T64*)Zp8))))->Zk1)=((((C)->Z01))[ZP5]);
(((C)->Z01))[ZP5]=(Zp8);Zp8=Zq8;}_i=(Z3)(((_i))-(ZE5(1)));}(C->Z31)=ZE5(-1);}T6 Zc9(T61*C,T0*a1){T6 R=0;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));
Zg8=(((C)->Z01))[ZP5];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((T64*)Zg8))->Zj1)),a1)))))){Zg8=((((T64*)Zg8))->Zk1);}R=((T6)((Zg8)!=((void*)(Zo))));
return R;}void Zd9(T61*C,T0*a1,T0*a2){Z89(C,a1,a2);ZL7((T47*)(((C)->Z61)),a2);}void Ze9(T61*C,T2 a1){Zb9(C,a1);{T47*n=((T47*)Zh(sizeof(*n)));
*n=M47;ZM7(n,a1);(C->Z61)=((T0*)n);}}T0*Zf9(T61*C,T0*a1){T0*R=Zo;T2 ZP5=0;T0*Zg8=Zo;ZP5=(Z3)((Z87(((T7*)a1)))%(((C)->Z11)));Zg8=(((C)->Z01))[ZP5];
while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Za6((T7*)(((((T64*)Zg8))->Zj1)),a1)))))){Zg8=((((T64*)Zg8))->Zk1);}if((Zg8)!=((void*)(Zo))){
R=((((T64*)Zg8))->Zi1);}return R;}void Za9(T64*C,T0*a1,T0*a2,T0*a3){(C->Zi1)=a1;(C->Zj1)=a2;(C->Zk1)=a3;}void Zg9(T49*C){if(((C)->ZR1)){
Zh9((T31*)(Zi9),((T3)'\n'));}}void Zj9(T49*C,T0*a1){if(Zk9(a1)){Zl9(C,Zm9);Zl9(C,a1);Zl9(C,Zn9);{T0*b1=a1;Zo9(b1);}}}T6 Zk9(T0*a1){T6
R=0;R=((T6)(Zp9(a1)));return R;}void Zq9(T49*C,T0*a1,T0*a2){Zl9(C,Zr9);Zl9(C,a1);Zl9(C,Zs9);Zl9(C,a2);Zl9(C,Zn9);{T0*b1=a1;T0*b2=a2;Zt9(b1,b2);
}}T0*Zu9=Zo;int Zv9=0;T0*Zw9(void){if(Zv9==0){Zv9=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;Zu9=((T0*)n);Zx9(n);}}}return Zu9;}void Zy9(T49*C,T0*a1,T0*a2){
Zz9(((ZL*)a1),a2);if((((((ZL*)a1))->ZS1))!=(Zo)){Zl9(C,ZA9);Zl9(C,a2);Zl9(C,ZB9);}else{ZC9(ZD9);ZC9(a2);ZC9(Zn9);Zv(ZE5(1));}}void ZE9(T3
a1){{T3 b1=a1;ZF9(b1,ZG9);}ZH9(ZG9);}void ZI9(T49*C,T0*a1,T0*a2){Zl9(C,ZJ9);Zl9(C,a2);Zl9(C,Zn9);ZK9(((T55*)a1),a2);}T0*ZL9(T0*a1,T0*a2){
T0*R=Zo;int _s=0;if((T6)((Zf7(((T7*)ZM9),a1))||((T6)(Zf7(((T7*)ZN9),a1))))){ZC9(ZO9);ZC9(a1);ZC9(ZP9);if((a2)!=((void*)(Zo))){ZC9(ZQ9);
ZC9(a2);ZE9(((T3)'\042'));}else{ZE9(((T3)'\056'));}ZE9(((T3)'\n'));}R=ZR9(a1);if((T6)(((R)==((void*)(Zo)))&&((T6)(Zf7(((T7*)ZS9),a1))))){
R=ZL9(ZT9,a2);if((T6)(((R)!=((void*)(Zo)))&&((T6)((Z3)((((((T7*)R))->Z21))>(ZE5(9))))))){ZU9((T38*)(Zw9()),R);if((Z3)((((((T7*)R))->Z21))>(ZE5(3)))){
ZU9((T38*)(Zw9()),R);}}}if((R)==((void*)(Zo))){if(Zf7(((T7*)ZM9),a1)){R=ZR9(ZM9);if((R)!=((void*)(Zo))){ZC9(ZV9(77,"The old \"SmallEiffel\" variable is not valid anymore. Please use SmartEiffel.\n"));
}}else if(Zf7(((T7*)ZN9),a1)){R=ZL9(ZM9,a2);if((R)!=((void*)(Zo))){ZC9(ZV9(133,"The old \"SmallEiffelDirectory\" variable is not valid anymore. Please use SmartEiffelDirectory or,\nbetter still, don\'t use it at all.\n"));
if((Z3)((((((T7*)R))->Z21))>(ZE5(9)))){ZU9((T38*)(Zw9()),R);if((Z3)((((((T7*)R))->Z21))>(ZE5(3)))){ZU9((T38*)(Zw9()),R);}}}}}if((R)==((void*)(Zo))){
ZC9(ZW9);ZC9(a1);ZE9(((T3)'\175'));if((a2)!=((void*)(Zo))){ZC9(ZX9);ZC9(a2);ZE9(((T3)'\042'));}ZC9(ZY9);}return R;}T54 ZZ9=0;void Z_9(T49*C,T2
a1){if(((C)->ZR1)){Z0a((T31*)(Zi9),(T11)(a1));Z1a((T31*)(Zi9));}}T0*Zi9=Zo;void ZC9(T0*a1){Z2a(a1);ZH9(ZG9);}void Z3a(T49*C,T0*a1){T2
_i=0;T0*Z4a=Zo;int _s=0;if((ZK6(((T7*)a1)))==(((T3)'\n'))){Z97(((T7*)a1),(T2)(ZE5(1)));Z3a(C,a1);}else if(Za7(((T7*)a1),((T3)'\n'))){
_i=ZF6(((T7*)a1),((T3)'\n'));Z4a=ZI6(((T7*)a1),(Z3)(((_i))+((T2)(ZE5(1)))),((((T7*)a1))->Z21));Z97(((T7*)a1),(Z3)((((Z3)(((((((T7*)a1))->Z21)))-(_i))))+((T2)(ZE5(1)))));
Z3a(C,a1);Z3a(C,Z4a);}else{Zl9(C,Z5a);Zl9(C,a1);Zl9(C,Zn9);Z6a(a1);}}void Z7a(T2 a1){Z8a((T11)(a1));ZH9(ZG9);}void Zl9(T49*C,T0*a1){if(((C)->ZR1)){
Z9a((T31*)(Zi9),a1);Z1a((T31*)(Zi9));}}T0*Zaa=Zo;T0*Zba=Zo;T0*Zca=Zo;T0*Zda=Zo;T0*Zea(void){if(Zv9==0){Zv9=1;{{T38*n=((T38*)Zh(sizeof(*n)));
*n=M38;Zu9=((T0*)n);Zx9(n);}}}return Zu9;}void Zfa(T83*C){Zv8((T85*)(Zca),(T10)(ZE5(0)),Zga);Zv8((T85*)(Zca),(T10)(ZE5(1)),Zha);Zv8((T85*)(Zca),(T10)(ZE5(2)),Zia);
Zv8((T85*)(Zca),(T10)(ZE5(2)),Zja);Zv8((T85*)(Zca),(T10)(ZE5(3)),Zka);Zv8((T85*)(Zca),(T10)(ZE5(4)),Zla);Zv8((T85*)(Zca),(T10)(ZE5(5)),Zma);
Zv8((T85*)(Zca),(T10)(ZE5(6)),Zna);Zv8((T85*)(Zca),(T10)(ZE5(7)),Zoa);Zv8((T85*)(Zca),(T10)(ZE5(8)),Zpa);Zv8((T85*)(Zca),(T10)(ZE5(9)),Zqa);
Zv8((T85*)(Zca),(T10)(ZE5(10)),Zra);Zv8((T85*)(Zca),(T10)(ZE5(11)),Zsa);(C->Z71)=ZE5(11);if(!((((T84*)(Zda))->Zc2))){Zta(C);}}void Zta(T83*C){
T3 _cc=0;T0*Zua=Zo;T10 _id=0;T10 Zva=0;T0*Zwa=Zo;T1 Z27=0;T2 Zxa=0;Zxa=(T2)(((C)->Z71));{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;Zwa=((T0*)n);
}ZI9((T49*)(Zya()),Zwa,Zza((T38*)(Zea())));if((((((T55*)Zwa))->ZS1))!=(Zo)){if(((((T55*)Zwa))->Za1)){Z27=ZE5(6);}while(!((Z1)((Z27)>(ZE5(4)))))
{ZAa(((T55*)Zwa));if(((((T55*)Zwa))->Za1)){Z27=ZE5(5);}else{_cc=((((T55*)Zwa))->Z91);}{int z1=Z27;switch(z1){case 0:{int z2=_cc;switch(z2){
case 9:case 10:case 13:case 32:break;case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:_id=(T10)(ZH5(_cc));
Z27=ZE5(1);break;default:;Z27=ZE5(6);}}break;case 1:{int z2=_cc;switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case
55:case 56:case 57:_id=(Z2)((((Z2)(((_id))*(ZE5(10)))))+((T10)(ZH5(_cc))));break;case 34:Zua=Zba;((((T7*)(((T7*)Zua))))->Z21)=(ZE5(0));
Z27=ZE5(3);break;case 9:case 32:Z27=ZE5(2);break;default:;Z27=ZE5(6);}}break;case 2:{int z2=_cc;switch(z2){case 34:Zua=Zba;((((T7*)(((T7*)Zua))))->Z21)=(ZE5(0));
Z27=ZE5(3);break;case 9:case 10:case 13:case 32:break;default:;Z27=ZE5(6);}}break;case 3:{int z2=_cc;switch(z2){case 34:Zva=(Z2)(((Zva))+(ZE5(1)));
if((Z3)(((T2)(_id))>(Zxa))){Zua=(((void)((T89*)(ZBa()))),ZCa(Zua));Zv8((T85*)(Zca),_id,Zua);(C->Z71)=Z16(((C)->Z71),_id);}Z27=ZE5(4);
break;case 9:case 10:case 13:Z27=ZE5(6);break;default:;ZQ5(((T7*)Zua),_cc);}}break;case 4:{int z2=_cc;switch(z2){case 35:Z27=ZE5(0);break;
}}break;}}}ZDa(((T55*)Zwa));if((Z27)==(ZE5(6))){Zl9((T49*)(Zya()),ZV9(27,"Corrupted *.id file (after "));Z_9((T49*)(Zya()),(T2)(Zva));
Zl9((T49*)(Zya()),ZV9(17," correct items).\n"));}Zl9((T49*)(Zya()),ZEa);Z_9((T49*)(Zya()),(T2)(((C)->Z71)));Zl9((T49*)(Zya()),ZFa);}}
T0*ZGa=Zo;int ZHa=0;T0*Zya(void){if(ZHa==0){ZHa=1;{{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;ZGa=((T0*)n);}}}return ZGa;}T0*ZIa=Zo;int ZJa=0;
T0*ZBa(void){if(ZJa==0){ZJa=1;{{T89*n=((T89*)Zh(1));ZIa=((T0*)n);ZKa(ZLa);ZKa(ZMa);ZKa(ZNa);ZKa(ZOa);ZKa(Zna);ZKa(ZPa);ZKa(Zka);ZKa(ZQa);
ZKa(ZRa);ZKa(Zma);ZKa(ZSa);ZKa(ZTa);ZKa(ZUa);ZKa(ZVa);ZKa(ZWa);ZKa(ZXa);ZKa(Zha);ZKa(Zra);ZKa(Zja);ZKa(Zia);ZKa(Zsa);ZKa(ZYa);ZKa(ZZa);
ZKa(Z_a);ZKa(Zga);ZKa(Z0b);ZKa(Zpa);ZKa(Z1b);ZKa(Z2b);ZKa(Z3b);ZKa(Z4b);ZKa(Z5b);ZKa(Zla);ZKa(Z6b);ZKa(Z7b);ZKa(Z8b);ZKa(Zoa);ZKa(Z9b);
ZKa(Zab);ZKa(Zbb);ZKa(Zcb);ZKa(Zdb);ZKa(Zeb);ZKa(Zfb);ZKa(Zgb);ZKa(Zhb);ZKa(Zib);ZKa(Zjb);ZKa(Zkb);ZKa(Zlb);ZKa(Zmb);ZKa(Znb);ZKa(Zob);
ZKa(Zpb);ZKa(Zqb);ZKa(Zrb);ZKa(Zsb);ZKa(Ztb);ZKa(Zub);ZKa(Zvb);ZKa(Zwb);ZKa(Zxb);ZKa(Zyb);ZKa(Zzb);ZKa(ZAb);ZKa(ZBb);ZKa(ZCb);ZKa(ZDb);
ZKa(ZEb);ZKa(ZFb);ZKa(ZGb);ZKa(ZHb);ZKa(ZIb);ZKa(ZJb);ZKa(ZKb);ZKa(ZLb);ZKa(ZMb);ZKa(ZNb);ZKa(ZOb);ZKa(ZPb);ZKa(ZQb);ZKa(ZRb);ZKa(ZSb);
ZKa(ZTb);ZKa(ZUb);ZKa(ZVb);ZKa(ZWb);ZKa(ZXb);ZKa(ZYb);ZKa(ZZb);ZKa(Z_b);ZKa(Z0c);ZKa(Z1c);ZKa(Z2c);ZKa(Z3c);ZKa(Z4c);ZKa(Z5c);ZKa(Z6c);
ZKa(Z7c);ZKa(Z8c);ZKa(Z9c);ZKa(Zac);ZKa(Zbc);ZKa(Zcc);ZKa(Zdc);ZKa(Zec);ZKa(Zfc);ZKa(Zgc);ZKa(Zhc);ZKa(Zic);ZKa(Zjc);ZKa(Zkc);ZKa(Zlc);
ZKa(Zmc);ZKa(Znc);ZKa(Zoc);ZKa(Zpc);ZKa(Zqc);ZKa(Zrc);ZKa(Zsc);ZKa(Ztc);ZKa(Zuc);ZKa(Zvc);ZKa(Zwc);ZKa(Zxc);ZKa(Zyc);ZKa(Zzc);ZKa(ZAc);
ZKa(ZBc);ZKa(ZCc);ZKa(ZDc);ZKa(ZEc);ZKa(ZFc);ZKa(ZGc);ZKa(ZHc);ZKa(ZIc);ZKa(ZJc);ZKa(ZKc);ZKa(ZLc);ZKa(ZMc);ZKa(ZNc);ZKa(ZOc);ZKa(ZPc);
ZKa(ZQc);ZKa(ZRc);ZKa(ZSc);ZKa(ZTc);ZKa(ZUc);ZKa(ZVc);ZKa(ZWc);ZKa(ZXc);ZKa(ZYc);ZKa(ZZc);ZKa(Z_c);ZKa(Z0d);ZKa(Z1d);ZKa(Z2d);ZKa(Z3d);
ZKa(Z4d);ZKa(Z5d);ZKa(Z6d);ZKa(Z7d);ZKa(Z8d);ZKa(Z9d);ZKa(Zad);ZKa(Zbd);ZKa(Zcd);ZKa(Zdd);ZKa(Zed);ZKa(Zfd);ZKa(Zgd);ZKa(Zhd);ZKa(Zid);
ZKa(Zjd);ZKa(Zkd);ZKa(Zld);ZKa(Zmd);ZKa(Znd);ZKa(Zod);ZKa(Zpd);ZKa(Zqd);ZKa(Zrd);ZKa(Zsd);ZKa(Ztd);ZKa(Zud);ZKa(Zvd);ZKa(Zwd);ZKa(Zxd);
ZKa(Zyd);ZKa(Zzd);ZKa(ZAd);ZKa(Zqa);ZKa(ZBd);ZKa(ZCd);ZKa(ZDd);ZKa(ZEd);ZKa(ZFd);ZKa(ZGd);ZKa(ZHd);ZKa(ZId);ZKa(ZJd);ZKa(ZKd);ZKa(ZLd);
}}}return ZIa;}T0*ZMd(T10 a1){T0*R=Zo;R=Zy8((T85*)(Zca),a1);return R;}void ZNd(T37*C){if((Z3)(((((T31*)(Zi9))->Zd1))>(ZE5(0)))){Z1a((T31*)(Zi9));
}(C->Z81)=((T6)(0));if((Z3)((((C)->Zd1))>=(((C)->Ze1)))){ZOd(C);}(C->Z91)=(((C)->Zb1))[((C)->Zd1)];(C->Zd1)=(Z3)(((((C)->Zd1)))+(ZE5(1)));
(C->Za1)=((T6)(((C)->Zc1)));}void ZOd(T37*C){T3 ZPd=0;if((Z3)((((C)->Ze1))>(ZE5(0)))){ZPd=(((C)->Zb1))[(Z3)(((((C)->Ze1)))-(ZE5(1)))];
}(C->Ze1)=Zj5(((C)->Zb1),(T2)(Z98(4096)));(C->Zd1)=ZE5(0);if((Z3)((((C)->Ze1))<=(ZE5(0)))){(C->Zc1)=((T6)(1));(((C)->Zb1))[(T2)(ZE5(0))]=(ZPd);
(C->Ze1)=ZE5(1);(C->Zd1)=ZE5(1);}}void ZQd(T37*C){(C->Zb1)=((T9)(Zk(Z98(4096),sizeof(T3))));(C->Z11)=Z98(4096);}void ZRd(T37*C,T0*a1){
T2 _i=0;T6 Zt1=0;T2 ZSd=0;T2 ZTd=0;T2 ZUd=0;if((Z3)(((((T31*)(Zi9))->Zd1))>(ZE5(0)))){Z1a((T31*)(Zi9));}ZUd=((((T7*)a1))->Z21);while(!(Zt1))
{_i=((C)->Zd1);while(!((T6)(((Z3)((_i)>=(((C)->Ze1))))||((T6)(((((C)->Zb1))[_i])==(((T3)'\n'))))))){_i=(Z3)(((_i))+(ZE5(1)));}if((Z3)((_i)>(((C)->Zd1)))){
ZSd=((((T7*)a1))->Z21);ZTd=(Z3)((((Z3)(((ZSd))+(_i))))-(((C)->Zd1)));if((Z3)((((((T7*)a1))->Z11))<(ZTd))){Zh7(((T7*)a1),ZT5((Z3)(((ZSd))*((T2)(ZE5(2)))),ZTd));
}Zi6(((((T7*)a1))->Zl1),ZSd,((C)->Zb1),((C)->Zd1),(Z3)(((_i))-((T2)(ZE5(1)))));((((T7*)(((T7*)a1))))->Z21)=(ZTd);}if((T6)(((Z3)((_i)<(((C)->Ze1))))&&((T6)(((((C)->Zb1))[_i])==(((T3)'\n')))))){
Zt1=((T6)(1));(C->Zd1)=(Z3)(((_i))+(ZE5(1)));if((T6)(((Z3)((((((T7*)a1))->Z21))>(ZUd)))&&((T6)((ZK6(((T7*)a1)))==(((T3)'\015')))))){Z97(((T7*)a1),(T2)(ZE5(1)));
}}else{if(!(((C)->Zc1))){ZOd(C);}Zt1=((T6)(((C)->Zc1)));}}(C->Z81)=((T6)(0));(C->Za1)=((T6)(((C)->Zc1)));}void ZVd(T91*C,T74 a1,T0*a2){
(C->ZV)=a1;{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;Z68(n,(T2)(ZE5(4)),(T2)(ZE5(1)));(C->Zh1)=((T0*)n);}Z08((T42*)(((C)->Zh1)),a2);}void ZDa(T55*C){
ZWd(((C)->ZT1));(C->ZS1)=Zo;}void ZAa(T55*C){(C->Z81)=((T6)(0));if((Z3)((((C)->Zd1))>=(((C)->Ze1)))){ZXd(C);}(C->Z91)=(((C)->Zb1))[((C)->Zd1)];
(C->Zd1)=(Z3)(((((C)->Zd1)))+(ZE5(1)));(C->Za1)=((T6)(((C)->Zc1)));}void ZXd(T55*C){T3 ZPd=0;if((Z3)((((C)->Ze1))>(ZE5(0)))){ZPd=(((C)->Zb1))[(Z3)(((((C)->Ze1)))-(ZE5(1)))];
}(C->Ze1)=ZYd(((C)->Zb1),((C)->Z11),((C)->ZT1));(C->Zd1)=ZE5(0);if((Z3)((((C)->Ze1))<=(ZE5(0)))){(C->Zc1)=((T6)(1));(((C)->Zb1))[(T2)(ZE5(0))]=(ZPd);
(C->Ze1)=ZE5(1);(C->Zd1)=ZE5(1);}}void ZZd(T55*C,T0*a1){T2 _i=0;T6 Zt1=0;T2 ZSd=0;T2 ZTd=0;T2 ZUd=0;ZUd=((((T7*)a1))->Z21);while(!(Zt1))
{_i=((C)->Zd1);while(!((T6)(((Z3)((_i)>=(((C)->Ze1))))||((T6)(((((C)->Zb1))[_i])==(((T3)'\n'))))))){_i=(Z3)(((_i))+(ZE5(1)));}if((Z3)((_i)>(((C)->Zd1)))){
ZSd=((((T7*)a1))->Z21);ZTd=(Z3)((((Z3)(((ZSd))+(_i))))-(((C)->Zd1)));if((Z3)((((((T7*)a1))->Z11))<(ZTd))){Zh7(((T7*)a1),ZT5((Z3)(((ZSd))*((T2)(ZE5(2)))),ZTd));
}Zi6(((((T7*)a1))->Zl1),ZSd,((C)->Zb1),((C)->Zd1),(Z3)(((_i))-((T2)(ZE5(1)))));((((T7*)(((T7*)a1))))->Z21)=(ZTd);}if((T6)(((Z3)((_i)<(((C)->Ze1))))&&((T6)(((((C)->Zb1))[_i])==(((T3)'\n')))))){
Zt1=((T6)(1));(C->Zd1)=(Z3)(((_i))+(ZE5(1)));if((T6)(((Z3)((((((T7*)a1))->Z21))>(ZUd)))&&((T6)((ZK6(((T7*)a1)))==(((T3)'\015')))))){Z97(((T7*)a1),(T2)(ZE5(1)));
}}else{if(!(((C)->Zc1))){ZXd(C);}Zt1=((T6)(((C)->Zc1)));}}(C->Z81)=((T6)(0));(C->Za1)=((T6)(((C)->Zc1)));}void ZK9(T55*C,T0*a1){T8 _p=Zo;
_p=Zl7(((T7*)a1));(C->ZT1)=Z_d(_p);if((Zo!=((C)->ZT1))){(C->Z81)=((T6)(0));(C->Za1)=((T6)(0));(C->ZS1)=a1;if((((C)->Z11))==(ZE5(0))){
(C->Zb1)=((T9)(Zk(Z98(4096),sizeof(T3))));(C->Z11)=Z98(4096);}(C->Zc1)=((T6)(0));(C->Zd1)=ZE5(0);(C->Ze1)=ZE5(0);}}void Z0e(T55*C){((((T7*)((T7*)(Z1e))))->Z21)=(ZE5(0));
ZZd(C,Z1e);}T0*Z1e=Zo;void Z2e(T0*a1,T0*a2){if(!((((((T7*)a2))->Z21))==(ZE5(0)))){if(((((((T7*)a2))->Zl1))[ZE5(0)])!=(((T3)'\040'))){
if(!((((((T7*)a1))->Z21))==(ZE5(0)))){Ze7(((T7*)a1),((T3)'\040'));}}ZV6(((T7*)a1),a2);}}int Z3e=0;void Z4e(T38*C){if(Z3e==0){Z3e=1;{if(!((((((T7*)Z5e))->Z21))==(ZE5(0)))){
if((((C)->Z02))!=((void*)(Zo))){Zl9((T49*)(Z6e()),Z7e);Zl9((T49*)(Z6e()),((C)->Z02));(C->ZY1)=((C)->Z02);(C->ZZ1)=((C)->Z12);(C->Z_1)=((C)->Z22);
if((((C)->Z32))!=((void*)(Zo))){ZH6((T7*)(Z8e),((C)->Z32));}else if(!((((((T7*)Z9e))->Z21))==(ZE5(0)))){ZH6((T7*)(Z8e),Z9e);}if((((C)->Z42))!=((void*)(Zo))){
ZH6((T7*)(Zae),((C)->Z42));}else if(!((((((T7*)Zbe))->Z21))==(ZE5(0)))){ZH6((T7*)(Zae),Zbe);}Zl9((T49*)(Z6e()),Zce);}else{{T0*b1=((C)->ZY1);
ZV6((T7*)(Zde),b1);}{T0*b1=Zee;ZV6((T7*)(Zde),b1);}Zfe((T73*)(Zge));}}}}}T0*Zhe=Zo;T0*Zie=Zo;int Zje=0;T0*Zke(void){if(Zje==0){Zje=1;{
Zie=Zle(10,Zme,Zne,Zoe,Zpe,Zqe,Zre,Zse,Zte,Zue,Zve);}}return Zie;}T6 Zwe=0;int Zxe=0;T6 Zye(void){if(Zxe==0){Zxe=1;{Zwe=((T6)(Zp9(Zze)));
}}return Zwe;}T0*ZAe=Zo;T0*ZBe(T38*C,T0*a1){T0*R=Zo;R=ZV9(33,ZA3);((((T7*)(((T7*)R))))->Z21)=(ZE5(0));Z4e(C);if((T6)(((((C)->ZY1))==((void*)(ZCe)))||((T6)((((C)->ZY1))==((void*)(ZDe)))))){
ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);ZEe(C,R);Z2e(R,ZFe);Z2e(R,a1);Z2e(R,ZGe);if(!((((((T7*)Z5e))->Z21))==(ZE5(0)))){Z2e(R,ZHe);Z2e(R,Z5e);
}Z2e(R,ZIe);Z2e(R,ZJe);Z2e(R,ZKe);Z2e(R,ZLe);Z2e(R,ZMe);}else if((((C)->ZY1))==((void*)(ZNe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);
Z2e(R,a1);ZQ5(((T7*)R),((T3)'\n'));ZOe(C,R);ZV6(((T7*)R),ZPe);if(!(((C)->ZU1))){Z2e(R,ZQe);}ZEe(C,R);{T7*C1=((T7*)a1);T0*b1=ZRe;Z97(C1,((((T7*)b1))->Z21));
}ZV6(((T7*)a1),ZSe(C));Z2e(R,a1);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(ZTe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);
Z2e(R,ZMe);ZEe(C,R);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(ZUe))){ZV6(((T7*)R),((C)->ZZ1));
Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,ZMe);ZEe(C,R);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(ZVe))){
ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,ZMe);ZEe(C,R);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);ZWe(C);}else
if((((C)->ZY1))==((void*)(ZXe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);ZEe(C,R);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZYe);
Z2e(R,ZMe);Z2e(R,ZKe);ZWe(C);}else if((((C)->ZY1))==((void*)(ZZe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z_e((T6)(0)));Z2e(R,Z8e);Z2e(R,ZLe);
Z2e(R,ZMe);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);ZWe(C);ZEe(C,R);}else if((((C)->ZY1))==((void*)(Z0f))){ZV6(((T7*)R),((C)->ZZ1));
Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,ZMe);ZEe(C,R);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);ZWe(C);if(((C)->ZU1)){Z2e(R,Z1f);}}else
if((((C)->ZY1))==((void*)(Z2f))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,ZMe);ZEe(C,R);ZWe(C);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);
Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(Z3f))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,ZMe);ZEe(C,R);Z2e(R,a1);
Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(Z4f))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,ZMe);
ZEe(C,R);Z2e(R,a1);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(Z5f))){ZV6(((T7*)R),Z6f);ZV6(((T7*)R),a1);
ZV6(((T7*)R),((C)->ZZ1));Z97(((T7*)R),(T2)(ZE5(2)));ZV6(((T7*)R),Z7f);ZEe(C,R);ZQ5(((T7*)R),((T3)'\040'));ZV6(((T7*)R),a1);Z97(((T7*)R),(T2)(ZE5(2)));
}else if((((C)->ZY1))==((void*)(Z8f))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,ZMe);ZEe(C,R);Z2e(R,ZKe);Z2e(R,a1);Z2e(R,ZGe);
Z2e(R,ZJe);}return R;}void ZEe(T38*C,T0*a1){T0*Zg1=Zo;Zg1=Z9f;if(((((T82*)(Zaf))->Zg1))==((void*)(Zo))){ZH6(((T7*)Zg1),Zn7((T7*)(Zbf())));
Zm7(((T7*)Zg1));if((((C)->ZY1))==((void*)(ZNe))){Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZVe))){Z2e(a1,Zef);
ZV6(((T7*)a1),Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZUe))){Z2e(a1,Zff);ZV6(((T7*)a1),Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZZe))){
Zg1=Zn7((T7*)(Zbf()));Zm7(((T7*)Zg1));ZV6(((T7*)a1),Zgf);Z2e(a1,Zg1);}else if((((C)->ZY1))==((void*)(Z0f))){Z2e(a1,Zcf);Z2e(a1,Zg1);}
else if((((C)->ZY1))==((void*)(Z2f))){Z2e(a1,Zcf);Z2e(a1,Zg1);}else if((((C)->ZY1))==((void*)(Z4f))){Z2e(a1,Zcf);Z2e(a1,Zg1);}else if((((C)->ZY1))==((void*)(Z5f))){
Z2e(a1,Zg1);}else if((((C)->ZY1))==((void*)(Z8f))){if((((C)->ZJ1))==((void*)(Zme))){Z2e(a1,Zcf);Z2e(a1,Zhf);}else{Z2e(a1,Zcf);Z2e(a1,Zg1);
Zdf(C,a1);}}}else{ZH6(((T7*)Zg1),(((T82*)(Zaf))->Zg1));if((T6)(((((C)->ZY1))==((void*)(ZCe)))||((T6)((((C)->ZY1))==((void*)(ZDe)))))){
Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZNe))){Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZTe))){
Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZUe))){Z2e(a1,Zif);ZV6(((T7*)a1),Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZVe))){
Z2e(a1,Zef);ZV6(((T7*)a1),Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZXe))){Z2e(a1,Zcf);ZV6(((T7*)a1),Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(ZZe))){
ZV6(((T7*)a1),Zgf);Z2e(a1,Zg1);}else if((((C)->ZY1))==((void*)(Z0f))){Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(Z2f))){
Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(Z3f))){Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(Z4f))){
Z2e(a1,Zcf);Z2e(a1,Zg1);Zdf(C,a1);}else if((((C)->ZY1))==((void*)(Z5f))){ZV6(((T7*)a1),Zg1);}else if((((C)->ZY1))==((void*)(Z8f))){Z2e(a1,Zcf);
Z2e(a1,Zg1);Zdf(C,a1);}}}T6 Zjf(T0*a1){T6 R=0;R=((T6)(Zp9(a1)));return R;}void Zdf(T38*C,T0*a1){T0*Zkf=Zo;Zkf=Zlf(C);if(!(Z07(((T7*)a1),Zkf))){
ZV6(((T7*)a1),Zkf);}}T0*Zmf(T38*C){T0*R=Zo;R=Zn7((T7*)(Zbf()));Zm7(((T7*)R));if((Zse)==((void*)(((C)->ZJ1)))){while(!((Z3)((((((T7*)R))->Z21))<=(ZE5(4)))))
{Z97(((T7*)R),(T2)(ZE5(1)));}}ZV6(((T7*)R),Znf);return R;}void ZOe(T38*C,T0*a1){T0*Zof=Zo;T0*Zx2=Zo;T2 _i=0;if(!((((((T7*)ZGe))->Z21))==(ZE5(0)))){
Zof=ZQ6(((T7*)ZGe));((((T7*)((T7*)(ZGe))))->Z21)=(ZE5(0));if((Zof)!=((void*)(Zo))){_i=((((T42*)Zof))->ZV2);while(!((Z3)((_i)>(((((T42*)Zof))->Zm1)))))
{Zx2=ZU7(((T42*)Zof),_i);ZV6(((T7*)a1),Zpf);Z2e(a1,Z8e);Z2e(a1,Zx2);ZQ5(((T7*)a1),((T3)'\n'));{T7*C1=((T7*)Zx2);T0*b1=ZRe;Z97(C1,((((T7*)b1))->Z21));
}ZV6(((T7*)Zx2),ZSe(C));Z2e(ZJe,Zx2);_i=(Z3)(((_i))+(ZE5(1)));}}}}T0*Zqf=Zo;int Zrf=0;T0*Zza(T38*C){if(Zrf==0){Zrf=1;{Zqf=Zmf(C);{T7*C1=((T7*)Zqf);
T0*b1=Znf;Z97(C1,((((T7*)b1))->Z21));}ZV6(((T7*)Zqf),Zsf);}}return Zqf;}void Ztf(T38*C){if((Zpe)==((void*)(((C)->ZJ1)))){}else if((T6)(((((C)->ZY1))==((void*)(ZCe)))||((T6)((((C)->ZY1))==((void*)(ZDe)))))){
Zuf(C,Zvf);}else if((((C)->ZY1))==((void*)(ZVe))){}else if((((C)->ZY1))==((void*)(ZXe))){}else if((((C)->ZY1))==((void*)(ZZe))){}else
if((((C)->ZY1))==((void*)(Z0f))){Zuf(C,Zvf);}else if((((C)->ZY1))==((void*)(Z2f))){if((Zre)==((void*)(((C)->ZJ1)))){Zuf(C,Zwf);}else{
Zuf(C,Zvf);}}else if((((C)->ZY1))==((void*)(Z3f))){Zuf(C,Zxf);}else if((((C)->ZY1))==((void*)(Z4f))){}else if((((C)->ZY1))==((void*)(Z5f))){
}else if((((C)->ZY1))==((void*)(Z8f))){Zuf(C,Zvf);}else if((((C)->ZY1))==((void*)(ZTe))){Zuf(C,Zvf);}else if((((C)->ZY1))==((void*)(ZNe))){
}else if((((C)->ZY1))==((void*)(ZUe))){}}void Zyf(T38*C){T2 _i=0;_i=ZW7((T42*)(Zke()),((C)->ZJ1));if((Z3)((_i)>((((T42*)(Zke()))->Zm1)))){
(((void)((T49*)(Z6e()))),ZC9(Zzf));(((void)((T49*)(Z6e()))),ZC9((((T55*)(Zhe))->ZS1)));(((void)((T49*)(Z6e()))),ZC9(ZAf));_i=ZE5(1);while(!((Z3)((_i)>((((T42*)(Zke()))->Zm1)))))
{(((void)((T49*)(Z6e()))),ZC9(ZU7((T42*)(Zke()),_i)));(((void)((T49*)(Z6e()))),ZE9(((T3)'\n')));_i=(Z3)(((_i))+(ZE5(1)));}Zv(ZE5(1));
}else{ZBf(C,ZU7((T42*)(Zke()),_i));Zl9((T49*)(Z6e()),ZCf);Zl9((T49*)(Z6e()),((C)->ZJ1));Zl9((T49*)(Z6e()),Zn9);}}void ZDf(T38*C){if((((C)->ZJ1))==((void*)(Zo))){
if(ZEf()){if(ZFf()){ZBf(C,Zme);}else if(ZGf()){ZBf(C,Zoe);}else if(ZHf()){ZBf(C,Zne);}else if(ZIf()){ZBf(C,Zqe);}else if(ZJf()){ZBf(C,Zre);
}else if(ZKf()){ZBf(C,Zue);}}}ZLf(ZMf);}T0*ZNf=Zo;T0*ZOf=Zo;T0*ZPf=Zo;int ZQf=0;T0*ZRf(void){if(ZQf==0){ZQf=1;{{T45*n=((T45*)Zh(sizeof(*n)));
*n=M45;ZPf=((T0*)n);ZSf(n);}}}return ZPf;}T0*ZTf=Zo;void ZUf(T0*a1,T0*a2){T2 _i=0;T2 Z27=0;T2 ZVf=0;T2 ZWf=0;T3 _c=0;T0*Z37=Zo;T0*ZXf=Zo;
_i=ZE5(1);while(!((Z3)((_i)>(((((T7*)a2))->Z21))))){_c=(((((T7*)a2))->Zl1))[(_i)-(ZE5(1))];{int z1=Z27;switch(z1){case 0:if((_c)==(((T3)'\044'))){
Z27=ZE5(1);ZVf=_i;}break;case 1:if((_c)==(((T3)'\173'))){Z27=ZE5(2);{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(8)));ZXf=((T0*)n);
}}else{Z27=ZE5(0);}break;case 2:if((_c)==(((T3)'\175'))){Z27=ZE5(3);ZWf=_i;}else{ZQ5(((T7*)ZXf),_c);}break;}}_i=(Z3)(((_i))+(ZE5(1)));
}if((Z27)==(ZE5(3))){Z37=(((void)((T49*)(Z6e()))),ZL9(ZXf,a1));if((Z37)!=((void*)(Zo))){ZH6(((T7*)ZXf),a2);Zb7(((T7*)a2),(Z3)(((ZVf))-((T2)(ZE5(1)))));
ZV6(((T7*)a2),Z37);ZL6(((T7*)ZXf),ZWf);ZV6(((T7*)a2),ZXf);ZUf(a1,a2);}}}T0*ZYf(T38*C,T0*a1){T0*R=Zo;R=ZZf;((((T7*)(((T7*)R))))->Z21)=(ZE5(0));
Z4e(C);if((T6)(((((C)->ZY1))==((void*)(ZCe)))||((T6)((((C)->ZY1))==((void*)(ZDe)))))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);
Z2e(R,Z_f);Z2e(R,Z0g);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(ZNe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,a1);}else
if((((C)->ZY1))==((void*)(ZTe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(ZUe))){
ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,Z1g);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(ZVe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);
Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(ZXe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,a1);
}else if((((C)->ZY1))==((void*)(ZZe))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z_e((T6)(1)));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(Z0f))){
ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(Z2f))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);
Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(Z3f))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,a1);
}else if((((C)->ZY1))==((void*)(Z4f))){ZV6(((T7*)R),((C)->ZZ1));Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,a1);}else if((((C)->ZY1))==((void*)(Z5f))){
ZV6(((T7*)R),Z2g);ZV6(((T7*)R),a1);ZV6(((T7*)R),((C)->ZZ1));Z97(((T7*)R),(T2)(ZE5(2)));}else if((((C)->ZY1))==((void*)(Z8f))){ZV6(((T7*)R),((C)->ZZ1));
Z2e(R,Z8e);Z2e(R,ZLe);Z2e(R,Z_f);Z2e(R,Zcf);Z2e(R,a1);Z97(((T7*)R),(T2)(ZE5(2)));ZV6(((T7*)R),ZSe(C));Z2e(R,a1);}return R;}void Z3g(T38*C,T0*a1,T0*a2,T2
a3,T2 a4){T2 _c=0;T2 _i1=0;T2 _i2=0;T2 Z4g=0;if((Z3)((a3)>(a4))){}else if((Z3)((a3)<(ZE5(9)))){Z2e(a1,a2);ZV6(((T7*)a1),Z5g);_i1=ZV5(ZE5(9),a4);
ZY5(_i1,a1);ZQ5(((T7*)a1),((T3)'\135'));ZV6(((T7*)a1),ZSe(C));Z3g(C,a1,a2,(Z3)(((_i1))+((T2)(ZE5(1)))),a4);}else if((a3)==(a4)){Z2e(a1,a2);
ZY5(a3,a1);ZV6(((T7*)a1),ZSe(C));}else{_c=(Z3)((((Z3)(((a4))-(a3))))+(ZE5(1)));if((Z3)((_c)<=(ZE5(10)))){_i1=(Z3)((a3)/(ZE5(10)));_i2=(Z3)((a4)%(ZE5(10)));
Z2e(a1,a2);ZY5(_i1,a1);ZQ5(((T7*)a1),((T3)'\133'));ZQ5(((T7*)a1),((T3)'0'));ZQ5(((T7*)a1),((T3)'\055'));ZY5(_i2,a1);ZQ5(((T7*)a1),((T3)'\135'));
ZV6(((T7*)a1),ZSe(C));}else if((Z3)((_c)<(ZE5(20)))){Z3g(C,a1,a2,a3,(Z3)(((a3))+((T2)(ZE5(9)))));Z3g(C,a1,a2,(Z3)(((a3))+((T2)(ZE5(10)))),a4);
}else{_i1=(Z3)((a3)/(ZE5(10)));_i2=(Z3)(((Z3)(((a4))-(ZE5(9))))/(ZE5(10)));Z2e(a1,a2);ZQ5(((T7*)a1),((T3)'\133'));ZY5(_i1,a1);ZQ5(((T7*)a1),((T3)'\055'));
ZY5(_i2,a1);ZV6(((T7*)a1),Z6g);ZV6(((T7*)a1),ZSe(C));Z4g=(Z3)((((Z3)(((_i2))*(ZE5(10)))))+(ZE5(10)));Z3g(C,a1,a2,Z4g,a4);}}}T0*Z7g=Zo;
int Z8g=0;T0*Z9g(void){if(Z8g==0){Z8g=1;{{T72*n=((T72*)Zh(sizeof(*n)));*n=M72;Z7g=((T0*)n);Zag(n);}}}return Z7g;}T0*Zbg=Zo;int Zcg=0;
T0*ZSe(T38*C){if(Zcg==0){Zcg=1;{if((T6)(((((C)->ZY1))==((void*)(ZCe)))||((T6)((((C)->ZY1))==((void*)(ZDe)))))){Zbg=Zdg;}else if((((C)->ZY1))==((void*)(ZNe))){
Zbg=Zeg;}else if((((C)->ZY1))==((void*)(ZTe))){Zbg=Zdg;}else if((((C)->ZY1))==((void*)(ZUe))){Zbg=Zeg;}else if((((C)->ZY1))==((void*)(ZVe))){
Zbg=Zeg;}else if((((C)->ZY1))==((void*)(ZXe))){Zbg=Zeg;}else if((((C)->ZY1))==((void*)(ZZe))){Zbg=Zdg;}else if((((C)->ZY1))==((void*)(Z0f))){
Zbg=Zdg;}else if((((C)->ZY1))==((void*)(Z2f))){Zbg=Zdg;}else if((((C)->ZY1))==((void*)(Z3f))){Zbg=Zdg;}else if((((C)->ZY1))==((void*)(Z4f))){
Zbg=Zdg;}else if((((C)->ZY1))==((void*)(Z5f))){Zbg=Zeg;Zi7(((T7*)Zbg));}else if((((C)->ZY1))==((void*)(Z8f))){Zbg=Zdg;}}}return Zbg;}
void Zx9(T38*C){T0*Zfg=Zo;T0*Zgg=Zo;T2 _i=0;T6 Zhg=0;T6 Zig=0;Zjg((T45*)(ZRf()));if((((T45*)(ZRf()))->Zf2)){ZH6((T7*)(Zkg),(((T45*)(ZRf()))->ZS1));
}(C->ZX1)=ZE5(1);Zgg=Zlg(C);_i=ZE5(0);while(!((T6)(((T6)((Zhg)||((T6)((Z3)((_i)>(((((T47*)Zgg))->Zm1)))))))||((T6)(((((T7*)((((((T47*)Zgg))->Zl1))[_i]))->Z21))==(ZE5(0)))))))
{Zfg=(((((T47*)Zgg))->Zl1))[_i];if(Zp9(Zfg)){(C->Zv1)=Zfg;Zmg(C);Zhg=((T6)(1));}_i=(Z3)(((_i))+(ZE5(1)));}if((T6)((!(Zhg))||((T6)((((T51*)(Zng))->Zr2))))){
if((Zog)!=((void*)(Zo))){(C->Zv1)=Zog;}else{(C->Zv1)=Zpg;}if((((T53*)(ZOf))->Zi1)){ZDf(C);}else{if((Zog)!=((void*)(Zo))){(((void)((T49*)(Z6e()))),ZC9(Zqg));
(((void)((T49*)(Z6e()))),ZC9(Zrg));(((void)((T49*)(Z6e()))),ZC9(Zsg));Zig=((T6)(1));_i=ZE5(1);}else{_i=ZE5(0);}if((Z3)((_i)<=(((((T47*)Zgg))->Zm1)))){
(((void)((T49*)(Z6e()))),ZC9(Ztg));while(!((T6)(((Z3)((_i)>(((((T47*)Zgg))->Zm1))))||((T6)(((((T7*)((((((T47*)Zgg))->Zl1))[_i]))->Z21))==(ZE5(0)))))))
{(((void)((T49*)(Z6e()))),ZC9(Zug));(((void)((T49*)(Z6e()))),ZC9((((((T47*)Zgg))->Zl1))[_i]));(((void)((T49*)(Z6e()))),ZE9(((T3)'\n')));
_i=(Z3)(((_i))+(ZE5(1)));}Zig=((T6)(1));}if(!(Zig)){(((void)((T49*)(Z6e()))),ZC9(Zvg));(((void)((T49*)(Z6e()))),ZC9(Zrg));(((void)((T49*)(Z6e()))),ZC9(Zwg));
}if(!((((T53*)(ZOf))->Zi1))){Zv(ZE5(1));}}}Zl9((T49*)(Z6e()),Zxg);Zl9((T49*)(Z6e()),((C)->Zv1));Zg9((T49*)(Z6e()));}T0*Zlg(T38*C){T0*R=Zo;
T2 _i=0;T0*_s=Zo;T0*Zyg=Zo;(C->Zv1)=Zog;R=Zzg;_i=ZE5(0);if((((C)->Zv1))!=((void*)(Zo))){if(((Z3)(((((((T47*)R))->Zm1)))+(ZE5(1))))==(ZE5(0))){
ZL7(((T47*)R),Zn7((T7*)(((C)->Zv1))));}else{ZH6((T7*)((((((T47*)R))->Zl1))[ZE5(0)]),((C)->Zv1));}_i=(Z3)(((_i))+(ZE5(1)));}ZAg(&(((C)->Zr1)));
ZBg(ZCg);ZDg(&(((C)->Zr1)));if(ZEf()){if((T6)((ZFf())||((T6)(ZGf())))){Zyg=ZEg;if((Zyg)!=((void*)(Zo))){if((Z3)((((((T47*)R))->Zm1))>=(_i))){
ZH6((T7*)((((((T47*)R))->Zl1))[_i]),Zyg);ZV6((T7*)((((((T47*)R))->Zl1))[_i]),ZFg);}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,Zyg);
_s=((T0*)n);}ZV6(((T7*)_s),ZGg);ZL7(((T47*)R),_s);}_i=(Z3)(((_i))+(ZE5(1)));}if(Zjf(ZHg)){ZBf(C,Zve);_s=ZIg;if((Z3)((((((T47*)R))->Zm1))>=(_i))){
ZH6((T7*)((((((T47*)R))->Zl1))[_i]),_s);}else{ZL7(((T47*)R),Zn7(((T7*)_s)));}_i=(Z3)(((_i))+(ZE5(1)));}_s=ZJg;if((Z3)((((((T47*)R))->Zm1))>=(_i))){
ZH6((T7*)((((((T47*)R))->Zl1))[_i]),_s);}else{ZL7(((T47*)R),Zn7(((T7*)_s)));}_i=(Z3)(((_i))+(ZE5(1)));}else if(ZHf()){Zyg=ZAe;if((Zyg)!=((void*)(Zo))){
if((Z3)((((((T47*)R))->Zm1))>=(_i))){ZH6((T7*)((((((T47*)R))->Zl1))[_i]),Zyg);ZV6((T7*)((((((T47*)R))->Zl1))[_i]),ZKg);}else{{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZH6(n,Zyg);_s=((T0*)n);}ZV6(((T7*)_s),ZLg);ZL7(((T47*)R),_s);}_i=(Z3)(((_i))+(ZE5(1)));}_s=ZMg;if((Z3)((((((T47*)R))->Zm1))>=(_i))){
ZH6((T7*)((((((T47*)R))->Zl1))[_i]),_s);}else{ZL7(((T47*)R),Zn7(((T7*)_s)));}_i=(Z3)(((_i))+(ZE5(1)));}else if(ZIf()){}else if(ZJf()){
}else if(ZKf()){}}if((((C)->Zx1))!=((void*)(Zo))){ZNg(((C)->Zx1),ZOg);if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){if((Z3)((((((T47*)R))->Zm1))>=(_i))){
ZH6((T7*)((((((T47*)R))->Zl1))[_i]),ZCg);}else{ZL7(((T47*)R),Zn7((T7*)(ZCg)));}_i=(Z3)(((_i))+(ZE5(1)));}}while(!((Z3)((_i)>(((((T47*)R))->Zm1)))))
{((((T7*)((T7*)((((((T47*)R))->Zl1))[_i]))))->Z21)=(ZE5(0));_i=(Z3)(((_i))+(ZE5(1)));}return R;}void ZU9(T38*C,T0*a1){ZPg(C);ZQg(a1);
ZH6(((T7*)a1),ZCg);}T0*Z6e(void){if(ZHa==0){ZHa=1;{{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;ZGa=((T0*)n);}}}return ZGa;}T0*ZRg=Zo;void Zuf(T38*C,T0*a1){
((((T7*)((T7*)(ZTf))))->Z21)=(ZE5(0));if((T6)(((T6)(((((C)->ZY1))==((void*)(ZNe)))||((T6)((((C)->ZY1))==((void*)(ZXe))))))||((T6)((((C)->ZY1))==((void*)(ZVe)))))){
}else{if(((((((T7*)a1))->Zl1))[(ZE5(1))-(ZE5(1))])!=(((T3)'\055'))){if((T6)((!(Za7(((T7*)a1),((T3)'\057'))))&&((T6)(!(Za7(((T7*)a1),((T3)'\134'))))))){
ZH6((T7*)(ZTf),ZSg);}}}Z67((T7*)(ZTf),a1);Ze7((T7*)(ZTf),((T3)'\040'));ZTg(ZKe,ZTf);}void ZUg(T38*C,T0*a1,T0*a2){if((((C)->ZJ1))==((void*)(Zue))){
ZV6(((T7*)a1),ZVg);}ZV6(((T7*)a1),((C)->Zw1));ZV6(((T7*)a1),a2);ZV6(((T7*)a1),Zlf(C));}T0*Zkg=Zo;T0*Zaf=Zo;void ZWg(T38*C){T0*_i=Zo;_i=ZXg((T51*)(Zng),ZYg);
if((_i)!=((void*)(Zo))){while(!(ZZg(_i))){Z_g(C,Z0h((T51*)(Zng),ZYg,Z1h(_i)));Z2h(_i);}}}T0*Z3h=Zo;int Z4h=0;T0*Zlf(T38*C){if(Z4h==0){Z4h=1;{
if((Zse)==((void*)(((C)->ZJ1)))){Z3h=Z5h;Zi7(((T7*)Z3h));}else if((Zue)==((void*)(((C)->ZJ1)))){Z3h=Z5h;Zi7(((T7*)Z3h));}else if((Zte)==((void*)(((C)->ZJ1)))){
Z3h=Z5h;}else if((Zne)==((void*)(((C)->ZJ1)))){Z3h=Z5h;}else if((Zoe)==((void*)(((C)->ZJ1)))){Z3h=Z5h;}else if((Zve)==((void*)(((C)->ZJ1)))){
Z3h=Z6h;}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z3h=((T0*)n);ZJ6(n,(T2)(ZE5(4)));}}}}return Z3h;}void ZBf(T38*C,T0*a1){(C->ZJ1)=a1;(C->ZV1)=Zo;
(C->ZW1)=Zo;}T0*Z7h=Zo;int Z8h=0;T0*Z9h(void){if(Z8h==0){Z8h=1;{Z7h=Zle(14,ZCe,ZDe,ZNe,ZTe,ZUe,ZVe,ZXe,ZZe,Z0f,Z2f,Z3f,Z4f,Z5f,Z8f);}}
return Z7h;}void Z_g(T38*C,T0*a1){if((((C)->Z52))==((void*)(Zo))){{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(ZE5(4)));(C->Z52)=((T0*)n);
}}ZL7((T47*)(((C)->Z52)),a1);}T0*Zng=Zo;void ZTg(T0*a1,T0*a2){T0*Zah=Zo;Zah=Zbh;Z77(((T7*)Zah),((T3)'\040'),(T2)(ZE5(1)));ZV6(((T7*)Zah),a2);
if(!(Z07(((T7*)a1),Zah))){ZQ5(((T7*)Zah),((T3)'\040'));if(!(ZZ6(((T7*)ZMe),Zah))){ZL6(((T7*)Zah),(T2)(ZE5(1)));if(!(Z57(((T7*)ZMe),Zah))){
Z2e(a1,a2);}}}}int Zch=0;void ZWe(T38*C){if(Zch==0){Zch=1;{Ztf(C);}}}T0*Zog=Zo;T0*Zzg=Zo;T0*Zge=Zo;void Zdh(T38*C,T0*a1,T0*a2,T0*a3){
T2 _i=0;(C->Zv1)=Zo;_i=ZW7((T42*)(Z9h()),a1);(C->ZY1)=ZU7((T42*)(Z9h()),_i);if((a2)==((void*)(Zo))){(C->ZZ1)=((C)->ZY1);}else{(C->ZZ1)=a2;
}if((a3)==((void*)(Zo))){(C->Z_1)=((C)->ZY1);}else{(C->Z_1)=a3;}(C->ZX1)=ZE5(2);}void Zeh(T38*C,T0*a1,T0*a2,T2 a3){T2 _i=0;T6 Zfh=0;if(ZU5(a3,(T2)(ZE5(3)),(T2)(ZE5(99)))){
if((Zme)==((void*)(((C)->ZJ1)))){Zfh=((T6)(1));}else if((Zoe)==((void*)(((C)->ZJ1)))){Zfh=((T6)(1));}}if(Zfh){Z3g(C,a1,a2,(T2)(ZE5(1)),a3);
}else{_i=ZE5(1);while(!((Z3)((_i)>(a3)))){Z2e(a1,a2);ZY5(_i,a1);ZV6(((T7*)a1),ZSe(C));_i=(Z3)(((_i))+(ZE5(1)));}}}T0*ZEg=Zo;int Zgh=0;
void ZPg(T38*C){if(Zgh==0){Zgh=1;{T0*_s=Zo;T3 Zhh=0;_s=((C)->ZJ1);if((_s)==((void*)(Zo))){}else if((_s)==((void*)(Zme))){Zhh=((T3)'U');
}else if((T6)(((T6)(((_s)==((void*)(Zne)))||((T6)((_s)==((void*)(Zse))))))||((T6)((_s)==((void*)(Zte)))))){Zhh=((T3)'W');}else if((_s)==((void*)(Zpe))){
Zhh=((T3)'U');}else if((_s)==((void*)(Zqe))){Zhh=((T3)'M');}else if((_s)==((void*)(Zre))){Zhh=((T3)'A');}else if((_s)==((void*)(Zue))){
Zhh=((T3)'V');}else if((_s)==((void*)(Zoe))){Zhh=((T3)'C');}else if((_s)==((void*)(Zve))){Zhh=((T3)'U');}if((_s)!=((void*)(Zo))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(Zhh);
}}}}T0*Z_e(T6 a1){T0*R=Zo;if(Zye()){R=Zjh;}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(0)));R=((T0*)n);}ZV6(((T7*)R),Zkh);if(a1){
ZV6(((T7*)R),Zlh);}else{ZV6(((T7*)R),Zmh);}ZV6(((T7*)R),Znh);ZV6(((T7*)R),Zoh);}return R;}void Zmg(T38*C){T0*_s=Zo;Zph((T72*)(Z9g()),((C)->Zv1));
if(((((T72*)(Z9g()))->ZS1))!=(Zo)){Zqh((T51*)(Zng));if(!((((T53*)(ZOf))->Zi1))){if(!(Zrh((T51*)(Zng),Zsh,Zth))){{T0*b1=ZV9(31,"\"[General] bin\" key is missing.");
ZV6((T7*)(Zde),b1);}Zuh((T73*)(Zge));}else{(C->Zw1)=Z0h((T51*)(Zng),Zsh,Zth);ZUf(Zo,((C)->Zw1));}if(!(Zrh((T51*)(Zng),Zsh,Zvh))){{T0*b1=ZV9(31,"\"[General] sys\" key is missing.");
ZV6((T7*)(Zde),b1);}Zuh((T73*)(Zge));}else{(C->Zx1)=Z0h((T51*)(Zng),Zsh,Zvh);ZUf(Zo,((C)->Zx1));}if(!(Zrh((T51*)(Zng),Zsh,Zwh))){{T0*b1=ZV9(33,"\"[General] short\" key is missing.");
ZV6((T7*)(Zde),b1);}Zuh((T73*)(Zge));}else{(C->Zy1)=Z0h((T51*)(Zng),Zsh,Zwh);ZUf(Zo,((C)->Zy1));}if(!(Zrh((T51*)(Zng),Zsh,Zxh))){{T0*b1=ZV9(30,"\"[General] os\" key is missing.");
ZV6((T7*)(Zde),b1);}Zuh((T73*)(Zge));}else{_s=Z0h((T51*)(Zng),Zsh,Zxh);if(!(Z38((T42*)(Zke()),_s))){{T0*b1=Zyh;ZV6((T7*)(Zde),b1);}{T0*b1=_s;
ZV6((T7*)(Zde),b1);}{T0*b1=Zzh;ZV6((T7*)(Zde),b1);}ZAh((T73*)(Zge));}_s=ZU7((T42*)(Zke()),ZW7((T42*)(Zke()),_s));ZBf(C,_s);}if(((((T73*)(Zge))->Zo1))!=(ZE5(0))){
{T0*b1=ZV9(69,"The configuration file seems invalid. Correct the above errors first.");ZV6((T7*)(Zde),b1);}ZAh((T73*)(Zge));}Zyf(C);}
}ZWg(C);}T0*ZBh(T38*C,T0*a1,T2 a2){T0*R=Zo;T0*ZCh=Zo;T0*ZDh=Zo;T2 _i=0;T0*Zz2=Zo;R=ZEh;((((T7*)(((T7*)R))))->Z21)=(ZE5(0));Z4e(C);if((T6)(((((C)->ZY1))==((void*)(ZCe)))||((T6)((((C)->ZY1))==((void*)(ZDe)))))){
ZV6(((T7*)R),((C)->Z_1));Z2e(R,Zae);ZEe(C,R);Zeh(C,R,a1,a2);if(!((((((T7*)ZGe))->Z21))==(ZE5(0)))){Z2e(R,ZFh);Z2e(R,ZGe);}if(!((((((T7*)Z5e))->Z21))==(ZE5(0)))){
Z2e(R,ZGh);Z2e(R,Z5e);}Z2e(R,ZHh);Z2e(R,ZJe);Z2e(R,ZKe);Z2e(R,ZLe);Z2e(R,ZMe);}else if((((C)->ZY1))==((void*)(ZNe))){ZOe(C,R);ZV6(((T7*)R),((C)->Z_1));
if(!(((C)->ZU1))){Z2e(R,ZQe);}Z2e(R,Zae);ZEe(C,R);if((Z3)((a2)<(ZE5(4)))){Zeh(C,R,a1,a2);}else{Zz2=a1;ZV6(((T7*)Zz2),ZIh);Z2e(R,Zo7(((T7*)ZV9(1,Z53)),Zz2));
{ZL*n=((ZL*)Zh(sizeof(*n)));*n=ZZ2;ZJh(n);ZDh=((T0*)n);}Zy9((T49*)(Z6e()),ZDh,Zz2);Z97(((T7*)Zz2),(T2)(ZE5(4)));_i=ZE5(1);while(!((Z3)((_i)>(a2))))
{ZKh(((ZL*)ZDh),Zz2);ZLh(((ZL*)ZDh),(T11)(_i));ZKh(((ZL*)ZDh),Zeg);ZMh(((ZL*)ZDh),((T3)'\n'));_i=(Z3)(((_i))+(ZE5(1)));}ZNh(((ZL*)ZDh));
}Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(ZTe))){ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);Z2e(R,Zae);Z2e(R,ZMe);ZEe(C,R);Zeh(C,R,a1,a2);
Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(ZUe))){ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);Z2e(R,Zae);Z2e(R,ZMe);
ZEe(C,R);Zeh(C,R,a1,a2);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(ZVe))){ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);
Z2e(R,Zae);Z2e(R,ZMe);ZEe(C,R);Zeh(C,R,a1,a2);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);ZWe(C);}else if((((C)->ZY1))==((void*)(ZXe))){
ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);ZEe(C,R);Zeh(C,R,a1,a2);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZOh);Z2e(R,Zae);Z2e(R,ZMe);Z2e(R,ZKe);
ZWe(C);}else if((((C)->ZY1))==((void*)(ZZe))){ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);Z2e(R,Zae);Z2e(R,a1);ZV6(((T7*)R),ZPh);Z2e(R,ZGe);Z2e(R,Z5e);
Z2e(R,ZJe);Z2e(R,ZKe);ZEe(C,R);if(!(((C)->ZU1))){ZV6(((T7*)R),ZQh);}}else if((((C)->ZY1))==((void*)(Z0f))){ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);
Z2e(R,Zae);Z2e(R,ZMe);ZEe(C,R);Zeh(C,R,a1,a2);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);if(((C)->ZU1)){Z2e(R,ZRh);}ZWe(C);}else if((((C)->ZY1))==((void*)(Z2f))){
ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);Z2e(R,Zae);Z2e(R,ZMe);ZEe(C,R);ZWe(C);Zeh(C,R,a1,a2);Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);
}else if((((C)->ZY1))==((void*)(Z3f))){ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);Z2e(R,Zae);Z2e(R,ZMe);ZEe(C,R);Zeh(C,R,a1,a2);Z2e(R,ZGe);Z2e(R,Z5e);
Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(Z4f))){ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);Z2e(R,Zae);Z2e(R,ZMe);ZEe(C,R);Zeh(C,R,a1,a2);
Z2e(R,ZGe);Z2e(R,Z5e);Z2e(R,ZJe);Z2e(R,ZKe);}else if((((C)->ZY1))==((void*)(Z5f))){{ZL*n=((ZL*)Zh(sizeof(*n)));*n=ZZ2;ZJh(n);ZCh=((T0*)n);
}Zy9((T49*)(Z6e()),ZCh,ZSh);ZKh(((ZL*)ZCh),ZTh);((((T7*)(((T7*)R))))->Z21)=(ZE5(0));ZEe(C,R);ZKh(((ZL*)ZCh),R);ZMh(((ZL*)ZCh),((T3)'\040'));
_i=ZE5(1);while(!((Z3)((_i)>=(a2)))){ZKh(((ZL*)ZCh),a1);ZLh(((ZL*)ZCh),(T11)(_i));ZKh(((ZL*)ZCh),ZUh);_i=(Z3)(((_i))+(ZE5(1)));}ZKh(((ZL*)ZCh),a1);
ZLh(((ZL*)ZCh),(T11)(_i));ZMh(((ZL*)ZCh),((T3)'\n'));ZNh(((ZL*)ZCh));((((T7*)(((T7*)R))))->Z21)=(ZE5(0));ZV6(((T7*)R),ZVh);}else if((((C)->ZY1))==((void*)(Z8f))){
ZV6(((T7*)R),((C)->Z_1));Z2e(R,ZLe);Z2e(R,Zae);Z2e(R,ZMe);ZEe(C,R);Z2e(R,ZKe);Zeh(C,R,a1,a2);Z2e(R,ZGe);Z2e(R,ZJe);}return R;}void ZWh(T38*C,T0*a1){
T0*_n=Zo;if((T6)(((((C)->ZY1))==((void*)(ZNe)))||((T6)((((C)->ZY1))==((void*)(ZZe)))))){_n=Zo7(((T7*)a1),ZIh);Zj9((T49*)(Z6e()),_n);}
}T0*ZXh=Zo;int ZYh=0;T0*ZZh(void){if(ZYh==0){ZYh=1;{ZXh=Zle(6,ZDe,ZXe,ZVe,ZUe,Z4f,Z_h);}}return ZXh;}T0*Z0i(T72*C,T2 a1){T0*R=Zo;if((Z3)((a1)<=((((T47*)(((C)->Ze2)))->Zm1)))){
R=((((T47*)(((C)->Ze2)))->Zl1))[a1];((((T7*)(((T7*)R))))->Z21)=(ZE5(0));}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,Z98(128));R=((T0*)n);
}ZL7((T47*)(((C)->Ze2)),R);}return R;}void Zag(T72*C){{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(Z98(6000)));(C->Ze2)=((T0*)n);}
}T0*Z1i(void){if(ZJa==0){ZJa=1;{{T89*n=((T89*)Zh(1));ZIa=((T0*)n);ZKa(ZLa);ZKa(ZMa);ZKa(ZNa);ZKa(ZOa);ZKa(Zna);ZKa(ZPa);ZKa(Zka);ZKa(ZQa);
ZKa(ZRa);ZKa(Zma);ZKa(ZSa);ZKa(ZTa);ZKa(ZUa);ZKa(ZVa);ZKa(ZWa);ZKa(ZXa);ZKa(Zha);ZKa(Zra);ZKa(Zja);ZKa(Zia);ZKa(Zsa);ZKa(ZYa);ZKa(ZZa);
ZKa(Z_a);ZKa(Zga);ZKa(Z0b);ZKa(Zpa);ZKa(Z1b);ZKa(Z2b);ZKa(Z3b);ZKa(Z4b);ZKa(Z5b);ZKa(Zla);ZKa(Z6b);ZKa(Z7b);ZKa(Z8b);ZKa(Zoa);ZKa(Z9b);
ZKa(Zab);ZKa(Zbb);ZKa(Zcb);ZKa(Zdb);ZKa(Zeb);ZKa(Zfb);ZKa(Zgb);ZKa(Zhb);ZKa(Zib);ZKa(Zjb);ZKa(Zkb);ZKa(Zlb);ZKa(Zmb);ZKa(Znb);ZKa(Zob);
ZKa(Zpb);ZKa(Zqb);ZKa(Zrb);ZKa(Zsb);ZKa(Ztb);ZKa(Zub);ZKa(Zvb);ZKa(Zwb);ZKa(Zxb);ZKa(Zyb);ZKa(Zzb);ZKa(ZAb);ZKa(ZBb);ZKa(ZCb);ZKa(ZDb);
ZKa(ZEb);ZKa(ZFb);ZKa(ZGb);ZKa(ZHb);ZKa(ZIb);ZKa(ZJb);ZKa(ZKb);ZKa(ZLb);ZKa(ZMb);ZKa(ZNb);ZKa(ZOb);ZKa(ZPb);ZKa(ZQb);ZKa(ZRb);ZKa(ZSb);
ZKa(ZTb);ZKa(ZUb);ZKa(ZVb);ZKa(ZWb);ZKa(ZXb);ZKa(ZYb);ZKa(ZZb);ZKa(Z_b);ZKa(Z0c);ZKa(Z1c);ZKa(Z2c);ZKa(Z3c);ZKa(Z4c);ZKa(Z5c);ZKa(Z6c);
ZKa(Z7c);ZKa(Z8c);ZKa(Z9c);ZKa(Zac);ZKa(Zbc);ZKa(Zcc);ZKa(Zdc);ZKa(Zec);ZKa(Zfc);ZKa(Zgc);ZKa(Zhc);ZKa(Zic);ZKa(Zjc);ZKa(Zkc);ZKa(Zlc);
ZKa(Zmc);ZKa(Znc);ZKa(Zoc);ZKa(Zpc);ZKa(Zqc);ZKa(Zrc);ZKa(Zsc);ZKa(Ztc);ZKa(Zuc);ZKa(Zvc);ZKa(Zwc);ZKa(Zxc);ZKa(Zyc);ZKa(Zzc);ZKa(ZAc);
ZKa(ZBc);ZKa(ZCc);ZKa(ZDc);ZKa(ZEc);ZKa(ZFc);ZKa(ZGc);ZKa(ZHc);ZKa(ZIc);ZKa(ZJc);ZKa(ZKc);ZKa(ZLc);ZKa(ZMc);ZKa(ZNc);ZKa(ZOc);ZKa(ZPc);
ZKa(ZQc);ZKa(ZRc);ZKa(ZSc);ZKa(ZTc);ZKa(ZUc);ZKa(ZVc);ZKa(ZWc);ZKa(ZXc);ZKa(ZYc);ZKa(ZZc);ZKa(Z_c);ZKa(Z0d);ZKa(Z1d);ZKa(Z2d);ZKa(Z3d);
ZKa(Z4d);ZKa(Z5d);ZKa(Z6d);ZKa(Z7d);ZKa(Z8d);ZKa(Z9d);ZKa(Zad);ZKa(Zbd);ZKa(Zcd);ZKa(Zdd);ZKa(Zed);ZKa(Zfd);ZKa(Zgd);ZKa(Zhd);ZKa(Zid);
ZKa(Zjd);ZKa(Zkd);ZKa(Zld);ZKa(Zmd);ZKa(Znd);ZKa(Zod);ZKa(Zpd);ZKa(Zqd);ZKa(Zrd);ZKa(Zsd);ZKa(Ztd);ZKa(Zud);ZKa(Zvd);ZKa(Zwd);ZKa(Zxd);
ZKa(Zyd);ZKa(Zzd);ZKa(ZAd);ZKa(Zqa);ZKa(ZBd);ZKa(ZCd);ZKa(ZDd);ZKa(ZEd);ZKa(ZFd);ZKa(ZGd);ZKa(ZHd);ZKa(ZId);ZKa(ZJd);ZKa(ZKd);ZKa(ZLd);
}}}return ZIa;}void Zph(T72*C,T0*a1){T2 _i=0;ZK9((T55*)(Zhe),a1);if(((((T55*)(Zhe))->ZS1))!=(Zo)){(C->ZS1)=(((void)((T89*)(Z1i()))),ZCa(a1));
if((Z0i(C,ZE5(0)))!=((void*)(Zo))){}_i=ZE5(1);ZZd((T55*)(Zhe),Z0i(C,_i));while(!((((T55*)(Zhe))->Za1))){_i=(Z3)(((_i))+(ZE5(1)));ZZd((T55*)(Zhe),Z0i(C,_i));
}if(((((T7*)(((((T47*)(((C)->Ze2)))->Zl1))[_i]))->Z21))==(ZE5(0))){(C->Z21)=(Z3)(((_i))-(ZE5(1)));}else{(C->Z21)=_i;}ZDa((T55*)(Zhe));
if((Z3)((((C)->Z21))<=(ZE5(0)))){{T0*b1=ZV9(6,"File \"");ZV6((T7*)(Zde),b1);}{T0*b1=((C)->ZS1);ZV6((T7*)(Zde),b1);}{T0*b1=ZV9(20,"\" seems to be empty.");
ZV6((T7*)(Zde),b1);}ZAh((T73*)(Zge));}}else{(C->ZS1)=Zo;}}void Z2i(T72*C){(C->ZS1)=Zo;(C->Zd2)=Zo;}void Z3i(T45*C){(C->Zf2)=((T6)(0));
ZQg(((C)->ZS1));ZH6((T7*)(Z4i),ZCg);if((Z3)(((((T7*)(Z4i))->Z21))>(ZE5(0)))){Z5i(C,Z4i);}}T2 Z6i(T45*C){T2 R=0;R=(Z3)((((((T47*)(((C)->Zg2)))->Zm1)))+(ZE5(1)));
return R;}void Z7i(T45*C,T0*a1){(C->Zf2)=((T6)(0));ZNg(((C)->ZS1),a1);ZH6((T7*)(Z4i),ZCg);if((Z3)(((((T7*)(Z4i))->Z21))>(ZE5(0)))){Z5i(C,Z4i);
}}void Z8i(T45*C,T0*a1){Z5i(C,a1);if(!(((C)->Zf2))){Z9i(&(((C)->Zr1)),a1);if((Zo!=((((C)->Zr1)).ZY))){(C->ZS1)=Zn7((T7*)(ZCg));ZDg(&(((C)->Zr1)));
Z5i(C,((C)->ZS1));}}}T0*Z4i=Zo;void Z5i(T45*C,T0*a1){T0*Zai=Zo;ZSf(C);(C->ZS1)=a1;Zbi(&(((C)->Zr1)),((C)->ZS1));if((Zo!=((((C)->Zr1)).ZY))){
Zci(&(((C)->Zr1)));while(!(Zt5(((T8)(((((C)->Zr1)).ZZ)))))){Zai=Zn7((T7*)(ZCg));ZL7((T47*)(((C)->Zg2)),Zai);Zci(&(((C)->Zr1)));}ZDg(&(((C)->Zr1)));
(C->Zf2)=((T6)(1));}else{(C->Zf2)=((T6)(0));}}void ZSf(T45*C){if((((C)->Zg2))==((void*)(Zo))){{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(ZE5(32)));
(C->Zg2)=((T0*)n);}}else{((((T47*)((T47*)(((C)->Zg2)))))->Zm1)=(ZE5(-1));}}T6 Zdi(T45*C,T0*a1){T6 R=0;T6 Zei=0;T0*Zai=Zo;T2 _i=0;Zei=((T6)(Zfi()));
_i=(((T47*)(((C)->Zg2)))->Zm1);while(!((T6)((R)||((T6)((Z3)((_i)<(ZE5(0)))))))){Zai=((((T47*)(((C)->Zg2)))->Zl1))[_i];if(Zei){R=((T6)(Za6(((T7*)Zai),a1)));
}else{R=((T6)(Zf7(((T7*)Zai),a1)));}_i=(Z3)(((_i))-(ZE5(1)));}return R;}void Zjg(T45*C){T0*Zai=Zo;ZSf(C);ZAg(&(((C)->Zr1)));if((Zo!=((((C)->Zr1)).ZY))){
(C->ZS1)=Zn7((T7*)(ZCg));Zci(&(((C)->Zr1)));while(!(Zt5(((T8)(((((C)->Zr1)).ZZ)))))){Zai=Zn7((T7*)(ZCg));ZL7((T47*)(((C)->Zg2)),Zai);
Zci(&(((C)->Zr1)));}ZDg(&(((C)->Zr1)));(C->Zf2)=((T6)(1));}else{(C->Zf2)=((T6)(0));}}T2 Zgi(T95*C,T2 a1){T2 R=0;T2 _n=0;_n=(T2)((((C)->Zl1))[(Z3)(((a1))-(ZE5(1)))]);
if(((_n&Zhi(63488)))==(Zhi(55296))){R=(Z3)((((_n&Zhi(2047))))+(ZE5(64)));R=(Z3)((((Z3)(((R))*(Z98(1024)))))+((T2)(Zii(C,a1))));}else{
R=(_n&Zhi(65535));}return R;}void Zji(T95*C,T2 a1){if((Z3)((a1)>(ZE5(0)))){if((Z3)((((C)->Z11))<(a1))){(C->Zl1)=((T98)(Zk(a1,sizeof(T10))));
(C->Z11)=a1;}}(C->Z21)=ZE5(0);if((((C)->Zh2))==((void*)(Zo))){{T99*n=((T99*)Zh(sizeof(*n)));*n=M99;ZP7(n,(T2)(ZE5(0)));(C->Zh2)=((T0*)n);
}{T96*n=((T96*)Zh(sizeof(*n)));*n=M96;ZN7(n,(T2)(ZE5(0)));(C->Zi2)=((T0*)n);}}else{ZP7((T99*)(((C)->Zh2)),(T2)(ZE5(0)));ZN7((T96*)(((C)->Zi2)),(T2)(ZE5(0)));
}}T6 Zki(T2 a1){T6 R=0;R=((T6)((T6)(((T6)(((T6)((ZU5(a1,(T2)(ZE5(0)),Zhi(1114111)))&&((T6)(!(ZU5(a1,Zhi(55296),Zhi(57343)))))))&&((T6)((a1)!=(Zhi(65534))))))&&((T6)((a1)!=(Zhi(65535)))))));
return R;}T10 Zii(T95*C,T2 a1){T10 R=0;R=((((T96*)(((C)->Zi2)))->Zl1))[ZR7(((T99*)(((C)->Zh2))),a1)];return R;}void Zli(T95*C,T0*a1){
T2 _i=0;T2 _v=0;_i=ZE5(1);while(!((Z3)((_i)>(((C)->Z21))))){_v=Zgi(C,_i);if((Z3)((_v)<(Z98(128)))){ZQ5(((T7*)a1),((T3)(_v)));}else if((Z3)((_v)<(Z98(2048)))){
ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)/((T2)(ZE5(64))))))+((T2)(Z98(192)))))));ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)%((T2)(ZE5(64))))))+((T2)(Z98(128)))))));
}else if((Z3)((_v)<(Zhi(65536)))){ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)/((T2)(Z98(4096))))))+((T2)(Z98(224)))))));_v=(Z3)((_v)%(Z98(4096)));
ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)/((T2)(ZE5(64))))))+((T2)(Z98(128)))))));ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)%((T2)(ZE5(64))))))+((T2)(Z98(128)))))));
}else{ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)/(Zhi(262144)))))+((T2)(Z98(240)))))));_v=(Z3)((_v)%(Zhi(262144)));ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)/(Zhi(4096)))))+((T2)(Z98(128)))))));
_v=(Z3)((_v)%(Zhi(4096)));ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)/((T2)(ZE5(64))))))+((T2)(Z98(128)))))));ZQ5(((T7*)a1),((T3)((Z3)((((Z3)((_v)%((T2)(ZE5(64))))))+((T2)(Z98(128)))))));
}_i=(Z3)(((_i))+(ZE5(1)));}}void Zmi(T95*C,T2 a1){T2 ZY6=0;if((Z3)((((C)->Z11))>(((C)->Z21)))){}else if((((C)->Z11))==(ZE5(0))){ZY6=ZE5(32);
(C->Zl1)=((T98)(Zk(ZY6,sizeof(T10))));(C->Z11)=ZY6;}else{ZY6=(Z3)(((ZE5(2)))*(((C)->Z11)));(C->Zl1)=Z76(((C)->Zl1),((C)->Z11),ZY6);(C->Z11)=ZY6;
}if((Z3)((a1)>=(Zhi(65536)))){ZQ7((T99*)(((C)->Zh2)),((C)->Z21));ZO7((T96*)(((C)->Zi2)),((Zni)((a1&Zhi(1023)))));(((C)->Zl1))[((C)->Z21)]=((Zni)((Z3)((((Z3)((a1)/((T2)(Z98(1024))))))-((T2)(ZE5(64))))));
}else{(((C)->Zl1))[((C)->Z21)]=((Zni)(a1));}(C->Z21)=(Z3)(((((C)->Z21)))+(ZE5(1)));}void Zoi(T95*C){(C->Z21)=ZE5(0);ZP7((T99*)(((C)->Zh2)),(T2)(ZE5(0)));
ZN7((T96*)(((C)->Zi2)),(T2)(ZE5(0)));}ZF*Zpi(T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){ZF*n;n=((ZF*)Zh(sizeof(*n)));*n=ZT2;Zqi(n,a1,a2,a3,a4,a5);
return n;}T0*Zri=Zo;int Zsi=0;T0*Zti(void){if(Zsi==0){Zsi=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;Zri=((T0*)n);}}}return Zri;}void Zui(ZF*C,T0*a1){
if((a1)==((void*)(Zo))){(C->Z12)=Zo;}else{ZH6((T7*)(((C)->ZM2)),a1);(C->Z12)=((C)->ZM2);}}void Zvi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){
(C->ZG2)=Zo;}else{ZH6((T7*)(((C)->ZQ2)),a1);(C->ZG2)=((C)->ZQ2);}}void Zwi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){(C->Z22)=Zo;}else{ZH6((T7*)(((C)->ZO2)),a1);
(C->Z22)=((C)->ZO2);}}void Zqi(ZF*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(8)));(C->Zz2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZI2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZJ2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZK2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZL2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZM2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZN2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZO2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZP2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZQ2)=((T0*)n);}Zxi(C,a1,a2,a3,a4,a5);}void Zyi(ZF*C){T0*Zu7=Zo;T0*_rc=Zo;
Zzi(C,Zo);ZAi(C,Zo);ZBi(C,Zo);ZCi(C,Zo);Zui(C,Zo);ZDi(C,Zo);Zwi(C,Zo);ZEi(C,Zo);Zvi(C,Zo);(C->ZR2)=((T6)(0));(C->ZS2)=((T6)(0));(C->ZH2)=((T6)(0));
_rc=((C)->Zx2);if((_rc)!=((void*)(Zo))){(C->ZH2)=((T6)((T6)((ZFi(((T51*)_rc),ZGi))&&((T6)(Za6((T7*)(Zf8(((T62*)(((((T51*)_rc))->Zv2))),ZGi)),((C)->ZA2)))))));
if(((C)->ZH2)){if(Zrh(((T51*)_rc),((C)->Zz2),ZHi)){Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZHi);Zzi(C,Zu7);}if(Zrh(((T51*)_rc),((C)->Zz2),ZIi)){
Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZIi);ZAi(C,Zu7);}if(Zrh(((T51*)_rc),((C)->Zz2),ZJi)){Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZJi);ZBi(C,Zu7);}if(Zrh(((T51*)_rc),((C)->Zz2),ZKi)){
Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZKi);ZCi(C,Zu7);}if(Zrh(((T51*)_rc),((C)->Zz2),ZLi)){Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZLi);Zvi(C,Zu7);}(C->ZR2)=((T6)((((C)->ZB2))==((void*)(((C)->ZC2)))));
if((T6)(((T6)((!(((C)->ZR2)))&&((T6)((((C)->ZB2))!=((void*)(Zo))))))&&((T6)((((C)->ZC2))!=((void*)(Zo)))))){(C->ZR2)=((T6)(Za6((T7*)(((C)->ZB2)),((C)->ZC2))));
}}}_rc=((C)->Zy2);if((_rc)!=((void*)(Zo))){(C->ZH2)=((T6)((T6)(((T6)((((C)->ZH2))&&((T6)(ZFi(((T51*)_rc),ZMi)))))&&((T6)((T6)((Za6((T7*)(Zf8(((T62*)(((((T51*)_rc))->Zv2))),ZMi)),((C)->ZD2)))||((T6)(Za6((T7*)(Zf8(((T62*)(((((T51*)_rc))->Zv2))),ZGi)),((C)->ZD2))))))))));
if(((C)->ZH2)){(C->ZD2)=ZU7((T42*)((((void)((T38*)(Zti()))),ZZh())),ZW7((T42*)((((void)((T38*)(Zti()))),ZZh())),Zf8(((T62*)(((((T51*)_rc))->Zv2))),ZMi)));
if(Zrh(((T51*)_rc),((C)->Zz2),ZNi)){Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZNi);Zui(C,Zu7);}if(Zrh(((T51*)_rc),((C)->Zz2),ZOi)){Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZOi);
ZDi(C,Zu7);}if(Zrh(((T51*)_rc),((C)->Zz2),ZPi)){Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZPi);Zwi(C,Zu7);}if(Zrh(((T51*)_rc),((C)->Zz2),ZQi)){Zu7=Z0h(((T51*)_rc),((C)->Zz2),ZQi);
ZEi(C,Zu7);}(C->ZS2)=((T6)((((C)->ZE2))==((void*)(((C)->ZF2)))));if((T6)(((T6)((!(((C)->ZS2)))&&((T6)((((C)->ZE2))!=((void*)(Zo))))))&&((T6)((((C)->ZF2))!=((void*)(Zo)))))){
(C->ZS2)=((T6)(Za6((T7*)(((C)->ZE2)),((C)->ZF2))));}}}}void Zxi(ZF*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){ZH6((T7*)(((C)->Zz2)),a1);(C->Zx2)=a2;
if((a3)!=((void*)(Zpg))){(C->ZA2)=ZU7((T42*)((((void)((T38*)(Zti()))),Z9h())),ZW7((T42*)((((void)((T38*)(Zti()))),Z9h())),a3));}(C->Zy2)=a4;
if((a5)!=((void*)(Zpg))){(C->ZD2)=ZU7((T42*)((((void)((T38*)(Zti()))),ZZh())),ZW7((T42*)((((void)((T38*)(Zti()))),ZZh())),a5));}Zyi(C);
}void ZDi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){(C->ZE2)=Zo;}else{ZH6((T7*)(((C)->ZN2)),a1);(C->ZE2)=((C)->ZN2);}if(((C)->ZS2)){if((a1)==((void*)(Zo))){
(C->ZF2)=Zo;}else{ZH6((T7*)(((C)->ZP2)),a1);(C->ZF2)=((C)->ZP2);}}}void ZBi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){(C->Z_1)=Zo;}else{ZH6((T7*)(((C)->ZK2)),a1);
(C->Z_1)=((C)->ZK2);}}void ZEi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){(C->ZF2)=Zo;}else{ZH6((T7*)(((C)->ZP2)),a1);(C->ZF2)=((C)->ZP2);}(C->ZS2)=((T6)(0));
}void ZCi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){(C->ZC2)=Zo;}else{ZH6((T7*)(((C)->ZL2)),a1);(C->ZC2)=((C)->ZL2);}(C->ZR2)=((T6)(0));}void
Zzi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){(C->ZZ1)=Zo;}else{ZH6((T7*)(((C)->ZI2)),a1);(C->ZZ1)=((C)->ZI2);}}void ZAi(ZF*C,T0*a1){if((a1)==((void*)(Zo))){
(C->ZB2)=Zo;}else{ZH6((T7*)(((C)->ZJ2)),a1);(C->ZB2)=((C)->ZJ2);}if(((C)->ZR2)){if((a1)==((void*)(Zo))){(C->ZC2)=Zo;}else{ZH6((T7*)(((C)->ZL2)),a1);
(C->ZC2)=((C)->ZL2);}}}void ZKa(T0*a1){ZRi(ZSi,a1,a1);}T0*ZCa(T0*a1){T0*R=Zo;R=ZTi(ZSi,a1);if((R)==((void*)(Zo))){R=Zn7(((T7*)a1));ZKa(R);
}return R;}T0*ZSi=Zo;void ZNh(ZL*C){if((Z3)((((C)->Zd1))>(ZE5(0)))){ZUi(C);}ZWd(((C)->ZY2));(C->ZS1)=Zo;}T0*ZVi=Zo;void ZJh(ZL*C){(C->Zb1)=((T9)(Zk(Z98(4096),sizeof(T3))));
(C->Z11)=Z98(4096);}void Zz9(ZL*C,T0*a1){T8 _p=Zo;_p=Zl7(((T7*)a1));(C->ZY2)=ZWi(_p);if((Zo!=((C)->ZY2))){(C->ZS1)=a1;if((((C)->Z11))==(ZE5(0))){
(C->Zb1)=((T9)(Zk(Z98(4096),sizeof(T3))));(C->Z11)=Z98(4096);}}}void ZLh(ZL*C,T11 a1){((((T7*)((T7*)(ZVi))))->Z21)=(ZE5(0));Z06(a1,ZVi);
ZKh(C,ZVi);}void ZUi(ZL*C){if((Z3)((((C)->Zd1))>(ZE5(0)))){ZXi(((C)->Zb1),((C)->Zd1),((C)->ZY2));(C->Zd1)=ZE5(0);}}void ZMh(ZL*C,T3 a1){
if((Z3)((((C)->Zd1))>=(Z98(4096)))){ZUi(C);}(((C)->Zb1))[((C)->Zd1)]=(a1);(C->Zd1)=(Z3)(((((C)->Zd1)))+(ZE5(1)));}void ZKh(ZL*C,T0*a1){
T2 _i=0;T2 Z21=0;_i=ZE5(1);Z21=((((T7*)a1))->Z21);while(!((Z3)((_i)>(Z21)))){ZMh(C,(((((T7*)a1))->Zl1))[(_i)-(ZE5(1))]);_i=(Z3)(((_i))+(ZE5(1)));
}}void ZYi(T93*C,T74 a1,T6 a2,T6 a3,T0*a4){(C->ZV)=a1;(C->Z_2)=((T6)(a2));(C->Z03)=((T6)(a3));(C->Z13)=Zn7(((T7*)a4));}void ZZi(T31*C){
(C->Zb1)=((T9)(Zk(Z98(4096),sizeof(T3))));(C->Z11)=Z98(4096);}void Z0a(T31*C,T11 a1){((((T7*)((T7*)(ZVi))))->Z21)=(ZE5(0));Z06(a1,ZVi);
Z9a(C,ZVi);}void Z1a(T31*C){if((Z3)((((C)->Zd1))>(ZE5(0)))){Z_i(C);}ZH9(Z0j);}void Z_i(T31*C){if((Z3)((((C)->Zd1))>(ZE5(0)))){ZXi(((C)->Zb1),((C)->Zd1),Z0j);
(C->Zd1)=ZE5(0);}}void Zh9(T31*C,T3 a1){if((Z3)((((C)->Zd1))>=(Z98(4096)))){Z_i(C);}(((C)->Zb1))[((C)->Zd1)]=(a1);(C->Zd1)=(Z3)(((((C)->Zd1)))+(ZE5(1)));
if((a1)==(((T3)'\n'))){Z_i(C);}}void Z9a(T31*C,T0*a1){T2 _i=0;T2 Z21=0;_i=ZE5(1);Z21=((((T7*)a1))->Z21);while(!((Z3)((_i)>(Z21)))){Zh9(C,(((((T7*)a1))->Zl1))[(_i)-(ZE5(1))]);
_i=(Z3)(((_i))+(ZE5(1)));}}void Z8a(T11 a1){((((T7*)((T7*)(ZVi))))->Z21)=(ZE5(0));Z06(a1,ZVi);Z2a(ZVi);}void Z2a(T0*a1){T2 _i=0;T2 Z21=0;
_i=ZE5(1);Z21=((((T7*)a1))->Z21);while(!((Z3)((_i)>(Z21)))){{T3 b1=(((((T7*)a1))->Zl1))[(_i)-(ZE5(1))];ZF9(b1,ZG9);}_i=(Z3)(((_i))+(ZE5(1)));
}}T0*Z1j=Zo;void Z2j(T11 a1){((((T7*)((T7*)(ZVi))))->Z21)=(ZE5(0));Z06(a1,ZVi);ZLf(ZVi);}void ZLf(T0*a1){T2 _i=0;T2 Z21=0;_i=ZE5(1);Z21=((((T7*)a1))->Z21);
while(!((Z3)((_i)>(Z21)))){{T3 b1=(((((T7*)a1))->Zl1))[(_i)-(ZE5(1))];Zh9((T31*)(Zi9),b1);}_i=(Z3)(((_i))+(ZE5(1)));}}T6 Z3j(T74*C){T6
R=0;R=((T6)((((Z4j)(((*C).ZS))))==(ZE5(0))));return R;}T10 Z5j(T74*C){T10 R=0;if(ZS5(((*C).ZS),ZE5(0))){R=(Zni)(((Z8)(((*C).ZS))>>(ZE5(17))));
}else{R=(Zni)(((Z8)(((*C).ZS))>>(ZE5(21))));}return R;}T0*Z6j(T0*a1,T2 a2){T0*R=Zo;T2 _i=0;ZI9((T49*)(Z7j()),Zhe,a1);if(((((T55*)(Zhe))->ZS1))!=(Zo)){
while(!((T6)(((((T55*)(Zhe))->Za1))||((T6)((_i)==(a2)))))){Z0e((T55*)(Zhe));_i=(Z3)(((_i))+(ZE5(1)));}if(!((((T55*)(Zhe))->Za1))){R=Z1e;
}ZDa((T55*)(Zhe));}return R;}void Z8j(T74*C){T2 _li=0;T2 _co=0;T2 _nb=0;T0*_bc=Zo;T0*Z9j=Zo;T0*Zz2=Zo;T0*Zf1=Zo;T0*Zaj=Zo;T10 Zbj=0;_li=Zcj(C);
_co=Zdj(C);_bc=((*C).ZQ);if((_bc)!=((void*)(Zo))){Z9j=Zej(C);}if((Z9j)!=((void*)(Zo))){Zz2=(T0*)(Z9j,Zu(),Zv(1),Zo);Zf1=(T0*)(_bc,Zu(),Zv(1),Zo);
}if((Zf1)==((void*)(Zo))){Zbj=Z5j(C);{int z1=Zbj;switch(z1){case 32767:Zf1=(((T82*)(Zaf))->Zf1);break;case 32766:Zf1=(((T51*)(Zng))->Zf1);
break;case 32765:Zf1=((*C).ZR);break;default:;Zf1=(((void)((T83*)(Zfj()))),ZMd(Zbj));}}}(((void)((T49*)(Z7j()))),ZC9(ZV9(5,"Line ")));
(((void)((T49*)(Z7j()))),Z7a(_li));if((Z3)((_co)>(ZE5(0)))){(((void)((T49*)(Z7j()))),ZC9(ZV9(8," column ")));(((void)((T49*)(Z7j()))),Z7a(_co));
}(((void)((T49*)(Z7j()))),ZC9(ZV9(4," in ")));if((Zz2)!=((void*)(Zo))){(((void)((T49*)(Z7j()))),ZC9(Zz2));}if((Zf1)!=((void*)(Zo))){(((void)((T49*)(Z7j()))),ZC9(ZV9(2,Z73)));
(((void)((T49*)(Z7j()))),ZC9(Zf1));(((void)((T49*)(Z7j()))),ZE9(((T3)'\051')));}(((void)((T49*)(Z7j()))),ZC9(ZV9(3," :\n")));if((Zf1)!=((void*)(Zo))){
Zaj=Z6j(Zf1,_li);if((T6)(((Z3)((_li)>(ZE5(0))))&&((T6)((Zaj)!=((void*)(Zo)))))){(((void)((T49*)(Z7j()))),ZC9(Zaj));(((void)((T49*)(Z7j()))),ZE9(((T3)'\n')));
if((Z3)((_co)>(ZE5(0)))){_nb=ZE5(1);while(!((Z3)((_nb)>=(_co)))){if(((((((T7*)Zaj))->Zl1))[(_nb)-(ZE5(1))])==(((T3)'\011'))){(((void)((T49*)(Z7j()))),ZE9(((T3)'\011')));
}else{(((void)((T49*)(Z7j()))),ZE9(((T3)'\040')));}_nb=(Z3)(((_nb))+(ZE5(1)));}(((void)((T49*)(Z7j()))),ZC9(ZV9(2,"^\n")));}}}}T0*Zej(T74*C){
T0*R=Zo;T0*_bc=Zo;_bc=((*C).ZQ);if((_bc)!=((void*)(Zo))){R=(T0*)(_bc,Zu(),Zv(1),Zo);}return R;}T0*Z7j(void){if(ZHa==0){ZHa=1;{{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;ZGa=((T0*)n);}}}return ZGa;}void Zgj(T74*C,T2 a1,T2 a2,T10 a3,T0*a4){(C->ZQ)=a4;if((T6)(((T6)(((Z2)((a3)<=(Z98(2047))))&&((T6)((Z3)((a1)<=(Z98(8191)))))))&&((T6)((Z3)((a2)<=(ZE5(127))))))){
(C->ZS)=(T2)(((a3)<<(ZE5(21))));(C->ZS)=(((*C).ZS)|((a1)<<(ZE5(8))));(C->ZS)=(((*C).ZS)|((a2)<<(ZE5(1))));}else{(C->ZS)=(T2)(((a3)<<(ZE5(17))));
(C->ZS)=(((*C).ZS)|((a1)<<(ZE5(1))));(C->ZS)=(((*C).ZS)|ZE5(1));}}T0*Zhj=Zo;int Zij=0;T0*Zfj(void){if(Zij==0){Zij=1;{{T83*n=((T83*)Zh(sizeof(*n)));
*n=M83;Zhj=((T0*)n);Zfa(n);}}}return Zhj;}T2 Zcj(T74*C){T2 R=0;if(ZS5(((*C).ZS),ZE5(0))){R=((((*C).ZS))>>(ZE5(1)));R=(R&Zhi(65535));}
else{R=((((*C).ZS))>>(ZE5(8)));R=(R&Zhi(8191));}return R;}T2 Zdj(T74*C){T2 R=0;if(ZS5(((*C).ZS),ZE5(0))){}else{R=((((*C).ZS))>>(ZE5(1)));
R=(R&Zhi(127));}return R;}T6 Zjj(T0*a1){T6 R=0;R=((T6)(Zp9(a1)));return R;}void Zt9(T0*a1,T0*a2){T8 _p1=Zo;T8 _p2=Zo;if(Zjj(a2)){Zo9(a2);
}_p1=Zl7(((T7*)a1));_p2=Zl7(((T7*)a2));Zkj(_p1,_p2);}T0*Zlj=Zo;void Zo9(T0*a1){T8 _p=Zo;_p=Zl7(((T7*)a1));Zmj(_p);}T6 Zp9(T0*a1){T6 R=0;
ZK9((T55*)(Zlj),a1);R=((T6)(((((T55*)(Zlj))->ZS1))!=(Zo)));if(R){ZDa((T55*)(Zlj));}return R;}T0*Znj(T2 a1){T0*R=Zo;{int z1=a1;switch(z1){
case 0:R=Zoj;break;case 1:R=Zpj;break;case 2:R=Zqj;break;case 3:R=Zrj;break;case 4:R=Zsj;break;case 5:R=Ztj;break;case 6:R=Zuj;break;
case 7:R=Zvj;break;default:;R=Zwj;}}return R;}T2 Zn8(T2 a1){T2 R=0;if((Z3)((a1)<=(ZE5(53)))){R=ZE5(53);}else if((Z3)((a1)<=(ZE5(97)))){
R=ZE5(97);}else if((Z3)((a1)<=(Z98(193)))){R=Z98(193);}else if((Z3)((a1)<=(Z98(389)))){R=Z98(389);}else if((Z3)((a1)<=(Z98(769)))){R=Z98(769);
}else if((Z3)((a1)<=(Z98(1543)))){R=Z98(1543);}else if((Z3)((a1)<=(Z98(3079)))){R=Z98(3079);}else if((Z3)((a1)<=(Z98(6151)))){R=Z98(6151);
}else if((Z3)((a1)<=(Z98(12289)))){R=Z98(12289);}else if((Z3)((a1)<=(Z98(24593)))){R=Z98(24593);}else if((Z3)((a1)<=(Zhi(49157)))){R=Zhi(49157);
}else if((Z3)((a1)<=(Zhi(98317)))){R=Zhi(98317);}else if((Z3)((a1)<=(Zhi(196613)))){R=Zhi(196613);}else if((Z3)((a1)<=(Zhi(393241)))){
R=Zhi(393241);}else if((Z3)((a1)<=(Zhi(786433)))){R=Zhi(786433);}else if((Z3)((a1)<=(Zhi(1572869)))){R=Zhi(1572869);}else if((Z3)((a1)<=(Zhi(3145739)))){
R=Zhi(3145739);}else if((Z3)((a1)<=(Zhi(6291469)))){R=Zhi(6291469);}else if((Z3)((a1)<=(Zhi(12582917)))){R=Zhi(12582917);}else if((Z3)((a1)<=(Zhi(25165843)))){
R=Zhi(25165843);}else if((Z3)((a1)<=(Zhi(50331653)))){R=Zhi(50331653);}else if((Z3)((a1)<=(Zhi(100663319)))){R=Zhi(100663319);}else if((Z3)((a1)<=(Zhi(201326611)))){
R=Zhi(201326611);}else if((Z3)((a1)<=(Zhi(402653189)))){R=Zhi(402653189);}else if((Z3)((a1)<=(Zhi(805306457)))){R=Zhi(805306457);}else{
R=Zhi(1610612741);}return R;}T0*Zxj=Zo;T0*Zbf(void){T0*R=Zo;if((Z3)(((Z3)((((((T47*)(Zxj))->Zm1)))+(ZE5(1))))>(ZE5(0)))){R=ZG7((T47*)(Zxj));
}return R;}void ZAh(T73*C){Zyj(C,Zzj);Zv(ZE5(1));}void Zyj(T73*C,T0*a1){T2 _i=0;T2 ZAj=0;T3 _cc=0;T3 ZBj=0;T74 _p={Zo,Zo,0};T6 Zt1=0;
T0*ZCj=Zo;(((void)((T49*)(ZDj()))),ZC9(ZEj));(((void)((T49*)(ZDj()))),ZC9(a1));(((void)((T49*)(ZDj()))),ZE9(((T3)'\072')));(((void)((T49*)(ZDj()))),ZE9(((T3)'\040')));
_i=ZE5(1);while(!((_i)==(ZE5(0)))){_i=Z_6((T7*)(Zde),ZFj,(T2)(ZE5(1)));if((_i)!=(ZE5(0))){{T7*C1=(T7*)(Zde);T2 b1=_i;ZM6(C1,b1,b1);}}
}_i=ZE5(1);ZAj=(Z3)(((ZE5(9)))+(((((T7*)a1))->Z21)));while(!((Z3)((_i)>((((T7*)(Zde))->Z21))))){ZBj=_cc;_cc=((((T7*)(Zde))->Zl1))[(_i)-(ZE5(1))];
_i=(Z3)(((_i))+(ZE5(1)));if((Z3)((ZAj)>(ZE5(60)))){if((T6)(((_cc)==(((T3)'\040')))||((T6)((_cc)==(((T3)'\n')))))){(((void)((T49*)(ZDj()))),ZE9(((T3)'\n')));
ZAj=ZE5(0);}else{(((void)((T49*)(ZDj()))),ZE9(_cc));ZAj=(Z3)(((ZAj))+(ZE5(1)));}}else{(((void)((T49*)(ZDj()))),ZE9(_cc));{int z1=_cc;
switch(z1){case 10:ZAj=ZE5(0);break;default:;ZAj=(Z3)(((ZAj))+(ZE5(1)));}}}}(((void)((T49*)(ZDj()))),ZE9(((T3)'\n')));while(!((Z3)(((((T75*)(ZGj))->Zm1))<(ZE5(0)))))
{{T74 Zv6;_p=(*(Zv6=ZD7((T75*)(ZGj)),&Zv6));}Zz7((T75*)(ZGj));if((Zej(&_p))==((void*)(Zo))){Z8j(&_p);}else{ZCj=(T0*)(Zej(&_p),Zu(),Zv(1),Zo);
if(!(ZHj(ZCj))){Z8j(&_p);}}Zt1=((T6)(0));while(!(Zt1)){_i=ZE7((T75*)(ZGj),_p);if(ZA7((T75*)(ZGj),_i)){ZB7((T75*)(ZGj),_i);}else{Zt1=((T6)(1));
}}}((((T7*)((T7*)(Zde))))->Z21)=(ZE5(0));((((T75*)((T75*)(ZGj))))->Zm1)=(ZE5(-1));(((void)((T49*)(ZDj()))),ZC9(ZIj));}T0*ZDj(void){if(ZHa==0){ZHa=1;{
{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;ZGa=((T0*)n);}}}return ZGa;}T0*Zde=Zo;void Zuh(T73*C){Zyj(C,ZJj);(C->Zo1)=(Z3)(((((C)->Zo1)))+(ZE5(1)));
if((Z3)((((C)->Zo1))>=(ZE5(6)))){(((void)((T49*)(ZDj()))),ZC9(ZEj));(((void)((T49*)(ZDj()))),ZC9(ZKj));Zv(ZE5(1));}}T0*ZGj=Zo;void ZLj(T74
a1){if(Z3j(&a1)){}else{ZC7((T75*)(ZGj),a1);}}void Zfe(T73*C){if(((C)->Zq1)){((((T7*)((T7*)(Zde))))->Z21)=(ZE5(0));((((T75*)((T75*)(ZGj))))->Zm1)=(ZE5(-1));
}else{Zyj(C,ZMj);}(C->Zp1)=(Z3)(((((C)->Zp1)))+(ZE5(1)));}T0*ZNj=Zo;T0*ZOj=Zo;void ZPj(T0*a1,T0*a2){T0*ZQj=Zo;ZQj=ZRj;ZH6(((T7*)ZQj),a2);
Zdf((T38*)(ZSj()),ZQj);((((T7*)((T7*)(ZTj))))->Z21)=(ZE5(0));ZUg((T38*)(ZSj()),ZTj,ZUj);ZQ5((T7*)(ZTj),((T3)'\040'));ZV6((T7*)(ZTj),a1);
ZV6((T7*)(ZTj),ZVj);ZV6((T7*)(ZTj),ZQj);ZQ5((T7*)(ZTj),((T3)'\040'));ZV6((T7*)(ZTj),a2);ZLf(ZTj);{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);
}Z3a((T49*)(ZWj()),ZTj);}void ZXj(T0*a1){ZLf(ZYj);ZLf(a1);ZLf(ZZj);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);
}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));}void Z0k(T12*C){T2 _i=0;T0*Z1k=Zo;T0*Zi1=Zo;Z1k=Z2k(C,Z3k);_i=ZE5(1);while(!((Z3)((_i)>(ZT7((T42*)(Z4k))))))
{Zi1=ZU7((T42*)(Z4k),_i);if(!(Z38((T42*)(Z5k),Zi1))){ZPj(Z1k,Zi1);}_i=(Z3)(((_i))+(ZE5(1)));}Z1k=Z2k(C,Z6k);_i=ZE5(1);while(!((Z3)((_i)>(ZT7((T42*)(Z7k))))))
{Zi1=ZU7((T42*)(Z7k),_i);if(!(Z38((T42*)(Z5k),Zi1))){ZPj(Z1k,Zi1);}_i=(Z3)(((_i))+(ZE5(1)));}}void Z8k(T12*C,T6 a1){T2 _i=0;T6 Z9k=0;
T0*Zak=Zo;T0*Zbk=Zo;T0*Zck=Zo;T0*Zdk=Zo;T0*Zw2=Zo;if(a1){_i=ZE5(0);while(!((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))){Zx7((ZD*)(((C)->ZL1)),((((ZD*)(((C)->ZK1)))->Zl1))[_i]);
_i=(Z3)(((_i))+(ZE5(1)));}((((ZD*)((ZD*)(((C)->ZK1)))))->Zm1)=(ZE5(-1));}Zak=Zek(((C)->ZD1));Zbk=Zek(((C)->ZE1));if((Zak)==((void*)(Zo))){
Z9k=((T6)(Zfk(C)));}else{Zw2=Zgk(((T51*)Zak));while(!(ZZg(Zw2))){Zdk=Z1h(Zw2);Zck=Zo;if(!(a1)){_i=ZE5(0);while(!((T6)(((Zck)!=((void*)(Zo)))||((T6)((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))))))
{Zck=((((ZD*)(((C)->ZK1)))->Zl1))[_i];if(!(Za6((T7*)(((((ZF*)Zck))->Zz2)),Zdk))){Zck=Zo;}_i=(Z3)(((_i))+(ZE5(1)));}}if((Zck)==((void*)(Zo))){
if((Z3)(((((ZD*)(((C)->ZL1)))->Zm1))<(ZE5(0)))){{ZF*n=((ZF*)Zh(sizeof(*n)));*n=ZT2;Zqi(n,Zdk,Zak,((C)->ZD1),Zbk,((C)->ZE1));Zck=((T0*)n);
}}else{Zck=((((ZD*)(((C)->ZL1)))->Zl1))[ZE5(0)];Zv7((ZD*)(((C)->ZL1)));Zxi(((ZF*)Zck),Zdk,Zak,((C)->ZD1),Zbk,((C)->ZE1));}Zx7((ZD*)(((C)->ZK1)),Zck);
}Z2h(Zw2);}}}void Zhk(T12*C){Zjg((T45*)(Zik()));if(!((((T45*)(Zik()))->Zf2))){Z2a(Zjk);Z2a(ZV9(41,"Cannot connect to the current directory!\n"));
Zkk(C);}Z7i((T45*)(Zik()),Zlk);if((((T45*)(Zik()))->Zf2)){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,(((T45*)(Zik()))->ZS1));(C->Zw1)=((T0*)n);
}Z3i((T45*)(Zik()));}else{Zjg((T45*)(Zik()));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,(((T45*)(Zik()))->ZS1));(C->Zw1)=((T0*)n);}}Z7i((T45*)(Zik()),Zmk);
if((((T45*)(Zik()))->Zf2)){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,(((T45*)(Zik()))->ZS1));(C->Zx1)=((T0*)n);}Z3i((T45*)(Zik()));}else{
Zjg((T45*)(Zik()));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,(((T45*)(Zik()))->ZS1));(C->Zx1)=((T0*)n);}}Z7i((T45*)(Zik()),Znk);if((((T45*)(Zik()))->Zf2)){
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,(((T45*)(Zik()))->ZS1));(C->Zy1)=((T0*)n);}Z3i((T45*)(Zik()));}else{Zjg((T45*)(Zik()));{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZH6(n,(((T45*)(Zik()))->ZS1));(C->Zy1)=((T0*)n);}}}T6 Zok(T0*a1){T6 R=0;R=((T6)(Zp9(a1)));return R;}void Zpk(T0*a1){ZLf(Zqk);ZLf(a1);
ZLf(Zrk);}void Zsk(T12*C){{T7*z1=(T7*)((C)->ZJ1);T3*Ztk=(Zo==z1)?Zo:((z1)->Zl1);int Zuk=(Zo==z1)?0:((z1)->Z21);int Zvk=-1;int Zwk=0;if(z1!=Zo)while(Zwk<Zuk&&(Zwk==0||Zvk!=-1)){
switch(Zvk){case-1:switch(*(Ztk+Zwk)){case'A':Zvk=10;break;case'B':Zvk=11;break;case'C':Zvk=12;break;case'D':Zvk=13;break;case'E':Zvk=14;break;
case'M':Zvk=15;break;case'O':Zvk=16;break;case'U':Zvk=17;break;case'W':Zvk=18;break;default:Zvk=-1;break;}break;case 0:switch(*(Ztk+Zwk)){
default:Zvk=-1;break;}break;case 1:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;case 2:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;
case 3:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;case 4:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;case 5:switch(*(Ztk+Zwk)){
default:Zvk=-1;break;}break;case 6:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;case 7:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;
case 8:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;case 9:switch(*(Ztk+Zwk)){default:Zvk=-1;break;}break;case 10:switch(*(Ztk+Zwk)){
case'm':Zvk=19;break;default:Zvk=-1;break;}break;case 11:switch(*(Ztk+Zwk)){case'e':Zvk=20;break;default:Zvk=-1;break;}break;case 12:switch(*(Ztk+Zwk)){
case'y':Zvk=21;break;default:Zvk=-1;break;}break;case 13:switch(*(Ztk+Zwk)){case'O':Zvk=22;break;default:Zvk=-1;break;}break;case 14:switch(*(Ztk+Zwk)){
case'l':Zvk=23;break;default:Zvk=-1;break;}break;case 15:switch(*(Ztk+Zwk)){case'a':Zvk=24;break;default:Zvk=-1;break;}break;case 16:switch(*(Ztk+Zwk)){
case'S':Zvk=25;break;case'p':Zvk=26;break;default:Zvk=-1;break;}break;case 17:switch(*(Ztk+Zwk)){case'N':Zvk=27;break;default:Zvk=-1;
break;}break;case 18:switch(*(Ztk+Zwk)){case'i':Zvk=28;break;default:Zvk=-1;break;}break;case 19:switch(*(Ztk+Zwk)){case'i':Zvk=29;break;
default:Zvk=-1;break;}break;case 20:switch(*(Ztk+Zwk)){case'O':Zvk=30;break;default:Zvk=-1;break;}break;case 21:switch(*(Ztk+Zwk)){case'g':Zvk=31;break;
default:Zvk=-1;break;}break;case 22:switch(*(Ztk+Zwk)){case'S':Zvk=(*(Ztk+Zwk+1))?3:6;break;default:Zvk=-1;break;}break;case 23:switch(*(Ztk+Zwk)){
case'a':Zvk=32;break;default:Zvk=-1;break;}break;case 24:switch(*(Ztk+Zwk)){case'c':Zvk=33;break;default:Zvk=-1;break;}break;case 25:switch(*(Ztk+Zwk)){
case'2':Zvk=(*(Ztk+Zwk+1))?6:7;break;default:Zvk=-1;break;}break;case 26:switch(*(Ztk+Zwk)){case'e':Zvk=34;break;default:Zvk=-1;break;
}break;case 27:switch(*(Ztk+Zwk)){case'I':Zvk=35;break;default:Zvk=-1;break;}break;case 28:switch(*(Ztk+Zwk)){case'n':Zvk=36;break;default:Zvk=-1;
break;}break;case 29:switch(*(Ztk+Zwk)){case'g':Zvk=37;break;default:Zvk=-1;break;}break;case 30:switch(*(Ztk+Zwk)){case'S':Zvk=(*(Ztk+Zwk+1))?1:3;break;
default:Zvk=-1;break;}break;case 31:switch(*(Ztk+Zwk)){case'w':Zvk=38;break;default:Zvk=-1;break;}break;case 32:switch(*(Ztk+Zwk)){case't':Zvk=39;break;
default:Zvk=-1;break;}break;case 33:switch(*(Ztk+Zwk)){case'i':Zvk=40;break;default:Zvk=-1;break;}break;case 34:switch(*(Ztk+Zwk)){case'n':Zvk=41;break;
default:Zvk=-1;break;}break;case 35:switch(*(Ztk+Zwk)){case'X':Zvk=(*(Ztk+Zwk+1))?8:0;break;default:Zvk=-1;break;}break;case 36:switch(*(Ztk+Zwk)){
case'd':Zvk=42;break;default:Zvk=-1;break;}break;case 37:switch(*(Ztk+Zwk)){case'a':Zvk=(*(Ztk+Zwk+1))?0:5;break;default:Zvk=-1;break;
}break;case 38:switch(*(Ztk+Zwk)){case'i':Zvk=43;break;default:Zvk=-1;break;}break;case 39:switch(*(Ztk+Zwk)){case'e':Zvk=(*(Ztk+Zwk+1))?4:9;break;
default:Zvk=-1;break;}break;case 40:switch(*(Ztk+Zwk)){case'n':Zvk=44;break;default:Zvk=-1;break;}break;case 41:switch(*(Ztk+Zwk)){case'V':Zvk=45;break;
default:Zvk=-1;break;}break;case 42:switch(*(Ztk+Zwk)){case'o':Zvk=46;break;default:Zvk=-1;break;}break;case 43:switch(*(Ztk+Zwk)){case'n':Zvk=2;break;
default:Zvk=-1;break;}break;case 44:switch(*(Ztk+Zwk)){case't':Zvk=47;break;default:Zvk=-1;break;}break;case 45:switch(*(Ztk+Zwk)){case'M':Zvk=48;break;
default:Zvk=-1;break;}break;case 46:switch(*(Ztk+Zwk)){case'w':Zvk=49;break;default:Zvk=-1;break;}break;case 47:switch(*(Ztk+Zwk)){case'o':Zvk=50;break;
default:Zvk=-1;break;}break;case 48:switch(*(Ztk+Zwk)){case'S':Zvk=(*(Ztk+Zwk+1))?7:8;break;default:Zvk=-1;break;}break;case 49:switch(*(Ztk+Zwk)){
case's':Zvk=(*(Ztk+Zwk+1))?9:1;break;default:Zvk=-1;break;}break;case 50:switch(*(Ztk+Zwk)){case's':Zvk=51;break;default:Zvk=-1;break;
}break;case 51:switch(*(Ztk+Zwk)){case'h':Zvk=(*(Ztk+Zwk+1))?5:4;break;default:Zvk=-1;break;}break;default:Zvk=-1;break;}Zwk++;}switch(Zvk){
case 0:(C->ZD1)=ZCe;ZH6((T7*)(((C)->ZH1)),Zxk);(C->ZE1)=ZDe;ZH6((T7*)(((C)->ZI1)),Zyk);break;case 1:break;case 2:(C->ZD1)=ZCe;ZH6((T7*)(((C)->ZH1)),Zzk);
(C->ZE1)=ZDe;ZH6((T7*)(((C)->ZI1)),ZAk);break;case 3:break;case 4:break;case 5:break;case 6:break;case 7:break;case 8:(C->ZD1)=Z5f;break;
case 9:(C->ZD1)=Z4f;(C->ZE1)=Z4f;break;default:;(C->ZJ1)=Zpg;}}if((((C)->ZM1))==((void*)(Zo))){{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(ZE5(4)));
(C->ZM1)=((T0*)n);}{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(ZE5(4)));(C->ZN1)=((T0*)n);}ZBk(C,ZCk);ZBk(C,ZDk);ZBk(C,ZEk);}if((((C)->Zv1))==((void*)(Zpg))){
(C->Zu1)=ZE5(1);}else if((((C)->ZD1))==((void*)(Zo))){(C->Zu1)=ZE5(2);}else{(C->Zu1)=ZE5(3);}}T0*ZSj(void){if(Zsi==0){Zsi=1;{{T38*n=((T38*)Zh(sizeof(*n)));
*n=M38;Zri=((T0*)n);}}}return Zri;}void ZFk(T12*C){T6 ZGk=0;ZGk=((T6)(!(((C)->ZO1))));if(((C)->ZO1)){ZLf(ZHk);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));
{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){Zm7((T7*)(Z_j));ZGk=((T6)((((((T7*)(Z_j))->Zl1))[ZE5(0)])==(((T3)'y'))));
}else{ZLf(ZIk);}}if(ZGk){{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}(C->ZO1)=((T6)(1));{T12*C1=C;int __s=0;{T0*c1=Zrg;T0*c2=((C1)->Zv1);Zm5(Zl7(((T7*)c1)),Zl7(((T7*)c2)));
}}ZJk(C);ZLf(ZKk);}}void ZLk(T0*a1,T0*a2){T0*ZQj=Zo;ZQj=ZMk;ZH6(((T7*)ZQj),a2);Zdf((T38*)(ZSj()),ZQj);((((T7*)((T7*)(ZTj))))->Z21)=(ZE5(0));
ZUg((T38*)(ZSj()),ZTj,ZNk);ZQ5((T7*)(ZTj),((T3)'\040'));ZV6((T7*)(ZTj),a1);ZV6((T7*)(ZTj),ZOk);ZV6((T7*)(ZTj),ZQj);ZQ5((T7*)(ZTj),((T3)'\040'));
ZV6((T7*)(ZTj),a2);ZLf(ZTj);{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Z3a((T49*)(ZWj()),ZTj);}T0*ZPk=Zo;void ZQk(T12*C,T2 a1){ZXj(ZRk);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){
if((((C)->ZM1))==((void*)(Zo))){{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(ZE5(4)));(C->ZM1)=((T0*)n);}}if((((C)->ZN1))==((void*)(Zo))){
{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(ZE5(4)));(C->ZN1)=((T0*)n);}}if((Z3)((a1)>((((T47*)(((C)->ZM1)))->Zm1)))){ZL7((T47*)(((C)->ZM1)),Zn7((T7*)(Z_j)));
ZL7((T47*)(((C)->ZN1)),ZV9(0,Z23));}else{ZH6((T7*)(((((T47*)(((C)->ZM1)))->Zl1))[a1]),Z_j);}}ZXj(ZSk);ZH6((T7*)(((((T47*)(((C)->ZN1)))->Zl1))[a1]),Z_j);
}void ZTk(T12*C){T2 _i=0;T2 Zai=0;T6 _ok=0;T6 ZUk=0;T6 ZVk=0;ZVk=((T6)(1));while(!(ZUk)){ZLf(ZWk);if((((C)->ZM1))!=((void*)(Zo))){_i=ZE5(0);
while(!((T6)(((Z3)((_i)>((((T47*)(((C)->ZM1)))->Zm1))))||((T6)(((((T7*)(((((T47*)(((C)->ZM1)))->Zl1))[_i]))->Z21))==(ZE5(0))))))){Z2j((T11)((Z3)(((_i))+((T2)(ZE5(1))))));
ZLf(ZXk);ZLf(((((T47*)(((C)->ZM1)))->Zl1))[_i]);ZLf(ZYk);ZLf(((((T47*)(((C)->ZN1)))->Zl1))[_i]);{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);
}_i=(Z3)(((_i))+(ZE5(1)));}}{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Z2j((T11)((Z3)(((_i))+((T2)(ZE5(1))))));ZLf(ZZk);Z2j((T11)((Z3)(((_i))+((T2)(ZE5(2))))));
ZLf(Z_k);Z2j((T11)((Z3)(((_i))+((T2)(ZE5(3))))));ZLf(Z0l);if(ZVk){Z2j((T11)((Z3)(((_i))+((T2)(ZE5(1))))));}else{Z2j((T11)((Z3)(((_i))+((T2)(ZE5(3))))));
}ZLf(Z1l);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));_ok=((T6)(0));if(((((T7*)(Z_j))->Z21))==(ZE5(0))){
if(ZVk){ZY5((Z3)(((_i))+((T2)(ZE5(1)))),Z_j);}else{ZY5((Z3)(((_i))+((T2)(ZE5(3)))),Z_j);}}if(Z17((T7*)(Z_j))){Zai=Zc7((T7*)(Z_j));if((T6)(((Z3)((Zai)>=(ZE5(1))))&&((T6)((Z3)((Zai)<=((Z3)(((_i))+(ZE5(3))))))))){
_ok=((T6)(1));{int z1=(Z3)(((Zai))-(_i));switch(z1){case 3:ZUk=((T6)(1));break;case 2:Z2l(C,_i);break;case 1:ZQk(C,_i);break;default:;
Z3l(C,(Z3)(((Zai))-((T2)(ZE5(1)))));}}}}if(!(_ok)){ZLf(Z4l);Z2j((T11)((Z3)(((_i))+((T2)(ZE5(3))))));ZLf(Z5l);}}}void Z6l(T12*C,T3 a1){
{T3 b1=a1;Zh9((T31*)(Zi9),b1);}if((a1)==(((T3)'\n'))){(C->ZP1)=(Z3)(((((C)->ZP1)))+(ZE5(1)));if((((C)->ZP1))==(ZE5(25))){ZLf(Z7l);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));
{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));(C->ZP1)=ZE5(1);}}}void ZBk(T12*C,T0*a1){T0*Z8l=Zo;ZAg(&(((C)->Zr1)));
Z8l=Zn7((T7*)(ZCg));ZDg(&(((C)->Zr1)));if(!((((((T7*)Z8l))->Z21))==(ZE5(0)))){ZNg(Z8l,a1);ZH6(((T7*)Z8l),ZCg);if(!((((((T7*)Z8l))->Z21))==(ZE5(0)))){
Z9l(Z8l,Zal);ZH6(((T7*)Z8l),ZCg);}}if((((((T7*)Z8l))->Z21))==(ZE5(0))){Z2a(Zjk);Z2a(Zbl);Z2a(a1);Z2a(Zcl);Zkk(C);}else{ZL7((T47*)(((C)->ZM1)),a1);
ZL7((T47*)(((C)->ZN1)),Z8l);}}void Zdl(T12*C){ZLf(Zel);if(((C)->ZO1)){ZLf(Zfl);}else{ZLf(Zgl);}}T0*Zhl=Zo;void Zil(T12*C,T2 a1){T0*Zck=Zo;
T0*Zjl=Zo;T0*Zkl=Zo;T6 ZUk=0;T6 ZVk=0;T6 Zll=0;T2 Zml=0;T2 _i=0;T2 Zai=0;ZVk=((T6)(1));while(!(ZUk)){Zck=((((ZD*)(((C)->ZK1)))->Zl1))[a1];
Zll=((T6)((((((ZF*)Zck))->ZD2))!=((void*)(Zo))));if(Zll){Zml=ZE5(12);}else{Zml=ZE5(8);}ZLf(Znl);ZLf(((((ZF*)Zck))->Zz2));{T3 b1=((T3)'\n');
Zh9((T31*)(Zi9),b1);}{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}if((((((ZF*)Zck))->Z_1))==((void*)(Zo))){Zjl=((((ZF*)Zck))->ZZ1);if((Zjl)==((void*)(Zo))){
Zjl=((((ZF*)Zck))->ZA2);}}if((((((ZF*)Zck))->Z22))==((void*)(Zo))){Zkl=((((ZF*)Zck))->Z12);if((Zkl)==((void*)(Zo))){Zkl=((((ZF*)Zck))->ZD2);
}}Zol(Zpl,((((ZF*)Zck))->ZA2),Zo);Zol(Zql,((((ZF*)Zck))->ZZ1),((((ZF*)Zck))->ZA2));Zol(Zrl,((((ZF*)Zck))->ZB2),Zo);Zol(Zsl,((((ZF*)Zck))->Z_1),Zjl);
Zol(Ztl,((((ZF*)Zck))->ZC2),Zo);Zol(Zul,((((ZF*)Zck))->ZD2),Zo);if(Zll){Zol(Zvl,((((ZF*)Zck))->Z12),((((ZF*)Zck))->ZD2));Zol(Zwl,((((ZF*)Zck))->ZE2),Zo);
Zol(Zxl,((((ZF*)Zck))->Z22),Zkl);Zol(Zyl,((((ZF*)Zck))->ZF2),Zo);Zol(Zzl,((((ZF*)Zck))->ZG2),Zo);ZLf(ZAl);}else{Zol(ZBl,((((ZF*)Zck))->ZG2),Zo);
ZLf(ZCl);}if(ZVk){ZLf(ZDl);}else if(Zll){ZLf(ZEl);}else{ZLf(ZFl);}((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);
}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));if(((((T7*)(Z_j))->Z21))==(ZE5(0))){if(ZVk){ZN5(ZE5(1),Z_j);}else if(Zll){ZN5(ZE5(12),Z_j);}else{ZN5(ZE5(8),Z_j);
}}if(Zp7((T7*)(Z_j))){Zai=Zc7((T7*)(Z_j));if((T6)(((Z3)((Zai)>=(ZE5(1))))&&((T6)((Z3)((Zai)<=(Zml)))))){{int z1=Zai;switch(z1){case 1:
ZLf(ZGl);_i=(((T42*)(ZHl()))->ZV2);while(!((Z3)((_i)>((((T42*)(ZHl()))->Zm1))))){if((Z3)((_i)>((((T42*)(ZHl()))->ZV2)))){ZLf(ZIl);}ZLf(ZU7((T42*)(ZHl()),_i));
_i=(Z3)(((_i))+(ZE5(1)));}{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}ZXj(ZJl);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){if(Z38((T42*)(ZHl()),Z_j)){
Zxi(((ZF*)Zck),((((ZF*)Zck))->Zz2),ZKl(Z_j,Zo),ZU7((T42*)((((void)((T38*)(ZSj()))),Z9h())),ZW7((T42*)((((void)((T38*)(ZSj()))),Z9h())),ZLl(ZMl,Z_j))),((((ZF*)Zck))->Zy2),((((ZF*)Zck))->ZD2));
}else{ZLf(ZNl);}}break;case 2:ZXj(ZOl);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){if(Zp9(Z_j)){Zzi(((ZF*)Zck),Z_j);}else{ZLf(ZPl);}}break;
case 3:ZXj(ZQl);ZAi(((ZF*)Zck),Z_j);break;case 4:ZXj(ZRl);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){if(Zp9(Z_j)){ZBi(((ZF*)Zck),Z_j);ZCi(((ZF*)Zck),Zo);
}else{ZLf(ZSl);}}break;case 5:ZXj(ZTl);ZCi(((ZF*)Zck),Z_j);break;case 6:ZLf(ZUl);_i=(((T42*)(ZVl()))->ZV2);while(!((Z3)((_i)>((((T42*)(ZVl()))->Zm1)))))
{if((Z3)((_i)>((((T42*)(ZVl()))->ZV2)))){ZLf(ZWl);}ZLf(ZU7((T42*)(ZVl()),_i));_i=(Z3)(((_i))+(ZE5(1)));}{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);
}ZXj(ZXl);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){if(Za6((T7*)(Z_j),Z_h)){Zxi(((ZF*)Zck),((((ZF*)Zck))->Zz2),((((ZF*)Zck))->Zx2),((((ZF*)Zck))->ZA2),Zo,Zo);
}else if(Z38((T42*)(ZVl()),Z_j)){Zxi(((ZF*)Zck),((((ZF*)Zck))->Zz2),((((ZF*)Zck))->Zx2),((((ZF*)Zck))->ZA2),ZKl(Z_j,Zo),ZU7((T42*)((((void)((T38*)(ZSj()))),ZZh())),ZW7((T42*)((((void)((T38*)(ZSj()))),ZZh())),ZLl(ZPk,Z_j))));
}else{ZLf(ZYl);}}break;case 7:if(Zll){ZXj(ZZl);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){if(Zp9(Z_j)){Zui(((ZF*)Zck),Z_j);}else{ZLf(Z_l);
}}}else{ZXj(Z0m);Zvi(((ZF*)Zck),Z_j);}break;case 8:if(Zll){ZXj(Z1m);ZDi(((ZF*)Zck),Z_j);}else{ZUk=((T6)(1));}break;case 9:ZXj(Z2m);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){
if(Zp9(Z_j)){Zwi(((ZF*)Zck),Z_j);ZEi(((ZF*)Zck),Zo);}else{ZLf(Z3m);}}break;case 10:ZXj(Z4m);ZEi(((ZF*)Zck),Z_j);break;case 11:ZXj(Z5m);
Zvi(((ZF*)Zck),Z_j);break;default:;ZUk=((T6)(1));}}ZVk=((T6)(0));}else{ZLf(Z6m);Z2j((T11)(Zml));ZLf(Z7m);}}else{ZLf(Z8m);Z2j((T11)(Zml));
ZLf(Z9m);}}}void Zam(T12*C,T0*a1){T0*_p=Zo;{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,a1);_p=((T0*)n);}Z5i((T45*)(Zik()),_p);if(!((((T45*)(Zik()))->Zf2))){
ZQg(a1);if((Z3)(((((T7*)(ZCg))->Z21))>(ZE5(0)))){Zam(C,ZCg);}else{Z2a(Zjk);Z2a(Zbm);Z2a(a1);Z2a(Zcm);Zkk(C);}}Z5i((T45*)(Zik()),_p);}
T0*Zdm=Zo;void Zem(T12*C){if((T6)(((T6)(((ZEg)==((void*)(Zo)))||((T6)((ZRg)==((void*)(Zo))))))||((T6)(Za6((T7*)(ZRg),Zfm))))){(C->Zv1)=Zgm;
}else{(C->Zv1)=ZOj;ZH6((T7*)(((C)->Zv1)),ZEg);if((ZK6((T7*)(((C)->Zv1))))!=(((T3)'\057'))){ZQ5((T7*)(((C)->Zv1)),((T3)'\057'));}ZV6((T7*)(((C)->Zv1)),Zhm);
}}void Zim(T12*C,T0*a1){T6 ZUk=0;T0*_s=Zo;if(Zf7(((T7*)Zjm),((C)->ZJ1))){Zm7(((T7*)a1));_s=Zn7(((T7*)a1));while(!(ZUk)){if((((((T7*)_s))->Z21))==(ZE5(0))){
ZUk=((T6)(1));}else if((ZK6(((T7*)_s)))==(((T3)'\073'))){Z97(((T7*)_s),(T2)(ZE5(1)));ZH6(((T7*)a1),_s);ZUk=((T6)(1));}else if(Zz5(ZK6(((T7*)_s)))){
Z97(((T7*)_s),(T2)(ZE5(1)));}else{ZUk=((T6)(1));}}}}T0*Z7k=Zo;T0*Zkm(void){if(Z8g==0){Z8g=1;{{T72*n=((T72*)Zh(sizeof(*n)));*n=M72;Z7g=((T0*)n);
Zag(n);}}}return Z7g;}T0*Zek(T0*a1){T0*R=Zo;T0*ZS1=Zo;ZS1=Zlm(a1);if((ZS1)!=((void*)(Zo))){R=ZKl(ZS1,Zo);}return R;}T0*Z5k=Zo;void Zmm(T12*C){
T2 Znm=0;while(!(((C)->Zt1))){Znm=Zom(C);{int z1=Znm;switch(z1){case 1:Zpm(C);(C->Zu1)=ZE5(2);break;case 2:Zqm(C);(C->Zu1)=ZE5(3);break;
case 3:Zrm(C);(C->Zu1)=ZE5(4);break;case 4:Zsm(C);(C->Zu1)=ZE5(5);break;case 5:ZFk(C);(C->Zu1)=ZE5(6);break;case 6:Ztm(C);break;default:;
}}}}void Zum(T12*C){ZLf(Zvm);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));ZLf(Zwm);
Zxm(C);Zmm(C);Zdl(C);}void Zym(T12*C){int _s=0;T6 Zzm=0;if(Zok(ZAm)){ZBm(C,Zve);(C->Zv1)=ZCm;Zzm=((T6)(1));}else if(Zok(ZDm)){ZBm(C,Zre);
}else if(Zok(ZEm)){ZBm(C,Zpe);}else if(Zok(ZFm)){ZBm(C,Zoe);Zem(C);}else if(Zok(ZGm)){ZBm(C,Zme);Zem(C);}else{if(ZEf()){if(ZFf()){ZBm(C,Zme);
Zem(C);}else if(ZHf()){ZBm(C,Zne);ZHm(C);}else if(ZGf()){ZBm(C,Zoe);Zem(C);}else if(ZJf()){ZBm(C,Zre);}else if(ZIf()){ZBm(C,Zqe);}else
if(ZKf()){ZBm(C,Zue);}}if((((C)->ZJ1))==((void*)(Zo))){Zbi(&(((C)->Zr1)),ZIm);if((Zo!=((((C)->Zr1)).ZY))){ZBm(C,Zne);ZDg(&(((C)->Zr1)));
}}}Zx9((T38*)(ZSj()));if((Zog)!=((void*)(Zo))){(C->Zv1)=Zog;}else if((((C)->Zv1))==((void*)(Zo))){(C->Zv1)=(((T38*)(ZSj()))->Zv1);}else
if((T6)((!(Zzm))&&((T6)(((((T38*)(ZSj()))->Zv1))!=((void*)(Zpg)))))){(C->Zv1)=(((T38*)(ZSj()))->Zv1);}else{(C->Zv1)=Zpg;}}void ZJm(T12*C){
T2 _i=0;T6 _ok=0;ZXj(ZKm);if((T6)((Za6((T7*)(Z_j),Zsh))||((T6)(Za6((T7*)(Z_j),ZYg))))){ZLf(ZLm);}else{_i=ZE5(0);_ok=((T6)(1));while(!((T6)((!(_ok))||((T6)((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))))))
{if(Za6((T7*)((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Zz2)),Z_j)){_ok=((T6)(0));ZLf(ZMm);}_i=(Z3)(((_i))+(ZE5(1)));}if(_ok){Zx7((ZD*)(((C)->ZK1)),((T0*)Zpi(Z_j,Zek(((C)->ZD1)),((C)->ZD1),Zek(((C)->ZE1)),((C)->ZE1))));
Zil(C,(((ZD*)(((C)->ZK1)))->Zm1));}}}T0*ZWj(void){if(ZHa==0){ZHa=1;{{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;ZGa=((T0*)n);}}}return ZGa;}
T2 Zom(T12*C){T2 R=0;T6 _ok=0;while(!(_ok)){ZLf(ZNm);if((((C)->ZJ1))==((void*)(Zo))){ZLf(Zpg);}else{ZLf(((C)->ZJ1));}ZLf(ZOm);if((((C)->Zv1))==((void*)(Zo))){
ZLf(Zpg);}else{ZLf(((C)->Zv1));}ZLf(ZPm);Z2j((T11)(((C)->Zu1)));ZLf(ZQm);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);
}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));Zm7((T7*)(Z_j));if(((((T7*)(Z_j))->Z21))==(ZE5(0))){R=((C)->Zu1);_ok=((T6)(1));}else if((T6)(((((((T7*)(Z_j))->Zl1))[ZE5(0)])==(((T3)'h')))||((T6)((((((T7*)(Z_j))->Zl1))[ZE5(0)])==(((T3)'H')))))){
ZRm(C);R=ZE5(-1);_ok=((T6)(1));}else if(Z17((T7*)(Z_j))){R=Zc7((T7*)(Z_j));_ok=((T6)((T6)(((Z3)((R)>(ZE5(0))))&&((T6)((Z3)((R)<=(ZE5(6))))))));
}if(!(_ok)){ZLf(ZSm);ZLf(Z_j);ZLf(ZTm);}}return R;}T0*ZUm=Zo;int ZVm=0;T0*ZWm(T12*C){if(ZVm==0){ZVm=1;{ZAg(&(((C)->Zr1)));if((Zo!=((((C)->Zr1)).ZY))){
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZUm=((T0*)n);ZH6(n,ZCg);}ZDg(&(((C)->Zr1)));ZNg(ZUm,ZXm);ZH6(((T7*)ZUm),ZCg);}}}return ZUm;}T6 ZYm(T12*C,T0*a1){
T6 R=0;T2 _i=0;_i=ZE5(0);while(!((T6)((R)||((T6)((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1)))))))){R=((T6)(Za6((T7*)((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Zz2)),a1)));
_i=(Z3)(((_i))+(ZE5(1)));}return R;}void ZZm(T0*a1,T0*a2,T0*a3,T6 a4){T0*Z_m=Zo;Z_m=Z0n;ZXj(a1);ZH6(((T7*)Z_m),Z_j);(((void)((T38*)(ZSj()))),ZUf(Zo,Z_m));
Z5i((T45*)(Zik()),Z_m);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){if(!((((T45*)(Zik()))->Zf2))){Zjg((T45*)(Zik()));if(Zdi((T45*)(Zik()),Z_m)){
Z7i((T45*)(Zik()),Z_m);}else{Z5i((T45*)(Zik()),Z_m);}}if((((T45*)(Zik()))->Zf2)){ZH6(((T7*)a2),Z_j);ZH6(((T7*)a3),Z_m);}else if(a4){ZLf(Z1n);
((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));if((ZK5(((((T7*)(Z_j))->Zl1))[ZE5(0)]))==(((T3)'y'))){
ZH6(((T7*)a2),Z_j);ZH6(((T7*)a3),Z_m);}}else{Zpk(Z_j);}}}void Zxm(T12*C){T6 Z2n=0;{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));
(C->ZH1)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZJ6(n,(T2)(ZE5(16)));(C->ZI1)=((T0*)n);}((((T53*)((T53*)(ZOf))))->Zi1)=((T6)(1));
ZAg(&(((C)->Zr1)));(C->Zs1)=Zn7((T7*)(ZCg));ZDg(&(((C)->Zr1)));Zym(C);Z3n(C);Z2n=((T6)((T6)(((T6)(((T6)(((((C)->Zv1))!=((void*)(Zpg)))&&((T6)(Zp9(((C)->Zv1))))))&&((T6)(!((((T51*)(Zng))->Zr2))))))&&((T6)(Z4n(C))))));
Zsk(C);if(!(Z2n)){Zhk(C);}if(Zfk(C)){if(Z2n){(C->Zu1)=ZE5(3);}else{Z8k(C,(T6)(1));}}else{(C->Zu1)=ZE5(5);}(C->ZA1)=Z5n;ZH6((T7*)(((C)->ZA1)),((C)->Zw1));
(((void)((T38*)(ZSj()))),ZUf(Zo,((C)->ZA1)));(C->ZB1)=Z6n;ZH6((T7*)(((C)->ZB1)),((C)->Zx1));(((void)((T38*)(ZSj()))),ZUf(Zo,((C)->ZB1)));
(C->ZC1)=Z7n;ZH6((T7*)(((C)->ZC1)),((C)->Zy1));(((void)((T38*)(ZSj()))),ZUf(Zo,((C)->ZC1)));((((T38*)((T38*)(ZSj()))))->Zw1)=(((C)->ZA1));
((((T38*)((T38*)(ZSj()))))->Zx1)=(((C)->ZB1));((((T38*)((T38*)(ZSj()))))->Zy1)=(((C)->ZC1));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZH6(n,Zpj);
(C->ZG1)=((T0*)n);}}void Zrm(T12*C){T2 _i=0;T0*Zck=Zo;(C->ZP1)=ZE5(1);Z8n(C,Z9n);Z8n(C,((C)->Zv1));Z8n(C,Zan);Z8n(C,((C)->ZJ1));Z8n(C,Zbn);
Z8n(C,((C)->Zw1));Z8n(C,Zcn);Z8n(C,((C)->Zx1));Z8n(C,Zdn);Z8n(C,((C)->Zy1));Z6l(C,((T3)'\n'));_i=ZE5(0);while(!((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1)))))
{Zck=((((ZD*)(((C)->ZK1)))->Zl1))[_i];if((Z3)((_i)>(ZE5(0)))){Z6l(C,((T3)'\n'));}Z8n(C,Zen);Z8n(C,((((ZF*)Zck))->Zz2));Z8n(C,Zfn);Z8n(C,((((ZF*)Zck))->ZA2));
if((((((ZF*)Zck))->ZZ1))!=((void*)(Zo))){Z8n(C,Zgn);Z8n(C,((((ZF*)Zck))->ZZ1));}if((((((ZF*)Zck))->ZB2))!=((void*)(Zo))){Z8n(C,Zhn);Z8n(C,((((ZF*)Zck))->ZB2));
}if((((((ZF*)Zck))->Z_1))!=((void*)(Zo))){Z8n(C,Zin);Z8n(C,((((ZF*)Zck))->Z_1));}if((((((ZF*)Zck))->ZC2))!=((void*)(Zo))){Z8n(C,Zjn);
Z8n(C,((((ZF*)Zck))->ZC2));}if((T6)(((((((ZF*)Zck))->ZD2))!=((void*)(Zo)))&&((T6)((((((ZF*)Zck))->ZD2))!=((void*)(Z_h)))))){Z8n(C,Zkn);
Z8n(C,((((ZF*)Zck))->ZD2));if((((((ZF*)Zck))->Z12))!=((void*)(Zo))){Z8n(C,Zln);Z8n(C,((((ZF*)Zck))->Z12));}if((((((ZF*)Zck))->ZE2))!=((void*)(Zo))){
Z8n(C,Zmn);Z8n(C,((((ZF*)Zck))->ZE2));}if((((((ZF*)Zck))->Z22))!=((void*)(Zo))){Z8n(C,Znn);Z8n(C,((((ZF*)Zck))->Z22));}if((((((ZF*)Zck))->ZF2))!=((void*)(Zo))){
Z8n(C,Zon);Z8n(C,((((ZF*)Zck))->ZF2));}}if((((((ZF*)Zck))->ZG2))!=((void*)(Zo))){Z8n(C,Zpn);Z8n(C,((((ZF*)Zck))->ZG2));}_i=(Z3)(((_i))+(ZE5(1)));
}if((((C)->ZM1))!=((void*)(Zo))){Z6l(C,((T3)'\n'));_i=ZE5(0);while(!((T6)(((Z3)((_i)>((((T47*)(((C)->ZM1)))->Zm1))))||((T6)(((((T7*)(((((T47*)(((C)->ZM1)))->Zl1))[_i]))->Z21))==(ZE5(0)))))))
{Z8n(C,Zqn);Z8n(C,((((T47*)(((C)->ZM1)))->Zl1))[_i]);Z8n(C,Zrn);Z8n(C,((((T47*)(((C)->ZN1)))->Zl1))[_i]);_i=(Z3)(((_i))+(ZE5(1)));}}if((((C)->ZD1))!=((void*)(Zo))){
Z8n(C,Zsn);Z8n(C,((C)->ZD1));}else{Z8n(C,Ztn);}Z6l(C,((T3)'\n'));ZLf(Zun);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);
}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));}void ZHm(T12*C){T2 _i=0;T6 Zhg=0;if((ZAe)==((void*)(Zo))){(C->Zv1)=Zvn;_i=(((T42*)(Zdm))->ZV2);while(!((T6)((Zhg)||((T6)((Z3)((_i)>((((T42*)(Zdm))->Zm1))))))))
{Zbi(&(((C)->Zr1)),ZU7((T42*)(Zdm),_i));Zhg=((T6)((Zo!=((((C)->Zr1)).ZY))));_i=(Z3)(((_i))+(ZE5(1)));}if(!(Zhg)){ZBm(C,Zse);}else{ZDg(&(((C)->Zr1)));
}}else{(C->Zv1)=ZOj;ZH6((T7*)(((C)->Zv1)),ZAe);if((ZK6((T7*)(((C)->Zv1))))!=(((T3)'\134'))){ZQ5((T7*)(((C)->Zv1)),((T3)'\134'));}ZV6((T7*)(((C)->Zv1)),Zwn);
}}void Zxn(T0*a1){((((T7*)((T7*)(ZTj))))->Z21)=(ZE5(0));ZUg((T38*)(ZSj()),ZTj,Zyn);ZQ5((T7*)(ZTj),((T3)'\040'));ZV6((T7*)(ZTj),a1);ZLf(ZTj);
{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Z3a((T49*)(ZWj()),ZTj);}T0*Zzn=Zo;void ZAn(T12*C){if((((C)->Zv1))!=((void*)(Zpg))){ZQg(((C)->Zv1));
if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){Zam(C,ZCg);}Zz9((ZL*)(Zhl),((C)->Zv1));if(!(((((ZL*)(Zhl))->ZS1))!=(Zo))){Z2a(Zjk);Z2a(ZBn);Z2a(((C)->Zv1));
Z2a(ZV9(2,Z93));Zkk(C);}}}T0*ZKl(T0*a1,T0*a2){T0*R=Zo;if(ZG8((ZH*)(Zzn),a1)){R=ZC8((ZH*)(Zzn),a1);}else if((a2)!=((void*)(Zo))){Zph((T72*)(Zkm()),a2);
if(((((T72*)(Zkm()))->ZS1))!=(Zo)){{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;R=((T0*)n);}Zqh(((T51*)R));}ZD8((ZH*)(Zzn),R,Zn7(((T7*)a1)));
}return R;}void Ztm(T12*C){if(((C)->ZO1)){(C->Zt1)=((T6)(1));}else{ZLf(ZCn);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);
}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));Zm7((T7*)(Z_j));(C->Zt1)=((T6)((T6)(((Z3)(((((T7*)(Z_j))->Z21))>(ZE5(0))))&&((T6)((((((T7*)(Z_j))->Zl1))[ZE5(0)])==(((T3)'y')))))));
}}void Zkk(T12*C){Z2a(ZDn);ZEn(C);ZFn(C,ZE5(1));}void ZEn(T12*C){if((((C)->Zs1))!=((void*)(Zo))){ZGn(&(((C)->Zr1)),((C)->Zs1));}}T0*ZHn(void){
T0*R=Zo;{T81*n=((T81*)Zh(1));R=((T0*)n);}return R;}T0*ZTj=Zo;void Z3l(T12*C,T2 a1){ZLf(ZIn);ZLf(((((T47*)(((C)->ZM1)))->Zl1))[a1]);ZLf(ZJn);
ZLf(((((T47*)(((C)->ZN1)))->Zl1))[a1]);{T3 b1=((T3)'\056');Zh9((T31*)(Zi9),b1);}ZXj(ZKn);if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){ZH6((T7*)(((((T47*)(((C)->ZN1)))->Zl1))[a1]),Z_j);
}}T6 Z4n(T12*C){T6 R=0;T0*Zw2=Zo;T0*ZLn=Zo;T0*ZMn=Zo;T0*ZNn=Zo;T0*ZOn=Zo;T0*Zu7=Zo;T0*Zck=Zo;T0*ZPn=Zo;if(Zrh((T51*)(Zng),Zsh,ZQn)){ZPn=Z0h((T51*)(Zng),Zsh,ZQn);
}else{ZPn=ZRn;}if(!(Za6(((T7*)ZPn),ZSn))){ZLf(ZV9(67,"*** Your installation file has an old format. It will not be used.\n"));}else{if((T6)(((T6)(((T6)((!(Zrh((T51*)(Zng),Zsh,Zth)))||((T6)(!(Zrh((T51*)(Zng),Zsh,Zvh))))))||((T6)(!(Zrh((T51*)(Zng),Zsh,Zwh))))))||((T6)(!(Zrh((T51*)(Zng),Zsh,Zxh)))))){
ZLf(ZTn);}else{(C->Zw1)=Z0h((T51*)(Zng),Zsh,Zth);(C->Zx1)=Z0h((T51*)(Zng),Zsh,Zvh);(C->Zy1)=Z0h((T51*)(Zng),Zsh,Zwh);ZBm(C,Z0h((T51*)(Zng),Zsh,Zxh));
ZLn=ZXg((T51*)(Zng),ZYg);if((ZLn)!=((void*)(Zo))){{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZM7(n,(T2)(ZE5(4)));(C->ZM1)=((T0*)n);}{T47*n=((T47*)Zh(sizeof(*n)));
*n=M47;ZM7(n,(T2)(ZE5(4)));(C->ZN1)=((T0*)n);}while(!(ZZg(ZLn))){ZL7((T47*)(((C)->ZM1)),Z1h(ZLn));ZL7((T47*)(((C)->ZN1)),Z0h((T51*)(Zng),ZYg,Z1h(ZLn)));
Z2h(ZLn);}}Zw2=Zgk((T51*)(Zng));if((Zw2)!=((void*)(Zo))){ZUn(Zw2);{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Zn1;Zy7(n,(T2)(ZE5(8)));(C->ZK1)=((T0*)n);
}{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Zn1;Zy7(n,(T2)(ZE5(8)));(C->ZL1)=((T0*)n);}while(!(ZZg(Zw2))){ZMn=Z1h(Zw2);if((T6)(((T6)((!(Za6(((T7*)ZMn),Zsh)))&&((T6)(!(Za6(((T7*)ZMn),ZYg))))))&&((T6)(Zrh((T51*)(Zng),ZMn,ZGi))))){
ZNn=Z0h((T51*)(Zng),ZMn,ZGi);if(Zrh((T51*)(Zng),ZMn,ZMi)){ZOn=Z0h((T51*)(Zng),ZMn,ZMi);}else{ZOn=Zo;}{ZF*n=((ZF*)Zh(sizeof(*n)));*n=ZT2;
Zqi(n,ZMn,Zek(ZNn),ZNn,Zek(ZOn),ZOn);Zck=((T0*)n);}if(Zrh((T51*)(Zng),ZMn,ZHi)){Zu7=Z0h((T51*)(Zng),ZMn,ZHi);Zzi(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZIi)){
Zu7=Z0h((T51*)(Zng),ZMn,ZIi);ZAi(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZJi)){Zu7=Z0h((T51*)(Zng),ZMn,ZJi);ZBi(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZKi)){
Zu7=Z0h((T51*)(Zng),ZMn,ZKi);ZCi(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZLi)){Zu7=Z0h((T51*)(Zng),ZMn,ZLi);Zvi(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZNi)){
Zu7=Z0h((T51*)(Zng),ZMn,ZNi);Zui(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZOi)){Zu7=Z0h((T51*)(Zng),ZMn,ZOi);ZDi(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZPi)){
Zu7=Z0h((T51*)(Zng),ZMn,ZPi);Zwi(((ZF*)Zck),Zu7);}if(Zrh((T51*)(Zng),ZMn,ZQi)){Zu7=Z0h((T51*)(Zng),ZMn,ZQi);ZEi(((ZF*)Zck),Zu7);}Zx7((ZD*)(((C)->ZK1)),Zck);
}Z2h(Zw2);}}R=((T6)(1));}}return R;}void ZBm(T12*C,T0*a1){T0*ZVn=Zo;T2 _i=0;ZVn=a1;if(!(Z48((T42*)((((void)((T38*)(ZSj()))),Zke())),ZVn))){
_i=ZW7((T42*)((((void)((T38*)(ZSj()))),Zke())),a1);if(ZV7((T42*)((((void)((T38*)(ZSj()))),Zke())),_i)){ZVn=ZU7((T42*)((((void)((T38*)(ZSj()))),Zke())),_i);
}else{ZVn=Zpg;}}if((ZVn)!=((void*)(Zpg))){(C->ZJ1)=ZVn;ZBf((T38*)(ZSj()),ZVn);}}void Z8n(T12*C,T0*a1){T2 _i=0;T0*_s0=Zo;if((a1)==((void*)(Zo))){
_s0=Zpg;}else{_s0=a1;}_i=ZE5(1);while(!((Z3)((_i)>(((((T7*)_s0))->Z21))))){Z6l(C,(((((T7*)_s0))->Zl1))[(_i)-(ZE5(1))]);_i=(Z3)(((_i))+(ZE5(1)));
}}T0*ZMl=Zo;T0*Z_j=Zo;void Z3n(T12*C){T2 _i=0;T0*ZWn=Zo;T0*_c=Zo;T0*Zj1=Zo;T0*ZXn=Zo;Z8i((T45*)(Zik()),ZWm(C));if((((T45*)(Zik()))->Zf2)){
_i=ZE5(1);while(!((Z3)((_i)>(Z6i((T45*)(Zik())))))){ZWn=ZYn;Zj1=ZZn;ZH6(((T7*)ZWn),(((((T47*)((((T45*)(Zik()))->Zg2))))->Zl1))[(_i)-(ZE5(1))]);
Zm7(((T7*)ZWn));ZH6(((T7*)Zj1),ZWn);if(Z07(((T7*)ZWn),Z_n)){Z97(((T7*)Zj1),(T2)(ZE5(3)));Z9l((((T45*)(Zik()))->ZS1),ZWn);ZH6(((T7*)ZWn),ZCg);
ZXn=ZKl(Zj1,ZWn);if((ZXn)!=((void*)(Zo))){Zj1=Zn7(((T7*)Zj1));if(ZFi(((T51*)ZXn),ZGi)){_c=Zf8(((T62*)(((((T51*)ZXn))->Zv2))),ZGi);if((T6)(((T6)(((_c)!=((void*)(Zo)))&&((T6)(!(Za6(((T7*)_c),Z_h))))))&&((T6)(Z38((T42*)((((void)((T38*)(ZSj()))),Z9h())),_c))))){
_c=ZU7((T42*)((((void)((T38*)(ZSj()))),Z9h())),ZW7((T42*)((((void)((T38*)(ZSj()))),Z9h())),_c));ZRi(ZMl,_c,Zj1);}else{Z2a(Zjk);Z2a(Z0o);
Z2a(ZWn);Z2a(Z1o);Z2a(ZGi);Z2a(Z2o);Zkk(C);}}else{Z2a(Zjk);Z2a(Z3o);Z2a(ZWn);Z2a(Z4o);Z2a(ZGi);Z2a(Z5o);Zkk(C);}if(ZFi(((T51*)ZXn),ZMi)){
_c=Zf8(((T62*)(((((T51*)ZXn))->Zv2))),ZMi);if((T6)(((_c)!=((void*)(Zo)))&&((T6)(!(Za6(((T7*)_c),Z_h)))))){if(Z38((T42*)((((void)((T38*)(ZSj()))),ZZh())),_c)){
_c=ZU7((T42*)((((void)((T38*)(ZSj()))),ZZh())),ZW7((T42*)((((void)((T38*)(ZSj()))),ZZh())),_c));ZRi(ZPk,_c,Zj1);}else{Z2a(Zjk);Z2a(Z6o);
Z2a(ZWn);Z2a(Z7o);Z2a(ZMi);Z2a(Z8o);Zkk(C);}}}}}_i=(Z3)(((_i))+(ZE5(1)));}}}void Zqm(T12*C){T6 ZUk=0;T6 ZVk=0;T0*Z9o=Zo;T2 _i=0;T2 Zai=0;
(C->ZO1)=((T6)(0));ZVk=((T6)(1));while(!(ZUk)){ZLf(Zao);if((((C)->ZD1))==((void*)(Zo))){ZLf(Zpg);}else{ZLf(((C)->ZD1));}{T3 b1=((T3)'\n');
Zh9((T31*)(Zi9),b1);}{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}_i=ZE5(0);while(!((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))){Z2j((T11)((Z3)(((_i))+((T2)(ZE5(1))))));
ZLf(Zbo);ZLf((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Zz2));ZLf(Zco);_i=(Z3)(((_i))+(ZE5(1)));}_i=(Z3)(((_i))+(ZE5(1)));{T3 b1=((T3)'\n');
Zh9((T31*)(Zi9),b1);}Z2j((T11)(_i));ZLf(Zdo);Z2j((T11)((Z3)(((_i))+((T2)(ZE5(1))))));{T0*b1=Zeo;T0*b2=((C)->ZD1);Zol(b1,b2,Zo);}Z2j((T11)((Z3)(((_i))+((T2)(ZE5(2))))));
{T0*b1=Zfo;T0*b2=((C)->ZH1);Zol(b1,b2,Zo);}{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Z2j((T11)((Z3)(((_i))+((T2)(ZE5(3))))));ZLf(ZV9(40,". Return to the main menu\n\nYour choice ["));
if(ZVk){Z2j((T11)((Z3)(((_i))+((T2)(ZE5(1))))));}else{Z2j((T11)((Z3)(((_i))+((T2)(ZE5(3))))));}ZLf(Zgo);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));
{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));if(((((T7*)(Z_j))->Z21))==(ZE5(0))){if(ZVk){ZY5((Z3)(((_i))+((T2)(ZE5(1)))),Z_j);
}else{ZY5((Z3)(((_i))+((T2)(ZE5(3)))),Z_j);}}if(Z17((T7*)(Z_j))){Zai=Zc7((T7*)(Z_j));if((T6)(((Z3)((Zai)<(ZE5(1))))||((T6)((Z3)((Zai)>((Z3)(((_i))+(ZE5(3))))))))){
ZLf(Zho);Z2j((T11)((Z3)(((_i))+((T2)(ZE5(3))))));ZLf(Zio);}else{{int z1=(Z3)(((Zai))-(_i));switch(z1){case 3:ZUk=((T6)(1));break;case
2:ZXj(Zjo);ZH6((T7*)(((C)->ZH1)),Z_j);_i=ZE5(0);while(!((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))){if((T6)((((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Z_1))!=((void*)(Zo)))&&((T6)((Z3)(((((T7*)((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Z_1)))->Z21))>(ZE5(0))))))){
ZCi((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]),((C)->ZH1));}else{ZCi((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]),Zo);}ZAi((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]),((C)->ZH1));
_i=(Z3)(((_i))+(ZE5(1)));}ZH6((T7*)(((C)->ZI1)),((C)->ZH1));if((T6)(((((C)->ZE1))!=((void*)(Zo)))&&((T6)((((C)->ZE1))!=((void*)(Z_h)))))){
ZXj(Zko);ZH6((T7*)(((C)->ZI1)),Z_j);_i=ZE5(0);while(!((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))){if((T6)((((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Z22))!=((void*)(Zo)))&&((T6)((Z3)(((((T7*)((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Z22)))->Z21))>(ZE5(0))))))){
ZEi((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]),((C)->ZI1));}else{ZEi((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]),Zo);}ZDi((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]),((C)->ZI1));
_i=(Z3)(((_i))+(ZE5(1)));}}break;case 1:Z9o=((C)->ZD1);(C->ZD1)=Zlo(Zmo,ZHl(),Z9o);((((T7*)((T7*)(((C)->ZH1)))))->Z21)=(ZE5(0));if(Z38((T42*)((((void)((T38*)(ZSj()))),ZZh())),((C)->ZD1))){
(C->ZE1)=((C)->ZD1);ZH6((T7*)(((C)->ZI1)),((C)->ZH1));}else{ZLf(Zno);Z9o=((C)->ZE1);if((T6)(((Z9o)==((void*)(Zo)))||((T6)((Z9o)==((void*)(Zpg)))))){
Z9o=Z_h;}(C->ZE1)=Zlo(Zoo,ZVl(),Z9o);if((((C)->ZE1))==((void*)(Z_h))){(C->ZE1)=Zpg;}((((T7*)((T7*)(((C)->ZI1)))))->Z21)=(ZE5(0));}Z8k(C,(T6)(1));
break;case 0:ZJm(C);break;default:;Zil(C,(Z3)(((Zai))-((T2)(ZE5(1)))));}}}ZVk=((T6)(0));}else{ZLf(Zpo);Z2j((T11)((Z3)(((_i))+((T2)(ZE5(3))))));
ZLf(Zqo);}}}void ZJk(T12*C){T0*Zro=Zo;T0*Zso=Zo;T0*Zto=Zo;T0*Zuo=Zo;T0*Zvo=Zo;T0*Zwo=Zo;T0*Zxo=Zo;T0*_s=Zo;T2 _i=0;T6 Zyo=0;T6 Zhg=0;
T6 Zzo=0;Zro=ZAo;Zso=ZBo;Zyo=((T6)(1));Zjg((T45*)(Zik()));if(!(Zdi((T45*)(Zik()),Zro))){Zyo=((T6)(0));}else{Z7i((T45*)(Zik()),Zro);if(!(Zdi((T45*)(Zik()),Zso))){
Zyo=((T6)(0));}else{Z7i((T45*)(Zik()),Zso);}}if(!(Zyo)){Z2a(Zjk);Z2a(ZCo);Zkk(C);}ZH6((T7*)(ZNj),(((T45*)(Zik()))->ZS1));{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZH6(n,ZNj);(C->Zz1)=((T0*)n);}if((Zo!=((((C)->Zr1)).ZY))){ZDg(&(((C)->Zr1)));}ZLf(ZDo);ZLf(ZEo);while(!(Zhg)){ZLf(ZFo);ZLf(((C)->ZG1));
ZLf(ZGo);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));if(((((T7*)(Z_j))->Z21))==(ZE5(0))){
Zhg=((T6)(1));_i=ZE5(0);Zhg=((T6)(0));while(!(Zhg)){if(Za6((T7*)((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Zz2)),((C)->ZG1))){Zto=(((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->ZA2);
Zhg=((T6)(1));}else{_i=(Z3)(((_i))+(ZE5(1)));}}}else{_i=ZE5(0);Zhg=((T6)(0));while(!((T6)((Zhg)||((T6)((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))))))
{Zhg=((T6)(Za6((T7*)((((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Zz2)),Z_j)));if(Zhg){ZH6((T7*)(((C)->ZG1)),Z_j);Zto=(((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->ZA2);
}else{_i=(Z3)(((_i))+(ZE5(1)));}}if(!(Zhg)){ZLf(ZHo);}}}(C->ZF1)=Zto;Zuo=(((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->ZB2);if((Zuo)==((void*)(Zo))){
Zuo=ZIo;}Zvo=(((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->ZC2);if((Zvo)==((void*)(Zo))){Zvo=ZJo;}Zzo=((T6)(1));ZGn(&(((C)->Zr1)),((C)->ZA1));
if(((((T7*)(ZCg))->Z21))==(ZE5(0))){if(!(ZKo(((C)->ZA1)))){Z2a(ZLo);Zzo=((T6)(0));}else{ZGn(&(((C)->Zr1)),((C)->ZA1));}}if(Zzo){ZLf(ZMo);
ZLf(((C)->ZG1));ZLf(ZNo);ZLf(Zto);ZLf(ZOo);ZLf(Zuo);ZLf(ZPo);ZLf(Zvo);ZLf(ZQo);Zdh((T38*)(ZSj()),Zto,(((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->ZZ1),(((ZF*)(((((ZD*)(((C)->ZK1)))->Zl1))[_i]))->Z_1));
ZH6((T7*)(Z8e),Zuo);ZH6((T7*)(Zae),Zvo);ZGn(&(((C)->Zr1)),((C)->Zz1));Zwo=ZRo;Ztf((T38*)(ZSj()));ZSo(C,Zwo);ZTo(C,Zwo);Zbi(&(((C)->Zr1)),((C)->Zz1));
if((Zo!=((((C)->Zr1)).ZY))){Zxo=ZSe((T38*)(ZSj()));Zci(&(((C)->Zr1)));while(!(Zt5(((T8)(((((C)->Zr1)).ZZ)))))){_s=ZUo;ZH6(((T7*)_s),ZCg);
if(Z07(((T7*)_s),Zxo)){Z9l(((C)->Zz1),_s);if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){ZH6(((T7*)_s),ZCg);{T0*b1=_s;Zo9(b1);}}}Zci(&(((C)->Zr1)));
}}ZDg(&(((C)->Zr1)));ZGn(&(((C)->Zr1)),((C)->ZA1));ZVo(C);Z0k(C);}ZEn(C);}void ZWo(T0*a1){T0*ZXo=Zo;T0*ZYo=Zo;((((T82*)((T82*)(Zaf))))->Zg1)=(a1);
ZLf(ZZo);ZLf(a1);{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}ZXo=Zn7(((T7*)a1));ZV6(((T7*)ZXo),Z_o);((((T82*)((T82*)(Zaf))))->Zg1)=(a1);ZYo=ZBe((T38*)(ZSj()),ZXo);
ZLf(ZYo);{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Z3a((T49*)(ZWj()),ZYo);}T0*Z0p=Zo;int Z1p=0;T0*ZVl(void){if(Z1p==0){Z1p=1;{{T42*n=((T42*)Zh(sizeof(*n)));
*n=M42;Z0p=((T0*)n);ZX7(n,(T2)(ZE5(1)),(T2)(ZE5(0)));}Z2p(ZPk,Z0p);Z_7(((T42*)Z0p),Z_h);}}return Z0p;}T0*Z4k=Zo;void ZSo(T12*C,T0*a1){
T0*Zai=Zo;T0*ZYo=Zo;T2 _i=0;T2 Zml=0;((((T82*)((T82*)(Zaf))))->Zg1)=(a1);Zai=Z3p;ZH6(((T7*)Zai),a1);ZV6(((T7*)Zai),Z4p);Zjg((T45*)(Zik()));
if(Zdi((T45*)(Zik()),Zai)){ZWo(a1);}else{_i=ZE5(1);while(!((Z3)((_i)>(Z6i((T45*)(Zik())))))){Zai=Zn7((T7*)((((((T47*)((((T45*)(Zik()))->Zg2))))->Zl1))[(_i)-(ZE5(1))]));
Zim(C,Zai);if(!(Z57(((T7*)Zai),a1))){}else if(!(Z07(((T7*)Zai),Z5p))){}else{Zml=(Z3)(((Zml))+(ZE5(1)));ZYo=ZYf((T38*)(ZSj()),Zai);ZLf(ZYo);
{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Z3a((T49*)(ZWj()),ZYo);}_i=(Z3)(((_i))+(ZE5(1)));}if((Z3)((Zml)>(ZE5(0)))){ZYo=ZBh((T38*)(ZSj()),a1,Zml);
ZLf(ZYo);{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Z3a((T49*)(ZWj()),ZYo);ZWh((T38*)(ZSj()),a1);}}}void ZVo(T12*C){T2 _i=0;T0*Z1k=Zo;T0*Zi1=Zo;
_i=ZE5(1);while(!((Z3)((_i)>(ZT7((T42*)(Z5k)))))){Zi1=ZU7((T42*)(Z5k),_i);if(Z38((T42*)(Z4k),Zi1)){Z1k=Z2k(C,Z6p);ZLk(Z1k,Zi1);ZWo(Zi1);
}else{Z1k=Z2k(C,Zo);ZLk(Z1k,Zi1);ZSo(C,Zi1);}_i=(Z3)(((_i))+(ZE5(1)));}_i=ZE5(1);while(!((Z3)((_i)>(ZT7((T42*)(Z5k)))))){Zi1=ZU7((T42*)(Z5k),_i);
Zxn(Zi1);_i=(Z3)(((_i))+(ZE5(1)));}}void Z2l(T12*C,T2 a1){T6 _ok=0;T2 Zai=0;T0*Z7p=Zo;T0*Z8p=Zo;while(!(_ok)){ZXj(Z9p);if(((((T7*)(Z_j))->Z21))==(ZE5(0))){
_ok=((T6)(1));}else{if(Z17((T7*)(Z_j))){Zai=Zc7((T7*)(Z_j));if((T6)(((Z3)((Zai)>=(ZE5(1))))&&((T6)((Z3)((Zai)<=(a1)))))){_ok=((T6)(1));
Z7p=((((T47*)(((C)->ZM1)))->Zl1))[(Z3)(((Zai))-(ZE5(1)))];Z8p=((((T47*)(((C)->ZN1)))->Zl1))[(Z3)(((Zai))-(ZE5(1)))];ZI7((T47*)(((C)->ZM1)),(Z3)(((Zai))-((T2)(ZE5(1)))));
ZI7((T47*)(((C)->ZN1)),(Z3)(((Zai))-((T2)(ZE5(1)))));((((T7*)(((T7*)Z7p))))->Z21)=(ZE5(0));((((T7*)(((T7*)Z8p))))->Z21)=(ZE5(0));ZL7((T47*)(((C)->ZM1)),Z7p);
ZL7((T47*)(((C)->ZN1)),Z8p);}}if(!(_ok)){ZLf(Zap);Z2j((T11)(a1));ZLf(Zbp);}}}}void ZFn(T12*C,T2 a1){if((T6)(((((C)->ZJ1))==((void*)(Zo)))||((T6)(Zf7(((T7*)Zcp),((C)->ZJ1)))))){
ZLf(Zdp);ZNd((T37*)(Z1j));}Zv(a1);}T0*Zlm(T0*a1){T0*R=Zo;if((a1)!=((void*)(Zo))){if((Zep(ZMl,a1))==(ZE5(1))){R=Zfp(ZMl,a1);}else if((Zep(ZPk,a1))==(ZE5(1))){
R=Zfp(ZPk,a1);}}return R;}T0*Zgp=Zo;int Zhp=0;T0*Zik(void){if(Zhp==0){Zhp=1;{{T45*n=((T45*)Zh(sizeof(*n)));*n=M45;Zgp=((T0*)n);ZSf(n);
}}}return Zgp;}T6 Zfk(T12*C){T6 R=0;T2 Zip=0;T0*Zjp=Zo;T0*Zck=Zo;T6 Zkp=0;T0*Zak=Zo;T0*Zbk=Zo;Zjp=ZNj;if((((C)->ZK1))==((void*)(Zo))){
R=((T6)(1));{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Zn1;Zy7(n,(T2)(ZE5(8)));(C->ZK1)=((T0*)n);}}if((((C)->ZL1))==((void*)(Zo))){{ZD*n=((ZD*)Zh(sizeof(*n)));
*n=Zn1;Zy7(n,(T2)(ZE5(8)));(C->ZL1)=((T0*)n);}}if((((C)->ZD1))!=((void*)(Zo))){Zak=Zek(((C)->ZD1));}Zip=ZE5(1);Zkp=((T6)(1));while(!((Z3)((Zip)>(ZE5(8)))))
{ZH6((T7*)(ZNj),(((void)((T81*)(ZHn()))),Znj(Zip)));if((Zip)!=(ZE5(1))){ZV6((T7*)(ZNj),Zlp);}if(!(ZYm(C,ZNj))){if((Z3)(((((ZD*)(((C)->ZL1)))->Zm1))<(ZE5(0)))){
if((((C)->ZD1))==((void*)(Zo))){{ZF*n=((ZF*)Zh(sizeof(*n)));*n=ZT2;Zqi(n,ZNj,Zo,Zpg,Zo,Zpg);Zck=((T0*)n);}}else{{ZF*n=((ZF*)Zh(sizeof(*n)));
*n=ZT2;Zqi(n,ZNj,Zak,((C)->ZD1),Zbk,((C)->ZE1));Zck=((T0*)n);}}}else{Zck=((((ZD*)(((C)->ZL1)))->Zl1))[ZE5(0)];Zv7((ZD*)(((C)->ZL1)));
if((((C)->ZD1))==((void*)(Zo))){Zxi(((ZF*)Zck),ZNj,Zo,Zpg,Zo,Zo);}else{Zxi(((ZF*)Zck),ZNj,Zak,((C)->ZD1),Zbk,((C)->ZE1));}}if(!(((((ZF*)Zck))->ZH2))){
Zkp=((T6)(0));if((Zip)==(ZE5(8))){Zvi(((ZF*)Zck),Zmp);}}Zx7((ZD*)(((C)->ZK1)),Zck);R=((T6)(1));}Zip=(Z3)(((Zip))+(ZE5(1)));}if(Zkp){(C->Zu1)=ZE5(3);
}return R;}void ZRm(T12*C){(C->ZP1)=ZE5(1);Z8n(C,Znp);Z8n(C,Zop);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);
}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));}void Zpp(T0*a1,T0*a2){if((a2)!=((void*)(Zo))){ZKh((ZL*)(Zhl),a1);ZKh((ZL*)(Zhl),Zqp);ZKh((ZL*)(Zhl),a2);
ZMh((ZL*)(Zhl),((T3)'\n'));}}void Zsm(T12*C){T2 _i=0;T0*Zck=Zo;if(Zp9(((C)->Zv1))){ZH6((T7*)(ZNj),((C)->Zv1));ZQ5((T7*)(ZNj),((T3)'\176'));
ZLf(Zrp);ZLf(((C)->Zv1));ZLf(Zsp);ZLf(ZNj);{T3 b1=((T3)'\n');Zh9((T31*)(Zi9),b1);}Zt9(((C)->Zv1),ZNj);}ZAn(C);if(!(((((ZL*)(Zhl))->ZS1))!=(Zo))){
ZLf(Ztp);(C->Zu1)=ZE5(1);}else{ZKh((ZL*)(Zhl),Zup);ZKh((ZL*)(Zhl),Zvp);ZKh((ZL*)(Zhl),Zwp);ZKh((ZL*)(Zhl),Zxp);ZKh((ZL*)(Zhl),((C)->Zw1));
ZMh((ZL*)(Zhl),((T3)'\n'));ZKh((ZL*)(Zhl),Zyp);ZKh((ZL*)(Zhl),((C)->Zx1));ZMh((ZL*)(Zhl),((T3)'\n'));ZKh((ZL*)(Zhl),Zzp);ZKh((ZL*)(Zhl),((C)->Zy1));
ZMh((ZL*)(Zhl),((T3)'\n'));ZKh((ZL*)(Zhl),ZAp);ZKh((ZL*)(Zhl),((C)->ZJ1));ZMh((ZL*)(Zhl),((T3)'\n'));ZKh((ZL*)(Zhl),ZBp);ZKh((ZL*)(Zhl),ZSn);
ZMh((ZL*)(Zhl),((T3)'\n'));if((((C)->ZM1))!=((void*)(Zo))){ZMh((ZL*)(Zhl),((T3)'\n'));ZKh((ZL*)(Zhl),ZCp);ZKh((ZL*)(Zhl),ZDp);_i=ZE5(0);
while(!((T6)(((Z3)((_i)>((((T47*)(((C)->ZM1)))->Zm1))))||((T6)(((((T7*)(((((T47*)(((C)->ZM1)))->Zl1))[_i]))->Z21))==(ZE5(0))))))){ZKh((ZL*)(Zhl),((((T47*)(((C)->ZM1)))->Zl1))[_i]);
ZKh((ZL*)(Zhl),ZEp);ZKh((ZL*)(Zhl),((((T47*)(((C)->ZN1)))->Zl1))[_i]);ZMh((ZL*)(Zhl),((T3)'\n'));_i=(Z3)(((_i))+(ZE5(1)));}}ZKh((ZL*)(Zhl),ZFp);
_i=ZE5(0);while(!((Z3)((_i)>((((ZD*)(((C)->ZK1)))->Zm1))))){Zck=((((ZD*)(((C)->ZK1)))->Zl1))[_i];ZMh((ZL*)(Zhl),((T3)'\n'));ZMh((ZL*)(Zhl),((T3)'\133'));
ZKh((ZL*)(Zhl),((((ZF*)Zck))->Zz2));ZKh((ZL*)(Zhl),ZGp);Zpp(ZGi,((((ZF*)Zck))->ZA2));Zpp(ZHi,((((ZF*)Zck))->ZZ1));Zpp(ZIi,((((ZF*)Zck))->ZB2));
Zpp(ZJi,((((ZF*)Zck))->Z_1));Zpp(ZKi,((((ZF*)Zck))->ZC2));Zpp(ZMi,((((ZF*)Zck))->ZD2));Zpp(ZNi,((((ZF*)Zck))->Z12));Zpp(ZOi,((((ZF*)Zck))->ZE2));
Zpp(ZPi,((((ZF*)Zck))->Z22));Zpp(ZQi,((((ZF*)Zck))->ZF2));Zpp(ZLi,((((ZF*)Zck))->ZG2));_i=(Z3)(((_i))+(ZE5(1)));}ZNh((ZL*)(Zhl));}}void
Zpm(T12*C){T6 ZUk=0;T6 ZVk=0;T2 Zai=0;int ZHp=0;(C->ZO1)=((T6)(0));ZVk=((T6)(1));while(!(ZUk)){ZLf(ZIp);{T0*b1=ZJp;T0*b2=((C)->Zv1);Zol(b1,b2,Zo);
}{T0*b1=ZKp;T0*b2=((C)->ZJ1);Zol(b1,b2,Zo);}{T0*b1=ZLp;T0*b2=((C)->Zw1);Zol(b1,b2,Zo);}{T0*b1=ZMp;T0*b2=((C)->Zx1);Zol(b1,b2,Zo);}{T0*b1=ZNp;
T0*b2=((C)->Zy1);Zol(b1,b2,Zo);}ZLf(ZOp);if(ZVk){ZLf(ZPp);}else{ZLf(ZQp);}((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);
}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));if(((((T7*)(Z_j))->Z21))==(ZE5(0))){if(ZVk){ZN5(ZE5(2),Z_j);}else{ZN5(ZE5(7),Z_j);}}if(Zp7((T7*)(Z_j))){
Zai=Zc7((T7*)(Z_j));if((T6)(((Z3)((Zai)<(ZE5(1))))||((T6)((Z3)((Zai)>(ZE5(7))))))){ZLf(ZRp);}else{{int z1=Zai;switch(z1){case 1:ZXj(ZSp);
if(!(((((T7*)(Z_j))->Z21))==(ZE5(0)))){ZH6((T7*)(ZOj),Z_j);if((((C)->Zv1))==((void*)(Zpg))){ZLf(ZTp);ZLf(ZOj);}(C->Zv1)=ZOj;{T0*b1=ZUp;
T0*b2=((C)->Zv1);Zm5(Zl7(((T7*)b1)),Zl7(((T7*)b2)));}}break;case 2:ZBm(C,Zlo(ZVp,(((void)((T38*)(ZSj()))),Zke()),((C)->ZJ1)));break;case
3:ZZm(ZWp,((C)->Zw1),((C)->ZA1),(T6)(1));((((T38*)((T38*)(ZSj()))))->Zw1)=(((C)->ZA1));break;case 4:ZZm(ZXp,((C)->Zx1),((C)->ZB1),(T6)(0));
((((T38*)((T38*)(ZSj()))))->Zx1)=(((C)->ZB1));break;case 5:ZZm(ZYp,((C)->Zy1),((C)->ZC1),(T6)(0));((((T38*)((T38*)(ZSj()))))->Zy1)=(((C)->ZC1));
break;case 6:ZTk(C);break;default:;ZUk=((T6)(1));}}ZVk=((T6)(0));}}else{ZLf(ZZp);}}}void ZTo(T12*C,T0*a1){T0*Z_p=Zo;T0*Z0q=Zo;T0*Z1q=Zo;
Z_p=ZNj;ZH6(((T7*)Z_p),a1);Zdf((T38*)(ZSj()),Z_p);Z9l(((C)->Zz1),Z_p);Z0q=Z2q;ZH6(((T7*)Z0q),ZCg);Z9l(((C)->ZA1),Z_p);Z1q=Z3q;ZH6(((T7*)Z1q),ZCg);
if(!(Zok(Z0q))){Z2a(Zjk);Z2a(Z4q);Z2a(Z0q);Z2a(Z5q);Zkk(C);}if(!(Zf7((T7*)(Zve),((C)->ZJ1)))){Zq9((T49*)(ZWj()),Z0q,Z1q);}else{ZH6((T7*)(ZTj),Z6q);
ZV6((T7*)(ZTj),Z0q);ZQ5((T7*)(ZTj),((T3)'\040'));ZV6((T7*)(ZTj),Z1q);Z3a((T49*)(ZWj()),ZTj);}}void Zol(T0*a1,T0*a2,T0*a3){ZLf(a1);ZLf(Z7q);
if((T6)(((a2)==((void*)(Zo)))||((T6)((((((T7*)a2))->Z21))==(ZE5(0)))))){if((a3)==((void*)(Zo))){ZLf(Z8q);}else{ZLf(Z9q);ZLf(a3);}}else{
ZLf(a2);}ZLf(Zaq);}T0*Zbq=Zo;int Zcq=0;T0*ZHl(void){if(Zcq==0){Zcq=1;{{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;Zbq=((T0*)n);ZX7(n,(T2)(ZE5(1)),(T2)(ZE5(0)));
}Z2p(ZMl,Zbq);}}return Zbq;}T0*Zlo(T0*a1,T0*a2,T0*a3){T0*R=Zo;T2 _i=0;T6 Zdq=0;T0*_w=Zo;T0*_n=Zo;while(!((R)!=((void*)(Zo)))){ZLf(a1);
ZLf(Zeq);_i=ZE5(1);while(!((Z3)((_i)>(((((T42*)a2))->Zm1))))){_n=ZP8(a2,_i);if((_n)==((void*)(a3))){{T3 b1=((T3)'\074');Zh9((T31*)(Zi9),b1);
}ZLf(_n);{T3 b1=((T3)'\076');Zh9((T31*)(Zi9),b1);}}else{ZLf(_n);}_i=(Z3)(((_i))+(ZE5(1)));if((Z3)((_i)<=(((((T42*)a2))->Zm1)))){ZLf(Zfq);
}}ZLf(Zgq);((((T7*)((T7*)(Z_j))))->Z21)=(ZE5(0));{T0*b1=Z_j;ZRd((T37*)(Z1j),b1);}Zs7((T7*)(Z_j));Zk7((T7*)(Z_j));if(((((T7*)(Z_j))->Z21))==(ZE5(0))){
R=a3;}else{_n=Zhq;Zdq=((T6)(0));_i=ZQ8(a2);_w=Z_j;Zm7(((T7*)_w));while(!((Z3)((_i)>(((((T42*)a2))->Zm1))))){ZH6(((T7*)_n),ZP8(a2,_i));
Zm7(((T7*)_n));if(Zf7(((T7*)_w),_n)){R=ZP8(a2,_i);_i=((((T42*)a2))->Zm1);}else if(Z57(((T7*)_n),_w)){if((R)!=((void*)(Zo))){R=Zo;Zdq=((T6)(1));
}else{R=ZP8(a2,_i);}}_i=(Z3)(((_i))+(ZE5(1)));}if((R)==((void*)(Zo))){ZLf(Ziq);ZLf(_w);if(Zdq){ZLf(ZV9(16,"\" is ambiguous.\n"));}else{
ZLf(Zjq);}}}}return R;}T0*Z2k(T12*C,T0*a1){T0*R=Zo;R=Zkq;if(Zf7((T7*)(ZNe),((C)->ZF1))){ZH6(((T7*)R),Zlq);}else{ZH6(((T7*)R),Zmq);}if(!(Za6((T7*)(((C)->ZG1)),Zpj))){
ZV6(((T7*)R),Znq);ZV6(((T7*)R),((C)->ZG1));}if((a1)!=((void*)(Zo))){ZQ5(((T7*)R),((T3)'\040'));ZV6(((T7*)R),a1);}return R;}void Z6a(T0*a1){
if((Zoq(a1))==(ZE5(0))){}}T2 Zoq(T0*a1){T2 R=0;T8 _p=Zo;_p=Zl7(((T7*)a1));R=Zpq(_p);return R;}T0*ZR9(T0*a1){T0*R=Zo;T8 _p=Zo;T8 Zqq=Zo;
_p=Zl7(((T7*)a1));_p=Zrq(_p);if((_p)!=(Zqq)){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zj7(n,_p);R=((T0*)n);}}return R;}T0*Zsq(T92*C){T0*R=Zo;
if((((*C).ZW))==((void*)(Zo))){(C->ZW)=(((void)((T89*)(Ztq()))),ZCa(Zuq));}R=((*C).ZW);return R;}T0*Ztq(void){if(ZJa==0){ZJa=1;{{T89*n=((T89*)Zh(1));
ZIa=((T0*)n);ZKa(ZLa);ZKa(ZMa);ZKa(ZNa);ZKa(ZOa);ZKa(Zna);ZKa(ZPa);ZKa(Zka);ZKa(ZQa);ZKa(ZRa);ZKa(Zma);ZKa(ZSa);ZKa(ZTa);ZKa(ZUa);ZKa(ZVa);
ZKa(ZWa);ZKa(ZXa);ZKa(Zha);ZKa(Zra);ZKa(Zja);ZKa(Zia);ZKa(Zsa);ZKa(ZYa);ZKa(ZZa);ZKa(Z_a);ZKa(Zga);ZKa(Z0b);ZKa(Zpa);ZKa(Z1b);ZKa(Z2b);
ZKa(Z3b);ZKa(Z4b);ZKa(Z5b);ZKa(Zla);ZKa(Z6b);ZKa(Z7b);ZKa(Z8b);ZKa(Zoa);ZKa(Z9b);ZKa(Zab);ZKa(Zbb);ZKa(Zcb);ZKa(Zdb);ZKa(Zeb);ZKa(Zfb);
ZKa(Zgb);ZKa(Zhb);ZKa(Zib);ZKa(Zjb);ZKa(Zkb);ZKa(Zlb);ZKa(Zmb);ZKa(Znb);ZKa(Zob);ZKa(Zpb);ZKa(Zqb);ZKa(Zrb);ZKa(Zsb);ZKa(Ztb);ZKa(Zub);
ZKa(Zvb);ZKa(Zwb);ZKa(Zxb);ZKa(Zyb);ZKa(Zzb);ZKa(ZAb);ZKa(ZBb);ZKa(ZCb);ZKa(ZDb);ZKa(ZEb);ZKa(ZFb);ZKa(ZGb);ZKa(ZHb);ZKa(ZIb);ZKa(ZJb);
ZKa(ZKb);ZKa(ZLb);ZKa(ZMb);ZKa(ZNb);ZKa(ZOb);ZKa(ZPb);ZKa(ZQb);ZKa(ZRb);ZKa(ZSb);ZKa(ZTb);ZKa(ZUb);ZKa(ZVb);ZKa(ZWb);ZKa(ZXb);ZKa(ZYb);
ZKa(ZZb);ZKa(Z_b);ZKa(Z0c);ZKa(Z1c);ZKa(Z2c);ZKa(Z3c);ZKa(Z4c);ZKa(Z5c);ZKa(Z6c);ZKa(Z7c);ZKa(Z8c);ZKa(Z9c);ZKa(Zac);ZKa(Zbc);ZKa(Zcc);
ZKa(Zdc);ZKa(Zec);ZKa(Zfc);ZKa(Zgc);ZKa(Zhc);ZKa(Zic);ZKa(Zjc);ZKa(Zkc);ZKa(Zlc);ZKa(Zmc);ZKa(Znc);ZKa(Zoc);ZKa(Zpc);ZKa(Zqc);ZKa(Zrc);
ZKa(Zsc);ZKa(Ztc);ZKa(Zuc);ZKa(Zvc);ZKa(Zwc);ZKa(Zxc);ZKa(Zyc);ZKa(Zzc);ZKa(ZAc);ZKa(ZBc);ZKa(ZCc);ZKa(ZDc);ZKa(ZEc);ZKa(ZFc);ZKa(ZGc);
ZKa(ZHc);ZKa(ZIc);ZKa(ZJc);ZKa(ZKc);ZKa(ZLc);ZKa(ZMc);ZKa(ZNc);ZKa(ZOc);ZKa(ZPc);ZKa(ZQc);ZKa(ZRc);ZKa(ZSc);ZKa(ZTc);ZKa(ZUc);ZKa(ZVc);
ZKa(ZWc);ZKa(ZXc);ZKa(ZYc);ZKa(ZZc);ZKa(Z_c);ZKa(Z0d);ZKa(Z1d);ZKa(Z2d);ZKa(Z3d);ZKa(Z4d);ZKa(Z5d);ZKa(Z6d);ZKa(Z7d);ZKa(Z8d);ZKa(Z9d);
ZKa(Zad);ZKa(Zbd);ZKa(Zcd);ZKa(Zdd);ZKa(Zed);ZKa(Zfd);ZKa(Zgd);ZKa(Zhd);ZKa(Zid);ZKa(Zjd);ZKa(Zkd);ZKa(Zld);ZKa(Zmd);ZKa(Znd);ZKa(Zod);
ZKa(Zpd);ZKa(Zqd);ZKa(Zrd);ZKa(Zsd);ZKa(Ztd);ZKa(Zud);ZKa(Zvd);ZKa(Zwd);ZKa(Zxd);ZKa(Zyd);ZKa(Zzd);ZKa(ZAd);ZKa(Zqa);ZKa(ZBd);ZKa(ZCd);
ZKa(ZDd);ZKa(ZEd);ZKa(ZFd);ZKa(ZGd);ZKa(ZHd);ZKa(ZId);ZKa(ZJd);ZKa(ZKd);ZKa(ZLd);}}}return ZIa;}void Zvq(T92*C,T74 a1){(C->ZV)=a1;((((T7*)((T7*)(Zuq))))->Z21)=(ZE5(0));
(C->ZW)=Zo;}T0*Zwq(T92*C){T0*R=Zo;if((((*C).ZW))==((void*)(Zo))){(C->ZW)=(((void)((T89*)(Ztq()))),ZCa(Zuq));}R=((*C).ZW);return R;}T6
ZJf(void){T6 R=0;R=((T6)(((((((T7*)Zih))->Zl1))[ZE5(0)])==(((T3)'A'))));return R;}void ZBg(T0*a1){{int z1=(((((T7*)a1))->Zl1))[ZE5(0)];
switch(z1){case 46:case 47:case 126:((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'U'));if((Z3)((((((T7*)a1))->Z21))>=(ZE5(4)))){
if(((((((T7*)a1))->Zl1))[(ZE5(2))-(ZE5(1))])==(((T3)'\057'))){if(((((((T7*)a1))->Zl1))[(ZE5(4))-(ZE5(1))])==(((T3)'\057'))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'C'));
}}}break;case 92:((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'W'));break;case 58:((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'M'));
break;case 91:((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'V'));break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:
case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:
case 89:case 90:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case
110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:if((Z3)((((((T7*)a1))->Z21))>=(ZE5(2)))){
{int z2=(((((T7*)a1))->Zl1))[(ZE5(2))-(ZE5(1))];switch(z2){case 58:if((((((T7*)a1))->Z21))==(ZE5(2))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'W'));
}else if(Za7(((T7*)a1),((T3)'\134'))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'W'));}else if(Za7(((T7*)a1),((T3)'\077'))){
((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'A'));}else if(Za7(((T7*)a1),((T3)'\057'))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'C'));
}break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:
case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 97:case 98:case 99:case 100:case 101:case 102:case
103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case
118:case 119:case 120:case 121:case 122:if(Za7(((T7*)a1),((T3)'\133'))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'V'));}else
if(Za7(((T7*)a1),((T3)'\072'))){if(Za7(((T7*)a1),((T3)'\057'))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'A'));}else if(Za7(((T7*)a1),((T3)'\133'))){
((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'V'));}else{((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'A'));}}else if(Za7(((T7*)a1),((T3)'\057'))){
((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'U'));}else if(Za7(((T7*)a1),((T3)'\134'))){((((T7*)(Zih))->Zl1))[((T2)(ZE5(1)))-(ZE5(1))]=(((T3)'U'));
}break;}}}break;}}}void Z9i(T48*C,T0*a1){T8 _p=Zo;Zbi(C,a1);if((Zo!=((*C).ZY))){ZH6((T7*)(ZCg),a1);}else{ZQg(a1);if((Z3)(((((T7*)(ZCg))->Z21))>(ZE5(0)))){
_p=Zl7((T7*)(ZCg));(C->ZY)=ZY3(_p);(C->ZZ)=((*C).ZY);if(Zt5(((*C).ZY))){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));
}}}void ZAg(T48*C){T8 ZS1=Zo;ZS1=Zxq;if((Zo!=ZS1)){Zj7((T7*)(ZCg),ZS1);(C->ZY)=ZY3(ZS1);(C->ZZ)=((*C).ZY);if(Zt5(((*C).ZY))){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));
}}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}}void ZDg(T48*C){T8 Zqq=Zo;if(Z54(((*C).ZY))){(C->ZY)=Zqq;(C->ZZ)=Zqq;}}void ZNg(T0*a1,T0*a2){
ZH6((T7*)(ZCg),a1);if((T6)((ZFf())||((T6)(ZGf())))){if(Za6(((T7*)Zyq),a2)){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else if(Za6(((T7*)Zzq),a2)){
((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else{Ze7((T7*)(ZCg),((T3)'\057'));if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\057'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));
}ZV6((T7*)(ZCg),a2);Ze7((T7*)(ZCg),((T3)'\057'));}}else if(ZHf()){if(Za6(((T7*)ZAq),a2)){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else if(Za6(((T7*)ZBq),a2)){
((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else{Ze7((T7*)(ZCg),((T3)'\134'));if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\134'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));
}ZV6((T7*)(ZCg),a2);Ze7((T7*)(ZCg),((T3)'\134'));}}else if(ZJf()){{int z1=ZK6((T7*)(ZCg));switch(z1){case 47:if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\057'))){
Z97((T7*)(ZCg),(T2)(ZE5(1)));}break;case 58:break;default:;if(((((((T7*)a2))->Zl1))[ZE5(0)])!=(((T3)'\057'))){Zg7((T7*)(ZCg),((T3)'\057'));
}}}ZV6((T7*)(ZCg),a2);Ze7((T7*)(ZCg),((T3)'\057'));}else if(ZIf()){Ze7((T7*)(ZCg),((T3)'\072'));if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\072'))){
Z97((T7*)(ZCg),(T2)(ZE5(1)));}ZV6((T7*)(ZCg),a2);Ze7((T7*)(ZCg),((T3)'\072'));}else if(ZKf()){if(((((T7*)(ZCg))->Z21))==(ZE5(1))){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));
}else if((ZK6((T7*)(ZCg)))==(((T3)'\135'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));if((ZK6((T7*)(ZCg)))==(((T3)'\133'))){ZV6((T7*)(ZCg),a2);ZQ5((T7*)(ZCg),((T3)'\135'));
}else{ZQ5((T7*)(ZCg),((T3)'\056'));ZV6((T7*)(ZCg),a2);ZQ5((T7*)(ZCg),((T3)'\135'));}}else if((ZK6((T7*)(ZCg)))==(((T3)'\072'))){ZQ5((T7*)(ZCg),((T3)'\133'));
ZV6((T7*)(ZCg),a2);ZQ5((T7*)(ZCg),((T3)'\135'));}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}}else if(ZEf()){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));
}else{ZBg(a1);if(ZEf()){ZNg(a1,a2);}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}}}T6 ZEf(void){T6 R=0;R=((T6)(((((((T7*)Zih))->Zl1))[ZE5(0)])!=(((T3)'\077'))));
return R;}T6 Zfi(void){T6 R=0;T48 _bd={Zo,Zo};{int z1=(((((T7*)Zih))->Zl1))[ZE5(0)];switch(z1){case 63:ZAg(&_bd);if((Zo!=((_bd).ZY))){
if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){ZBg(ZCg);}ZDg(&_bd);if(((((((T7*)Zih))->Zl1))[ZE5(0)])!=(((T3)'\077'))){R=((T6)(Zfi()));}}break;
case 86:case 87:break;default:;R=((T6)(1));}}return R;}T6 ZHf(void){T6 R=0;R=((T6)(((((((T7*)Zih))->Zl1))[ZE5(0)])==(((T3)'W'))));return
R;}T6 ZFf(void){T6 R=0;R=((T6)(((((((T7*)Zih))->Zl1))[ZE5(0)])==(((T3)'U'))));return R;}T0*ZCg=Zo;T6 ZIf(void){T6 R=0;R=((T6)(((((((T7*)Zih))->Zl1))[ZE5(0)])==(((T3)'M'))));
return R;}void ZGn(T48*C,T0*a1){T8 _p=Zo;_p=Zl7(((T7*)a1));if(Z74(_p)){ZAg(C);if((Zo!=((*C).ZY))){ZDg(C);}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));
}}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}}void ZQg(T0*a1){ZH6((T7*)(ZCg),a1);if(ZFf()){Z97((T7*)(ZCg),(T2)(ZE5(1)));while(!((T6)((((((T7*)(ZCg))->Z21))==(ZE5(0)))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\057')))))))
{Z97((T7*)(ZCg),(T2)(ZE5(1)));}if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){Ze7((T7*)(ZCg),((T3)'\057'));}}else if(ZHf()){Z97((T7*)(ZCg),(T2)(ZE5(1)));
while(!((T6)((((((T7*)(ZCg))->Z21))==(ZE5(0)))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\134'))))))){Z97((T7*)(ZCg),(T2)(ZE5(1)));}if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){
Ze7((T7*)(ZCg),((T3)'\134'));}}else if(ZGf()){Z97((T7*)(ZCg),(T2)(ZE5(1)));while(!((T6)(((T6)((((((T7*)(ZCg))->Z21))==(ZE5(0)))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\057'))))))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\072')))))))
{Z97((T7*)(ZCg),(T2)(ZE5(1)));}if(((((T7*)(ZCg))->Z21))==(ZE5(0))){}else if((((((T7*)(ZCg))->Zl1))[ZE5(0)])==(((T3)'\057'))){if(((((T7*)(ZCg))->Z21))==(ZE5(2))){
if((((((T7*)(ZCg))->Zl1))[(ZE5(2))-(ZE5(1))])==(((T3)'\057'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));}}}if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){
Ze7((T7*)(ZCg),((T3)'\057'));}}else if(ZJf()){if((ZK6((T7*)(ZCg)))==(((T3)'\072'))){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else{Z97((T7*)(ZCg),(T2)(ZE5(1)));
while(!((T6)(((T6)((((((T7*)(ZCg))->Z21))==(ZE5(0)))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\057'))))))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\072')))))))
{Z97((T7*)(ZCg),(T2)(ZE5(1)));}}if((T6)((!(((((T7*)(ZCg))->Z21))==(ZE5(0))))&&((T6)((T6)(((ZK6((T7*)(ZCg)))!=(((T3)'\057')))&&((T6)((ZK6((T7*)(ZCg)))!=(((T3)'\072'))))))))){
ZQ5((T7*)(ZCg),((T3)'\057'));}}else if(ZIf()){Z97((T7*)(ZCg),(T2)(ZE5(1)));while(!((T6)((((((T7*)(ZCg))->Z21))==(ZE5(0)))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\072')))))))
{Z97((T7*)(ZCg),(T2)(ZE5(1)));}if(!(((((T7*)(ZCg))->Z21))==(ZE5(0)))){Ze7((T7*)(ZCg),((T3)'\072'));}}else if(ZKf()){if((ZK6((T7*)(ZCg)))==(((T3)'\135'))){
Z97((T7*)(ZCg),(T2)(ZE5(1)));while(!((T6)(((T6)((((((T7*)(ZCg))->Z21))==(ZE5(0)))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\056'))))))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\133')))))))
{Z97((T7*)(ZCg),(T2)(ZE5(1)));}if((Z3)(((((T7*)(ZCg))->Z21))>(ZE5(0)))){{int z1=ZK6((T7*)(ZCg));switch(z1){case 46:Z97((T7*)(ZCg),(T2)(ZE5(1)));
ZQ5((T7*)(ZCg),((T3)'\135'));break;default:;if(((((T7*)(ZCg))->Z21))==((Z3)(((((((T7*)a1))->Z21)))-(ZE5(1))))){Z97((T7*)(ZCg),(T2)(ZE5(1)));
}else{ZQ5((T7*)(ZCg),((T3)'\135'));}}}}}else if((ZK6((T7*)(ZCg)))==(((T3)'\072'))){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else{Z97((T7*)(ZCg),(T2)(ZE5(1)));
while(!((T6)((((((T7*)(ZCg))->Z21))==(ZE5(0)))||((T6)((ZK6((T7*)(ZCg)))==(((T3)'\135'))))))){Z97((T7*)(ZCg),(T2)(ZE5(1)));}if(((((T7*)(ZCg))->Z21))==(ZE5(0))){
((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}}}else if(ZEf()){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else{ZBg(a1);if(ZEf()){ZQg(a1);}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));
}}}void Zci(T48*C){T8 Zz2=Zo;(C->ZZ)=Z04(((*C).ZY));if((Zo!=((*C).ZZ))){Zz2=Z24(((*C).ZZ));Zj7((T7*)(ZCg),Zz2);}}void Zbi(T48*C,T0*a1){
T8 ZCq=Zo;ZCq=Zl7(((T7*)a1));(C->ZY)=ZY3(ZCq);(C->ZZ)=((*C).ZY);((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}T6 ZKo(T0*a1){T6 R=0;T8 _p=Zo;
_p=Zl7(((T7*)a1));R=((T6)(Z94(_p)));return R;}void Z9l(T0*a1,T0*a2){ZH6((T7*)(ZCg),a1);if((T6)((ZFf())||((T6)(ZGf())))){Ze7((T7*)(ZCg),((T3)'\057'));
if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\057'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));}ZV6((T7*)(ZCg),a2);}else if(ZHf()){Ze7((T7*)(ZCg),((T3)'\134'));
if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\134'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));}ZV6((T7*)(ZCg),a2);}else if(ZJf()){{int z1=ZK6((T7*)(ZCg));
switch(z1){case 58:break;case 47:if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\057'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));}break;default:;if(((((((T7*)a2))->Zl1))[ZE5(0)])!=(((T3)'\057'))){
ZQ5((T7*)(ZCg),((T3)'\057'));}}}ZV6((T7*)(ZCg),a2);}else if(ZIf()){Ze7((T7*)(ZCg),((T3)'\072'));if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\072'))){
Z97((T7*)(ZCg),(T2)(ZE5(1)));}ZV6((T7*)(ZCg),a2);}else if(ZKf()){{int z1=ZK6((T7*)(ZCg));switch(z1){case 93:break;case 46:Z97((T7*)(ZCg),(T2)(ZE5(1)));
ZQ5((T7*)(ZCg),((T3)'\135'));break;default:;ZQ5((T7*)(ZCg),((T3)'\135'));}}if(((((((T7*)a2))->Zl1))[ZE5(0)])==(((T3)'\135'))){Z97((T7*)(ZCg),(T2)(ZE5(1)));
}ZV6((T7*)(ZCg),a2);}else if(ZEf()){((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));}else{ZBg(a1);if(ZEf()){Z9l(a1,a2);}else{((((T7*)((T7*)(ZCg))))->Z21)=(ZE5(0));
}}}T6 ZKf(void){T6 R=0;R=((T6)(((((((T7*)Zih))->Zl1))[ZE5(0)])==(((T3)'V'))));return R;}T6 ZGf(void){T6 R=0;R=((T6)(((((((T7*)Zih))->Zl1))[ZE5(0)])==(((T3)'C'))));
return R;}T6 ZHj(T0*a1){T6 R=0;if((Zga)==((void*)(a1))){R=((T6)(1));}else if((Zbb)==((void*)(a1))){R=((T6)(1));}else if((Z8b)==((void*)(a1))){
R=((T6)(1));}else if((Z3b)==((void*)(a1))){R=((T6)(1));}else if((ZVa)==((void*)(a1))){R=((T6)(1));}else if((Z2b)==((void*)(a1))){R=((T6)(1));
}return R;}T6 ZDq(void){T6 R=0;T6 Zt1=0;if((T6)((ZEq((T36*)(ZFq)))||((T6)(!(Zw5(ZGq((T36*)(ZFq)))))))){((((T36*)((T36*)(ZFq))))->ZW2)=(ZHq);
}else{R=((T6)(1));ZIq((T36*)(ZFq));while(!(Zt1)){if(ZEq((T36*)(ZFq))){Zt1=((T6)(1));}else if(Zw5(ZGq((T36*)(ZFq)))){ZIq((T36*)(ZFq));
}else{Zt1=((T6)(1));}}ZJq((T36*)(ZFq));}return R;}T0*ZFq=Zo;T6 ZKq(int C){T6 R=0;R=((T6)((T6)((ZLq(C))&&((T6)(ZMq(C))))));return R;}T6
ZLq(int C){T6 R=0;R=((T6)((T6)((ZNq(C))&&((T6)(ZOq(C))))));return R;}T6 ZNq(int C){T6 R=0;R=((T6)(ZPq(C)));if(!(ZEq((T36*)(ZFq)))){if((ZGq((T36*)(ZFq)))==(((T3)'\041'))){
ZIq((T36*)(ZFq));ZJq((T36*)(ZFq));}}return R;}T6 ZPq(int C){T6 R=0;if(ZEq((T36*)(ZFq))){((((T36*)((T36*)(ZFq))))->ZW2)=(ZHq);}else{{int
z1=ZGq((T36*)(ZFq));switch(z1){case 43:case 45:ZIq((T36*)(ZFq));ZJq((T36*)(ZFq));R=((T6)(ZPq(C)));break;case 40:ZIq((T36*)(ZFq));ZJq((T36*)(ZFq));
R=((T6)(ZKq(C)));if(R){if((T6)((ZEq((T36*)(ZFq)))||((T6)((ZGq((T36*)(ZFq)))!=(((T3)'\051')))))){R=((T6)(0));((((T36*)((T36*)(ZFq))))->ZW2)=(ZHq);
}else{ZIq((T36*)(ZFq));ZJq((T36*)(ZFq));}}break;default:;R=((T6)(ZDq()));}}}return R;}T6 Zr7(int C,T0*a1){T6 R=0;ZQq((T36*)(ZFq),a1);
ZJq((T36*)(ZFq));R=((T6)(ZKq(C)));if(R){if(((Z3)((((((T36*)(ZFq))->ZX2)))+(ZE5(1))))!=((Z3)(((((((T7*)a1))->Z21)))+(ZE5(1))))){R=((T6)(0));
((((T36*)((T36*)(ZFq))))->ZW2)=(ZRq);}}return R;}T6 ZMq(int C){T6 R=0;if(ZEq((T36*)(ZFq))){R=((T6)(1));}else{{int z1=ZGq((T36*)(ZFq));
switch(z1){case 43:case 45:ZIq((T36*)(ZFq));ZJq((T36*)(ZFq));R=((T6)((T6)((ZLq(C))&&((T6)(ZMq(C))))));break;default:;R=((T6)(1));}}}return
R;}T6 ZOq(int C){T6 R=0;if(ZEq((T36*)(ZFq))){R=((T6)(1));}else{{int z1=ZGq((T36*)(ZFq));switch(z1){case 42:case 47:ZIq((T36*)(ZFq));ZJq((T36*)(ZFq));
R=((T6)((T6)((ZNq(C))&&((T6)(ZOq(C))))));break;default:;R=((T6)(1));}}}return R;}void ZSq(T51*C){while(!(!(ZTq(C,((T3)'\n'))))){ZUq(C);
}}T6 Zrh(T51*C,T0*a1,T0*a2){T6 R=0;T0*ZVq=Zo;if((((C)->Zw2))!=((void*)(Zo))){ZVq=Zf9((T61*)(((C)->Zw2)),a1);R=((T6)((T6)(((ZVq)!=((void*)(Zo)))&&((T6)(Zr8(((T62*)ZVq),a2))))));
}return R;}void ZWq(T74 a1,T0*a2){ZLj(a1);{T0*b1=a2;ZV6((T7*)(Zde),b1);}Zfe((T73*)(Zge));}void ZXq(T74 a1,T0*a2){ZLj(a1);{T0*b1=a2;ZV6((T7*)(Zde),b1);
}Zuh((T73*)(Zge));}T0*ZYq=Zo;T0*ZZq=Zo;T6 Z_q(T51*C){T6 R=0;if((T6)(((T6)((Z0r(C))&&((T6)(ZTq(C,((T3)'\133'))))))&&((T6)(Z0r(C))))){R=((T6)((T6)(((T6)(((T6)((Z1r(C))&&((T6)(Z0r(C)))))&&((T6)(ZTq(C,((T3)'\135'))))))&&((T6)(Z0r(C))))));
if(R){ZSq(C);(C->Zs2)=Zwq(&(((C)->Zq2)));if((((C)->Zw2))==((void*)(Zo))){{T61*n=((T61*)Zh(sizeof(*n)));*n=M61;{T61*C1=n;Ze9(C1,Z98(193));
}(C->Zw2)=((T0*)n);}}if(!(Zc9((T61*)(((C)->Zw2)),((C)->Zs2)))){Zd9((T61*)(((C)->Zw2)),((T0*)Z78()),((C)->Zs2));}Z2r(C);}}return R;}T0*Z3r=Zo;
int Z4r=0;T0*Z5r(void){if(Z4r==0){Z4r=1;{{T95*n=((T95*)Zh(sizeof(*n)));*n=M95;Z3r=((T0*)n);Zji(n,(T2)(ZE5(0)));}}}return Z3r;}void Z6r(T51*C,T0*a1){
{T74 Zv6;ZLj((*(Zv6=Z7r(C),&Zv6)));}{T0*b1=a1;ZV6((T7*)(Zde),b1);}ZAh((T73*)(Zge));}void Z2r(T51*C){T6 Zt1=0;ZSq(C);while(!(Zt1)){Zt1=((T6)(!(Z8r(C))));
}}void Z9r(T51*C,T0*a1){if((((T53*)(ZOf))->Zi1)){(C->Zr2)=((T6)(1));}else{Z6r(C,a1);}}T0*Zar(void){if(Z8g==0){Z8g=1;{{T72*n=((T72*)Zh(sizeof(*n)));
*n=M72;Z7g=((T0*)n);Zag(n);}}}return Z7g;}void Zbr(T51*C){T6 Zt1=0;ZSq(C);while(!(Zt1)){Zt1=((T6)(!(Z_q(C))));}}T6 ZTq(T51*C,T3 a1){T6
R=0;if((a1)==(((C)->_cc))){(C->Zo2)=((C)->Zk2);(C->Zp2)=((C)->Zj2);R=((T6)(1));Zcr(C);}return R;}T6 Zdr(T51*C){T6 R=0;T2 Z27=0;T2 _l=0;
T2 _c=0;{T74 Zv6;Zvq(&(((C)->Zq2)),(*(Zv6=Zer(((C)->Zk2),((C)->Zj2)),&Zv6)));}Z27=ZE5(0);while(!((T6)(((((C)->_cc))==(((T3)'\n')))||((T6)((((C)->_cc))==(((T3)'\000')))))))
{R=((T6)(1));{int z1=Z27;switch(z1){case 0:{int z2=((C)->_cc);switch(z2){case 9:case 32:ZQ5((T7*)(ZZq),((C)->_cc));Z27=ZE5(1);break;case
45:_l=((C)->Zk2);_c=((C)->Zj2);Z27=ZE5(2);break;default:;{T3 b1=((C)->_cc);ZQ5((T7*)(Zuq),b1);}}}break;case 1:{int z2=((C)->_cc);switch(z2){
case 9:case 32:ZQ5((T7*)(ZZq),((C)->_cc));break;case 45:_l=((C)->Zk2);_c=((C)->Zj2);Z27=ZE5(2);break;default:;{T0*b1=ZZq;ZV6((T7*)(Zuq),b1);
}((((T7*)((T7*)(ZZq))))->Z21)=(ZE5(0));{T3 b1=((C)->_cc);ZQ5((T7*)(Zuq),b1);}Z27=ZE5(0);}}break;case 2:{int z2=((C)->_cc);switch(z2){
case 45:Z27=ZE5(3);break;case 9:case 32:{T0*b1=ZZq;ZV6((T7*)(Zuq),b1);}{T3 b1=((T3)'\055');ZQ5((T7*)(Zuq),b1);}((((T7*)((T7*)(ZZq))))->Z21)=(ZE5(0));
ZQ5((T7*)(ZZq),((C)->_cc));Z27=ZE5(1);break;default:;{T0*b1=ZZq;ZV6((T7*)(Zuq),b1);}{T3 b1=((T3)'\055');ZQ5((T7*)(Zuq),b1);}{T3 b1=((C)->_cc);
ZQ5((T7*)(Zuq),b1);}((((T7*)((T7*)(ZZq))))->Z21)=(ZE5(0));Z27=ZE5(0);}}break;default:;}}Zcr(C);}return R;}T6 Zfr(T51*C,T0*a1){T6 R=0;
T2 _c=0;T2 _i=0;T2 _j=0;_i=((C)->Zj2);_c=((((T7*)a1))->Z21);if((Z3)(((Z3)((((Z3)((((((T7*)(((C)->Zl2)))->Z21)))-(_i))))+(ZE5(1))))>=(_c))){
(C->Zo2)=((C)->Zk2);(C->Zp2)=_i;_j=ZE5(1);while(!((Z3)((_c)<=(ZE5(0))))){if(ZG5(((((T7*)(((C)->Zl2)))->Zl1))[(_i)-(ZE5(1))],(((((T7*)a1))->Zl1))[(_j)-(ZE5(1))])){
_i=(Z3)(((_i))+(ZE5(1)));_j=(Z3)(((_j))+(ZE5(1)));_c=(Z3)(((_c))-(ZE5(1)));}else{_c=ZE5(-1);}}}if((_c)==(ZE5(0))){if((Z3)((_i)>((((T7*)(((C)->Zl2)))->Z21)))){
R=((T6)(1));(C->_cc)=((T3)'\n');(C->Zj2)=_i;ZUq(C);}else{{int z1=((((T7*)(((C)->Zl2)))->Zl1))[(_i)-(ZE5(1))];switch(z1){case 9:case 32:
case 45:R=((T6)(1));(C->_cc)=((((T7*)(((C)->Zl2)))->Zl1))[(_i)-(ZE5(1))];(C->Zj2)=_i;ZUq(C);break;case 48:case 49:case 50:case 51:case
52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case
76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 95:case 97:case
98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:
case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:break;default:;R=((T6)(1));(C->_cc)=((((T7*)(((C)->Zl2)))->Zl1))[(_i)-(ZE5(1))];
(C->Zj2)=_i;}}}}return R;}T74 Z7r(T51*C){T74 R={Zo,Zo,0};{T74 Zv6;R=(*(Zv6=Zer(((C)->Zk2),((C)->Zj2)),&Zv6));}return R;}T0*Zgr(void){
if(ZHa==0){ZHa=1;{{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;ZGa=((T0*)n);}}}return ZGa;}T6 Z1r(T51*C){T6 R=0;T6 Zt1=0;if(ZF5(((C)->_cc))){
{T74 Zv6;Zvq(&(((C)->Zq2)),(*(Zv6=Zer(((C)->Zk2),((C)->Zj2)),&Zv6)));}{T3 b1=((C)->_cc);ZQ5((T7*)(Zuq),b1);}while(!(Zt1)){Zcr(C);{int
z1=((C)->_cc);switch(z1){case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case
109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:{T3 b1=((C)->_cc);
ZQ5((T7*)(Zuq),b1);}break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case
78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:{T3 b1=((C)->_cc);ZQ5((T7*)(Zuq),b1);
}break;case 46:case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 95:{T3 b1=((C)->_cc);ZQ5((T7*)(Zuq),b1);
}break;default:;Zt1=((T6)(1));}}}R=((T6)(1));}return R;}T6 Zhr(T51*C){T6 R=0;T2 Z27=0;T2 _l=0;T2 _c=0;T6 Z_2=0;T6 Z03=0;T6 Zt1=0;T2 Zir=0;
T2 Zjr=0;T2 Zkr=0;T0*Zlr=Zo;T0*Zmr=Zo;T2 Znr=0;T2 Zor=0;_l=((C)->Zk2);_c=((C)->Zj2);if(Zfr(C,Zpr)){Z_2=((T6)(1));}if((((C)->_cc))==(((T3)'U'))){
Z03=((T6)(1));Zcr(C);}if((((C)->_cc))==(((T3)'\042'))){R=((T6)(1));if((T6)(((((T84*)(Zda))->Za2))||((T6)((((T84*)(Zda))->Zb2))))){{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZJ6(n,(T2)(ZE5(32)));Zlr=((T0*)n);}}((((T7*)((T7*)(ZZq))))->Z21)=(ZE5(0));while(!((Z3)((Z27)>(ZE5(9))))){Zcr(C);{int z1=Z27;switch(z1){
case 0:{int z2=((C)->_cc);switch(z2){case 10:while(!((Zmr)!=((void*)(Zo)))){if(((((T7*)(ZZq))->Z21))==(ZE5(0))){Z9r(C,Zqr);}else{{int
z3=ZK6((T7*)(ZZq));switch(z3){case 9:case 32:Z97((T7*)(ZZq),(T2)(ZE5(1)));{T51*C1=C;T0*b1=Zrr;{T74 Zv6;ZWq((*(Zv6=Z7r(C1),&Zv6)),b1);
}}break;case 91:case 123:Zmr=Zsr;((((T7*)(((T7*)Zmr))))->Z21)=(ZE5(0));if((ZK6((T7*)(ZZq)))==(((T3)'\173'))){ZQ5(((T7*)Zmr),((T3)'\175'));
Znr=ZE5(1);Z27=ZE5(8);}else{ZQ5(((T7*)Zmr),((T3)'\135'));Z27=ZE5(7);}ZV6(((T7*)Zmr),ZZq);Zor=ZE5(1);Z97(((T7*)Zmr),(T2)(ZE5(1)));ZQ5(((T7*)Zmr),((T3)'\042'));
((((T7*)((T7*)(ZZq))))->Z21)=(ZE5(0));break;default:;Z9r(C,Zqr);}}}}break;case 34:Z27=ZE5(11);break;case 37:Z27=ZE5(1);break;default:;
ZQ5((T7*)(ZZq),((C)->_cc));}}break;case 1:Z27=ZE5(0);{int z2=((C)->_cc);switch(z2){case 10:Z27=ZE5(3);break;case 65:ZQ5((T7*)(ZZq),((T3)'\100'));
break;case 66:ZQ5((T7*)(ZZq),((T3)'\010'));break;case 67:ZQ5((T7*)(ZZq),((T3)'\136'));break;case 68:ZQ5((T7*)(ZZq),((T3)'\044'));break;
case 70:ZQ5((T7*)(ZZq),((T3)'\014'));break;case 72:ZQ5((T7*)(ZZq),((T3)'\134'));break;case 76:ZQ5((T7*)(ZZq),((T3)'\176'));break;case
78:ZQ5((T7*)(ZZq),((T3)'\n'));break;case 81:ZQ5((T7*)(ZZq),((T3)'\140'));break;case 82:ZQ5((T7*)(ZZq),((T3)'\015'));break;case 83:ZQ5((T7*)(ZZq),((T3)'\043'));
break;case 84:ZQ5((T7*)(ZZq),((T3)'\011'));break;case 85:ZQ5((T7*)(ZZq),((T3)'\000'));break;case 86:ZQ5((T7*)(ZZq),((T3)'\174'));break;
case 37:ZQ5((T7*)(ZZq),((T3)'\045'));break;case 39:ZQ5((T7*)(ZZq),((T3)'\047'));break;case 34:ZQ5((T7*)(ZZq),((T3)'\042'));break;case
40:ZQ5((T7*)(ZZq),((T3)'\133'));break;case 41:ZQ5((T7*)(ZZq),((T3)'\135'));break;case 60:ZQ5((T7*)(ZZq),((T3)'\173'));break;case 62:ZQ5((T7*)(ZZq),((T3)'\175'));
break;case 47:Zir=ZE5(0);Zkr=ZE5(0);Z27=ZE5(4);break;case 9:case 32:Z27=ZE5(2);break;default:;Z9r(C,Ztr);Z27=ZE5(0);}}break;case 2:{int
z2=((C)->_cc);switch(z2){case 10:Z27=ZE5(3);break;case 9:case 32:{T51*C1=C;T0*b1=Zrr;{T74 Zv6;ZWq((*(Zv6=Z7r(C1),&Zv6)),b1);}}break;default:;
Z9r(C,ZV9(60,"In extended form of manifest string.Bad character after \'%\'."));}}break;case 3:{int z2=((C)->_cc);switch(z2){case 9:case
32:break;case 37:Z27=ZE5(0);break;case 10:Z9r(C,Zqr);break;default:;Z9r(C,ZV9(62,"In extended form of manifest string. Bad character before \'%\'."));
}}break;case 4:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zkr=(Z3)(((Zkr))+(ZE5(1)));
Zir=(Z3)((((Z3)(((Zir))*(ZE5(10)))))+((T2)(ZH5(((C)->_cc)))));break;case 120:if(Zu5((T6)((Zkr)==(ZE5(1))),(T6)((Zir)==(ZE5(0))))){Zkr=ZE5(0);
Z27=ZE5(5);}else{Z9r(C,Zur);}break;case 85:if((Zkr)==(ZE5(0))){Zcr(C);if((((C)->_cc))==(((T3)'x'))){Z27=ZE5(6);Zjr=ZE5(0);Zkr=ZE5(0);
}else{Z9r(C,Zur);}}else{Z9r(C,Zur);}break;case 47:ZQ5((T7*)(ZZq),((T3)(Zir)));Z27=ZE5(0);if((Zkr)==(ZE5(0))){{T51*C1=C;T0*b1=Zvr;{T74
Zv6;ZXq((*(Zv6=Z7r(C1),&Zv6)),b1);}}}else if((Z3)((Zir)>((T2)(Zwr)))){Zir=ZE5(0);{T51*C1=C;T0*b1=Zxr;{T74 Zv6;ZXq((*(Zv6=Z7r(C1),&Zv6)),b1);
}}}break;default:;Z9r(C,Zur);}}break;case 5:if(Zy5(((C)->_cc))){Zir=(Z3)((((Z3)(((Zir))*(ZE5(16)))))+((T2)(ZL5(((C)->_cc)))));Zkr=(Z3)(((Zkr))+(ZE5(1)));
if(ZZ5(Zkr)){ZQ5((T7*)(ZZq),((T3)(Zir)));Zir=ZE5(0);}}else if((((C)->_cc))==(((T3)'\057'))){Z27=ZE5(0);if((Zkr)==(ZE5(0))){{T51*C1=C;
T0*b1=Zyr;{T74 Zv6;ZXq((*(Zv6=Z7r(C1),&Zv6)),b1);}}}else if(ZW5(Zkr)){{T51*C1=C;T0*b1=ZV9(85,"You must use an even number of hexadecimal digits to denote a sequence of CHARACTERs.");
{T74 Zv6;ZXq((*(Zv6=Z7r(C1),&Zv6)),b1);}}}}else{Z9r(C,Zyr);}break;case 6:if(Zy5(((C)->_cc))){Zjr=(Z3)((((Z3)(((Zjr))*(ZE5(16)))))+((T2)(ZL5(((C)->_cc)))));
Zkr=(Z3)(((Zkr))+(ZE5(1)));}else if((((C)->_cc))==(((T3)'\057'))){Z27=ZE5(0);if((Zkr)==(ZE5(0))){{T51*C1=C;T0*b1=Zzr;{T74 Zv6;ZXq((*(Zv6=Z7r(C1),&Zv6)),b1);
}}}else if((Z3)((Zkr)>(ZE5(8)))){{T51*C1=C;T0*b1=ZV9(57,"Too long hexadecimal sequence for a single unicode value.");{T74 Zv6;ZXq((*(Zv6=Z7r(C1),&Zv6)),b1);
}}}else{Zoi((T95*)(Z5r()));if((((void)((T95*)(Z5r()))),Zki(Zjr))){Zmi((T95*)(Z5r()),Zjr);Zli((T95*)(Z5r()),ZZq);}else{{T51*C1=C;T0*b1=ZV9(109,"Invalid unicode notation (see also http://www.unicode.org as well as feature \173""UNICODE_STRING\175"".valid_unicode).");
{T74 Zv6;ZXq((*(Zv6=Z7r(C1),&Zv6)),b1);}}}}}else{Z9r(C,Zzr);}break;case 7:{int z2=((C)->_cc);switch(z2){case 9:case 32:Zor=(Z3)(((Zor))+(ZE5(1)));
break;case 10:ZQ5((T7*)(ZZq),((T3)'\n'));Zor=ZE5(1);break;case 0:{T74 Zv6;ZLj((*(Zv6=Zer(_l,_c),&Zv6)));}Z9r(C,ZAr);break;default:;ZQ5((T7*)(ZZq),((C)->_cc));
if((Znr)==(ZE5(0))){Znr=Zor;}Z27=ZE5(8);}}break;case 8:Zor=(Z3)(((Zor))+(ZE5(1)));{int z2=((C)->_cc);switch(z2){case 9:case 32:if((Z3)((Zor)>=(Znr))){
ZQ5((T7*)(ZZq),((C)->_cc));}break;case 10:ZQ5((T7*)(ZZq),((C)->_cc));Zor=ZE5(0);break;case 0:{T74 Zv6;ZLj((*(Zv6=Zer(_l,_c),&Zv6)));}
Z9r(C,ZAr);break;case 34:ZQ5((T7*)(ZZq),((C)->_cc));if(Z07((T7*)(ZZq),Zmr)){Z27=ZE5(10);}break;default:;if((Z3)((Zor)<(Znr))){if((((C)->_cc))==((((((T7*)Zmr))->Zl1))[ZE5(0)])){
ZQ5((T7*)(ZZq),((C)->_cc));Z27=ZE5(9);}else{{T74 Zv6;ZLj((*(Zv6=Zer(_l,_c),&Zv6)));}Z9r(C,ZAr);}}else{ZQ5((T7*)(ZZq),((C)->_cc));}}}break;
default:;{int z2=((C)->_cc);switch(z2){case 0:{T74 Zv6;ZLj((*(Zv6=Zer(_l,_c),&Zv6)));}Z9r(C,ZAr);break;case 34:ZQ5((T7*)(ZZq),((C)->_cc));
if(Z07((T7*)(ZZq),Zmr)){Z27=ZE5(10);}break;default:;ZQ5((T7*)(ZZq),((C)->_cc));}}}}}if((Z27)==(ZE5(10))){{T7*C1=(T7*)(ZZq);T0*b1=Zmr;
Z97(C1,((((T7*)b1))->Z21));}while(!(Zt1)){if(((((T7*)(ZZq))->Z21))==(ZE5(0))){Zt1=((T6)(1));}else{Zt1=((T6)((ZK6((T7*)(ZZq)))==(((T3)'\n'))));
Z97((T7*)(ZZq),(T2)(ZE5(1)));}}}{T74 Zv6;{T93*n=((T93*)Zh(sizeof(*n)));*n=M93;ZYi(n,(*(Zv6=Zer(_l,_c),&Zv6)),(T6)(Z_2),(T6)(Z03),ZZq);
(C->Zu2)=((T0*)n);}}Zcr(C);ZUq(C);}return R;}void Zqh(T51*C){(C->Zs2)=Zo;(C->Zt2)=Zo;(C->Zk2)=ZE5(1);(C->Zj2)=ZE5(1);(C->Zl2)=(((((T47*)((((T72*)(Zar()))->Ze2))))->Zl1))[((C)->Zk2)];
(C->Zf1)=(((T72*)(Zar()))->ZS1);if(((((T7*)(((C)->Zl2)))->Z21))==(ZE5(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->Zl2)))->Zl1))[ZE5(0)];
}ZUq(C);if((((C)->_cc))!=(((T3)'\133'))){Z2r(C);}Zbr(C);ZSq(C);if((((C)->_cc))!=(((T3)'\000'))){{T74 Zv6;ZLj((*(Zv6=Zer(((C)->Zk2),((C)->Zj2)),&Zv6)));
}Z9r(C,ZV9(28,"Unexpected text continuation"));}else if((T6)(((((C)->Zv2))==((void*)(Zo)))&&((T6)((((C)->Zw2))==((void*)(Zo)))))){{T74
Zv6;ZLj((*(Zv6=Zer(((C)->Zk2),((C)->Zj2)),&Zv6)));}Z9r(C,ZV9(18,"Invalid empty file"));}Z2i((T72*)(Zar()));}T6 ZFi(T51*C,T0*a1){T6 R=0;
R=((T6)((T6)(((((C)->Zv2))!=((void*)(Zo)))&&((T6)(Zr8((T62*)(((C)->Zv2)),a1))))));return R;}void ZUq(T51*C){T74 _sp={Zo,Zo,0};T6 Zt1=0;
while(!(Zt1)){{int z1=((C)->_cc);switch(z1){case 9:case 10:case 32:Zcr(C);break;case 45:Zcr(C);if((((C)->_cc))==(((T3)'\055'))){if(((C)->Zn2)){
if((((C)->Zk2))==((((T72*)(Zar()))->Z21))){(C->_cc)=((T3)'\000');Zt1=((T6)(1));}else{(C->Zk2)=(Z3)(((((C)->Zk2)))+(ZE5(1)));(C->Zj2)=ZE5(1);
(C->Zl2)=(((((T47*)((((T72*)(Zar()))->Ze2))))->Zl1))[((C)->Zk2)];if(((((T7*)(((C)->Zl2)))->Z21))==(ZE5(0))){(C->_cc)=((T3)'\n');}else{
(C->_cc)=((((T7*)(((C)->Zl2)))->Zl1))[ZE5(0)];}}}else{{T74 Zv6;_sp=(*(Zv6=Zer(((C)->Zk2),(Z3)(((((C)->Zj2)))-((T2)(ZE5(1))))),&Zv6));
}Zcr(C);((((T7*)((T7*)(ZYq))))->Z21)=(ZE5(0));while(!((((C)->_cc))==(((T3)'\n')))){ZQ5((T7*)(ZYq),((C)->_cc));Zcr(C);}if((((C)->Zm2))==((void*)(Zo))){
{T91*n=((T91*)Zh(sizeof(*n)));*n=M91;ZVd(n,_sp,Zn7((T7*)(ZYq)));(C->Zm2)=((T0*)n);}}else{Z08(((T42*)((((T91*)(((C)->Zm2)))->Zh1))),Zn7((T7*)(ZYq)));
}}}else{(C->_cc)=((T3)'\055');(C->Zj2)=(Z3)(((((C)->Zj2)))-(ZE5(1)));Zt1=((T6)(1));}break;default:;Zt1=((T6)(1));}}}}T0*Zgk(T51*C){T0*R=Zo;
if((((C)->Zw2))!=((void*)(Zo))){R=ZJ7(((T47*)((((T61*)(((C)->Zw2)))->Z61))));}return R;}T0*Z0h(T51*C,T0*a1,T0*a2){T0*R=Zo;R=Zf8((T62*)(Z79((T61*)(((C)->Zw2)),a1)),a2);
return R;}void Zcr(T51*C){if((Z3)((((C)->Zj2))<((((T7*)(((C)->Zl2)))->Z21)))){(C->Zj2)=(Z3)(((((C)->Zj2)))+(ZE5(1)));(C->_cc)=((((T7*)(((C)->Zl2)))->Zl1))[(((C)->Zj2))-(ZE5(1))];
}else if((((C)->Zj2))==((((T7*)(((C)->Zl2)))->Z21))){(C->Zj2)=(Z3)(((((C)->Zj2)))+(ZE5(1)));(C->_cc)=((T3)'\n');}else if((((C)->Zk2))==((((T72*)(Zar()))->Z21))){
(C->_cc)=((T3)'\000');}else{(C->Zk2)=(Z3)(((((C)->Zk2)))+(ZE5(1)));(C->Zj2)=ZE5(1);(C->Zl2)=(((((T47*)((((T72*)(Zar()))->Ze2))))->Zl1))[((C)->Zk2)];
if(((((T7*)(((C)->Zl2)))->Z21))==(ZE5(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->Zl2)))->Zl1))[ZE5(0)];}}}T6 Z8r(T51*C){T6
R=0;T6 Z9k=0;if((T6)((Z1r(C))&&((T6)(Z0r(C))))){if(!(ZTq(C,((T3)'\072')))){{T74 Zv6;ZLj((*(Zv6=Zer(((C)->Zk2),((C)->Zj2)),&Zv6)));}{T0*b1=ZBr;
ZV6((T7*)(Zde),b1);}Zfe((T73*)(Zge));}Z9k=((T6)(Z0r(C)));(C->Zt2)=Zsq(&(((C)->Zq2)));if((ZCr(C))!=((void*)(Zo))){(((void)((T49*)(Zgr()))),ZC9(ZDr));
(((void)((T49*)(Zgr()))),ZC9(((C)->Zt2)));(((void)((T49*)(Zgr()))),ZC9(ZEr));if((((C)->Zs2))!=((void*)(Zo))){(((void)((T49*)(Zgr()))),ZC9(ZFr));
(((void)((T49*)(Zgr()))),ZC9(((C)->Zs2)));(((void)((T49*)(Zgr()))),ZE9(((T3)'\135')));}(((void)((T49*)(Zgr()))),ZC9(ZGr));}if((T6)(((((C)->_cc))==(((T3)'\n')))||((T6)((((C)->_cc))==(((T3)'\000')))))){
R=((T6)(1));ZHr(C,ZIr);}else if((T6)(((((C)->_cc))==(((T3)'\042')))&&((T6)(Zhr(C))))){R=((T6)(1));ZHr(C,(((T93*)(((C)->Zu2)))->Z13));
}else if(Zdr(C)){R=((T6)(1));ZHr(C,Zsq(&(((C)->Zq2))));}if(R){ZSq(C);}}return R;}T0*ZXg(T51*C,T0*a1){T0*R=Zo;T0*ZVq=Zo;if((((C)->Zw2))!=((void*)(Zo))){
ZVq=Zf9((T61*)(((C)->Zw2)),a1);if((ZVq)!=((void*)(Zo))){R=ZJr(ZVq);}}return R;}void ZHr(T51*C,T0*a1){if((((C)->Zs2))==((void*)(Zo))){
if((((C)->Zv2))==((void*)(Zo))){{T62*n=((T62*)Zh(sizeof(*n)));*n=M62;{T62*C1=n;Z88(C1,Z98(193));}(C->Zv2)=((T0*)n);}}Zs8((T62*)(((C)->Zv2)),a1,((C)->Zt2));
}else{Zs8((T62*)(Z79((T61*)(((C)->Zw2)),((C)->Zs2))),a1,((C)->Zt2));}}T0*ZCr(T51*C){T0*R=Zo;if((((C)->Zs2))==((void*)(Zo))){if((((C)->Zv2))!=((void*)(Zo))){
R=Zu8((T62*)(((C)->Zv2)),((C)->Zt2));}}else if(Zc9((T61*)(((C)->Zw2)),((C)->Zs2))){R=Zu8((T62*)(Z79((T61*)(((C)->Zw2)),((C)->Zs2))),((C)->Zt2));
}return R;}T6 Z0r(T51*C){T6 R=0;T6 Zt1=0;while(!(Zt1)){{int z1=((C)->_cc);switch(z1){case 9:case 32:Zcr(C);break;default:;Zt1=((T6)(1));
}}}R=((T6)(1));return R;}T74 Zer(T2 a1,T2 a2){T74 R={Zo,Zo,0};{T74*C1=&R;T2 b1=a1;T2 b2=a2;Zgj(C1,b1,b2,Z98(32766),Zo);}return R;}void
ZIq(T36*C){(C->ZX2)=(Z3)(((((C)->ZX2)))+(ZE5(1)));}void ZQq(T36*C,T0*a1){(C->ZX2)=ZE5(0);(C->Zm1)=(Z3)(((((((T7*)a1))->Z21)))-(ZE5(1)));
(C->Z11)=((((T7*)a1))->Z11);(C->Zl1)=((((T7*)a1))->Zl1);(C->ZW2)=Zo;}T3 ZGq(T36*C){T3 R=0;R=(((C)->Zl1))[((C)->ZX2)];return R;}void ZJq(T36*C){
T6 Zt1=0;while(!(Zt1)){if((Z3)((((C)->ZX2))>(((C)->Zm1)))){Zt1=((T6)(1));}else if(Zx5((((C)->Zl1))[((C)->ZX2)])){(C->ZX2)=(Z3)(((((C)->ZX2)))+(ZE5(1)));
}else{Zt1=((T6)(1));}}}T6 ZEq(T36*C){T6 R=0;R=((T6)((Z3)((((C)->ZX2))>(((C)->Zm1)))));return R;}T12*ZKr=Zo;int ZLr;char**ZMr;void ZNr(void){
{T0*C=Zi9;Z1a(((T31*)C));}}void ZOr(int ZPr,char*ZQr[]){ZLr=ZPr;ZMr=ZQr;ZRr(ZNr);
#ifdef SIGQUIT
ZSr(ZTr,ZW3);
#endif
#ifdef SIGILL
ZSr(ZUr,ZW3);
#endif
#ifdef SIGABRT
ZSr(ZVr,ZW3);
#endif
#ifdef SIGFPE
ZSr(ZWr,ZW3);
#endif
#ifdef SIGSEGV
ZSr(ZXr,ZW3);
#endif
#ifdef SIGBUS
ZSr(ZYr,ZW3);
#endif
#ifdef SIGSYS
ZSr(ZZr,ZW3);
#endif
#ifdef SIGTRAP
ZSr(Z_r,ZW3);
#endif
#ifdef SIGXCPU
ZSr(Z0s,ZW3);
#endif
#ifdef SIGXFSZ
ZSr(Z1s,ZW3);
#endif
Z2s();{T53*n=((T53*)Zh(sizeof(*n)));*n=M53;ZOf=((T0*)n);}Zdm=Zle(8,ZV9(10,"C:\\WINDOWS"),ZV9(8,"C:\\WINNT"),ZV9(8,"C:\\WIN95"),ZV9(8,"C:\\WIN98"),
ZV9(8,"C:\\WINME"),ZV9(8,"C:\\WIN2K"),ZV9(10,"C:\\WIN2000"),ZV9(8,"C:\\WINXP"));{int _s=0;ZRg=ZR9(Z3s);}{T51*n=((T51*)Zh(sizeof(*n)));
*n=M51;Zng=((T0*)n);}{T84*n=((T84*)Zh(sizeof(*n)));*n=M84;Zda=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZVi=((T0*)n);ZJ6(n,(T2)(Z98(512)));
}{T82*n=((T82*)Zh(sizeof(*n)));*n=M82;Zaf=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZTf=((T0*)n);ZJ6(n,(T2)(Z98(128)));}{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZO6=((T0*)n);ZJ6(n,(T2)(Z98(256)));}{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;ZP6=((T0*)n);Z68(n,(T2)(ZE5(4)),(T2)(ZE5(1)));}Z4k=Zle(5,
ZV9(7,ZL3),ZV9(5,ZM3),ZV9(6,"finder"),ZV9(9,"ace_check"),ZV9(15,"print_jvm_class"));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZTj=((T0*)n);ZJ6(n,(T2)(Z98(512)));
}Z5k=Zle(3,ZV9(12,Z43),ZV9(7,ZL3),ZV9(5,ZM3));Z7k=Zle(5,ZV9(12,Z43),ZV9(5,Zs3),ZV9(11,"class_check"),ZV9(6,"pretty"),ZV9(14,"compile_to_jvm"));
{T50*n=((T50*)Zh(1));Zaa=((T0*)n);}{ZL*n=((ZL*)Zh(sizeof(*n)));*n=ZZ2;Zhl=((T0*)n);ZJh(n);}{T66*n=((T66*)Zh(sizeof(*n)));*n=M66;ZPk=((T0*)n);
Z19(n);}{T66*n=((T66*)Zh(sizeof(*n)));*n=M66;ZMl=((T0*)n);Z19(n);}{ZH*n=((ZH*)Zh(sizeof(*n)));*n=ZQ1;Zzn=((T0*)n);{ZH*C1=n;ZH8(C1,Z98(193));
}}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZNj=((T0*)n);ZJ6(n,(T2)(ZE5(16)));}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zkg=((T0*)n);ZJ6(n,(T2)(ZE5(16)));
}{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;Zzg=((T0*)n);ZM7(n,(T2)(ZE5(4)));}{int _s=0;ZAe=ZR9(Z4s);}{int _s=0;ZEg=ZR9(Z5s);}{T73*n=((T73*)Zh(sizeof(*n)));
*n=M73;Zge=((T0*)n);}{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;Zhe=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZZq=((T0*)n);ZJ6(n,(T2)(ZE5(80)));
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZYq=((T0*)n);ZJ6(n,(T2)(ZE5(80)));}{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;Zxj=((T0*)n);ZM7(n,(T2)(ZE5(1)));
}{T66*n=((T66*)Zh(sizeof(*n)));*n=M66;ZSi=((T0*)n);Z29(n,(T2)(Z98(16384)));}{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zca=((T0*)n);ZB8(n,(T2)(Z98(2048)));
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zba=((T0*)n);ZJ6(n,(T2)(Z98(128)));}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z1e=((T0*)n);ZJ6(n,(T2)(Z98(1024)));
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zde=((T0*)n);ZJ6(n,(T2)(Z98(1024)));}{T75*n=((T75*)Zh(sizeof(*n)));*n=M75;ZGj=((T0*)n);ZF7(n,(T2)(ZE5(16)));
}{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;Zlj=((T0*)n);}{int _s=0;Zog=ZR9(Zrg);}{T22*n=((T22*)Zh(1));ZNf=((T0*)n);}{T31*n=((T31*)Zh(sizeof(*n)));
*n=M31;Zi9=((T0*)n);ZZi(n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z4i=((T0*)n);ZJ6(n,(T2)(ZE5(16)));}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZCg=((T0*)n);
ZJ6(n,(T2)(Z98(256)));}{T37*n=((T37*)Zh(sizeof(*n)));*n=M37;Z1j=((T0*)n);ZQd(n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZOj=((T0*)n);ZJ6(n,(T2)(ZE5(16)));
}{T36*n=((T36*)Zh(sizeof(*n)));*n=M36;ZFq=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_j=((T0*)n);ZJ6(n,(T2)(ZE5(16)));}{T12*n=((T12*)Zh(sizeof(*n)));
*n=M12;ZKr=n;}}int main(int ZPr,char*ZQr[]){ZOr(ZPr,ZQr);{T12*n=ZKr;Zum(n);}Zv(0);return 0;}T0*Zgo;T0*ZJo;T0*ZWl;T0*Z8o;T0*ZMi;T0*Zve;
T0*Ztn;T0*Zkc;T0*Zkn;T0*ZQm;T0*Zhc;T0*Zoe;T0*Zan;T0*Zsd;T0*ZJd;T0*ZTl;T0*Zjb;T0*ZWb;T0*Zrj;T0*ZPl;T0*Zvn;T0*Zqj;T0*ZKm;T0*Zxh;T0*Zen;
T0*Z1c;T0*ZJj;T0*ZA9;T0*Z7c;T0*Zed;T0*Zac;T0*Zbm;T0*ZFp;T0*Zqp;T0*Zkh;T0*Znb;T0*Zdd;T0*ZWa;T0*ZX9;T0*ZUj;T0*ZDc;T0*ZCc;T0*Z0o;T0*Z3q;
T0*ZIc;T0*Zrb;T0*ZXp;T0*ZBr;T0*ZJ9;T0*ZOc;T0*ZKj;T0*ZYp;T0*Zwd;T0*ZMm;T0*Zn9;T0*Zfo;T0*Zfd;T0*Zzr;T0*ZRk;T0*ZGe;T0*ZGl;T0*Znl;T0*Zvp;
T0*ZUe;T0*Zpo;T0*ZHd;T0*ZZo;T0*Z7b;T0*ZGb;T0*ZGo;T0*Z2g;T0*ZRc;T0*ZB9;T0*ZZa;T0*Zne;T0*Zpg;T0*Zjm;T0*Zlb;T0*Zkb;T0*ZD9;T0*Zhf;T0*Zvj;
T0*Zoj;T0*Zth;T0*ZAb;T0*ZCb;T0*ZIb;T0*Zjk;T0*ZNb;T0*ZDb;T0*Zxb;T0*Zub;T0*ZIo;T0*ZEa;T0*Zhn;T0*Z0n;T0*ZPb;T0*Zha;T0*Zhb;T0*ZQn;T0*Zuc;
T0*ZQ9;T0*ZVe;T0*Zvh;T0*ZFb;T0*Zbc;T0*Z7l;T0*Z5m;T0*Zab;T0*Zzd;T0*ZFo;T0*ZZp;T0*Zxc;T0*ZLe;T0*Zwj;T0*ZSp;T0*ZEl;T0*Z5p;T0*ZVc;T0*ZId;
T0*Z3m;T0*ZDn;T0*ZUl;T0*Zbo;T0*Zpj;T0*Zzj;T0*Zwb;T0*ZGd;T0*Zyq;T0*ZSc;T0*Zyk;T0*Zih;T0*Zbn;T0*ZAl;T0*ZCo;T0*ZAo;T0*ZEd;T0*ZMp;T0*ZPa;
T0*Zhm;T0*Zxg;T0*Z4m;T0*ZLg;T0*Zwc;T0*Zwf;T0*Z9b;T0*Z2o;T0*Ztp;T0*Zpc;T0*Z3p;T0*Zrk;T0*ZJl;T0*ZLo;T0*ZBn;T0*ZLp;T0*Zun;T0*ZAf;T0*Z4l;
T0*ZKn;T0*ZVa;T0*Z6o;T0*Zyc;T0*ZCf;T0*ZCn;T0*ZNl;T0*ZOl;T0*Zgl;T0*Z6f;T0*Zrl;T0*ZEp;T0*Z1o;T0*Z0m;T0*ZQb;T0*Zsh;T0*ZIn;T0*ZCm;T0*Zwh;
T0*ZSm;T0*Zmo;T0*Z4s;T0*Zqc;T0*ZYj;T0*Zsc;T0*ZDp;T0*Z6m;T0*ZCd;T0*ZZn;T0*ZBq;T0*ZHh;T0*Z4b;T0*ZYb;T0*Zpn;T0*Z7o;T0*Zvr;T0*ZKg;T0*Zqg;
T0*ZEh;T0*Zoo;T0*Z4q;T0*Znk;T0*ZCp;T0*Zqo;T0*Z3c;T0*Zcp;T0*ZFh;T0*ZOk;T0*Ztr;T0*Z3d;T0*ZEm;T0*Zqe;T0*ZDd;T0*Zzh;T0*Zzf;T0*Z9f;T0*Zin;
T0*ZUo;T0*Zif;T0*Zvf;T0*ZPc;T0*Z1d;T0*Zzl;T0*ZHe;T0*Z2d;T0*ZTm;T0*Z0d;T0*Zmn;T0*Zpa;T0*ZJe;T0*Znp;T0*Z_f;T0*Z6b;T0*Zef;T0*Zbl;T0*ZSg;
T0*Z1g;T0*ZQe;T0*Zdg;T0*Zcf;T0*Z5b;T0*ZKk;T0*ZPh;T0*Z8e;T0*ZXe;T0*ZTe;T0*ZZe;T0*ZGi;T0*Zdb;T0*ZM9;T0*Zsb;T0*Z_a;T0*Zap;T0*ZTp;T0*Zmb;
T0*Zqb;T0*ZDo;T0*ZGc;T0*ZHc;T0*Zxr;T0*Z6p;T0*ZOa;T0*ZKi;T0*ZNe;T0*ZHi;T0*ZMa;T0*Zyd;T0*Z7f;T0*Zon;T0*Zql;T0*Zgc;T0*ZPi;T0*Z5q;T0*ZRo;
T0*Zur;T0*Zjd;T0*ZJc;T0*Z9c;T0*ZIr;T0*Zpe;T0*ZGh;T0*Zvc;T0*Zvl;T0*Z8c;T0*ZMe;T0*Z8d;T0*ZXa;T0*Zsj;T0*Z5s;T0*Z1m;T0*ZSk;T0*Z_b;T0*Zsg;
T0*Zco;T0*Z5e;T0*Zee;T0*Zbe;T0*Zm9;T0*ZS9;T0*Zmq;T0*Zsl;T0*Zme;T0*ZJn;T0*ZPo;T0*Z3s;T0*ZAr;T0*ZT9;T0*Zrc;T0*ZSb;T0*Zqd;T0*ZP9;T0*Zad;
T0*Zgm;T0*Z9d;T0*Zyr;T0*Zna;T0*ZO9;T0*ZGg;T0*ZUa;T0*Zrg;T0*ZOp;T0*ZYe;T0*ZKd;T0*Zod;T0*ZNo;T0*ZQc;T0*Zal;T0*Zjc;T0*Z5f;T0*Z7e;T0*Zwg;
T0*Ztd;T0*Zze;T0*Zka;T0*Zxp;T0*Zpr;T0*Z2c;T0*ZBc;T0*Z_h;T0*Z0f;T0*ZUp;T0*ZHq;T0*Zcc;T0*Zxf;T0*Znq;T0*Zuj;T0*Zwm;T0*ZNp;T0*ZXb;T0*Z4o;
T0*Zjq;T0*ZVg;T0*Z6k;T0*Zyn;T0*Zbb;T0*Zlq;T0*Zyl;T0*Z6d;T0*ZJg;T0*Z6c;T0*Zbd;T0*ZBd;T0*Z4f;T0*Zud;T0*ZYa;T0*ZVp;T0*Zec;T0*Zdc;T0*Z2f;
T0*Zyp;T0*ZIm;T0*ZVh;T0*Zqn;T0*Zfb;T0*Z_n;T0*ZZb;T0*ZMk;T0*Z6g;T0*Zfn;T0*Zob;T0*Zlp;T0*Zbp;T0*Zpb;T0*ZMo;T0*Z1l;T0*ZIl;T0*ZCk;T0*ZLa;
T0*Z1b;T0*Zrn;T0*ZEo;T0*ZMc;T0*ZNa;T0*Z0l;T0*Z0b;T0*Zlk;T0*ZYg;T0*Zs9;T0*Zjn;T0*ZEj;T0*ZBp;T0*Zlc;T0*Zeb;T0*Z_o;T0*ZOi;T0*ZNm;T0*ZOg;
T0*Zld;T0*Zmc;T0*Zsn;T0*ZEb;T0*Zvg;T0*ZYc;T0*ZKb;T0*ZLb;T0*ZTc;T0*ZXm;T0*Z5d;T0*ZFd;T0*ZAm;T0*Znh;T0*ZOb;T0*Znc;T0*Zqr;T0*Zoc;T0*ZVj;
T0*Zce;T0*Z7n;T0*ZQa;T0*ZEr;T0*ZRa;T0*Zcd;T0*ZRb;T0*ZDk;T0*ZWp;T0*Zue;T0*ZRj;T0*Z_l;T0*ZTb;T0*ZBl;T0*Z9p;T0*ZUh;T0*Z8q;T0*Zsp;T0*ZPe;
T0*ZUb;T0*Z6h;T0*ZWk;T0*ZQo;T0*Zeq;T0*Zwl;T0*ZOm;T0*Ztl;T0*Z7d;T0*Zse;T0*Zpl;T0*Zsf;T0*ZIe;T0*Zaq;T0*Zsr;T0*Z9m;T0*Z5l;T0*ZZj;T0*Z0c;
T0*Zfq;T0*Zte;T0*ZXk;T0*ZYk;T0*ZKc;T0*Zmk;T0*Z5g;T0*Z3f;T0*ZDl;T0*ZHk;T0*ZGp;T0*ZCe;T0*Zul;T0*ZPp;T0*Zko;T0*ZDe;T0*ZQp;T0*Zgq;T0*Zpf;
T0*ZXc;T0*Z8m;T0*ZOh;T0*ZFl;T0*ZFc;T0*Z1f;T0*Z8f;T0*Ziq;T0*ZEc;T0*ZRn;T0*ZZf;T0*ZSn;T0*Zxd;T0*ZRh;T0*ZMj;T0*ZQh;T0*Zmp;T0*Zqa;T0*Zln;
T0*ZLi;T0*ZGr;T0*Zbh;T0*Zcm;T0*Zup;T0*Zr9;T0*Zug;T0*ZGm;T0*ZPm;T0*ZCl;T0*Zdp;T0*Zrr;T0*ZTh;T0*Z5o;T0*Zop;T0*Zhq;T0*Z_k;T0*Zpd;T0*Zrd;
T0*Zjh;T0*ZKe;T0*Zzp;T0*ZIk;T0*ZUc;T0*ZZc;T0*Z_c;T0*ZFr;T0*Zmh;T0*ZEk;T0*Z3k;T0*Z4p;T0*Zwp;T0*Zgf;T0*Z6n;T0*Zeo;T0*Zel;T0*ZJi;T0*Zkd;
T0*Z3o;T0*Zrp;T0*Ztg;T0*Zqk;T0*ZBb;T0*Zib;T0*ZHb;T0*Zzb;T0*ZMb;T0*Zyb;T0*Ztb;T0*Zvb;T0*Zgb;T0*Zdn;T0*ZJb;T0*Zgn;T0*ZIi;T0*Zra;T0*Zja;
T0*Zsa;T0*Zhd;T0*ZWc;T0*Z5c;T0*ZY9;T0*ZIh;T0*Zeg;T0*ZMg;T0*Z2m;T0*Z2q;T0*ZMf;T0*ZFa;T0*ZTa;T0*ZRp;T0*Zzq;T0*Zlh;T0*Zzc;T0*ZFe;T0*Z5h;
T0*ZAc;T0*Zff;T0*Z5a;T0*ZAk;T0*Z9q;T0*ZFj;T0*ZRq;T0*Zoa;T0*ZAq;T0*Zxk;T0*ZJp;T0*ZTn;T0*ZBo;T0*Zno;T0*Zgd;T0*Zwn;T0*Zma;T0*Znn;T0*ZYn;
T0*Z6q;T0*Zmd;T0*ZZl;T0*Ztj;T0*ZAp;T0*Z3b;T0*Zia;T0*Zuq;T0*Zjo;T0*ZN9;T0*Ztc;T0*Z7m;T0*Z1n;T0*ZOo;T0*Z9n;T0*Zid;T0*Z5n;T0*Zae;T0*Znd;
T0*ZXl;T0*ZSa;T0*ZLm;T0*Z2b;T0*ZHo;T0*Z9e;T0*Zfm;T0*ZZk;T0*ZRe;T0*Znf;T0*ZSh;T0*Zho;T0*Z4d;T0*ZAd;T0*ZQi;T0*Zoh;T0*ZNk;T0*ZSl;T0*Z4c;
T0*ZIj;T0*Zzk;T0*ZFg;T0*ZVb;T0*ZW9;T0*ZDm;T0*ZIp;T0*ZYl;T0*Zga;T0*Z7q;T0*Zre;T0*Zxl;T0*ZRl;T0*ZNc;T0*Z8b;T0*Zla;T0*Zvd;T0*ZLc;T0*Zic;
T0*ZKp;T0*Zyh;T0*Zkq;T0*Zio;T0*ZQl;T0*Zcn;T0*Zcl;T0*Zcb;T0*Zao;T0*ZHg;T0*ZNi;T0*Zvm;T0*ZFm;T0*Z0g;T0*Zdo;T0*Zfl;T0*ZIg;T0*ZDr;T0*ZLd;
T0*Zfc;T0*ZV9(int c,char*e){T7*s=((T7*)Zh(sizeof(T7)));s->Z21=c;s->Z11=c+1;s->Zl1=((T9)Zh(c+1));Zx6(s->Zl1,e,c+1);return((T0*)s);}T0*Z6s(char*e){
int c=Zl4(e);T7*s=((T7*)Zh(sizeof(T7)));s->Z21=c;s->Z11=c+1;s->Zl1=((T9)Zh(c+1));Zx6(s->Zl1,e,c+1);return((T0*)s);}void Z2s(void){Zgo=ZV9(3,Zw3);
ZJo=ZV9(0,Z23);ZWl=ZV9(2,Za3);Z8o=ZV9(7,ZF3);ZMi=ZV9(17,"cpp_compiler_type");Zve=ZV9(5,ZI3);Ztn=ZV9(51,"\n   The default C compiler could not be determined.");
Zkc=ZV9(9,"exception");Zkn=ZV9(26,"\n      C++ compiler type: ");ZQm=ZV9(3,Zw3);Zhc=ZV9(12,"double_floor");Zoe=ZV9(6,Z63);Zan=ZV9(23,"\n\n   Operating system: ");
Zsd=ZV9(10,"to_pointer");ZJd=ZV9(6,"Result");ZTl=ZV9(16,"C linker options");Zjb=ZV9(9,"bit_clear");ZWb=ZV9(4,"call");Zrj=ZV9(7,"require");
ZPl=ZV9(49,ZR3);Zvn=ZV9(9,ZJ3);Zqj=ZV9(2,"no");ZKm=ZV9(15,"new C mode name");Zxh=ZV9(2,"os");Zen=ZV9(12,"\n   C mode: ");Z1c=ZV9(4,"code");
ZJj=ZV9(5,"Error");ZA9=ZV9(9,"Writing \"");Z7c=ZV9(4,"copy");Zed=ZV9(17,"standard_is_equal");Zac=ZV9(14,"default_create");Zbm=ZV9(42,"Could not compute the parent directory of ");
ZFp=ZV9(983,"\n\n-- ======================================================================= --\n\n-- Below are the \"C mode\" sections. Each C mode describes which C compiler must\n-- be called, with which options, which linker, and so on. The keys are\n-- described below.\n\n-- The first sections (boost, ..., debug_check) are by default used in\n-- conjunction with the corresponding SmartEiffel check level. This behaviour\n-- may be changed by using the -c_mode flag.\n\n-- The recognized keys in each section are:\n\n-- \'compiler_type\', which tells which is the compiler type to use\n\n-- \'compiler_path\', which gives the path to the compiler executable\n\n-- \'compiler_options\', which gives some options to the compiler\n\n-- \'linker_path\', which gives the path to the linker executable (not used in\n--  -no_split mode)\n\n-- \'linker_options\', which gives some options for the linker (not used in\n--  -no_split mode)\n\n-- \'smarteiffel_options\', which gives some extra SmartEiffel options to take\n--  into account\n\n");
Zqp=ZV9(2,Zc3);Zkh=ZV9(34,"Math=IEEE Parameters=Both Code=Far");Znb=ZV9(10,"bit_rotate");Zdd=ZV9(13,"standard_copy");ZWa=ZV9(7,"GENERAL");
ZX9=ZV9(15," used in file \"");ZUj=ZV9(7,ZL3);ZDc=ZV9(4,"last");ZCc=ZV9(4,"item");Z0o=ZV9(13,ZO3);Z3q=ZV9(0,Z23);ZIc=ZV9(4,"make");Zrb=ZV9(4,"\174"">>>");
ZXp=ZV9(13,"Sys directory");ZBr=ZV9(12,"Inserted \':\'");ZJ9=ZV9(21,"Trying to read file \"");ZOc=ZV9(14,"Maximum_double");Z7s();}void
Z7s(void){ZKj=ZV9(17,"Too many errors.\n");ZYp=ZV9(15,"Short directory");Zwd=ZV9(4,"twin");ZMm=ZV9(56,"\n*** This C mode already exists. Please choose another.\n");
Zn9=ZV9(3,Zk3);Zfo=ZV9(35,". Set the default compilers options");Zfd=ZV9(13,"standard_twin");Zzr=ZV9(44,"Unexpected character in hexadecimal unicode.");
ZRk=ZV9(12,"loadpath key");ZGe=ZV9(0,Z23);ZGl=ZV9(19,"Known C compilers: ");Znl=ZV9(86,"\n---------------------------------------------------------------------------\n\nC mode: ");
Zvp=ZV9(10,"[General]\n");ZUe=ZV9(6,"wcl386");Zpo=ZV9(41,"Please enter a valid number between 1 and");ZHd=ZV9(19,"open_argument_count");
ZZo=ZV9(21,"C compiling no-split ");Z7b=ZV9(8,"REAL_REF");ZGb=ZV9(7,"or else");ZGo=ZV9(67,".\nPlease either type <Enter> to go on, or choose a new C mode now.\n");
Z2g=ZV9(45,Zo3);ZRc=ZV9(12,"Pointer_bits");ZB9=ZV9(8,"\" file.\n");ZZa=ZV9(6,"MEMORY");Zne=ZV9(7,Zh3);Zpg=ZV9(9,ZH3);Zjm=ZV9(7,ZC3);Zlb=ZV9(1,"\174""");
Zkb=ZV9(1,"\176""");ZD9=ZV9(19,"Cannot write file \"");Zhf=ZV9(5,"a.out");Zvj=ZV9(3,"all");Zoj=ZV9(7,"unknown");Zth=ZV9(3,ZB3);ZAb=ZV9(2,"#-");
ZCb=ZV9(2,"#*");ZIb=ZV9(2,"#+");Zjk=ZV9(208,"\n*** Fatal problem during installation of SmartEiffel.\n    Read carefully the following information before starting\n    again the installation.\n***************************************************************\n");
ZNb=ZV9(2,"//");ZDb=ZV9(2,"/=");Zxb=ZV9(2,"<=");Zub=ZV9(2,">=");ZIo=ZV9(0,Z23);ZEa=ZV9(32,"Previous IDs reloaded (max_id = ");Zhn=ZV9(27,"\n      C compiler options: ");
Z0n=ZV9(0,Z23);ZPb=ZV9(2,"a1");Zha=ZV9(9,"INTEGER_8");Zhb=ZV9(2,"\\\\");ZQn=ZV9(3,"tag");Z8s();}void Z8s(void){Zuc=ZV9(2,"io");ZQ9=ZV9(10," in file \"");
ZVe=ZV9(5,"bcc32");Zvh=ZV9(3,ZG3);ZFb=ZV9(2,"or");Zbc=ZV9(14,"default_rescue");Z7l=ZV9(26,"--press <Enter> for more--");Z5m=ZV9(19,Zy3);
Zab=ZV9(15,"TEXT_FILE_WRITE");Zzd=ZV9(9,"arguments");ZFo=ZV9(36,"\nThe default installation C mode is ");ZZp=ZV9(39,Zn3);Zxc=ZV9(13,"is_deep_equal");
ZLe=ZV9(0,Z23);Zwj=ZV9(5,"debug");ZSp=ZV9(23,"configuration file name");ZEl=ZV9(5,"12]: ");Z5p=ZV9(2,Zd3);ZVc=ZV9(8,"print_on");ZId=ZV9(9,"Precursor");
Z3m=ZV9(49,ZR3);ZDn=ZV9(191,"***************************************************************\nFix the previously described problem and launch again the,\ninstallation, or contact the SmartEiffel team:\nSmartEiffel@loria.fr\n");
ZUl=ZV9(21,"Known C++ compilers: ");Zbo=ZV9(14,". Modify the \"");Zpj=ZV9(5,"boost");Zzj=ZV9(11,"Fatal Error");Zwb=ZV9(7,"implies");ZGd=ZV9(19,"open_argument_index");
Zyq=ZV9(1,Z33);ZSc=ZV9(12,"pointer_size");Zyk=ZV9(5,Zt3);Zih=ZV9(1,"\?");Zbn=ZV9(22,"\n   Bin directory:    ");ZAl=ZV9(48,"\n12.  Return to the previous menu\n\nYour choice [");
ZCo=ZV9(181,"The install/germ directory does not exist!\nDid you use a SmartEiffel archive from Loria\?\nIf not, you can download it at http://SmartEiffel.loria.fr\nand start the installation again.");
ZAo=ZV9(7,Zi3);ZEd=ZV9(14,"open_arguments");ZMp=ZV9(24,"4. Set the Sys directory");ZPa=ZV9(11,"BOOLEAN_REF");Zhm=ZV9(5,".serc");Zxg=ZV9(30,"Using the configuration file: ");
Z4m=ZV9(18,"C++ linker options");ZLg=ZV9(7,Zj3);Zwc=ZV9(22,"is_basic_expanded_type");Zwf=ZV9(5,"mieee");Z9b=ZV9(14,"TEXT_FILE_READ");
Z2o=ZV9(7,ZF3);Ztp=ZV9(95,"\n*** There was an error while trying to write the configuration file. Please verify its name.\n\n");Zpc=ZV9(6,"fourth");
Z3p=ZV9(0,Z23);Z9s();}void Z9s(void){Zrk=ZV9(66," does not exist or is not a directory:\n    this value is ignored.\n");ZJl=ZV9(15,"C compiler type");
ZLo=ZV9(50,"*** Could not create the bin directory: aborting.\n");ZBn=ZV9(15,"Could not open ");ZLp=ZV9(24,"3. Set the Bin directory");
Zun=ZV9(37,"Type <Enter> to go back to the menu: ");ZAf=ZV9(35,"\".\nCurrently handled system names:\n");Z4l=ZV9(41,"\n*** Please enter a nember between 1 and ");
ZKn=ZV9(8,"loadpath");ZVa=ZV9(8,"FUNCTION");Z6o=ZV9(13,ZO3);Zyc=ZV9(10,"is_default");ZCf=ZV9(11,"System is \"");ZCn=ZV9(148,"\n---------------------------------------------------------------------------\n\nYou did not install SmartEiffel. Are you sure you want to exit\? [y\174""N] ");
ZNl=ZV9(25,"\n*** Unknown C compiler.\n");ZOl=ZV9(15,"C compiler path");Zgl=ZV9(97,"SmartEiffel was not properly installed.\nPlease run the installer again to fix the installation.\n\n");
Z6f=ZV9(45,Zo3);Zrl=ZV9(33,"3.  Change the C compiler options");ZEp=ZV9(2,Zc3);Z1o=ZV9(21," contains an invalid ");Z0m=ZV9(19,Zy3);ZQb=ZV9(8,"add_last");
Zsh=ZV9(7,"General");ZIn=ZV9(21,"This extra loadpath (");ZCm=ZV9(18,ZV3);Zwh=ZV9(5,Zs3);ZSm=ZV9(12,"\nYou typed \"");Zmo=ZV9(53,"\nPlease enter the new value of the default C compiler");
Z4s=ZV9(11,"USERPROFILE");Zqc=ZV9(12,"from_pointer");ZYj=ZV9(35,"\nPlease enter the new value of the ");Zsc=ZV9(15,"generating_type");
ZDp=ZV9(278,"\n-- This section contains the default loadpaths used by this SmartEiffel\n-- installation.\n\n-- The key is a mere description and serves no other purpose,\n\n-- The value of the key is the path to a loadpath file.\n\n-- Note that the loadpath files ar read in the order given below.\n\n");
Z6m=ZV9(41,ZT3);ZCd=ZV9(12,"like Current");ZZn=ZV9(0,Z23);ZBq=ZV9(2,Zb3);ZHh=ZV9(7,Zp3);Z4b=ZV9(12,"REAL_GENERAL");ZYb=ZV9(8,"capacity");
Zpn=ZV9(28,"\n      SmartEiffel options: ");Z7o=ZV9(27," contains an invalid valid ");Zvr=ZV9(24,"Bad (empty\?) ascii code.");ZKg=ZV9(7,Zj3);
Zqg=ZV9(26,"The environment variable \"");ZEh=ZV9(33,ZA3);Zoo=ZV9(55,"\nPlease enter the new value of the default C++ compiler");Z4q=ZV9(27,"Unable to find executable \"");
Znk=ZV9(5,Zs3);Zas();}void Zas(void){ZCp=ZV9(11,"[Loadpath]\n");Zqo=ZV9(2,Z93);Z3c=ZV9(14,"collection_off");Zcp=ZV9(7,Zh3);ZFh=ZV9(4,Zx3);
ZOk=ZV9(4,ZU3);Ztr=ZV9(26,"Unknown special character.");Z3d=ZV9(15,"raise_exception");ZEm=ZV9(25,"/boot/beos/system/Tracker");Zqe=ZV9(9,ZS3);
ZDd=ZV9(6,"method");Zzh=ZV9(25,"#: config file corrupted!");Zzf=ZV9(29,"Unknown system name in file\n\"");Z9f=ZV9(0,Z23);Zin=ZV9(22,"\n      C linker path: ");
ZUo=ZV9(32,"                                ");Zif=ZV9(4,Zz3);Zvf=ZV9(1,"m");ZPc=ZV9(12,"Maximum_real");Z1d=ZV9(9,"put_16_le");Zzl=ZV9(40,"11. Change the SmartEiffel extra options");
ZHe=ZV9(8,ZQ3);Z2d=ZV9(9,"put_16_ne");ZTm=ZV9(48,"\".\nPlease enter a valid number between 1 and 6.\n");Z0d=ZV9(9,"put_16_be");Zmn=ZV9(29,"\n      C++ compiler options: ");
Zpa=ZV9(7,"POINTER");ZJe=ZV9(0,Z23);Znp=ZV9(287,"SmartEiffel The GNU Eiffel Compiler, Eiffel tools and libraries\nRelease 1.1 Release (Monday June 16th 2003) [Charlemagne]\nCopyright (C), 1994-2003 - INRIA - LORIA - UHP - Nancy 2 - FRANCE\nD.COLNET, S.COLLIN, O.ZENDRA, P.RIBET, C.ADRIAN - SmartEiffel@loria.fr\nhttp://SmartEiffel.loria.fr\n");
Z_f=ZV9(2,"-c");Z6b=ZV9(7,"REAL_64");Zef=ZV9(2,"-e");Zbl=ZV9(35,"\nCould not compute the path to the ");ZSg=ZV9(2,"-l");Z1g=ZV9(2,"/c");
ZQe=ZV9(2,Ze3);Zdg=ZV9(2,".o");Zcf=ZV9(2,"-o");Z5b=ZV9(7,"REAL_32");ZKk=ZV9(6,"Done.\n");ZPh=ZV9(22,"#1#2#3#4#5#6#7#8#9#\?.o");Z8e=ZV9(0,Z23);
ZXe=ZV9(2,"cl");ZTe=ZV9(2,"cc");ZZe=ZV9(2,"sc");ZGi=ZV9(15,"c_compiler_type");Zdb=ZV9(14,"UNICODE_STRING");ZM9=ZV9(11,"SmallEiffel");
Zsb=ZV9(7,"bit_xor");Z_a=ZV9(12,"NATIVE_ARRAY");Zbs();}void Zbs(void){Zap=ZV9(44,"\n*** Please enter a n integer between 1 and ");ZTp=ZV9(70,"*** Don\'t forget to set the \"SmartEiffel\" environment variable to\n*** ");
Zmb=ZV9(7,"bit_put");Zqb=ZV9(7,"bit_set");ZDo=ZV9(79,ZD3);ZGc=ZV9(6,"low_16");ZHc=ZV9(6,"low_32");Zxr=ZV9(36,"Decimal CHARACTER code out of range.");
Z6p=ZV9(9,"-no_split");ZOa=ZV9(5,"BIT_N");ZKi=ZV9(16,"c_linker_options");ZNe=ZV9(9,"lcc-win32");ZHi=ZV9(15,"c_compiler_path");ZMa=ZV9(5,"ARRAY");
Zyd=ZV9(13,"with_capacity");Z7f=ZV9(10,"\nlink/exe=");Zon=ZV9(27,"\n      C++ linker options: ");Zql=ZV9(30,"2.  Change the C compiler path");
Zgc=ZV9(11,"Double_bits");ZPi=ZV9(15,"cpp_linker_path");Z5q=ZV9(3,Zk3);ZRo=ZV9(12,Z43);Zur=ZV9(43,"Unexpected character in decimal ascii code.");
Zjd=ZV9(7,"storage");ZJc=ZV9(22,"Minimum_character_code");Z9c=ZV9(10,"c_inline_h");ZIr=ZV9(0,Z23);Zpe=ZV9(4,ZP3);ZGh=ZV9(8,ZQ3);Zvc=ZV9(12,"Integer_bits");
Zvl=ZV9(32,"7.  Change the C++ compiler path");Z8c=ZV9(10,"c_inline_c");ZMe=ZV9(0,Z23);Z8d=ZV9(17,"same_dynamic_type");ZXa=ZV9(15,"INTEGER_GENERAL");
Zsj=ZV9(6,"ensure");Z5s=ZV9(4,"HOME");Z1m=ZV9(20,"C++ compiler options");ZSk=ZV9(14,"loadpath value");Z_b=ZV9(9,"clear_all");Zsg=ZV9(41,"\" does not contain name of a valid file.\n");
Zco=ZV9(9,"\" C mode\n");Z5e=ZV9(0,Z23);Zee=ZV9(80," is not supported as a C++ compiler. I will continue, but expect some problems.\n");
Zbe=ZV9(0,Z23);Zm9=ZV9(10,"Removing \"");ZS9=ZV9(20,"SmartEiffelDirectory");Zmq=ZV9(13,"-boost -no_gc");Zsl=ZV9(28,"4.  Change the C linker path");
Zme=ZV9(4,Zg3);Zcs();}void Zcs(void){ZJn=ZV9(6,") is: ");ZPo=ZV9(28,"\n                (linker)   ");Z3s=ZV9(4,"USER");ZAr=ZV9(40,"Error inside multi-line manifest string.");
ZT9=ZV9(11,ZE3);Zrc=ZV9(12,"full_collect");ZSb=ZV9(8,"as_16_ne");Zqd=ZV9(10,"to_integer");ZP9=ZV9(15,"\" variable used");Zad=ZV9(7,"se_argv");
Zgm=ZV9(9,Zl3);Z9d=ZV9(7,"se_argc");Zyr=ZV9(47,"Unexpected character in hexadecimal ascii code.");Zna=ZV9(7,"BOOLEAN");ZO9=ZV9(10,"Obsolete \"");
ZGg=ZV9(6,Zv3);ZUa=ZV9(11,"FIXED_ARRAY");Zrg=ZV9(11,ZE3);ZOp=ZV9(74,"6. Manage the [Loadpath] section\n7. Return to the main menu\n\nYour choice [");
ZYe=ZV9(6,ZN3);ZKd=ZV9(6,"target");Zod=ZV9(12,"to_integer_8");ZNo=ZV9(17,"\n  - C compiler: ");ZQc=ZV9(11,"object_size");Zal=ZV9(11,"loadpath.se");
Zjc=ZV9(14,"element_sizeof");Z5f=ZV9(10,"OpenVMS_CC");Z7e=ZV9(24,"Selecting C++ compiler: ");Zwg=ZV9(66,"\" environment variable to a valid SmartEiffel configuration file.\n");
Ztd=ZV9(7,"to_real");Zze=ZV9(9,"SCOPTIONS");Zka=ZV9(9,"CHARACTER");Zxp=ZV9(5,"bin: ");Zpr=ZV9(4,"once");Z2c=ZV9(10,"collecting");ZBc=ZV9(11,"is_not_null");
Z_h=ZV9(4,"none");Z0f=ZV9(4,"dice");ZUp=ZV9(11,ZE3);ZHq=ZV9(26,"Integer constant expected.");Zcc=ZV9(11,"deep_memcmp");Zxf=ZV9(4,"cpml");
Znq=ZV9(9," -c_mode ");Zuj=ZV9(4,"loop");Zwm=ZV9(97,"\nDon\'t forget that rule: the <Enter> key ensures that SmartEiffel will eventually\nget installed.\n");
ZNp=ZV9(26,"5. Set the Short directory");ZXb=ZV9(6,"calloc");Z4o=ZV9(22," does not contain the ");Zjq=ZV9(25,"\" is not a valid choice.\n");
ZVg=ZV9(4,"mcr ");Zds();}void Zds(void){Z6k=ZV9(6,"-clean");Zyn=ZV9(5,ZM3);Zbb=ZV9(5,"TUPLE");Zlq=ZV9(6,"-boost");Zyl=ZV9(33,"10. Change the C++ linker options");
Z6d=ZV9(6,"second");ZJg=ZV9(9,Zl3);Z6c=ZV9(11,"conforms_to");Zbd=ZV9(15,"sedb_breakpoint");ZBd=ZV9(11,"last_result");Z4f=ZV9(4,"vpcc");
Zud=ZV9(12,"trace_switch");ZYa=ZV9(11,"INTEGER_REF");ZVp=ZV9(51,"\nPlease enter the new value of the operating system");Zec=ZV9(14,"deep_twin_from");
Zdc=ZV9(9,"deep_twin");Z2f=ZV9(4,"vbcc");Zyp=ZV9(5,"sys: ");ZIm=ZV9(3,"C:\\");ZVh=ZV9(30,"@linkit.com\ndelete linkit.com;");Zqn=ZV9(4,"\n   ");
Zfb=ZV9(8,"and then");Z_n=ZV9(3,".rc");ZZb=ZV9(14,"Character_bits");ZMk=ZV9(0,Z23);Z6g=ZV9(6,"][0-9]");Zfn=ZV9(24,"\n      C compiler type: ");
Zob=ZV9(3,"#<<");Zlp=ZV9(6,"_check");Zbp=ZV9(2,Z93);Zpb=ZV9(3,"#>>");ZMo=ZV9(46,"\nSummary of gathered options:\n  - C mode:     ");Z1l=ZV9(3,Zw3);
ZIl=ZV9(2,Za3);ZCk=ZV9(3,"lib");ZLa=ZV9(3,"ANY");Z1b=ZV9(11,"POINTER_REF");Zrn=ZV9(2,Zc3);ZEo=ZV9(84,"You are about to start the SmartEiffel installation.\nJust one last thing, though...\n");
ZMc=ZV9(19,"manifest_initialize");ZNa=ZV9(3,"BIT");Z0l=ZV9(44,". Return to the previous menu\n\nYour choice [");Z0b=ZV9(8,"PLATFORM");
Zlk=ZV9(3,ZB3);ZYg=ZV9(8,"Loadpath");Zs9=ZV9(6,"\" as \"");Zjn=ZV9(25,"\n      C linker options: ");ZEj=ZV9(7,"****** ");ZBp=ZV9(5,"tag: ");
Zlc=ZV9(5,"fifth");Zes();}void Zes(void){Zeb=ZV9(3,"and");Z_o=ZV9(2,Zd3);ZOi=ZV9(20,"cpp_compiler_options");ZNm=ZV9(98,"---------------------------------------------------------------------------\n\n   Operating system: ");
ZOg=ZV9(9,"system.se");Zld=ZV9(6,"to_bit");Zmc=ZV9(5,"first");Zsn=ZV9(24,"\n   Default C compiler: ");ZEb=ZV9(3,"not");Zvg=ZV9(57,"No default configuration file was found. Please set the \"");
ZYc=ZV9(3,"put");ZKb=ZV9(3,"\174""<<");ZLb=ZV9(3,"\174"">>");ZTc=ZV9(3,"pow");ZXm=ZV9(7,Zi3);Z5d=ZV9(7,"realloc");ZFd=ZV9(21,"open_argument_indices");
ZAm=ZV9(7,ZK3);Znh=ZV9(18," Ignore=93,194,304");ZOb=ZV9(3,"xor");Znc=ZV9(5,"floor");Zqr=ZV9(39,"Unexpected new line in manifest string.");
Zoc=ZV9(5,"flush");ZVj=ZV9(4,ZU3);Zce=ZV9(2,Z93);Z7n=ZV9(0,Z23);ZQa=ZV9(13,"CHARACTER_REF");ZEr=ZV9(27,"\' is defined more than once");
ZRa=ZV9(10,"DICTIONARY");Zcd=ZV9(13,"signal_number");ZRb=ZV9(5,"agent");ZDk=ZV9(5,"tools");ZWp=ZV9(13,"Bin directory");Zue=ZV9(7,ZC3);
ZRj=ZV9(0,Z23);Z_l=ZV9(49,ZR3);ZTb=ZV9(5,"atan2");ZBl=ZV9(39,"7. Change the SmartEiffel extra options");Z9p=ZV9(15,"loadpath number");
ZUh=ZV9(3,",-\n");Z8q=ZV9(9,ZH3);Zsp=ZV9(4," to ");ZPe=ZV9(6,"lcclnk");ZUb=ZV9(5,"blank");Z6h=ZV9(3,".00");ZWk=ZV9(79,ZD3);ZQo=ZV9(15,"\n\nHere we go!\n\n");
Zeq=ZV9(4,":\n  ");Zwl=ZV9(35,"8.  Change the C++ compiler options");ZOm=ZV9(29,"\n   Configuration file name: ");Zfs();}void Zfs(void){
Ztl=ZV9(31,"5.  Change the C linker options");Z7d=ZV9(8,"set_item");Zse=ZV9(3,Zr3);Zpl=ZV9(30,"1.  Change the C compiler type");Zsf=ZV9(3,".id");
ZIe=ZV9(7,Zp3);Zaq=ZV9(2,")\n");Zsr=ZV9(5,"]foo\"");Z9m=ZV9(2,Z93);Z5l=ZV9(2,Z93);ZZj=ZV9(2,":\n");Z0c=ZV9(5,"count");Zfq=ZV9(2,Za3);
Zte=ZV9(3,Zu3);ZXk=ZV9(2,". ");ZYk=ZV9(2,Zc3);ZKc=ZV9(14,"Minimum_double");Zmk=ZV9(3,ZG3);Z5g=ZV9(3,"[1-");Z3f=ZV9(3,"ccc");ZDl=ZV9(4,"1]: ");
ZHk=ZV9(107,"\nSmartEiffel is already installed with the current options. Do you want to\ninstall SmartEiffel again\? [no] ");ZGp=ZV9(2,"]\n");
ZCe=ZV9(3,"gcc");Zul=ZV9(32,"6.  Change the C++ compiler type");ZPp=ZV9(4,"2]: ");Zko=ZV9(28,"default C++ compiler options");ZDe=ZV9(3,"g++");
ZQp=ZV9(4,"7]: ");Zgq=ZV9(3,"\n\? ");Zpf=ZV9(3,"lcc");ZXc=ZV9(25,"print_all_run_time_stacks");Z8m=ZV9(41,ZT3);ZOh=ZV9(6,ZN3);ZFl=ZV9(4,"8]: ");
ZFc=ZV9(5,"low_8");Z1f=ZV9(2,Ze3);Z8f=ZV9(3,"tcc");Ziq=ZV9(1,"\"");ZEc=ZV9(5,"lower");ZRn=ZV9(1,"0");ZZf=ZV9(33,ZA3);ZSn=ZV9(1,"1");Zxd=ZV9(5,"upper");
ZRh=ZV9(6,"-s -d1");ZMj=ZV9(7,"Warning");ZQh=ZV9(11," StripDebug");Zmp=ZV9(15,"-sedb -no_strip");Zqa=ZV9(23,"NATIVE_ARRAY[CHARACTER]");
Zln=ZV9(26,"\n      C++ compiler path: ");Zgs();}void Zgs(void){ZLi=ZV9(19,"smarteiffel_options");ZGr=ZV9(44,".\nIts retained value will be the last read.\n");
Zbh=ZV9(16,Zm3);Zcm=ZV9(2,Z93);Zup=ZV9(356,"-- This is the configuration file of SmartEiffel, generated by the\n-- SmartEiffel installer.\n-- If you have any problems or questions, please:\n--   - either look at the SmartEiffel site (http://SmartEiffel.loria.fr)\n--   - or contact the SmartEiffel team (SmartEiffel@loria.fr)\n-- ======================================================================= --\n");
Zr9=ZV9(10,"Renaming \"");Zug=ZV9(4,"  - ");ZGm=ZV9(7,"/bin/ls");ZPm=ZV9(271,"\n\n1. Define the OS, the configuration file, the default directories and loadpaths\n2. Choose the C compilers and options for each C mode\n3. Display the configuration information\n4. Write the configuration file to disk\n5. Install SmartEiffel\n6. Exit\n\nh. Help\n\nYour choice [");
ZCl=ZV9(47,"\n8.  Return to the previous menu\n\nYour choice [");Zdp=ZV9(26,"Type <Enter> to continue.\n");Zrr=ZV9(67,"Extra blank or tab character removed in multi-line manifest string.");
ZTh=ZV9(11,"$ link/exe=");Z5o=ZV9(7,ZF3);Zop=ZV9(2854,"\nThis is the SmartEiffel installer.\n\nThis installer is here to help you. The options of the main menu are the six\nsteps that can be performed to install SmartEiffel. Once an action was perform-\ned, the menu proposes the next one.\n\nYou may have seen that, even starting the program, the menu already proposes\nsome option other than the first! Don\'t worry! It just means that the first\nsteps were automatically performed by the installer. You may always choose to\nchange them, by not choosing the default menu action.\n\nThe six steps are:\n\n- First, tell the installer which system SmartEiffel is to be installed upon;\n  also choose the directories SmartEiffel will be installed in, and the path\n  to the configuration file to be created. At last, you may add default\n  \"loadpath\" entries, meaning the files which describe where to find classes,\n  by default (this facility is here to help you insert third-party libraries).\n\n  Note that this step may be automatically performed. In that case, the OS was\n  automatically performe"
"d, the configuration file is given a default location,\n  the directories too, and the default loadpath files are those provided by\n  SmartEiffel.\n\n\n- Second, you may want to tell SmartEiffel which \"C modes\" are to be recognized.\n  SmartEiffel uses a C compiler as back-end; it means that you need a C compiler\n  installed on your machine.\n\n  The C modes are ways to tailor how the C compiler must behave; each C modes is\n  a C compiler, its path, and its options, and extra options for SmartEiffel to\n  use.\n\n  Let me explain in more details:\n\n  SmartEiffel disposes of many options to tailor how instrumented your execut-\n  able will be; wich assertions to check, should SmartEiffel add a debugger,\n  should SmartEiffel generate the \"debug\" statements, and so on.\n\n  Each \"assertion level\": boost, require_check, and so on, is associated with\n  a default C mode, named after the level. A typical configuration would associ-\n  ate the \"boost\" level with a highly optimizing C compiler (such as \"gcc -O3\");\n  it would, on the "
"other hand, tell SmartEiffel to no strip the executable in\n  debug mode (and why not adding the SmartEiffel Debugger) while asking the C\n  compiler to generate the symbol tables.\n\n\n- Third, you can verify what you entered in the two previous sections. If all is\n  ok, then you are ready to install SmartEiffel.\n\n\n- Fourth, the configuration file is to be written at its chosen location.\n\n\n- Fifth, the SmartEiffel tools are installed! They use the configuration file to\n  generate themselves; just before compiling the tools, you will be asked which\n  C mode should be used for that very task; the default mode is \"boost\".\n\n\n- Sixth, last but not least: you can now leave the installer; you are now ready\n  to enjoy SmartEiffel!\n\n\n        Happy SmartEiffelling :o)\n\n\nType <Enter> to go back to the menu: ");
Zhq=ZV9(16,Zm3);Z_k=ZV9(28,". Remove an extra loadpath\n\n");Zpd=ZV9(13,"to_integer_16");Zrd=ZV9(13,"to_integer_32");Zjh=ZV9(0,Z23);ZKe=ZV9(0,Z23);
Zzp=ZV9(7,"short: ");ZIk=ZV9(14,"OK, aborting.\n");ZUc=ZV9(5,"print");ZZc=ZV9(5,"put_0");Z_c=ZV9(5,"put_1");ZFr=ZV9(17," in the section [");
Zmh=ZV9(10," Data=Auto");ZEk=ZV9(8,"tutorial");Z3k=ZV9(16,"-clean -no_split");Z4p=ZV9(2,Zd3);Zwp=ZV9(635,"\n-- This section contains some general-purpose keys. They describe how is the\n-- SmartEiffel distribution arranged, and on which operating system it was\n-- installed.\n\n-- The \'bin\' key is the path to the directory that contains the SmartEiffel\n-- directory. It is used by \'compile\' to find \'compile_to_c\'.\n\n-- The \'sys\' directory is used to find the C and Java files used by the\n-- compilers.\n\n-- The \'short\' directory is used by the \'short\' utility to fotmat the output.\n\n-- The \'os\' key tells on which system SmartEiffel is installed on.\n\n-- At last, \'tag\' gives the version of install configuration (used only by the\n-- installer)\n\n");
Zgf=ZV9(4," To ");Z6n=ZV9(0,Z23);Zeo=ZV9(27,". Set the default compilers");Zel=ZV9(78,Z83);ZJi=ZV9(13,"c_linker_path");Zkd=ZV9(5,"third");
Z3o=ZV9(13,ZO3);Zrp=ZV9(9,"Renaming ");Ztg=ZV9(71,"A valid configuration file was not found in all its default locations:\n");Zqk=ZV9(5,"\n*** ");
ZBb=ZV9(1,"*");Zib=ZV9(1,"&");ZHb=ZV9(1,"+");Zzb=ZV9(1,"-");ZMb=ZV9(1,"/");Zyb=ZV9(1,"<");Ztb=ZV9(1,"=");Zvb=ZV9(1,">");Zhs();}void Zhs(void){
Zgb=ZV9(1,Z53);Zdn=ZV9(22,"\n   Short directory:  ");ZJb=ZV9(1,"^");Zgn=ZV9(24,"\n      C compiler path: ");ZIi=ZV9(18,"c_compiler_options");
Zra=ZV9(10,"INTEGER_16");Zja=ZV9(10,"INTEGER_32");Zsa=ZV9(10,"INTEGER_64");Zhd=ZV9(9,"std_input");ZWc=ZV9(20,"print_run_time_stack");
Z5c=ZV9(17,"collector_counter");ZY9=ZV9(13," is not set.\n");ZIh=ZV9(4,".lnk");Zeg=ZV9(4,".obj");ZMg=ZV9(9,ZJ3);Z2m=ZV9(15,"C++ linker path");
Z2q=ZV9(0,Z23);ZMf=ZV9(79,"\nThe type of your operating system was automatically  computed. Please verify.\n");ZFa=ZV9(3,").\n");ZTa=ZV9(10,"EXCEPTIONS");
ZRp=ZV9(39,Zn3);Zzq=ZV9(2,Zb3);Zlh=ZV9(9," Data=Far");Zzc=ZV9(16,"is_expanded_type");ZFe=ZV9(4,Zx3);Z5h=ZV9(4,".exe");ZAc=ZV9(8,"is_equal");
Zff=ZV9(4,Zz3);Z5a=ZV9(13,"System call \"");ZAk=ZV9(9,Zf3);Z9q=ZV9(9,"default: ");ZFj=ZV9(2,"  ");ZRq=ZV9(21,"End of text expected.");
Zoa=ZV9(6,"STRING");ZAq=ZV9(1,Z33);Zxk=ZV9(5,Zt3);ZJp=ZV9(34,"1. Set the configuration file name");ZTn=ZV9(55,"The configuration file is invalid; it will be ignored.\n");
ZBo=ZV9(4,"germ");Zno=ZV9(170,"\nThis compiler has no known C++ capabilities.\n In order to compile C++ programs, please also pick a C++ compiler.\n\nType <Enter> if you don\'t know what this is all about.\n");
Zgd=ZV9(9,"std_error");Zwn=ZV9(6,"SE.CFG");Zma=ZV9(6,"DOUBLE");Znn=ZV9(24,"\n      C++ linker path: ");ZYn=ZV9(0,Z23);Z6q=ZV9(4,"cpt ");
Zmd=ZV9(12,"to_character");ZZl=ZV9(17,"C++ compiler path");Ztj=ZV9(9,"invariant");ZAp=ZV9(4,"os: ");Zis();}void Zis(void){Z3b=ZV9(9,"PROCEDURE");
Zia=ZV9(7,"INTEGER");Zuq=ZV9(49,"                                                 ");Zjo=ZV9(26,"default C compiler options");ZN9=ZV9(20,"SmallEiffelDirectory");
Ztc=ZV9(9,"generator");Z7m=ZV9(2,Z93);Z1n=ZV9(57,"This directory does not exist; should I create it\? [Y\174""n] ");ZOo=ZV9(28,"\n  - C options:  (compiler) ");
Z9n=ZV9(105,"\n---------------------------------------------------------------------------\n   Configuration file name: ");Zid=ZV9(10,"std_output");
Z5n=ZV9(0,Z23);Zae=ZV9(0,Z23);Znd=ZV9(9,"to_double");ZXl=ZV9(17,"C++ compiler type");ZSa=ZV9(10,"DOUBLE_REF");ZLm=ZV9(59,"\n*** This section name is reserved. Please choose another.\n");
Z2b=ZV9(9,"PREDICATE");ZHo=ZV9(39,"\n*** Please choose an existant C mode.\n");Z9e=ZV9(0,Z23);Zfm=ZV9(4,"root");ZZk=ZV9(24,". Add an extra loadpath\n");
ZRe=ZV9(2,Zd3);Znf=ZV9(2,".h");ZSh=ZV9(10,"linkit.com");Zho=ZV9(42,"Please enter a valid number between 1 and ");Z4d=ZV9(9,"Real_bits");
ZAd=ZV9(7,"Current");ZQi=ZV9(18,"cpp_linker_options");Zoh=ZV9(18," NoVersion NoIcons");ZNk=ZV9(12,Z43);ZSl=ZV9(49,ZR3);Z4c=ZV9(13,"collection_on");
ZIj=ZV9(7,"------\n");Zzk=ZV9(9,Zf3);ZFg=ZV9(6,Zv3);ZVb=ZV9(12,"Boolean_bits");ZW9=ZV9(23,"Environment variable $\173""");ZDm=ZV9(18,"s:startup-sequence");
ZIp=ZV9(78,Z83);ZYl=ZV9(27,"\n*** Unknown C++ compiler.\n");Zga=ZV9(4,"NONE");Z7q=ZV9(2,Z73);Zre=ZV9(5,Zq3);Zxl=ZV9(30,"9.  Change the C++ linker path");
ZRl=ZV9(13,"C linker path");ZNc=ZV9(22,"Maximum_character_code");Z8b=ZV9(7,"ROUTINE");Zla=ZV9(4,"REAL");Zvd=ZV9(20,"truncated_to_integer");
Zjs();}void Zjs(void){ZLc=ZV9(12,"Minimum_real");Zic=ZV9(13,"die_with_code");ZKp=ZV9(27,"2. Set the operating system");Zyh=ZV9(12,"Unknown os \"");
Zkq=ZV9(24,"                        ");Zio=ZV9(2,Z93);ZQl=ZV9(18,"C compiler options");Zcn=ZV9(22,"\n   Sys directory:    ");Zcl=ZV9(14," loadpath.se\n\n");
Zcb=ZV9(4,"TYPE");Zao=ZV9(97,"\n---------------------------------------------------------------------------\nDefault compiler is ");ZHg=ZV9(7,ZK3);
ZNi=ZV9(17,"cpp_compiler_path");Zvm=ZV9(948,"\nHello!\n\nThank you for choosing SmartEiffel.\n\nI\'m here to help you install your software. Many default options have been set\nfor you; the simplest way to install SmartEiffel is to keep pressing the\n<Enter> key as long as I ask anything.\n\nOf course you can change the options I set; it\'s just a matter of chosing items\nin the menus, and you\'ll see you can greatly customize your SmartEiffel\ninstallation. A golden rule is, just pressing <Enter> always works, and\ninexorably leads towards the actual SmartEiffel installation. When no default is\nprovided (between brackets), the <Enter> key will just leave everything\nunchanged and get you back to the previous menu.\n\nAs training, you\'ll be asked to press the <Enter> key to gain access to the\nmain menu ;-)\n\nIf you have problems, please contact the SmartEiffel team:\n  - either by mail:  SmartEiffel@loria.fr\n  - either by using the bugs database: http://SmartZilla.loria.fr\n\n\nPress the <Enter> key: ");
ZFm=ZV9(11,"/bin/ls.exe");Z0g=ZV9(10,"-ansi -x c");Zdo=ZV9(23,". Create a new C mode\n\n");Zfl=ZV9(46,"Thank you for installing SmartEiffel. Enjoy!\n\n");
ZIg=ZV9(18,ZV3);ZDr=ZV9(9,"The key \'");ZLd=ZV9(4,"Void");Zfc=ZV9(7,"dispose");}void*Zle(int ZPr,...){T42*m;Zks pa;T0**s;m=Zh(sizeof(*m));
*m=M42;if(ZPr){s=Zh(ZPr*sizeof(*s));m->Zl1=s;m->Z11=ZPr;m->ZV2=1;m->Zm1=ZPr;Zls(pa,ZPr);while(ZPr--){*(s++)=Zms(pa,T0*);}Zns(pa);}else{
m->Zl1=Zo;m->Z11=0;m->ZV2=1;m->Zm1=0;}return m;}T0*ZP8(T0*C,T2 a1){T0*R;{Tid id=((T0*)C)->id;if(id<=42){R=(ZU7(((T42*)C),a1));}else{R=((((((T47*)C))->Zl1))[a1]);
}}return R;}T2 ZQ8(T0*C){T2 R;{Tid id=((T0*)C)->id;if(id<=42){R=(((((T42*)C))->ZV2));}else{R=(ZE5(0));}}return R;}T6 ZS8(T0*C,T2 a1){
T6 R;{Tid id=((T0*)C)->id;if(id<=42){R=(T6)(ZV7(((T42*)C),a1));}else{R=(T6)(ZH7(((T47*)C),a1));}}return R;}void Zt7(T0*C,T0*a1){{Tid id=((T0*)C)->id;
if(id<=42){Z08(((T42*)C),a1);}else{ZL7(((T47*)C),a1);}}}T0*ZK8(T0*C,T2 a1){T0*R;{Tid id=((T0*)C)->id;if(id<=62){R=(Zd8(((T62*)C),a1));
}else{R=(ZY8(((T66*)C),a1));}}return R;}T0*ZJr(T0*C){T0*R;{Tid id=((T0*)C)->id;if(id<=62){R=(ZJ7(((T47*)(((((T62*)C))->Z61)))));}else{
R=(ZV8(((T66*)C)));}}return R;}T2 Zep(T0*C,T0*a1){T2 R;{Tid id=((T0*)C)->id;if(id<=62){R=(Zb8(((T62*)C),a1));}else{R=(ZW8(((T66*)C),a1));
}}return R;}T0*ZLl(T0*C,T0*a1){T0*R;{Tid id=((T0*)C)->id;if(id<=62){R=(Zf8(((T62*)C),a1));}else{R=(Z_8(((T66*)C),a1));}}return R;}T0*Zfp(T0*C,T0*a1){
T0*R;{Tid id=((T0*)C)->id;if(id<=62){R=(Zk8(((T62*)C),a1));}else{R=(Z09(((T66*)C),a1));}}return R;}void ZRi(T0*C,T0*a1,T0*a2){{Tid id=((T0*)C)->id;
if(id<=62){Zs8(((T62*)C),a1,a2);}else{Z49(((T66*)C),a1,a2);}}}void Z2p(T0*C,T0*a1){{Tid id=((T0*)C)->id;if(id<=62){Zt8(((T62*)C),a1);
}else{Z59(((T66*)C),a1);}}}T0*ZTi(T0*C,T0*a1){T0*R;{Tid id=((T0*)C)->id;if(id<=62){R=(Zu8(((T62*)C),a1));}else{R=(Z69(((T66*)C),a1));
}}return R;}void Z2h(T0*C){{Tid id=((T0*)C)->id;if(id<=70){ZI8(((T70*)C));}else{ZN8(((ZJ*)C));}}}T0*Z1h(T0*C){T0*R;{Tid id=((T0*)C)->id;
if(id<=70){R=(ZJ8(((T70*)C)));}else{R=(ZO8(((ZJ*)C)));}}return R;}T6 ZZg(T0*C){T6 R;{Tid id=((T0*)C)->id;if(id<=70){R=(T6)(ZM8(((T70*)C)));
}else{R=(T6)(ZR8(((ZJ*)C)));}}return R;}void ZUn(T0*C){{Tid id=((T0*)C)->id;if(id<=70){((((T70*)(((T70*)C))))->Z72)=(ZE5(1));}else{ZT8(((ZJ*)C));
}}}
#ifdef __cplusplus
}
#endif

