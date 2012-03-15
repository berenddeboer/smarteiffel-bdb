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
void ZO81(Ze3*C,T0*a1){T2 Zet=0;Zet=ZNy(((Zv8*)(((C)->Zie))));while(!((Zet)==(ZGs(0)))){{Zn4*C1=(Zn4*)(ZOy(((Zv8*)(((C)->Zie))),Zet));
T0*b1=a1;ZP81(C1,b1,ZQ81);}Zet=(Z3)(((Zet))-(ZGs(1)));}}T2 ZR81(Ze3*C,T0*a1){T2 R=0;R=ZNy(((Zv8*)(((C)->Zie))));while(!((T6)(((R)==(ZGs(0)))||((T6)((a1)==((void*)((((Zn4*)(ZOy(((Zv8*)(((C)->Zie))),R)))->Zse))))))))
{R=(Z3)(((R))-(ZGs(1)));}return R;}void ZS81(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T6 ZT81(Ze3*C,T0*a1){
T6 R=0;T2 Zet=0;T0*ZU81=Zo;T0*ZV81=Zo;T0*ZxH=Zo;R=((T6)(1));Zet=ZNy(((Zv8*)(((C)->Zie))));while(!((T6)((!(R))||((T6)((Zet)==(ZGs(0)))))))
{ZxH=ZW81(C,Zet);if(ZyW(ZxH)){if((ZnH(ZxH))!=((void*)(ZxH))){R=((T6)(0));}else if((ZxP(ZxH,a1))!=((void*)(ZxH))){R=((T6)(0));}}else{R=((T6)(0));
}Zet=(Z3)(((Zet))-(ZGs(1)));}if(R){Zet=ZNy(((Zv8*)(((C)->Zie))));while(!((Zet)==(ZGs(0)))){ZU81=ZOy((Zv8*)(((C)->Zie)),Zet);ZV81=ZX81(((Zn4*)ZU81),a1);
if((ZV81)==((void*)(Zo))){ZS81(((((Zn4*)ZU81))->ZCb),ZY81);Zet=ZGs(0);}else{Zet=(Z3)(((Zet))-(ZGs(1)));}}ZO81(C,a1);}return R;}T0*ZW81(Ze3*C,T2
a1){T0*R=Zo;R=(((Zn4*)(ZOy(((Zv8*)(((C)->Zie))),a1)))->Zlc);return R;}void ZZ81(Ze3*C,T0*a1,T0*a2){T2 Zet=0;T2 ZXw=0;T0*ZOP=Zo;T0*Z_81=Zo;
Zet=ZGs(1);ZXw=ZNy(((Zv8*)(((C)->Zie))));while(!((Z3)((Zet)>(ZXw)))){ZOP=ZOy(((Zv8*)(((C)->Zie))),Zet);if(Z091(((Zn4*)ZOP))){Z_81=((((Zn4*)ZOP))->Zse);
Zmx(((T7*)a1),Z_81);Zmx(((T7*)a2),Z191);Zmx(((T7*)a2),Z_81);Zgt(((T7*)a2),((T3)'\054'));Z291(ZW81(C,Zet),a1);}Zet=(Z3)(((Zet))+(ZGs(1)));
}}void Z391(Ze3*C,T6 a1){T2 Zet=0;T2 ZXw=0;Zet=ZGs(1);ZXw=ZNy(((Zv8*)(((C)->Zie))));while(!((Z3)((Zet)>(ZXw)))){Z491((Zn4*)(ZOy(((Zv8*)(((C)->Zie))),Zet)),(T6)(a1));
Zet=(Z3)(((Zet))+(ZGs(1)));}}void Z591(Ze3*C){T2 Zet=0;Zet=ZNy(((Zv8*)(((C)->Zie))));while(!((Zet)==(ZGs(0)))){Z691((Z84*)(ZkH));Z491((Zn4*)(ZOy(((Zv8*)(((C)->Zie))),Zet)),(T6)(0));
Z791((Z84*)(ZkH));Zet=(Z3)(((Zet))-(ZGs(1)));}}void Z891(Ze3*C,T0*a1){T2 Zet=0;T0*ZV81=Zo;Zet=(((Zv8*)(((C)->Zie)))->ZXb);while(!((ZOy((Zv8*)(((C)->Zie)),Zet))==((void*)(Zo))))
{ZV81=ZOy((Zv8*)(((C)->Zie)),Zet);if((((((Zn4*)ZV81))->Zse))==((void*)(((((Zn4*)a1))->Zse)))){Z5G(((((Zn4*)a1))->ZCb));Z5G(((((Zn4*)ZV81))->ZCb));
{T0*b1=Z1G(24,"Same name appears twice.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zet=(Z3)(((Zet))+(ZGs(1)));}{Zv8*C1=(Zv8*)(((C)->Zie));
T0*b1=a1;T2 b2=Zet;(((C1)->ZUb))[(Z3)(((b2))-(((C1)->ZXb)))]=(b1);}((((Zn4*)(((Zn4*)a1))))->Zpe)=(Zet);}void Z991(Ze3*C,T0*a1){T2 Zet=0;
T0*ZU81=Zo;T0*ZV81=Zo;(C->Zie)=ZRy((Zv8*)(((C)->Zie)));Zet=(((Zv8*)(((C)->Zie)))->ZWb);while(!((Z3)((Zet)<((((Zv8*)(((C)->Zie)))->ZXb)))))
{ZU81=ZOy((Zv8*)(((C)->Zie)),Zet);ZV81=ZX81(((Zn4*)ZU81),a1);if((ZV81)==((void*)(Zo))){ZS81(((((Zn4*)ZU81))->ZCb),ZY81);}else{{Zv8*C1=(Zv8*)(((C)->Zie));
T0*b1=ZV81;T2 b2=Zet;(((C1)->ZUb))[(Z3)(((b2))-(((C1)->ZXb)))]=(b1);}}Zet=(Z3)(((Zet))-(ZGs(1)));}}T6 Za91(Ze3*C){T6 R=0;T2 Zet=0;T0*Zb91=Zo;
T0*ZkY=Zo;R=((T6)(1));Zet=ZNy(((Zv8*)(((C)->Zie))));while(!((T6)((!(R))||((T6)((Zet)==(ZGs(0))))))){Zb91=ZW81(C,Zet);if(ZX01(Zb91)){ZkY=Zg_((ZZ3*)(Z_G(Zb91)));
if((ZkY)!=((void*)(Zo))){R=((T6)(Zc91(((ZG7*)ZkY))));}}Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}void Zd91(Ze3*C,T0*a1){T2 Ze91=0;T2 Zf91=0;
(C->ZZb)=a1;Ze91=(((Z9a*)(((C)->ZZb)))->ZWb);while(!((Z3)((Ze91)<((((Z9a*)(((C)->ZZb)))->ZXb))))){Zf91=(Z3)(((Zf91))+(Zg91(Zh91(((C)->ZZb),Ze91))));
Ze91=(Z3)(((Ze91))-(ZGs(1)));}{Zv8*n=((Zv8*)Zh(sizeof(*n)));*n=Z8l;ZPy(n,(T2)(ZGs(1)),Zf91);(C->Zie)=((T0*)n);}Ze91=(((Z9a*)(((C)->ZZb)))->ZXb);
while(!((Z3)((Ze91)>((((Z9a*)(((C)->ZZb)))->ZWb))))){Zi91(Zh91(((C)->ZZb),Ze91),(T0*)C);Ze91=(Z3)(((Ze91))+(ZGs(1)));}}void Zj91(Ze3*C){
T2 Zet=0;T0*ZxH=Zo;T0*ZkY=Zo;Zet=ZNy(((Zv8*)(((C)->Zie))));while(!((Zet)==(ZGs(0)))){ZxH=ZnH(ZW81(C,Zet));if(ZqU(ZxH)){if(!(ZIG(ZxH))){
ZkY=Zg_((ZZ3*)(Z_G(ZxH)));if((ZkY)!=((void*)(Zo))){ZD61((Z84*)(ZkH),ZkY,ZOy(((Zv8*)(((C)->Zie))),Zet),Zo);}}}Zet=(Z3)(((Zet))-(ZGs(1)));
}}T0*Zk91(Ze3*C){T0*R=Zo;R=Zh(sizeof(*C));*((Ze3*)R)=*C;return R;}T0*Zl91(Ze3*C,T0*a1){T0*R=Zo;if(ZT81(C,a1)){R=((T0*)(C));}else{R=Zk91(C);
Z991(((Ze3*)R),a1);ZO81(((Ze3*)R),a1);}return R;}T6 Zm91(Ze3*C){T6 R=0;T2 Zet=0;Zet=ZNy(((Zv8*)(((C)->Zie))));while(!((T6)((R)||((T6)((Zet)==(ZGs(0)))))))
{R=((T6)(Z091((Zn4*)(ZOy(((Zv8*)(((C)->Zie))),Zet)))));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}void Zn91(Zg3*C,T0*a1){(C->Zme)=a1;(C->Zke)=Zo;
}void Zo91(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}void Zp91(Zg3*C){ZgH(((C)->Z1d));if((((C)->Zke))!=((void*)(Zo))){
Zz11((Zx2*)(((C)->Zke)));}if((((C)->Zme))!=((void*)(Zo))){Zq91((ZX6*)(((C)->Zme)));}}void Zr91(Zg3*C,T0*a1,T2 a2){T0*Zex=Zo;T0*ZKX=Zo;
(C->Z1d)=ZaH(((C)->Z1d));Zex=((C)->Z1d);if(Zo!=(Zex)){switch(((T0*)Zex)->id){case 320:break;default:Zex=Zo;}}ZKX=((C)->Z1d);if(Zo!=(ZKX)){
switch(((T0*)ZKX)->id){case 262:break;default:ZKX=Zo;}}if((((C)->Zke))!=((void*)(Zo))){ZB11((Zx2*)(((C)->Zke)),Zex,ZKX);if((T6)(((Zex)!=((void*)(Zo)))||((T6)((ZKX)!=((void*)(Zo)))))){
if((((C)->Zke))!=((void*)(Zo))){if(!((((((C)->Zle)).Zxb))==(ZGs(0)))){(C->Zke)=Zo;}}}}if((((C)->Zme))!=((void*)(Zo))){(C->Zme)=Zs91((ZX6*)(((C)->Zme)));
}if((((C)->Zke))==((void*)(Zo))){if(Z_W(((C)->Z1d))){ZFW(((ZX6*)a1),a2);if((((C)->Zme))!=((void*)(Zo))){Zt91(((ZX6*)a1),((C)->Zme),a2);
}}}}void Zu91(Zg3*C,T0*a1){if((((C)->Zke))==((void*)(Zo))){{Zx2*n=((Zx2*)Zh(sizeof(*n)));*n=ZQd;ZN11(n,a1);(C->Zke)=((T0*)n);}}else{ZXB(((ZB4*)((((Zx2*)(((C)->Zke)))->ZZb))),a1);
}}T0*Zv91=Zo;int Zw91=0;T0*Zx91(void){if(Zw91==0){Zw91=1;{{Za4*n=((Za4*)Zh(sizeof(*n)));*n=ZZf;Zv91=((T0*)n);}}}return Zv91;}void Zy91(Zg3*C){
T6 Zz91=0;T6 ZA91=0;if((((C)->Zne))!=((void*)(Zo))){ZB91((Z49*)(((C)->Zne)),(T0*)C);}else{Zz91=((T6)((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))));
ZA91=((T6)((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(7)))));ZC91((Z84*)(ZkH));ZgM((Z84*)(ZkH),ZD91);ZE91((Z84*)(ZkH));ZdL((Z84*)(ZkH),((T3)'\075'));
if(ZA91){ZdL((Z84*)(ZkH),((T3)'\050'));{T81 Zow;ZF91((Z84*)(ZkH),(*(Zow=ZLG(((C)->Z1d)),&Zow)));}ZdL((Z84*)(ZkH),((T3)'\054'));}ZD21(((C)->Z1d));
if(ZA91){ZdL((Z84*)(ZkH),((T3)'\051'));}ZgM((Z84*)(ZkH),ZCQ);if((((C)->Zke))==((void*)(Zo))){if((((((C)->Zle)).Zxb))==(ZGs(0))){if(Zz91){
ZG91((Za4*)(Zx91()),((C)->ZCb));}}else if((((C)->Zme))!=((void*)(Zo))){ZHW((ZX6*)(((C)->Zme)));}}else if(ZH91(C)){ZgM((Z84*)(ZkH),ZI91);
ZE91((Z84*)(ZkH));ZgM((Z84*)(ZkH),ZJ91);Z721((Zx2*)(((C)->Zke)),((C)->Zle));if((((((C)->Zle)).Zxb))==(ZGs(0))){if(Zz91){ZgM((Z84*)(ZkH),ZK91);
ZG91((Za4*)(Zx91()),((C)->ZCb));}}else if((((C)->Zme))!=((void*)(Zo))){ZgM((Z84*)(ZkH),ZL91);ZHW((ZX6*)(((C)->Zme)));}ZgM((Z84*)(ZkH),ZM91);
}else{ZF11((Zx2*)(((C)->Zke)),((C)->Zle));if((((((C)->Zle)).Zxb))==(ZGs(0))){if(Zz91){ZdL((Z84*)(ZkH),((T3)'\040'));ZgM((Z84*)(ZkH),ZN91);
ZdL((Z84*)(ZkH),((T3)'\173'));ZG91((Za4*)(Zx91()),((C)->ZCb));ZdL((Z84*)(ZkH),((T3)'\175'));}}else if((((C)->Zme))!=((void*)(Zo))){ZdL((Z84*)(ZkH),((T3)'\040'));
ZgM((Z84*)(ZkH),ZN91);ZdL((Z84*)(ZkH),((T3)'\173'));ZHW((ZX6*)(((C)->Zme)));ZdL((Z84*)(ZkH),((T3)'\175'));}}ZgM((Z84*)(ZkH),ZO91);ZP91((Z84*)(ZkH));
}}T6 ZQ91(Zg3*C,T0*a1){T6 R=0;if(ZWG(((C)->Z1d),a1)){if((T6)(((((C)->Zke))==((void*)(Zo)))||((T6)(ZJ11((Zx2*)(((C)->Zke)),a1))))){if((T6)(((((C)->Zme))==((void*)(Zo)))||((T6)(ZR91((ZX6*)(((C)->Zme)),a1))))){
R=((T6)(1));}}}return R;}void ZS91(Zg3*C,T81 a1,T0*a2){(C->ZCb)=a1;(C->Z1d)=a2;}void ZT91(Zg3*C,T81 a1,T0*a2){(C->Zle)=a1;(C->Zme)=a2;
}void ZU91(Zg3*C){ZLH(((C)->Z1d));if((((C)->Zke))!=((void*)(Zo))){ZW11((Zx2*)(((C)->Zke)));}if((((C)->Zme))!=((void*)(Zo))){ZKW((ZX6*)(((C)->Zme)));
}}T6 ZV91(Zg3*C){T6 R=0;R=((T6)((T6)((R)||((T6)(ZRH(((C)->Z1d)))))));if((((C)->Zke))!=((void*)(Zo))){R=((T6)((T6)((R)||((T6)(ZY11((Zx2*)(((C)->Zke))))))));
}if((((C)->Zme))!=((void*)(Zo))){R=((T6)((T6)((R)||((T6)(ZMW((ZX6*)(((C)->Zme))))))));}return R;}void ZW91(Zg3*C,T0*a1){T6 ZxR=0;ZxR=((T6)(Z4L(((C)->Z1d),a1)));
if((((C)->Zke))!=((void*)(Zo))){Z021((Zx2*)(((C)->Zke)),a1);}}T0*ZX91(Zg3*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zg3*)R)=*C;return R;}T0*ZY91(Zg3*C,T0*a1){
T0*R=Zo;if((ZZy(((T79*)(((((T91*)a1))->ZZb)))))==(ZGs(1))){R=((T0*)(C));}else{{Zp8*n=((Zp8*)Zh(sizeof(*n)));*n=Z2l;ZzR(n,(T0*)C,a1);R=((T0*)n);
}}return R;}T6 ZH91(Zg3*C){T6 R=0;if((Z3)((Z421((Zx2*)(((C)->Zke))))<=(ZGs(32)))){R=((T6)(1));}return R;}T0*ZZ91(Zg3*C,T0*a1){T0*R=Zo;
T0*Z3V=Zo;T0*Z_91=Zo;T0*Z0a1=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;Z3V=ZyH(((C)->Z1d),a1);if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
(C->Z1d)=Z3V;Z_91=ZGH(Z3V);}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){if(ZET(Z_91)){if((((C)->Zke))!=((void*)(Zo))){(C->Zke)=ZU11((Zx2*)(((C)->Zke)),(T0*)C);
if((((C)->Zke))==((void*)(Zo))){Zo91(((C)->ZCb),Z1a1);}}}else if(ZzT(Z_91)){if((((C)->Zke))!=((void*)(Zo))){(C->Zke)=Z221((Zx2*)(((C)->Zke)),(T0*)C);
if((((C)->Zke))==((void*)(Zo))){Zo91(((C)->ZCb),Z1a1);}}}else if(ZwU(Z_91)){if((((C)->Zke))!=((void*)(Zo))){{Z49*n=((Z49*)Zh(sizeof(*n)));
*n=ZGl;Z2a1(n,(T0*)C);(C->Zne)=((T0*)n);}(C->Zke)=ZO11((Zx2*)(((C)->Zke)),(T0*)C);if((((C)->Zke))==((void*)(Zo))){Zo91(((C)->ZCb),Z1a1);
}}}else{{T0*b1=Z1G(48,"Expression must be INTEGER, CHARACTER or STRING.");Zmx((T7*)(Z2G),b1);}ZMT(Z_91,Z1G(16," is not allowed."));Z5G(((C)->ZCb));
Z3G((T80*)(Z4G));}}if((((C)->Zme))!=((void*)(Zo))){(C->Zme)=ZRW((ZX6*)(((C)->Zme)),a1);}R=((T0*)(C));}else{R=ZX91(C);if((((C)->Zke))!=((void*)(Zo))){
{Zx2*n=((Zx2*)Zh(sizeof(*n)));*n=ZQd;ZT11(n,((C)->Zke));Z0a1=((T0*)n);}((((Zg3*)(((Zg3*)R))))->Zke)=(Z0a1);}((((Zg3*)(((Zg3*)R))))->Z4c)=(Zo);
R=ZZ91(((Zg3*)R),a1);}return R;}void Z3a1(Zg3*C){ZFL(((C)->Z1d));}void Z4a1(Zz6*C,T0*a1){T2 Zet=0;Zet=Zjy(((Zl2*)(((C)->Zie))));while(!((Zet)==(ZGs(0))))
{{Zi1*C1=(Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zet));T0*b1=a1;Z5a1(C1,b1,Z6a1);}Zet=(Z3)(((Zet))-(ZGs(1)));}}void Z7a1(Zz6*C,T0*a1){T2 Zet=0;
T0*ZxH=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>(Zjy(((Zl2*)(((C)->Zie)))))))){ZxH=ZnH(Z8a1(C,Zet));Zw01(ZxH,a1);Zgt(((T7*)a1),((T3)'\040'));
Zgt(((T7*)a1),((T3)'a'));Z6t(Zet,a1);Zet=(Z3)(((Zet))+(ZGs(1)));if((Z3)((Zet)<=(Zjy(((Zl2*)(((C)->Zie))))))){Zgt(((T7*)a1),((T3)'\054'));
}}}T2 Z9a1(Zz6*C,T0*a1){T2 R=0;R=Zjy(((Zl2*)(((C)->Zie))));while(!((T6)(((R)==(ZGs(0)))||((T6)((a1)==((void*)((((Zi1*)(Zky(((Zl2*)(((C)->Zie))),R)))->Zse))))))))
{R=(Z3)(((R))-(ZGs(1)));}return R;}void Zaa1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T0*Zba1(Zz6*C,T81 a1){
T0*R=Zo;T2 Zet=0;T2 ZXw=0;{Za3*n=((Za3*)Zh(sizeof(*n)));*n=Z3j;((((Za3*)(n)))->Z2j)=(((T0*)Zca1(a1)));R=((T0*)n);}Zet=ZGs(2);ZXw=Zjy(((Zl2*)(((C)->Zie))));
while(!((Z3)((Zet)>(ZXw)))){Zda1(((Za3*)R),((T0*)Zca1(a1)));Zet=(Z3)(((Zet))+(ZGs(1)));}return R;}T6 Zea1(Zz6*C,T0*a1){T6 R=0;T2 Zet=0;
T0*ZU81=Zo;T0*ZV81=Zo;T0*ZxH=Zo;R=((T6)(1));Zet=Zjy(((Zl2*)(((C)->Zie))));while(!((T6)((!(R))||((T6)((Zet)==(ZGs(0))))))){ZxH=Z8a1(C,Zet);
if(ZyW(ZxH)){if((ZnH(ZxH))!=((void*)(ZxH))){R=((T6)(0));}else if((ZxP(ZxH,a1))!=((void*)(ZxH))){R=((T6)(0));}}else{R=((T6)(0));}Zet=(Z3)(((Zet))-(ZGs(1)));
}if(R){Zet=Zjy(((Zl2*)(((C)->Zie))));while(!((Zet)==(ZGs(0)))){ZU81=Zky((Zl2*)(((C)->Zie)),Zet);ZV81=Zfa1(((Zi1*)ZU81),a1);if((ZV81)==((void*)(Zo))){
Zaa1(((((Zi1*)ZU81))->ZCb),ZY81);Zet=ZGs(0);}else{Zet=(Z3)(((Zet))-(ZGs(1)));}}Z4a1(C,a1);}return R;}void Zga1(Zz6*C,T0*a1,T0*a2){*((Zz6*)(C))=*((Zz6*)(a1));
Zha1(C,a2);Z4a1(C,a2);}T0*Z8a1(Zz6*C,T2 a1){T0*R=Zo;R=(((Zi1*)(Zky(((Zl2*)(((C)->Zie))),a1)))->Zlc);return R;}void Zia1(Zz6*C){T0*ZxH=Zo;
T2 Zet=0;T2 ZOP=0;((((T7*)((T7*)(Zja1))))->Zdc)=(ZGs(0));ZdL((Z84*)(ZkH),((T3)'\173'));Zet=ZGs(1);while(!((Z3)((Zet)>(Zjy(((Zl2*)(((C)->Zie))))))))
{ZxH=ZnH(Z8a1(C,Zet));if(Z3L(ZxH)){ZgM((Z84*)(ZkH),Zka1);Zmx((T7*)(Zja1),Zla1);Z6t(ZOP,Zja1);Zmx((T7*)(Zja1),Zma1);Z6t(Zet,Zja1);Zmx((T7*)(Zja1),Zna1);
ZOP=(Z3)(((ZOP))+(ZGs(1)));}Zet=(Z3)(((Zet))+(ZGs(1)));}ZgM((Z84*)(ZkH),Zoa1);ZgM((Z84*)(ZkH),Zja1);(C->Zaj)=ZOP;}T0*Zja1=Zo;void Zpa1(Zz6*C,T0*a1,T0*a2){
T2 Zet=0;T0*ZxH=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>(Zjy(((Zl2*)(((C)->Zie)))))))){ZxH=ZnH(Z8a1(C,Zet));Zmx(((T7*)a1),(((Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zet)))->Zse));
Z291(ZxH,a1);Zmx(((T7*)a2),Zqa1);Z6t(Zet,a2);Zgt(((T7*)a2),((T3)'\054'));Zet=(Z3)(((Zet))+(ZGs(1)));}}void Zra1(Zz6*C,T0*a1){T0*Zsa1=Zo;
T0*Zta1=Zo;T0*Zua1=Zo;T0*ZFH=Zo;T0*Zva1=Zo;T2 Zet=0;T2 Zwa1=0;Zxa1(C,a1);Zet=Zjy(((Zl2*)(((C)->Zie))));while(!((Zet)==(ZGs(0)))){Zsa1=Zky(((Zl2*)(((C)->Zie))),Zet);
Zta1=((((Zi1*)Zsa1))->Zlc);if(Zo!=(Zta1)){switch(((T0*)Zta1)->id){case 277:break;default:Zta1=Zo;}}if((Zta1)!=((void*)(Zo))){Zwa1=Z9a1(C,(((ZD8*)(((((ZP4*)Zta1))->ZWg)))->Zse));
if((Zwa1)==(Zet)){Z5G(((((ZP4*)Zta1))->ZCb));{T0*b1=Zya1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else if((Z3)((Zwa1)>(ZGs(0)))){{Zi3*n=((Zi3*)Zh(sizeof(*n)));
*n=Zre;Zza1(n,(((ZD8*)(((((ZP4*)Zta1))->ZWg)))->ZCb),(T0*)C,Zwa1);Zua1=((T0*)n);}{Zr8*n=((Zr8*)Zh(sizeof(*n)));*n=Z3l;ZAa1(n,((((ZP4*)Zta1))->ZCb),Zua1);
ZFH=((T0*)n);}((((Zi1*)(((Zi1*)Zsa1))))->Zlc)=(ZFH);}}Zet=(Z3)(((Zet))-(ZGs(1)));}if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(7)))){Zet=Zjy(((Zl2*)(((C)->Zie))));
while(!((Zet)==(ZGs(0)))){ZFH=(((Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zet)))->Zlc);if(Zo!=(ZFH)){switch(((T0*)ZFH)->id){case 280:break;default:
ZFH=Zo;}}if((ZFH)!=((void*)(Zo))){Zwa1=Z9a1(C,ZBa1((Zi3*)(((((Zr8*)ZFH))->ZWg))));Zva1=(((Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zwa1)))->Zlc);
if(Zo!=(Zva1)){switch(((T0*)Zva1)->id){case 280:break;default:Zva1=Zo;}}if((Zva1)!=((void*)(Zo))){Z5G(((((Zr8*)ZFH))->ZCb));Z5G(((((Zr8*)Zva1))->ZCb));
{T0*b1=Zya1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}Zet=(Z3)(((Zet))-(ZGs(1)));}}}void ZCa1(Zz6*C){ZgM((Z84*)(ZkH),ZDa1);ZDM((Z84*)(ZkH),(T11)(((C)->Zaj)));
ZgM((Z84*)(ZkH),ZEa1);}void ZFa1(Zz6*C){T2 Zet=0;T0*ZxH=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>(Zjy(((Zl2*)(((C)->Zie)))))))){ZxH=ZnH(Z8a1(C,Zet));
((((T7*)((T7*)(Zja1))))->Zdc)=(ZGs(0));Zw01(ZxH,Zja1);Zgt((T7*)(Zja1),((T3)'\040'));ZgM((Z84*)(ZkH),Zja1);Z691((Z84*)(ZkH));ZGa1((Z84*)(ZkH),Zet);
Z791((Z84*)(ZkH));ZdL((Z84*)(ZkH),((T3)'\075'));ZHa1((Z84*)(ZkH),Zet);ZgM((Z84*)(ZkH),ZCQ);Zet=(Z3)(((Zet))+(ZGs(1)));}}void ZIa1(Zz6*C,T0*a1){
T2 Zet=0;T2 ZXw=0;Zet=ZGs(1);ZXw=Zjy(((Zl2*)(((C)->Zie))));while(!((Z3)((Zet)>(ZXw)))){ZJa1((Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zet)),a1);
Zet=(Z3)(((Zet))+(ZGs(1)));}}void ZKa1(Zz6*C,T0*a1){T2 Zet=0;T0*ZV81=Zo;Zet=(((Zl2*)(((C)->Zie)))->ZXb);while(!((Zky((Zl2*)(((C)->Zie)),Zet))==((void*)(Zo))))
{ZV81=Zky((Zl2*)(((C)->Zie)),Zet);if((((((Zi1*)ZV81))->Zse))==((void*)(((((Zi1*)a1))->Zse)))){Z5G(((((Zi1*)a1))->ZCb));Z5G(((((Zi1*)ZV81))->ZCb));
{T0*b1=Z1G(24,"Same name appears twice.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zet=(Z3)(((Zet))+(ZGs(1)));}{Zl2*C1=(Zl2*)(((C)->Zie));
T0*b1=a1;T2 b2=Zet;(((C1)->ZUb))[(Z3)(((b2))-(((C1)->ZXb)))]=(b1);}((((Zi1*)(((Zi1*)a1))))->Zpe)=(Zet);}void ZLa1(Zz6*C,T0*a1){T2 Zet=0;
T0*ZxH=Zo;Zet=ZGs(1);while(!((Z3)((Zet)>(Zjy(((Zl2*)(((C)->Zie)))))))){ZxH=ZnH(Z8a1(C,Zet));ZtQ(ZxH,a1);Zgt(((T7*)a1),((T3)'\040'));Zgt(((T7*)a1),((T3)'a'));
Z6t(Zet,a1);Zet=(Z3)(((Zet))+(ZGs(1)));if((Z3)((Zet)<=(Zjy(((Zl2*)(((C)->Zie))))))){Zgt(((T7*)a1),((T3)'\054'));}}}T6 Z5L(Zz6*C,T0*a1){
T6 R=0;T2 Zet=0;T0*ZMa1=Zo;T6 ZNa1=0;ZMa1=a1;if(Zo!=(ZMa1)){switch(((T0*)ZMa1)->id){case 166:case 276:break;default:ZMa1=Zo;}}if((T6)(((T6)(((ZMa1)!=((void*)(Zo)))&&((T6)(Z3L(ZGH(a1))))))&&((T6)(!(ZXG(a1)))))){
Zet=Zjy(((Zl2*)(((C)->Zie))));while(!((Z3)((Zet)<(ZGs(1))))){ZNa1=((T6)((T6)((ZNa1)||((T6)((ZOa1(ZMa1))==((void*)((((Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zet)))->Zse))))))));
if((((void)((Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zet)))),ZPa1((T0*)C))){R=((T6)(1));}Zet=(Z3)(((Zet))-(ZGs(1)));}if(!(ZNa1)){Z6L(a1);}}else{
Zet=Zjy(((Zl2*)(((C)->Zie))));while(!((Z3)((Zet)<(ZGs(1))))){if((((void)((Zi1*)(Zky(((Zl2*)(((C)->Zie))),Zet)))),ZPa1((T0*)C))){R=((T6)(1));
}Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}void Zha1(Zz6*C,T0*a1){T2 Zet=0;T0*ZU81=Zo;T0*ZV81=Zo;(C->Zie)=Zny((Zl2*)(((C)->Zie)));Zet=(((Zl2*)(((C)->Zie)))->ZWb);
while(!((Z3)((Zet)<((((Zl2*)(((C)->Zie)))->ZXb))))){ZU81=Zky((Zl2*)(((C)->Zie)),Zet);ZV81=Zfa1(((Zi1*)ZU81),a1);if((ZV81)==((void*)(Zo))){
Zaa1(((((Zi1*)ZU81))->ZCb),ZY81);}else{{Zl2*C1=(Zl2*)(((C)->Zie));T0*b1=ZV81;T2 b2=Zet;(((C1)->ZUb))[(Z3)(((b2))-(((C1)->ZXb)))]=(b1);
}}Zet=(Z3)(((Zet))-(ZGs(1)));}}T6 ZQa1(Zz6*C,T0*a1,T0*a2){T6 R=0;T2 Zet=0;T0*Zh31=Zo;T0*Zi31=Zo;Zet=Zjy(((Zl2*)(((C)->Zie))));if((Zjy(((Zl2*)(((((Zz6*)a1))->Zie)))))!=(Zet)){
{T81 Zow;Z5G((*(Zow=ZRa1(((Zz6*)a1)),&Zow)));}{T81 Zow;Zaa1((*(Zow=ZRa1(C),&Zow)),Z1G(24,"Bad number of arguments."));}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
R=((T6)(1));while(!((T6)((!(R))||((T6)((Zet)==(ZGs(0))))))){Zh31=Z8a1(C,Zet);Zi31=Z8a1(((Zz6*)a1),Zet);if(!(ZZN(Zi31,Zh31,a2,(T6)(1)))){
R=((T6)(0));Z3G((T80*)(Z4G));{T81 Zow;Z5G((*(Zow=ZrP(Zh31),&Zow)));}{T81 Zow;Z5G((*(Zow=ZrP(Zi31),&Zow)));}{T0*b1=Z1G(22,"Incompatible types in ");
Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}Zet=(Z3)(((Zet))-(ZGs(1)));
}}return R;}void Zxa1(Zz6*C,T0*a1){T2 Ze91=0;T2 Zf91=0;(C->ZZb)=a1;Ze91=(((Z9a*)(((C)->ZZb)))->ZWb);while(!((Z3)((Ze91)<((((Z9a*)(((C)->ZZb)))->ZXb)))))
{Zf91=(Z3)(((Zf91))+(Zg91(Zh91(((C)->ZZb),Ze91))));Ze91=(Z3)(((Ze91))-(ZGs(1)));}{Zl2*n=((Zl2*)Zh(sizeof(*n)));*n=ZLd;Zly(n,(T2)(ZGs(1)),Zf91);
(C->Zie)=((T0*)n);}Ze91=(((Z9a*)(((C)->ZZb)))->ZXb);while(!((Z3)((Ze91)>((((Z9a*)(((C)->ZZb)))->ZWb))))){Zi91(Zh91(((C)->ZZb),Ze91),(T0*)C);
Ze91=(Z3)(((Ze91))+(ZGs(1)));}}T6 ZSa1(Zz6*C){T6 R=0;T2 Zet=0;Zet=(((Zl2*)(((C)->Zie)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<((((Zl2*)(((C)->Zie)))->ZXb))))))))
{R=((T6)(Zh_((((Zi1*)(Zky((Zl2*)(((C)->Zie)),Zet)))->Zlc))));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}void ZTa1(Zz6*C){ZgM((Z84*)(ZkH),ZUa1);
ZDM((Z84*)(ZkH),(T11)(((C)->Zaj)));ZgM((Z84*)(ZkH),ZVa1);}T81 ZRa1(Zz6*C){T81 R={Zo,Zo,0};R=(((Zi1*)(((((Zl2*)(((C)->Zie)))->ZUb))[ZGs(0)]))->ZCb);
return R;}T0*ZWa1(Zi1*C){T0*R=Zo;R=((((C)->ZCb)).Zvb);return R;}void ZXa1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));
}void Z5a1(Zi1*C,T0*a1,T0*a2){T0*ZiL=Zo;T0*ZJH=Zo;T0*ZkL=Zo;ZkL=ZWa1(C);if(ZYa1(((T87*)ZkL),((C)->Zse))){ZJH=Z_G(a1);ZiL=ZZa1(((ZZ3*)ZJH),((C)->Zse));
if((ZiL)!=((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(ZiL),&Zow)));}}ZXa1(((C)->ZCb),a2);}}T6 Z_a1(Zi1*C,T0*a1){T6 R=0;if(Z0b1(((C)->Zlc),a1)){
R=((T6)(1));}return R;}void Z1b1(Zi1*C){Z5G(((C)->ZCb));{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Z2b1(Zi1*C,T81 a1,T0*a2){(C->ZCb)=a1;(C->Zse)=a2;}void Z3b1(Zi1*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);
}Z5G(((C)->ZCb));Z3G((T80*)(Z4G));}void ZJa1(Zi1*C,T0*a1){T0*ZxH=Zo;ZxH=ZnH(((C)->Zlc));ZmW(ZxH,a1);Zgt(((T7*)a1),((T3)'\040'));Zgt(((T7*)a1),((T3)'\137'));
Zmx(((T7*)a1),((C)->Zse));Zgt(((T7*)a1),((T3)'\073'));}T6 ZPa1(T0*a1){T6 R=0;return R;}void Z4b1(Zi1*C,T0*a1){T6 Z8L=0;T0*ZjL=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));
ZjL=ZnH(((C)->Zlc));if(ZbL(ZjL)){if(ZbL(a1)){ZdL((Z84*)(ZkH),((T3)'\050'));ZcL(a1);ZGa1((Z84*)(ZkH),((C)->Zpe));ZdL((Z84*)(ZkH),((T3)'\051'));
}else{ZGa1((Z84*)(ZkH),((C)->Zpe));}}else if(ZbL(a1)){ZGa1((Z84*)(ZkH),((C)->Zpe));}else if(ZX01(ZjL)){if(!(ZPX(ZjL))){ZdL((Z84*)(ZkH),((T3)'\046'));
}ZGa1((Z84*)(ZkH),((C)->Zpe));}else{ZGa1((Z84*)(ZkH),((C)->Zpe));}if(Z8L){ZgL((Z84*)(ZkH));}}T0*Z5b1(Zi1*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Zi1*)R)=*C;return R;}T2 Z6b1(Zi1*C){T2 R=0;Z3b1(C);return R;}T0*Zfa1(Zi1*C,T0*a1){T0*R=Zo;T0*ZjL=Zo;ZjL=ZxP(((C)->Zlc),a1);if((ZjL)==((void*)(Zo))){
{T81 Zow;Z5G((*(Zow=ZrP(((C)->Zlc)),&Zow)));}ZXa1(((C)->ZCb),Z3H);}if((((C)->Zlc))==((void*)(ZjL))){R=((T0*)(C));}else{R=Z5b1(C);((((Zi1*)(((Zi1*)R))))->Zlc)=(ZjL);
}return R;}T0*Z7b1(Zi1*C){T0*R=Zo;R=ZCL(((C)->Zlc));return R;}void Z8b1(Zk3*C){Z9b1(C);ZpG((((ZD8*)(((C)->Z2c)))->ZCb),((C)->ZFb),((C)->Z3c));
}T0*Zab1(void){if(ZrG==0){ZrG=1;{{ZG9*n=((ZG9*)Zh(sizeof(*n)));*n=Zfm;ZqG=((T0*)n);{ZG9*C1=n;ZhF(C1,ZGs(53));}}ZgF(((ZG9*)ZqG),ZtG);ZgF(((ZG9*)ZqG),ZuG);
ZgF(((ZG9*)ZqG),ZvG);ZgF(((ZG9*)ZqG),ZwG);ZgF(((ZG9*)ZqG),ZxG);ZgF(((ZG9*)ZqG),ZyG);ZgF(((ZG9*)ZqG),ZzG);ZgF(((ZG9*)ZqG),ZAG);ZgF(((ZG9*)ZqG),(((void)((T27*)(Zbb1()))),ZCG(ZDG)));
ZgF(((ZG9*)ZqG),(((void)((T27*)(Zbb1()))),ZCG(ZEG)));}}return ZqG;}T0*Zcb1(Zk3*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;T0*ZGG=Zo;T0*ZHG=Zo;R=a1;
if(ZIG(a2)){if(ZIG(a3)){ZHG=Z9G(a3);ZGG=Z9G(a2);if((ZHG)!=((void*)(ZGG))){if(ZJG(a2,a3)){R=ZKG(a1,a3);if((T6)(((R)!=((void*)(a1)))&&((T6)(!(ZfF((ZG9*)(Zab1()),(((ZD8*)(((C)->Z2c)))->Zse))))))){
{T81 Zow;Z5G((*(Zow=ZLG(a1),&Zow)));}{T0*b1=ZMG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZGG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZNG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZHG;
Zmx((T7*)(Z2G),b1);}{T0*b1=ZOG;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
}}}}return R;}T6 Zdb1(Zk3*C,T0*a1){T6 R=0;T0*ZUG=Zo;if((((C)->ZFb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(ZVG((Za3*)(((C)->ZFb)),a1)));
}if(R){if((((C)->Z3c))==((void*)(Zo))){R=((T6)(ZWG(((C)->Z1c),a1)));}else if(ZXG(((C)->Z1c))){if(ZYG(((C)->Z3c),a1)){R=((T6)((ZZG(((C)->Z3c),a1))!=((void*)(Zo))));
}else{R=((T6)(0));}}else{R=((T6)(ZWG(((C)->Z1c),a1)));if(R){if((((C)->Z3c))!=((void*)(Zo))){ZUG=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Z3c)))->Z4c))))->Zof);
if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZUG))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){R=((T6)(ZYG(((C)->Z3c),ZUG)));}}}}}return R;}T0*Zeb1(Zk3*C,T0*a1){
T0*R=Zo;R=Z1H((Za3*)(((C)->ZFb)),a1);if((R)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z2H((Za3*)(((C)->ZFb))),&Zow)));}{T0*b1=Z3H;Zmx((T7*)(Z2G),b1);
}Z4H(a1);ZaG((T80*)(Z4G));}return R;}void Zfb1(Zk3*C,T0*a1,T0*a2,T0*a3){(C->Z3c)=Zo;(C->Z4c)=Zo;(C->Z1c)=a1;(C->Z2c)=a2;(C->ZFb)=a3;}
T0*Zgb1(Zk3*C){T0*R=Zo;if((((T43*)(ZSG))->ZRk)){R=((T0*)(C));}else{R=Zhb1(C);if((R)!=((void*)(C))){Z8H((T43*)(ZSG));}}return R;}T0*Zib1(Zk3*C){
T0*R=Zo;(C->Z1c)=ZaH(((C)->Z1c));ZbH((Za3*)(((C)->ZFb)));R=Zhb1(C);return R;}void Zjb1(Zk3*C){T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){
if((((C)->ZFb))!=((void*)(Zo))){ZdH=(((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>=(ZGs(1)))){
{T81 Zow;ZeH((T43*)(ZSG),(*(Zow=Zkb1(C),&Zow)),((C)->Z3c),ZdH);}}}}ZgH(((C)->Z1c));if((((C)->ZFb))!=((void*)(Zo))){ZhH((Za3*)(((C)->ZFb)));
}}void Z9b1(Zk3*C){if((ZiH(((C)->Z3c)))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
Zlb1(Z1G(29,"Feature found is a procedure."));}}T6 Zmb1(Zk3*C,T0*a1){T6 R=0;R=((T6)(Zdb1(C,a1)));if(R){R=((T6)(!(ZmH(ZnH(Znb1(C))))));
}return R;}void Zob1(Zk3*C,T0*a1,T0*a2){ZqH(((C)->Z1c),a1,a2);ZrH((Za3*)(((C)->ZFb)),a1,a2);}void Zpb1(Zk3*C){{T81 Zow;Z5G((*(Zow=Zkb1(C),&Zow)));
}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Zqb1(Zk3*C,T0*a1,T81
a2,T0*a3){(C->Z1c)=a1;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,(ZRI),a2);(C->Z2c)=((T0*)n);}{Za3*n=((Za3*)Zh(sizeof(*n)));*n=Z3j;((((Za3*)(n)))->Z2j)=(a3);
(C->ZFb)=((T0*)n);}}void Zrb1(Zk3*C,T0*a1){T0*ZxH=Zo;ZxH=ZyH(((C)->Z1c),a1);if((ZxH)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));
}{T0*b1=Z1G(11,"Bad target.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z1c)=ZxH;}void Zlb1(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}void Zsb1(Zk3*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=Zkb1(C),&Zow)));}Z3G((T80*)(Z4G));}T2 Ztb1(void){
T2 R=0;return R;}void Zub1(Zk3*C,T3 a1){if((a1)==(((T3)'R'))){{T81 Zow;ZDH(((C)->Z3c),(*(Zow=Zkb1(C),&Zow)));}}ZEH(((C)->Z1c),a1);ZEH(((((Za3*)(((C)->ZFb))))->Z2j),a1);
}T0*Znb1(Zk3*C){T0*R=Zo;T0*ZFH=Zo;R=ZiH(((C)->Z3c));ZFH=R;if(Zo!=(ZFH)){switch(((T0*)ZFH)->id){case 280:break;default:ZFH=Zo;}}if((ZFH)!=((void*)(Zo))){
R=ZnH(ZGH(((((Za3*)(((C)->ZFb))))->Z2j)));}return R;}void Zvb1(Zk3*C){T0*ZIH=Zo;T0*ZJH=Zo;T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){ZIH=ZGH(((C)->Z1c));
ZJH=Z_G(ZIH);ZdH=((((ZZ3*)ZJH))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){ZKH(((C)->Z1c),((C)->Z3c));
}}ZLH(((C)->Z1c));ZMH((Za3*)(((C)->ZFb)));}T6 Zwb1(Zk3*C){T6 R=0;R=((T6)(ZOH((Za3*)(((C)->ZFb)))));if(R){}else if(ZXG(((C)->Z1c))){if((ZPH())!=((void*)(((C)->Z3c)))){
R=((T6)(ZQH(((C)->Z3c))));}}else{R=((T6)(ZRH(((C)->Z1c))));}return R;}T0*Zbb1(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);
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
ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T6 Zxb1(Zk3*C){T6 R=0;if(Z0L(((C)->Z1c))){
if((((C)->ZFb))!=((void*)(Zo))){R=((T6)(Z1L((Za3*)(((C)->ZFb)))));}else{R=((T6)(1));}}return R;}T6 Zyb1(Zk3*C,T0*a1){T6 R=0;R=((T6)(Z3L(ZGH(((C)->Z1c)))));
R=((T6)((T6)((Z4L(((C)->Z1c),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z5L(((Zz6*)a1),((C)->Z1c))){R=((T6)(1));}}else if((T6)((Z3L(ZGH(((C)->Z1c))))&&((T6)(!(ZXG(((C)->Z1c))))))){
Z6L(((C)->Z1c));}return R;}void Zzb1(Zk3*C,T0*a1){T6 Z8L=0;T0*Z9L=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Z9L=ZnH(Znb1(C));if(ZbL(Z9L)){if(ZbL(a1)){
ZcL(a1);ZdL((Z84*)(ZkH),((T3)'\050'));{Zk3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Zk3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);
}}}else{if(ZbL(a1)){{Zk3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}else{if(ZfL(a1)){ZdL((Z84*)(ZkH),((T3)'\046'));ZdL((Z84*)(ZkH),((T3)'\050'));
{Zk3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Zk3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}}if(Z8L){ZgL((Z84*)(ZkH));
}}void ZAb1(Zk3*C,T0*a1){T0*ZiL=Zo;T0*ZJH=Zo;T0*ZjL=Zo;T0*ZkL=Zo;ZjL=ZGH(((C)->Z1c));if((ZjL)!=((void*)(Zo))){ZJH=Z_G(ZjL);if((ZJH)!=((void*)(Zo))){
ZkL=((((ZZ3*)ZJH))->Zvb);ZiL=ZlL(((T87*)ZkL),ZJH,((C)->Z1c),((C)->Z2c),a1);}}if((ZiL)==((void*)(Zo))){Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
{T0*b1=Z1G(25,"Bad target for this call.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z3c)=ZiL;}T0*ZBb1(Zk3*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Zk3*)R)=*C;return R;}T2 ZCb1(Zk3*C){T2 R=0;Zsb1(C);return R;}T0*ZDb1(Zk3*C,T0*a1){T0*R=Zo;T0*ZpL=Zo;T0*ZqL=Zo;T0*ZrL=Zo;if((((C)->Z4c))==((void*)(Zo))){
(C->Z4c)=a1;Zrb1(C,a1);(C->ZFb)=Zeb1(C,a1);ZqL=ZGH(((C)->Z1c));ZpL=ZGH(((((Za3*)(((C)->ZFb))))->Z2j));(C->Z1c)=Zcb1(C,((C)->Z1c),ZqL,ZpL);
ZAb1(C,a1);R=Zgb1(C);Z8b1(C);}else{ZrL=ZBb1(C);Zfb1(((Zk3*)ZrL),((C)->Z1c),((C)->Z2c),((C)->ZFb));R=ZDb1(((Zk3*)ZrL),a1);}return R;}T0*Zhb1(Zk3*C){
T0*R=Zo;T0*ZsL=Zo;ZsL=((C)->Z1c);if(Zo!=(ZsL)){switch(((T0*)ZsL)->id){case 318:case 319:break;default:ZsL=Zo;}}if((ZsL)==((void*)(Zo))){
R=((T0*)(C));}else if(ZuL(ZsL)){R=((((Za3*)(((C)->ZFb))))->Z2j);}else{{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;ZvL(n,(((ZD8*)(((C)->Z2c)))->ZCb));
R=((T0*)n);}}return R;}T0*ZEb1(Zk3*C){T0*R=Zo;T0*ZkL=Zo;T0*ZyL=Zo;T0*ZjL=Zo;ZkL=ZzL(((C)->Z1c));if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),((C)->Z2c));
if((ZyL)!=((void*)(Zo))){ZjL=ZBL(ZyL);if((ZjL)!=((void*)(Zo))){R=ZCL(ZjL);}}}return R;}void ZFb1(Zk3*C){if((((C)->Z3c))!=((void*)(Zo))){
ZEL(((C)->Z3c));}ZFL(((C)->Z1c));if((((C)->ZFb))!=((void*)(Zo))){ZGL((Za3*)(((C)->ZFb)));}}void ZGb1(Zk3*C){T0*ZJH=Zo;T0*ZiL=Zo;ZiL=((C)->Z3c);
ZJH=((((ZQ7*)ZiL))->Znf);(C->Z3c)=ZIL((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[ZGs(0)]),ZiL);}T81 Zkb1(Zk3*C){
T81 R={Zo,Zo,0};R=(((ZD8*)(((C)->Z2c)))->ZCb);return R;}void ZHb1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));
}T6 ZbG(Zo3*C,T0*a1){T6 R=0;T2 Zet=0;if((Z3)((ZIb1(C,a1))>(ZGs(0)))){R=((T6)(1));}else{Zet=ZZF(C);while(!((T6)((R)||((T6)((Zet)==(ZGs(0)))))))
{R=((T6)(ZJb1(((T85*)a1),Z_F(C,Zet))));Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}T2 ZZF(Zo3*C){T2 R=0;if((((C)->Z5e))==((void*)(Zo))){R=ZGs(1);
}else{R=(Z3)(((ZGs(2)))+((((ZP*)(((C)->Z5e)))->ZWb)));}return R;}T0*Z_F(Zo3*C,T2 a1){T0*R=Zo;if((a1)==(ZGs(1))){R=((C)->ZGd);}else{R=((((ZP*)(((C)->Z5e)))->ZUb))[(Z3)(((a1))-(ZGs(2)))];
}return R;}void ZeG(Zo3*C,T0*a1,T0*a2){T2 Zet=0;T0*ZWF=Zo;(C->ZGd)=Z_F(((Zo3*)a1),ZGs(1));{ZP*n=((ZP*)Zh(sizeof(*n)));*n=Zfc;Zvz(n,(Z3)((((Z3)(((ZZF(((Zo3*)a1))))+(ZZF(((Zo3*)a2))))))-((T2)(ZGs(1)))));
(C->Z5e)=((T0*)n);}Zet=ZZF(((Zo3*)a1));while(!((Zet)==(ZGs(1)))){Zuz((ZP*)(((C)->Z5e)),Z_F(((Zo3*)a1),Zet));Zet=(Z3)(((Zet))-(ZGs(1)));
}Zet=ZZF(((Zo3*)a2));while(!((Zet)==(ZGs(0)))){ZWF=Z_F(((Zo3*)a2),Zet);if((ZIb1(C,ZWF))==(ZGs(0))){Zuz((ZP*)(((C)->Z5e)),ZWF);}Zet=(Z3)(((Zet))-(ZGs(1)));
}}T2 ZIb1(Zo3*C,T0*a1){T2 R=0;T0*ZKb1=Zo;ZKb1=((((T85*)a1))->Zse);R=ZZF(C);while(!((T6)(((R)==(ZGs(0)))||((T6)((ZKb1)==((void*)((((T85*)(Z_F(C,R)))->Zse))))))))
{R=(Z3)(((R))-(ZGs(1)));}return R;}void ZgG(Zo3*C){T2 Zet=0;T0*ZWF=Zo;Zet=ZZF(C);while(!((Zet)==(ZGs(0)))){ZWF=Z_F(C,Zet);Z5G(((((T85*)ZWF))->ZCb));
Zet=(Z3)(((Zet))-(ZGs(1)));}}T6 ZhG(Zo3*C){T6 R=0;T2 Zet=0;T0*ZWF=Zo;Zet=ZZF(C);while(!((T6)((R)||((T6)((Zet)==(ZGs(0))))))){ZWF=Z_F(C,Zet);
R=((T6)((((((T85*)ZWF))->Zse))==((void*)(ZVH))));Zet=(Z3)(((Zet))-(ZGs(1)));}return R;}void ZLb1(Zo3*C,T0*a1){T2 Zet=0;Zet=ZIb1(C,a1);
if((Z3)((Zet)>(ZGs(0)))){Z5G((((T85*)(Z_F(C,Zet)))->ZCb));ZHb1(((((T85*)a1))->ZCb),Z1G(30,"Same Class Name appears twice."));}if((((C)->Z5e))==((void*)(Zo))){
{ZP*n=((ZP*)Zh(sizeof(*n)));*n=Zfc;Zvz(n,(T2)(ZGs(4)));(C->Z5e)=((T0*)n);}}Zuz((ZP*)(((C)->Z5e)),a1);}void ZMb1(Zq3*C){ZNb1(C);ZpG((((ZD8*)(((C)->Z2c)))->ZCb),Zo,((C)->Z3c));
}T6 ZOb1(Zq3*C,T0*a1){T6 R=0;T0*ZUG=Zo;R=((T6)(1));if(R){if((((C)->Z3c))==((void*)(Zo))){R=((T6)(ZWG(((C)->Z1c),a1)));}else if(ZXG(((C)->Z1c))){
if(ZYG(((C)->Z3c),a1)){R=((T6)((ZZG(((C)->Z3c),a1))!=((void*)(Zo))));}else{R=((T6)(0));}}else{R=((T6)(ZWG(((C)->Z1c),a1)));if(R){if((((C)->Z3c))!=((void*)(Zo))){
ZUG=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Z3c)))->Z4c))))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZUG))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
R=((T6)(ZYG(((C)->Z3c),ZUG)));}}}}}return R;}void ZPb1(Zq3*C,T0*a1,T0*a2){(C->Z3c)=Zo;(C->Z4c)=Zo;(C->Z1c)=a1;(C->Z2c)=a2;}T0*ZQb1(Zq3*C){
T0*R=Zo;if((((T43*)(ZSG))->ZRk)){R=((T0*)(C));}else{R=((T0*)(C));if((R)!=((void*)(C))){Z8H((T43*)(ZSG));}}return R;}T0*ZRb1(Zq3*C){T0*R=Zo;
(C->Z1c)=ZaH(((C)->Z1c));R=((T0*)(C));return R;}void ZSb1(Zq3*C){T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){}ZgH(((C)->Z1c));}void ZNb1(Zq3*C){
if((ZiH(((C)->Z3c)))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));ZTb1(Z1G(29,"Feature found is a procedure."));
}}T6 ZUb1(Zq3*C,T0*a1){T6 R=0;R=((T6)(ZOb1(C,a1)));if(R){R=((T6)(!(ZmH(ZnH(ZVb1(C))))));}return R;}void ZWb1(Zq3*C,T0*a1,T0*a2){ZqH(((C)->Z1c),a1,a2);
}void ZXb1(Zq3*C){{T81 Zow;Z5G((*(Zow=ZYb1(C),&Zow)));}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZZb1(Zq3*C,T0*a1,T0*a2){(C->Z1c)=a1;(C->Z2c)=a2;}void Z_b1(Zq3*C,T0*a1){T0*ZxH=Zo;ZxH=ZyH(((C)->Z1c),a1);
if((ZxH)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));}{T0*b1=Z1G(11,"Bad target.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));
}(C->Z1c)=ZxH;}void ZTb1(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Z0c1(Zq3*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}{T81 Zow;
Z5G((*(Zow=ZYb1(C),&Zow)));}Z3G((T80*)(Z4G));}T2 Z1c1(void){T2 R=0;return R;}void Z2c1(Zq3*C,T3 a1){if((a1)==(((T3)'R'))){{T81 Zow;ZDH(((C)->Z3c),(*(Zow=ZYb1(C),&Zow)));
}}ZEH(((C)->Z1c),a1);}T0*ZVb1(Zq3*C){T0*R=Zo;R=ZiH(((C)->Z3c));return R;}void Z3c1(Zq3*C){T0*ZIH=Zo;T0*ZJH=Zo;T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){
ZIH=ZGH(((C)->Z1c));ZJH=Z_G(ZIH);ZdH=((((ZZ3*)ZJH))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
ZKH(((C)->Z1c),((C)->Z3c));}}ZLH(((C)->Z1c));}T6 Z4c1(Zq3*C){T6 R=0;if(R){}else if(ZXG(((C)->Z1c))){if((ZPH())!=((void*)(((C)->Z3c)))){
R=((T6)(ZQH(((C)->Z3c))));}}else{R=((T6)(ZRH(((C)->Z1c))));}return R;}T6 Z5c1(Zq3*C){T6 R=0;if(Z0L(((C)->Z1c))){R=((T6)(1));}return R;
}T6 Z6c1(Zq3*C,T0*a1){T6 R=0;R=((T6)(Z3L(ZGH(((C)->Z1c)))));R=((T6)((T6)((Z4L(((C)->Z1c),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z5L(((Zz6*)a1),((C)->Z1c))){
R=((T6)(1));}}else if((T6)((Z3L(ZGH(((C)->Z1c))))&&((T6)(!(ZXG(((C)->Z1c))))))){Z6L(((C)->Z1c));}return R;}void Z7c1(Zq3*C,T0*a1){T6 Z8L=0;
T0*Z9L=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Z9L=ZnH(ZVb1(C));if(ZbL(Z9L)){if(ZbL(a1)){ZcL(a1);ZdL((Z84*)(ZkH),((T3)'\050'));{Zq3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);
}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Zq3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}else{if(ZbL(a1)){{Zq3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}else{
if(ZfL(a1)){ZdL((Z84*)(ZkH),((T3)'\046'));ZdL((Z84*)(ZkH),((T3)'\050'));{Zq3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));
}else{{Zq3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}}if(Z8L){ZgL((Z84*)(ZkH));}}void Z8c1(Zq3*C,T0*a1){T0*ZiL=Zo;T0*ZJH=Zo;T0*ZjL=Zo;T0*ZkL=Zo;
ZjL=ZGH(((C)->Z1c));if((ZjL)!=((void*)(Zo))){ZJH=Z_G(ZjL);if((ZJH)!=((void*)(Zo))){ZkL=((((ZZ3*)ZJH))->Zvb);ZiL=ZlL(((T87*)ZkL),ZJH,((C)->Z1c),((C)->Z2c),a1);
}}if((ZiL)==((void*)(Zo))){Z5G((((ZD8*)(((C)->Z2c)))->ZCb));{T0*b1=Z1G(25,"Bad target for this call.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));
}(C->Z3c)=ZiL;}T0*Z9c1(Zq3*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zq3*)R)=*C;return R;}T2 Zac1(Zq3*C){T2 R=0;T0*ZTX=Zo;ZTX=((C)->Z3c);if(Zo!=(ZTX)){
switch(((T0*)ZTX)->id){case 583:break;default:ZTX=Zo;}}if((ZTX)==((void*)(Zo))){Z0c1(C);}else{R=ZSU(((((ZC7*)ZTX))->Zde));}return R;}
T0*Zbc1(Zq3*C,T0*a1){T0*R=Zo;T0*ZrL=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;Z_b1(C,a1);Z8c1(C,a1);R=ZQb1(C);ZMb1(C);}else{ZrL=Z9c1(C);
ZPb1(((Zq3*)ZrL),((C)->Z1c),((C)->Z2c));R=Zbc1(((Zq3*)ZrL),a1);}return R;}T0*Zcc1(Zq3*C){T0*R=Zo;T0*ZkL=Zo;T0*ZyL=Zo;T0*ZjL=Zo;ZkL=ZzL(((C)->Z1c));
if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),((C)->Z2c));if((ZyL)!=((void*)(Zo))){ZjL=ZBL(ZyL);if((ZjL)!=((void*)(Zo))){R=ZCL(ZjL);}}
}return R;}void Zdc1(Zq3*C){if((((C)->Z3c))!=((void*)(Zo))){ZEL(((C)->Z3c));}ZFL(((C)->Z1c));}void Zec1(Zq3*C){T0*ZJH=Zo;T0*ZiL=Zo;ZiL=((C)->Z3c);
ZJH=((((ZQ7*)ZiL))->Znf);(C->Z3c)=ZIL((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[ZGs(0)]),ZiL);}T81 ZYb1(Zq3*C){
T81 R={Zo,Zo,0};R=(((ZD8*)(((C)->Z2c)))->ZCb);return R;}void Zfc1(Zw3*C){Zgc1(C);ZpG((((ZD8*)(((C)->Z2c)))->ZCb),Zo,((C)->Z3c));}T6 Zhc1(Zw3*C,T0*a1){
T6 R=0;T0*ZUG=Zo;R=((T6)(1));if(R){if((((C)->Z3c))==((void*)(Zo))){R=((T6)(ZWG(((C)->Z1c),a1)));}else if(ZXG(((C)->Z1c))){if(ZYG(((C)->Z3c),a1)){
R=((T6)((ZZG(((C)->Z3c),a1))!=((void*)(Zo))));}else{R=((T6)(0));}}else{R=((T6)(ZWG(((C)->Z1c),a1)));if(R){if((((C)->Z3c))!=((void*)(Zo))){
ZUG=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Z3c)))->Z4c))))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZUG))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
R=((T6)(ZYG(((C)->Z3c),ZUG)));}}}}}return R;}void Zic1(Zw3*C,T0*a1,T0*a2){(C->Z3c)=Zo;(C->Z4c)=Zo;(C->Z1c)=a1;(C->Z2c)=a2;}T0*Zjc1(Zw3*C){
T0*R=Zo;if((((T43*)(ZSG))->ZRk)){R=((T0*)(C));}else{R=Zkc1(C);if((R)!=((void*)(C))){Z8H((T43*)(ZSG));}}return R;}T0*Zlc1(Zw3*C){T0*R=Zo;
(C->Z1c)=ZaH(((C)->Z1c));R=Zkc1(C);return R;}void Zmc1(Zw3*C){T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){}ZgH(((C)->Z1c));}void Zgc1(Zw3*C){
if((ZiH(((C)->Z3c)))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));Znc1(Z1G(29,"Feature found is a procedure."));
}}void Zoc1(Zw3*C){if((T6)((((((T89*)(ZPM))->Zaf))==(ZGs(1)))&&((T6)(ZmU(ZnH(ZGH(((C)->Z1c)))))))){ZgM((Z84*)(ZkH),Zpc1);ZD21(((C)->Z1c));
ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Zw3*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}T6 Zqc1(Zw3*C,T0*a1){T6 R=0;R=((T6)(Zhc1(C,a1)));if(R){R=((T6)(!(ZmH(ZnH(Zrc1(C))))));
}return R;}void Zsc1(Zw3*C,T0*a1,T0*a2){ZqH(((C)->Z1c),a1,a2);}void Ztc1(Zw3*C){{T81 Zow;Z5G((*(Zow=Zuc1(C),&Zow)));}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Zvc1(Zw3*C,T81 a1,T0*a2){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Zwc1(n,(ZVI),a1);(C->Z2c)=((T0*)n);
}(C->Z1c)=a2;}void Zxc1(Zw3*C,T0*a1){T0*ZxH=Zo;ZxH=ZyH(((C)->Z1c),a1);if((ZxH)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));
}{T0*b1=Z1G(11,"Bad target.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z1c)=ZxH;}void Znc1(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}void Zyc1(Zw3*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=Zuc1(C),&Zow)));}Z3G((T80*)(Z4G));}T2 Zzc1(void){
T2 R=0;return R;}void ZAc1(Zw3*C,T3 a1){if((a1)==(((T3)'R'))){{T81 Zow;ZDH(((C)->Z3c),(*(Zow=Zuc1(C),&Zow)));}}ZEH(((C)->Z1c),a1);}T0*Zrc1(Zw3*C){
T0*R=Zo;R=ZiH(((C)->Z3c));return R;}void ZBc1(Zw3*C){T0*ZIH=Zo;T0*ZJH=Zo;T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){ZIH=ZGH(((C)->Z1c));
ZJH=Z_G(ZIH);ZdH=((((ZZ3*)ZJH))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){ZKH(((C)->Z1c),((C)->Z3c));
}}ZLH(((C)->Z1c));}T6 ZCc1(Zw3*C){T6 R=0;if(R){}else if(ZXG(((C)->Z1c))){if((ZPH())!=((void*)(((C)->Z3c)))){R=((T6)(ZQH(((C)->Z3c))));
}}else{R=((T6)(ZRH(((C)->Z1c))));}return R;}T6 ZDc1(Zw3*C){T6 R=0;if(Z0L(((C)->Z1c))){R=((T6)(1));}return R;}T6 ZEc1(Zw3*C,T0*a1){T6 R=0;
R=((T6)(Z3L(ZGH(((C)->Z1c)))));R=((T6)((T6)((Z4L(((C)->Z1c),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z5L(((Zz6*)a1),((C)->Z1c))){
R=((T6)(1));}}else if((T6)((Z3L(ZGH(((C)->Z1c))))&&((T6)(!(ZXG(((C)->Z1c))))))){Z6L(((C)->Z1c));}return R;}T6 ZFc1(Zw3*C){T6 R=0;if(ZmU(ZGH(((C)->Z1c)))){
R=((T6)(Z_W(((C)->Z1c))));}return R;}void ZGc1(Zw3*C,T0*a1){T6 Z8L=0;T0*Z9L=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Z9L=ZnH(Zrc1(C));if(ZbL(Z9L)){
if(ZbL(a1)){ZcL(a1);ZdL((Z84*)(ZkH),((T3)'\050'));Zoc1(C);ZdL((Z84*)(ZkH),((T3)'\051'));}else{Zoc1(C);}}else{if(ZbL(a1)){Zoc1(C);}else{
if(ZfL(a1)){ZdL((Z84*)(ZkH),((T3)'\046'));ZdL((Z84*)(ZkH),((T3)'\050'));Zoc1(C);ZdL((Z84*)(ZkH),((T3)'\051'));}else{Zoc1(C);}}}if(Z8L){
ZgL((Z84*)(ZkH));}}void ZHc1(Zw3*C,T0*a1){T0*ZiL=Zo;T0*ZJH=Zo;T0*ZjL=Zo;T0*ZkL=Zo;ZjL=ZGH(((C)->Z1c));if((ZjL)!=((void*)(Zo))){ZJH=Z_G(ZjL);
if((ZJH)!=((void*)(Zo))){ZkL=((((ZZ3*)ZJH))->Zvb);ZiL=ZlL(((T87*)ZkL),ZJH,((C)->Z1c),((C)->Z2c),a1);}}if((ZiL)==((void*)(Zo))){Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
{T0*b1=Z1G(25,"Bad target for this call.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z3c)=ZiL;}T0*ZIc1(Zw3*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Zw3*)R)=*C;return R;}T2 ZJc1(Zw3*C){T2 R=0;T0*ZTX=Zo;ZTX=((C)->Z3c);if(Zo!=(ZTX)){switch(((T0*)ZTX)->id){case 583:break;default:ZTX=Zo;
}}if((ZTX)==((void*)(Zo))){Zyc1(C);}else{R=ZSU(((((ZC7*)ZTX))->Zde));}return R;}T0*ZKc1(Zw3*C,T0*a1){T0*R=Zo;T0*ZrL=Zo;if((((C)->Z4c))==((void*)(Zo))){
(C->Z4c)=a1;Zxc1(C,a1);ZHc1(C,a1);R=Zjc1(C);Zfc1(C);}else{ZrL=ZIc1(C);Zic1(((Zw3*)ZrL),((C)->Z1c),((C)->Z2c));R=ZKc1(((Zw3*)ZrL),a1);
}return R;}T0*Zkc1(Zw3*C){T0*R=Zo;T0*ZkL=Zo;ZkL=((C)->Z1c);if(Zo!=(ZkL)){switch(((T0*)ZkL)->id){case 318:case 319:break;default:ZkL=Zo;
}}if((ZkL)==((void*)(Zo))){R=((T0*)(C));}else if(ZuL(ZkL)){{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zml;ZwL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);
}}else{{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;ZvL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);}}return R;}T0*ZLc1(Zw3*C){T0*R=Zo;T0*ZkL=Zo;
T0*ZyL=Zo;T0*ZjL=Zo;ZkL=ZzL(((C)->Z1c));if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),((C)->Z2c));if((ZyL)!=((void*)(Zo))){ZjL=ZBL(ZyL);
if((ZjL)!=((void*)(Zo))){R=ZCL(ZjL);}}}return R;}void ZMc1(Zw3*C){if((((C)->Z3c))!=((void*)(Zo))){ZEL(((C)->Z3c));}ZFL(((C)->Z1c));}void
ZNc1(Zw3*C){T0*ZJH=Zo;T0*ZiL=Zo;ZiL=((C)->Z3c);ZJH=((((ZQ7*)ZiL))->Znf);(C->Z3c)=ZIL((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[ZGs(0)]),ZiL);
}T81 Zuc1(Zw3*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((C)->Z2c)))->ZCb);return R;}void ZOc1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);
}Z3G((T80*)(Z4G));}void ZPc1(ZE3*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){{Zz8*n=((Zz8*)Zh(sizeof(*n)));*n=Z9l;((((Zz8*)(n)))->ZGd)=(a1);(C->Zkc)=((T0*)n);
}ZQc1(C,((C)->Zkc),a2,Zo,Zo,a3);((((ZE3*)(C)))->ZFe)=(a4);(C->Zvb)=a5;}T6 ZRc1(ZE3*C,T0*a1,T0*a2){T6 R=0;if((Zo)!=((void*)(ZBL(a1)))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZOc1((*(Zow=ZSc1(C),&Zow)),ZWN);}}if((((C)->ZFb))!=((void*)(ZXN(a1)))){if((T6)(((((C)->ZFb))==((void*)(Zo)))||((T6)((ZXN(a1))==((void*)(Zo)))))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZOc1((*(Zow=ZSc1(C),&Zow)),ZYN);}}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){
{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;ZOc1((*(Zow=ZSc1(C),&Zow)),ZTc1);}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
if((((C)->ZFb))!=((void*)(Zo))){if(!(ZQa1((Zz6*)(((C)->ZFb)),ZXN(a1),a2))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Z5G((*(Zow=ZSc1(C),&Zow)));
}{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}
}}R=((T6)(((((T80*)(Z4G))->ZEg))==(ZGs(0))));if(R){ZUc1(C,a1);}return R;}void ZUc1(ZE3*C,T0*a1){if((((T43*)(ZSG))->ZRk)){if((((C)->ZHb))==((void*)(Zo))){
(C->ZHb)=Z2O(a1);}else if((Z2O(a1))==((void*)(Zo))){Z3O(a1,((C)->ZHb));}}}void ZVc1(ZE3*C,T0*a1){T2 Zet=0;T0*Z5O=Zo;T0*Z6O=Zo;(C->Zvb)=(((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),ZGs(1))))->ZCb)).Zvb);
Zet=ZGs(1);while(!((Z3)((Zet)>(Z8O((Zz8*)(((C)->Zkc))))))){Z5O=Z7O((Zz8*)(((C)->Zkc)),Zet);Z6O=Z3D(((Zp6*)a1),Z5O);if((Z6O)!=((void*)(Zo))){
Z5O=((((Zz8*)(((((ZX4*)Z6O))->Zkc))))->ZGd);Z5G(((((ZD8*)Z5O))->ZCb));Z5G((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),Zet)))->ZCb));{T0*b1=Z1G(29,"Double definition of feature ");
Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)Z5O))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}else{Z0D(((Zp6*)a1),(T0*)C,Z5O);
}Zet=(Z3)(((Zet))+(ZGs(1)));}}void ZQc1(ZE3*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){((((ZE3*)(C)))->Zkc)=(a1);(C->ZHb)=a4;(C->ZFb)=a2;(C->ZIb)=a3;
(C->ZJb)=a5;}T0*ZWc1(ZE3*C,T0*a1,T0*a2){T0*R=Zo;T0*ZaO=Zo;Z5G(((((ZD8*)a1))->ZCb));ZaO=ZbO((Zz8*)(((C)->Zkc)),((((ZD8*)a1))->Zcn));if((ZaO)!=((void*)(Zo))){
ZcO(((ZD8*)ZaO),a2);}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=((T0*)(C));if((R)!=((void*)(Zo))){
((((ZE3*)(((ZE3*)R))))->Zjc)=(((C)->Zjc));ZUc1(C,R);}else{ZTN(((T87*)a2),a1);}return R;}void ZXc1(ZE3*C,T81 a1){if((((C)->ZIb))!=((void*)(Zo))){
if(!((((T43*)(ZSG))->ZRk))){Z5G(a1);{T0*b1=Z1G(27,"This feature is obsolete :\n");Zmx((T7*)(Z2G),b1);}{T0*b1=(((T93*)(((C)->ZIb)))->Zse);
Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZSc1(C),&Zow)));}ZPG((T80*)(Z4G));}}}T0*ZYc1(ZE3*C,T0*a1,T0*a2){T0*R=Zo;{ZU7*n=((ZU7*)Zh(sizeof(*n)));
*n=Znk;ZZc1(n,a1,a2,(T0*)C);R=((T0*)n);}return R;}void Z_c1(ZE3*C,T0*a1){if((T6)(((a1)!=((void*)(Zo)))&&((T6)((Z3)((ZZy(((T79*)(((((T91*)a1))->ZZb)))))>(ZGs(1))))))){
(C->ZGe)=a1;}}T6 Z0d1(ZE3*C,T0*a1){T6 R=0;R=((T6)((ZBL(a1))!=((void*)(Zo))));if(R){{T0*b1=ZWN;Zmx((T7*)(Z2G),b1);}}else{if((((C)->ZFb))==((void*)(Zo))){
R=((T6)((ZXN(a1))!=((void*)(Zo))));}else{R=((T6)((ZXN(a1))==((void*)(Zo))));}if(R){{T0*b1=ZYN;Zmx((T7*)(Z2G),b1);}}else if((((C)->ZFb))==((void*)(Zo))){
}else if((Zjy(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie)))))!=(Zjy(((Zl2*)((((Zz6*)(ZXN(a1)))->Zie)))))){{T0*b1=ZTc1;Zmx((T7*)(Z2G),b1);}R=((T6)(1));
}}ZUc1(C,a1);return R;}T81 ZSc1(ZE3*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->ZCb);return R;}void Z1d1(ZE3*C,T0*a1){
if((a1)!=((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z2d1(((ZX6*)a1)),&Zow)));}}else{{T81 Zow;Z5G((*(Zow=ZSc1(C),&Zow)));}}{T0*b1=Z1G(47,"Deferred feature must not have rescue compound.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}T2 Z3d1(ZI3*C){T2 R=0;R=(((Zl2*)(((C)->ZKe)))->ZWb);return R;}void Z4d1(ZI3*C,T0*a1,T0*a2){T2 Zet=0;
(C->ZKe)=a1;Zet=(((Zl2*)(((C)->ZKe)))->ZWb);while(!((Zet)==(ZGs(0)))){((((Zi1*)((Zi1*)(Z5d1(((C)->ZKe),Zet)))))->Zlc)=(a2);Zet=(Z3)(((Zet))-(ZGs(1)));
}}void Z6d1(ZI3*C,T0*a1){T2 Zet=0;Zet=(((Zl2*)(((C)->ZKe)))->ZXb);while(!((Z3)((Zet)>((((Zl2*)(((C)->ZKe)))->ZWb))))){ZkO(a1,Z5d1(((C)->ZKe),Zet));
Zet=(Z3)(((Zet))+(ZGs(1)));}}T0*Z7d1(ZX3*C,T0*a1,T0*a2){T0*R=Zo;{T81 Zow;Z5G((*(Zow=Z8d1(C),&Zow)));}Z9d1(((((ZD8*)a1))->ZCb),Z1G(42,"An attribute must not be undefined (VDUS)."));
ZTN(((T87*)a2),a1);return R;}void Z9d1(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T6 Zad1(ZX3*C,T0*a1,T0*a2){
T6 R=0;if((((C)->Zlc))!=((void*)(ZBL(a1)))){if((T6)(((((C)->Zlc))==((void*)(Zo)))||((T6)((ZBL(a1))==((void*)(Zo)))))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));
}{T81 Zow;Z9d1((*(Zow=Z8d1(C),&Zow)),ZWN);}}}if((Zo)!=((void*)(ZXN(a1)))){{T81 Zow;Z5G((*(Zow=ZVN(a1),&Zow)));}{T81 Zow;Z9d1((*(Zow=Z8d1(C),&Zow)),ZYN);
}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){if((((C)->Zlc))!=((void*)(Zo))){if(!(ZZN(ZBL(a1),((C)->Zlc),a2,(T6)(0)))){{T0*b1=Z_N;Zmx((T7*)(Z2G),b1);
}{T0*b1=Z9G(((((ZZ3*)a2))->Z4c));Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){
}R=((T6)(((((T80*)(Z4G))->ZEg))==(ZGs(0))));if(R){Zbd1(C,a1);}return R;}void Zbd1(ZX3*C,T0*a1){if((((T43*)(ZSG))->ZRk)){if((((C)->ZHb))==((void*)(Zo))){
(C->ZHb)=Z2O(a1);}else if((Z2O(a1))==((void*)(Zo))){Z3O(a1,((C)->ZHb));}}}void Zcd1(ZX3*C,T0*a1){T2 Zet=0;T0*Z5O=Zo;T0*Z6O=Zo;(C->Zvb)=(((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),ZGs(1))))->ZCb)).Zvb);
Zet=ZGs(1);while(!((Z3)((Zet)>(Z8O((Zz8*)(((C)->Zkc))))))){Z5O=Z7O((Zz8*)(((C)->Zkc)),Zet);Z6O=Z3D(((Zp6*)a1),Z5O);if((Z6O)!=((void*)(Zo))){
Z5O=((((Zz8*)(((((ZX4*)Z6O))->Zkc))))->ZGd);Z5G(((((ZD8*)Z5O))->ZCb));Z5G((((ZD8*)(Z7O((Zz8*)(((C)->Zkc)),Zet)))->ZCb));{T0*b1=Z1G(29,"Double definition of feature ");
Zmx((T7*)(Z2G),b1);}{T0*b1=((((ZD8*)Z5O))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z0O;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}else{Z0D(((Zp6*)a1),(T0*)C,Z5O);
}Zet=(Z3)(((Zet))+(ZGs(1)));}}T0*Zdd1(ZX3*C,T0*a1,T0*a2){T0*R=Zo;T0*ZaO=Zo;Z5G(((((ZD8*)a1))->ZCb));ZaO=ZbO((Zz8*)(((C)->Zkc)),((((ZD8*)a1))->Zcn));
if((ZaO)!=((void*)(Zo))){ZcO(((ZD8*)ZaO),a2);}((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));R=Z7d1(C,a1,a2);
if((R)!=((void*)(Zo))){((((ZE3*)(((ZE3*)R))))->Zjc)=(((C)->Zjc));Zbd1(C,R);}else{ZTN(((T87*)a2),a1);}return R;}void Zed1(ZX3*C,T0*a1,T0*a2,T0*a3){
((((ZX3*)(C)))->Zkc)=(a1);(C->Zlc)=a2;(C->Zmc)=a3;}T0*Zfd1(ZX3*C,T0*a1,T0*a2){T0*R=Zo;T0*ZJH=Zo;ZJH=Z_G(a1);R=ZjD(((ZR6*)(((((ZZ3*)ZJH))->Ztg))),a2);
if(Zo!=(R)){switch(((T0*)R)->id){case 583:break;default:R=Zo;}}if((R)==((void*)(Zo))){{ZC7*n=((ZC7*)Zh(sizeof(*n)));*n=Zak;ZfO(n,a1,a2,(T0*)C);
R=((T0*)n);}}return R;}T6 Zgd1(ZX3*C,T0*a1){T6 R=0;if((((C)->Zlc))==((void*)(Zo))){R=((T6)((ZBL(a1))!=((void*)(Zo))));}else{R=((T6)((ZBL(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZWN;Zmx((T7*)(Z2G),b1);}}else{R=((T6)((ZXN(a1))!=((void*)(Zo))));if(R){{T0*b1=ZYN;Zmx((T7*)(Z2G),b1);}}}Zbd1(C,a1);return
R;}T81 Z8d1(ZX3*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((((Zz8*)(((C)->Zkc))))->ZGd)))->ZCb);return R;}
#ifdef __cplusplus
}
#endif

