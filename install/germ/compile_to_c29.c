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
void Zyo2(T39*C){(C->ZUh)=((T9)(Zk(Zxt(4096),sizeof(T3))));(C->ZVb)=Zxt(4096);}void ZUv1(T39*C,T11 a1){((((T7*)((T7*)(Z6G1))))->Zdc)=(ZGs(0));
Zrt(a1,Z6G1);Z_v1(C,Z6G1);}void ZWv1(T39*C,T5 a1,T2 a2){((((T7*)((T7*)(Z6G1))))->Zdc)=(ZGs(0));Znt(a1,Z6G1,a2);Z_v1(C,Z6G1);}void ZYP(T39*C){
if((Z3)((((C)->ZWh))>(ZGs(0)))){Zzo2(C);}Zxv1(ZAo2);}void Zzo2(T39*C){if((Z3)((((C)->ZWh))>(ZGs(0)))){ZtG1(((C)->ZUh),((C)->ZWh),ZAo2);
(C->ZWh)=ZGs(0);}}void ZTF(T39*C,T3 a1){if((Z3)((((C)->ZWh))>=(Zxt(4096)))){Zzo2(C);}(((C)->ZUh))[((C)->ZWh)]=(a1);(C->ZWh)=(Z3)(((((C)->ZWh)))+(ZGs(1)));
if((a1)==(((T3)'\n'))){Zzo2(C);}}void Z_v1(T39*C,T0*a1){T2 Zet=0;T2 ZSF=0;Zet=ZGs(1);ZSF=((((T7*)a1))->Zdc);while(!((Z3)((Zet)>(ZSF))))
{ZTF(C,(((((T7*)a1))->ZUb))[(Zet)-(ZGs(1))]);Zet=(Z3)(((Zet))+(ZGs(1)));}}void ZZv1(T11 a1){((((T7*)((T7*)(Z6G1))))->Zdc)=(ZGs(0));Zrt(a1,Z6G1);
ZXv1(Z6G1);}void ZXv1(T0*a1){T2 Zet=0;T2 ZSF=0;Zet=ZGs(1);ZSF=((((T7*)a1))->Zdc);while(!((Z3)((Zet)>(ZSF)))){{T3 b1=(((((T7*)a1))->ZUb))[(Zet)-(ZGs(1))];
Zvv1(b1,Zwv1);}Zet=(Z3)(((Zet))+(ZGs(1)));}}T0*Z7n1(Z7a*C,T0*a1,T0*a2){T0*R=Zo;T0*ZBo2=Zo;T0*ZCo2=Zo;T0*Z_m1=Zo;T0*ZaO=Zo;T0*ZCF1=Zo;
T2 Zet=0;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)(((Z3)((Zet)<(ZGs(0))))||((T6)((Z_m1)!=((void*)(Zo))))))){ZBo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];
Z_m1=ZZE1(((Zr2*)ZBo2),a1,a2);Zet=(Z3)(((Zet))-(ZGs(1)));}while(!((Z3)((Zet)<(ZGs(0))))){ZCo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];ZaO=ZZE1(((Zr2*)ZCo2),a1,a2);
if((ZaO)!=((void*)(Zo))){ZCF1=ZoF1(((Zr2*)ZCo2),a2);if(ZzF1(((Zr2*)ZCo2),ZCF1)){ZBo2=ZCo2;Z_m1=ZaO;}}Zet=(Z3)(((Zet))-(ZGs(1)));}if((Z_m1)!=((void*)(Zo))){
if((((((ZD8*)Z_m1))->Zse))!=((void*)(((((ZD8*)a2))->Zse)))){R=ZDo2(C,ZBo2,Z_m1,a2);}else{R=Z_m1;}}return R;}T0*Zyl1(Z7a*C,T0*a1,T0*a2,T0*a3){
T0*R=Zo;T2 Zet=0;T0*ZBo2=Zo;T0*ZCo2=Zo;T0*Z_m1=Zo;T0*ZaO=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)(((Z_m1)!=((void*)(Zo)))||((T6)((Z3)((Zet)<(ZGs(0))))))))
{ZBo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];Z_m1=Z1F1(((Zr2*)ZBo2),a1,a2,a3);Zet=(Z3)(((Zet))-(ZGs(1)));}while(!((Z3)((Zet)<(ZGs(0))))){
ZCo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];ZaO=Z1F1(((Zr2*)ZCo2),a1,a2,a3);if((ZaO)!=((void*)(Zo))){if(ZzF1(((Zr2*)ZCo2),ZaO)){ZBo2=ZCo2;
Z_m1=ZaO;}}Zet=(Z3)(((Zet))-(ZGs(1)));}R=Z_m1;return R;}void ZBl1(Z7a*C){T2 Zet=0;T0*Z4W=Zo;T0*ZkL=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);
while(!((Z3)((Zet)<(ZGs(0))))){Z4W=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];ZkL=ZsO(((((Zr2*)Z4W))->ZGb));if((ZkL)==((void*)(Zo))){{T81 Zow;
Z5G((*(Zow=ZmF1(((Zr2*)Z4W)),&Zow)));}{T0*b1=ZEo2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{Zzl1(((T87*)ZkL));}Zet=(Z3)(((Zet))-(ZGs(1)));
}}T6 ZZ71(Z7a*C,T81 a1,T0*a2,T0*a3){T6 R=0;T2 Zet=0;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0))))))))
{R=((T6)(Z4F1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]),a1,a2,a3)));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T0*Zwl1(Z7a*C,T0*a1,T0*a2){
T0*R=Zo;T2 Zet=0;T0*ZBo2=Zo;T0*ZCo2=Zo;T0*ZFo2=Zo;T0*ZGo2=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)(((ZFo2)!=((void*)(Zo)))||((T6)((Z3)((Zet)<(ZGs(0))))))))
{ZBo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];ZFo2=ZdF1(((Zr2*)ZBo2),a1,a2);Zet=(Z3)(((Zet))-(ZGs(1)));}while(!((Z3)((Zet)<(ZGs(0))))){ZCo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];
ZGo2=ZdF1(((Zr2*)ZCo2),a1,a2);if((ZGo2)==((void*)(Zo))){}else if((ZFo2)==((void*)(ZGo2))){}else if(ZHo2(ZGo2,ZFo2)){Z5G(((C)->ZCb));{T81
Zow;Z5G((*(Zow=ZVN(ZFo2),&Zow)));}{T81 Zow;Z5G((*(Zow=ZVN(ZGo2),&Zow)));}{T0*b1=ZIo2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else if(Zlm1(ZGo2)){
}else if(Zlm1(ZFo2)){ZFo2=ZGo2;ZBo2=ZCo2;}else if(ZgF1(((Zr2*)ZBo2),a2)){if(ZgF1(((Zr2*)ZCo2),a2)){}else{Z5G(((((ZD8*)a2))->ZCb));{T81
Zow;Z5G((*(Zow=ZmF1(((Zr2*)ZCo2)),&Zow)));}{T81 Zow;Z5G((*(Zow=ZVN(ZGo2),&Zow)));}{T0*b1=ZJo2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}
else if(ZgF1(((Zr2*)ZCo2),a2)){Z5G(((((ZD8*)a2))->ZCb));{T81 Zow;Z5G((*(Zow=ZmF1(((Zr2*)ZBo2)),&Zow)));}{T81 Zow;Z5G((*(Zow=ZVN(ZFo2),&Zow)));
}{T0*b1=ZJo2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{{T81 Zow;Z5G((*(Zow=ZmF1(((Zr2*)ZCo2)),&Zow)));}{T81 Zow;Z5G((*(Zow=ZmF1(((Zr2*)ZBo2)),&Zow)));
}{T81 Zow;Z5G((*(Zow=ZVN(ZFo2),&Zow)));}{T81 Zow;Z5G((*(Zow=ZVN(ZGo2),&Zow)));}{T0*b1=ZJo2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zet=(Z3)(((Zet))-(ZGs(1)));
}R=ZFo2;return R;}T6 Zom1(Z7a*C,T0*a1){T6 R=0;T2 Zet=0;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0))))))))
{R=((T6)(ZgF1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]),a1)));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T0*Zi72(Z7a*C,T0*a1){T0*R=Zo;T2 Zet=0;
T0*ZKo2=Zo;Zet=ZGs(0);while(!((R)!=((void*)(Zo)))){R=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];ZKo2=((((Zr2*)R))->Zvb);if((ZKo2)==((void*)(a1))){
}else if(ZxM(((T87*)ZKo2),a1)){}else{R=Zo;}Zet=(Z3)(((Zet))+(ZGs(1)));}return R;}T0*ZAm1(Z7a*C,T0*a1){T0*R=Zo;T2 Zet=0;T0*ZWl1=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);
while(!((Z3)((Zet)<(ZGs(0))))){ZWl1=ZiF1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]),a1);if((R)==((void*)(Zo))){R=ZWl1;}else if((ZWl1)!=((void*)(Zo))){
R=ZcG(((ZD*)R),ZWl1);}if((R)==((void*)(Zo))){Zet=(Z3)(((Zet))-(ZGs(1)));}else if(ZYF(((ZD*)R))){Zet=ZGs(-1);}else{Zet=(Z3)(((Zet))-(ZGs(1)));
}}return R;}T0*Zj72(Z7a*C,T0*a1,T0*a2){T0*R=Zo;T2 Zet=0;T0*ZKo2=Zo;Zet=ZGs(0);while(!((R)==((void*)(a2)))){R=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];
Zet=(Z3)(((Zet))+(ZGs(1)));}R=Zo;while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((Zet)>((((Zd8*)(((C)->ZZb)))->ZWb)))))))){R=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];
ZKo2=((((Zr2*)R))->Zvb);if((ZKo2)==((void*)(a1))){}else if(ZxM(((T87*)ZKo2),a1)){}else{R=Zo;}Zet=(Z3)(((Zet))+(ZGs(1)));}return R;}T6
ZSm1(Z7a*C,T0*a1,T0*a2){T6 R=0;T2 Zet=0;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0)))))))){R=((T6)(ZlF1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]),a1,a2)));
Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}void ZPn1(Z7a*C,T0*a1,T81 a2,T0*a3,T0*a4){(C->Zvb)=a1;(C->Z5n)=a3;(C->ZCb)=a2;(C->ZZb)=a4;}T0*Z4n1(Z7a*C,T0*a1,T0*a2){
T0*R=Zo;T0*ZBo2=Zo;T0*Z_m1=Zo;T2 Zet=0;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)(((Z3)((Zet)<(ZGs(0))))||((T6)((Z_m1)!=((void*)(Zo)))))))
{ZBo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];Z_m1=ZnF1(((Zr2*)ZBo2),a1,a2);Zet=(Z3)(((Zet))-(ZGs(1)));}R=Z_m1;if((R)==((void*)(Zo))){R=a2;
Z5G(((((ZD8*)a2))->ZCb));{T0*b1=(((T85*)(((((T87*)a1))->Zpc)))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(49,". PARENT_LIST.original_name, Not Yet Implemented.");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}return R;}T0*ZDo2(Z7a*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;T2 Zet=0;T0*ZCo2=Zo;T0*ZsL=Zo;ZsL=((((Zr2*)a1))->Zvb);
Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZCo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];if((a1)!=((void*)(ZCo2))){if((ZsL)==((void*)(((((Zr2*)ZCo2))->Zvb)))){
if(((((ZD8*)(ZoF1(((Zr2*)ZCo2),a2)))->Zse))==((void*)(((((ZD8*)a3))->Zse)))){R=a3;}else if(((((ZD8*)(ZoF1(((Zr2*)a1),a2)))->Zse))==((void*)(((((ZD8*)a3))->Zse)))){
R=a3;}}}Zet=(Z3)(((Zet))-(ZGs(1)));}if((R)==((void*)(Zo))){R=a2;}return R;}void Zkn1(Z7a*C,T0*a1){T2 Zet=0;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);
while(!((Z3)((Zet)<(ZGs(0))))){Zjn1((T87*)((((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]))->Zvb)),a1);Zet=(Z3)(((Zet))-(ZGs(1)));}}T0*ZSl1(Z7a*C,T0*a1){
T0*R=Zo;T2 Zet=0;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((Zet)<(ZGs(0)))))))){R=ZrF1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]),a1);
Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T0*ZfZ(Z7a*C,T0*a1,T0*a2){T0*R=Zo;T2 Zet=0;T0*ZLo2=Zo;T0*ZGo2=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);
while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((Zet)<(ZGs(0)))))))){ZLo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];R=ZsF1(((Zr2*)ZLo2),a1,a2);
Zet=(Z3)(((Zet))-(ZGs(1)));}if((R)==((void*)(Zo))){Z5G(((((Zd2*)a1))->ZCb));{T0*b1=Z1G(28,"Precursor routine not found.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}if(Zu41((T87*)(((C)->Zvb)))){while(!((Z3)((Zet)<(ZGs(0))))){ZLo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];ZGo2=ZsF1(((Zr2*)ZLo2),a1,a2);
if((T6)(((ZGo2)!=((void*)(Zo)))&&((T6)((ZGo2)!=((void*)(R)))))){Z5G(((((Zd2*)a1))->ZCb));{T81 Zow;Z5G((*(Zow=ZkS1(R),&Zow)));}{T81 Zow;
Z5G((*(Zow=ZkS1(ZGo2),&Zow)));}{T0*b1=Z1G(63,"Multiple Precursor found (must use \173"" ... \175"" ancestor selection).");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}T6 Zbn1(Z7a*C,T0*a1){T6 R=0;T2 Zet=0;T0*ZkL=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);
while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0)))))))){ZkL=(((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]))->Zvb);if((a1)==((void*)(ZkL))){R=((T6)(1));
}else if(ZxM(((T87*)ZkL),a1)){R=((T6)(1));}else{Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}void ZNn1(Z7a*C,T0*a1){T2 Zet=0;Z181(a1,(T11)((Z3)(((((((Zd8*)(((C)->ZZb))))->ZWb)))+(ZGs(1)))));
ZdU(a1,ZMo2);Zet=ZGs(0);while(!((Z3)((Zet)>((((Zd8*)(((C)->ZZb)))->ZWb))))){ZyF1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zet]),a1);ZgU(a1,((T3)'\040'));
Zet=(Z3)(((Zet))+(ZGs(1)));}}void ZVn1(Z7a*C){T2 Zwv=0;T2 Zxv=0;T0*ZBo2=Zo;T0*ZCo2=Zo;Zwv=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zwv)<(ZGs(0)))))
{ZAF1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zwv]));Zwv=(Z3)(((Zwv))-(ZGs(1)));}if((Z3)(((Z3)((((((Zd8*)(((C)->ZZb)))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
Zxv=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((Zxv)==(ZGs(0)))){Zwv=ZGs(0);while(!((Zwv)==(Zxv))){ZBo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zwv];ZCo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zxv];
ZpF1(((Zr2*)ZBo2),ZCo2);ZpF1(((Zr2*)ZCo2),ZBo2);Zwv=(Z3)(((Zwv))+(ZGs(1)));}Zxv=(Z3)(((Zxv))-(ZGs(1)));}}}void ZUn1(Z7a*C){T2 Zwv=0;Zwv=(((Zd8*)(((C)->ZZb)))->ZWb);
while(!((Z3)((Zwv)<(ZGs(0))))){ZGF1((Zr2*)(((((Zd8*)(((C)->ZZb)))->ZUb))[Zwv]),(T0*)C);Zwv=(Z3)(((Zwv))-(ZGs(1)));}}void ZRn1(Z7a*C,T0*a1){
T2 Zet=0;T0*ZBo2=Zo;T0*ZCo2=Zo;T0*Z_m1=Zo;T0*ZaO=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZCo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];
ZaO=ZuF1(((Zr2*)ZCo2),a1);if((T6)(((ZaO)!=((void*)(Zo)))&&((T6)(ZzF1(((Zr2*)ZCo2),a1))))){ZBo2=ZCo2;Z_m1=ZaO;}Zet=(Z3)(((Zet))-(ZGs(1)));
}if((Z_m1)!=((void*)(Zo))){ZQl1((T87*)(((((Zr2*)ZBo2))->Zvb)),Z_m1);}else{Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{ZBo2=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];Z_m1=ZuF1(((Zr2*)ZBo2),a1);if((Z_m1)!=((void*)(Zo))){ZQl1((T87*)(((((Zr2*)ZBo2))->Zvb)),Z_m1);
}Zet=(Z3)(((Zet))-(ZGs(1)));}}}T0*Z2o1(Z7a*C,T0*a1,T0*a2){T0*R=Zo;T2 Zet=0;T0*Z4W=Zo;T0*ZNo2=Zo;Zet=(((Zd8*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{Z4W=((((Zd8*)(((C)->ZZb)))->ZUb))[Zet];ZNo2=ZcF1(((Zr2*)Z4W),a2);if((Z9G(ZNo2))==((void*)(Z9G(a2)))){R=ZNo2;Zet=ZGs(-1);}else if((R)==((void*)(Zo))){
R=ZDU(ZNo2,a2);}else if(ZJG(ZNo2,a2)){if(ZJG(R,a2)){R=ZDU(ZNo2,R);}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
R=ZNo2;}}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));}Zet=(Z3)(((Zet))-(ZGs(1)));}return R;
}T0*ZOo2(Zda*C,T0*a1,T0*a2){T0*R=Zo;{ZE3*n=((ZE3*)Zh(sizeof(*n)));*n=ZHe;ZPc1(n,a1,((C)->ZFb),((C)->ZJb),((C)->ZFe),a2);R=((T0*)n);}return
R;}void ZPo2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T6 ZQo2(Zda*C,T0*a1,T0*a2){T6 R=0;if((Zo)!=((void*)(ZBL(a1)))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZPo2((*(Zow=ZKX1(C),&Zow)),ZWN);}}if((((C)->ZFb))!=((void*)(ZXN(a1)))){if((T6)(((((C)->ZFb))==((void*)(Zo)))||((T6)((ZXN(a1))==((void*)(Zo)))))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZPo2((*(Zow=ZKX1(C),&Zow)),ZYN);}}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZPo2((*(Zow=ZKX1(C),&Zow)),ZTc1);}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
if((((C)->ZFb))!=((void*)(Zo))){if(!(ZQa1((Zz6*)(((C)->ZFb)),ZXN(a1),a2))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Z5G((*(Zow=ZKX1(C),&Zow)));
}{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}
}}R=((T6)(((((T80*)(Z4G))->ZEg))==(ZGs(0))));if(R){ZRo2(C,a1);}return R;}void ZRo2(Zda*C,T0*a1){if((((T43*)(ZSG))->ZRk)){if((((C)->ZHb))==((void*)(Zo))){
(C->ZHb)=Z2O(a1);}else if((Z2O(a1))==((void*)(Zo))){Z3O(a1,((C)->ZHb));}}}T0*Z1n1(Zda*C,T0*a1,T0*a2){T0*R=Zo;T6 ZSo2=0;if((((C)->ZKb))!=((void*)(Zo))){
ZSo2=((T6)(1));}else if((((C)->ZLb))!=((void*)(Zo))){ZSo2=((T6)(!(ZsN1((ZX6*)(((C)->ZLb))))));}if(ZSo2){R=ZjD(((ZR6*)(((((ZZ3*)a1))->Ztg))),a2);
if(Zo!=(R)){switch(((T0*)R)->id){case 451:break;default:R=Zo;}}if((R)==((void*)(Zo))){R=Zbu1(C,((((ZZ3*)a1))->Z4c),a2);}}return R;}void
ZTo2(Zda*C,T0*a1){T2 Zet=0;T0*Z5O=Zo;T0*Z6O=Zo;(C->Zvb)=(((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),ZGs(1))))->ZCb)).Zvb);Zet=ZGs(1);while(!((Z3)((Zet)>(Z8O((Zz8*)(((C)->Zkc)))))))
{Z5O=Z7O((Zz8*)(((C)->Zkc)),Zet);Z6O=Z3D(((Zp6*)a1),Z5O);if((Z6O)!=((void*)(Zo))){Z5O=((((Zz8*)(((((ZX4*)Z6O))->Zkc))))->ZGd);Z5G(((((ZD8*)Z5O))->ZCb));
Z5G((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),Zet)))->ZCb));{T0*b1=Z1G(29,"Double definition of feature ");Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)Z5O))->Zse);
Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}else{Z0D(((Zp6*)a1),(T0*)C,Z5O);}Zet=(Z3)(((Zet))+(ZGs(1)));}}void
ZUo2(Zda*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){((((Zda*)(C)))->Zkc)=(a1);(C->ZHb)=a4;(C->ZFb)=a2;(C->ZIb)=a3;(C->ZJb)=a5;}T0*ZVo2(Zda*C,T0*a1,T0*a2){
T0*R=Zo;T0*ZaO=Zo;Z5G(((((ZD8*)a1))->ZCb));ZaO=ZbO((Zz8*)(((C)->Zkc)),((((ZD8*)a1))->Zcn));if((ZaO)!=((void*)(Zo))){ZcO(((ZD8*)ZaO),a2);
}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=ZOo2(C,a1,a2);if((R)!=((void*)(Zo))){((((ZE3*)(((ZE3*)R))))->Zjc)=(((C)->Zjc));
ZRo2(C,R);}else{ZTN(((T87*)a2),a1);}return R;}void ZWo2(Zda*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5,T0*a6,T0*a7){ZUo2(C,a1,a2,a3,a4,a5);(C->ZKb)=a6;
(C->ZLb)=a7;(C->Zbh)=ZGs(34);}void ZXo2(Zda*C,T81 a1){if((((C)->ZIb))!=((void*)(Zo))){if(!((((T43*)(ZSG))->ZRk))){Z5G(a1);{T0*b1=Z1G(27,"This feature is obsolete :\n");
Zmx((T7*)(Z2G),b1);}{T0*b1=(((T93*)(((C)->ZIb)))->Zse);Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZKX1(C),&Zow)));}ZPG((T80*)(Z4G));}}}void
Zau1(Zda*C,T0*a1,T0*a2,T0*a3){T81 ZjG={Zo,Zo,0};T0*Zem1=Zo;T0*ZYo2=Zo;T0*ZZo2=Zo;T0*Z_o2=Zo;T0*Z0p2=Zo;T0*Z1p2=Zo;T0*ZEY1=Zo;T0*Zgq1=Zo;
{T81*C1=&ZjG;T0*b1=a1;Z3m1(C1,(T2)(ZGs(1)),(T2)(ZGs(1)),((((T87*)b1))->_id),b1);}(C->Zvb)=a1;{Zz8*n=((Zz8*)Zh(sizeof(*n)));*n=Z9l;((((Zz8*)(n)))->ZGd)=(a2);
Zem1=((T0*)n);}{Zi1*n=((Zi1*)Zh(sizeof(*n)));*n=Zte;Z2b1(n,ZjG,ZQJ);ZYo2=((T0*)n);}{Z_*n=((Z_*)Zh(sizeof(*n)));*n=Zqc;ZiO(n,ZYo2,((((ZE7*)(((((ZD8*)a3))->Zdn))))->Zlc));
Z_o2=((T0*)n);}Z0p2=Z4m1(1,Z_o2);{Zz6*n=((Zz6*)Zh(sizeof(*n)));*n=Zbj;Zra1(n,Z0p2);Z1p2=((T0*)n);}{Zi3*n=((Zi3*)Zh(sizeof(*n)));*n=Zre;
Zza1(n,ZjG,Z1p2,(T2)(ZGs(1)));ZZo2=((T0*)n);}{Zi9*n=((Zi9*)Zh(sizeof(*n)));*n=Z_l;ZuL1(n,a3,ZZo2);ZEY1=((T0*)n);}{ZX6*n=((ZX6*)Zh(sizeof(*n)));
*n=Zzj;Z4N1(n,Zo,ZEY1);Zgq1=((T0*)n);}ZWo2(C,Zem1,Z1p2,Zo,Zo,Zo,Zo,Zgq1);{ZD*n=((ZD*)Zh(sizeof(*n)));*n=Z0c;(C->Zjc)=((T0*)n);}}T0*Zbu1(Zda*C,T0*a1,T0*a2){
T0*R=Zo;{ZG7*n=((ZG7*)Zh(sizeof(*n)));*n=Zgk;ZmX1(n,a1,a2,(T0*)C);R=((T0*)n);}return R;}void Z2p2(Zda*C,T0*a1){if((T6)(((a1)!=((void*)(Zo)))&&((T6)((Z3)((ZZy(((T79*)(((((T91*)a1))->ZZb)))))>(ZGs(1))))))){
(C->ZGe)=a1;}}T6 Z3p2(Zda*C,T0*a1){T6 R=0;R=((T6)((ZBL(a1))!=((void*)(Zo))));if(R){{T0*b1=ZWN;Zmx((T7*)(Z2G),b1);}}else{if((((C)->ZFb))==((void*)(Zo))){
R=((T6)((ZXN(a1))!=((void*)(Zo))));}else{R=((T6)((ZXN(a1))==((void*)(Zo))));}if(R){{T0*b1=ZYN;Zmx((T7*)(Z2G),b1);}}else if((((C)->ZFb))==((void*)(Zo))){
}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){{T0*b1=ZTc1;Zmx((T7*)(Z2G),b1);}R=((T6)(1));
}}ZRo2(C,a1);return R;}T81 ZKX1(Zda*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->ZCb);return R;}void Z4p2(Zha*C,T81
a1){{ZB*n=((ZB*)Zh(sizeof(*n)));*n=ZYb;ZZx(n,(T2)(ZGs(4)),(T2)(ZGs(1)));(C->ZZb)=((T0*)n);}(C->ZCb)=a1;}void ZXm1(Zha*C){T2 Zet=0;Zet=(((ZB*)(((C)->ZZb)))->ZWb);
while(!((Z3)((Zet)<((((ZB*)(((C)->ZZb)))->ZXb))))){Z232((Z18*)(ZXx((ZB*)(((C)->ZZb)),Zet)));Zet=(Z3)(((Zet))-(ZGs(1)));}}void Z5p2(Zha*C,T0*a1){
T0*Z6p2=Zo;T2 Zet=0;T0*ZU81=Zo;T0*ZV81=Zo;Zet=(((ZB*)(((C)->ZZb)))->ZWb);((((Z18*)(((Z18*)a1))))->Zpe)=((Z3)(((Zet))+((T2)(ZGs(1)))));
ZU81=(((T85*)(((((Z18*)a1))->Zpc)))->Zse);while(!((Z3)((Zet)<((((ZB*)(((C)->ZZb)))->ZXb))))){Z6p2=ZXx((ZB*)(((C)->ZZb)),Zet);ZV81=(((T85*)(((((Z18*)Z6p2))->Zpc)))->Zse);
if((ZU81)==((void*)(ZV81))){{T81 Zow;Z5G((*(Zow=Z332(((Z18*)a1)),&Zow)));}{T81 Zow;Z5G((*(Zow=Z332(((Z18*)Z6p2)),&Zow)));}{T0*b1=Z1G(66,"Formal generic name appears twice in formal generic list (VCFG.2).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}ZZ22(((Z18*)Z6p2),a1,(Z3)((((((ZB*)(((C)->ZZb)))->ZWb)))+((T2)(ZGs(1)))));Zet=(Z3)(((Zet))-(ZGs(1)));
}ZYx((ZB*)(((C)->ZZb)),a1);}T6 Zim1(ZD8*C){T6 R=0;{int z1=((C)->Zen);switch(z1){case 4:R=((T6)(1));break;case 5:R=((T6)(Zim1((ZD8*)(((C)->Z2c)))));
break;}}return R;}void Z7p2(ZD8*C,T0*a1,T0*a2){(C->ZCb)=((((ZD8*)a1))->ZCb);(C->Zse)=((((ZD8*)a1))->Zse);(C->Zcn)=((C)->Zse);(C->Zdn)=a2;
(C->Zrf)=((((ZD8*)a1))->Zrf);(C->Zen)=ZGs(1);}void Z8p2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T6 ZYC(ZD8*C,T0*a1){
T6 R=0;R=((T6)((((C)->Zcn))==((void*)(((((ZD8*)a1))->Zcn)))));return R;}void Z9p2(ZD8*C,T0*a1){(C->Z2c)=a1;(C->ZCb)=((((ZD8*)a1))->ZCb);
(C->Zse)=((((ZD8*)a1))->Zse);(C->Zcn)=((((ZD8*)a1))->Zcn);(C->Zrf)=((((ZD8*)a1))->Zrf);(C->Zen)=ZGs(4);}void ZuH(ZD8*C,T0*a1,T81 a2){
(C->ZCb)=a2;(C->Zse)=a1;(C->Zcn)=(((void)((T27*)(Zap2()))),Zxl2(((C)->Zse)));(C->Zrf)=ZBx((T7*)(((C)->Zcn)));(C->Zen)=ZGs(2);}void Zbp2(ZD8*C){
ZgM((Z84*)(ZkH),Zcp2);if((T6)(((((T43*)(ZSG))->ZXk))&&((T6)(Z3L((((ZE7*)(((C)->Zdn)))->Z4c)))))){ZgM((Z84*)(ZkH),Zdp2);ZDM((Z84*)(ZkH),(T11)(ZEM((((ZE7*)(((C)->Zdn)))->Z4c))));
ZgM((Z84*)(ZkH),Zep2);}else{ZgM((Z84*)(ZkH),Zfp2);}Z_V1((ZE7*)(((C)->Zdn)));ZdL((Z84*)(ZkH),((T3)'\051'));}void Zwc1(ZD8*C,T0*a1,T81 a2){
(C->ZCb)=a2;(C->Zse)=a1;(C->Zcn)=(((void)((T27*)(Zap2()))),ZFl2(((C)->Zse)));(C->Zrf)=ZBx((T7*)(((C)->Zcn)));(C->Zen)=ZGs(3);}T6 Zgp2(ZD8*C,T0*a1){
T6 R=0;T0*Z9e1=Zo;Z9e1=((C)->Zdn);if((Z9e1)!=((void*)(Zo))){if(ZYG(Z9e1,a1)){R=((T6)((ZcW1(((ZE7*)Z9e1),a1))!=((void*)(Zo))));}}return
R;}void Zhp2(ZD8*C){Z5G(((C)->ZCb));{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}void Zip2(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Zjp2(ZD8*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}Z5G(((C)->ZCb));
Z3G((T80*)(Z4G));}void ZcO(ZD8*C,T0*a1){if(Zim1(C)){Z8p2(((C)->ZCb),Z1G(46,"A frozen feature must not be undefined (VDUS)."));ZTN(((T87*)a1),(T0*)C);
}}T0*ZFQ1(ZD8*C){T0*R=Zo;{int z1=((C)->Zen);switch(z1){case 1:break;case 2:R=Zkp2;break;case 3:R=Zlp2;break;case 5:R=ZWK;break;default:;
R=ZFQ1((ZD8*)(((C)->Z2c)));}}return R;}T0*Zap2(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);
ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);
ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);
ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);
ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);
ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);
ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);
ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);
ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);
ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);
ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);
ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);
ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);
ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);
ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}void ZkZ(ZD8*C,T2 a1,T0*a2){(C->ZCb)=((((ZD8*)a2))->ZCb);(C->Z2c)=a2;(C->Zse)=((((ZD8*)a2))->Zse);
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zwx(n,(Z3)((((T2)(ZGs(8))))+((((T7*)((((ZD8*)(((C)->Z2c)))->Zcn)))->Zdc))));(C->Zcn)=((T0*)n);}Zgt((T7*)(((C)->Zcn)),((T3)'\137'));
Z6t(a1,((C)->Zcn));Zgt((T7*)(((C)->Zcn)),((T3)'P'));Zmx((T7*)(((C)->Zcn)),(((ZD8*)(((C)->Z2c)))->Zcn));(C->Zcn)=(((void)((T27*)(Zap2()))),ZCG(((C)->Zcn)));
(C->Zrf)=ZBx((T7*)(((C)->Zcn)));(C->Zen)=ZGs(5);}void Znl1(ZD8*C,T0*a1){T81 ZKB={Zo,Zo,0};(C->ZCb)=ZKB;(C->Zse)=a1;(C->Zcn)=a1;(C->Zrf)=ZBx((T7*)(((C)->Zcn)));
(C->Zen)=ZGs(1);}T6 Zmp2(ZD8*C){T6 R=0;R=((T6)((ZGs(1))==(((C)->Zen))));return R;}T6 Znp2(T0*a1){T6 R=0;return R;}T0*ZM82(ZD8*C,T0*a1){
T0*R=Zo;R=ZQe1((ZZ3*)(Z_G(a1)),(T0*)C);return R;}void Zop2(ZD8*C,T0*a1){T6 Z8L=0;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Zbp2(C);if(Z8L){ZgL((Z84*)(ZkH));
}}void Zfk1(ZD8*C,T0*a1){{int z1=((C)->Zen);switch(z1){case 1:Zmx(((T7*)a1),((C)->Zse));break;case 2:Zmx(((T7*)a1),Zkp2);Zgt(((T7*)a1),((T3)'\040'));
Zgt(((T7*)a1),((T3)'\042'));Zmx(((T7*)a1),((C)->Zse));Zgt(((T7*)a1),((T3)'\042'));break;case 3:Zmx(((T7*)a1),Zlp2);Zgt(((T7*)a1),((T3)'\040'));
Zgt(((T7*)a1),((T3)'\042'));Zmx(((T7*)a1),((C)->Zse));Zgt(((T7*)a1),((T3)'\042'));break;case 5:break;default:;Zfk1((ZD8*)(((C)->Z2c)),a1);
}}}T2 Zpp2(ZD8*C){T2 R=0;Zjp2(C);return R;}void Z5m1(ZD8*C,T0*a1,T81 a2){(C->ZCb)=a2;(C->Zse)=a1;(C->Zcn)=a1;(C->Zrf)=ZBx((T7*)(((C)->Zcn)));
(C->Zen)=ZGs(1);}T0*Zqp2(ZD8*C,T0*a1){T0*R=Zo;T0*ZdZ=Zo;T0*ZiL=Zo;T0*Zrp2=Zo;T0*Z9e1=Zo;ZdZ=((((C)->ZCb)).Zvb);Zrp2=Zi_((T87*)(ZsO(a1)),ZdZ,(T0*)C);
ZiL=ZyP((ZZ3*)(Z_G(a1)),Zrp2);if((ZiL)==((void*)(Zo))){Zxq1(Zrp2);{T0*b1=Z1G(2," :");Zmx((T7*)(Z2G),b1);}Zip2(Zsp2);}else{Z9e1=ZiL;if(Zo!=(Z9e1)){
switch(((T0*)Z9e1)->id){case 174:break;default:Z9e1=Zo;}}if((Z9e1)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(ZiL),&Zow)));}Z5G(((C)->ZCb));
{T0*b1=Z1G(30,"Feature found is not writable.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}if((((C)->Zdn))==((void*)(Zo))){(C->Zdn)=Z9e1;
R=((T0*)(C));}else if((((C)->Zdn))==((void*)(ZiL))){R=((T0*)(C));}else{{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Z7p2(n,(T0*)C,Z9e1);R=((T0*)n);
}}return R;}T0*Ztp2(ZD8*C){T0*R=Zo;T0*ZkL=Zo;T0*ZyL=Zo;T0*ZjL=Zo;ZkL=((((C)->ZCb)).Zvb);if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),(T0*)C);
if((ZyL)!=((void*)(Zo))){ZjL=ZBL(ZyL);if((ZjL)!=((void*)(Zo))){R=ZCL(ZjL);}}}return R;}T0*ZZl1(ZD8*C){T0*R=Zo;R=((((C)->ZCb)).Zvb);return
R;}void Zup2(Zja*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZtE1);}else{ZgM((Z84*)(ZkH),ZuE1);
}}}T0*Zvp2(void){if(ZCm1==0){ZCm1=1;{{Zj6*n=((Zj6*)Zh(sizeof(*n)));*n=ZYi;ZBm1=((T0*)n);}}}return ZBm1;}void Zj41(Zja*C){T2 Zet=0;T0*ZwE1=Zo;
if(!(Zwp2(C))){Zxp2(C);Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb))))){ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];Zyp2(ZwE1);
Zet=(Z3)(((Zet))+(ZGs(1)));}Zup2(C);}}void Zl41(Zja*C,T81 a1,T0*a2,T0*a3){(C->ZCb)=a1;(C->ZHb)=a2;(C->ZZb)=a3;}void Zxp2(Zja*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZAE1);}else{ZgM((Z84*)(ZkH),ZBE1);}}}void Zn41(Zja*C){T2 Zet=0;if((((C)->ZZb))!=((void*)(Zo))){
Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZCE1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]));Zet=(Z3)(((Zet))-(ZGs(1)));
}}}T6 Zwp2(Zja*C){T6 R=0;T2 Zet=0;T0*ZwE1=Zo;Zet=(((Zu1*)(((C)->ZZb)))->ZWb);R=((T6)(1));while(!((T6)((!(R))||((T6)((Z3)((Zet)<(ZGs(0))))))))
{ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];R=((T6)(ZDE1(((Zn6*)ZwE1))));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T6 Zp41(Zja*C){T6 R=0;T2 Zet=0;
if((((C)->ZZb))!=((void*)(Zo))){Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0)))))))){R=((T6)(Z2H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]))));
Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}void Zr41(Zja*C,T0*a1){T2 Zet=0;Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0)))))
{Z3H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]),a1);Zet=(Z3)(((Zet))-(ZGs(1)));}}T0*Zzp2(Zja*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zja*)R)=*C;
return R;}T0*Zv41(Zja*C,T0*a1){T0*R=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;(C->Z3c)=ZPH();if((((C)->ZZb))!=((void*)(Zo))){(C->ZZb)=(((void)((Zj6*)(Zvp2()))),ZrO(((C)->ZZb),a1,((C)->Z3c),((T3)'\137')));
}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){R=((T0*)(C));}}else{R=Zzp2(C);((((Zja*)(((Zja*)R))))->Z4c)=(Zo);R=Zv41(((Zja*)R),a1);}return R;
}void Zyp2(T0*a1){T6 Zz61=0;if(ZDE1(((Zn6*)a1))){}else{ZWE1(((Zn6*)a1));Zz61=((T6)(Zsq1((Z84*)(ZkH))));((((Z84*)((Z84*)(ZkH))))->ZNf)=(ZAp2);
ZYE1(((Zn6*)a1));if(Zz61){ZB61((Z84*)(ZkH));}}}void Z4P(Z11*C,T81 a1,T0*a2,T0*a3,T0*a4){(C->ZCb)=a1;(C->ZZb)=a2;(C->Z4c)=a3;(C->Z3c)=a4;
}void ZBp2(Z11*C,T81 a1,T6 a2,T0*a3,T0*a4){ZCp2(C,a1,a3,a4);(C->Zrc)=((T6)(a2));}void ZDp2(Z11*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZtE1);}else{ZgM((Z84*)(ZkH),ZuE1);}}}void ZmS1(Z11*C){T2 Zet=0;T0*ZwE1=Zo;if(!(ZEp2(C))){
ZFp2(C);Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb))))){ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];ZGp2(ZwE1);Zet=(Z3)(((Zet))+(ZGs(1)));
}ZDp2(C);}}void ZDO(Z11*C,T0*a1){T2 Zet=0;T0*ZKO=Zo;if((((C)->ZZb))!=((void*)(Zo))){Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb)))))
{ZKO=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];if(!(Z_z(((Zu1*)a1),ZKO))){Z1A(((Zu1*)a1),ZKO);}Zet=(Z3)(((Zet))+(ZGs(1)));}}}void ZPQ1(Z11*C,T0*a1,T0*a2){
T2 Zet=0;if((((C)->ZZb))!=((void*)(Zo))){Zet=ZGs(0);while(!((Z3)((Zet)>((((Zu1*)(((C)->ZZb)))->ZWb))))){Z0H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]),a1,a2);
Zet=(Z3)(((Zet))+(ZGs(1)));}}}void ZCp2(Z11*C,T81 a1,T0*a2,T0*a3){(C->ZCb)=a1;(C->ZHb)=a2;(C->ZZb)=a3;}void ZFp2(Z11*C){if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
if((((C)->Z3c))==((void*)(Zo))){ZgM((Z84*)(ZkH),ZAE1);}else{ZgM((Z84*)(ZkH),ZBE1);}}}void ZXQ1(Z11*C){T2 Zet=0;if((((C)->ZZb))!=((void*)(Zo))){
Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZCE1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]));Zet=(Z3)(((Zet))-(ZGs(1)));
}}}T6 ZEp2(Z11*C){T6 R=0;T2 Zet=0;T0*ZwE1=Zo;Zet=(((Zu1*)(((C)->ZZb)))->ZWb);R=((T6)(1));while(!((T6)((!(R))||((T6)((Z3)((Zet)<(ZGs(0))))))))
{ZwE1=((((Zu1*)(((C)->ZZb)))->ZUb))[Zet];R=((T6)(ZDE1(((Zn6*)ZwE1))));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}T6 ZKQ1(Z11*C){T6 R=0;T2 Zet=0;
if((((C)->ZZb))!=((void*)(Zo))){Zet=(((Zu1*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0)))))))){R=((T6)(Z2H1((Zn6*)(((((Zu1*)(((C)->ZZb)))->ZUb))[Zet]))));
Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}T6 ZHp2(void){T6 R=0;return R;}void ZGp2(T0*a1){T6 Zz61=0;if(ZDE1(((Zn6*)a1))){}else{ZWE1(((Zn6*)a1));
Zz61=((T6)(Zsq1((Z84*)(ZkH))));((((Z84*)((Z84*)(ZkH))))->ZNf)=(ZIp2);ZYE1(((Zn6*)a1));if(Zz61){ZB61((Z84*)(ZkH));}}}void ZJp2(Zi3*C,T0*a1,T0*a2){
*((Zi3*)(C))=*((Zi3*)(a1));(C->Zqe)=a2;}T0*ZBa1(Zi3*C){T0*R=Zo;R=(((Zi1*)(Zky(((Zl2*)((((Zz6*)(((C)->Zqe)))->Zie))),((C)->Zpe))))->Zse);
return R;}T6 ZKp2(Zi3*C,T0*a1){T6 R=0;if(Z0b1(ZLp2(C),a1)){R=((T6)(1));}return R;}void ZMp2(Zi3*C){Z5G(((C)->ZCb));{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZNp2(Zi3*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}Z5G(((C)->ZCb));Z3G((T80*)(Z4G));}T0*ZLp2(Zi3*C){
T0*R=Zo;R=Z8a1((Zz6*)(((C)->Zqe)),((C)->Zpe));return R;}void Zza1(Zi3*C,T81 a1,T0*a2,T2 a3){(C->ZCb)=a1;(C->Zqe)=a2;(C->Zpe)=a3;}T6 ZOp2(T0*a1){
T6 R=0;return R;}void ZPp2(Zi3*C,T0*a1){T6 Z8L=0;T0*ZjL=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));ZjL=ZnH(ZLp2(C));if(ZbL(ZjL)){if(ZbL(a1)){
ZdL((Z84*)(ZkH),((T3)'\050'));ZcL(a1);ZGa1((Z84*)(ZkH),((C)->Zpe));ZdL((Z84*)(ZkH),((T3)'\051'));}else{ZGa1((Z84*)(ZkH),((C)->Zpe));}
}else if(ZbL(a1)){ZGa1((Z84*)(ZkH),((C)->Zpe));}else if(ZX01(ZjL)){if(!(ZPX(ZjL))){ZdL((Z84*)(ZkH),((T3)'\046'));}ZGa1((Z84*)(ZkH),((C)->Zpe));
}else{ZGa1((Z84*)(ZkH),((C)->Zpe));}if(Z8L){ZgL((Z84*)(ZkH));}}T2 ZQp2(Zi3*C){T2 R=0;ZNp2(C);return R;}T0*ZRp2(Zi3*C,T0*a1){T0*R=Zo;T0*ZiL=Zo;
T0*Z4e1=Zo;ZiL=ZPH();Z4e1=ZAP(ZiL);if((((C)->Zqe))==((void*)(Z4e1))){R=((T0*)(C));}else{{Zi3*n=((Zi3*)Zh(sizeof(*n)));*n=Zre;ZJp2(n,(T0*)C,Z4e1);
R=((T0*)n);}}return R;}T0*ZF52(Zi3*C){T0*R=Zo;R=ZCL(ZLp2(C));return R;}T0*ZSp2(ZX4*C,T0*a1,T0*a2){T0*R=Zo;{ZE3*n=((ZE3*)Zh(sizeof(*n)));
*n=ZHe;ZPc1(n,a1,((C)->ZFb),((C)->ZJb),((C)->ZFe),a2);R=((T0*)n);}return R;}void ZTp2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);
}Z3G((T80*)(Z4G));}T6 ZUp2(ZX4*C,T0*a1,T0*a2){T6 R=0;if((Zo)!=((void*)(ZBL(a1)))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZTp2((*(Zow=ZiR(C),&Zow)),ZWN);
}}if((((C)->ZFb))!=((void*)(ZXN(a1)))){if((T6)(((((C)->ZFb))==((void*)(Zo)))||((T6)((ZXN(a1))==((void*)(Zo)))))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));
}{T81 Zow;ZTp2((*(Zow=ZiR(C),&Zow)),ZYN);}}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZTp2((*(Zow=ZiR(C),&Zow)),ZTc1);}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
if((((C)->ZFb))!=((void*)(Zo))){if(!(ZQa1((Zz6*)(((C)->ZFb)),ZXN(a1),a2))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Z5G((*(Zow=ZiR(C),&Zow)));
}{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}
}}R=((T6)(((((T80*)(Z4G))->ZEg))==(ZGs(0))));if(R){ZVp2(C,a1);}return R;}void ZWp2(ZX4*C,T0*a1,T0*a2){(C->Z2h)=a1;(C->Z3h)=a2;}void ZVp2(ZX4*C,T0*a1){
if((((T43*)(ZSG))->ZRk)){if((((C)->ZHb))==((void*)(Zo))){(C->ZHb)=Z2O(a1);}else if((Z2O(a1))==((void*)(Zo))){Z3O(a1,((C)->ZHb));}}}void
ZXp2(ZX4*C,T0*a1){T2 Zet=0;T0*Z5O=Zo;T0*Z6O=Zo;(C->Zvb)=(((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),ZGs(1))))->ZCb)).Zvb);Zet=ZGs(1);while(!((Z3)((Zet)>(Z8O((Zz8*)(((C)->Zkc)))))))
{Z5O=Z7O((Zz8*)(((C)->Zkc)),Zet);Z6O=Z3D(((Zp6*)a1),Z5O);if((Z6O)!=((void*)(Zo))){Z5O=((((Zz8*)(((((ZX4*)Z6O))->Zkc))))->ZGd);Z5G(((((ZD8*)Z5O))->ZCb));
Z5G((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),Zet)))->ZCb));{T0*b1=Z1G(29,"Double definition of feature ");Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)Z5O))->Zse);
Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}else{Z0D(((Zp6*)a1),(T0*)C,Z5O);}Zet=(Z3)(((Zet))+(ZGs(1)));}}void
ZYp2(ZX4*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){((((ZX4*)(C)))->Zkc)=(a1);(C->ZHb)=a4;(C->ZFb)=a2;(C->ZIb)=a3;(C->ZJb)=a5;}T0*ZZp2(ZX4*C,T0*a1,T0*a2){
T0*R=Zo;T0*ZaO=Zo;Z5G(((((ZD8*)a1))->ZCb));ZaO=ZbO((Zz8*)(((C)->Zkc)),((((ZD8*)a1))->Zcn));if((ZaO)!=((void*)(Zo))){ZcO(((ZD8*)ZaO),a2);
}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=ZSp2(C,a1,a2);if((R)!=((void*)(Zo))){((((ZE3*)(((ZE3*)R))))->Zjc)=(((C)->Zjc));
ZVp2(C,R);}else{ZTN(((T87*)a2),a1);}return R;}void ZFm1(ZX4*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5,T0*a6,T0*a7){ZYp2(C,a1,a2,a3,a4,a5);ZWp2(C,a6,a7);
}void Z_p2(ZX4*C,T81 a1){if((((C)->ZIb))!=((void*)(Zo))){if(!((((T43*)(ZSG))->ZRk))){Z5G(a1);{T0*b1=Z1G(27,"This feature is obsolete :\n");
Zmx((T7*)(Z2G),b1);}{T0*b1=(((T93*)(((C)->ZIb)))->Zse);Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZiR(C),&Zow)));}ZPG((T80*)(Z4G));}}}T6
Zh02(ZX4*C){T6 R=0;R=((T6)(ZiT1(((C)->Z2h),(T0*)C)));return R;}T2 Zo22(ZX4*C,T0*a1){T2 R=0;if((((C)->ZFb))!=((void*)(Zo))){R=Z9a1((Zz6*)(((C)->ZFb)),a1);
}return R;}T0*Z5R(ZX4*C){T0*R=Zo;T0*ZlT1=Zo;T0*ZVx=Zo;ZlT1=((C)->Z2h);if(Zo!=(ZlT1)){switch(((T0*)ZlT1)->id){case 144:break;default:ZlT1=Zo;
}}if((ZlT1)==((void*)(Zo))){R=ZJQ(C);}else{ZVx=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->Zse);{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zwx(n,(Z3)(((((((T7*)ZVx))->Zdc)))+((T2)(ZGs(8)))));
R=((T0*)n);}Zmx(((T7*)R),ZnT1);ZFt((((T87*)(((C)->Zvb)))->_id),R);Zmx(((T7*)R),ZVx);}return R;}T0*ZGm1(ZX4*C,T0*a1,T0*a2){T0*R=Zo;{ZO7*n=((ZO7*)Zh(sizeof(*n)));
*n=Zkk;Z702(n,a1,a2,(T0*)C);R=((T0*)n);}return R;}void Z0q2(ZX4*C,T0*a1){if((T6)(((a1)!=((void*)(Zo)))&&((T6)((Z3)((ZZy(((T79*)(((((T91*)a1))->ZZb)))))>(ZGs(1))))))){
(C->ZGe)=a1;}}T6 Z1q2(ZX4*C,T0*a1){T6 R=0;R=((T6)((ZBL(a1))!=((void*)(Zo))));if(R){{T0*b1=ZWN;Zmx((T7*)(Z2G),b1);}}else{if((((C)->ZFb))==((void*)(Zo))){
R=((T6)((ZXN(a1))!=((void*)(Zo))));}else{R=((T6)((ZXN(a1))==((void*)(Zo))));}if(R){{T0*b1=ZYN;Zmx((T7*)(Z2G),b1);}}else if((((C)->ZFb))==((void*)(Zo))){
}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){{T0*b1=ZTc1;Zmx((T7*)(Z2G),b1);}R=((T6)(1));
}}ZVp2(C,a1);return R;}T81 ZiR(ZX4*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->ZCb);return R;}void Z2q2(ZX4*C,T0*a1){
if((a1)!=((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z2d1(((ZX6*)a1)),&Zow)));}}else{{T81 Zow;Z5G((*(Zow=ZiR(C),&Zow)));}}{T0*b1=Z1G(47,"External feature must not have rescue compound.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}T0*ZJQ(ZX4*C){T0*R=Zo;if((((C)->Z3h))==((void*)(Zo))){R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->Zse);
}else{R=((C)->Z3h);}return R;}Zg5*Z3q2(T81 a1){Zg5*n;n=((Zg5*)Zh(sizeof(*n)));*n=Zjh;Z3q1(n,a1);return n;}T0*Z4q2(Zg5*C){T0*R=Zo;Z5q2(C);
return R;}T0*Z6q2(void){if(Z7P==0){Z7P=1;{T81 Z9P={Zo,Zo,0};{Z83*n=((Z83*)Zh(sizeof(*n)));*n=Zge;Z6P=((T0*)n);ZaP(n,Z9P);}}}return Z6P;
}T0*Z7q2(Zg5*C){T0*R=Zo;{int z1=((C)->Zih);switch(z1){case 8:R=ZbI;break;case 16:R=ZcI;break;case 0:case 32:R=ZeI;break;default:;R=ZfI;
}}return R;}T0*Z8q2(Zg5*C){T0*R=Zo;{int z1=((C)->Zih);switch(z1){case 8:R=ZbI;break;case 16:R=ZcI;break;case 0:case 32:R=ZeI;break;default:;
R=ZfI;}}return R;}T2 ZJk2(Zg5*C){T2 R=0;{int z1=((C)->Zih);switch(z1){case 8:R=ZGs(1);break;case 16:R=ZGs(2);break;case 0:case 32:R=ZGs(4);
break;default:;R=ZGs(8);}}return R;}T6 Z9q2(void){T6 R=0;return R;}T6 Zaq2(Zg5*C){T6 R=0;T0*Z9T=Zo;Z9T=Zo;R=((T6)((Z9T)!=((void*)(Zo))));
return R;}void Zbq2(Zg5*C,T0*a1){Zmx(((T7*)a1),ZaT);Z6t(Zcq2(C),a1);}T6 Zdq2(Zg5*C){T6 R=0;T0*ZjL=Zo;ZjL=((T0*)(C));if((C)==((void*)(ZjL))){
if((ZnH(ZjL))==((void*)(ZjL))){R=((T6)((ZcT(ZjL))==((void*)(Z9G(ZjL)))));}}return R;}T2 Zcq2(Zg5*C){T2 R=0;{int z1=((C)->Zih);switch(z1){
case 8:R=ZGs(1);break;case 16:R=ZGs(10);break;case 0:case 32:R=ZGs(2);break;default:;R=ZGs(11);}}return R;}void ZGo1(Zg5*C,T81 a1){(C->Zih)=ZGs(16);
{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zu81(n,ZcI,a1);(C->Zfe)=((T0*)n);}}void Zeq2(Zg5*C){((((T7*)((T7*)(ZgT))))->Zdc)=(ZGs(0));Zgt((T7*)(ZgT),((T3)'\050'));
{Zg5*C1=C;T0*b1=ZgT;Zfq2(C1,b1);}Zgt((T7*)(ZgT),((T3)'\051'));ZgM((Z84*)(ZkH),ZgT);}void ZHo1(Zg5*C,T81 a1){(C->Zih)=ZGs(32);{T85*n=((T85*)Zh(sizeof(*n)));
*n=M85;Zu81(n,ZdI,a1);(C->Zfe)=((T0*)n);}}void Zgq2(Zg5*C,T81 a1){(C->Zih)=ZGs(65);{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zu81(n,ZaI,a1);
(C->Zfe)=((T0*)n);}}void Z3q1(Zg5*C,T81 a1){(C->Zih)=ZGs(0);{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zu81(n,ZeI,a1);(C->Zfe)=((T0*)n);}}void
ZIo1(Zg5*C,T81 a1){(C->Zih)=ZGs(64);{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zu81(n,ZfI,a1);(C->Zfe)=((T0*)n);}}void Z5q2(Zg5*C){ZMT((T0*)C,Z1G(19," is (not) generic \?"));
ZaG((T80*)(Z4G));}void Zfq2(Zg5*C,T0*a1){Zgt(((T7*)a1),((T3)'T'));{int z1=((C)->Zih);switch(z1){case 8:Zgt(((T7*)a1),((T3)'1'));break;
case 0:case 32:Zgt(((T7*)a1),((T3)'2'));break;case 16:Zgt(((T7*)a1),((T3)'1'));Zgt(((T7*)a1),((T3)'0'));break;default:;Zgt(((T7*)a1),((T3)'1'));
Zgt(((T7*)a1),((T3)'1'));}}}void ZFo1(Zg5*C,T81 a1){(C->Zih)=ZGs(8);{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zu81(n,ZbI,a1);(C->Zfe)=((T0*)n);
}}T0*Zhq2(Zg5*C){T0*R=Zo;T0*ZKT=Zo;if((((C)->ZQc))!=((void*)(Zo))){R=((C)->ZQc);}else{ZKT=((C)->Zfe);if((ZKT)!=((void*)(Zo))){(C->ZQc)=ZLT(((T85*)ZKT));
R=((C)->ZQc);}else{{T0*b1=Z1G(27,"Cannot find Base Class for ");Zmx((T7*)(Z2G),b1);}ZMT((T0*)C,Z0O);ZaG((T80*)(Z4G));}}return R;}T0*Ziq2(T81
a1){T0*R=Zo;{Zw1*n=((Zw1*)Zh(sizeof(*n)));*n=ZQl;ZMN(n,(T11)(ZGs(0)),a1);R=((T0*)n);}return R;}void Zjq2(Zg5*C,T0*a1){Zgt(((T7*)a1),((T3)'\045'));
Zgt(((T7*)a1),((T3)'E'));Z6t(Zcq2(C),a1);Zgt(((T7*)a1),((T3)'\045'));}T6 Zkq2(Zg5*C){T6 R=0;T0*ZST=Zo;ZST=Zo;R=((T6)((ZST)!=((void*)(Zo))));
return R;}T6 Zlq2(Zg5*C,T0*a1){T6 R=0;T0*ZAs1=Zo;ZAs1=a1;if(Zo!=(ZAs1)){switch(((T0*)ZAs1)->id){case 290:break;default:ZAs1=Zo;}}if((ZAs1)!=((void*)(Zo))){
if(Zmq2(C,((((ZK1*)ZAs1))->Zbd))){R=((T6)(1));}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
}}else{R=((T6)(ZxM((T87*)(Zhq2(C)),ZsO(a1))));}return R;}T0*Znq2(Zg5*C,T0*a1){T0*R=Zo;T0*ZQ31=Zo;T81 ZjG={Zo,Zo,0};if((a1)!=((void*)(Zo))){
ZQ31=ZnH(a1);if(Zo!=(ZQ31)){switch(((T0*)ZQ31)->id){case 290:break;default:ZQ31=Zo;}}}if((T6)(((ZQ31)!=((void*)(Zo)))&&((T6)((Z9G(((((ZK1*)ZQ31))->Zbd)))==((void*)(Z8q2(C))))))){
R=ZQ31;}else{{T81 Zow;ZjG=(*(Zow=Zoq2(C),&Zow));}if((((ZjG).Zxb))==(ZGs(0))){if((a1)!=((void*)(Zo))){{T81 Zow;ZjG=(*(Zow=ZrP(a1),&Zow));
}}}{ZK1*n=((ZK1*)Zh(sizeof(*n)));*n=Zed;ZcW(n,ZjG,(T0*)C);R=((T0*)n);}}return R;}void Zpq2(T0*a1){ZdU(a1,ZeU);ZdU(a1,ZV01);ZgU(a1,((T3)'\n'));
}T6 Zmq2(Zg5*C,T0*a1){T6 R=0;T0*Zqq2=Zo;if(ZzT(a1)){Zqq2=ZnH(a1);if(Zo!=(Zqq2)){switch(((T0*)Zqq2)->id){case 292:break;default:Zqq2=Zo;
}}R=((T6)((Z3)((ZJk2(C))<=(ZJk2(((Zg5*)Zqq2))))));}else if((T6)((ZbU(a1))||((T6)(ZqT(a1))))){R=((T6)(1));}else{R=((T6)(Zlq2(C,ZnH(a1))));
}if(!(R)){ZiU((T0*)C,a1);}return R;}T0*Zrq2(Zg5*C){T0*R=Zo;{T81 Zow;if(!(((((*(Zow=Zoq2(C),&Zow))).Zxb))==(ZGs(0)))){{T81 ZH81;R=ZkU(&((*(ZH81=Zoq2(C),&ZH81))));
}}}return R;}T0*Zsq2(Zg5*C,T0*a1){T0*R=Zo;T0*ZAs1=Zo;ZAs1=a1;if(Zo!=(ZAs1)){switch(((T0*)ZAs1)->id){case 290:break;default:ZAs1=Zo;}}
if((ZAs1)!=((void*)(Zo))){if(ZJG(((((ZK1*)ZAs1))->Zbd),(T0*)C)){R=a1;}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
R=Z6q2();}}else{R=Z6q2();}return R;}T0*Ztq2(Zg5*C,T0*a1){T0*R=Zo;R=((T0*)(C));if((Zhq2(C))!=((void*)(Zo))){if((Zuq2(C))==((void*)(Zo))){
}}return R;}T0*Zvq2(Zg5*C){T0*R=Zo;T0*ZuU=Zo;ZuU=((C)->Zfe);if((ZuU)!=((void*)(Zo))){R=ZLT(((T85*)ZuU));}return R;}T0*Zuq2(Zg5*C){T0*R=Zo;
if((((C)->ZRc))!=((void*)(Zo))){R=((C)->ZRc);}else{(C->ZRc)=ZyU(((T0*)(C)));R=((C)->ZRc);}return R;}T81 Zoq2(Zg5*C){T81 R={Zo,Zo,0};R=(((T85*)(((C)->Zfe)))->ZCb);
return R;}T0*Zwq2(Zg5*C,T0*a1){T0*R=Zo;T0*Zxq2=Zo;Zxq2=ZnH(a1);if(ZzT(Zxq2)){if(Zmq2(C,Zxq2)){R=Zxq2;}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));
((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=((T0*)(C));}}else if(ZqT(Zxq2)){R=a1;}else if(ZbU(Zxq2)){R=a1;}else{R=Zsq2(C,Zxq2);}return
R;}void Zyq2(Zg5*C,T0*a1){Zmx(((T7*)a1),ZwS);Z6t(Zcq2(C),a1);Zgt(((T7*)a1),((T3)'\050'));Zgt(((T7*)a1),((T3)'\051'));}
#ifdef __cplusplus
}
#endif

