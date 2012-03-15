#ifdef __cplusplus
extern"C"{
#endif
#ifdef __cplusplus
}
#endif
#include"compile_to_c.h"
#ifdef __cplusplus
extern"C"{
#endif
void ZhP(T0*a1){T0*ZYA2=Zo;T0*ZZA2=Zo;T0*Z_A2=Zo;T0*Z0B2=Zo;T0*ZdH=Zo;T0*ZKV1=Zo;T2 Zet=0;ZYA2=((((ZQ7*)a1))->Z4c);ZdH=(((ZZ3*)(((((ZQ7*)a1))->Znf)))->Zof);
if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){ZZA2=Z9G(ZYA2);Z_A2=((((ZQ7*)a1))->Zpc);Z0B2=ZeA((ZQ1*)(Z1B2()),ZZA2);
if((Z0B2)!=((void*)(Zo))){if(!(ZgD(((ZR6*)Z0B2),Z_A2))){ZhD(((ZR6*)Z0B2),a1,Z_A2);Z8H((T43*)(ZSG));}}else{{ZR6*n=((ZR6*)Zh(sizeof(*n)));
*n=Znj;{ZR6*C1=n;ZiD(C1,Zxt(193));}Z0B2=((T0*)n);}ZbD(((ZR6*)Z0B2),a1,Z_A2);Z9A((ZQ1*)(Z1B2()),Z0B2,ZZA2);Z8H((T43*)(ZSG));}if((Z3)(((((T43*)(ZSG))->ZQk))>=(ZGs(2)))){
Zet=(Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1)));while(!((Zet)==(ZGs(0)))){ZKV1=ZIL((ZZ3*)((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZUb))[(Zet)-(ZGs(1))]),a1);
Zet=(Z3)(((Zet))-(ZGs(1)));}}}}void ZJw2(T0*a1){T0*ZZA2=Zo;T0*Z_A2=Zo;T0*Z0B2=Zo;ZZA2=(((ZZ3*)(((((ZQ7*)a1))->Znf)))->ZUc);Z0B2=ZeA((ZQ1*)(Z1B2()),ZZA2);
if((Z0B2)!=((void*)(Zo))){Z_A2=((((ZQ7*)a1))->Zpc);ZfD(((ZR6*)Z0B2),Z_A2);}}T0*Z2B2(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));
*n=M38;ZdP=((T0*)n);}}}return ZdP;}T0*Z3B2=Zo;int Z4B2=0;T0*Z1B2(void){if(Z4B2==0){Z4B2=1;{{ZQ1*n=((ZQ1*)Zh(sizeof(*n)));*n=Zid;Z3B2=((T0*)n);
ZdA(n,(T2)(Zxt(1024)));}}}return Z3B2;}void ZKH(T0*a1,T0*a2){T0*ZYA2=Zo;T0*ZoX=Zo;if(ZXG(a1)){}else if(Z4V(a1)){}else{ZYA2=((((ZQ7*)a2))->Z4c);
ZoX=ZYA2;if(Zo!=(ZoX)){switch(((T0*)ZoX)->id){case 296:case 298:break;default:ZoX=Zo;}}if((ZoX)!=((void*)(Zo))){}else if(ZbL(ZYA2)){ZhP(a2);
}}}void ZaG(T80*C){Z5B2(C,Z6B2);Zv(ZGs(1));}void Z4H(T0*a1){{T0*b1=Z7B2;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(a1);Zmx((T7*)(Z2G),b1);}{T0*b1=Z8B2;
Zmx((T7*)(Z2G),b1);}}void Z5B2(T80*C,T0*a1){T2 Zet=0;T2 Z9B2=0;T3 Zex=0;T3 ZaB2=0;T81 Z4W={Zo,Zo,0};T6 Zd22=0;T0*ZNu2=Zo;(((void)((T38*)(ZbB2()))),Zzi1(ZcB2));
(((void)((T38*)(ZbB2()))),Zzi1(a1));(((void)((T38*)(ZbB2()))),Zuv1(((T3)'\072')));(((void)((T38*)(ZbB2()))),Zuv1(((T3)'\040')));Zet=ZGs(1);
while(!((Zet)==(ZGs(0)))){Zet=Zrx((T7*)(Z2G),ZdB2,(T2)(ZGs(1)));if((Zet)!=(ZGs(0))){{T7*C1=(T7*)(Z2G);T2 b1=Zet;Z_w(C1,b1,b1);}}}Zet=ZGs(1);
Z9B2=(Z3)(((ZGs(9)))+(((((T7*)a1))->Zdc)));while(!((Z3)((Zet)>((((T7*)(Z2G))->Zdc))))){ZaB2=Zex;Zex=((((T7*)(Z2G))->ZUb))[(Zet)-(ZGs(1))];
Zet=(Z3)(((Zet))+(ZGs(1)));if((Z3)((Z9B2)>(ZGs(60)))){if((T6)(((Zex)==(((T3)'\040')))||((T6)((Zex)==(((T3)'\n')))))){(((void)((T38*)(ZbB2()))),Zuv1(((T3)'\n')));
Z9B2=ZGs(0);}else{(((void)((T38*)(ZbB2()))),Zuv1(Zex));Z9B2=(Z3)(((Z9B2))+(ZGs(1)));}}else{(((void)((T38*)(ZbB2()))),Zuv1(Zex));{int z1=Zex;
switch(z1){case 10:Z9B2=ZGs(0);break;default:;Z9B2=(Z3)(((Z9B2))+(ZGs(1)));}}}}(((void)((T38*)(ZbB2()))),Zuv1(((T3)'\n')));while(!((Z3)(((((T82*)(ZQG()))->ZWb))<(ZGs(0)))))
{{T81 Zow;Z4W=(*(Zow=ZwF((T82*)(ZQG())),&Zow));}ZpF((T82*)(ZQG()));if((ZkU(&Z4W))==((void*)(Zo))){ZMr2(&Z4W);}else{ZNu2=(((T85*)(ZkU(&Z4W)))->Zse);
if(!(ZeB2(ZNu2))){ZMr2(&Z4W);}}Zd22=((T6)(0));while(!(Zd22)){Zet=ZuF((T82*)(ZQG()),Z4W);if(ZrF((T82*)(ZQG()),Zet)){ZsF((T82*)(ZQG()),Zet);
}else{Zd22=((T6)(1));}}}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));(((void)((T38*)(ZbB2()))),Zzi1(ZfB2));
}T6 ZgB2(void){T6 R=0;R=((T6)((T6)((((((T7*)(Z2G))->Zdc))==(ZGs(0)))&&((T6)((Z3)(((((T82*)(ZQG()))->ZWb))<(ZGs(0))))))));return R;}T0*ZbB2(void){
if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}void ZiU(T0*a1,T0*a2){ZMT(a1,ZhB2);ZMT(a2,Z0O);}T0*Z2G=Zo;
void Z3G(T80*C){Z5B2(C,ZiB2);(C->ZEg)=(Z3)(((((C)->ZEg)))+(ZGs(1)));if((Z3)((((C)->ZEg))>=(ZGs(6)))){(((void)((T38*)(ZbB2()))),Zzi1(ZcB2));
(((void)((T38*)(ZbB2()))),Zzi1(ZjB2));Zv(ZGs(1));}}void Zxq1(T0*a1){T6 Z8L=0;Z5G(((((ZD8*)a1))->ZCb));if((((((ZD8*)a1))->Zen))==(ZGs(2))){
{T0*b1=Zkp2;Zmx((T7*)(Z2G),b1);}Z8L=((T6)(1));}else if((((((ZD8*)a1))->Zen))==(ZGs(3))){{T0*b1=Zlp2;Zmx((T7*)(Z2G),b1);}Z8L=((T6)(1));
}if(Z8L){{T0*b1=Z1G(2,ZBn);Zmx((T7*)(Z2G),b1);}}{T0*b1=((((ZD8*)a1))->Zse);Zmx((T7*)(Z2G),b1);}if(Z8L){{T3 b1=((T3)'\042');Zgt((T7*)(Z2G),b1);
}}}T0*ZkB2=Zo;int ZlB2=0;T0*ZQG(void){if(ZlB2==0){ZlB2=1;{{T82*n=((T82*)Zh(sizeof(*n)));*n=M82;ZkB2=((T0*)n);ZxF(n,(T2)(ZGs(16)));}}}
return ZkB2;}void ZMT(T0*a1,T0*a2){{T0*b1=ZmB2;Zmx((T7*)(Z2G),b1);}if(ZyW(a1)){{T0*b1=Z9G(a1);Zmx((T7*)(Z2G),b1);}}else{{T0*b1=ZcT(a1);
Zmx((T7*)(Z2G),b1);}}{T0*b1=a2;Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZrP(a1),&Zow)));}}void Z5G(T81 a1){if((((a1).Zxb))==(ZGs(0))){
}else{ZvF((T82*)(ZQG()),a1);}}void Zj_(T0*a1){Z5G(((((ZD8*)a1))->ZCb));{T0*b1=ZVl1;Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)a1))->Zse);Zmx((T7*)(Z2G),b1);
}{T0*b1=ZnB2;Zmx((T7*)(Z2G),b1);}}void ZPG(T80*C){if(((C)->ZGg)){((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
}else{Z5B2(C,ZoB2);}(C->ZFg)=(Z3)(((((C)->ZFg)))+(ZGs(1)));}T0*ZpB2=Zo;int ZqB2=0;T0*ZrB2(void){if(ZqB2==0){ZqB2=1;{{ZG9*n=((ZG9*)Zh(sizeof(*n)));
*n=Zfm;ZpB2=((T0*)n);ZhF(n,(T2)(Zxt(4096)));}}}return ZpB2;}void Zeo2(T0*a1,T0*a2){T6 ZKF1=0;T0*ZsB2=Zo;T2 ZXw=0;ZKF1=((T6)(ZtB2(a2,a1)));
ZsB2=((((T93*)a2))->ZZm);Zmx(((T7*)a1),ZuB2);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){Zmx(((T7*)a1),ZvB2);}ZXw=((((T95*)ZsB2))->Zdc);
Z6t(ZXw,a1);Zgt(((T7*)a1),((T3)'\054'));if((ZXw)==(ZGs(0))){Zmx(((T7*)a1),Z4T);}else{Zgt(((T7*)a1),((T3)'s'));Zmx(((T7*)a1),((((T93*)a2))->Z0n));
}Zgt(((T7*)a1),((T3)'\054'));if((((((T95*)ZsB2))->Zvl))==((void*)(Zo))){ZXw=ZGs(0);}else{ZXw=(Z3)((((((T96*)(((((T95*)ZsB2))->Zvl)))->ZWb)))+(ZGs(1)));
}Z6t(ZXw,a1);Zgt(((T7*)a1),((T3)'\054'));if((ZXw)!=(ZGs(0))){Zmx(((T7*)a1),ZwB2);Zmx(((T7*)a1),((((T93*)a2))->Z0n));Zmx(((T7*)a1),ZxB2);
Zmx(((T7*)a1),((((T93*)a2))->Z0n));}else{Zmx(((T7*)a1),ZyB2);}Zgt(((T7*)a1),((T3)'\051'));if(ZKF1){Zgt(((T7*)a1),((T3)'\051'));}}T0*ZzB2=Zo;
T0*Zvo2(T0*a1){T0*R=Zo;ZWw((T7*)(ZAB2),ZBB2);Zmx((T7*)(ZAB2),((((T93*)a1))->Z0n));while(!(!(Z5C((ZL4*)(ZWy2()),ZAB2)))){Zgt((T7*)(ZAB2),((T3)'a'));
}R=Z7t((T7*)(ZAB2));Z6C((ZL4*)(ZWy2()),a1,R);return R;}void ZCB2(T3 a1,T0*a2){if((a1)==(((T3)'\n'))){Zgt(((T7*)a2),((T3)'\134'));Zgt(((T7*)a2),((T3)'n'));
}else if((a1)==(((T3)'\134'))){Zgt(((T7*)a2),((T3)'\134'));Zgt(((T7*)a2),((T3)'\134'));}else if((a1)==(((T3)'\077'))){Zgt(((T7*)a2),((T3)'\134'));
Zgt(((T7*)a2),((T3)'\077'));}else if((a1)==(((T3)'\042'))){Zgt(((T7*)a2),((T3)'\134'));Zgt(((T7*)a2),((T3)'\042'));}else if((a1)==(((T3)'\047'))){
Zgt(((T7*)a2),((T3)'\134'));Zgt(((T7*)a2),((T3)'\047'));}else if((T6)(((Z2)((ZDs(a1))<(ZGs(32))))||((T6)((Z2)((ZGs(122))<(ZDs(a1))))))){
Zgt(((T7*)a2),((T3)'\134'));ZRs((ZFs)(ZDs(a1)),a2);Zmx(((T7*)a2),ZDB2);}else{Zgt(((T7*)a2),a1);}}T0*ZEB2=Zo;int ZFB2=0;T0*ZGB2(void){
if(ZFB2==0){ZFB2=1;{{ZO3*n=((ZO3*)Zh(sizeof(*n)));*n=ZPe;ZEB2=((T0*)n);ZRA(n,(T2)(Zxt(4096)));}}}return ZEB2;}void ZHB2(T6 a1){T2 Zet=0;
T2 Z3x=0;T2 ZIB2=0;T0*ZoL1=Zo;T0*ZsB2=Zo;T98 ZJB2=Zo;T0*ZKB2=Zo;T0*ZLB2=Zo;if(!(a1)){ZgM((Z84*)(ZkH),ZMB2);}ZXT((Z84*)(ZkH));ZgM((Z84*)(ZkH),ZNB2);
Zet=ZGs(1);while(!((Z3)((Zet)>((((ZO3*)(ZGB2()))->Zdc))))){ZoL1=ZPA((ZO3*)(ZGB2()),Zet);if(((((T93*)ZoL1))->ZYm)){ZsB2=((((T93*)ZoL1))->ZZm);
ZIB2=((((T95*)ZsB2))->Zdc);if((Z3)((ZIB2)>(ZGs(0)))){ZWw((T7*)(ZAB2),ZOB2);Zmx((T7*)(ZAB2),((((T93*)ZoL1))->Z0n));ZNA2((Z84*)(ZkH),ZAB2,ZIB2);
ZIB2=(Z3)(((ZIB2))-(ZGs(1)));ZJB2=((((T95*)ZsB2))->ZUb);Z3x=ZGs(0);while(!((Z3)((Z3x)>(ZIB2)))){ZDM((Z84*)(ZkH),(T11)((ZJB2)[Z3x]));Z3x=(Z3)(((Z3x))+(ZGs(1)));
if((Z3)((Z3x)<=(ZIB2))){ZdL((Z84*)(ZkH),((T3)'\054'));}}ZgM((Z84*)(ZkH),ZPB2);}ZKB2=((((T95*)ZsB2))->Zvl);if((T6)(((ZKB2)!=((void*)(Zo)))&&((T6)((Z3)(((Z3)(((((((T96*)ZKB2))->ZWb)))+(ZGs(1))))>(ZGs(0))))))){
ZWw((T7*)(ZAB2),ZQB2);Zmx((T7*)(ZAB2),((((T93*)ZoL1))->Z0n));ZNA2((Z84*)(ZkH),ZAB2,ZIB2);Z3x=ZGs(0);while(!((Z3)((Z3x)>(((((T96*)ZKB2))->ZWb)))))
{ZDM((Z84*)(ZkH),(T11)((((((T96*)ZKB2))->ZUb))[Z3x]));Z3x=(Z3)(((Z3x))+(ZGs(1)));if((Z3)((Z3x)<=(((((T96*)ZKB2))->ZWb)))){ZdL((Z84*)(ZkH),((T3)'\054'));
}}ZgM((Z84*)(ZkH),ZPB2);}ZLB2=((((T95*)ZsB2))->Zul);if((T6)(((ZLB2)!=((void*)(Zo)))&&((T6)((Z3)(((Z3)(((((((T99*)ZLB2))->ZWb)))+(ZGs(1))))>(ZGs(0))))))){
ZWw((T7*)(ZAB2),ZRB2);Zmx((T7*)(ZAB2),((((T93*)ZoL1))->Z0n));ZNA2((Z84*)(ZkH),ZAB2,ZIB2);Z3x=ZGs(0);while(!((Z3)((Z3x)>(((((T99*)ZLB2))->ZWb)))))
{ZDM((Z84*)(ZkH),(T11)((((((T99*)ZLB2))->ZUb))[Z3x]));Z3x=(Z3)(((Z3x))+(ZGs(1)));if((Z3)((Z3x)<=(((((T99*)ZLB2))->ZWb)))){ZdL((Z84*)(ZkH),((T3)'\054'));
}}ZgM((Z84*)(ZkH),ZPB2);}}else if((((((T93*)ZoL1))->Z_m))!=((void*)(Zo))){ZWw((T7*)(ZAB2),ZSB2);Zmx((T7*)(ZAB2),((((T93*)ZoL1))->Z0n));
((((T7*)((T7*)(ZzB2))))->Zdc)=(ZGs(0));{T0*b1=((((T93*)ZoL1))->Zse);T0*b2=ZzB2;Z9o2(((((T7*)b1))->Zdc),((((T7*)b1))->ZUb),b2);}ZvS((Z84*)(ZkH),ZAB2,ZzB2);
}Zet=(Z3)(((Zet))+(ZGs(1)));}ZZT((Z84*)(ZkH));}void ZTB2(Zc5*C,T6 a1){T2 Zet=0;T2 Z3x=0;T2 ZUB2=0;T2 ZVB2=0;T2 ZN_=0;T0*ZoL1=Zo;T6 Zz91=0;
T0*ZJH=Zo;Zz91=((T6)((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))));if(!((((T43*)(ZSG))->ZXk))){ZVB2=(((ZL4*)(ZWy2()))->Zdc);ZPv1((T38*)(ZWB2()),ZXB2,ZVB2);
if((Z3)((ZVB2)>(ZGs(0)))){Zet=ZGs(1);while(!((Z3)((Zet)>(ZVB2)))){ZoL1=Z2C((ZL4*)(ZWy2()),Zet);ZWw((T7*)(ZAB2),ZYB2);Zmx((T7*)(ZAB2),((((T93*)ZoL1))->Z1n));
Znw2((Z84*)(ZkH),ZAB2);Zet=(Z3)(((Zet))+(ZGs(1)));}}}ZZB2((T6)(a1));if((((T43*)(ZSG))->ZXk)){ZdS((Z84*)(ZkH),Z_B2,Z0C2);}else if((Z3)((ZVB2)>(ZGs(0)))){
Zet=ZGs(1);ZUB2=ZGs(1);while(!((T6)(((Z3)((ZUB2)>(ZGs(1))))&&((T6)((Z3)((Zet)>(ZVB2))))))){ZWw((T7*)(ZAB2),ZHR);Zgt((T7*)(ZAB2),((T3)'\040'));
Zmx((T7*)(ZAB2),ZXy2);Z6t(ZUB2,ZAB2);Zmx((T7*)(ZAB2),ZxS);((((T7*)((T7*)(ZzB2))))->Zdc)=(ZGs(0));if((T6)((Zz91)&&((T6)((((C)->Zfh))!=((void*)(Zo)))))){
Zmx((T7*)(ZzB2),Z1G(146,"se_frame_descriptor fd=\173""\"<global-once>\",0,0,\"\",1\175"";\nse_dump_stack ds;\nds.fd=&fd;\nds.p=0;\nds.caller=NULL;\nds.exception_origin=NULL;\nds.locals=NULL;\n"));
}Z3x=ZGs(50);while(!((T6)(((Z3x)==(ZGs(0)))||((T6)((Z3)((Zet)>(ZVB2))))))){ZoL1=Z2C((ZL4*)(ZWy2()),Zet);Zmx((T7*)(ZzB2),((((T93*)ZoL1))->Z1n));
Zgt((T7*)(ZzB2),((T3)'\075'));if(((((T93*)ZoL1))->ZYm)){Zeo2(ZzB2,ZoL1);}else{Zfo2(ZzB2,ZoL1);}Zgt((T7*)(ZzB2),((T3)'\073'));Zgt((T7*)(ZzB2),((T3)'\n'));
Z3x=(Z3)(((Z3x))-(ZGs(1)));Zet=(Z3)(((Zet))+(ZGs(1)));}ZUB2=(Z3)(((ZUB2))+(ZGs(1)));if((Z3)((Zet)<=(ZVB2))){Zmx((T7*)(ZzB2),ZXy2);Z6t(ZUB2,ZzB2);
Zmx((T7*)(ZzB2),ZYy2);}Zms1((Z84*)(ZkH),(T2)(ZGs(3)));ZdS((Z84*)(ZkH),ZAB2,ZzB2);}}if((((C)->Zfh))!=((void*)(Zo))){ZJH=Z_G((((ZQ7*)(((C)->Zfh)))->Z4c));
ZN_=((((ZZ3*)ZJH))->_id);ZWw((T7*)(ZAB2),Z1G(10,"T0*se_ums("));if(Zz91){Zmx((T7*)(ZAB2),Z1G(21,ZPp));}Zmx((T7*)(ZAB2),Z1G(56,"int32_t c,uint16_t*s,int32_t sc,int16_t*lsv,int32_t*lsi)"));
((((T7*)((T7*)(ZzB2))))->Zdc)=(ZGs(0));Zgt((T7*)(ZzB2),((T3)'T'));Z6t(ZN_,ZzB2);Zmx((T7*)(ZzB2),Z1G(5,"*us;\n"));if(Zz91){Zmx((T7*)(ZzB2),Z1G(117,"se_frame_descriptor fd=\173""\"<unicode-initialization>\",0,0,\"\",1\175"";\nse_dump_stack ds;\nds.fd=&fd;\nds.p=0;\nds.caller=caller;\n"));
}{Zj8*C1=(Zj8*)(Z1C2());T0*b1=Z2C2;T0*b2=ZzB2;T0*b3=ZJH;ZTr1(C1,b1,b2,b3,Zo);}Zgt((T7*)(ZzB2),((T3)'r'));Z6t(ZN_,ZzB2);Zmx((T7*)(ZzB2),Z1G(20,"manifest_initialize("));
if(Zz91){Zmx((T7*)(ZzB2),Z1G(4,Zcp));}Zmx((T7*)(ZzB2),Z1G(35,"us,c,s,sc,lsv,lsi);return (T0*)us;\n"));ZdS((Z84*)(ZkH),ZAB2,ZzB2);}}T0*ZWB2(void){
if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}T0*Z1C2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));
*n=ZOk;ZMM=((T0*)n);}}}return ZMM;}void Z3C2(T6 a1){ZxI1((Zj8*)(Z1C2()),ZzB2,(T6)(a1));Zmx((T7*)(ZzB2),Z4C2);ZvI1((Zj8*)(Z1C2()),ZzB2,(T6)(a1));
Zmx((T7*)(ZzB2),Z5C2);ZdS((Z84*)(ZkH),ZAB2,ZzB2);}void Z6C2(T2 a1){ZWw((T7*)(ZAB2),ZHR);Zgt((T7*)(ZAB2),((T3)'\040'));Zmx((T7*)(ZAB2),Z7C2);
Z6t(a1,ZAB2);Zmx((T7*)(ZAB2),ZxS);ZIM((Z84*)(ZkH),ZAB2);}void Zuo2(T0*a1){T0*Z8C2=Zo;T0*Z9C2=Zo;if((((((T93*)a1))->Z0n))==((void*)(Zo))){
Z9C2=ZSA((ZO3*)(ZGB2()),a1);if((Z9C2)==((void*)(Zo))){((((T7*)((T7*)(ZAB2))))->Zdc)=(ZGs(0));ZFt((((T87*)(((((((T93*)a1))->ZCb)).Zvb)))->_id),ZAB2);
Zgt((T7*)(ZAB2),((T3)'\137'));Z6t(ZLA(((T93*)a1)),ZAB2);while(!(!(ZfF((ZG9*)(ZrB2()),ZAB2)))){Zgt((T7*)(ZAB2),((T3)'a'));}Z8C2=Z7t((T7*)(ZAB2));
((((T93*)(((T93*)a1))))->Z0n)=(Z8C2);ZgF((ZG9*)(ZrB2()),Z8C2);ZKA((ZO3*)(ZGB2()),a1,a1);}else{Zxo2(((T93*)a1),Z9C2);}}}void Z9J1(Zc5*C){
T2 Zet=0;T2 ZVB2=0;T2 ZaC2=0;T2 ZUB2=0;T2 ZN_=0;T2 ZbC2=0;T0*ZoL1=Zo;ZVB2=(((ZL4*)(ZWy2()))->Zdc);ZUB2=ZGs(1);Z6C2(ZUB2);Zet=ZGs(1);if((((C)->Zfh))!=((void*)(Zo))){
ZbC2=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Zfh)))->Z4c))))->_id);}while(!((Z3)((Zet)>(ZVB2)))){if((Z3)((ZaC2)>(Zxt(300)))){ZaC2=ZGs(0);ZUB2=(Z3)(((ZUB2))+(ZGs(1)));
ZgM((Z84*)(ZkH),Z7C2);ZDM((Z84*)(ZkH),(T11)(ZUB2));ZgM((Z84*)(ZkH),ZYy2);ZgM((Z84*)(ZkH),ZmM);Z6C2(ZUB2);}ZoL1=Z2C((ZL4*)(ZWy2()),Zet);
ZgM((Z84*)(ZkH),ZaT);if(((((T93*)ZoL1))->ZYm)){ZN_=ZbC2;}else{ZN_=ZGs(7);}ZDM((Z84*)(ZkH),(T11)(ZN_));ZgM((Z84*)(ZkH),ZcC2);ZDM((Z84*)(ZkH),(T11)(ZN_));
ZgM((Z84*)(ZkH),ZdC2);ZgM((Z84*)(ZkH),((((T93*)ZoL1))->Z1n));ZgM((Z84*)(ZkH),ZbR);ZaC2=(Z3)(((ZaC2))+(ZGs(1)));Zet=(Z3)(((Zet))+(ZGs(1)));
}ZgM((Z84*)(ZkH),ZmM);}void Z9o2(T2 a1,T9 a2,T0*a3){T2 ZeC2=0;T2 Zet=0;Zgt(((T7*)a3),((T3)'\042'));while(!((Z3)((Zet)>=(a1)))){ZCB2((a2)[Zet],a3);
Zet=(Z3)(((Zet))+(ZGs(1)));ZeC2=(Z3)(((ZeC2))+(ZGs(1)));if((Z3)((ZeC2)>(Zxt(1024)))){Zmx(((T7*)a3),ZfC2);ZeC2=ZGs(0);}}Zgt(((T7*)a3),((T3)'\042'));
}void Zfo2(T0*a1,T0*a2){T6 ZKF1=0;ZKF1=((T6)(ZtB2(a2,a1)));Zmx(((T7*)a1),ZgC2);Z6t(((((T7*)(((((T93*)a2))->Zse))))->Zdc),a1);Zgt(((T7*)a1),((T3)'\054'));
if((((((T93*)a2))->Z_m))==((void*)(Zo))){{T0*b1=((((T93*)a2))->Zse);T0*b2=a1;Z9o2(((((T7*)b1))->Zdc),((((T7*)b1))->ZUb),b2);}}else{Zgt(((T7*)a1),((T3)'s'));
Zmx(((T7*)a1),((((T93*)a2))->Z0n));}Zgt(((T7*)a1),((T3)'\051'));if(ZKF1){Zgt(((T7*)a1),((T3)'\051'));}}T6 ZtB2(T0*a1,T0*a2){T6 R=0;T81
ZqO={Zo,Zo,0};if(((((T93*)a1))->ZXm)){}else if((((T89*)(ZPM))->Z5f)){R=((T6)(1));ZqO=((((T93*)a1))->ZCb);Zmx(((T7*)a2),ZhC2);{T0*b1=((((T93*)a1))->Zse);
T0*b2=a2;Z9o2(((((T7*)b1))->Zdc),((((T7*)b1))->ZUb),b2);}Zmx(((T7*)a2),ZiC2);Z6t(Zrd1(&ZqO),a2);Zmx(((T7*)a2),ZjC2);Z6t(Zsd1(&ZqO),a2);
Zgt(((T7*)a2),((T3)'\040'));Zmx(((T7*)a2),Zl02(&ZqO));Zmx(((T7*)a2),ZkC2);}return R;}T0*ZlC2=Zo;int ZmC2=0;T0*ZWy2(void){if(ZmC2==0){ZmC2=1;{
{ZL4*n=((ZL4*)Zh(sizeof(*n)));*n=ZTg;ZlC2=((T0*)n);Z8C(n,(T2)(Zxt(4096)));}}}return ZlC2;}void ZZB2(T6 a1){ZWw((T7*)(ZAB2),ZnC2);ZWw((T7*)(ZzB2),ZoC2);
Z3C2((T6)(a1));ZWw((T7*)(ZAB2),ZpC2);ZWw((T7*)(ZzB2),ZqC2);Z3C2((T6)(a1));if((((T43*)(ZSG))->ZXk)){ZdS((Z84*)(ZkH),ZrC2,ZsC2);}}T0*ZAB2=Zo;
T0*ZGv1(T0*a1){T0*R=Zo;T8 Z4W=Zo;T8 ZtC2=Zo;Z4W=ZQx(((T7*)a1));Z4W=ZuC2(Z4W);if((Z4W)!=(ZtC2)){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zmt(n,Z4W);
R=((T0*)n);}}return R;}void Zy_(T81 a1,T0*a2,T0*a3){T0*ZPi1=Zo;T0*ZvC2=Zo;T0*ZMd1=Zo;T0*Z9A2=Zo;T0*ZaA2=Zo;T0*ZAs1=Zo;Z9A2=ZnH(a2);ZaA2=ZnH(a3);
if((T6)((ZMR(a2))&&((T6)(ZbL(a3))))){ZdW(a1);}ZvC2=Z9G(Z9A2);if((ZvC2)==((void*)(ZjI))){}else if((ZvC2)!=((void*)(Z9G(ZaA2)))){if(ZqU(Z9A2)){
if(ZbL(ZaA2)){ZAs1=ZT01(Z9A2,ZaA2);ZPi1=ZIc2(Z9A2,ZAs1);Zy_(a1,ZAs1,ZaA2);}}else if(ZqU(ZaA2)){}else{ZMd1=ZNd1(Z9A2);ZLd1(((Z64*)ZMd1),a1,ZaA2);
}}}T0*ZwC2=Zo;void ZxC2(T81 a1,T0*a2){T0*ZtW=Zo;T2 Zet=0;T0*ZyC2=Zo;if(!(ZqU(a2))){ZtW=Z9G(ZnH(a2));if(!(Z8E((Z38*)(ZzC2()),ZtW))){Zet=ZGs(1);
while(!((Z3)((Zet)>((((Z38*)(ZzC2()))->Zdc))))){ZyC2=Z5E((Z38*)(ZzC2()),Zet);Zy_(a1,a2,ZyC2);Zy_(a1,ZyC2,a2);Zet=(Z3)(((Zet))+(ZGs(1)));
}Z9E((Z38*)(ZzC2()),a2,ZtW);}}}void ZcA2(T0*a1,T0*a2,T0*a3){T0*ZJH=Zo;ZAC2(a1,a2,a3);if(ZqU(a3)){if(ZqU(a2)){ZWw((T7*)(ZwC2),ZBC2);Z6t(ZEM(a2),ZwC2);
Zmx((T7*)(ZwC2),ZCC2);Z6t(ZEM(a3),ZwC2);Zmx((T7*)(ZwC2),ZDC2);ZWR1((Z84*)(ZkH),ZwC2);}else{ZIM((Z84*)(ZkH),ZwC2);ZWw((T7*)(ZwC2),ZEC2);
Z6U(a2,ZwC2);Zmx((T7*)(ZwC2),ZFC2);ZgM((Z84*)(ZkH),ZwC2);}}else{ZIM((Z84*)(ZkH),ZwC2);ZdL((Z84*)(ZkH),((T3)'T'));ZDM((Z84*)(ZkH),(T11)(ZEM(a3)));
ZdL((Z84*)(ZkH),((T3)'\052'));ZJH=Z_G(a3);Zmq1((Zj8*)(ZGC2()),ZHC2,ZJH);if(ZIG(a2)){ZgM((Z84*)(ZkH),ZIC2);}else{ZgM((Z84*)(ZkH),ZJC2);
if(ZhS(((ZZ3*)ZJH))){ZgM((Z84*)(ZkH),ZKC2);}ZgM((Z84*)(ZkH),ZLC2);}ZgM((Z84*)(ZkH),ZMC2);}}T0*ZNd1(T0*a1){T0*R=Zo;T0*ZPi1=Zo;ZPi1=Z9G(a1);
R=ZnF((ZK9*)(ZNC2()),ZPi1);if((R)==((void*)(Zo))){{Z64*n=((Z64*)Zh(sizeof(*n)));*n=Zsf;ZQd1(n,a1);R=((T0*)n);}ZiF((ZK9*)(ZNC2()),R,ZPi1);
}return R;}T0*ZOC2=Zo;int ZPC2=0;T0*ZNC2(void){if(ZPC2==0){ZPC2=1;{{ZK9*n=((ZK9*)Zh(sizeof(*n)));*n=Zhm;ZOC2=((T0*)n);ZmF(n,(T2)(Zxt(512)));
}}}return ZOC2;}void ZLV1(T0*a1,T0*a2){T0*ZQC2=Zo;T0*ZRC2=Zo;T81 Z9P={Zo,Zo,0};T0*ZSC2=Zo;T0*ZTC2=Zo;T2 Zet=0;T0*ZPi1=Zo;ZQC2=ZiH(a1);
if((ZQC2)!=((void*)(Zo))){ZRC2=ZnH(ZiH(a2));if(ZJG(ZRC2,ZQC2)){Zy_(Z9P,ZRC2,ZQC2);}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
}}ZSC2=ZAP(a1);if((ZSC2)!=((void*)(Zo))){ZTC2=ZAP(a2);Zet=Zjy(((Zl2*)(((((Zz6*)ZSC2))->Zie))));while(!((Zet)==(ZGs(0)))){ZQC2=ZnH(Z8a1(((Zz6*)ZSC2),Zet));
ZRC2=ZnH(Z8a1(((Zz6*)ZTC2),Zet));if((T6)((ZbL(ZQC2))&&((T6)(ZqU(ZRC2))))){ZPi1=ZIc2(ZQC2,ZRC2);}else{Zy_(Z9P,ZRC2,ZQC2);Zy_(Z9P,ZQC2,ZRC2);
}Zet=(Z3)(((Zet))-(ZGs(1)));}}}void ZAC2(T0*a1,T0*a2,T0*a3){((((T7*)((T7*)(ZwC2))))->Zdc)=(ZGs(0));ZmW(a3,ZwC2);Zgt((T7*)(ZwC2),((T3)'\040'));
Zmx((T7*)(ZwC2),a1);Zgt((T7*)(ZwC2),((T3)'\050'));Z6U(a2,ZwC2);Zmx((T7*)(ZwC2),ZUC2);ZvP((T38*)(ZVC2()),ZWC2);ZvP((T38*)(ZVC2()),Z9G(a2));
ZvP((T38*)(ZVC2()),ZXC2);ZvP((T38*)(ZVC2()),Z9G(a3));ZvP((T38*)(ZVC2()),ZYC2);ZvP((T38*)(ZVC2()),ZwC2);ZWP((T38*)(ZVC2()),((T3)'\042'));
ZWP((T38*)(ZVC2()),((T3)'\n'));}T0*ZKG(T0*a1,T0*a2){T0*R=Zo;T0*Z9A2=Zo;T0*ZZC2=Zo;T0*Z_C2=Zo;T0*ZvC2=Zo;T0*Z0D2=Zo;Z9A2=ZGH(a1);ZvC2=Z9G(Z9A2);
Z0D2=Z9G(a2);if((ZvC2)==((void*)(Z0D2))){R=a1;}else if(ZbL(Z9A2)){if(ZbL(a2)){R=a1;}else{{Z89*n=((Z89*)Zh(sizeof(*n)));*n=ZKl;ZBc2(n,a1,a2);
R=((T0*)n);}}}else if(ZbL(a2)){{Z89*n=((Z89*)Zh(sizeof(*n)));*n=ZKl;ZBc2(n,a1,ZT01(Z9A2,a2));R=((T0*)n);}}else if((T6)((ZzT(a2))&&((T6)(ZzT(Z9A2))))){
{Z89*n=((Z89*)Zh(sizeof(*n)));*n=ZKl;ZBc2(n,a1,a2);R=((T0*)n);}}else if((T6)((ZqT(a2))&&((T6)(ZzT(Z9A2))))){{Z89*n=((Z89*)Zh(sizeof(*n)));
*n=ZKl;ZBc2(n,a1,a2);R=((T0*)n);}}else if(ZbU(a2)){if((T6)((ZzT(Z9A2))||((T6)(ZqT(Z9A2))))){{Z89*n=((Z89*)Zh(sizeof(*n)));*n=ZKl;ZBc2(n,a1,a2);
R=((T0*)n);}}else{R=a1;}}else if(ZMR(a2)){ZZC2=ZnH(Z9A2);if(Zo!=(ZZC2)){switch(((T0*)ZZC2)->id){case 304:case 306:break;default:ZZC2=Zo;
}}Z_C2=ZnH(a2);if(Zo!=(Z_C2)){switch(((T0*)Z_C2)->id){case 304:case 306:break;default:Z_C2=Zo;}}if((ZQX(ZZC2))!=(ZQX(Z_C2))){{Z89*n=((Z89*)Zh(sizeof(*n)));
*n=ZKl;ZBc2(n,a1,a2);R=((T0*)n);}}else{R=a1;}}else{R=a1;}return R;}T0*ZGC2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));*n=ZOk;
ZMM=((T0*)n);}}}return ZMM;}T0*ZVC2(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}T6 ZZN(T0*a1,T0*a2,T0*a3,T6
a4){T6 R=0;T0*ZRU=Zo;T0*ZJk1=Zo;T0*ZKk1=Zo;T0*ZsL=Zo;T0*ZtL=Zo;if((ZcT(a1))==((void*)(ZcT(a2)))){R=((T6)(1));}else{ZRU=((((ZZ3*)a3))->Z4c);
ZJk1=ZnH(ZxP(a1,ZRU));ZKk1=ZnH(ZxP(a2,ZRU));if((Z9G(ZKk1))==((void*)(Z9G(ZJk1)))){R=((T6)(1));}else{R=((T6)(ZJG(ZKk1,ZJk1)));if(R){Z1D2((T6)(a4),ZJk1,ZKk1);
}else if(Zh_(a1)){((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));if(ZJG(ZJk1,ZKk1)){{T81 Zow;ZsL=(((*(Zow=ZrP(a1),&Zow))).Zvb);
}ZtL=ZsO(a2);R=((T6)((T6)(((ZtL)==((void*)(ZsL)))||((T6)(ZxM(((T87*)ZtL),ZsL))))));if(!(R)){{T81 Zow;Z5G((*(Zow=ZrP(a1),&Zow)));}ZMT(a2,Z1G(54," does not conforms to \"like Current\" written in class "));
{T0*b1=(((T85*)(((((T87*)ZsL))->Zpc)))->Zse);Zmx((T7*)(Z2G),b1);}{T3 b1=((T3)'\056');Zgt((T7*)(Z2G),b1);}}}if(R){Z1D2((T6)(a4),ZJk1,ZKk1);
}}}}return R;}T0*Z2D2=Zo;int Z3D2=0;T0*ZbA2(void){if(Z3D2==0){Z3D2=1;{{Z96*n=((Z96*)Zh(sizeof(*n)));*n=Zyi;Z2D2=((T0*)n);{Z96*C1=n;ZRC(C1,Zxt(193));
}}}}return Z2D2;}T0*Z4D2(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);
ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);
ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);
ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);
ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);
ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);
ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);
ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);
ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);
ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);
ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);
ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);
ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);
ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);
ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T0*ZIc2(T0*a1,T0*a2){T0*R=Zo;T0*Z9A2=Zo;T0*ZaA2=Zo;T0*ZPi1=Zo;Z9A2=ZnH(a1);ZaA2=ZnH(a2);if(ZqU(Z9A2)){
if(ZbL(ZaA2)){ZaA2=ZT01(Z9A2,ZaA2);}}else if(ZqU(ZaA2)){if(ZbL(Z9A2)){if(ZzT(ZaA2)){Z9A2=ZT01(ZaA2,Zo);}else{Z9A2=ZT01(ZaA2,Z9A2);}}}
ZPi1=Z5D2;((((T7*)(((T7*)ZPi1))))->Zdc)=(ZGs(0));Zgt(((T7*)ZPi1),((T3)'T'));Z6t(ZEM(Z9A2),ZPi1);Zmx(((T7*)ZPi1),Z6D2);Z6t(ZEM(ZaA2),ZPi1);
ZPi1=(((void)((T27*)(Z4D2()))),ZCG(ZPi1));if(!(ZQC((Z96*)(ZbA2()),ZPi1))){ZMC((Z96*)(ZbA2()),Zdj(Z9A2,ZaA2),ZPi1);Z7D2(Z9A2);Z7D2(ZaA2);
}R=ZPi1;return R;}void ZdA2(T0*a1,T0*a2,T0*a3){T0*Z8D2=Zo;T0*Z9D2=Zo;T0*Z2U=Zo;T2 Zet=0;T2 ZN_=0;T0*ZaD2=Zo;Z8D2=Z_G(a2);Z9D2=Z_G(a3);
ZAC2(a1,a2,a3);ZIM((Z84*)(ZkH),ZwC2);if(ZqU(a3)){if(ZIG(a3)){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){ZgM((Z84*)(ZkH),ZbD2);}Zet=(Z3)(((((((Ze7*)((((Z23*)(((((ZZ3*)Z8D2))->Zof)))->Zae))))->ZWb)))+(ZGs(1)));
if((Z3)((Zet)>(ZGs(1)))){ZgM((Z84*)(ZkH),ZcD2);while(!((Zet)==(ZGs(0)))){ZN_=(((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)Z8D2))->Zof)))->Zae))))->ZUb))[(Zet)-(ZGs(1))]))->_id);
ZgM((Z84*)(ZkH),ZdD2);ZDM((Z84*)(ZkH),(T11)(ZN_));ZgM((Z84*)(ZkH),ZeD2);ZcL(a3);ZgM((Z84*)(ZkH),ZfD2);ZDM((Z84*)(ZkH),(T11)(ZN_));ZgM((Z84*)(ZkH),ZgD2);
Zet=(Z3)(((Zet))-(ZGs(1)));}if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){ZgM((Z84*)(ZkH),ZhD2);ZgM((Z84*)(ZkH),((((ZZ3*)Z8D2))->ZUc));ZgM((Z84*)(ZkH),ZiD2);
}ZgM((Z84*)(ZkH),ZjD2);}else{ZgM((Z84*)(ZkH),ZkD2);ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)Z8D2))->_id)));ZgM((Z84*)(ZkH),ZlD2);}}else{ZdL((Z84*)(ZkH),((T3)'T'));
ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)Z9D2))->_id)));ZgM((Z84*)(ZkH),ZmD2);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){ZgM((Z84*)(ZkH),ZnD2);
ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)Z8D2))->_id)));ZgM((Z84*)(ZkH),ZoD2);}Z2U=Z3U(((ZZ3*)Z9D2));if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZXb);
while(!((Z3)((Zet)>(((((ZV8*)Z2U))->ZWb))))){ZaD2=(((ZD8*)((((ZE7*)(ZUy(((ZV8*)Z2U),Zet)))->Zpc)))->Zse);ZgM((Z84*)(ZkH),ZpD2);ZgM((Z84*)(ZkH),ZaD2);
ZgM((Z84*)(ZkH),ZqD2);ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)Z8D2))->_id)));ZgM((Z84*)(ZkH),ZrD2);ZgM((Z84*)(ZkH),ZaD2);ZgM((Z84*)(ZkH),ZsD2);
Zet=(Z3)(((Zet))+(ZGs(1)));}}ZgM((Z84*)(ZkH),ZtD2);}}else{ZdL((Z84*)(ZkH),((T3)'T'));ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)Z9D2))->_id)));ZdL((Z84*)(ZkH),((T3)'\052'));
Zmq1((Zj8*)(ZGC2()),ZuD2,Z9D2);if(ZIG(a2)){ZgM((Z84*)(ZkH),ZvD2);}else{Z2U=Z3U(((ZZ3*)Z9D2));if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZXb);
while(!((Z3)((Zet)>(((((ZV8*)Z2U))->ZWb))))){ZaD2=(((ZD8*)((((ZE7*)(ZUy(((ZV8*)Z2U),Zet)))->Zpc)))->Zse);ZgM((Z84*)(ZkH),ZwD2);ZgM((Z84*)(ZkH),ZaD2);
ZgM((Z84*)(ZkH),ZxD2);ZgM((Z84*)(ZkH),ZaD2);ZgM((Z84*)(ZkH),ZyD2);Zet=(Z3)(((Zet))+(ZGs(1)));}}}ZgM((Z84*)(ZkH),ZzD2);}ZgM((Z84*)(ZkH),ZAD2);
}void Zfe1(T0*a1,T0*a2){T0*ZPi1=Zo;T2 Zet=0;if(Z3L(a2)){ZgM((Z84*)(ZkH),ZBD2);}else{ZPi1=ZIc2(a1,a2);ZgM((Z84*)(ZkH),ZPi1);ZdL((Z84*)(ZkH),((T3)'\050'));
if(ZbL(a1)){ZdL((Z84*)(ZkH),((T3)'\050'));Zet=ZGs(1);while(!(((((((T7*)ZPi1))->ZUb))[(Zet)-(ZGs(1))])==(((T3)'t')))){ZdL((Z84*)(ZkH),(((((T7*)ZPi1))->ZUb))[(Zet)-(ZGs(1))]);
Zet=(Z3)(((Zet))+(ZGs(1)));}ZdL((Z84*)(ZkH),((T3)'\052'));ZdL((Z84*)(ZkH),((T3)'\051'));}}}void Z1D2(T6 a1,T0*a2,T0*a3){T81 Z9P={Zo,Zo,0};
if(a1){Zy_(Z9P,a2,a3);}else{Zy_(Z9P,a3,a2);}}T0*ZCD2=Zo;int ZDD2=0;T0*ZzC2(void){if(ZDD2==0){ZDD2=1;{{Z38*n=((Z38*)Zh(sizeof(*n)));*n=ZCk;
ZCD2=((T0*)n);{Z38*C1=n;ZbE(C1,Zxt(193));}}}}return ZCD2;}void ZzP(T81 a1,T0*a2,T0*a3){T2 Zet=0;if((a2)!=((void*)(Zo))){Zet=Zjy(((Zl2*)(((((Zz6*)a2))->Zie))));
while(!((Z3)((Zet)<=(ZGs(0))))){ZxC2(a1,ZnH(Z8a1(((Zz6*)a2),Zet)));Zet=(Z3)(((Zet))-(ZGs(1)));}}if((a3)!=((void*)(Zo))){ZxC2(a1,ZnH(a3));
}}void ZY71(T81 a1,T0*a2,T0*a3){if(ZqU(a2)){if(ZqU(a3)){}else{Zy_(a1,a2,a3);}}else{Zy_(a1,a2,a3);}}void Z8t1(T0*a1,T0*a2){T0*ZMd1=Zo;
T81 Z9P={Zo,Zo,0};ZV71(((Z23*)a2),Z9P,a1);ZMd1=ZNd1(((((ZZ3*)a1))->Z4c));ZOd1(((Z64*)ZMd1),Z9P,a2);}void ZED2(T0*a1){T2 Zet=0;T2 Z3x=0;
T0*Zh31=Zo;T0*Zi31=Zo;T81 Z9P={Zo,Zo,0};Zet=ZGs(1);while(!((Z3)((Zet)>(((((Z3a*)a1))->Zdc))))){Zh31=(((ZZ3*)(ZHF(((Z3a*)a1),Zet)))->Z4c);
Z3x=ZGs(1);while(!((Z3)((Z3x)>(((((Z3a*)a1))->Zdc))))){Zi31=(((ZZ3*)(ZHF(((Z3a*)a1),Z3x)))->Z4c);if((Zh31)!=((void*)(Zi31))){if(ZJG(Zh31,Zi31)){
Zy_(Z9P,Zh31,Zi31);}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));}}Z3x=(Z3)(((Z3x))+(ZGs(1)));
}Zet=(Z3)(((Zet))+(ZGs(1)));}}void Z7D2(T0*a1){T0*ZAs1=Zo;T0*ZR31=Zo;T0*ZJH=Zo;ZAs1=a1;if(Zo!=(ZAs1)){switch(((T0*)ZAs1)->id){case 290:
break;default:ZAs1=Zo;}}if((ZAs1)!=((void*)(Zo))){ZJH=ZSV(((ZK1*)ZAs1));ZCP(((ZZ3*)ZJH));ZR31=((((ZK1*)ZAs1))->Zbd);if((T6)((ZIG(ZR31))||((T6)(ZMR(ZR31))))){
if((ZZa1(((ZZ3*)ZJH),ZQJ))==((void*)(Zo))){}}}}T0*ZFD2=Zo;int ZGD2=0;T0*ZHD2(void){if(ZGD2==0){ZGD2=1;{{Zg4*n=((Zg4*)Zh(sizeof(*n)));
*n=Z2g;ZFD2=((T0*)n);{Zg4*C1=n;ZyB(C1,Zxt(193));}}}}return ZFD2;}T0*ZID2=Zo;T0*ZJD2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));
*n=ZOk;ZMM=((T0*)n);}}}return ZMM;}void ZKD2(Z36*C,T0*a1){T2 ZLD2=0;T2 ZMD2=0;T0*ZFh2=Zo;T0*ZiL=Zo;T0*ZJX=Zo;ZLD2=ZEM(a1);ZFh2=ZnH(Z1y((ZY*)(ZJR(a1)),ZGs(1)));
ZMD2=ZEM(ZFh2);ZWw((T7*)(ZND2),ZHR);Zgt((T7*)(ZND2),((T3)'\052'));Zmx((T7*)(ZND2),ZOD2);Z6t(ZLD2,ZND2);Zmx((T7*)(ZND2),ZPD2);((((T7*)((T7*)(ZID2))))->Zdc)=(ZGs(0));
Zgt((T7*)(ZID2),((T3)'T'));Z6t(ZLD2,ZID2);Zmx((T7*)(ZID2),ZQD2);if(ZbL(ZFh2)){Zmx((T7*)(ZID2),ZtI1);}else{Zgt((T7*)(ZID2),((T3)'T'));
Z6t(ZMD2,ZID2);}Zmx((T7*)(ZID2),ZRD2);if((((Zj8*)(ZJD2()))->ZLk)){Zmx((T7*)(ZID2),ZSD2);Z6t(ZLD2,ZID2);Zmx((T7*)(ZID2),ZTD2);}else{Zmx((T7*)(ZID2),ZwS);
Z6t(ZLD2,ZID2);Zmx((T7*)(ZID2),ZUD2);ZiL=ZZa1((ZZ3*)(Z_G(a1)),ZxK);Z6t(ZEM(ZiH(ZiL)),ZID2);Zmx((T7*)(ZID2),ZVD2);}Zmx((T7*)(ZID2),ZWD2);
ZJX=ZFh2;if(Zo!=(ZJX)){switch(((T0*)ZJX)->id){case 304:case 306:break;default:ZJX=Zo;}}Zmx((T7*)(ZID2),ZXD2);if(ZX01(ZFh2)){Zgt((T7*)(ZID2),((T3)'\052'));
}Zmx((T7*)(ZID2),ZYD2);if(ZbL(ZFh2)){Zmx((T7*)(ZID2),ZtI1);}else if(ZqT(ZFh2)){Zmx((T7*)(ZID2),ZZD2);}else if((T6)(((T6)(((T6)(((T6)(((ZEM(ZFh2))==(ZGs(1)))||((T6)((ZEM(ZFh2))==(ZGs(10))))))||((T6)(ZmU(ZFh2)))))||((T6)(ZET(ZFh2)))))||((T6)((T6)(((ZJX)!=((void*)(Zo)))&&((T6)((Z3)((ZQX(ZJX))<=(Zd12))))))))){
Zmx((T7*)(ZID2),Z_D2);}else{Zgt((T7*)(ZID2),((T3)'T'));Z6t(ZMD2,ZID2);if(ZX01(ZFh2)){Zgt((T7*)(ZID2),((T3)'\052'));}}Zmx((T7*)(ZID2),Z0E2);
Zmx((T7*)(ZID2),Z1E2);ZdS((Z84*)(ZkH),ZND2,ZID2);}void Zbe1(T0*a1){T2 ZN_=0;ZN_=ZEM(a1);ZgM((Z84*)(ZkH),ZOD2);ZDM((Z84*)(ZkH),(T11)(ZN_));
}void Zqe1(T0*a1){T2 ZN_=0;ZN_=ZEM(a1);if(!(ZxB((Zg4*)(ZHD2()),ZN_))){ZsB((Zg4*)(ZHD2()),a1,ZN_);}}void Z2E2(Z36*C){T2 Zet=0;Zet=ZGs(1);
while(!((Z3)((Zet)>((((Zg4*)(ZHD2()))->Zdc))))){ZKD2(C,ZvB((Zg4*)(ZHD2()),Zet));Zet=(Z3)(((Zet))+(ZGs(1)));}}T0*ZND2=Zo;T0*Z3E2(T92*C){
T0*R=Zo;{Zi1*n=((Zi1*)Zh(sizeof(*n)));*n=Zte;Z2b1(n,((*C).ZCb),Z4E2(C));R=((T0*)n);}return R;}T0*Z5E2(T92*C,T0*a1,T2 a2){T0*R=Zo;{Zi3*n=((Zi3*)Zh(sizeof(*n)));
*n=Zre;Zza1(n,((*C).ZCb),a1,a2);R=((T0*)n);}return R;}T6 Z6E2(void){T6 R=0;if((((((T7*)ZyZ))->Zdc))==(ZGs(4))){R=((T6)(ZJx(((T7*)ZZK),ZyZ)));
}return R;}T6 Z7E2(void){T6 R=0;if((((((T7*)ZyZ))->Zdc))==(ZGs(6))){R=((T6)(ZJx(((T7*)ZXK),ZyZ)));}return R;}T0*Z4E2(T92*C){T0*R=Zo;if((((*C).ZDb))==((void*)(Zo))){
(C->ZDb)=(((void)((T27*)(Z8E2()))),ZCG(ZyZ));}R=((*C).ZDb);return R;}T6 Z9E2(T92*C){T6 R=0;T3 ZXw=0;ZXw=ZNs((((((T7*)ZyZ))->ZUb))[ZGs(0)]);
{int z1=ZXw;switch(z1){case 97:if(ZJx(((T7*)ZaE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZNi1),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZBI),ZyZ)){
R=((T6)(1));}else if(ZJx(((T7*)Z5J),ZyZ)){ZbE2(C);R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZcE2),ZyZ)));}break;case 99:if(ZJx(((T7*)ZGv2),ZyZ)){
R=((T6)(1));}else if(ZJx(((T7*)ZdE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)Z7_),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZeE2),ZyZ)));
}break;case 100:if(ZJx(((T7*)ZOi1),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZfE2),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZgE2),ZyZ)));
}break;case 101:if(ZJx(((T7*)ZN91),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZhE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)Z4v2),ZyZ)){R=((T6)(1));
}else if(ZJx(((T7*)ZKi1),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZJw1),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZiE2),ZyZ)){R=((T6)(1));}else{
R=((T6)(ZJx(((T7*)Z0v2),ZyZ)));}break;case 102:if(ZJx(((T7*)ZjE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZkE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZlE2),ZyZ)){
R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZmE2),ZyZ)));}break;case 105:if(ZJx(((T7*)ZNF1),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZRI),ZyZ)){R=((T6)(1));
}else if(ZJx(((T7*)ZnE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)Zkp2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZoE2),ZyZ)){R=((T6)(1));}else
if(ZJx(((T7*)ZpE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZLi1),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZqE2),ZyZ)));}break;case 108:
if(ZJx(((T7*)Zek1),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZrE2),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZMi1),ZyZ)));}break;case 111:
if(ZJx(((T7*)ZsE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZtE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZuE2),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZWI),ZyZ)));
}break;case 112:if(ZJx(((T7*)ZWK),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)Zlp2),ZyZ)));}break;case 114:if(ZJx(((T7*)ZvE2),ZyZ)){R=((T6)(1));
}else if(ZJx(((T7*)ZwE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZJi1),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZxE2),ZyZ)){R=((T6)(1));}else{
R=((T6)(ZJx(((T7*)ZyE2),ZyZ)));}break;case 115:if(ZJx(((T7*)ZzE2),ZyZ)){R=((T6)(1));}else if(ZJx(((T7*)ZTT),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZAE2),ZyZ)));
}break;case 116:if(ZJx(((T7*)ZBE2),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZCE2),ZyZ)));}break;case 117:if(ZJx(((T7*)ZDE2),ZyZ)){R=((T6)(1));
}else if(ZJx(((T7*)ZEE2),ZyZ)){R=((T6)(1));}else{R=((T6)(ZJx(((T7*)ZFE2),ZyZ)));}break;case 118:R=((T6)(ZJx(((T7*)ZGE2),ZyZ)));break;
case 119:R=((T6)(ZJx(((T7*)ZHE2),ZyZ)));break;case 120:R=((T6)(ZJx(((T7*)ZvH),ZyZ)));break;}}return R;}void ZbE2(T92*C){{T3 b1=((T3)'\042');
Zgt((T7*)(Z2G),b1);}{T0*b1=ZyZ;Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(83,"\" is now a keyword in the new Eiffel definition. You must use another name (sorry).");
Zmx((T7*)(Z2G),b1);}Z5G(((*C).ZCb));ZPG((T80*)(Z4G));}T0*ZIE2(T92*C,T0*a1,T2 a2){T0*R=Zo;{Zl4*n=((Zl4*)Zh(sizeof(*n)));*n=Z7g;Z2f1(n,((*C).ZCb),a1,a2);
R=((T0*)n);}return R;}T0*ZJE2(T92*C){T0*R=Zo;{Zn4*n=((Zn4*)Zh(sizeof(*n)));*n=Zag;Zif1(n,((*C).ZCb),Z4E2(C));R=((T0*)n);}return R;}T0*Z8E2(void){
if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);
ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);
ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);
ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);
ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);
ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);
ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);
ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);
ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);
ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);
ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);
ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);
ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);
ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);
}}}return ZSH;}T0*ZKE2(T92*C){T0*R=Zo;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Z5m1(n,Z4E2(C),((*C).ZCb));R=((T0*)n);}return R;}void ZwZ(T92*C,T81
a1){(C->ZCb)=a1;((((T7*)((T7*)(ZyZ))))->Zdc)=(ZGs(0));(C->ZDb)=Zo;}T0*ZAZ(T92*C){T0*R=Zo;{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zu81(n,Z4E2(C),((*C).ZCb));
R=((T0*)n);}return R;}T0*ZLE2(T92*C){T0*R=Zo;{Zr6*n=((Zr6*)Zh(sizeof(*n)));*n=Z4j;ZAH1(n,Z4E2(C),((*C).ZCb));R=((T0*)n);}return R;}T0*ZME2(T92*C){
T0*R=Zo;if((((*C).ZDb))==((void*)(Zo))){(C->ZDb)=(((void)((T27*)(Z8E2()))),ZCG(ZyZ));}R=((*C).ZDb);return R;}T0*ZNE2(T92*C){T0*R=Zo;{Zz4*n=((Zz4*)Zh(sizeof(*n)));
*n=ZAg;((((Zz4*)(n)))->ZCb)=(((*C).ZCb));R=((T0*)n);}return R;}T6 ZOE2(void){T6 R=0;if((((((T7*)ZyZ))->Zdc))==(ZGs(7))){R=((T6)(ZJx(((T7*)ZNK),ZyZ)));
}return R;}void ZdQ(Zh6*C){(C->Zde)=(Z3)(((((C)->Zde)))+(ZGs(1)));}T6 ZPE2(T12*C,T0*a1){T6 R=0;if((T6)((ZQE2(ZRE2,a1))||((T6)(ZQE2(ZSE2,a1))))){
if(!(((C)->Z6j))){Z_v1((T39*)(ZQF),ZTE2);Z_v1((T39*)(ZQF),ZhA1);Z_v1((T39*)(ZQF),ZUE2);Z_v1((T39*)(ZQF),Z_v2);}{int z1=(((T55*)(ZVE2()))->ZWb);
switch(z1){case 1:Zv(ZGs(0));break;case 2:if(((C)->Z5j)){Zv(ZGs(0));}break;}}(C->Z6j)=((T6)(1));R=((T6)(1));}return R;}T6 ZWE2(T0*a1){
T6 R=0;if(ZQE2(ZMv2,a1)){R=((T6)(1));ZNv2((ZQ9*)(ZbP));}return R;}T0*ZXE2(void){if(ZE_==0){ZE_=1;{{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;
ZD_=((T0*)n);ZG_(n);}}}return ZD_;}T6 ZYE2(T12*C,T0*a1,T2 a2,T2 a3){T6 R=0;if(ZQE2(Zvv2,a1)){R=((T6)(1));if((Z3)((a2)<(a3))){Zwv2((ZD6*)(ZcP),ZZE2((Z3)(((a2))+((T2)(ZGs(1))))));
}else{(((void)((T38*)(Z_E2()))),Zzi1(ZhA1));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(39,": missing file name after -cecil flag.\n")));Zv(ZGs(1));
}}return R;}T0*Z0F2=Zo;int Z1F2=0;T0*ZVE2(void){if(Z1F2==0){Z1F2=1;{T2 Zet=0;T0*ZMa1=Zo;Zet=Z2F2;{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;
Z0F2=((T0*)n);ZCB(n,Zet);}while(!((Zet)==(ZGs(0)))){Zet=(Z3)(((Zet))-(ZGs(1)));ZMa1=((T0*)Z3F2(Z4F2[Zet]));(((((T55*)Z0F2))->ZUb))[Zet]=(ZMa1);
}}}return Z0F2;}T6 Z5F2(T12*C){T6 R=0;T2 Zet=0;T0*ZMa1=Zo;(((void)((T51*)(ZXE2()))),ZqC1());Zet=(((T55*)(ZVE2()))->ZWb);while(!((T6)((R)||((T6)((Zet)==(ZGs(0)))))))
{ZMa1=ZZE2(Zet);if((T6)((Ztx(((T7*)ZMa1),Z6F2))||((T6)(Ztx(((T7*)ZMa1),Z7F2))))){R=((T6)(1));Zzv2((T89*)(ZPM),ZMa1);}Zet=(Z3)(((Zet))-(ZGs(1)));
}if(R){Zet=ZGs(1);while(!((Z3)((Zet)>((((T55*)(ZVE2()))->ZWb))))){ZMa1=ZZE2(Zet);if((ZMa1)==((void*)((((T89*)(ZPM))->Z1f)))){}else if(Z8F2(C,ZMa1)){
}else{(((void)((T38*)(Z_E2()))),Zzi1(Z1G(18,"Flag or argument \"")));(((void)((T38*)(Z_E2()))),Zzi1(ZMa1));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(35,"\" is not allowed when an ACE file (")));
(((void)((T38*)(Z_E2()))),Zzi1((((T89*)(ZPM))->Z1f)));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(11,") is used.\n")));(((void)((T38*)(Z_E2()))),Zzi1(Z9F2));
ZfA1((T51*)(ZXE2()),(T0*)C);}Zet=(Z3)(((Zet))+(ZGs(1)));}}return R;}T6 ZQE2(T0*a1,T0*a2){T6 R=0;T2 ZaF2=0;T2 ZbF2=0;ZbF2=((((T7*)a2))->Zdc);
if((Z3)((ZbF2)>=(ZGs(2)))){ZaF2=((((T7*)a1))->Zdc);{int z1=(((((T7*)a2))->ZUb))[ZGs(0)];switch(z1){case 45:if(((((((T7*)a2))->ZUb))[(ZGs(2))-(ZGs(1))])==(((T3)'\055'))){
R=((T6)(((Z3)(((ZaF2))+(ZGs(2))))==(ZbF2)));}else{R=((T6)(((Z3)(((ZaF2))+(ZGs(1))))==(ZbF2)));}break;case 47:R=((T6)(((Z3)(((ZaF2))+(ZGs(1))))==(ZbF2)));
break;}}while(!((T6)((!(R))||((T6)((ZaF2)==(ZGs(0))))))){if(ZIs((((((T7*)a1))->ZUb))[(ZaF2)-(ZGs(1))],(((((T7*)a2))->ZUb))[(ZbF2)-(ZGs(1))])){
ZbF2=(Z3)(((ZbF2))-(ZGs(1)));ZaF2=(Z3)(((ZaF2))-(ZGs(1)));}else{R=((T6)(0));}}}return R;}T6 ZcF2(T0*a1){T6 R=0;if(ZQE2(Zaz2,a1)){R=((T6)(1));
}if(ZQE2(Zou2,a1)){Z_v1((T39*)(ZQF),ZhA1);Z_v1((T39*)(ZQF),ZdF2);R=((T6)(1));}if(R){ZPv2((T89*)(ZPM));}return R;}T6 ZeF2(T12*C,T0*a1,T2
a2,T2 a3){T6 R=0;T0*ZSy1=Zo;if(Z5v(((T7*)ZfF2),a1)){R=((T6)(1));if((Z3)((a2)<(a3))){ZSy1=ZZE2((Z3)(((a2))+(ZGs(1))));if(Ztx(((T7*)ZSy1),ZgF2)){
(((void)((T38*)(Z_E2()))),Zzi1(Z1G(22,"Bad executable name: \"")));(((void)((T38*)(Z_E2()))),Zzi1(ZSy1));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(77,"\". Must not use Eiffel source file suffix with option \"-o <executable_name>\".")));
Zv(ZGs(1));}((((T89*)((T89*)(ZPM))))->Z2f)=(ZSy1);}else{(((void)((T38*)(Z_E2()))),Zzi1(ZhA1));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(37,": missing output name after -o flag.\n")));
Zv(ZGs(1));}}return R;}void ZhF2(T12*C){T2 Z5e1=0;int ZoA1=0;((((ZQ9*)((ZQ9*)(ZbP))))->ZZe)=(1);{T0*b1=ZhA1;ZWw((T7*)(ZiF2),b1);}Z5e1=(((T55*)(ZVE2()))->ZWb);
if((Z3)((Z5e1)<(ZGs(1)))){ZfA1((T51*)(ZXE2()),(T0*)C);}{T2 Zet=0;Zet=(((T55*)(ZVE2()))->ZWb);while(!((Zet)==(ZGs(0)))){if(ZjF2(ZZE2(Zet))){
}Zet=(Z3)(((Zet))-(ZGs(1)));}ZvP((T38*)(Z_E2()),Z_v2);}ZkF2(Z5e1);if(Z5F2(C)){ZeC1((T51*)(ZXE2()));}else{ZlF2(C,(T2)(ZGs(1)));Zav2((T89*)(ZPM));
ZeC1((T51*)(ZXE2()));ZlF2(C,(T2)(ZGs(2)));ZCu2((T89*)(ZPM),ZhA1);}ZmF2((T43*)(ZSG));(((void)((T42*)(ZnF2()))));{T10 Zet=0;T10 ZN_=0;T0*ZoF2=Zo;
T0*ZpF2=Zo;{Z_9*n=((Z_9*)Zh(sizeof(*n)));*n=ZUm;ZOB1(n);ZoF2=((T0*)n);}Zov1((T38*)(ZS_()),ZoF2,ZT_((T51*)(ZF_())));Zet=ZGs(1);while(!((Z3)(((T2)(Zet))>((((T47*)(ZC_()))->Zdc)))))
{ZpF2=ZkD((T47*)(ZC_()),(T2)(Zet));ZN_=ZqD((T47*)(ZC_()),(T2)(Zet));Z181(ZoF2,(T11)(ZN_));ZgU(ZoF2,((T3)'\040'));ZgU(ZoF2,((T3)'\042'));
ZdU(ZoF2,ZpF2);ZgU(ZoF2,((T3)'\042'));ZgU(ZoF2,((T3)'\040'));ZqF2(ZoF2,ZpF2);ZgU(ZoF2,((T3)'\043'));ZgU(ZoF2,((T3)'\n'));Zet=(Z2)(((Zet))+(ZGs(1)));
}ZQB1(ZoF2);}(((void)((T27*)(ZrF2()))));ZvP((T38*)(Zzl2()),ZsF2);ZSP((T38*)(Zzl2()),(((T32*)(ZBl2()))->Zdc));ZvP((T38*)(Zzl2()),ZSv1);
}void ZlF2(T12*C,T2 a1){T2 Z5e1=0;T2 Zdt2=0;T0*ZMa1=Zo;Z5e1=(((T55*)(ZVE2()))->ZWb);Zdt2=ZGs(1);while(!((Z3)((Zdt2)>(Z5e1)))){ZMa1=ZZE2(Zdt2);
if(ZtF2(C,ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZuF2(ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZWE2(ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));
}else if(ZvF2(ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZPE2(C,ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZjF2(ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));
}else if(ZwF2(C,ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZYE2(C,ZMa1,Zdt2,Z5e1)){Zdt2=(Z3)(((Zdt2))+(ZGs(2)));}else if(ZeF2(C,ZMa1,Zdt2,Z5e1)){
Zdt2=(Z3)(((Zdt2))+(ZGs(2)));}else if(ZQE2(Zjv2,ZMa1)){((((T89*)((T89*)(ZPM))))->Z3f)=(1);Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZQE2(ZxF2,ZMa1)){
Z4J1((Zj8*)(ZyF2()));Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZQE2(Zhv2,ZMa1)){ZNI1((Zj8*)(ZyF2()));Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZzF2(ZMa1)){
Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZAF2(ZMa1)){Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZQE2(Ziv2,ZMa1)){((((T51*)((T51*)(ZXE2()))))->Zai)=(1);
Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZQE2(Zkv2,ZMa1)){((((T89*)((T89*)(ZPM))))->Zbf)=((T6)(1));Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZcF2(ZMa1)){
Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZQE2(Zmv2,ZMa1)){((((T89*)((T89*)(ZPM))))->Zcf)=((T6)(1));Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZBF2(ZMa1)){
Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZQE2(Zqv2,ZMa1)){((((Z84*)((Z84*)(ZkH))))->ZGf)=((T6)(1));Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}else if(ZQE2(ZCF2,ZMa1)){
if((a1)==(ZGs(1))){if((Z3)((Zdt2)<(Z5e1))){ZLC1((T51*)(ZXE2()),ZZE2((Z3)(((Zdt2))+((T2)(ZGs(1))))));Zdt2=(Z3)(((Zdt2))+(ZGs(2)));}else{
(((void)((T38*)(Z_E2()))),Zzi1(ZhA1));(((void)((T38*)(Z_E2()))),Zzi1(ZDF2));Zv(ZGs(1));}}else{Zdt2=(Z3)(((Zdt2))+(ZGs(2)));}}else if(ZQE2(ZEF2,ZMa1)){
if((a1)==(ZGs(1))){if((Z3)((Zdt2)<(Z5e1))){Zzz1((T51*)(ZXE2()),ZZE2((Z3)(((Zdt2))+((T2)(ZGs(1))))));Zdt2=(Z3)(((Zdt2))+(ZGs(2)));}else{
(((void)((T38*)(Z_E2()))),Zzi1(ZhA1));(((void)((T38*)(Z_E2()))),Zzi1(ZFF2));Zv(ZGs(1));}}else{Zdt2=(Z3)(((Zdt2))+(ZGs(2)));}}else if(ZQE2(Zgv2,ZMa1)){
if((T6)(((Z3)((Zdt2)<(Z5e1)))||((T6)((a1)!=(ZGs(1)))))){Zdt2=(Z3)(((Zdt2))+(ZGs(2)));}else{(((void)((T38*)(Z_E2()))),Zzi1(ZhA1));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(40,": missing compiler name after -cc flag.\n")));
Zv(ZGs(1));}}else if((a1)==(ZGs(2))){if((Z3)((Zdt2)<(Z5e1))){Zdt2=ZzC1((T51*)(ZXE2()),ZMa1,Zdt2,ZZE2((Z3)(((Zdt2))+((T2)(ZGs(1))))));
}else{Zdt2=ZzC1((T51*)(ZXE2()),ZMa1,Zdt2,Zo);}}else{Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}}}T0*ZyF2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));
*n=ZOk;ZMM=((T0*)n);}}}return ZMM;}T0*Z_E2(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}T6
ZjF2(T0*a1){T6 R=0;if(ZQE2(ZRv2,a1)){((((T38*)((T38*)(Z_E2()))))->ZKh)=(1);R=((T6)(1));}return R;}T0*ZrF2(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));
ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);
ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);
ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);
ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);
ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);
ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);
ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);
ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);
ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);
ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);
ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);
ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);
ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);
ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T6 ZtF2(T12*C,T0*a1){T6 R=0;
if((T6)(((T6)((ZQE2(ZGF2,a1))||((T6)(ZQE2(ZHF2,a1)))))||((T6)(Z5v(((T7*)ZIF2),a1))))){if(!(((C)->Z5j))){Z_v1((T39*)(ZQF),ZiA1);}{int z1=(((T55*)(ZVE2()))->ZWb);
switch(z1){case 1:Zv(ZGs(0));break;case 2:if(((C)->Z6j)){Zv(ZGs(0));}break;}}(C->Z5j)=((T6)(1));R=((T6)(1));}return R;}T6 ZBF2(T0*a1){
T6 R=0;if(ZQE2(ZTv2,a1)){((((T89*)((T89*)(ZPM))))->Z6f)=(1);R=((T6)(1));}return R;}T6 ZvF2(T0*a1){T6 R=0;if(ZQE2(ZOv2,a1)){R=((T6)(1));
((((T80*)((T80*)(Z4G))))->ZGg)=(1);}return R;}T6 ZzF2(T0*a1){T6 R=0;if(ZQE2(ZQv2,a1)){((((T89*)((T89*)(ZPM))))->Z4f)=(1);R=((T6)(1));
}return R;}T6 ZuF2(T0*a1){T6 R=0;if(ZQE2(ZKv2,a1)){R=((T6)(1));ZLv2((ZQ9*)(ZbP));}return R;}T6 Z8F2(T12*C,T0*a1){T6 R=0;if((T6)(((T6)(((T6)((ZPE2(C,a1))||((T6)(ZWE2(a1)))))||((T6)(ZvF2(a1)))))||((T6)(ZjF2(a1))))){
R=((T6)(1));}return R;}T6 ZAF2(T0*a1){T6 R=0;if(ZQE2(ZSv2,a1)){((((T89*)((T89*)(ZPM))))->Z5f)=(1);R=((T6)(1));}return R;}void ZkF2(T2
a1){T2 Zet=0;T0*ZJF2=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>(a1)))){if(ZQE2(Zgv2,ZZE2(Zet))){if((Z3)((Zet)<(a1))){Zet=(Z3)(((Zet))+(ZGs(1)));
ZJF2=ZZE2(Zet);Zet=(Z3)(((a1))+(ZGs(1)));}}Zet=(Z3)(((Zet))+(ZGs(1)));}Z9D1((T51*)(ZXE2()),ZJF2);}T6 ZwF2(T12*C,T0*a1){T6 R=0;if(ZQE2(ZHi1,a1)){
R=((T6)(1));((((T89*)((T89*)(ZPM))))->Zaf)=(ZGs(1));}else if(ZQE2(Z8z2,a1)){R=((T6)(1));((((T89*)((T89*)(ZPM))))->Zaf)=(ZGs(2));}else
if(ZQE2(ZKF2,a1)){R=((T6)(1));((((T89*)((T89*)(ZPM))))->Zaf)=(ZGs(3));}else if(ZQE2(ZLF2,a1)){R=((T6)(1));((((T89*)((T89*)(ZPM))))->Zaf)=(ZGs(4));
}else if(ZQE2(ZMF2,a1)){R=((T6)(1));((((T89*)((T89*)(ZPM))))->Zaf)=(ZGs(5));}else if(ZQE2(ZNF2,a1)){R=((T6)(1));((((T89*)((T89*)(ZPM))))->Zaf)=(ZGs(6));
}else if(ZQE2(ZOF2,a1)){R=((T6)(1));((((T89*)((T89*)(ZPM))))->Zaf)=(ZGs(7));}else if(ZQE2(ZPF2,a1)){R=((T6)(1));ZXv2((T89*)(ZPM));}if(R){
ZQF2(C,a1);}return R;}T0*ZnF2(void){if(ZJn1==0){ZJn1=1;{{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;ZIn1=((T0*)n);ZK_(n);}}}return ZIn1;}void
ZQF2(T12*C,T0*a1){if((((C)->Z7j))!=((void*)(Zo))){if(!(ZJx((T7*)(((C)->Z7j)),a1))){(((void)((T38*)(Z_E2()))),Zzi1(ZhA1));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(26,": level is already set to ")));
(((void)((T38*)(Z_E2()))),Zzi1(((C)->Z7j)));(((void)((T38*)(Z_E2()))),Zzi1(Z1G(11,". Bad flag ")));(((void)((T38*)(Z_E2()))),Zzi1(a1));
(((void)((T38*)(Z_E2()))),Zzi1(Zhv1));Zv(ZGs(1));}}else{(C->Z7j)=a1;}}T0*ZZE2(T2 a1){T0*R=Zo;R=((((T55*)(ZVE2()))->ZUb))[a1];return R;
}T0*ZRF2=Zo;void ZSF2(ZD6*C){T2 Zet=0;if((((C)->Zej))!=((void*)(Zo))){Zet=ZGs(1);while(!((Z3)((Zet)>((((Zs7*)(((C)->Zej)))->Zdc))))){
ZiP((Z31*)(ZUD((Zs7*)(((C)->Zej)),Zet)));Zet=(Z3)(((Zet))+(ZGs(1)));}}}T0*ZTF2(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));
*n=M38;ZdP=((T0*)n);}}}return ZdP;}void ZHP(T0*a1,T0*a2){T0*ZDZ=Zo;T0*ZXM1=Zo;T0*ZUF2=Zo;ZDZ=((((ZQ7*)a2))->Z4c);ZXM1=ZiH(a2);ZUF2=ZAP(a2);
ZDP(a2);((((T7*)((T7*)(ZRF2))))->Zdc)=(ZGs(0));if((ZXM1)!=((void*)(Zo))){ZtQ(ZXM1,ZRF2);}else{Zmx((T7*)(ZRF2),ZHR);}Zgt((T7*)(ZRF2),((T3)'\040'));
Zmx((T7*)(ZRF2),a1);Zgt((T7*)(ZRF2),((T3)'\050'));ZtQ(ZDZ,ZRF2);Zgt((T7*)(ZRF2),((T3)'\040'));Zgt((T7*)(ZRF2),((T3)'C'));if((ZUF2)!=((void*)(Zo))){
Zgt((T7*)(ZRF2),((T3)'\054'));ZLa1(((Zz6*)ZUF2),ZRF2);}Zgt((T7*)(ZRF2),((T3)'\051'));ZIM((Z84*)(ZkH),ZRF2);ZXT((Z84*)(ZkH));ZJX1(a2);
}void Zwv2(ZD6*C,T0*a1){if((((C)->Zej))==((void*)(Zo))){{Zs7*n=((Zs7*)Zh(sizeof(*n)));*n=Z3k;{Zs7*C1=n;ZZD(C1,Zxt(193));}(C->Zej)=((T0*)n);
}ZYD((Zs7*)(((C)->Zej)),((T0*)Z5P(a1)),a1);}else if(!(ZXD((Zs7*)(((C)->Zej)),a1))){ZYD((Zs7*)(((C)->Zej)),((T0*)Z5P(a1)),a1);}}void ZVF2(ZD6*C){
T2 Zet=0;if((((C)->Zej))!=((void*)(Zo))){Zet=ZGs(1);while(!((Z3)((Zet)>((((Zs7*)(((C)->Zej)))->Zdc))))){ZgP((Z31*)(ZUD((Zs7*)(((C)->Zej)),Zet)));
Zet=(Z3)(((Zet))+(ZGs(1)));}}}void ZDP(T0*a1){if((((T38*)(ZTF2()))->ZKh)){ZWP((T38*)(ZTF2()),((T3)'\011'));ZvP((T38*)(ZTF2()),Z9G(((((ZQ7*)a1))->Z4c)));
ZWP((T38*)(ZTF2()),((T3)'\056'));ZvP((T38*)(ZTF2()),(((ZD8*)(((((ZQ7*)a1))->Zpc)))->Zse));ZWP((T38*)(ZTF2()),((T3)'\n'));}}void ZJX1(T0*a1){
T0*ZDZ=Zo;T0*ZXM1=Zo;T0*ZWF2=Zo;T0*ZDt2=Zo;T0*ZdH=Zo;ZDZ=((((ZQ7*)a1))->Z4c);ZXM1=ZiH(a1);ZdH=(((ZZ3*)(Z_G(ZDZ)))->Zof);if(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(0))){
ZMT(ZDZ,ZXF2);{T0*b1=ZYF2;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(ZDZ);Zmx((T7*)(Z2G),b1);}{T3 b1=((T3)'\056');Zgt((T7*)(Z2G),b1);}{T0*b1=(((ZD8*)(((((ZQ7*)a1))->Zpc)))->Zcn);
Zmx((T7*)(Z2G),b1);}{T3 b1=((T3)'\056');Zgt((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){ZgM((Z84*)(ZkH),ZZF2);
}}else{if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){ZgM((Z84*)(ZkH),Z_F2);Z1u2(a1,Z0G2,ZmI1);}if((ZXM1)!=((void*)(Zo))){((((T7*)((T7*)(ZRF2))))->Zdc)=(ZGs(0));
Zgt((T7*)(ZRF2),((T3)'\173'));ZtQ(ZXM1,ZRF2);Zmx((T7*)(ZRF2),Z1G2);ZgM((Z84*)(ZkH),ZRF2);}{ZY5*n=((ZY5*)Zh(sizeof(*n)));*n=Z1i;((((ZY5*)(n)))->Zlc)=(((((ZQ7*)a1))->Z4c));
ZWF2=((T0*)n);}if((ZAP(a1))!=((void*)(Zo))){ZDt2=Z2G2(a1);}if(ZqU(ZDZ)){ZjY1((Z84*)(ZkH),a1,ZWF2,ZDt2);Z3Z(a1);Z4Z((Z84*)(ZkH));}else{
ZEz2((Z84*)(ZkH),a1,ZdH,ZWF2,ZDt2);}if((ZXM1)!=((void*)(Zo))){ZgM((Z84*)(ZkH),ZCQ);}if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){Z1u2(a1,Z3G2,ZqI1);
}if((ZXM1)!=((void*)(Zo))){ZgM((Z84*)(ZkH),Z4G2);}}ZgM((Z84*)(ZkH),ZmM);}void Zpx2(ZD6*C){T2 Zet=0;if((((C)->Zej))!=((void*)(Zo))){Zet=ZGs(1);
while(!((Z3)((Zet)>((((Zs7*)(((C)->Zej)))->Zdc))))){ZEP((Z31*)(ZUD((Zs7*)(((C)->Zej)),Zet)));Zet=(Z3)(((Zet))+(ZGs(1)));}}}T0*Z2G2(T0*a1){
T0*R=Zo;T0*Z5G2=Zo;T0*Z6G2=Zo;T0*Z7G2=Zo;T0*Z4e1=Zo;T2 Zet=0;Z4e1=ZAP(a1);{Z69*n=((Z69*)Zh(sizeof(*n)));*n=ZHl;Z2e1(n,Z8a1(((Zz6*)Z4e1),(T2)(ZGs(1))),(T2)(ZGs(1)));
Z5G2=((T0*)n);}if((Z3)((Zjy(((Zl2*)(((((Zz6*)Z4e1))->Zie)))))>(ZGs(1)))){{Z43*n=((Z43*)Zh(sizeof(*n)));*n=Zce;ZvA(n,(Z3)(((Zjy(((Zl2*)(((((Zz6*)Z4e1))->Zie))))))-((T2)(ZGs(1)))));
Z6G2=((T0*)n);}Zet=ZGs(2);while(!((Z3)((Zet)>(Zjy(((Zl2*)(((((Zz6*)Z4e1))->Zie)))))))){{Z69*n=((Z69*)Zh(sizeof(*n)));*n=ZHl;Z2e1(n,Z8a1(((Zz6*)Z4e1),Zet),Zet);
Z7G2=((T0*)n);}ZsA(((Z43*)Z6G2),Z7G2);Zet=(Z3)(((Zet))+(ZGs(1)));}{Za3*n=((Za3*)Zh(sizeof(*n)));*n=Z3j;ZnH1(n,Z5G2,Z6G2);R=((T0*)n);}
}else{{Za3*n=((Za3*)Zh(sizeof(*n)));*n=Z3j;((((Za3*)(n)))->Z2j)=(Z5G2);R=((T0*)n);}}return R;}void ZH22(ZT6*C){(C->Zpj)=(Z3)(((((C)->Zpj)))+(ZGs(1)));
}T0*ZM22(ZT6*C){T0*R=Zo;T6 Zd22=0;R=Z8G2;((((T7*)(((T7*)R))))->Zdc)=(ZGs(0));Zgt(((T7*)R),ZV22(C));ZH22(C);while(!(Zd22)){if(ZJ22(C)){
Zd22=((T6)(1));}else if((ZV22(C))==(((T3)'\054'))){Zd22=((T6)(1));}else if(Zzs(ZV22(C))){Zd22=((T6)(1));}else{Zgt(((T7*)R),ZV22(C));ZH22(C);
if((Z0x(((T7*)R)))==(((T3)'\051'))){if((Z3)((ZYw(((T7*)R),((T3)'\050')))<(ZYw(((T7*)R),((T3)'\051'))))){(C->Zpj)=(Z3)(((((C)->Zpj)))-(ZGs(1)));
ZFx(((T7*)R),(T2)(ZGs(1)));Zd22=((T6)(1));}}}}R=Z7t(((T7*)R));ZI22(C);return R;}T6 Z9G2(ZT6*C,T0*a1){T6 R=0;T2 ZaG2=0;ZaG2=((C)->Zpj);
if(ZK22(C,a1)){if((Z3)((((C)->Zpj))>(((C)->Zdc)))){R=((T6)(1));}else{(C->Zpj)=ZaG2;}}return R;}void ZG22(ZT6*C,T0*a1){(C->Zoj)=a1;(C->Zse)=(((T93*)(((C)->Zoj)))->Zse);
(C->Zdc)=(((T7*)(((C)->Zse)))->Zdc);(C->Zpj)=ZGs(1);ZI22(C);}T3 ZV22(ZT6*C){T3 R=0;R=((((T7*)(((C)->Zse)))->ZUb))[(((C)->Zpj))-(ZGs(1))];
return R;}T0*ZW22(ZT6*C){T0*R=Zo;T6 Zd22=0;R=ZbG2;((((T7*)(((T7*)R))))->Zdc)=(ZGs(0));Zgt(((T7*)R),ZV22(C));ZH22(C);while(!(Zd22)){if(ZJ22(C)){
Zd22=((T6)(1));}else if(Zzs(ZV22(C))){Zd22=((T6)(1));}else if((ZV22(C))==(((T3)'\054'))){Zd22=((T6)(1));}else{Zgt(((T7*)R),ZV22(C));ZH22(C);
}}{int z1=(((((T7*)R))->ZUb))[ZGs(0)];switch(z1){case 34:case 60:break;default:;ZAx(((T7*)R),((T3)'\042'));ZMx(((T7*)R),((T3)'\042'));
}}R=Z7t(((T7*)R));return R;}T6 ZK22(ZT6*C,T0*a1){T6 R=0;T2 ZaG2=0;T2 Zet=0;T6 Zd22=0;ZaG2=((C)->Zpj);Zet=ZGs(1);while(!(Zd22)){if((Z3)((Zet)>(((((T7*)a1))->Zdc)))){
Zd22=((T6)(1));}else if((Z3)((((C)->Zpj))>(((C)->Zdc)))){Zd22=((T6)(1));}else if((((((T7*)(((C)->Zse)))->ZUb))[(((C)->Zpj))-(ZGs(1))])==((((((T7*)a1))->ZUb))[(Zet)-(ZGs(1))])){
Zet=(Z3)(((Zet))+(ZGs(1)));(C->Zpj)=(Z3)(((((C)->Zpj)))+(ZGs(1)));}else{Zd22=((T6)(1));}}if((Z3)((Zet)>(((((T7*)a1))->Zdc)))){ZI22(C);
R=((T6)(1));}else{(C->Zpj)=ZaG2;}return R;}void ZI22(ZT6*C){while(!((T6)(((Z3)((((C)->Zpj))>(((C)->Zdc))))||((T6)(!(Zzs(((((T7*)(((C)->Zse)))->ZUb))[(((C)->Zpj))-(ZGs(1))])))))))
{(C->Zpj)=(Z3)(((((C)->Zpj)))+(ZGs(1)));}}T0*ZU22(ZT6*C){T0*R=Zo;T6 Zd22=0;T0*ZcG2=Zo;if((ZV22(C))!=(((T3)'\050'))){{T0*b1=Z1G(54,"Bad external signature (missing opening \"(\" delimiter.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}ZH22(C);ZI22(C);{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;ZSz(n,(T2)(ZGs(8)));R=((T0*)n);}ZQz(((T55*)R),Zo);
while(!(Zd22)){if(ZJ22(C)){{T0*b1=Z1G(46,"Bad external signature (missing \")\" delimiter.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else
if((ZV22(C))==(((T3)'\054'))){ZH22(C);ZI22(C);}else if((ZV22(C))==(((T3)'\051'))){Zd22=((T6)(1));ZH22(C);ZI22(C);}else{ZcG2=ZM22(C);ZQz(((T55*)R),ZcG2);
}}return R;}T6 ZJ22(ZT6*C){T6 R=0;R=((T6)((Z3)((((C)->Zpj))>(((C)->Zdc)))));return R;}T0*ZdG2(Zy7*C){T0*R=Zo;if((((*C).ZGb))==((void*)(Zo))){
{ZE3*n=((ZE3*)Zh(sizeof(*n)));*n=ZHe;{ZE3*C1=n;T0*b1=ZeG2();T0*b2=((*C).ZFb);T0*b3=((*C).ZIb);T0*b4=((*C).ZHb);T0*b5=((*C).ZJb);ZQc1(C1,b1,b2,b3,b4,b5);
}R=((T0*)n);}}else{{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Zbl;ZC72(n,ZeG2(),((*C).ZFb),((*C).ZGb),((*C).ZIb),((*C).ZHb),((*C).ZJb));R=((T0*)n);
}}return R;}void ZfG2(T0*a1){if((((((ZD8*)a1))->Zse))==((void*)(ZZK))){Z5G(((((ZD8*)a1))->ZCb));{T0*b1=Z1G(45,"Feature `Void\' cannot be redefined (builtin).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}ZIA((ZK3*)(ZgG2()),a1);}T0*ZhG2(Zy7*C,T0*a1,T0*a2){T0*R=Zo;if((((*C).ZGb))==((void*)(Zo))){{ZX4*n=((ZX4*)Zh(sizeof(*n)));
*n=Z4h;ZFm1(n,ZeG2(),((*C).ZFb),((*C).ZIb),((*C).ZHb),((*C).ZJb),a1,a2);R=((T0*)n);}}else{{Zk7*n=((Zk7*)Zh(sizeof(*n)));*n=ZXj;Z6m1(n,ZeG2(),((*C).ZFb),((*C).ZGb),((*C).ZIb),((*C).ZHb),((*C).ZJb),a1,a2);
R=((T0*)n);}}return R;}T0*ZiG2(Zy7*C){T0*R=Zo;if((((*C).ZGb))==((void*)(Zo))){Z5G((((ZD8*)(((((ZK3*)(ZgG2()))->ZUb))[ZGs(0)]))->ZCb));
{T0*b1=ZjG2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else if(ZzT(((*C).ZGb))){{Zn8*n=((Zn8*)Zh(sizeof(*n)));*n=Z0l;ZU42(n,ZeG2(),((*C).ZGb));
R=((T0*)n);}}else{{T81 Zow;Z5G((*(Zow=ZrP(((*C).ZGb)),&Zow)));}{T0*b1=ZjG2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}return R;}void ZkG2(T81
a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T0*ZlG2(Zy7*C){T0*R=Zo;if((((*C).ZGb))==((void*)(Zo))){ZkG2((((ZD8*)(((((ZK3*)(ZgG2()))->ZUb))[ZGs(0)]))->ZCb),Z1G(23,"Bad feature definition."));
}else if((((*C).ZFb))!=((void*)(Zo))){{ZQ9*C1=(ZQ9*)(ZbP);T0*b1=Z1G(41,"Attribute must not have formal arguments.");{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}{ZR8*n=((ZR8*)Zh(sizeof(*n)));*n=Zjl;Zz92(n,ZeG2(),((*C).ZGb));R=((T0*)n);}return R;}T0*ZoG2=Zo;int ZpG2=0;T0*ZgG2(void){if(ZpG2==0){ZpG2=1;{
{ZK3*n=((ZK3*)Zh(sizeof(*n)));*n=ZMe;ZoG2=((T0*)n);ZHA(n,(T2)(ZGs(8)));}}}return ZoG2;}T0*ZqG2(Zy7*C,T0*a1){T0*R=Zo;ZrG2(C);if(ZET(((*C).ZGb))){
{ZK5*n=((ZK5*)Zh(sizeof(*n)));*n=ZNh;Zfx1(n,ZeG2(),((*C).ZGb),a1);R=((T0*)n);}}else{{T81 Zow;ZkG2((*(Zow=ZrP(((*C).ZGb)),&Zow)),Z1G(54,"The type of this constant feature should be CHARACTER."));
}}return R;}T0*ZsG2(Zy7*C,T0*a1){T0*R=Zo;ZrG2(C);if(ZmU(((*C).ZGb))){{ZV2*n=((ZV2*)Zh(sizeof(*n)));*n=Z3e;Z371(n,ZeG2(),((*C).ZGb),a1);
R=((T0*)n);}}else{{T81 Zow;ZkG2((*(Zow=ZrP(((*C).ZGb)),&Zow)),Z1G(52,"The type of this constant feature should be BOOLEAN."));}}return
R;}T0*ZeG2(void){T0*R=Zo;{Zz8*n=((Zz8*)Zh(sizeof(*n)));*n=Z9l;Zu72(n,ZgG2());R=((T0*)n);}return R;}T0*ZtG2(Zy7*C,T0*a1){T0*R=Zo;ZrG2(C);
if(ZMR(((*C).ZGb))){{Zy9*n=((Zy9*)Zh(sizeof(*n)));*n=Zbm;Zeg2(n,ZeG2(),((*C).ZGb),a1);R=((T0*)n);}}else{{T81 Zow;ZkG2((*(Zow=ZrP(((*C).ZGb)),&Zow)),Z1G(48,"The type of this constant feature should be BIT."));
}}return R;}void ZrG2(Zy7*C){if((((*C).ZGb))==((void*)(Zo))){Z5G((((ZD8*)(((((ZK3*)(ZgG2()))->ZUb))[ZGs(0)]))->ZCb));{T0*b1=Z1G(42,"Bad constant declaration (no result type).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else if(!(ZyW(((*C).ZGb)))){{T81 Zow;Z5G((*(Zow=ZrP(((*C).ZGb)),&Zow)));}{T0*b1=Z1G(38,"Must not use such a type for constant.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}T0*ZuG2(Zy7*C){T0*R=Zo;if((((*C).ZGb))==((void*)(Zo))){{Zda*n=((Zda*)Zh(sizeof(*n)));*n=Z9n;ZWo2(n,ZeG2(),((*C).ZFb),((*C).ZIb),((*C).ZHb),((*C).ZJb),((*C).ZKb),((*C).ZLb));
R=((T0*)n);}}else{{Zs9*n=((Zs9*)Zh(sizeof(*n)));*n=Z5m;ZAf2(n,ZeG2(),((*C).ZFb),((*C).ZGb),((*C).ZIb),((*C).ZHb),((*C).ZJb),((*C).ZKb),((*C).ZLb));
R=((T0*)n);}}return R;}T0*ZvG2(Zy7*C,T0*a1){T0*R=Zo;ZrG2(C);if(ZwU(((*C).ZGb))){{ZX2*n=((ZX2*)Zh(sizeof(*n)));*n=Z6e;Zd71(n,ZeG2(),((*C).ZGb),a1);
R=((T0*)n);}}else{{T81 Zow;ZkG2((*(Zow=ZrP(((*C).ZGb)),&Zow)),Z1G(51,"The type of this constant feature should be STRING."));}}return
R;}T0*ZwG2(Zy7*C){T0*R=Zo;if((((*C).ZGb))==((void*)(Zo))){{Z65*n=((Z65*)Zh(sizeof(*n)));*n=Zch;Zyo1(n,ZeG2(),((*C).ZFb),((*C).ZIb),((*C).ZHb),((*C).ZJb),((*C).ZKb),((*C).ZLb));
R=((T0*)n);}}else{{Zc7*n=((Zc7*)Zh(sizeof(*n)));*n=ZMj;ZNP1(n,ZeG2(),((*C).ZFb),((*C).ZGb),((*C).ZIb),((*C).ZHb),((*C).ZJb),((*C).ZKb),((*C).ZLb));
R=((T0*)n);}}return R;}void ZxG2(Zy7*C){((((ZK3*)((ZK3*)(ZgG2()))))->ZWb)=(ZGs(-1));(C->ZFb)=Zo;(C->ZGb)=Zo;(C->ZHb)=Zo;(C->ZIb)=Zo;(C->ZJb)=Zo;
(C->ZKb)=Zo;(C->ZLb)=Zo;}void ZyG2(Zy7*C,T81 a1,T6 a2,T0*a3,T0*a4){if((T6)(((a3)!=((void*)(Zo)))||((T6)((a4)!=((void*)(Zo)))))){{Zf2*n=((Zf2*)Zh(sizeof(*n)));
*n=ZZl;ZId2(n,a1,(T6)(a2),a3,a4);(C->ZJb)=((T0*)n);}}}T0*ZzG2(Zy7*C,T0*a1){T0*R=Zo;T0*ZuW=Zo;T11 ZAG2=0;T0*ZLt=Zo;T6 ZBG2=0;ZrG2(C);if(ZzT(((*C).ZGb))){
ZAG2=((((Zw1*)a1))->ZMl);ZuW=((*C).ZGb);if(Zo!=(ZuW)){switch(((T0*)ZuW)->id){case 292:break;default:ZuW=Zo;}}{int z1=ZJk2(((Zg5*)ZuW));
switch(z1){case 1:ZBG2=((T6)(!(Zyt(ZAG2))));break;case 2:ZBG2=((T6)(!(Zvt(ZAG2))));break;case 4:ZBG2=((T6)(!(Ztt(ZAG2))));break;default:;
}}if(ZBG2){ZLt=Z0p1(((Zw1*)a1),ZuW);if(ZJG(((((Zw1*)ZLt))->Zlc),ZuW)){}{T0*b1=Z1G(73,"Bad constant attribute definition (manifest constant value out of range).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{{Zq5*n=((Zq5*)Zh(sizeof(*n)));*n=Zph;Z4q1(n,ZeG2(),((*C).ZGb),a1);R=((T0*)n);}}}else if(ZqT(((*C).ZGb))){
{ZX3*n=((ZX3*)Zh(sizeof(*n)));*n=ZUe;Zed1(n,ZeG2(),((*C).ZGb),ZZo1(((Zw1*)a1)));R=((T0*)n);}}else if(ZbU(((*C).ZGb))){{ZW*n=((ZW*)Zh(sizeof(*n)));
*n=Znc;ZdO(n,ZeG2(),((*C).ZGb),ZZo1(((Zw1*)a1)));R=((T0*)n);}}else{{T81 Zow;ZkG2((*(Zow=ZrP(((*C).ZGb)),&Zow)),Z1G(67,"The type of this constant feature should be INTEGER REAL or DOUBLE."));
}}return R;}T0*ZCG2(Zy7*C,T0*a1){T0*R=Zo;ZrG2(C);if(ZqT(((*C).ZGb))){{ZX3*n=((ZX3*)Zh(sizeof(*n)));*n=ZUe;Zed1(n,ZeG2(),((*C).ZGb),a1);
R=((T0*)n);}}else if(ZbU(((*C).ZGb))){((((ZC9*)(((ZC9*)a1))))->Zlc)=(((*C).ZGb));{ZW*n=((ZW*)Zh(sizeof(*n)));*n=Znc;ZdO(n,ZeG2(),((*C).ZGb),a1);
R=((T0*)n);}}else{{T81 Zow;Z5G((*(Zow=ZrP(((*C).ZGb)),&Zow)));}{T0*b1=Z1G(59,"The type of this constant feature should be REAL or DOUBLE.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}return R;}void ZmB1(T0*a1){{int z1=(((((T7*)a1))->ZUb))[ZGs(0)];switch(z1){case 46:case 47:case
126:((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'U'));if((Z3)((((((T7*)a1))->Zdc))>=(ZGs(4)))){if(((((((T7*)a1))->ZUb))[(ZGs(2))-(ZGs(1))])==(((T3)'\057'))){
if(((((((T7*)a1))->ZUb))[(ZGs(4))-(ZGs(1))])==(((T3)'\057'))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'C'));}}}break;case
92:((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'W'));break;case 58:((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'M'));
break;case 91:((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'V'));break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:
case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:
case 89:case 90:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case
110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:if((Z3)((((((T7*)a1))->Zdc))>=(ZGs(2)))){
{int z2=(((((T7*)a1))->ZUb))[(ZGs(2))-(ZGs(1))];switch(z2){case 58:if((((((T7*)a1))->Zdc))==(ZGs(2))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'W'));
}else if(ZGx(((T7*)a1),((T3)'\134'))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'W'));}else if(ZGx(((T7*)a1),((T3)'\077'))){
((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'A'));}else if(ZGx(((T7*)a1),((T3)'\057'))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'C'));
}break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:
case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 97:case 98:case 99:case 100:case 101:case 102:case
103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case
118:case 119:case 120:case 121:case 122:if(ZGx(((T7*)a1),((T3)'\133'))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'V'));}
else if(ZGx(((T7*)a1),((T3)'\072'))){if(ZGx(((T7*)a1),((T3)'\057'))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'A'));}else
if(ZGx(((T7*)a1),((T3)'\133'))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'V'));}else{((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'A'));
}}else if(ZGx(((T7*)a1),((T3)'\057'))){((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'U'));}else if(ZGx(((T7*)a1),((T3)'\134'))){
((((T7*)(Z0B1))->ZUb))[((T2)(ZGs(1)))-(ZGs(1))]=(((T3)'U'));}break;}}}break;}}}T6 ZCB1(void){T6 R=0;R=((T6)(((((((T7*)Z0B1))->ZUb))[ZGs(0)])==(((T3)'A'))));
return R;}void Z_72(T61*C,T0*a1){T8 Z4W=Zo;Z182(C,a1);if((Zo!=((*C).ZNb))){ZWw((T7*)(Zvz1),a1);}else{ZYD1(a1);if((Z3)(((((T7*)(Zvz1))->Zdc))>(ZGs(0)))){
Z4W=ZQx((T7*)(Zvz1));(C->ZNb)=Z1r(Z4W);(C->ZOb)=((*C).ZNb);if(Zts(((*C).ZNb))){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}}else{((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));
}}}void ZlB1(T61*C){T8 Zfz2=Zo;Zfz2=ZDG2;if((Zo!=Zfz2)){Zmt((T7*)(Zvz1),Zfz2);(C->ZNb)=Z1r(Zfz2);(C->ZOb)=((*C).ZNb);if(Zts(((*C).ZNb))){
((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}}else{((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}}void ZnB1(T61*C){T8 ZtC2=Zo;if(Z9r(((*C).ZNb))){
(C->ZNb)=ZtC2;(C->ZOb)=ZtC2;}}void Zwz1(T0*a1,T0*a2){ZWw((T7*)(Zvz1),a1);if((T6)((ZpB1())||((T6)(ZqB1())))){if(Z5v(((T7*)ZEG2),a2)){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));
}else if(Z5v(((T7*)ZFG2),a2)){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else{ZIx((T7*)(Zvz1),((T3)'\057'));if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\057'))){
ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}Zmx((T7*)(Zvz1),a2);ZIx((T7*)(Zvz1),((T3)'\057'));}}else if(ZwB1()){if(Z5v(((T7*)ZGG2),a2)){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));
}else if(Z5v(((T7*)ZHG2),a2)){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else{ZIx((T7*)(Zvz1),((T3)'\134'));if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\134'))){
ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}Zmx((T7*)(Zvz1),a2);ZIx((T7*)(Zvz1),((T3)'\134'));}}else if(ZCB1()){{int z1=Z0x((T7*)(Zvz1));switch(z1){
case 47:if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\057'))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}break;case 58:break;default:;if(((((((T7*)a2))->ZUb))[ZGs(0)])!=(((T3)'\057'))){
ZMx((T7*)(Zvz1),((T3)'\057'));}}}Zmx((T7*)(Zvz1),a2);ZIx((T7*)(Zvz1),((T3)'\057'));}else if(ZBB1()){ZIx((T7*)(Zvz1),((T3)'\072'));if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\072'))){
ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}Zmx((T7*)(Zvz1),a2);ZIx((T7*)(Zvz1),((T3)'\072'));}else if(ZDB1()){if(((((T7*)(Zvz1))->Zdc))==(ZGs(1))){
((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else if((Z0x((T7*)(Zvz1)))==(((T3)'\135'))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));if((Z0x((T7*)(Zvz1)))==(((T3)'\133'))){
Zmx((T7*)(Zvz1),a2);Zgt((T7*)(Zvz1),((T3)'\135'));}else{Zgt((T7*)(Zvz1),((T3)'\056'));Zmx((T7*)(Zvz1),a2);Zgt((T7*)(Zvz1),((T3)'\135'));
}}else if((Z0x((T7*)(Zvz1)))==(((T3)'\072'))){Zgt((T7*)(Zvz1),((T3)'\133'));Zmx((T7*)(Zvz1),a2);Zgt((T7*)(Zvz1),((T3)'\135'));}else{((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));
}}else if(ZoB1()){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else{ZmB1(a1);if(ZoB1()){Zwz1(a1,a2);}else{((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));
}}}T6 ZoB1(void){T6 R=0;R=((T6)(((((((T7*)Z0B1))->ZUb))[ZGs(0)])!=(((T3)'\077'))));return R;}T6 Z482(void){T6 R=0;T61 Zdz1={Zo,Zo};{int
z1=(((((T7*)Z0B1))->ZUb))[ZGs(0)];switch(z1){case 63:ZlB1(&Zdz1);if((Zo!=((Zdz1).ZNb))){if(!(((((T7*)(Zvz1))->Zdc))==(ZGs(0)))){ZmB1(Zvz1);
}ZnB1(&Zdz1);if(((((((T7*)Z0B1))->ZUb))[ZGs(0)])!=(((T3)'\077'))){R=((T6)(Z482()));}}break;case 86:case 87:break;default:;R=((T6)(1));
}}return R;}T6 ZwB1(void){T6 R=0;R=((T6)(((((((T7*)Z0B1))->ZUb))[ZGs(0)])==(((T3)'W'))));return R;}T6 ZpB1(void){T6 R=0;R=((T6)(((((((T7*)Z0B1))->ZUb))[ZGs(0)])==(((T3)'U'))));
return R;}T0*Zvz1=Zo;T6 ZBB1(void){T6 R=0;R=((T6)(((((((T7*)Z0B1))->ZUb))[ZGs(0)])==(((T3)'M'))));return R;}void ZYD1(T0*a1){ZWw((T7*)(Zvz1),a1);
if(ZpB1()){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));while(!((T6)((((((T7*)(Zvz1))->Zdc))==(ZGs(0)))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\057')))))))
{ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}if(!(((((T7*)(Zvz1))->Zdc))==(ZGs(0)))){ZIx((T7*)(Zvz1),((T3)'\057'));}}else if(ZwB1()){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));
while(!((T6)((((((T7*)(Zvz1))->Zdc))==(ZGs(0)))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\134'))))))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}if(!(((((T7*)(Zvz1))->Zdc))==(ZGs(0)))){
ZIx((T7*)(Zvz1),((T3)'\134'));}}else if(ZqB1()){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));while(!((T6)(((T6)((((((T7*)(Zvz1))->Zdc))==(ZGs(0)))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\057'))))))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\072')))))))
{ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}if(((((T7*)(Zvz1))->Zdc))==(ZGs(0))){}else if((((((T7*)(Zvz1))->ZUb))[ZGs(0)])==(((T3)'\057'))){if(((((T7*)(Zvz1))->Zdc))==(ZGs(2))){
if((((((T7*)(Zvz1))->ZUb))[(ZGs(2))-(ZGs(1))])==(((T3)'\057'))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}}}if(!(((((T7*)(Zvz1))->Zdc))==(ZGs(0)))){
ZIx((T7*)(Zvz1),((T3)'\057'));}}else if(ZCB1()){if((Z0x((T7*)(Zvz1)))==(((T3)'\072'))){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else{ZFx((T7*)(Zvz1),(T2)(ZGs(1)));
while(!((T6)(((T6)((((((T7*)(Zvz1))->Zdc))==(ZGs(0)))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\057'))))))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\072')))))))
{ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}}if((T6)((!(((((T7*)(Zvz1))->Zdc))==(ZGs(0))))&&((T6)((T6)(((Z0x((T7*)(Zvz1)))!=(((T3)'\057')))&&((T6)((Z0x((T7*)(Zvz1)))!=(((T3)'\072'))))))))){
Zgt((T7*)(Zvz1),((T3)'\057'));}}else if(ZBB1()){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));while(!((T6)((((((T7*)(Zvz1))->Zdc))==(ZGs(0)))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\072')))))))
{ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}if(!(((((T7*)(Zvz1))->Zdc))==(ZGs(0)))){ZIx((T7*)(Zvz1),((T3)'\072'));}}else if(ZDB1()){if((Z0x((T7*)(Zvz1)))==(((T3)'\135'))){
ZFx((T7*)(Zvz1),(T2)(ZGs(1)));while(!((T6)(((T6)((((((T7*)(Zvz1))->Zdc))==(ZGs(0)))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\056'))))))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\133')))))))
{ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}if((Z3)(((((T7*)(Zvz1))->Zdc))>(ZGs(0)))){{int z1=Z0x((T7*)(Zvz1));switch(z1){case 46:ZFx((T7*)(Zvz1),(T2)(ZGs(1)));
Zgt((T7*)(Zvz1),((T3)'\135'));break;default:;if(((((T7*)(Zvz1))->Zdc))==((Z3)(((((((T7*)a1))->Zdc)))-(ZGs(1))))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));
}else{Zgt((T7*)(Zvz1),((T3)'\135'));}}}}}else if((Z0x((T7*)(Zvz1)))==(((T3)'\072'))){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else{ZFx((T7*)(Zvz1),(T2)(ZGs(1)));
while(!((T6)((((((T7*)(Zvz1))->Zdc))==(ZGs(0)))||((T6)((Z0x((T7*)(Zvz1)))==(((T3)'\135'))))))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}if(((((T7*)(Zvz1))->Zdc))==(ZGs(0))){
((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}}}else if(ZoB1()){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else{ZmB1(a1);if(ZoB1()){ZYD1(a1);}
else{((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}}}void Z282(T61*C){T8 ZIX=Zo;(C->ZOb)=Z4r(((*C).ZNb));if((Zo!=((*C).ZOb))){ZIX=Z6r(((*C).ZOb));
Zmt((T7*)(Zvz1),ZIX);}}void Z182(T61*C,T0*a1){T8 ZIG2=Zo;ZIG2=ZQx(((T7*)a1));(C->ZNb)=Z1r(ZIG2);(C->ZOb)=((*C).ZNb);((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));
}void Zuz1(T0*a1,T0*a2){ZWw((T7*)(Zvz1),a1);if((T6)((ZpB1())||((T6)(ZqB1())))){ZIx((T7*)(Zvz1),((T3)'\057'));if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\057'))){
ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}Zmx((T7*)(Zvz1),a2);}else if(ZwB1()){ZIx((T7*)(Zvz1),((T3)'\134'));if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\134'))){
ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}Zmx((T7*)(Zvz1),a2);}else if(ZCB1()){{int z1=Z0x((T7*)(Zvz1));switch(z1){case 58:break;case 47:if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\057'))){
ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}break;default:;if(((((((T7*)a2))->ZUb))[ZGs(0)])!=(((T3)'\057'))){Zgt((T7*)(Zvz1),((T3)'\057'));}}}Zmx((T7*)(Zvz1),a2);
}else if(ZBB1()){ZIx((T7*)(Zvz1),((T3)'\072'));if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\072'))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}Zmx((T7*)(Zvz1),a2);
}else if(ZDB1()){{int z1=Z0x((T7*)(Zvz1));switch(z1){case 93:break;case 46:ZFx((T7*)(Zvz1),(T2)(ZGs(1)));Zgt((T7*)(Zvz1),((T3)'\135'));
break;default:;Zgt((T7*)(Zvz1),((T3)'\135'));}}if(((((((T7*)a2))->ZUb))[ZGs(0)])==(((T3)'\135'))){ZFx((T7*)(Zvz1),(T2)(ZGs(1)));}Zmx((T7*)(Zvz1),a2);
}else if(ZoB1()){((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));}else{ZmB1(a1);if(ZoB1()){Zuz1(a1,a2);}else{((((T7*)((T7*)(Zvz1))))->Zdc)=(ZGs(0));
}}}T6 ZDB1(void){T6 R=0;R=((T6)(((((((T7*)Z0B1))->ZUb))[ZGs(0)])==(((T3)'V'))));return R;}T6 ZqB1(void){T6 R=0;R=((T6)(((((((T7*)Z0B1))->ZUb))[ZGs(0)])==(((T3)'C'))));
return R;}T0*ZJG2=Zo;int ZKG2=0;T0*ZDs1(void){if(ZKG2==0){ZKG2=1;{{Zc9*n=((Zc9*)Zh(sizeof(*n)));*n=ZSl;ZJG2=((T0*)n);ZUE(n,(T2)(Zxt(2048)));
}}}return ZJG2;}T0*ZPH(void){T0*R=Zo;if(!((Z3)(((((Z58*)(ZSO()))->ZWb))<(ZGs(0))))){R=ZcE((Z58*)(ZSO()));}return R;}void ZeH(T43*C,T81
a1,T0*a2,T0*a3){T0*ZKV1=Zo;T0*ZLG2=Zo;T0*ZTC2=Zo;T2 ZJN=0;T2 ZKO=0;T0*Zh31=Zo;T0*Zi31=Zo;ZJN=ZGs(1);ZLG2=ZAP(a2);while(!((Z3)((ZJN)>((Z3)(((((((Ze7*)(((((Z23*)a3))->Zae))))->ZWb)))+(ZGs(1)))))))
{ZKV1=ZIL((ZZ3*)((((((Ze7*)(((((Z23*)a3))->Zae))))->ZUb))[(ZJN)-(ZGs(1))]),a2);ZKO=ZGs(1);ZTC2=ZAP(ZKV1);while(!((Z3)((ZKO)>(Zjy(((Zl2*)(((((Zz6*)ZLG2))->Zie))))))))
{Zh31=Z8a1(((Zz6*)ZLG2),ZKO);Zi31=Z8a1(((Zz6*)ZTC2),ZKO);if((Z9G(Zh31))!=((void*)(Z9G(Zi31)))){Z5G(a1);{T0*b1=Z1G(37,"Unsafe covariant redefinition (type \"");
Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(Zh31);Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(16,"\" redefined as \"");Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(Zi31);Zmx((T7*)(Z2G),b1);
}{T0*b1=Z1G(3,"\").");Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZrP(Zh31),&Zow)));}{T81 Zow;Z5G((*(Zow=ZrP(Zi31),&Zow)));}ZPG((T80*)(Z4G));
(C->ZQk)=ZGs(4);}ZKO=(Z3)(((ZKO))+(ZGs(1)));}ZJN=(Z3)(((ZJN))+(ZGs(1)));}}T0*ZMG2(void){if(Z7P==0){Z7P=1;{T81 Z9P={Zo,Zo,0};{Z83*n=((Z83*)Zh(sizeof(*n)));
*n=Zge;Z6P=((T0*)n);ZaP(n,Z9P);}}}return Z6P;}void ZNG2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}void ZC02(T0*a1){
T0*ZOG2=Zo;ZOG2=ZPG2;ZWw(((T7*)ZOG2),a1);while(!((ZYw(((T7*)ZOG2),((T3)'\137')))==(ZGs(1)))){ZFx(((T7*)ZOG2),(T2)(ZGs(1)));}if(!(ZfF((ZG9*)(ZQG2()),ZOG2))){
ZOG2=Z7t(((T7*)ZOG2));ZgF((ZG9*)(ZQG2()),ZOG2);}}T0*ZRG2=Zo;int ZSG2=0;T0*ZcX1(void){if(ZSG2==0){ZSG2=1;{{Zr4*n=((Zr4*)Zh(sizeof(*n)));
*n=Zwg;ZRG2=((T0*)n);ZQB(n,(T2)(Zxt(512)));}}}return ZRG2;}T0*ZTG2=Zo;int ZUG2=0;T0*Z8J1(void){if(ZUG2==0){ZUG2=1;{{Ze7*n=((Ze7*)Zh(sizeof(*n)));
*n=ZNj;ZTG2=((T0*)n);ZLD(n,(T2)(Zxt(2048)));}}}return ZTG2;}void Z3i1(T0*a1){T0*ZkL=Zo;ZvP((T38*)(ZVG2()),ZWG2);ZvP((T38*)(ZVG2()),a1);
ZvP((T38*)(ZVG2()),ZXG2);ZvP((T38*)(ZVG2()),(((T77*)(ZYG2()))->Ztc));ZvP((T38*)(ZVG2()),ZZG2);ZkL=Z_G2((ZQ9*)(ZbP));}T6 ZeB2(T0*a1){T6
R=0;if((ZjI)==((void*)(a1))){R=((T6)(1));}else if((ZyI)==((void*)(a1))){R=((T6)(1));}else if((ZuI)==((void*)(a1))){R=((T6)(1));}else if((ZoI)==((void*)(a1))){
R=((T6)(1));}else if((Z8I)==((void*)(a1))){R=((T6)(1));}else if((ZnI)==((void*)(a1))){R=((T6)(1));}return R;}T0*Z0H2(void){if(ZE_==0){ZE_=1;{
{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;ZD_=((T0*)n);ZG_(n);}}}return ZD_;}void Z8H(T43*C){(C->ZZk)=(Z3)(((((C)->ZZk)))+(ZGs(1)));}void Z1H2(T43*C){
{T2 Zet=0;T2 ZOP=0;T0*ZMd1=Zo;T0*ZJH=Zo;T0*ZCq1=Zo;ZvP((T38*)(ZVC2()),Z2H2);ZSP((T38*)(ZVC2()),(((ZK9*)(ZNC2()))->Zdc));Zet=ZGs(1);while(!((Z3)((Zet)>((((ZK9*)(ZNC2()))->Zdc)))))
{ZMd1=ZkF((ZK9*)(ZNC2()),Zet);ZJH=((((Z64*)ZMd1))->Znf);ZCq1=((((ZZ3*)ZJH))->Zof);ZOP=(Z3)(((ZOP))+((((Z44*)(((((Z64*)ZMd1))->Zpf)))->Zdc)));
Zet=(Z3)(((Zet))+(ZGs(1)));}ZvP((T38*)(ZVC2()),Z3H2);ZSP((T38*)(ZVC2()),ZOP);ZvP((T38*)(ZVC2()),Z4H2);}{int z1=((C)->ZQk);switch(z1){
case 4:{T0*b1=Z1G(63,"The system is not type safe (read previous warnings carefully.)");Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));break;case
5:ZvP((T38*)(ZVG2()),Z1G(78,"Type-system safety check not performed in this mode (use flag -safety_check).\n"));break;default:;ZvP((T38*)(ZVG2()),Z1G(25,"The system is type safe.\n"));
}}{T6 Z5H2=0;if((((T38*)(Z6H2()))->ZKh)){Z5H2=((T6)(1));}else if((((T80*)(Z4G))->ZGg)){}else{Z5H2=((T6)(1));}if(Z5H2){Z7H2((((T80*)(Z4G))->ZFg),Z8H2);
}}Z7H2((((T80*)(Z4G))->ZEg),Z9H2);ZvP((T38*)(ZVG2()),ZaH2);}void Zpy2(T43*C){T2 ZbH2=0;ZbH2=(T2)((Z2)((((((T42*)(ZcH2()))->ZKd)))+(ZGs(1))));
ZHI1((Z84*)(ZkH),ZdH2,ZbH2);if(((C)->ZVk)){ZQA2((Z84*)(ZkH),ZeH2,ZbH2);}if(((C)->ZUk)){ZQA2((Z84*)(ZkH),ZfH2,ZbH2);}if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
ZQA2((Z84*)(ZkH),ZgH2,ZbH2);ZWw((T7*)(ZhH2),ZiH2);Z6t(ZbH2,ZhH2);Zmx((T7*)(ZhH2),ZjH2);Znw2((Z84*)(ZkH),ZhH2);ZWw((T7*)(ZhH2),ZkH2);Z6t(ZbH2,ZhH2);
Zgt((T7*)(ZhH2),((T3)'\135'));Znw2((Z84*)(ZkH),ZhH2);if(ZDu2((T89*)(ZPM))){ZWw((T7*)(ZhH2),ZlH2);Z6t(ZbH2,ZhH2);Zmx((T7*)(ZhH2),ZmH2);
Znw2((Z84*)(ZkH),ZhH2);ZWw((T7*)(ZhH2),ZnH2);Z6t(ZbH2,ZhH2);Zmx((T7*)(ZhH2),ZoH2);Znw2((Z84*)(ZkH),ZhH2);}}}T0*ZhH2=Zo;void ZpH2(T43*C){
T2 Zet=0;T6 Z5H2=0;T0*ZJH=Zo;Z5H2=((T6)((((T89*)(ZPM))->Z4f)));if(Z5H2){(C->ZQk)=ZGs(6);ZqH2(C,ZrH2);if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
if(((((ZZ3*)ZJH))->Zrh)){ZMr1(((ZZ3*)ZJH));}Zet=(Z3)(((Zet))-(ZGs(1)));}}else{(C->ZQk)=ZGs(5);}}void ZsH2(T43*C){T0*ZJH=Zo;T2 Zet=0;T2
ZtH2=0;ZvP((T38*)(ZVG2()),ZuH2);ZSP((T38*)(ZVG2()),((C)->ZZk));ZvP((T38*)(ZVG2()),ZvH2);while(!((ZtH2)==(((C)->ZZk)))){ZtH2=((C)->ZZk);
ZWP((T38*)(ZVG2()),((T3)'\056'));if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));
ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];ZOr1(((ZZ3*)ZJH));
Zet=(Z3)(((Zet))-(ZGs(1)));}}ZvP((T38*)(ZVG2()),ZwH2);ZSP((T38*)(ZVG2()),((C)->ZZk));ZvP((T38*)(ZVG2()),ZxH2);}void ZpG(T81 a1,T0*a2,T0*a3){
T2 Zet=0;T0*Z1p2=Zo;Z1p2=ZAP(a3);if((a2)==((void*)(Zo))){if((Z1p2)!=((void*)(Zo))){Z5G(a1);{T81 Zow;Z5G((*(Zow=ZRa1(((Zz6*)Z1p2)),&Zow)));
}{T0*b1=Z1G(23,ZLp);Zmx((T7*)(Z2G),b1);}Zet=Zjy(((Zl2*)(((((Zz6*)Z1p2))->Zie))));{T2 b1=Zet;Z6t(b1,Z2G);}{T0*b1=Z1G(9,Zyq);Zmx((T7*)(Z2G),b1);
}if((Z3)((Zet)>(ZGs(1)))){{T3 b1=((T3)'s');Zgt((T7*)(Z2G),b1);}}{T0*b1=Z1G(38,". (The actual argument list is empty.)");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}}else if((Z1p2)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(a3),&Zow)));}{T81 Zow;Z5G((*(Zow=Z2H(((Za3*)a2)),&Zow)));}
{T0*b1=Z1G(6,"There ");Zmx((T7*)(Z2G),b1);}Zet=Z5H1(((Za3*)a2));if((Z3)((Zet)>(ZGs(1)))){{T0*b1=Z1G(4,"are ");Zmx((T7*)(Z2G),b1);}}else{
{T0*b1=Z1G(3,"is ");Zmx((T7*)(Z2G),b1);}}{T2 b1=Zet;Z6t(b1,Z2G);}{T0*b1=Z1G(16," actual argument");Zmx((T7*)(Z2G),b1);}if((Z3)((Zet)>(ZGs(1)))){
{T3 b1=((T3)'s');Zgt((T7*)(Z2G),b1);}}{T0*b1=Z1G(38,". (The feature found has no argument.)");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{
ZhH1(((Za3*)a2),a3);}}void ZqH2(T43*C,T0*a1){ZvP((T38*)(ZVG2()),a1);ZvP((T38*)(ZVG2()),ZyH2);ZSP((T38*)(ZVG2()),((C)->ZZk));ZvP((T38*)(ZVG2()),ZzH2);
}T0*ZAH2=Zo;int ZBH2=0;T0*ZQG2(void){if(ZBH2==0){ZBH2=1;{{ZG9*n=((ZG9*)Zh(sizeof(*n)));*n=Zfm;ZAH2=((T0*)n);{ZG9*C1=n;ZhF(C1,ZGs(53));
}}}}return ZAH2;}T0*ZCH2(void){if(Zw91==0){Zw91=1;{{Za4*n=((Za4*)Zh(sizeof(*n)));*n=ZZf;Zv91=((T0*)n);}}}return Zv91;}void ZmF2(T43*C){
T0*ZDH2=Zo;T0*ZEH2=Zo;T0*ZJH=Zo;T2 ZFH2=0;T2 Zet=0;T6 ZGH2=0;ZDH2=ZIx1();ZEH2=ZUv2((T89*)(ZPM));ZHH2(C,ZDH2,ZEH2);if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
Z2A2((Z84*)(ZkH));ZZT((Z84*)(ZkH));ZGH2=((T6)(!((((Zj8*)(ZIH2()))->ZLk))));if(((((T89*)(ZPM))->Zaf))==(ZGs(1))){ZWR1((Z84*)(ZkH),ZJH2);
}if(ZDu2((T89*)(ZPM))){ZWR1((Z84*)(ZkH),ZKH2);}if(ZGH2){ZWR1((Z84*)(ZkH),ZLH2);}if((((Za4*)(ZCH2()))->ZYf)){ZWR1((Z84*)(ZkH),ZMH2);}if(((C)->ZXk)){
ZWR1((Z84*)(ZkH),ZNH2);}if(((C)->ZXk)){ZVd1((Z84*)(ZkH),ZOH2);ZVd1((Z84*)(ZkH),ZPH2);ZxD1((T51*)(Z0H2()));}ZXA2((Z84*)(ZkH),ZQH2);ZAt2((ZG3*)(ZpR));
if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());
}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];if(((((ZZ3*)ZJH))->Zrh)){ZFH2=(Z3)(((ZFH2))+(ZGs(1)));
}Zeu1(((ZZ3*)ZJH));Zet=(Z3)(((Zet))-(ZGs(1)));}ZXA2((Z84*)(ZkH),ZRH2);if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
Zgu1(((ZZ3*)ZJH));Zet=(Z3)(((Zet))-(ZGs(1)));}ZXA2((Z84*)(ZkH),ZSH2);if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
Zhu1(((ZZ3*)ZJH));Zet=(Z3)(((Zet))-(ZGs(1)));}ZXA2((Z84*)(ZkH),ZTH2);if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
Zju1(((ZZ3*)ZJH));Zet=(Z3)(((Zet))-(ZGs(1)));}if(!(ZRE((Zc9*)(ZDs1()),ZOK))){ZgM((Z84*)(ZkH),ZUH2);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
ZdS((Z84*)(ZkH),ZVH2,ZWH2);}}ZHB2((T6)(ZXH2()));Z6z2((Z84*)(ZkH),ZQG2());if(ZGH2){(((void)((Zj8*)(ZIH2()))));if((((T43*)(ZSG))->ZXk)){
ZLI1(Z1G(58,"The Garbage Collector cannot currently be used with SCOOP."));}ZvP((T38*)(ZMI1()),ZYH2);{T2 ZZH2=0;T2 Z_H2=0;T2 Zet=0;T0*Z6J1=Zo;
T0*ZJH=Zo;T2 Z0I2=0;Z6J1=Z8J1();Zet=((((Ze7*)Z6J1))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=(((((Ze7*)Z6J1))->ZUb))[Zet];if(((((ZZ3*)ZJH))->Zrh)){
if(ZmH(((((ZZ3*)ZJH))->Z4c))){Z_H2=(Z3)(((Z_H2))+(ZGs(1)));}else{ZZH2=(Z3)(((ZZH2))+(ZGs(1)));}}Zet=(Z3)(((Zet))-(ZGs(1)));}ZZH2=(Z3)(((ZGs(4)))*(ZZH2));
Z0I2=(Z3)(((ZZH2))*(ZGs(8)));if((Z3)((Z0I2)<(Zxt(256)))){ZZH2=ZGs(32);}Z_H2=(Z3)(((ZGs(3)))*(Z_H2));Z0I2=(Z3)(((Z_H2))*(ZGs(32)));if((Z3)((Z0I2)<(Zxt(256)))){
Z_H2=ZGs(8);}ZTA2((Z84*)(ZkH),Z1I2,ZZH2);ZTA2((Z84*)(ZkH),Z2I2,Z_H2);}ZZT((Z84*)(ZkH));}{T0*ZJH=Zo;T0*Z3I2=Zo;T0*ZRU=Zo;T2 Z4I2=0;T2 Zet=0;
T6 Zd22=0;T0*ZKT=Zo;ZvP((T38*)(ZVG2()),Z5I2);ZSP((T38*)(ZVG2()),(((Zc9*)(ZDs1()))->Zdc));ZvP((T38*)(ZVG2()),Z6I2);ZXT((Z84*)(ZkH));if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
ZRU=((((ZZ3*)ZJH))->Z4c);if(ZIG(ZRU)){Zis1(((ZZ3*)ZJH),(T2)(ZGs(0)));}else if(ZwU(ZRU)){Z3I2=ZJH;}Zet=(Z3)(((Zet))-(ZGs(1)));}if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
ZRU=((((ZZ3*)ZJH))->Z4c);if(ZMR(ZRU)){Zis1(((ZZ3*)ZJH),(T2)(ZGs(0)));}Zet=(Z3)(((Zet))-(ZGs(1)));}if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
ZKT=(((T85*)(((((ZZ3*)ZJH))->Zfe)))->Zse);if((ZiI)==((void*)(ZKT))){Zis1(((ZZ3*)ZJH),(T2)(ZGs(0)));}Zet=(Z3)(((Zet))-(ZGs(1)));}if((Z3I2)!=((void*)(Zo))){
Zis1(((ZZ3*)Z3I2),(T2)(ZGs(0)));}if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));
ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];ZRU=((((ZZ3*)ZJH))->Z4c);
ZKT=(((T85*)(ZBT(ZRU)))->Zse);if((T6)(((ZWH)==((void*)(ZKT)))||((T6)((Z7I)==((void*)(ZKT)))))){Zis1(((ZZ3*)ZJH),(T2)(ZGs(0)));}Zet=(Z3)(((Zet))-(ZGs(1)));
}if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());
}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];ZRU=((((ZZ3*)ZJH))->Z4c);if(Z9U(ZRU)){
Zis1(((ZZ3*)ZJH),(T2)(ZGs(0)));}Zet=(Z3)(((Zet))-(ZGs(1)));}Z4I2=ZGs(6);while(!(Zd22)){Zd22=((T6)(1));if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
if(!(((((ZZ3*)ZJH))->Zsh))){Zd22=((T6)(0));Zis1(((ZZ3*)ZJH),Z4I2);}Zet=(Z3)(((Zet))-(ZGs(1)));}Z4I2=(Z3)(((Z4I2))-(ZGs(1)));}}Znx2((Z84*)(ZkH));
if(ZDu2((T89*)(ZPM))){{T2 Zet=0;ZXT((Z84*)(ZkH));Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZMs1((ZZ3*)(((((Ze7*)(Z8J1()))->ZUb))[Zet]));
Zet=(Z3)(((Zet))-(ZGs(1)));}}}Zkw2((Z84*)(ZkH),((C)->ZYk));ZTB2((Zc5*)(ZgI1),(T6)(ZXH2()));{T2 Zet=0;Zet=(((Zr4*)(ZcX1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{ZCX1((ZG7*)(((((Zr4*)(ZcX1()))->ZUb))[Zet]));Zet=(Z3)(((Zet))-(ZGs(1)));}}{T2 Zet=0;Zet=(((Z58*)(Z3u2()))->ZWb);if((Z3)((Zet)>=(ZGs(0)))){
while(!((Z3)((Zet)<(ZGs(0))))){Z7I2(((((Z58*)(Z3u2()))->ZUb))[Zet],((((ZB2*)(Z4u2()))->ZUb))[Zet]);Zet=(Z3)(((Zet))-(ZGs(1)));}}}if(ZGH2){
Z5J1((Zj8*)(ZIH2()));}Z2E2((Z36*)(Z7e1));{T0*Z0B2=Zo;T2 Z8I2=0;T2 Z9I2=0;T2 ZaI2=0;int ZHw2=0;ZvP((T38*)(Z2B2()),ZbI2);if(!(((((ZQ1*)(Z1B2()))->Zdc))==(ZGs(0)))){
ZXT((Z84*)(ZkH));Z8I2=ZGs(1);while(!((Z3)((Z8I2)>((((ZQ1*)(Z1B2()))->Zdc))))){Z0B2=ZbA((ZQ1*)(Z1B2()),Z8I2);Z9I2=ZGs(1);while(!((Z3)((Z9I2)>(((((ZR6*)Z0B2))->Zdc)))))
{Zms1((Z84*)(ZkH),(T2)(ZGs(3)));ZQt2(ZdD(((ZR6*)Z0B2),Z9I2));ZaI2=(Z3)(((ZaI2))+(ZGs(1)));Z9I2=(Z3)(((Z9I2))+(ZGs(1)));}Z8I2=(Z3)(((Z8I2))+(ZGs(1)));
}}ZPv1((T38*)(Z2B2()),ZcI2,ZaI2);}{T2 Zet=0;T0*Z1t2=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>((((Z27*)(Zct2()))->Zdc))))){Z1t2=ZzD((Z27*)(Zct2()),Zet);
Z_f2(((Zu9*)Z1t2));Zet=(Z3)(((Zet))+(ZGs(1)));}}Z7A2((Z84*)(ZkH));if(((C)->ZXk)){(((void)((ZS*)(ZdI2()))),Z3N(Z8J1()));}ZtA2((Z84*)(ZkH));
Z1H2(C);}else{{T0*b1=Z1G(22,"Cannot produce C code.");Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}}T0*ZYG2(void){if(Zli1==0){Zli1=1;{{T77*n=((T77*)Zh(sizeof(*n)));
*n=M77;Zki1=((T0*)n);Zni1(n);}}}return Zki1;}T0*ZeI2=Zo;int ZfI2=0;T0*ZgI2(void){if(ZfI2==0){ZfI2=1;{{Zv4*n=((Zv4*)Zh(sizeof(*n)));*n=Zyg;
ZeI2=((T0*)n);ZVB(n,(T2)(Zxt(1024)));}}}return ZeI2;}void ZhI2(T43*C){T0*ZJH=Zo;T2 Zet=0;T0*ZOP=Zo;T0*Z7J1=Zo;T81 ZjG={Zo,Zo,0};T0*ZQ31=Zo;
if(((C)->ZVk)){(((void)((ZF6*)(ZiI2()))),Zr12());}{T2 Zet=0;Zet=(((Z58*)(Z3u2()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZhP(((((Z58*)(Z3u2()))->ZUb))[Zet]);
Zet=(Z3)(((Zet))-(ZGs(1)));}}Z_s2((ZG3*)(ZpR));if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));
ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];ZOP=(((T85*)(((((ZZ3*)ZJH))->Zfe)))->Zse);
if((T6)((ZeB2(ZOP))||((T6)((ZOP)==((void*)(ZZH)))))){}else{ZQ31=((((ZZ3*)ZJH))->Z4c);if(Zo!=(ZQ31)){switch(((T0*)ZQ31)->id){case 290:
break;default:ZQ31=Zo;}}if((ZQ31)==((void*)(Zo))){Zts1(((ZZ3*)ZJH));}else if(ZzT(((((ZK1*)ZQ31))->Zbd))){Zts1(((ZZ3*)ZJH));if((((C)->Z_k))==((void*)(Zo))){
{Z3a*n=((Z3a*)Zh(sizeof(*n)));*n=ZWm;{Z3a*C1=n;ZNF(C1,ZGs(53));}(C->Z_k)=((T0*)n);}}ZMF((Z3a*)(((C)->Z_k)),ZJH);}}Zet=(Z3)(((Zet))-(ZGs(1)));
}if((((C)->Z_k))!=((void*)(Zo))){ZED2(((C)->Z_k));}if((((T43*)(ZSG))->ZXk)){Z7J1=(((ZG7*)(((C)->ZYk)))->Z4c);if(!(Z3L(Z7J1))){{T81 Zow;
ZjG=(*(Zow=ZrP(Z7J1),&Zow));}Z7J1=(((void)((ZS*)(ZdI2()))),Z4N(ZjG,Z7J1));Z7J1=ZxP(Z7J1,ZMG2());(C->ZYk)=ZyP((ZZ3*)(Z_G(Z7J1)),(((ZG7*)(((C)->ZYk)))->Zpc));
if(Zo!=((C->ZYk))){switch(((T0*)(C->ZYk))->id){case 451:break;default:(C->ZYk)=Zo;}}}}}T6 Z0b1(T0*a1,T0*a2){T6 R=0;if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)a2))->Zae))))->ZWb)))+(ZGs(1))))<=(ZGs(1)))){
R=((T6)(1));}else{R=((T6)(ZxT(a1,a2)));}return R;}T0*ZiI2(void){if(ZEI1==0){ZEI1=1;{T81 Z9P={Zo,Zo,0};{ZF6*n=((ZF6*)Zh(sizeof(*n)));*n=Zgj;
ZDI1=((T0*)n);ZFI1(n,Z9P);}}}return ZDI1;}T0*ZIH2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));*n=ZOk;ZMM=((T0*)n);}}}return
ZMM;}T0*ZVG2(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}void Zrn1(T43*C,T0*a1){T0*ZIX=Zo;
ZIX=((((T87*)a1))->Zpc);ZuC((ZO5*)(ZDy2()),a1,ZIX);Z8H(C);}T0*ZGJ1(T0*a1){T0*R=Zo;R=ZzC((ZO5*)(ZDy2()),a1);return R;}T0*Zin1(T0*a1){T0*R=Zo;
T0*ZkL=Zo;T0*ZjI2=Zo;R=ZVE((Zc9*)(ZDs1()),((((T85*)a1))->Zse));if((R)==((void*)(Zo))){ZkL=ZzC((ZO5*)(ZDy2()),a1);if((ZkL)!=((void*)(Zo))){
{ZJ6*n=((ZJ6*)Zh(sizeof(*n)));*n=Zjj;((((ZJ6*)(n)))->Zfe)=(((((T87*)ZkL))->Zpc));ZjI2=((T0*)n);}R=ZKJ1(((ZJ6*)ZjI2));}else{{T0*b1=Z1G(33,"SMART_EIFFEL Internal error for: ");
Zmx((T7*)(Z2G),b1);}{T0*b1=((((T85*)a1))->Zse);Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}return R;}T0*Zc41(T0*a1){T0*R=Zo;R=ZzC((ZO5*)(ZDy2()),a1);
if((R)==((void*)(Zo))){if(ZeB2(((((T85*)a1))->Zse))){{T87*n=((T87*)Zh(sizeof(*n)));*n=M87;Zvf1(n,((((T85*)a1))->Zse));R=((T0*)n);}ZSP((T38*)(ZVG2()),(((ZO5*)(ZDy2()))->Zdc));
ZWP((T38*)(ZVG2()),((T3)'\011'));ZWP((T38*)(ZVG2()),((T3)'\050'));ZvP((T38*)(ZVG2()),((((T85*)a1))->Zse));ZWP((T38*)(ZVG2()),((T3)'\051'));
ZWP((T38*)(ZVG2()),((T3)'\n'));}else if((((ZQ9*)(ZbP))->Zmm)){{T0*b1=Z1G(34,"Internal Error #1 in SMART_EIFFEL.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}else{if(ZFv2((T89*)(ZPM),((((T85*)a1))->Zse))){R=ZkI2((ZQ9*)(ZbP),a1);}if((R)==((void*)(Zo))){Z5G(((((T85*)a1))->ZCb));
{T0*b1=Z1G(22,"Unable to load class \"");Zmx((T7*)(Z2G),b1);}{T0*b1=((((T85*)a1))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(2,ZEn);Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}}}Zsn1(((T87*)R),a1);return R;}void ZV12(T0*a1){if(!(ZSB((Zv4*)(ZgI2()),a1))){ZUB((Zv4*)(ZgI2()),a1);}}T0*ZlI2=Zo;
int ZmI2=0;T0*ZDy2(void){if(ZmI2==0){ZmI2=1;{{ZO5*n=((ZO5*)Zh(sizeof(*n)));*n=ZPh;ZlI2=((T0*)n);ZyC(n,(T2)(Zxt(1024)));}}}return ZlI2;
}T6 ZXH2(void){T6 R=0;T0*ZJH=Zo;if(ZRE((Zc9*)(ZDs1()),ZvI)){ZJH=ZPE((Zc9*)(ZDs1()),ZvI);R=((T6)(((((ZZ3*)ZJH))->Zrh)));}return R;}T6 ZYG(T0*a1,T0*a2){
T6 R=0;T2 Zet=0;T0*Z6O=Zo;T0*ZKV1=Zo;T0*ZJH=Zo;R=((T6)(1));Zet=(Z3)(((((((Ze7*)(((((Z23*)a2))->Zae))))->ZWb)))+(ZGs(1)));Z6O=Z0X(a1);
while(!((T6)((!(R))||((T6)((Zet)==(ZGs(0))))))){ZJH=(((((Ze7*)(((((Z23*)a2))->Zae))))->ZUb))[(Zet)-(ZGs(1))];ZKV1=ZIL(((ZZ3*)ZJH),a1);
if((Z6O)==((void*)(Z0X(ZKV1)))){if(((((ZD8*)(((((ZQ7*)ZKV1))->Zpc)))->Zse))!=((void*)((((ZD8*)(((((ZQ7*)a1))->Zpc)))->Zse)))){R=((T6)(0));
}}else{R=((T6)(0));}Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T0*ZnI2=Zo;int ZoI2=0;T0*ZSO(void){if(ZoI2==0){ZoI2=1;{{Z58*n=((Z58*)Zh(sizeof(*n)));
*n=ZEk;ZnI2=((T0*)n);ZkE(n,(T2)(ZGs(50)));}}}return ZnI2;}void ZdW(T81 a1){Z5G(a1);{T0*b1=Z1G(46,"Type \"reference BIT_N\" is not yet implemented.");
Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T0*ZpI2=Zo;int ZqI2=0;T0*ZdI2(void){if(ZqI2==0){ZqI2=1;{{ZS*n=((ZS*)Zh(1));ZpI2=((T0*)n);}}}return
ZpI2;}T0*ZcH2(void){if(ZJn1==0){ZJn1=1;{{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;ZIn1=((T0*)n);ZK_(n);}}}return ZIn1;}void ZqF2(T0*a1,T0*a2){
T0*ZkL=Zo;T0*ZJH=Zo;T0*Zfz2=Zo;T0*ZWF=Zo;if((a2)==((void*)(ZjI))){}else{ZJH=ZVE((Zc9*)(ZDs1()),a2);if((ZJH)!=((void*)(Zo))){ZkL=((((ZZ3*)ZJH))->Zvb);
}else{{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zb41(n,a2);ZWF=((T0*)n);}ZkL=ZzC((ZO5*)(ZDy2()),ZWF);}}ZgU(a1,((T3)'\n'));if((ZkL)!=((void*)(Zo))){
ZdU(a1,ZrI2);Zfz2=((((T87*)ZkL))->Ztc);ZdU(a1,Zfz2);ZgU(a1,((T3)'\042'));ZgU(a1,((T3)'\n'));ZKn1(((T87*)ZkL),a1);}if((ZJH)!=((void*)(Zo))){
ZRt1(((ZZ3*)ZJH),a1);}}T0*ZKr1(void){T0*R=Zo;T0*ZWF=Zo;{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zb41(n,ZhI);ZWF=((T0*)n);}R=ZzC((ZO5*)(ZDy2()),ZWF);
return R;}T0*ZyU(T0*a1){T0*R=Zo;T0*ZtW=Zo;ZtW=Z9G(a1);R=ZVE((Zc9*)(ZDs1()),ZtW);if((R)==((void*)(Zo))){{ZZ3*n=((ZZ3*)Zh(sizeof(*n)));
*n=ZCh;ZBs1(n,a1,ZtW);R=((T0*)n);}}return R;}T6 Zfu1(T0*a1){T6 R=0;T2 Zet=0;T0*ZdH=Zo;if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0))))))))
{ZdH=(((ZZ3*)(((((Ze7*)(Z8J1()))->ZUb))[Zet]))->Zof);if(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(0))){}else
if(ZKF(((Z3a*)(((((Z23*)ZdH))->Z9e))),a1)){R=((T6)((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))));}Zet=(Z3)(((Zet))-(ZGs(1)));
}return R;}void ZHH2(T43*C,T0*a1,T0*a2){T0*Z3r1=Zo;T0*ZsI2=Zo;T0*ZtI2=Zo;T0*Z7J1=Zo;T2 ZuI2=0;T0*ZvI2=Zo;if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
((((T43*)(C)))->ZVk)=(1);((((T43*)(C)))->ZUk)=(1);}ZGu2((T89*)(ZPM));{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zb41(n,a1);ZvI2=((T0*)n);}ZsI2=Zc41(ZvI2);
if((ZsI2)==((void*)(Zo))){{T0*b1=Z1G(23,"Cannot load root class ");Zmx((T7*)(Z2G),b1);}{T0*b1=a1;Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);
}Z3G((T80*)(Z4G));}else if(((((T87*)ZsI2))->Zfg)){Z5G((((T85*)(((((T87*)ZsI2))->Zpc)))->ZCb));{T0*b1=Z1G(86,"The root class must not be expanded (sorry, but this is a limitation of the compiler).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{Z3r1=Zxn1(((T87*)ZsI2),a2);ZtI2=Zhn1(((T87*)ZsI2),Z3r1);}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
if((((((Zda*)ZtI2))->ZFb))!=((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZKX1(((Zda*)ZtI2)),&Zow)));}{T0*b1=Z1G(43,"Creation procedure must not have arguments.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){Z7J1=(((ZZ3*)(Zin1(((((T87*)ZsI2))->Zpc))))->Z4c);}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
(C->ZYk)=Zbu1(((Zda*)ZtI2),Z7J1,Z3r1);}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){ZSF2((ZD6*)(ZcP));(C->ZQk)=ZGs(1);ZqH2(C,ZwI2);if(((C)->ZXk)){
ZvP((T38*)(ZVG2()),ZxI2);}ZhI2(C);while(!((T6)(((ZuI2)==(((C)->ZZk)))||((T6)((Z3)(((((T80*)(Z4G))->ZEg))>(ZGs(0)))))))){ZuI2=((C)->ZZk);
ZhI2(C);}ZqH2(C,ZyI2);}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){(C->ZQk)=ZGs(2);ZqH2(C,ZzI2);{T0*ZJH=Zo;T2 Zet=0;if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
Z4t1(((ZZ3*)ZJH));Zet=(Z3)(((Zet))-(ZGs(1)));}ZVF2((ZD6*)(ZcP));}while(!((T6)(((ZuI2)==(((C)->ZZk)))||((T6)((Z3)(((((T80*)(Z4G))->ZEg))>(ZGs(0))))))))
{ZuI2=((C)->ZZk);{T0*ZJH=Zo;T2 Zet=0;if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));
ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];Z4t1(((ZZ3*)ZJH));
Zet=(Z3)(((Zet))-(ZGs(1)));}ZVF2((ZD6*)(ZcP));}}{T2 Zet=0;T0*ZAI2=Zo;T0*ZJH=Zo;Zet=(((Zv4*)(ZgI2()))->ZWb);ZPv1((T38*)(ZVG2()),ZBI2,(Z3)(((Zet))+((T2)(ZGs(1)))));
while(!((Z3)((Zet)<(ZGs(0))))){ZAI2=((((Zv4*)(ZgI2()))->ZUb))[Zet];ZJH=Z_G(((((ZQ7*)ZAI2))->Z4c));if(((((ZZ3*)ZJH))->Zrh)){{T0*b1=(((ZD8*)(((((ZQ7*)ZAI2))->Zpc)))->Zse);
Zmx((T7*)(Z2G),b1);}{T0*b1=ZCI2;Zmx((T7*)(Z2G),b1);}{T0*b1=ZcT(((((ZQ7*)ZAI2))->Z4c));Zmx((T7*)(Z2G),b1);}{T81 Zow;ZNG2((*(Zow=Z8G(ZAI2),&Zow)),Z0O);
}}Zet=(Z3)(((Zet))-(ZGs(1)));}}{T2 Zet=0;Zet=ZGs(1);while(!((Z3)((Zet)>((((ZO5*)(ZDy2()))->Zdc))))){ZWm1((T87*)(ZwC((ZO5*)(ZDy2()),Zet)));
Zet=(Z3)(((Zet))+(ZGs(1)));}}ZqH2(C,ZDI2);{T2 Zet=0;T0*Z9A2=Zo;T0*ZaA2=Zo;T0*Z641=Zo;T0*Z741=Zo;T0*ZEt2=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>((((Z96*)(ZbA2()))->Zdc)))))
{ZEt2=ZPC((Z96*)(ZbA2()),Zet);Z9A2=((((ZB6*)ZEt2))->ZGd);ZaA2=((((ZB6*)ZEt2))->ZHd);if(ZX01(Z9A2)){if(ZbL(ZaA2)){Z641=Z_G(Z9A2);Z741=Z_G(ZaA2);
}}else if(ZX01(ZaA2)){if(ZbL(Z9A2)){Z641=Z_G(Z9A2);Z741=Z_G(ZaA2);}}if((Z641)!=((void*)(Zo))){Z1u1(((ZZ3*)Z641),Z741);Z1u1(((ZZ3*)Z741),Z641);
Z641=Zo;}Zet=(Z3)(((Zet))+(ZGs(1)));}}ZqH2(C,ZEI2);while(!((T6)(((ZuI2)==(((C)->ZZk)))||((T6)((Z3)(((((T80*)(Z4G))->ZEg))>(ZGs(0))))))))
{ZqH2(C,ZFI2);ZuI2=((C)->ZZk);ZhI2(C);{T0*ZJH=Zo;T2 Zet=0;if(((Z3)((((((Ze7*)(Z8J1()))->ZWb)))+(ZGs(1))))!=((((Zc9*)(ZDs1()))->Zdc))){
((((Ze7*)((Ze7*)(Z8J1()))))->ZWb)=(ZGs(-1));ZTE((Zc9*)(ZDs1()),Z8J1());}Zet=(((Ze7*)(Z8J1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZJH=((((Ze7*)(Z8J1()))->ZUb))[Zet];
Z4t1(((ZZ3*)ZJH));Zet=(Z3)(((Zet))-(ZGs(1)));}ZVF2((ZD6*)(ZcP));}}ZqH2(C,ZGI2);}if(!(ZgB2())){{T0*b1=Z1G(47,"Internal Warning #1 (Error Handler Not Empty): ");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){ZpH2(C);ZPv1((T38*)(ZVG2()),ZHI2,(((ZO5*)(ZDy2()))->Zdc));
}if((T6)(((T6)((((((T80*)(Z4G))->ZEg))==(ZGs(0)))&&((T6)(!(((C)->ZSk))))))&&((T6)(!(((C)->ZRk)))))){ZsH2(C);}}
#ifdef __cplusplus
}
#endif

