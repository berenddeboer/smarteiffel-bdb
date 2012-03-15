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
}return Zm;}int Z_(T78 o1,T78 o2){return Z01(&o1,&o2,sizeof(o1));}int Z31(T97 o1,T97 o2){return Z01(&o1,&o2,sizeof(o1));}int Z61(T50 o1,T50
o2){return Z01(&o1,&o2,sizeof(o1));}T78 M78={Zo,Zo,0};T23 M23=Zo;T56 M56=0;T65 M65={65,Zo,0,0,0,Zo,0,Zo};T85 M85=Zo;T87 M87={0};T90 M90=0;
T38 M38={0,0,0,Zo,0,0,0,0};T86 M86={Zo,Zo};T96 M96={{Zo,Zo,0},Zo};T71 M71={Zo,Zo,Zo};T49 M49={49,Zo,0,0};T77 M77={0,0,0};T12 M12={{Zo,Zo},Zo,0,0,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,0,0,0};
ZF ZX1={Zo,0,0};ZH ZY1={Zo,0,0};T35 M35=0;T51 M51={0,0};T57 M57={Zo,0,0,0,Zo,Zo,0,0,0,0};T97 M97={{Zo,Zo,0},Zo};T39 M39={Zo,Zo,Zo,Zo,Zo,0,0,Zo,Zo,{Zo,Zo},0,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo};
T92 M92={0,Zo,Zo};ZJ Ze2={Zo,0,0};T74 M74={74,Zo,0};T7 M7={Zo,0,0};T55 M55={0};T89 M89={Zo,0,0,0,Zo,0};ZL Zi2={116,Zo,0};T50 M50={Zo,Zo};
T88 M88={0,0,0};T36 M36=0;T76 M76={Zo,Zo,0,Zo};T47 M47={Zo,0,{Zo,Zo},Zo};T69 M69={69,Zo,0,0,0,Zo,0};ZN Zs2={Zo,0,0,Zo,Zo};T53 M53={0,0,Zo,0,Zo,0,0,0,{{Zo,Zo,0},Zo},Zo,0,Zo,Zo,Zo,Zo,Zo};
ZD Z23={Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,0,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,Zo,0,0};ZB Z33={Zo,Zo,Zo};ZP Z43={Zo,0,0,0};T44 M44={44,Zo,0,0,0};
T64 M64={Zo,0,0,0,Zo};T94 M94=Zo;T67 M67={Zo,Zo,Zo};T79 M79={Zo,0,0};T37 M37={Zo,Zo,0,0,0};ZR Z93={Zo,Zo,0,0,Zo};T98 M98={{Zo,Zo,0},0,0,Zo};
T32 M32={0,Zo,0};T52 M52=Zo;char*Zd3="";char*Ze3=".";char*Zf3="compile_to_c";char*Zg3="@";char*Zh3="Cygwin";char*Zi3=" (";char*Zj3="\n---------------------------------------------------------------------------\n\n";
char*Zk3=".\n";char*Zl3=", ";char*Zm3="..";char*Zn3=": ";char*Zo3=".c";char*Zp3="-s";char*Zq3="-pipe -O2";char*Zr3="UNIX";char*Zs3="Windows";
char*Zt3="install";char*Zu3="\\SE.CFG";char*Zv3="/lang/eiffel/.serc12";char*Zw3="\".\n";char*Zx3="                ";char*Zy3="Please enter a number between 1 and 7.\n";
char*Zz3="/.serc12";char*ZA3="cc/warning=disable=(embedcomment,longextern) ";char*ZB3="-x none";char*ZC3="Amiga";char*ZD3="DOS";char*ZE3="short";
char*ZF3="-pipe";char*ZG3="OS2";char*ZH3="]: ";char*ZI3="-x c";char*ZJ3="SmartEiffel options";char*ZK3="/fe=";char*ZL3="...This is a local once buffer...";
char*ZM3="bin";char*ZN3="OpenVMS";char*ZO3="\n\n---------------------------------------------------------------------------\n\n";char*ZP3="SmartEiffel";
char*ZQ3=" key.\n\n";char*ZR3="sys";char*ZS3="undefined";char*ZT3="Elate";char*ZU3="C:\\SE.CFG";char*ZV3="/sys/rc";char*ZW3="compile";
char*ZX3="clean";char*ZY3=" /link";char*ZZ3="\nThe RC file ";char*Z_3="BeOS";char*Z04="-x \'c++\'";char*Z14="*** This file does not exist or is not readable.\n";
char*Z24="Macintosh";char*Z34="\n*** Please enter a number between 1 and ";char*Z44="/etc/serc12";char*Z54=" -o ";void Zu(void){Zs(Zt,"Eiffel program crash at run time.\n");
Zs(Zt,"No trace when using option \"-boost\"\n");}void Z64(int sig){Z74("Received signal %d.\n",sig);Zu();Zv(Zw);}
#ifdef WIN32
#define SIMULATED_MODE
typedef struct Zn4{Zo4 Zp4;Zq4 Zr4;int Zs4;char*Zt4;}Zu4;static Zu4*Zv4(char*Za4){int len=Zw4((char*)Za4);char*Zt4=Zh(len+5);Zu4*Zm=Zh(sizeof(Zu4));
Zt4=Zx4(Zt4,(char*)Za4);if(Zt4[len-1]!='\\')Zt4[len++]='\\';Zt4[len++]='*';Zt4[len++]='.';Zt4[len++]='*';Zt4[len++]=0;Zm->Zp4=Zy4(Zt4,&(Zm->Zr4));
if(Zm->Zp4==Zz4){ZA4(Zt4);ZA4(Zm);return Zo;}else{Zm->Zt4=Zt4;}Zm->Zs4=0;return Zm;}static void*ZB4(Zu4*Zc4){if(Zc4->Zs4){if(ZC4(Zc4->Zp4,&(Zc4->Zr4))){
Zc4->Zs4=1;return Zc4;}else{return Zo;}}else{Zc4->Zs4=1;return Zc4;}}
#define simulated_get_entry_name(x) ((x)->data.cFileName)
static int ZD4(Zu4*Zc4){ZE4(Zc4->Zp4);ZA4(Zc4->Zt4);ZA4(Zc4);return 0;}char*ZF4(char*ZG4,int ZH4);int ZI4(const char*ZG4);int ZJ4(const
char*Zl4);int ZK4(const char*Zl4);
#define simulated_getcwd(x, y) getcwd(x, y)
#define simulated_chdir(x) chdir(x)
#define simulated_rmdir(x) rmdir(x)
int ZL4(const char*Zl4,int ZM4){ZJ4(Zl4);return 0;}
#endif
#ifdef AMIGA
#define SIMULATED_MODE
#include <exec/types.h>
#include <dos/dos.h>
#include <dos/dostags.h>
#include <proto/exec.h>
#include <proto/dos.h>
typedef struct Zn4{struct ZN4*ZO4;ZP4 ZQ4;}Zu4;static void ZR4(Zu4*dir){if(dir!=Zo){if(dir->ZQ4!=Zo){ZS4(dir->ZQ4);}if(dir->ZO4!=Zo){
ZT4(ZU4,dir->ZO4);}ZA4(dir);}}static Zu4*Zv4(char*Za4){ZV4 ok=ZW4;Zu4*Zm=Zh(sizeof(Zu4));if(Zm!=Zo){Zm->ZQ4=Zo;Zm->ZO4=(struct ZN4*)ZX4(ZU4,Zo);
if(Zm->ZO4!=Zo){Zm->ZQ4=ZY4(Za4,ZZ4);if(Zm->ZQ4!=Zo){ok=(Z_4(Zm->ZQ4,Zm->ZO4)!=Z05);if(ok){ok=(Zm->ZO4->Z15>=0)&&(Zm->ZO4->Z15!=Z25);
}}}}if(!ok){ZR4(Zm);Zm=Zo;}return Zm;}static void*ZB4(Zu4*Zc4){ZV4 ok;Zu4*Zm=Zo;ok=(Z35(Zc4->ZQ4,Zc4->ZO4)!=Z05);if(ok){Zm=Zc4;}return(void*)Zm;
}
#define simulated_get_entry_name(entry) ((entry)->info->fib_FileName)
static int ZD4(Zu4*Zc4){ZR4(Zc4);return 0;}static Z94 Z45(char*ZG4,Zi Z55){Z94 Zm=Zo;ZP4 ZQ4=ZY4("",ZZ4);if(ZQ4!=Zo){if(Z65(ZQ4,ZG4,Z55)!=Z05){
Zm=(Z94)ZG4;}ZS4(ZQ4);}return Zm;}static int Z75(char*Z85){int Zm=-1;ZP4 ZQ4=ZY4(Z85,ZZ4);if(ZQ4!=Zo){ZP4 Z95=Za5(ZQ4);if(Zb5(Z85)){ZS4(Z95);
Zm=0;}else{Za5(Z95);}}return Zm;}static void Zc5(char*Za4,Zi*Zd5,ZV4*Ze5){*Zd5=Zw4(Za4);if((*Zd5>0)&&(Za4[*Zd5-1]=='/')){*Ze5=Zf5;Za4[*Zd5-1]='\0';
}else{*Ze5=ZW4;}}static void Zg5(char*Za4,Zi*Zd5,ZV4*Ze5){if(*Ze5){Za4[*Zd5-1]='/';}}static int ZL4(char*Zl4,int Zh5){ZP4 ZQ4;int Zm=-1;
Zi Zi5;ZV4 Zj5;Zc5(Zl4,&Zi5,&Zj5);ZQ4=Zk5(Zl4);if(ZQ4!=Zo){ZS4(ZQ4);Zm=0;}Zg5(Zl4,&Zi5,&Zj5);return Zm;}static int Zl5(char*Zl4){int Zm=-1;
Zi Zi5;ZV4 Zj5;Zc5(Zl4,&Zi5,&Zj5);if(Zm5(Zl4)){Zm=0;}Zg5(Zl4,&Zi5,&Zj5);return Zm;}
#endif
Z94 Z84(Z94 Za4){
#ifndef SIMULATED_MODE
return(Zn5(((char*)Za4)));
#else
return(Zv4(((char*)Za4)));
#endif
}Z94 Zb4(Z94 Zc4){
#ifndef SIMULATED_MODE
return Zo5((DIR*)Zc4);
#else
return ZB4((Zu4*)Zc4);
#endif
}Z94 Zd4(Z94 Ze4){
#ifndef SIMULATED_MODE
return(((struct Zp5*)Ze4)->Zq5);
#else
return Zr5((Zu4*)Ze4);
#endif
}Zf4 Zg4(Z94 Zc4){int Zs5;
#ifndef SIMULATED_MODE
Zs5=(Zt5((DIR*)Zc4)==0);
#else
Zs5=(ZD4((Zu4*)Zc4)==0);
#endif
return((Zf4)(Zs5?1:0));}Z94 Zh4(void){static char*buf=Zo;
#ifdef WIN32
static int Zj=0;
#else
static Zi Zj=0;
#endif
int Zs5;if(buf==Zo){Zj=256;buf=(char*)Zh(Zj);}
#ifndef SIMULATED_MODE
Zs5=(ZF4(buf,Zj)!=Zo);
#else
Zs5=(Z45(buf,Zj)!=Zo);
#endif
if(Zs5){return buf;}else{ZA4(buf);Zj=Zj*2;buf=(char*)Zh(Zj);return Zh4();}}Zf4 Zi4(Z94 Zj4){int Zs5;
#ifndef SIMULATED_MODE
Zs5=(ZI4((char*)Zj4));
#else
Zs5=Z75((char*)Zj4);
#endif
return((Zf4)(Zs5==0?1:0));}Zf4 Zk4(Z94 Zl4){int Zs5;
#ifndef SIMULATED_MODE
Zs5=(ZJ4((char*)Zl4,0777));
#else
Zs5=ZL4((char*)Zl4,0777);
#endif
return((Zf4)(Zs5==0?1:0));}Zf4 Zm4(Z94 Zl4){int Zs5;
#ifndef SIMULATED_MODE
Zs5=ZK4((char*)Zl4);
#else
Zs5=Zl5((char*)Zl4);
#endif
return((Zf4)(Zs5==0?1:0));}
#if defined __USE_POSIX || defined __unix__ || defined _POSIX_C_SOURCE
#else
int Zu5(char*ZG4,int Zj){int c;c=Zv5(Zw5);if(c==EOF)return 0;*ZG4=(char)c;return 1;}
#endif
void Zx5(Z94 Zy5,Z94 Zz5){Zi ZA5=Zw4((char*)Zy5);Zi ZB5=Zw4((char*)Zz5);char*v;v=Zh(ZA5+ZB5+2);ZC5(v,((char*)Zy5),ZA5);v[ZA5]='=';ZC5(v+ZA5+1,((char*)Zz5),ZB5);
v[ZA5+1+ZB5]='\0';ZD5(v);}T6 ZE5(T8 C){T6 R=0;R=((T6)(!((Zo!=C))));return R;}T6 ZF5(T6 C,T6 a1){T6 R=0;R=((T6)((T6)((C)&&((T6)(a1)))));
return R;}T6 ZG5(T6 C){T6 R=0;R=((T6)((C)==(0)));return R;}T6 ZH5(T6 C,T6 a1){T6 R=0;R=((T6)((T6)((C)||((T6)(a1)))));return R;}T6 ZI5(T3
C){T6 R=0;if((((unsigned)((C)))>=((unsigned)(((T3)'0'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'9'))))));}return R;}T6 ZJ5(T3
C){T6 R=0;{int z1=(C);switch(z1){case 0:case 9:case 10:case 12:case 13:case 32:R=((T6)(1));break;}}return R;}T6 ZK5(T3 C){T6 R=0;if(ZI5(C)){
R=((T6)(1));}else if((((unsigned)((C)))>=((unsigned)(((T3)'a'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'f'))))));}else if((((unsigned)((C)))>=((unsigned)(((T3)'A'))))){
R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'F'))))));}return R;}T6 ZL5(T3 C){T6 R=0;if((((unsigned)((C)))>=((unsigned)(((T3)'0'))))){
R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'9'))))));}return R;}T6 ZM5(T3 C,T3 a1){T6 R=0;R=((T6)((Z2)((ZN5(C))<=(ZN5(a1)))));return
R;}T1 ZO5(T3 C){T1 R=0;R=(Z1)(((((ZP5)(ZN5(C)))))-(ZQ5(48)));return R;}T6 ZR5(T3 C){T6 R=0;if((((unsigned)((C)))>=((unsigned)(((T3)'a'))))){
R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'z'))))));}else if((((unsigned)((C)))>=((unsigned)(((T3)'A'))))){R=((T6)((((unsigned)((C)))<=((unsigned)(((T3)'Z'))))));
}return R;}T6 ZS5(T3 C,T3 a1){T6 R=0;if(((C))==(a1)){R=((T6)(1));}else{{int z1=ZN5(C);switch(z1){case 65:case 66:case 67:case 68:case
69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case
86:case 87:case 88:case 89:case 90:R=((T6)((ZN5(C))==((Z2)(((ZN5(a1)))-(ZQ5(32))))));break;case 97:case 98:case 99:case 100:case 101:
case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:
case 117:case 118:case 119:case 120:case 121:case 122:R=((T6)((ZN5(C))==((Z2)(((ZN5(a1)))+(ZQ5(32))))));break;}}}return R;}T1 ZT5(T3 C){
T1 R=0;R=(Z1)(((((ZP5)(ZN5(C)))))-(ZQ5(48)));return R;}T3 ZU5(T3 C){T3 R=0;if((Z2)((ZN5(C))<(ZQ5(97)))){R=(C);}else if((Z2)((ZN5(C))>(ZQ5(122)))){
R=(C);}else{R=((T3)((Z2)(((ZN5(C)))-(ZQ5(32)))));}return R;}T6 ZV5(T3 C,T3 a1){T6 R=0;R=((T6)((Z2)((ZN5(C))>=(ZN5(a1)))));return R;}T3
ZW5(T3 C){T3 R=0;if((Z2)((ZN5(C))<(ZQ5(65)))){R=(C);}else if((Z2)((ZN5(C))>(ZQ5(90)))){R=(C);}else{R=((T3)((Z2)(((ZN5(C)))+(ZQ5(32)))));
}return R;}T1 ZX5(T3 C){T1 R=0;R=((ZP5)(ZN5(C)));if((Z2)((ZN5(C))<(ZN5(((T3)'A'))))){R=(Z1)(((R))-(ZQ5(48)));}else if((Z2)((ZN5(C))<(ZN5(((T3)'a'))))){
R=(Z1)(((R))-(ZQ5(55)));}else{R=(Z1)(((R))-(ZQ5(87)));}return R;}T3 ZY5(T1 C){T3 R=0;R=((T3)((Z2)((((T10)((C))))+(ZN5(((T3)'0'))))));
return R;}void ZZ5(T1 C,T0*a1){T1 Z_5=0;T2 Z06=0;T2 Z16=0;if(((C))==(ZQ5(0))){Z26(((T7*)a1),((T3)'0'));}else{if((Z1)(((C))>(ZQ5(0)))){
Z06=(Z3)(((((((T7*)a1))->Z91)))+(ZQ5(1)));Z_5=(C);while(!((Z_5)==(ZQ5(0)))){Z26(((T7*)a1),ZY5((Z1)((Z_5)%(ZQ5(10)))));Z_5=(Z1)((Z_5)/(ZQ5(10)));
}}else{Z26(((T7*)a1),((T3)'\055'));Z06=(Z3)(((((((T7*)a1))->Z91)))+(ZQ5(1)));Z_5=(C);while(!((Z_5)==(ZQ5(0)))){Z26(((T7*)a1),ZY5(-((Z1)((Z_5)%(ZQ5(10))))));
Z_5=(Z1)((Z_5)/(ZQ5(10)));}}Z16=((((T7*)a1))->Z91);while(!((Z3)((Z06)>=(Z16)))){Z36(((T7*)a1),Z06,Z16);Z16=(Z3)(((Z16))-(ZQ5(1)));Z06=(Z3)(((Z06))+(ZQ5(1)));
}}}T6 Z46(T2 C,T1 a1){T6 R=0;R=((T6)((((((C))>>(a1))&ZQ5(1)))!=(ZQ5(0))));return R;}T6 Z56(T2 C){T6 R=0;R=((T6)((((C)&ZQ5(1)))==(ZQ5(0))));
return R;}T2 Z66(T2 C,T2 a1){T2 R=0;if((Z3)((C)>=(a1))){R=C;}else{R=a1;}return R;}T6 Z76(T2 C,T2 a1,T2 a2){T6 R=0;R=((T6)((T6)(((Z3)((C)>=(a1)))&&((T6)((Z3)((C)<=(a2)))))));
return R;}T2 Z86(T2 C,T2 a1){T2 R=0;if((Z3)((C)<=(a1))){R=C;}else{R=a1;}return R;}T6 Z96(T2 C){T6 R=0;R=((T6)((((C)&ZQ5(1)))!=(ZQ5(0))));
return R;}T3 Za6(T2 C){T3 R=0;R=((T3)((Z3)((((C)))+((T2)(ZN5(((T3)'0')))))));return R;}void Zb6(T2 C,T0*a1){T2 Z_5=0;T2 Z06=0;T2 Z16=0;
if(((C))==(ZQ5(0))){Z26(((T7*)a1),((T3)'0'));}else{if((Z3)(((C))>(ZQ5(0)))){Z06=(Z3)(((((((T7*)a1))->Z91)))+(ZQ5(1)));Z_5=(C);while(!((Z_5)==(ZQ5(0))))
{Z26(((T7*)a1),Za6((Z3)((Z_5)%((T2)(ZQ5(10))))));Z_5=(Z3)((Z_5)/(ZQ5(10)));}}else{Z26(((T7*)a1),((T3)'\055'));Z06=(Z3)(((((((T7*)a1))->Z91)))+(ZQ5(1)));
Z_5=(C);while(!((Z_5)==(ZQ5(0)))){Z26(((T7*)a1),Za6(-((Z3)((Z_5)%((T2)(ZQ5(10)))))));Z_5=(Z3)((Z_5)/(ZQ5(10)));}}Z16=((((T7*)a1))->Z91);
while(!((Z3)((Z06)>=(Z16)))){Z36(((T7*)a1),Z06,Z16);Z16=(Z3)(((Z16))-(ZQ5(1)));Z06=(Z3)(((Z06))+(ZQ5(1)));}}}T3 Zc6(T11 C){T3 R=0;R=((T3)((Z5)((((C)))+((T11)(ZN5(((T3)'0')))))));
return R;}void Zd6(T11 C,T0*a1){T11 Z_5=0;T2 Z06=0;T2 Z16=0;if(((C))==(ZQ5(0))){Z26(((T7*)a1),((T3)'0'));}else{if((Z5)(((C))>(ZQ5(0)))){
Z06=(Z3)(((((((T7*)a1))->Z91)))+(ZQ5(1)));Z_5=(C);while(!((Z_5)==(ZQ5(0)))){Z26(((T7*)a1),Zc6((Z5)((Z_5)%((T11)(ZQ5(10))))));Z_5=(Z5)((Z_5)/(ZQ5(10)));
}}else{Z26(((T7*)a1),((T3)'\055'));Z06=(Z3)(((((((T7*)a1))->Z91)))+(ZQ5(1)));Z_5=(C);while(!((Z_5)==(ZQ5(0)))){Z26(((T7*)a1),Zc6(-((Z5)((Z_5)%((T11)(ZQ5(10)))))));
Z_5=(Z5)((Z_5)/(ZQ5(10)));}}Z16=((((T7*)a1))->Z91);while(!((Z3)((Z06)>=(Z16)))){Z36(((T7*)a1),Z06,Z16);Z16=(Z3)(((Z16))-(ZQ5(1)));Z06=(Z3)(((Z06))+(ZQ5(1)));
}}}T10 Ze6(T10 C,T10 a1){T10 R=0;if((Z2)((C)>=(a1))){R=C;}else{R=a1;}return R;}ZU Zf6(ZU C,T2 a1,T2 a2){ZU R=Zo;R=((ZU)(Zk(a2,sizeof(T0*))));
Zg6(R,C,(Z3)(((a1))-((T2)(ZQ5(1)))));return R;}void Zh6(ZU C,T2 a1){T2 Z06=0;while(!((Z06)==(a1))){(C)[Z06]=((C)[(Z3)(((Z06))+((T2)(ZQ5(1))))]);
Z06=(Z3)(((Z06))+(ZQ5(1)));}}void Zi6(ZU C,T2 a1,T2 a2){T0*Zj6=Zo;T2 Z06=0;Z06=a1;while(!((Z3)((Z06)>(a2)))){(C)[Z06]=(Zj6);Z06=(Z3)(((Z06))+(ZQ5(1)));
}}void Zg6(ZU C,ZU a1,T2 a2){T2 Z06=0;Z06=a2;while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=((a1)[Z06]);Z06=(Z3)(((Z06))-(ZQ5(1)));}}void Zk6(ZV
C,T2 a1){T10 Zj6=0;T2 Z06=0;Z06=a1;while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=(Zj6);Z06=(Z3)(((Z06))-(ZQ5(1)));}}ZV Zl6(ZV C,T2 a1,T2 a2){
ZV R=Zo;R=((ZV)(Zk(a2,sizeof(T10))));Zm6(R,C,(Z3)(((a1))-((T2)(ZQ5(1)))));return R;}void Zm6(ZV C,ZV a1,T2 a2){T2 Z06=0;Z06=a2;while(!((Z3)((Z06)<(ZQ5(0)))))
{(C)[Z06]=((a1)[Z06]);Z06=(Z3)(((Z06))-(ZQ5(1)));}}T6 Zn6(T0*a1,T0*a2){T6 R=0;if((a1)==((void*)(a2))){R=((T6)(1));}else if((a1)==((void*)(Zo))){
}else if((a2)==((void*)(Zo))){}else{R=((T6)(Zo6(((T7*)a1),a2)));}return R;}T45 Zp6(T45 C,T2 a1,T2 a2){T45 R=Zo;R=((T45)(Zk(a2,sizeof(T0*))));
Zq6(R,C,(Z3)(((a1))-((T2)(ZQ5(1)))));return R;}T2 Zr6(T45 C,T0*a1,T2 a2){T2 R=0;while(!((T6)(((Z3)((R)>(a2)))||((T6)(Zn6(a1,(C)[R]))))))
{R=(Z3)(((R))+(ZQ5(1)));}return R;}void Zs6(T45 C,T2 a1,T2 a2){T2 Z06=0;Z06=a1;while(!((Z06)==(a2))){(C)[Z06]=((C)[(Z3)(((Z06))+((T2)(ZQ5(1))))]);
Z06=(Z3)(((Z06))+(ZQ5(1)));}}void Zt6(T45 C,T0*a1,T2 a2){T2 Z06=0;Z06=a2;while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=(a1);Z06=(Z3)(((Z06))-(ZQ5(1)));
}}void Zu6(T45 C,T2 a1,T2 a2){T0*Zj6=Zo;T2 Z06=0;Z06=a1;while(!((Z3)((Z06)>(a2)))){(C)[Z06]=(Zj6);Z06=(Z3)(((Z06))+(ZQ5(1)));}}T2 Zv6(T45
C,T0*a1,T2 a2){T2 R=0;while(!((T6)(((Z3)((R)>(a2)))||((T6)((a1)==((void*)((C)[R]))))))){R=(Z3)(((R))+(ZQ5(1)));}return R;}void Zq6(T45
C,T45 a1,T2 a2){T2 Z06=0;Z06=a2;while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=((a1)[Z06]);Z06=(Z3)(((Z06))-(ZQ5(1)));}}void Zw6(T9 C,T2 a1,T9
a2,T2 a3,T2 a4){T2 Zx6=0;T2 Zy6=0;Zx6=a1;Zy6=a3;while(!((Z3)((Zy6)>(a4)))){(C)[Zx6]=((a2)[Zy6]);Zy6=(Z3)(((Zy6))+(ZQ5(1)));Zx6=(Z3)(((Zx6))+(ZQ5(1)));
}}T9 Zz6(T9 C,T2 a1,T2 a2){T9 R=Zo;R=((T9)(Zk(a2,sizeof(T3))));ZA6(R,C,(Z3)(((a1))-((T2)(ZQ5(1)))));return R;}void ZB6(T9 C,T3 a1,T2 a2){
T2 Z06=0;Z06=a2;while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=(a1);Z06=(Z3)(((Z06))-(ZQ5(1)));}}T6 ZC6(T9 C,T9 a1,T2 a2){T6 R=0;T2 Z06=0;Z06=(Z3)(((a2))-(ZQ5(1)));
while(!((T6)(((Z3)((Z06)<(ZQ5(0))))||((T6)(((C)[Z06])!=((a1)[Z06])))))){Z06=(Z3)(((Z06))-(ZQ5(1)));}R=((T6)((Z3)((Z06)<(ZQ5(0)))));return
R;}T6 ZD6(T9 C,T3 a1,T2 a2){T6 R=0;T2 Z06=0;Z06=a2;while(!((T6)(((Z3)((Z06)<(ZQ5(0))))||((T6)((a1)==((C)[Z06])))))){Z06=(Z3)(((Z06))-(ZQ5(1)));
}R=((T6)((Z3)((Z06)>=(ZQ5(0)))));return R;}void ZE6(T9 C,T2 a1,T9 a2,T2 a3){T2 ZF6=0;T2 ZG6=0;ZG6=(Z3)(((a3))-(ZQ5(1)));ZF6=(Z3)(((a1))+(ZG6));
while(!((Z3)((ZG6)<(ZQ5(0))))){(C)[ZF6]=((a2)[ZG6]);ZG6=(Z3)(((ZG6))-(ZQ5(1)));ZF6=(Z3)(((ZF6))-(ZQ5(1)));}}void ZH6(T9 C,T2 a1,T2 a2){
T3 Zj6=0;T2 Z06=0;Z06=a1;while(!((Z3)((Z06)>(a2)))){(C)[Z06]=(Zj6);Z06=(Z3)(((Z06))+(ZQ5(1)));}}void ZA6(T9 C,T9 a1,T2 a2){T2 Z06=0;Z06=a2;
while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=((a1)[Z06]);Z06=(Z3)(((Z06))-(ZQ5(1)));}}T81 ZI6(T81 C,T2 a1,T2 a2){T81 R=Zo;R=((T81)(Zk(a2,sizeof(T78))));
ZJ6(R,C,(Z3)(((a1))-((T2)(ZQ5(1)))));return R;}void ZK6(T81 C,T2 a1){T2 Z06=0;while(!((Z06)==(a1))){{T78 ZL6;{T78 ZM6=(*(ZL6=(C)[(Z3)(((Z06))+((T2)(ZQ5(1))))],&ZL6));
ZN6((C)+(Z06),&(ZM6),sizeof(T78));}}Z06=(Z3)(((Z06))+(ZQ5(1)));}}void ZO6(T81 C,T2 a1,T2 a2){T2 Z06=0;Z06=a1;while(!((Z06)==(a2))){{T78
ZL6;{T78 ZM6=(*(ZL6=(C)[(Z3)(((Z06))+((T2)(ZQ5(1))))],&ZL6));ZN6((C)+(Z06),&(ZM6),sizeof(T78));}}Z06=(Z3)(((Z06))+(ZQ5(1)));}}void ZP6(T81
C,T2 a1,T2 a2){T78 Zj6={Zo,Zo,0};T2 Z06=0;Z06=a1;while(!((Z3)((Z06)>(a2)))){{T78 ZM6=Zj6;ZN6((C)+(Z06),&(ZM6),sizeof(T78));}Z06=(Z3)(((Z06))+(ZQ5(1)));
}}T2 ZQ6(T81 C,T78 a1,T2 a2){T2 R=0;{T78 ZL6;while(!((T6)(((Z3)((R)>(a2)))||((T6)(!Z_((a1),((*(ZL6=(C)[R],&ZL6))))))))){R=(Z3)(((R))+(ZQ5(1)));
}}return R;}void ZJ6(T81 C,T81 a1,T2 a2){T2 Z06=0;Z06=a2;while(!((Z3)((Z06)<(ZQ5(0))))){{T78 ZL6;{T78 ZM6=(*(ZL6=(a1)[Z06],&ZL6));ZN6((C)+(Z06),&(ZM6),sizeof(T78));
}}Z06=(Z3)(((Z06))-(ZQ5(1)));}}void ZR6(ZW C,T2 a1){T2 Zj6=0;T2 Z06=0;Z06=a1;while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=(Zj6);Z06=(Z3)(((Z06))-(ZQ5(1)));
}}ZW ZS6(ZW C,T2 a1,T2 a2){ZW R=Zo;R=((ZW)(Zk(a2,sizeof(T2))));ZT6(R,C,(Z3)(((a1))-((T2)(ZQ5(1)))));return R;}T2 ZU6(ZW C,T2 a1,T2 a2){
T2 R=0;while(!((T6)(((Z3)((R)>(a2)))||((T6)((a1)==((C)[R])))))){R=(Z3)(((R))+(ZQ5(1)));}return R;}void ZT6(ZW C,ZW a1,T2 a2){T2 Z06=0;
Z06=a2;while(!((Z3)((Z06)<(ZQ5(0))))){(C)[Z06]=((a1)[Z06]);Z06=(Z3)(((Z06))-(ZQ5(1)));}}T2 ZV6(T7*C,T3 a1){T2 R=0;R=ZW6(C,a1,(T2)(ZQ5(1)));
return R;}void ZX6(T7*C,T0*a1){T2 ZY6=0;ZY6=((((T7*)a1))->Z91);if((Z3)((ZY6)>(ZQ5(0)))){if((Z3)((((C)->Z81))<(ZY6))){(C->Zs1)=((T9)(Zk(ZY6,sizeof(T3))));
(C->Z81)=ZY6;}ZA6(((C)->Zs1),((((T7*)a1))->Zs1),(Z3)(((ZY6))-((T2)(ZQ5(1)))));}(C->Z91)=ZY6;}T0*ZZ6(T7*C,T2 a1,T2 a2){T0*R=Zo;T2 ZY6=0;
ZY6=(Z3)((((Z3)(((a2))-(a1))))+(ZQ5(1)));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,ZY6);R=((T0*)n);}((((T7*)(((T7*)R))))->Z91)=(ZY6);Zw6(((((T7*)R))->Zs1),(T2)(ZQ5(0)),((C)->Zs1),(Z3)(((a1))-((T2)(ZQ5(1)))),(Z3)(((a2))-((T2)(ZQ5(1)))));
return R;}T3 Z07(T7*C){T3 R=0;R=(((C)->Zs1))[(Z3)(((((C)->Z91)))-(ZQ5(1)))];return R;}void Z17(T7*C,T2 a1){if((Z3)((a1)>(((C)->Z91)))){
(C->Z91)=ZQ5(0);}else{if((Z3)((a1)>(ZQ5(0)))){Z27(C,(T2)(ZQ5(1)),a1);}}}void Z27(T7*C,T2 a1,T2 a2){T2 Z06=0;T2 Z37=0;Z37=(Z3)((((Z3)(((a2))-(a1))))+(ZQ5(1)));
if((Z3)((Z37)>(ZQ5(0)))){Z06=(Z3)(((a2))+(ZQ5(1)));while(!((Z3)((Z06)>(((C)->Z91))))){(((C)->Zs1))[((Z3)(((Z06))-(Z37)))-(ZQ5(1))]=((((C)->Zs1))[(Z06)-(ZQ5(1))]);
Z06=(Z3)(((Z06))+(ZQ5(1)));}(C->Z91)=(Z3)(((((C)->Z91)))-(Z37));}}T6 Zo6(T7*C,T0*a1){T6 R=0;if((((C)->Z91))==(((((T7*)a1))->Z91))){R=((T6)(ZC6(((C)->Zs1),((((T7*)a1))->Zs1),((C)->Z91))));
}return R;}T0*Z47=Zo;T0*Z57=Zo;T0*Z67(T7*C){T0*R=Zo;if((Z3)((((C)->Z91))>(ZQ5(0)))){Z77((T44*)(Z57));Z87(C,Z57);if(!(Z97((T44*)(Z57)))){
R=Za7((T44*)(Z57));}}return R;}void Zb7(T7*C,T0*a1){T2 Zc7=0;T2 Zd7=0;T2 Ze7=0;Zc7=((((T7*)a1))->Z91);Zd7=(Z3)(((((C)->Z91)))+(Zc7));
if((Z3)((Zd7)>(((C)->Z81)))){if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((T9)(Zk(Zd7,sizeof(T3))));(C->Z81)=Zd7;}else{Ze7=Z66((Z3)(((ZQ5(2)))*(((C)->Z81))),Zd7);
(C->Zs1)=Zz6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;}}ZE6(((C)->Zs1),((C)->Z91),((((T7*)a1))->Zs1),Zc7);(C->Z91)=Zd7;}T6 Zf7(T7*C,T0*a1){
T6 R=0;R=((T6)((Zg7(C,a1,(T2)(ZQ5(1))))!=(ZQ5(0))));return R;}T2 ZW6(T7*C,T3 a1,T2 a2){T2 R=0;R=a2;while(!((T6)(((Z3)((R)>(((C)->Z91))))||((T6)((a1)==((((C)->Zs1))[(R)-(ZQ5(1))]))))))
{R=(Z3)(((R))+(ZQ5(1)));}if((Z3)((R)>(((C)->Z91)))){R=ZQ5(0);}return R;}T6 Zh7(T7*C,T0*a1){T6 R=0;T2 Zx6=0;T2 Zy6=0;if((Z3)((((((T7*)a1))->Z91))<=(((C)->Z91)))){
Zx6=(Z3)((((Z3)(((((C)->Z91)))-(((((T7*)a1))->Z91)))))+(ZQ5(1)));Zy6=ZQ5(1);while(!((T6)(((Z3)((Zx6)>(((C)->Z91))))||((T6)(((((C)->Zs1))[(Zx6)-(ZQ5(1))])!=((((((T7*)a1))->Zs1))[(Zy6)-(ZQ5(1))]))))))
{Zx6=(Z3)(((Zx6))+(ZQ5(1)));Zy6=(Z3)(((Zy6))+(ZQ5(1)));}R=((T6)((Z3)((Zx6)>(((C)->Z91)))));}return R;}T6 Zi7(T7*C){T6 R=0;T2 Z06=0;T2
Zj7=0;T2 Zk7=0;T2 Zl7=0;T2 Zm7=0;T3 Zn7=0;Z06=ZQ5(1);while(!((T6)(((Zj7)==(ZQ5(2)))||((T6)((Z3)((Z06)>(((C)->Z91)))))))){Zn7=(((C)->Zs1))[(Z06)-(ZQ5(1))];
{int z1=Zj7;switch(z1){case 0:if(ZJ5(Zn7)){}else if((Zn7)==(((T3)'\053'))){Zl7=ZQ5(7);Zm7=Zo7(214748364);Zj7=ZQ5(1);}else if((Zn7)==(((T3)'\055'))){
Zl7=ZQ5(8);Zm7=Zo7(214748364);Zj7=ZQ5(1);}else if(ZI5(Zn7)){Zl7=ZQ5(7);Zm7=Zo7(214748364);Zk7=(T2)(ZT5(Zn7));Zj7=ZQ5(3);}else{Zj7=ZQ5(2);
}break;case 1:if(ZI5(Zn7)){Zk7=(T2)(ZT5(Zn7));Zj7=ZQ5(3);}else{Zj7=ZQ5(2);}break;case 3:if(ZI5(Zn7)){Zk7=(Z3)((((Z3)(((ZQ5(10)))*(Zk7))))+((T2)(ZT5(Zn7))));
if((Z3)((Zk7)>=(Zm7))){Zj7=ZQ5(4);}}else if(ZJ5(Zn7)){Zj7=ZQ5(5);}else{Zj7=ZQ5(2);}break;case 4:if(ZI5(Zn7)){if((Z3)((Zk7)>(Zm7))){Zj7=ZQ5(2);
}else{if((Z3)(((T2)(ZT5(Zn7)))<=(Zl7))){Zj7=ZQ5(5);}else{Zj7=ZQ5(2);}}}else if(ZJ5(Zn7)){Zj7=ZQ5(5);}else{Zj7=ZQ5(2);}break;default:;
if(ZJ5(Zn7)){}else{Zj7=ZQ5(2);}}}Z06=(Z3)(((Z06))+(ZQ5(1)));}R=((T6)((Z3)((Zj7)>=(ZQ5(3)))));return R;}void Z_6(T7*C,T2 a1){if((Z3)((a1)>(ZQ5(0)))){
if((Z3)((((C)->Z81))<(a1))){(C->Zs1)=((T9)(Zk(a1,sizeof(T3))));(C->Z81)=a1;}}(C->Z91)=ZQ5(0);}T6 Zp7(T7*C,T0*a1){T6 R=0;T2 Z06=0;if((Z3)((((((T7*)a1))->Z91))<=(((C)->Z91)))){
Z06=((((T7*)a1))->Z91);while(!((T6)(((Z06)==(ZQ5(0)))||((T6)(((((C)->Zs1))[(Z06)-(ZQ5(1))])!=((((((T7*)a1))->Zs1))[(Z06)-(ZQ5(1))]))))))
{Z06=(Z3)(((Z06))-(ZQ5(1)));}R=((T6)((Z06)==(ZQ5(0))));}return R;}void Zq7(T7*C,T0*a1){T2 Zc7=0;T2 Zd7=0;T2 Ze7=0;Zc7=((((T7*)a1))->Z91);
Zd7=(Z3)(((((C)->Z91)))+(Zc7));if((Z3)((Zd7)>(((C)->Z81)))){if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((T9)(Zk(Zd7,sizeof(T3))));(C->Z81)=Zd7;
}else{Ze7=Z66((Z3)(((ZQ5(2)))*(((C)->Z81))),Zd7);(C->Zs1)=Zz6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;}}ZE6(((C)->Zs1),((C)->Z91),((((T7*)a1))->Zs1),Zc7);
(C->Z91)=Zd7;}void Zr7(T7*C,T3 a1,T2 a2){Z_6(C,a2);(C->Z91)=a2;{T7*C1=C;T3 b1=a1;ZB6(((C1)->Zs1),b1,(Z3)(((((C1)->Z91)))-((T2)(ZQ5(1)))));
}}void Z26(T7*C,T3 a1){T2 Ze7=0;if((Z3)((((C)->Z81))>(((C)->Z91)))){}else if((((C)->Z81))==(ZQ5(0))){Ze7=ZQ5(32);(C->Zs1)=((T9)(Zk(Ze7,sizeof(T3))));
(C->Z81)=Ze7;}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));(C->Zs1)=Zz6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;}(((C)->Zs1))[((C)->Z91)]=(a1);
(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));}T2 Zs7(T7*C){T2 R=0;T2 Z06=0;T2 Zt7=0;Zt7=((C)->Z91);Z06=ZQ5(1);while(!((Z3)((Zt7)<=(ZQ5(0)))))
{R=(Z3)(((Z3)((R)*(ZQ5(5))))+((T2)(ZN5((((C)->Zs1))[(Z06)-(ZQ5(1))]))));Z06=(Z3)(((Z06))+(ZQ5(1)));Zt7=(Z3)(((Zt7))-(ZQ5(1)));}if((Z3)((R)<(ZQ5(0)))){
R=~(R);}return R;}void Zu7(T7*C,T2 a1){if((Z3)((a1)>(((C)->Z91)))){(C->Z91)=ZQ5(0);}else{(C->Z91)=(Z3)(((((C)->Z91)))-(a1));}}T6 Zv7(T7*C,T3
a1){T6 R=0;R=((T6)(ZD6(((C)->Zs1),a1,(Z3)(((((C)->Z91)))-((T2)(ZQ5(1)))))));return R;}void Zw7(T7*C,T2 a1){if((Z3)((a1)<(((C)->Z91)))){
Zu7(C,(Z3)(((((C)->Z91)))-(a1)));}}T2 Zx7(T7*C){T2 R=0;T2 Z06=0;T3 Zn7=0;T6 Zy7=0;Z06=ZQ5(1);while(!(!(ZJ5((((C)->Zs1))[(Z06)-(ZQ5(1))]))))
{Z06=(Z3)(((Z06))+(ZQ5(1)));}Zn7=(((C)->Zs1))[(Z06)-(ZQ5(1))];Z06=(Z3)(((Z06))+(ZQ5(1)));if((Zn7)==(((T3)'\053'))){Zn7=(((C)->Zs1))[(Z06)-(ZQ5(1))];
Z06=(Z3)(((Z06))+(ZQ5(1)));}else if((Zn7)==(((T3)'\055'))){Zy7=((T6)(1));Zn7=(((C)->Zs1))[(Z06)-(ZQ5(1))];Z06=(Z3)(((Z06))+(ZQ5(1)));
}R=(T2)(-(ZO5(Zn7)));while(!((Z3)((Z06)>(((C)->Z91))))){Zn7=(((C)->Zs1))[(Z06)-(ZQ5(1))];if(ZI5(Zn7)){R=(Z3)((((Z3)(((ZQ5(10)))*(R))))-((T2)(ZT5(Zn7))));
}else{Z06=((C)->Z91);}Z06=(Z3)(((Z06))+(ZQ5(1)));}if(Zy7){}else{R=-(R);}return R;}void Zz7(T7*C,T3 a1){T2 Ze7=0;if((Z3)((((C)->Z81))>(((C)->Z91)))){
}else if((((C)->Z81))==(ZQ5(0))){Ze7=ZQ5(32);(C->Zs1)=((T9)(Zk(Ze7,sizeof(T3))));(C->Z81)=Ze7;}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));
(C->Zs1)=Zz6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;}(((C)->Zs1))[((C)->Z91)]=(a1);(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));}void ZA7(T7*C,T3
a1){if((T6)(((((C)->Z91))==(ZQ5(0)))||((T6)(((((C)->Zs1))[(((C)->Z91))-(ZQ5(1))])!=(a1))))){Zz7(C,a1);}}T6 ZB7(T7*C,T0*a1){T6 R=0;T9 ZC7=Zo;
T9 ZD7=Zo;T2 Z06=0;Z06=((C)->Z91);if((Z06)==(((((T7*)a1))->Z91))){if(ZC6(((C)->Zs1),((((T7*)a1))->Zs1),Z06)){R=((T6)(1));}else{Z06=(Z3)(((Z06))-(ZQ5(1)));
ZC7=((C)->Zs1);ZD7=((((T7*)a1))->Zs1);R=((T6)(1));while(!((Z3)((Z06)<(ZQ5(0))))){if(ZS5((ZC7)[Z06],(ZD7)[Z06])){Z06=(Z3)(((Z06))-(ZQ5(1)));
}else{Z06=ZQ5(-1);R=((T6)(0));}}}}return R;}void ZE7(T7*C,T3 a1){T2 Ze7=0;if((Z3)((((C)->Z81))>(((C)->Z91)))){}else if((((C)->Z81))==(ZQ5(0))){
Ze7=ZQ5(32);(C->Zs1)=((T9)(Zk(Ze7,sizeof(T3))));(C->Z81)=Ze7;}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));(C->Zs1)=Zz6(((C)->Zs1),((C)->Z81),Ze7);
(C->Z81)=Ze7;}(((C)->Zs1))[((C)->Z91)]=(a1);(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));}void ZF7(T7*C,T2 a1){T9 ZG7=Zo;if((Z3)((a1)<=(((C)->Z91)))){
}else if((Z3)((((C)->Z81))<(a1))){if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((T9)(Zk(a1,sizeof(T3))));}else{(C->Zs1)=Zz6(((C)->Zs1),((C)->Z81),a1);
}(C->Z81)=a1;}else{ZH6(((C)->Zs1),((C)->Z91),(Z3)(((a1))-((T2)(ZQ5(1)))));}(C->Z91)=a1;}void ZH7(T7*C){T2 Z06=0;Z06=((C)->Z91);while(!((Z06)==(ZQ5(0))))
{(((C)->Zs1))[(Z06)-(ZQ5(1))]=(ZU5((((C)->Zs1))[(Z06)-(ZQ5(1))]));Z06=(Z3)(((Z06))-(ZQ5(1)));}}T2 Zg7(T7*C,T0*a1,T2 a2){T2 R=0;T2 Z06=0;
T2 ZG7=0;ZG7=a2;while(!((T6)(((R)!=(ZQ5(0)))||((T6)((Z3)(((Z3)((((Z3)(((ZG7))+(((((T7*)a1))->Z91)))))-(ZQ5(1))))>(((C)->Z91)))))))){Z06=ZQ5(1);
while(!((T6)(((Z3)((Z06)>(((((T7*)a1))->Z91))))||((T6)(((((C)->Zs1))[((Z3)((((Z3)(((ZG7))+(Z06))))-(ZQ5(1))))-(ZQ5(1))])!=((((((T7*)a1))->Zs1))[(Z06)-(ZQ5(1))]))))))
{Z06=(Z3)(((Z06))+(ZQ5(1)));}if((Z3)((Z06)>(((((T7*)a1))->Z91)))){R=ZG7;}else{ZG7=(Z3)(((ZG7))+(ZQ5(1)));}}return R;}void ZI7(T7*C,T8
a1){T9 ZG7=Zo;T2 Z06=0;ZG7=a1;(C->Z91)=ZQ5(0);while(!(((ZG7)[Z06])==(((T3)'\000')))){Zz7(C,(ZG7)[Z06]);Z06=(Z3)(((Z06))+(ZQ5(1)));}}void
ZJ7(T7*C){while(!((T6)(((((C)->Z91))==(ZQ5(0)))||((T6)(((((C)->Zs1))[(((C)->Z91))-(ZQ5(1))])!=(((T3)'\040'))))))){(C->Z91)=(Z3)(((((C)->Z91)))-(ZQ5(1)));
}}T8 ZK7(T7*C){T8 R=Zo;if((Z3)((((C)->Z81))>(((C)->Z91)))){(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));if(((((C)->Zs1))[(((C)->Z91))-(ZQ5(1))])!=(((T3)'\000'))){
(((C)->Zs1))[(((C)->Z91))-(ZQ5(1))]=(((T3)'\000'));}}else{Zz7(C,((T3)'\000'));}(C->Z91)=(Z3)(((((C)->Z91)))-(ZQ5(1)));R=((void*)(((C)->Zs1)));
return R;}void ZL7(T7*C){T2 Z06=0;Z06=((C)->Z91);while(!((Z06)==(ZQ5(0)))){(((C)->Zs1))[(Z06)-(ZQ5(1))]=(ZW5((((C)->Zs1))[(Z06)-(ZQ5(1))]));
Z06=(Z3)(((Z06))-(ZQ5(1)));}}T0*ZM7(T7*C){T0*R=Zo;R=Zh(sizeof(*C));*((T7*)R)=M7;ZX6(((T7*)R),((T0*)C));return R;}T0*ZN7(T7*C,T0*a1){T0*R=Zo;
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(Z3)(((((C)->Z91)))+(((((T7*)a1))->Z91))));R=((T0*)n);}Zb7(((T7*)R),(T0*)C);Zb7(((T7*)R),a1);
return R;}T6 ZO7(T7*C){T6 R=0;int ZP7=0;R=((T6)(ZQ7(ZP7,(T0*)C)));return R;}void ZR7(T7*C){T2 Z06=0;Z06=ZQ5(1);while(!((T6)(((Z3)((Z06)>(((C)->Z91))))||((T6)(((((C)->Zs1))[(Z06)-(ZQ5(1))])!=(((T3)'\040')))))))
{Z06=(Z3)(((Z06))+(ZQ5(1)));}Z17(C,(Z3)(((Z06))-((T2)(ZQ5(1)))));}void Z87(T7*C,T0*a1){T2 Zj7=0;T2 Z06=0;T3 ZY6=0;if((Z3)((((C)->Z91))>(ZQ5(0)))){
Z06=ZQ5(1);while(!((Z3)((Z06)>(((C)->Z91))))){ZY6=(((C)->Zs1))[(Z06)-(ZQ5(1))];if((Zj7)==(ZQ5(0))){if(!(ZJ5(ZY6))){((((T7*)((T7*)(Z47))))->Z91)=(ZQ5(0));
Zz7((T7*)(Z47),ZY6);Zj7=ZQ5(1);}}else{if(!(ZJ5(ZY6))){Zz7((T7*)(Z47),ZY6);}else{ZS7(a1,ZM7((T7*)(Z47)));Zj7=ZQ5(0);}}Z06=(Z3)(((Z06))+(ZQ5(1)));
}if((Zj7)==(ZQ5(1))){ZS7(a1,ZM7((T7*)(Z47)));}}}void Z36(T7*C,T2 a1,T2 a2){T3 ZT7=0;ZT7=(((C)->Zs1))[(a1)-(ZQ5(1))];(((C)->Zs1))[(a1)-(ZQ5(1))]=((((C)->Zs1))[(a2)-(ZQ5(1))]);
(((C)->Zs1))[(a2)-(ZQ5(1))]=(ZT7);}void ZU7(T44*C,T0*a1){T2 Zd7=0;(C->Z53)=((((T44*)a1))->Z53);(C->Zt1)=((((T44*)a1))->Zt1);Zd7=(Z3)((((Z3)(((((C)->Zt1)))-(((C)->Z53)))))+(ZQ5(1)));
if((Z3)((((C)->Z81))<(Zd7))){(C->Zs1)=((T45)(Zk(Zd7,sizeof(T0*))));(C->Z81)=Zd7;}if((Z3)((Zd7)>(ZQ5(0)))){Zq6(((C)->Zs1),((((T44*)a1))->Zs1),(Z3)(((Zd7))-((T2)(ZQ5(1)))));
}}T2 ZV7(T44*C){T2 R=0;R=(Z3)((((Z3)(((((C)->Zt1)))-(((C)->Z53)))))+(ZQ5(1)));return R;}T0*ZW7(T44*C,T2 a1){T0*R=Zo;R=(((C)->Zs1))[(Z3)(((a1))-(((C)->Z53)))];
return R;}T6 ZX7(T44*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((((C)->Z53))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->Zt1))))))));return R;}T2 ZY7(T44*C,T0*a1){
T2 R=0;R=(Z3)(((((C)->Z53)))+(Zr6(((C)->Zs1),a1,(Z3)(((((C)->Zt1)))-(((C)->Z53))))));return R;}void ZZ7(T44*C,T2 a1,T2 a2){T2 Z_7=0;(C->Z53)=a1;
(C->Zt1)=a2;Z_7=(Z3)((((Z3)(((a2))-(a1))))+(ZQ5(1)));if((Z3)((Z_7)>(ZQ5(0)))){if((Z3)((((C)->Z81))<(Z_7))){(C->Zs1)=((T45)(Zk(Z_7,sizeof(T0*))));
(C->Z81)=Z_7;}else{{T44*C1=C;T0*Z08=Zo;{T44*C2=C1;T0*c1=Z08;Zt6(((C2)->Zs1),c1,(Z3)(((((C2)->Zt1)))-(((C2)->Z53))));}}}}}void Z18(T44*C,T0*a1){
if((Z3)((((C)->Zt1))<(((C)->Z53)))){Z28(C,a1);}else{Z28(C,a1);Z38(C,((C)->Z53),(Z3)(((((C)->Zt1)))-((T2)(ZQ5(1)))),(T2)(ZQ5(1)));{T44*C1=C;
T0*b1=a1;T2 b2=((C)->Z53);(((C1)->Zs1))[(Z3)(((b2))-(((C1)->Z53)))]=(b1);}}}T6 Z97(T44*C){T6 R=0;R=((T6)((Z3)((((C)->Zt1))<(((C)->Z53)))));
return R;}void Z38(T44*C,T2 a1,T2 a2,T2 a3){T0*Z48=Zo;T2 Z06=0;if((a3)==(ZQ5(0))){}else if((Z3)((a3)<(ZQ5(0)))){Z06=a1;while(!((Z3)((Z06)>(a2))))
{{T44*C1=C;T0*b1=ZW7(C,Z06);T2 b2=(Z3)(((Z06))+(a3));(((C1)->Zs1))[(Z3)(((b2))-(((C1)->Z53)))]=(b1);}{T44*C1=C;T0*b1=Z48;T2 b2=Z06;(((C1)->Zs1))[(Z3)(((b2))-(((C1)->Z53)))]=(b1);
}Z06=(Z3)(((Z06))+(ZQ5(1)));}}else{Z06=a2;while(!((Z3)((Z06)<(a1)))){{T44*C1=C;T0*b1=ZW7(C,Z06);T2 b2=(Z3)(((Z06))+(a3));(((C1)->Zs1))[(Z3)(((b2))-(((C1)->Z53)))]=(b1);
}{T44*C1=C;T0*b1=Z48;T2 b2=Z06;(((C1)->Zs1))[(Z3)(((b2))-(((C1)->Z53)))]=(b1);}Z06=(Z3)(((Z06))-(ZQ5(1)));}}}T6 Z58(T44*C,T0*a1){T6 R=0;
R=((T6)(ZX7(C,ZY7(C,a1))));return R;}T6 Z68(T44*C,T0*a1){T6 R=0;R=((T6)(ZX7(C,Z78(C,a1))));return R;}void Z28(T44*C,T0*a1){T2 Ze7=0;if((Z3)((((C)->Z81))<((Z3)(((ZV7(C)))+(ZQ5(1)))))){
if((((C)->Z81))==(ZQ5(0))){Ze7=ZQ5(16);(C->Zs1)=((T45)(Zk(Ze7,sizeof(T0*))));(C->Z81)=Ze7;}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));(C->Zs1)=Zp6(((C)->Zs1),((C)->Z81),Ze7);
(C->Z81)=Ze7;}}(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));{T44*C1=C;T0*b1=a1;T2 b2=((C)->Zt1);(((C1)->Zs1))[(Z3)(((b2))-(((C1)->Z53)))]=(b1);
}}void Z77(T44*C){(C->Zt1)=(Z3)(((((C)->Z53)))-(ZQ5(1)));}T2 Z78(T44*C,T0*a1){T2 R=0;R=(Z3)(((((C)->Z53)))+(Zv6(((C)->Zs1),a1,(Z3)(((((C)->Zt1)))-(((C)->Z53))))));
return R;}T0*Za7(T44*C){T0*R=Zo;R=Zh(sizeof(*C));*((T44*)R)=M44;ZU7(((T44*)R),((T0*)C));return R;}void Z88(T44*C,T2 a1,T2 a2){if((Z3)((((C)->Z81))<(a1))){
(C->Zs1)=((T45)(Zk(a1,sizeof(T0*))));(C->Z81)=a1;}(C->Z53)=a2;(C->Zt1)=(Z3)(((a2))-(ZQ5(1)));}T65*Z98(void){T65*n;n=((T65*)Zh(sizeof(*n)));
*n=M65;{T65*C1=n;Za8(C1,Zb8(193));}return n;}T6 Zc8(T0*a1,T0*a2){T6 R=0;if((a1)==((void*)(a2))){R=((T6)(1));}else if((a1)==((void*)(Zo))){
}else if((a2)==((void*)(Zo))){}else{R=((T6)(Zo6(((T7*)a1),a2)));}return R;}T2 Zd8(T65*C,T0*a1){T2 R=0;T2 Z06=0;Z06=ZQ5(1);while(!((Z3)((Z06)>(((C)->Z91)))))
{if(Zc8(a1,Ze8(C,Z06))){R=(Z3)(((R))+(ZQ5(1)));}Z06=(Z3)(((Z06))+(ZQ5(1)));}return R;}void Zf8(T65*C,T0*a1,T0*a2){T2 Z16=0;T0*Zg8=Zo;
(C->Za1)=ZQ5(-1);if((((C)->Z81))==(((C)->Z91))){Zh8(C);}Z16=(Z3)((Zs7(((T7*)a2)))%(((C)->Z81)));{T71*n=((T71*)Zh(sizeof(*n)));*n=M71;
Zi8(n,a1,a2,(((C)->Z71))[Z16]);Zg8=((T0*)n);}(((C)->Z71))[Z16]=(Zg8);(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));}T0*Zj8(T65*C,T2 a1){T0*R=Zo;
Zk8(C,a1);R=(((T71*)(((C)->Zb1)))->Zq1);return R;}T0*Zl8(T65*C,T0*a1){T0*R=Zo;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));
Zg8=(((C)->Z71))[Z16];while(!(Zo6((T7*)(((((T71*)Zg8))->Zq1)),a1))){Zg8=((((T71*)Zg8))->Zr1);}R=((((T71*)Zg8))->Zp1);return R;}void Zm8(T65*C,T2
a1){T2 Ze7=0;int Zn8=0;Ze7=Zo8(a1);(C->Z71)=((T72)(Zk(Ze7,sizeof(T0*))));(C->Z81)=Ze7;(C->Za1)=ZQ5(-1);(C->Z91)=ZQ5(0);}T0*Ze8(T65*C,T2
a1){T0*R=Zo;Zk8(C,a1);R=(((T71*)(((C)->Zb1)))->Zp1);return R;}void Zk8(T65*C,T2 a1){if((a1)==((Z3)(((((C)->Za1)))+(ZQ5(1))))){(C->Za1)=a1;
(C->Zb1)=(((T71*)(((C)->Zb1)))->Zr1);while(!((((C)->Zb1))!=((void*)(Zo)))){(C->Zc1)=(Z3)(((((C)->Zc1)))+(ZQ5(1)));(C->Zb1)=(((C)->Z71))[((C)->Zc1)];
}}else if((a1)==(((C)->Za1))){}else if((a1)==(ZQ5(1))){(C->Za1)=ZQ5(1);(C->Zc1)=ZQ5(0);(C->Zb1)=(((C)->Z71))[((C)->Zc1)];while(!((((C)->Zb1))!=((void*)(Zo))))
{(C->Zc1)=(Z3)(((((C)->Zc1)))+(ZQ5(1)));(C->Zb1)=(((C)->Z71))[((C)->Zc1)];}}else{Zk8(C,(T2)(ZQ5(1)));while(!((((C)->Za1))==(a1))){Zk8(C,(Z3)(((((C)->Za1)))+((T2)(ZQ5(1)))));
}}}T0*Zp8(T65*C,T0*a1){T0*R=Zo;T2 Z06=0;Z06=ZQ5(1);while(!(Zc8(a1,Ze8(C,Z06)))){Z06=(Z3)(((Z06))+(ZQ5(1)));}R=(((T71*)(((C)->Zb1)))->Zq1);
return R;}void Zh8(T65*C){T2 Z06=0;T2 Z16=0;T2 Ze7=0;T72 Zq8=Zo;T0*Zr8=Zo;T0*Zs8=Zo;int Zn8=0;Ze7=Zo8((Z3)(((((C)->Z81)))+(ZQ5(1))));
Zq8=((C)->Z71);(C->Z71)=((T72)(Zk(Ze7,sizeof(T0*))));Z06=(Z3)(((((C)->Z81)))-(ZQ5(1)));(C->Z81)=Ze7;while(!((Z3)((Z06)<(ZQ5(0))))){Zr8=(Zq8)[Z06];
while(!((Zr8)==((void*)(Zo)))){Zs8=((((T71*)Zr8))->Zr1);Z16=(Z3)((Zs7((T7*)(((((T71*)Zr8))->Zq1))))%(((C)->Z81)));((((T71*)(((T71*)Zr8))))->Zr1)=((((C)->Z71))[Z16]);
(((C)->Z71))[Z16]=(Zr8);Zr8=Zs8;}Z06=(Z3)(((Z06))-(ZQ5(1)));}(C->Za1)=ZQ5(-1);}T6 Zt8(T65*C,T0*a1){T6 R=0;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));
Zg8=(((C)->Z71))[Z16];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((T71*)Zg8))->Zq1)),a1)))))){Zg8=((((T71*)Zg8))->Zr1);}R=((T6)((Zg8)!=((void*)(Zo))));
return R;}void Zu8(T65*C,T0*a1,T0*a2){Zf8(C,a1,a2);Zv8((T49*)(((C)->Zd1)),a2);}void Zw8(T65*C,T0*a1){T0*Zg8=Zo;T2 Z06=0;T2 Z16=0;Z06=((C)->Z91);
Zg8=(((C)->Z71))[Z16];while(!((Z3)((Z06)<=(ZQ5(0))))){while(!((Zg8)!=((void*)(Zo)))){Z16=(Z3)(((Z16))+(ZQ5(1)));Zg8=(((C)->Z71))[Z16];
}ZS7(a1,((((T71*)Zg8))->Zp1));Zg8=((((T71*)Zg8))->Zr1);Z06=(Z3)(((Z06))-(ZQ5(1)));}}void Za8(T65*C,T2 a1){Zm8(C,a1);{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;Zx8(n,a1);(C->Zd1)=((T0*)n);}}T0*Zy8(T65*C,T0*a1){T0*R=Zo;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));Zg8=(((C)->Z71))[Z16];
while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((T71*)Zg8))->Zq1)),a1)))))){Zg8=((((T71*)Zg8))->Zr1);}if((Zg8)!=((void*)(Zo))){
R=((((T71*)Zg8))->Zp1);}return R;}void Zi8(T71*C,T0*a1,T0*a2,T0*a3){(C->Zp1)=a1;(C->Zq1)=a2;(C->Zr1)=a3;}T0*Zz8(T49*C){T0*R=Zo;R=(((C)->Zs1))[((C)->Zt1)];
return R;}T6 ZA8(T49*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZQ5(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->Zt1))))))));return R;}void ZB8(T49*C,T2
a1){Zs6(((C)->Zs1),a1,((C)->Zt1));(C->Zt1)=(Z3)(((((C)->Zt1)))-(ZQ5(1)));}T0*ZC8(T49*C){T0*R=Zo;{ZL*n=((ZL*)Zh(sizeof(*n)));*n=Zi2;ZD8(n,(T0*)C);
R=((T0*)n);}return R;}void Zv8(T49*C,T0*a1){T2 Ze7=0;if((Z3)(((Z3)(((((C)->Zt1)))+(ZQ5(1))))<=((Z3)(((((C)->Z81)))-(ZQ5(1)))))){(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));
}else if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((T45)(Zk(ZQ5(2),sizeof(T0*))));(C->Z81)=ZQ5(2);(C->Zt1)=ZQ5(0);}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));
(C->Zs1)=Zp6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));}(((C)->Zs1))[((C)->Zt1)]=(a1);}void Zx8(T49*C,T2
a1){if((Z3)((((C)->Z81))<(a1))){(C->Zs1)=((T45)(Zk(a1,sizeof(T0*))));(C->Z81)=a1;}else if((Z3)((((C)->Z81))>(a1))){Zu6(((C)->Zs1),(T2)(ZQ5(0)),((C)->Zt1));
}(C->Zt1)=ZQ5(-1);}void ZE8(ZF*C,T2 a1){if((Z3)((a1)>(((C)->Z81)))){(C->Zs1)=((ZW)(Zk(a1,sizeof(T2))));(C->Z81)=a1;}else if((Z3)((((C)->Z81))>(ZQ5(0)))){
(C->Zt1)=Z66(((C)->Zt1),(Z3)(((a1))-(ZQ5(1))));if((Z3)((((C)->Zt1))>=(ZQ5(0)))){ZR6(((C)->Zs1),((C)->Zt1));}}(C->Zt1)=(Z3)(((a1))-(ZQ5(1)));
}void ZF8(ZF*C,T2 a1){T2 Ze7=0;if((Z3)(((Z3)(((((C)->Zt1)))+(ZQ5(1))))<=((Z3)(((((C)->Z81)))-(ZQ5(1)))))){(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));
}else if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((ZW)(Zk(ZQ5(2),sizeof(T2))));(C->Z81)=ZQ5(2);(C->Zt1)=ZQ5(0);}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));
(C->Zs1)=ZS6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));}(((C)->Zs1))[((C)->Zt1)]=(a1);}T2 ZG8(ZF*C,T2
a1){T2 R=0;R=ZU6(((C)->Zs1),a1,((C)->Zt1));return R;}void ZH8(ZH*C){ZU ZI8=Zo;if((((C)->Zt1))==(ZQ5(0))){(C->Zs1)=ZI8;(C->Z81)=ZQ5(0);
(C->Zt1)=ZQ5(-1);}else{Zh6(((C)->Zs1),((C)->Zt1));(C->Zt1)=(Z3)(((((C)->Zt1)))-(ZQ5(1)));}}void ZJ8(ZH*C,T0*a1){T2 Ze7=0;if((Z3)(((Z3)(((((C)->Zt1)))+(ZQ5(1))))<=((Z3)(((((C)->Z81)))-(ZQ5(1)))))){
(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));}else if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((ZU)(Zk(ZQ5(2),sizeof(T0*))));(C->Z81)=ZQ5(2);(C->Zt1)=ZQ5(0);
}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));(C->Zs1)=Zf6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));}
(((C)->Zs1))[((C)->Zt1)]=(a1);}void ZK8(ZH*C,T2 a1){if((Z3)((((C)->Z81))<(a1))){(C->Zs1)=((ZU)(Zk(a1,sizeof(T0*))));(C->Z81)=a1;}else
if((Z3)((((C)->Z81))>(a1))){Zi6(((C)->Zs1),(T2)(ZQ5(0)),((C)->Zt1));}(C->Zt1)=ZQ5(-1);}void ZL8(T92*C,T10 a1,T0*a2,T0*a3){(C->Zp1)=a1;
(C->Zq1)=a2;(C->Zr1)=a3;}void ZM8(ZJ*C,T2 a1){if((Z3)((a1)>(((C)->Z81)))){(C->Zs1)=((ZV)(Zk(a1,sizeof(T10))));(C->Z81)=a1;}else if((Z3)((((C)->Z81))>(ZQ5(0)))){
(C->Zt1)=Z66(((C)->Zt1),(Z3)(((a1))-(ZQ5(1))));if((Z3)((((C)->Zt1))>=(ZQ5(0)))){Zk6(((C)->Zs1),((C)->Zt1));}}(C->Zt1)=(Z3)(((a1))-(ZQ5(1)));
}void ZN8(ZJ*C,T10 a1){T2 Ze7=0;if((Z3)(((Z3)(((((C)->Zt1)))+(ZQ5(1))))<=((Z3)(((((C)->Z81)))-(ZQ5(1)))))){(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));
}else if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((ZV)(Zk(ZQ5(2),sizeof(T10))));(C->Z81)=ZQ5(2);(C->Zt1)=ZQ5(0);}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));
(C->Zs1)=Zl6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));}(((C)->Zs1))[((C)->Zt1)]=(a1);}void ZO8(T74*C){
(C->Zg2)=(Z3)(((((C)->Zg2)))+(ZQ5(1)));}T0*ZP8(T74*C){T0*R=Zo;R=ZQ8(((C)->Zf2),((C)->Zg2));return R;}void ZR8(T74*C,T0*a1){(C->Zf2)=a1;
(C->Zg2)=ZQ5(1);}T6 ZS8(T74*C){T6 R=0;R=((T6)((Z3)((((C)->Zg2))>((((T65*)(((C)->Zf2)))->Z91)))));return R;}void ZT8(T89*C,T10 a1,T0*a2){
T2 ZU8=0;T2 Z16=0;T0*Zg8=Zo;ZU8=Zs7(((T7*)a2));Z16=(Z3)((ZU8)%(((C)->Z81)));Zg8=(((C)->Z71))[Z16];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((T92*)Zg8))->Zq1)),a2))))))
{Zg8=((((T92*)Zg8))->Zr1);}if((Zg8)==((void*)(Zo))){if((((C)->Z81))==(((C)->Z91))){ZV8(C);Z16=(Z3)((ZU8)%(((C)->Z81)));}{T92*n=((T92*)Zh(sizeof(*n)));
*n=M92;ZL8(n,a1,a2,(((C)->Z71))[Z16]);Zg8=((T0*)n);}(((C)->Z71))[Z16]=(Zg8);(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));(C->Za1)=ZQ5(-1);}
else{((((T92*)(((T92*)Zg8))))->Zp1)=(a1);}}T0*ZW8(T89*C,T10 a1){T0*R=Zo;T2 Z06=0;Z06=ZQ5(1);while(!((a1)==(ZX8(C,Z06)))){Z06=(Z3)(((Z06))+(ZQ5(1)));
}R=(((T92*)(((C)->Zb1)))->Zq1);return R;}T10 ZX8(T89*C,T2 a1){T10 R=0;ZY8(C,a1);R=(((T92*)(((C)->Zb1)))->Zp1);return R;}void ZY8(T89*C,T2
a1){if((a1)==((Z3)(((((C)->Za1)))+(ZQ5(1))))){(C->Za1)=a1;(C->Zb1)=(((T92*)(((C)->Zb1)))->Zr1);while(!((((C)->Zb1))!=((void*)(Zo)))){
(C->Zc1)=(Z3)(((((C)->Zc1)))+(ZQ5(1)));(C->Zb1)=(((C)->Z71))[((C)->Zc1)];}}else if((a1)==(((C)->Za1))){}else if((a1)==(ZQ5(1))){(C->Za1)=ZQ5(1);
(C->Zc1)=ZQ5(0);(C->Zb1)=(((C)->Z71))[((C)->Zc1)];while(!((((C)->Zb1))!=((void*)(Zo)))){(C->Zc1)=(Z3)(((((C)->Zc1)))+(ZQ5(1)));(C->Zb1)=(((C)->Z71))[((C)->Zc1)];
}}else{ZY8(C,(T2)(ZQ5(1)));while(!((((C)->Za1))==(a1))){ZY8(C,(Z3)(((((C)->Za1)))+((T2)(ZQ5(1)))));}}}void ZV8(T89*C){T2 Z06=0;T2 Z16=0;
T2 Ze7=0;T93 Zq8=Zo;T0*Zr8=Zo;T0*Zs8=Zo;int Zn8=0;Ze7=Zo8((Z3)(((((C)->Z81)))+(ZQ5(1))));Zq8=((C)->Z71);(C->Z71)=((T93)(Zk(Ze7,sizeof(T0*))));
Z06=(Z3)(((((C)->Z81)))-(ZQ5(1)));(C->Z81)=Ze7;while(!((Z3)((Z06)<(ZQ5(0))))){Zr8=(Zq8)[Z06];while(!((Zr8)==((void*)(Zo)))){Zs8=((((T92*)Zr8))->Zr1);
Z16=(Z3)((Zs7((T7*)(((((T92*)Zr8))->Zq1))))%(((C)->Z81)));((((T92*)(((T92*)Zr8))))->Zr1)=((((C)->Z71))[Z16]);(((C)->Z71))[Z16]=(Zr8);
Zr8=Zs8;}Z06=(Z3)(((Z06))-(ZQ5(1)));}(C->Za1)=ZQ5(-1);}void ZZ8(T89*C,T2 a1){T2 Ze7=0;int Zn8=0;Ze7=Zo8(a1);(C->Z71)=((T93)(Zk(Ze7,sizeof(T0*))));
(C->Z81)=Ze7;(C->Za1)=ZQ5(-1);(C->Z91)=ZQ5(0);}void Z_8(ZL*C){(C->Zg2)=(Z3)(((((C)->Zg2)))+(ZQ5(1)));}T0*Z09(ZL*C){T0*R=Zo;R=Z19(((C)->Zh2),((C)->Zg2));
return R;}void ZD8(ZL*C,T0*a1){(C->Zh2)=a1;(C->Zg2)=Z29(((C)->Zh2));}T6 Z39(ZL*C){T6 R=0;R=((T6)(!(Z49(((C)->Zh2),((C)->Zg2)))));return
R;}void Z59(ZL*C){(C->Zg2)=Z29(((C)->Zh2));}T6 Z69(T0*a1,T0*a2){T6 R=0;if((a1)==((void*)(a2))){R=((T6)(1));}else if((a1)==((void*)(Zo))){
}else if((a2)==((void*)(Zo))){}else{R=((T6)(Zo6(((T7*)a1),a2)));}return R;}T0*Z79(T69*C){T0*R=Zo;{T74*n=((T74*)Zh(sizeof(*n)));*n=M74;
ZR8(n,(T0*)C);R=((T0*)n);}return R;}T2 Z89(T69*C,T0*a1){T2 R=0;T2 Z06=0;Z06=ZQ5(1);while(!((Z3)((Z06)>(((C)->Z91))))){if(Z69(a1,Z99(C,Z06))){
R=(Z3)(((R))+(ZQ5(1)));}Z06=(Z3)(((Z06))+(ZQ5(1)));}return R;}T0*Za9(T69*C,T2 a1){T0*R=Zo;Zb9(C,a1);R=(((T71*)(((C)->Zb1)))->Zq1);return
R;}T0*Zc9(T69*C,T0*a1){T0*R=Zo;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));Zg8=(((C)->Z71))[Z16];while(!(Zo6((T7*)(((((T71*)Zg8))->Zq1)),a1)))
{Zg8=((((T71*)Zg8))->Zr1);}R=((((T71*)Zg8))->Zp1);return R;}T0*Z99(T69*C,T2 a1){T0*R=Zo;Zb9(C,a1);R=(((T71*)(((C)->Zb1)))->Zp1);return
R;}void Zb9(T69*C,T2 a1){if((a1)==((Z3)(((((C)->Za1)))+(ZQ5(1))))){(C->Za1)=a1;(C->Zb1)=(((T71*)(((C)->Zb1)))->Zr1);while(!((((C)->Zb1))!=((void*)(Zo))))
{(C->Zc1)=(Z3)(((((C)->Zc1)))+(ZQ5(1)));(C->Zb1)=(((C)->Z71))[((C)->Zc1)];}}else if((a1)==(((C)->Za1))){}else if((a1)==(ZQ5(1))){(C->Za1)=ZQ5(1);
(C->Zc1)=ZQ5(0);(C->Zb1)=(((C)->Z71))[((C)->Zc1)];while(!((((C)->Zb1))!=((void*)(Zo)))){(C->Zc1)=(Z3)(((((C)->Zc1)))+(ZQ5(1)));(C->Zb1)=(((C)->Z71))[((C)->Zc1)];
}}else{Zb9(C,(T2)(ZQ5(1)));while(!((((C)->Za1))==(a1))){Zb9(C,(Z3)(((((C)->Za1)))+((T2)(ZQ5(1)))));}}}T0*Zd9(T69*C,T0*a1){T0*R=Zo;T2 Z06=0;
Z06=ZQ5(1);while(!(Z69(a1,Z99(C,Z06)))){Z06=(Z3)(((Z06))+(ZQ5(1)));}R=(((T71*)(((C)->Zb1)))->Zq1);return R;}void Ze9(T69*C){Zf9(C,Zb8(193));
}void Zg9(T69*C){T2 Z06=0;T2 Z16=0;T2 Ze7=0;T72 Zq8=Zo;T0*Zr8=Zo;T0*Zs8=Zo;int Zn8=0;Ze7=Zo8((Z3)(((((C)->Z81)))+(ZQ5(1))));Zq8=((C)->Z71);
(C->Z71)=(((void)(((C)->Z71))),((T72)(Zk(Ze7,sizeof(T0*)))));Z06=(Z3)(((((C)->Z81)))-(ZQ5(1)));(C->Z81)=Ze7;while(!((Z3)((Z06)<(ZQ5(0)))))
{Zr8=(Zq8)[Z06];while(!((Zr8)==((void*)(Zo)))){Zs8=((((T71*)Zr8))->Zr1);Z16=(Z3)((Zs7((T7*)(((((T71*)Zr8))->Zq1))))%(((C)->Z81)));((((T71*)(((T71*)Zr8))))->Zr1)=((((C)->Z71))[Z16]);
(((C)->Z71))[Z16]=(Zr8);Zr8=Zs8;}Z06=(Z3)(((Z06))-(ZQ5(1)));}(C->Za1)=ZQ5(-1);}void Zh9(T69*C,T0*a1,T0*a2){T2 Z16=0;T0*Zg8=Zo;(C->Za1)=ZQ5(-1);
if((((C)->Z81))==(((C)->Z91))){Zg9(C);}Z16=(Z3)((Zs7(((T7*)a2)))%(((C)->Z81)));{T71*n=((T71*)Zh(sizeof(*n)));*n=M71;Zi8(n,a1,a2,(((C)->Z71))[Z16]);
Zg8=((T0*)n);}(((C)->Z71))[Z16]=(Zg8);(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));}void Zi9(T69*C,T0*a1){T0*Zg8=Zo;T2 Z06=0;T2 Z16=0;Z06=((C)->Z91);
Zg8=(((C)->Z71))[Z16];while(!((Z3)((Z06)<=(ZQ5(0))))){while(!((Zg8)!=((void*)(Zo)))){Z16=(Z3)(((Z16))+(ZQ5(1)));Zg8=(((C)->Z71))[Z16];
}ZS7(a1,((((T71*)Zg8))->Zp1));Zg8=((((T71*)Zg8))->Zr1);Z06=(Z3)(((Z06))-(ZQ5(1)));}}void Zf9(T69*C,T2 a1){T2 Ze7=0;int Zn8=0;Ze7=Zo8(a1);
(C->Z71)=(((void)(((C)->Z71))),((T72)(Zk(Ze7,sizeof(T0*)))));(C->Z81)=Ze7;(C->Za1)=ZQ5(-1);(C->Z91)=ZQ5(0);}T0*Zj9(T69*C,T0*a1){T0*R=Zo;
T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));Zg8=(((C)->Z71))[Z16];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((T71*)Zg8))->Zq1)),a1))))))
{Zg8=((((T71*)Zg8))->Zr1);}if((Zg8)!=((void*)(Zo))){R=((((T71*)Zg8))->Zp1);}return R;}void Zk9(ZB*C,T0*a1,T0*a2,T0*a3){(C->Zp1)=a1;(C->Zq1)=a2;
(C->Zr1)=a3;}T0*Zl9(ZP*C,T0*a1){T0*R=Zo;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));Zg8=(((C)->Z71))[Z16];while(!(Zo6((T7*)(((((ZB*)Zg8))->Zq1)),a1)))
{Zg8=((((ZB*)Zg8))->Zr1);}R=((((ZB*)Zg8))->Zp1);return R;}void Zm9(ZP*C,T0*a1,T0*a2){T2 ZU8=0;T2 Z16=0;T0*Zg8=Zo;ZU8=Zs7(((T7*)a2));Z16=(Z3)((ZU8)%(((C)->Z81)));
Zg8=(((C)->Z71))[Z16];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((ZB*)Zg8))->Zq1)),a2)))))){Zg8=((((ZB*)Zg8))->Zr1);}if((Zg8)==((void*)(Zo))){
if((((C)->Z81))==(((C)->Z91))){Zn9(C);Z16=(Z3)((ZU8)%(((C)->Z81)));}{ZB*n=((ZB*)Zh(sizeof(*n)));*n=Z33;Zk9(n,a1,a2,(((C)->Z71))[Z16]);
Zg8=((T0*)n);}(((C)->Z71))[Z16]=(Zg8);(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));(C->Za1)=ZQ5(-1);}else{((((ZB*)(((ZB*)Zg8))))->Zp1)=(a1);
}}void Zn9(ZP*C){T2 Z06=0;T2 Z16=0;T2 Ze7=0;ZT Zq8=Zo;T0*Zr8=Zo;T0*Zs8=Zo;int Zn8=0;Ze7=Zo8((Z3)(((((C)->Z81)))+(ZQ5(1))));Zq8=((C)->Z71);
(C->Z71)=((ZT)(Zk(Ze7,sizeof(T0*))));Z06=(Z3)(((((C)->Z81)))-(ZQ5(1)));(C->Z81)=Ze7;while(!((Z3)((Z06)<(ZQ5(0))))){Zr8=(Zq8)[Z06];while(!((Zr8)==((void*)(Zo))))
{Zs8=((((ZB*)Zr8))->Zr1);Z16=(Z3)((Zs7((T7*)(((((ZB*)Zr8))->Zq1))))%(((C)->Z81)));((((ZB*)(((ZB*)Zr8))))->Zr1)=((((C)->Z71))[Z16]);(((C)->Z71))[Z16]=(Zr8);
Zr8=Zs8;}Z06=(Z3)(((Z06))-(ZQ5(1)));}(C->Za1)=ZQ5(-1);}T6 Zo9(ZP*C,T0*a1){T6 R=0;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));
Zg8=(((C)->Z71))[Z16];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((ZB*)Zg8))->Zq1)),a1)))))){Zg8=((((ZB*)Zg8))->Zr1);}R=((T6)((Zg8)!=((void*)(Zo))));
return R;}void Zp9(ZP*C,T2 a1){T2 Ze7=0;int Zn8=0;Ze7=Zo8(a1);(C->Z71)=((ZT)(Zk(Ze7,sizeof(T0*))));(C->Z81)=Ze7;(C->Za1)=ZQ5(-1);(C->Z91)=ZQ5(0);
}void Zq9(T64*C,T0*a1,T0*a2){T2 Z16=0;T0*Zg8=Zo;(C->Za1)=ZQ5(-1);if((((C)->Z81))==(((C)->Z91))){Zr9(C);}Z16=(Z3)((Zs7(((T7*)a2)))%(((C)->Z81)));
{T67*n=((T67*)Zh(sizeof(*n)));*n=M67;Zs9(n,a1,a2,(((C)->Z71))[Z16]);Zg8=((T0*)n);}(((C)->Z71))[Z16]=(Zg8);(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));
}T0*Zt9(T64*C,T0*a1){T0*R=Zo;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));Zg8=(((C)->Z71))[Z16];while(!(Zo6((T7*)(((((T67*)Zg8))->Zq1)),a1)))
{Zg8=((((T67*)Zg8))->Zr1);}R=((((T67*)Zg8))->Zp1);return R;}void Zu9(T64*C,T2 a1){T2 Ze7=0;int Zn8=0;Ze7=Zo8(a1);(C->Z71)=((T68)(Zk(Ze7,sizeof(T0*))));
(C->Z81)=Ze7;(C->Za1)=ZQ5(-1);(C->Z91)=ZQ5(0);}void Zr9(T64*C){T2 Z06=0;T2 Z16=0;T2 Ze7=0;T68 Zq8=Zo;T0*Zr8=Zo;T0*Zs8=Zo;int Zn8=0;Ze7=Zo8((Z3)(((((C)->Z81)))+(ZQ5(1))));
Zq8=((C)->Z71);(C->Z71)=((T68)(Zk(Ze7,sizeof(T0*))));Z06=(Z3)(((((C)->Z81)))-(ZQ5(1)));(C->Z81)=Ze7;while(!((Z3)((Z06)<(ZQ5(0))))){Zr8=(Zq8)[Z06];
while(!((Zr8)==((void*)(Zo)))){Zs8=((((T67*)Zr8))->Zr1);Z16=(Z3)((Zs7((T7*)(((((T67*)Zr8))->Zq1))))%(((C)->Z81)));((((T67*)(((T67*)Zr8))))->Zr1)=((((C)->Z71))[Z16]);
(((C)->Z71))[Z16]=(Zr8);Zr8=Zs8;}Z06=(Z3)(((Z06))-(ZQ5(1)));}(C->Za1)=ZQ5(-1);}T6 Zv9(T64*C,T0*a1){T6 R=0;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));
Zg8=(((C)->Z71))[Z16];while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((T67*)Zg8))->Zq1)),a1)))))){Zg8=((((T67*)Zg8))->Zr1);}R=((T6)((Zg8)!=((void*)(Zo))));
return R;}void Zw9(T64*C,T0*a1,T0*a2){Zq9(C,a1,a2);Zv8((T49*)(((C)->Zd1)),a2);}void Zx9(T64*C,T2 a1){Zu9(C,a1);{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;Zx8(n,a1);(C->Zd1)=((T0*)n);}}T0*Zy9(T64*C,T0*a1){T0*R=Zo;T2 Z16=0;T0*Zg8=Zo;Z16=(Z3)((Zs7(((T7*)a1)))%(((C)->Z81)));Zg8=(((C)->Z71))[Z16];
while(!((T6)(((Zg8)==((void*)(Zo)))||((T6)(Zo6((T7*)(((((T67*)Zg8))->Zq1)),a1)))))){Zg8=((((T67*)Zg8))->Zr1);}if((Zg8)!=((void*)(Zo))){
R=((((T67*)Zg8))->Zp1);}return R;}void Zs9(T67*C,T0*a1,T0*a2,T0*a3){(C->Zp1)=a1;(C->Zq1)=a2;(C->Zr1)=a3;}void Zz9(T79*C){T81 ZI8=Zo;if((((C)->Zt1))==(ZQ5(0))){
(C->Zs1)=ZI8;(C->Z81)=ZQ5(0);(C->Zt1)=ZQ5(-1);}else{ZK6(((C)->Zs1),((C)->Zt1));(C->Zt1)=(Z3)(((((C)->Zt1)))-(ZQ5(1)));}}T6 ZA9(T79*C,T2
a1){T6 R=0;R=((T6)((T6)(((Z3)((ZQ5(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->Zt1))))))));return R;}void ZB9(T79*C,T2 a1){ZO6(((C)->Zs1),a1,((C)->Zt1));
(C->Zt1)=(Z3)(((((C)->Zt1)))-(ZQ5(1)));}void ZC9(T79*C,T78 a1){T2 Ze7=0;if((Z3)(((Z3)(((((C)->Zt1)))+(ZQ5(1))))<=((Z3)(((((C)->Z81)))-(ZQ5(1)))))){
(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));}else if((((C)->Z81))==(ZQ5(0))){(C->Zs1)=((T81)(Zk(ZQ5(2),sizeof(T78))));(C->Z81)=ZQ5(2);(C->Zt1)=ZQ5(0);
}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));(C->Zs1)=ZI6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;(C->Zt1)=(Z3)(((((C)->Zt1)))+(ZQ5(1)));}
{T78 ZM6=a1;ZN6((((C)->Zs1))+(((C)->Zt1)),&(ZM6),sizeof(T78));}}T78 ZD9(T79*C){T78 R={Zo,Zo,0};{T78 ZL6;R=(*(ZL6=(((C)->Zs1))[ZQ5(0)],&ZL6));
}return R;}T2 ZE9(T79*C,T78 a1){T2 R=0;R=ZQ6(((C)->Zs1),a1,((C)->Zt1));return R;}void ZF9(T79*C,T2 a1){if((Z3)((((C)->Z81))<(a1))){(C->Zs1)=((T81)(Zk(a1,sizeof(T78))));
(C->Z81)=a1;}else if((Z3)((((C)->Z81))>(a1))){ZP6(((C)->Zs1),(T2)(ZQ5(0)),((C)->Zt1));}(C->Zt1)=ZQ5(-1);}void ZG9(T51*C){if(((C)->ZZ1)){
ZH9((T32*)(ZI9),((T3)'\n'));}}void ZJ9(T51*C,T0*a1){if(ZK9(a1)){ZL9(C,ZM9);ZL9(C,a1);ZL9(C,ZN9);ZO9(a1);}}void ZP9(T51*C,T0*a1,T0*a2){
ZL9(C,ZQ9);ZL9(C,a1);ZL9(C,ZR9);ZL9(C,a2);ZL9(C,ZN9);ZS9(a1,a2);}T0*ZT9=Zo;int ZU9=0;T0*ZV9(void){if(ZU9==0){ZU9=1;{{T39*n=((T39*)Zh(sizeof(*n)));
*n=M39;ZT9=((T0*)n);ZW9(n);}}}return ZT9;}void ZX9(T51*C,T0*a1,T0*a2){ZY9(((ZR*)a1),a2);if((((((ZR*)a1))->Z_1))!=(Zo)){ZL9(C,ZZ9);ZL9(C,a2);
ZL9(C,Z_9);}else{Z0a(Z1a);Z0a(a2);Z0a(ZN9);Zv(ZQ5(1));}}void Z2a(T3 a1){{T3 b1=a1;Z3a(b1,Z4a);}Z5a(Z4a);}void Z6a(T51*C,T0*a1,T0*a2){
ZL9(C,Z7a);ZL9(C,a2);ZL9(C,ZN9);Z8a(((T57*)a1),a2);}T0*Z9a(T0*a1,T0*a2){T0*R=Zo;int ZG7=0;if((T6)((ZB7(((T7*)Zaa),a1))||((T6)(ZB7(((T7*)Zba),a1))))){
Z0a(Zca);Z0a(a1);Z0a(Zda);if((a2)!=((void*)(Zo))){Z0a(Zea);Z0a(a2);Z2a(((T3)'\042'));}else{Z2a(((T3)'\056'));}Z2a(((T3)'\n'));}R=Zfa(a1);
if((T6)(((R)==((void*)(Zo)))&&((T6)(ZB7(((T7*)Zga),a1))))){R=Z9a(Zha,a2);if((T6)(((R)!=((void*)(Zo)))&&((T6)((Z3)((((((T7*)R))->Z91))>(ZQ5(9))))))){
Zia((T39*)(ZV9()),R);if((Z3)((((((T7*)R))->Z91))>(ZQ5(3)))){Zia((T39*)(ZV9()),R);}}}if((R)==((void*)(Zo))){if(ZB7(((T7*)Zaa),a1)){R=Zfa(Zaa);
if((R)!=((void*)(Zo))){Z0a(Zja(77,"The old \"SmallEiffel\" variable is not valid anymore. Please use SmartEiffel.\n"));}}else if(ZB7(((T7*)Zba),a1)){
R=Z9a(Zaa,a2);if((R)!=((void*)(Zo))){Z0a(Zja(133,"The old \"SmallEiffelDirectory\" variable is not valid anymore. Please use SmartEiffelDirectory or,\nbetter still, don\'t use it at all.\n"));
if((Z3)((((((T7*)R))->Z91))>(ZQ5(9)))){Zia((T39*)(ZV9()),R);if((Z3)((((((T7*)R))->Z91))>(ZQ5(3)))){Zia((T39*)(ZV9()),R);}}}}}if((R)==((void*)(Zo))){
Z0a(Zka);Z0a(a1);Z2a(((T3)'\175'));if((a2)!=((void*)(Zo))){Z0a(Zla);Z0a(a2);Z2a(((T3)'\042'));}Z0a(Zma);}return R;}void Zna(T51*C,T2 a1){
if(((C)->ZZ1)){Zoa((T32*)(ZI9),(T11)(a1));Zpa((T32*)(ZI9));}}T0*ZI9=Zo;void Z0a(T0*a1){Zqa(a1);Z5a(Z4a);}void Zra(T51*C,T0*a1){T2 Z06=0;
T0*Zsa=Zo;int ZG7=0;if((Z07(((T7*)a1)))==(((T3)'\n'))){Zu7(((T7*)a1),(T2)(ZQ5(1)));Zra(C,a1);}else if(Zv7(((T7*)a1),((T3)'\n'))){Z06=ZV6(((T7*)a1),((T3)'\n'));
Zsa=ZZ6(((T7*)a1),(Z3)(((Z06))+((T2)(ZQ5(1)))),((((T7*)a1))->Z91));Zu7(((T7*)a1),(Z3)((((Z3)(((((((T7*)a1))->Z91)))-(Z06))))+((T2)(ZQ5(1)))));
Zra(C,a1);Zra(C,Zsa);}else{ZL9(C,Zta);ZL9(C,a1);ZL9(C,ZN9);Zua(a1);}}void Zva(T2 a1){Zwa((T11)(a1));Z5a(Z4a);}void ZL9(T51*C,T0*a1){if(((C)->ZZ1)){
Zxa((T32*)(ZI9),a1);Zpa((T32*)(ZI9));}}T0*Zya=Zo;T0*Zza=Zo;T0*ZAa=Zo;int ZBa=0;T0*ZCa(void){if(ZBa==0){ZBa=1;{{T89*n=((T89*)Zh(sizeof(*n)));
*n=M89;ZAa=((T0*)n);ZZ8(n,(T2)(Zb8(2048)));}}}return ZAa;}T0*ZDa=Zo;T0*ZEa(void){if(ZU9==0){ZU9=1;{{T39*n=((T39*)Zh(sizeof(*n)));*n=M39;
ZT9=((T0*)n);ZW9(n);}}}return ZT9;}void ZFa(T87*C){ZT8((T89*)(ZCa()),(T10)(ZQ5(0)),ZGa);ZT8((T89*)(ZCa()),(T10)(ZQ5(1)),ZHa);ZT8((T89*)(ZCa()),(T10)(ZQ5(2)),ZIa);
ZT8((T89*)(ZCa()),(T10)(ZQ5(2)),ZJa);ZT8((T89*)(ZCa()),(T10)(ZQ5(3)),ZKa);ZT8((T89*)(ZCa()),(T10)(ZQ5(4)),ZLa);ZT8((T89*)(ZCa()),(T10)(ZQ5(4)),ZMa);
ZT8((T89*)(ZCa()),(T10)(ZQ5(5)),ZNa);ZT8((T89*)(ZCa()),(T10)(ZQ5(5)),ZOa);ZT8((T89*)(ZCa()),(T10)(ZQ5(6)),ZPa);ZT8((T89*)(ZCa()),(T10)(ZQ5(7)),ZQa);
ZT8((T89*)(ZCa()),(T10)(ZQ5(8)),ZRa);ZT8((T89*)(ZCa()),(T10)(ZQ5(9)),ZSa);ZT8((T89*)(ZCa()),(T10)(ZQ5(10)),ZTa);ZT8((T89*)(ZCa()),(T10)(ZQ5(11)),ZUa);
(C->Ze1)=ZQ5(11);if(!((((T88*)(ZDa))->Zl2))){ZVa(C);}}void ZVa(T87*C){T3 Zn7=0;T0*ZWa=Zo;T10 ZXa=0;T10 ZYa=0;T0*ZZa=Zo;T1 Zj7=0;T2 Z_a=0;
Z_a=(T2)(((C)->Ze1));{T57*n=((T57*)Zh(sizeof(*n)));*n=M57;ZZa=((T0*)n);}Z6a((T51*)(Z0b()),ZZa,Z1b((T39*)(ZEa())));if((((((T57*)ZZa))->Z_1))!=(Zo)){
if(((((T57*)ZZa))->Zh1)){Zj7=ZQ5(6);}while(!((Z1)((Zj7)>(ZQ5(4))))){Z2b(((T57*)ZZa));if(((((T57*)ZZa))->Zh1)){Zj7=ZQ5(5);}else{Zn7=((((T57*)ZZa))->Zg1);
}{int z1=Zj7;switch(z1){case 0:{int z2=Zn7;switch(z2){case 9:case 10:case 13:case 32:break;case 48:case 49:case 50:case 51:case 52:case
53:case 54:case 55:case 56:case 57:ZXa=(T10)(ZT5(Zn7));Zj7=ZQ5(1);break;default:;Zj7=ZQ5(6);}}break;case 1:{int z2=Zn7;switch(z2){case
48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZXa=(Z2)((((Z2)(((ZXa))*(ZQ5(10)))))+((T10)(ZT5(Zn7))));break;
case 34:ZWa=Zza;((((T7*)(((T7*)ZWa))))->Z91)=(ZQ5(0));Zj7=ZQ5(3);break;case 9:case 32:Zj7=ZQ5(2);break;default:;Zj7=ZQ5(6);}}break;case
2:{int z2=Zn7;switch(z2){case 34:ZWa=Zza;((((T7*)(((T7*)ZWa))))->Z91)=(ZQ5(0));Zj7=ZQ5(3);break;case 9:case 10:case 13:case 32:break;
default:;Zj7=ZQ5(6);}}break;case 3:{int z2=Zn7;switch(z2){case 34:ZYa=(Z2)(((ZYa))+(ZQ5(1)));if((Z3)(((T2)(ZXa))>(Z_a))){ZWa=(((void)((T94*)(Z3b()))),Z4b(ZWa));
ZT8((T89*)(ZCa()),ZXa,ZWa);(C->Ze1)=Ze6(((C)->Ze1),ZXa);}Zj7=ZQ5(4);break;case 9:case 10:case 13:Zj7=ZQ5(6);break;default:;Z26(((T7*)ZWa),Zn7);
}}break;case 4:{int z2=Zn7;switch(z2){case 35:Zj7=ZQ5(0);break;}}break;}}}Z5b(((T57*)ZZa));if((Zj7)==(ZQ5(6))){ZL9((T51*)(Z0b()),Zja(27,"Corrupted *.id file (after "));
Zna((T51*)(Z0b()),(T2)(ZYa));ZL9((T51*)(Z0b()),Zja(17," correct items).\n"));}ZL9((T51*)(Z0b()),Z6b);Zna((T51*)(Z0b()),(T2)(((C)->Ze1)));
ZL9((T51*)(Z0b()),Z7b);}}T0*Z8b=Zo;int Z9b=0;T0*Z0b(void){if(Z9b==0){Z9b=1;{{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;Z8b=((T0*)n);}}}return
Z8b;}T0*Zab=Zo;int Zbb=0;T0*Z3b(void){if(Zbb==0){Zbb=1;{{T94*n=((T94*)Zh(1));Zab=((T0*)n);Zcb(Zdb);Zcb(Zeb);Zcb(Zfb);Zcb(Zgb);Zcb(Zhb);
Zcb(ZPa);Zcb(Zib);Zcb(ZKa);Zcb(Zjb);Zcb(Zkb);Zcb(ZNa);Zcb(Zlb);Zcb(Zmb);Zcb(Znb);Zcb(Zob);Zcb(Zpb);Zcb(Zqb);Zcb(ZHa);Zcb(ZTa);Zcb(ZJa);
Zcb(ZIa);Zcb(ZUa);Zcb(Zrb);Zcb(Zsb);Zcb(Ztb);Zcb(ZGa);Zcb(Zub);Zcb(ZRa);Zcb(Zvb);Zcb(Zwb);Zcb(Zxb);Zcb(Zyb);Zcb(ZMa);Zcb(ZLa);Zcb(ZOa);
Zcb(Zzb);Zcb(ZAb);Zcb(ZQa);Zcb(ZBb);Zcb(ZCb);Zcb(ZDb);Zcb(ZEb);Zcb(ZFb);Zcb(ZGb);Zcb(ZHb);Zcb(ZIb);Zcb(ZJb);Zcb(ZKb);Zcb(ZLb);Zcb(ZMb);
Zcb(ZNb);Zcb(ZOb);Zcb(ZPb);Zcb(ZQb);Zcb(ZRb);Zcb(ZSb);Zcb(ZTb);Zcb(ZUb);Zcb(ZVb);Zcb(ZWb);Zcb(ZXb);Zcb(ZYb);Zcb(ZZb);Zcb(Z_b);Zcb(Z0c);
Zcb(Z1c);Zcb(Z2c);Zcb(Z3c);Zcb(Z4c);Zcb(Z5c);Zcb(Z6c);Zcb(Z7c);Zcb(Z8c);Zcb(Z9c);Zcb(Zac);Zcb(Zbc);Zcb(Zcc);Zcb(Zdc);Zcb(Zec);Zcb(Zfc);
Zcb(Zgc);Zcb(Zhc);Zcb(Zic);Zcb(Zjc);Zcb(Zkc);Zcb(Zlc);Zcb(Zmc);Zcb(Znc);Zcb(Zoc);Zcb(Zpc);Zcb(Zqc);Zcb(Zrc);Zcb(Zsc);Zcb(Ztc);Zcb(Zuc);
Zcb(Zvc);Zcb(Zwc);Zcb(Zxc);Zcb(Zyc);Zcb(Zzc);Zcb(ZAc);Zcb(ZBc);Zcb(ZCc);Zcb(ZDc);Zcb(ZEc);Zcb(ZFc);Zcb(ZGc);Zcb(ZHc);Zcb(ZIc);Zcb(ZJc);
Zcb(ZKc);Zcb(ZLc);Zcb(ZMc);Zcb(ZNc);Zcb(ZOc);Zcb(ZPc);Zcb(ZQc);Zcb(ZRc);Zcb(ZSc);Zcb(ZTc);Zcb(ZUc);Zcb(ZVc);Zcb(ZWc);Zcb(ZXc);Zcb(ZYc);
Zcb(ZZc);Zcb(Z_c);Zcb(Z0d);Zcb(Z1d);Zcb(Z2d);Zcb(Z3d);Zcb(Z4d);Zcb(Z5d);Zcb(Z6d);Zcb(Z7d);Zcb(Z8d);Zcb(Z9d);Zcb(Zad);Zcb(Zbd);Zcb(Zcd);
Zcb(Zdd);Zcb(Zed);Zcb(Zfd);Zcb(Zgd);Zcb(Zhd);Zcb(Zid);Zcb(Zjd);Zcb(Zkd);Zcb(Zld);Zcb(Zmd);Zcb(Znd);Zcb(Zod);Zcb(Zpd);Zcb(Zqd);Zcb(Zrd);
Zcb(Zsd);Zcb(Ztd);Zcb(Zud);Zcb(Zvd);Zcb(Zwd);Zcb(Zxd);Zcb(Zyd);Zcb(Zzd);Zcb(ZAd);Zcb(ZBd);Zcb(ZCd);Zcb(ZDd);Zcb(ZEd);Zcb(ZFd);Zcb(ZGd);
Zcb(ZHd);Zcb(ZId);Zcb(ZJd);Zcb(ZKd);Zcb(ZLd);Zcb(ZMd);Zcb(ZNd);Zcb(ZOd);Zcb(ZPd);Zcb(ZQd);Zcb(ZRd);Zcb(ZSd);Zcb(ZTd);Zcb(ZUd);Zcb(ZVd);
Zcb(ZWd);Zcb(ZXd);Zcb(ZYd);Zcb(ZZd);Zcb(Z_d);Zcb(Zfb);Zcb(Z0e);Zcb(ZSa);Zcb(Z1e);Zcb(Z2e);Zcb(Z3e);Zcb(Z4e);Zcb(Z5e);Zcb(Z6e);Zcb(Z7e);
Zcb(Z8e);Zcb(Z9e);Zcb(Zae);Zcb(Zbe);}}}return Zab;}T0*Zce(T10 a1){T0*R=Zo;R=ZW8((T89*)(ZCa()),a1);return R;}void Zde(T38*C){if((Z3)(((((T32*)(ZI9))->Zk1))>(ZQ5(0)))){
Zpa((T32*)(ZI9));}(C->Zf1)=((T6)(0));if((Z3)((((C)->Zk1))>=(((C)->Zl1)))){Zee(C);}(C->Zg1)=(((C)->Zi1))[((C)->Zk1)];(C->Zk1)=(Z3)(((((C)->Zk1)))+(ZQ5(1)));
(C->Zh1)=((T6)(((C)->Zj1)));}void Zee(T38*C){T3 Zfe=0;if((Z3)((((C)->Zl1))>(ZQ5(0)))){Zfe=(((C)->Zi1))[(Z3)(((((C)->Zl1)))-(ZQ5(1)))];
}(C->Zl1)=Zu5(((C)->Zi1),(T2)(Zb8(4096)));(C->Zk1)=ZQ5(0);if((Z3)((((C)->Zl1))<=(ZQ5(0)))){(C->Zj1)=((T6)(1));(((C)->Zi1))[(T2)(ZQ5(0))]=(Zfe);
(C->Zl1)=ZQ5(1);(C->Zk1)=ZQ5(1);}}void Zge(T38*C){(C->Zi1)=((T9)(Zk(Zb8(4096),sizeof(T3))));(C->Z81)=Zb8(4096);}void Zhe(T38*C,T0*a1){
T2 Z06=0;T6 Zie=0;T2 Zje=0;T2 Zke=0;T2 Zle=0;if((Z3)(((((T32*)(ZI9))->Zk1))>(ZQ5(0)))){Zpa((T32*)(ZI9));}Zle=((((T7*)a1))->Z91);while(!(Zie))
{Z06=((C)->Zk1);while(!((T6)(((Z3)((Z06)>=(((C)->Zl1))))||((T6)(((((C)->Zi1))[Z06])==(((T3)'\n'))))))){Z06=(Z3)(((Z06))+(ZQ5(1)));}if((Z3)((Z06)>(((C)->Zk1)))){
Zje=((((T7*)a1))->Z91);Zke=(Z3)((((Z3)(((Zje))+(Z06))))-(((C)->Zk1)));if((Z3)((((((T7*)a1))->Z81))<(Zke))){ZF7(((T7*)a1),Z66((Z3)(((Zje))*((T2)(ZQ5(2)))),Zke));
}Zw6(((((T7*)a1))->Zs1),Zje,((C)->Zi1),((C)->Zk1),(Z3)(((Z06))-((T2)(ZQ5(1)))));((((T7*)(((T7*)a1))))->Z91)=(Zke);}if((T6)(((Z3)((Z06)<(((C)->Zl1))))&&((T6)(((((C)->Zi1))[Z06])==(((T3)'\n')))))){
Zie=((T6)(1));(C->Zk1)=(Z3)(((Z06))+(ZQ5(1)));if((T6)(((Z3)((((((T7*)a1))->Z91))>(Zle)))&&((T6)((Z07(((T7*)a1)))==(((T3)'\015')))))){
Zu7(((T7*)a1),(T2)(ZQ5(1)));}}else{if(!(((C)->Zj1))){Zee(C);}Zie=((T6)(((C)->Zj1)));}}(C->Zf1)=((T6)(0));(C->Zh1)=((T6)(((C)->Zj1)));
}void Zme(T96*C,T78 a1,T0*a2){(C->Z11)=a1;{T44*n=((T44*)Zh(sizeof(*n)));*n=M44;Z88(n,(T2)(ZQ5(4)),(T2)(ZQ5(1)));(C->Zo1)=((T0*)n);}Z28((T44*)(((C)->Zo1)),a2);
}void Z5b(T57*C){Zne(((C)->Z02));(C->Z_1)=Zo;}void Z2b(T57*C){(C->Zf1)=((T6)(0));if((Z3)((((C)->Zk1))>=(((C)->Zl1)))){Zoe(C);}(C->Zg1)=(((C)->Zi1))[((C)->Zk1)];
(C->Zk1)=(Z3)(((((C)->Zk1)))+(ZQ5(1)));(C->Zh1)=((T6)(((C)->Zj1)));}void Zoe(T57*C){T3 Zfe=0;if((Z3)((((C)->Zl1))>(ZQ5(0)))){Zfe=(((C)->Zi1))[(Z3)(((((C)->Zl1)))-(ZQ5(1)))];
}(C->Zl1)=Zpe(((C)->Zi1),((C)->Z81),((C)->Z02));(C->Zk1)=ZQ5(0);if((Z3)((((C)->Zl1))<=(ZQ5(0)))){(C->Zj1)=((T6)(1));(((C)->Zi1))[(T2)(ZQ5(0))]=(Zfe);
(C->Zl1)=ZQ5(1);(C->Zk1)=ZQ5(1);}}void Zqe(T57*C,T0*a1){T2 Z06=0;T6 Zie=0;T2 Zje=0;T2 Zke=0;T2 Zle=0;Zle=((((T7*)a1))->Z91);while(!(Zie))
{Z06=((C)->Zk1);while(!((T6)(((Z3)((Z06)>=(((C)->Zl1))))||((T6)(((((C)->Zi1))[Z06])==(((T3)'\n'))))))){Z06=(Z3)(((Z06))+(ZQ5(1)));}if((Z3)((Z06)>(((C)->Zk1)))){
Zje=((((T7*)a1))->Z91);Zke=(Z3)((((Z3)(((Zje))+(Z06))))-(((C)->Zk1)));if((Z3)((((((T7*)a1))->Z81))<(Zke))){ZF7(((T7*)a1),Z66((Z3)(((Zje))*((T2)(ZQ5(2)))),Zke));
}Zw6(((((T7*)a1))->Zs1),Zje,((C)->Zi1),((C)->Zk1),(Z3)(((Z06))-((T2)(ZQ5(1)))));((((T7*)(((T7*)a1))))->Z91)=(Zke);}if((T6)(((Z3)((Z06)<(((C)->Zl1))))&&((T6)(((((C)->Zi1))[Z06])==(((T3)'\n')))))){
Zie=((T6)(1));(C->Zk1)=(Z3)(((Z06))+(ZQ5(1)));if((T6)(((Z3)((((((T7*)a1))->Z91))>(Zle)))&&((T6)((Z07(((T7*)a1)))==(((T3)'\015')))))){
Zu7(((T7*)a1),(T2)(ZQ5(1)));}}else{if(!(((C)->Zj1))){Zoe(C);}Zie=((T6)(((C)->Zj1)));}}(C->Zf1)=((T6)(0));(C->Zh1)=((T6)(((C)->Zj1)));
}void Z8a(T57*C,T0*a1){T8 Zre=Zo;Zre=ZK7(((T7*)a1));(C->Z02)=Zse(Zre);if((Zo!=((C)->Z02))){(C->Zf1)=((T6)(0));(C->Zh1)=((T6)(0));(C->Z_1)=a1;
if((((C)->Z81))==(ZQ5(0))){(C->Zi1)=((T9)(Zk(Zb8(4096),sizeof(T3))));(C->Z81)=Zb8(4096);}(C->Zj1)=((T6)(0));(C->Zk1)=ZQ5(0);(C->Zl1)=ZQ5(0);
}}void Zte(T57*C){((((T7*)((T7*)(Zue))))->Z91)=(ZQ5(0));Zqe(C,Zue);}T0*Zue=Zo;void Zve(T0*a1,T0*a2){if(!((((((T7*)a2))->Z91))==(ZQ5(0)))){
if(((((((T7*)a2))->Zs1))[ZQ5(0)])!=(((T3)'\040'))){if(!((((((T7*)a1))->Z91))==(ZQ5(0)))){ZA7(((T7*)a1),((T3)'\040'));}}Zb7(((T7*)a1),a2);
}}int Zwe=0;void Zxe(T39*C){if(Zwe==0){Zwe=1;{if(!((((((T7*)Zye))->Z91))==(ZQ5(0)))){if((((C)->Z82))!=((void*)(Zo))){ZL9((T51*)(Zze()),ZAe);
ZL9((T51*)(Zze()),((C)->Z82));(C->Z52)=((C)->Z82);(C->Z62)=((C)->Z92);(C->Z72)=((C)->Za2);if((((C)->Zb2))!=((void*)(Zo))){ZX6((T7*)(ZBe),((C)->Zb2));
}else if(!((((((T7*)ZCe))->Z91))==(ZQ5(0)))){ZX6((T7*)(ZBe),ZCe);}if((((C)->Zc2))!=((void*)(Zo))){ZX6((T7*)(ZDe),((C)->Zc2));}else if(!((((((T7*)ZEe))->Z91))==(ZQ5(0)))){
ZX6((T7*)(ZDe),ZEe);}ZL9((T51*)(Zze()),ZFe);}else{{T0*b1=((C)->Z52);Zb7((T7*)(ZGe),b1);}{T0*b1=ZHe;Zb7((T7*)(ZGe),b1);}ZIe((T77*)(ZJe));
}}}}}T0*ZKe=Zo;T0*ZLe=Zo;int ZMe=0;T0*ZNe(void){if(ZMe==0){ZMe=1;{ZLe=ZOe(10,ZPe,ZQe,ZRe,ZSe,ZTe,ZUe,ZVe,ZWe,ZXe,ZYe);}}return ZLe;}T6
ZZe=0;int Z_e=0;T6 Z0f(T39*C){if(Z_e==0){Z_e=1;{ZZe=((T6)(ZK9(Z1f)));}}return ZZe;}T0*Z2f=Zo;T0*Z3f(T39*C,T0*a1){T0*R=Zo;R=Zja(33,ZL3);
((((T7*)(((T7*)R))))->Z91)=(ZQ5(0));Zxe(C);if((T6)(((((C)->Z52))==((void*)(Z4f)))||((T6)((((C)->Z52))==((void*)(Z5f)))))){Zb7(((T7*)R),((C)->Z62));
Zve(R,ZBe);Z6f(C,R);Zve(R,Z7f);Zve(R,a1);Zve(R,Z8f);if(!((((((T7*)Zye))->Z91))==(ZQ5(0)))){Zve(R,Z9f);Zve(R,Zye);}Zve(R,Zaf);Zve(R,Zbf);
Zve(R,Zcf);Zve(R,Zdf);Zve(R,Zef);}else if((((C)->Z52))==((void*)(Zff))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,a1);Z26(((T7*)R),((T3)'\n'));
Zgf(C,R);Zb7(((T7*)R),Zhf);if(!(((C)->Z12))){Zve(R,Zif);}Z6f(C,R);{T7*C1=((T7*)a1);T0*b1=Zjf;Zu7(C1,((((T7*)b1))->Z91));}Zb7(((T7*)a1),Zkf(C));
Zve(R,a1);Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zlf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zef);Z6f(C,R);
Zve(R,a1);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zmf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);
Zve(R,Zef);Z6f(C,R);Zve(R,a1);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Znf))){Zb7(((T7*)R),((C)->Z62));
Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zef);Z6f(C,R);Zve(R,a1);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);Zof(C);}else if((((C)->Z52))==((void*)(Zpf))){
Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Z6f(C,R);Zve(R,a1);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zqf);Zve(R,Zef);Zve(R,Zcf);Zof(C);
}else if((((C)->Z52))==((void*)(Zrf))){Zb7(((T7*)R),((C)->Z62));Zve(R,Zsf(C,(T6)(0)));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zef);Zve(R,a1);Zve(R,Z8f);
Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);Zof(C);Z6f(C,R);}else if((((C)->Z52))==((void*)(Ztf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);
Zve(R,Zef);Z6f(C,R);Zve(R,a1);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);Zof(C);if(((C)->Z12)){Zve(R,Zuf);}}else if((((C)->Z52))==((void*)(Zvf))){
Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zef);Z6f(C,R);Zof(C);Zve(R,a1);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);}else
if((((C)->Z52))==((void*)(Zwf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zef);Z6f(C,R);Zve(R,a1);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);
Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zxf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zef);Z6f(C,R);Zve(R,a1);Zve(R,Z8f);
Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zyf))){Zb7(((T7*)R),Zzf);Zb7(((T7*)R),a1);Zb7(((T7*)R),((C)->Z62));Zu7(((T7*)R),(T2)(ZQ5(2)));
Zb7(((T7*)R),ZAf);Z6f(C,R);Z26(((T7*)R),((T3)'\040'));Zb7(((T7*)R),a1);Zu7(((T7*)R),(T2)(ZQ5(2)));}else if((((C)->Z52))==((void*)(ZBf))){
Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zef);Z6f(C,R);Zve(R,Zcf);Zve(R,a1);Zve(R,Z8f);Zve(R,Zbf);}return R;}void Z6f(T39*C,T0*a1){
T0*ZCf=Zo;ZCf=ZDf;if(((((T86*)(ZEf))->Zn1))==((void*)(Zo))){ZX6(((T7*)ZCf),ZM7((T7*)(ZFf())));ZL7(((T7*)ZCf));if((((C)->Z52))==((void*)(Zff))){
Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Znf))){Zve(a1,ZIf);Zb7(((T7*)a1),ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zmf))){
Zve(a1,ZJf);Zb7(((T7*)a1),ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zrf))){ZCf=ZM7((T7*)(ZFf()));ZL7(((T7*)ZCf));Zb7(((T7*)a1),ZKf);
Zve(a1,ZCf);}else if((((C)->Z52))==((void*)(Ztf))){Zve(a1,ZGf);Zve(a1,ZCf);}else if((((C)->Z52))==((void*)(Zvf))){Zve(a1,ZGf);Zve(a1,ZCf);
}else if((((C)->Z52))==((void*)(Zxf))){Zve(a1,ZGf);Zve(a1,ZCf);}else if((((C)->Z52))==((void*)(Zyf))){Zve(a1,ZCf);}else if((((C)->Z52))==((void*)(ZBf))){
if((((C)->ZP1))==((void*)(ZPe))){Zve(a1,ZGf);Zve(a1,ZLf);}else{Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}}}else{ZX6(((T7*)ZCf),(((T86*)(ZEf))->Zn1));
if((T6)(((((C)->Z52))==((void*)(Z4f)))||((T6)((((C)->Z52))==((void*)(Z5f)))))){Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zff))){
Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zlf))){Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zmf))){
Zve(a1,ZMf);Zb7(((T7*)a1),ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Znf))){Zve(a1,ZIf);Zb7(((T7*)a1),ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zpf))){
Zve(a1,ZGf);Zb7(((T7*)a1),ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zrf))){Zb7(((T7*)a1),ZKf);Zve(a1,ZCf);}else if((((C)->Z52))==((void*)(Ztf))){
Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zvf))){Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zwf))){
Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zxf))){Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}else if((((C)->Z52))==((void*)(Zyf))){
Zb7(((T7*)a1),ZCf);}else if((((C)->Z52))==((void*)(ZBf))){Zve(a1,ZGf);Zve(a1,ZCf);ZHf(C,a1);}}}void ZHf(T39*C,T0*a1){T0*ZNf=Zo;ZNf=ZOf(C);
if(!(Zh7(((T7*)a1),ZNf))){Zb7(((T7*)a1),ZNf);}}T0*ZPf(T39*C){T0*R=Zo;R=ZM7((T7*)(ZFf()));ZL7(((T7*)R));if((ZVe)==((void*)(((C)->ZP1)))){
while(!((Z3)((((((T7*)R))->Z91))<=(ZQ5(4))))){Zu7(((T7*)R),(T2)(ZQ5(1)));}}Zb7(((T7*)R),ZQf);return R;}void Zgf(T39*C,T0*a1){T0*ZRf=Zo;
T0*ZSf=Zo;T2 Z06=0;if(!((((((T7*)Z8f))->Z91))==(ZQ5(0)))){ZRf=Z67(((T7*)Z8f));((((T7*)((T7*)(Z8f))))->Z91)=(ZQ5(0));if((ZRf)!=((void*)(Zo))){
Z06=((((T44*)ZRf))->Z53);while(!((Z3)((Z06)>(((((T44*)ZRf))->Zt1))))){ZSf=ZW7(((T44*)ZRf),Z06);Zb7(((T7*)a1),ZTf);Zve(a1,ZBe);Zve(a1,ZSf);
Z26(((T7*)a1),((T3)'\n'));{T7*C1=((T7*)ZSf);T0*b1=Zjf;Zu7(C1,((((T7*)b1))->Z91));}Zb7(((T7*)ZSf),Zkf(C));Zve(Zbf,ZSf);Z06=(Z3)(((Z06))+(ZQ5(1)));
}}}}T0*ZUf=Zo;int ZVf=0;T0*Z1b(T39*C){if(ZVf==0){ZVf=1;{ZUf=ZPf(C);{T7*C1=((T7*)ZUf);T0*b1=ZQf;Zu7(C1,((((T7*)b1))->Z91));}Zb7(((T7*)ZUf),ZWf);
}}return ZUf;}void ZXf(T39*C){if((ZSe)==((void*)(((C)->ZP1)))){}else if((T6)(((((C)->Z52))==((void*)(Z4f)))||((T6)((((C)->Z52))==((void*)(Z5f)))))){
ZYf(C,ZZf);}else if((((C)->Z52))==((void*)(Znf))){}else if((((C)->Z52))==((void*)(Zpf))){}else if((((C)->Z52))==((void*)(Zrf))){}else
if((((C)->Z52))==((void*)(Ztf))){ZYf(C,ZZf);}else if((((C)->Z52))==((void*)(Zvf))){if((ZUe)==((void*)(((C)->ZP1)))){ZYf(C,Z_f);}else{
ZYf(C,ZZf);}}else if((((C)->Z52))==((void*)(Zwf))){ZYf(C,Z0g);}else if((((C)->Z52))==((void*)(Zxf))){}else if((((C)->Z52))==((void*)(Zyf))){
}else if((((C)->Z52))==((void*)(ZBf))){ZYf(C,ZZf);}else if((((C)->Z52))==((void*)(Zlf))){ZYf(C,ZZf);}else if((((C)->Z52))==((void*)(Zff))){
}else if((((C)->Z52))==((void*)(Zmf))){}}void Z1g(T39*C){T2 Z06=0;Z06=ZY7((T44*)(ZNe()),((C)->ZP1));if((Z3)((Z06)>((((T44*)(ZNe()))->Zt1)))){
(((void)((T51*)(Zze()))),Z0a(Z2g));(((void)((T51*)(Zze()))),Z0a((((T57*)(ZKe))->Z_1)));(((void)((T51*)(Zze()))),Z0a(Z3g));Z06=ZQ5(1);
while(!((Z3)((Z06)>((((T44*)(ZNe()))->Zt1))))){(((void)((T51*)(Zze()))),Z0a(ZW7((T44*)(ZNe()),Z06)));(((void)((T51*)(Zze()))),Z2a(((T3)'\n')));
Z06=(Z3)(((Z06))+(ZQ5(1)));}Zv(ZQ5(1));}else{Z4g(C,ZW7((T44*)(ZNe()),Z06));ZL9((T51*)(Zze()),Z5g);ZL9((T51*)(Zze()),((C)->ZP1));ZL9((T51*)(Zze()),ZN9);
}}void Z6g(T39*C){if((((C)->ZP1))==((void*)(Zo))){if(Z7g()){if(Z8g()){Z4g(C,ZPe);}else if(Z9g()){Z4g(C,ZRe);}else if(Zag()){Z4g(C,ZQe);
}else if(Zbg()){Z4g(C,ZTe);}else if(Zcg()){Z4g(C,ZUe);}else if(Zdg()){Z4g(C,ZXe);}}}Zeg(Zfg);}T0*Zgg=Zo;T0*Zhg=Zo;T0*Zig=Zo;int Zjg=0;
T0*Zkg(void){if(Zjg==0){Zjg=1;{{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;Zig=((T0*)n);Zlg(n);}}}return Zig;}T0*Zmg=Zo;void Zng(T0*a1,T0*a2){
T2 Z06=0;T2 Zj7=0;T2 Zog=0;T2 Zpg=0;T3 ZY6=0;T0*Zk7=Zo;T0*Zqg=Zo;Z06=ZQ5(1);while(!((Z3)((Z06)>(((((T7*)a2))->Z91))))){ZY6=(((((T7*)a2))->Zs1))[(Z06)-(ZQ5(1))];
{int z1=Zj7;switch(z1){case 0:if((ZY6)==(((T3)'\044'))){Zj7=ZQ5(1);Zog=Z06;}break;case 1:if((ZY6)==(((T3)'\173'))){Zj7=ZQ5(2);{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Z_6(n,(T2)(ZQ5(8)));Zqg=((T0*)n);}}else{Zj7=ZQ5(0);}break;case 2:if((ZY6)==(((T3)'\175'))){Zj7=ZQ5(3);Zpg=Z06;}else{Z26(((T7*)Zqg),ZY6);
}break;}}Z06=(Z3)(((Z06))+(ZQ5(1)));}if((Zj7)==(ZQ5(3))){Zk7=(((void)((T51*)(Zze()))),Z9a(Zqg,a1));if((Zk7)!=((void*)(Zo))){ZX6(((T7*)Zqg),a2);
Zw7(((T7*)a2),(Z3)(((Zog))-((T2)(ZQ5(1)))));Zb7(((T7*)a2),Zk7);Z17(((T7*)Zqg),Zpg);Zb7(((T7*)a2),Zqg);Zng(a1,a2);}}}T0*Zrg(T39*C,T0*a1){
T0*R=Zo;R=Zsg;((((T7*)(((T7*)R))))->Z91)=(ZQ5(0));Zxe(C);if((T6)(((((C)->Z52))==((void*)(Z4f)))||((T6)((((C)->Z52))==((void*)(Z5f)))))){
Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Ztg);Zve(R,Zug);Zve(R,a1);}else if((((C)->Z52))==((void*)(Zff))){Zb7(((T7*)R),((C)->Z62));
Zve(R,ZBe);Zve(R,Zdf);Zve(R,a1);}else if((((C)->Z52))==((void*)(Zlf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Ztg);Zve(R,a1);
}else if((((C)->Z52))==((void*)(Zmf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Zvg);Zve(R,a1);}else if((((C)->Z52))==((void*)(Znf))){
Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Ztg);Zve(R,a1);}else if((((C)->Z52))==((void*)(Zpf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);
Zve(R,Zdf);Zve(R,Ztg);Zve(R,a1);}else if((((C)->Z52))==((void*)(Zrf))){Zb7(((T7*)R),((C)->Z62));Zve(R,Zsf(C,(T6)(1)));Zve(R,ZBe);Zve(R,Zdf);
Zve(R,a1);}else if((((C)->Z52))==((void*)(Ztf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Ztg);Zve(R,a1);}else if((((C)->Z52))==((void*)(Zvf))){
Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Ztg);Zve(R,a1);}else if((((C)->Z52))==((void*)(Zwf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);
Zve(R,Zdf);Zve(R,Ztg);Zve(R,a1);}else if((((C)->Z52))==((void*)(Zxf))){Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Ztg);Zve(R,a1);
}else if((((C)->Z52))==((void*)(Zyf))){Zb7(((T7*)R),Zwg);Zb7(((T7*)R),a1);Zb7(((T7*)R),((C)->Z62));Zu7(((T7*)R),(T2)(ZQ5(2)));}else if((((C)->Z52))==((void*)(ZBf))){
Zb7(((T7*)R),((C)->Z62));Zve(R,ZBe);Zve(R,Zdf);Zve(R,Ztg);Zve(R,ZGf);Zve(R,a1);Zu7(((T7*)R),(T2)(ZQ5(2)));Zb7(((T7*)R),Zkf(C));Zve(R,a1);
}return R;}void Zxg(T39*C,T0*a1,T0*a2,T2 a3,T2 a4){T2 ZY6=0;T2 Zx6=0;T2 Zy6=0;T2 Zyg=0;if((Z3)((a3)>(a4))){}else if((Z3)((a3)<(ZQ5(9)))){
Zve(a1,a2);Zb7(((T7*)a1),Zzg);Zx6=Z86(ZQ5(9),a4);Zb6(Zx6,a1);Z26(((T7*)a1),((T3)'\135'));Zb7(((T7*)a1),Zkf(C));Zxg(C,a1,a2,(Z3)(((Zx6))+((T2)(ZQ5(1)))),a4);
}else if((a3)==(a4)){Zve(a1,a2);Zb6(a3,a1);Zb7(((T7*)a1),Zkf(C));}else{ZY6=(Z3)((((Z3)(((a4))-(a3))))+(ZQ5(1)));if((Z3)((ZY6)<=(ZQ5(10)))){
Zx6=(Z3)((a3)/(ZQ5(10)));Zy6=(Z3)((a4)%(ZQ5(10)));Zve(a1,a2);Zb6(Zx6,a1);Z26(((T7*)a1),((T3)'\133'));Z26(((T7*)a1),((T3)'0'));Z26(((T7*)a1),((T3)'\055'));
Zb6(Zy6,a1);Z26(((T7*)a1),((T3)'\135'));Zb7(((T7*)a1),Zkf(C));}else if((Z3)((ZY6)<(ZQ5(20)))){Zxg(C,a1,a2,a3,(Z3)(((a3))+((T2)(ZQ5(9)))));
Zxg(C,a1,a2,(Z3)(((a3))+((T2)(ZQ5(10)))),a4);}else{Zx6=(Z3)((a3)/(ZQ5(10)));Zy6=(Z3)(((Z3)(((a4))-(ZQ5(9))))/(ZQ5(10)));Zve(a1,a2);Z26(((T7*)a1),((T3)'\133'));
Zb6(Zx6,a1);Z26(((T7*)a1),((T3)'\055'));Zb6(Zy6,a1);Zb7(((T7*)a1),ZAg);Zb7(((T7*)a1),Zkf(C));Zyg=(Z3)((((Z3)(((Zy6))*(ZQ5(10)))))+(ZQ5(10)));
Zxg(C,a1,a2,Zyg,a4);}}}T0*ZBg=Zo;int ZCg=0;T0*ZDg(void){if(ZCg==0){ZCg=1;{{T76*n=((T76*)Zh(sizeof(*n)));*n=M76;ZBg=((T0*)n);ZEg(n);}}}
return ZBg;}T0*ZFg=Zo;int ZGg=0;T0*Zkf(T39*C){if(ZGg==0){ZGg=1;{if((T6)(((((C)->Z52))==((void*)(Z4f)))||((T6)((((C)->Z52))==((void*)(Z5f)))))){
ZFg=ZHg;}else if((((C)->Z52))==((void*)(Zff))){ZFg=ZIg;}else if((((C)->Z52))==((void*)(Zlf))){ZFg=ZHg;}else if((((C)->Z52))==((void*)(Zmf))){
ZFg=ZIg;}else if((((C)->Z52))==((void*)(Znf))){ZFg=ZIg;}else if((((C)->Z52))==((void*)(Zpf))){ZFg=ZIg;}else if((((C)->Z52))==((void*)(Zrf))){
ZFg=ZHg;}else if((((C)->Z52))==((void*)(Ztf))){ZFg=ZHg;}else if((((C)->Z52))==((void*)(Zvf))){ZFg=ZHg;}else if((((C)->Z52))==((void*)(Zwf))){
ZFg=ZHg;}else if((((C)->Z52))==((void*)(Zxf))){ZFg=ZHg;}else if((((C)->Z52))==((void*)(Zyf))){ZFg=ZIg;ZH7(((T7*)ZFg));}else if((((C)->Z52))==((void*)(ZBf))){
ZFg=ZHg;}}}return ZFg;}void ZW9(T39*C){T0*ZJg=Zo;T0*ZKg=Zo;T2 Z06=0;T6 ZLg=0;T6 ZMg=0;ZNg((T47*)(Zkg()));if((((T47*)(Zkg()))->Zo2)){ZX6((T7*)(ZOg),(((T47*)(Zkg()))->Z_1));
}(C->Z42)=ZQ5(1);ZKg=ZPg(C);Z06=ZQ5(0);while(!((T6)(((T6)((ZLg)||((T6)((Z3)((Z06)>(((((T49*)ZKg))->Zt1)))))))||((T6)(((((T7*)((((((T49*)ZKg))->Zs1))[Z06]))->Z91))==(ZQ5(0)))))))
{ZJg=(((((T49*)ZKg))->Zs1))[Z06];if(ZK9(ZJg)){(C->ZB1)=ZJg;ZQg(C);ZLg=((T6)(1));}Z06=(Z3)(((Z06))+(ZQ5(1)));}if((T6)((!(ZLg))||((T6)((((T53*)(ZRg))->ZB2))))){
if((ZSg)!=((void*)(Zo))){(C->ZB1)=ZSg;}else{(C->ZB1)=ZTg;}if((((T55*)(Zhg))->Zp1)){Z6g(C);}else{if((ZSg)!=((void*)(Zo))){(((void)((T51*)(Zze()))),Z0a(ZUg));
(((void)((T51*)(Zze()))),Z0a(ZVg));(((void)((T51*)(Zze()))),Z0a(ZWg));ZMg=((T6)(1));Z06=ZQ5(1);}else{Z06=ZQ5(0);}if((Z3)((Z06)<=(((((T49*)ZKg))->Zt1)))){
(((void)((T51*)(Zze()))),Z0a(ZXg));while(!((T6)(((Z3)((Z06)>(((((T49*)ZKg))->Zt1))))||((T6)(((((T7*)((((((T49*)ZKg))->Zs1))[Z06]))->Z91))==(ZQ5(0)))))))
{(((void)((T51*)(Zze()))),Z0a(ZYg));(((void)((T51*)(Zze()))),Z0a((((((T49*)ZKg))->Zs1))[Z06]));(((void)((T51*)(Zze()))),Z2a(((T3)'\n')));
Z06=(Z3)(((Z06))+(ZQ5(1)));}ZMg=((T6)(1));}if(!(ZMg)){(((void)((T51*)(Zze()))),Z0a(ZZg));(((void)((T51*)(Zze()))),Z0a(ZVg));(((void)((T51*)(Zze()))),Z0a(Z_g));
}if(!((((T55*)(Zhg))->Zp1))){Zv(ZQ5(1));}}}ZL9((T51*)(Zze()),Z0h);ZL9((T51*)(Zze()),((C)->ZB1));ZG9((T51*)(Zze()));}T0*ZPg(T39*C){T0*R=Zo;
T2 Z06=0;T0*ZG7=Zo;T0*Z1h=Zo;(C->ZB1)=ZSg;R=Z2h();Z06=ZQ5(0);if((((C)->ZB1))!=((void*)(Zo))){if(((Z3)(((((((T49*)R))->Zt1)))+(ZQ5(1))))==(ZQ5(0))){
Zv8(((T49*)R),ZM7((T7*)(((C)->ZB1))));}else{ZX6((T7*)((((((T49*)R))->Zs1))[ZQ5(0)]),((C)->ZB1));}Z06=(Z3)(((Z06))+(ZQ5(1)));}Z3h(&(((C)->Zx1)));
Z4h(Z5h);Z6h(&(((C)->Zx1)));if(Z7g()){if((T6)((Z8g())||((T6)(Z9g())))){Z1h=Z7h;if((Z1h)!=((void*)(Zo))){if((Z3)((((((T49*)R))->Zt1))>=(Z06))){
ZX6((T7*)((((((T49*)R))->Zs1))[Z06]),Z1h);Zb7((T7*)((((((T49*)R))->Zs1))[Z06]),Z8h);}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,Z1h);
ZG7=((T0*)n);}Zb7(((T7*)ZG7),Z9h);Zv8(((T49*)R),ZG7);}Z06=(Z3)(((Z06))+(ZQ5(1)));}if(ZK9(Zah)){Z4g(C,ZYe);ZG7=Zbh;if((Z3)((((((T49*)R))->Zt1))>=(Z06))){
ZX6((T7*)((((((T49*)R))->Zs1))[Z06]),ZG7);}else{Zv8(((T49*)R),ZM7(((T7*)ZG7)));}Z06=(Z3)(((Z06))+(ZQ5(1)));}ZG7=Zch;if((Z3)((((((T49*)R))->Zt1))>=(Z06))){
ZX6((T7*)((((((T49*)R))->Zs1))[Z06]),ZG7);}else{Zv8(((T49*)R),ZM7(((T7*)ZG7)));}Z06=(Z3)(((Z06))+(ZQ5(1)));}else if(Zag()){Z1h=Z2f;if((Z1h)!=((void*)(Zo))){
if((Z3)((((((T49*)R))->Zt1))>=(Z06))){ZX6((T7*)((((((T49*)R))->Zs1))[Z06]),Z1h);Zb7((T7*)((((((T49*)R))->Zs1))[Z06]),Zdh);}else{{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZX6(n,Z1h);ZG7=((T0*)n);}Zb7(((T7*)ZG7),Zeh);Zv8(((T49*)R),ZG7);}Z06=(Z3)(((Z06))+(ZQ5(1)));}ZG7=Zfh;if((Z3)((((((T49*)R))->Zt1))>=(Z06))){
ZX6((T7*)((((((T49*)R))->Zs1))[Z06]),ZG7);}else{Zv8(((T49*)R),ZM7(((T7*)ZG7)));}Z06=(Z3)(((Z06))+(ZQ5(1)));}else if(Zbg()){}else if(Zcg()){
}else if(Zdg()){}}if((((C)->ZD1))!=((void*)(Zo))){Zgh(((C)->ZD1),Zhh);if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){if((Z3)((((((T49*)R))->Zt1))>=(Z06))){
ZX6((T7*)((((((T49*)R))->Zs1))[Z06]),Z5h);}else{Zv8(((T49*)R),ZM7((T7*)(Z5h)));}Z06=(Z3)(((Z06))+(ZQ5(1)));}}while(!((Z3)((Z06)>(((((T49*)R))->Zt1)))))
{((((T7*)((T7*)((((((T49*)R))->Zs1))[Z06]))))->Z91)=(ZQ5(0));Z06=(Z3)(((Z06))+(ZQ5(1)));}return R;}void Zia(T39*C,T0*a1){Zih(C);Zjh(a1);
ZX6(((T7*)a1),Z5h);}T0*Zze(void){if(Z9b==0){Z9b=1;{{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;Z8b=((T0*)n);}}}return Z8b;}T0*Zkh=Zo;void ZYf(T39*C,T0*a1){
((((T7*)((T7*)(Zmg))))->Z91)=(ZQ5(0));if((T6)(((T6)(((((C)->Z52))==((void*)(Zff)))||((T6)((((C)->Z52))==((void*)(Zpf))))))||((T6)((((C)->Z52))==((void*)(Znf)))))){
}else{if(((((((T7*)a1))->Zs1))[(ZQ5(1))-(ZQ5(1))])!=(((T3)'\055'))){if((T6)((!(Zv7(((T7*)a1),((T3)'\057'))))&&((T6)(!(Zv7(((T7*)a1),((T3)'\134'))))))){
ZX6((T7*)(Zmg),Zlh);}}}Zq7((T7*)(Zmg),a1);ZA7((T7*)(Zmg),((T3)'\040'));Zmh(Zcf,Zmg);}void Znh(T39*C,T0*a1,T0*a2){if((((C)->ZP1))==((void*)(ZXe))){
Zb7(((T7*)a1),Zoh);}Zb7(((T7*)a1),((C)->ZC1));Zb7(((T7*)a1),a2);Zb7(((T7*)a1),ZOf(C));}T0*ZOg=Zo;T0*ZEf=Zo;void Zph(T39*C){T0*Z06=Zo;
Z06=Zqh((T53*)(ZRg),Zrh);if((Z06)!=((void*)(Zo))){while(!(Zsh(Z06))){Zth(C,Zuh((T53*)(ZRg),Zrh,Zvh(Z06)));Zwh(Z06);}}}T0*Zxh=Zo;int Zyh=0;
T0*ZOf(T39*C){if(Zyh==0){Zyh=1;{if((ZVe)==((void*)(((C)->ZP1)))){Zxh=Zzh;ZH7(((T7*)Zxh));}else if((ZXe)==((void*)(((C)->ZP1)))){Zxh=Zzh;
ZH7(((T7*)Zxh));}else if((ZWe)==((void*)(((C)->ZP1)))){Zxh=Zzh;}else if((ZQe)==((void*)(((C)->ZP1)))){Zxh=Zzh;}else if((ZRe)==((void*)(((C)->ZP1)))){
Zxh=Zzh;}else if((ZYe)==((void*)(((C)->ZP1)))){Zxh=ZAh;}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zxh=((T0*)n);Z_6(n,(T2)(ZQ5(4)));}}}}return
Zxh;}void Z4g(T39*C,T0*a1){(C->ZP1)=a1;(C->Z22)=Zo;(C->Z32)=Zo;}T0*ZBh=Zo;int ZCh=0;T0*ZDh(void){if(ZCh==0){ZCh=1;{ZBh=ZOe(14,Z4f,Z5f,
Zff,Zlf,Zmf,Znf,Zpf,Zrf,Ztf,Zvf,Zwf,Zxf,Zyf,ZBf);}}return ZBh;}void Zth(T39*C,T0*a1){if((((C)->Zd2))==((void*)(Zo))){{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;Zx8(n,(T2)(ZQ5(4)));(C->Zd2)=((T0*)n);}}Zv8((T49*)(((C)->Zd2)),a1);}T0*ZRg=Zo;void Zmh(T0*a1,T0*a2){T0*ZEh=Zo;ZEh=ZFh;Zr7(((T7*)ZEh),((T3)'\040'),(T2)(ZQ5(1)));
Zb7(((T7*)ZEh),a2);if(!(Zh7(((T7*)a1),ZEh))){Z26(((T7*)ZEh),((T3)'\040'));if(!(Zf7(((T7*)Zef),ZEh))){Z17(((T7*)ZEh),(T2)(ZQ5(1)));if(!(Zp7(((T7*)Zef),ZEh))){
Zve(a1,a2);}}}}int ZGh=0;void Zof(T39*C){if(ZGh==0){ZGh=1;{ZXf(C);}}}T0*ZSg=Zo;T0*ZHh=Zo;int ZIh=0;T0*Z2h(void){if(ZIh==0){ZIh=1;{{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;ZHh=((T0*)n);Zx8(n,(T2)(ZQ5(4)));}}}return ZHh;}T0*ZJe=Zo;void ZJh(T39*C,T0*a1,T0*a2,T0*a3){T2 Z06=0;(C->ZB1)=Zo;Z06=ZY7((T44*)(ZDh()),a1);
(C->Z52)=ZW7((T44*)(ZDh()),Z06);if((a2)==((void*)(Zo))){(C->Z62)=((C)->Z52);}else{(C->Z62)=a2;}if((a3)==((void*)(Zo))){(C->Z72)=((C)->Z52);
}else{(C->Z72)=a3;}(C->Z42)=ZQ5(2);}void ZKh(T39*C,T0*a1,T0*a2,T2 a3){T2 Z06=0;T6 ZLh=0;if(Z76(a3,(T2)(ZQ5(3)),(T2)(ZQ5(99)))){if((ZPe)==((void*)(((C)->ZP1)))){
ZLh=((T6)(1));}else if((ZRe)==((void*)(((C)->ZP1)))){ZLh=((T6)(1));}}if(ZLh){Zxg(C,a1,a2,(T2)(ZQ5(1)),a3);}else{Z06=ZQ5(1);while(!((Z3)((Z06)>(a3))))
{Zve(a1,a2);Zb6(Z06,a1);Zb7(((T7*)a1),Zkf(C));Z06=(Z3)(((Z06))+(ZQ5(1)));}}}T0*Z7h=Zo;int ZMh=0;void Zih(T39*C){if(ZMh==0){ZMh=1;{T0*ZG7=Zo;
T3 ZNh=0;ZG7=((C)->ZP1);if((ZG7)==((void*)(Zo))){}else if((ZG7)==((void*)(ZPe))){ZNh=((T3)'U');}else if((T6)(((T6)(((ZG7)==((void*)(ZQe)))||((T6)((ZG7)==((void*)(ZVe))))))||((T6)((ZG7)==((void*)(ZWe)))))){
ZNh=((T3)'W');}else if((ZG7)==((void*)(ZSe))){ZNh=((T3)'U');}else if((ZG7)==((void*)(ZTe))){ZNh=((T3)'M');}else if((ZG7)==((void*)(ZUe))){
ZNh=((T3)'A');}else if((ZG7)==((void*)(ZXe))){ZNh=((T3)'V');}else if((ZG7)==((void*)(ZRe))){ZNh=((T3)'C');}else if((ZG7)==((void*)(ZYe))){
ZNh=((T3)'U');}if((ZG7)!=((void*)(Zo))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(ZNh);}}}}T0*Zsf(T39*C,T6 a1){T0*R=Zo;if(Z0f(C)){
R=ZPh;}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(0)));R=((T0*)n);}Zb7(((T7*)R),ZQh);if(a1){Zb7(((T7*)R),ZRh);}else{Zb7(((T7*)R),ZSh);
}Zb7(((T7*)R),ZTh);Zb7(((T7*)R),ZUh);}return R;}void ZQg(T39*C){T0*ZG7=Zo;ZVh((T76*)(ZDg()),((C)->ZB1));if(((((T76*)(ZDg()))->Z_1))!=(Zo)){
ZWh((T53*)(ZRg));if(!((((T55*)(Zhg))->Zp1))){if(!(ZXh((T53*)(ZRg),ZYh,ZZh))){{T0*b1=Zja(31,"\"[General] bin\" key is missing.");Zb7((T7*)(ZGe),b1);
}Z_h((T77*)(ZJe));}else{(C->ZC1)=Zuh((T53*)(ZRg),ZYh,ZZh);Zng(Zo,((C)->ZC1));}if(!(ZXh((T53*)(ZRg),ZYh,Z0i))){{T0*b1=Zja(31,"\"[General] sys\" key is missing.");
Zb7((T7*)(ZGe),b1);}Z_h((T77*)(ZJe));}else{(C->ZD1)=Zuh((T53*)(ZRg),ZYh,Z0i);Zng(Zo,((C)->ZD1));}if(!(ZXh((T53*)(ZRg),ZYh,Z1i))){{T0*b1=Zja(33,"\"[General] short\" key is missing.");
Zb7((T7*)(ZGe),b1);}Z_h((T77*)(ZJe));}else{(C->ZE1)=Zuh((T53*)(ZRg),ZYh,Z1i);Zng(Zo,((C)->ZE1));}if(!(ZXh((T53*)(ZRg),ZYh,Z2i))){{T0*b1=Zja(30,"\"[General] os\" key is missing.");
Zb7((T7*)(ZGe),b1);}Z_h((T77*)(ZJe));}else{ZG7=Zuh((T53*)(ZRg),ZYh,Z2i);if(!(Z58((T44*)(ZNe()),ZG7))){{T0*b1=Z3i;Zb7((T7*)(ZGe),b1);}
{T0*b1=ZG7;Zb7((T7*)(ZGe),b1);}{T0*b1=Z4i;Zb7((T7*)(ZGe),b1);}Z5i((T77*)(ZJe));}ZG7=ZW7((T44*)(ZNe()),ZY7((T44*)(ZNe()),ZG7));Z4g(C,ZG7);
}if(((((T77*)(ZJe))->Zu1))!=(ZQ5(0))){{T0*b1=Zja(69,"The configuration file seems invalid. Correct the above errors first.");Zb7((T7*)(ZGe),b1);
}Z5i((T77*)(ZJe));}Z1g(C);}}Zph(C);}T0*Z6i(T39*C,T0*a1,T2 a2){T0*R=Zo;T0*Z7i=Zo;T0*Z8i=Zo;T2 Z06=0;T0*Z9i=Zo;R=Zai;((((T7*)(((T7*)R))))->Z91)=(ZQ5(0));
Zxe(C);if((T6)(((((C)->Z52))==((void*)(Z4f)))||((T6)((((C)->Z52))==((void*)(Z5f)))))){Zb7(((T7*)R),((C)->Z72));Zve(R,ZDe);Z6f(C,R);ZKh(C,R,a1,a2);
if(!((((((T7*)Z8f))->Z91))==(ZQ5(0)))){Zve(R,Zbi);Zve(R,Z8f);}if(!((((((T7*)Zye))->Z91))==(ZQ5(0)))){Zve(R,Zci);Zve(R,Zye);}Zve(R,Zdi);
Zve(R,Zbf);Zve(R,Zcf);Zve(R,Zdf);Zve(R,Zef);}else if((((C)->Z52))==((void*)(Zff))){Zgf(C,R);Zb7(((T7*)R),((C)->Z72));if(!(((C)->Z12))){
Zve(R,Zif);}Zve(R,ZDe);Z6f(C,R);if((Z3)((a2)<(ZQ5(4)))){ZKh(C,R,a1,a2);}else{Z9i=a1;Zb7(((T7*)Z9i),Zei);Zve(R,ZN7(((T7*)Zja(1,Zg3)),Z9i));
{ZR*n=((ZR*)Zh(sizeof(*n)));*n=Z93;Zfi(n);Z8i=((T0*)n);}ZX9((T51*)(Zze()),Z8i,Z9i);Zu7(((T7*)Z9i),(T2)(ZQ5(4)));Z06=ZQ5(1);while(!((Z3)((Z06)>(a2))))
{Zgi(((ZR*)Z8i),Z9i);Zhi(((ZR*)Z8i),(T11)(Z06));Zgi(((ZR*)Z8i),ZIg);Zii(((ZR*)Z8i),((T3)'\n'));Z06=(Z3)(((Z06))+(ZQ5(1)));}Zji(((ZR*)Z8i));
}Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zlf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Zve(R,ZDe);Zve(R,Zef);Z6f(C,R);ZKh(C,R,a1,a2);
Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zmf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Zve(R,ZDe);Zve(R,Zef);
Z6f(C,R);ZKh(C,R,a1,a2);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Znf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);
Zve(R,ZDe);Zve(R,Zef);Z6f(C,R);ZKh(C,R,a1,a2);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);Zof(C);}else if((((C)->Z52))==((void*)(Zpf))){
Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Z6f(C,R);ZKh(C,R,a1,a2);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zki);Zve(R,ZDe);Zve(R,Zef);Zve(R,Zcf);
Zof(C);}else if((((C)->Z52))==((void*)(Zrf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Zve(R,ZDe);Zve(R,a1);Zb7(((T7*)R),Zli);Zve(R,Z8f);Zve(R,Zye);
Zve(R,Zbf);Zve(R,Zcf);Z6f(C,R);if(!(((C)->Z12))){Zb7(((T7*)R),Zmi);}}else if((((C)->Z52))==((void*)(Ztf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);
Zve(R,ZDe);Zve(R,Zef);Z6f(C,R);ZKh(C,R,a1,a2);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);if(((C)->Z12)){Zve(R,Zni);}Zof(C);}else if((((C)->Z52))==((void*)(Zvf))){
Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Zve(R,ZDe);Zve(R,Zef);Z6f(C,R);Zof(C);ZKh(C,R,a1,a2);Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);
}else if((((C)->Z52))==((void*)(Zwf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Zve(R,ZDe);Zve(R,Zef);Z6f(C,R);ZKh(C,R,a1,a2);Zve(R,Z8f);Zve(R,Zye);
Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zxf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Zve(R,ZDe);Zve(R,Zef);Z6f(C,R);ZKh(C,R,a1,a2);
Zve(R,Z8f);Zve(R,Zye);Zve(R,Zbf);Zve(R,Zcf);}else if((((C)->Z52))==((void*)(Zyf))){{ZR*n=((ZR*)Zh(sizeof(*n)));*n=Z93;Zfi(n);Z7i=((T0*)n);
}ZX9((T51*)(Zze()),Z7i,Zoi);Zgi(((ZR*)Z7i),Zpi);((((T7*)(((T7*)R))))->Z91)=(ZQ5(0));Z6f(C,R);Zgi(((ZR*)Z7i),R);Zii(((ZR*)Z7i),((T3)'\040'));
Z06=ZQ5(1);while(!((Z3)((Z06)>=(a2)))){Zgi(((ZR*)Z7i),a1);Zhi(((ZR*)Z7i),(T11)(Z06));Zgi(((ZR*)Z7i),Zqi);Z06=(Z3)(((Z06))+(ZQ5(1)));}
Zgi(((ZR*)Z7i),a1);Zhi(((ZR*)Z7i),(T11)(Z06));Zii(((ZR*)Z7i),((T3)'\n'));Zji(((ZR*)Z7i));((((T7*)(((T7*)R))))->Z91)=(ZQ5(0));Zb7(((T7*)R),Zri);
}else if((((C)->Z52))==((void*)(ZBf))){Zb7(((T7*)R),((C)->Z72));Zve(R,Zdf);Zve(R,ZDe);Zve(R,Zef);Z6f(C,R);Zve(R,Zcf);ZKh(C,R,a1,a2);Zve(R,Z8f);
Zve(R,Zbf);}return R;}void Zsi(T39*C,T0*a1){T0*Zti=Zo;if((T6)(((((C)->Z52))==((void*)(Zff)))||((T6)((((C)->Z52))==((void*)(Zrf)))))){
Zti=ZN7(((T7*)a1),Zei);ZJ9((T51*)(Zze()),Zti);}}T0*Zui=Zo;int Zvi=0;T0*Zwi(void){if(Zvi==0){Zvi=1;{Zui=ZOe(6,Z5f,Zpf,Znf,Zmf,Zxf,Zxi);
}}return Zui;}T0*Zyi(T76*C,T2 a1){T0*R=Zo;if((Z3)((a1)<=((((T49*)(((C)->Zn2)))->Zt1)))){R=((((T49*)(((C)->Zn2)))->Zs1))[a1];((((T7*)(((T7*)R))))->Z91)=(ZQ5(0));
}else{{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,Zb8(128));R=((T0*)n);}Zv8((T49*)(((C)->Zn2)),R);}return R;}void ZEg(T76*C){{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;Zx8(n,(T2)(Zb8(6000)));(C->Zn2)=((T0*)n);}}T0*Zzi(void){if(Zbb==0){Zbb=1;{{T94*n=((T94*)Zh(1));Zab=((T0*)n);Zcb(Zdb);Zcb(Zeb);
Zcb(Zfb);Zcb(Zgb);Zcb(Zhb);Zcb(ZPa);Zcb(Zib);Zcb(ZKa);Zcb(Zjb);Zcb(Zkb);Zcb(ZNa);Zcb(Zlb);Zcb(Zmb);Zcb(Znb);Zcb(Zob);Zcb(Zpb);Zcb(Zqb);
Zcb(ZHa);Zcb(ZTa);Zcb(ZJa);Zcb(ZIa);Zcb(ZUa);Zcb(Zrb);Zcb(Zsb);Zcb(Ztb);Zcb(ZGa);Zcb(Zub);Zcb(ZRa);Zcb(Zvb);Zcb(Zwb);Zcb(Zxb);Zcb(Zyb);
Zcb(ZMa);Zcb(ZLa);Zcb(ZOa);Zcb(Zzb);Zcb(ZAb);Zcb(ZQa);Zcb(ZBb);Zcb(ZCb);Zcb(ZDb);Zcb(ZEb);Zcb(ZFb);Zcb(ZGb);Zcb(ZHb);Zcb(ZIb);Zcb(ZJb);
Zcb(ZKb);Zcb(ZLb);Zcb(ZMb);Zcb(ZNb);Zcb(ZOb);Zcb(ZPb);Zcb(ZQb);Zcb(ZRb);Zcb(ZSb);Zcb(ZTb);Zcb(ZUb);Zcb(ZVb);Zcb(ZWb);Zcb(ZXb);Zcb(ZYb);
Zcb(ZZb);Zcb(Z_b);Zcb(Z0c);Zcb(Z1c);Zcb(Z2c);Zcb(Z3c);Zcb(Z4c);Zcb(Z5c);Zcb(Z6c);Zcb(Z7c);Zcb(Z8c);Zcb(Z9c);Zcb(Zac);Zcb(Zbc);Zcb(Zcc);
Zcb(Zdc);Zcb(Zec);Zcb(Zfc);Zcb(Zgc);Zcb(Zhc);Zcb(Zic);Zcb(Zjc);Zcb(Zkc);Zcb(Zlc);Zcb(Zmc);Zcb(Znc);Zcb(Zoc);Zcb(Zpc);Zcb(Zqc);Zcb(Zrc);
Zcb(Zsc);Zcb(Ztc);Zcb(Zuc);Zcb(Zvc);Zcb(Zwc);Zcb(Zxc);Zcb(Zyc);Zcb(Zzc);Zcb(ZAc);Zcb(ZBc);Zcb(ZCc);Zcb(ZDc);Zcb(ZEc);Zcb(ZFc);Zcb(ZGc);
Zcb(ZHc);Zcb(ZIc);Zcb(ZJc);Zcb(ZKc);Zcb(ZLc);Zcb(ZMc);Zcb(ZNc);Zcb(ZOc);Zcb(ZPc);Zcb(ZQc);Zcb(ZRc);Zcb(ZSc);Zcb(ZTc);Zcb(ZUc);Zcb(ZVc);
Zcb(ZWc);Zcb(ZXc);Zcb(ZYc);Zcb(ZZc);Zcb(Z_c);Zcb(Z0d);Zcb(Z1d);Zcb(Z2d);Zcb(Z3d);Zcb(Z4d);Zcb(Z5d);Zcb(Z6d);Zcb(Z7d);Zcb(Z8d);Zcb(Z9d);
Zcb(Zad);Zcb(Zbd);Zcb(Zcd);Zcb(Zdd);Zcb(Zed);Zcb(Zfd);Zcb(Zgd);Zcb(Zhd);Zcb(Zid);Zcb(Zjd);Zcb(Zkd);Zcb(Zld);Zcb(Zmd);Zcb(Znd);Zcb(Zod);
Zcb(Zpd);Zcb(Zqd);Zcb(Zrd);Zcb(Zsd);Zcb(Ztd);Zcb(Zud);Zcb(Zvd);Zcb(Zwd);Zcb(Zxd);Zcb(Zyd);Zcb(Zzd);Zcb(ZAd);Zcb(ZBd);Zcb(ZCd);Zcb(ZDd);
Zcb(ZEd);Zcb(ZFd);Zcb(ZGd);Zcb(ZHd);Zcb(ZId);Zcb(ZJd);Zcb(ZKd);Zcb(ZLd);Zcb(ZMd);Zcb(ZNd);Zcb(ZOd);Zcb(ZPd);Zcb(ZQd);Zcb(ZRd);Zcb(ZSd);
Zcb(ZTd);Zcb(ZUd);Zcb(ZVd);Zcb(ZWd);Zcb(ZXd);Zcb(ZYd);Zcb(ZZd);Zcb(Z_d);Zcb(Zfb);Zcb(Z0e);Zcb(ZSa);Zcb(Z1e);Zcb(Z2e);Zcb(Z3e);Zcb(Z4e);
Zcb(Z5e);Zcb(Z6e);Zcb(Z7e);Zcb(Z8e);Zcb(Z9e);Zcb(Zae);Zcb(Zbe);}}}return Zab;}void ZVh(T76*C,T0*a1){T2 Z06=0;Z8a((T57*)(ZKe),a1);if(((((T57*)(ZKe))->Z_1))!=(Zo)){
(C->Z_1)=(((void)((T94*)(Zzi()))),Z4b(a1));if((Zyi(C,ZQ5(0)))!=((void*)(Zo))){}Z06=ZQ5(1);Zqe((T57*)(ZKe),Zyi(C,Z06));while(!((((T57*)(ZKe))->Zh1)))
{Z06=(Z3)(((Z06))+(ZQ5(1)));Zqe((T57*)(ZKe),Zyi(C,Z06));}if(((((T7*)(((((T49*)(((C)->Zn2)))->Zs1))[Z06]))->Z91))==(ZQ5(0))){(C->Z91)=(Z3)(((Z06))-(ZQ5(1)));
}else{(C->Z91)=Z06;}Z5b((T57*)(ZKe));if((Z3)((((C)->Z91))<=(ZQ5(0)))){{T0*b1=Zja(6,"File \"");Zb7((T7*)(ZGe),b1);}{T0*b1=((C)->Z_1);Zb7((T7*)(ZGe),b1);
}{T0*b1=Zja(20,"\" seems to be empty.");Zb7((T7*)(ZGe),b1);}Z5i((T77*)(ZJe));}}else{(C->Z_1)=Zo;}}void ZAi(T76*C){(C->Z_1)=Zo;(C->Zm2)=Zo;
}void ZBi(T47*C){(C->Zo2)=((T6)(0));Zjh(((C)->Z_1));ZX6((T7*)(ZCi),Z5h);if((Z3)(((((T7*)(ZCi))->Z91))>(ZQ5(0)))){ZDi(C,ZCi);}}T2 ZEi(T47*C){
T2 R=0;R=(Z3)((((((T49*)(((C)->Zp2)))->Zt1)))+(ZQ5(1)));return R;}void ZFi(T47*C,T0*a1){(C->Zo2)=((T6)(0));Zgh(((C)->Z_1),a1);ZX6((T7*)(ZCi),Z5h);
if((Z3)(((((T7*)(ZCi))->Z91))>(ZQ5(0)))){ZDi(C,ZCi);}}void ZGi(T47*C,T0*a1){ZDi(C,a1);if(!(((C)->Zo2))){ZHi(&(((C)->Zx1)),a1);if((Zo!=((((C)->Zx1)).Z41))){
(C->Z_1)=ZM7((T7*)(Z5h));Z6h(&(((C)->Zx1)));ZDi(C,((C)->Z_1));}}}T0*ZCi=Zo;void ZDi(T47*C,T0*a1){T0*ZIi=Zo;Zlg(C);(C->Z_1)=a1;ZJi(&(((C)->Zx1)),((C)->Z_1));
if((Zo!=((((C)->Zx1)).Z41))){ZKi(&(((C)->Zx1)));while(!(ZE5(((T8)(((((C)->Zx1)).Z51)))))){ZIi=ZM7((T7*)(Z5h));Zv8((T49*)(((C)->Zp2)),ZIi);
ZKi(&(((C)->Zx1)));}Z6h(&(((C)->Zx1)));(C->Zo2)=((T6)(1));}else{(C->Zo2)=((T6)(0));}}void Zlg(T47*C){if((((C)->Zp2))==((void*)(Zo))){
{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;Zx8(n,(T2)(ZQ5(32)));(C->Zp2)=((T0*)n);}}else{((((T49*)((T49*)(((C)->Zp2)))))->Zt1)=(ZQ5(-1));}}
T6 ZLi(T47*C,T0*a1){T6 R=0;T6 ZMi=0;T0*ZIi=Zo;T2 Z06=0;ZMi=((T6)(ZNi()));Z06=(((T49*)(((C)->Zp2)))->Zt1);while(!((T6)((R)||((T6)((Z3)((Z06)<(ZQ5(0))))))))
{ZIi=((((T49*)(((C)->Zp2)))->Zs1))[Z06];if(ZMi){R=((T6)(Zo6(((T7*)ZIi),a1)));}else{R=((T6)(ZB7(((T7*)ZIi),a1)));}Z06=(Z3)(((Z06))-(ZQ5(1)));
}return R;}void ZNg(T47*C){T0*ZIi=Zo;Zlg(C);Z3h(&(((C)->Zx1)));if((Zo!=((((C)->Zx1)).Z41))){(C->Z_1)=ZM7((T7*)(Z5h));ZKi(&(((C)->Zx1)));
while(!(ZE5(((T8)(((((C)->Zx1)).Z51)))))){ZIi=ZM7((T7*)(Z5h));Zv8((T49*)(((C)->Zp2)),ZIi);ZKi(&(((C)->Zx1)));}Z6h(&(((C)->Zx1)));(C->Zo2)=((T6)(1));
}else{(C->Zo2)=((T6)(0));}}T2 ZOi(ZN*C,T2 a1){T2 R=0;T2 Zti=0;Zti=(T2)((((C)->Zs1))[(Z3)(((a1))-(ZQ5(1)))]);if(((Zti&Zo7(63488)))==(Zo7(55296))){
R=(Z3)((((Zti&Zo7(2047))))+(ZQ5(64)));R=(Z3)((((Z3)(((R))*(Zb8(1024)))))+((T2)(ZPi(C,a1))));}else{R=(Zti&Zo7(65535));}return R;}void ZQi(ZN*C,T2
a1){if((Z3)((a1)>(ZQ5(0)))){if((Z3)((((C)->Z81))<(a1))){(C->Zs1)=((ZV)(Zk(a1,sizeof(T10))));(C->Z81)=a1;}}(C->Z91)=ZQ5(0);if((((C)->Zq2))==((void*)(Zo))){
{ZF*n=((ZF*)Zh(sizeof(*n)));*n=ZX1;ZE8(n,(T2)(ZQ5(0)));(C->Zq2)=((T0*)n);}{ZJ*n=((ZJ*)Zh(sizeof(*n)));*n=Ze2;ZM8(n,(T2)(ZQ5(0)));(C->Zr2)=((T0*)n);
}}else{ZE8((ZF*)(((C)->Zq2)),(T2)(ZQ5(0)));ZM8((ZJ*)(((C)->Zr2)),(T2)(ZQ5(0)));}}T6 ZRi(T2 a1){T6 R=0;R=((T6)((T6)(((T6)(((T6)((Z76(a1,(T2)(ZQ5(0)),Zo7(1114111)))&&((T6)(!(Z76(a1,Zo7(55296),Zo7(57343)))))))&&((T6)((a1)!=(Zo7(65534))))))&&((T6)((a1)!=(Zo7(65535)))))));
return R;}T10 ZPi(ZN*C,T2 a1){T10 R=0;R=((((ZJ*)(((C)->Zr2)))->Zs1))[ZG8(((ZF*)(((C)->Zq2))),a1)];return R;}void ZSi(ZN*C,T0*a1){T2 Z06=0;
T2 Zj6=0;Z06=ZQ5(1);while(!((Z3)((Z06)>(((C)->Z91))))){Zj6=ZOi(C,Z06);if((Z3)((Zj6)<(Zb8(128)))){Z26(((T7*)a1),((T3)(Zj6)));}else if((Z3)((Zj6)<(Zb8(2048)))){
Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)/((T2)(ZQ5(64))))))+((T2)(Zb8(192)))))));Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)%((T2)(ZQ5(64))))))+((T2)(Zb8(128)))))));
}else if((Z3)((Zj6)<(Zo7(65536)))){Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)/((T2)(Zb8(4096))))))+((T2)(Zb8(224)))))));Zj6=(Z3)((Zj6)%(Zb8(4096)));
Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)/((T2)(ZQ5(64))))))+((T2)(Zb8(128)))))));Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)%((T2)(ZQ5(64))))))+((T2)(Zb8(128)))))));
}else{Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)/(Zo7(262144)))))+((T2)(Zb8(240)))))));Zj6=(Z3)((Zj6)%(Zo7(262144)));Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)/(Zo7(4096)))))+((T2)(Zb8(128)))))));
Zj6=(Z3)((Zj6)%(Zo7(4096)));Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)/((T2)(ZQ5(64))))))+((T2)(Zb8(128)))))));Z26(((T7*)a1),((T3)((Z3)((((Z3)((Zj6)%((T2)(ZQ5(64))))))+((T2)(Zb8(128)))))));
}Z06=(Z3)(((Z06))+(ZQ5(1)));}}void ZTi(ZN*C,T2 a1){T2 Ze7=0;if((Z3)((((C)->Z81))>(((C)->Z91)))){}else if((((C)->Z81))==(ZQ5(0))){Ze7=ZQ5(32);
(C->Zs1)=((ZV)(Zk(Ze7,sizeof(T10))));(C->Z81)=Ze7;}else{Ze7=(Z3)(((ZQ5(2)))*(((C)->Z81)));(C->Zs1)=Zl6(((C)->Zs1),((C)->Z81),Ze7);(C->Z81)=Ze7;
}if((Z3)((a1)>=(Zo7(65536)))){ZF8((ZF*)(((C)->Zq2)),((C)->Z91));ZN8((ZJ*)(((C)->Zr2)),((ZUi)((a1&Zo7(1023)))));(((C)->Zs1))[((C)->Z91)]=((ZUi)((Z3)((((Z3)((a1)/((T2)(Zb8(1024))))))-((T2)(ZQ5(64))))));
}else{(((C)->Zs1))[((C)->Z91)]=((ZUi)(a1));}(C->Z91)=(Z3)(((((C)->Z91)))+(ZQ5(1)));}void ZVi(ZN*C){(C->Z91)=ZQ5(0);ZE8((ZF*)(((C)->Zq2)),(T2)(ZQ5(0)));
ZM8((ZJ*)(((C)->Zr2)),(T2)(ZQ5(0)));}ZD*ZWi(T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){ZD*n;n=((ZD*)Zh(sizeof(*n)));*n=Z23;ZXi(n,a1,a2,a3,a4,a5);
return n;}T0*ZYi=Zo;int ZZi=0;T0*Z_i(void){if(ZZi==0){ZZi=1;{{T39*n=((T39*)Zh(sizeof(*n)));*n=M39;ZYi=((T0*)n);}}}return ZYi;}void Z0j(ZD*C,T0*a1){
if((a1)==((void*)(Zo))){(C->Z92)=Zo;}else{ZX6((T7*)(((C)->ZW2)),a1);(C->Z92)=((C)->ZW2);}}void Z1j(ZD*C,T0*a1){if((a1)==((void*)(Zo))){
(C->ZQ2)=Zo;}else{ZX6((T7*)(((C)->Z_2)),a1);(C->ZQ2)=((C)->Z_2);}}void Z2j(ZD*C,T0*a1){if((a1)==((void*)(Zo))){(C->Za2)=Zo;}else{ZX6((T7*)(((C)->ZY2)),a1);
(C->Za2)=((C)->ZY2);}}void ZXi(ZD*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(8)));(C->ZJ2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZS2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZT2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZU2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZV2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZW2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZX2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZY2)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZZ2)=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->Z_2)=((T0*)n);}Z3j(C,a1,a2,a3,a4,a5);}void Z4j(ZD*C){T0*ZT7=Zo;T0*Z5j=Zo;
Z6j(C,Zo);Z7j(C,Zo);Z8j(C,Zo);Z9j(C,Zo);Z0j(C,Zo);Zaj(C,Zo);Z2j(C,Zo);Zbj(C,Zo);Z1j(C,Zo);(C->Z03)=((T6)(0));(C->Z13)=((T6)(0));(C->ZR2)=((T6)(0));
Z5j=((C)->ZH2);if((Z5j)!=((void*)(Zo))){(C->ZR2)=((T6)((T6)((Zcj(((T53*)Z5j),Zdj))&&((T6)(Zo6((T7*)(Zl8(((T65*)(((((T53*)Z5j))->ZF2))),Zdj)),((C)->ZK2)))))));
if(((C)->ZR2)){if(ZXh(((T53*)Z5j),((C)->ZJ2),Zej)){ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zej);Z6j(C,ZT7);}if(ZXh(((T53*)Z5j),((C)->ZJ2),Zfj)){
ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zfj);Z7j(C,ZT7);}if(ZXh(((T53*)Z5j),((C)->ZJ2),Zgj)){ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zgj);Z8j(C,ZT7);}if(ZXh(((T53*)Z5j),((C)->ZJ2),Zhj)){
ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zhj);Z9j(C,ZT7);}if(ZXh(((T53*)Z5j),((C)->ZJ2),Zij)){ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zij);Z1j(C,ZT7);}(C->Z03)=((T6)((((C)->ZL2))==((void*)(((C)->ZM2)))));
if((T6)(((T6)((!(((C)->Z03)))&&((T6)((((C)->ZL2))!=((void*)(Zo))))))&&((T6)((((C)->ZM2))!=((void*)(Zo)))))){(C->Z03)=((T6)(Zo6((T7*)(((C)->ZL2)),((C)->ZM2))));
}}}Z5j=((C)->ZI2);if((Z5j)!=((void*)(Zo))){(C->ZR2)=((T6)((T6)(((T6)((((C)->ZR2))&&((T6)(Zcj(((T53*)Z5j),Zjj)))))&&((T6)((T6)((Zo6((T7*)(Zl8(((T65*)(((((T53*)Z5j))->ZF2))),Zjj)),((C)->ZN2)))||((T6)(Zo6((T7*)(Zl8(((T65*)(((((T53*)Z5j))->ZF2))),Zdj)),((C)->ZN2))))))))));
if(((C)->ZR2)){(C->ZN2)=ZW7((T44*)((((void)((T39*)(Z_i()))),Zwi())),ZY7((T44*)((((void)((T39*)(Z_i()))),Zwi())),Zl8(((T65*)(((((T53*)Z5j))->ZF2))),Zjj)));
if(ZXh(((T53*)Z5j),((C)->ZJ2),Zkj)){ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zkj);Z0j(C,ZT7);}if(ZXh(((T53*)Z5j),((C)->ZJ2),Zlj)){ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zlj);
Zaj(C,ZT7);}if(ZXh(((T53*)Z5j),((C)->ZJ2),Zmj)){ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Zmj);Z2j(C,ZT7);}if(ZXh(((T53*)Z5j),((C)->ZJ2),Znj)){ZT7=Zuh(((T53*)Z5j),((C)->ZJ2),Znj);
Zbj(C,ZT7);}(C->Z13)=((T6)((((C)->ZO2))==((void*)(((C)->ZP2)))));if((T6)(((T6)((!(((C)->Z13)))&&((T6)((((C)->ZO2))!=((void*)(Zo))))))&&((T6)((((C)->ZP2))!=((void*)(Zo)))))){
(C->Z13)=((T6)(Zo6((T7*)(((C)->ZO2)),((C)->ZP2))));}}}}void Z3j(ZD*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){ZX6((T7*)(((C)->ZJ2)),a1);(C->ZH2)=a2;
if((a3)!=((void*)(ZTg))){(C->ZK2)=ZW7((T44*)((((void)((T39*)(Z_i()))),ZDh())),ZY7((T44*)((((void)((T39*)(Z_i()))),ZDh())),a3));}(C->ZI2)=a4;
if((a5)!=((void*)(ZTg))){(C->ZN2)=ZW7((T44*)((((void)((T39*)(Z_i()))),Zwi())),ZY7((T44*)((((void)((T39*)(Z_i()))),Zwi())),a5));}Z4j(C);
}void Zaj(ZD*C,T0*a1){if((a1)==((void*)(Zo))){(C->ZO2)=Zo;}else{ZX6((T7*)(((C)->ZX2)),a1);(C->ZO2)=((C)->ZX2);}if(((C)->Z13)){if((a1)==((void*)(Zo))){
(C->ZP2)=Zo;}else{ZX6((T7*)(((C)->ZZ2)),a1);(C->ZP2)=((C)->ZZ2);}}}void Z8j(ZD*C,T0*a1){if((a1)==((void*)(Zo))){(C->Z72)=Zo;}else{ZX6((T7*)(((C)->ZU2)),a1);
(C->Z72)=((C)->ZU2);}}void Zbj(ZD*C,T0*a1){if((a1)==((void*)(Zo))){(C->ZP2)=Zo;}else{ZX6((T7*)(((C)->ZZ2)),a1);(C->ZP2)=((C)->ZZ2);}(C->Z13)=((T6)(0));
}void Z9j(ZD*C,T0*a1){if((a1)==((void*)(Zo))){(C->ZM2)=Zo;}else{ZX6((T7*)(((C)->ZV2)),a1);(C->ZM2)=((C)->ZV2);}(C->Z03)=((T6)(0));}void
Z6j(ZD*C,T0*a1){if((a1)==((void*)(Zo))){(C->Z62)=Zo;}else{ZX6((T7*)(((C)->ZS2)),a1);(C->Z62)=((C)->ZS2);}}void Z7j(ZD*C,T0*a1){if((a1)==((void*)(Zo))){
(C->ZL2)=Zo;}else{ZX6((T7*)(((C)->ZT2)),a1);(C->ZL2)=((C)->ZT2);}if(((C)->Z03)){if((a1)==((void*)(Zo))){(C->ZM2)=Zo;}else{ZX6((T7*)(((C)->ZV2)),a1);
(C->ZM2)=((C)->ZV2);}}}void Zcb(T0*a1){Zoj(Zpj(),a1,a1);}T0*Z4b(T0*a1){T0*R=Zo;R=Zqj(Zpj(),a1);if((R)==((void*)(Zo))){R=ZM7(((T7*)a1));
Zcb(R);}return R;}T0*Zrj=Zo;int Zsj=0;T0*Zpj(void){if(Zsj==0){Zsj=1;{{T69*n=((T69*)Zh(sizeof(*n)));*n=M69;Zrj=((T0*)n);Zf9(n,(T2)(Zb8(16384)));
}}}return Zrj;}void Zji(ZR*C){if((Z3)((((C)->Zk1))>(ZQ5(0)))){Ztj(C);}Zne(((C)->Z83));(C->Z_1)=Zo;}T0*Zuj=Zo;void Zfi(ZR*C){(C->Zi1)=((T9)(Zk(Zb8(4096),sizeof(T3))));
(C->Z81)=Zb8(4096);}void ZY9(ZR*C,T0*a1){T8 Zre=Zo;Zre=ZK7(((T7*)a1));(C->Z83)=Zvj(Zre);if((Zo!=((C)->Z83))){(C->Z_1)=a1;if((((C)->Z81))==(ZQ5(0))){
(C->Zi1)=((T9)(Zk(Zb8(4096),sizeof(T3))));(C->Z81)=Zb8(4096);}}}void Zhi(ZR*C,T11 a1){((((T7*)((T7*)(Zuj))))->Z91)=(ZQ5(0));Zd6(a1,Zuj);
Zgi(C,Zuj);}void Ztj(ZR*C){if((Z3)((((C)->Zk1))>(ZQ5(0)))){Zwj(((C)->Zi1),((C)->Zk1),((C)->Z83));(C->Zk1)=ZQ5(0);}}void Zii(ZR*C,T3 a1){
if((Z3)((((C)->Zk1))>=(Zb8(4096)))){Ztj(C);}(((C)->Zi1))[((C)->Zk1)]=(a1);(C->Zk1)=(Z3)(((((C)->Zk1)))+(ZQ5(1)));}void Zgi(ZR*C,T0*a1){
T2 Z06=0;T2 Zxj=0;Z06=ZQ5(1);Zxj=((((T7*)a1))->Z91);while(!((Z3)((Z06)>(Zxj)))){Zii(C,(((((T7*)a1))->Zs1))[(Z06)-(ZQ5(1))]);Z06=(Z3)(((Z06))+(ZQ5(1)));
}}void Zyj(T98*C,T78 a1,T6 a2,T6 a3,T0*a4){(C->Z11)=a1;(C->Za3)=((T6)(a2));(C->Zb3)=((T6)(a3));(C->Zc3)=ZM7(((T7*)a4));}void Zzj(T32*C){
(C->Zi1)=((T9)(Zk(Zb8(4096),sizeof(T3))));(C->Z81)=Zb8(4096);}void Zoa(T32*C,T11 a1){((((T7*)((T7*)(Zuj))))->Z91)=(ZQ5(0));Zd6(a1,Zuj);
Zxa(C,Zuj);}void Zpa(T32*C){if((Z3)((((C)->Zk1))>(ZQ5(0)))){ZAj(C);}Z5a(ZBj);}void ZAj(T32*C){if((Z3)((((C)->Zk1))>(ZQ5(0)))){Zwj(((C)->Zi1),((C)->Zk1),ZBj);
(C->Zk1)=ZQ5(0);}}void ZH9(T32*C,T3 a1){if((Z3)((((C)->Zk1))>=(Zb8(4096)))){ZAj(C);}(((C)->Zi1))[((C)->Zk1)]=(a1);(C->Zk1)=(Z3)(((((C)->Zk1)))+(ZQ5(1)));
if((a1)==(((T3)'\n'))){ZAj(C);}}void Zxa(T32*C,T0*a1){T2 Z06=0;T2 Zxj=0;Z06=ZQ5(1);Zxj=((((T7*)a1))->Z91);while(!((Z3)((Z06)>(Zxj))))
{ZH9(C,(((((T7*)a1))->Zs1))[(Z06)-(ZQ5(1))]);Z06=(Z3)(((Z06))+(ZQ5(1)));}}void Zwa(T11 a1){((((T7*)((T7*)(Zuj))))->Z91)=(ZQ5(0));Zd6(a1,Zuj);
Zqa(Zuj);}void Zqa(T0*a1){T2 Z06=0;T2 Zxj=0;Z06=ZQ5(1);Zxj=((((T7*)a1))->Z91);while(!((Z3)((Z06)>(Zxj)))){{T3 b1=(((((T7*)a1))->Zs1))[(Z06)-(ZQ5(1))];
Z3a(b1,Z4a);}Z06=(Z3)(((Z06))+(ZQ5(1)));}}T0*ZCj=Zo;void ZDj(T11 a1){((((T7*)((T7*)(Zuj))))->Z91)=(ZQ5(0));Zd6(a1,Zuj);Zeg(Zuj);}void
Zeg(T0*a1){T2 Z06=0;T2 Zxj=0;Z06=ZQ5(1);Zxj=((((T7*)a1))->Z91);while(!((Z3)((Z06)>(Zxj)))){{T3 b1=(((((T7*)a1))->Zs1))[(Z06)-(ZQ5(1))];
ZH9((T32*)(ZI9),b1);}Z06=(Z3)(((Z06))+(ZQ5(1)));}}T10 ZEj(T78*C){T10 R=0;if(Z46(((*C).ZZ),ZQ5(0))){R=(ZUi)(((Z8)(((*C).ZZ))>>(ZQ5(17))));
}else{R=(ZUi)(((Z8)(((*C).ZZ))>>(ZQ5(21))));}return R;}T0*ZFj(T0*a1,T2 a2){T0*R=Zo;T2 Z06=0;Z6a((T51*)(ZGj()),ZKe,a1);if(((((T57*)(ZKe))->Z_1))!=(Zo)){
while(!((T6)(((((T57*)(ZKe))->Zh1))||((T6)((Z06)==(a2)))))){Zte((T57*)(ZKe));Z06=(Z3)(((Z06))+(ZQ5(1)));}if(!((((T57*)(ZKe))->Zh1))){
R=Zue;}Z5b((T57*)(ZKe));}return R;}void ZHj(T78*C){T2 ZIj=0;T2 ZJj=0;T2 ZKj=0;T0*ZLj=Zo;T0*ZMj=Zo;T0*Z9i=Zo;T0*ZNj=Zo;T0*ZOj=Zo;T10 ZPj=0;
ZIj=ZQj(C);ZJj=ZRj(C);ZLj=((*C).ZX);if((ZLj)!=((void*)(Zo))){ZMj=ZSj(C);}if((ZMj)!=((void*)(Zo))){Z9i=(T0*)(ZMj,Zu(),Zv(1),Zo);ZNj=(T0*)(ZLj,Zu(),Zv(1),Zo);
}if((ZNj)==((void*)(Zo))){ZPj=ZEj(C);{int z1=ZPj;switch(z1){case 32767:ZNj=(((T86*)(ZEf))->Zm1);break;case 32766:ZNj=(((T53*)(ZRg))->Zm1);
break;case 32765:ZNj=((*C).ZY);break;default:;ZNj=(((void)((T87*)(ZTj()))),Zce(ZPj));}}}(((void)((T51*)(ZGj()))),Z0a(Zja(5,"Line ")));
(((void)((T51*)(ZGj()))),Zva(ZIj));if((Z3)((ZJj)>(ZQ5(0)))){(((void)((T51*)(ZGj()))),Z0a(Zja(8," column ")));(((void)((T51*)(ZGj()))),Zva(ZJj));
}(((void)((T51*)(ZGj()))),Z0a(Zja(4," in ")));if((Z9i)!=((void*)(Zo))){(((void)((T51*)(ZGj()))),Z0a(Z9i));}if((ZNj)!=((void*)(Zo))){(((void)((T51*)(ZGj()))),Z0a(Zja(2,Zi3)));
(((void)((T51*)(ZGj()))),Z0a(ZNj));(((void)((T51*)(ZGj()))),Z2a(((T3)'\051')));}(((void)((T51*)(ZGj()))),Z0a(Zja(3," :\n")));if((ZNj)!=((void*)(Zo))){
ZOj=ZFj(ZNj,ZIj);if((T6)(((Z3)((ZIj)>(ZQ5(0))))&&((T6)((ZOj)!=((void*)(Zo)))))){(((void)((T51*)(ZGj()))),Z0a(ZOj));(((void)((T51*)(ZGj()))),Z2a(((T3)'\n')));
if((Z3)((ZJj)>(ZQ5(0)))){ZKj=ZQ5(1);while(!((Z3)((ZKj)>=(ZJj)))){if(((((((T7*)ZOj))->Zs1))[(ZKj)-(ZQ5(1))])==(((T3)'\011'))){(((void)((T51*)(ZGj()))),Z2a(((T3)'\011')));
}else{(((void)((T51*)(ZGj()))),Z2a(((T3)'\040')));}ZKj=(Z3)(((ZKj))+(ZQ5(1)));}(((void)((T51*)(ZGj()))),Z0a(Zja(2,"^\n")));}}}}T0*ZSj(T78*C){
T0*R=Zo;T0*ZLj=Zo;ZLj=((*C).ZX);if((ZLj)!=((void*)(Zo))){R=(T0*)(ZLj,Zu(),Zv(1),Zo);}return R;}T0*ZGj(void){if(Z9b==0){Z9b=1;{{T51*n=((T51*)Zh(sizeof(*n)));
*n=M51;Z8b=((T0*)n);}}}return Z8b;}void ZUj(T78*C,T2 a1,T2 a2,T10 a3,T0*a4){(C->ZX)=a4;if((T6)(((T6)(((Z2)((a3)<=(Zb8(2047))))&&((T6)((Z3)((a1)<=(Zb8(8191)))))))&&((T6)((Z3)((a2)<=(ZQ5(127))))))){
(C->ZZ)=(T2)(((a3)<<(ZQ5(21))));(C->ZZ)=(((*C).ZZ)|((a1)<<(ZQ5(8))));(C->ZZ)=(((*C).ZZ)|((a2)<<(ZQ5(1))));}else{(C->ZZ)=(T2)(((a3)<<(ZQ5(17))));
(C->ZZ)=(((*C).ZZ)|((a1)<<(ZQ5(1))));(C->ZZ)=(((*C).ZZ)|ZQ5(1));}}T0*ZVj=Zo;int ZWj=0;T0*ZTj(void){if(ZWj==0){ZWj=1;{{T87*n=((T87*)Zh(sizeof(*n)));
*n=M87;ZVj=((T0*)n);ZFa(n);}}}return ZVj;}T2 ZQj(T78*C){T2 R=0;if(Z46(((*C).ZZ),ZQ5(0))){R=((((*C).ZZ))>>(ZQ5(1)));R=(R&Zo7(65535));}
else{R=((((*C).ZZ))>>(ZQ5(8)));R=(R&Zo7(8191));}return R;}T2 ZRj(T78*C){T2 R=0;if(Z46(((*C).ZZ),ZQ5(0))){}else{R=((((*C).ZZ))>>(ZQ5(1)));
R=(R&Zo7(127));}return R;}void ZS9(T0*a1,T0*a2){T8 ZXj=Zo;T8 ZYj=Zo;if(ZK9(a2)){ZO9(a2);}ZXj=ZK7(((T7*)a1));ZYj=ZK7(((T7*)a2));ZZj(ZXj,ZYj);
}T0*Z_j=Zo;void ZO9(T0*a1){T8 Zre=Zo;Zre=ZK7(((T7*)a1));Z0k(Zre);}T6 ZK9(T0*a1){T6 R=0;Z8a((T57*)(Z_j),a1);R=((T6)(((((T57*)(Z_j))->Z_1))!=(Zo)));
if(R){Z5b((T57*)(Z_j));}return R;}T0*Z1k(T2 a1){T0*R=Zo;{int z1=a1;switch(z1){case 0:R=Z2k;break;case 1:R=Z3k;break;case 2:R=Z4k;break;
case 3:R=Z5k;break;case 4:R=Z6k;break;case 5:R=Z7k;break;case 6:R=Z8k;break;case 7:R=Z9k;break;default:;R=Zak;}}return R;}T2 Zo8(T2 a1){
T2 R=0;if((Z3)((a1)<=(ZQ5(53)))){R=ZQ5(53);}else if((Z3)((a1)<=(ZQ5(97)))){R=ZQ5(97);}else if((Z3)((a1)<=(Zb8(193)))){R=Zb8(193);}else
if((Z3)((a1)<=(Zb8(389)))){R=Zb8(389);}else if((Z3)((a1)<=(Zb8(769)))){R=Zb8(769);}else if((Z3)((a1)<=(Zb8(1543)))){R=Zb8(1543);}else
if((Z3)((a1)<=(Zb8(3079)))){R=Zb8(3079);}else if((Z3)((a1)<=(Zb8(6151)))){R=Zb8(6151);}else if((Z3)((a1)<=(Zb8(12289)))){R=Zb8(12289);
}else if((Z3)((a1)<=(Zb8(24593)))){R=Zb8(24593);}else if((Z3)((a1)<=(Zo7(49157)))){R=Zo7(49157);}else if((Z3)((a1)<=(Zo7(98317)))){R=Zo7(98317);
}else if((Z3)((a1)<=(Zo7(196613)))){R=Zo7(196613);}else if((Z3)((a1)<=(Zo7(393241)))){R=Zo7(393241);}else if((Z3)((a1)<=(Zo7(786433)))){
R=Zo7(786433);}else if((Z3)((a1)<=(Zo7(1572869)))){R=Zo7(1572869);}else if((Z3)((a1)<=(Zo7(3145739)))){R=Zo7(3145739);}else if((Z3)((a1)<=(Zo7(6291469)))){
R=Zo7(6291469);}else if((Z3)((a1)<=(Zo7(12582917)))){R=Zo7(12582917);}else if((Z3)((a1)<=(Zo7(25165843)))){R=Zo7(25165843);}else if((Z3)((a1)<=(Zo7(50331653)))){
R=Zo7(50331653);}else if((Z3)((a1)<=(Zo7(100663319)))){R=Zo7(100663319);}else if((Z3)((a1)<=(Zo7(201326611)))){R=Zo7(201326611);}else
if((Z3)((a1)<=(Zo7(402653189)))){R=Zo7(402653189);}else if((Z3)((a1)<=(Zo7(805306457)))){R=Zo7(805306457);}else{R=Zo7(1610612741);}return
R;}T0*Zbk=Zo;int Zck=0;T0*Zdk(void){if(Zck==0){Zck=1;{{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;Zbk=((T0*)n);Zx8(n,(T2)(ZQ5(1)));}}}return
Zbk;}T0*ZFf(void){T0*R=Zo;if((Z3)(((Z3)((((((T49*)(Zdk()))->Zt1)))+(ZQ5(1))))>(ZQ5(0)))){R=Zz8((T49*)(Zdk()));}return R;}void Z5i(T77*C){
Zek(C,Zfk);Zv(ZQ5(1));}void Zek(T77*C,T0*a1){T2 Z06=0;T2 Zgk=0;T3 Zn7=0;T3 Zhk=0;T78 Zre={Zo,Zo,0};T6 Zie=0;T0*Zik=Zo;(((void)((T51*)(Zjk()))),Z0a(Zkk));
(((void)((T51*)(Zjk()))),Z0a(a1));(((void)((T51*)(Zjk()))),Z2a(((T3)'\072')));(((void)((T51*)(Zjk()))),Z2a(((T3)'\040')));Z06=ZQ5(1);
while(!((Z06)==(ZQ5(0)))){Z06=Zg7((T7*)(ZGe),Zlk,(T2)(ZQ5(1)));if((Z06)!=(ZQ5(0))){{T7*C1=(T7*)(ZGe);T2 b1=Z06;Z27(C1,b1,b1);}}}Z06=ZQ5(1);
Zgk=(Z3)(((ZQ5(9)))+(((((T7*)a1))->Z91)));while(!((Z3)((Z06)>((((T7*)(ZGe))->Z91))))){Zhk=Zn7;Zn7=((((T7*)(ZGe))->Zs1))[(Z06)-(ZQ5(1))];
Z06=(Z3)(((Z06))+(ZQ5(1)));if((Z3)((Zgk)>(ZQ5(60)))){if((T6)(((Zn7)==(((T3)'\040')))||((T6)((Zn7)==(((T3)'\n')))))){(((void)((T51*)(Zjk()))),Z2a(((T3)'\n')));
Zgk=ZQ5(0);}else{(((void)((T51*)(Zjk()))),Z2a(Zn7));Zgk=(Z3)(((Zgk))+(ZQ5(1)));}}else{(((void)((T51*)(Zjk()))),Z2a(Zn7));{int z1=Zn7;
switch(z1){case 10:Zgk=ZQ5(0);break;default:;Zgk=(Z3)(((Zgk))+(ZQ5(1)));}}}}(((void)((T51*)(Zjk()))),Z2a(((T3)'\n')));while(!((Z3)(((((T79*)(Zmk()))->Zt1))<(ZQ5(0)))))
{{T78 ZL6;Zre=(*(ZL6=ZD9((T79*)(Zmk())),&ZL6));}Zz9((T79*)(Zmk()));if((ZSj(&Zre))==((void*)(Zo))){ZHj(&Zre);}else{Zik=(T0*)(ZSj(&Zre),Zu(),Zv(1),Zo);
if(!(Znk(Zik))){ZHj(&Zre);}}Zie=((T6)(0));while(!(Zie)){Z06=ZE9((T79*)(Zmk()),Zre);if(ZA9((T79*)(Zmk()),Z06)){ZB9((T79*)(Zmk()),Z06);
}else{Zie=((T6)(1));}}}((((T7*)((T7*)(ZGe))))->Z91)=(ZQ5(0));((((T79*)((T79*)(Zmk()))))->Zt1)=(ZQ5(-1));(((void)((T51*)(Zjk()))),Z0a(Zok));
}T0*Zjk(void){if(Z9b==0){Z9b=1;{{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;Z8b=((T0*)n);}}}return Z8b;}T0*ZGe=Zo;void Z_h(T77*C){Zek(C,Zpk);
(C->Zu1)=(Z3)(((((C)->Zu1)))+(ZQ5(1)));if((Z3)((((C)->Zu1))>=(ZQ5(6)))){(((void)((T51*)(Zjk()))),Z0a(Zkk));(((void)((T51*)(Zjk()))),Z0a(Zqk));
Zv(ZQ5(1));}}T0*Zrk=Zo;int Zsk=0;T0*Zmk(void){if(Zsk==0){Zsk=1;{{T79*n=((T79*)Zh(sizeof(*n)));*n=M79;Zrk=((T0*)n);ZF9(n,(T2)(ZQ5(16)));
}}}return Zrk;}void Ztk(T78 a1){if((((a1).ZZ))==(ZQ5(0))){}else{ZC9((T79*)(Zmk()),a1);}}void ZIe(T77*C){if(((C)->Zw1)){((((T7*)((T7*)(ZGe))))->Z91)=(ZQ5(0));
((((T79*)((T79*)(Zmk()))))->Zt1)=(ZQ5(-1));}else{Zek(C,Zuk);}(C->Zv1)=(Z3)(((((C)->Zv1)))+(ZQ5(1)));}T0*Zvk=Zo;T0*Zwk=Zo;void Zxk(T0*a1,T0*a2){
T0*Zyk=Zo;Zyk=Zzk;ZX6(((T7*)Zyk),a2);ZHf((T39*)(ZAk()),Zyk);((((T7*)((T7*)(ZBk))))->Z91)=(ZQ5(0));Znh((T39*)(ZAk()),ZBk,ZCk);Z26((T7*)(ZBk),((T3)'\040'));
Zb7((T7*)(ZBk),a1);Zb7((T7*)(ZBk),ZDk);Zb7((T7*)(ZBk),Zyk);Z26((T7*)(ZBk),((T3)'\040'));Zb7((T7*)(ZBk),a2);Zeg(ZBk);{T3 b1=((T3)'\n');
ZH9((T32*)(ZI9),b1);}Zra((T51*)(ZEk()),ZBk);}void ZFk(T0*a1){Zeg(ZGk);Zeg(a1);Zeg(ZHk);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;
Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));}void ZJk(T12*C){T2 Z06=0;T0*ZKk=Zo;T0*ZLk=Zo;ZKk=ZMk(C,ZNk);Z06=ZQ5(1);while(!((Z3)((Z06)>(ZV7((T44*)(ZOk))))))
{ZLk=ZW7((T44*)(ZOk),Z06);if(!(Z58((T44*)(ZPk),ZLk))){Zxk(ZKk,ZLk);}Z06=(Z3)(((Z06))+(ZQ5(1)));}ZKk=ZMk(C,ZQk);Z06=ZQ5(1);while(!((Z3)((Z06)>(ZV7((T44*)(ZRk))))))
{ZLk=ZW7((T44*)(ZRk),Z06);if(!(Z58((T44*)(ZPk),ZLk))){Zxk(ZKk,ZLk);}Z06=(Z3)(((Z06))+(ZQ5(1)));}}void ZSk(T12*C,T6 a1){T2 Z06=0;T6 ZTk=0;
T0*ZUk=Zo;T0*ZVk=Zo;T0*ZWk=Zo;T0*ZXk=Zo;T0*ZYk=Zo;if(a1){Z06=ZQ5(0);while(!((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1))))){ZJ8((ZH*)(((C)->ZR1)),((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]);
Z06=(Z3)(((Z06))+(ZQ5(1)));}((((ZH*)((ZH*)(((C)->ZQ1)))))->Zt1)=(ZQ5(-1));}ZUk=ZZk(((C)->ZJ1));ZVk=ZZk(((C)->ZK1));if((ZUk)==((void*)(Zo))){
ZTk=((T6)(Z_k(C)));}else{ZYk=Z0l(((T53*)ZUk));while(!(Zsh(ZYk))){ZXk=Zvh(ZYk);ZWk=Zo;if(!(a1)){Z06=ZQ5(0);while(!((T6)(((ZWk)!=((void*)(Zo)))||((T6)((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1))))))))
{ZWk=((((ZH*)(((C)->ZQ1)))->Zs1))[Z06];if(!(Zo6((T7*)(((((ZD*)ZWk))->ZJ2)),ZXk))){ZWk=Zo;}Z06=(Z3)(((Z06))+(ZQ5(1)));}}if((ZWk)==((void*)(Zo))){
if((Z3)(((((ZH*)(((C)->ZR1)))->Zt1))<(ZQ5(0)))){{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Z23;ZXi(n,ZXk,ZUk,((C)->ZJ1),ZVk,((C)->ZK1));ZWk=((T0*)n);
}}else{ZWk=((((ZH*)(((C)->ZR1)))->Zs1))[ZQ5(0)];ZH8((ZH*)(((C)->ZR1)));Z3j(((ZD*)ZWk),ZXk,ZUk,((C)->ZJ1),ZVk,((C)->ZK1));}ZJ8((ZH*)(((C)->ZQ1)),ZWk);
}Zwh(ZYk);}}}void Z1l(T12*C){ZNg((T47*)(Z2l()));if(!((((T47*)(Z2l()))->Zo2))){Zqa(Z3l);Zqa(Zja(41,"Cannot connect to the current directory!\n"));
Z4l(C);}ZFi((T47*)(Z2l()),Z5l);if((((T47*)(Z2l()))->Zo2)){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,(((T47*)(Z2l()))->Z_1));(C->ZC1)=((T0*)n);
}ZBi((T47*)(Z2l()));}else{ZNg((T47*)(Z2l()));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,(((T47*)(Z2l()))->Z_1));(C->ZC1)=((T0*)n);}}ZFi((T47*)(Z2l()),Z6l);
if((((T47*)(Z2l()))->Zo2)){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,(((T47*)(Z2l()))->Z_1));(C->ZD1)=((T0*)n);}ZBi((T47*)(Z2l()));}else{
ZNg((T47*)(Z2l()));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,(((T47*)(Z2l()))->Z_1));(C->ZD1)=((T0*)n);}}ZFi((T47*)(Z2l()),Z7l);if((((T47*)(Z2l()))->Zo2)){
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,(((T47*)(Z2l()))->Z_1));(C->ZE1)=((T0*)n);}ZBi((T47*)(Z2l()));}else{ZNg((T47*)(Z2l()));{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZX6(n,(((T47*)(Z2l()))->Z_1));(C->ZE1)=((T0*)n);}}}void Z8l(T0*a1){Zeg(Z9l);Zeg(a1);Zeg(Zal);}void Zbl(T12*C){{T7*z1=(T7*)((C)->ZP1);
T3*Zcl=(Zo==z1)?Zo:((z1)->Zs1);int Zdl=(Zo==z1)?0:((z1)->Z91);int Zel=-1;int Zfl=0;if(z1!=Zo)while(Zfl<Zdl&&(Zfl==0||Zel!=-1)){switch(Zel){
case-1:switch(*(Zcl+Zfl)){case'A':Zel=10;break;case'B':Zel=11;break;case'C':Zel=12;break;case'D':Zel=13;break;case'E':Zel=14;break;case'M':Zel=15;break;
case'O':Zel=16;break;case'U':Zel=17;break;case'W':Zel=18;break;default:Zel=-1;break;}break;case 0:switch(*(Zcl+Zfl)){default:Zel=-1;break;
}break;case 1:switch(*(Zcl+Zfl)){default:Zel=-1;break;}break;case 2:switch(*(Zcl+Zfl)){default:Zel=-1;break;}break;case 3:switch(*(Zcl+Zfl)){
default:Zel=-1;break;}break;case 4:switch(*(Zcl+Zfl)){default:Zel=-1;break;}break;case 5:switch(*(Zcl+Zfl)){default:Zel=-1;break;}break;
case 6:switch(*(Zcl+Zfl)){default:Zel=-1;break;}break;case 7:switch(*(Zcl+Zfl)){default:Zel=-1;break;}break;case 8:switch(*(Zcl+Zfl)){
default:Zel=-1;break;}break;case 9:switch(*(Zcl+Zfl)){default:Zel=-1;break;}break;case 10:switch(*(Zcl+Zfl)){case'm':Zel=19;break;default:Zel=-1;
break;}break;case 11:switch(*(Zcl+Zfl)){case'e':Zel=20;break;default:Zel=-1;break;}break;case 12:switch(*(Zcl+Zfl)){case'y':Zel=21;break;
default:Zel=-1;break;}break;case 13:switch(*(Zcl+Zfl)){case'O':Zel=22;break;default:Zel=-1;break;}break;case 14:switch(*(Zcl+Zfl)){case'l':Zel=23;break;
default:Zel=-1;break;}break;case 15:switch(*(Zcl+Zfl)){case'a':Zel=24;break;default:Zel=-1;break;}break;case 16:switch(*(Zcl+Zfl)){case'S':Zel=25;break;
case'p':Zel=26;break;default:Zel=-1;break;}break;case 17:switch(*(Zcl+Zfl)){case'N':Zel=27;break;default:Zel=-1;break;}break;case 18:switch(*(Zcl+Zfl)){
case'i':Zel=28;break;default:Zel=-1;break;}break;case 19:switch(*(Zcl+Zfl)){case'i':Zel=29;break;default:Zel=-1;break;}break;case 20:switch(*(Zcl+Zfl)){
case'O':Zel=30;break;default:Zel=-1;break;}break;case 21:switch(*(Zcl+Zfl)){case'g':Zel=31;break;default:Zel=-1;break;}break;case 22:switch(*(Zcl+Zfl)){
case'S':Zel=(*(Zcl+Zfl+1))?3:6;break;default:Zel=-1;break;}break;case 23:switch(*(Zcl+Zfl)){case'a':Zel=32;break;default:Zel=-1;break;
}break;case 24:switch(*(Zcl+Zfl)){case'c':Zel=33;break;default:Zel=-1;break;}break;case 25:switch(*(Zcl+Zfl)){case'2':Zel=(*(Zcl+Zfl+1))?6:7;break;
default:Zel=-1;break;}break;case 26:switch(*(Zcl+Zfl)){case'e':Zel=34;break;default:Zel=-1;break;}break;case 27:switch(*(Zcl+Zfl)){case'I':Zel=35;break;
default:Zel=-1;break;}break;case 28:switch(*(Zcl+Zfl)){case'n':Zel=36;break;default:Zel=-1;break;}break;case 29:switch(*(Zcl+Zfl)){case'g':Zel=37;break;
default:Zel=-1;break;}break;case 30:switch(*(Zcl+Zfl)){case'S':Zel=(*(Zcl+Zfl+1))?1:3;break;default:Zel=-1;break;}break;case 31:switch(*(Zcl+Zfl)){
case'w':Zel=38;break;default:Zel=-1;break;}break;case 32:switch(*(Zcl+Zfl)){case't':Zel=39;break;default:Zel=-1;break;}break;case 33:switch(*(Zcl+Zfl)){
case'i':Zel=40;break;default:Zel=-1;break;}break;case 34:switch(*(Zcl+Zfl)){case'n':Zel=41;break;default:Zel=-1;break;}break;case 35:switch(*(Zcl+Zfl)){
case'X':Zel=(*(Zcl+Zfl+1))?8:0;break;default:Zel=-1;break;}break;case 36:switch(*(Zcl+Zfl)){case'd':Zel=42;break;default:Zel=-1;break;
}break;case 37:switch(*(Zcl+Zfl)){case'a':Zel=(*(Zcl+Zfl+1))?0:5;break;default:Zel=-1;break;}break;case 38:switch(*(Zcl+Zfl)){case'i':Zel=43;break;
default:Zel=-1;break;}break;case 39:switch(*(Zcl+Zfl)){case'e':Zel=(*(Zcl+Zfl+1))?4:9;break;default:Zel=-1;break;}break;case 40:switch(*(Zcl+Zfl)){
case'n':Zel=44;break;default:Zel=-1;break;}break;case 41:switch(*(Zcl+Zfl)){case'V':Zel=45;break;default:Zel=-1;break;}break;case 42:switch(*(Zcl+Zfl)){
case'o':Zel=46;break;default:Zel=-1;break;}break;case 43:switch(*(Zcl+Zfl)){case'n':Zel=2;break;default:Zel=-1;break;}break;case 44:switch(*(Zcl+Zfl)){
case't':Zel=47;break;default:Zel=-1;break;}break;case 45:switch(*(Zcl+Zfl)){case'M':Zel=48;break;default:Zel=-1;break;}break;case 46:switch(*(Zcl+Zfl)){
case'w':Zel=49;break;default:Zel=-1;break;}break;case 47:switch(*(Zcl+Zfl)){case'o':Zel=50;break;default:Zel=-1;break;}break;case 48:switch(*(Zcl+Zfl)){
case'S':Zel=(*(Zcl+Zfl+1))?7:8;break;default:Zel=-1;break;}break;case 49:switch(*(Zcl+Zfl)){case's':Zel=(*(Zcl+Zfl+1))?9:1;break;default:Zel=-1;
break;}break;case 50:switch(*(Zcl+Zfl)){case's':Zel=51;break;default:Zel=-1;break;}break;case 51:switch(*(Zcl+Zfl)){case'h':Zel=(*(Zcl+Zfl+1))?5:4;break;
default:Zel=-1;break;}break;default:Zel=-1;break;}Zfl++;}switch(Zel){case 0:(C->ZJ1)=Z4f;ZX6((T7*)(((C)->ZN1)),Zgl);(C->ZK1)=Z5f;ZX6((T7*)(((C)->ZO1)),Zhl);
break;case 1:break;case 2:(C->ZJ1)=Z4f;ZX6((T7*)(((C)->ZN1)),Zil);(C->ZK1)=Z5f;ZX6((T7*)(((C)->ZO1)),Zjl);break;case 3:break;case 4:break;
case 5:break;case 6:break;case 7:break;case 8:(C->ZJ1)=Zyf;break;case 9:(C->ZJ1)=Zxf;(C->ZK1)=Zxf;break;default:;(C->ZP1)=ZTg;}}if((((C)->ZS1))==((void*)(Zo))){
{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;Zx8(n,(T2)(ZQ5(4)));(C->ZS1)=((T0*)n);}{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;Zx8(n,(T2)(ZQ5(4)));
(C->ZT1)=((T0*)n);}Zkl(C,Zll);Zkl(C,Zml);Zkl(C,Znl);}if((((C)->ZB1))==((void*)(ZTg))){(C->ZA1)=ZQ5(1);}else if((((C)->ZJ1))==((void*)(Zo))){
(C->ZA1)=ZQ5(2);}else{(C->ZA1)=ZQ5(3);}}T0*ZAk(void){if(ZZi==0){ZZi=1;{{T39*n=((T39*)Zh(sizeof(*n)));*n=M39;ZYi=((T0*)n);}}}return ZYi;
}void Zol(T12*C){T6 Zpl=0;Zpl=((T6)(!(((C)->ZU1))));if(((C)->ZU1)){Zeg(Zql);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);
}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){ZL7((T7*)(ZIk));Zpl=((T6)((((((T7*)(ZIk))->Zs1))[ZQ5(0)])==(((T3)'y'))));
}else{Zeg(Zrl);}}if(Zpl){{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}(C->ZU1)=((T6)(1));{T12*C1=C;int Zsl=0;{T0*c1=ZVg;T0*c2=((C1)->ZB1);Zx5(ZK7(((T7*)c1)),ZK7(((T7*)c2)));
}}Ztl(C);Zeg(Zul);}}void Zvl(T0*a1,T0*a2){T0*Zyk=Zo;Zyk=Zwl;ZX6(((T7*)Zyk),a2);ZHf((T39*)(ZAk()),Zyk);((((T7*)((T7*)(ZBk))))->Z91)=(ZQ5(0));
Znh((T39*)(ZAk()),ZBk,Zxl);Z26((T7*)(ZBk),((T3)'\040'));Zb7((T7*)(ZBk),a1);Zb7((T7*)(ZBk),Zyl);Zb7((T7*)(ZBk),Zyk);Z26((T7*)(ZBk),((T3)'\040'));
Zb7((T7*)(ZBk),a2);Zeg(ZBk);{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}Zra((T51*)(ZEk()),ZBk);}T0*Zzl=Zo;int ZAl=0;T0*ZBl(void){if(ZAl==0){ZAl=1;{
{T69*n=((T69*)Zh(sizeof(*n)));*n=M69;Zzl=((T0*)n);Ze9(n);}}}return Zzl;}void ZCl(T12*C,T2 a1){ZFk(ZDl);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){
if((((C)->ZS1))==((void*)(Zo))){{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;Zx8(n,(T2)(ZQ5(4)));(C->ZS1)=((T0*)n);}}if((((C)->ZT1))==((void*)(Zo))){
{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;Zx8(n,(T2)(ZQ5(4)));(C->ZT1)=((T0*)n);}}if((Z3)((a1)>((((T49*)(((C)->ZS1)))->Zt1)))){Zv8((T49*)(((C)->ZS1)),ZM7((T7*)(ZIk)));
Zv8((T49*)(((C)->ZT1)),Zja(0,Zd3));}else{ZX6((T7*)(((((T49*)(((C)->ZS1)))->Zs1))[a1]),ZIk);}}ZFk(ZEl);ZX6((T7*)(((((T49*)(((C)->ZT1)))->Zs1))[a1]),ZIk);
}void ZFl(T12*C){T2 Z06=0;T2 ZIi=0;T6 ZGl=0;T6 ZHl=0;T6 ZIl=0;ZIl=((T6)(1));while(!(ZHl)){Zeg(ZJl);if((((C)->ZS1))!=((void*)(Zo))){Z06=ZQ5(0);
while(!((T6)(((Z3)((Z06)>((((T49*)(((C)->ZS1)))->Zt1))))||((T6)(((((T7*)(((((T49*)(((C)->ZS1)))->Zs1))[Z06]))->Z91))==(ZQ5(0))))))){ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(1))))));
Zeg(ZKl);Zeg(((((T49*)(((C)->ZS1)))->Zs1))[Z06]);Zeg(ZLl);Zeg(((((T49*)(((C)->ZT1)))->Zs1))[Z06]);{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);
}Z06=(Z3)(((Z06))+(ZQ5(1)));}}{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(1))))));Zeg(ZMl);ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(2))))));
Zeg(ZNl);ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(3))))));Zeg(ZOl);if(ZIl){ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(1))))));}else{ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(3))))));
}Zeg(ZPl);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));ZGl=((T6)(0));if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){
if(ZIl){Zb6((Z3)(((Z06))+((T2)(ZQ5(1)))),ZIk);}else{Zb6((Z3)(((Z06))+((T2)(ZQ5(3)))),ZIk);}}if(Zi7((T7*)(ZIk))){ZIi=Zx7((T7*)(ZIk));if((T6)(((Z3)((ZIi)>=(ZQ5(1))))&&((T6)((Z3)((ZIi)<=((Z3)(((Z06))+(ZQ5(3))))))))){
ZGl=((T6)(1));{int z1=(Z3)(((ZIi))-(Z06));switch(z1){case 3:ZHl=((T6)(1));break;case 2:ZQl(C,Z06);break;case 1:ZCl(C,Z06);break;default:;
ZRl(C,(Z3)(((ZIi))-((T2)(ZQ5(1)))));}}}}if(!(ZGl)){Zeg(ZSl);ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(3))))));Zeg(ZTl);}}}void ZUl(T12*C,T3 a1){
{T3 b1=a1;ZH9((T32*)(ZI9),b1);}if((a1)==(((T3)'\n'))){(C->ZV1)=(Z3)(((((C)->ZV1)))+(ZQ5(1)));if((((C)->ZV1))==(ZQ5(25))){Zeg(ZVl);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));
{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));(C->ZV1)=ZQ5(1);}}}void Zkl(T12*C,T0*a1){T0*ZWl=Zo;Z3h(&(((C)->Zx1)));
ZWl=ZM7((T7*)(Z5h));Z6h(&(((C)->Zx1)));if(!((((((T7*)ZWl))->Z91))==(ZQ5(0)))){Zgh(ZWl,a1);ZX6(((T7*)ZWl),Z5h);if(!((((((T7*)ZWl))->Z91))==(ZQ5(0)))){
ZXl(ZWl,ZYl);ZX6(((T7*)ZWl),Z5h);}}if((((((T7*)ZWl))->Z91))==(ZQ5(0))){Zqa(Z3l);Zqa(ZZl);Zqa(a1);Zqa(Z_l);Z4l(C);}else{Zv8((T49*)(((C)->ZS1)),a1);
Zv8((T49*)(((C)->ZT1)),ZWl);}}void Z0m(T12*C){Zeg(Z1m);if(((C)->ZU1)){Zeg(Z2m);}else{Zeg(Z3m);}}T0*Z4m=Zo;void Z5m(T12*C,T2 a1){T0*ZWk=Zo;
T0*Z6m=Zo;T0*Z7m=Zo;T6 ZHl=0;T6 ZIl=0;T6 Z8m=0;T2 Z9m=0;T2 Z06=0;T2 ZIi=0;ZIl=((T6)(1));while(!(ZHl)){ZWk=((((ZH*)(((C)->ZQ1)))->Zs1))[a1];
Z8m=((T6)((((((ZD*)ZWk))->ZN2))!=((void*)(Zo))));if(Z8m){Z9m=ZQ5(12);}else{Z9m=ZQ5(8);}Zeg(Zam);Zeg(((((ZD*)ZWk))->ZJ2));{T3 b1=((T3)'\n');
ZH9((T32*)(ZI9),b1);}{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}if((((((ZD*)ZWk))->Z72))==((void*)(Zo))){Z6m=((((ZD*)ZWk))->Z62);if((Z6m)==((void*)(Zo))){
Z6m=((((ZD*)ZWk))->ZK2);}}if((((((ZD*)ZWk))->Za2))==((void*)(Zo))){Z7m=((((ZD*)ZWk))->Z92);if((Z7m)==((void*)(Zo))){Z7m=((((ZD*)ZWk))->ZN2);
}}Zbm(Zcm,((((ZD*)ZWk))->ZK2),Zo);Zbm(Zdm,((((ZD*)ZWk))->Z62),((((ZD*)ZWk))->ZK2));Zbm(Zem,((((ZD*)ZWk))->ZL2),Zo);Zbm(Zfm,((((ZD*)ZWk))->Z72),Z6m);
Zbm(Zgm,((((ZD*)ZWk))->ZM2),Zo);Zbm(Zhm,((((ZD*)ZWk))->ZN2),Zo);if(Z8m){Zbm(Zim,((((ZD*)ZWk))->Z92),((((ZD*)ZWk))->ZN2));Zbm(Zjm,((((ZD*)ZWk))->ZO2),Zo);
Zbm(Zkm,((((ZD*)ZWk))->Za2),Z7m);Zbm(Zlm,((((ZD*)ZWk))->ZP2),Zo);Zbm(Zmm,((((ZD*)ZWk))->ZQ2),Zo);Zeg(Znm);}else{Zbm(Zom,((((ZD*)ZWk))->ZQ2),Zo);
Zeg(Zpm);}if(ZIl){Zeg(Zqm);}else if(Z8m){Zeg(Zrm);}else{Zeg(Zsm);}((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);
}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){if(ZIl){ZZ5(ZQ5(1),ZIk);}else if(Z8m){ZZ5(ZQ5(12),ZIk);}else{ZZ5(ZQ5(8),ZIk);
}}if(ZO7((T7*)(ZIk))){ZIi=Zx7((T7*)(ZIk));if((T6)(((Z3)((ZIi)>=(ZQ5(1))))&&((T6)((Z3)((ZIi)<=(Z9m)))))){{int z1=ZIi;switch(z1){case 1:
Zeg(Ztm);Z06=(((T44*)(Zum()))->Z53);while(!((Z3)((Z06)>((((T44*)(Zum()))->Zt1))))){if((Z3)((Z06)>((((T44*)(Zum()))->Z53)))){Zeg(Zvm);
}Zeg(ZW7((T44*)(Zum()),Z06));Z06=(Z3)(((Z06))+(ZQ5(1)));}{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}ZFk(Zwm);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){
if(Z58((T44*)(Zum()),ZIk)){Z3j(((ZD*)ZWk),((((ZD*)ZWk))->ZJ2),Zxm(ZIk,Zo),ZW7((T44*)((((void)((T39*)(ZAk()))),ZDh())),ZY7((T44*)((((void)((T39*)(ZAk()))),ZDh())),Zym(Zzm(),ZIk))),((((ZD*)ZWk))->ZI2),((((ZD*)ZWk))->ZN2));
}else{Zeg(ZAm);}}break;case 2:ZFk(ZBm);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){if(ZK9(ZIk)){Z6j(((ZD*)ZWk),ZIk);}else{Zeg(ZCm);}}break;
case 3:ZFk(ZDm);Z7j(((ZD*)ZWk),ZIk);break;case 4:ZFk(ZEm);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){if(ZK9(ZIk)){Z8j(((ZD*)ZWk),ZIk);Z9j(((ZD*)ZWk),Zo);
}else{Zeg(ZFm);}}break;case 5:ZFk(ZGm);Z9j(((ZD*)ZWk),ZIk);break;case 6:Zeg(ZHm);Z06=(((T44*)(ZIm()))->Z53);while(!((Z3)((Z06)>((((T44*)(ZIm()))->Zt1)))))
{if((Z3)((Z06)>((((T44*)(ZIm()))->Z53)))){Zeg(ZJm);}Zeg(ZW7((T44*)(ZIm()),Z06));Z06=(Z3)(((Z06))+(ZQ5(1)));}{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);
}ZFk(ZKm);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){if(Zo6((T7*)(ZIk),Zxi)){Z3j(((ZD*)ZWk),((((ZD*)ZWk))->ZJ2),((((ZD*)ZWk))->ZH2),((((ZD*)ZWk))->ZK2),Zo,Zo);
}else if(Z58((T44*)(ZIm()),ZIk)){Z3j(((ZD*)ZWk),((((ZD*)ZWk))->ZJ2),((((ZD*)ZWk))->ZH2),((((ZD*)ZWk))->ZK2),Zxm(ZIk,Zo),ZW7((T44*)((((void)((T39*)(ZAk()))),Zwi())),ZY7((T44*)((((void)((T39*)(ZAk()))),Zwi())),Zym(ZBl(),ZIk))));
}else{Zeg(ZLm);}}break;case 7:if(Z8m){ZFk(ZMm);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){if(ZK9(ZIk)){Z0j(((ZD*)ZWk),ZIk);}else{Zeg(ZNm);
}}}else{ZFk(ZOm);Z1j(((ZD*)ZWk),ZIk);}break;case 8:if(Z8m){ZFk(ZPm);Zaj(((ZD*)ZWk),ZIk);}else{ZHl=((T6)(1));}break;case 9:ZFk(ZQm);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){
if(ZK9(ZIk)){Z2j(((ZD*)ZWk),ZIk);Zbj(((ZD*)ZWk),Zo);}else{Zeg(ZRm);}}break;case 10:ZFk(ZSm);Zbj(((ZD*)ZWk),ZIk);break;case 11:ZFk(ZTm);
Z1j(((ZD*)ZWk),ZIk);break;default:;ZHl=((T6)(1));}}ZIl=((T6)(0));}else{Zeg(ZUm);ZDj((T11)(Z9m));Zeg(ZVm);}}else{Zeg(ZWm);ZDj((T11)(Z9m));
Zeg(ZXm);}}}void ZYm(T12*C,T0*a1){T0*Zre=Zo;{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,a1);Zre=((T0*)n);}ZDi((T47*)(Z2l()),Zre);if(!((((T47*)(Z2l()))->Zo2))){
Zjh(a1);if((Z3)(((((T7*)(Z5h))->Z91))>(ZQ5(0)))){ZYm(C,Z5h);}else{Zqa(Z3l);Zqa(ZZm);Zqa(a1);Zqa(Z_m);Z4l(C);}}ZDi((T47*)(Z2l()),Zre);
}T0*Z0n=Zo;void Z1n(T12*C){if((T6)(((T6)(((Z7h)==((void*)(Zo)))||((T6)((Zkh)==((void*)(Zo))))))||((T6)(Zo6((T7*)(Zkh),Z2n))))){(C->ZB1)=Z3n;
}else{(C->ZB1)=Zwk;ZX6((T7*)(((C)->ZB1)),Z7h);if((Z07((T7*)(((C)->ZB1))))!=(((T3)'\057'))){Z26((T7*)(((C)->ZB1)),((T3)'\057'));}Zb7((T7*)(((C)->ZB1)),Z4n);
}}void Z5n(T12*C,T0*a1){T6 ZHl=0;T0*ZG7=Zo;if(ZB7(((T7*)Z6n),((C)->ZP1))){ZL7(((T7*)a1));ZG7=ZM7(((T7*)a1));while(!(ZHl)){if((((((T7*)ZG7))->Z91))==(ZQ5(0))){
ZHl=((T6)(1));}else if((Z07(((T7*)ZG7)))==(((T3)'\073'))){Zu7(((T7*)ZG7),(T2)(ZQ5(1)));ZX6(((T7*)a1),ZG7);ZHl=((T6)(1));}else if(ZL5(Z07(((T7*)ZG7)))){
Zu7(((T7*)ZG7),(T2)(ZQ5(1)));}else{ZHl=((T6)(1));}}}}T0*ZRk=Zo;T0*Z7n(void){if(ZCg==0){ZCg=1;{{T76*n=((T76*)Zh(sizeof(*n)));*n=M76;ZBg=((T0*)n);
ZEg(n);}}}return ZBg;}T0*ZZk(T0*a1){T0*R=Zo;T0*Z8n=Zo;Z8n=Z9n(a1);if((Z8n)!=((void*)(Zo))){R=Zxm(Z8n,Zo);}return R;}T0*ZPk=Zo;void Zan(T12*C){
T2 Zbn=0;while(!(((C)->Zz1))){Zbn=Zcn(C);{int z1=Zbn;switch(z1){case 1:Zdn(C);(C->ZA1)=ZQ5(2);break;case 2:Zen(C);(C->ZA1)=ZQ5(3);break;
case 3:Zfn(C);(C->ZA1)=ZQ5(4);break;case 4:Zgn(C);(C->ZA1)=ZQ5(5);break;case 5:Zol(C);(C->ZA1)=ZQ5(6);break;case 6:Zhn(C);break;default:;
}}}}void Zin(T12*C){Zeg(Zjn);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));Zeg(Zkn);
Zln(C);Zan(C);Z0m(C);}void Zmn(T12*C){int ZG7=0;T6 Znn=0;if(ZK9(Zon)){Zpn(C,ZYe);(C->ZB1)=Zqn;Znn=((T6)(1));}else if(ZK9(Zrn)){Zpn(C,ZUe);
}else if(ZK9(Zsn)){Zpn(C,ZSe);}else if(ZK9(Ztn)){Zpn(C,ZRe);Z1n(C);}else if(ZK9(Zun)){Zpn(C,ZPe);Z1n(C);}else{if(Z7g()){if(Z8g()){Zpn(C,ZPe);
Z1n(C);}else if(Zag()){Zpn(C,ZQe);Zvn(C);}else if(Z9g()){Zpn(C,ZRe);Z1n(C);}else if(Zcg()){Zpn(C,ZUe);}else if(Zbg()){Zpn(C,ZTe);}else
if(Zdg()){Zpn(C,ZXe);}}if((((C)->ZP1))==((void*)(Zo))){ZJi(&(((C)->Zx1)),Zwn);if((Zo!=((((C)->Zx1)).Z41))){Zpn(C,ZQe);Z6h(&(((C)->Zx1)));
}}}ZW9((T39*)(ZAk()));if((ZSg)!=((void*)(Zo))){(C->ZB1)=ZSg;}else if(ZH5((T6)((((C)->ZB1))==((void*)(Zo))),(T6)((((C)->ZB1))==((void*)(ZTg))))){
(C->ZB1)=(((T39*)(ZAk()))->ZB1);}else if((T6)((!(Znn))&&((T6)(((((T39*)(ZAk()))->ZB1))!=((void*)(ZTg)))))){(C->ZB1)=(((T39*)(ZAk()))->ZB1);
}}void Zxn(T12*C){T2 Z06=0;T6 ZGl=0;ZFk(Zyn);if((T6)((Zo6((T7*)(ZIk),ZYh))||((T6)(Zo6((T7*)(ZIk),Zrh))))){Zeg(Zzn);}else{Z06=ZQ5(0);ZGl=((T6)(1));
while(!((T6)((!(ZGl))||((T6)((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1)))))))){if(Zo6((T7*)((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZJ2)),ZIk)){
ZGl=((T6)(0));Zeg(ZAn);}Z06=(Z3)(((Z06))+(ZQ5(1)));}if(ZGl){ZJ8((ZH*)(((C)->ZQ1)),((T0*)ZWi(ZIk,ZZk(((C)->ZJ1)),((C)->ZJ1),ZZk(((C)->ZK1)),((C)->ZK1))));
Z5m(C,(((ZH*)(((C)->ZQ1)))->Zt1));}}}T0*ZEk(void){if(Z9b==0){Z9b=1;{{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;Z8b=((T0*)n);}}}return Z8b;}
T2 Zcn(T12*C){T2 R=0;T6 ZGl=0;while(!(ZGl)){Zeg(ZBn);if((((C)->ZP1))==((void*)(Zo))){Zeg(ZTg);}else{Zeg(((C)->ZP1));}Zeg(ZCn);if((((C)->ZB1))==((void*)(Zo))){
Zeg(ZTg);}else{Zeg(((C)->ZB1));}Zeg(ZDn);ZDj((T11)(((C)->ZA1)));Zeg(ZEn);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);
}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));ZL7((T7*)(ZIk));if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){R=((C)->ZA1);ZGl=((T6)(1));}else if((T6)(((((((T7*)(ZIk))->Zs1))[ZQ5(0)])==(((T3)'h')))||((T6)((((((T7*)(ZIk))->Zs1))[ZQ5(0)])==(((T3)'H')))))){
ZFn(C);R=ZQ5(-1);ZGl=((T6)(1));}else if(Zi7((T7*)(ZIk))){R=Zx7((T7*)(ZIk));ZGl=((T6)((T6)(((Z3)((R)>(ZQ5(0))))&&((T6)((Z3)((R)<=(ZQ5(6))))))));
}if(!(ZGl)){Zeg(ZGn);Zeg(ZIk);Zeg(ZHn);}}return R;}T0*ZIn=Zo;int ZJn=0;T0*ZKn(T12*C){if(ZJn==0){ZJn=1;{Z3h(&(((C)->Zx1)));if((Zo!=((((C)->Zx1)).Z41))){
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZIn=((T0*)n);ZX6(n,Z5h);}Z6h(&(((C)->Zx1)));Zgh(ZIn,ZLn);ZX6(((T7*)ZIn),Z5h);}}}return ZIn;}T6 ZMn(T12*C,T0*a1){
T6 R=0;T2 Z06=0;Z06=ZQ5(0);while(!((T6)((R)||((T6)((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1)))))))){R=((T6)(Zo6((T7*)((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZJ2)),a1)));
Z06=(Z3)(((Z06))+(ZQ5(1)));}return R;}void ZNn(T0*a1,T0*a2,T0*a3,T6 a4){T0*ZOn=Zo;ZOn=ZPn;ZFk(a1);ZX6(((T7*)ZOn),ZIk);(((void)((T39*)(ZAk()))),Zng(Zo,ZOn));
ZDi((T47*)(Z2l()),ZOn);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){if(!((((T47*)(Z2l()))->Zo2))){ZNg((T47*)(Z2l()));if(ZLi((T47*)(Z2l()),ZOn)){
ZFi((T47*)(Z2l()),ZOn);}else{ZDi((T47*)(Z2l()),ZOn);}}if((((T47*)(Z2l()))->Zo2)){ZX6(((T7*)a2),ZIk);ZX6(((T7*)a3),ZOn);}else if(a4){Zeg(ZQn);
((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));if((ZW5(((((T7*)(ZIk))->Zs1))[ZQ5(0)]))==(((T3)'y'))){
ZX6(((T7*)a2),ZIk);ZX6(((T7*)a3),ZOn);}}else{Z8l(ZIk);}}}void Zln(T12*C){T6 ZRn=0;{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));
(C->ZN1)=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z_6(n,(T2)(ZQ5(16)));(C->ZO1)=((T0*)n);}((((T55*)((T55*)(Zhg))))->Zp1)=((T6)(1));
Z3h(&(((C)->Zx1)));(C->Zy1)=ZM7((T7*)(Z5h));Z6h(&(((C)->Zx1)));Zmn(C);ZSn(C);ZRn=((T6)((T6)(((T6)(((T6)(((((C)->ZB1))!=((void*)(ZTg)))&&((T6)(ZK9(((C)->ZB1))))))&&((T6)(!((((T53*)(ZRg))->ZB2))))))&&((T6)(ZTn(C))))));
Zbl(C);if(!(ZRn)){Z1l(C);}if(Z_k(C)){if(ZRn){(C->ZA1)=ZQ5(3);}else{ZSk(C,(T6)(1));}}else{(C->ZA1)=ZQ5(5);}(C->ZG1)=ZUn;ZX6((T7*)(((C)->ZG1)),((C)->ZC1));
(((void)((T39*)(ZAk()))),Zng(Zo,((C)->ZG1)));(C->ZH1)=ZVn;ZX6((T7*)(((C)->ZH1)),((C)->ZD1));(((void)((T39*)(ZAk()))),Zng(Zo,((C)->ZH1)));
(C->ZI1)=ZWn;ZX6((T7*)(((C)->ZI1)),((C)->ZE1));(((void)((T39*)(ZAk()))),Zng(Zo,((C)->ZI1)));((((T39*)((T39*)(ZAk()))))->ZC1)=(((C)->ZG1));
((((T39*)((T39*)(ZAk()))))->ZD1)=(((C)->ZH1));((((T39*)((T39*)(ZAk()))))->ZE1)=(((C)->ZI1));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZX6(n,Z3k);
(C->ZM1)=((T0*)n);}}void Zfn(T12*C){T2 Z06=0;T0*ZWk=Zo;(C->ZV1)=ZQ5(1);ZXn(C,ZYn);ZXn(C,((C)->ZB1));ZXn(C,ZZn);ZXn(C,((C)->ZP1));ZXn(C,Z_n);
ZXn(C,((C)->ZC1));ZXn(C,Z0o);ZXn(C,((C)->ZD1));ZXn(C,Z1o);ZXn(C,((C)->ZE1));ZUl(C,((T3)'\n'));Z06=ZQ5(0);while(!((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1)))))
{ZWk=((((ZH*)(((C)->ZQ1)))->Zs1))[Z06];if((Z3)((Z06)>(ZQ5(0)))){ZUl(C,((T3)'\n'));}ZXn(C,Z2o);ZXn(C,((((ZD*)ZWk))->ZJ2));ZXn(C,Z3o);ZXn(C,((((ZD*)ZWk))->ZK2));
if((((((ZD*)ZWk))->Z62))!=((void*)(Zo))){ZXn(C,Z4o);ZXn(C,((((ZD*)ZWk))->Z62));}if((((((ZD*)ZWk))->ZL2))!=((void*)(Zo))){ZXn(C,Z5o);ZXn(C,((((ZD*)ZWk))->ZL2));
}if((((((ZD*)ZWk))->Z72))!=((void*)(Zo))){ZXn(C,Z6o);ZXn(C,((((ZD*)ZWk))->Z72));}if((((((ZD*)ZWk))->ZM2))!=((void*)(Zo))){ZXn(C,Z7o);
ZXn(C,((((ZD*)ZWk))->ZM2));}if((T6)(((((((ZD*)ZWk))->ZN2))!=((void*)(Zo)))&&((T6)((((((ZD*)ZWk))->ZN2))!=((void*)(Zxi)))))){ZXn(C,Z8o);
ZXn(C,((((ZD*)ZWk))->ZN2));if((((((ZD*)ZWk))->Z92))!=((void*)(Zo))){ZXn(C,Z9o);ZXn(C,((((ZD*)ZWk))->Z92));}if((((((ZD*)ZWk))->ZO2))!=((void*)(Zo))){
ZXn(C,Zao);ZXn(C,((((ZD*)ZWk))->ZO2));}if((((((ZD*)ZWk))->Za2))!=((void*)(Zo))){ZXn(C,Zbo);ZXn(C,((((ZD*)ZWk))->Za2));}if((((((ZD*)ZWk))->ZP2))!=((void*)(Zo))){
ZXn(C,Zco);ZXn(C,((((ZD*)ZWk))->ZP2));}}if((((((ZD*)ZWk))->ZQ2))!=((void*)(Zo))){ZXn(C,Zdo);ZXn(C,((((ZD*)ZWk))->ZQ2));}Z06=(Z3)(((Z06))+(ZQ5(1)));
}if((((C)->ZS1))!=((void*)(Zo))){ZUl(C,((T3)'\n'));Z06=ZQ5(0);while(!((T6)(((Z3)((Z06)>((((T49*)(((C)->ZS1)))->Zt1))))||((T6)(((((T7*)(((((T49*)(((C)->ZS1)))->Zs1))[Z06]))->Z91))==(ZQ5(0)))))))
{ZXn(C,Zeo);ZXn(C,((((T49*)(((C)->ZS1)))->Zs1))[Z06]);ZXn(C,Zfo);ZXn(C,((((T49*)(((C)->ZT1)))->Zs1))[Z06]);Z06=(Z3)(((Z06))+(ZQ5(1)));
}}if((((C)->ZJ1))!=((void*)(Zo))){ZXn(C,Zgo);ZXn(C,((C)->ZJ1));}else{ZXn(C,Zho);}ZUl(C,((T3)'\n'));Zeg(Zio);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));
{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));}void Zvn(T12*C){T2 Z06=0;T6 ZLg=0;if((Z2f)==((void*)(Zo))){(C->ZB1)=Zjo;
Z06=(((T44*)(Z0n))->Z53);while(!((T6)((ZLg)||((T6)((Z3)((Z06)>((((T44*)(Z0n))->Zt1)))))))){ZJi(&(((C)->Zx1)),ZW7((T44*)(Z0n),Z06));ZLg=((T6)((Zo!=((((C)->Zx1)).Z41))));
Z06=(Z3)(((Z06))+(ZQ5(1)));}if(!(ZLg)){Zpn(C,ZVe);}else{Z6h(&(((C)->Zx1)));}}else{(C->ZB1)=Zwk;ZX6((T7*)(((C)->ZB1)),Z2f);if((Z07((T7*)(((C)->ZB1))))!=(((T3)'\134'))){
Z26((T7*)(((C)->ZB1)),((T3)'\134'));}Zb7((T7*)(((C)->ZB1)),Zko);}}void Zlo(T0*a1){((((T7*)((T7*)(ZBk))))->Z91)=(ZQ5(0));Znh((T39*)(ZAk()),ZBk,Zmo);
Z26((T7*)(ZBk),((T3)'\040'));Zb7((T7*)(ZBk),a1);Zeg(ZBk);{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}Zra((T51*)(ZEk()),ZBk);}T0*Zno=Zo;int
Zoo=0;T0*Zpo(void){if(Zoo==0){Zoo=1;{{ZP*n=((ZP*)Zh(sizeof(*n)));*n=Z43;Zno=((T0*)n);{ZP*C1=n;Zp9(C1,Zb8(193));}}}}return Zno;}void Zqo(T12*C){
if((((C)->ZB1))!=((void*)(ZTg))){Zjh(((C)->ZB1));if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){ZYm(C,Z5h);}ZY9((ZR*)(Z4m),((C)->ZB1));if(!(((((ZR*)(Z4m))->Z_1))!=(Zo))){
Zqa(Z3l);Zqa(Zro);Zqa(((C)->ZB1));Zqa(Zja(2,Zk3));Z4l(C);}}}T0*Zxm(T0*a1,T0*a2){T0*R=Zo;if(Zo9((ZP*)(Zpo()),a1)){R=Zl9((ZP*)(Zpo()),a1);
}else if((a2)!=((void*)(Zo))){ZVh((T76*)(Z7n()),a2);if(((((T76*)(Z7n()))->Z_1))!=(Zo)){{T53*n=((T53*)Zh(sizeof(*n)));*n=M53;R=((T0*)n);
}ZWh(((T53*)R));}Zm9((ZP*)(Zpo()),R,ZM7(((T7*)a1)));}return R;}void Zhn(T12*C){if(((C)->ZU1)){(C->Zz1)=((T6)(1));}else{Zeg(Zso);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));
{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));ZL7((T7*)(ZIk));(C->Zz1)=((T6)((T6)(((Z3)(((((T7*)(ZIk))->Z91))>(ZQ5(0))))&&((T6)((((((T7*)(ZIk))->Zs1))[ZQ5(0)])==(((T3)'y')))))));
}}void Z4l(T12*C){Zqa(Zto);Zuo(C);Zvo(C,ZQ5(1));}void Zuo(T12*C){if((((C)->Zy1))!=((void*)(Zo))){Zwo(&(((C)->Zx1)),((C)->Zy1));}}T0*Zxo(void){
T0*R=Zo;{T85*n=((T85*)Zh(1));R=((T0*)n);}return R;}T0*ZBk=Zo;void ZRl(T12*C,T2 a1){Zeg(Zyo);Zeg(((((T49*)(((C)->ZS1)))->Zs1))[a1]);Zeg(Zzo);
Zeg(((((T49*)(((C)->ZT1)))->Zs1))[a1]);{T3 b1=((T3)'\056');ZH9((T32*)(ZI9),b1);}ZFk(ZAo);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){ZX6((T7*)(((((T49*)(((C)->ZT1)))->Zs1))[a1]),ZIk);
}}T6 ZTn(T12*C){T6 R=0;T0*ZYk=Zo;T0*ZBo=Zo;T0*ZCo=Zo;T0*ZDo=Zo;T0*ZEo=Zo;T0*ZT7=Zo;T0*ZWk=Zo;T0*ZFo=Zo;if(ZXh((T53*)(ZRg),ZYh,ZGo)){ZFo=Zuh((T53*)(ZRg),ZYh,ZGo);
}else{ZFo=ZHo;}if(!(Zo6(((T7*)ZFo),ZIo))){Zeg(Zja(67,"*** Your installation file has an old format. It will not be used.\n"));}else{if((T6)(((T6)(((T6)((!(ZXh((T53*)(ZRg),ZYh,ZZh)))||((T6)(!(ZXh((T53*)(ZRg),ZYh,Z0i))))))||((T6)(!(ZXh((T53*)(ZRg),ZYh,Z1i))))))||((T6)(!(ZXh((T53*)(ZRg),ZYh,Z2i)))))){
Zeg(ZJo);}else{(C->ZC1)=Zuh((T53*)(ZRg),ZYh,ZZh);(C->ZD1)=Zuh((T53*)(ZRg),ZYh,Z0i);(C->ZE1)=Zuh((T53*)(ZRg),ZYh,Z1i);Zpn(C,Zuh((T53*)(ZRg),ZYh,Z2i));
ZBo=Zqh((T53*)(ZRg),Zrh);if((ZBo)!=((void*)(Zo))){{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;Zx8(n,(T2)(ZQ5(4)));(C->ZS1)=((T0*)n);}{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;Zx8(n,(T2)(ZQ5(4)));(C->ZT1)=((T0*)n);}while(!(Zsh(ZBo))){Zv8((T49*)(((C)->ZS1)),Zvh(ZBo));Zv8((T49*)(((C)->ZT1)),Zuh((T53*)(ZRg),Zrh,Zvh(ZBo)));
Zwh(ZBo);}}ZYk=Z0l((T53*)(ZRg));if((ZYk)!=((void*)(Zo))){ZKo(ZYk);{ZH*n=((ZH*)Zh(sizeof(*n)));*n=ZY1;ZK8(n,(T2)(ZQ5(8)));(C->ZQ1)=((T0*)n);
}{ZH*n=((ZH*)Zh(sizeof(*n)));*n=ZY1;ZK8(n,(T2)(ZQ5(8)));(C->ZR1)=((T0*)n);}while(!(Zsh(ZYk))){ZCo=Zvh(ZYk);if((T6)(((T6)((!(Zo6(((T7*)ZCo),ZYh)))&&((T6)(!(Zo6(((T7*)ZCo),Zrh))))))&&((T6)(ZXh((T53*)(ZRg),ZCo,Zdj))))){
ZDo=Zuh((T53*)(ZRg),ZCo,Zdj);if(ZXh((T53*)(ZRg),ZCo,Zjj)){ZEo=Zuh((T53*)(ZRg),ZCo,Zjj);}else{ZEo=Zo;}{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Z23;
ZXi(n,ZCo,ZZk(ZDo),ZDo,ZZk(ZEo),ZEo);ZWk=((T0*)n);}if(ZXh((T53*)(ZRg),ZCo,Zej)){ZT7=Zuh((T53*)(ZRg),ZCo,Zej);Z6j(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Zfj)){
ZT7=Zuh((T53*)(ZRg),ZCo,Zfj);Z7j(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Zgj)){ZT7=Zuh((T53*)(ZRg),ZCo,Zgj);Z8j(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Zhj)){
ZT7=Zuh((T53*)(ZRg),ZCo,Zhj);Z9j(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Zij)){ZT7=Zuh((T53*)(ZRg),ZCo,Zij);Z1j(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Zkj)){
ZT7=Zuh((T53*)(ZRg),ZCo,Zkj);Z0j(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Zlj)){ZT7=Zuh((T53*)(ZRg),ZCo,Zlj);Zaj(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Zmj)){
ZT7=Zuh((T53*)(ZRg),ZCo,Zmj);Z2j(((ZD*)ZWk),ZT7);}if(ZXh((T53*)(ZRg),ZCo,Znj)){ZT7=Zuh((T53*)(ZRg),ZCo,Znj);Zbj(((ZD*)ZWk),ZT7);}ZJ8((ZH*)(((C)->ZQ1)),ZWk);
}Zwh(ZYk);}}R=((T6)(1));}}return R;}void Zpn(T12*C,T0*a1){T0*ZLo=Zo;T2 Z06=0;ZLo=a1;if(!(Z68((T44*)((((void)((T39*)(ZAk()))),ZNe())),ZLo))){
Z06=ZY7((T44*)((((void)((T39*)(ZAk()))),ZNe())),a1);if(ZX7((T44*)((((void)((T39*)(ZAk()))),ZNe())),Z06)){ZLo=ZW7((T44*)((((void)((T39*)(ZAk()))),ZNe())),Z06);
}else{ZLo=ZTg;}}if((ZLo)!=((void*)(ZTg))){(C->ZP1)=ZLo;Z4g((T39*)(ZAk()),ZLo);}}void ZXn(T12*C,T0*a1){T2 Z06=0;T0*ZMo=Zo;if((a1)==((void*)(Zo))){
ZMo=ZTg;}else{ZMo=a1;}Z06=ZQ5(1);while(!((Z3)((Z06)>(((((T7*)ZMo))->Z91))))){ZUl(C,(((((T7*)ZMo))->Zs1))[(Z06)-(ZQ5(1))]);Z06=(Z3)(((Z06))+(ZQ5(1)));
}}T0*ZNo=Zo;int ZOo=0;T0*Zzm(void){if(ZOo==0){ZOo=1;{{T69*n=((T69*)Zh(sizeof(*n)));*n=M69;ZNo=((T0*)n);Ze9(n);}}}return ZNo;}T0*ZIk=Zo;
void ZSn(T12*C){T2 Z06=0;T0*ZPo=Zo;T0*ZY6=Zo;T0*ZQo=Zo;T0*ZRo=Zo;ZGi((T47*)(Z2l()),ZKn(C));if((((T47*)(Z2l()))->Zo2)){Z06=ZQ5(1);while(!((Z3)((Z06)>(ZEi((T47*)(Z2l()))))))
{ZPo=ZSo;ZQo=ZTo;ZX6(((T7*)ZPo),(((((T49*)((((T47*)(Z2l()))->Zp2))))->Zs1))[(Z06)-(ZQ5(1))]);ZL7(((T7*)ZPo));ZX6(((T7*)ZQo),ZPo);if(Zh7(((T7*)ZPo),ZUo)){
Zu7(((T7*)ZQo),(T2)(ZQ5(3)));ZXl((((T47*)(Z2l()))->Z_1),ZPo);ZX6(((T7*)ZPo),Z5h);ZRo=Zxm(ZQo,ZPo);if((ZRo)!=((void*)(Zo))){ZQo=ZM7(((T7*)ZQo));
if(Zcj(((T53*)ZRo),Zdj)){ZY6=Zl8(((T65*)(((((T53*)ZRo))->ZF2))),Zdj);if((T6)(((T6)(((ZY6)!=((void*)(Zo)))&&((T6)(!(Zo6(((T7*)ZY6),Zxi))))))&&((T6)(Z58((T44*)((((void)((T39*)(ZAk()))),ZDh())),ZY6))))){
ZY6=ZW7((T44*)((((void)((T39*)(ZAk()))),ZDh())),ZY7((T44*)((((void)((T39*)(ZAk()))),ZDh())),ZY6));Zoj(Zzm(),ZY6,ZQo);}else{Zqa(Z3l);Zqa(ZVo);
Zqa(ZPo);Zqa(ZWo);Zqa(Zdj);Zqa(ZXo);Z4l(C);}}else{Zqa(Z3l);Zqa(ZYo);Zqa(ZPo);Zqa(ZZo);Zqa(Zdj);Zqa(Z_o);Z4l(C);}if(Zcj(((T53*)ZRo),Zjj)){
ZY6=Zl8(((T65*)(((((T53*)ZRo))->ZF2))),Zjj);if((T6)(((ZY6)!=((void*)(Zo)))&&((T6)(!(Zo6(((T7*)ZY6),Zxi)))))){if(Z58((T44*)((((void)((T39*)(ZAk()))),Zwi())),ZY6)){
ZY6=ZW7((T44*)((((void)((T39*)(ZAk()))),Zwi())),ZY7((T44*)((((void)((T39*)(ZAk()))),Zwi())),ZY6));Zoj(ZBl(),ZY6,ZQo);}else{Zqa(Z3l);Zqa(Z0p);
Zqa(ZPo);Zqa(Z1p);Zqa(Zjj);Zqa(Z2p);Z4l(C);}}}}}Z06=(Z3)(((Z06))+(ZQ5(1)));}}}void Zen(T12*C){T6 ZHl=0;T6 ZIl=0;T0*Z3p=Zo;T2 Z06=0;T2
ZIi=0;(C->ZU1)=((T6)(0));ZIl=((T6)(1));while(!(ZHl)){Zeg(Z4p);if((((C)->ZJ1))==((void*)(Zo))){Zeg(ZTg);}else{Zeg(((C)->ZJ1));}{T3 b1=((T3)'\n');
ZH9((T32*)(ZI9),b1);}{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}Z06=ZQ5(0);while(!((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1))))){ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(1))))));
Zeg(Z5p);Zeg((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZJ2));Zeg(Z6p);Z06=(Z3)(((Z06))+(ZQ5(1)));}Z06=(Z3)(((Z06))+(ZQ5(1)));{T3 b1=((T3)'\n');
ZH9((T32*)(ZI9),b1);}ZDj((T11)(Z06));Zeg(Z7p);ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(1))))));{T0*b1=Z8p;T0*b2=((C)->ZJ1);Zbm(b1,b2,Zo);}ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(2))))));
{T0*b1=Z9p;T0*b2=((C)->ZN1);Zbm(b1,b2,Zo);}{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(3))))));Zeg(Zja(40,". Return to the main menu\n\nYour choice ["));
if(ZIl){ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(1))))));}else{ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(3))))));}Zeg(Zap);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));
{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){if(ZIl){Zb6((Z3)(((Z06))+((T2)(ZQ5(1)))),ZIk);
}else{Zb6((Z3)(((Z06))+((T2)(ZQ5(3)))),ZIk);}}if(Zi7((T7*)(ZIk))){ZIi=Zx7((T7*)(ZIk));if((T6)(((Z3)((ZIi)<(ZQ5(1))))||((T6)((Z3)((ZIi)>((Z3)(((Z06))+(ZQ5(3))))))))){
Zeg(Zbp);ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(3))))));Zeg(Zcp);}else{{int z1=(Z3)(((ZIi))-(Z06));switch(z1){case 3:ZHl=((T6)(1));break;case
2:ZFk(Zdp);ZX6((T7*)(((C)->ZN1)),ZIk);Z06=ZQ5(0);while(!((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1))))){if((T6)((((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->Z72))!=((void*)(Zo)))&&((T6)((Z3)(((((T7*)((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->Z72)))->Z91))>(ZQ5(0))))))){
Z9j((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]),((C)->ZN1));}else{Z9j((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]),Zo);}Z7j((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]),((C)->ZN1));
Z06=(Z3)(((Z06))+(ZQ5(1)));}ZX6((T7*)(((C)->ZO1)),((C)->ZN1));if((T6)(((((C)->ZK1))!=((void*)(Zo)))&&((T6)((((C)->ZK1))!=((void*)(Zxi)))))){
ZFk(Zep);ZX6((T7*)(((C)->ZO1)),ZIk);Z06=ZQ5(0);while(!((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1))))){if((T6)((((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->Za2))!=((void*)(Zo)))&&((T6)((Z3)(((((T7*)((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->Za2)))->Z91))>(ZQ5(0))))))){
Zbj((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]),((C)->ZO1));}else{Zbj((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]),Zo);}Zaj((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]),((C)->ZO1));
Z06=(Z3)(((Z06))+(ZQ5(1)));}}break;case 1:Z3p=((C)->ZJ1);(C->ZJ1)=Zfp(Zgp,Zum(),Z3p);((((T7*)((T7*)(((C)->ZN1)))))->Z91)=(ZQ5(0));if(Z58((T44*)((((void)((T39*)(ZAk()))),Zwi())),((C)->ZJ1))){
(C->ZK1)=((C)->ZJ1);ZX6((T7*)(((C)->ZO1)),((C)->ZN1));}else{Zeg(Zhp);Z3p=((C)->ZK1);if((T6)(((Z3p)==((void*)(Zo)))||((T6)((Z3p)==((void*)(ZTg)))))){
Z3p=Zxi;}(C->ZK1)=Zfp(Zip,ZIm(),Z3p);if((((C)->ZK1))==((void*)(Zxi))){(C->ZK1)=ZTg;}((((T7*)((T7*)(((C)->ZO1)))))->Z91)=(ZQ5(0));}ZSk(C,(T6)(1));
break;case 0:Zxn(C);break;default:;Z5m(C,(Z3)(((ZIi))-((T2)(ZQ5(1)))));}}}ZIl=((T6)(0));}else{Zeg(Zjp);ZDj((T11)((Z3)(((Z06))+((T2)(ZQ5(3))))));
Zeg(Zkp);}}}void Ztl(T12*C){T0*Zlp=Zo;T0*Zmp=Zo;T0*Znp=Zo;T0*Zop=Zo;T0*Zpp=Zo;T0*Zqp=Zo;T0*Zrp=Zo;T0*ZG7=Zo;T2 Z06=0;T6 Zsp=0;T6 ZLg=0;
T6 Ztp=0;Zlp=Zup;Zmp=Zvp;Zsp=((T6)(1));ZNg((T47*)(Z2l()));if(!(ZLi((T47*)(Z2l()),Zlp))){Zsp=((T6)(0));}else{ZFi((T47*)(Z2l()),Zlp);if(!(ZLi((T47*)(Z2l()),Zmp))){
Zsp=((T6)(0));}else{ZFi((T47*)(Z2l()),Zmp);}}if(!(Zsp)){Zqa(Z3l);Zqa(Zwp);Z4l(C);}ZX6((T7*)(Zvk),(((T47*)(Z2l()))->Z_1));{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZX6(n,Zvk);(C->ZF1)=((T0*)n);}if((Zo!=((((C)->Zx1)).Z41))){Z6h(&(((C)->Zx1)));}Zeg(Zxp);Zeg(Zyp);while(!(ZLg)){Zeg(Zzp);Zeg(((C)->ZM1));
Zeg(ZAp);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){
ZLg=((T6)(1));Z06=ZQ5(0);ZLg=((T6)(0));while(!(ZLg)){if(Zo6((T7*)((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZJ2)),((C)->ZM1))){Znp=(((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZK2);
ZLg=((T6)(1));}else{Z06=(Z3)(((Z06))+(ZQ5(1)));}}}else{Z06=ZQ5(0);ZLg=((T6)(0));while(!((T6)((ZLg)||((T6)((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1))))))))
{ZLg=((T6)(Zo6((T7*)((((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZJ2)),ZIk)));if(ZLg){ZX6((T7*)(((C)->ZM1)),ZIk);Znp=(((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZK2);
}else{Z06=(Z3)(((Z06))+(ZQ5(1)));}}if(!(ZLg)){Zeg(ZBp);}}}(C->ZL1)=Znp;Zop=(((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZL2);if((Zop)==((void*)(Zo))){
Zop=ZCp;}Zpp=(((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->ZM2);if((Zpp)==((void*)(Zo))){Zpp=ZDp;}Ztp=((T6)(1));Zwo(&(((C)->Zx1)),((C)->ZG1));
if(((((T7*)(Z5h))->Z91))==(ZQ5(0))){if(!(ZEp(((C)->ZG1)))){Zqa(ZFp);Ztp=((T6)(0));}else{Zwo(&(((C)->Zx1)),((C)->ZG1));}}if(Ztp){Zeg(ZGp);
Zeg(((C)->ZM1));Zeg(ZHp);Zeg(Znp);Zeg(ZIp);Zeg(Zop);Zeg(ZJp);Zeg(Zpp);Zeg(ZKp);ZJh((T39*)(ZAk()),Znp,(((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->Z62),(((ZD*)(((((ZH*)(((C)->ZQ1)))->Zs1))[Z06]))->Z72));
ZX6((T7*)(ZBe),Zop);ZX6((T7*)(ZDe),Zpp);Zwo(&(((C)->Zx1)),((C)->ZF1));Zqp=ZLp;ZXf((T39*)(ZAk()));ZMp(C,Zqp);ZNp(C,Zqp);ZJi(&(((C)->Zx1)),((C)->ZF1));
if((Zo!=((((C)->Zx1)).Z41))){Zrp=Zkf((T39*)(ZAk()));ZKi(&(((C)->Zx1)));while(!(ZE5(((T8)(((((C)->Zx1)).Z51)))))){ZG7=ZOp;ZX6(((T7*)ZG7),Z5h);
if(Zh7(((T7*)ZG7),Zrp)){ZXl(((C)->ZF1),ZG7);if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){ZX6(((T7*)ZG7),Z5h);ZO9(ZG7);}}ZKi(&(((C)->Zx1)));
}}Z6h(&(((C)->Zx1)));Zwo(&(((C)->Zx1)),((C)->ZG1));ZPp(C);ZJk(C);}Zuo(C);}void ZQp(T0*a1){T0*ZRp=Zo;T0*ZSp=Zo;((((T86*)((T86*)(ZEf))))->Zn1)=(a1);
Zeg(ZTp);Zeg(a1);{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}ZRp=ZM7(((T7*)a1));Zb7(((T7*)ZRp),ZUp);((((T86*)((T86*)(ZEf))))->Zn1)=(a1);ZSp=Z3f((T39*)(ZAk()),ZRp);
Zeg(ZSp);{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}Zra((T51*)(ZEk()),ZSp);}T0*ZVp=Zo;int ZWp=0;T0*ZIm(void){if(ZWp==0){ZWp=1;{{T44*n=((T44*)Zh(sizeof(*n)));
*n=M44;ZVp=((T0*)n);ZZ7(n,(T2)(ZQ5(1)),(T2)(ZQ5(0)));}ZXp(ZBl(),ZVp);Z18(((T44*)ZVp),Zxi);}}return ZVp;}T0*ZOk=Zo;void ZMp(T12*C,T0*a1){
T0*ZIi=Zo;T0*ZSp=Zo;T2 Z06=0;T2 Z9m=0;((((T86*)((T86*)(ZEf))))->Zn1)=(a1);ZIi=ZYp;ZX6(((T7*)ZIi),a1);Zb7(((T7*)ZIi),ZZp);ZNg((T47*)(Z2l()));
if(ZLi((T47*)(Z2l()),ZIi)){ZQp(a1);}else{Z06=ZQ5(1);while(!((Z3)((Z06)>(ZEi((T47*)(Z2l())))))){ZIi=ZM7((T7*)((((((T49*)((((T47*)(Z2l()))->Zp2))))->Zs1))[(Z06)-(ZQ5(1))]));
Z5n(C,ZIi);if(!(Zp7(((T7*)ZIi),a1))){}else if(!(Zh7(((T7*)ZIi),Z_p))){}else{Z9m=(Z3)(((Z9m))+(ZQ5(1)));ZSp=Zrg((T39*)(ZAk()),ZIi);Zeg(ZSp);
{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}Zra((T51*)(ZEk()),ZSp);}Z06=(Z3)(((Z06))+(ZQ5(1)));}if((Z3)((Z9m)>(ZQ5(0)))){ZSp=Z6i((T39*)(ZAk()),a1,Z9m);
Zeg(ZSp);{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}Zra((T51*)(ZEk()),ZSp);Zsi((T39*)(ZAk()),a1);}}}void ZPp(T12*C){T2 Z06=0;T0*ZKk=Zo;T0*ZLk=Zo;
Z06=ZQ5(1);while(!((Z3)((Z06)>(ZV7((T44*)(ZPk)))))){ZLk=ZW7((T44*)(ZPk),Z06);if(Z58((T44*)(ZOk),ZLk)){ZKk=ZMk(C,Z0q);Zvl(ZKk,ZLk);ZQp(ZLk);
}else{ZKk=ZMk(C,Zo);Zvl(ZKk,ZLk);ZMp(C,ZLk);}Z06=(Z3)(((Z06))+(ZQ5(1)));}Z06=ZQ5(1);while(!((Z3)((Z06)>(ZV7((T44*)(ZPk)))))){ZLk=ZW7((T44*)(ZPk),Z06);
Zlo(ZLk);Z06=(Z3)(((Z06))+(ZQ5(1)));}}void ZQl(T12*C,T2 a1){T6 ZGl=0;T2 ZIi=0;T0*Z1q=Zo;T0*Z2q=Zo;while(!(ZGl)){ZFk(Z3q);if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){
ZGl=((T6)(1));}else{if(Zi7((T7*)(ZIk))){ZIi=Zx7((T7*)(ZIk));if((T6)(((Z3)((ZIi)>=(ZQ5(1))))&&((T6)((Z3)((ZIi)<=(a1)))))){ZGl=((T6)(1));
Z1q=((((T49*)(((C)->ZS1)))->Zs1))[(Z3)(((ZIi))-(ZQ5(1)))];Z2q=((((T49*)(((C)->ZT1)))->Zs1))[(Z3)(((ZIi))-(ZQ5(1)))];ZB8((T49*)(((C)->ZS1)),(Z3)(((ZIi))-((T2)(ZQ5(1)))));
ZB8((T49*)(((C)->ZT1)),(Z3)(((ZIi))-((T2)(ZQ5(1)))));((((T7*)(((T7*)Z1q))))->Z91)=(ZQ5(0));((((T7*)(((T7*)Z2q))))->Z91)=(ZQ5(0));Zv8((T49*)(((C)->ZS1)),Z1q);
Zv8((T49*)(((C)->ZT1)),Z2q);}}if(!(ZGl)){Zeg(Z4q);ZDj((T11)(a1));Zeg(Z5q);}}}}void Zvo(T12*C,T2 a1){if((T6)(((((C)->ZP1))==((void*)(Zo)))||((T6)(ZB7(((T7*)Z6q),((C)->ZP1)))))){
Zeg(Z7q);Zde((T38*)(ZCj));}Zv(a1);}T0*Z9n(T0*a1){T0*R=Zo;if((a1)!=((void*)(Zo))){if((Z8q(Zzm(),a1))==(ZQ5(1))){R=Z9q(Zzm(),a1);}else if((Z8q(ZBl(),a1))==(ZQ5(1))){
R=Z9q(ZBl(),a1);}}return R;}T0*Zaq=Zo;int Zbq=0;T0*Z2l(void){if(Zbq==0){Zbq=1;{{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;Zaq=((T0*)n);Zlg(n);
}}}return Zaq;}T6 Z_k(T12*C){T6 R=0;T2 Zcq=0;T0*Zdq=Zo;T0*ZWk=Zo;T6 Zeq=0;T0*ZUk=Zo;T0*ZVk=Zo;Zdq=Zvk;if((((C)->ZQ1))==((void*)(Zo))){
R=((T6)(1));{ZH*n=((ZH*)Zh(sizeof(*n)));*n=ZY1;ZK8(n,(T2)(ZQ5(8)));(C->ZQ1)=((T0*)n);}}if((((C)->ZR1))==((void*)(Zo))){{ZH*n=((ZH*)Zh(sizeof(*n)));
*n=ZY1;ZK8(n,(T2)(ZQ5(8)));(C->ZR1)=((T0*)n);}}if((((C)->ZJ1))!=((void*)(Zo))){ZUk=ZZk(((C)->ZJ1));}Zcq=ZQ5(1);Zeq=((T6)(1));while(!((Z3)((Zcq)>(ZQ5(8)))))
{ZX6((T7*)(Zvk),(((void)((T85*)(Zxo()))),Z1k(Zcq)));if((Zcq)!=(ZQ5(1))){Zb7((T7*)(Zvk),Zfq);}if(!(ZMn(C,Zvk))){if((Z3)(((((ZH*)(((C)->ZR1)))->Zt1))<(ZQ5(0)))){
if((((C)->ZJ1))==((void*)(Zo))){{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Z23;ZXi(n,Zvk,Zo,ZTg,Zo,ZTg);ZWk=((T0*)n);}}else{{ZD*n=((ZD*)Zh(sizeof(*n)));
*n=Z23;ZXi(n,Zvk,ZUk,((C)->ZJ1),ZVk,((C)->ZK1));ZWk=((T0*)n);}}}else{ZWk=((((ZH*)(((C)->ZR1)))->Zs1))[ZQ5(0)];ZH8((ZH*)(((C)->ZR1)));
if((((C)->ZJ1))==((void*)(Zo))){Z3j(((ZD*)ZWk),Zvk,Zo,ZTg,Zo,Zo);}else{Z3j(((ZD*)ZWk),Zvk,ZUk,((C)->ZJ1),ZVk,((C)->ZK1));}}if(!(((((ZD*)ZWk))->ZR2))){
Zeq=((T6)(0));if((Zcq)==(ZQ5(8))){Z1j(((ZD*)ZWk),Zgq);}}ZJ8((ZH*)(((C)->ZQ1)),ZWk);R=((T6)(1));}Zcq=(Z3)(((Zcq))+(ZQ5(1)));}if(Zeq){(C->ZA1)=ZQ5(3);
}return R;}void ZFn(T12*C){(C->ZV1)=ZQ5(1);ZXn(C,Zhq);ZXn(C,Ziq);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);
}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));}void Zjq(T0*a1,T0*a2){if((a2)!=((void*)(Zo))){Zgi((ZR*)(Z4m),a1);Zgi((ZR*)(Z4m),Zkq);Zgi((ZR*)(Z4m),a2);
Zii((ZR*)(Z4m),((T3)'\n'));}}void Zgn(T12*C){T2 Z06=0;T0*ZWk=Zo;if(ZK9(((C)->ZB1))){ZX6((T7*)(Zvk),((C)->ZB1));Z26((T7*)(Zvk),((T3)'\176'));
Zeg(Zlq);Zeg(((C)->ZB1));Zeg(Zmq);Zeg(Zvk);{T3 b1=((T3)'\n');ZH9((T32*)(ZI9),b1);}ZS9(((C)->ZB1),Zvk);}Zqo(C);if(!(((((ZR*)(Z4m))->Z_1))!=(Zo))){
Zeg(Znq);(C->ZA1)=ZQ5(1);}else{Zgi((ZR*)(Z4m),Zoq);Zgi((ZR*)(Z4m),Zpq);Zgi((ZR*)(Z4m),Zqq);Zgi((ZR*)(Z4m),Zrq);Zgi((ZR*)(Z4m),((C)->ZC1));
Zii((ZR*)(Z4m),((T3)'\n'));Zgi((ZR*)(Z4m),Zsq);Zgi((ZR*)(Z4m),((C)->ZD1));Zii((ZR*)(Z4m),((T3)'\n'));Zgi((ZR*)(Z4m),Ztq);Zgi((ZR*)(Z4m),((C)->ZE1));
Zii((ZR*)(Z4m),((T3)'\n'));Zgi((ZR*)(Z4m),Zuq);Zgi((ZR*)(Z4m),((C)->ZP1));Zii((ZR*)(Z4m),((T3)'\n'));Zgi((ZR*)(Z4m),Zvq);Zgi((ZR*)(Z4m),ZIo);
Zii((ZR*)(Z4m),((T3)'\n'));if((((C)->ZS1))!=((void*)(Zo))){Zii((ZR*)(Z4m),((T3)'\n'));Zgi((ZR*)(Z4m),Zwq);Zgi((ZR*)(Z4m),Zxq);Z06=ZQ5(0);
while(!((T6)(((Z3)((Z06)>((((T49*)(((C)->ZS1)))->Zt1))))||((T6)(((((T7*)(((((T49*)(((C)->ZS1)))->Zs1))[Z06]))->Z91))==(ZQ5(0))))))){Zgi((ZR*)(Z4m),((((T49*)(((C)->ZS1)))->Zs1))[Z06]);
Zgi((ZR*)(Z4m),Zyq);Zgi((ZR*)(Z4m),((((T49*)(((C)->ZT1)))->Zs1))[Z06]);Zii((ZR*)(Z4m),((T3)'\n'));Z06=(Z3)(((Z06))+(ZQ5(1)));}}Zgi((ZR*)(Z4m),Zzq);
Z06=ZQ5(0);while(!((Z3)((Z06)>((((ZH*)(((C)->ZQ1)))->Zt1))))){ZWk=((((ZH*)(((C)->ZQ1)))->Zs1))[Z06];Zii((ZR*)(Z4m),((T3)'\n'));Zii((ZR*)(Z4m),((T3)'\133'));
Zgi((ZR*)(Z4m),((((ZD*)ZWk))->ZJ2));Zgi((ZR*)(Z4m),ZAq);Zjq(Zdj,((((ZD*)ZWk))->ZK2));Zjq(Zej,((((ZD*)ZWk))->Z62));Zjq(Zfj,((((ZD*)ZWk))->ZL2));
Zjq(Zgj,((((ZD*)ZWk))->Z72));Zjq(Zhj,((((ZD*)ZWk))->ZM2));Zjq(Zjj,((((ZD*)ZWk))->ZN2));Zjq(Zkj,((((ZD*)ZWk))->Z92));Zjq(Zlj,((((ZD*)ZWk))->ZO2));
Zjq(Zmj,((((ZD*)ZWk))->Za2));Zjq(Znj,((((ZD*)ZWk))->ZP2));Zjq(Zij,((((ZD*)ZWk))->ZQ2));Z06=(Z3)(((Z06))+(ZQ5(1)));}Zji((ZR*)(Z4m));}}
void Zdn(T12*C){T6 ZHl=0;T6 ZIl=0;T2 ZIi=0;int ZBq=0;(C->ZU1)=((T6)(0));ZIl=((T6)(1));while(!(ZHl)){Zeg(ZCq);{T0*b1=ZDq;T0*b2=((C)->ZB1);
Zbm(b1,b2,Zo);}{T0*b1=ZEq;T0*b2=((C)->ZP1);Zbm(b1,b2,Zo);}{T0*b1=ZFq;T0*b2=((C)->ZC1);Zbm(b1,b2,Zo);}{T0*b1=ZGq;T0*b2=((C)->ZD1);Zbm(b1,b2,Zo);
}{T0*b1=ZHq;T0*b2=((C)->ZE1);Zbm(b1,b2,Zo);}Zeg(ZIq);if(ZIl){Zeg(ZJq);}else{Zeg(ZKq);}((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;
Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){if(ZIl){ZZ5(ZQ5(2),ZIk);}else{ZZ5(ZQ5(7),ZIk);
}}if(ZO7((T7*)(ZIk))){ZIi=Zx7((T7*)(ZIk));if((T6)(((Z3)((ZIi)<(ZQ5(1))))||((T6)((Z3)((ZIi)>(ZQ5(7))))))){Zeg(ZLq);}else{{int z1=ZIi;switch(z1){
case 1:ZFk(ZMq);if(!(((((T7*)(ZIk))->Z91))==(ZQ5(0)))){ZX6((T7*)(Zwk),ZIk);if((((C)->ZB1))==((void*)(ZTg))){Zeg(ZNq);Zeg(Zwk);}(C->ZB1)=Zwk;
{T0*b1=ZOq;T0*b2=((C)->ZB1);Zx5(ZK7(((T7*)b1)),ZK7(((T7*)b2)));}}break;case 2:Zpn(C,Zfp(ZPq,(((void)((T39*)(ZAk()))),ZNe()),((C)->ZP1)));
break;case 3:ZNn(ZQq,((C)->ZC1),((C)->ZG1),(T6)(1));((((T39*)((T39*)(ZAk()))))->ZC1)=(((C)->ZG1));break;case 4:ZNn(ZRq,((C)->ZD1),((C)->ZH1),(T6)(0));
((((T39*)((T39*)(ZAk()))))->ZD1)=(((C)->ZH1));break;case 5:ZNn(ZSq,((C)->ZE1),((C)->ZI1),(T6)(0));((((T39*)((T39*)(ZAk()))))->ZE1)=(((C)->ZI1));
break;case 6:ZFl(C);break;default:;ZHl=((T6)(1));}}ZIl=((T6)(0));}}else{Zeg(ZTq);}}}void ZNp(T12*C,T0*a1){T0*ZUq=Zo;T0*ZVq=Zo;T0*ZWq=Zo;
ZUq=Zvk;ZX6(((T7*)ZUq),a1);ZHf((T39*)(ZAk()),ZUq);ZXl(((C)->ZF1),ZUq);ZVq=ZXq;ZX6(((T7*)ZVq),Z5h);ZXl(((C)->ZG1),ZUq);ZWq=ZYq;ZX6(((T7*)ZWq),Z5h);
if(!(ZK9(ZVq))){Zqa(Z3l);Zqa(ZZq);Zqa(ZVq);Zqa(Z_q);Z4l(C);}if(!(ZB7((T7*)(ZYe),((C)->ZP1)))){ZP9((T51*)(ZEk()),ZVq,ZWq);}else{ZX6((T7*)(ZBk),Z0r);
Zb7((T7*)(ZBk),ZVq);Z26((T7*)(ZBk),((T3)'\040'));Zb7((T7*)(ZBk),ZWq);Zra((T51*)(ZEk()),ZBk);}}void Zbm(T0*a1,T0*a2,T0*a3){Zeg(a1);Zeg(Z1r);
if((T6)(((a2)==((void*)(Zo)))||((T6)((((((T7*)a2))->Z91))==(ZQ5(0)))))){if((a3)==((void*)(Zo))){Zeg(Z2r);}else{Zeg(Z3r);Zeg(a3);}}else{
Zeg(a2);}Zeg(Z4r);}T0*Z5r=Zo;int Z6r=0;T0*Zum(void){if(Z6r==0){Z6r=1;{{T44*n=((T44*)Zh(sizeof(*n)));*n=M44;Z5r=((T0*)n);ZZ7(n,(T2)(ZQ5(1)),(T2)(ZQ5(0)));
}ZXp(Zzm(),Z5r);}}return Z5r;}T0*Zfp(T0*a1,T0*a2,T0*a3){T0*R=Zo;T2 Z06=0;T6 Z7r=0;T0*Z8r=Zo;T0*Zti=Zo;while(!((R)!=((void*)(Zo)))){Zeg(a1);
Zeg(Z9r);Z06=ZQ5(1);while(!((Z3)((Z06)>(((((T44*)a2))->Zt1))))){Zti=Z19(a2,Z06);if((Zti)==((void*)(a3))){{T3 b1=((T3)'\074');ZH9((T32*)(ZI9),b1);
}Zeg(Zti);{T3 b1=((T3)'\076');ZH9((T32*)(ZI9),b1);}}else{Zeg(Zti);}Z06=(Z3)(((Z06))+(ZQ5(1)));if((Z3)((Z06)<=(((((T44*)a2))->Zt1)))){
Zeg(Zar);}}Zeg(Zbr);((((T7*)((T7*)(ZIk))))->Z91)=(ZQ5(0));{T0*b1=ZIk;Zhe((T38*)(ZCj),b1);}ZR7((T7*)(ZIk));ZJ7((T7*)(ZIk));if(((((T7*)(ZIk))->Z91))==(ZQ5(0))){
R=a3;}else{Zti=Zcr;Z7r=((T6)(0));Z06=Z29(a2);Z8r=ZIk;ZL7(((T7*)Z8r));while(!((Z3)((Z06)>(((((T44*)a2))->Zt1))))){ZX6(((T7*)Zti),Z19(a2,Z06));
ZL7(((T7*)Zti));if(ZB7(((T7*)Z8r),Zti)){R=Z19(a2,Z06);Z06=((((T44*)a2))->Zt1);}else if(Zp7(((T7*)Zti),Z8r)){if((R)!=((void*)(Zo))){R=Zo;
Z7r=((T6)(1));}else{R=Z19(a2,Z06);}}Z06=(Z3)(((Z06))+(ZQ5(1)));}if((R)==((void*)(Zo))){Zeg(Zdr);Zeg(Z8r);if(Z7r){Zeg(Zja(16,"\" is ambiguous.\n"));
}else{Zeg(Zer);}}}}return R;}T0*ZMk(T12*C,T0*a1){T0*R=Zo;R=Zfr;if(ZB7((T7*)(Zff),((C)->ZL1))){ZX6(((T7*)R),Zgr);}else{ZX6(((T7*)R),Zhr);
}if(!(Zo6((T7*)(((C)->ZM1)),Z3k))){Zb7(((T7*)R),Zir);Zb7(((T7*)R),((C)->ZM1));}if((a1)!=((void*)(Zo))){Z26(((T7*)R),((T3)'\040'));Zb7(((T7*)R),a1);
}return R;}void Zua(T0*a1){if((Zjr(a1))==(ZQ5(0))){}}T2 Zjr(T0*a1){T2 R=0;T8 Zre=Zo;Zre=ZK7(((T7*)a1));R=Zkr(Zre);return R;}T0*Zfa(T0*a1){
T0*R=Zo;T8 Zre=Zo;T8 Zlr=Zo;Zre=ZK7(((T7*)a1));Zre=Zmr(Zre);if((Zre)!=(Zlr)){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZI7(n,Zre);R=((T0*)n);
}}return R;}T0*Znr(T97*C){T0*R=Zo;if((((*C).Z21))==((void*)(Zo))){(C->Z21)=(((void)((T94*)(Zor()))),Z4b(Zpr));}R=((*C).Z21);return R;
}T0*Zor(void){if(Zbb==0){Zbb=1;{{T94*n=((T94*)Zh(1));Zab=((T0*)n);Zcb(Zdb);Zcb(Zeb);Zcb(Zfb);Zcb(Zgb);Zcb(Zhb);Zcb(ZPa);Zcb(Zib);Zcb(ZKa);
Zcb(Zjb);Zcb(Zkb);Zcb(ZNa);Zcb(Zlb);Zcb(Zmb);Zcb(Znb);Zcb(Zob);Zcb(Zpb);Zcb(Zqb);Zcb(ZHa);Zcb(ZTa);Zcb(ZJa);Zcb(ZIa);Zcb(ZUa);Zcb(Zrb);
Zcb(Zsb);Zcb(Ztb);Zcb(ZGa);Zcb(Zub);Zcb(ZRa);Zcb(Zvb);Zcb(Zwb);Zcb(Zxb);Zcb(Zyb);Zcb(ZMa);Zcb(ZLa);Zcb(ZOa);Zcb(Zzb);Zcb(ZAb);Zcb(ZQa);
Zcb(ZBb);Zcb(ZCb);Zcb(ZDb);Zcb(ZEb);Zcb(ZFb);Zcb(ZGb);Zcb(ZHb);Zcb(ZIb);Zcb(ZJb);Zcb(ZKb);Zcb(ZLb);Zcb(ZMb);Zcb(ZNb);Zcb(ZOb);Zcb(ZPb);
Zcb(ZQb);Zcb(ZRb);Zcb(ZSb);Zcb(ZTb);Zcb(ZUb);Zcb(ZVb);Zcb(ZWb);Zcb(ZXb);Zcb(ZYb);Zcb(ZZb);Zcb(Z_b);Zcb(Z0c);Zcb(Z1c);Zcb(Z2c);Zcb(Z3c);
Zcb(Z4c);Zcb(Z5c);Zcb(Z6c);Zcb(Z7c);Zcb(Z8c);Zcb(Z9c);Zcb(Zac);Zcb(Zbc);Zcb(Zcc);Zcb(Zdc);Zcb(Zec);Zcb(Zfc);Zcb(Zgc);Zcb(Zhc);Zcb(Zic);
Zcb(Zjc);Zcb(Zkc);Zcb(Zlc);Zcb(Zmc);Zcb(Znc);Zcb(Zoc);Zcb(Zpc);Zcb(Zqc);Zcb(Zrc);Zcb(Zsc);Zcb(Ztc);Zcb(Zuc);Zcb(Zvc);Zcb(Zwc);Zcb(Zxc);
Zcb(Zyc);Zcb(Zzc);Zcb(ZAc);Zcb(ZBc);Zcb(ZCc);Zcb(ZDc);Zcb(ZEc);Zcb(ZFc);Zcb(ZGc);Zcb(ZHc);Zcb(ZIc);Zcb(ZJc);Zcb(ZKc);Zcb(ZLc);Zcb(ZMc);
Zcb(ZNc);Zcb(ZOc);Zcb(ZPc);Zcb(ZQc);Zcb(ZRc);Zcb(ZSc);Zcb(ZTc);Zcb(ZUc);Zcb(ZVc);Zcb(ZWc);Zcb(ZXc);Zcb(ZYc);Zcb(ZZc);Zcb(Z_c);Zcb(Z0d);
Zcb(Z1d);Zcb(Z2d);Zcb(Z3d);Zcb(Z4d);Zcb(Z5d);Zcb(Z6d);Zcb(Z7d);Zcb(Z8d);Zcb(Z9d);Zcb(Zad);Zcb(Zbd);Zcb(Zcd);Zcb(Zdd);Zcb(Zed);Zcb(Zfd);
Zcb(Zgd);Zcb(Zhd);Zcb(Zid);Zcb(Zjd);Zcb(Zkd);Zcb(Zld);Zcb(Zmd);Zcb(Znd);Zcb(Zod);Zcb(Zpd);Zcb(Zqd);Zcb(Zrd);Zcb(Zsd);Zcb(Ztd);Zcb(Zud);
Zcb(Zvd);Zcb(Zwd);Zcb(Zxd);Zcb(Zyd);Zcb(Zzd);Zcb(ZAd);Zcb(ZBd);Zcb(ZCd);Zcb(ZDd);Zcb(ZEd);Zcb(ZFd);Zcb(ZGd);Zcb(ZHd);Zcb(ZId);Zcb(ZJd);
Zcb(ZKd);Zcb(ZLd);Zcb(ZMd);Zcb(ZNd);Zcb(ZOd);Zcb(ZPd);Zcb(ZQd);Zcb(ZRd);Zcb(ZSd);Zcb(ZTd);Zcb(ZUd);Zcb(ZVd);Zcb(ZWd);Zcb(ZXd);Zcb(ZYd);
Zcb(ZZd);Zcb(Z_d);Zcb(Zfb);Zcb(Z0e);Zcb(ZSa);Zcb(Z1e);Zcb(Z2e);Zcb(Z3e);Zcb(Z4e);Zcb(Z5e);Zcb(Z6e);Zcb(Z7e);Zcb(Z8e);Zcb(Z9e);Zcb(Zae);
Zcb(Zbe);}}}return Zab;}void Zqr(T97*C,T78 a1){(C->Z11)=a1;((((T7*)((T7*)(Zpr))))->Z91)=(ZQ5(0));(C->Z21)=Zo;}T0*Zrr(T97*C){T0*R=Zo;if((((*C).Z21))==((void*)(Zo))){
(C->Z21)=(((void)((T94*)(Zor()))),Z4b(Zpr));}R=((*C).Z21);return R;}T6 Zcg(void){T6 R=0;R=((T6)(((((((T7*)ZOh))->Zs1))[ZQ5(0)])==(((T3)'A'))));
return R;}void Z4h(T0*a1){{int z1=(((((T7*)a1))->Zs1))[ZQ5(0)];switch(z1){case 46:case 47:case 126:((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'U'));
if((Z3)((((((T7*)a1))->Z91))>=(ZQ5(4)))){if(((((((T7*)a1))->Zs1))[(ZQ5(2))-(ZQ5(1))])==(((T3)'\057'))){if(((((((T7*)a1))->Zs1))[(ZQ5(4))-(ZQ5(1))])==(((T3)'\057'))){
((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'C'));}}}break;case 92:((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'W'));
break;case 58:((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'M'));break;case 91:((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'V'));
break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:
case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 97:case 98:case 99:case 100:case 101:case 102:case
103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case
118:case 119:case 120:case 121:case 122:if((Z3)((((((T7*)a1))->Z91))>=(ZQ5(2)))){{int z2=(((((T7*)a1))->Zs1))[(ZQ5(2))-(ZQ5(1))];switch(z2){
case 58:if((((((T7*)a1))->Z91))==(ZQ5(2))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'W'));}else if(Zv7(((T7*)a1),((T3)'\134'))){
((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'W'));}else if(Zv7(((T7*)a1),((T3)'\077'))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'A'));
}else if(Zv7(((T7*)a1),((T3)'\057'))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'C'));}break;case 65:case 66:case 67:case 68:
case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:
case 86:case 87:case 88:case 89:case 90:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:
case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:
if(Zv7(((T7*)a1),((T3)'\133'))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'V'));}else if(Zv7(((T7*)a1),((T3)'\072'))){if(Zv7(((T7*)a1),((T3)'\057'))){
((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'A'));}else if(Zv7(((T7*)a1),((T3)'\133'))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'V'));
}else{((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'A'));}}else if(Zv7(((T7*)a1),((T3)'\057'))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'U'));
}else if(Zv7(((T7*)a1),((T3)'\134'))){((((T7*)(ZOh))->Zs1))[((T2)(ZQ5(1)))-(ZQ5(1))]=(((T3)'U'));}break;}}}break;}}}void ZHi(T50*C,T0*a1){
T8 Zre=Zo;ZJi(C,a1);if((Zo!=((*C).Z41))){ZX6((T7*)(Z5h),a1);}else{Zjh(a1);if((Z3)(((((T7*)(Z5h))->Z91))>(ZQ5(0)))){Zre=ZK7((T7*)(Z5h));
(C->Z41)=Z84(Zre);(C->Z51)=((*C).Z41);if(ZE5(((*C).Z41))){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));
}}}void Z3h(T50*C){T8 Z8n=Zo;Z8n=Zsr;if((Zo!=Z8n)){ZI7((T7*)(Z5h),Z8n);(C->Z41)=Z84(Z8n);(C->Z51)=((*C).Z41);if(ZE5(((*C).Z41))){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));
}}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}}void Z6h(T50*C){T8 Zlr=Zo;if(Zg4(((*C).Z41))){(C->Z41)=Zlr;(C->Z51)=Zlr;}}void Zgh(T0*a1,T0*a2){
ZX6((T7*)(Z5h),a1);if((T6)((Z8g())||((T6)(Z9g())))){if(Zo6(((T7*)Ztr),a2)){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else if(Zo6(((T7*)Zur),a2)){
((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else{ZA7((T7*)(Z5h),((T3)'\057'));if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\057'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
}Zb7((T7*)(Z5h),a2);ZA7((T7*)(Z5h),((T3)'\057'));}}else if(Zag()){if(Zo6(((T7*)Zvr),a2)){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else if(Zo6(((T7*)Zwr),a2)){
((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else{ZA7((T7*)(Z5h),((T3)'\134'));if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\134'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
}Zb7((T7*)(Z5h),a2);ZA7((T7*)(Z5h),((T3)'\134'));}}else if(Zcg()){{int z1=Z07((T7*)(Z5h));switch(z1){case 47:if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\057'))){
Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}break;case 58:break;default:;if(((((((T7*)a2))->Zs1))[ZQ5(0)])!=(((T3)'\057'))){ZE7((T7*)(Z5h),((T3)'\057'));
}}}Zb7((T7*)(Z5h),a2);ZA7((T7*)(Z5h),((T3)'\057'));}else if(Zbg()){ZA7((T7*)(Z5h),((T3)'\072'));if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\072'))){
Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}Zb7((T7*)(Z5h),a2);ZA7((T7*)(Z5h),((T3)'\072'));}else if(Zdg()){if(((((T7*)(Z5h))->Z91))==(ZQ5(1))){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));
}else if((Z07((T7*)(Z5h)))==(((T3)'\135'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));if((Z07((T7*)(Z5h)))==(((T3)'\133'))){Zb7((T7*)(Z5h),a2);Z26((T7*)(Z5h),((T3)'\135'));
}else{Z26((T7*)(Z5h),((T3)'\056'));Zb7((T7*)(Z5h),a2);Z26((T7*)(Z5h),((T3)'\135'));}}else if((Z07((T7*)(Z5h)))==(((T3)'\072'))){Z26((T7*)(Z5h),((T3)'\133'));
Zb7((T7*)(Z5h),a2);Z26((T7*)(Z5h),((T3)'\135'));}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}}else if(Z7g()){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));
}else{Z4h(a1);if(Z7g()){Zgh(a1,a2);}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}}}T6 Z7g(void){T6 R=0;R=((T6)(((((((T7*)ZOh))->Zs1))[ZQ5(0)])!=(((T3)'\077'))));
return R;}T6 ZNi(void){T6 R=0;T50 Zxr={Zo,Zo};{int z1=(((((T7*)ZOh))->Zs1))[ZQ5(0)];switch(z1){case 63:Z3h(&Zxr);if((Zo!=((Zxr).Z41))){
if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){Z4h(Z5h);}Z6h(&Zxr);if(((((((T7*)ZOh))->Zs1))[ZQ5(0)])!=(((T3)'\077'))){R=((T6)(ZNi()));}}break;
case 86:case 87:break;default:;R=((T6)(1));}}return R;}T6 Zag(void){T6 R=0;R=((T6)(((((((T7*)ZOh))->Zs1))[ZQ5(0)])==(((T3)'W'))));return
R;}T6 Z8g(void){T6 R=0;R=((T6)(((((((T7*)ZOh))->Zs1))[ZQ5(0)])==(((T3)'U'))));return R;}T0*Z5h=Zo;T6 Zbg(void){T6 R=0;R=((T6)(((((((T7*)ZOh))->Zs1))[ZQ5(0)])==(((T3)'M'))));
return R;}void Zwo(T50*C,T0*a1){T8 Zre=Zo;Zre=ZK7(((T7*)a1));if(Zi4(Zre)){Z3h(C);if((Zo!=((*C).Z41))){Z6h(C);}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));
}}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}}void Zjh(T0*a1){ZX6((T7*)(Z5h),a1);if(Z8g()){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));while(!((T6)((((((T7*)(Z5h))->Z91))==(ZQ5(0)))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\057')))))))
{Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){ZA7((T7*)(Z5h),((T3)'\057'));}}else if(Zag()){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
while(!((T6)((((((T7*)(Z5h))->Z91))==(ZQ5(0)))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\134'))))))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){
ZA7((T7*)(Z5h),((T3)'\134'));}}else if(Z9g()){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));while(!((T6)(((T6)((((((T7*)(Z5h))->Z91))==(ZQ5(0)))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\057'))))))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\072')))))))
{Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}if(((((T7*)(Z5h))->Z91))==(ZQ5(0))){}else if((((((T7*)(Z5h))->Zs1))[ZQ5(0)])==(((T3)'\057'))){if(((((T7*)(Z5h))->Z91))==(ZQ5(2))){
if((((((T7*)(Z5h))->Zs1))[(ZQ5(2))-(ZQ5(1))])==(((T3)'\057'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}}}if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){
ZA7((T7*)(Z5h),((T3)'\057'));}}else if(Zcg()){if((Z07((T7*)(Z5h)))==(((T3)'\072'))){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else{Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
while(!((T6)(((T6)((((((T7*)(Z5h))->Z91))==(ZQ5(0)))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\057'))))))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\072')))))))
{Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}}if((T6)((!(((((T7*)(Z5h))->Z91))==(ZQ5(0))))&&((T6)((T6)(((Z07((T7*)(Z5h)))!=(((T3)'\057')))&&((T6)((Z07((T7*)(Z5h)))!=(((T3)'\072'))))))))){
Z26((T7*)(Z5h),((T3)'\057'));}}else if(Zbg()){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));while(!((T6)((((((T7*)(Z5h))->Z91))==(ZQ5(0)))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\072')))))))
{Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}if(!(((((T7*)(Z5h))->Z91))==(ZQ5(0)))){ZA7((T7*)(Z5h),((T3)'\072'));}}else if(Zdg()){if((Z07((T7*)(Z5h)))==(((T3)'\135'))){
Zu7((T7*)(Z5h),(T2)(ZQ5(1)));while(!((T6)(((T6)((((((T7*)(Z5h))->Z91))==(ZQ5(0)))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\056'))))))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\133')))))))
{Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}if((Z3)(((((T7*)(Z5h))->Z91))>(ZQ5(0)))){{int z1=Z07((T7*)(Z5h));switch(z1){case 46:Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
Z26((T7*)(Z5h),((T3)'\135'));break;default:;if(((((T7*)(Z5h))->Z91))==((Z3)(((((((T7*)a1))->Z91)))-(ZQ5(1))))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
}else{Z26((T7*)(Z5h),((T3)'\135'));}}}}}else if((Z07((T7*)(Z5h)))==(((T3)'\072'))){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else{Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
while(!((T6)((((((T7*)(Z5h))->Z91))==(ZQ5(0)))||((T6)((Z07((T7*)(Z5h)))==(((T3)'\135'))))))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}if(((((T7*)(Z5h))->Z91))==(ZQ5(0))){
((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}}}else if(Z7g()){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else{Z4h(a1);if(Z7g()){Zjh(a1);}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));
}}}void ZKi(T50*C){T8 Z9i=Zo;(C->Z51)=Zb4(((*C).Z41));if((Zo!=((*C).Z51))){Z9i=Zd4(((*C).Z51));ZI7((T7*)(Z5h),Z9i);}}void ZJi(T50*C,T0*a1){
T8 Zyr=Zo;Zyr=ZK7(((T7*)a1));(C->Z41)=Z84(Zyr);(C->Z51)=((*C).Z41);((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}T6 ZEp(T0*a1){T6 R=0;T8 Zre=Zo;
Zre=ZK7(((T7*)a1));R=((T6)(Zk4(Zre)));return R;}void ZXl(T0*a1,T0*a2){ZX6((T7*)(Z5h),a1);if((T6)((Z8g())||((T6)(Z9g())))){ZA7((T7*)(Z5h),((T3)'\057'));
if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\057'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}Zb7((T7*)(Z5h),a2);}else if(Zag()){ZA7((T7*)(Z5h),((T3)'\134'));
if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\134'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}Zb7((T7*)(Z5h),a2);}else if(Zcg()){{int z1=Z07((T7*)(Z5h));
switch(z1){case 58:break;case 47:if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\057'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}break;default:;if(((((((T7*)a2))->Zs1))[ZQ5(0)])!=(((T3)'\057'))){
Z26((T7*)(Z5h),((T3)'\057'));}}}Zb7((T7*)(Z5h),a2);}else if(Zbg()){ZA7((T7*)(Z5h),((T3)'\072'));if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\072'))){
Zu7((T7*)(Z5h),(T2)(ZQ5(1)));}Zb7((T7*)(Z5h),a2);}else if(Zdg()){{int z1=Z07((T7*)(Z5h));switch(z1){case 93:break;case 46:Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
Z26((T7*)(Z5h),((T3)'\135'));break;default:;Z26((T7*)(Z5h),((T3)'\135'));}}if(((((((T7*)a2))->Zs1))[ZQ5(0)])==(((T3)'\135'))){Zu7((T7*)(Z5h),(T2)(ZQ5(1)));
}Zb7((T7*)(Z5h),a2);}else if(Z7g()){((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));}else{Z4h(a1);if(Z7g()){ZXl(a1,a2);}else{((((T7*)((T7*)(Z5h))))->Z91)=(ZQ5(0));
}}}T6 Zdg(void){T6 R=0;R=((T6)(((((((T7*)ZOh))->Zs1))[ZQ5(0)])==(((T3)'V'))));return R;}T6 Z9g(void){T6 R=0;R=((T6)(((((((T7*)ZOh))->Zs1))[ZQ5(0)])==(((T3)'C'))));
return R;}T6 Znk(T0*a1){T6 R=0;if((ZGa)==((void*)(a1))){R=((T6)(1));}else if((ZDb)==((void*)(a1))){R=((T6)(1));}else if((ZAb)==((void*)(a1))){
R=((T6)(1));}else if((Zxb)==((void*)(a1))){R=((T6)(1));}else if((Zob)==((void*)(a1))){R=((T6)(1));}else if((Zwb)==((void*)(a1))){R=((T6)(1));
}return R;}T6 Zzr(void){T6 R=0;T6 Zie=0;if((T6)((ZAr((T37*)(ZBr)))||((T6)(!(ZI5(ZCr((T37*)(ZBr)))))))){((((T37*)((T37*)(ZBr))))->Z63)=(ZDr);
}else{R=((T6)(1));ZEr((T37*)(ZBr));while(!(Zie)){if(ZAr((T37*)(ZBr))){Zie=((T6)(1));}else if(ZI5(ZCr((T37*)(ZBr)))){ZEr((T37*)(ZBr));
}else{Zie=((T6)(1));}}ZFr((T37*)(ZBr));}return R;}T0*ZBr=Zo;T6 ZGr(int C){T6 R=0;R=((T6)((T6)((ZHr(C))&&((T6)(ZIr(C))))));return R;}T6
ZHr(int C){T6 R=0;R=((T6)((T6)((ZJr(C))&&((T6)(ZKr(C))))));return R;}T6 ZJr(int C){T6 R=0;R=((T6)(ZLr(C)));if(!(ZAr((T37*)(ZBr)))){if((ZCr((T37*)(ZBr)))==(((T3)'\041'))){
ZEr((T37*)(ZBr));ZFr((T37*)(ZBr));}}return R;}T6 ZLr(int C){T6 R=0;if(ZAr((T37*)(ZBr))){((((T37*)((T37*)(ZBr))))->Z63)=(ZDr);}else{{int
z1=ZCr((T37*)(ZBr));switch(z1){case 43:case 45:ZEr((T37*)(ZBr));ZFr((T37*)(ZBr));R=((T6)(ZLr(C)));break;case 40:ZEr((T37*)(ZBr));ZFr((T37*)(ZBr));
R=((T6)(ZGr(C)));if(R){if((T6)((ZAr((T37*)(ZBr)))||((T6)((ZCr((T37*)(ZBr)))!=(((T3)'\051')))))){R=((T6)(0));((((T37*)((T37*)(ZBr))))->Z63)=(ZDr);
}else{ZEr((T37*)(ZBr));ZFr((T37*)(ZBr));}}break;default:;R=((T6)(Zzr()));}}}return R;}T6 ZQ7(int C,T0*a1){T6 R=0;ZMr((T37*)(ZBr),a1);
ZFr((T37*)(ZBr));R=((T6)(ZGr(C)));if(R){if(((Z3)((((((T37*)(ZBr))->Z73)))+(ZQ5(1))))!=((Z3)(((((((T7*)a1))->Z91)))+(ZQ5(1))))){R=((T6)(0));
((((T37*)((T37*)(ZBr))))->Z63)=(ZNr);}}return R;}T6 ZIr(int C){T6 R=0;if(ZAr((T37*)(ZBr))){R=((T6)(1));}else{{int z1=ZCr((T37*)(ZBr));
switch(z1){case 43:case 45:ZEr((T37*)(ZBr));ZFr((T37*)(ZBr));R=((T6)((T6)((ZHr(C))&&((T6)(ZIr(C))))));break;default:;R=((T6)(1));}}}return
R;}T6 ZKr(int C){T6 R=0;if(ZAr((T37*)(ZBr))){R=((T6)(1));}else{{int z1=ZCr((T37*)(ZBr));switch(z1){case 42:case 47:ZEr((T37*)(ZBr));ZFr((T37*)(ZBr));
R=((T6)((T6)((ZJr(C))&&((T6)(ZKr(C))))));break;default:;R=((T6)(1));}}}return R;}void ZOr(T53*C){while(!(!(ZPr(C,((T3)'\n'))))){ZQr(C);
}}T6 ZXh(T53*C,T0*a1,T0*a2){T6 R=0;T0*ZRr=Zo;if((((C)->ZG2))!=((void*)(Zo))){ZRr=Zy9((T64*)(((C)->ZG2)),a1);R=((T6)((T6)(((ZRr)!=((void*)(Zo)))&&((T6)(Zt8(((T65*)ZRr),a2))))));
}return R;}void ZSr(T78 a1,T0*a2){Ztk(a1);{T0*b1=a2;Zb7((T7*)(ZGe),b1);}ZIe((T77*)(ZJe));}void ZTr(T78 a1,T0*a2){Ztk(a1);{T0*b1=a2;Zb7((T7*)(ZGe),b1);
}Z_h((T77*)(ZJe));}T0*ZUr=Zo;T0*ZVr=Zo;T6 ZWr(T53*C){T6 R=0;if((T6)(((T6)((ZXr(C))&&((T6)(ZPr(C,((T3)'\133'))))))&&((T6)(ZXr(C))))){R=((T6)((T6)(((T6)(((T6)((ZYr(C))&&((T6)(ZXr(C)))))&&((T6)(ZPr(C,((T3)'\135'))))))&&((T6)(ZXr(C))))));
if(R){ZOr(C);(C->ZC2)=Zrr(&(((C)->ZA2)));if((((C)->ZG2))==((void*)(Zo))){{T64*n=((T64*)Zh(sizeof(*n)));*n=M64;{T64*C1=n;Zx9(C1,Zb8(193));
}(C->ZG2)=((T0*)n);}}if(!(Zv9((T64*)(((C)->ZG2)),((C)->ZC2)))){Zw9((T64*)(((C)->ZG2)),((T0*)Z98()),((C)->ZC2));}ZZr(C);}}return R;}T0*Z_r=Zo;
int Z0s=0;T0*Z1s(void){if(Z0s==0){Z0s=1;{{ZN*n=((ZN*)Zh(sizeof(*n)));*n=Zs2;Z_r=((T0*)n);ZQi(n,(T2)(ZQ5(0)));}}}return Z_r;}void ZZr(T53*C){
T6 Zie=0;ZOr(C);while(!(Zie)){Zie=((T6)(!(Z2s(C))));}}void Z3s(T53*C,T0*a1){if((((T55*)(Zhg))->Zp1)){(C->ZB2)=((T6)(1));}else{Z4s(C,a1);
}}T0*Z5s(void){if(ZCg==0){ZCg=1;{{T76*n=((T76*)Zh(sizeof(*n)));*n=M76;ZBg=((T0*)n);ZEg(n);}}}return ZBg;}void Z6s(T53*C){T6 Zie=0;ZOr(C);
while(!(Zie)){Zie=((T6)(!(ZWr(C))));}}T6 ZPr(T53*C,T3 a1){T6 R=0;if((a1)==(((C)->_cc))){(C->Zy2)=((C)->Zu2);(C->Zz2)=((C)->Zt2);R=((T6)(1));
Z7s(C);}return R;}T6 Z8s(T53*C){T6 R=0;T2 Zj7=0;T2 Z9s=0;T2 ZY6=0;{T78 ZL6;Zqr(&(((C)->ZA2)),(*(ZL6=Zas(((C)->Zu2),((C)->Zt2)),&ZL6)));
}Zj7=ZQ5(0);while(!((T6)(((((C)->_cc))==(((T3)'\n')))||((T6)((((C)->_cc))==(((T3)'\000'))))))){R=((T6)(1));{int z1=Zj7;switch(z1){case
0:{int z2=((C)->_cc);switch(z2){case 9:case 32:Z26((T7*)(ZVr),((C)->_cc));Zj7=ZQ5(1);break;case 45:Z9s=((C)->Zu2);ZY6=((C)->Zt2);Zj7=ZQ5(2);
break;default:;{T3 b1=((C)->_cc);Z26((T7*)(Zpr),b1);}}}break;case 1:{int z2=((C)->_cc);switch(z2){case 9:case 32:Z26((T7*)(ZVr),((C)->_cc));
break;case 45:Z9s=((C)->Zu2);ZY6=((C)->Zt2);Zj7=ZQ5(2);break;default:;{T0*b1=ZVr;Zb7((T7*)(Zpr),b1);}((((T7*)((T7*)(ZVr))))->Z91)=(ZQ5(0));
{T3 b1=((C)->_cc);Z26((T7*)(Zpr),b1);}Zj7=ZQ5(0);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 45:Zj7=ZQ5(3);break;case 9:case 32:
{T0*b1=ZVr;Zb7((T7*)(Zpr),b1);}{T3 b1=((T3)'\055');Z26((T7*)(Zpr),b1);}((((T7*)((T7*)(ZVr))))->Z91)=(ZQ5(0));Z26((T7*)(ZVr),((C)->_cc));
Zj7=ZQ5(1);break;default:;{T0*b1=ZVr;Zb7((T7*)(Zpr),b1);}{T3 b1=((T3)'\055');Z26((T7*)(Zpr),b1);}{T3 b1=((C)->_cc);Z26((T7*)(Zpr),b1);
}((((T7*)((T7*)(ZVr))))->Z91)=(ZQ5(0));Zj7=ZQ5(0);}}break;default:;}}Z7s(C);}return R;}T6 Zbs(T53*C,T0*a1){T6 R=0;T2 ZY6=0;T2 Z06=0;T2
Zt7=0;T6 Zcs=0;Z06=((C)->Zt2);ZY6=((((T7*)a1))->Z91);if((Z3)(((Z3)((((Z3)((((((T7*)(((C)->Zv2)))->Z91)))-(Z06))))+(ZQ5(1))))>=(ZY6))){
(C->Zy2)=((C)->Zu2);(C->Zz2)=Z06;Zt7=ZQ5(1);while(!((Z3)((ZY6)<=(ZQ5(0))))){if((((((T7*)(((C)->Zv2)))->Zs1))[(Z06)-(ZQ5(1))])==((((((T7*)a1))->Zs1))[(Zt7)-(ZQ5(1))])){
Z06=(Z3)(((Z06))+(ZQ5(1)));Zt7=(Z3)(((Zt7))+(ZQ5(1)));ZY6=(Z3)(((ZY6))-(ZQ5(1)));}else if(ZS5(((((T7*)(((C)->Zv2)))->Zs1))[(Z06)-(ZQ5(1))],(((((T7*)a1))->Zs1))[(Zt7)-(ZQ5(1))])){
Z06=(Z3)(((Z06))+(ZQ5(1)));Zt7=(Z3)(((Zt7))+(ZQ5(1)));ZY6=(Z3)(((ZY6))-(ZQ5(1)));Zcs=((T6)(1));}else{ZY6=ZQ5(-1);}}}if((ZY6)==(ZQ5(0))){
if((Z3)((Z06)>((((T7*)(((C)->Zv2)))->Z91)))){R=((T6)(1));(C->_cc)=((T3)'\n');(C->Zt2)=Z06;ZQr(C);}else{{int z1=((((T7*)(((C)->Zv2)))->Zs1))[(Z06)-(ZQ5(1))];
switch(z1){case 9:case 32:case 45:R=((T6)(1));(C->_cc)=((((T7*)(((C)->Zv2)))->Zs1))[(Z06)-(ZQ5(1))];(C->Zt2)=Z06;ZQr(C);break;case 48:
case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:
case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:
case 90:case 95:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case
110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:break;default:;R=((T6)(1));
(C->_cc)=((((T7*)(((C)->Zv2)))->Zs1))[(Z06)-(ZQ5(1))];(C->Zt2)=Z06;}}}}if(ZF5((T6)(ZF5((T6)(R),(T6)(Zcs))),(T6)((a1)!=((void*)(Zds))))){
{T78 ZL6;Ztk((*(ZL6=Zas(((C)->Zy2),((C)->Zz2)),&ZL6)));}{T0*b1=Zes;Zb7((T7*)(ZGe),b1);}{T0*b1=a1;Zb7((T7*)(ZGe),b1);}{T0*b1=Zja(1,"\'");
Zb7((T7*)(ZGe),b1);}ZIe((T77*)(ZJe));}return R;}T78 Zfs(T53*C){T78 R={Zo,Zo,0};{T78 ZL6;R=(*(ZL6=Zas(((C)->Zu2),((C)->Zt2)),&ZL6));}return
R;}T0*Zgs(void){if(Z9b==0){Z9b=1;{{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;Z8b=((T0*)n);}}}return Z8b;}T6 ZYr(T53*C){T6 R=0;T6 Zie=0;if(ZR5(((C)->_cc))){
{T78 ZL6;Zqr(&(((C)->ZA2)),(*(ZL6=Zas(((C)->Zu2),((C)->Zt2)),&ZL6)));}{T3 b1=((C)->_cc);Z26((T7*)(Zpr),b1);}while(!(Zie)){Z7s(C);{int
z1=((C)->_cc);switch(z1){case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case
109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:{T3 b1=((C)->_cc);
Z26((T7*)(Zpr),b1);}break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case
78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:{T3 b1=((C)->_cc);Z26((T7*)(Zpr),b1);
}break;case 46:case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 95:{T3 b1=((C)->_cc);Z26((T7*)(Zpr),b1);
}break;default:;Zie=((T6)(1));}}}R=((T6)(1));}return R;}T6 Zhs(T53*C){T6 R=0;T2 Zj7=0;T2 Z9s=0;T2 ZY6=0;T6 Zis=0;T6 Zjs=0;T6 Zie=0;T2
Zks=0;T2 Zls=0;T2 Zms=0;T0*Zns=Zo;T0*Zos=Zo;T2 Zps=0;T2 Zqs=0;Z9s=((C)->Zu2);ZY6=((C)->Zt2);if(Zbs(C,Zrs)){Zis=((T6)(1));}if((((C)->_cc))==(((T3)'U'))){
Zjs=((T6)(1));Z7s(C);}if((((C)->_cc))==(((T3)'\042'))){R=((T6)(1));if((T6)(((((T88*)(ZDa))->Zj2))||((T6)((((T88*)(ZDa))->Zk2))))){{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Z_6(n,(T2)(ZQ5(32)));Zns=((T0*)n);}}((((T7*)((T7*)(ZVr))))->Z91)=(ZQ5(0));while(!((Z3)((Zj7)>(ZQ5(9))))){Z7s(C);{int z1=Zj7;switch(z1){
case 0:{int z2=((C)->_cc);switch(z2){case 10:while(!((Zos)!=((void*)(Zo)))){if(((((T7*)(ZVr))->Z91))==(ZQ5(0))){Z3s(C,Zss);}else{{int
z3=Z07((T7*)(ZVr));switch(z3){case 9:case 32:Zu7((T7*)(ZVr),(T2)(ZQ5(1)));{T53*C1=C;T0*b1=Zts;{T78 ZL6;ZSr((*(ZL6=Zfs(C1),&ZL6)),b1);
}}break;case 91:case 123:Zos=Zus;((((T7*)(((T7*)Zos))))->Z91)=(ZQ5(0));if((Z07((T7*)(ZVr)))==(((T3)'\173'))){Z26(((T7*)Zos),((T3)'\175'));
Zps=ZQ5(1);Zj7=ZQ5(8);}else{Z26(((T7*)Zos),((T3)'\135'));Zj7=ZQ5(7);}Zb7(((T7*)Zos),ZVr);Zqs=ZQ5(1);Zu7(((T7*)Zos),(T2)(ZQ5(1)));Z26(((T7*)Zos),((T3)'\042'));
((((T7*)((T7*)(ZVr))))->Z91)=(ZQ5(0));break;default:;Z3s(C,Zss);}}}}break;case 34:Zj7=ZQ5(11);break;case 37:Zj7=ZQ5(1);break;default:;
Z26((T7*)(ZVr),((C)->_cc));}}break;case 1:Zj7=ZQ5(0);{int z2=((C)->_cc);switch(z2){case 10:Zj7=ZQ5(3);break;case 65:Z26((T7*)(ZVr),((T3)'\100'));
break;case 66:Z26((T7*)(ZVr),((T3)'\010'));break;case 67:Z26((T7*)(ZVr),((T3)'\136'));break;case 68:Z26((T7*)(ZVr),((T3)'\044'));break;
case 70:Z26((T7*)(ZVr),((T3)'\014'));break;case 72:Z26((T7*)(ZVr),((T3)'\134'));break;case 76:Z26((T7*)(ZVr),((T3)'\176'));break;case
78:Z26((T7*)(ZVr),((T3)'\n'));break;case 81:Z26((T7*)(ZVr),((T3)'\140'));break;case 82:Z26((T7*)(ZVr),((T3)'\015'));break;case 83:Z26((T7*)(ZVr),((T3)'\043'));
break;case 84:Z26((T7*)(ZVr),((T3)'\011'));break;case 85:Z26((T7*)(ZVr),((T3)'\000'));break;case 86:Z26((T7*)(ZVr),((T3)'\174'));break;
case 37:Z26((T7*)(ZVr),((T3)'\045'));break;case 39:Z26((T7*)(ZVr),((T3)'\047'));break;case 34:Z26((T7*)(ZVr),((T3)'\042'));break;case
40:Z26((T7*)(ZVr),((T3)'\133'));break;case 41:Z26((T7*)(ZVr),((T3)'\135'));break;case 60:Z26((T7*)(ZVr),((T3)'\173'));break;case 62:Z26((T7*)(ZVr),((T3)'\175'));
break;case 47:Zks=ZQ5(0);Zms=ZQ5(0);Zj7=ZQ5(4);break;case 9:case 32:Zj7=ZQ5(2);break;default:;Z3s(C,Zvs);Zj7=ZQ5(0);}}break;case 2:{int
z2=((C)->_cc);switch(z2){case 10:Zj7=ZQ5(3);break;case 9:case 32:{T53*C1=C;T0*b1=Zts;{T78 ZL6;ZSr((*(ZL6=Zfs(C1),&ZL6)),b1);}}break;default:;
Z3s(C,Zja(60,"In extended form of manifest string.Bad character after \'%\'."));}}break;case 3:{int z2=((C)->_cc);switch(z2){case 9:case
32:break;case 37:Zj7=ZQ5(0);break;case 10:Z3s(C,Zss);break;default:;Z3s(C,Zja(62,"In extended form of manifest string. Bad character before \'%\'."));
}}break;case 4:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zms=(Z3)(((Zms))+(ZQ5(1)));
Zks=(Z3)((((Z3)(((Zks))*(ZQ5(10)))))+((T2)(ZT5(((C)->_cc)))));break;case 120:if(ZF5((T6)((Zms)==(ZQ5(1))),(T6)((Zks)==(ZQ5(0))))){Zms=ZQ5(0);
Zj7=ZQ5(5);}else{Z3s(C,Zws);}break;case 85:if((Zms)==(ZQ5(0))){Z7s(C);if((((C)->_cc))==(((T3)'x'))){Zj7=ZQ5(6);Zls=ZQ5(0);Zms=ZQ5(0);
}else{Z3s(C,Zws);}}else{Z3s(C,Zws);}break;case 47:Z26((T7*)(ZVr),((T3)(Zks)));Zj7=ZQ5(0);if((Zms)==(ZQ5(0))){{T53*C1=C;T0*b1=Zxs;{T78
ZL6;ZTr((*(ZL6=Zfs(C1),&ZL6)),b1);}}}else if((Z3)((Zks)>((T2)(Zys)))){Zks=ZQ5(0);{T53*C1=C;T0*b1=Zzs;{T78 ZL6;ZTr((*(ZL6=Zfs(C1),&ZL6)),b1);
}}}break;default:;Z3s(C,Zws);}}break;case 5:if(ZK5(((C)->_cc))){Zks=(Z3)((((Z3)(((Zks))*(ZQ5(16)))))+((T2)(ZX5(((C)->_cc)))));Zms=(Z3)(((Zms))+(ZQ5(1)));
if(Z56(Zms)){Z26((T7*)(ZVr),((T3)(Zks)));Zks=ZQ5(0);}}else if((((C)->_cc))==(((T3)'\057'))){Zj7=ZQ5(0);if((Zms)==(ZQ5(0))){{T53*C1=C;
T0*b1=ZAs;{T78 ZL6;ZTr((*(ZL6=Zfs(C1),&ZL6)),b1);}}}else if(Z96(Zms)){{T53*C1=C;T0*b1=Zja(85,"You must use an even number of hexadecimal digits to denote a sequence of CHARACTERs.");
{T78 ZL6;ZTr((*(ZL6=Zfs(C1),&ZL6)),b1);}}}}else{Z3s(C,ZAs);}break;case 6:if(ZK5(((C)->_cc))){Zls=(Z3)((((Z3)(((Zls))*(ZQ5(16)))))+((T2)(ZX5(((C)->_cc)))));
Zms=(Z3)(((Zms))+(ZQ5(1)));}else if((((C)->_cc))==(((T3)'\057'))){Zj7=ZQ5(0);if((Zms)==(ZQ5(0))){{T53*C1=C;T0*b1=ZBs;{T78 ZL6;ZTr((*(ZL6=Zfs(C1),&ZL6)),b1);
}}}else if((Z3)((Zms)>(ZQ5(8)))){{T53*C1=C;T0*b1=Zja(57,"Too long hexadecimal sequence for a single unicode value.");{T78 ZL6;ZTr((*(ZL6=Zfs(C1),&ZL6)),b1);
}}}else{ZVi((ZN*)(Z1s()));if((((void)((ZN*)(Z1s()))),ZRi(Zls))){ZTi((ZN*)(Z1s()),Zls);ZSi((ZN*)(Z1s()),ZVr);}else{{T53*C1=C;T0*b1=Zja(109,"Invalid unicode notation (see also http://www.unicode.org as well as feature \173""UNICODE_STRING\175"".valid_unicode).");
{T78 ZL6;ZTr((*(ZL6=Zfs(C1),&ZL6)),b1);}}}}}else{Z3s(C,ZBs);}break;case 7:{int z2=((C)->_cc);switch(z2){case 9:case 32:Zqs=(Z3)(((Zqs))+(ZQ5(1)));
break;case 10:Z26((T7*)(ZVr),((T3)'\n'));Zqs=ZQ5(1);break;case 0:{T78 ZL6;Ztk((*(ZL6=Zas(Z9s,ZY6),&ZL6)));}Z3s(C,ZCs);break;default:;
Z26((T7*)(ZVr),((C)->_cc));if((Zps)==(ZQ5(0))){Zps=Zqs;}Zj7=ZQ5(8);}}break;case 8:Zqs=(Z3)(((Zqs))+(ZQ5(1)));{int z2=((C)->_cc);switch(z2){
case 9:case 32:if((Z3)((Zqs)>=(Zps))){Z26((T7*)(ZVr),((C)->_cc));}break;case 10:Z26((T7*)(ZVr),((C)->_cc));Zqs=ZQ5(0);break;case 0:{T78
ZL6;Ztk((*(ZL6=Zas(Z9s,ZY6),&ZL6)));}Z3s(C,ZCs);break;case 34:Z26((T7*)(ZVr),((C)->_cc));if(Zh7((T7*)(ZVr),Zos)){Zj7=ZQ5(10);}break;default:;
if((Z3)((Zqs)<(Zps))){if((((C)->_cc))==((((((T7*)Zos))->Zs1))[ZQ5(0)])){Z26((T7*)(ZVr),((C)->_cc));Zj7=ZQ5(9);}else{{T78 ZL6;Ztk((*(ZL6=Zas(Z9s,ZY6),&ZL6)));
}Z3s(C,ZCs);}}else{Z26((T7*)(ZVr),((C)->_cc));}}}break;default:;{int z2=((C)->_cc);switch(z2){case 0:{T78 ZL6;Ztk((*(ZL6=Zas(Z9s,ZY6),&ZL6)));
}Z3s(C,ZCs);break;case 34:Z26((T7*)(ZVr),((C)->_cc));if(Zh7((T7*)(ZVr),Zos)){Zj7=ZQ5(10);}break;default:;Z26((T7*)(ZVr),((C)->_cc));}
}}}}if((Zj7)==(ZQ5(10))){{T7*C1=(T7*)(ZVr);T0*b1=Zos;Zu7(C1,((((T7*)b1))->Z91));}while(!(Zie)){if(((((T7*)(ZVr))->Z91))==(ZQ5(0))){Zie=((T6)(1));
}else{Zie=((T6)((Z07((T7*)(ZVr)))==(((T3)'\n'))));Zu7((T7*)(ZVr),(T2)(ZQ5(1)));}}}{T78 ZL6;{T98*n=((T98*)Zh(sizeof(*n)));*n=M98;Zyj(n,(*(ZL6=Zas(Z9s,ZY6),&ZL6)),(T6)(Zis),(T6)(Zjs),ZVr);
(C->ZE2)=((T0*)n);}}Z7s(C);ZQr(C);}return R;}void ZWh(T53*C){(C->ZC2)=Zo;(C->ZD2)=Zo;(C->Zu2)=ZQ5(1);(C->Zt2)=ZQ5(1);(C->Zv2)=(((((T49*)((((T76*)(Z5s()))->Zn2))))->Zs1))[((C)->Zu2)];
(C->Zm1)=(((T76*)(Z5s()))->Z_1);if(((((T7*)(((C)->Zv2)))->Z91))==(ZQ5(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->Zv2)))->Zs1))[ZQ5(0)];
}ZQr(C);if((((C)->_cc))!=(((T3)'\133'))){ZZr(C);}Z6s(C);ZOr(C);if((((C)->_cc))!=(((T3)'\000'))){{T78 ZL6;Ztk((*(ZL6=Zas(((C)->Zu2),((C)->Zt2)),&ZL6)));
}Z3s(C,Zja(28,"Unexpected text continuation"));}else if((T6)(((((C)->ZF2))==((void*)(Zo)))&&((T6)((((C)->ZG2))==((void*)(Zo)))))){{T78
ZL6;Ztk((*(ZL6=Zas(((C)->Zu2),((C)->Zt2)),&ZL6)));}Z3s(C,Zja(18,"Invalid empty file"));}ZAi((T76*)(Z5s()));}T6 Zcj(T53*C,T0*a1){T6 R=0;
R=((T6)((T6)(((((C)->ZF2))!=((void*)(Zo)))&&((T6)(Zt8((T65*)(((C)->ZF2)),a1))))));return R;}void ZQr(T53*C){T78 ZDs={Zo,Zo,0};T6 Zie=0;
while(!(Zie)){{int z1=((C)->_cc);switch(z1){case 9:case 10:case 32:Z7s(C);break;case 45:Z7s(C);if((((C)->_cc))==(((T3)'\055'))){if(((C)->Zx2)){
if((((C)->Zu2))==((((T76*)(Z5s()))->Z91))){(C->_cc)=((T3)'\000');Zie=((T6)(1));}else{(C->Zu2)=(Z3)(((((C)->Zu2)))+(ZQ5(1)));(C->Zt2)=ZQ5(1);
(C->Zv2)=(((((T49*)((((T76*)(Z5s()))->Zn2))))->Zs1))[((C)->Zu2)];if(((((T7*)(((C)->Zv2)))->Z91))==(ZQ5(0))){(C->_cc)=((T3)'\n');}else{
(C->_cc)=((((T7*)(((C)->Zv2)))->Zs1))[ZQ5(0)];}}}else{{T78 ZL6;ZDs=(*(ZL6=Zas(((C)->Zu2),(Z3)(((((C)->Zt2)))-((T2)(ZQ5(1))))),&ZL6));
}Z7s(C);((((T7*)((T7*)(ZUr))))->Z91)=(ZQ5(0));while(!((((C)->_cc))==(((T3)'\n')))){Z26((T7*)(ZUr),((C)->_cc));Z7s(C);}if((((C)->Zw2))==((void*)(Zo))){
{T96*n=((T96*)Zh(sizeof(*n)));*n=M96;Zme(n,ZDs,ZM7((T7*)(ZUr)));(C->Zw2)=((T0*)n);}}else{Z28(((T44*)((((T96*)(((C)->Zw2)))->Zo1))),ZM7((T7*)(ZUr)));
}}}else{(C->_cc)=((T3)'\055');(C->Zt2)=(Z3)(((((C)->Zt2)))-(ZQ5(1)));Zie=((T6)(1));}break;default:;Zie=((T6)(1));}}}}T0*Z0l(T53*C){T0*R=Zo;
if((((C)->ZG2))!=((void*)(Zo))){R=ZC8(((T49*)((((T64*)(((C)->ZG2)))->Zd1))));}return R;}T0*Zuh(T53*C,T0*a1,T0*a2){T0*R=Zo;R=Zl8((T65*)(Zt9((T64*)(((C)->ZG2)),a1)),a2);
return R;}void Z7s(T53*C){if((Z3)((((C)->Zt2))<((((T7*)(((C)->Zv2)))->Z91)))){(C->Zt2)=(Z3)(((((C)->Zt2)))+(ZQ5(1)));(C->_cc)=((((T7*)(((C)->Zv2)))->Zs1))[(((C)->Zt2))-(ZQ5(1))];
}else if((((C)->Zt2))==((((T7*)(((C)->Zv2)))->Z91))){(C->Zt2)=(Z3)(((((C)->Zt2)))+(ZQ5(1)));(C->_cc)=((T3)'\n');}else if((((C)->Zu2))==((((T76*)(Z5s()))->Z91))){
(C->_cc)=((T3)'\000');}else{(C->Zu2)=(Z3)(((((C)->Zu2)))+(ZQ5(1)));(C->Zt2)=ZQ5(1);(C->Zv2)=(((((T49*)((((T76*)(Z5s()))->Zn2))))->Zs1))[((C)->Zu2)];
if(((((T7*)(((C)->Zv2)))->Z91))==(ZQ5(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->Zv2)))->Zs1))[ZQ5(0)];}}}T6 Z2s(T53*C){T6
R=0;T6 ZTk=0;if((T6)((ZYr(C))&&((T6)(ZXr(C))))){if(!(ZPr(C,((T3)'\072')))){{T78 ZL6;Ztk((*(ZL6=Zas(((C)->Zu2),((C)->Zt2)),&ZL6)));}{T0*b1=ZEs;
Zb7((T7*)(ZGe),b1);}ZIe((T77*)(ZJe));}ZTk=((T6)(ZXr(C)));(C->ZD2)=Znr(&(((C)->ZA2)));if((ZFs(C))!=((void*)(Zo))){(((void)((T51*)(Zgs()))),Z0a(ZGs));
(((void)((T51*)(Zgs()))),Z0a(((C)->ZD2)));(((void)((T51*)(Zgs()))),Z0a(ZHs));if((((C)->ZC2))!=((void*)(Zo))){(((void)((T51*)(Zgs()))),Z0a(ZIs));
(((void)((T51*)(Zgs()))),Z0a(((C)->ZC2)));(((void)((T51*)(Zgs()))),Z2a(((T3)'\135')));}(((void)((T51*)(Zgs()))),Z0a(ZJs));}if((T6)(((((C)->_cc))==(((T3)'\n')))||((T6)((((C)->_cc))==(((T3)'\000')))))){
R=((T6)(1));ZKs(C,ZLs);}else if((T6)(((((C)->_cc))==(((T3)'\042')))&&((T6)(Zhs(C))))){R=((T6)(1));ZKs(C,(((T98*)(((C)->ZE2)))->Zc3));
}else if(Z8s(C)){R=((T6)(1));ZKs(C,Znr(&(((C)->ZA2))));}if(R){ZOr(C);}}return R;}T0*Zqh(T53*C,T0*a1){T0*R=Zo;T0*ZRr=Zo;if((((C)->ZG2))!=((void*)(Zo))){
ZRr=Zy9((T64*)(((C)->ZG2)),a1);if((ZRr)!=((void*)(Zo))){R=ZMs(ZRr);}}return R;}void Z4s(T53*C,T0*a1){{T78 ZL6;Ztk((*(ZL6=Zfs(C),&ZL6)));
}{T0*b1=a1;Zb7((T7*)(ZGe),b1);}Z5i((T77*)(ZJe));}void ZKs(T53*C,T0*a1){if((((C)->ZC2))==((void*)(Zo))){if((((C)->ZF2))==((void*)(Zo))){
{T65*n=((T65*)Zh(sizeof(*n)));*n=M65;{T65*C1=n;Za8(C1,Zb8(193));}(C->ZF2)=((T0*)n);}}Zu8((T65*)(((C)->ZF2)),a1,((C)->ZD2));}else{Zu8((T65*)(Zt9((T64*)(((C)->ZG2)),((C)->ZC2))),a1,((C)->ZD2));
}}T0*ZFs(T53*C){T0*R=Zo;if((((C)->ZC2))==((void*)(Zo))){if((((C)->ZF2))!=((void*)(Zo))){R=Zy8((T65*)(((C)->ZF2)),((C)->ZD2));}}else if(Zv9((T64*)(((C)->ZG2)),((C)->ZC2))){
R=Zy8((T65*)(Zt9((T64*)(((C)->ZG2)),((C)->ZC2))),((C)->ZD2));}return R;}T6 ZXr(T53*C){T6 R=0;T6 Zie=0;while(!(Zie)){{int z1=((C)->_cc);
switch(z1){case 9:case 32:Z7s(C);break;default:;Zie=((T6)(1));}}}R=((T6)(1));return R;}T78 Zas(T2 a1,T2 a2){T78 R={Zo,Zo,0};{T78*C1=&R;
T2 b1=a1;T2 b2=a2;ZUj(C1,b1,b2,Zb8(32766),Zo);}return R;}void ZEr(T37*C){(C->Z73)=(Z3)(((((C)->Z73)))+(ZQ5(1)));}void ZMr(T37*C,T0*a1){
(C->Z73)=ZQ5(0);(C->Zt1)=(Z3)(((((((T7*)a1))->Z91)))-(ZQ5(1)));(C->Z81)=((((T7*)a1))->Z81);(C->Zs1)=((((T7*)a1))->Zs1);(C->Z63)=Zo;}T3
ZCr(T37*C){T3 R=0;R=(((C)->Zs1))[((C)->Z73)];return R;}void ZFr(T37*C){T6 Zie=0;while(!(Zie)){if((Z3)((((C)->Z73))>(((C)->Zt1)))){Zie=((T6)(1));
}else if(ZJ5((((C)->Zs1))[((C)->Z73)])){(C->Z73)=(Z3)(((((C)->Z73)))+(ZQ5(1)));}else{Zie=((T6)(1));}}}T6 ZAr(T37*C){T6 R=0;R=((T6)((Z3)((((C)->Z73))>(((C)->Zt1)))));
return R;}T12*ZNs=Zo;int ZOs;char**ZPs;void ZQs(void){{T0*C=ZI9;Zpa(((T32*)C));}}void ZRs(int ZSs,char*ZTs[]){ZOs=ZSs;ZPs=ZTs;ZUs(ZQs);
#ifdef SIGQUIT
ZVs(ZWs,Z64);
#endif
#ifdef SIGILL
ZVs(ZXs,Z64);
#endif
#ifdef SIGABRT
ZVs(ZYs,Z64);
#endif
#ifdef SIGFPE
ZVs(ZZs,Z64);
#endif
#ifdef SIGSEGV
ZVs(Z_s,Z64);
#endif
#ifdef SIGBUS
ZVs(Z0t,Z64);
#endif
#ifdef SIGSYS
ZVs(Z1t,Z64);
#endif
#ifdef SIGTRAP
ZVs(Z2t,Z64);
#endif
#ifdef SIGXCPU
ZVs(Z3t,Z64);
#endif
#ifdef SIGXFSZ
ZVs(Z4t,Z64);
#endif
Z5t();{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;Zhg=((T0*)n);}Z0n=ZOe(8,Zja(10,"C:\\WINDOWS"),Zja(8,"C:\\WINNT"),Zja(8,"C:\\WIN95"),Zja(8,"C:\\WIN98"),
Zja(8,"C:\\WINME"),Zja(8,"C:\\WIN2K"),Zja(10,"C:\\WIN2000"),Zja(8,"C:\\WINXP"));{int ZG7=0;Zkh=Zfa(Z6t);}{T53*n=((T53*)Zh(sizeof(*n)));
*n=M53;ZRg=((T0*)n);}{T88*n=((T88*)Zh(sizeof(*n)));*n=M88;ZDa=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zuj=((T0*)n);Z_6(n,(T2)(Zb8(512)));
}{T86*n=((T86*)Zh(sizeof(*n)));*n=M86;ZEf=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zmg=((T0*)n);Z_6(n,(T2)(Zb8(128)));}{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Z47=((T0*)n);Z_6(n,(T2)(Zb8(256)));}{T44*n=((T44*)Zh(sizeof(*n)));*n=M44;Z57=((T0*)n);Z88(n,(T2)(ZQ5(4)),(T2)(ZQ5(1)));}ZOk=ZOe(5,
Zja(7,ZW3),Zja(5,ZX3),Zja(6,"finder"),Zja(9,"ace_check"),Zja(15,"print_jvm_class"));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZBk=((T0*)n);Z_6(n,(T2)(Zb8(512)));
}ZPk=ZOe(3,Zja(12,Zf3),Zja(7,ZW3),Zja(5,ZX3));ZRk=ZOe(5,Zja(12,Zf3),Zja(5,ZE3),Zja(11,"class_check"),Zja(6,"pretty"),Zja(14,"compile_to_jvm"));
{T52*n=((T52*)Zh(1));Zya=((T0*)n);}{ZR*n=((ZR*)Zh(sizeof(*n)));*n=Z93;Z4m=((T0*)n);Zfi(n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zvk=((T0*)n);
Z_6(n,(T2)(ZQ5(16)));}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZOg=((T0*)n);Z_6(n,(T2)(ZQ5(16)));}{int ZG7=0;Z2f=Zfa(Z7t);}{int ZG7=0;Z7h=Zfa(Z8t);
}{T77*n=((T77*)Zh(sizeof(*n)));*n=M77;ZJe=((T0*)n);}{T57*n=((T57*)Zh(sizeof(*n)));*n=M57;ZKe=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;
ZVr=((T0*)n);Z_6(n,(T2)(ZQ5(80)));}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZUr=((T0*)n);Z_6(n,(T2)(ZQ5(80)));}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;
Zza=((T0*)n);Z_6(n,(T2)(Zb8(128)));}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zue=((T0*)n);Z_6(n,(T2)(Zb8(1024)));}{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;ZGe=((T0*)n);Z_6(n,(T2)(Zb8(1024)));}{T57*n=((T57*)Zh(sizeof(*n)));*n=M57;Z_j=((T0*)n);}{int ZG7=0;ZSg=Zfa(ZVg);}{T23*n=((T23*)Zh(1));
Zgg=((T0*)n);}{T32*n=((T32*)Zh(sizeof(*n)));*n=M32;ZI9=((T0*)n);Zzj(n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZCi=((T0*)n);Z_6(n,(T2)(ZQ5(16)));
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z5h=((T0*)n);Z_6(n,(T2)(Zb8(256)));}{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZCj=((T0*)n);Zge(n);}{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Zwk=((T0*)n);Z_6(n,(T2)(ZQ5(16)));}{T37*n=((T37*)Zh(sizeof(*n)));*n=M37;ZBr=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;ZIk=((T0*)n);
Z_6(n,(T2)(ZQ5(16)));}{T12*n=((T12*)Zh(sizeof(*n)));*n=M12;ZNs=n;}}int main(int ZSs,char*ZTs[]){ZRs(ZSs,ZTs);{T12*n=ZNs;Zin(n);}Zv(0);
return 0;}T0*Zap;T0*ZDp;T0*ZJm;T0*Z2p;T0*Zjj;T0*Zka;T0*Zho;T0*ZMc;T0*Z8o;T0*ZEn;T0*ZJc;T0*ZZn;T0*ZUd;T0*Z9e;T0*ZGm;T0*ZLb;T0*Znc;T0*Z5k;
T0*ZCm;T0*Z4k;T0*Zyn;T0*Z2i;T0*Z2o;T0*Ztc;T0*Zzc;T0*ZGd;T0*ZCc;T0*ZZm;T0*Zzq;T0*Zkq;T0*ZPb;T0*ZFd;T0*Zpb;T0*ZCk;T0*Z4d;T0*Z3d;T0*ZVo;
T0*Z9d;T0*Ztf;T0*ZUn;T0*Z0g;T0*ZTb;T0*ZRq;T0*Zfd;T0*ZSq;T0*ZYd;T0*ZAn;T0*ZN9;T0*Z9p;T0*Zoh;T0*ZWg;T0*ZHd;T0*ZDl;T0*ZHe;T0*Ztm;T0*Zam;
T0*Zpq;T0*Z2k;T0*Zjp;T0*Z7e;T0*ZTp;T0*Zxf;T0*Zzb;T0*Zqk;T0*Zhh;T0*Z7c;T0*ZAp;T0*Zid;T0*Ztr;T0*Zvf;T0*Zsb;T0*ZOh;T0*ZTg;T0*ZNb;T0*ZMb;
T0*Zma;T0*Z9k;T0*ZZh;T0*Z1c;T0*Z3c;T0*Z9c;T0*Zon;T0*Z3l;T0*Zec;T0*Z4c;T0*ZZb;T0*ZWb;T0*Z5o;T0*Zgc;T0*ZHa;T0*ZJb;T0*ZGo;T0*ZWc;T0*Zta;
T0*Z0i;T0*Z6c;T0*ZDc;T0*ZVl;T0*ZTm;T0*ZCb;T0*Zzp;T0*ZTq;T0*ZZc;T0*Zak;T0*ZMq;T0*Zrm;T0*Z_p;T0*Zmd;T0*Zyf;T0*Z8e;T0*ZRm;T0*ZHm;T0*Z5p;
T0*Z3k;T0*ZYb;T0*Z6e;T0*Zjd;T0*Zhl;T0*ZXe;T0*Z_n;T0*ZPn;T0*ZDr;T0*Zba;T0*Znm;T0*Zcf;T0*Zup;T0*Z4e;T0*ZGq;T0*Zib;T0*ZSm;T0*Zea;T0*Zqi;
T0*ZYc;T0*Zqf;T0*ZBb;T0*Zpk;T0*ZAh;T0*Zaf;T0*Z3n;T0*ZXo;T0*Znq;T0*ZRc;T0*Zal;T0*Zwm;T0*ZFp;T0*ZVe;T0*Z3i;T0*Zro;T0*ZFq;T0*Zio;T0*ZWf;
T0*ZXq;T0*ZWe;T0*ZSl;T0*Zzg;T0*Zwf;T0*ZAo;T0*Zob;T0*Zki;T0*Zdf;T0*Z0p;T0*Z_c;T0*ZVn;T0*Z4f;T0*ZJs;T0*Zso;T0*Zjn;T0*ZAm;T0*Z5f;T0*ZBm;
T0*ZTf;T0*Z3m;T0*Zem;T0*Zuf;T0*ZBf;T0*Zts;T0*Zyq;T0*ZWo;T0*ZOm;T0*Zhc;T0*ZYh;T0*Zyo;T0*Z1i;T0*ZGn;T0*ZSh;T0*ZPh;T0*Zgp;T0*ZSc;T0*ZGk;
T0*ZYg;T0*Zlk;T0*ZIs;T0*ZUc;T0*Zxq;T0*ZUm;T0*Z2e;T0*Zyb;T0*Zpc;T0*Zdo;T0*Z1p;T0*ZAg;T0*ZQh;T0*Zip;T0*ZZq;T0*Z7l;T0*Zwq;T0*Zkp;T0*Zvc;
T0*Zyl;T0*Zvd;T0*Zsn;T0*Zfh;T0*Z3e;T0*ZKf;T0*Z6o;T0*ZRh;T0*Zbh;T0*ZOp;T0*Zla;T0*Zbf;T0*Zgd;T0*Ztd;T0*Z4n;T0*Zmm;T0*Zud;T0*ZHn;T0*Zsd;
T0*Zao;T0*ZRa;T0*ZOa;T0*ZZl;T0*ZMa;T0*Zul;T0*Zwg;T0*Zei;T0*ZIg;T0*Zdj;T0*ZFb;T0*ZEs;T0*Z7f;T0*ZUb;T0*Zwp;T0*Ztb;T0*Z1r;T0*Zzh;T0*Z4q;
T0*ZJf;T0*ZNq;T0*ZOb;T0*ZSb;T0*Zxp;T0*Z7d;T0*Z8d;T0*Z0q;T0*Zye;T0*Zhb;T0*Zhj;T0*Z8f;T0*Z9h;T0*Zej;T0*Zeb;T0*Z1a;T0*Z_d;T0*Zmi;T0*Zhf;
T0*Zco;T0*Zdm;T0*ZIc;T0*Zmj;T0*Z_q;T0*ZLp;T0*ZLd;T0*Zpi;T0*Zad;T0*ZBc;T0*ZXc;T0*Zim;T0*ZAc;T0*Zwl;T0*ZAd;T0*Zqb;T0*Z6k;T0*Z0h;T0*ZPm;
T0*ZLs;T0*ZEl;T0*Zrc;T0*Z6p;T0*ZZf;T0*Zhr;T0*Zef;T0*Zfm;T0*Ztg;T0*ZIf;T0*Zlh;T0*Zvg;T0*Zni;T0*Zif;T0*ZHg;T0*ZGf;T0*Zzo;T0*ZJp;T0*Zpf;
T0*Zlf;T0*Zrf;T0*Zha;T0*ZXg;T0*ZTc;T0*Zjc;T0*ZSd;T0*Z5g;T0*Zah;T0*ZCd;T0*ZBd;T0*ZPa;T0*Znb;T0*ZM9;T0*ZVg;T0*Zfg;T0*ZIq;T0*ZUe;T0*Zae;
T0*Z7t;T0*ZQd;T0*ZHp;T0*Zhd;T0*ZYl;T0*ZLc;T0*ZR9;T0*Zds;T0*ZNr;T0*ZVd;T0*ZKa;T0*Zrq;T0*Zrs;T0*Zuc;T0*Z2d;T0*Zxi;T0*ZOq;T0*ZEc;T0*Zir;
T0*Z8k;T0*Zkn;T0*ZHq;T0*Zsg;T0*Zoc;T0*ZUg;T0*ZZo;T0*Zai;T0*Zer;T0*ZQk;T0*Zca;T0*Zmo;T0*ZDb;T0*Zgr;T0*Zur;T0*Zlm;T0*ZYe;T0*Zyd;T0*Z4i;
T0*Zyc;T0*ZDd;T0*Z1e;T0*ZWd;T0*Zvr;T0*Zrb;T0*ZPq;T0*ZGc;T0*ZBs;T0*ZFc;T0*Zoi;T0*Zsq;T0*Zwn;T0*Zeo;T0*ZHb;T0*ZUo;T0*Zqc;T0*Z6n;T0*Zes;
T0*ZUh;T0*Z3o;T0*Zxs;T0*ZQb;T0*Zfq;T0*Zli;T0*Z5q;T0*ZRb;T0*ZGp;T0*ZPl;T0*Zvm;T0*Zll;T0*Zdb;T0*Zvb;T0*Zfo;T0*Zvs;T0*Zto;T0*Zyp;T0*Zdd;
T0*Zgb;T0*ZYq;T0*ZQe;T0*ZOl;T0*Zub;T0*Zqn;T0*Z5l;T0*Zrh;T0*Z7o;T0*Zkk;T0*Zvq;T0*ZNc;T0*Z_9;T0*ZGb;T0*Zoq;T0*ZUp;T0*Zlj;T0*ZZ9;T0*ZBn;
T0*ZNd;T0*Zhq;T0*ZOc;T0*Zgo;T0*Z5c;T0*Zug;T0*Zaa;T0*Zpd;T0*Zbc;T0*Zcc;T0*Zkd;T0*ZLn;T0*Zxd;T0*Z5e;T0*Zfc;T0*ZPc;T0*ZQc;T0*ZDk;T0*ZLf;
T0*ZFe;T0*Z7a;T0*Zjb;T0*Zeh;T0*Zkb;T0*ZEd;T0*Zic;T0*Zml;T0*ZQq;T0*Znf;T0*Zjo;T0*ZNm;T0*Zpr;T0*Zkc;T0*Zom;T0*Z3q;T0*Z2r;T0*Zmq;T0*Zlc;
T0*ZJl;T0*ZKp;T0*Z9r;T0*Zjm;T0*ZCn;T0*Zgm;T0*Zzd;T0*Zcm;T0*Zws;T0*Z4r;T0*Zga;T0*ZXm;T0*ZTl;T0*ZHk;T0*Zsc;T0*Zar;T0*ZKl;T0*ZLl;T0*Zbd;
T0*Z6l;T0*Zuk;T0*ZRe;T0*Zqm;T0*Z6b;T0*Zql;T0*ZAq;T0*Zhm;T0*ZJq;T0*Zep;T0*ZKq;T0*Zbr;T0*Zod;T0*ZWm;T0*Zsm;T0*Z6d;T0*Zdr;T0*Z_f;T0*Z5d;
T0*ZHo;T0*ZIo;T0*ZZd;T0*Zgq;T0*ZSo;T0*ZSa;T0*Z9o;T0*Zda;T0*Zok;T0*Zij;T0*ZFh;T0*Zwr;T0*Z_m;T0*ZAe;T0*Zdi;T0*ZCs;T0*Zfk;T0*Zun;T0*ZDn;
T0*Zpm;T0*Z7q;T0*ZBe;T0*ZCp;T0*Z_o;T0*Ziq;T0*Zcr;T0*ZNl;T0*ZRd;T0*ZTd;T0*Z6q;T0*Ztq;T0*Zrl;T0*ZTe;T0*Zld;T0*Zqd;T0*Zrd;T0*Zdh;T0*Znl;
T0*ZNk;T0*Zmf;T0*Zus;T0*ZZp;T0*ZDf;T0*Zqq;T0*ZQ9;T0*Z8p;T0*Z1m;T0*Zri;T0*Zgj;T0*ZMd;T0*ZYo;T0*Zlq;T0*Z9l;T0*Z2c;T0*ZKb;T0*Z8c;T0*Z0c;
T0*ZEe;T0*Zdc;T0*Z_b;T0*ZVb;T0*ZXb;T0*ZIb;T0*Z1o;T0*Zac;T0*Z4o;T0*Zfj;T0*ZTa;T0*ZJa;T0*Z9f;T0*ZUa;T0*ZJd;T0*Znd;T0*Zxc;T0*ZQm;T0*Zbi;
T0*Zmb;T0*ZLq;T0*Zff;T0*Z0d;T0*Zzs;T0*Z1d;T0*Zch;T0*Zjl;T0*Z3r;T0*ZAf;T0*ZQa;T0*ZWn;T0*Z3g;T0*Zgl;T0*ZDq;T0*ZMf;T0*ZJo;T0*Zvp;T0*Zhp;
T0*ZId;T0*Zko;T0*ZNa;T0*Zbo;T0*ZCe;T0*ZZg;T0*Z7b;T0*Z0r;T0*Zzk;T0*ZOd;T0*ZMm;T0*Z7k;T0*ZTh;T0*Zzf;T0*Zci;T0*Zuq;T0*Zxb;T0*ZIa;T0*Zfb;
T0*Zdp;T0*ZVc;T0*ZVm;T0*ZQn;T0*ZIp;T0*ZYn;T0*ZKd;T0*ZPd;T0*ZKm;T0*Zlb;T0*Zzn;T0*Zwb;T0*ZBp;T0*Z2n;T0*ZMl;T0*Zjf;T0*ZQf;T0*Zbp;T0*Zwd;
T0*Z8h;T0*Z0e;T0*ZGs;T0*Znj;T0*Zxl;T0*ZFm;T0*Zwc;T0*ZTo;T0*Zil;T0*Zss;T0*Zmc;T0*Zrn;T0*ZCq;T0*ZLm;T0*ZGa;T0*ZDe;T0*ZHs;T0*Zkm;T0*ZSe;
T0*ZEm;T0*Z2g;T0*Zed;T0*ZAb;T0*ZAs;T0*ZLa;T0*ZXd;T0*Z8t;T0*Zcd;T0*ZKc;T0*ZEq;T0*Zfr;T0*ZYp;T0*Zcp;T0*ZDm;T0*Z0o;T0*Z_l;T0*ZEb;T0*Z4p;
T0*Zkj;T0*Z_g;T0*Z1f;T0*Ztn;T0*Z7p;T0*ZPe;T0*Z2m;T0*Zbe;T0*Z6t;T0*ZHc;T0*Zja(int c,char*e){T7*s=((T7*)Zh(sizeof(T7)));s->Z91=c;s->Z81=c+1;
s->Zs1=((T9)Zh(c+1));ZN6(s->Zs1,e,c+1);return((T0*)s);}T0*Z9t(char*e){int c=Zw4(e);T7*s=((T7*)Zh(sizeof(T7)));s->Z91=c;s->Z81=c+1;s->Zs1=((T9)Zh(c+1));
ZN6(s->Zs1,e,c+1);return((T0*)s);}void Z5t(void){Zap=Zja(3,ZH3);ZDp=Zja(0,Zd3);ZJm=Zja(2,Zl3);Z2p=Zja(7,ZQ3);Zjj=Zja(17,"cpp_compiler_type");
Zka=Zja(23,"Environment variable $\173""");Zho=Zja(51,"\n   The default C compiler could not be determined.");ZMc=Zja(9,"exception");
Z8o=Zja(26,"\n      C++ compiler type: ");ZEn=Zja(3,ZH3);ZJc=Zja(12,"double_floor");ZZn=Zja(23,"\n\n   Operating system: ");ZUd=Zja(10,"to_pointer");
Z9e=Zja(6,"Result");ZGm=Zja(16,"C linker options");ZLb=Zja(9,"bit_clear");Znc=Zja(4,"call");Z5k=Zja(7,"require");ZCm=Zja(49,Z14);Z4k=Zja(2,"no");
Zyn=Zja(15,"new C mode name");Z2i=Zja(2,"os");Z2o=Zja(12,"\n   C mode: ");Ztc=Zja(4,"code");Zzc=Zja(4,"copy");ZGd=Zja(17,"standard_is_equal");
ZCc=Zja(14,"default_create");ZZm=Zja(42,"Could not compute the parent directory of ");Zzq=Zja(983,"\n\n-- ======================================================================= --\n\n-- Below are the \"C mode\" sections. Each C mode describes which C compiler must\n-- be called, with which options, which linker, and so on. The keys are\n-- described below.\n\n-- The first sections (boost, ..., debug_check) are by default used in\n-- conjunction with the corresponding SmartEiffel check level. This behaviour\n-- may be changed by using the -c_mode flag.\n\n-- The recognized keys in each section are:\n\n-- \'compiler_type\', which tells which is the compiler type to use\n\n-- \'compiler_path\', which gives the path to the compiler executable\n\n-- \'compiler_options\', which gives some options to the compiler\n\n-- \'linker_path\', which gives the path to the linker executable (not used in\n--  -no_split mode)\n\n-- \'linker_options\', which gives some options for the linker (not used in\n--  -no_split mode)\n\n-- \'smarteiffel_options\', which gives some extra SmartEiffel options to take\n--  into account\n\n");
Zkq=Zja(2,Zn3);ZPb=Zja(10,"bit_rotate");ZFd=Zja(13,"standard_copy");Zpb=Zja(7,"GENERAL");ZCk=Zja(7,ZW3);Z4d=Zja(4,"last");Z3d=Zja(4,"item");
ZVo=Zja(13,ZZ3);Z9d=Zja(4,"make");Ztf=Zja(4,"dice");ZUn=Zja(0,Zd3);Z0g=Zja(4,"cpml");ZTb=Zja(4,"\174"">>>");ZRq=Zja(13,"Sys directory");
Zfd=Zja(14,"Maximum_double");ZSq=Zja(15,"Short directory");ZYd=Zja(4,"twin");ZAn=Zja(56,"\n*** This C mode already exists. Please choose another.\n");
ZN9=Zja(3,Zw3);Z9p=Zja(35,". Set the default compilers options");Zoh=Zja(4,"mcr ");Zat();}void Zat(void){ZWg=Zja(41,"\" does not contain name of a valid file.\n");
ZHd=Zja(13,"standard_twin");ZDl=Zja(12,"loadpath key");ZHe=Zja(80," is not supported as a C++ compiler. I will continue, but expect some problems.\n");
Ztm=Zja(19,"Known C compilers: ");Zam=Zja(86,"\n---------------------------------------------------------------------------\n\nC mode: ");
Zpq=Zja(10,"[General]\n");Z2k=Zja(7,"unknown");Zjp=Zja(41,"Please enter a valid number between 1 and");Z7e=Zja(19,"open_argument_count");
ZTp=Zja(21,"C compiling no-split ");Zxf=Zja(4,"vpcc");Zzb=Zja(8,"REAL_REF");Zqk=Zja(17,"Too many errors.\n");Zhh=Zja(9,"system.se");Z7c=Zja(7,"or else");
ZAp=Zja(67,".\nPlease either type <Enter> to go on, or choose a new C mode now.\n");Zid=Zja(12,"Pointer_bits");Ztr=Zja(1,Ze3);Zvf=Zja(4,"vbcc");
Zsb=Zja(6,"MEMORY");ZOh=Zja(1,"\?");ZTg=Zja(9,ZS3);ZNb=Zja(1,"\174""");ZMb=Zja(1,"\176""");Zma=Zja(13," is not set.\n");Z9k=Zja(3,"all");
ZZh=Zja(3,ZM3);Z1c=Zja(2,"#-");Z3c=Zja(2,"#*");Z9c=Zja(2,"#+");Zon=Zja(7,ZV3);Z3l=Zja(208,"\n*** Fatal problem during installation of SmartEiffel.\n    Read carefully the following information before starting\n    again the installation.\n***************************************************************\n");
Zec=Zja(2,"//");Z4c=Zja(2,"/=");ZZb=Zja(2,"<=");ZWb=Zja(2,">=");Z5o=Zja(27,"\n      C compiler options: ");Zgc=Zja(2,"a1");ZHa=Zja(9,"INTEGER_8");
ZJb=Zja(2,"\\\\");ZGo=Zja(3,"tag");ZWc=Zja(2,"io");Zta=Zja(13,"System call \"");Z0i=Zja(3,ZR3);Z6c=Zja(2,"or");ZDc=Zja(14,"default_rescue");
ZVl=Zja(26,"--press <Enter> for more--");ZTm=Zja(19,ZJ3);ZCb=Zja(15,"TEXT_FILE_WRITE");Zbt();}void Zbt(void){Zzp=Zja(36,"\nThe default installation C mode is ");
ZTq=Zja(39,Zy3);ZZc=Zja(13,"is_deep_equal");Zak=Zja(5,"debug");ZMq=Zja(23,"configuration file name");Zrm=Zja(5,"12]: ");Z_p=Zja(2,Zo3);
Zmd=Zja(8,"print_on");Zyf=Zja(10,"OpenVMS_CC");Z8e=Zja(9,"Precursor");ZRm=Zja(49,Z14);ZHm=Zja(21,"Known C++ compilers: ");Z5p=Zja(14,". Modify the \"");
Z3k=Zja(5,"boost");ZYb=Zja(7,"implies");Z6e=Zja(19,"open_argument_index");Zjd=Zja(12,"pointer_size");Zhl=Zja(5,ZF3);ZXe=Zja(7,ZN3);Z_n=Zja(22,"\n   Bin directory:    ");
ZPn=Zja(0,Zd3);ZDr=Zja(26,"Integer constant expected.");Zba=Zja(20,"SmallEiffelDirectory");Znm=Zja(48,"\n12.  Return to the previous menu\n\nYour choice [");
Zcf=Zja(0,Zd3);Zup=Zja(7,Zt3);Z4e=Zja(14,"open_arguments");ZGq=Zja(24,"4. Set the Sys directory");Zib=Zja(11,"BOOLEAN_REF");ZSm=Zja(18,"C++ linker options");
Zea=Zja(10," in file \"");Zqi=Zja(3,",-\n");ZYc=Zja(22,"is_basic_expanded_type");Zqf=Zja(6,ZY3);ZBb=Zja(14,"TEXT_FILE_READ");Zpk=Zja(5,"Error");
ZAh=Zja(3,".00");Zaf=Zja(7,ZB3);Z3n=Zja(11,Z44);ZXo=Zja(7,ZQ3);Znq=Zja(95,"\n*** There was an error while trying to write the configuration file. Please verify its name.\n\n");
ZRc=Zja(6,"fourth");Zal=Zja(66," does not exist or is not a directory:\n    this value is ignored.\n");Zwm=Zja(15,"C compiler type");
ZFp=Zja(50,"*** Could not create the bin directory: aborting.\n");ZVe=Zja(3,ZD3);Z3i=Zja(12,"Unknown os \"");Zro=Zja(15,"Could not open ");
ZFq=Zja(24,"3. Set the Bin directory");Zio=Zja(37,"Type <Enter> to go back to the menu: ");Zct();}void Zct(void){ZWf=Zja(3,".id");ZXq=Zja(0,Zd3);
ZWe=Zja(3,ZG3);ZSl=Zja(41,"\n*** Please enter a nember between 1 and ");Zzg=Zja(3,"[1-");Zwf=Zja(3,"ccc");ZAo=Zja(8,"loadpath");Zob=Zja(8,"FUNCTION");
Zki=Zja(6,ZY3);Zdf=Zja(0,Zd3);Z0p=Zja(13,ZZ3);Z_c=Zja(10,"is_default");ZVn=Zja(0,Zd3);Z4f=Zja(3,"gcc");ZJs=Zja(44,".\nIts retained value will be the last read.\n");
Zso=Zja(148,"\n---------------------------------------------------------------------------\n\nYou did not install SmartEiffel. Are you sure you want to exit\? [y\174""N] ");
Zjn=Zja(974,"\nHello!\n\nThank you for choosing SmartEiffel.\n\nI\'m here to help you install your software. Many default options have been set\nfor you; the simplest way to install SmartEiffel is to keep pressing the\n<Enter> key as long as I ask anything.\n\nOf course you can change the options I set; it\'s just a matter of chosing items\nin the menus, and you\'ll see you can greatly customize your SmartEiffel\ninstallation. A golden rule is, just pressing <Enter> always works, and\ninexorably leads towards the actual SmartEiffel installation. When no default is\nprovided (between brackets), the <Enter> key will just leave everything\nunchanged and get you back to the previous menu.\n\nAs training, you\'ll be asked to press the <Enter> key to gain access to the\nmain menu ;-)\n\nIf you have problems, please contact the SmartEiffel12 team:\n  - either by mail:  smarteiffel@except.com.ar\n  - either by using the bugs database: http://opensvn.csie.org/traccgi/smarteiffel12\n\n\nPress the <Enter> key: ");
ZAm=Zja(25,"\n*** Unknown C compiler.\n");Z5f=Zja(3,"g++");ZBm=Zja(15,"C compiler path");ZTf=Zja(3,"lcc");Z3m=Zja(97,"SmartEiffel was not properly installed.\nPlease run the installer again to fix the installation.\n\n");
Zem=Zja(33,"3.  Change the C compiler options");Zuf=Zja(2,Zp3);ZBf=Zja(3,"tcc");Zts=Zja(67,"Extra blank or tab character removed in multi-line manifest string.");
Zyq=Zja(2,Zn3);ZWo=Zja(21," contains an invalid ");ZOm=Zja(19,ZJ3);Zhc=Zja(8,"add_last");ZYh=Zja(7,"General");Zyo=Zja(21,"This extra loadpath (");
Z1i=Zja(5,ZE3);ZGn=Zja(12,"\nYou typed \"");ZSh=Zja(10," Data=Auto");ZPh=Zja(0,Zd3);Zgp=Zja(53,"\nPlease enter the new value of the default C compiler");
ZSc=Zja(12,"from_pointer");ZGk=Zja(35,"\nPlease enter the new value of the ");ZYg=Zja(4,"  - ");Zlk=Zja(2,"  ");ZIs=Zja(17," in the section [");
ZUc=Zja(15,"generating_type");Zxq=Zja(278,"\n-- This section contains the default loadpaths used by this SmartEiffel\n-- installation.\n\n-- The key is a mere description and serves no other purpose,\n\n-- The value of the key is the path to a loadpath file.\n\n-- Note that the loadpath files ar read in the order given below.\n\n");
ZUm=Zja(41,Z34);Z2e=Zja(12,"like Current");Zyb=Zja(12,"REAL_GENERAL");Zpc=Zja(8,"capacity");Zdo=Zja(28,"\n      SmartEiffel options: ");
Z1p=Zja(27," contains an invalid valid ");Zdt();}void Zdt(void){ZAg=Zja(6,"][0-9]");ZQh=Zja(34,"Math=IEEE Parameters=Both Code=Far");
Zip=Zja(55,"\nPlease enter the new value of the default C++ compiler");ZZq=Zja(27,"Unable to find executable \"");Z7l=Zja(5,ZE3);Zwq=Zja(11,"[Loadpath]\n");
Zkp=Zja(2,Zk3);Zvc=Zja(14,"collection_off");Zyl=Zja(4,Z54);Zvd=Zja(15,"raise_exception");Zsn=Zja(25,"/boot/beos/system/Tracker");Zfh=Zja(9,ZU3);
Z3e=Zja(6,"method");ZKf=Zja(4," To ");Z6o=Zja(22,"\n      C linker path: ");ZRh=Zja(9," Data=Far");Zbh=Zja(20,Zv3);ZOp=Zja(32,"                                ");
Zla=Zja(15," used in file \"");Zbf=Zja(0,Zd3);Zgd=Zja(12,"Maximum_real");Ztd=Zja(9,"put_16_le");Z4n=Zja(7,".serc12");Zmm=Zja(40,"11. Change the SmartEiffel extra options");
Zud=Zja(9,"put_16_ne");ZHn=Zja(48,"\".\nPlease enter a valid number between 1 and 6.\n");Zsd=Zja(9,"put_16_be");Zao=Zja(29,"\n      C++ compiler options: ");
ZRa=Zja(7,"POINTER");ZOa=Zja(7,"REAL_64");ZZl=Zja(35,"\nCould not compute the path to the ");ZMa=Zja(7,"REAL_32");Zul=Zja(6,"Done.\n");
Zwg=Zja(45,ZA3);Zei=Zja(4,".lnk");ZIg=Zja(4,".obj");Zdj=Zja(15,"c_compiler_type");ZFb=Zja(14,"UNICODE_STRING");ZEs=Zja(12,"Inserted \':\'");
Z7f=Zja(4,ZI3);ZUb=Zja(7,"bit_xor");Zwp=Zja(190,"The install/germ directory does not exist!\nDid you use a smarteiffel12 package\?\nIf not, you can download it at http://opensvn.csie.org/traccgi/smarteiffel12\nand start the installation again.");
Ztb=Zja(12,"NATIVE_ARRAY");Z1r=Zja(2,Zi3);Zzh=Zja(4,".exe");Z4q=Zja(44,"\n*** Please enter a n integer between 1 and ");ZJf=Zja(4,ZK3);
ZNq=Zja(70,"*** Don\'t forget to set the \"SmartEiffel\" environment variable to\n*** ");ZOb=Zja(7,"bit_put");ZSb=Zja(7,"bit_set");Zet();
}void Zet(void){Zxp=Zja(79,ZO3);Z7d=Zja(6,"low_16");Z8d=Zja(6,"low_32");Z0q=Zja(9,"-no_split");Zye=Zja(0,Zd3);Zhb=Zja(5,"BIT_N");Zhj=Zja(16,"c_linker_options");
Z8f=Zja(0,Zd3);Z9h=Zja(8,Zz3);Zej=Zja(15,"c_compiler_path");Zeb=Zja(5,"ARRAY");Z1a=Zja(19,"Cannot write file \"");Z_d=Zja(13,"with_capacity");
Zmi=Zja(11," StripDebug");Zhf=Zja(6,"lcclnk");Zco=Zja(27,"\n      C++ linker options: ");Zdm=Zja(30,"2.  Change the C compiler path");
ZIc=Zja(11,"Double_bits");Zmj=Zja(15,"cpp_linker_path");Z_q=Zja(3,Zw3);ZLp=Zja(12,Zf3);ZLd=Zja(7,"storage");Zpi=Zja(11,"$ link/exe=");
Zad=Zja(22,"Minimum_character_code");ZBc=Zja(10,"c_inline_h");ZXc=Zja(12,"Integer_bits");Zim=Zja(32,"7.  Change the C++ compiler path");
ZAc=Zja(10,"c_inline_c");Zwl=Zja(0,Zd3);ZAd=Zja(17,"same_dynamic_type");Zqb=Zja(15,"INTEGER_GENERAL");Z6k=Zja(6,"ensure");Z0h=Zja(30,"Using the configuration file: ");
ZPm=Zja(20,"C++ compiler options");ZLs=Zja(0,Zd3);ZEl=Zja(14,"loadpath value");Zrc=Zja(9,"clear_all");Z6p=Zja(9,"\" C mode\n");ZZf=Zja(1,"m");
Zhr=Zja(13,"-boost -no_gc");Zef=Zja(0,Zd3);Zfm=Zja(28,"4.  Change the C linker path");Ztg=Zja(2,"-c");ZIf=Zja(2,"-e");Zlh=Zja(2,"-l");
Zvg=Zja(2,"/c");Zni=Zja(6,"-s -d1");Zif=Zja(2,Zp3);ZHg=Zja(2,".o");ZGf=Zja(2,"-o");Zft();}void Zft(void){Zzo=Zja(6,") is: ");ZJp=Zja(28,"\n                (linker)   ");
Zpf=Zja(2,"cl");Zlf=Zja(2,"cc");Zrf=Zja(2,"sc");Zha=Zja(11,ZP3);ZXg=Zja(71,"A valid configuration file was not found in all its default locations:\n");
ZTc=Zja(12,"full_collect");Zjc=Zja(8,"as_16_ne");ZSd=Zja(10,"to_integer");Z5g=Zja(11,"System is \"");Zah=Zja(7,ZV3);ZCd=Zja(7,"se_argv");
ZBd=Zja(7,"se_argc");ZPa=Zja(7,"BOOLEAN");Znb=Zja(11,"FIXED_ARRAY");ZM9=Zja(10,"Removing \"");ZVg=Zja(11,ZP3);Zfg=Zja(79,"\nThe type of your operating system was automatically  computed. Please verify.\n");
ZIq=Zja(74,"6. Manage the [Loadpath] section\n7. Return to the main menu\n\nYour choice [");ZUe=Zja(5,ZC3);Zae=Zja(6,"target");Z7t=Zja(11,"USERPROFILE");
ZQd=Zja(12,"to_integer_8");ZHp=Zja(17,"\n  - C compiler: ");Zhd=Zja(11,"object_size");ZYl=Zja(11,"loadpath.se");ZLc=Zja(14,"element_sizeof");
ZR9=Zja(6,"\" as \"");Zds=Zja(9,"reference");ZNr=Zja(21,"End of text expected.");ZVd=Zja(7,"to_real");ZKa=Zja(9,"CHARACTER");Zrq=Zja(5,"bin: ");
Zrs=Zja(4,"once");Zuc=Zja(10,"collecting");Z2d=Zja(11,"is_not_null");Zxi=Zja(4,"none");ZOq=Zja(11,ZP3);ZEc=Zja(11,"deep_memcmp");Zir=Zja(9," -c_mode ");
Z8k=Zja(4,"loop");Zkn=Zja(97,"\nDon\'t forget that rule: the <Enter> key ensures that SmartEiffel will eventually\nget installed.\n");
ZHq=Zja(26,"5. Set the Short directory");Zsg=Zja(33,ZL3);Zoc=Zja(6,"calloc");ZUg=Zja(26,"The environment variable \"");ZZo=Zja(22," does not contain the ");
Zai=Zja(33,ZL3);Zer=Zja(25,"\" is not a valid choice.\n");Zgt();}void Zgt(void){ZQk=Zja(6,"-clean");Zca=Zja(10,"Obsolete \"");Zmo=Zja(5,ZX3);
ZDb=Zja(5,"TUPLE");Zgr=Zja(6,"-boost");Zur=Zja(2,Zm3);Zlm=Zja(33,"10. Change the C++ linker options");ZYe=Zja(5,ZT3);Zyd=Zja(6,"second");
Z4i=Zja(25,"#: config file corrupted!");Zyc=Zja(11,"conforms_to");ZDd=Zja(15,"sedb_breakpoint");Z1e=Zja(11,"last_result");ZWd=Zja(12,"trace_switch");
Zvr=Zja(1,Ze3);Zrb=Zja(11,"INTEGER_REF");ZPq=Zja(51,"\nPlease enter the new value of the operating system");ZGc=Zja(14,"deep_twin_from");
ZBs=Zja(44,"Unexpected character in hexadecimal unicode.");ZFc=Zja(9,"deep_twin");Zoi=Zja(10,"linkit.com");Zsq=Zja(5,"sys: ");Zwn=Zja(3,"C:\\");
Zeo=Zja(4,"\n   ");ZHb=Zja(8,"and then");ZUo=Zja(3,".rc");Zqc=Zja(14,"Character_bits");Z6n=Zja(7,ZN3);Zes=Zja(78,"Wrong case for keyword, this will not work in SE 2.2. You should capitalize: \'");
ZUh=Zja(18," NoVersion NoIcons");Z3o=Zja(24,"\n      C compiler type: ");Zxs=Zja(24,"Bad (empty\?) ascii code.");ZQb=Zja(3,"#<<");Zfq=Zja(6,"_check");
Zli=Zja(22,"#1#2#3#4#5#6#7#8#9#\?.o");Z5q=Zja(2,Zk3);ZRb=Zja(3,"#>>");ZGp=Zja(46,"\nSummary of gathered options:\n  - C mode:     ");
ZPl=Zja(3,ZH3);Zvm=Zja(2,Zl3);Zll=Zja(3,"lib");Zdb=Zja(3,"ANY");Zvb=Zja(11,"POINTER_REF");Zfo=Zja(2,Zn3);Zvs=Zja(26,"Unknown special character.");
Zto=Zja(198,"***************************************************************\nFix the previously described problem and launch again the,\ninstallation, or contact the SmartEiffel12 team:\nsmarteiffel@except.com.ar\n");
Zyp=Zja(84,"You are about to start the SmartEiffel installation.\nJust one last thing, though...\n");Zdd=Zja(19,"manifest_initialize");
Zgb=Zja(3,"BIT");ZYq=Zja(0,Zd3);Zht();}void Zht(void){ZQe=Zja(7,Zs3);ZOl=Zja(44,". Return to the previous menu\n\nYour choice [");Zub=Zja(8,"PLATFORM");
Zqn=Zja(20,Zv3);Z5l=Zja(3,ZM3);Zrh=Zja(8,"Loadpath");Z7o=Zja(25,"\n      C linker options: ");Zkk=Zja(7,"****** ");Zvq=Zja(5,"tag: ");
ZNc=Zja(5,"fifth");Z_9=Zja(8,"\" file.\n");ZGb=Zja(3,"and");Zoq=Zja(381,"-- This is the configuration file of SmartEiffel, generated by the\n-- SmartEiffel installer.\n-- If you have any problems or questions, please:\n--   - either look at the SmartEiffel site (http://opensvn.csie.org/traccgi/smarteiffel12)\n--   - or contact the SmartEiffel12 team (smarteiffel@except.com.ar)\n-- ======================================================================= --\n");
ZUp=Zja(2,Zo3);Zlj=Zja(20,"cpp_compiler_options");ZZ9=Zja(9,"Writing \"");ZBn=Zja(98,"---------------------------------------------------------------------------\n\n   Operating system: ");
ZNd=Zja(6,"to_bit");Zhq=Zja(442,"SmartEiffel The GNU Eiffel Compiler, Eiffel tools and libraries\nRelease 1.2r7 transitional Release (Sunday April 2nd 2006)\nThis is an unofficial release. Check http://SmartEiffel.loria.fr for\nthe official SmartEiffel\nCopyright (C), 1994-2003 - INRIA - LORIA - UHP - Nancy 2 - FRANCE\nD.COLNET, S.COLLIN, O.ZENDRA, P.RIBET, C.ADRIAN \nCopyright (C) 2005-2006 D.F.MOISSET - smarteiffel@except.com.ar\nhttp://opensvn.csie.org/traccgi/smarteiffel12\n");
ZOc=Zja(5,"first");Zgo=Zja(24,"\n   Default C compiler: ");Z5c=Zja(3,"not");Zug=Zja(10,"-ansi -x c");Zaa=Zja(11,"SmallEiffel");Zpd=Zja(3,"put");
Zbc=Zja(3,"\174""<<");Zcc=Zja(3,"\174"">>");Zkd=Zja(3,"pow");ZLn=Zja(7,Zt3);Zxd=Zja(7,"realloc");Z5e=Zja(21,"open_argument_indices");
Zfc=Zja(3,"xor");ZPc=Zja(5,"floor");ZQc=Zja(5,"flush");ZDk=Zja(4,Z54);ZLf=Zja(5,"a.out");ZFe=Zja(2,Zk3);Z7a=Zja(21,"Trying to read file \"");
Zjb=Zja(13,"CHARACTER_REF");Zeh=Zja(7,Zu3);Zkb=Zja(10,"DICTIONARY");ZEd=Zja(13,"signal_number");Zic=Zja(5,"agent");Zml=Zja(5,"tools");
ZQq=Zja(13,"Bin directory");Znf=Zja(5,"bcc32");Zjo=Zja(9,ZU3);ZNm=Zja(49,Z14);Zpr=Zja(49,"                                                 ");
Zkc=Zja(5,"atan2");Zit();}void Zit(void){Zom=Zja(39,"7. Change the SmartEiffel extra options");Z3q=Zja(15,"loadpath number");Z2r=Zja(9,ZS3);
Zmq=Zja(4," to ");Zlc=Zja(5,"blank");ZJl=Zja(79,ZO3);ZKp=Zja(15,"\n\nHere we go!\n\n");Z9r=Zja(4,":\n  ");Zjm=Zja(35,"8.  Change the C++ compiler options");
ZCn=Zja(29,"\n   Configuration file name: ");Zgm=Zja(31,"5.  Change the C linker options");Zzd=Zja(8,"set_item");Zcm=Zja(30,"1.  Change the C compiler type");
Zws=Zja(43,"Unexpected character in decimal ascii code.");Z4r=Zja(2,")\n");Zga=Zja(20,"SmartEiffelDirectory");ZXm=Zja(2,Zk3);ZTl=Zja(2,Zk3);
ZHk=Zja(2,":\n");Zsc=Zja(5,"count");Zar=Zja(2,Zl3);ZKl=Zja(2,". ");ZLl=Zja(2,Zn3);Zbd=Zja(14,"Minimum_double");Z6l=Zja(3,ZR3);Zuk=Zja(7,"Warning");
ZRe=Zja(6,Zh3);Zqm=Zja(4,"1]: ");Z6b=Zja(32,"Previous IDs reloaded (max_id = ");Zql=Zja(107,"\nSmartEiffel is already installed with the current options. Do you want to\ninstall SmartEiffel again\? [no] ");
ZAq=Zja(2,"]\n");Zhm=Zja(32,"6.  Change the C++ compiler type");ZJq=Zja(4,"2]: ");Zep=Zja(28,"default C++ compiler options");ZKq=Zja(4,"7]: ");
Zbr=Zja(3,"\n\? ");Zod=Zja(25,"print_all_run_time_stacks");ZWm=Zja(41,Z34);Zsm=Zja(4,"8]: ");Z6d=Zja(5,"low_8");Zdr=Zja(1,"\"");Z_f=Zja(5,"mieee");
Z5d=Zja(5,"lower");ZHo=Zja(1,"0");ZIo=Zja(1,"1");ZZd=Zja(5,"upper");Zgq=Zja(15,"-sedb -no_strip");ZSo=Zja(0,Zd3);ZSa=Zja(23,"NATIVE_ARRAY[CHARACTER]");
Z9o=Zja(26,"\n      C++ compiler path: ");Zjt();}void Zjt(void){Zda=Zja(15,"\" variable used");Zok=Zja(7,"------\n");Zij=Zja(19,"smarteiffel_options");
ZFh=Zja(16,Zx3);Zwr=Zja(2,Zm3);Z_m=Zja(2,Zk3);ZAe=Zja(24,"Selecting C++ compiler: ");Zdi=Zja(7,ZB3);ZCs=Zja(40,"Error inside multi-line manifest string.");
Zfk=Zja(11,"Fatal Error");Zun=Zja(7,"/bin/ls");ZDn=Zja(271,"\n\n1. Define the OS, the configuration file, the default directories and loadpaths\n2. Choose the C compilers and options for each C mode\n3. Display the configuration information\n4. Write the configuration file to disk\n5. Install SmartEiffel\n6. Exit\n\nh. Help\n\nYour choice [");
Zpm=Zja(47,"\n8.  Return to the previous menu\n\nYour choice [");Z7q=Zja(26,"Type <Enter> to continue.\n");ZBe=Zja(0,Zd3);ZCp=Zja(0,Zd3);
Z_o=Zja(7,ZQ3);Ziq=Zja(2854,"\nThis is the SmartEiffel installer.\n\nThis installer is here to help you. The options of the main menu are the six\nsteps that can be performed to install SmartEiffel. Once an action was perform-\ned, the menu proposes the next one.\n\nYou may have seen that, even starting the program, the menu already proposes\nsome option other than the first! Don\'t worry! It just means that the first\nsteps were automatically performed by the installer. You may always choose to\nchange them, by not choosing the default menu action.\n\nThe six steps are:\n\n- First, tell the installer which system SmartEiffel is to be installed upon;\n  also choose the directories SmartEiffel will be installed in, and the path\n  to the configuration file to be created. At last, you may add default\n  \"loadpath\" entries, meaning the files which describe where to find classes,\n  by default (this facility is here to help you insert third-party libraries).\n\n  Note that this step may be automatically performed. In that case, the OS was\n  automatically performe"
"d, the configuration file is given a default location,\n  the directories too, and the default loadpath files are those provided by\n  SmartEiffel.\n\n\n- Second, you may want to tell SmartEiffel which \"C modes\" are to be recognized.\n  SmartEiffel uses a C compiler as back-end; it means that you need a C compiler\n  installed on your machine.\n\n  The C modes are ways to tailor how the C compiler must behave; each C modes is\n  a C compiler, its path, and its options, and extra options for SmartEiffel to\n  use.\n\n  Let me explain in more details:\n\n  SmartEiffel disposes of many options to tailor how instrumented your execut-\n  able will be; wich assertions to check, should SmartEiffel add a debugger,\n  should SmartEiffel generate the \"debug\" statements, and so on.\n\n  Each \"assertion level\": boost, require_check, and so on, is associated with\n  a default C mode, named after the level. A typical configuration would associ-\n  ate the \"boost\" level with a highly optimizing C compiler (such as \"gcc -O3\");\n  it would, on the "
"other hand, tell SmartEiffel to no strip the executable in\n  debug mode (and why not adding the SmartEiffel Debugger) while asking the C\n  compiler to generate the symbol tables.\n\n\n- Third, you can verify what you entered in the two previous sections. If all is\n  ok, then you are ready to install SmartEiffel.\n\n\n- Fourth, the configuration file is to be written at its chosen location.\n\n\n- Fifth, the SmartEiffel tools are installed! They use the configuration file to\n  generate themselves; just before compiling the tools, you will be asked which\n  C mode should be used for that very task; the default mode is \"boost\".\n\n\n- Sixth, last but not least: you can now leave the installer; you are now ready\n  to enjoy SmartEiffel!\n\n\n        Happy SmartEiffelling :o)\n\n\nType <Enter> to go back to the menu: ");
Zcr=Zja(16,Zx3);ZNl=Zja(28,". Remove an extra loadpath\n\n");ZRd=Zja(13,"to_integer_16");ZTd=Zja(13,"to_integer_32");Z6q=Zja(7,Zs3);Ztq=Zja(7,"short: ");
Zrl=Zja(14,"OK, aborting.\n");ZTe=Zja(9,Z24);Zld=Zja(5,"print");Zqd=Zja(5,"put_0");Zrd=Zja(5,"put_1");Zdh=Zja(7,Zu3);Znl=Zja(8,"tutorial");
ZNk=Zja(16,"-clean -no_split");Zmf=Zja(6,"wcl386");Zus=Zja(5,"]foo\"");ZZp=Zja(2,Zo3);ZDf=Zja(0,Zd3);Zqq=Zja(635,"\n-- This section contains some general-purpose keys. They describe how is the\n-- SmartEiffel distribution arranged, and on which operating system it was\n-- installed.\n\n-- The \'bin\' key is the path to the directory that contains the SmartEiffel\n-- directory. It is used by \'compile\' to find \'compile_to_c\'.\n\n-- The \'sys\' directory is used to find the C and Java files used by the\n-- compilers.\n\n-- The \'short\' directory is used by the \'short\' utility to fotmat the output.\n\n-- The \'os\' key tells on which system SmartEiffel is installed on.\n\n-- At last, \'tag\' gives the version of install configuration (used only by the\n-- installer)\n\n");
ZQ9=Zja(10,"Renaming \"");Z8p=Zja(27,". Set the default compilers");Z1m=Zja(78,Zj3);Zri=Zja(30,"@linkit.com\ndelete linkit.com;");Zgj=Zja(13,"c_linker_path");
ZMd=Zja(5,"third");ZYo=Zja(13,ZZ3);Zlq=Zja(9,"Renaming ");Z9l=Zja(5,"\n*** ");Z2c=Zja(1,"*");ZKb=Zja(1,"&");Z8c=Zja(1,"+");Z0c=Zja(1,"-");
Zkt();}void Zkt(void){ZEe=Zja(0,Zd3);Zdc=Zja(1,"/");Z_b=Zja(1,"<");ZVb=Zja(1,"=");ZXb=Zja(1,">");ZIb=Zja(1,Zg3);Z1o=Zja(22,"\n   Short directory:  ");
Zac=Zja(1,"^");Z4o=Zja(24,"\n      C compiler path: ");Zfj=Zja(18,"c_compiler_options");ZTa=Zja(10,"INTEGER_16");ZJa=Zja(10,"INTEGER_32");
Z9f=Zja(8,Z04);ZUa=Zja(10,"INTEGER_64");ZJd=Zja(9,"std_input");Znd=Zja(20,"print_run_time_stack");Zxc=Zja(17,"collector_counter");ZQm=Zja(15,"C++ linker path");
Zbi=Zja(4,ZI3);Zmb=Zja(10,"EXCEPTIONS");ZLq=Zja(39,Zy3);Zff=Zja(9,"lcc-win32");Z0d=Zja(16,"is_expanded_type");Zzs=Zja(36,"Decimal CHARACTER code out of range.");
Z1d=Zja(8,"is_equal");Zch=Zja(11,Z44);Zjl=Zja(9,Zq3);Z3r=Zja(9,"default: ");ZAf=Zja(10,"\nlink/exe=");ZQa=Zja(6,"STRING");ZWn=Zja(0,Zd3);
Z3g=Zja(35,"\".\nCurrently handled system names:\n");Zgl=Zja(5,ZF3);ZDq=Zja(34,"1. Set the configuration file name");ZMf=Zja(4,ZK3);ZJo=Zja(55,"The configuration file is invalid; it will be ignored.\n");
Zvp=Zja(4,"germ");Zhp=Zja(170,"\nThis compiler has no known C++ capabilities.\n In order to compile C++ programs, please also pick a C++ compiler.\n\nType <Enter> if you don\'t know what this is all about.\n");
ZId=Zja(9,"std_error");Zko=Zja(6,"SE.CFG");ZNa=Zja(6,"DOUBLE");Zbo=Zja(24,"\n      C++ linker path: ");ZCe=Zja(0,Zd3);ZZg=Zja(57,"No default configuration file was found. Please set the \"");
Z7b=Zja(3,").\n");Z0r=Zja(4,"cpt ");Zzk=Zja(0,Zd3);ZOd=Zja(12,"to_character");ZMm=Zja(17,"C++ compiler path");Z7k=Zja(9,"invariant");
Zlt();}void Zlt(void){ZTh=Zja(18," Ignore=93,194,304");Zzf=Zja(45,ZA3);Zci=Zja(8,Z04);Zuq=Zja(4,"os: ");Zxb=Zja(9,"PROCEDURE");ZIa=Zja(7,"INTEGER");
Zfb=Zja(9,"ARGUMENTS");Zdp=Zja(26,"default C compiler options");ZVc=Zja(9,"generator");ZVm=Zja(2,Zk3);ZQn=Zja(57,"This directory does not exist; should I create it\? [Y\174""n] ");
ZIp=Zja(28,"\n  - C options:  (compiler) ");ZYn=Zja(105,"\n---------------------------------------------------------------------------\n   Configuration file name: ");
ZKd=Zja(10,"std_output");ZPd=Zja(9,"to_double");ZKm=Zja(17,"C++ compiler type");Zlb=Zja(10,"DOUBLE_REF");Zzn=Zja(59,"\n*** This section name is reserved. Please choose another.\n");
Zwb=Zja(9,"PREDICATE");ZBp=Zja(39,"\n*** Please choose an existant C mode.\n");Z2n=Zja(4,"root");ZMl=Zja(24,". Add an extra loadpath\n");
Zjf=Zja(2,Zo3);ZQf=Zja(2,".h");Zbp=Zja(42,"Please enter a valid number between 1 and ");Zwd=Zja(9,"Real_bits");Z8h=Zja(8,Zz3);Z0e=Zja(7,"Current");
ZGs=Zja(9,"The key \'");Znj=Zja(18,"cpp_linker_options");Zxl=Zja(12,Zf3);ZFm=Zja(49,Z14);Zwc=Zja(13,"collection_on");ZTo=Zja(0,Zd3);Zil=Zja(9,Zq3);
Zss=Zja(39,"Unexpected new line in manifest string.");Zmc=Zja(12,"Boolean_bits");Zrn=Zja(18,"s:startup-sequence");ZCq=Zja(78,Zj3);ZLm=Zja(27,"\n*** Unknown C++ compiler.\n");
ZGa=Zja(4,"NONE");ZDe=Zja(0,Zd3);ZHs=Zja(27,"\' is defined more than once");Zkm=Zja(30,"9.  Change the C++ linker path");ZSe=Zja(4,Z_3);
ZEm=Zja(13,"C linker path");Z2g=Zja(29,"Unknown system name in file\n\"");Zed=Zja(22,"Maximum_character_code");ZAb=Zja(7,"ROUTINE");ZAs=Zja(47,"Unexpected character in hexadecimal ascii code.");
Zmt();}void Zmt(void){ZLa=Zja(4,"REAL");ZXd=Zja(20,"truncated_to_integer");Z8t=Zja(4,"HOME");Zcd=Zja(12,"Minimum_real");ZKc=Zja(13,"die_with_code");
ZEq=Zja(27,"2. Set the operating system");Zfr=Zja(24,"                        ");ZYp=Zja(0,Zd3);Zcp=Zja(2,Zk3);ZDm=Zja(18,"C compiler options");
Z0o=Zja(22,"\n   Sys directory:    ");Z_l=Zja(14," loadpath.se\n\n");ZEb=Zja(4,"TYPE");Z4p=Zja(97,"\n---------------------------------------------------------------------------\nDefault compiler is ");
Zkj=Zja(17,"cpp_compiler_path");Z_g=Zja(66,"\" environment variable to a valid SmartEiffel configuration file.\n");Z1f=Zja(9,"SCOPTIONS");
Ztn=Zja(11,"/bin/ls.exe");Z7p=Zja(23,". Create a new C mode\n\n");ZPe=Zja(4,Zr3);Z2m=Zja(46,"Thank you for installing SmartEiffel. Enjoy!\n\n");
Zbe=Zja(4,"Void");Z6t=Zja(4,"USER");ZHc=Zja(7,"dispose");}void*ZOe(int ZSs,...){T44*m;Znt pa;T0**s;m=Zh(sizeof(*m));*m=M44;if(ZSs){s=Zh(ZSs*sizeof(*s));
m->Zs1=s;m->Z81=ZSs;m->Z53=1;m->Zt1=ZSs;Zot(pa,ZSs);while(ZSs--){*(s++)=Zpt(pa,T0*);}Zqt(pa);}else{m->Zs1=Zo;m->Z81=0;m->Z53=1;m->Zt1=0;
}return m;}T0*Z19(T0*C,T2 a1){T0*R;{Tid id=((T0*)C)->id;if(id<=44){R=(ZW7(((T44*)C),a1));}else{R=((((((T49*)C))->Zs1))[a1]);}}return R;
}T2 Z29(T0*C){T2 R;{Tid id=((T0*)C)->id;if(id<=44){R=(((((T44*)C))->Z53));}else{R=(ZQ5(0));}}return R;}T6 Z49(T0*C,T2 a1){T6 R;{Tid id=((T0*)C)->id;
if(id<=44){R=(T6)(ZX7(((T44*)C),a1));}else{R=(T6)(ZA8(((T49*)C),a1));}}return R;}void ZS7(T0*C,T0*a1){{Tid id=((T0*)C)->id;if(id<=44){
Z28(((T44*)C),a1);}else{Zv8(((T49*)C),a1);}}}T0*ZQ8(T0*C,T2 a1){T0*R;{Tid id=((T0*)C)->id;if(id<=65){R=(Zj8(((T65*)C),a1));}else{R=(Za9(((T69*)C),a1));
}}return R;}void Zwh(T0*C){{Tid id=((T0*)C)->id;if(id<=74){ZO8(((T74*)C));}else{Z_8(((ZL*)C));}}}T0*Zvh(T0*C){T0*R;{Tid id=((T0*)C)->id;
if(id<=74){R=(ZP8(((T74*)C)));}else{R=(Z09(((ZL*)C)));}}return R;}T6 Zsh(T0*C){T6 R;{Tid id=((T0*)C)->id;if(id<=74){R=(T6)(ZS8(((T74*)C)));
}else{R=(T6)(Z39(((ZL*)C)));}}return R;}void ZKo(T0*C){{Tid id=((T0*)C)->id;if(id<=74){((((T74*)(((T74*)C))))->Zg2)=(ZQ5(1));}else{Z59(((ZL*)C));
}}}T0*ZMs(T0*C){T0*R;{Tid id=((T0*)C)->id;if(id<=65){R=(ZC8(((T49*)(((((T65*)C))->Zd1)))));}else{R=(Z79(((T69*)C)));}}return R;}T2 Z8q(T0*C,T0*a1){
T2 R;{Tid id=((T0*)C)->id;if(id<=65){R=(Zd8(((T65*)C),a1));}else{R=(Z89(((T69*)C),a1));}}return R;}T0*Zym(T0*C,T0*a1){T0*R;{Tid id=((T0*)C)->id;
if(id<=65){R=(Zl8(((T65*)C),a1));}else{R=(Zc9(((T69*)C),a1));}}return R;}T0*Z9q(T0*C,T0*a1){T0*R;{Tid id=((T0*)C)->id;if(id<=65){R=(Zp8(((T65*)C),a1));
}else{R=(Zd9(((T69*)C),a1));}}return R;}void Zoj(T0*C,T0*a1,T0*a2){{Tid id=((T0*)C)->id;if(id<=65){Zu8(((T65*)C),a1,a2);}else{Zh9(((T69*)C),a1,a2);
}}}void ZXp(T0*C,T0*a1){{Tid id=((T0*)C)->id;if(id<=65){Zw8(((T65*)C),a1);}else{Zi9(((T69*)C),a1);}}}T0*Zqj(T0*C,T0*a1){T0*R;{Tid id=((T0*)C)->id;
if(id<=65){R=(Zy8(((T65*)C),a1));}else{R=(Zj9(((T69*)C),a1));}}return R;}
#ifdef __cplusplus
}
#endif

