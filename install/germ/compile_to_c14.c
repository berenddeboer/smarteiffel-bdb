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
T0*Z_p1(Zq5*C,T0*a1,T0*a2){T0*R=Zo;{T81 Zow;Z5G((*(Zow=Z0q1(C),&Zow)));}Z1q1(((((ZD8*)a1))->ZCb),Z1G(42,"An attribute must not be undefined (VDUS)."));
ZTN(((T87*)a2),a1);return R;}void Z2q1(Zq5*C,T0*a1,T0*a2,T2 a3){T0*Zem1=Zo;T81 ZjG={Zo,Zo,0};T0*ZuW=Zo;T0*ZKX=Zo;(C->Zvb)=a1;{Zz8*n=((Zz8*)Zh(sizeof(*n)));
*n=Z9l;((((Zz8*)(n)))->ZGd)=(a2);Zem1=((T0*)n);}{T81*C1=&ZjG;T0*b1=a1;Z3m1(C1,(T2)(ZGs(1)),(T2)(ZGs(1)),((((T87*)b1))->_id),b1);}{Zg5*n=((Zg5*)Zh(sizeof(*n)));
*n=Zjh;Z3q1(n,ZjG);ZuW=((T0*)n);}{Zw1*n=((Zw1*)Zh(sizeof(*n)));*n=ZQl;ZMN(n,(T11)(a3),ZjG);ZKX=((T0*)n);}Z4q1(C,Zem1,ZuW,ZKX);(C->Zjc)=Z5q1();
}void Z1q1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T6 Z6q1(Zq5*C,T0*a1,T0*a2){T6 R=0;if((((C)->Zlc))!=((void*)(ZBL(a1)))){
if((T6)(((((C)->Zlc))==((void*)(Zo)))||((T6)((ZBL(a1))==((void*)(Zo)))))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Z1q1((*(Zow=Z0q1(C),&Zow)),ZWN);
}}}if((Zo)!=((void*)(ZXN(a1)))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Z1q1((*(Zow=Z0q1(C),&Zow)),ZYN);}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
if((((C)->Zlc))!=((void*)(Zo))){if(!(ZZN(ZBL(a1),((C)->Zlc),a2,(T6)(0)))){{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));
Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){}R=((T6)(((((T80*)(Z4G))->ZEg))==(ZGs(0))));
if(R){Z7q1(C,a1);}return R;}void Z7q1(Zq5*C,T0*a1){if((((T43*)(ZSG))->ZRk)){if((((C)->ZHb))==((void*)(Zo))){(C->ZHb)=Z2O(a1);}else if((Z2O(a1))==((void*)(Zo))){
Z3O(a1,((C)->ZHb));}}}void Z8q1(Zq5*C,T0*a1){T2 Zet=0;T0*Z5O=Zo;T0*Z6O=Zo;(C->Zvb)=(((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),ZGs(1))))->ZCb)).Zvb);
Zet=ZGs(1);while(!((Z3)((Zet)>(Z8O((Zz8*)(((C)->Zkc))))))){Z5O=Z7O((Zz8*)(((C)->Zkc)),Zet);Z6O=Z3D(((Zp6*)a1),Z5O);if((Z6O)!=((void*)(Zo))){
Z5O=((((Zz8*)(((((ZX4*)Z6O))->Zkc))))->ZGd);Z5G(((((ZD8*)Z5O))->ZCb));Z5G((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),Zet)))->ZCb));{T0*b1=Z1G(29,"Double definition of feature ");
Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)Z5O))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}else{Z0D(((Zp6*)a1),(T0*)C,Z5O);
}Zet=(Z3)(((Zet))+(ZGs(1)));}}T0*Z9q1(Zq5*C,T0*a1,T0*a2){T0*R=Zo;T0*ZaO=Zo;Z5G(((((ZD8*)a1))->ZCb));ZaO=ZbO((Zz8*)(((C)->Zkc)),((((ZD8*)a1))->Zcn));
if((ZaO)!=((void*)(Zo))){ZcO(((ZD8*)ZaO),a2);}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=Z_p1(C,a1,a2);
if((R)!=((void*)(Zo))){((((ZE3*)(((ZE3*)R))))->Zjc)=(((C)->Zjc));Z7q1(C,R);}else{ZTN(((T87*)a2),a1);}return R;}void Z4q1(Zq5*C,T0*a1,T0*a2,T0*a3){
((((Zq5*)(C)))->Zkc)=(a1);(C->Zlc)=a2;(C->Zmc)=a3;}T0*Zaq1(Zq5*C,T0*a1,T0*a2){T0*R=Zo;T0*ZJH=Zo;ZJH=Z_G(a1);R=ZjD(((ZR6*)(((((ZZ3*)ZJH))->Ztg))),a2);
if(Zo!=(R)){switch(((T0*)R)->id){case 583:break;default:R=Zo;}}if((R)==((void*)(Zo))){{ZC7*n=((ZC7*)Zh(sizeof(*n)));*n=Zak;ZfO(n,a1,a2,(T0*)C);
R=((T0*)n);}}return R;}T0*Zbq1=Zo;int Zcq1=0;T0*Z5q1(void){if(Zcq1==0){Zcq1=1;{{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Z0c;Zbq1=((T0*)n);}}}return
Zbq1;}T6 Zdq1(Zq5*C,T0*a1){T6 R=0;if((((C)->Zlc))==((void*)(Zo))){R=((T6)((ZBL(a1))!=((void*)(Zo))));}else{R=((T6)((ZBL(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZWN;Zmx((T7*)(Z2G),b1);}}else{R=((T6)((ZXN(a1))!=((void*)(Zo))));if(R){{T0*b1=ZYN;Zmx((T7*)(Z2G),b1);}}}Z7q1(C,a1);return
R;}T81 Z0q1(Zq5*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->ZCb);return R;}void Zeq1(ZZ3*C,T0*a1){T6 Z6_=0;T0*Zfq1=Zo;
T0*Zgq1=Zo;T0*ZEQ=Zo;T6 Zz61=0;Z6_=((T6)(((((T89*)(ZPM))->Zaf))==(ZGs(1))));Zfq1=Zhq1;((((T7*)(((T7*)Zfq1))))->Zdc)=(ZGs(0));if(ZbL(((C)->Z4c))){
Z6U(((C)->Z4c),Zfq1);}else{ZmW(((C)->Z4c),Zfq1);Zgt(((T7*)Zfq1),((T3)'\040'));}Zmx(((T7*)Zfq1),Z7_);Z6t(((C)->_id),Zfq1);if((a1)!=((void*)(Zo))){
Zmx(((T7*)Zfq1),(((ZD8*)(((((ZQ7*)a1))->Zpc)))->Zse));}Zgt(((T7*)Zfq1),((T3)'\050'));if((a1)!=((void*)(Zo))){ZEQ=ZAP(a1);}if(Z6_){if((ZEQ)!=((void*)(Zo))){
Z7a1(((Zz6*)ZEQ),Zfq1);}else{Zmx(((T7*)Zfq1),Ziq1);}}else{Zmx(((T7*)Zfq1),Zjq1);if((ZEQ)!=((void*)(Zo))){Zgt(((T7*)Zfq1),((T3)'\054'));
Z7a1(((Zz6*)ZEQ),Zfq1);}}Zgt(((T7*)Zfq1),((T3)'\051'));ZIM((Z84*)(ZkH),Zfq1);Zgq1=Zhq1;((((T7*)(((T7*)Zgq1))))->Zdc)=(ZGs(0));if(ZbL(((C)->Z4c))){
Z6U(((C)->Z4c),Zgq1);}else{Zw01(((C)->Z4c),Zfq1);}Zmx(((T7*)Zgq1),Zkq1);ZgM((Z84*)(ZkH),Zgq1);if(!(Z6_)){ZgM((Z84*)(ZkH),Zlq1);}if(ZbL(((C)->Z4c))){
Zmq1((Zj8*)(Znq1()),Zoq1,(T0*)C);}else{ZgM((Z84*)(ZkH),Zpq1);ZDM((Z84*)(ZkH),(T11)(((C)->_id)));ZgM((Z84*)(ZkH),Zqq1);}if((a1)!=((void*)(Zo))){
Zrq1((Z84*)(ZkH),a1);ZEL(a1);Zz61=((T6)(Zsq1((Z84*)(ZkH))));Z3Z(a1);if(Zz61){ZB61((Z84*)(ZkH));}Z4Z((Z84*)(ZkH));}ZgM((Z84*)(ZkH),Ztq1);
}void Zuq1(ZZ3*C,T0*a1,T0*a2){{T0*b1=Zvq1;Zmx((T7*)(Z2G),b1);}{T0*b1=((C)->ZUc);Zmx((T7*)(Z2G),b1);}{T0*b1=Zwq1;Zmx((T7*)(Z2G),b1);}Zxq1(a2);
{T0*b1=Zyq1;Zmx((T7*)(Z2G),b1);}{T0*b1=(((T85*)(((((T87*)a1))->Zpc)))->Zse);Zmx((T7*)(Z2G),b1);}Zzq1(((((ZD8*)a2))->ZCb),Z0O);}T6 ZAq1(ZZ3*C){
T6 R=0;T2 Zet=0;T0*Z2U=Zo;T0*Z9e1=Zo;T0*ZxH=Zo;Z2U=Z3U(C);if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZWb);while(!((T6)((R)||((T6)((Zet)==(ZGs(0)))))))
{Z9e1=ZUy(((ZV8*)Z2U),Zet);ZxH=((((ZE7*)Z9e1))->Zlc);R=((T6)(Zt01(ZxH)));Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}void ZBq1(ZZ3*C,T0*a1){
T2 Zet=0;T2 ZxH=0;T0*ZCq1=Zo;T0*ZDq1=Zo;T0*ZOx=Zo;T0*Z9e1=Zo;T0*ZEq1=Zo;Z9e1=a1;if(Zo!=(Z9e1)){switch(((T0*)Z9e1)->id){case 174:break;
default:Z9e1=Zo;}}ZEq1=a1;if(Zo!=(ZEq1)){switch(((T0*)ZEq1)->id){case 525:break;default:ZEq1=Zo;}}ZCq1=((C)->Zof);{int z1=(Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1)));
switch(z1){case 0:break;case 1:ZDq1=(((ZZ3*)((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZUb))[ZGs(0)]))->Z4c);ZOx=ZFq1(ZDq1);ZxH=ZEM(ZDq1);
if(ZqU(ZDq1)){ZgM((Z84*)(ZkH),ZGq1);}else{ZgM((Z84*)(ZkH),ZHq1);}ZgM((Z84*)(ZkH),ZIq1);ZDM((Z84*)(ZkH),(T11)(ZxH));ZgM((Z84*)(ZkH),ZJq1);
ZgM((Z84*)(ZkH),ZOx);ZgM((Z84*)(ZkH),ZKq1);Zr01(ZDq1);ZgM((Z84*)(ZkH),ZLq1);ZgM((Z84*)(ZkH),ZOx);ZgM((Z84*)(ZkH),ZMq1);if((Z9e1)!=((void*)(Zo))){
ZNq1(((ZE7*)Z9e1));}else{{T0*b1=ZEq1;ZgM((Z84*)(ZkH),ZOq1(Z0X(b1)));}}ZgM((Z84*)(ZkH),ZPq1);break;default:;ZgM((Z84*)(ZkH),ZQq1);if((Z9e1)!=((void*)(Zo))){
ZNq1(((ZE7*)Z9e1));}else{{T0*b1=ZEq1;ZgM((Z84*)(ZkH),ZOq1(Z0X(b1)));}}ZgM((Z84*)(ZkH),ZRq1);Zet=ZGs(1);while(!((Z3)((Zet)>((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1)))))))
{ZxH=ZEM((((ZZ3*)((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZUb))[(Zet)-(ZGs(1))]))->Z4c));ZgM((Z84*)(ZkH),ZSq1);ZDM((Z84*)(ZkH),(T11)(ZxH));
ZgM((Z84*)(ZkH),ZTq1);Zet=(Z3)(((Zet))+(ZGs(1)));}ZgM((Z84*)(ZkH),ZUq1);}}}T0*Zhq1=Zo;T0*ZFq1(T0*a1){T0*R=Zo;R=ZVq1;ZWw(((T7*)R),ZWq1);
Z6t(ZEM(a1),R);if(ZbL(a1)){Zgt(((T7*)R),((T3)'\052'));}return R;}T0*ZQe1(ZZ3*C,T0*a1){T0*R=Zo;T0*ZaO=Zo;T0*ZdZ=Zo;ZdZ=((((((ZD8*)a1))->ZCb)).Zvb);
ZaO=Zi_((T87*)(((C)->Zvb)),ZdZ,a1);if((ZaO)!=((void*)(a1))){Z5G(((((ZD8*)a1))->ZCb));R=ZXq1(C,ZaO);((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));
((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));}else{R=ZXq1(C,ZaO);}return R;}void Zu_(ZZ3*C,T0*a1){if((((C)->Zyh))==((void*)(Zo))){{Z58*n=((Z58*)Zh(sizeof(*n)));
*n=ZEk;ZkE(n,(T2)(ZGs(4)));(C->Zyh)=((T0*)n);}}if((a1)!=((void*)(Zo))){if(!(ZgE((Z58*)(((C)->Zyh)),a1))){ZiE((Z58*)(((C)->Zyh)),a1);}
}}void ZYq1(T0*a1){T2 ZZq1=0;T2 Z_q1=0;T2 Z0r1=0;T6 Z1r1=0;Z_q1=((((ZV8*)a1))->ZWb);ZZq1=ZGs(1);Z1r1=((T6)(1));while(!(!(Z1r1))){Z1r1=((T6)(0));
if((Z3)(((Z3)(((Z_q1))-(ZZq1)))>(ZGs(0)))){Z0r1=(Z3)(((ZZq1))+(ZGs(1)));while(!((Z3)((Z0r1)>(Z_q1)))){if(Z2r1(ZUy(((ZV8*)a1),(Z3)(((Z0r1))-((T2)(ZGs(1))))),ZUy(((ZV8*)a1),Z0r1))){
ZXy(((ZV8*)a1),(Z3)(((Z0r1))-((T2)(ZGs(1)))),Z0r1);Z1r1=((T6)(1));}Z0r1=(Z3)(((Z0r1))+(ZGs(1)));}Z_q1=(Z3)(((Z_q1))-(ZGs(1)));}if((T6)((Z1r1)&&((T6)((Z3)(((Z3)(((Z_q1))-(ZZq1)))>(ZGs(0))))))){
Z1r1=((T6)(0));Z0r1=(Z3)(((Z_q1))-(ZGs(1)));while(!((Z3)((Z0r1)<(ZZq1)))){if(Z2r1(ZUy(((ZV8*)a1),Z0r1),ZUy(((ZV8*)a1),(Z3)(((Z0r1))+((T2)(ZGs(1))))))){
ZXy(((ZV8*)a1),Z0r1,(Z3)(((Z0r1))+((T2)(ZGs(1)))));Z1r1=((T6)(1));}Z0r1=(Z3)(((Z0r1))-(ZGs(1)));}ZZq1=(Z3)(((ZZq1))+(ZGs(1)));}}}void
ZRf1(ZZ3*C,T0*a1,T0*a2){T2 ZSF=0;T2 Zet=0;T0*ZIX=Zo;T81 ZjG={Zo,Zo,0};T0*Z3r1=Zo;T0*Z4r1=Zo;T0*ZiL=Zo;if(!(ZgD((ZR6*)(((C)->Ztg)),Z5r1()))){
if((a2)!=((void*)(Zo))){ZSF=Z0y(((ZY*)a2));}{T81*C1=&ZjG;T0*b1=Z0g1(((Zw7*)a1));Z3m1(C1,(T2)(ZGs(1)),(T2)(ZGs(1)),((((T87*)b1))->_id),b1);
}{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Z5m1(n,ZfJ,ZjG);Z3r1=((T0*)n);}{Zq5*n=((Zq5*)Zh(sizeof(*n)));*n=Zph;Z2q1(n,Z0g1(((Zw7*)a1)),Z3r1,ZSF);
Z4r1=((T0*)n);}ZiL=Zaq1(((Zq5*)Z4r1),a1,Z3r1);if((Z3)((ZSF)>=(ZGs(1)))){Z6r1(a1,ZBJ,Z1y(((ZY*)a2),(T2)(ZGs(1))),(T2)(ZGs(1)));}if((Z3)((ZSF)>=(ZGs(2)))){
Z6r1(a1,ZkK,Z1y(((ZY*)a2),(T2)(ZGs(2))),(T2)(ZGs(2)));}if((Z3)((ZSF)>=(ZGs(3)))){Z6r1(a1,ZyK,Z1y(((ZY*)a2),(T2)(ZGs(3))),(T2)(ZGs(3)));
}if((Z3)((ZSF)>=(ZGs(4)))){Z6r1(a1,ZEJ,Z1y(((ZY*)a2),(T2)(ZGs(4))),(T2)(ZGs(4)));}if((Z3)((ZSF)>=(ZGs(5)))){Z6r1(a1,ZAJ,Z1y(((ZY*)a2),(T2)(ZGs(5))),(T2)(ZGs(5)));
}Zet=ZGs(6);while(!((Z3)((Zet)>(ZSF)))){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zwx(n,(T2)(ZGs(8)));ZIX=((T0*)n);}ZWw(((T7*)ZIX),Z7r1);Z6t(Zet,ZIX);
ZIX=(((void)((T27*)(Z8r1()))),ZCG(ZIX));Z6r1(a1,ZIX,Z1y(((ZY*)a2),Zet),Zet);Zet=(Z3)(((Zet))+(ZGs(1)));}}}void ZkS(ZZ3*C,T6 a1,T0*a2){
T0*Z9e1=Zo;T0*ZxH=Zo;T0*ZJH=Zo;T2 Zet=0;((((Zp4*)((Zp4*)(Z9r1()))))->ZWb)=(ZGs(-1));((((Zp4*)((Zp4*)(Zar1()))))->ZWb)=(ZGs(-1));if((Z3U(C))!=((void*)(Zo))){
Zet=(((ZV8*)(Z3U(C)))->ZWb);while(!((Zet)==(ZGs(0)))){Z9e1=ZUy((ZV8*)(Z3U(C)),Zet);ZxH=((((ZE7*)Z9e1))->Zlc);if(Zt01(ZxH)){ZJH=Z_G(ZxH);
((((Zp4*)((Zp4*)(Zbr1()))))->ZWb)=(ZGs(-1));ZNB((Zp4*)(Zbr1()),Z9e1);if(Zcr1(((ZZ3*)ZJH),(T0*)C)){ZNB((Zp4*)(Zar1()),Z9e1);}else{ZNB((Zp4*)(Z9r1()),Z9e1);
}}Zet=(Z3)(((Zet))-(ZGs(1)));}}if((T6)(((Z3)(((((Zp4*)(Z9r1()))->ZWb))<(ZGs(0))))&&((T6)((Z3)(((((Zp4*)(Zar1()))->ZWb))<(ZGs(0))))))){
Zdr1(C,a2);}else{if((Z3)(((((Zp4*)(Zar1()))->ZWb))>=(ZGs(0)))){Zmx(((T7*)a2),Zer1);}if(!(a1)){Zmx(((T7*)a2),Zfr1);Z6t(((C)->_id),a2);
Zmx(((T7*)a2),Zgr1);}Zdr1(C,a2);Zet=(((Zp4*)(Z9r1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){Z9e1=((((Zp4*)(Z9r1()))->ZUb))[Zet];Zhr1(C,a2,Z9e1);
Zet=(Z3)(((Zet))-(ZGs(1)));}Zet=(((Zp4*)(Zar1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){Z9e1=((((Zp4*)(Zar1()))->ZUb))[Zet];ZxH=((((ZE7*)Z9e1))->Zlc);
ZJH=Z_G(ZxH);((((Zp4*)((Zp4*)(Zbr1()))))->ZWb)=(ZGs(-1));ZNB((Zp4*)(Zbr1()),Z9e1);if(Zcr1(((ZZ3*)ZJH),(T0*)C)){}if((T6)(((T6)(((T6)(((Zet)==(ZGs(0)))&&((T6)(((Z3)((((((Zp4*)(Zbr1()))->ZWb)))+(ZGs(1))))==(ZGs(1))))))&&((T6)(((Z3)(((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1))))))&&((T6)(((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[(ZGs(1))-(ZGs(1))])==((void*)(C)))))){
Zmx(((T7*)a2),Zir1);Zmx(((T7*)a2),(((ZD8*)(((((ZE7*)Z9e1))->Zpc)))->Zse));Zmx(((T7*)a2),Zjr1);if(a1){Zmx(((T7*)a2),Zkr1);Z6t(((C)->_id),a2);
Zmx(((T7*)a2),Zlr1);}else{Zgt(((T7*)a2),((T3)'\051'));}Zmx(((T7*)a2),Zmr1);}else{Zhr1(C,a2,Z9e1);}Zet=(Z3)(((Zet))-(ZGs(1)));}if(!(a1)){
Zgt(((T7*)a2),((T3)'\175'));}}}T2 Znr1(ZZ3*C){T2 R=0;T0*Z2U=Zo;T0*ZKO=Zo;T2 Zet=0;if(ZhS(C)){R=sizeof(T2);}Z2U=Z3U(C);if((Z2U)!=((void*)(Zo))){
Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){ZKO=ZUy(((ZV8*)Z2U),Zet);R=(Z3)(((R))+(Zb01(((((ZE7*)ZKO))->Zlc))));Zet=(Z3)(((Zet))-(ZGs(1)));
}}if((R)==(ZGs(0))){R=ZGs(1);}return R;}T6 Zcr1(ZZ3*C,T0*a1){T6 R=0;if((C)==((void*)(a1))){R=((T6)(1));}return R;}void Zdr1(ZZ3*C,T0*a1){
if(ZbL(((C)->Z4c))){Zmx(((T7*)a1),Zor1);Z6t(((C)->_id),a1);Zmx(((T7*)a1),Zpr1);}}void Zzq1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);
}Z3G((T80*)(Z4G));}T0*Zqr1(void){if(Zrm1==0){Zrm1=1;{T0*ZWF=Zo;{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zb41(n,Z9I);ZWF=((T0*)n);}Zqm1=Zc41(ZWF);
}}return Zqm1;}T6 ZLF(ZZ3*C,T0*a1){T6 R=0;R=((T6)((C)==((void*)(a1))));return R;}T0*Zrr1=Zo;int Zsr1=0;T0*Z5r1(void){if(Zsr1==0){Zsr1=1;{
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Zrr1=((T0*)n);Znl1(n,ZfJ);}}}return Zrr1;}void Zhr1(ZZ3*C,T0*a1,T0*a2){ZWw((T7*)(Ztr1),Zur1);Zmx((T7*)(Ztr1),(((ZD8*)(((((ZE7*)a2))->Zpc)))->Zse));
Zmx((T7*)(Ztr1),ZMo1);Z6t(Zvr1(C,a2),Ztr1);Zmx((T7*)(Ztr1),ZOo1);(((void)((Zj8*)(Znq1()))),Zwr1(a1,Ztr1,Z_G(((((ZE7*)a2))->Zlc))));}void
Zxr1(ZZ3*C,T0*a1){if(((C)->Zrh)){Zi01(((C)->Z4c),a1);}}T0*ZIk1(ZZ3*C,T0*a1,T0*a2){T0*R=Zo;T0*ZaO=Zo;T0*ZdZ=Zo;T0*ZiL=Zo;T0*Z6O=Zo;T0*ZkL=Zo;
ZdZ=((((((ZD8*)a1))->ZCb)).Zvb);ZaO=Zi_((T87*)(((C)->Zvb)),ZdZ,a1);ZiL=ZjD((ZR6*)(((C)->Ztg)),ZaO);if((ZiL)!=((void*)(Zo))){R=ZiH(ZiL);
if(ZyW(R)){R=ZnH(R);}else{R=ZxP(R,((C)->Z4c));R=ZnH(R);}}else{ZkL=((C)->Zvb);Z6O=Zul1(((T87*)ZkL),(T0*)C,ZaO);if((Z6O)==((void*)(Zo))){
Zuq1(C,ZkL,ZaO);Z5G(((((ZD8*)a1))->ZCb));Z5G(((((ZD8*)ZaO))->ZCb));Zyr1(Z1G(18," Anchor not found."));}else{R=ZBL(Z6O);if((R)==((void*)(Zo))){
{T81 Zow;Z5G((*(Zow=ZVN(Z6O),&Zow)));}Z5G(((((ZD8*)a1))->ZCb));Z5G(((((ZD8*)ZaO))->ZCb));Zyr1(Z1G(29," Anchor found is a procedure."));
}else{R=ZxP(R,((C)->Z4c));R=ZnH(R);}}}return R;}T0*Zzr1=Zo;int ZAr1=0;T0*Zar1(void){if(ZAr1==0){ZAr1=1;{{Zp4*n=((Zp4*)Zh(sizeof(*n)));
*n=Zvg;Zzr1=((T0*)n);ZOB(n,(T2)(ZGs(24)));}}}return Zzr1;}T0*ZBr1(void){if(ZCm1==0){ZCm1=1;{{Zj6*n=((Zj6*)Zh(sizeof(*n)));*n=ZYi;ZBm1=((T0*)n);
}}}return ZBm1;}T6 ZCr1(ZZ3*C,T0*a1){T6 R=0;T0*Z3r1=Zo;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Znl1(n,a1);Z3r1=((T0*)n);}R=((T6)(ZgD((ZR6*)(((C)->Ztg)),Z3r1)));
return R;}T6 Z2r1(T0*a1,T0*a2){T6 R=0;T0*ZsL=Zo;T0*ZtL=Zo;T0*ZDr1=Zo;T0*ZEr1=Zo;T0*ZFr1=Zo;T0*ZGr1=Zo;if((((((ZE7*)a1))->Zbk))!=(((((ZE7*)a2))->Zbk))){
R=((T6)((Z3)((((((ZE7*)a1))->Zbk))<(((((ZE7*)a2))->Zbk)))));}else{ZDr1=((((ZE7*)a1))->ZTj);ZEr1=((((ZE7*)a2))->ZTj);ZsL=((((ZX4*)ZDr1))->Zvb);
ZtL=((((ZX4*)ZEr1))->Zvb);ZFr1=((((T87*)ZsL))->Zpc);ZGr1=((((T87*)ZtL))->Zpc);if((((((T85*)ZFr1))->Zse))==((void*)(((((T85*)ZGr1))->Zse)))){
{T81 ZH81;T81 Zow;R=((T6)(ZHr1(&((*(ZH81=ZVN(ZDr1),&ZH81))),(*(Zow=ZVN(ZEr1),&Zow)))));}}else if(ZJb1(((T85*)ZGr1),ZFr1)){R=((T6)(1));
}else if(ZJb1(((T85*)ZFr1),ZGr1)){}else if((((((T87*)ZsL))->Zlg))==((void*)(Zo))){if((((((T87*)ZtL))->Zlg))==((void*)(Zo))){R=((T6)(Zvx((T7*)(((((T85*)ZFr1))->Zse)),((((T85*)ZGr1))->Zse))));
}else{R=((T6)(1));}}else if((((((T87*)ZtL))->Zlg))==((void*)(Zo))){}else{R=((T6)((Z3)(((Z3)(((((((Zd8*)((((Z7a*)(((((T87*)ZtL))->Zlg)))->ZZb))))->ZWb)))+(ZGs(1))))<((Z3)(((((((Zd8*)((((Z7a*)(((((T87*)ZsL))->Zlg)))->ZZb))))->ZWb)))+(ZGs(1)))))));
}}return R;}T0*ZIr1(ZZ3*C){T0*R=Zo;T0*ZJr1=Zo;T0*ZkL=Zo;ZJr1=ZKr1();if((ZJr1)!=((void*)(Zo))){ZkL=((C)->Zvb);if((T6)(((ZJr1)!=((void*)(ZkL)))&&((T6)(ZxM(((T87*)ZkL),ZJr1))))){
if(ZYa1(((T87*)ZkL),ZuJ)){R=ZZa1(C,ZuJ);if(Zo!=(R)){switch(((T0*)R)->id){case 451:break;default:R=Zo;}}if((R)!=((void*)(Zo))){R=ZLr1(((ZG7*)R));
}}}}return R;}void ZMr1(ZZ3*C){T0*ZiL=Zo;T2 Zet=0;T0*ZXw=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);
ZXw=ZNr1(ZiL);if((ZXw)!=((void*)(Zo))){Zq91(((ZX6*)ZXw));}Zet=(Z3)(((Zet))+(ZGs(1)));}}void ZOr1(ZZ3*C){T0*ZiL=Zo;T2 Zet=0;Zet=ZGs(1);
while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);ZPr1(ZiL);Zet=(Z3)(((Zet))+(ZGs(1)));}}void ZQr1(ZZ3*C,T0*a1){
T2 Zet=0;T0*Z2U=Zo;T0*Z9e1=Zo;T0*ZxH=Zo;T0*ZIX=Zo;T0*ZCq1=Zo;if(ZbL(((C)->Z4c))){Zmx(((T7*)a1),ZRr1);Z6U(((C)->Z4c),a1);Zgt(((T7*)a1),((T3)'\040'));
{Zj8*C1=(Zj8*)(Znq1());T0*b1=ZSr1;T0*b2=a1;T0*b3=(T0*)C;ZTr1(C1,b1,b2,b3,Zo);}Zmx(((T7*)a1),ZUr1);}else{Zmx(((T7*)a1),ZVr1);Z6U(((C)->Z4c),a1);
Zmx(((T7*)a1),ZWr1);}Z2U=Z3U(C);if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){Z9e1=ZUy(((ZV8*)Z2U),Zet);
ZIX=(((ZD8*)(((((ZE7*)Z9e1))->Zpc)))->Zse);ZxH=ZnH(((((ZE7*)Z9e1))->Zlc));if(ZbL(ZxH)){ZCq1=(((ZZ3*)(Z_G(ZxH)))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(0)))){
Zmx(((T7*)a1),ZXr1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),ZYr1);Zmx(((T7*)a1),ZIX);Zgt(((T7*)a1),((T3)'\075'));ZCq1=(((ZZ3*)(Z_G(ZxH)))->Zof);
if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){Zgt(((T7*)a1),((T3)'X'));Z6t((((ZZ3*)(((((Z23*)ZCq1))->Z8e)))->_id),a1);
}else{Zgt(((T7*)a1),((T3)'r'));Z6t((((ZZ3*)((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZUb))[ZGs(0)]))->_id),a1);}Zmx(((T7*)a1),ZZr1);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
Zmx(((T7*)a1),Z_r1);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){Zmx(((T7*)a1),Z0s1);}}if(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1))){
Zgt(((T7*)a1),((T3)'\050'));Z6U((((ZZ3*)((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZUb))[ZGs(0)]))->Z4c),a1);Zgt(((T7*)a1),((T3)'\051'));}
Zmx(((T7*)a1),Z1s1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Z2s1);}}else if(ZmH(ZxH)){if((ZZa1(C,ZcJ))==((void*)(Zo))){ZMT(ZxH,Z3s1);Z3G((T80*)(Z4G));
{T81 Zow;Z5G((*(Zow=Z4s1(((ZE7*)Z9e1)),&Zow)));}{T0*b1=Z5s1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zmx(((T7*)a1),Z6s1);Zmx(((T7*)a1),ZIX);
Zmx(((T7*)a1),Z7s1);Z6t(ZEM(ZxH),a1);Zmx(((T7*)a1),Z8s1);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){Zmx(((T7*)a1),Z_r1);}Zmx(((T7*)a1),Z9s1);
Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Zas1);}else if(ZPX(ZxH)){}else if(ZX01(ZxH)){Zmx(((T7*)a1),Zbs1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Zcs1);
Z6t(ZEM(ZxH),a1);Zmx(((T7*)a1),Zds1);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){Zmx(((T7*)a1),Z_r1);}Zmx(((T7*)a1),Zes1);Zmx(((T7*)a1),ZIX);
Zmx(((T7*)a1),Zfs1);}Zet=(Z3)(((Zet))-(ZGs(1)));}}if(ZX01(((C)->Z4c))){Zmx(((T7*)a1),Zgs1);}Zgt(((T7*)a1),((T3)'\175'));Zgt(((T7*)a1),((T3)'\n'));
}T0*Zhs1(ZZ3*C){T0*R=Zo;R=ZQe1(C,((((Zz8*)((((ZX4*)(ZOm1((T87*)(Zqr1()))))->Zkc))))->ZGd));return R;}T0*Ztr1=Zo;void Zo_(ZZ3*C,T0*a1){
T2 Zet=0;Zet=ZJD((Ze7*)(((C)->Zvh)),a1);if((Z3)((Zet)>((((Ze7*)(((C)->Zvh)))->ZWb)))){ZKD((Ze7*)(((C)->Zvh)),a1);}}void Zis1(ZZ3*C,T2
a1){T2 Zet=0;T0*Z641=Zo;T0*Z741=Zo;T2 Zp31=0;T2 Z1V=0;if(((C)->Zsh)){}else if(!(((C)->Zrh))){(C->Zsh)=((T6)(1));}else if((a1)==(ZGs(0))){
Zjs1(C);}else{Zet=(((Ze7*)(((C)->Zvh)))->ZWb);if((Z3)((Zet)>=(ZGs(0)))){Z641=((T0*)(C));Zp31=(Z3)(((Zet))+(ZGs(1)));while(!((Zet)==(ZGs(0))))
{Z741=((((Ze7*)(((C)->Zvh)))->ZUb))[Zet];if(!(((((ZZ3*)Z741))->Zsh))){Z1V=(Z3)((((((Ze7*)(((((ZZ3*)Z741))->Zvh)))->ZWb)))+(ZGs(1)));if((Z3)((Z1V)>(Zp31))){
Z641=Z741;Zp31=Z1V;}}Zet=(Z3)(((Zet))-(ZGs(1)));}if((Z641)==((void*)(C))){Zjs1(C);}else{Zis1(((ZZ3*)Z641),(Z3)(((a1))-((T2)(ZGs(1)))));
}}}}void Zjs1(ZZ3*C){T2 Zks1=0;T2 Zls1=0;T2 Zet=0;T0*ZiL=Zo;(C->Zsh)=((T6)(1));Zks1=(((ZR6*)(((C)->Ztg)))->Zdc);Zls1=(((T87*)(((C)->Zvb)))->Zpg);
if((Z3)((Zls1)<(ZGs(3)))){}else if((Z3)((Zls1)<(ZGs(4)))){Zks1=(Z3)(((Zks1))+((Z3)((Zks1)/(ZGs(4)))));}else if((Zls1)==(ZGs(4))){Zks1=(Z3)(((Zks1))+((Z3)((Zks1)/(ZGs(3)))));
}if((Z3)((Zls1)>=(ZGs(5)))){if((((C)->Zog))!=((void*)(Zo))){Zks1=(Z3)(((Zks1))+(ZGs(2)));}}Zms1((Z84*)(ZkH),Zks1);if((((C)->Zyh))!=((void*)(Zo))){
if((Z3)(((((Z58*)(((C)->Zyh)))->ZWb))<(ZGs(0)))){Zeq1(C,Zo);}else{Zet=(((Z58*)(((C)->Zyh)))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZiL=((((Z58*)(((C)->Zyh)))->ZUb))[Zet];
Zeq1(C,ZiL);Zet=(Z3)(((Zet))-(ZGs(1)));}}}ZWP((T38*)(Zns1()),((T3)'\011'));ZvP((T38*)(Zns1()),((C)->ZUc));ZvP((T38*)(Zns1()),Zos1);ZSP((T38*)(Zns1()),(((ZR6*)(((C)->Ztg)))->Zdc));
ZvP((T38*)(Zns1()),Zps1);Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);Zqs1(ZiL);Zet=(Z3)(((Zet))+(ZGs(1)));
}if((((C)->Zog))!=((void*)(Zo))){Zrs1((Z76*)(((C)->Zog)));}}T0*ZyP(ZZ3*C,T0*a1){T0*R=Zo;T0*Z6O=Zo;T0*ZkL=Zo;R=ZjD((ZR6*)(((C)->Ztg)),a1);
if((R)==((void*)(Zo))){ZkL=((C)->Zvb);Z6O=Zul1(((T87*)ZkL),(T0*)C,a1);if((Z6O)==((void*)(Zo))){Zuq1(C,ZkL,a1);}else{R=ZjD((ZR6*)(((C)->Ztg)),a1);
if((R)==((void*)(Zo))){R=Zss1(Z6O,((C)->Z4c),a1);if((R)==((void*)(Zo))){Zuq1(C,ZkL,a1);}}}}return R;}void Zts1(ZZ3*C){T0*ZiL=Zo;T2 Zet=0;
T0*Z9e1=Zo;T0*ZJH=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);Zus1(ZiL);Z9e1=ZiL;
if(Zo!=(Z9e1)){switch(((T0*)Z9e1)->id){case 174:break;default:Z9e1=Zo;}}if((Z9e1)!=((void*)(Zo))){ZJH=Z_G(((((ZE7*)Z9e1))->Zlc));if(((C)->Zwh)){
Zvs1(((ZZ3*)ZJH));}if(((C)->Zxh)){Zws1(((ZZ3*)ZJH));}}Zet=(Z3)(((Zet))+(ZGs(1)));}Zxs1((Zj8*)(Znq1()),(T0*)C);Zys1(C);if(((C)->Zwh)){
if(ZmH(((C)->Z4c))){ZiL=ZZa1(C,ZtJ);}else{ZiL=ZZa1(C,ZsJ);ZhP(ZiL);}}if(((C)->Zxh)){if(ZmH(((C)->Z4c))){ZiL=ZZa1(C,ZrJ);}else{ZiL=ZZa1(C,ZMJ);
ZhP(ZiL);}}}T0*ZIL(ZZ3*C,T0*a1){T0*R=Zo;T0*Z5O=Zo;T0*Zzs1=Zo;T0*ZAs1=Zo;Zzs1=((((ZQ7*)a1))->Z4c);if((C)==((void*)(Z_G(Zzs1)))){R=a1;}
else{ZAs1=((C)->Z4c);if(Zo!=(ZAs1)){switch(((T0*)ZAs1)->id){case 290:break;default:ZAs1=Zo;}}if((ZAs1)!=((void*)(Zo))){Z5O=((((ZQ7*)a1))->Zpc);
}else{Z5O=Zi_((T87*)(((C)->Zvb)),ZsO(Zzs1),((((ZQ7*)a1))->Zpc));}R=ZXq1(C,Z5O);}return R;}void ZBs1(ZZ3*C,T0*a1,T0*a2){T2 Zet=0;T0*ZCs1=Zo;
(C->ZUc)=a2;(C->Zrf)=ZBx(((T7*)a2));{ZR6*n=((ZR6*)Zh(sizeof(*n)));*n=Znj;{ZR6*C1=n;ZiD(C1,Zxt(193));}(C->Ztg)=((T0*)n);}ZSE((Zc9*)(ZDs1()),(T0*)C,a2);
(C->Zsh)=((T6)(1));(C->Z4c)=a1;{Ze7*n=((Ze7*)Zh(sizeof(*n)));*n=ZNj;ZLD(n,(T2)(ZGs(16)));(C->Zvh)=((T0*)n);}(C->Zvb)=ZsO(a1);(C->Zfe)=ZBT(a1);
(C->_id)=(T2)(ZH_((T42*)(ZEs1()),a2));Z8H((T43*)(ZSG));{Z23*n=((Z23*)Zh(sizeof(*n)));*n=Zbe;ZS71(n,(T0*)C);(C->Zof)=((T0*)n);}if(ZqU(a1)){
ZCP(C);ZJm1((T87*)(((C)->Zvb)),a1);}if(Z9U(a1)){ZCs1=ZJR(a1);Zet=((((ZY*)ZCs1))->ZXb);while(!((Z3)((Zet)>(((((ZY*)ZCs1))->ZWb))))){if((Z_G(Z1y(((ZY*)ZCs1),Zet)))!=((void*)(Zo))){
}Zet=(Z3)(((Zet))+(ZGs(1)));}}}void ZwW(ZZ3*C,T0*a1){T0*Z2U=Zo;T2 Zet=0;T0*Z9e1=Zo;T0*ZxH=Zo;T6 ZFs1=0;Z2U=Z3U(C);ZFs1=((T6)((T6)(((((T43*)(ZSG))->ZXk))&&((T6)((((T87*)(((C)->Zvb)))->Zgg))))));
if((Z2U)==((void*)(Zo))){if(ZhS(C)){Zgt(((T7*)a1),((T3)'\173'));Z6t(((C)->_id),a1);if(ZFs1){Zgt(((T7*)a1),((T3)'\054'));Zmx(((T7*)a1),Z4T);
}Zgt(((T7*)a1),((T3)'\175'));}else if(ZFs1){Zgt(((T7*)a1),((T3)'\173'));Zmx(((T7*)a1),Z4T);Zgt(((T7*)a1),((T3)'\175'));}else{Z001(((C)->Z4c),a1);
}}else{Zgt(((T7*)a1),((T3)'\173'));if(ZhS(C)){Z6t(((C)->_id),a1);Zgt(((T7*)a1),((T3)'\054'));}if(ZFs1){Zmx(((T7*)a1),Z4T);Zgt(((T7*)a1),((T3)'\054'));
}Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){Z9e1=ZUy(((ZV8*)Z2U),Zet);ZxH=((((ZE7*)Z9e1))->Zlc);Z001(ZxH,a1);Zet=(Z3)(((Zet))-(ZGs(1)));
if((Z3)((Zet)>(ZGs(0)))){Zgt(((T7*)a1),((T3)'\054'));}}Zgt(((T7*)a1),((T3)'\175'));}}T0*ZGs1(ZZ3*C,T0*a1){T0*R=Zo;T0*ZHs1=Zo;T0*ZIs1=Zo;
T0*ZJs1=Zo;ZHs1=ZYm1((T87*)(((C)->Zvb)),(T0*)C,a1);if((ZHs1)!=((void*)(Zo))){{ZH8*n=((ZH8*)Zh(sizeof(*n)));*n=Zel;((((ZH8*)(n)))->ZCb)=(((((ZD8*)a1))->ZCb));
ZIs1=((T0*)n);}{ZP6*n=((ZP6*)Zh(sizeof(*n)));*n=Zmj;ZKs1(n,ZIs1,((((ZG7*)ZHs1))->Zpc));ZJs1=((T0*)n);}{ZX6*n=((ZX6*)Zh(sizeof(*n)));*n=Zzj;
ZLs1(n,Zo,ZJs1,Zo);R=((T0*)n);}}return R;}void Zyr1(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZMs1(ZZ3*C){T2 Zet=0;
T0*ZNs1=Zo;T6 Z0Q=0;T0*ZiL=Zo;T0*ZRU=Zo;T0*ZxH=Zo;T0*Z9e1=Zo;T0*ZEq1=Zo;T0*ZOx=Zo;if(((C)->Zrh)){ZRU=((C)->Z4c);Zms1((Z84*)(ZkH),(T2)(ZGs(1)));
ZNs1=ZOs1;ZWw(((T7*)ZNs1),ZPs1);Z6t(((C)->_id),ZNs1);Zmx(((T7*)ZNs1),ZQs1);Z6t(ZEM(ZRU),ZNs1);if(ZbL(ZRU)){Zgt(((T7*)ZNs1),((T3)'\052'));
}Zmx(((T7*)ZNs1),ZRs1);ZIM((Z84*)(ZkH),ZNs1);ZgM((Z84*)(ZkH),ZSs1);if(ZmH(ZRU)){ZxH=((((ZY*)(ZJR(ZRU)))->ZUb))[ZGs(0)];ZOx=Z1G(16,ZPo);
((((T7*)(((T7*)ZOx))))->Zdc)=(ZGs(0));ZmW(ZxH,ZOx);ZgM((Z84*)(ZkH),ZTs1);ZDM((Z84*)(ZkH),(T11)(ZEM(ZxH)));if(ZqU(ZxH)){ZgM((Z84*)(ZkH),ZUs1);
}else{ZgM((Z84*)(ZkH),ZVs1);}ZgM((Z84*)(ZkH),ZWs1);ZgM((Z84*)(ZkH),ZOx);ZgM((Z84*)(ZkH),ZXs1);}else{ZgM((Z84*)(ZkH),ZYs1);Z0Q=((T6)(0));
Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);Z9e1=ZiL;if(Zo!=(Z9e1)){switch(((T0*)Z9e1)->id){
case 174:break;default:Z9e1=Zo;}}if((Z9e1)!=((void*)(Zo))){if(Z0Q){ZgM((Z84*)(ZkH),ZZs1);}else{Z0Q=((T6)(1));}Z_s1(((ZE7*)Z9e1));}else{
ZEq1=ZiL;if(Zo!=(ZEq1)){switch(((T0*)ZEq1)->id){case 525:break;default:ZEq1=Zo;}}if((ZEq1)!=((void*)(Zo))){if(Z0Q){ZgM((Z84*)(ZkH),Z0t1);
}else{Z0Q=((T6)(1));}Z1t1(((ZM7*)ZEq1));}}Zet=(Z3)(((Zet))+(ZGs(1)));}}ZgM((Z84*)(ZkH),Z2t1);}}T0*Zg_(ZZ3*C){T0*R=Zo;T0*ZkL=Zo;ZkL=((C)->Zvb);
R=ZKm1((T87*)(((C)->Zvb)),((C)->Z4c));return R;}T0*Z3t1=Zo;T0*Znq1(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));*n=ZOk;ZMM=((T0*)n);
}}}return ZMM;}T0*Zns1(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}void Z4t1(ZZ3*C){T0*ZiL=Zo;
T2 Zet=0;T0*ZJH=Zo;T0*ZjL=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);Z5t1(ZiL);
ZjL=ZiH(ZiL);if((ZjL)!=((void*)(Zo))){if(ZsT(ZjL)){}else{ZJH=Z_G(ZjL);}}Zet=(Z3)(((Zet))+(ZGs(1)));}if((((C)->Zog))!=((void*)(Zo))){Z6t1((Z76*)(((C)->Zog)));
}}T2 Zvr1(ZZ3*C,T0*a1){T2 R=0;T0*Z2U=Zo;T0*ZxH=Zo;T2 Zet=0;if(ZhS(C)){R=sizeof(T1);}Z2U=Z3U(C);Zet=((((ZV8*)Z2U))->ZWb);while(!((ZUy(((ZV8*)Z2U),Zet))==((void*)(a1))))
{ZxH=(((ZE7*)(ZUy(((ZV8*)Z2U),Zet)))->Zlc);R=(Z3)(((R))+(Zb01(ZxH)));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}void Z7t1(ZZ3*C,T0*a1){if(((C)->Zrh)){
ZE01(((C)->Z4c),a1);}}void ZCP(ZZ3*C){if(!(((C)->Zrh))){(C->Zrh)=((T6)(1));if((((T87*)(((C)->Zvb)))->Zgg)){((((T43*)((T43*)(ZSG))))->ZXk)=(1);
}(C->Zsh)=((T6)(0));Z8t1((T0*)C,((C)->Zof));Z8H((T43*)(ZSG));}}T0*Z8r1(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);
ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);
ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);
ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);
ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);
ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);
ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);
ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);
ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);
ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);
ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);
ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);
ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);
ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);
ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}void Zys1(ZZ3*C){T0*ZRU=Zo;if(!(((C)->ZAh))){(C->ZAh)=((T6)(1));
ZRU=((C)->Z4c);if((T6)(((T6)((Zon1((T87*)(ZsO(ZRU))))&&((T6)(((C)->Zrh)))))||((T6)((((T43*)(ZSG))->ZRk))))){ZwO((Zj6*)(ZBr1()));Zjn1((T87*)(((C)->Zvb)),(T0*)C);
(C->Zog)=ZpO((Zj6*)(ZBr1()),ZRU);}}}void Z9t1(ZZ3*C,T0*a1){T2 Zet=0;T0*Z2U=Zo;T0*Z9e1=Zo;T0*ZRU=Zo;T0*ZxH=Zo;T0*ZIX=Zo;T6 Zat1=0;T0*ZCq1=Zo;
ZRU=((C)->Z4c);Zmx(((T7*)a1),Zbt1);if(ZbL(ZRU)){Zat1=((T6)(ZhS((ZZ3*)(Z_G(ZRU)))));if(Zat1){Zmx(((T7*)a1),Zct1);}Zmx(((T7*)a1),Zdt1);
}Zmx(((T7*)a1),Zet1);Z6U(ZRU,a1);Zmx(((T7*)a1),Zft1);if(ZbL(ZRU)){Zmx(((T7*)a1),Zgt1);}else{Zmx(((T7*)a1),Zht1);}Zmx(((T7*)a1),Zit1);
Z2U=Z3U(C);if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){Z9e1=ZUy(((ZV8*)Z2U),Zet);ZIX=(((ZD8*)(((((ZE7*)Z9e1))->Zpc)))->Zse);
ZxH=ZnH(((((ZE7*)Z9e1))->Zlc));if(ZIG(ZxH)){Zmx(((T7*)a1),Zjt1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Zkt1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Zfs1);
}Zet=(Z3)(((Zet))-(ZGs(1)));}Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){Z9e1=ZUy(((ZV8*)Z2U),Zet);ZIX=(((ZD8*)(((((ZE7*)Z9e1))->Zpc)))->Zse);
ZxH=ZnH(((((ZE7*)Z9e1))->Zlc));if(ZbL(ZxH)){ZCq1=(((ZZ3*)(Z_G(ZxH)))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(0)))){
Zmx(((T7*)a1),Zlt1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Zmt1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Znt1);if(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1))){
ZxH=(((ZZ3*)((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZUb))[ZGs(0)]))->Z4c);Zgt(((T7*)a1),((T3)'r'));}else{Zgt(((T7*)a1),((T3)'X'));}Z6t(ZEM(ZxH),a1);
Zmx(((T7*)a1),Zot1);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){Zmx(((T7*)a1),Z_r1);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
Zmx(((T7*)a1),Z0s1);}}if(((Z3)(((((((Ze7*)(((((Z23*)ZCq1))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1))){Zgt(((T7*)a1),((T3)'\050'));Z6U(ZxH,a1);
Zgt(((T7*)a1),((T3)'\051'));}Zmx(((T7*)a1),Zpt1);}}else if(ZmH(ZxH)){if((ZZa1(C,ZcJ))==((void*)(Zo))){ZMT(ZxH,Z3s1);Z3G((T80*)(Z4G));
{T81 Zow;Z5G((*(Zow=Z4s1(((ZE7*)Z9e1)),&Zow)));}{T0*b1=Z5s1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zmx(((T7*)a1),Zqt1);Z6t(ZEM(ZxH),a1);
Zmx(((T7*)a1),Zrt1);if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){Zmx(((T7*)a1),Z_r1);}Zmx(((T7*)a1),Zst1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Ztt1);
Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Zut1);}else if(ZPX(ZxH)){}else if(ZX01(ZxH)){Zmx(((T7*)a1),Zqt1);Z6t(ZEM(ZxH),a1);Zmx(((T7*)a1),Zvt1);
if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){Zmx(((T7*)a1),Z_r1);}Zmx(((T7*)a1),Zwt1);Zmx(((T7*)a1),ZIX);Zmx(((T7*)a1),Zxt1);Zmx(((T7*)a1),ZIX);
Zmx(((T7*)a1),ZbR);}Zet=(Z3)(((Zet))-(ZGs(1)));}}if(Zat1){Zmx(((T7*)a1),ZmM);}Zmx(((T7*)a1),Zyt1);}T0*Zzt1=Zo;int ZAt1=0;T0*Zbr1(void){
if(ZAt1==0){ZAt1=1;{{Zp4*n=((Zp4*)Zh(sizeof(*n)));*n=Zvg;Zzt1=((T0*)n);ZOB(n,(T2)(ZGs(24)));}}}return Zzt1;}void ZBt1(ZZ3*C){T2 Zet=0;
T6 Z0Q=0;T0*ZiL=Zo;T0*ZRU=Zo;T0*Z9e1=Zo;T0*ZEq1=Zo;if(((C)->Zrh)){ZRU=((C)->Z4c);ZgM((Z84*)(ZkH),ZCt1);ZDM((Z84*)(ZkH),(T11)(ZEM(ZRU)));
ZgM((Z84*)(ZkH),ZDt1);Z0Q=((T6)(0));Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);Z9e1=ZiL;
if(Zo!=(Z9e1)){switch(((T0*)Z9e1)->id){case 174:break;default:Z9e1=Zo;}}ZEq1=ZiL;if(Zo!=(ZEq1)){switch(((T0*)ZEq1)->id){case 525:break;
default:ZEq1=Zo;}}if((T6)(((Z9e1)!=((void*)(Zo)))||((T6)((ZEq1)!=((void*)(Zo)))))){if(Z0Q){ZgM((Z84*)(ZkH),ZEt1);}else{ZdL((Z84*)(ZkH),((T3)'\042'));
Z0Q=((T6)(1));}ZgM((Z84*)(ZkH),(((ZD8*)(((((ZQ7*)ZiL))->Zpc)))->Zse));}Zet=(Z3)(((Zet))+(ZGs(1)));}if(!(Z0Q)){ZgM((Z84*)(ZkH),ZFt1);}
else{ZdL((Z84*)(ZkH),((T3)'\042'));}ZgM((Z84*)(ZkH),ZGt1);}}void ZHt1(ZZ3*C){if(((C)->Zrh)){Zms1((Z84*)(ZkH),(T2)(ZGs(1)));ZP01(((C)->Z4c));
}}void ZIt1(ZZ3*C){if(((C)->Zrh)){Zms1((Z84*)(ZkH),(T2)(ZGs(4)));ZR01(((C)->Z4c));}}T0*ZJt1=Zo;int ZKt1=0;T0*Z9r1(void){if(ZKt1==0){ZKt1=1;{
{Zp4*n=((Zp4*)Zh(sizeof(*n)));*n=Zvg;ZJt1=((T0*)n);ZOB(n,(T2)(ZGs(24)));}}}return ZJt1;}void ZpS(ZZ3*C,T0*a1){Zmx(((T7*)a1),ZyS);Z6t(((C)->_id),a1);
Zmx(((T7*)a1),ZLt1);Z6t(((C)->_id),a1);Zmx(((T7*)a1),ZMt1);Z6t(((C)->_id),a1);Zmx(((T7*)a1),ZNt1);Z6t(((C)->_id),a1);Zmx(((T7*)a1),ZOt1);
ZkS(C,(T6)(1),a1);Zmx(((T7*)a1),ZPt1);}T0*Z3U(ZZ3*C){T0*R=Zo;T0*Z9e1=Zo;T2 Zet=0;if((((C)->Zzh))==((void*)(Zo))){Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc)))))
{Z9e1=ZdD((ZR6*)(((C)->Ztg)),Zet);if(Zo!=(Z9e1)){switch(((T0*)Z9e1)->id){case 174:break;default:Z9e1=Zo;}}if((Z9e1)!=((void*)(Zo))){if((((C)->Zzh))==((void*)(Zo))){
{ZV8*n=((ZV8*)Zh(sizeof(*n)));*n=Zll;ZWy(n,(T2)(ZGs(4)),(T2)(ZGs(1)));(C->Zzh)=((T0*)n);}}ZVy((ZV8*)(((C)->Zzh)),Z9e1);}Zet=(Z3)(((Zet))+(ZGs(1)));
}if((((C)->Zzh))!=((void*)(Zo))){ZYq1(((C)->Zzh));}}R=((C)->Zzh);return R;}T6 ZQt1(ZZ3*C){T6 R=0;T2 Zet=0;T0*ZJH=Zo;Zet=(Z3)(((((((Ze7*)((((Z23*)(((C)->Zof)))->Zae))))->ZWb)))+(ZGs(1)));
while(!((T6)((R)||((T6)((Zet)==(ZGs(0))))))){ZJH=(((((Ze7*)((((Z23*)(((C)->Zof)))->Zae))))->ZUb))[(Zet)-(ZGs(1))];if((ZJH)==((void*)(C))){
R=((T6)(ZAq1(C)));}else{R=((T6)(Zt01(((((ZZ3*)ZJH))->Z4c))));}Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T0*ZEs1(void){if(ZJn1==0){ZJn1=1;{
{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;ZIn1=((T0*)n);ZK_(n);}}}return ZIn1;}void ZRt1(ZZ3*C,T0*a1){T0*ZRU=Zo;ZRU=((C)->Z4c);ZdU(a1,ZSt1);
Z181(a1,(T11)(((C)->_id)));ZgU(a1,((T3)'\040'));ZTt1(ZRU,a1);if(ZbL(ZRU)){ZdU(a1,ZUt1);if(((C)->Zrh)){ZdU(a1,ZVt1);if((T6)((ZbL(ZRU))&&((T6)(!(ZhS(C)))))){
ZdU(a1,ZWt1);}else{ZdU(a1,ZXt1);}}else{ZdU(a1,ZYt1);}ZgU(a1,((T3)'\n'));Z_71((Z23*)(((C)->Zof)),a1);}}void ZZt1(ZZ3*C,T81 a1){T2 Zet=0;
T0*ZiL=Zo;(C->Zth)=((T6)(1));Zet=(((ZR6*)(((C)->Ztg)))->Zdc);while(!((Z3)((Zet)<(ZGs(1))))){ZiL=ZdD((ZR6*)(((C)->Ztg)),Zet);if(!(Z_t1(ZiL))){
Z0u1(ZiL,a1);}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zth)=((T6)(0));}void Zws1(ZZ3*C){T2 Zet=0;T0*ZJH=Zo;if(!(((C)->Zxh))){Z8H((T43*)(ZSG));
(C->Zxh)=((T6)(1));((((T43*)((T43*)(ZSG))))->ZWk)=(1);}Zet=(Z3)(((((((Ze7*)((((Z23*)(((C)->Zof)))->Zae))))->ZWb)))+(ZGs(1)));while(!((Zet)==(ZGs(0))))
{ZJH=(((((Ze7*)((((Z23*)(((C)->Zof)))->Zae))))->ZUb))[(Zet)-(ZGs(1))];if(!(((((ZZ3*)ZJH))->Zxh))){Zws1(((ZZ3*)ZJH));}Zet=(Z3)(((Zet))-(ZGs(1)));
}}void Z1u1(ZZ3*C,T0*a1){T0*Z9e1=Zo;T2 Zet=0;Zet=ZGs(1);while(!((Z3)((Zet)>((((ZR6*)(((C)->Ztg)))->Zdc))))){Z9e1=ZdD((ZR6*)(((C)->Ztg)),Zet);
if(Zo!=(Z9e1)){switch(((T0*)Z9e1)->id){case 174:break;default:Z9e1=Zo;}}if((Z9e1)!=((void*)(Zo))){Z9e1=ZyP(((ZZ3*)a1),((((ZE7*)Z9e1))->Zpc));
if(Zo!=(Z9e1)){switch(((T0*)Z9e1)->id){case 174:break;default:Z9e1=Zo;}}}Zet=(Z3)(((Zet))+(ZGs(1)));}}T0*ZXq1(ZZ3*C,T0*a1){T0*R=Zo;R=ZyP(C,a1);
if((R)==((void*)(Zo))){Z5G(((((ZD8*)a1))->ZCb));{T0*b1=Z2u1;Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)a1))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z3u1;
Zmx((T7*)(Z2G),b1);}ZMT(((C)->Z4c),Z0O);ZaG((T80*)(Z4G));}return R;}void Z6r1(T0*a1,T0*a2,T0*a3,T2 a4){T81 ZjG={Zo,Zo,0};T0*ZkL=Zo;T0*Z2U=Zo;
T0*Z3r1=Zo;T0*Z4u1=Zo;T0*Z9e1=Zo;T0*ZiL=Zo;T0*Z5u1=Zo;T0*Z6u1=Zo;ZkL=ZsO(a1);{T81*C1=&ZjG;T0*b1=ZkL;Z3m1(C1,(T2)(ZGs(1)),(T2)(ZGs(1)),((((T87*)b1))->_id),b1);
}{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Z5m1(n,a2,ZjG);Z3r1=((T0*)n);}{ZR8*n=((ZR8*)Zh(sizeof(*n)));*n=Zjl;Z7u1(n,ZkL,Z3r1,a3);Z2U=((T0*)n);
}Z9e1=Z8u1(((ZR8*)Z2U),a1,Z3r1);((((ZE7*)(((ZE7*)Z9e1))))->Zbk)=(a4);((((ZD8*)(((ZD8*)Z3r1))))->Zdn)=(Z9e1);Z5u1=ZSx(((T7*)Z9u1),a2);
Z5u1=(((void)((T27*)(Z8r1()))),ZCG(Z5u1));{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Z5m1(n,Z5u1,ZjG);Z4u1=((T0*)n);}{Zda*n=((Zda*)Zh(sizeof(*n)));
*n=Z9n;Zau1(n,ZkL,Z4u1,Z3r1);Z6u1=((T0*)n);}ZiL=Zbu1(((Zda*)Z6u1),a1,Z4u1);}void Zvs1(ZZ3*C){T2 Zet=0;T0*ZJH=Zo;if(!(((C)->Zwh))){Z8H((T43*)(ZSG));
(C->Zwh)=((T6)(1));((((T43*)((T43*)(ZSG))))->ZWk)=(1);}Zet=(Z3)(((((((Ze7*)((((Z23*)(((C)->Zof)))->Zae))))->ZWb)))+(ZGs(1)));while(!((Zet)==(ZGs(0))))
{ZJH=(((((Ze7*)((((Z23*)(((C)->Zof)))->Zae))))->ZUb))[(Zet)-(ZGs(1))];if(!(((((ZZ3*)ZJH))->Zwh))){Zvs1(((ZZ3*)ZJH));}Zet=(Z3)(((Zet))-(ZGs(1)));
}}T0*ZqX(ZZ3*C,T0*a1,T0*a2){T0*R=Zo;R=ZjD((ZR6*)(((C)->Ztg)),a2);if((R)==((void*)(Zo))){Zcu1(a1);R=ZjD((ZR6*)(((C)->Ztg)),a2);}if((R)==((void*)(Zo))){
Z5G(((((ZD8*)a2))->ZCb));{T0*b1=Z1G(34,"There is no such feature in class ");Zmx((T7*)(Z2G),b1);}{T0*b1=(((T85*)((((T87*)(Zdu1(a1)))->Zpc)))->Zse);
Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(110,". (Feature \"call\" is available for all agents and feature \"item\" is available only for FUNCTION or PREDICATE.)");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}return R;}void Zeu1(ZZ3*C){if(((C)->Zrh)){if((Z3)((((C)->ZBh))<(ZGs(1)))){Z411(((C)->Z4c));(C->ZBh)=ZGs(1);
}}}T6 ZhS(ZZ3*C){T6 R=0;if((((C)->Zuh))==(ZGs(0))){if(ZqU(((C)->Z4c))){(C->Zuh)=ZGs(-1);}else if(Z3L(((C)->Z4c))){(C->Zuh)=ZGs(1);}else
if(((C)->Zrh)){if(((((T89*)(ZPM))->Zaf))==(ZGs(1))){if(Zfu1((T0*)C)){(C->Zuh)=ZGs(1);}else{(C->Zuh)=ZGs(-1);}}else{(C->Zuh)=ZGs(1);}}
}R=((T6)((((C)->Zuh))==(ZGs(1))));return R;}void Zgu1(ZZ3*C){if(((C)->Zrh)){if((Z3)((((C)->ZBh))<(ZGs(2)))){Z611(((C)->Z4c));(C->ZBh)=ZGs(2);
}}}void Zhu1(ZZ3*C){T2 Zet=0;T0*Ziu1=Zo;if(((C)->Zrh)){if((Z3)((((C)->ZBh))<(ZGs(3)))){if((T6)((ZX01(((C)->Z4c)))&&((T6)((Z3U(C))!=((void*)(Zo)))))){
Zet=(((ZV8*)(Z3U(C)))->ZWb);while(!((Zet)==(ZGs(0)))){Ziu1=(((ZE7*)(ZUy((ZV8*)(Z3U(C)),Zet)))->Zlc);if(ZqU(Ziu1)){Zhu1((ZZ3*)(Z_G(Ziu1)));
}Zet=(Z3)(((Zet))-(ZGs(1)));}}ZAU(((C)->Z4c));(C->ZBh)=ZGs(3);}}}void Zju1(ZZ3*C){if(((C)->Zrh)){if((Z3)((((C)->ZBh))<(ZGs(4)))){Z911(((C)->Z4c));
(C->ZBh)=ZGs(4);}}}T0*ZZa1(ZZ3*C,T0*a1){T0*R=Zo;T0*Z3r1=Zo;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Znl1(n,a1);Z3r1=((T0*)n);}R=ZjD((ZR6*)(((C)->Ztg)),Z3r1);
if((R)==((void*)(Zo))){R=ZyP(C,Z3r1);}return R;}void ZQT(ZZ3*C){T0*Zgq1=Zo;T0*ZRU=Zo;T0*ZxH=Zo;T2 Zet=0;T0*Z2U=Zo;T0*Z9e1=Zo;Zgq1=Zhq1;
((((T7*)(((T7*)Zgq1))))->Zdc)=(ZGs(0));ZRU=((C)->Z4c);ZWw((T7*)(Ztr1),Zku1);Z6t(((C)->_id),Ztr1);Zmx((T7*)(Ztr1),Zlu1);Z6t(((C)->_id),Ztr1);
if(ZbL(ZRU)){Zgt((T7*)(Ztr1),((T3)'\052'));}Zmx((T7*)(Ztr1),Zmu1);if(ZbL(ZRU)){Zmx(((T7*)Zgq1),Znu1);}Zmx(((T7*)Zgq1),Zou1);Zmx(((T7*)Zgq1),((C)->ZUc));
Zmx(((T7*)Zgq1),Zpu1);if((T6)((ZbL(ZRU))||((T6)(ZmH(ZRU))))){Zmx(((T7*)Zgq1),Zqu1);}Z2U=Z3U(C);if((Z2U)!=((void*)(Zo))){Zmx(((T7*)Zgq1),Zru1);
Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){Z9e1=ZUy(((ZV8*)Z2U),Zet);ZxH=((((ZE7*)Z9e1))->Zlc);Zmx(((T7*)Zgq1),Zsu1);Zmx(((T7*)Zgq1),(((ZD8*)(((((ZE7*)Z9e1))->Zpc)))->Zse));
Zmx(((T7*)Zgq1),Ztu1);if(ZqU(ZxH)){Z6t(ZEM(ZxH),Zgq1);Zmx(((T7*)Zgq1),Zuu1);}else if(ZwU(ZxH)){Zmx(((T7*)Zgq1),Zvu1);}else{Zmx(((T7*)Zgq1),Zwu1);
}Zmx(((T7*)Zgq1),Zxu1);if((T6)((Z3L(ZRU))&&((T6)(!((((T87*)(ZsO(ZRU)))->Zgg)))))){Zmx(((T7*)Zgq1),Zyu1);}else if(ZbL(ZRU)){Zmx(((T7*)Zgq1),Zzu1);
}else{Zgt(((T7*)Zgq1),((T3)'\056'));}Zgt(((T7*)Zgq1),((T3)'\137'));Zmx(((T7*)Zgq1),(((ZD8*)(((((ZE7*)Z9e1))->Zpc)))->Zse));Zmx(((T7*)Zgq1),ZAu1);
Zet=(Z3)(((Zet))-(ZGs(1)));if((Z3)((Zet)>(ZGs(0)))){Zmx(((T7*)Zgq1),ZBu1);}}Zmx(((T7*)Zgq1),ZCu1);}ZdS((Z84*)(ZkH),Ztr1,Zgq1);}T0*ZDu1(Zy5*C){
T0*R=Zo;R=ZGH(((C)->ZEh));return R;}void ZEu1(Zy5*C){ZgH(((C)->ZFh));}void ZFu1(Zy5*C,T0*a1,T2 a2){(C->ZFh)=ZaH(((C)->ZFh));}void ZGu1(Zy5*C){
T0*ZdH=Zo;T0*ZHu1=Zo;T2 Zet=0;if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){{T81 Zow;Zl61((Z84*)(ZkH),(*(Zow=ZIu1(C),&Zow)));}}ZgM((Z84*)(ZkH),ZJu1);
if(ZqU(ZnH(ZKu1(C)))){{T81 Zow;Z5G((*(Zow=ZIu1(C),&Zow)));}ZLu1(Z1G(45,"Right-hand side expanded Not Yet Implemented."));}ZdH=(((ZZ3*)(Z_G(ZDu1(C))))->Zof);
if(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(0))){if(!(Z_W(((C)->ZFh)))){ZD21(((C)->ZFh));ZgM((Z84*)(ZkH),ZCQ);
}ZD21(((C)->ZEh));ZgM((Z84*)(ZkH),ZMu1);}else if(ZXG(((C)->ZFh))){if(ZKF(((Z3a*)(((((Z23*)ZdH))->Z9e))),Z_G(ZGH(((C)->ZFh))))){ZD21(((C)->ZEh));
ZgM((Z84*)(ZkH),ZNu1);ZD21(((C)->ZFh));ZgM((Z84*)(ZkH),ZbR);}else{ZD21(((C)->ZEh));ZgM((Z84*)(ZkH),ZMu1);}}else if((T6)((((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1)))&&((T6)(!(ZhS((ZZ3*)((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZUb))[ZGs(0)]))))))){
ZD21(((C)->ZEh));ZdL((Z84*)(ZkH),((T3)'\075'));ZHu1=(((ZZ3*)(Z_G(ZKu1(C))))->Zof);if((T6)((((Z3)(((((((Ze7*)(((((Z23*)ZHu1))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1)))&&((T6)(((((((Ze7*)(((((Z23*)ZHu1))->Zae))))->ZUb))[ZGs(0)])==((void*)((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZUb))[ZGs(0)])))))){
}else{ZgM((Z84*)(ZkH),Z4T);ZdL((Z84*)(ZkH),((T3)'\073'));}ZD21(((C)->ZFh));ZgM((Z84*)(ZkH),ZCQ);}else{ZD21(((C)->ZEh));ZdL((Z84*)(ZkH),((T3)'\075'));
if(ZXG(((C)->ZFh))){ZgM((Z84*)(ZkH),ZOu1);}ZD21(((C)->ZFh));ZgM((Z84*)(ZkH),ZPu1);ZD21(((C)->ZEh));ZgM((Z84*)(ZkH),ZQu1);if((T6)(((T6)(((((T43*)(ZSG))->ZXk))&&((T6)(!(Z3L(ZGH(((C)->ZEh))))))))&&((T6)(Z3L(ZGH(((C)->ZFh))))))){
ZgM((Z84*)(ZkH),ZRu1);ZgM((Z84*)(ZkH),ZSu1);ZD21(((C)->ZEh));ZgM((Z84*)(ZkH),ZTu1);ZD21(((C)->ZEh));ZgM((Z84*)(ZkH),ZUu1);ZD21(((C)->ZEh));
ZgM((Z84*)(ZkH),ZVu1);}ZgM((Z84*)(ZkH),ZWu1);ZD21(((C)->ZEh));ZgM((Z84*)(ZkH),ZXu1);ZgM((Z84*)(ZkH),ZYu1);Zet=ZGs(1);while(!((Z3)((Zet)>((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1)))))))
{ZgM((Z84*)(ZkH),ZZu1);ZDM((Z84*)(ZkH),(T11)((((ZZ3*)((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZUb))[(Zet)-(ZGs(1))]))->_id)));ZdL((Z84*)(ZkH),((T3)'\072'));
Zet=(Z3)(((Zet))+(ZGs(1)));}ZgM((Z84*)(ZkH),Z_u1);ZD21(((C)->ZEh));ZgM((Z84*)(ZkH),Z0v1);}}T6 Z1v1(Zy5*C,T0*a1){T6 R=0;if(Z0b1(ZGH(((C)->ZEh)),a1)){
if(Z0b1(ZGH(((C)->ZFh)),a1)){if(ZWG(((C)->ZEh),a1)){if(ZWG(((C)->ZFh),a1)){R=((T6)(1));}}}}return R;}void Z2v1(Zy5*C,T0*a1,T0*a2){(C->ZEh)=a1;
(C->ZFh)=a2;}void ZLu1(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Z3v1(Zy5*C){ZLH(((C)->ZFh));}T6 Z4v1(Zy5*C){T6 R=0;
if(ZRH(((C)->ZEh))){R=((T6)(1));}else{R=((T6)(ZRH(((C)->ZFh))));}return R;}T6 Z5v1(Zy5*C){T6 R=0;if(Z0L(((C)->ZEh))){R=((T6)(Z0L(((C)->ZFh))));
}return R;}void Z6v1(Zy5*C,T0*a1){T6 ZxR=0;ZxR=((T6)(Z4L(((C)->ZEh),a1)));ZxR=((T6)(Z4L(((C)->ZFh),a1)));}T0*Z7v1(Zy5*C,T0*a1){T0*R=Zo;
{Zp8*n=((Zp8*)Zh(sizeof(*n)));*n=Z2l;ZzR(n,(T0*)C,a1);R=((T0*)n);}return R;}T0*Z8v1(Zy5*C,T0*a1){T0*R=Zo;T0*Z3V=Zo;T6 Z9v1=0;T6 Zav1=0;
if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;Z3V=ZyH(((C)->ZEh),a1);if((Z3V)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->ZEh)),&Zow)));
}{T0*b1=Zbv1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}(C->ZEh)=Z3V;Z3V=ZyH(((C)->ZFh),a1);if((Z3V)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->ZFh)),&Zow)));
}{T0*b1=Zcv1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}(C->ZFh)=Z3V;if(!(ZbL(ZnH(ZDu1(C))))){ZMT(ZnH(ZDu1(C)),Z1G(25," is not a reference Type."));
{T81 Zow;Z5G((*(Zow=ZIu1(C),&Zow)));}{T0*b1=Z1G(35," Invalid reverse assignment (VJRV).");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}if(ZXG(((C)->ZFh))){
}else if(!(ZJG(ZnH(ZDu1(C)),ZnH(ZKu1(C))))){Z9v1=((T6)(1));}else if(ZJG(ZnH(ZKu1(C)),ZnH(ZDu1(C)))){if((T6)(((T6)((!(Zh_(ZDu1(C))))&&((T6)(!(Z2_(ZKu1(C)))))))&&((T6)(!(Z2_(ZDu1(C))))))){
Zav1=((T6)(1));}}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));}if(Z9v1){{T81 Zow;Z5G((*(Zow=ZIu1(C),&Zow)));
}{T0*b1=Z1G(395,"Strange assignment attempt. The left-hand side expression should conform with the right-hand side (VJRV). Note: the previous constraint is more strict than ETL is, but, the SmartEiffel team is convinced that this is better for your safety to enforce this extra constraint. This code will not work in SE 2.x; it is accepted by SE 1.2 for compatibility with other compilers without this constraint");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}if(Zav1){ZMT(ZKu1(C),Z1G(6," is a "));ZMT(ZDu1(C),Z1G(55,". Simple assignment is allowed (\"\?=\" is not necessary)."));
{T81 Zow;Z5G((*(Zow=ZIu1(C),&Zow)));}ZPG((T80*)(Z4G));}{T81 Zow;Zy_((*(Zow=ZLG(((C)->ZFh)),&Zow)),ZGH(((C)->ZFh)),ZDu1(C));}R=((T0*)(C));
}else{{Zy5*n=((Zy5*)Zh(sizeof(*n)));*n=ZGh;Z2v1(n,((C)->ZEh),((C)->ZFh));R=((T0*)n);}R=Z8v1(((Zy5*)R),a1);}return R;}void Zdv1(Zy5*C){
ZFL(((C)->ZFh));}T0*ZKu1(Zy5*C){T0*R=Zo;R=ZGH(((C)->ZFh));return R;}T81 ZIu1(Zy5*C){T81 R={Zo,Zo,0};{T81 Zow;R=(*(Zow=ZLG(((C)->ZEh)),&Zow));
}return R;}void ZZP(T38*C){if(((C)->ZKh)){ZTF((T39*)(ZQF),((T3)'\n'));}}void Zev1(T38*C,T0*a1){if(Zfv1(a1)){ZvP(C,Zgv1);ZvP(C,a1);ZvP(C,Zhv1);
Ziv1(a1);}}void Zjv1(T38*C,T0*a1,T0*a2){ZvP(C,Zkv1);ZvP(C,a1);ZvP(C,Zlv1);ZvP(C,a2);ZvP(C,Zhv1);Zmv1(a1,a2);}T0*Znv1(void){if(ZE_==0){ZE_=1;{
{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;ZD_=((T0*)n);ZG_(n);}}}return ZD_;}void Zov1(T38*C,T0*a1,T0*a2){Zpv1(a1,a2);if(Zqv1(a1)){ZvP(C,Zrv1);
ZvP(C,a2);ZvP(C,Zsv1);}else{Zzi1(Ztv1);Zzi1(a2);Zzi1(Zhv1);Zv(ZGs(1));}}void Zuv1(T3 a1){{T3 b1=a1;Zvv1(b1,Zwv1);}Zxv1(Zwv1);}void ZR_(T38*C,T0*a1,T0*a2){
ZvP(C,Zyv1);ZvP(C,a2);ZvP(C,Zhv1);Zzv1(((T44*)a1),a2);}T0*ZAv1(T0*a1,T0*a2){T0*R=Zo;int ZOx=0;if((T6)((ZJx(((T7*)ZBv1),a1))||((T6)(ZJx(((T7*)ZCv1),a1))))){
Zzi1(ZDv1);Zzi1(a1);Zzi1(ZEv1);if((a2)!=((void*)(Zo))){Zzi1(ZFv1);Zzi1(a2);Zuv1(((T3)'\042'));}else{Zuv1(((T3)'\056'));}Zuv1(((T3)'\n'));
}R=ZGv1(a1);if((T6)(((R)==((void*)(Zo)))&&((T6)(ZJx(((T7*)ZHv1),a1))))){R=ZAv1(ZIv1,a2);if((T6)(((R)!=((void*)(Zo)))&&((T6)((Z3)((((((T7*)R))->Zdc))>(ZGs(9))))))){
ZJv1((T51*)(Znv1()),R);if((Z3)((((((T7*)R))->Zdc))>(ZGs(3)))){ZJv1((T51*)(Znv1()),R);}}}if((R)==((void*)(Zo))){if(ZJx(((T7*)ZBv1),a1)){
R=ZGv1(ZBv1);if((R)!=((void*)(Zo))){Zzi1(Z1G(77,"The old \"SmallEiffel\" variable is not valid anymore. Please use SmartEiffel.\n"));
}}else if(ZJx(((T7*)ZCv1),a1)){R=ZAv1(ZBv1,a2);if((R)!=((void*)(Zo))){Zzi1(Z1G(133,"The old \"SmallEiffelDirectory\" variable is not valid anymore. Please use SmartEiffelDirectory or,\nbetter still, don\'t use it at all.\n"));
if((Z3)((((((T7*)R))->Zdc))>(ZGs(9)))){ZJv1((T51*)(Znv1()),R);if((Z3)((((((T7*)R))->Zdc))>(ZGs(3)))){ZJv1((T51*)(Znv1()),R);}}}}}if((R)==((void*)(Zo))){
Zzi1(ZKv1);Zzi1(a1);Zuv1(((T3)'\175'));if((a2)!=((void*)(Zo))){Zzi1(ZLv1);Zzi1(a2);Zuv1(((T3)'\042'));}Zzi1(ZMv1);}return R;}void ZNv1(T38*C,T0*a1,T0*a2){
ZR_(C,a1,a2);if(!((((((T44*)a1))->Ztc))!=(Zo))){Zzi1(ZOv1);Zzi1(a2);Zzi1(Z1G(13,"\" not found.\n"));Zv(ZGs(1));}}void ZPv1(T38*C,T0*a1,T2
a2){if(((C)->ZKh)){if((Z3)((a2)>(ZGs(0)))){ZvP(C,ZQv1);ZvP(C,a1);if((Z3)((a2)>(ZGs(1)))){ZWP(C,((T3)'s'));}ZvP(C,ZRv1);ZSP(C,a2);ZvP(C,ZSv1);
}else{ZvP(C,ZTv1);ZvP(C,a1);ZvP(C,ZSv1);}}}void ZSP(T38*C,T2 a1){if(((C)->ZKh)){ZUv1((T39*)(ZQF),(T11)(a1));ZYP((T39*)(ZQF));}}void ZVv1(T38*C,T5
a1,T2 a2){if(((C)->ZKh)){ZWv1((T39*)(ZQF),a1,a2);ZYP((T39*)(ZQF));}}void Zzi1(T0*a1){ZXv1(a1);Zxv1(Zwv1);}void ZYv1(T2 a1){ZZv1((T11)(a1));
Zxv1(Zwv1);}void ZWP(T38*C,T3 a1){if(((C)->ZKh)){ZTF((T39*)(ZQF),a1);ZYP((T39*)(ZQF));}}void ZvP(T38*C,T0*a1){if(((C)->ZKh)){Z_v1((T39*)(ZQF),a1);
ZYP((T39*)(ZQF));}}T0*Z0w1=Zo;void Z1w1(ZG5*C,T0*a1){if(Z2w1(C)){Z001(((C)->ZVc),a1);}else{if(Z3w1(C)){ZwW((ZZ3*)(Z4w1(C)),a1);}else{
Zgt(((T7*)a1),((T3)'0'));}}}T0*Z5w1(ZG5*C){T0*R=Zo;R=ZJR(((C)->ZTc));return R;}T6 Z6w1(ZG5*C){T6 R=0;R=((T6)(ZMR(((C)->ZTc))));return
R;}T2 Z7w1(ZG5*C){T2 R=0;R=Znr1((ZZ3*)(Z4w1(C)));return R;}void Z8w1(ZG5*C,T0*a1){if(Z9w1(C)){Zmx(((T7*)a1),Z5T);}else{Zgt(((T7*)a1),((T3)'T'));
Z6t(Zaw1(C),a1);}}T6 Zbw1(void){T6 R=0;return R;}T6 Zcw1(ZG5*C){T6 R=0;T0*Z9T=Zo;Z9T=Zo;R=((T6)((Z9T)!=((void*)(Zo))));return R;}void
Zdw1(ZG5*C,T0*a1){Zmx(((T7*)a1),ZaT);Z6t(Zaw1(C),a1);}T6 Zew1(ZG5*C){T6 R=0;T0*ZjL=Zo;if((((C)->ZVc))!=(Zo)){ZjL=((C)->ZVc);if((C)==((void*)(ZjL))){
if((ZnH(ZjL))==((void*)(ZjL))){R=((T6)((ZcT(ZjL))==((void*)(Z9G(ZjL)))));}}}return R;}void Zfw1(ZG5*C){T0*ZJH=Zo;T2 ZVR=0;ZJH=Z4w1(C);
if(ZQt1(((ZZ3*)ZJH))){ZVR=((((ZZ3*)ZJH))->_id);ZWw((T7*)(ZYR),ZHR);Zgt((T7*)(ZYR),((T3)'\040'));Zdw1(C,ZYR);Zmx((T7*)(ZYR),Zgw1);Z6t(ZVR,ZYR);
Zmx((T7*)(ZYR),Zhw1);((((T7*)((T7*)(ZKR))))->Zdc)=(ZGs(0));ZkS(((ZZ3*)ZJH),(T6)(1),ZKR);ZdS((Z84*)(ZkH),ZYR,ZKR);}}T6 Ziw1(ZG5*C){T6 R=0;
R=((T6)(ZeT(((C)->ZTc))));return R;}T2 Zaw1(ZG5*C){T2 R=0;R=(((ZZ3*)(Z4w1(C)))->_id);return R;}void Zjw1(ZG5*C){((((T7*)((T7*)(ZgT))))->Zdc)=(ZGs(0));
Zgt((T7*)(ZgT),((T3)'\050'));Zkw1(C,ZgT);Zgt((T7*)(ZgT),((T3)'\051'));ZgM((Z84*)(ZkH),ZgT);}void Zlw1(ZG5*C,T0*a1,T0*a2){(C->ZCb)=((((ZG5*)a1))->ZCb);
(C->ZSc)=((((ZG5*)a1))->ZSc);(C->ZTc)=a2;if(ZqU(((C)->ZTc))){(C->ZUc)=Z9G(((C)->ZTc));(C->ZVc)=((C)->ZTc);}else{(C->ZUc)=Zmw1(Z9G(((C)->ZTc)));
(C->ZVc)=((T0*)(C));}}T6 Znw1(ZG5*C){T6 R=0;R=((T6)(ZqT(((C)->ZTc))));return R;}void Zow1(ZG5*C){if(Z2w1(C)){Zr01(((C)->ZVc));}else{Zpw1(C);
}}void Zqw1(ZG5*C){T2 ZuT=0;ZuT=Zaw1(C);((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));if(Z3w1(C)){Zmx((T7*)(ZvT),Z_S);Zmx((T7*)(ZvT),Z0T);Zgt((T7*)(ZvT),((T3)'\040'));
Zgt((T7*)(ZvT),((T3)'S'));Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'T'));Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZCQ);}else if(Z9w1(C)){
Zmx((T7*)(ZvT),Z_S);Zmx((T7*)(ZvT),Z5T);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'T'));Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZCQ);}ZgM((Z84*)(ZkH),ZvT);
}T6 Zrw1(ZG5*C){T6 R=0;R=((T6)(ZQt1((ZZ3*)(Z4w1(C)))));return R;}void Zsw1(ZG5*C,T0*a1){if(ZqU(((C)->ZTc))){Zw01(((C)->ZTc),a1);}else
if(Z9w1(C)){Zmx(((T7*)a1),Z5T);}else{Zgt(((T7*)a1),((T3)'T'));Z6t(Zaw1(C),a1);}}T6 Ztw1(ZG5*C,T0*a1){T6 R=0;R=((T6)(ZxT(((C)->ZTc),a1)));
return R;}T6 Zuw1(ZG5*C){T6 R=0;R=((T6)(ZzT(((C)->ZTc))));return R;}void Zvw1(ZG5*C,T81 a1,T0*a2){(C->ZCb)=a1;(C->ZTc)=a2;(C->ZSc)=Zmw1(ZcT(((C)->ZTc)));
}T0*Zww1(ZG5*C){T0*R=Zo;R=ZBT(((C)->ZTc));return R;}void Zxw1(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}T6 Zyw1(ZG5*C){T6
R=0;R=((T6)(ZET(((C)->ZTc))));return R;}T0*Zzw1(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);
ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);
ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);
ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);
ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);
ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);
ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);
ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);
ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);
ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);
ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);
ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);
ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);
ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);
ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T0*ZAw1(ZG5*C){T0*R=Zo;T0*ZKT=Zo;if((((C)->ZQc))!=((void*)(Zo))){
R=((C)->ZQc);}else{ZKT=Zww1(C);if((ZKT)!=((void*)(Zo))){(C->ZQc)=ZLT(((T85*)ZKT));R=((C)->ZQc);}else{{T0*b1=Z1G(27,"Cannot find Base Class for ");
Zmx((T7*)(Z2G),b1);}ZMT((T0*)C,Z0O);ZaG((T80*)(Z4G));}}return R;}T0*ZBw1(ZG5*C,T81 a1){T0*R=Zo;if(Zuw1(C)){{Zw1*n=((Zw1*)Zh(sizeof(*n)));
*n=ZQl;ZMN(n,(T11)(ZGs(0)),a1);R=((T0*)n);}}else if(ZCw1(C)){{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zml;ZwL(n,a1);R=((T0*)n);}}else if(Zyw1(C)){
{ZH4*n=((ZH4*)Zh(sizeof(*n)));*n=ZRg;ZOX(n,a1,((T3)'\000'));R=((T0*)n);}}else if((T6)((Znw1(C))||((T6)(ZDw1(C))))){{ZC9*n=((ZC9*)Zh(sizeof(*n)));
*n=Zdm;ZJ01(n,a1,(T5)(0.0),(T0*)C);R=((T0*)n);}}return R;}T6 Z9w1(ZG5*C){T6 R=0;if(ZEw1(C)){R=((T6)((Z3U((ZZ3*)(Z4w1(C))))==((void*)(Zo))));
}return R;}void ZFw1(ZG5*C,T0*a1){Zgt(((T7*)a1),((T3)'\045'));Zgt(((T7*)a1),((T3)'E'));Z6t(Zaw1(C),a1);Zgt(((T7*)a1),((T3)'\045'));}void
ZGw1(ZG5*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){ZQT((ZZ3*)(Z4w1(C)));}}T6 Z3w1(ZG5*C){T6 R=0;if(ZqU(((C)->ZTc))){R=((T6)(ZfL(((C)->ZTc))));
}else{R=((T6)((Z3U((ZZ3*)(Z4w1(C))))!=((void*)(Zo))));}return R;}T6 ZHw1(ZG5*C){T6 R=0;T0*ZST=Zo;ZST=Zo;R=((T6)((ZST)!=((void*)(Zo))));
return R;}void Zkw1(ZG5*C,T0*a1){if(Z9w1(C)){Zmx(((T7*)a1),Z5T);}else{Zgt(((T7*)a1),((T3)'T'));Z6t(Zaw1(C),a1);Zgt(((T7*)a1),((T3)'\052'));
}}T0*ZIw1(ZG5*C,T0*a1){T0*R=Zo;T81 ZjG={Zo,Zo,0};if(ZqU(((C)->ZTc))){ZjG=((C)->ZCb);if((((ZjG).Zxb))==(ZGs(0))){if((a1)!=((void*)(Zo))){
{T81 Zow;ZjG=(*(Zow=ZrP(a1),&Zow));}}}{ZK1*n=((ZK1*)Zh(sizeof(*n)));*n=Zed;ZcW(n,ZjG,ZnH(((C)->ZTc)));R=((T0*)n);}}else{R=((C)->ZTc);
}return R;}T0*Zmw1(T0*a1){T0*R=Zo;ZWw((T7*)(ZvT),ZJw1);Zgt((T7*)(ZvT),((T3)'\040'));Zmx((T7*)(ZvT),a1);R=(((void)((T27*)(Zzw1()))),ZCG(ZvT));
return R;}void Zpw1(ZG5*C){T0*Z2U=Zo;T2 Zet=0;T0*ZiL=Zo;if(Z9w1(C)){ZdL((Z84*)(ZkH),((T3)'0'));}else{ZdL((Z84*)(ZkH),((T3)'\173'));Z2U=Z3U((ZZ3*)(Z4w1(C)));
Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){ZiL=ZUy(((ZV8*)Z2U),Zet);Zr01(((((ZE7*)ZiL))->Zlc));Zet=(Z3)(((Zet))-(ZGs(1)));if((Z3)((Zet)>(ZGs(0)))){
ZdL((Z84*)(ZkH),((T3)'\054'));}}ZdL((Z84*)(ZkH),((T3)'\175'));}}void ZKw1(ZG5*C){T0*Z2U=Zo;T2 Zet=0;T2 ZuT=0;T0*ZKO=Zo;T0*ZxH=Zo;ZuT=Zaw1(C);
Z2U=Z3U((ZZ3*)(Z4w1(C)));ZWw((T7*)(ZvT),Z0T);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'S'));Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\173'));
if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){ZKO=ZUy(((ZV8*)Z2U),Zet);ZxH=ZnH(((((ZE7*)ZKO))->Zlc));ZmW(ZxH,ZvT);
Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'\137'));Zmx((T7*)(ZvT),(((ZD8*)(((((ZE7*)ZKO))->Zpc)))->Zse));Zgt((T7*)(ZvT),((T3)'\073'));
Zet=(Z3)(((Zet))-(ZGs(1)));}}Zgt((T7*)(ZvT),((T3)'\175'));Zmx((T7*)(ZvT),ZCQ);ZgM((Z84*)(ZkH),ZvT);ZWw((T7*)(ZvT),Z5T);Zgt((T7*)(ZvT),((T3)'\040'));
Zmx((T7*)(ZvT),ZL31);Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZLw1);Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZMw1);Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZNw1);ZdS((Z84*)(ZkH),ZvT,ZOw1);
}T6 ZPw1(ZG5*C){T6 R=0;R=((T6)(Z9U(((C)->ZTc))));return R;}T6 ZDw1(ZG5*C){T6 R=0;R=((T6)(ZbU(((C)->ZTc))));return R;}void ZQw1(T0*a1){
ZdU(a1,ZeU);ZdU(a1,ZV01);ZgU(a1,((T3)'\n'));}T6 ZEw1(ZG5*C){T6 R=0;if(ZIG(((C)->ZTc))){}else{R=((T6)(1));}return R;}T6 ZRw1(ZG5*C,T0*a1){
T6 R=0;R=((T6)(ZJG(((C)->ZTc),a1)));if(!(R)){ZiU((T0*)C,a1);}return R;}T0*ZSw1(ZG5*C){T0*R=Zo;if(!((((((C)->ZCb)).Zxb))==(ZGs(0)))){R=ZkU(&(((C)->ZCb)));
}return R;}T6 ZCw1(ZG5*C){T6 R=0;R=((T6)(ZmU(((C)->ZTc))));return R;}T0*ZTw1(ZG5*C,T0*a1){T0*R=Zo;T0*ZoU=Zo;if((((C)->ZVc))==((void*)(C))){
R=((T0*)(C));}else if((((C)->ZVc))==((void*)(((C)->ZTc)))){R=((T0*)(C));}else{ZoU=ZxP(((C)->ZTc),a1);if((ZoU)==((void*)(Zo))){Z5G(((C)->ZCb));
Zxw1(Z1G(26,"Bad outside expanded type."));}else if(Z3L(ZoU)){Z5G(((C)->ZCb));{T0*b1=ZUw1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}if((((C)->ZVc))!=((void*)(Zo))){
{ZG5*n=((ZG5*)Zh(sizeof(*n)));*n=ZLh;Zlw1(n,(T0*)C,ZnH(ZoU));R=((T0*)n);}}else if(ZqU(ZoU)){(C->ZVc)=ZoU;(C->ZUc)=Z9G(ZoU);R=((T0*)(C));
}else if((((C)->ZTc))==((void*)(ZnH(ZoU)))){(C->ZUc)=Zmw1(Z9G(ZoU));(C->ZVc)=((T0*)(C));R=((T0*)(C));}else{(C->ZUc)=Zmw1(Z9G(ZoU));{ZG5*n=((ZG5*)Zh(sizeof(*n)));
*n=ZLh;Zlw1(n,(T0*)C,ZnH(ZoU));(C->ZVc)=((T0*)n);}R=((T0*)(C));}ZCP((ZZ3*)(Z_G(((C)->ZTc))));ZCP((ZZ3*)(Z_G(((((ZG5*)R))->ZVc))));}return
R;}void ZVw1(ZG5*C){T2 ZuT=0;T0*ZJH=Zo;ZJH=Z4w1(C);ZuT=((((ZZ3*)ZJH))->_id);((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));Zgt((T7*)(ZvT),((T3)'T'));
Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'M'));Z6t(ZuT,ZvT);ZWT((Z84*)(ZkH),ZvT);ZXT((Z84*)(ZkH));((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));
ZwW(((ZZ3*)ZJH),ZvT);Zmx((T7*)(ZvT),ZCQ);ZgM((Z84*)(ZkH),ZvT);ZZT((Z84*)(ZkH));}T0*ZWw1(ZG5*C){T0*R=Zo;T0*ZuU=Zo;ZuU=Zww1(C);if((ZuU)!=((void*)(Zo))){
R=ZLT(((T85*)ZuU));}return R;}T0*Z4w1(ZG5*C){T0*R=Zo;if((((C)->ZRc))!=((void*)(Zo))){R=((C)->ZRc);}else if((((C)->ZVc))!=(Zo)){(C->ZRc)=ZyU(((C)->ZVc));
R=((C)->ZRc);}return R;}void ZXw1(ZG5*C){if(Z3w1(C)){if((((C)->ZVc))==((void*)(C))){ZKw1(C);}else{ZAU(((C)->ZVc));}}ZVw1(C);}T0*ZYw1(ZG5*C,T0*a1){
T0*R=Zo;if((((C)->ZUc))==((void*)(Z9G(a1)))){R=((C)->ZVc);}else{R=ZnH(ZDU(((C)->ZTc),a1));}return R;}T6 Z2w1(ZG5*C){T6 R=0;if((((C)->ZVc))==((void*)(((C)->ZTc)))){
R=((T6)(ZIG(((C)->ZTc))));}return R;}void ZZw1(ZG5*C,T0*a1){Zmx(((T7*)a1),ZwS);Z6t(Zaw1(C),a1);Zgt(((T7*)a1),((T3)'\050'));Zgt(((T7*)a1),((T3)'\051'));
}void Z_w1(ZI5*C,T0*a1){{Zk1*n=((Zk1*)Zh(sizeof(*n)));*n=ZXc;ZWz(n,(T2)(ZGs(4)));(C->ZZb)=((T0*)n);}ZVz((Zk1*)(((C)->ZZb)),a1);}T0*Z0x1(ZI5*C,T0*a1){
T0*R=Zo;T2 Zet=0;T0*Z1x1=Zo;T0*Z2x1=Zo;T6 Z3x1=0;Z2x1=((((ZD8*)a1))->Zcn);R=a1;Zet=(((Zk1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{Z1x1=((((Zk1*)(((C)->ZZb)))->ZUb))[Zet];if(((((ZD8*)(((((ZR4*)Z1x1))->Z_g)))->Zcn))==((void*)(Z2x1))){R=((((ZR4*)Z1x1))->ZZg);}else if(((((ZD8*)(((((ZR4*)Z1x1))->ZZg)))->Zcn))==((void*)(Z2x1))){
Z3x1=((T6)(1));}Zet=(Z3)(((Zet))-(ZGs(1)));}if((T6)((Z3x1)&&((T6)((R)==((void*)(a1)))))){R=Zo;}return R;}T0*Z4x1(ZI5*C,T0*a1){T0*R=Zo;
T2 Zet=0;T0*Z1x1=Zo;T0*Z2x1=Zo;T6 Z3x1=0;Z2x1=((((ZD8*)a1))->Zcn);R=a1;Zet=(((Zk1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{Z1x1=((((Zk1*)(((C)->ZZb)))->ZUb))[Zet];if(((((ZD8*)(((((ZR4*)Z1x1))->ZZg)))->Zcn))==((void*)(Z2x1))){R=((((ZR4*)Z1x1))->Z_g);Zet=ZGs(-1);
}else if(((((ZD8*)(((((ZR4*)Z1x1))->Z_g)))->Zcn))==((void*)(Z2x1))){Z3x1=((T6)(1));}Zet=(Z3)(((Zet))-(ZGs(1)));}if((T6)((Z3x1)&&((T6)((R)==((void*)(a1)))))){
R=Zo;}return R;}void Z5x1(ZI5*C,T0*a1){T2 Zet=0;T2 Z3x=0;T0*Z6x1=Zo;T0*Z7x1=Zo;Zet=(((Zk1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{Z6x1=((((Zk1*)(((C)->ZZb)))->ZUb))[Zet];if(!(ZPe1(((T87*)a1),((((ZR4*)Z6x1))->Z_g)))){Z5G((((ZD8*)(((((ZR4*)Z6x1))->Z_g)))->ZCb));{T0*b1=Z1G(42,"Cannot rename inexistant feature (VHRC.1).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zet=(Z3)(((Zet))-(ZGs(1)));Z3x=Zet;while(!((Z3)((Z3x)<(ZGs(0))))){Z7x1=((((Zk1*)(((C)->ZZb)))->ZUb))[Z3x];
if(((((ZD8*)(((((ZR4*)Z7x1))->Z_g)))->Zcn))==((void*)((((ZD8*)(((((ZR4*)Z6x1))->Z_g)))->Zcn)))){Z5G((((ZD8*)(((((ZR4*)Z6x1))->Z_g)))->ZCb));
Z5G((((ZD8*)(((((ZR4*)Z7x1))->Z_g)))->ZCb));{T0*b1=Z1G(46,"Multiple rename for the same feature (VHRC.2).");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));
}Z3x=(Z3)(((Z3x))-(ZGs(1)));}}}T0*Z8x1(ZK5*C,T0*a1,T0*a2){T0*R=Zo;{T81 Zow;Z5G((*(Zow=Z9x1(C),&Zow)));}Zax1(((((ZD8*)a1))->ZCb),Z1G(42,"An attribute must not be undefined (VDUS)."));
ZTN(((T87*)a2),a1);return R;}void Zax1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T6 Zbx1(ZK5*C,T0*a1,T0*a2){
T6 R=0;if((((C)->Zlc))!=((void*)(ZBL(a1)))){if((T6)(((((C)->Zlc))==((void*)(Zo)))||((T6)((ZBL(a1))==((void*)(Zo)))))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));
}{T81 Zow;Zax1((*(Zow=Z9x1(C),&Zow)),ZWN);}}}if((Zo)!=((void*)(ZXN(a1)))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Zax1((*(Zow=Z9x1(C),&Zow)),ZYN);
}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){if((((C)->Zlc))!=((void*)(Zo))){if(!(ZZN(ZBL(a1),((C)->Zlc),a2,(T6)(0)))){{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);
}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
}R=((T6)(((((T80*)(Z4G))->ZEg))==(ZGs(0))));if(R){Zcx1(C,a1);}return R;}void Zcx1(ZK5*C,T0*a1){if((((T43*)(ZSG))->ZRk)){if((((C)->ZHb))==((void*)(Zo))){
(C->ZHb)=Z2O(a1);}else if((Z2O(a1))==((void*)(Zo))){Z3O(a1,((C)->ZHb));}}}void Zdx1(ZK5*C,T0*a1){T2 Zet=0;T0*Z5O=Zo;T0*Z6O=Zo;(C->Zvb)=(((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),ZGs(1))))->ZCb)).Zvb);
Zet=ZGs(1);while(!((Z3)((Zet)>(Z8O((Zz8*)(((C)->Zkc))))))){Z5O=Z7O((Zz8*)(((C)->Zkc)),Zet);Z6O=Z3D(((Zp6*)a1),Z5O);if((Z6O)!=((void*)(Zo))){
Z5O=((((Zz8*)(((((ZX4*)Z6O))->Zkc))))->ZGd);Z5G(((((ZD8*)Z5O))->ZCb));Z5G((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),Zet)))->ZCb));{T0*b1=Z1G(29,"Double definition of feature ");
Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)Z5O))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}else{Z0D(((Zp6*)a1),(T0*)C,Z5O);
}Zet=(Z3)(((Zet))+(ZGs(1)));}}T0*Zex1(ZK5*C,T0*a1,T0*a2){T0*R=Zo;T0*ZaO=Zo;Z5G(((((ZD8*)a1))->ZCb));ZaO=ZbO((Zz8*)(((C)->Zkc)),((((ZD8*)a1))->Zcn));
if((ZaO)!=((void*)(Zo))){ZcO(((ZD8*)ZaO),a2);}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=Z8x1(C,a1,a2);
if((R)!=((void*)(Zo))){((((ZE3*)(((ZE3*)R))))->Zjc)=(((C)->Zjc));Zcx1(C,R);}else{ZTN(((T87*)a2),a1);}return R;}void Zfx1(ZK5*C,T0*a1,T0*a2,T0*a3){
((((ZK5*)(C)))->Zkc)=(a1);(C->Zlc)=a2;(C->Zmc)=a3;}T0*Zgx1(ZK5*C,T0*a1,T0*a2){T0*R=Zo;T0*ZJH=Zo;ZJH=Z_G(a1);R=ZjD(((ZR6*)(((((ZZ3*)ZJH))->Ztg))),a2);
if(Zo!=(R)){switch(((T0*)R)->id){case 583:break;default:R=Zo;}}if((R)==((void*)(Zo))){{ZC7*n=((ZC7*)Zh(sizeof(*n)));*n=Zak;ZfO(n,a1,a2,(T0*)C);
R=((T0*)n);}}return R;}T6 Zhx1(ZK5*C,T0*a1){T6 R=0;if((((C)->Zlc))==((void*)(Zo))){R=((T6)((ZBL(a1))!=((void*)(Zo))));}else{R=((T6)((ZBL(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZWN;Zmx((T7*)(Z2G),b1);}}else{R=((T6)((ZXN(a1))!=((void*)(Zo))));if(R){{T0*b1=ZYN;Zmx((T7*)(Z2G),b1);}}}Zcx1(C,a1);return
R;}T81 Z9x1(ZK5*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->ZCb);return R;}void Zix1(ZT4*C,T0*a1){T2 Zet=0;T0*Z6O=Zo;
if((((C)->ZZb))!=((void*)(Zo))){Zet=ZGs(0);while(!((Z3)((Zet)>((((ZY9*)(((C)->ZZb)))->ZWb))))){Z6O=((((ZY9*)(((C)->ZZb)))->ZUb))[Zet];
((((ZX4*)(((ZX4*)Z6O))))->Zjc)=(((C)->Zjc));Zjx1(Z6O,a1);Zet=(Z3)(((Zet))+(ZGs(1)));}}}void Zkx1(ZT4*C,T0*a1,T0*a2,T0*a3){(C->Zjc)=a1;
(C->Zqd)=a2;(C->ZZb)=a3;}
#ifdef __cplusplus
}
#endif

