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
T44*Z1z1(void){T44*n;n=((T44*)Zh(sizeof(*n)));*n=M44;return n;}void ZW_(T44*C){Zun2(((C)->ZTh));(C->Ztc)=Zo;}void ZU_(T44*C){(C->ZSh)=((T6)(0));
if((Z3)((((C)->ZWh))>=(((C)->ZXh)))){Zzq2(C);}(C->ZQh)=(((C)->ZUh))[((C)->ZWh)];(C->ZWh)=(Z3)(((((C)->ZWh)))+(ZGs(1)));(C->ZRh)=((T6)(((C)->ZVh)));
}void Zzq2(T44*C){T3 ZAq2=0;if((Z3)((((C)->ZXh))>(ZGs(0)))){ZAq2=(((C)->ZUh))[(Z3)(((((C)->ZXh)))-(ZGs(1)))];}(C->ZXh)=ZBq2(((C)->ZUh),((C)->ZVb),((C)->ZTh));
(C->ZWh)=ZGs(0);if((Z3)((((C)->ZXh))<=(ZGs(0)))){(C->ZVh)=((T6)(1));(((C)->ZUh))[(T2)(ZGs(0))]=(ZAq2);(C->ZXh)=ZGs(1);(C->ZWh)=ZGs(1);
}}void ZCi1(T44*C){ZU_(C);while(!((T6)((((C)->ZRh))||((T6)(!(Zzs(((C)->ZQh)))))))){ZU_(C);}if(!(((C)->ZRh))){ZCq2(C);}}void Zz72(T44*C,T0*a1){
T2 Zet=0;T6 Zd22=0;T2 Z9N1=0;T2 ZEx=0;T2 ZDq2=0;ZDq2=((((T7*)a1))->Zdc);while(!(Zd22)){Zet=((C)->ZWh);while(!((T6)(((Z3)((Zet)>=(((C)->ZXh))))||((T6)(((((C)->ZUh))[Zet])==(((T3)'\n')))))))
{Zet=(Z3)(((Zet))+(ZGs(1)));}if((Z3)((Zet)>(((C)->ZWh)))){Z9N1=((((T7*)a1))->Zdc);ZEx=(Z3)((((Z3)(((Z9N1))+(Zet))))-(((C)->ZWh)));if((Z3)((((((T7*)a1))->ZVb))<(ZEx))){
Zlx(((T7*)a1),Z3t((Z3)(((Z9N1))*((T2)(ZGs(2)))),ZEx));}Zvv(((((T7*)a1))->ZUb),Z9N1,((C)->ZUh),((C)->ZWh),(Z3)(((Zet))-((T2)(ZGs(1)))));
((((T7*)(((T7*)a1))))->Zdc)=(ZEx);}if((T6)(((Z3)((Zet)<(((C)->ZXh))))&&((T6)(((((C)->ZUh))[Zet])==(((T3)'\n')))))){Zd22=((T6)(1));(C->ZWh)=(Z3)(((Zet))+(ZGs(1)));
if((T6)(((Z3)((((((T7*)a1))->Zdc))>(ZDq2)))&&((T6)((Z0x(((T7*)a1)))==(((T3)'\015')))))){ZFx(((T7*)a1),(T2)(ZGs(1)));}}else{if(!(((C)->ZVh))){
Zzq2(C);}Zd22=((T6)(((C)->ZVh)));}}(C->ZSh)=((T6)(0));(C->ZRh)=((T6)(((C)->ZVh)));}T6 ZEq2(T44*C,T0*a1){T6 R=0;T9 Z341=Zo;T9 Z441=Zo;
T2 Zet=0;Zzq2(C);Z341=((C)->ZUh);Zzq2(((T44*)a1));Z441=((((T44*)a1))->ZUh);R=((T6)(1));while(!((T6)(((T6)((!(R))||((T6)(((C)->ZVh)))))||((T6)(((((T44*)a1))->ZVh))))))
{if((((C)->ZXh))==(((((T44*)a1))->ZXh))){if(((Z341)[ZGs(0)])!=((Z441)[ZGs(0)])){R=((T6)(0));}else{(Z341)[(T2)(ZGs(0))]=(((T3)'\015'));
(Z441)[(T2)(ZGs(0))]=(((T3)'\n'));Zet=(Z3)(((((C)->ZXh)))-(ZGs(1)));while(!(((Z341)[Zet])!=((Z441)[Zet]))){Zet=(Z3)(((Zet))-(ZGs(1)));
}R=((T6)((Zet)==(ZGs(0))));}if(R){Zzq2(C);Zzq2(((T44*)a1));}}else{ZU_(C);ZU_(((T44*)a1));while(!((T6)(((T6)((!(R))||((T6)(((C)->ZRh)))))||((T6)(((((T44*)a1))->ZRh))))))
{R=((T6)((((C)->ZQh))==(((((T44*)a1))->ZQh))));ZU_(C);ZU_(((T44*)a1));}}}R=((T6)((T6)(((T6)((R)&&((T6)(((C)->ZVh)))))&&((T6)(((((T44*)a1))->ZVh))))));
ZW_(C);ZW_(((T44*)a1));return R;}void Zzv1(T44*C,T0*a1){T8 Z4W=Zo;Z4W=ZQx(((T7*)a1));(C->ZTh)=ZFq2(Z4W);if((Zo!=((C)->ZTh))){(C->ZSh)=((T6)(0));
(C->ZRh)=((T6)(0));(C->Ztc)=a1;if((((C)->ZVb))==(ZGs(0))){(C->ZUh)=((T9)(Zk(Zxt(4096),sizeof(T3))));(C->ZVb)=Zxt(4096);}(C->ZVh)=((T6)(0));
(C->ZWh)=ZGs(0);(C->ZXh)=ZGs(0);}}void Zxi1(T44*C){ZCi1(C);if(!(((C)->ZRh))){ZU_(C);}((((T7*)((T7*)(Zyi1))))->Zdc)=(ZGs(0));while(!((T6)((((C)->ZRh))||((T6)(Zzs(((C)->ZQh)))))))
{Zgt((T7*)(Zyi1),((C)->ZQh));ZU_(C);}}void Z4A1(T44*C){((((T7*)((T7*)(Zyi1))))->Zdc)=(ZGs(0));Zz72(C,Zyi1);}T0*Zyi1=Zo;void ZCq2(T44*C){
(C->ZSh)=((T6)(1));(C->ZRh)=((T6)(0));(C->ZWh)=(Z3)(((((C)->ZWh)))-(ZGs(1)));}void ZGq2(T0*a1){Zmx(((T7*)a1),ZER);Z6t(ZGs(7),a1);}void
ZHq2(T0*a1){Zmx(((T7*)a1),ZHR);Zgt(((T7*)a1),((T3)'\052'));}T0*ZIq2(ZF6*C){T0*R=Zo;ZJq2(C);return R;}T0*ZKq2(void){if(Z7P==0){Z7P=1;{
T81 Z9P={Zo,Zo,0};{Z83*n=((Z83*)Zh(sizeof(*n)));*n=Zge;Z6P=((T0*)n);ZaP(n,Z9P);}}}return Z6P;}void ZLq2(T0*a1){Zmx(((T7*)a1),ZRR);Z6t(ZGs(7),a1);
}T6 ZMq2(void){T6 R=0;return R;}void ZNq2(ZF6*C){T0*ZJH=Zo;T2 ZVR=0;T6 ZWR=0;ZJH=ZzI1(C);ZVR=((((ZZ3*)ZJH))->_id);ZWw((T7*)(ZYR),ZHR);
Zgt((T7*)(ZYR),((T3)'\040'));Zmx((T7*)(ZYR),ZZR);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z_R);ZWw((T7*)(ZKR),Z0S);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),Z1S);
Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),Z2S);ZGq2(ZKR);Zmx((T7*)(ZKR),Z3S);(((void)((Zj8*)(ZOq2()))),Z5S(ZKR,Z6S,ZzI1(C)));Zmx((T7*)(ZKR),Z7S);ZPq2(ZKR);
Zmx((T7*)(ZKR),ZCQ);ZPq2(ZKR);Zmx((T7*)(ZKR),Z9S);(((void)((Zj8*)(ZOq2()))),Z5S(ZKR,ZaS,ZzI1(C)));Zmx((T7*)(ZKR),ZbS);ZPq2(ZKR);Zmx((T7*)(ZKR),ZCQ);
ZPq2(ZKR);Zmx((T7*)(ZKR),ZcS);ZdS((Z84*)(ZkH),ZYR,ZKR);ZWw((T7*)(ZYR),ZHR);Zgt((T7*)(ZYR),((T3)'\040'));ZQq2(ZYR);Zmx((T7*)(ZYR),ZfS);
Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZgS);((((T7*)((T7*)(ZKR))))->Zdc)=(ZGs(0));ZWR=((T6)((T6)((ZhS(((ZZ3*)ZJH)))&&((T6)((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2))))))));
if(ZWR){Zmx((T7*)(ZKR),ZiS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZjS);}ZkS(((ZZ3*)ZJH),(T6)(0),ZKR);if(ZWR){Zmx((T7*)(ZKR),ZlS);}ZdS((Z84*)(ZkH),ZYR,ZKR);
ZWw((T7*)(ZYR),ZHR);Zgt((T7*)(ZYR),((T3)'\040'));ZRq2(ZYR);Zmx((T7*)(ZYR),ZnS);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZoS);((((T7*)((T7*)(ZKR))))->Zdc)=(ZGs(0));
ZpS(((ZZ3*)ZJH),ZKR);ZdS((Z84*)(ZkH),ZYR,ZKR);ZWw((T7*)(ZYR),ZqS);Z6t(ZVR,ZYR);ZWw((T7*)(ZKR),ZrS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZsS);Z6t(ZVR,ZKR);
Zmx((T7*)(ZKR),ZtS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZuS);ZvS((Z84*)(ZkH),ZYR,ZKR);((((T7*)((T7*)(ZYR))))->Zdc)=(ZGs(0));Zgt((T7*)(ZYR),((T3)'T'));
Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\052'));Zmx((T7*)(ZYR),ZwS);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZxS);ZWw((T7*)(ZKR),ZyS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZzS);
if((((Zj8*)(ZOq2()))->ZMk)){ZSq2(ZKR);Zmx((T7*)(ZKR),ZBS);}Zmx((T7*)(ZKR),ZCS);ZTq2(ZKR);Zmx((T7*)(ZKR),ZES);ZTq2(ZKR);Zmx((T7*)(ZKR),ZFS);
ZGq2(ZKR);Zmx((T7*)(ZKR),ZGS);ZPq2(ZKR);Zmx((T7*)(ZKR),ZHS);ZPq2(ZKR);Zmx((T7*)(ZKR),ZCQ);ZPq2(ZKR);Zmx((T7*)(ZKR),ZIS);ZTq2(ZKR);Zmx((T7*)(ZKR),ZJS);
ZTq2(ZKR);Zmx((T7*)(ZKR),ZKS);ZLq2(ZKR);Zmx((T7*)(ZKR),ZLS);ZGq2(ZKR);Zmx((T7*)(ZKR),ZMS);ZPq2(ZKR);Zmx((T7*)(ZKR),ZNS);ZPq2(ZKR);Zmx((T7*)(ZKR),ZCQ);
ZPq2(ZKR);Zmx((T7*)(ZKR),ZOS);ZLq2(ZKR);Zmx((T7*)(ZKR),ZPS);ZLq2(ZKR);Zmx((T7*)(ZKR),ZQS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZCQ);ZGq2(ZKR);
Zmx((T7*)(ZKR),ZRS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZSS);ZLq2(ZKR);Zmx((T7*)(ZKR),ZTS);ZTq2(ZKR);Zmx((T7*)(ZKR),ZQS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZUS);
ZGq2(ZKR);Zmx((T7*)(ZKR),ZVS);Zmx((T7*)(ZKR),ZWS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZCQ);Zmx((T7*)(ZKR),ZXS);Z6t(ZVR,ZKR);Zmx((T7*)(ZKR),ZYS);
ZdS((Z84*)(ZkH),ZYR,ZKR);}void ZUq2(ZF6*C){T0*ZJH=Zo;T2 ZVR=0;ZJH=ZzI1(C);ZVR=((((ZZ3*)ZJH))->_id);ZWw((T7*)(ZYR),Z_S);Zmx((T7*)(ZYR),Z0T);
Zgt((T7*)(ZYR),((T3)'\040'));Zgt((T7*)(ZYR),((T3)'B'));Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\040'));Zmx((T7*)(ZYR),ZyS);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),ZCQ);
Zmx((T7*)(ZYR),Z0T);Zgt((T7*)(ZYR),((T3)'\040'));Zgt((T7*)(ZYR),((T3)'B'));Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z1T);Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z2T);
Z6t(ZVR,ZYR);Zmx((T7*)(ZYR),Z3T);ZgM((Z84*)(ZkH),ZYR);ZWw((T7*)(ZYR),ZyS);Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\052'));ZGq2(ZYR);ZvS((Z84*)(ZkH),ZYR,Z4T);
ZWw((T7*)(ZYR),Z5T);Zgt((T7*)(ZYR),((T3)'\040'));ZTq2(ZYR);Z6T((Z84*)(ZkH),ZYR,((T3)'0'));ZWw((T7*)(ZYR),Z7T);ZLq2(ZYR);ZvS((Z84*)(ZkH),ZYR,Z4T);
ZWw((T7*)(ZYR),ZyS);Z6t(ZVR,ZYR);Zgt((T7*)(ZYR),((T3)'\052'));ZPq2(ZYR);ZvS((Z84*)(ZkH),ZYR,Z4T);if((((Zj8*)(ZOq2()))->ZMk)){ZWw((T7*)(ZYR),Z5T);
Zgt((T7*)(ZYR),((T3)'\040'));ZSq2(ZYR);Z6T((Z84*)(ZkH),ZYR,((T3)'0'));}}T6 ZVq2(ZF6*C){T6 R=0;T0*Z9T=Zo;Z9T=Zo;R=((T6)((Z9T)!=((void*)(Zo))));
return R;}void ZQq2(T0*a1){Zmx(((T7*)a1),ZaT);Z6t(ZGs(7),a1);}T6 ZWq2(ZF6*C){T6 R=0;T0*ZjL=Zo;ZjL=((T0*)(C));if((C)==((void*)(ZjL))){
if((ZnH(ZjL))==((void*)(ZjL))){R=((T6)((ZcT(ZjL))==((void*)(Z9G(ZjL)))));}}return R;}T2 ZXq2(void){T2 R=0;T8 Z4W=Zo;R=sizeof(T8);return
R;}void ZYq2(T0*a1){Zmx(((T7*)a1),ZjT);ZSq2(a1);Zmx(((T7*)a1),ZkT);Zmx(((T7*)a1),(ZvI));Zmx(((T7*)a1),ZlT);ZSq2(a1);Zgt(((T7*)a1),((T3)'\054'));
ZTq2(a1);Zmx(((T7*)a1),ZmT);}void ZJq2(ZF6*C){ZMT((T0*)C,Z1G(19," is (not) generic \?"));ZaG((T80*)(Z4G));}T0*ZZq2(void){if(ZEI1==0){ZEI1=1;{
T81 Z9P={Zo,Zo,0};{ZF6*n=((ZF6*)Zh(sizeof(*n)));*n=Zgj;ZDI1=((T0*)n);ZFI1(n,Z9P);}}}return ZDI1;}void ZFI1(ZF6*C,T81 a1){{T85*n=((T85*)Zh(sizeof(*n)));
*n=M85;Zu81(n,ZvI,a1);(C->Zfe)=((T0*)n);}}void Z_q2(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}T0*ZOq2(void){if(ZNM==0){ZNM=1;{
{Zj8*n=((Zj8*)Zh(sizeof(*n)));*n=ZOk;ZMM=((T0*)n);}}}return ZMM;}int Z0r2=0;void Zr12(void){if(Z0r2==0){Z0r2=1;{T0*ZkL=Zo;T0*ZJH=Zo;T0*ZiL=Zo;
ZkL=Z1r2((ZF6*)(ZZq2()));ZJH=ZzI1((ZF6*)(ZZq2()));ZCP(((ZZ3*)ZJH));ZiL=ZZa1(((ZZ3*)ZJH),ZcJ);ZiL=ZZa1(((ZZ3*)ZJH),ZfJ);ZiL=ZZa1(((ZZ3*)ZJH),ZxK);
ZCP((ZZ3*)(Z_G(ZiH(ZiL))));}}}T0*Z2r2(T81 a1){T0*R=Zo;{Zz4*n=((Zz4*)Zh(sizeof(*n)));*n=ZAg;((((Zz4*)(n)))->ZCb)=(a1);R=((T0*)n);}return
R;}T0*Z1r2(ZF6*C){T0*R=Zo;T0*ZKT=Zo;if((((C)->ZQc))!=((void*)(Zo))){R=((C)->ZQc);}else{ZKT=((C)->Zfe);if((ZKT)!=((void*)(Zo))){(C->ZQc)=ZLT(((T85*)ZKT));
R=((C)->ZQc);}else{{T0*b1=Z1G(27,"Cannot find Base Class for ");Zmx((T7*)(Z2G),b1);}ZMT((T0*)C,Z0O);ZaG((T80*)(Z4G));}}return R;}void
Z3r2(T0*a1){Zgt(((T7*)a1),((T3)'\045'));Zgt(((T7*)a1),((T3)'R'));Z6t(ZGs(7),a1);Zgt(((T7*)a1),((T3)'\045'));}T6 Z4r2(ZF6*C){T6 R=0;T0*ZST=Zo;
ZST=Zo;R=((T6)((ZST)!=((void*)(Zo))));return R;}void ZPq2(T0*a1){Zmx(((T7*)a1),ZUT);Z6t(ZGs(7),a1);}void ZRq2(T0*a1){Zmx(((T7*)a1),Z_T);
Z6t(ZGs(7),a1);}void Z5r2(ZF6*C){T0*Z2U=Zo;T2 Zet=0;T2 ZuT=0;T0*ZKO=Zo;T0*ZxH=Zo;ZuT=ZGs(7);Z2U=Z3U((ZZ3*)(ZzI1(C)));ZWw((T7*)(ZvT),Z0T);
Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'S'));Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\173'));if(ZhS((ZZ3*)(ZzI1(C)))){Zmx((T7*)(ZvT),ZlW);
}if((Z2U)!=((void*)(Zo))){Zet=((((ZV8*)Z2U))->ZWb);while(!((Zet)==(ZGs(0)))){ZKO=ZUy(((ZV8*)Z2U),Zet);ZxH=ZnH(((((ZE7*)ZKO))->Zlc));ZmW(ZxH,ZvT);
Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'\137'));Zmx((T7*)(ZvT),(((ZD8*)(((((ZE7*)ZKO))->Zpc)))->Zse));Zgt((T7*)(ZvT),((T3)'\073'));
Zet=(Z3)(((Zet))-(ZGs(1)));}}Zgt((T7*)(ZvT),((T3)'\175'));Zmx((T7*)(ZvT),ZCQ);ZgM((Z84*)(ZkH),ZvT);}void Z6r2(T0*a1){ZdU(a1,ZeU);ZdU(a1,ZfU);
ZgU(a1,((T3)'\n'));}T6 Z7r2(ZF6*C,T0*a1){T6 R=0;if(Z3L(a1)){R=((T6)((Z1r2(C))==((void*)(ZsO(a1)))));}if(!(R)){if(ZwU(a1)){R=((T6)(1));
}else{R=((T6)(ZxM((T87*)(Z1r2(C)),ZsO(a1))));}}if(!(R)){ZiU((T0*)C,a1);}return R;}T0*Z8r2(ZF6*C){T0*R=Zo;{T81 Zow;if(!(((((*(Zow=Z9r2(C),&Zow))).Zxb))==(ZGs(0)))){
{T81 ZH81;R=ZkU(&((*(ZH81=Z9r2(C),&ZH81))));}}}return R;}void Zar2(ZF6*C){T2 ZuT=0;T0*ZJH=Zo;ZJH=ZzI1(C);ZuT=((((ZZ3*)ZJH))->_id);((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));
Zgt((T7*)(ZvT),((T3)'T'));Z6t(ZuT,ZvT);Zgt((T7*)(ZvT),((T3)'\040'));Zgt((T7*)(ZvT),((T3)'M'));Z6t(ZuT,ZvT);ZWT((Z84*)(ZkH),ZvT);ZXT((Z84*)(ZkH));
((((T7*)((T7*)(ZvT))))->Zdc)=(ZGs(0));ZwW(((ZZ3*)ZJH),ZvT);Zmx((T7*)(ZvT),ZCQ);ZgM((Z84*)(ZkH),ZvT);ZZT((Z84*)(ZkH));}T0*Zbr2(ZF6*C){
T0*R=Zo;T0*ZuU=Zo;ZuU=((C)->Zfe);if((ZuU)!=((void*)(Zo))){R=ZLT(((T85*)ZuU));}return R;}void ZTq2(T0*a1){Zmx(((T7*)a1),ZxU);Z6t(ZGs(7),a1);
}T0*ZzI1(ZF6*C){T0*R=Zo;if((((C)->ZRc))!=((void*)(Zo))){R=((C)->ZRc);}else{(C->ZRc)=ZyU(((T0*)(C)));R=((C)->ZRc);}return R;}void Zcr2(ZF6*C){
Z5r2(C);Zar2(C);}T81 Z9r2(ZF6*C){T81 R={Zo,Zo,0};R=(((T85*)(((C)->Zfe)))->ZCb);return R;}void Zdr2(T0*a1){ZPq2(a1);Zgt(((T7*)a1),((T3)'\075'));
Zmx(((T7*)a1),Z4T);Zmx(((T7*)a1),ZCQ);}T0*Zer2(ZF6*C,T0*a1){T0*R=Zo;T0*Zvg1=Zo;T0*ZkL=Zo;T0*ZtL=Zo;Zvg1=ZnH(a1);if(ZwU(Zvg1)){R=((T0*)(C));
}else if(ZsT(Zvg1)){R=((T0*)(C));}else if(ZOR(Zvg1)){R=Zvg1;}else if(ZqU(Zvg1)){R=ZDU(Zvg1,(T0*)C);}else{ZkL=Z1r2(C);ZtL=ZsO(Zvg1);if(ZxM(((T87*)ZtL),ZkL)){
R=((T0*)(C));}else if(ZxM(((T87*)ZkL),ZtL)){R=Zvg1;}else{R=ZKq2();}}return R;}void ZSq2(T0*a1){Zmx(((T7*)a1),ZEU);Z6t(ZGs(7),a1);}void
Zfr2(T0*a1){Zmx(((T7*)a1),ZwS);Z6t(ZGs(7),a1);Zgt(((T7*)a1),((T3)'\050'));Zgt(((T7*)a1),((T3)'\051'));}Zh8*Zgr2(T81 a1){Zh8*n;n=((Zh8*)Zh(sizeof(*n)));
*n=ZKk;ZD31(n,a1);return n;}T0*Zhr2(Zh8*C){T0*R=Zo;Zir2(C);return R;}T0*Zjr2(void){if(Z7P==0){Z7P=1;{T81 Z9P={Zo,Zo,0};{Z83*n=((Z83*)Zh(sizeof(*n)));
*n=Zge;Z6P=((T0*)n);ZaP(n,Z9P);}}}return Z6P;}T2 Zkr2(void){T2 R=0;R=sizeof(T6);return R;}T6 Zlr2(void){T6 R=0;return R;}T6 Zmr2(Zh8*C){
T6 R=0;T0*Z9T=Zo;Z9T=Zo;R=((T6)((Z9T)!=((void*)(Zo))));return R;}void Znr2(T0*a1){Zmx(((T7*)a1),ZaT);Z6t(ZGs(6),a1);}T6 Zor2(Zh8*C){T6
R=0;T0*ZjL=Zo;ZjL=((T0*)(C));if((C)==((void*)(ZjL))){if((ZnH(ZjL))==((void*)(ZjL))){R=((T6)((ZcT(ZjL))==((void*)(Z9G(ZjL)))));}}return
R;}void Zir2(Zh8*C){ZMT((T0*)C,Z1G(19," is (not) generic \?"));ZaG((T80*)(Z4G));}void Zpr2(T0*a1){Zgt(((T7*)a1),((T3)'T'));Zgt(((T7*)a1),((T3)'6'));
}void ZD31(Zh8*C,T81 a1){{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zu81(n,Z_H,a1);(C->Zfe)=((T0*)n);}}T0*Zqr2(Zh8*C){T0*R=Zo;T0*ZKT=Zo;if((((C)->ZQc))!=((void*)(Zo))){
R=((C)->ZQc);}else{ZKT=((C)->Zfe);if((ZKT)!=((void*)(Zo))){(C->ZQc)=ZLT(((T85*)ZKT));R=((C)->ZQc);}else{{T0*b1=Z1G(27,"Cannot find Base Class for ");
Zmx((T7*)(Z2G),b1);}ZMT((T0*)C,Z0O);ZaG((T80*)(Z4G));}}return R;}T0*Zrr2(T81 a1){T0*R=Zo;{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zml;ZwL(n,a1);
R=((T0*)n);}return R;}void Zsr2(T0*a1){Zgt(((T7*)a1),((T3)'\045'));Zgt(((T7*)a1),((T3)'E'));Z6t(ZGs(6),a1);Zgt(((T7*)a1),((T3)'\045'));
}int Ztr2=0;void Zur2(Zh8*C){if(Ztr2==0){Ztr2=1;{if((Zqr2(C))!=((void*)(Zo))){if((Zvr2(C))==((void*)(Zo))){}}}}}T6 Zwr2(Zh8*C){T6 R=0;
T0*ZST=Zo;ZST=Zo;R=((T6)((ZST)!=((void*)(Zo))));return R;}T6 Zxr2(Zh8*C,T0*a1){T6 R=0;T0*ZAs1=Zo;ZAs1=a1;if(Zo!=(ZAs1)){switch(((T0*)ZAs1)->id){
case 290:break;default:ZAs1=Zo;}}if((ZAs1)!=((void*)(Zo))){if(Zyr2(C,((((ZK1*)ZAs1))->Zbd))){R=((T6)(1));}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));
((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));}}else{R=((T6)(ZxM((T87*)(Zqr2(C)),ZsO(a1))));}return R;}T0*Zzr2(Zh8*C,T0*a1){T0*R=Zo;T0*ZQ31=Zo;
T81 ZjG={Zo,Zo,0};if((a1)!=((void*)(Zo))){ZQ31=ZnH(a1);if(Zo!=(ZQ31)){switch(((T0*)ZQ31)->id){case 290:break;default:ZQ31=Zo;}}}if((T6)(((ZQ31)!=((void*)(Zo)))&&((T6)((Z9G(((((ZK1*)ZQ31))->Zbd)))==((void*)(Z_H)))))){
R=ZQ31;}else{{T81 Zow;ZjG=(*(Zow=ZAr2(C),&Zow));}if((((ZjG).Zxb))==(ZGs(0))){if((a1)!=((void*)(Zo))){{T81 Zow;ZjG=(*(Zow=ZrP(a1),&Zow));
}}}{ZK1*n=((ZK1*)Zh(sizeof(*n)));*n=Zed;ZcW(n,ZjG,(T0*)C);R=((T0*)n);}}return R;}void ZBr2(T0*a1){ZdU(a1,ZeU);ZdU(a1,ZV01);ZgU(a1,((T3)'\n'));
}T6 Zyr2(Zh8*C,T0*a1){T6 R=0;if(ZmU(a1)){R=((T6)(1));}else{R=((T6)(Zxr2(C,ZnH(a1))));}if(!(R)){ZiU((T0*)C,a1);}return R;}T0*ZCr2(Zh8*C){
T0*R=Zo;{T81 Zow;if(!(((((*(Zow=ZAr2(C),&Zow))).Zxb))==(ZGs(0)))){{T81 ZH81;R=ZkU(&((*(ZH81=ZAr2(C),&ZH81))));}}}return R;}T0*ZDr2(Zh8*C,T0*a1){
T0*R=Zo;T0*ZAs1=Zo;ZAs1=a1;if(Zo!=(ZAs1)){switch(((T0*)ZAs1)->id){case 290:break;default:ZAs1=Zo;}}if((ZAs1)!=((void*)(Zo))){if(ZJG(((((ZK1*)ZAs1))->Zbd),(T0*)C)){
R=a1;}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=Zjr2();}}else{R=Zjr2();}return R;}T0*ZEr2(Zh8*C,T0*a1){
T0*R=Zo;R=((T0*)(C));Zur2(C);return R;}T0*ZFr2(Zh8*C){T0*R=Zo;T0*ZuU=Zo;ZuU=((C)->Zfe);if((ZuU)!=((void*)(Zo))){R=ZLT(((T85*)ZuU));}return
R;}T0*Zvr2(Zh8*C){T0*R=Zo;if((((C)->ZRc))!=((void*)(Zo))){R=((C)->ZRc);}else{(C->ZRc)=ZyU(((T0*)(C)));R=((C)->ZRc);}return R;}T81 ZAr2(Zh8*C){
T81 R={Zo,Zo,0};R=(((T85*)(((C)->Zfe)))->ZCb);return R;}T0*ZGr2(Zh8*C,T0*a1){T0*R=Zo;T0*Zvg1=Zo;Zvg1=ZnH(a1);if(ZmU(Zvg1)){R=((T0*)(C));
}else{R=ZDr2(C,Zvg1);}return R;}void ZHr2(T0*a1){Zmx(((T7*)a1),ZwS);Z6t(ZGs(6),a1);Zgt(((T7*)a1),((T3)'\050'));Zgt(((T7*)a1),((T3)'\051'));
}T6 ZIr2(T81*C){T6 R=0;T0*ZkL=Zo;ZkL=((*C).Zvb);if((ZkL)!=((void*)(Zo))){R=((T6)(((((T87*)ZkL))->Zqg)));}return R;}T10 ZJr2(T81*C){T10
R=0;if(ZZs(((*C).Zxb),ZGs(0))){R=(ZXo1)(((Z8)(((*C).Zxb))>>(ZGs(17))));}else{R=(ZXo1)(((Z8)(((*C).Zxb))>>(ZGs(21))));}return R;}T0*ZKr2(T0*a1,T2
a2){T0*R=Zo;T2 Zet=0;ZR_((T38*)(ZLr2()),ZYh1,a1);if(((((T44*)(ZYh1))->Ztc))!=(Zo)){while(!((T6)(((((T44*)(ZYh1))->ZRh))||((T6)((Zet)==(a2))))))
{Z4A1((T44*)(ZYh1));Zet=(Z3)(((Zet))+(ZGs(1)));}if(!((((T44*)(ZYh1))->ZRh))){R=Zyi1;}ZW_((T44*)(ZYh1));}return R;}void ZMr2(T81*C){T2
ZNr2=0;T2 ZOr2=0;T2 ZPr2=0;T0*ZkL=Zo;T0*ZKT=Zo;T0*ZIX=Zo;T0*ZQr2=Zo;T0*ZRr2=Zo;T10 ZSr2=0;ZNr2=Zrd1(C);ZOr2=Zsd1(C);ZkL=((*C).Zvb);if((ZkL)!=((void*)(Zo))){
ZKT=ZkU(C);}if((ZKT)!=((void*)(Zo))){ZIX=((((T85*)ZKT))->Zse);ZQr2=((((T87*)ZkL))->Ztc);}if((ZQr2)==((void*)(Zo))){ZSr2=ZJr2(C);{int z1=ZSr2;
switch(z1){case 32767:ZQr2=(((T89*)(ZPM))->Z1f);break;case 32766:ZQr2=(((T56*)(ZtA1))->Z1f);break;case 32765:ZQr2=((*C).Zwb);break;default:;
ZQr2=(((void)((T42*)(ZTr2()))),ZZ_(ZSr2));}}}(((void)((T38*)(ZLr2()))),Zzi1(Z1G(5,"Line ")));(((void)((T38*)(ZLr2()))),ZYv1(ZNr2));if((Z3)((ZOr2)>(ZGs(0)))){
(((void)((T38*)(ZLr2()))),Zzi1(Z1G(8,ZKo)));(((void)((T38*)(ZLr2()))),ZYv1(ZOr2));}(((void)((T38*)(ZLr2()))),Zzi1(Z1G(4,ZFo)));if((ZIX)!=((void*)(Zo))){
(((void)((T38*)(ZLr2()))),Zzi1(ZIX));}if((ZQr2)!=((void*)(Zo))){(((void)((T38*)(ZLr2()))),Zzi1(Z1G(2,ZCn)));(((void)((T38*)(ZLr2()))),Zzi1(ZQr2));
(((void)((T38*)(ZLr2()))),Zuv1(((T3)'\051')));}(((void)((T38*)(ZLr2()))),Zzi1(Z1G(3," :\n")));if((ZQr2)!=((void*)(Zo))){ZRr2=ZKr2(ZQr2,ZNr2);
if((T6)(((Z3)((ZNr2)>(ZGs(0))))&&((T6)((ZRr2)!=((void*)(Zo)))))){(((void)((T38*)(ZLr2()))),Zzi1(ZRr2));(((void)((T38*)(ZLr2()))),Zuv1(((T3)'\n')));
if((Z3)((ZOr2)>(ZGs(0)))){ZPr2=ZGs(1);while(!((Z3)((ZPr2)>=(ZOr2)))){if(((((((T7*)ZRr2))->ZUb))[(ZPr2)-(ZGs(1))])==(((T3)'\011'))){(((void)((T38*)(ZLr2()))),Zuv1(((T3)'\011')));
}else{(((void)((T38*)(ZLr2()))),Zuv1(((T3)'\040')));}ZPr2=(Z3)(((ZPr2))+(ZGs(1)));}(((void)((T38*)(ZLr2()))),Zzi1(Z1G(2,"^\n")));}}}}
T0*ZkU(T81*C){T0*R=Zo;T0*ZkL=Zo;ZkL=((*C).Zvb);if((ZkL)!=((void*)(Zo))){R=((((T87*)ZkL))->Zpc);}return R;}T0*ZLr2(void){if(ZeP==0){ZeP=1;{
{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}T0*Zl02(T81*C){T0*R=Zo;T0*ZkL=Zo;T10 ZSr2=0;ZkL=((*C).Zvb);if((ZkL)!=((void*)(Zo))){
R=((((T87*)ZkL))->Ztc);}else{ZSr2=ZJr2(C);{int z1=ZSr2;switch(z1){case 32767:R=(((T89*)(ZPM))->Z1f);break;case 32766:R=(((T56*)(ZtA1))->Z1f);
break;default:;R=(((void)((T42*)(ZTr2()))),ZZ_(ZSr2));}}}return R;}void Z3m1(T81*C,T2 a1,T2 a2,T10 a3,T0*a4){(C->Zvb)=a4;if((T6)(((T6)(((Z2)((a3)<=(Zxt(2047))))&&((T6)((Z3)((a1)<=(Zxt(8191)))))))&&((T6)((Z3)((a2)<=(ZGs(127))))))){
(C->Zxb)=(T2)(((a3)<<(ZGs(21))));(C->Zxb)=(((*C).Zxb)|((a1)<<(ZGs(8))));(C->Zxb)=(((*C).Zxb)|((a2)<<(ZGs(1))));}else{(C->Zxb)=(T2)(((a3)<<(ZGs(17))));
(C->Zxb)=(((*C).Zxb)|((a1)<<(ZGs(1))));(C->Zxb)=(((*C).Zxb)|ZGs(1));}}T6 ZHr1(T81*C,T81 a1){T6 R=0;T2 ZNr2=0;T2 ZUr2=0;ZNr2=Zrd1(C);ZUr2=Zrd1(&a1);
if((Z3)((ZNr2)<(ZUr2))){R=((T6)(1));}else if((ZNr2)==(ZUr2)){R=((T6)((Z3)((Zsd1(C))<(Zsd1(&a1)))));}return R;}T0*ZTr2(void){if(ZJn1==0){ZJn1=1;{
{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;ZIn1=((T0*)n);ZK_(n);}}}return ZIn1;}T2 Zrd1(T81*C){T2 R=0;if(ZZs(((*C).Zxb),ZGs(0))){R=((((*C).Zxb))>>(ZGs(1)));
R=(R&Zct(65535));}else{R=((((*C).Zxb))>>(ZGs(8)));R=(R&Zct(8191));}return R;}T2 Zsd1(T81*C){T2 R=0;if(ZZs(((*C).Zxb),ZGs(0))){}else{R=((((*C).Zxb))>>(ZGs(1)));
R=(R&Zct(127));}return R;}void Zmv1(T0*a1,T0*a2){T8 ZBo2=Zo;T8 ZCo2=Zo;if(Zfv1(a2)){Ziv1(a2);}ZBo2=ZQx(((T7*)a1));ZCo2=ZQx(((T7*)a2));
ZVr2(ZBo2,ZCo2);}T0*ZWr2=Zo;T0*ZXr2=Zo;T6 ZYr2(T0*a1,T0*a2){T6 R=0;Zzv1((T44*)(ZWr2),a1);if(((((T44*)(ZWr2))->Ztc))!=(Zo)){Zzv1((T44*)(ZXr2),a2);
if(((((T44*)(ZXr2))->Ztc))!=(Zo)){R=((T6)(ZEq2((T44*)(ZWr2),ZXr2)));}else{ZW_((T44*)(ZWr2));}}return R;}void Ziv1(T0*a1){T8 Z4W=Zo;Z4W=ZQx(((T7*)a1));
ZZr2(Z4W);}T6 Zfv1(T0*a1){T6 R=0;Zzv1((T44*)(ZWr2),a1);R=((T6)(((((T44*)(ZWr2))->Ztc))!=(Zo)));if(R){ZW_((T44*)(ZWr2));}return R;}T0*Z_r2(T0*a1){
T0*R=Zo;R=Z0s2;((((T7*)(((T7*)R))))->Zdc)=(ZGs(0));Zmx(((T7*)R),Z1s2);ZFt((((T87*)(((((ZX4*)a1))->Zvb)))->_id),R);Zmx(((T7*)R),(((ZD8*)(((((Zz8*)(((((ZX4*)a1))->Zkc))))->ZGd)))->Zcn));
R=(((void)((T27*)(Z2s2()))),ZCG(R));return R;}T0*ZOq1(T0*a1){T0*R=Zo;R=Z3s2;((((T7*)(((T7*)R))))->Zdc)=(ZGs(0));Zmx(((T7*)R),Z4s2);ZFt((((T87*)(((((ZX4*)a1))->Zvb)))->_id),R);
Zmx(((T7*)R),(((ZD8*)(((((Zz8*)(((((ZX4*)a1))->Zkc))))->ZGd)))->Zcn));R=(((void)((T27*)(Z2s2()))),ZCG(R));return R;}T0*Z5s2=Zo;int Z6s2=0;
T0*Z7s2(void){if(Z6s2==0){Z6s2=1;{{Z58*n=((Z58*)Zh(sizeof(*n)));*n=ZEk;Z5s2=((T0*)n);ZkE(n,(T2)(ZGs(32)));}}}return Z5s2;}T0*Z0s2=Zo;
T0*Z8s2=Zo;T0*Z9s2(T0*a1){T0*R=Zo;T2 Zet=0;T0*ZiL=Zo;Zet=ZGs(0);while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((Zet)>((((Z58*)(Z7s2()))->ZWb))))))))
{ZiL=((((Z58*)(Z7s2()))->ZUb))[Zet];if((T6)((((((ZD8*)(((((ZQ7*)ZiL))->Zpc)))->Zse))==((void*)(a1)))&&((T6)(((((T85*)((((T87*)((((ZX4*)(Z0X(ZiL)))->Zvb)))->Zpc)))->Zse))==((void*)(Z9I)))))){
R=ZiL;}Zet=(Z3)(((Zet))+(ZGs(1)));}return R;}T0*Zas2=Zo;void ZaJ1(T0*a1){T2 Zet=0;T0*ZiL=Zo;T0*Zbs2=Zo;T0*Zcs2=Zo;T0*ZjL=Zo;T0*ZMQ1=Zo;
if((Z3)(((Z3)((((((Z58*)(Z7s2()))->ZWb)))+(ZGs(1))))>(ZGs(0)))){Zet=(((Z58*)(Z7s2()))->ZWb);{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Zad;Z8A(n,(Z3)((Zet)/((T2)(ZGs(2)))));
Zcs2=((T0*)n);}while(!((Z3)((Zet)<(ZGs(0))))){ZiL=((((Z58*)(Z7s2()))->ZUb))[Zet];Zbs2=Z0X(ZiL);if(Zo!=(Zbs2)){switch(((T0*)Zbs2)->id){
case 425:break;default:Zbs2=Zo;}}if(!(Z5A(((ZE1*)Zcs2),Zbs2))){if((((ZZ3*)(Z_G(((((ZQ7*)ZiL))->Z4c))))->Zrh)){Z7A(((ZE1*)Zcs2),Zbs2);
ZjL=ZiH(ZiL);if(Zt01(ZjL)){ZMQ1=ZOq1(Zbs2);(((void)((Zj8*)(Zds2()))),Zwr1(a1,ZMQ1,Z_G(ZjL)));}}}Zet=(Z3)(((Zet))-(ZGs(1)));}}}void Zes2(T0*a1,T0*a2){
T0*Zfs2=Zo;T0*Zgs2=Zo;T0*ZkY=Zo;if((Zhs2(a1))!=((void*)(Zo))){ZfM((ZL*)(Zhs2(a1)));}Zfs2=ZiH(a1);if(ZX01(Zfs2)){ZkY=Zg_((ZZ3*)(Z_G(Zfs2)));
if((ZkY)!=((void*)(Zo))){ZD61((Z84*)(ZkH),ZkY,Zo,ZOq1(Z0X(a1)));}}Zgs2=Zaf1(a1);if((Zgs2)!=((void*)(Zo))){ZdL((Z84*)(ZkH),((T3)'\173'));
Z391(((Ze3*)Zgs2),(T6)(0));}if((ZNr1(a1))!=((void*)(Zo))){ZHW((ZX6*)(ZNr1(a1)));}if((Zis2(a1))!=((void*)(Zo))){ZmS1((Z11*)(Zis2(a1)));
}if((Zgs2)!=((void*)(Zo))){ZdL((Z84*)(ZkH),((T3)'\175'));}}void ZsR1(T0*a1){T0*Zf_=Zo;T0*Zjs2=Zo;T0*ZMQ1=Zo;T0*ZjL=Zo;if((T6)((!((((T43*)(ZSG))->ZXk)))||((T6)(Z3L(ZiH(a1)))))){
Zf_=Z0X(a1);Zjs2=((((ZX4*)Zf_))->Zvb);ZMQ1=ZOq1(Zf_);if(!(Ztm1(((T87*)Zjs2),ZMQ1))){((((T7*)((T7*)(Zas2))))->Zdc)=(ZGs(0));ZjL=ZiH(a1);
if(Z3L(ZjL)){Zgt((T7*)(Zas2),((T3)'s'));}Zgt((T7*)(Zas2),((T3)'T'));if(ZqU(ZjL)){Z6t(ZEM(ZjL),Zas2);Zgt((T7*)(Zas2),((T3)'\040'));}else{
Zgt((T7*)(Zas2),((T3)'0'));Zgt((T7*)(Zas2),((T3)'\052'));}Zmx((T7*)(Zas2),ZMQ1);((((T7*)((T7*)(Z8s2))))->Zdc)=(ZGs(0));Z001(ZjL,Z8s2);
ZvS((Z84*)(ZkH),Zas2,Z8s2);}}}void Zk_1(T0*a1){T0*Z8L=Zo;T0*ZjL=Zo;if((T6)((!((((T43*)(ZSG))->ZXk)))||((T6)(Z3L(ZiH(a1)))))){Z8L=Z_r2(Z0X(a1));
ZgM((Z84*)(ZkH),Zks2);ZgM((Z84*)(ZkH),Z8L);ZgM((Z84*)(ZkH),Zls2);}else{ZjL=ZiH(a1);((((T7*)((T7*)(Zas2))))->Zdc)=(ZGs(0));Zgt((T7*)(Zas2),((T3)'T'));
if(ZqU(ZjL)){Z6t(ZEM(ZjL),Zas2);}else{Zgt((T7*)(Zas2),((T3)'0'));Zgt((T7*)(Zas2),((T3)'\052'));}Z8L=ZOq1(Z0X(a1));ZgM((Z84*)(ZkH),Zas2);
ZdL((Z84*)(ZkH),((T3)'\040'));ZgM((Z84*)(ZkH),Z8L);if(!(ZqU(ZjL))){ZgM((Z84*)(ZkH),Zms2);}ZgM((Z84*)(ZkH),ZCQ);ZgM((Z84*)(ZkH),Zns2);
ZgM((Z84*)(ZkH),Z8L);ZgM((Z84*)(ZkH),Zos2);}}T0*Zps2(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return
ZdP;}T0*Zds2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));*n=ZOk;ZMM=((T0*)n);}}}return ZMM;}T0*Z2s2(void){if(ZTH==0){ZTH=1;{
{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);
ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);
ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);
ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);
ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);
ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);
ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);
ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);
ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);
ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);
ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);
ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);
ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);
ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}void
ZuR1(T0*a1){T0*Z8L=Zo;T0*ZjL=Zo;if((T6)((!((((T43*)(ZSG))->ZXk)))||((T6)(Z3L(ZiH(a1)))))){Z8L=Z_r2(Z0X(a1));ZgM((Z84*)(ZkH),Zqs2);ZgM((Z84*)(ZkH),Z8L);
ZgM((Z84*)(ZkH),Zrs2);ZgM((Z84*)(ZkH),Z8L);ZgM((Z84*)(ZkH),Zss2);}else{ZjL=ZiH(a1);((((T7*)((T7*)(Zas2))))->Zdc)=(ZGs(0));Zgt((T7*)(Zas2),((T3)'T'));
if(ZqU(ZjL)){Z6t(ZEM(ZjL),Zas2);}else{Zgt((T7*)(Zas2),((T3)'0'));Zgt((T7*)(Zas2),((T3)'\052'));}Z8L=ZOq1(Z0X(a1));ZgM((Z84*)(ZkH),Zas2);
ZdL((Z84*)(ZkH),((T3)'\040'));ZgM((Z84*)(ZkH),Z8L);if(!(ZqU(ZjL))){ZgM((Z84*)(ZkH),Zts2);}ZgM((Z84*)(ZkH),ZCQ);ZgM((Z84*)(ZkH),Zus2);
ZgM((Z84*)(ZkH),Z8L);ZgM((Z84*)(ZkH),Zvs2);}}T0*Z3s2=Zo;T6 ZkR1(T0*a1){T6 R=0;if(!((((T43*)(ZSG))->ZXk))){if(Z3z((T79*)(Zws2()),(((ZD8*)(((((Zz8*)(((((Zc7*)a1))->Zkc))))->ZGd)))->Zse))){
R=((T6)(1));}else if(ZPP1(((Zc7*)a1))){R=((T6)(1));}}return R;}void ZwR1(T0*a1){T0*ZMQ1=Zo;T0*ZjL=Zo;ZMQ1=ZOq1(Z0X(a1));if((T6)(((((T43*)(ZSG))->ZXk))&&((T6)(!(Z3L(ZiH(a1))))))){
ZjL=ZiH(a1);if(ZqU(ZjL)){ZgM((Z84*)(ZkH),Zfo1);ZgM((Z84*)(ZkH),Zas2);ZdL((Z84*)(ZkH),((T3)'\052'));ZgM((Z84*)(ZkH),Zxs2);ZgM((Z84*)(ZkH),ZMQ1);
ZgM((Z84*)(ZkH),Zys2);ZgM((Z84*)(ZkH),Zas2);ZgM((Z84*)(ZkH),Zzs2);ZgM((Z84*)(ZkH),ZMQ1);ZgM((Z84*)(ZkH),ZAs2);ZgM((Z84*)(ZkH),Zas2);ZgM((Z84*)(ZkH),ZBs2);
}ZgM((Z84*)(ZkH),ZCs2);ZgM((Z84*)(ZkH),ZMQ1);ZgM((Z84*)(ZkH),ZDs2);if(ZqU(ZjL)){ZgM((Z84*)(ZkH),ZEs2);}ZgM((Z84*)(ZkH),ZMQ1);ZgM((Z84*)(ZkH),ZFs2);
if(ZqU(ZjL)){ZgM((Z84*)(ZkH),ZmM);}ZgM((Z84*)(ZkH),ZGs2);ZgM((Z84*)(ZkH),ZMQ1);ZdL((Z84*)(ZkH),((T3)'\075'));if(ZqU(ZjL)){ZdL((Z84*)(ZkH),((T3)'\052'));
}ZdL((Z84*)(ZkH),((T3)'\050'));ZgM((Z84*)(ZkH),Zas2);if(ZqU(ZjL)){ZdL((Z84*)(ZkH),((T3)'\052'));}ZgM((Z84*)(ZkH),ZHs2);ZgM((Z84*)(ZkH),ZMQ1);
ZgM((Z84*)(ZkH),ZIs2);}else{ZgM((Z84*)(ZkH),ZJs2);}ZgM((Z84*)(ZkH),ZKs2);ZgM((Z84*)(ZkH),ZMQ1);ZgM((Z84*)(ZkH),ZLs2);}T0*ZMs2=Zo;int ZNs2=0;
T0*Z6T1(void){if(ZNs2==0){ZNs2=1;{{Z58*n=((Z58*)Zh(sizeof(*n)));*n=ZEk;ZMs2=((T0*)n);ZkE(n,(T2)(ZGs(32)));}}}return ZMs2;}void ZPR1(Zb2*C,T0*a1){
T0*ZJH=Zo;ZiE((Z58*)(Z7s2()),a1);if(((((ZD8*)(((((ZQ7*)a1))->Zpc)))->Zse))==((void*)(ZwK))){if((((C)->Zyd))==((void*)(Zo))){if(((((T85*)((((T87*)((((ZX4*)(Z0X(a1)))->Zvb)))->Zpc)))->Zse))==((void*)(Z9I))){
ZJH=Z_G(ZiH(a1));(C->Zyd)=ZZa1(((ZZ3*)ZJH),ZDJ);}}}}void ZtR1(T0*a1){T0*Zf_=Zo;T0*Zjs2=Zo;T0*Z8L=Zo;if((T6)((!((((T43*)(ZSG))->ZXk)))||((T6)(Z3L(ZiH(a1)))))){
Zf_=Z0X(a1);Zjs2=((((ZX4*)Zf_))->Zvb);Z8L=Z_r2(Zf_);if(!(Ztm1(((T87*)Zjs2),Z8L))){ZWw((T7*)(Zas2),ZOs2);Zmx((T7*)(Zas2),Z8L);Z6T((Z84*)(ZkH),Zas2,((T3)'0'));
}}}T0*ZPs2=Zo;int ZQs2=0;T0*Zws2(void){if(ZQs2==0){ZQs2=1;{ZPs2=ZPz1(4,ZuK,ZvK,ZJJ,ZwK);}}return ZPs2;}T2 Zlz(T2 a1){T2 R=0;if((Z3)((a1)<=(ZGs(53)))){
R=ZGs(53);}else if((Z3)((a1)<=(ZGs(97)))){R=ZGs(97);}else if((Z3)((a1)<=(Zxt(193)))){R=Zxt(193);}else if((Z3)((a1)<=(Zxt(389)))){R=Zxt(389);
}else if((Z3)((a1)<=(Zxt(769)))){R=Zxt(769);}else if((Z3)((a1)<=(Zxt(1543)))){R=Zxt(1543);}else if((Z3)((a1)<=(Zxt(3079)))){R=Zxt(3079);
}else if((Z3)((a1)<=(Zxt(6151)))){R=Zxt(6151);}else if((Z3)((a1)<=(Zxt(12289)))){R=Zxt(12289);}else if((Z3)((a1)<=(Zxt(24593)))){R=Zxt(24593);
}else if((Z3)((a1)<=(Zct(49157)))){R=Zct(49157);}else if((Z3)((a1)<=(Zct(98317)))){R=Zct(98317);}else if((Z3)((a1)<=(Zct(196613)))){R=Zct(196613);
}else if((Z3)((a1)<=(Zct(393241)))){R=Zct(393241);}else if((Z3)((a1)<=(Zct(786433)))){R=Zct(786433);}else if((Z3)((a1)<=(Zct(1572869)))){
R=Zct(1572869);}else if((Z3)((a1)<=(Zct(3145739)))){R=Zct(3145739);}else if((Z3)((a1)<=(Zct(6291469)))){R=Zct(6291469);}else if((Z3)((a1)<=(Zct(12582917)))){
R=Zct(12582917);}else if((Z3)((a1)<=(Zct(25165843)))){R=Zct(25165843);}else if((Z3)((a1)<=(Zct(50331653)))){R=Zct(50331653);}else if((Z3)((a1)<=(Zct(100663319)))){
R=Zct(100663319);}else if((Z3)((a1)<=(Zct(201326611)))){R=Zct(201326611);}else if((Z3)((a1)<=(Zct(402653189)))){R=Zct(402653189);}else
if((Z3)((a1)<=(Zct(805306457)))){R=Zct(805306457);}else{R=Zct(1610612741);}return R;}T0*ZRs2=Zo;int ZSs2=0;T0*ZTs2(void){if(ZSs2==0){ZSs2=1;{
{Z27*n=((Z27*)Zh(sizeof(*n)));*n=ZCj;ZRs2=((T0*)n);{Z27*C1=n;ZFD(C1,ZGs(53));}}}}return ZRs2;}void ZUs2(T0*a1,T0*a2){Zmx(((T7*)a1),ZVs2);
Zmx(((T7*)a1),a2);Zmx(((T7*)a1),ZWs2);}T0*ZXs2=Zo;int ZYs2=0;T0*ZZs2(void){if(ZYs2==0){ZYs2=1;{{ZG9*n=((ZG9*)Zh(sizeof(*n)));*n=Zfm;ZXs2=((T0*)n);
{ZG9*C1=n;ZhF(C1,ZGs(53));}}}}return ZXs2;}void Z_s2(ZG3*C){T2 Zet=0;if((((C)->ZIe))!=((void*)(Zo))){Zet=ZGs(1);while(!((Z3)((Zet)>((((ZN*)(((C)->ZIe)))->Zdc)))))
{{ZV6*C1=(ZV6*)(Zez((ZN*)(((C)->ZIe)),Zet));ZhP(((C1)->Z3c));}Zet=(Z3)(((Zet))+(ZGs(1)));}}}void Z0t2(ZG3*C){T2 Zet=0;T6 Z6_=0;T0*Z1t2=Zo;
Z6_=((T6)(((((T89*)(ZPM))->Zaf))==(ZGs(1))));if((((C)->ZIe))!=((void*)(Zo))){ZgM((Z84*)(ZkH),Z2t2);if(!(Z6_)){ZgM((Z84*)(ZkH),Z3t2);}
ZgM((Z84*)(ZkH),Z4t2);Zet=ZGs(1);while(!((Z3)((Zet)>((((ZN*)(((C)->ZIe)))->Zdc))))){ZAM1((ZV6*)(Zez((ZN*)(((C)->ZIe)),Zet)),(T6)(Z6_));
Zet=(Z3)(((Zet))+(ZGs(1)));}ZgM((Z84*)(ZkH),Z5t2);Zet=ZGs(1);while(!((Z3)((Zet)>((((ZN*)(((C)->ZIe)))->Zdc))))){ZyM1((ZV6*)(Zez((ZN*)(((C)->ZIe)),Zet)));
Zet=(Z3)(((Zet))+(ZGs(1)));}ZgM((Z84*)(ZkH),Z6t2);ZVd1((Z84*)(ZkH),Z7t2);ZXT((Z84*)(ZkH));ZPv1((T38*)(Z8t2()),Z9t2,(((ZN*)(((C)->ZIe)))->Zdc));
Zet=ZGs(1);while(!((Z3)((Zet)>((((ZN*)(((C)->ZIe)))->Zdc))))){Z3M1((ZV6*)(Zez((ZN*)(((C)->ZIe)),Zet)),(T6)(Z6_));Zet=(Z3)(((Zet))+(ZGs(1)));
}ZPv1((T38*)(Z8t2()),Zat2,(((Z27*)(ZTs2()))->Zdc));Zet=ZGs(1);while(!((Z3)((Zet)>((((Z27*)(ZTs2()))->Zdc))))){Z1t2=ZzD((Z27*)(ZTs2()),Zet);
ZgF((ZG9*)(ZZs2()),((((Zu9*)Z1t2))->Zuk));ZTf2(((Zu9*)Z1t2));Zet=(Z3)(((Zet))+(ZGs(1)));}ZZT((Z84*)(ZkH));}}T0*Z8t2(void){if(ZeP==0){ZeP=1;{
{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}void ZDJ1(ZG3*C,T0*a1){if((((C)->ZIe))!=((void*)(Zo))){Zmx(((T7*)a1),Zbt2);
}}void ZFf2(T0*a1,T81 a2){if(!(ZfF((ZG9*)(ZZs2()),((((Zu9*)a1))->Zuk)))){Z5G(a2);{T0*b1=Z1G(53,"There is no such agent ever defined in the live code.");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));ZCD((Z27*)(Zct2()),a1);}}void ZXf2(ZG3*C,T0*a1,T0*a2,T0*a3){T2 Zet=0;T2 Zdt2=0;T2 Zet2=0;T2 Zft2=0;
T2 ZN_=0;T0*Zgt2=Zo;T0*ZST=Zo;T0*Zht2=Zo;T0*Zit2=Zo;T0*Zjt2=Zo;T0*Zkt2=Zo;T0*Zlt2=Zo;T6 Zmt2=0;if((((C)->ZIe))!=((void*)(Zo))){Zet=ZGs(1);
Zht2=((((Z1a*)a2))->Zsj);Zkt2=((((Z1a*)a2))->ZYj);Zet2=ZAf1(((Zw7*)Zkt2));Zgt(((T7*)a1),((T3)'\n'));while(!((Z3)((Zet)>((((ZN*)(((C)->ZIe)))->Zdc)))))
{Zgt2=Zez((ZN*)(((C)->ZIe)),Zet);ZST=((((ZV6*)Zgt2))->Zlc);ZN_=((((ZV6*)Zgt2))->Zrj);Zmt2=((T6)(0));Zlt2=((((Z1a*)ZST))->ZYj);Zft2=ZAf1(((Zw7*)Zlt2));
if((Z3)((Zet2)>=(Zft2))){Zmt2=((T6)(1));Zdt2=Zft2;while(!((T6)((!(Zmt2))||((T6)((Z3)((Zdt2)<=(ZGs(0)))))))){Zit2=ZSf1(((Zw7*)Zkt2),Zdt2);
Zjt2=ZSf1(((Zw7*)Zlt2),Zdt2);if(ZbL(Zit2)){Zmt2=((T6)(ZbL(Zjt2)));}else if(ZJG(Zit2,Zjt2)){Zmt2=((T6)((Z9G(Zit2))==((void*)(Z9G(Zjt2)))));
}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));Zmt2=((T6)(0));}Zdt2=(Z3)(((Zdt2))-(ZGs(1)));}
}if((T6)((Zmt2)&&((T6)((a3)!=((void*)(Zo)))))){Zmt2=((T6)((((((Z1a*)ZST))->Z_j))!=((void*)(Zo))));}if(Zmt2){Zmx(((T7*)a1),Znt2);Z6t(ZN_,a1);
ZUs2(a1,Zot2(ZST));Zmx(((T7*)a1),Zpt2);if((a3)!=((void*)(Zo))){Zmx(((T7*)a1),Zqt2);ZmW(a3,a1);Zmx(((T7*)a1),ZfY1);}Zmx(((T7*)a1),Zrt2);
Z6t(ZN_,a1);Zmx(((T7*)a1),Zst2);if(!(((((T89*)(ZPM))->Zaf))==(ZGs(1)))){Zmx(((T7*)a1),Ztt2);}Zmx(((T7*)a1),Zut2);Zdt2=ZGs(1);while(!((Z3)((Zdt2)>(Zft2))))
{Zgt(((T7*)a1),((T3)'\054'));Zgt(((T7*)a1),((T3)'a'));Z6t(Zdt2,a1);Zdt2=(Z3)(((Zdt2))+(ZGs(1)));}Zgt(((T7*)a1),((T3)'\051'));if((a3)!=((void*)(Zo))){
Zgt(((T7*)a1),((T3)'\051'));}else{Zmx(((T7*)a1),Zvt2);}Zmx(((T7*)a1),Zwt2);}else{ZUs2(a1,Zot2(ZST));Zgt(((T7*)a1),((T3)'\n'));}Zet=(Z3)(((Zet))+(ZGs(1)));
}}}T0*Zxt2=Zo;int Zyt2=0;T0*Zct2(void){if(Zyt2==0){Zyt2=1;{{Z27*n=((Z27*)Zh(sizeof(*n)));*n=ZCj;Zxt2=((T0*)n);{Z27*C1=n;ZFD(C1,ZGs(53));
}}}}return Zxt2;}T2 Z1N1(ZG3*C,T0*a1){T2 R=0;T0*Zzt2=Zo;if((((C)->ZIe))==((void*)(Zo))){{ZN*n=((ZN*)Zh(sizeof(*n)));*n=Zec;{ZN*C1=n;Zsz(C1,ZGs(53));
}(C->ZIe)=((T0*)n);}}Zzt2=Ztz((ZN*)(((C)->ZIe)),a1);if((Zzt2)==((void*)(Zo))){Znz((ZN*)(((C)->ZIe)),a1);R=(((ZN*)(((C)->ZIe)))->Zdc);
}else{R=((((ZV6*)Zzt2))->Zrj);}return R;}T0*ZtR(T0*a1,T0*a2){T0*R=Zo;T0*ZST=Zo;ZST=((((ZQ7*)a2))->Z4c);if(Zo!=(ZST)){switch(((T0*)ZST)->id){
case 296:case 298:break;default:ZST=Zo;}}{Zu9*n=((Zu9*)Zh(sizeof(*n)));*n=Z9m;ZQf2(n,ZST,a1,ZiH(a2));R=((T0*)n);}ZCD((Z27*)(ZTs2()),R);
return R;}void ZAt2(ZG3*C){if((((C)->ZIe))!=((void*)(Zo))){ZgM((Z84*)(ZkH),ZBt2);}}void ZCt2(T0*a1,T0*a2,T2 a3){T0*ZDt2=Zo;T0*Z831=Zo;
T0*ZdH1=Zo;T6 ZEt2=0;ZDt2=ZAP(a1);Z831=ZnH(Z8a1(((Zz6*)ZDt2),a3));ZdH1=ZnH(Z8a1(((Zz6*)a2),a3));if(Z3L(ZdH1)){ZEt2=((T6)(!(Z3L(Z831))));
}else if(ZbL(Z831)){ZEt2=((T6)(ZqU(ZdH1)));}else{ZEt2=((T6)(ZbL(ZdH1)));}if(ZEt2){Zfe1(Z831,ZdH1);}ZdL((Z84*)(ZkH),((T3)'a'));ZDM((Z84*)(ZkH),(T11)(a3));
if(ZEt2){ZdL((Z84*)(ZkH),((T3)'\051'));}}void ZFt2(T0*a1,T0*a2,T2 a3,T2 a4){T2 ZoU=0;T0*ZJV1=Zo;T0*ZKV1=Zo;if((a3)==(a4)){ZJV1=(((((Ze7*)(((((Z23*)a2))->Zae))))->ZUb))[(a3)-(ZGs(1))];
ZKV1=ZIL(((ZZ3*)ZJV1),a1);ZGt2((Z84*)(ZkH),ZKV1,a1);}else{ZoU=(Z3)(((Z3)(((a3))+(a4)))/(ZGs(2)));ZJV1=(((((Ze7*)(((((Z23*)a2))->Zae))))->ZUb))[(ZoU)-(ZGs(1))];
ZgM((Z84*)(ZkH),ZHt2);ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)ZJV1))->_id)));ZgM((Z84*)(ZkH),ZMj2);ZFt2(a1,a2,a3,ZoU);ZgM((Z84*)(ZkH),ZIt2);ZFt2(a1,a2,(Z3)(((ZoU))+((T2)(ZGs(1)))),a4);
ZdL((Z84*)(ZkH),((T3)'\175'));}}void ZJt2(T0*a1,T0*a2){T2 Zet=0;T0*ZJV1=Zo;T0*ZKV1=Zo;ZgM((Z84*)(ZkH),ZKt2);Zet=ZGs(1);while(!((Z3)((Zet)>((Z3)(((((((Ze7*)(((((Z23*)a2))->Zae))))->ZWb)))+(ZGs(1)))))))
{ZJV1=(((((Ze7*)(((((Z23*)a2))->Zae))))->ZUb))[(Zet)-(ZGs(1))];ZKV1=ZIL(((ZZ3*)ZJV1),a1);ZgM((Z84*)(ZkH),ZLt2);ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)ZJV1))->_id)));
ZdL((Z84*)(ZkH),((T3)'\072'));ZGt2((Z84*)(ZkH),ZKV1,a1);ZgM((Z84*)(ZkH),ZMt2);Zet=(Z3)(((Zet))+(ZGs(1)));}if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
ZgM((Z84*)(ZkH),ZNt2);}ZgM((Z84*)(ZkH),ZmM);}T0*ZOt2(T0*a1){T0*R=Zo;((((T7*)((T7*)(ZPt2))))->Zdc)=(ZGs(0));Zgt((T7*)(ZPt2),((T3)'X'));
Z6t((((ZZ3*)(((((ZQ7*)a1))->Znf)))->_id),ZPt2);Zmx((T7*)(ZPt2),(((ZD8*)(((((ZQ7*)a1))->Zpc)))->Zcn));R=ZPt2;return R;}T0*ZPt2=Zo;void
ZQt2(T0*a1){T6 Z6_=0;T0*ZRt2=Zo;T0*ZEQ1=Zo;T0*Zfs2=Zo;T0*ZSt2=Zo;T2 Zet=0;T0*Z5O=Zo;T0*ZdH=Zo;Z6_=((T6)(((((T89*)(ZPM))->Zaf))==(ZGs(1))));
ZRt2=ZAP(a1);Zfs2=ZiH(a1);((((T7*)((T7*)(ZPt2))))->Zdc)=(ZGs(0));if((Zfs2)==((void*)(Zo))){Zmx((T7*)(ZPt2),ZHR);}else{Zfs2=ZnH(Zfs2);
ZmW(Zfs2,ZPt2);}Zgt((T7*)(ZPt2),((T3)'\040'));Zgt((T7*)(ZPt2),((T3)'X'));Z6t(ZEM(((((ZQ7*)a1))->Z4c)),ZPt2);{ZD8*C1=(ZD8*)(((((ZQ7*)a1))->Zpc));
T0*b1=ZPt2;Zmx(((T7*)b1),((C1)->Zcn));}if(Z6_){Zmx((T7*)(ZPt2),ZTt2);}else{Zmx((T7*)(ZPt2),ZUt2);}if((ZRt2)!=((void*)(Zo))){Zet=ZGs(1);
while(!((Z3)((Zet)>(Zjy(((Zl2*)(((((Zz6*)ZRt2))->Zie)))))))){Zgt((T7*)(ZPt2),((T3)'\054'));ZSt2=ZnH(Z8a1(((Zz6*)ZRt2),Zet));Zw01(ZSt2,ZPt2);
Zmx((T7*)(ZPt2),ZVt2);Z6t(Zet,ZPt2);Zet=(Z3)(((Zet))+(ZGs(1)));}}Zgt((T7*)(ZPt2),((T3)'\051'));ZIM((Z84*)(ZkH),ZPt2);ZXT((Z84*)(ZkH));
if((T6)(((((T43*)(ZSG))->ZXk))&&((T6)(Z3L(((((ZQ7*)a1))->Z4c)))))){ZgM((Z84*)(ZkH),ZWt2);}if((Zfs2)!=((void*)(Zo))){((((T7*)((T7*)(ZPt2))))->Zdc)=(ZGs(0));
ZmW(Zfs2,ZPt2);Zgt((T7*)(ZPt2),((T3)'\040'));Zgt((T7*)(ZPt2),((T3)'R'));if(!(Z6_)){Zgt((T7*)(ZPt2),((T3)'\075'));Z001(Zfs2,ZPt2);}Zmx((T7*)(ZPt2),ZCQ);
ZgM((Z84*)(ZkH),ZPt2);}if(!(Z6_)){ZgM((Z84*)(ZkH),ZXt2);Z5O=((((ZQ7*)a1))->Zpc);ZEQ1=ZFQ1(((ZD8*)Z5O));if((ZEQ1)!=((void*)(Zo))){ZgM((Z84*)(ZkH),ZEQ1);
ZdL((Z84*)(ZkH),((T3)'\040'));}ZgM((Z84*)(ZkH),((((ZD8*)Z5O))->Zse));ZdL((Z84*)(ZkH),((T3)'\042'));ZgM((Z84*)(ZkH),ZYt2);}ZgM((Z84*)(ZkH),ZZt2);
ZdH=(((ZZ3*)(((((ZQ7*)a1))->Znf)))->Zof);if(Z6_){ZgM((Z84*)(ZkH),Z_t2);}else{ZgM((Z84*)(ZkH),Z0u2);}if(!(Z6_)){Z1u2(a1,Z2u2,ZmI1);}if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(7)))){
ZJt2(a1,ZdH);}else{ZFt2(a1,ZdH,(T2)(ZGs(1)),(Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))));}ZgM((Z84*)(ZkH),ZmM);if(!(Z6_)){
Z1u2(a1,ZhS1,ZqI1);}if((Zfs2)!=((void*)(Zo))){ZgM((Z84*)(ZkH),ZxR1);}else{ZgM((Z84*)(ZkH),ZmM);}}void ZRe1(T0*a1){T0*ZiL=Zo;ZiL=((((ZG1*)a1))->Z3c);
if(!(ZgE((Z58*)(Z3u2()),ZiL))){ZiE((Z58*)(Z3u2()),ZiL);ZoA((ZB2*)(Z4u2()),a1);}}T0*Z5u2=Zo;int Z6u2=0;T0*Z4u2(void){if(Z6u2==0){Z6u2=1;{
{ZB2*n=((ZB2*)Zh(sizeof(*n)));*n=ZRd;Z5u2=((T0*)n);ZpA(n,(T2)(ZGs(64)));}}}return Z5u2;}T0*Z7u2=Zo;int Z8u2=0;T0*Z3u2(void){if(Z8u2==0){Z8u2=1;{
{Z58*n=((Z58*)Zh(sizeof(*n)));*n=ZEk;Z7u2=((T0*)n);ZkE(n,(T2)(ZGs(64)));}}}return Z7u2;}T0*Z9u2=Zo;int Zau2=0;T0*Zbu2(void){if(Zau2==0){Zau2=1;{
{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;Z9u2=((T0*)n);ZSz(n,(T2)(ZGs(1)));}}}return Z9u2;}void Zcu2(T89*C,T0*a1){T6 Zd22=0;T6 Zdu2=0;if(Zeu2(C,ZR22)){
Zfu2(C,Z1G(40,"The \"use\" clause is not yet implemented."));}if(Zeu2(C,Zgu2)){while(!((((C)->_cc))!=(((T3)'\042')))){ZZh1(((T90*)a1),Zhu2(C));
if(Ziu2(C,((T3)'\073'))){}}}if(Zeu2(C,Zju2)){while(!((((C)->_cc))!=(((T3)'\042')))){ZWh1(((T90*)a1),Zhu2(C));if(Ziu2(C,((T3)'\073'))){
}}}if(Zeu2(C,Zku2)){Zfu2(C,Z1G(42,"The \"adapt\" clause is not yet implemented."));}if(Zeu2(C,Zlu2)){while(!(Zd22)){if(Zeu2(C,Zmu2)){
((((T90*)(((T90*)a1))))->Zaf)=(Znu2(C));}else if(Zeu2(C,Zou2)){Zdu2=((T6)(Zpu2(C)));(C->Zgf)=((T6)((T6)((((C)->Zgf))||((T6)(Zdu2)))));
ZTi1(((T90*)a1),(T6)(Zdu2));}else if(Zeu2(C,ZOi1)){Zii1(((T90*)a1),Zqu2(C));}else{Zd22=((T6)(1));}if(Ziu2(C,((T3)'\073'))){}}}if(Zeu2(C,Zru2)){
while(!(!(Zsu2(C,a1)))){}}}void Ztu2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}T0*Zuu2(T89*C){T0*R=Zo;T6 Zd22=0;
T81 Z4W={Zo,Zo,0};T0*Zvu2=Zo;T0*ZUs=Zo;T0*ZWl1=Zo;T2 ZXw=0;T2 Z7Q=0;R=Zwu2;((((T7*)(((T7*)R))))->Zdc)=(ZGs(0));if(Ziu2(C,((T3)'\042'))){
{T81 Zow;Z4W=(*(Zow=Zxu2(((C)->Z_e),((C)->Z0f)),&Zow));}while(!(Zd22)){{int z1=((C)->_cc);switch(z1){case 34:Zd22=((T6)(1));break;case
0:Z5G(Z4W);{T0*b1=Z1G(20,"Closing \" not found.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));break;case 36:Z7Q=((C)->ZWe);ZXw=((C)->ZVe);ZWl1=((C)->ZXe);
Zyu2(C);if((((C)->_cc))==(((T3)'\173'))){Zyu2(C);{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zwx(n,(T2)(ZGs(12)));Zvu2=((T0*)n);}}else{Zgt(((T7*)R),((T3)'\044'));
(C->ZWe)=Z7Q;(C->ZVe)=ZXw;(C->ZXe)=ZWl1;}while(!((Zvu2)==((void*)(Zo)))){{int z2=((C)->_cc);switch(z2){case 125:ZUs=(((void)((T38*)(Zzu2()))),ZAv1(Zvu2,((C)->Z1f)));
if((ZUs)!=((void*)(Zo))){Zmx(((T7*)R),ZUs);}Zvu2=Zo;break;case 0:Z5G(Z4W);{T0*b1=Z1G(50,"Bad Environment variable.\n(Closing \"\175""\" not found.)");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));break;default:;Zgt(((T7*)Zvu2),((C)->_cc));Zyu2(C);}}}break;default:;Zgt(((T7*)R),((C)->_cc));}}
Zyu2(C);}}else{while(!(Zd22)){{int z1=((C)->_cc);switch(z1){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case
57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case
81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 95:case 97:case 98:case 99:case 100:case 101:case 102:
case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:
case 118:case 119:case 120:case 121:case 122:Zgt(((T7*)R),((C)->_cc));Zyu2(C);break;default:;Zd22=((T6)(1));}}}}if((((((T7*)R))->Zdc))==(ZGs(0))){
Zfu2(C,Z1G(29,"Non empty name expected here."));}ZAu2(C);return R;}void ZBu2(T89*C){if(Ziu2(C,((T3)'\050'))){if((Zhu2(C))!=((void*)(Zo))){
}if(Ziu2(C,((T3)'\051'))){}}}void ZCu2(T89*C,T0*a1){if((ZIx1())==((void*)(Zo))){(((void)((T38*)(Zzu2()))),Zzi1(a1));(((void)((T38*)(Zzu2()))),Zzi1(Z1G(42,": error: No <Root-Class> in command line.\n")));
Zv(ZGs(1));}if((T6)((ZDu2(C))&&((T6)((((C)->Zaf))==(ZGs(1)))))){(((void)((T38*)(Zzu2()))),Zzi1(a1));(((void)((T38*)(Zzu2()))),Zzi1(Z1G(37,": cannot use -sedb with -boost flag.\n")));
Zv(ZGs(1));}ZMC1((T51*)(ZEu2()));ZFu2(C);}void ZGu2(T89*C){T2 Zet=0;if((((C)->Z1f))!=((void*)(Zo))){Zet=ZGs(0);while(!((Z3)((Zet)>((((Z05*)(ZXz1()))->ZWb)))))
{Z1i1((T90*)(((((Z05*)(ZXz1()))->ZUb))[Zet]));Zet=(Z3)(((Zet))+(ZGs(1)));}}}T0*ZHu2(T0*a1,T6 a2){T0*R=Zo;{T90*n=((T90*)Zh(sizeof(*n)));
*n=M90;Z9i1(n,a1,(T6)(a2));R=((T0*)n);}Z9C((Z05*)(ZXz1()),R);return R;}T6 Zpu2(T89*C){T6 R=0;if(!(Ziu2(C,((T3)'\050')))){{T89*C1=C;T0*b1=ZIu2;
{T81 Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}if(Zeu2(C,ZIi1)){}else if((T6)((Zeu2(C,ZNi1))||((T6)(Zeu2(C,ZQi1))))){R=((T6)(1));}else{Zfu2(C,Z1G(77,"At this point in the ACE file, you are supposed to say \"yes\", \"no\", or \"all\"."));
}if(!(Ziu2(C,((T3)'\051')))){{T89*C1=C;T0*b1=ZKu2;{T81 Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}return R;}T0*ZLu2=Zo;T0*Zwu2=Zo;T6 Zsu2(T89*C,T0*a1){
T6 R=0;T2 ZMu2=0;T0*ZNu2=Zo;T0*ZOu2=Zo;if(Zeu2(C,Zmu2)){R=((T6)(1));ZMu2=Znu2(C);if(!(Ziu2(C,((T3)'\072')))){{T89*C1=C;T0*b1=ZPu2;{T81
Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}while(!(!(ZQu2(C)))){ZNu2=ZAZ(&(((C)->ZEd)));ZRi1(((T90*)a1),ZNu2,ZMu2);if(Ziu2(C,((T3)'\054'))){
}}}else if(Zeu2(C,Zou2)){(C->Zgf)=((T6)(1));R=((T6)(1));if(!(Ziu2(C,((T3)'\072')))){{T89*C1=C;T0*b1=ZPu2;{T81 Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);
}}}while(!(!(ZQu2(C)))){ZNu2=ZAZ(&(((C)->ZEd)));ZUi1(((T90*)a1),ZNu2);if(Ziu2(C,((T3)'\054'))){}}}else if(Zeu2(C,ZOi1)){R=((T6)(1));ZOu2=Zqu2(C);
if(!(Ziu2(C,((T3)'\072')))){{T89*C1=C;T0*b1=ZPu2;{T81 Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}while(!(!(ZQu2(C)))){ZNu2=ZAZ(&(((C)->ZEd)));
ZXi1(((T90*)a1),ZNu2,ZOu2);if(Ziu2(C,((T3)'\054'))){}}}return R;}void ZRu2(T89*C){T0*ZSu2=Zo;ZSu2=ZTu2;ZWw(((T7*)ZSu2),ZUu2(((C)->Z8f)));
if(!(Z5v(((T7*)ZSu2),ZHi1))){Zmx(((T7*)ZSu2),ZVu2);}ZiD1((T51*)(ZEu2()),ZSu2);}T0*ZEu2(void){if(ZE_==0){ZE_=1;{{T51*n=((T51*)Zh(sizeof(*n)));
*n=M51;ZD_=((T0*)n);ZG_(n);}}}return ZD_;}void ZWu2(T0*a1){T2 Zet=0;T3 ZXw=0;ZWw((T7*)(ZXu2),a1);Zet=(((T7*)(ZXu2))->Zdc);if((Z3)((Zet)>(ZGs(2)))){
if((((((T7*)(ZXu2))->ZUb))[((Z3)(((Zet))-(ZGs(1))))-(ZGs(1))])==(((T3)'\056'))){if(ZIs(((((T7*)(ZXu2))->ZUb))[(Zet)-(ZGs(1))],((T3)'e'))){
ZFx((T7*)(ZXu2),(T2)(ZGs(2)));}}}Zet=(((T7*)(ZXu2))->Zdc);while(!((Zet)==(ZGs(0)))){ZXw=((((T7*)(ZXu2))->ZUb))[(Zet)-(ZGs(1))];if(ZHs(ZXw)){
Zet=(Z3)(((Zet))-(ZGs(1)));}else if((ZXw)==(((T3)'\137'))){Zet=(Z3)(((Zet))-(ZGs(1)));}else if(Zys(ZXw)){Zet=(Z3)(((Zet))-(ZGs(1)));}
else{ZZw((T7*)(ZXu2),Zet);Zet=ZGs(0);}}ZPx((T7*)(ZXu2));}T6 ZYu2(T89*C){T6 R=0;T0*ZZu2=Zo;T0*Z_u2=Zo;if((((C)->_cc))==(((T3)'\000'))){
}else if(Zeu2(C,Z0v2)){Z1v2(C);}else if(Zeu2(C,Z2v2)){Z3v2(C);}else if(Zeu2(C,Z4v2)){}else if((((C)->_cc))==(((T3)'\042'))){R=((T6)(1));
Z_u2=ZHu2(Zuu2(C),(T6)(0));Zcu2(C,Z_u2);}else if(ZHs(((C)->_cc))){R=((T6)(1));ZZu2=Zhu2(C);if(Ziu2(C,((T3)'\072'))){if((((C)->_cc))==(((T3)'\042'))){
Z_u2=ZHu2(Zuu2(C),(T6)(0));((((T90*)(((T90*)Z_u2))))->Zpc)=(ZZu2);}else{{T81 Zow;Z5G((*(Zow=ZJu2(C),&Zow)));}{T0*b1=Z1G(41,"Cluster path expected after cluster name.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}else{Z_u2=ZHu2(ZZu2,(T6)(0));}Zcu2(C,Z_u2);}else{Z5v2(C,Z6v2);}return R;}void ZDC1(T0*a1){T0*Z7v2=Zo;
ZWu2(a1);Z7v2=Z7t((T7*)(ZXu2));Z7v2=(((void)((T27*)(Z8v2()))),ZCG(Z7v2));ZQz((T55*)(Zbu2()),Z7v2);}T6 ZqN1(T89*C,T0*a1){T6 R=0;T0*ZpN1=Zo;
T0*Z_u2=Zo;ZpN1=((((((ZM1*)a1))->ZCb)).Zvb);Z_u2=((((T87*)ZpN1))->Zbg);if((Z_u2)!=((void*)(Zo))){R=((T6)(Zei1(((T90*)Z_u2),((((T87*)ZpN1))->Zpc),a1)));
}else{R=((T6)(Zgi1(C,a1)));}if(R){if((((C)->Zaf))==(ZGs(1))){(C->Zaf)=ZGs(2);}}return R;}void Z5v2(T89*C,T0*a1){{T81 Zow;Z5G((*(Zow=ZJu2(C),&Zow)));
}{T0*b1=Z1G(14,"Error in the \"");Zmx((T7*)(Z2G),b1);}{T0*b1=a1;Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(10,"\" section.");Zmx((T7*)(Z2G),b1);}
ZaG((T80*)(Z4G));}void Zfu2(T89*C,T0*a1){{T81 Zow;Z5G((*(Zow=ZJu2(C),&Zow)));}{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}T0*Zhu2(T89*C){
T0*R=Zo;R=(((void)((T27*)(Z8v2()))),ZCG(Zuu2(C)));return R;}T0*Z9v2(void){if(Zli1==0){Zli1=1;{{T77*n=((T77*)Zh(sizeof(*n)));*n=M77;Zki1=((T0*)n);
Zni1(n);}}}return Zki1;}T2 Z0m1(T89*C,T0*a1){T2 R=0;T0*Z_u2=Zo;Z_u2=((((T87*)a1))->Zbg);if((Z_u2)!=((void*)(Zo))){R=Zji1(((T90*)Z_u2),((((T87*)a1))->Zpc));
}else{R=((C)->Zaf);}return R;}void Zav2(T89*C){if((((C)->Zaf))==(ZGs(0))){(C->Zaf)=ZGs(7);}Zbv2(C,((C)->Zaf));ZRu2(C);}void Zcv2(T89*C){
T2 Zet=0;if(!(((C)->Zff))){(C->Zff)=((T6)(1));Zet=ZGs(0);while(!((Z3)((Zet)>((((Z05*)(ZXz1()))->ZWb))))){Zqi1((T90*)(((((Z05*)(ZXz1()))->ZUb))[Zet]));
Zet=(Z3)(((Zet))+(ZGs(1)));}}}T6 Ziu2(T89*C,T3 a1){T6 R=0;if((a1)==(((C)->_cc))){(C->Z_e)=((C)->ZWe);(C->Z0f)=((C)->ZVe);R=((T6)(1));
Zyu2(C);ZAu2(C);}return R;}T6 Zeu2(T89*C,T0*a1){T6 R=0;T2 ZXw=0;T2 Zet=0;T2 Z3x=0;T6 Zdv2=0;Zet=((C)->ZVe);ZXw=((((T7*)a1))->Zdc);if((Z3)(((Z3)((((Z3)((((((T7*)(((C)->ZXe)))->Zdc)))-(Zet))))+(ZGs(1))))>=(ZXw))){
(C->Z_e)=((C)->ZWe);(C->Z0f)=Zet;Z3x=ZGs(1);while(!((Z3)((ZXw)<=(ZGs(0))))){if((((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))])==((((((T7*)a1))->ZUb))[(Z3x)-(ZGs(1))])){
Zet=(Z3)(((Zet))+(ZGs(1)));Z3x=(Z3)(((Z3x))+(ZGs(1)));ZXw=(Z3)(((ZXw))-(ZGs(1)));}else if(ZIs(((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))],(((((T7*)a1))->ZUb))[(Z3x)-(ZGs(1))])){
Zet=(Z3)(((Zet))+(ZGs(1)));Z3x=(Z3)(((Z3x))+(ZGs(1)));ZXw=(Z3)(((ZXw))-(ZGs(1)));Zdv2=((T6)(1));}else{ZXw=ZGs(-1);}}}if((ZXw)==(ZGs(0))){
if((Z3)((Zet)>((((T7*)(((C)->ZXe)))->Zdc)))){R=((T6)(1));(C->_cc)=((T3)'\n');(C->ZVe)=Zet;ZAu2(C);}else{{int z1=((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))];
switch(z1){case 9:case 32:case 45:R=((T6)(1));(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))];(C->ZVe)=Zet;ZAu2(C);break;case 48:
case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:
case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:
case 90:case 95:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case
110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:break;default:;R=((T6)(1));
(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))];(C->ZVe)=Zet;}}}}if(Zus((T6)(Zus((T6)(R),(T6)(Zdv2))),(T6)((a1)!=((void*)(ZKV))))){
{T81 Zow;Z5G((*(Zow=Zxu2(((C)->Z_e),((C)->Z0f)),&Zow)));}{T0*b1=Zev2;Zmx((T7*)(Z2G),b1);}{T0*b1=a1;Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(1,"\'");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}return R;}T81 ZJu2(T89*C){T81 R={Zo,Zo,0};{T81 Zow;R=(*(Zow=Zxu2(((C)->ZWe),((C)->ZVe)),&Zow));
}return R;}T0*Zfv2(void){if(ZNM==0){ZNM=1;{{Zj8*n=((Zj8*)Zh(sizeof(*n)));*n=ZOk;ZMM=((T0*)n);}}}return ZMM;}T0*Zzu2(void){if(ZeP==0){ZeP=1;{
{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}T0*ZIx1(void){T0*R=Zo;if((Z3)(((Z3)((((((T55*)(Zbu2()))->ZWb)))+(ZGs(1))))>(ZGs(0)))){
R=ZzB((T55*)(Zbu2()));}return R;}void Z3v2(T89*C){T6 Zd22=0;T6 ZUs=0;while(!(Zd22)){if((((C)->_cc))==(((T3)'\000'))){Zd22=((T6)(1));}
else if(Ziu2(C,((T3)'\073'))){}else if(Zeu2(C,Zgv2)){if(Ziu2(C,((T3)'\072'))){}Z9D1((T51*)(ZEu2()),Zhu2(C));}else if(Zeu2(C,Zhv2)){if(Zpu2(C)){
ZNI1((Zj8*)(Zfv2()));}}else if(Zeu2(C,Ziv2)){if(Zpu2(C)){((((T51*)((T51*)(ZEu2()))))->Zai)=(1);}}else if(Zeu2(C,Zjv2)){if(Zpu2(C)){((((T89*)(C)))->Z3f)=(1);
}}else if(Zeu2(C,Zkv2)){((((T89*)(C)))->Zbf)=((T6)(Zpu2(C)));}else if(Zeu2(C,Zlv2)){ZUs=((T6)(Zpu2(C)));if(!(((C)->Z7f))){((((T89*)(C)))->Z7f)=((T6)(ZUs));
}}else if(Zeu2(C,Zmv2)){((((T89*)(C)))->Zcf)=((T6)(Zpu2(C)));}else if(Zeu2(C,Znv2)){if(Ziu2(C,((T3)'\072'))){}((((T51*)((T51*)(ZEu2()))))->Zmi)=(Zhu2(C));
}else if(Zeu2(C,Zov2)){if(Ziu2(C,((T3)'\072'))){}((((T51*)((T51*)(ZEu2()))))->Zni)=(Zhu2(C));}else if(Zeu2(C,Zpv2)){if(Ziu2(C,((T3)'\072'))){
}Zzz1((T51*)(ZEu2()),Zhu2(C));}else if(Zeu2(C,Zqv2)){((((Z84*)((Z84*)(ZkH))))->ZGf)=((T6)(Zpu2(C)));}else{Zd22=((T6)(1));}}}void Z1v2(T89*C){
T6 Zd22=0;while(!(Zd22)){if((((C)->_cc))==(((T3)'\000'))){Zd22=((T6)(1));}else if(Zeu2(C,Z2v2)){Z3v2(C);Zd22=((T6)(1));}else if(Ziu2(C,((T3)'\073'))){
}else if(Zeu2(C,Zrv2)){if(Ziu2(C,((T3)'\072'))){}ZWw((T7*)(ZRx1),Zhu2(C));}else if(Zeu2(C,Zsv2)){if(Ziu2(C,((T3)'\072'))){}(((void)((T51*)(ZEu2()))),ZcC1(Zhu2(C)));
}else if(Zeu2(C,Ztv2)){if(Ziu2(C,((T3)'\072'))){}ZWw((T7*)(ZSx1),Zhu2(C));}else if(Zeu2(C,Zuv2)){if(Ziu2(C,((T3)'\072'))){}ZWw((T7*)(ZQx1),Zhu2(C));
}else if(Zeu2(C,Zvv2)){Zwv2((ZD6*)(ZcP),Zqu2(C));}else if(Zeu2(C,Zxv2)){if(Ziu2(C,((T3)'\072'))){}(((void)((T51*)(ZEu2()))));{T0*b1=Zhu2(C);
ZQz((T55*)(ZhB1()),b1);}}else if(Zeu2(C,Zyv2)){if(Ziu2(C,((T3)'\072'))){}(((void)((T51*)(ZEu2()))));{T0*b1=Zhu2(C);ZQz((T55*)(ZeD1()),b1);
}}else{Zd22=((T6)(1));}}}void Zzv2(T89*C,T0*a1){T6 ZAv2=0;if((((C)->Z1f))!=((void*)(Zo))){(((void)((T38*)(Zzu2()))),Zzi1(Z1G(41,"Multiple ACE files in the command line: \"")));
(((void)((T38*)(Zzu2()))),Zzi1(((C)->Z1f)));(((void)((T38*)(Zzu2()))),Zzi1(Z1G(7,"\" and \"")));(((void)((T38*)(Zzu2()))),Zzi1(a1));(((void)((T38*)(Zzu2()))),Zzi1(Z1G(3,ZGo)));
Zv(ZGs(1));}(C->Z1f)=a1;Zpi1((T77*)(Z9v2()),a1);if(!(((((T77*)(Z9v2()))->Ztc))!=(Zo))){{T0*b1=Z1G(13,"Cannot open \"");Zmx((T7*)(Z2G),b1);
}{T0*b1=a1;Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(27,"\" file.\nACE file not found.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}ZvP((T38*)(Zzu2()),Z1G(9,"Parsing \""));
ZvP((T38*)(Zzu2()),((C)->Z1f));ZvP((T38*)(Zzu2()),Z1G(12,"\" ACE file.\n"));(C->ZWe)=ZGs(1);(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(Z9v2()))->Zal))))->ZUb))[((C)->ZWe)];
Zbv2(C,ZGs(1));if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}(C->ZZe)=((T6)(1));
ZAu2(C);if(!(Zeu2(C,ZBv2))){{T81 Zow;Z5G((*(Zow=ZJu2(C),&Zow)));}{T0*b1=Z1G(44,"Keyword \"system\" expected. Invalid ACE file.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}(C->Z2f)=Zhu2(C);if(!(Zeu2(C,ZCv2))){{T81 Zow;Z5G((*(Zow=ZJu2(C),&Zow)));}{T0*b1=Z1G(42,"Keyword \"root\" expected. Invalid ACE file.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}{T0*b1=Zhu2(C);ZQz((T55*)(Zbu2()),b1);}ZBu2(C);if(Ziu2(C,((T3)'\072'))){(C->Zef)=Zhu2(C);}if(Zeu2(C,Zlu2)){
ZAv2=((T6)(ZDv2(C)));}if(ZEv2(C)){}if(Zeu2(C,Z0v2)){Z1v2(C);}if(Zeu2(C,Z2v2)){Z3v2(C);}if(Zeu2(C,Z4v2)){}if((((C)->_cc))!=(((T3)'\000'))){
{T81 Zow;Z5G((*(Zow=ZJu2(C),&Zow)));}{T0*b1=Z1G(40,"End of text expected (invalid ACE file).");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}
ZA72((T77*)(Z9v2()));ZFu2(C);if(ZAv2){((((T38*)((T38*)(Zzu2()))))->ZKh)=(1);}}T6 Zgi1(T89*C,T0*a1){T6 R=0;if((((C)->Zdf))==((void*)(ZQi1))){
R=((T6)(1));}else if((((C)->Zdf))==((void*)(ZIi1))){}else{R=((T6)(ZDW(((ZM1*)a1),((C)->Zdf))));}return R;}T6 ZXn1(T89*C,T0*a1){T6 R=0;
T0*Z_u2=Zo;Z_u2=((((T87*)a1))->Zbg);if((Z_u2)!=((void*)(Zo))){R=((T6)(Z_h1(((T90*)Z_u2),((((T87*)a1))->Zpc))));}else{R=((T6)(((C)->Z9f)));
}if(R){if((((C)->Zaf))==(ZGs(1))){(C->Zaf)=ZGs(2);}}return R;}T6 ZEv2(T89*C){T6 R=0;T6 Zd22=0;if(Zeu2(C,Z6v2)){R=((T6)(1));while(!(Zd22))
{if(ZYu2(C)){if(Ziu2(C,((T3)'\073'))){}if(Zeu2(C,Z4v2)){}}else{Zd22=((T6)(1));}}}return R;}T0*Z8v2(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));
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
ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T6 ZFv2(T89*C,T0*a1){T6 R=0;
T2 Zet=0;T0*Z_u2=Zo;T0*ZNu2=Zo;ZWu2(a1);ZNu2=(((void)((T27*)(Z8v2()))),ZCG(ZXu2));Zet=ZGs(0);while(!((T6)(((Z3)((Zet)>((((Z05*)(ZXz1()))->ZWb))))||((T6)(R)))))
{Z_u2=((((Z05*)(ZXz1()))->ZUb))[Zet];R=((T6)(ZDi1(((T90*)Z_u2),ZNu2)));Zet=(Z3)(((Zet))+(ZGs(1)));}if((T6)((!(R))&&((T6)((((C)->Z1f))==((void*)(Zo)))))){
Zcv2(C);Zet=ZGs(0);while(!((T6)(((Z3)((Zet)>((((Z05*)(ZXz1()))->ZWb))))||((T6)(R))))){Z_u2=((((Z05*)(ZXz1()))->ZUb))[Zet];R=((T6)(Z4i1(((T90*)Z_u2),ZNu2)));
Zet=(Z3)(((Zet))+(ZGs(1)));}}if(!(R)){(((void)((T38*)(Zzu2()))),Zzi1(Z1G(31,"Unable to find file for class \"")));(((void)((T38*)(Zzu2()))),Zzi1(a1));
(((void)((T38*)(Zzu2()))),Zzi1(Z1G(3,"\". ")));((((T7*)((T7*)(Zwu2))))->Zdc)=(ZGs(0));ZYz1(C,Zwu2);(((void)((T38*)(Zzu2()))),Zzi1(Zwu2));
}return R;}void ZAu2(T89*C){T81 ZjG={Zo,Zo,0};T6 Zd22=0;while(!(Zd22)){{int z1=((C)->_cc);switch(z1){case 9:case 10:case 32:Zyu2(C);break;
case 45:Zyu2(C);if((((C)->_cc))==(((T3)'\055'))){if(((C)->ZZe)){if((((C)->ZWe))==((((T77*)(Z9v2()))->Zdc))){(C->_cc)=((T3)'\000');Zd22=((T6)(1));
}else{(C->ZWe)=(Z3)(((((C)->ZWe)))+(ZGs(1)));(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(Z9v2()))->Zal))))->ZUb))[((C)->ZWe)];if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){
(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}}}else{{T81 Zow;ZjG=(*(Zow=Zxu2(((C)->ZWe),(Z3)(((((C)->ZVe)))-((T2)(ZGs(1))))),&Zow));
}Zyu2(C);((((T7*)((T7*)(ZLu2))))->Zdc)=(ZGs(0));while(!((((C)->_cc))==(((T3)'\n')))){Zgt((T7*)(ZLu2),((C)->_cc));Zyu2(C);}if((((C)->ZYe))==((void*)(Zo))){
{T91*n=((T91*)Zh(sizeof(*n)));*n=M91;Zkd1(n,ZjG,Z7t((T7*)(ZLu2)));(C->ZYe)=((T0*)n);}}else{Z5z(((T79*)((((T91*)(((C)->ZYe)))->ZZb))),Z7t((T7*)(ZLu2)));
}}}else{(C->_cc)=((T3)'\055');(C->ZVe)=(Z3)(((((C)->ZVe)))-(ZGs(1)));Zd22=((T6)(1));}break;default:;Zd22=((T6)(1));}}}}T0*ZUu2(T2 a1){
T0*R=Zo;{int z1=a1;switch(z1){case 0:R=ZGi1;break;case 1:R=ZHi1;break;case 2:R=ZIi1;break;case 3:R=ZJi1;break;case 4:R=ZKi1;break;case
5:R=ZLi1;break;case 6:R=ZMi1;break;case 7:R=ZNi1;break;default:;R=ZOi1;}}return R;}void Z5A1(T0*a1,T0*a2,T6 a3){T0*Z_u2=Zo;Z_u2=ZHu2(a1,(T6)(a3));
if((a2)!=((void*)(Zo))){((((T90*)(((T90*)Z_u2))))->Zpc)=((((void)((T27*)(Z8v2()))),ZCG(a2)));}}T6 ZQu2(T89*C){T6 R=0;if(ZMs(((C)->_cc))){
{T81 Zow;ZwZ(&(((C)->ZEd)),(*(Zow=Zxu2(((C)->ZWe),((C)->ZVe)),&Zow)));}{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}while(!(R)){Zyu2(C);{int
z1=((C)->_cc);switch(z1){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case
68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case
85:case 86:case 87:case 88:case 89:case 90:case 95:{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}break;default:;R=((T6)(1));}}}ZAu2(C);}return
R;}T0*ZXu2=Zo;T2 Znu2(T89*C){T2 R=0;if(!(Ziu2(C,((T3)'\050')))){{T89*C1=C;T0*b1=ZIu2;{T81 Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}if(Zeu2(C,ZHi1)){
R=ZGs(1);}else if(Zeu2(C,ZIi1)){R=ZGs(2);}else if(Zeu2(C,ZJi1)){R=ZGs(3);}else if(Zeu2(C,ZKi1)){R=ZGs(4);}else if(Zeu2(C,ZLi1)){R=ZGs(5);
}else if(Zeu2(C,ZMi1)){R=ZGs(6);}else if((T6)(((T6)((Zeu2(C,ZGv2))||((T6)(Zeu2(C,ZNi1)))))||((T6)(Zeu2(C,ZQi1))))){R=ZGs(7);}else if(Zeu2(C,ZOi1)){
R=ZGs(8);}else{{T81 Zow;Z5G((*(Zow=ZJu2(C),&Zow)));}{T0*b1=Z1G(28,"Unknown assertion level tag.");Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));
{T0*b1=Z1G(154,"You have to fix the problem in your ACE file. Valid assertion level tags are: \"no\", \"require\", \"ensure\", \"invariant\", \"loop\", \"check\", \"all\", and \"debug\".");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}if(!(Ziu2(C,((T3)'\051')))){{T89*C1=C;T0*b1=ZKu2;{T81 Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}Zbv2(C,R);
return R;}T6 ZDu2(T89*C){T6 R=0;R=((T6)((T6)(((Z3)((((C)->Zaf))>=(ZGs(2))))&&((T6)(((C)->Zgf))))));return R;}T0*ZAi1(T0*a1){T0*R=Zo;T2
Zet=0;Zet=ZGs(0);while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((Zet)>((((Z05*)(ZXz1()))->ZWb)))))))){R=ZSi1((T90*)(((((Z05*)(ZXz1()))->ZUb))[Zet]),a1);
Zet=(Z3)(((Zet))+(ZGs(1)));}return R;}void Zyu2(T89*C){if((Z3)((((C)->ZVe))<((((T7*)(((C)->ZXe)))->Zdc)))){(C->ZVe)=(Z3)(((((C)->ZVe)))+(ZGs(1)));
(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[(((C)->ZVe))-(ZGs(1))];}else if((((C)->ZVe))==((((T7*)(((C)->ZXe)))->Zdc))){(C->ZVe)=(Z3)(((((C)->ZVe)))+(ZGs(1)));
(C->_cc)=((T3)'\n');}else if((((C)->ZWe))==((((T77*)(Z9v2()))->Zdc))){(C->_cc)=((T3)'\000');}else{(C->ZWe)=(Z3)(((((C)->ZWe)))+(ZGs(1)));
(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(Z9v2()))->Zal))))->ZUb))[((C)->ZWe)];if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){(C->_cc)=((T3)'\n');
}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}}}T0*ZHv2=Zo;int ZIv2=0;T0*ZXz1(void){if(ZIv2==0){ZIv2=1;{{Z05*n=((Z05*)Zh(sizeof(*n)));
*n=Z6h;ZHv2=((T0*)n);ZaC(n,(T2)(ZGs(64)));}}}return ZHv2;}T6 ZDv2(T89*C){T6 R=0;T6 Zd22=0;while(!(Zd22)){if((((C)->_cc))==(((T3)'\000'))){
Zd22=((T6)(1));}else if(ZEv2(C)){Zd22=((T6)(1));}else if(Zeu2(C,Z0v2)){Z1v2(C);Zd22=((T6)(1));}else if(Zeu2(C,Z2v2)){Z3v2(C);Zd22=((T6)(1));
}else if(Ziu2(C,((T3)'\073'))){}else if(Zeu2(C,Zmu2)){(C->Zaf)=Znu2(C);}else if(Zeu2(C,ZOi1)){(C->Zdf)=Zqu2(C);}else if(Zeu2(C,ZJv2)){
if(!(Zpu2(C))){Z4J1((Zj8*)(Zfv2()));}}else if(Zeu2(C,ZKv2)){if(Zpu2(C)){ZLv2((ZQ9*)(ZbP));}}else if(Zeu2(C,ZMv2)){if(Zpu2(C)){ZNv2((ZQ9*)(ZbP));
}}else if(Zeu2(C,ZOv2)){if(Zpu2(C)){((((T80*)((T80*)(Z4G))))->ZGg)=(1);}}else if(Zeu2(C,Zou2)){if(Zpu2(C)){ZPv2(C);}}else if(Zeu2(C,ZQv2)){
if(Zpu2(C)){((((T89*)(C)))->Z4f)=(1);}}else if(Zeu2(C,ZRv2)){R=((T6)(Zpu2(C)));}else if(Zeu2(C,ZSv2)){(C->Z5f)=((T6)(Zpu2(C)));}else if(Zeu2(C,ZTv2)){
(C->Z6f)=((T6)(Zpu2(C)));}else{Zd22=((T6)(1));}}return R;}T0*Zqu2(T89*C){T0*R=Zo;if(!(Ziu2(C,((T3)'\050')))){{T89*C1=C;T0*b1=ZIu2;{T81
Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}if(Zeu2(C,ZIi1)){R=ZIi1;}else if((T6)((Zeu2(C,ZQi1))||((T6)(Zeu2(C,ZNi1))))){Zbv2(C,ZGs(8));R=ZQi1;
}else{Zbv2(C,ZGs(8));R=Zhu2(C);}if(!(Ziu2(C,((T3)'\051')))){{T89*C1=C;T0*b1=ZKu2;{T81 Zow;Ztu2((*(Zow=ZJu2(C1),&Zow)),b1);}}}return R;
}T0*ZUv2(T89*C){T0*R=Zo;T0*ZkL=Zo;T0*ZWF=Zo;if((((C)->Zef))==((void*)(Zo))){{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zb41(n,ZIx1());ZWF=((T0*)n);
}ZkL=Zc41(ZWF);(C->Zef)=Zbm1(((T87*)ZkL));}R=((C)->Zef);return R;}void ZPv2(T89*C){(C->Z9f)=((T6)(1));(C->Zgf)=((T6)(1));}T81 Zxu2(T2
a1,T2 a2){T81 R={Zo,Zo,0};{T81*C1=&R;T2 b1=a1;T2 b2=a2;Z3m1(C1,b1,b2,Zxt(32767),Zo);}return R;}void ZFu2(T89*C){T2 Zet=0;Zav2(C);ZdD1((T51*)(ZEu2()));
if((((C)->Zdf))==((void*)(Zo))){(C->Zdf)=ZIi1;}Zet=(((Z05*)(ZXz1()))->ZWb);while(!((Z3)((Zet)<(ZGs(0))))){ZVi1((T90*)(((((Z05*)(ZXz1()))->ZUb))[Zet]));
Zet=(Z3)(((Zet))-(ZGs(1)));}}void ZYz1(T89*C,T0*a1){T2 Zet=0;T2 ZVv2=0;T0*ZWv2=Zo;if((((T43*)(ZSG))->ZSk)){}else if((((C)->Z1f))==((void*)(Zo))){
Zmx(((T7*)a1),Z1G(346,"\nYou are in command line mode (i.e. no ACE file is used).\nThe load path can be changed using a file called\nloadpath.se in the current working directory.\nUsually, this loadpath.se file is a simple list of directories.\nIt is also possible to use system variables or include files. See\nthe documentation for the finder command for more information.\n"));
}else{Zmx(((T7*)a1),Z1G(70,"\nEiffel class file searching is being done according to the ACE file \""));Zmx(((T7*)a1),((C)->Z1f));Zmx(((T7*)a1),Z1G(3,ZGo));
}if((((T43*)(ZSG))->ZSk)){Zmx(((T7*)a1),Z1G(62,"(Command pretty only looks in the current working directory.)\n"));}else{Zmx(((T7*)a1),Z1G(64,"Files are being searched for in the following list of clusters ("));
Z6t((Z3)((((((Z05*)(ZXz1()))->ZWb)))+(ZGs(1))),a1);Zmx(((T7*)a1),Z1G(9," items):\n"));Zet=ZGs(0);while(!((Z3)((Zet)>((((Z05*)(ZXz1()))->ZWb)))))
{ZVv2=(Z3)(((ZVv2))+(ZGs(1)));ZWi1((T90*)(((((Z05*)(ZXz1()))->ZUb))[Zet]),ZVv2,a1);Zet=(Z3)(((Zet))+(ZGs(1)));}ZcB1((T51*)(ZEu2()),a1);
Zmx(((T7*)a1),Z1G(57,"The value of the environment variable \"SmartEiffel\" is:\n\""));ZWv2=(((void)((T38*)(Zzu2()))),ZAv1(ZIv1,Zo));
if((ZWv2)!=((void*)(Zo))){Zmx(((T7*)a1),ZWv2);}Zmx(((T7*)a1),Z1G(3,ZGo));if((((C)->Z1f))!=((void*)(Zo))){Zmx(((T7*)a1),Z1G(111,"Please, also note that you can use the \"ace_check\" command\nto view all informations stored into your ACE file.\n"));
}}}void ZXv2(T89*C){(C->Zaf)=ZGs(8);(C->Zdf)=ZQi1;}void Zbv2(T89*C,T2 a1){if((Z3)((a1)>(((C)->Z8f)))){(C->Z8f)=a1;}}
#ifdef __cplusplus
}
#endif

