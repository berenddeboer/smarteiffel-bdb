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
T6 Zmc2(Z89*C){T6 R=0;R=((T6)(Z4V(((C)->Z1d))));return R;}T6 Znc2(Z89*C){T6 R=0;R=((T6)(ZMg1(((C)->Z1d))));return R;}T0*Zoc2(Z89*C,T0*a1){
T0*R=Zo;T0*ZKX=Zo;T0*ZJH=Zo;T0*ZjL=Zo;ZjL=((C)->ZIl);if((T6)((ZbU(ZjL))||((T6)(ZqT(ZjL))))){ZKX=a1;if(Zo!=(ZKX)){switch(((T0*)ZKX)->id){
case 262:break;default:ZKX=Zo;}}if((ZKX)!=((void*)(Zo))){{T81 Zow;{ZC9*n=((ZC9*)Zh(sizeof(*n)));*n=Zdm;ZJ01(n,(*(Zow=Zpc2(C),&Zow)),Zot(((((Zw1*)ZKX))->ZMl)),ZjL);
R=((T0*)n);}}}else{ZJH=a1;if(Zo!=(ZJH)){switch(((T0*)ZJH)->id){case 258:break;default:ZJH=Zo;}}if((ZJH)!=((void*)(Zo))){((((ZC9*)(((ZC9*)ZJH))))->Zlc)=(ZjL);
R=ZJH;}else{R=((T0*)(C));}}}else if(ZzT(ZjL)){ZKX=a1;if(Zo!=(ZKX)){switch(((T0*)ZKX)->id){case 262:break;default:ZKX=Zo;}}if((ZKX)!=((void*)(Zo))){
R=ZKX;}else{R=((T0*)(C));}}else{R=((T0*)(C));}return R;}T0*Zqc2(Z89*C){T0*R=Zo;R=Zoc2(C,ZaH(((C)->Z1d)));return R;}void Zrc2(Z89*C){ZgH(((C)->Z1d));
}void Zsc2(Z89*C){if((((C)->ZJl))==((void*)(Zo))){ZgM((Z84*)(ZkH),Ztc2);ZcL(((C)->ZIl));}else{ZgM((Z84*)(ZkH),((C)->ZJl));}ZdL((Z84*)(ZkH),((T3)'\050'));
}T6 Zuc2(Z89*C){T6 R=0;R=((T6)(Ze31(((C)->Z1d))));return R;}void Zvc2(Z89*C){T2 Zet=0;Zsc2(C);if(ZbL(((C)->Zmf))){ZdL((Z84*)(ZkH),((T3)'\050'));
Zet=ZGs(1);while(!((((((T7*)(((C)->ZJl)))->ZUb))[(Zet)-(ZGs(1))])==(((T3)'t')))){ZdL((Z84*)(ZkH),((((T7*)(((C)->ZJl)))->ZUb))[(Zet)-(ZGs(1))]);
Zet=(Z3)(((Zet))+(ZGs(1)));}ZgM((Z84*)(ZkH),Zwc2);ZD21(((C)->Z1d));ZdL((Z84*)(ZkH),((T3)'\051'));}else{ZR21(((C)->Z1d),((C)->Zmf));}ZdL((Z84*)(ZkH),((T3)'\051'));
}T6 Zxc2(Z89*C){T6 R=0;R=((T6)(ZRg1(((C)->Z1d))));return R;}T6 Zyc2(Z89*C,T0*a1){T6 R=0;R=((T6)(ZWG(((C)->Z1d),a1)));return R;}void Zzc2(Z89*C,T0*a1,T0*a2){
ZqH(((C)->Z1d),a1,a2);}void ZAc2(Z89*C){{T81 Zow;Z5G((*(Zow=Zpc2(C),&Zow)));}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZBc2(Z89*C,T0*a1,T0*a2){(C->Z1d)=a1;(C->Zmf)=ZnH(ZGH(a1));(C->ZIl)=ZnH(a2);if((T6)((ZqU(((C)->Zmf)))&&((T6)(ZbL(((C)->ZIl)))))){
{T81 Zow;Z5G((*(Zow=ZLG(a1),&Zow)));}{T0*b1=ZCc2;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((C)->Zmf));Zmx((T7*)(Z2G),b1);}{T0*b1=ZDc2;Zmx((T7*)(Z2G),b1);
}{T0*b1=Z9G(((C)->ZIl));Zmx((T7*)(Z2G),b1);}{T0*b1=ZEc2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}if((T6)((ZqU(((C)->Zmf)))&&((T6)(ZqU(((C)->ZIl)))))){
{T81 Zow;if((T6)(((T6)(((T6)((ZzT(((C)->Zmf)))&&((T6)(Zxs((T6)(ZqT(((C)->ZIl))),(T6)(ZbU(((C)->ZIl))))))))&&((T6)(((((T85*)(ZkU(&((*(Zow=ZLG(a1),&Zow))))))->Zse))!=((void*)(ZaI))))))&&((T6)((Z3)((Zb01(((C)->Zmf)))>=(Zb01(((C)->ZIl)))))))){
{T81 ZH81;Z5G((*(ZH81=ZLG(a1),&ZH81)));}{T0*b1=ZFc2;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((C)->Zmf));Zmx((T7*)(Z2G),b1);}{T0*b1=ZGc2;Zmx((T7*)(Z2G),b1);
}{T0*b1=Z9G(((C)->ZIl));Zmx((T7*)(Z2G),b1);}{T0*b1=ZHc2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}}}else{(C->ZJl)=ZIc2(((C)->Zmf),((C)->ZIl));
}if((T6)((ZMR(((C)->Zmf)))&&((T6)(ZbL(((C)->ZIl)))))){{T81 Zow;ZdW((*(Zow=ZLG(a1),&Zow)));}}}void ZJc2(Z89*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);
}{T81 Zow;Z5G((*(Zow=Zpc2(C),&Zow)));}Z3G((T80*)(Z4G));}T2 ZKc2(Z89*C){T2 R=0;R=ZsN(((C)->Z1d));return R;}void ZLc2(Z89*C,T0*a1){ZuN(((C)->Z1d),a1);
}void ZMc2(Z89*C,T3 a1){ZEH(((C)->Z1d),a1);}void ZNc2(Z89*C){ZLH(((C)->Z1d));}T6 ZOc2(Z89*C){T6 R=0;R=((T6)(ZRH(((C)->Z1d))));return R;
}T6 ZPc2(Z89*C){T6 R=0;R=((T6)(Z0L(((C)->Z1d))));return R;}T6 ZQc2(Z89*C){T6 R=0;R=((T6)(Z5h1(((C)->Z1d))));return R;}T6 ZRc2(T0*a1){
T6 R=0;return R;}T6 ZSc2(Z89*C){T6 R=0;R=((T6)(Z_W(((C)->Z1d))));return R;}T2 ZTc2(Z89*C){T2 R=0;ZJc2(C);return R;}T0*ZUc2(Z89*C,T0*a1){
T0*R=Zo;R=ZyH(((C)->Z1d),a1);return R;}T0*ZVc2(Z89*C){T0*R=Zo;R=Zoc2(C,ZSh1(((C)->Z1d)));return R;}T0*ZWc2(Z89*C){T0*R=Zo;R=ZsO(((C)->ZIl));
return R;}void ZXc2(Z89*C){ZFL(((C)->Z1d));}T6 ZYc2(Z89*C){T6 R=0;R=((T6)(ZXG(((C)->Z1d))));return R;}T81 Zpc2(Z89*C){T81 R={Zo,Zo,0};
{T81 Zow;R=(*(Zow=ZLG(((C)->Z1d)),&Zow));}return R;}Zu3*Zca1(T81 a1){Zu3*n;n=((Zu3*)Zh(sizeof(*n)));*n=ZLl;((((Zu3*)(n)))->ZCb)=(a1);
return n;}void ZZc2(Zu3*C){ZXv1(Z1G(616,"Sorry, some feature is not yet implemented (i.e. feature\n`not_yet_implemented\' of class GENERAL has been called somewhere). If\nthis is not the case, just run this code under the debugger to\nknow the `not_yet_implemented\' caller. If this is a feature of the\nSmartEiffel library, you may consider to post your\nimplementation on the SmartEiffel mailing list.\n                               e-mail: smarteiffel@except.com.ar\n                              Happy debug and thanks in advance.\n                   http://opensvn.csie.org/traccgi/smarteiffel12\n                                                Daniel F Moisset\n"));
Z_c2(C);}void Z0d2(Zu3*C,T81 a1,T0*a2){(C->ZCb)=a1;(C->ZGb)=a2;}void Z1d2(Zu3*C){ZdL((Z84*)(ZkH),((T3)'a'));ZDM((Z84*)(ZkH),(T11)(((C)->Zpe)));
}T6 Z2d2(T0*a1){T6 R=0;return R;}void Z3d2(Zu3*C){Z5G(((C)->ZCb));{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Z4d2(Zu3*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}Z5G(((C)->ZCb));Z3G((T80*)(Z4G));}void Z_c2(Zu3*C){
Zu();Zv(ZGs(1));}T0*Z2M1(Zu3*C){T0*R=Zo;if((((C)->ZGb))==((void*)(Zo))){R=Z8a1((Zz6*)(ZAP(((C)->Z3c))),((C)->Zpe));}else{R=((C)->ZGb);
}R=ZnH(R);return R;}T0*ZaH1(Zu3*C,T0*a1,T0*a2,T2 a3){T0*R=Zo;if((((C)->Z3c))==((void*)(Zo))){(C->Z3c)=a2;(C->Zpe)=a3;ZTM1(((ZV6*)a1),(T0*)C);
R=((T0*)(C));}else{{Zu3*n=((Zu3*)Zh(sizeof(*n)));*n=ZLl;Z0d2(n,((C)->ZCb),((C)->ZGb));R=((T0*)n);}R=ZaH1(((Zu3*)R),a1,a2,a3);}return R;
}T6 Z5d2(T0*a1){T6 R=0;return R;}T2 Z6d2(Zu3*C){T2 R=0;Z4d2(C);return R;}T0*Z7d2(Zu3*C,T0*a1){T0*R=Zo;T0*ZxH=Zo;if((((C)->Z3c))==((void*)(Zo))){
Z5G(((C)->ZCb));{T0*b1=Z1G(59,"Open operand out of agent scope. (Missing \"agent\" keyword\?)");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));
}else if((((C)->ZGb))!=((void*)(Zo))){ZxH=ZxP(((C)->ZGb),a1);if((ZxH)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZrP(((C)->ZGb)),&Zow)));}{T0*b1=Z8d2;
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}(C->ZGb)=ZxH;ZxH=Z8a1((Zz6*)(ZAP(((C)->Z3c))),((C)->Zpe));if(!(ZJG(((C)->ZGb),ZxH))){{T81 Zow;Z5G((*(Zow=ZrP(((C)->ZGb)),&Zow)));
}{T81 Zow;Z5G((*(Zow=ZrP(ZxH),&Zow)));}{T0*b1=Z8d2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}R=((T0*)(C));return R;}T0*Z9d2(Zu3*C){T0*R=Zo;
ZZc2(C);return R;}void Zad2(Ze9*C){Zbd2(C);ZpG((((ZD8*)(((C)->Z2c)))->ZCb),((C)->ZFb),((C)->Z3c));}T0*Zcd2(void){if(ZrG==0){ZrG=1;{{ZG9*n=((ZG9*)Zh(sizeof(*n)));
*n=Zfm;ZqG=((T0*)n);{ZG9*C1=n;ZhF(C1,ZGs(53));}}ZgF(((ZG9*)ZqG),ZtG);ZgF(((ZG9*)ZqG),ZuG);ZgF(((ZG9*)ZqG),ZvG);ZgF(((ZG9*)ZqG),ZwG);ZgF(((ZG9*)ZqG),ZxG);
ZgF(((ZG9*)ZqG),ZyG);ZgF(((ZG9*)ZqG),ZzG);ZgF(((ZG9*)ZqG),ZAG);ZgF(((ZG9*)ZqG),(((void)((T27*)(Zdd2()))),ZCG(ZDG)));ZgF(((ZG9*)ZqG),(((void)((T27*)(Zdd2()))),ZCG(ZEG)));
}}return ZqG;}T0*Zed2(Ze9*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;T0*ZGG=Zo;T0*ZHG=Zo;R=a1;if(ZIG(a2)){if(ZIG(a3)){ZHG=Z9G(a3);ZGG=Z9G(a2);if((ZHG)!=((void*)(ZGG))){
if(ZJG(a2,a3)){R=ZKG(a1,a3);if((T6)(((R)!=((void*)(a1)))&&((T6)(!(ZfF((ZG9*)(Zcd2()),(((ZD8*)(((C)->Z2c)))->Zse))))))){{T81 Zow;Z5G((*(Zow=ZLG(a1),&Zow)));
}{T0*b1=ZMG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZGG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZNG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZHG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZOG;
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));}}}}return
R;}T6 Zfd2(Ze9*C,T0*a1){T6 R=0;T0*ZUG=Zo;if((((C)->ZFb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(ZVG((Za3*)(((C)->ZFb)),a1)));}if(R){
if((((C)->Z3c))==((void*)(Zo))){R=((T6)(ZWG(((C)->Z1c),a1)));}else if(ZXG(((C)->Z1c))){if(ZYG(((C)->Z3c),a1)){R=((T6)((ZZG(((C)->Z3c),a1))!=((void*)(Zo))));
}else{R=((T6)(0));}}else{R=((T6)(ZWG(((C)->Z1c),a1)));if(R){if((((C)->Z3c))!=((void*)(Zo))){ZUG=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Z3c)))->Z4c))))->Zof);
if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZUG))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){R=((T6)(ZYG(((C)->Z3c),ZUG)));}}}}}return R;}T0*Zgd2(Ze9*C,T0*a1){
T0*R=Zo;R=Z1H((Za3*)(((C)->ZFb)),a1);if((R)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z2H((Za3*)(((C)->ZFb))),&Zow)));}{T0*b1=Z3H;Zmx((T7*)(Z2G),b1);
}Z4H(a1);ZaG((T80*)(Z4G));}return R;}void Zhd2(Ze9*C,T0*a1,T0*a2,T0*a3){(C->Z3c)=Zo;(C->Z4c)=Zo;(C->Z1c)=a1;(C->Z2c)=a2;(C->ZFb)=a3;}
T0*Zid2(Ze9*C){T0*R=Zo;if((((T43*)(ZSG))->ZRk)){R=((T0*)(C));}else{R=((T0*)(C));if((R)!=((void*)(C))){Z8H((T43*)(ZSG));}}return R;}T0*Zjd2(Ze9*C){
T0*R=Zo;(C->Z1c)=ZaH(((C)->Z1c));ZbH((Za3*)(((C)->ZFb)));R=((T0*)(C));return R;}void Zkd2(Ze9*C){T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){
if((((C)->ZFb))!=((void*)(Zo))){ZdH=(((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>=(ZGs(1)))){
{T81 Zow;ZeH((T43*)(ZSG),(*(Zow=Zld2(C),&Zow)),((C)->Z3c),ZdH);}}}}ZgH(((C)->Z1c));if((((C)->ZFb))!=((void*)(Zo))){ZhH((Za3*)(((C)->ZFb)));
}}void Zbd2(Ze9*C){if((ZiH(((C)->Z3c)))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
Zmd2(Z1G(29,"Feature found is a procedure."));}}T6 Znd2(Ze9*C,T0*a1){T6 R=0;R=((T6)(Zfd2(C,a1)));if(R){R=((T6)(!(ZmH(ZnH(Zod2(C))))));
}return R;}void Zpd2(Ze9*C,T0*a1,T0*a2){ZqH(((C)->Z1c),a1,a2);ZrH((Za3*)(((C)->ZFb)),a1,a2);}void Zqd2(Ze9*C){{T81 Zow;Z5G((*(Zow=Zld2(C),&Zow)));
}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Zrd2(Ze9*C,T0*a1,T81
a2,T0*a3){(C->Z1c)=a1;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,(Z1J),a2);(C->Z2c)=((T0*)n);}{Za3*n=((Za3*)Zh(sizeof(*n)));*n=Z3j;((((Za3*)(n)))->Z2j)=(a3);
(C->ZFb)=((T0*)n);}}void Zsd2(Ze9*C,T0*a1){T0*ZxH=Zo;ZxH=ZyH(((C)->Z1c),a1);if((ZxH)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));
}{T0*b1=Z1G(11,"Bad target.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z1c)=ZxH;}void Zmd2(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}void Ztd2(Ze9*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=Zld2(C),&Zow)));}Z3G((T80*)(Z4G));}T2 Zud2(void){
T2 R=0;return R;}void Zvd2(Ze9*C,T3 a1){if((a1)==(((T3)'R'))){{T81 Zow;ZDH(((C)->Z3c),(*(Zow=Zld2(C),&Zow)));}}ZEH(((C)->Z1c),a1);ZEH(((((Za3*)(((C)->ZFb))))->Z2j),a1);
}T0*Zod2(Ze9*C){T0*R=Zo;T0*ZFH=Zo;R=ZiH(((C)->Z3c));ZFH=R;if(Zo!=(ZFH)){switch(((T0*)ZFH)->id){case 280:break;default:ZFH=Zo;}}if((ZFH)!=((void*)(Zo))){
R=ZnH(ZGH(((((Za3*)(((C)->ZFb))))->Z2j)));}return R;}void Zwd2(Ze9*C){T0*ZIH=Zo;T0*ZJH=Zo;T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){ZIH=ZGH(((C)->Z1c));
ZJH=Z_G(ZIH);ZdH=((((ZZ3*)ZJH))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){ZKH(((C)->Z1c),((C)->Z3c));
}}ZLH(((C)->Z1c));ZMH((Za3*)(((C)->ZFb)));}T6 Zxd2(Ze9*C){T6 R=0;R=((T6)(ZOH((Za3*)(((C)->ZFb)))));if(R){}else if(ZXG(((C)->Z1c))){if((ZPH())!=((void*)(((C)->Z3c)))){
R=((T6)(ZQH(((C)->Z3c))));}}else{R=((T6)(ZRH(((C)->Z1c))));}return R;}T0*Zdd2(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);
ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);
ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);
ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);
ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);
ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);
ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);
ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);
ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);
ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);
ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);
ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);
ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);
ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);
ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T6 Zyd2(Ze9*C){T6 R=0;if(Z0L(((C)->Z1c))){
if((((C)->ZFb))!=((void*)(Zo))){R=((T6)(Z1L((Za3*)(((C)->ZFb)))));}else{R=((T6)(1));}}return R;}T6 Zzd2(Ze9*C,T0*a1){T6 R=0;R=((T6)(Z3L(ZGH(((C)->Z1c)))));
R=((T6)((T6)((Z4L(((C)->Z1c),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z5L(((Zz6*)a1),((C)->Z1c))){R=((T6)(1));}}else if((T6)((Z3L(ZGH(((C)->Z1c))))&&((T6)(!(ZXG(((C)->Z1c))))))){
Z6L(((C)->Z1c));}return R;}void ZAd2(Ze9*C,T0*a1){T6 Z8L=0;T0*Z9L=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Z9L=ZnH(Zod2(C));if(ZbL(Z9L)){if(ZbL(a1)){
ZcL(a1);ZdL((Z84*)(ZkH),((T3)'\050'));{Ze9*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Ze9*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);
}}}else{if(ZbL(a1)){{Ze9*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}else{if(ZfL(a1)){ZdL((Z84*)(ZkH),((T3)'\046'));ZdL((Z84*)(ZkH),((T3)'\050'));
{Ze9*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Ze9*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}}if(Z8L){ZgL((Z84*)(ZkH));
}}void ZBd2(Ze9*C,T0*a1){T0*ZiL=Zo;T0*ZJH=Zo;T0*ZjL=Zo;T0*ZkL=Zo;ZjL=ZGH(((C)->Z1c));if((ZjL)!=((void*)(Zo))){ZJH=Z_G(ZjL);if((ZJH)!=((void*)(Zo))){
ZkL=((((ZZ3*)ZJH))->Zvb);ZiL=ZlL(((T87*)ZkL),ZJH,((C)->Z1c),((C)->Z2c),a1);}}if((ZiL)==((void*)(Zo))){Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
{T0*b1=Z1G(25,"Bad target for this call.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z3c)=ZiL;}T0*ZCd2(Ze9*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Ze9*)R)=*C;return R;}T2 ZDd2(Ze9*C){T2 R=0;Ztd2(C);return R;}T0*ZEd2(Ze9*C,T0*a1){T0*R=Zo;T0*ZpL=Zo;T0*ZqL=Zo;T0*ZrL=Zo;if((((C)->Z4c))==((void*)(Zo))){
(C->Z4c)=a1;Zsd2(C,a1);(C->ZFb)=Zgd2(C,a1);ZqL=ZGH(((C)->Z1c));ZpL=ZGH(((((Za3*)(((C)->ZFb))))->Z2j));(C->Z1c)=Zed2(C,((C)->Z1c),ZqL,ZpL);
ZBd2(C,a1);R=Zid2(C);Zad2(C);}else{ZrL=ZCd2(C);Zhd2(((Ze9*)ZrL),((C)->Z1c),((C)->Z2c),((C)->ZFb));R=ZEd2(((Ze9*)ZrL),a1);}return R;}T0*ZFd2(Ze9*C){
T0*R=Zo;T0*ZkL=Zo;T0*ZyL=Zo;T0*ZjL=Zo;ZkL=ZzL(((C)->Z1c));if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),((C)->Z2c));if((ZyL)!=((void*)(Zo))){
ZjL=ZBL(ZyL);if((ZjL)!=((void*)(Zo))){R=ZCL(ZjL);}}}return R;}void ZGd2(Ze9*C){if((((C)->Z3c))!=((void*)(Zo))){ZEL(((C)->Z3c));}ZFL(((C)->Z1c));
if((((C)->ZFb))!=((void*)(Zo))){ZGL((Za3*)(((C)->ZFb)));}}void ZHd2(Ze9*C){T0*ZJH=Zo;T0*ZiL=Zo;ZiL=((C)->Z3c);ZJH=((((ZQ7*)ZiL))->Znf);
(C->Z3c)=ZIL((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[ZGs(0)]),ZiL);}T81 Zld2(Ze9*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((C)->Z2c)))->ZCb);
return R;}void ZRO(Zf2*C,T81 a1,T0*a2,T0*a3,T0*a4){(C->ZCb)=a1;(C->ZZb)=a2;(C->Z4c)=a3;(C->Z3c)=a4;}void ZId2(Zf2*C,T81 a1,T6 a2,T0*a3,T0*a4){
ZJd2(C,a1,a3,a4);(C->ZYl)=((T6)(a2));}void ZKd2(Zf2*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZtE1);
}else{ZgM((Z84*)(ZkH),ZuE1);}}}void ZiM(Zf2*C){T2 Zet=0;T0*ZwE1=Zo;if(!(ZLd2(C))){ZMd2(C);Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb)))))
{ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];if((T6)((!((((T43*)(ZSG))->ZXk)))||((T6)(!(((((Zn6*)ZwE1))->Z_i)))))){ZNd2(ZwE1);}Zet=(Z3)(((Zet))+(ZGs(1)));
}ZKd2(C);}}void ZBO(Zf2*C,T0*a1){T2 Zet=0;T0*ZKO=Zo;if((((C)->ZZb))!=((void*)(Zo))){Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb)))))
{ZKO=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];if(!(Z_z(((Zu1*)a1),ZKO))){Z1A(((Zu1*)a1),ZKO);}Zet=(Z3)(((Zet))+(ZGs(1)));}}}void ZJd2(Zf2*C,T81
a1,T0*a2,T0*a3){(C->ZCb)=a1;(C->ZHb)=a2;(C->ZZb)=a3;}void ZoM(Zf2*C){T2 Zet=0;T0*ZwE1=Zo;T6 ZOd2=0;if(!(ZLd2(C))){Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb)))))
{ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];if(((((Zn6*)ZwE1))->Z_i)){if(!(ZOd2)){ZMd2(C);ZOd2=((T6)(1));}ZNd2(ZwE1);}Zet=(Z3)(((Zet))+(ZGs(1)));
}if(ZOd2){ZKd2(C);}}}void ZMd2(Zf2*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZAE1);
}else{ZgM((Z84*)(ZkH),ZBE1);}}}void ZsM(Zf2*C){T2 Zet=0;if((((C)->ZZb))!=((void*)(Zo))){Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{ZCE1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]));Zet=(Z3)(((Zet))-(ZGs(1)));}}}T6 ZLd2(Zf2*C){T6 R=0;T2 Zet=0;T0*ZwE1=Zo;Zet=(((Zu1*)(((C)->ZZb)))->ZWb);
R=((T6)(1));while(!((T6)((!(R))||((T6)((Z3)((Zet)<(ZGs(0)))))))){ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];R=((T6)(ZDE1(((Zn6*)ZwE1))));
Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T6 ZuM(Zf2*C){T6 R=0;T2 Zet=0;if((((C)->ZZb))!=((void*)(Zo))){Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0))))))))
{R=((T6)(Z2H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]))));Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}void ZzM(Zf2*C,T0*a1){T2 Zet=0;Zet=(((Zu1*)(((C)->ZZb)))->ZWb);
while(!((Z3)((Zet)<(ZGs(0))))){Z3H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]),a1);Zet=(Z3)(((Zet))-(ZGs(1)));}}void ZNd2(T0*a1){T6 Zz61=0;
if(ZDE1(((Zn6*)a1))){}else{ZWE1(((Zn6*)a1));Zz61=((T6)(Zsq1((Z84*)(ZkH))));((((Z84*)((Z84*)(ZkH))))->ZNf)=(ZPd2);ZYE1(((Zn6*)a1));if(Zz61){
ZB61((Z84*)(ZkH));}}}T0*ZQd2(Zi9*C){T0*R=Zo;R=ZGH(((C)->ZEh));return R;}void ZRd2(T0*a1,T0*a2){T0*ZXw=Zo;ZXw=a2;if(Zo!=(ZXw)){switch(((T0*)ZXw)->id){
case 236:case 242:case 243:case 244:case 245:case 246:case 247:case 248:case 249:case 250:case 251:case 252:case 253:case 254:case 257:case
263:case 264:case 267:case 268:case 269:case 338:case 339:case 341:case 342:case 343:case 344:case 345:break;default:ZXw=Zo;}}if((ZXw)!=((void*)(Zo))){
if((T6)(((T6)((Z3L(ZGH(((((Zk3*)ZXw))->Z1c))))&&((T6)(!(ZXG(((((Zk3*)ZXw))->Z1c)))))))&&((T6)(!(Z3L(ZGH(a1))))))){{T81 Zow;Z5G((*(Zow=ZLG(a1),&Zow)));
}{T0*b1=Z1G(124,"Separateness Consistency Rule violated\n(OOSC2 p. 1025): invalid assignment. (See the 2 following messages for more details.)");
Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));{T81 Zow;Z5G((*(Zow=ZZM1(ZXw),&Zow)));}{T0*b1=Z1G(55,"This call is separate (because the target is separate).");
Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));{T81 Zow;Z5G((*(Zow=ZLG(a1),&Zow)));}{T0*b1=Z1G(71,"In this situation, the type of the left-hand-side must be separate too.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}}void ZSd2(Zi9*C){ZgH(((C)->ZFh));}void ZTd2(Zi9*C,T0*a1,T2 a2){(C->ZFh)=ZaH(((C)->ZFh));}T0*ZUd2(Zi9*C){
T0*R=Zo;T0*ZVd2=Zo;T0*ZWd2=Zo;T0*ZXd2=Zo;ZVd2=ZnH(ZQd2(C));ZWd2=ZnH(ZYd2(C));if((T6)((Ze31(((C)->ZFh)))&&((T6)(ZqU(ZVd2))))){{T81 Zow;
Z5G((*(Zow=ZLG(((C)->ZFh)),&Zow)));}{T0*b1=Z1G(66,"Void may not be assigned to an expanded entity. Left hand side is ");Zmx((T7*)(Z2G),b1);
}ZMT(ZQd2(C),Z1G(1,Zon));Z3G((T80*)(Z4G));}ZXd2=ZKG(((C)->ZFh),ZVd2);{T81 Zow;Zy_((*(Zow=ZLG(ZXd2),&Zow)),ZGH(ZXd2),ZVd2);}if((ZXd2)==((void*)(((C)->ZFh)))){
R=((T0*)(C));}else{{Zi9*n=((Zi9*)Zh(sizeof(*n)));*n=Z_l;ZuL1(n,((C)->ZEh),ZXd2);R=((T0*)n);}}return R;}void ZZd2(Zi9*C){T6 Z_d2=0;if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
{T81 Zow;Zl61((Z84*)(ZkH),(*(Zow=Z0e2(C),&Zow)));}}if(ZXG(((C)->ZFh))){if(ZbL(ZQd2(C))){Z_d2=((T6)(ZbL(ZYd2(C))));}}ZD21(((C)->ZEh));
ZdL((Z84*)(ZkH),((T3)'\075'));if(Z_d2){ZgM((Z84*)(ZkH),Z1e2);}else if(ZmU(ZGH(((C)->ZFh)))){ZgM((Z84*)(ZkH),Z2e2);}ZD21(((C)->ZFh));if((T6)((Z_d2)||((T6)(ZmU(ZGH(((C)->ZFh))))))){
ZgM((Z84*)(ZkH),Z3e2);}ZgM((Z84*)(ZkH),ZCQ);}T6 Z4e2(Zi9*C,T0*a1){T6 R=0;if(ZWG(((C)->ZEh),a1)){if(ZWG(((C)->ZFh),a1)){R=((T6)(1));}}
return R;}void ZuL1(Zi9*C,T0*a1,T0*a2){(C->ZEh)=a1;(C->ZFh)=a2;}void Z5e2(Zi9*C){ZLH(((C)->ZFh));}T6 Z6e2(Zi9*C){T6 R=0;R=((T6)(ZRH(((C)->ZEh))));
R=((T6)((T6)((R)||((T6)(ZRH(((C)->ZFh)))))));return R;}T6 Z7e2(Zi9*C){T6 R=0;if(Z0L(((C)->ZEh))){R=((T6)(Z0L(((C)->ZFh))));}return R;
}void Z8e2(Zi9*C,T0*a1){T6 ZxR=0;ZxR=((T6)(Z4L(((C)->ZEh),a1)));ZxR=((T6)(Z4L(((C)->ZFh),a1)));}T0*Z9e2(Zi9*C,T0*a1){T0*R=Zo;{Zp8*n=((Zp8*)Zh(sizeof(*n)));
*n=Z2l;ZzR(n,(T0*)C,a1);R=((T0*)n);}return R;}T0*Zae2(Zi9*C,T0*a1){T0*R=Zo;T0*Z7Q=Zo;T0*ZJN=Zo;T0*Zbe2=Zo;T0*Zce2=Zo;Z7Q=ZyH(((C)->ZEh),a1);
if((Z7Q)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->ZEh)),&Zow)));}{T0*b1=Zbv1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}ZJN=ZyH(((C)->ZFh),a1);
if((ZJN)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->ZFh)),&Zow)));}{T0*b1=Zcv1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zbe2=ZGH(ZJN);
Zce2=ZGH(Z7Q);if(!(ZJG(ZGH(ZJN),ZGH(Z7Q)))){{T81 Zow;Z5G((*(Zow=ZLG(Z7Q),&Zow)));}{T0*b1=Z1G(23," Bad assignment (VJAR).");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}else if(ZbL(ZGH(ZJN))){ZRd2(Z7Q,ZJN);}if((T6)(((Z7Q)==((void*)(((C)->ZEh))))&&((T6)((ZJN)==((void*)(((C)->ZFh))))))){
R=ZUd2(C);}else{{Zi9*n=((Zi9*)Zh(sizeof(*n)));*n=Z_l;ZuL1(n,Z7Q,ZJN);R=((T0*)n);}R=ZUd2(((Zi9*)R));}return R;}void Zde2(Zi9*C){ZFL(((C)->ZFh));
}T0*ZYd2(Zi9*C){T0*R=Zo;R=ZGH(((C)->ZFh));return R;}T81 Z0e2(Zi9*C){T81 R={Zo,Zo,0};{T81 Zow;R=(*(Zow=ZLG(((C)->ZEh)),&Zow));}return R;
}void Zee2(Zm9*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZtE1);}else{ZgM((Z84*)(ZkH),ZuE1);
}}}T0*Zfe2(void){if(ZCm1==0){ZCm1=1;{{Zj6*n=((Zj6*)Zh(sizeof(*n)));*n=ZYi;ZBm1=((T0*)n);}}}return ZBm1;}void Zfa2(Zm9*C){T2 Zet=0;T0*ZwE1=Zo;
if(!(Zge2(C))){Zhe2(C);Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb))))){ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];Zie2(ZwE1);
Zet=(Z3)(((Zet))+(ZGs(1)));}Zee2(C);}}void Zje2(Zm9*C,T81 a1,T0*a2,T0*a3){(C->ZCb)=a1;(C->ZHb)=a2;(C->ZZb)=a3;}void Zhe2(Zm9*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZAE1);}else{ZgM((Z84*)(ZkH),ZBE1);}}}void Zna2(Zm9*C){T2 Zet=0;if((((C)->ZZb))!=((void*)(Zo))){
Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZCE1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]));Zet=(Z3)(((Zet))-(ZGs(1)));
}}}T6 Zge2(Zm9*C){T6 R=0;T2 Zet=0;T0*ZwE1=Zo;Zet=(((Zu1*)(((C)->ZZb)))->ZWb);R=((T6)(1));while(!((T6)((!(R))||((T6)((Z3)((Zet)<(ZGs(0))))))))
{ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];R=((T6)(ZDE1(((Zn6*)ZwE1))));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T6 Zpa2(Zm9*C){T6 R=0;T2 Zet=0;
if((((C)->ZZb))!=((void*)(Zo))){Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0)))))))){R=((T6)(Z2H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]))));
Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}void Zra2(Zm9*C,T0*a1){T2 Zet=0;Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{Z3H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]),a1);Zet=(Z3)(((Zet))-(ZGs(1)));}}T0*Zke2(Zm9*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zm9*)R)=*C;
return R;}T0*Zva2(Zm9*C,T0*a1){T0*R=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;(C->Z3c)=ZPH();if((((C)->ZZb))!=((void*)(Zo))){(C->ZZb)=(((void)((Zj6*)(Zfe2()))),ZrO(((C)->ZZb),a1,((C)->Z3c),((T3)'\137')));
}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){R=((T0*)(C));}}else{R=Zke2(C);((((Zm9*)(((Zm9*)R))))->Z4c)=(Zo);R=Zva2(((Zm9*)R),a1);}return R;
}void Zie2(T0*a1){T6 Zz61=0;if(ZDE1(((Zn6*)a1))){}else{ZWE1(((Zn6*)a1));Zz61=((T6)(Zsq1((Z84*)(ZkH))));((((Z84*)((Z84*)(ZkH))))->ZNf)=(Zle2);
ZYE1(((Zn6*)a1));if(Zz61){ZB61((Z84*)(ZkH));}}}void Zme2(Zq9*C,T0*a1){if(Zne2(C)){if(Zoe2(C)){ZwW((ZZ3*)(Zpe2(C)),a1);}else{Zgt(((T7*)a1),((T3)'0'));
}}else{Zmx(((T7*)a1),Z4T);}}void Zqe2(Zq9*C,T0*a1){Zmx(((T7*)a1),ZER);Z6t(Zre2(C),a1);}void Zse2(Zq9*C,T0*a1){if(Zte2(C)){Zmx(((T7*)a1),ZHR);
Zgt(((T7*)a1),((T3)'\052'));}else{Zue2(C,a1);}}T0*Zve2(void){if(Z7P==0){Z7P=1;{T81 Z9P={Zo,Zo,0};{Z83*n=((Z83*)Zh(sizeof(*n)));*n=Zge;
Z6P=((T0*)n);ZaP(n,Z9P);}}}return Z6P;}T0*Zwe2(Zq9*C){T0*R=Zo;T2 Zet=0;T0*ZCs1=Zo;R=((C)->Zcd);if((R)==((void*)(Zo))){ZCs1=((C)->ZFj);
Zet=((((ZY*)ZCs1))->ZWb);while(!((Z3)((Zet)<(ZGs(1))))){if((ZcT(Z1y(((ZY*)ZCs1),Zet)))==((void*)(Zo))){}Zet=(Z3)(((Zet))-(ZGs(1)));}R=Zxe2;
ZWw(((T7*)R),(((T85*)(((C)->Zfe)))->Zse));Zgt(((T7*)R),((T3)'\133'));Zet=ZGs(1);while(!((Z3)((Zet)>(((((ZY*)ZCs1))->ZWb))))){Zmx(((T7*)R),ZcT(Z1y(((ZY*)ZCs1),Zet)));
Zet=(Z3)(((Zet))+(ZGs(1)));if((Z3)((Zet)<=(((((ZY*)ZCs1))->ZWb)))){Zgt(((T7*)R),((T3)'\054'));}}Zgt(((T7*)R),((T3)'\135'));R=(((void)((T27*)(Zye2()))),ZCG(R));
(C->Zcd)=R;}return R;}T0*Zze2(Zq9*C){T0*R=Zo;if((((C)->ZVc))!=(Zo)){R=Zwe2((Zq9*)(((C)->ZVc)));if((Z3)((((((T7*)R))->Zdc))>(Zxt(512)))){
{T81 Zow;Z5G((*(Zow=ZAe2(C),&Zow)));}{T0*b1=Z1G(137,"Probably infinite or too long generic derivation of this type mark (see next warnings to find the cause of the problem... and good luck).");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));{T0*b1=Z1G(64,"The huge generic derivation related to the previous warning is: ");Zmx((T7*)(Z2G),b1);
}{T0*b1=R;Zmx((T7*)(Z2G),b1);}if((Z3)(((((T80*)(Z4G))->ZFg))>(ZGs(50)))){Z3G((T80*)(Z4G));}else{ZPG((T80*)(Z4G));}}}return R;}void ZBe2(Zq9*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5,T0*a6){
(C->ZQc)=a1;(C->ZRc)=a2;(C->Zfe)=a3;(C->ZFj)=a4;(C->Zcd)=a5;(C->ZVc)=a6;}T2 ZCe2(Zq9*C){T2 R=0;if(Zte2(C)){R=ZDe2();}else{R=Znr1((ZZ3*)(Zpe2(C)));
}return R;}void ZEe2(Zq9*C,T0*a1){Zmx(((T7*)a1),ZRR);Z6t(Zre2(C),a1);}void Zue2(Zq9*C,T0*a1){if(Zte2(C)){Zmx(((T7*)a1),ZtI1);}else if(ZFe2(C)){
Zmx(((T7*)a1),Z5T);}else{Zgt(((T7*)a1),((T3)'T'));Z6t(Zre2(C),a1);}}T6 ZGe2(void){T6 R=0;return R;}void ZHe2(Zq9*C){T0*ZJH=Zo;T2 ZVR=0;
T6 ZWR=0;ZJH=Zpe2(C);ZVR=((((ZZ3*)ZJH))->_id);ZWw((T7*)(ZYR),ZHR);Zgt((T7*)(ZYR),((T3)'\040'));Zmx((T7*)(ZYR),ZZR);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z_R);
ZWw((T7*)(ZKR),Z0S);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),Z1S);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),Z2S);Zqe2(C,ZKR);Zmx((T7*)(ZKR),Z3S);(((void)((Zj8*)(ZIe2()))),Z5S(ZKR,Z6S,Zpe2(C)));
Zmx((T7*)(ZKR),Z7S);ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZCQ);ZJe2(C,ZKR);Zmx((T7*)(ZKR),Z9S);(((void)((Zj8*)(ZIe2()))),Z5S(ZKR,ZaS,Zpe2(C)));Zmx((T7*)(ZKR),ZbS);
ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZCQ);ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZcS);ZdS((Z84*)(ZkH),ZYR,ZKR);ZWw((T7*)(ZYR),ZHR);Zgt((T7*)(ZYR),((T3)'\040'));
ZKe2(C,ZYR);Zmx((T7*)(ZYR),ZfS);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZgS);((((T7*)((T7*)(ZKR))))->Zdc)=(ZGs(0));ZWR=((T6)((T6)((ZhS(((ZZ3*)ZJH)))&&((T6)((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2))))))));
if(ZWR){Zmx((T7*)(ZKR),ZiS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZjS);}ZkS(((ZZ3*)ZJH),(T6)(0),ZKR);if(ZWR){Zmx((T7*)(ZKR),ZlS);}ZdS((Z84*)(ZkH),ZYR,ZKR);
ZWw((T7*)(ZYR),ZHR);Zgt((T7*)(ZYR),((T3)'\040'));ZLe2(C,ZYR);Zmx((T7*)(ZYR),ZnS);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZoS);((((T7*)((T7*)(ZKR))))->Zdc)=(ZGs(0));
ZpS(((ZZ3*)ZJH),ZKR);ZdS((Z84*)(ZkH),ZYR,ZKR);ZWw((T7*)(ZYR),ZqS);Z6t(ZVR,ZYR);ZWw((T7*)(ZKR),ZrS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZsS);Z6t(ZVR,ZKR);
Zmx((T7*)(ZKR),ZtS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZuS);ZvS((Z84*)(ZkH),ZYR,ZKR);((((T7*)((T7*)(ZYR))))->Zdc)=(ZGs(0));Zgt((T7*)(ZYR),((T3)'T'));
Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\052'));Zmx((T7*)(ZYR),ZwS);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZxS);ZWw((T7*)(ZKR),ZyS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZzS);
if((((Zj8*)(ZIe2()))->ZMk)){ZMe2(C,ZKR);Zmx((T7*)(ZKR),ZBS);}Zmx((T7*)(ZKR),ZCS);ZNe2(C,ZKR);Zmx((T7*)(ZKR),ZES);ZNe2(C,ZKR);Zmx((T7*)(ZKR),ZFS);
Zqe2(C,ZKR);Zmx((T7*)(ZKR),ZGS);ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZHS);ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZCQ);ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZIS);ZNe2(C,ZKR);
Zmx((T7*)(ZKR),ZJS);ZNe2(C,ZKR);Zmx((T7*)(ZKR),ZKS);ZEe2(C,ZKR);Zmx((T7*)(ZKR),ZLS);Zqe2(C,ZKR);Zmx((T7*)(ZKR),ZMS);ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZNS);
ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZCQ);ZJe2(C,ZKR);Zmx((T7*)(ZKR),ZOS);ZEe2(C,ZKR);Zmx((T7*)(ZKR),ZPS);ZEe2(C,ZKR);Zmx((T7*)(ZKR),ZQS);Z6t(ZVR,ZKR);
Zmx((T7*)(ZKR),ZCQ);Zqe2(C,ZKR);Zmx((T7*)(ZKR),ZRS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZSS);ZEe2(C,ZKR);Zmx((T7*)(ZKR),ZTS);ZNe2(C,ZKR);Zmx((T7*)(ZKR),ZQS);
Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZUS);Zqe2(C,ZKR);Zmx((T7*)(ZKR),ZVS);if(Zoe2(C)){Zmx((T7*)(ZKR),ZWS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZCQ);}Zmx((T7*)(ZKR),ZXS);
Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZYS);ZdS((Z84*)(ZkH),ZYR,ZKR);}void ZOe2(Zq9*C){T0*ZJH=Zo;T2 ZVR=0;ZJH=Zpe2(C);ZVR=((((ZZ3*)ZJH))->_id);ZWw((T7*)(ZYR),Z_S);
Zmx((T7*)(ZYR),Z0T);Zgt((T7*)(ZYR),((T3)'\040'));Zgt((T7*)(ZYR),((T3)'B'));Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\040'));Zmx((T7*)(ZYR),ZyS);
Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZCQ);Zmx((T7*)(ZYR),Z0T);Zgt((T7*)(ZYR),((T3)'\040'));Zgt((T7*)(ZYR),((T3)'B'));Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z1T);
Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z2T);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z3T);ZgM((Z84*)(ZkH),ZYR);ZWw((T7*)(ZYR),ZyS);Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\052'));
Zqe2(C,ZYR);ZvS((Z84*)(ZkH),ZYR,Z4T);ZWw((T7*)(ZYR),Z5T);Zgt((T7*)(ZYR),((T3)'\040'));ZNe2(C,ZYR);Z6T((Z84*)(ZkH),ZYR,((T3)'0'));ZWw((T7*)(ZYR),Z7T);
ZEe2(C,ZYR);ZvS((Z84*)(ZkH),ZYR,Z4T);ZWw((T7*)(ZYR),ZyS);Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\052'));ZJe2(C,ZYR);ZvS((Z84*)(ZkH),ZYR,Z4T);
if((((Zj8*)(ZIe2()))->ZMk)){ZWw((T7*)(ZYR),Z5T);Zgt((T7*)(ZYR),((T3)'\040'));ZMe2(C,ZYR);Z6T((Z84*)(ZkH),ZYR,((T3)'0'));}}T6 ZPe2(Zq9*C){
T6 R=0;T0*Z9T=Zo;Z9T=Zo;R=((T6)((Z9T)!=((void*)(Zo))));return R;}void ZKe2(Zq9*C,T0*a1){Zmx(((T7*)a1),ZaT);Z6t(Zre2(C),a1);}T6 ZQe2(Zq9*C){
T6 R=0;T0*ZjL=Zo;if((((C)->ZVc))!=(Zo)){ZjL=((C)->ZVc);if((C)==((void*)(ZjL))){if((((((Zq9*)ZjL))->ZVc))==((void*)(ZjL))){R=((T6)((Zwe2(((Zq9*)ZjL)))==((void*)(Zze2(((Zq9*)ZjL))))));
}}}return R;}void ZRe2(Zq9*C){T0*ZJH=Zo;T2 ZVR=0;ZJH=Zpe2(C);if(ZQt1(((ZZ3*)ZJH))){ZVR=((((ZZ3*)ZJH))->_id);ZWw((T7*)(ZYR),ZHR);Zgt((T7*)(ZYR),((T3)'\040'));
ZKe2(C,ZYR);Zmx((T7*)(ZYR),Zgw1);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Zhw1);((((T7*)((T7*)(ZKR))))->Zdc)=(ZGs(0));ZkS(((ZZ3*)ZJH),(T6)(1),ZKR);
ZdS((Z84*)(ZkH),ZYR,ZKR);}}void ZSe2(Zq9*C,T0*a1){if(Zte2(C)){ZTe2(C,a1);}}T2 Zre2(Zq9*C){T2 R=0;R=(((ZZ3*)(Zpe2(C)))->_id);return R;
}T2 ZDe2(void){T2 R=0;T8 Z4W=Zo;R=sizeof(T8);return R;}void ZUe2(Zq9*C){((((T7*)((T7*)(ZgT))))->Zdc)=(ZGs(0));Zgt((T7*)(ZgT),((T3)'\050'));
ZVe2(C,ZgT);Zgt((T7*)(ZgT),((T3)'\051'));ZgM((Z84*)(ZkH),ZgT);}void ZWe2(Zq9*C,T0*a1){Zmx(((T7*)a1),ZjT);ZMe2(C,a1);Zmx(((T7*)a1),ZkT);
Zmx(((T7*)a1),Zze2(C));Zmx(((T7*)a1),ZlT);ZMe2(C,a1);Zgt(((T7*)a1),((T3)'\054'));ZNe2(C,a1);Zmx(((T7*)a1),ZmT);}void ZXe2(Zq9*C){if(Zne2((Zq9*)(((C)->ZVc)))){
ZYe2(C);}else{ZgM((Z84*)(ZkH),Z4T);}}void ZZe2(Zq9*C){T2 ZuT=0;ZuT=Zre2(C);((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));if(Zoe2(C)){Zmx((T7*)(ZvT),Z_S);
Zmx((T7*)(ZvT),Z0T);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'S'));Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'T'));
Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZCQ);}else if(ZFe2(C)){Zmx((T7*)(ZvT),Z_S);Zmx((T7*)(ZvT),Z5T);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'T'));
Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZCQ);}else if(Zte2(C)){Zmx((T7*)(ZvT),Z_S);Zmx((T7*)(ZvT),ZHR);Zgt((T7*)(ZvT),((T3)'\052'));Zgt((T7*)(ZvT),((T3)'T'));
Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZCQ);}ZgM((Z84*)(ZkH),ZvT);}T6 Z_e2(Zq9*C){T6 R=0;if(Zte2(C)){R=((T6)(1));}else{R=((T6)(ZQt1((ZZ3*)(Zpe2(C)))));
}return R;}void Z0f2(T0*a1,T0*a2){T2 Zet=0;T0*Zh31=Zo;T0*Zi31=Zo;Zet=((((ZY*)a2))->ZWb);while(!((Zet)==(ZGs(0)))){Zh31=Z1y(((ZY*)a2),Zet);
Zi31=ZxP(Zh31,a1);if(ZqU(Zi31)){ZCP((ZZ3*)(Z_G(Zi31)));}Zet=(Z3)(((Zet))-(ZGs(1)));}}void Z1f2(Zq9*C,T0*a1){if(Zte2(C)){Zmx(((T7*)a1),ZtI1);
}else if(ZFe2(C)){Zmx(((T7*)a1),Z5T);}else{Zgt(((T7*)a1),((T3)'T'));Z6t(Zre2(C),a1);}}T6 Z2f2(Zq9*C,T0*a1){T6 R=0;T2 Zet=0;Zet=(((ZY*)(((C)->ZFj)))->ZWb);
R=((T6)(1));while(!((T6)((!(R))||((T6)((Zet)==(ZGs(0))))))){R=((T6)(ZxT(Z1y((ZY*)(((C)->ZFj)),Zet),a1)));Zet=(Z3)(((Zet))-(ZGs(1)));}
return R;}void Z3f2(Zq9*C){T0*ZkL=Zo;T0*Z4f2=Zo;ZkL=Z5f2(C);Z4f2=((((T87*)ZkL))->Zig);if((Z4f2)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZAe2(C),&Zow)));
}{T0*b1=(((T85*)(((((T87*)ZkL))->Zpc)))->Zse);Zmx((T7*)(Z2G),b1);}Z6f2(Z1G(24," is not a generic class."));}else if((ZWx(((ZB*)(((((Zha*)Z4f2))->ZZb)))))!=(Z0y((ZY*)(((C)->ZFj))))){
{T81 Zow;Z5G((*(Zow=ZAe2(C),&Zow)));}Z5G(((((Zha*)Z4f2))->ZCb));Z6f2(Zh72);}}void ZzZ(Zq9*C,T0*a1,T0*a2){T2 Zet=0;T0*ZxH=Zo;(C->Zfe)=a1;
(C->ZFj)=a2;(C->ZGj)=((T6)(1));Zet=(((ZY*)(((C)->ZFj)))->ZWb);while(!((T6)((!(((C)->ZGj)))||((T6)((Zet)==(ZGs(0))))))){ZxH=Z1y(((ZY*)a2),Zet);
if(ZyW(ZxH)){if((ZnH(ZxH))!=((void*)(ZxH))){(C->ZGj)=((T6)(0));}}else{(C->ZGj)=((T6)(0));}Zet=(Z3)(((Zet))-(ZGs(1)));}if(((C)->ZGj)){
(C->ZVc)=((T0*)(C));}}void Z6f2(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}T0*ZIe2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));
*n=ZOk;ZMM=((T0*)n);}}}return ZMM;}T6 Zne2(Zq9*C){T6 R=0;R=((T6)((((T87*)(Z5f2(C)))->Zfg)));return R;}void Z7f2(Zq9*C,T0*a1){if(Zte2(C)){
ZWe2(C,a1);}}T0*Zye2(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);
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
ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T0*Z8f2(Zq9*C,T81 a1){T0*R=Zo;if(Zte2(C)){{Zz4*n=((Zz4*)Zh(sizeof(*n)));*n=ZAg;((((Zz4*)(n)))->ZCb)=(a1);
R=((T0*)n);}}return R;}T0*Z5f2(Zq9*C){T0*R=Zo;T0*ZKT=Zo;if((((C)->ZQc))!=((void*)(Zo))){R=((C)->ZQc);}else{ZKT=((C)->Zfe);if((ZKT)!=((void*)(Zo))){
(C->ZQc)=ZLT(((T85*)ZKT));R=((C)->ZQc);}else{{T0*b1=Z1G(27,"Cannot find Base Class for ");Zmx((T7*)(Z2G),b1);}ZMT((T0*)C,Z0O);ZaG((T80*)(Z4G));
}}return R;}T6 ZFe2(Zq9*C){T6 R=0;if(Z9f2(C)){R=((T6)((Z3U((ZZ3*)(Zpe2(C))))==((void*)(Zo))));}return R;}void Zaf2(Zq9*C,T0*a1){Zgt(((T7*)a1),((T3)'\045'));
if(Zte2(C)){Zgt(((T7*)a1),((T3)'R'));}else{Zgt(((T7*)a1),((T3)'E'));}Z6t(Zre2(C),a1);Zgt(((T7*)a1),((T3)'\045'));}void Zbf2(Zq9*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
ZQT((ZZ3*)(Zpe2(C)));}}T6 Zte2(Zq9*C){T6 R=0;R=((T6)(!((((T87*)(Z5f2(C)))->Zfg))));return R;}T6 Zoe2(Zq9*C){T6 R=0;if(ZFe2(C)){}else if(Zne2(C)){
R=((T6)(1));}else if(ZhS((ZZ3*)(Zpe2(C)))){R=((T6)(1));}else{R=((T6)((Z3U((ZZ3*)(Zpe2(C))))!=((void*)(Zo))));}return R;}T6 Zcf2(Zq9*C){
T6 R=0;T0*ZST=Zo;ZST=Zo;R=((T6)((ZST)!=((void*)(Zo))));return R;}void Zdf2(Zq9*C){if(Zte2(C)){ZOe2(C);}}void Zef2(Zq9*C){if(Zte2(C)){
ZHe2(C);}else{ZRe2(C);}}void ZVe2(Zq9*C,T0*a1){if(ZFe2(C)){Zmx(((T7*)a1),Z5T);}else{Zgt(((T7*)a1),((T3)'T'));Z6t(Zre2(C),a1);Zgt(((T7*)a1),((T3)'\052'));
}}T0*Zff2(Zq9*C,T0*a1){T0*R=Zo;T81 ZjG={Zo,Zo,0};{T81 Zow;ZjG=(*(Zow=ZAe2(C),&Zow));}if((((ZjG).Zxb))==(ZGs(0))){if((a1)!=((void*)(Zo))){
{T81 Zow;ZjG=(*(Zow=ZrP(a1),&Zow));}}}{ZK1*n=((ZK1*)Zh(sizeof(*n)));*n=Zed;ZcW(n,ZjG,((C)->ZVc));R=((T0*)n);}return R;}void ZJe2(Zq9*C,T0*a1){
Zmx(((T7*)a1),ZUT);Z6t(Zre2(C),a1);}void ZLe2(Zq9*C,T0*a1){Zmx(((T7*)a1),Z_T);Z6t(Zre2(C),a1);}void ZYe2(Zq9*C){T0*Z2U=Zo;T2 Zet=0;T0*ZiL=Zo;
if(ZFe2(C)){ZdL((Z84*)(ZkH),((T3)'0'));}else{ZdL((Z84*)(ZkH),((T3)'\173'));Z2U=Z3U((ZZ3*)(Zpe2(C)));Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0))))
{ZiL=ZUy(((ZV8*)Z2U),Zet);Zr01(((((ZE7*)ZiL))->Zlc));Zet=(Z3)(((Zet))-(ZGs(1)));if((Z3)((Zet)>(ZGs(0)))){ZdL((Z84*)(ZkH),((T3)'\054'));
}}ZdL((Z84*)(ZkH),((T3)'\175'));}}void Zgf2(Zq9*C){T0*Z2U=Zo;T2 Zet=0;T2 ZuT=0;T0*ZKO=Zo;T0*ZxH=Zo;ZuT=Zre2(C);Z2U=Z3U((ZZ3*)(Zpe2(C)));
ZWw((T7*)(ZvT),Z0T);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'S'));Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\173'));if(Zte2(C)){if(ZhS((ZZ3*)(Zpe2(C)))){
Zmx((T7*)(ZvT),ZlW);}}if(Zhf2(C)){Zmx((T7*)(ZvT),ZwK1);}if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){ZKO=ZUy(((ZV8*)Z2U),Zet);
ZxH=ZnH(((((ZE7*)ZKO))->Zlc));ZmW(ZxH,ZvT);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'\137'));Zmx((T7*)(ZvT),(((ZD8*)(((((ZE7*)ZKO))->Zpc)))->Zse));
Zgt((T7*)(ZvT),((T3)'\073'));Zet=(Z3)(((Zet))-(ZGs(1)));}}Zgt((T7*)(ZvT),((T3)'\175'));Zmx((T7*)(ZvT),ZCQ);ZgM((Z84*)(ZkH),ZvT);if(Zne2(C)){
ZWw((T7*)(ZvT),Z5T);Zgt((T7*)(ZvT),((T3)'\040'));Zmx((T7*)(ZvT),ZL31);Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZLw1);Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZMw1);
Z6t(ZuT,ZvT);Zmx((T7*)(ZvT),ZNw1);ZdS((Z84*)(ZkH),ZvT,ZOw1);}}void Zif2(Zq9*C,T0*a1){ZdU(a1,ZeU);if(Zte2(C)){ZdU(a1,ZfU);}else{ZdU(a1,ZV01);
}ZgU(a1,((T3)'\n'));}T6 Z9f2(Zq9*C){T6 R=0;R=((T6)((((T87*)(Z5f2(C)))->Zfg)));return R;}T6 Zjf2(Zq9*C,T0*a1){T6 R=0;T2 Zet=0;T0*Zh31=Zo;
T0*Zi31=Zo;T0*ZW71=Zo;T0*ZX71=Zo;if(Z3L(a1)){R=((T6)((Z5f2(C))==((void*)(ZsO(a1)))));}if((T6)((Zhf2(C))&&((T6)(!(Z3L(a1)))))){{T81 Zow;
Z5G((*(Zow=ZAe2(C),&Zow)));}{T81 Zow;Z5G((*(Zow=ZrP(a1),&Zow)));}Z6f2(ZDK1);}else if(!(R)){if(ZsT(a1)){}else if((Zpe2(C))==((void*)(Z_G(a1)))){
R=((T6)(1));}else if(Z9U(a1)){if((Z5f2(C))==((void*)(ZsO(a1)))){R=((T6)(1));ZW71=(((Zq9*)(((C)->ZVc)))->ZFj);ZX71=ZJR(ZnH(a1));Zet=((((ZY*)ZW71))->ZWb);
while(!((T6)((!(R))||((T6)((Zet)==(ZGs(0))))))){Zh31=ZnH(Z1y(((ZY*)ZW71),Zet));Zi31=ZnH(Z1y(((ZY*)ZX71),Zet));if(ZJG(Zh31,Zi31)){Zet=(Z3)(((Zet))-(ZGs(1)));
}else{R=((T6)(0));{T0*b1=ZWO1;Zmx((T7*)(Z2G),b1);}{T3 b1=((T3)'\040');Zgt((T7*)(Z2G),b1);}}}}else if(ZxM((T87*)(Z5f2(C)),ZsO(a1))){R=((T6)(ZRm1((T87*)(Z5f2(C)),(T0*)C,a1)));
}}else{if(ZxM((T87*)(Z5f2(C)),ZsO(a1))){R=((T6)(1));}}}if(!(R)){ZiU((T0*)C,a1);}return R;}T0*Zkf2(Zq9*C){T0*R=Zo;{T81 Zow;if(!(((((*(Zow=ZAe2(C),&Zow))).Zxb))==(ZGs(0)))){
{T81 ZH81;R=ZkU(&((*(ZH81=ZAe2(C),&ZH81))));}}}return R;}T0*Zlf2(Zq9*C,T0*a1){T0*R=Zo;T2 Zet=0;T0*Zbg1=Zo;T0*Zh31=Zo;T0*Zi31=Zo;T6 Zcg1=0;
if(((C)->ZGj)){Z0f2(a1,((C)->ZFj));Z3f2(C);R=((T0*)(C));}else{if((((C)->ZVc))==((void*)(Zo))){Zbg1=Z6y((ZY*)(((C)->ZFj)));Zcg1=((T6)(1));
}else{Zbg1=(((Zq9*)(((C)->ZVc)))->ZFj);}Zet=((((ZY*)Zbg1))->ZWb);while(!((Zet)==(ZGs(0)))){Zh31=Z1y((ZY*)(((C)->ZFj)),Zet);Zi31=ZxP(Zh31,a1);
if((T6)(((Zi31)==((void*)(Zo)))||((T6)(!(ZyW(Zi31)))))){ZMT(Zh31,Zdg1);Z3G((T80*)(Z4G));Zet=ZGs(0);}else{Zi31=ZnH(Zi31);if(Zcg1){{ZY*C1=((ZY*)Zbg1);
T0*b1=Zi31;T2 b2=Zet;(((C1)->ZUb))[(Z3)(((b2))-(((C1)->ZXb)))]=(b1);}}else if((T6)(((Zi31)==((void*)(Z1y(((ZY*)Zbg1),Zet))))||((T6)((Z9G(Zi31))==((void*)(Z9G(Z1y(((ZY*)Zbg1),Zet)))))))){
}else{Zbg1=Z6y(((ZY*)Zbg1));Zcg1=((T6)(1));{ZY*C1=((ZY*)Zbg1);T0*b1=Zi31;T2 b2=Zet;(((C1)->ZUb))[(Z3)(((b2))-(((C1)->ZXb)))]=(b1);}}if(ZqU(Zi31)){
ZCP((ZZ3*)(Z_G(Zi31)));}Zet=(Z3)(((Zet))-(ZGs(1)));}}if(Zcg1){if((((C)->ZVc))==((void*)(Zo))){{Zq9*n=((Zq9*)Zh(sizeof(*n)));*n=Z3m;ZzZ(n,((C)->Zfe),Zbg1);
(C->ZVc)=((T0*)n);}Z3f2((Zq9*)(((C)->ZVc)));R=((T0*)(C));}else{{Zq9*n=((Zq9*)Zh(sizeof(*n)));*n=Z3m;ZzZ(n,((C)->Zfe),Zbg1);R=((T0*)n);
}Z3f2(((Zq9*)R));{Zq9*n=((Zq9*)Zh(sizeof(*n)));*n=Z3m;ZBe2(n,((C)->ZQc),Zpe2(((Zq9*)R)),((C)->Zfe),((C)->ZFj),((C)->Zcd),R);R=((T0*)n);
}}}else{R=((T0*)(C));}}return R;}void Zmf2(Zq9*C){T2 ZuT=0;T0*ZJH=Zo;ZJH=Zpe2(C);ZuT=((((ZZ3*)ZJH))->_id);((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));
Zgt((T7*)(ZvT),((T3)'T'));Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'M'));Z6t(ZuT,ZvT);ZWT((Z84*)(ZkH),ZvT);ZXT((Z84*)(ZkH));
((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));ZwW(((ZZ3*)ZJH),ZvT);Zmx((T7*)(ZvT),ZCQ);ZgM((Z84*)(ZkH),ZvT);ZZT((Z84*)(ZkH));}T0*Znf2(Zq9*C){
T0*R=Zo;T0*ZuU=Zo;ZuU=((C)->Zfe);if((ZuU)!=((void*)(Zo))){R=ZLT(((T85*)ZuU));}return R;}void ZNe2(Zq9*C,T0*a1){Zmx(((T7*)a1),ZxU);Z6t(Zre2(C),a1);
}T0*Zpe2(Zq9*C){T0*R=Zo;if((((C)->ZRc))!=((void*)(Zo))){R=((C)->ZRc);}else if((((C)->ZVc))!=(Zo)){(C->ZRc)=ZyU(((C)->ZVc));R=((C)->ZRc);
}return R;}void Zof2(Zq9*C){if(Zne2(C)){if(Zoe2(C)){Zgf2(C);}Zmf2(C);}}void Zpf2(Zq9*C){if(Zte2(C)){if(Zoe2(C)){Zgf2(C);Zmf2(C);}}Zbf2(C);
}T81 ZAe2(Zq9*C){T81 R={Zo,Zo,0};R=(((T85*)(((C)->Zfe)))->ZCb);return R;}void ZTe2(Zq9*C,T0*a1){ZJe2(C,a1);Zgt(((T7*)a1),((T3)'\075'));
Zmx(((T7*)a1),Z4T);Zmx(((T7*)a1),ZCQ);}T0*Zqf2(Zq9*C,T0*a1){T0*R=Zo;T0*Zvg1=Zo;Zvg1=ZnH(a1);if(ZsT(a1)){R=((T0*)(C));}else if(ZOR(Zvg1)){
R=Zvg1;}else if(ZJG(Zvg1,((C)->ZVc))){R=((C)->ZVc);}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
if(Zjf2((Zq9*)(((C)->ZVc)),Zvg1)){R=Zvg1;}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));if(Z9U(Zvg1)){
R=Zve2();}else{R=ZDU(Zvg1,(T0*)C);}}}return R;}T6 Zhf2(Zq9*C){T6 R=0;R=((T6)((((T87*)(Z5f2(C)))->Zgg)));return R;}void ZMe2(Zq9*C,T0*a1){
Zmx(((T7*)a1),ZEU);Z6t(Zre2(C),a1);}void Zrf2(Zq9*C,T0*a1){Zmx(((T7*)a1),ZwS);Z6t(Zre2(C),a1);Zgt(((T7*)a1),((T3)'\050'));Zgt(((T7*)a1),((T3)'\051'));
}T0*Zsf2(Zs9*C,T0*a1,T0*a2){T0*R=Zo;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Zbl;ZEP1(n,a1,((C)->ZFb),((C)->Zlc),((C)->ZJb),((C)->ZFe),a2);R=((T0*)n);
}return R;}void Ztf2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T6 Zuf2(Zs9*C,T0*a1,T0*a2){T6 R=0;if((((C)->Zlc))!=((void*)(ZBL(a1)))){
if((T6)(((((C)->Zlc))==((void*)(Zo)))||((T6)((ZBL(a1))==((void*)(Zo)))))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Ztf2((*(Zow=Z6Z1(C),&Zow)),ZWN);
}}}if((((C)->ZFb))!=((void*)(ZXN(a1)))){if((T6)(((((C)->ZFb))==((void*)(Zo)))||((T6)((ZXN(a1))==((void*)(Zo)))))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));
}{T81 Zow;Ztf2((*(Zow=Z6Z1(C),&Zow)),ZYN);}}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Ztf2((*(Zow=Z6Z1(C),&Zow)),ZTc1);}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){if((((C)->Zlc))!=((void*)(Zo))){
if(!(ZZN(ZBL(a1),((C)->Zlc),a2,(T6)(0)))){{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;
Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){if((((C)->ZFb))!=((void*)(Zo))){if(!(ZQa1((Zz6*)(((C)->ZFb)),ZXN(a1),a2))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Z5G((*(Zow=Z6Z1(C),&Zow)));}{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));
Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}}}R=((T6)(((((T80*)(Z4G))->ZEg))==(ZGs(0))));if(R){Zvf2(C,a1);}return
R;}void Zvf2(Zs9*C,T0*a1){if((((T43*)(ZSG))->ZRk)){if((((C)->ZHb))==((void*)(Zo))){(C->ZHb)=Z2O(a1);}else if((Z2O(a1))==((void*)(Zo))){
Z3O(a1,((C)->ZHb));}}}void Zwf2(Zs9*C,T0*a1){T2 Zet=0;T0*Z5O=Zo;T0*Z6O=Zo;(C->Zvb)=(((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),ZGs(1))))->ZCb)).Zvb);
Zet=ZGs(1);while(!((Z3)((Zet)>(Z8O((Zz8*)(((C)->Zkc))))))){Z5O=Z7O((Zz8*)(((C)->Zkc)),Zet);Z6O=Z3D(((Zp6*)a1),Z5O);if((Z6O)!=((void*)(Zo))){
Z5O=((((Zz8*)(((((ZX4*)Z6O))->Zkc))))->ZGd);Z5G(((((ZD8*)Z5O))->ZCb));Z5G((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),Zet)))->ZCb));{T0*b1=Z1G(29,"Double definition of feature ");
Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)Z5O))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}else{Z0D(((Zp6*)a1),(T0*)C,Z5O);
}Zet=(Z3)(((Zet))+(ZGs(1)));}}void Zxf2(Zs9*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5,T0*a6,T0*a7){Zyf2(C,a1,a2,a3,a4,a5);(C->ZKb)=a6;(C->ZLb)=a7;
(C->Zbh)=ZGs(34);}void Zyf2(Zs9*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){((((Zs9*)(C)))->Zkc)=(a1);(C->ZHb)=a4;(C->ZFb)=a2;(C->ZIb)=a3;(C->ZJb)=a5;
}T0*Zzf2(Zs9*C,T0*a1,T0*a2){T0*R=Zo;T0*ZaO=Zo;Z5G(((((ZD8*)a1))->ZCb));ZaO=ZbO((Zz8*)(((C)->Zkc)),((((ZD8*)a1))->Zcn));if((ZaO)!=((void*)(Zo))){
ZcO(((ZD8*)ZaO),a2);}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=Zsf2(C,a1,a2);if((R)!=((void*)(Zo))){
((((ZE3*)(((ZE3*)R))))->Zjc)=(((C)->Zjc));Zvf2(C,R);}else{ZTN(((T87*)a2),a1);}return R;}void ZAf2(Zs9*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5,T0*a6,T0*a7,T0*a8){
Zxf2(C,a1,a2,a4,a5,a6,a7,a8);(C->Zlc)=a3;}void ZBf2(Zs9*C,T81 a1){if((((C)->ZIb))!=((void*)(Zo))){if(!((((T43*)(ZSG))->ZRk))){Z5G(a1);
{T0*b1=Z1G(27,"This feature is obsolete :\n");Zmx((T7*)(Z2G),b1);}{T0*b1=(((T93*)(((C)->ZIb)))->Zse);Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=Z6Z1(C),&Zow)));
}ZPG((T80*)(Z4G));}}}T0*ZCf2(Zs9*C,T0*a1,T0*a2){T0*R=Zo;{ZI7*n=((ZI7*)Zh(sizeof(*n)));*n=Zhk;ZBY1(n,a1,a2,(T0*)C);R=((T0*)n);}return R;
}void ZDf2(Zs9*C,T0*a1){if((T6)(((a1)!=((void*)(Zo)))&&((T6)((Z3)((ZZy(((T79*)(((((T91*)a1))->ZZb)))))>(ZGs(1))))))){(C->ZGe)=a1;}}T6
ZEf2(Zs9*C,T0*a1){T6 R=0;if((((C)->Zlc))==((void*)(Zo))){R=((T6)((ZBL(a1))!=((void*)(Zo))));}else{R=((T6)((ZBL(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZWN;Zmx((T7*)(Z2G),b1);}}else{if((((C)->ZFb))==((void*)(Zo))){R=((T6)((ZXN(a1))!=((void*)(Zo))));}else{R=((T6)((ZXN(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZYN;Zmx((T7*)(Z2G),b1);}}else if((((C)->ZFb))==((void*)(Zo))){}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){
{T0*b1=ZTc1;Zmx((T7*)(Z2G),b1);}R=((T6)(1));}}Zvf2(C,a1);return R;}T81 Z6Z1(Zs9*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->ZCb);
return R;}
#ifdef __cplusplus
}
#endif

