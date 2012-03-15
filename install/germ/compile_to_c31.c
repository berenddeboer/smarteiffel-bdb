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
T6 ZAm2(T76*C){T6 R=0;T0*_bc=Zo;_bc=((*C).Zqb);if((_bc)!=((void*)(Zo))){R=((T6)(((((T82*)_bc))->Zrg)));}return R;}T6 ZMF(T76*C){T6 R=0;
R=((T6)((((ZWs)(((*C).Zsb))))==(Zrs(0))));return R;}T10 ZBm2(T76*C){T10 R=0;if(ZJs(((*C).Zsb),Zrs(0))){R=(ZLl1)(((Z8)(((*C).Zsb))>>(Zrs(17))));
}else{R=(ZLl1)(((Z8)(((*C).Zsb))>>(Zrs(21))));}return R;}T0*ZCm2(T0*a1,T2 a2){T0*R=Zo;T2 _i=0;ZZY((T36*)(ZDm2()),Zjf1,a1);if(((((T42*)(Zjf1))->Zoc))!=(Zo)){
while(!((T6)(((((T42*)(Zjf1))->ZPh))||((T6)((_i)==(a2)))))){Zvw1((T42*)(Zjf1));_i=(Z3)(((_i))+(Zrs(1)));}if(!((((T42*)(Zjf1))->ZPh))){
R=ZTf1;}Z3Z((T42*)(Zjf1));}return R;}void ZEm2(T76*C){T2 _li=0;T2 _co=0;T2 _nb=0;T0*_bc=Zo;T0*ZqS=Zo;T0*Zkc=Zo;T0*Z3f=Zo;T0*ZFm2=Zo;T10
ZGm2=0;_li=ZUa1(C);_co=ZVa1(C);_bc=((*C).Zqb);if((_bc)!=((void*)(Zo))){ZqS=Z0T(C);}if((ZqS)!=((void*)(Zo))){Zkc=((((T80*)ZqS))->Zre);
Z3f=((((T82*)_bc))->Zoc);}if((Z3f)==((void*)(Zo))){ZGm2=ZBm2(C);{int z1=ZGm2;switch(z1){case 32767:Z3f=(((T84*)(ZFI))->Z3f);break;case
32766:Z3f=(((T53*)(ZUw1))->Z3f);break;case 32765:Z3f=((*C).Zrb);break;default:;Z3f=(((void)((T40*)(ZHm2()))),Z6Z(ZGm2));}}}(((void)((T36*)(ZDm2()))),ZUf1(ZvF(5,"Line ")));
(((void)((T36*)(ZDm2()))),Zws1(_li));if((Z3)((_co)>(Zrs(0)))){(((void)((T36*)(ZDm2()))),ZUf1(ZvF(8,ZCo)));(((void)((T36*)(ZDm2()))),Zws1(_co));
}(((void)((T36*)(ZDm2()))),ZUf1(ZvF(4,Zxo)));if((Zkc)!=((void*)(Zo))){(((void)((T36*)(ZDm2()))),ZUf1(Zkc));}if((Z3f)!=((void*)(Zo))){
(((void)((T36*)(ZDm2()))),ZUf1(ZvF(2,Zun)));(((void)((T36*)(ZDm2()))),ZUf1(Z3f));(((void)((T36*)(ZDm2()))),Z1s1(((T3)'\051')));}(((void)((T36*)(ZDm2()))),ZUf1(ZvF(3," :\n")));
if((Z3f)!=((void*)(Zo))){ZFm2=ZCm2(Z3f,_li);if((T6)(((Z3)((_li)>(Zrs(0))))&&((T6)((ZFm2)!=((void*)(Zo)))))){(((void)((T36*)(ZDm2()))),ZUf1(ZFm2));
(((void)((T36*)(ZDm2()))),Z1s1(((T3)'\n')));if((Z3)((_co)>(Zrs(0)))){_nb=Zrs(1);while(!((Z3)((_nb)>=(_co)))){if(((((((T7*)ZFm2))->ZPb))[(_nb)-(Zrs(1))])==(((T3)'\011'))){
(((void)((T36*)(ZDm2()))),Z1s1(((T3)'\011')));}else{(((void)((T36*)(ZDm2()))),Z1s1(((T3)'\040')));}_nb=(Z3)(((_nb))+(Zrs(1)));}(((void)((T36*)(ZDm2()))),ZUf1(ZvF(2,"^\n")));
}}}}T0*Z0T(T76*C){T0*R=Zo;T0*_bc=Zo;_bc=((*C).Zqb);if((_bc)!=((void*)(Zo))){R=((((T82*)_bc))->Zkc);}return R;}T0*ZDm2(void){if(ZRK==0){ZRK=1;{
{T36*n=((T36*)Zh(sizeof(*n)));*n=M36;ZQK=((T0*)n);}}}return ZQK;}T0*Z0X1(T76*C){T0*R=Zo;T0*_bc=Zo;T10 ZGm2=0;_bc=((*C).Zqb);if((_bc)!=((void*)(Zo))){
R=((((T82*)_bc))->Zoc);}else{ZGm2=ZBm2(C);{int z1=ZGm2;switch(z1){case 32767:R=(((T84*)(ZFI))->Z3f);break;case 32766:R=(((T53*)(ZUw1))->Z3f);
break;default:;R=(((void)((T40*)(ZHm2()))),Z6Z(ZGm2));}}}return R;}void Z4j1(T76*C,T2 a1,T2 a2,T10 a3,T0*a4){(C->Zqb)=a4;if((T6)(((T6)(((Z2)((a3)<=(Zft(2047))))&&((T6)((Z3)((a1)<=(Zft(8191)))))))&&((T6)((Z3)((a2)<=(Zrs(127))))))){
(C->Zsb)=(T2)(((a3)<<(Zrs(21))));(C->Zsb)=(((*C).Zsb)|((a1)<<(Zrs(8))));(C->Zsb)=(((*C).Zsb)|((a2)<<(Zrs(1))));}else{(C->Zsb)=(T2)(((a3)<<(Zrs(17))));
(C->Zsb)=(((*C).Zsb)|((a1)<<(Zrs(1))));(C->Zsb)=(((*C).Zsb)|Zrs(1));}}T6 Zmo1(T76*C,T76 a1){T6 R=0;T2 _li=0;T2 ZIm2=0;_li=ZUa1(C);ZIm2=ZUa1(&a1);
if((Z3)((_li)<(ZIm2))){R=((T6)(1));}else if((_li)==(ZIm2)){R=((T6)((Z3)((ZVa1(C))<(ZVa1(&a1)))));}return R;}T0*ZHm2(void){if(ZBk1==0){ZBk1=1;{
{T40*n=((T40*)Zh(sizeof(*n)));*n=M40;ZAk1=((T0*)n);ZTY(n);}}}return ZAk1;}T2 ZUa1(T76*C){T2 R=0;if(ZJs(((*C).Zsb),Zrs(0))){R=((((*C).Zsb))>>(Zrs(1)));
R=(R&ZXs(65535));}else{R=((((*C).Zsb))>>(Zrs(8)));R=(R&ZXs(8191));}return R;}T2 ZVa1(T76*C){T2 R=0;if(ZJs(((*C).Zsb),Zrs(0))){}else{R=((((*C).Zsb))>>(Zrs(1)));
R=(R&ZXs(127));}return R;}T6 ZJm2(T0*a1){T6 R=0;R=((T6)(ZQr1(a1)));return R;}void ZUr1(T0*a1,T0*a2){T8 _p1=Zo;T8 _p2=Zo;if(ZJm2(a2)){
ZPr1(a2);}_p1=Znx(((T7*)a1));_p2=Znx(((T7*)a2));ZKm2(_p1,_p2);}T0*ZLm2=Zo;T0*ZMm2=Zo;T6 ZNm2(T0*a1,T0*a2){T6 R=0;Z6s1((T42*)(ZLm2),a1);
if(((((T42*)(ZLm2))->Zoc))!=(Zo)){Z6s1((T42*)(ZMm2),a2);if(((((T42*)(ZMm2))->Zoc))!=(Zo)){R=((T6)(Zml2((T42*)(ZLm2),ZMm2)));}else{Z3Z((T42*)(ZLm2));
}}return R;}void ZPr1(T0*a1){T8 _p=Zo;_p=Znx(((T7*)a1));ZOm2(_p);}T6 ZQr1(T0*a1){T6 R=0;Z6s1((T42*)(ZLm2),a1);R=((T6)(((((T42*)(ZLm2))->Zoc))!=(Zo)));
if(R){Z3Z((T42*)(ZLm2));}return R;}T0*ZPm2(T0*a1){T0*R=Zo;R=ZQm2;((((T7*)(((T7*)R))))->Zcc)=(Zrs(0));ZXw(((T7*)R),ZRm2);Znt((((T82*)(((((Z85*)a1))->Zqb)))->_id),R);
ZXw(((T7*)R),(((ZB8*)(((((Zx8*)(((((Z85*)a1))->Zfc))))->ZBd)))->Z3n));R=(((void)((T26*)(ZSm2()))),ZAS(R));return R;}T0*Zvn1(T0*a1){T0*R=Zo;
R=ZTm2;((((T7*)(((T7*)R))))->Zcc)=(Zrs(0));ZXw(((T7*)R),ZUm2);Znt((((T82*)(((((Z85*)a1))->Zqb)))->_id),R);ZXw(((T7*)R),(((ZB8*)(((((Zx8*)(((((Z85*)a1))->Zfc))))->ZBd)))->Z3n));
R=(((void)((T26*)(ZSm2()))),ZAS(R));return R;}T0*ZVm2=Zo;T0*ZQm2=Zo;T0*ZWm2=Zo;T0*ZXm2(T0*a1){T0*R=Zo;T2 _i=0;T0*_rf=Zo;_i=Zrs(0);while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((_i)>((((Z_5*)(ZVm2))->ZRb))))))))
{_rf=((((Z_5*)(ZVm2))->ZPb))[_i];if((T6)((((((ZB8*)(((((ZS7*)_rf))->Zkc)))->Zre))==((void*)(a1)))&&((T6)(((((T80*)((((T82*)((((Z85*)(ZyV(_rf)))->Zqb)))->Zkc)))->Zre))==((void*)(ZpK)))))){
R=_rf;}_i=(Z3)(((_i))+(Zrs(1)));}return R;}T0*ZYm2=Zo;void ZfF1(T0*a1){T2 _i=0;T0*_rf=Zo;T0*_of=Zo;T0*ZZm2=Zo;T0*_rt=Zo;T0*ZIM1=Zo;if((Z3)(((Z3)((((((Z_5*)(ZVm2))->ZRb)))+(Zrs(1))))>(Zrs(0)))){
_i=(((Z_5*)(ZVm2))->ZRb);{Zp6*n=((Zp6*)Zh(sizeof(*n)));*n=ZTi;ZdA(n,(Z3)((_i)/((T2)(Zrs(2)))));ZZm2=((T0*)n);}while(!((Z3)((_i)<(Zrs(0)))))
{_rf=((((Z_5*)(ZVm2))->ZPb))[_i];_of=ZyV(_rf);if(Zo!=(_of)){switch(((T0*)_of)->id){case 410:break;default:_of=Zo;}}if(!(ZaA(((Zp6*)ZZm2),_of))){
if((((Ze4*)(Z8G(((((ZS7*)_rf))->Z0c))))->Zth)){ZcA(((Zp6*)ZZm2),_of);_rt=ZqG(_rf);if(ZBZ(_rt)){ZIM1=Zvn1(_of);(((void)((Zh8*)(Z_m2()))),Zdo1(a1,ZIM1,Z8G(_rt)));
}}}_i=(Z3)(((_i))-(Zrs(1)));}}}void Z0n2(T0*a1,T0*a2){T0*Zgc=Zo;T0*ZFb=Zo;T0*ZPW=Zo;if((Z1n2(a1))!=((void*)(Zo))){Z6I((ZN*)(Z1n2(a1)));
}Zgc=ZqG(a1);if(Z4_(Zgc)){ZPW=ZsY((Ze4*)(Z8G(Zgc)));if((ZPW)!=((void*)(Zo))){Zp41((Zi4*)(ZsG),ZPW,Zo,Zvn1(ZyV(a1)));}}ZFb=ZBc1(a1);if((ZFb)!=((void*)(Zo))){
ZcH((Zi4*)(ZsG),((T3)'\173'));ZI61(((Zo3*)ZFb),(T6)(0));}if((Zso1(a1))!=((void*)(Zo))){ZgV((Z47*)(Zso1(a1)));}if((Z2n2(a1))!=((void*)(Zo))){
ZiO1((Z11*)(Z2n2(a1)));}if((ZFb)!=((void*)(Zo))){ZcH((Zi4*)(ZsG),((T3)'\175'));}}void ZoN1(T0*a1){T0*_bf=Zo;T0*Z3n2=Zo;T0*ZIM1=Zo;T0*_rt=Zo;
if((T6)((!((((T41*)(Z1G))->ZPk)))||((T6)(Z2H(ZqG(a1)))))){_bf=ZyV(a1);Z3n2=((((Z85*)_bf))->Zqb);ZIM1=Zvn1(_bf);if(!(Zuj1(((T82*)Z3n2),ZIM1))){
((((T7*)((T7*)(ZYm2))))->Zcc)=(Zrs(0));_rt=ZqG(a1);if(Z2H(_rt)){ZZs((T7*)(ZYm2),((T3)'s'));}ZZs((T7*)(ZYm2),((T3)'T'));if(Z5T(_rt)){ZQs(ZuI(_rt),ZYm2);
ZZs((T7*)(ZYm2),((T3)'\040'));}else{ZZs((T7*)(ZYm2),((T3)'0'));ZZs((T7*)(ZYm2),((T3)'\052'));}ZXw((T7*)(ZYm2),ZIM1);((((T7*)((T7*)(ZWm2))))->Zcc)=(Zrs(0));
Z8Z(_rt,ZWm2);ZYN((Zi4*)(ZsG),ZYm2,ZWm2);}}}void Z5W1(T0*a1){T0*Z7H=Zo;T0*_rt=Zo;if((T6)((!((((T41*)(Z1G))->ZPk)))||((T6)(Z2H(ZqG(a1)))))){
Z7H=ZPm2(ZyV(a1));Z7I((Zi4*)(ZsG),Z4n2);Z7I((Zi4*)(ZsG),Z7H);Z7I((Zi4*)(ZsG),Z5n2);}else{_rt=ZqG(a1);((((T7*)((T7*)(ZYm2))))->Zcc)=(Zrs(0));
ZZs((T7*)(ZYm2),((T3)'T'));if(Z5T(_rt)){ZQs(ZuI(_rt),ZYm2);}else{ZZs((T7*)(ZYm2),((T3)'0'));ZZs((T7*)(ZYm2),((T3)'\052'));}Z7H=Zvn1(ZyV(a1));
Z7I((Zi4*)(ZsG),ZYm2);ZcH((Zi4*)(ZsG),((T3)'\040'));Z7I((Zi4*)(ZsG),Z7H);if(!(Z5T(_rt))){Z7I((Zi4*)(ZsG),Z6n2);}Z7I((Zi4*)(ZsG),Z8M);
Z7I((Zi4*)(ZsG),Z7n2);Z7I((Zi4*)(ZsG),Z7H);Z7I((Zi4*)(ZsG),Z8n2);}}T0*Z9n2(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));*n=M36;
ZQK=((T0*)n);}}}return ZQK;}T0*Z_m2(void){if(ZDI==0){ZDI=1;{{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZGk;ZCI=((T0*)n);}}}return ZCI;}T0*ZSm2(void){
if(ZbP==0){ZbP=1;{{T26*n=((T26*)Zh(1));ZaP=((T0*)n);ZdP(ZeP);ZdP(ZfP);ZdP(ZgP);ZdP(ZhP);ZdP(ZiP);ZdP(ZjP);ZdP(ZkP);ZdP(ZlP);ZdP(ZmP);
ZdP(ZnP);ZdP(ZoP);ZdP(ZpP);ZdP(ZqP);ZdP(ZrP);ZdP(ZpK);ZdP(ZsP);ZdP(ZtP);ZdP(ZuP);ZdP(ZvP);ZdP(ZwP);ZdP(ZxP);ZdP(ZyP);ZdP(ZzP);ZdP(ZAP);
ZdP(ZBP);ZdP(ZCP);ZdP(ZDP);ZdP(ZEP);ZdP(ZFP);ZdP(ZGP);ZdP(ZHP);ZdP(ZIP);ZdP(ZJP);ZdP(ZKP);ZdP(ZLP);ZdP(ZMP);ZdP(ZNP);ZdP(ZOP);ZdP(ZPP);
ZdP(ZQP);ZdP(ZRP);ZdP(ZSP);ZdP(ZTP);ZdP(ZUP);ZdP(ZVP);ZdP(ZWP);ZdP(ZXP);ZdP(ZYP);ZdP(ZZP);ZdP(Z_P);ZdP(Z0Q);ZdP(Z1Q);ZdP(Z2Q);ZdP(Z3Q);
ZdP(Z4Q);ZdP(Z5Q);ZdP(Z6Q);ZdP(Z7Q);ZdP(Z8Q);ZdP(Z9Q);ZdP(ZaQ);ZdP(ZbQ);ZdP(ZcQ);ZdP(ZdJ);ZdP(ZdQ);ZdP(ZeQ);ZdP(ZfQ);ZdP(ZgQ);ZdP(ZhQ);
ZdP(ZiQ);ZdP(ZjQ);ZdP(ZkQ);ZdP(ZlQ);ZdP(ZmQ);ZdP(ZnQ);ZdP(ZoQ);ZdP(ZpQ);ZdP(ZqQ);ZdP(ZDG);ZdP(ZrQ);ZdP(ZsQ);ZdP(ZtQ);ZdP(ZuQ);ZdP(ZvQ);
ZdP(ZwQ);ZdP(ZxQ);ZdP(ZyQ);ZdP(ZzQ);ZdP(ZAQ);ZdP(ZBQ);ZdP(ZCQ);ZdP(ZDQ);ZdP(ZEQ);ZdP(ZFQ);ZdP(ZGQ);ZdP(ZHQ);ZdP(ZIQ);ZdP(ZJQ);ZdP(ZKQ);
ZdP(ZLQ);ZdP(ZMQ);ZdP(ZNQ);ZdP(ZOQ);ZdP(ZPQ);ZdP(ZQQ);ZdP(ZRQ);ZdP(ZSQ);ZdP(ZTQ);ZdP(ZUQ);ZdP(ZVQ);ZdP(ZWQ);ZdP(ZXQ);ZdP(ZYQ);ZdP(ZZQ);
ZdP(Z_Q);ZdP(Z0R);ZdP(Z1R);ZdP(Z2R);ZdP(Z3R);ZdP(Z4R);ZdP(Z5R);ZdP(Z6R);ZdP(Z7R);ZdP(Z8R);ZdP(Z9R);ZdP(ZaR);ZdP(ZbR);ZdP(ZcR);ZdP(ZdR);
ZdP(ZeR);ZdP(ZfR);ZdP(ZgR);ZdP(ZhR);ZdP(ZiR);ZdP(ZjR);ZdP(ZkR);ZdP(ZlR);ZdP(ZmR);ZdP(ZnR);ZdP(ZoR);ZdP(ZpR);ZdP(ZqR);ZdP(ZrR);ZdP(ZsR);
ZdP(ZtR);ZdP(ZuR);ZdP(ZvR);ZdP(ZwR);ZdP(ZxR);ZdP(ZyR);ZdP(ZzR);ZdP(ZAR);ZdP(ZBR);ZdP(ZCR);ZdP(ZDR);ZdP(ZER);ZdP(ZFR);ZdP(ZGR);ZdP(ZHR);
ZdP(ZIR);ZdP(ZJR);ZdP(ZKR);ZdP(ZLR);ZdP(ZMR);ZdP(ZNR);ZdP(ZOR);ZdP(ZPR);ZdP(ZQR);ZdP(ZRR);ZdP(ZSR);ZdP(ZTR);ZdP(ZUR);ZdP(ZVR);ZdP(ZWR);
ZdP(ZXR);ZdP(ZYR);ZdP(ZZR);ZdP(Z_R);ZdP(Z0S);ZdP(Z1S);ZdP(Z2S);ZdP(Z3S);ZdP(Z4S);ZdP(Z5S);ZdP(Z6S);ZdP(Z7S);ZdP(Z8S);ZdP(Z9S);ZdP(ZaS);
ZdP(ZbS);ZdP(ZcS);ZdP(ZdS);ZdP(ZeS);ZdP(ZfS);ZdP(ZgS);ZdP(ZhS);ZdP(ZiS);ZdP(ZjS);ZdP(ZkS);ZdP(ZlS);ZdP(ZmS);ZdP(ZnS);ZdP(ZoS);}}}return
ZaP;}void ZqN1(T0*a1){T0*Z7H=Zo;T0*_rt=Zo;if((T6)((!((((T41*)(Z1G))->ZPk)))||((T6)(Z2H(ZqG(a1)))))){Z7H=ZPm2(ZyV(a1));Z7I((Zi4*)(ZsG),Zan2);
Z7I((Zi4*)(ZsG),Z7H);Z7I((Zi4*)(ZsG),Zbn2);Z7I((Zi4*)(ZsG),Z7H);Z7I((Zi4*)(ZsG),Zcn2);}else{_rt=ZqG(a1);((((T7*)((T7*)(ZYm2))))->Zcc)=(Zrs(0));
ZZs((T7*)(ZYm2),((T3)'T'));if(Z5T(_rt)){ZQs(ZuI(_rt),ZYm2);}else{ZZs((T7*)(ZYm2),((T3)'0'));ZZs((T7*)(ZYm2),((T3)'\052'));}Z7H=Zvn1(ZyV(a1));
Z7I((Zi4*)(ZsG),ZYm2);ZcH((Zi4*)(ZsG),((T3)'\040'));Z7I((Zi4*)(ZsG),Z7H);if(!(Z5T(_rt))){Z7I((Zi4*)(ZsG),Zdn2);}Z7I((Zi4*)(ZsG),Z8M);
Z7I((Zi4*)(ZsG),Zen2);Z7I((Zi4*)(ZsG),Z7H);Z7I((Zi4*)(ZsG),Zfn2);}}T0*ZTm2=Zo;T6 ZgN1(T0*a1){T6 R=0;if(!((((T41*)(Z1G))->ZPk))){if(ZUA((T74*)(Zgn2()),(((ZB8*)(((((Zx8*)(((((Zk7*)a1))->Zfc))))->ZBd)))->Zre))){
R=((T6)(1));}else if(ZML1(((Zk7*)a1))){R=((T6)(1));}}return R;}void ZsN1(T0*a1){T0*ZIM1=Zo;T0*_rt=Zo;ZIM1=Zvn1(ZyV(a1));if((T6)(((((T41*)(Z1G))->ZPk))&&((T6)(!(Z2H(ZqG(a1))))))){
_rt=ZqG(a1);if(Z5T(_rt)){Z7I((Zi4*)(ZsG),Z4l1);Z7I((Zi4*)(ZsG),ZYm2);ZcH((Zi4*)(ZsG),((T3)'\052'));Z7I((Zi4*)(ZsG),Zhn2);Z7I((Zi4*)(ZsG),ZIM1);
Z7I((Zi4*)(ZsG),Zin2);Z7I((Zi4*)(ZsG),ZYm2);Z7I((Zi4*)(ZsG),Zjn2);Z7I((Zi4*)(ZsG),ZIM1);Z7I((Zi4*)(ZsG),Zkn2);Z7I((Zi4*)(ZsG),ZYm2);Z7I((Zi4*)(ZsG),Zln2);
}Z7I((Zi4*)(ZsG),Zmn2);Z7I((Zi4*)(ZsG),ZIM1);Z7I((Zi4*)(ZsG),Znn2);if(Z5T(_rt)){Z7I((Zi4*)(ZsG),Zon2);}Z7I((Zi4*)(ZsG),ZIM1);Z7I((Zi4*)(ZsG),Zpn2);
if(Z5T(_rt)){Z7I((Zi4*)(ZsG),ZdI);}Z7I((Zi4*)(ZsG),Zqn2);Z7I((Zi4*)(ZsG),ZIM1);ZcH((Zi4*)(ZsG),((T3)'\075'));if(Z5T(_rt)){ZcH((Zi4*)(ZsG),((T3)'\052'));
}ZcH((Zi4*)(ZsG),((T3)'\050'));Z7I((Zi4*)(ZsG),ZYm2);if(Z5T(_rt)){ZcH((Zi4*)(ZsG),((T3)'\052'));}Z7I((Zi4*)(ZsG),Zrn2);Z7I((Zi4*)(ZsG),ZIM1);
Z7I((Zi4*)(ZsG),Zsn2);}else{Z7I((Zi4*)(ZsG),Ztn2);}Z7I((Zi4*)(ZsG),Zun2);Z7I((Zi4*)(ZsG),ZIM1);Z7I((Zi4*)(ZsG),Zvn2);}T0*Z1P1=Zo;void
ZLN1(Z92*C,T0*a1){T0*_rc=Zo;Z2A((Z_5*)(ZVm2),a1);if(((((ZB8*)(((((ZS7*)a1))->Zkc)))->Zre))==((void*)(ZVR))){if((((C)->Zsd))==((void*)(Zo))){
if(((((T80*)((((T82*)((((Z85*)(ZyV(a1)))->Zqb)))->Zkc)))->Zre))==((void*)(ZpK))){_rc=Z8G(ZqG(a1));(C->Zsd)=Zw81(((Ze4*)_rc),Z0R);}}}}
void ZpN1(T0*a1){T0*_bf=Zo;T0*Z3n2=Zo;T0*Z7H=Zo;if((T6)((!((((T41*)(Z1G))->ZPk)))||((T6)(Z2H(ZqG(a1)))))){_bf=ZyV(a1);Z3n2=((((Z85*)_bf))->Zqb);
Z7H=ZPm2(_bf);if(!(Zuj1(((T82*)Z3n2),Z7H))){ZBw((T7*)(ZYm2),Zwn2);ZXw((T7*)(ZYm2),Z7H);ZzO((Zi4*)(ZsG),ZYm2,((T3)'0'));}}}T0*Zxn2=Zo;
int Zyn2=0;T0*Zgn2(void){if(Zyn2==0){Zyn2=1;{Zxn2=Zhw1(4,ZTR,ZUR,Z6R,ZVR);}}return Zxn2;}T2 ZtB(T2 a1){T2 R=0;if((Z3)((a1)<=(Zrs(53)))){
R=Zrs(53);}else if((Z3)((a1)<=(Zrs(97)))){R=Zrs(97);}else if((Z3)((a1)<=(Zft(193)))){R=Zft(193);}else if((Z3)((a1)<=(Zft(389)))){R=Zft(389);
}else if((Z3)((a1)<=(Zft(769)))){R=Zft(769);}else if((Z3)((a1)<=(Zft(1543)))){R=Zft(1543);}else if((Z3)((a1)<=(Zft(3079)))){R=Zft(3079);
}else if((Z3)((a1)<=(Zft(6151)))){R=Zft(6151);}else if((Z3)((a1)<=(Zft(12289)))){R=Zft(12289);}else if((Z3)((a1)<=(Zft(24593)))){R=Zft(24593);
}else if((Z3)((a1)<=(ZXs(49157)))){R=ZXs(49157);}else if((Z3)((a1)<=(ZXs(98317)))){R=ZXs(98317);}else if((Z3)((a1)<=(ZXs(196613)))){R=ZXs(196613);
}else if((Z3)((a1)<=(ZXs(393241)))){R=ZXs(393241);}else if((Z3)((a1)<=(ZXs(786433)))){R=ZXs(786433);}else if((Z3)((a1)<=(ZXs(1572869)))){
R=ZXs(1572869);}else if((Z3)((a1)<=(ZXs(3145739)))){R=ZXs(3145739);}else if((Z3)((a1)<=(ZXs(6291469)))){R=ZXs(6291469);}else if((Z3)((a1)<=(ZXs(12582917)))){
R=ZXs(12582917);}else if((Z3)((a1)<=(ZXs(25165843)))){R=ZXs(25165843);}else if((Z3)((a1)<=(ZXs(50331653)))){R=ZXs(50331653);}else if((Z3)((a1)<=(ZXs(100663319)))){
R=ZXs(100663319);}else if((Z3)((a1)<=(ZXs(201326611)))){R=ZXs(201326611);}else if((Z3)((a1)<=(ZXs(402653189)))){R=ZXs(402653189);}else
if((Z3)((a1)<=(ZXs(805306457)))){R=ZXs(805306457);}else{R=ZXs(1610612741);}return R;}T0*Zzn2=Zo;int ZAn2=0;T0*ZBn2(void){if(ZAn2==0){ZAn2=1;{
{ZO3*n=((ZO3*)Zh(sizeof(*n)));*n=ZGe;Zzn2=((T0*)n);{ZO3*C1=n;ZQC(C1,Zrs(53));}}}}return Zzn2;}void ZCn2(T0*a1,T0*a2){ZXw(((T7*)a1),ZDn2);
ZXw(((T7*)a1),a2);ZXw(((T7*)a1),ZEn2);}T0*ZFn2=Zo;int ZGn2=0;T0*ZHn2(void){if(ZGn2==0){ZGn2=1;{{Z1a*n=((Z1a*)Zh(sizeof(*n)));*n=ZXm;ZFn2=((T0*)n);
{Z1a*C1=n;ZdF(C1,Zrs(53));}}}}return ZFn2;}void ZIn2(ZQ3*C){T2 _i=0;if((((C)->ZHe))!=((void*)(Zo))){_i=Zrs(1);while(!((Z3)((_i)>((((ZU*)(((C)->ZHe)))->Zcc)))))
{{Z27*C1=(Z27*)(ZmB((ZU*)(((C)->ZHe)),_i));ZUK(((C1)->Z_b));}_i=(Z3)(((_i))+(Zrs(1)));}}}void ZJn2(ZQ3*C){T2 _i=0;T6 ZlY=0;T0*ZGc=Zo;
ZlY=((T6)(((((T84*)(ZFI))->Zcf))==(Zrs(1))));if((((C)->ZHe))!=((void*)(Zo))){Z7I((Zi4*)(ZsG),ZKn2);if(!(ZlY)){Z7I((Zi4*)(ZsG),ZLn2);}
Z7I((Zi4*)(ZsG),ZMn2);_i=Zrs(1);while(!((Z3)((_i)>((((ZU*)(((C)->ZHe)))->Zcc))))){ZAI1((Z27*)(ZmB((ZU*)(((C)->ZHe)),_i)),(T6)(ZlY));_i=(Z3)(((_i))+(Zrs(1)));
}Z7I((Zi4*)(ZsG),ZNn2);_i=Zrs(1);while(!((Z3)((_i)>((((ZU*)(((C)->ZHe)))->Zcc))))){ZyI1((Z27*)(ZmB((ZU*)(((C)->ZHe)),_i)));_i=(Z3)(((_i))+(Zrs(1)));
}Z7I((Zi4*)(ZsG),ZOn2);Znb1((Zi4*)(ZsG),ZPn2);ZES((Zi4*)(ZsG));Zns1((T36*)(ZQn2()),ZRn2,(((ZU*)(((C)->ZHe)))->Zcc));_i=Zrs(1);while(!((Z3)((_i)>((((ZU*)(((C)->ZHe)))->Zcc)))))
{Z3I1((Z27*)(ZmB((ZU*)(((C)->ZHe)),_i)),(T6)(ZlY));_i=(Z3)(((_i))+(Zrs(1)));}Zns1((T36*)(ZQn2()),ZSn2,(((ZO3*)(ZBn2()))->Zcc));_i=Zrs(1);
while(!((Z3)((_i)>((((ZO3*)(ZBn2()))->Zcc))))){ZGc=ZKC((ZO3*)(ZBn2()),_i);ZcF((Z1a*)(ZHn2()),((((Zo9*)ZGc))->Znk));Zcb2(((Zo9*)ZGc));
_i=(Z3)(((_i))+(Zrs(1)));}ZGS((Zi4*)(ZsG));}}T0*ZQn2(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));*n=M36;ZQK=((T0*)n);}}}return
ZQK;}void ZGF1(ZQ3*C,T0*a1){if((((C)->ZHe))!=((void*)(Zo))){ZXw(((T7*)a1),ZTn2);}}void Z_a2(T0*a1,T76 a2){if(!(ZbF((Z1a*)(ZHn2()),((((Zo9*)a1))->Znk)))){
ZzF(a2);{T0*b1=ZvF(53,"There is no such agent ever defined in the live code.");ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));ZNC((ZO3*)(ZUn2()),a1);
}}void Zgb2(ZQ3*C,T0*a1,T0*a2,T0*a3){T2 _i=0;T2 ZVn2=0;T2 ZWn2=0;T2 ZXn2=0;T2 _id=0;T0*ZYn2=Zo;T0*ZyS=Zo;T0*ZZn2=Zo;T0*Z_n2=Zo;T0*Z0o2=Zo;
T0*Z1o2=Zo;T0*Z2o2=Zo;T6 Z3o2=0;if((((C)->ZHe))!=((void*)(Zo))){_i=Zrs(1);ZZn2=((((ZW9*)a2))->Zpj);Z1o2=((((ZW9*)a2))->ZUj);ZWn2=Z0d1(((Zy7*)Z1o2));
ZZs(((T7*)a1),((T3)'\n'));while(!((Z3)((_i)>((((ZU*)(((C)->ZHe)))->Zcc))))){ZYn2=ZmB((ZU*)(((C)->ZHe)),_i);ZyS=((((Z27*)ZYn2))->Zgc);
_id=((((Z27*)ZYn2))->Zoj);Z3o2=((T6)(0));Z2o2=((((ZW9*)ZyS))->ZUj);ZXn2=Z0d1(((Zy7*)Z2o2));if((Z3)((ZWn2)>=(ZXn2))){Z3o2=((T6)(1));ZVn2=ZXn2;
while(!((T6)((!(Z3o2))||((T6)((Z3)((ZVn2)<=(Zrs(0)))))))){Z_n2=Zid1(((Zy7*)Z1o2),ZVn2);Z0o2=Zid1(((Zy7*)Z2o2),ZVn2);if(ZaH(Z_n2)){Z3o2=((T6)(ZaH(Z0o2)));
}else if(ZYF(Z_n2,Z0o2)){}else{((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));Z3o2=((T6)(0));}ZVn2=(Z3)(((ZVn2))-(Zrs(1)));
}}if((T6)((Z3o2)&&((T6)((a3)!=((void*)(Zo)))))){Z3o2=((T6)((((((ZW9*)ZyS))->ZWj))!=((void*)(Zo))));}if(Z3o2){ZXw(((T7*)a1),Z4o2);ZQs(_id,a1);
ZCn2(a1,Z5o2(ZyS));ZXw(((T7*)a1),Z6o2);if((a3)!=((void*)(Zo))){ZXw(((T7*)a1),Z7o2);ZXU(a3,a1);ZXw(((T7*)a1),Z3U1);}ZXw(((T7*)a1),Z8o2);
ZQs(_id,a1);ZXw(((T7*)a1),Z9o2);if(!(((((T84*)(ZFI))->Zcf))==(Zrs(1)))){ZXw(((T7*)a1),Zao2);}ZXw(((T7*)a1),Zbo2);ZVn2=Zrs(1);while(!((Z3)((ZVn2)>(ZXn2))))
{ZZs(((T7*)a1),((T3)'\054'));ZZs(((T7*)a1),((T3)'a'));ZQs(ZVn2,a1);ZVn2=(Z3)(((ZVn2))+(Zrs(1)));}ZZs(((T7*)a1),((T3)'\051'));if((a3)!=((void*)(Zo))){
ZZs(((T7*)a1),((T3)'\051'));}else{ZXw(((T7*)a1),Zco2);}ZXw(((T7*)a1),Zdo2);}else{ZCn2(a1,Z5o2(ZyS));ZZs(((T7*)a1),((T3)'\n'));}_i=(Z3)(((_i))+(Zrs(1)));
}}}T0*Zeo2=Zo;int Zfo2=0;T0*ZUn2(void){if(Zfo2==0){Zfo2=1;{{ZO3*n=((ZO3*)Zh(sizeof(*n)));*n=ZGe;Zeo2=((T0*)n);{ZO3*C1=n;ZQC(C1,Zrs(53));
}}}}return Zeo2;}T2 Z1J1(ZQ3*C,T0*a1){T2 R=0;T0*Zgo2=Zo;if((((C)->ZHe))==((void*)(Zo))){{ZU*n=((ZU*)Zh(sizeof(*n)));*n=Zdc;{ZU*C1=n;ZzB(C1,Zrs(53));
}(C->ZHe)=((T0*)n);}}Zgo2=ZAB((ZU*)(((C)->ZHe)),a1);if((Zgo2)==((void*)(Zo))){ZvB((ZU*)(((C)->ZHe)),a1);R=(((ZU*)(((C)->ZHe)))->Zcc);
}else{R=((((Z27*)Zgo2))->Zoj);}return R;}T0*ZWM(T0*a1,T0*a2){T0*R=Zo;T0*ZyS=Zo;ZyS=((((ZS7*)a2))->Z0c);if(Zo!=(ZyS)){switch(((T0*)ZyS)->id){
case 283:case 285:break;default:ZyS=Zo;}}{Zo9*n=((Zo9*)Zh(sizeof(*n)));*n=Z_l;Zab2(n,ZyS,a1,ZqG(a2));R=((T0*)n);}ZNC((ZO3*)(ZBn2()),R);
return R;}void Zho2(ZQ3*C){if((((C)->ZHe))!=((void*)(Zo))){Z7I((Zi4*)(ZsG),Zio2);}}void Zjo2(T0*a1,T0*a2,T2 a3){T0*Zko2=Zo;T0*_at=Zo;
T0*_ft=Zo;T6 ZBl=0;Zko2=ZcL(a1);_at=ZvG(ZI71(((ZH6*)Zko2),a3));_ft=ZvG(ZI71(((ZH6*)a2),a3));if(Z2H(_ft)){ZBl=((T6)(!(Z2H(_at))));}else
if(ZaH(_at)){ZBl=((T6)(Z5T(_ft)));}else{ZBl=((T6)(ZaH(_ft)));}if(ZBl){ZHb1(_at,_ft);}ZcH((Zi4*)(ZsG),((T3)'a'));ZtI((Zi4*)(ZsG),(T11)(a3));
if(ZBl){ZcH((Zi4*)(ZsG),((T3)'\051'));}}void Zlo2(T0*a1,T0*a2,T2 a3,T2 a4){T2 _m=0;T0*ZzR1=Zo;T0*ZAR1=Zo;if((a3)==(a4)){ZzR1=(((((ZC3*)(((((Zc3*)a2))->Z9e))))->ZPb))[(a3)-(Zrs(1))];
ZAR1=ZCH(((Ze4*)ZzR1),a1);Zmo2((Zi4*)(ZsG),ZAR1,a1);}else{_m=(Z3)(((Z3)(((a3))+(a4)))/(Zrs(2)));ZzR1=(((((ZC3*)(((((Zc3*)a2))->Z9e))))->ZPb))[(_m)-(Zrs(1))];
Z7I((Zi4*)(ZsG),Zno2);ZtI((Zi4*)(ZsG),(T11)(((((Ze4*)ZzR1))->_id)));Z7I((Zi4*)(ZsG),ZZe2);Zlo2(a1,a2,a3,_m);Z7I((Zi4*)(ZsG),Zoo2);Zlo2(a1,a2,(Z3)(((_m))+((T2)(Zrs(1)))),a4);
ZcH((Zi4*)(ZsG),((T3)'\175'));}}void Zpo2(T0*a1,T0*a2){T2 _i=0;T0*ZzR1=Zo;T0*ZAR1=Zo;Z7I((Zi4*)(ZsG),Zqo2);_i=Zrs(1);while(!((Z3)((_i)>((Z3)(((((((ZC3*)(((((Zc3*)a2))->Z9e))))->ZRb)))+(Zrs(1)))))))
{ZzR1=(((((ZC3*)(((((Zc3*)a2))->Z9e))))->ZPb))[(_i)-(Zrs(1))];ZAR1=ZCH(((Ze4*)ZzR1),a1);Z7I((Zi4*)(ZsG),Zro2);ZtI((Zi4*)(ZsG),(T11)(((((Ze4*)ZzR1))->_id)));
ZcH((Zi4*)(ZsG),((T3)'\072'));Zmo2((Zi4*)(ZsG),ZAR1,a1);Z7I((Zi4*)(ZsG),Zso2);_i=(Z3)(((_i))+(Zrs(1)));}if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){
Z7I((Zi4*)(ZsG),Zto2);}Z7I((Zi4*)(ZsG),ZdI);}T0*Zuo2(T0*a1){T0*R=Zo;((((T7*)((T7*)(Zvo2))))->Zcc)=(Zrs(0));ZZs((T7*)(Zvo2),((T3)'X'));
ZQs((((Ze4*)(((((ZS7*)a1))->Znf)))->_id),Zvo2);ZXw((T7*)(Zvo2),(((ZB8*)(((((ZS7*)a1))->Zkc)))->Z3n));R=Zvo2;return R;}T0*Zvo2=Zo;void
Zwo2(T0*a1){T6 ZlY=0;T0*ZAb=Zo;T0*Zcd=Zo;T0*Zgc=Zo;T0*Zxo2=Zo;T2 _i=0;T0*_fn=Zo;T0*Zof=Zo;ZlY=((T6)(((((T84*)(ZFI))->Zcf))==(Zrs(1))));
ZAb=ZcL(a1);Zgc=ZqG(a1);((((T7*)((T7*)(Zvo2))))->Zcc)=(Zrs(0));if((Zgc)==((void*)(Zo))){ZXw((T7*)(Zvo2),Z9N);}else{Zgc=ZvG(Zgc);ZXU(Zgc,Zvo2);
}ZZs((T7*)(Zvo2),((T3)'\040'));ZZs((T7*)(Zvo2),((T3)'X'));ZQs(ZuI(((((ZS7*)a1))->Z0c)),Zvo2);{ZB8*C1=(ZB8*)(((((ZS7*)a1))->Zkc));T0*b1=Zvo2;
ZXw(((T7*)b1),((C1)->Z3n));}if(ZlY){ZXw((T7*)(Zvo2),Zyo2);}else{ZXw((T7*)(Zvo2),Zzo2);}if((ZAb)!=((void*)(Zo))){_i=Zrs(1);while(!((Z3)((_i)>(Zty(((Zn2*)(((((ZH6*)ZAb))->Zhe))))))))
{ZZs((T7*)(Zvo2),((T3)'\054'));Zxo2=ZvG(ZI71(((ZH6*)ZAb),_i));ZEZ(Zxo2,Zvo2);ZXw((T7*)(Zvo2),ZAo2);ZQs(_i,Zvo2);_i=(Z3)(((_i))+(Zrs(1)));
}}ZZs((T7*)(Zvo2),((T3)'\051'));ZyI((Zi4*)(ZsG),Zvo2);ZES((Zi4*)(ZsG));if((T6)(((((T41*)(Z1G))->ZPk))&&((T6)(Z2H(((((ZS7*)a1))->Z0c)))))){
Z7I((Zi4*)(ZsG),ZBo2);}if((Zgc)!=((void*)(Zo))){((((T7*)((T7*)(Zvo2))))->Zcc)=(Zrs(0));ZXU(Zgc,Zvo2);ZZs((T7*)(Zvo2),((T3)'\040'));ZZs((T7*)(Zvo2),((T3)'R'));
if(!(ZlY)){ZZs((T7*)(Zvo2),((T3)'\075'));Z8Z(Zgc,Zvo2);}ZXw((T7*)(Zvo2),Z8M);Z7I((Zi4*)(ZsG),Zvo2);}if(!(ZlY)){Z7I((Zi4*)(ZsG),ZCo2);
_fn=((((ZS7*)a1))->Zkc);Zcd=ZBM1(((ZB8*)_fn));if((Zcd)!=((void*)(Zo))){Z7I((Zi4*)(ZsG),Zcd);ZcH((Zi4*)(ZsG),((T3)'\040'));}Z7I((Zi4*)(ZsG),((((ZB8*)_fn))->Zre));
ZcH((Zi4*)(ZsG),((T3)'\042'));Z7I((Zi4*)(ZsG),ZDo2);}Z7I((Zi4*)(ZsG),ZEo2);Zof=(((Ze4*)(((((ZS7*)a1))->Znf)))->Zof);if(ZlY){Z7I((Zi4*)(ZsG),ZFo2);
}else{Z7I((Zi4*)(ZsG),ZGo2);}if(!(ZlY)){ZHo2(a1,ZIo2,ZrE1);}if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(7)))){Zpo2(a1,Zof);}else{Zlo2(a1,Zof,(T2)(Zrs(1)),(Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))));
}Z7I((Zi4*)(ZsG),ZdI);if(!(ZlY)){ZHo2(a1,ZdO1,ZvE1);}if((Zgc)!=((void*)(Zo))){Z7I((Zi4*)(ZsG),ZtN1);}else{Z7I((Zi4*)(ZsG),ZdI);}}void
Zhc1(T0*a1){T0*_rf=Zo;_rf=((((ZA1*)a1))->Z_b);if(!(Z0A((Z_5*)(ZJo2),_rf))){Z2A((Z_5*)(ZJo2),_rf);Z0z((Zq4*)(ZKo2),a1);}}T0*ZKo2=Zo;T0*ZJo2=Zo;
T0*ZLo2=Zo;void ZMo2(T84*C,T0*a1){T6 ZSY1=0;T6 ZNo2=0;if(ZOo2(C,ZvZ1)){ZPo2(C,ZvF(40,"The \"use\" clause is not yet implemented."));}
if(ZOo2(C,ZQo2)){while(!((((C)->_cc))!=(((T3)'\042')))){Zkf1(((T85*)a1),ZRo2(C));if(ZSo2(C,((T3)'\073'))){}}}if(ZOo2(C,ZTo2)){while(!((((C)->_cc))!=(((T3)'\042'))))
{Zhf1(((T85*)a1),ZRo2(C));if(ZSo2(C,((T3)'\073'))){}}}if(ZOo2(C,ZUo2)){ZPo2(C,ZvF(42,"The \"adapt\" clause is not yet implemented."));
}if(ZOo2(C,ZVo2)){while(!(ZSY1)){if(ZOo2(C,ZWo2)){((((T85*)(((T85*)a1))))->Zcf)=(ZXo2(C));}else if(ZOo2(C,ZYo2)){ZNo2=((T6)(ZZo2(C)));
(C->Zif)=((T6)((T6)((((C)->Zif))||((T6)(ZNo2)))));Zcg1(((T85*)a1),(T6)(ZNo2));}else if(ZOo2(C,Z8g1)){ZDf1(((T85*)a1),Z_o2(C));}else{ZSY1=((T6)(1));
}if(ZSo2(C,((T3)'\073'))){}}}if(ZOo2(C,Z0p2)){while(!(!(Z1p2(C,a1)))){}}}void Z2p2(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);
}ZoK((T75*)(ZyF));}T0*Z3p2(T84*C){T0*R=Zo;T6 ZSY1=0;T76 _p={Zo,Zo,0};T0*Z4p2=Zo;T0*Zde=Zo;T0*_cl=Zo;T2 _c=0;T2 _l=0;R=Z5p2;((((T7*)(((T7*)R))))->Zcc)=(Zrs(0));
if(ZSo2(C,((T3)'\042'))){{T76 Z3w;_p=(*(Z3w=Z6p2(((C)->Z0f),((C)->Z1f)),&Z3w));}while(!(ZSY1)){{int z1=((C)->_cc);switch(z1){case 34:
ZSY1=((T6)(1));break;case 0:ZzF(_p);{T0*b1=ZvF(20,"Closing \" not found.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));break;case 36:_l=((C)->ZXe);
_c=((C)->ZWe);_cl=((C)->ZYe);Z7p2(C);if((((C)->_cc))==(((T3)'\173'))){Z7p2(C);{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z6x(n,(T2)(Zrs(12)));
Z4p2=((T0*)n);}}else{ZZs(((T7*)R),((T3)'\044'));(C->ZXe)=_l;(C->ZWe)=_c;(C->ZYe)=_cl;}while(!((Z4p2)==((void*)(Zo)))){{int z2=((C)->_cc);
switch(z2){case 125:Zde=(((void)((T36*)(Z8p2()))),Z7s1(Z4p2,((C)->Z3f)));if((Zde)!=((void*)(Zo))){ZXw(((T7*)R),Zde);}Z4p2=Zo;break;case
0:ZzF(_p);{T0*b1=ZvF(50,"Bad Environment variable.\n(Closing \"\175""\" not found.)");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));break;default:;
ZZs(((T7*)Z4p2),((C)->_cc));Z7p2(C);}}}break;default:;ZZs(((T7*)R),((C)->_cc));}}Z7p2(C);}}else{while(!(ZSY1)){{int z1=((C)->_cc);switch(z1){
case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:
case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:
case 89:case 90:case 95:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case
109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:ZZs(((T7*)R),((C)->_cc));
Z7p2(C);break;default:;ZSY1=((T6)(1));}}}}if((((((T7*)R))->Zcc))==(Zrs(0))){ZPo2(C,ZvF(29,"Non empty name expected here."));}Z9p2(C);
return R;}void Zap2(T84*C){if(ZSo2(C,((T3)'\050'))){if((ZRo2(C))!=((void*)(Zo))){}if(ZSo2(C,((T3)'\051'))){}}}void Zbp2(T84*C,T0*a1){
if((Zfu1())==((void*)(Zo))){(((void)((T36*)(Z8p2()))),ZUf1(a1));(((void)((T36*)(Z8p2()))),ZUf1(ZvF(42,": error: No <Root-Class> in command line.\n")));
Zv(Zrs(1));}if((T6)((Zcp2(C))&&((T6)((((C)->Zcf))==(Zrs(1)))))){(((void)((T36*)(Z8p2()))),ZUf1(a1));(((void)((T36*)(Z8p2()))),ZUf1(ZvF(37,": cannot use -sedb with -boost flag.\n")));
Zv(Zrs(1));}Z5z1((T48*)(Zdp2()));Zep2(C);}void Zfp2(T84*C){T2 _i=0;if((((C)->Z3f))!=((void*)(Zo))){_i=Zrs(0);while(!((Z3)((_i)>((((ZP8*)(Znw1))->ZRb)))))
{Znf1((T85*)(((((ZP8*)(Znw1))->ZPb))[_i]));_i=(Z3)(((_i))+(Zrs(1)));}}}T0*Zgp2(T0*a1,T6 a2){T0*R=Zo;{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;
Zvf1(n,a1,(T6)(a2));R=((T0*)n);}ZAA((ZP8*)(Znw1),R);return R;}T6 ZZo2(T84*C){T6 R=0;if(!(ZSo2(C,((T3)'\050')))){{T84*C1=C;T0*b1=Zhp2;
{T76 Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}if(ZOo2(C,Z2g1)){}else if((T6)((ZOo2(C,Z7g1))||((T6)(ZOo2(C,Z9g1))))){R=((T6)(1));}else{ZPo2(C,ZvF(77,"At this point in the ACE file, you are supposed to say \"yes\", \"no\", or \"all\"."));
}if(!(ZSo2(C,((T3)'\051')))){{T84*C1=C;T0*b1=Zjp2;{T76 Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}return R;}T0*Zkp2=Zo;T0*Z5p2=Zo;T6 Z1p2(T84*C,T0*a1){
T6 R=0;T2 Zlp2=0;T0*Zmp2=Zo;T0*Znp2=Zo;if(ZOo2(C,ZWo2)){R=((T6)(1));Zlp2=ZXo2(C);if(!(ZSo2(C,((T3)'\072')))){{T84*C1=C;T0*b1=Zop2;{T76
Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}while(!(!(Zpp2(C)))){Zmp2=Zqp2(&(((C)->Z2f)));Zag1(((T85*)a1),Zmp2,Zlp2);if(ZSo2(C,((T3)'\054'))){
}}}else if(ZOo2(C,ZYo2)){(C->Zif)=((T6)(1));R=((T6)(1));if(!(ZSo2(C,((T3)'\072')))){{T84*C1=C;T0*b1=Zop2;{T76 Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);
}}}while(!(!(Zpp2(C)))){Zmp2=Zqp2(&(((C)->Z2f)));Zdg1(((T85*)a1),Zmp2);if(ZSo2(C,((T3)'\054'))){}}}else if(ZOo2(C,Z8g1)){R=((T6)(1));
Znp2=Z_o2(C);if(!(ZSo2(C,((T3)'\072')))){{T84*C1=C;T0*b1=Zop2;{T76 Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}while(!(!(Zpp2(C)))){Zmp2=Zqp2(&(((C)->Z2f)));
Zgg1(((T85*)a1),Zmp2,Znp2);if(ZSo2(C,((T3)'\054'))){}}}return R;}void Zrp2(T84*C){T0*Zsp2=Zo;Zsp2=Ztp2;ZBw(((T7*)Zsp2),Zup2(((C)->Zaf)));
if(!(ZNu(((T7*)Zsp2),Z1g1))){ZXw(((T7*)Zsp2),Zvp2);}ZCz1((T48*)(Zdp2()),Zsp2);}T0*Zdp2(void){if(ZNY==0){ZNY=1;{{T48*n=((T48*)Zh(sizeof(*n)));
*n=M48;ZMY=((T0*)n);ZPY(n);}}}return ZMY;}void Zwp2(T0*a1){T2 _i=0;T3 _c=0;ZBw((T7*)(Zxp2),a1);_i=(((T7*)(Zxp2))->Zcc);if((Z3)((_i)>(Zrs(2)))){
if((((((T7*)(Zxp2))->ZPb))[((Z3)(((_i))-(Zrs(1))))-(Zrs(1))])==(((T3)'\056'))){if(Zts(((((T7*)(Zxp2))->ZPb))[(_i)-(Zrs(1))],((T3)'e'))){
Zex((T7*)(Zxp2),(T2)(Zrs(2)));}}}_i=(((T7*)(Zxp2))->Zcc);while(!((_i)==(Zrs(0)))){_c=((((T7*)(Zxp2))->ZPb))[(_i)-(Zrs(1))];if(Zss(_c)){
_i=(Z3)(((_i))-(Zrs(1)));}else if((_c)==(((T3)'\137'))){_i=(Z3)(((_i))-(Zrs(1)));}else if(Zjs(_c)){_i=(Z3)(((_i))-(Zrs(1)));}else{ZDw((T7*)(Zxp2),_i);
_i=Zrs(0);}}Zmx((T7*)(Zxp2));}T6 Zyp2(T84*C){T6 R=0;T0*Zzp2=Zo;T0*Zcg=Zo;if((((C)->_cc))==(((T3)'\000'))){}else if(ZOo2(C,ZAp2)){ZBp2(C);
}else if(ZOo2(C,ZCp2)){ZDp2(C);}else if(ZOo2(C,ZEp2)){}else if((((C)->_cc))==(((T3)'\042'))){R=((T6)(1));Zcg=Zgp2(Z3p2(C),(T6)(0));ZMo2(C,Zcg);
}else if(Zss(((C)->_cc))){R=((T6)(1));Zzp2=ZRo2(C);if(ZSo2(C,((T3)'\072'))){if((((C)->_cc))==(((T3)'\042'))){Zcg=Zgp2(Z3p2(C),(T6)(0));
((((T85*)(((T85*)Zcg))))->Zkc)=(Zzp2);}else{{T76 Z3w;ZzF((*(Z3w=Zip2(C),&Z3w)));}{T0*b1=ZvF(41,"Cluster path expected after cluster name.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}else{Zcg=Zgp2(Zzp2,(T6)(0));}ZMo2(C,Zcg);}else{ZFp2(C,ZGp2);}return R;}void ZXy1(T0*a1){T0*ZHp2=Zo;
Zwp2(a1);ZHp2=ZRs((T7*)(Zxp2));ZHp2=(((void)((T26*)(ZIp2()))),ZAS(ZHp2));ZPz((T52*)(ZLo2),ZHp2);}T6 ZoJ1(T84*C,T0*a1){T6 R=0;T0*Zqb=Zo;
T0*Zcg=Zo;Zqb=((((((ZI1*)a1))->Zxb)).Zqb);Zcg=((((T82*)Zqb))->Zcg);if((Zcg)!=((void*)(Zo))){R=((T6)(Zzf1(((T85*)Zcg),((((T82*)Zqb))->Zkc),a1)));
}else{R=((T6)(ZBf1(C,a1)));}if(R){if((((C)->Zcf))==(Zrs(1))){(C->Zcf)=Zrs(2);}}return R;}void ZFp2(T84*C,T0*a1){{T76 Z3w;ZzF((*(Z3w=Zip2(C),&Z3w)));
}{T0*b1=ZvF(14,"Error in the \"");ZXw((T7*)(ZwF),b1);}{T0*b1=a1;ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(10,"\" section.");ZXw((T7*)(ZwF),b1);}
ZEF((T75*)(ZyF));}void ZPo2(T84*C,T0*a1){{T76 Z3w;ZzF((*(Z3w=Zip2(C),&Z3w)));}{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}T0*ZRo2(T84*C){
T0*R=Zo;R=(((void)((T26*)(ZIp2()))),ZAS(Z3p2(C)));return R;}T0*ZJp2(void){if(ZGf1==0){ZGf1=1;{{T72*n=((T72*)Zh(sizeof(*n)));*n=M72;ZFf1=((T0*)n);
ZIf1(n);}}}return ZFf1;}T2 Z1j1(T84*C,T0*a1){T2 R=0;T0*Zcg=Zo;Zcg=((((T82*)a1))->Zcg);if((Zcg)!=((void*)(Zo))){R=ZEf1(((T85*)Zcg),((((T82*)a1))->Zkc));
}else{R=((C)->Zcf);}return R;}void ZKp2(T84*C){if((((C)->Zcf))==(Zrs(0))){(C->Zcf)=Zrs(7);}ZLp2(C,((C)->Zcf));Zrp2(C);}void ZMp2(T84*C){
T2 _i=0;if(!(((C)->Zhf))){(C->Zhf)=((T6)(1));_i=Zrs(0);while(!((Z3)((_i)>((((ZP8*)(Znw1))->ZRb))))){ZLf1((T85*)(((((ZP8*)(Znw1))->ZPb))[_i]));
_i=(Z3)(((_i))+(Zrs(1)));}}}T6 ZSo2(T84*C,T3 a1){T6 R=0;if((a1)==(((C)->_cc))){(C->Z0f)=((C)->ZXe);(C->Z1f)=((C)->ZWe);R=((T6)(1));Z7p2(C);
Z9p2(C);}return R;}T6 ZOo2(T84*C,T0*a1){T6 R=0;T2 _c=0;T2 _i=0;T2 _j=0;_i=((C)->ZWe);_c=((((T7*)a1))->Zcc);if((Z3)(((Z3)((((Z3)((((((T7*)(((C)->ZYe)))->Zcc)))-(_i))))+(Zrs(1))))>=(_c))){
(C->Z0f)=((C)->ZXe);(C->Z1f)=_i;_j=Zrs(1);while(!((Z3)((_c)<=(Zrs(0))))){if(Zts(((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))],(((((T7*)a1))->ZPb))[(_j)-(Zrs(1))])){
_i=(Z3)(((_i))+(Zrs(1)));_j=(Z3)(((_j))+(Zrs(1)));_c=(Z3)(((_c))-(Zrs(1)));}else{_c=Zrs(-1);}}}if((_c)==(Zrs(0))){if((Z3)((_i)>((((T7*)(((C)->ZYe)))->Zcc)))){
R=((T6)(1));(C->_cc)=((T3)'\n');(C->ZWe)=_i;Z9p2(C);}else{{int z1=((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))];switch(z1){case 9:case 32:
case 45:R=((T6)(1));(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))];(C->ZWe)=_i;Z9p2(C);break;case 48:case 49:case 50:case 51:case
52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case
76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 95:case 97:case
98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:
case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:break;default:;R=((T6)(1));(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))];
(C->ZWe)=_i;}}}}return R;}T76 Zip2(T84*C){T76 R={Zo,Zo,0};{T76 Z3w;R=(*(Z3w=Z6p2(((C)->ZXe),((C)->ZWe)),&Z3w));}return R;}T0*ZNp2(void){
if(ZDI==0){ZDI=1;{{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZGk;ZCI=((T0*)n);}}}return ZCI;}T0*Z8p2(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));
*n=M36;ZQK=((T0*)n);}}}return ZQK;}T0*Zfu1(void){T0*R=Zo;if((Z3)(((Z3)((((((T52*)(ZLo2))->ZRb)))+(Zrs(1))))>(Zrs(0)))){R=ZGz((T52*)(ZLo2));
}return R;}void ZDp2(T84*C){T6 ZSY1=0;T6 Zde=0;while(!(ZSY1)){if((((C)->_cc))==(((T3)'\000'))){ZSY1=((T6)(1));}else if(ZSo2(C,((T3)'\073'))){
}else if(ZOo2(C,ZOp2)){if(ZSo2(C,((T3)'\072'))){}Ztz1((T48*)(Zdp2()),ZRo2(C));}else if(ZOo2(C,ZPp2)){if(ZZo2(C)){ZSE1((Zh8*)(ZNp2()));
}}else if(ZOo2(C,ZQp2)){if(ZZo2(C)){((((T48*)((T48*)(Zdp2()))))->Z8i)=(1);}}else if(ZOo2(C,ZRp2)){if(ZZo2(C)){((((T84*)(C)))->Z5f)=(1);
}}else if(ZOo2(C,ZSp2)){((((T84*)(C)))->Zdf)=((T6)(ZZo2(C)));}else if(ZOo2(C,ZTp2)){Zde=((T6)(ZZo2(C)));if(!(((C)->Z9f))){((((T84*)(C)))->Z9f)=((T6)(Zde));
}}else if(ZOo2(C,ZUp2)){((((T84*)(C)))->Zef)=((T6)(ZZo2(C)));}else if(ZOo2(C,ZVp2)){if(ZSo2(C,((T3)'\072'))){}((((T48*)((T48*)(Zdp2()))))->Zki)=(ZRo2(C));
}else if(ZOo2(C,ZWp2)){if(ZSo2(C,((T3)'\072'))){}((((T48*)((T48*)(Zdp2()))))->Zli)=(ZRo2(C));}else if(ZOo2(C,ZXp2)){if(ZSo2(C,((T3)'\072'))){
}Z1w1((T48*)(Zdp2()),ZRo2(C));}else if(ZOo2(C,ZYp2)){((((Zi4*)((Zi4*)(ZsG))))->ZGf)=((T6)(ZZo2(C)));}else{ZSY1=((T6)(1));}}}void ZBp2(T84*C){
T6 ZSY1=0;while(!(ZSY1)){if((((C)->_cc))==(((T3)'\000'))){ZSY1=((T6)(1));}else if(ZOo2(C,ZCp2)){ZDp2(C);ZSY1=((T6)(1));}else if(ZSo2(C,((T3)'\073'))){
}else if(ZOo2(C,ZZp2)){if(ZSo2(C,((T3)'\072'))){}ZBw((T7*)(Zou1),ZRo2(C));}else if(ZOo2(C,Z_p2)){if(ZSo2(C,((T3)'\072'))){}(((void)((T48*)(Zdp2()))),ZAy1(ZRo2(C)));
}else if(ZOo2(C,Z0q2)){if(ZSo2(C,((T3)'\072'))){}ZBw((T7*)(Zpu1),ZRo2(C));}else if(ZOo2(C,Z1q2)){if(ZSo2(C,((T3)'\072'))){}ZBw((T7*)(Znu1),ZRo2(C));
}else if(ZOo2(C,Z2q2)){Z3q2((ZL6*)(ZPK),Z_o2(C));}else if(ZOo2(C,Z4q2)){if(ZSo2(C,((T3)'\072'))){}(((void)((T48*)(Zdp2()))));{T0*b1=ZRo2(C);
ZPz((T52*)(ZEx1),b1);}}else if(ZOo2(C,Z5q2)){if(ZSo2(C,((T3)'\072'))){}(((void)((T48*)(Zdp2()))));{T0*b1=ZRo2(C);ZPz((T52*)(Zyz1),b1);
}}else{ZSY1=((T6)(1));}}}void Z6q2(T84*C,T0*a1){T6 Z7q2=0;if((((C)->Z3f))!=((void*)(Zo))){(((void)((T36*)(Z8p2()))),ZUf1(ZvF(41,"Multiple ACE files in the command line: \"")));
(((void)((T36*)(Z8p2()))),ZUf1(((C)->Z3f)));(((void)((T36*)(Z8p2()))),ZUf1(ZvF(7,"\" and \"")));(((void)((T36*)(Z8p2()))),ZUf1(a1));(((void)((T36*)(Z8p2()))),ZUf1(ZvF(3,Zyo)));
Zv(Zrs(1));}(C->Z3f)=a1;ZKf1((T72*)(ZJp2()),a1);if(!(((((T72*)(ZJp2()))->Zoc))!=(Zo))){{T0*b1=ZvF(13,"Cannot open \"");ZXw((T7*)(ZwF),b1);
}{T0*b1=a1;ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(27,"\" file.\nACE file not found.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}Z7L((T36*)(Z8p2()),ZvF(9,"Parsing \""));
Z7L((T36*)(Z8p2()),((C)->Z3f));Z7L((T36*)(Z8p2()),ZvF(12,"\" ACE file.\n"));(C->ZXe)=Zrs(1);(C->ZWe)=Zrs(1);(C->ZYe)=(((((T52*)((((T72*)(ZJp2()))->Z2l))))->ZPb))[((C)->ZXe)];
ZLp2(C,Zrs(1));if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}(C->Z_e)=((T6)(1));
Z9p2(C);if(!(ZOo2(C,Z8q2))){{T76 Z3w;ZzF((*(Z3w=Zip2(C),&Z3w)));}{T0*b1=ZvF(44,"Keyword \"system\" expected. Invalid ACE file.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}(C->Z4f)=ZRo2(C);if(!(ZOo2(C,Z9q2))){{T76 Z3w;ZzF((*(Z3w=Zip2(C),&Z3w)));}{T0*b1=ZvF(42,"Keyword \"root\" expected. Invalid ACE file.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}{T0*b1=ZRo2(C);ZPz((T52*)(ZLo2),b1);}Zap2(C);if(ZSo2(C,((T3)'\072'))){(C->Zgf)=ZRo2(C);}if(ZOo2(C,ZVo2)){
Z7q2=((T6)(Zaq2(C)));}if(Zbq2(C)){}if(ZOo2(C,ZAp2)){ZBp2(C);}if(ZOo2(C,ZCp2)){ZDp2(C);}if(ZOo2(C,ZEp2)){}if((((C)->_cc))!=(((T3)'\000'))){
{T76 Z3w;ZzF((*(Z3w=Zip2(C),&Z3w)));}{T0*b1=ZvF(40,"End of text expected (invalid ACE file).");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}
Zb32((T72*)(ZJp2()));Zep2(C);if(Z7q2){((((T36*)((T36*)(Z8p2()))))->ZJh)=(1);}}T6 ZBf1(T84*C,T0*a1){T6 R=0;if((((C)->Zff))==((void*)(Z9g1))){
R=((T6)(1));}else if((((C)->Zff))==((void*)(Z2g1))){}else{R=((T6)(ZcV(((ZI1*)a1),((C)->Zff))));}return R;}T6 ZOk1(T84*C,T0*a1){T6 R=0;
T0*Zcg=Zo;Zcg=((((T82*)a1))->Zcg);if((Zcg)!=((void*)(Zo))){R=((T6)(Zlf1(((T85*)Zcg),((((T82*)a1))->Zkc))));}else{R=((T6)(((C)->Zbf)));
}if(R){if((((C)->Zcf))==(Zrs(1))){(C->Zcf)=Zrs(2);}}return R;}T6 Zbq2(T84*C){T6 R=0;T6 ZSY1=0;if(ZOo2(C,ZGp2)){R=((T6)(1));while(!(ZSY1))
{if(Zyp2(C)){if(ZSo2(C,((T3)'\073'))){}if(ZOo2(C,ZEp2)){}}else{ZSY1=((T6)(1));}}}return R;}T0*ZIp2(void){if(ZbP==0){ZbP=1;{{T26*n=((T26*)Zh(1));
ZaP=((T0*)n);ZdP(ZeP);ZdP(ZfP);ZdP(ZgP);ZdP(ZhP);ZdP(ZiP);ZdP(ZjP);ZdP(ZkP);ZdP(ZlP);ZdP(ZmP);ZdP(ZnP);ZdP(ZoP);ZdP(ZpP);ZdP(ZqP);ZdP(ZrP);
ZdP(ZpK);ZdP(ZsP);ZdP(ZtP);ZdP(ZuP);ZdP(ZvP);ZdP(ZwP);ZdP(ZxP);ZdP(ZyP);ZdP(ZzP);ZdP(ZAP);ZdP(ZBP);ZdP(ZCP);ZdP(ZDP);ZdP(ZEP);ZdP(ZFP);
ZdP(ZGP);ZdP(ZHP);ZdP(ZIP);ZdP(ZJP);ZdP(ZKP);ZdP(ZLP);ZdP(ZMP);ZdP(ZNP);ZdP(ZOP);ZdP(ZPP);ZdP(ZQP);ZdP(ZRP);ZdP(ZSP);ZdP(ZTP);ZdP(ZUP);
ZdP(ZVP);ZdP(ZWP);ZdP(ZXP);ZdP(ZYP);ZdP(ZZP);ZdP(Z_P);ZdP(Z0Q);ZdP(Z1Q);ZdP(Z2Q);ZdP(Z3Q);ZdP(Z4Q);ZdP(Z5Q);ZdP(Z6Q);ZdP(Z7Q);ZdP(Z8Q);
ZdP(Z9Q);ZdP(ZaQ);ZdP(ZbQ);ZdP(ZcQ);ZdP(ZdJ);ZdP(ZdQ);ZdP(ZeQ);ZdP(ZfQ);ZdP(ZgQ);ZdP(ZhQ);ZdP(ZiQ);ZdP(ZjQ);ZdP(ZkQ);ZdP(ZlQ);ZdP(ZmQ);
ZdP(ZnQ);ZdP(ZoQ);ZdP(ZpQ);ZdP(ZqQ);ZdP(ZDG);ZdP(ZrQ);ZdP(ZsQ);ZdP(ZtQ);ZdP(ZuQ);ZdP(ZvQ);ZdP(ZwQ);ZdP(ZxQ);ZdP(ZyQ);ZdP(ZzQ);ZdP(ZAQ);
ZdP(ZBQ);ZdP(ZCQ);ZdP(ZDQ);ZdP(ZEQ);ZdP(ZFQ);ZdP(ZGQ);ZdP(ZHQ);ZdP(ZIQ);ZdP(ZJQ);ZdP(ZKQ);ZdP(ZLQ);ZdP(ZMQ);ZdP(ZNQ);ZdP(ZOQ);ZdP(ZPQ);
ZdP(ZQQ);ZdP(ZRQ);ZdP(ZSQ);ZdP(ZTQ);ZdP(ZUQ);ZdP(ZVQ);ZdP(ZWQ);ZdP(ZXQ);ZdP(ZYQ);ZdP(ZZQ);ZdP(Z_Q);ZdP(Z0R);ZdP(Z1R);ZdP(Z2R);ZdP(Z3R);
ZdP(Z4R);ZdP(Z5R);ZdP(Z6R);ZdP(Z7R);ZdP(Z8R);ZdP(Z9R);ZdP(ZaR);ZdP(ZbR);ZdP(ZcR);ZdP(ZdR);ZdP(ZeR);ZdP(ZfR);ZdP(ZgR);ZdP(ZhR);ZdP(ZiR);
ZdP(ZjR);ZdP(ZkR);ZdP(ZlR);ZdP(ZmR);ZdP(ZnR);ZdP(ZoR);ZdP(ZpR);ZdP(ZqR);ZdP(ZrR);ZdP(ZsR);ZdP(ZtR);ZdP(ZuR);ZdP(ZvR);ZdP(ZwR);ZdP(ZxR);
ZdP(ZyR);ZdP(ZzR);ZdP(ZAR);ZdP(ZBR);ZdP(ZCR);ZdP(ZDR);ZdP(ZER);ZdP(ZFR);ZdP(ZGR);ZdP(ZHR);ZdP(ZIR);ZdP(ZJR);ZdP(ZKR);ZdP(ZLR);ZdP(ZMR);
ZdP(ZNR);ZdP(ZOR);ZdP(ZPR);ZdP(ZQR);ZdP(ZRR);ZdP(ZSR);ZdP(ZTR);ZdP(ZUR);ZdP(ZVR);ZdP(ZWR);ZdP(ZXR);ZdP(ZYR);ZdP(ZZR);ZdP(Z_R);ZdP(Z0S);
ZdP(Z1S);ZdP(Z2S);ZdP(Z3S);ZdP(Z4S);ZdP(Z5S);ZdP(Z6S);ZdP(Z7S);ZdP(Z8S);ZdP(Z9S);ZdP(ZaS);ZdP(ZbS);ZdP(ZcS);ZdP(ZdS);ZdP(ZeS);ZdP(ZfS);
ZdP(ZgS);ZdP(ZhS);ZdP(ZiS);ZdP(ZjS);ZdP(ZkS);ZdP(ZlS);ZdP(ZmS);ZdP(ZnS);ZdP(ZoS);}}}return ZaP;}T6 Zcq2(T84*C,T0*a1){T6 R=0;T2 _i=0;T0*Zcg=Zo;
T0*Zmp2=Zo;Zwp2(a1);Zmp2=(((void)((T26*)(ZIp2()))),ZAS(Zxp2));_i=Zrs(0);while(!((T6)(((Z3)((_i)>((((ZP8*)(Znw1))->ZRb))))||((T6)(R)))))
{Zcg=((((ZP8*)(Znw1))->ZPb))[_i];R=((T6)(ZYf1(((T85*)Zcg),Zmp2)));_i=(Z3)(((_i))+(Zrs(1)));}if((T6)((!(R))&&((T6)((((C)->Z3f))==((void*)(Zo)))))){
ZMp2(C);_i=Zrs(0);while(!((T6)(((Z3)((_i)>((((ZP8*)(Znw1))->ZRb))))||((T6)(R))))){Zcg=((((ZP8*)(Znw1))->ZPb))[_i];R=((T6)(Zqf1(((T85*)Zcg),Zmp2)));
_i=(Z3)(((_i))+(Zrs(1)));}}if(!(R)){(((void)((T36*)(Z8p2()))),ZUf1(ZvF(31,"Unable to find file for class \"")));(((void)((T36*)(Z8p2()))),ZUf1(a1));
(((void)((T36*)(Z8p2()))),ZUf1(ZvF(3,"\". ")));((((T7*)((T7*)(Z5p2))))->Zcc)=(Zrs(0));Zow1(C,Z5p2);(((void)((T36*)(Z8p2()))),ZUf1(Z5p2));
}return R;}void Z9p2(T84*C){T76 _sp={Zo,Zo,0};T6 ZSY1=0;while(!(ZSY1)){{int z1=((C)->_cc);switch(z1){case 9:case 10:case 32:Z7p2(C);break;
case 45:Z7p2(C);if((((C)->_cc))==(((T3)'\055'))){if(((C)->Z_e)){if((((C)->ZXe))==((((T72*)(ZJp2()))->Zcc))){(C->_cc)=((T3)'\000');ZSY1=((T6)(1));
}else{(C->ZXe)=(Z3)(((((C)->ZXe)))+(Zrs(1)));(C->ZWe)=Zrs(1);(C->ZYe)=(((((T52*)((((T72*)(ZJp2()))->Z2l))))->ZPb))[((C)->ZXe)];if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){
(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}}}else{{T76 Z3w;_sp=(*(Z3w=Z6p2(((C)->ZXe),(Z3)(((((C)->ZWe)))-((T2)(Zrs(1))))),&Z3w));
}Z7p2(C);((((T7*)((T7*)(Zkp2))))->Zcc)=(Zrs(0));while(!((((C)->_cc))==(((T3)'\n')))){ZZs((T7*)(Zkp2),((C)->_cc));Z7p2(C);}if((((C)->ZZe))==((void*)(Zo))){
{T86*n=((T86*)Zh(sizeof(*n)));*n=M86;ZNa1(n,_sp,ZRs((T7*)(Zkp2)));(C->ZZe)=((T0*)n);}}else{ZWA(((T74*)((((T86*)(((C)->ZZe)))->ZUb))),ZRs((T7*)(Zkp2)));
}}}else{(C->_cc)=((T3)'\055');(C->ZWe)=(Z3)(((((C)->ZWe)))-(Zrs(1)));ZSY1=((T6)(1));}break;default:;ZSY1=((T6)(1));}}}}T0*Zup2(T2 a1){
T0*R=Zo;{int z1=a1;switch(z1){case 0:R=Z0g1;break;case 1:R=Z1g1;break;case 2:R=Z2g1;break;case 3:R=Z3g1;break;case 4:R=Z4g1;break;case
5:R=Z5g1;break;case 6:R=Z6g1;break;case 7:R=Z7g1;break;default:;R=Z8g1;}}return R;}void Zww1(T0*a1,T0*a2,T6 a3){T0*Zcg=Zo;Zcg=Zgp2(a1,(T6)(a3));
if((a2)!=((void*)(Zo))){((((T85*)(((T85*)Zcg))))->Zkc)=((((void)((T26*)(ZIp2()))),ZAS(a2)));}}T6 Zpp2(T84*C){T6 R=0;if(Zxs(((C)->_cc))){
{T76 Z3w;Zdq2(&(((C)->Z2f)),(*(Z3w=Z6p2(((C)->ZXe),((C)->ZWe)),&Z3w)));}{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}while(!(R)){Z7p2(C);{int
z1=((C)->_cc);switch(z1){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case
68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case
85:case 86:case 87:case 88:case 89:case 90:case 95:{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}break;default:;R=((T6)(1));}}}Z9p2(C);}return
R;}T0*Zxp2=Zo;T2 ZXo2(T84*C){T2 R=0;if(!(ZSo2(C,((T3)'\050')))){{T84*C1=C;T0*b1=Zhp2;{T76 Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}if(ZOo2(C,Z1g1)){
R=Zrs(1);}else if(ZOo2(C,Z2g1)){R=Zrs(2);}else if(ZOo2(C,Z3g1)){R=Zrs(3);}else if(ZOo2(C,Z4g1)){R=Zrs(4);}else if(ZOo2(C,Z5g1)){R=Zrs(5);
}else if(ZOo2(C,Z6g1)){R=Zrs(6);}else if((T6)(((T6)((ZOo2(C,Zfq2))||((T6)(ZOo2(C,Z7g1)))))||((T6)(ZOo2(C,Z9g1))))){R=Zrs(7);}else if(ZOo2(C,Z8g1)){
R=Zrs(8);}else{{T76 Z3w;ZzF((*(Z3w=Zip2(C),&Z3w)));}{T0*b1=ZvF(28,"Unknown assertion level tag.");ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));
{T0*b1=ZvF(154,"You have to fix the problem in your ACE file. Valid assertion level tags are: \"no\", \"require\", \"ensure\", \"invariant\", \"loop\", \"check\", \"all\", and \"debug\".");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}if(!(ZSo2(C,((T3)'\051')))){{T84*C1=C;T0*b1=Zjp2;{T76 Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}ZLp2(C,R);
return R;}T6 Zcp2(T84*C){T6 R=0;R=((T6)((T6)(((Z3)((((C)->Zcf))>=(Zrs(2))))&&((T6)(((C)->Zif))))));return R;}T0*ZVf1(T0*a1){T0*R=Zo;T2
_i=0;_i=Zrs(0);while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((_i)>((((ZP8*)(Znw1))->ZRb)))))))){R=Zbg1((T85*)(((((ZP8*)(Znw1))->ZPb))[_i]),a1);
_i=(Z3)(((_i))+(Zrs(1)));}return R;}void Z7p2(T84*C){if((Z3)((((C)->ZWe))<((((T7*)(((C)->ZYe)))->Zcc)))){(C->ZWe)=(Z3)(((((C)->ZWe)))+(Zrs(1)));
(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[(((C)->ZWe))-(Zrs(1))];}else if((((C)->ZWe))==((((T7*)(((C)->ZYe)))->Zcc))){(C->ZWe)=(Z3)(((((C)->ZWe)))+(Zrs(1)));
(C->_cc)=((T3)'\n');}else if((((C)->ZXe))==((((T72*)(ZJp2()))->Zcc))){(C->_cc)=((T3)'\000');}else{(C->ZXe)=(Z3)(((((C)->ZXe)))+(Zrs(1)));
(C->ZWe)=Zrs(1);(C->ZYe)=(((((T52*)((((T72*)(ZJp2()))->Z2l))))->ZPb))[((C)->ZXe)];if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){(C->_cc)=((T3)'\n');
}else{(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}}}T0*Znw1=Zo;T6 Zaq2(T84*C){T6 R=0;T6 ZSY1=0;while(!(ZSY1)){if((((C)->_cc))==(((T3)'\000'))){
ZSY1=((T6)(1));}else if(Zbq2(C)){ZSY1=((T6)(1));}else if(ZOo2(C,ZAp2)){ZBp2(C);ZSY1=((T6)(1));}else if(ZOo2(C,ZCp2)){ZDp2(C);ZSY1=((T6)(1));
}else if(ZSo2(C,((T3)'\073'))){}else if(ZOo2(C,ZWo2)){(C->Zcf)=ZXo2(C);}else if(ZOo2(C,Z8g1)){(C->Zff)=Z_o2(C);}else if(ZOo2(C,Zgq2)){
if(!(ZZo2(C))){Z9F1((Zh8*)(ZNp2()));}}else if(ZOo2(C,Zhq2)){if(ZZo2(C)){Ziq2((ZK9*)(ZOK));}}else if(ZOo2(C,Zjq2)){if(ZZo2(C)){((((ZK9*)((ZK9*)(ZOK))))->Zbm)=(1);
}}else if(ZOo2(C,Zkq2)){if(ZZo2(C)){((((T75*)((T75*)(ZyF))))->ZCg)=(1);}}else if(ZOo2(C,ZYo2)){if(ZZo2(C)){Zlq2(C);}}else if(ZOo2(C,Zmq2)){
if(ZZo2(C)){((((T84*)(C)))->Z6f)=(1);}}else if(ZOo2(C,Znq2)){R=((T6)(ZZo2(C)));}else if(ZOo2(C,Zoq2)){(C->Z7f)=((T6)(ZZo2(C)));}else if(ZOo2(C,Zpq2)){
(C->Z8f)=((T6)(ZZo2(C)));}else{ZSY1=((T6)(1));}}return R;}T0*Z_o2(T84*C){T0*R=Zo;if(!(ZSo2(C,((T3)'\050')))){{T84*C1=C;T0*b1=Zhp2;{T76
Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}if(ZOo2(C,Z2g1)){R=Z2g1;}else if((T6)((ZOo2(C,Z9g1))||((T6)(ZOo2(C,Z7g1))))){ZLp2(C,Zrs(8));R=Z9g1;
}else{ZLp2(C,Zrs(8));R=ZRo2(C);}if(!(ZSo2(C,((T3)'\051')))){{T84*C1=C;T0*b1=Zjp2;{T76 Z3w;Z2p2((*(Z3w=Zip2(C1),&Z3w)),b1);}}}return R;
}T0*Zqq2(T84*C){T0*R=Zo;T0*_bc=Zo;T0*_cn=Zo;if((((C)->Zgf))==((void*)(Zo))){{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Z721(n,Zfu1());_cn=((T0*)n);
}_bc=Z821(_cn);(C->Zgf)=Zcj1(((T82*)_bc));}R=((C)->Zgf);return R;}void Zlq2(T84*C){(C->Zbf)=((T6)(1));(C->Zif)=((T6)(1));}T76 Z6p2(T2
a1,T2 a2){T76 R={Zo,Zo,0};{T76*C1=&R;T2 b1=a1;T2 b2=a2;Z4j1(C1,b1,b2,Zft(32767),Zo);}return R;}void Zep2(T84*C){T2 _i=0;ZKp2(C);Zxz1((T48*)(Zdp2()));
if((((C)->Zff))==((void*)(Zo))){(C->Zff)=Z2g1;}_i=(((ZP8*)(Znw1))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){Zeg1((T85*)(((((ZP8*)(Znw1))->ZPb))[_i]));
_i=(Z3)(((_i))-(Zrs(1)));}}void Zow1(T84*C,T0*a1){T2 _i=0;T2 _no=0;T0*Zrq2=Zo;if((((T41*)(Z1G))->ZKk)){}else if((((C)->Z3f))==((void*)(Zo))){
ZXw(((T7*)a1),ZvF(346,"\nYou are in command line mode (i.e. no ACE file is used).\nThe load path can be changed using a file called\nloadpath.se in the current working directory.\nUsually, this loadpath.se file is a simple list of directories.\nIt is also possible to use system variables or include files. See\nthe documentation for the finder command for more information.\n"));
}else{ZXw(((T7*)a1),ZvF(70,"\nEiffel class file searching is being done according to the ACE file \""));ZXw(((T7*)a1),((C)->Z3f));ZXw(((T7*)a1),ZvF(3,Zyo));
}if((((T41*)(Z1G))->ZKk)){ZXw(((T7*)a1),ZvF(62,"(Command pretty only looks in the current working directory.)\n"));}else{ZXw(((T7*)a1),ZvF(64,"Files are being searched for in the following list of clusters ("));
ZQs((Z3)((((((ZP8*)(Znw1))->ZRb)))+(Zrs(1))),a1);ZXw(((T7*)a1),ZvF(9," items):\n"));_i=Zrs(0);while(!((Z3)((_i)>((((ZP8*)(Znw1))->ZRb)))))
{_no=(Z3)(((_no))+(Zrs(1)));Zfg1((T85*)(((((ZP8*)(Znw1))->ZPb))[_i]),_no,a1);_i=(Z3)(((_i))+(Zrs(1)));}ZBx1((T48*)(Zdp2()),a1);ZXw(((T7*)a1),ZvF(57,"The value of the environment variable \"SmartEiffel\" is:\n\""));
Zrq2=(((void)((T36*)(Z8p2()))),Z7s1(Zfs1,Zo));if((Zrq2)!=((void*)(Zo))){ZXw(((T7*)a1),Zrq2);}ZXw(((T7*)a1),ZvF(3,Zyo));if((((C)->Z3f))!=((void*)(Zo))){
ZXw(((T7*)a1),ZvF(111,"Please, also note that you can use the \"ace_check\" command\nto view all informations stored into your ACE file.\n"));
}}}void Zsq2(T84*C){(C->Zcf)=Zrs(8);(C->Zff)=Z9g1;}void ZLp2(T84*C,T2 a1){if((Z3)((a1)>(((C)->Zaf)))){(C->Zaf)=a1;}}
#ifdef __cplusplus
}
#endif

