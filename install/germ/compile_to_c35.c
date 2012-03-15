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
T0*ZPA2(ZK9*C){T0*R=Zo;T6 ZSY1=0;T0*_n=Zo;T0*_cn=Zo;(C->ZZe)=Zo;(C->ZXe)=Zrs(1);(C->ZWe)=Zrs(1);(C->ZYe)=(((((T52*)((((T72*)(ZoD2()))->Z2l))))->ZPb))[((C)->ZXe)];
if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}ZpD2(C);while(!(ZSY1))
{if((((C)->_cc))==(((T3)'\000'))){ZSY1=((T6)(1));}else if(ZqD2(C,Zfy2)){ZSY1=((T6)(1));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z6x(n,(T2)(Zrs(32)));
_n=((T0*)n);}while(!(Zfx(((T7*)ZrD2),((C)->_cc)))){ZZs(((T7*)_n),((C)->_cc));ZsD2(C);}{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Z721(n,(((void)((T26*)(ZtD2()))),ZAS(_n)));
_cn=((T0*)n);}}else{while(!(Zfx(((T7*)ZuD2),((C)->_cc)))){ZsD2(C);}ZpD2(C);}}if((_cn)==((void*)(Zo))){{T0*b1=ZvF(38,"Unable to find a class definition in \"");
ZXw((T7*)(ZwF),b1);}{T0*b1=(((T72*)(ZoD2()))->Zoc);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(2,Zwn);ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}R=Z6C2(C,_cn);
return R;}T0*ZvD2(ZK9*C){T0*R=Zo;T76 _sp={Zo,Zo,0};T0*_hc=Zo;T0*_al=Zo;T0*_ea=Zo;T6 ZwD2=0;T6 ZxD2=0;if(ZqD2(C,Zuy2)){if(ZyD2(C)){((((T88*)((T88*)(((C)->Zrl)))))->ZOm)=((T6)(1));
((((ZA7*)(&(((C)->ZBm)))))->ZDb)=(((C)->Zrl));}else{ZzD2(C,ZvF(34,"Obsolete manifest string expected."));}}((((ZA7*)(&(((C)->ZBm)))))->ZCb)=(ZAD2(C));
if(ZqD2(C,Z3g1)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}ZwD2=((T6)(ZqD2(C,Zo71)));_hc=ZAD2(C);ZvA2(&(((C)->ZBm)),_sp,(T6)(ZwD2),_hc,ZCD2(C));
}if(ZqD2(C,Zty2)){ZDD2(C);}R=ZED2(C);if(ZqD2(C,Z4g1)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}(C->Zgm)=((T6)(1));ZxD2=((T6)(ZqD2(C,ZDy2)));
_hc=ZAD2(C);_al=ZCD2(C);if((T6)(((_hc)!=((void*)(Zo)))||((T6)((_al)!=((void*)(Zo)))))){{Z11*n=((Z11*)Zh(sizeof(*n)));*n=Znc;Zik2(n,_sp,(T6)(ZxD2),_hc,_al);
_ea=((T0*)n);}}((((Z85*)(((Z85*)R))))->ZDe)=(_ea);(C->Zgm)=((T6)(0));}if(ZqD2(C,Zzy2)){(C->Zhm)=((T6)(1));ZFD2(R,ZGD2(C,Zzy2,ZEp2));(C->Zhm)=((T6)(0));
}else if(ZqD2(C,ZEp2)){if(Zcp2((T84*)(ZFI))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}((((Z85*)(((Z85*)R))))->ZCe)=(_sp);
}}else{{ZK9*C1=C;T0*b1=ZvF(35,"A routine must be ended with \"end\".");{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}(C->ZFb)=Zo;return
R;}void ZID2(ZK9*C,T6 a1,T0*a2){T0*ZLn1=Zo;T0*Zko2=Zo;if(ZJD2(C)){if((T6)(((T6)((ZKD2(C))||((T6)(ZLD2(C)))))||((T6)(ZMD2(C))))){{T76 Z3w;
ZlA2((*(Z3w=ZGG(((C)->Zom)),&Z3w)),ZvF(38,"This name must not appear after a dot."));}}ZLn1=ZMy2(&(((C)->Z2f)));Zko2=ZND2(C);ZOD2(C,(T6)(a1),a2,ZLn1,Zko2,(T6)(0));
}else{ZzD2(C,ZvF(32,"Identifier expected after a dot."));}}T0*ZPD2(void){if(ZVm1==0){ZVm1=1;{{ZD*n=((ZD*)Zh(sizeof(*n)));*n=ZWb;ZUm1=((T0*)n);
}}}return ZUm1;}T6 ZMD2(ZK9*C){T6 R=0;if(ZQy2()){{Zj8*n=((Zj8*)Zh(sizeof(*n)));*n=ZHk;((((Zj8*)(n)))->Zxb)=(((((C)->Z2f)).Zxb));(C->Zom)=((T0*)n);
}R=((T6)(1));}return R;}void ZQD2(ZK9*C,T6 a1){T0*Zxd=Zo;T0*Zg92=Zo;if(ZMD2(C)){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->Zom)),&Z3w)));}{T0*b1=ZvF(26,"Must not affect `Current\'.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else if(ZLD2(C)){ZzF(((((C)->Z2f)).Zxb));{T0*b1=ZvF(23,"Must not affect `Void\'.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}else if(ZRD2(C)){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->Zom)),&Z3w)));}{T0*b1=ZvF(34,"Must not affect a formal argument.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else{if(Z9y2()){Zxd=ZSD2(C);}else if(ZTD2(C)){Zxd=((C)->Zom);}else{Zxd=ZMy2(&(((C)->Z2f)));}if(ZUD2(C)){
Zg92=((C)->Zom);if(a1){{Ze9*n=((Ze9*)Zh(sizeof(*n)));*n=ZRl;ZuH1(n,Zxd,Zg92);(C->Zum)=((T0*)n);}}else{{ZO5*n=((ZO5*)Zh(sizeof(*n)));*n=ZIh;
Zzr1(n,Zxd,Zg92);(C->Zum)=((T0*)n);}}}else{ZzD2(C,ZvF(51,"Right hand side expression expected for assignment."));}}}T6 ZVD2(ZK9*C,T0*a1){
T6 R=0;T0*ZTc=Zo;if(ZUD2(C)){R=((T6)(1));ZTc=ZWD2(C,((C)->Zom));if(!(ZqD2(C,ZDy2))){{ZK9*C1=C;T0*b1=ZvF(13,"Added \"then\".");{T76 Z3w;
ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}ZWk1(((Ze5*)a1),ZTc,ZXD2(C));}return R;}void ZXA2(T2 a1,T0*a2){if((Z3)((a1)>(Zrs(0)))){(((void)((T36*)(ZWA2()))),ZUf1(Zxv2));
(((void)((T36*)(ZWA2()))),Zws1(a1));(((void)((T36*)(ZWA2()))),ZUf1(a2));}}T76 ZmA2(ZK9*C){T76 R={Zo,Zo,0};{T76 Z3w;R=(*(Z3w=ZBD2(C,((C)->ZXe),((C)->ZWe)),&Z3w));
}return R;}void ZHD2(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));}T0*ZXD2(ZK9*C){T0*R=Zo;T0*_hc=Zo;T0*ZUk=Zo;
_hc=ZAD2(C);(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));while(!(!(ZZD2(C)))){ZUk=((C)->Zum);if((((C)->_cc))==(((T3)'\050'))){{ZK9*C1=C;T0*b1=Z_D2;
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));while(!((((C)->_cc))!=(((T3)'\073')))){{ZK9*C1=C;T0*b1=Z0E2;
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){ZUk=Z1E2(C,ZUk);
if((R)==((void*)(Zo))){{Z47*n=((Z47*)Zh(sizeof(*n)));*n=Zwj;Z4J1(n,_hc,ZUk);R=((T0*)n);}}else{Z5J1(((Z47*)R),ZUk);}}}if((T6)(((_hc)!=((void*)(Zo)))&&((T6)((R)==((void*)(Zo)))))){
{Z47*n=((Z47*)Zh(sizeof(*n)));*n=Zwj;((((Z47*)(n)))->ZCb)=(_hc);R=((T0*)n);}}return R;}T0*ZGD2(ZK9*C,T0*a1,T0*a2){T0*R=Zo;T0*_hc=Zo;T0*ZUk=Zo;
_hc=ZAD2(C);(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));while(!(!(ZZD2(C)))){ZUk=((C)->Zum);if((((C)->_cc))==(((T3)'\050'))){{ZK9*C1=C;T0*b1=Z_D2;
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));while(!((((C)->_cc))!=(((T3)'\073')))){{ZK9*C1=C;T0*b1=Z0E2;
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){ZUk=Z1E2(C,ZUk);
if((R)==((void*)(Zo))){{Z47*n=((Z47*)Zh(sizeof(*n)));*n=Zwj;Z4J1(n,_hc,ZUk);R=((T0*)n);}}else{Z5J1(((Z47*)R),ZUk);}}}if(!(ZqD2(C,a2))){
{T0*b1=ZvF(13,"In compound (");ZXw((T7*)(ZwF),b1);}{T0*b1=a1;ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(27,"). Instruction or keyword \"");ZXw((T7*)(ZwF),b1);
}{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZzD2(C,ZvF(11,ZHq));}if((T6)(((_hc)!=((void*)(Zo)))&&((T6)((R)==((void*)(Zo)))))){{Z47*n=((Z47*)Zh(sizeof(*n)));
*n=Zwj;((((Z47*)(n)))->ZCb)=(_hc);R=((T0*)n);}}return R;}void Z2E2(ZK9*C){T0*Zkc=Zo;T0*ZJe=Zo;T0*Z3E2=Zo;T0*ZUb=Zo;T2 ZIi=0;(C->ZAb)=Zo;
if(ZYD2(C,((T3)'\050'))){while(!((Z3)((ZIi)>(Zrs(4))))){{int z1=ZIi;switch(z1){case 0:if(ZJD2(C)){Zkc=Z5y2(&(((C)->Z2f)));ZIi=Zrs(1);
}else if(ZYD2(C,((T3)'\051'))){ZIi=Zrs(5);}else{ZIi=Zrs(6);}break;case 1:if(ZYD2(C,((T3)'\072'))){if((ZJe)!=((void*)(Zo))){Zwy(((Zn2*)ZJe),Zkc);
Zkc=Zo;}ZIi=Zrs(3);}else{(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));if((ZJe)==((void*)(Zo))){{Zn2*n=((Zn2*)Zh(sizeof(*n)));*n=ZGd;Zyy(n,(T2)(Zrs(2)),(T2)(Zrs(1)));
ZJe=((T0*)n);}}Zwy(((Zn2*)ZJe),Zkc);Zkc=Zo;ZIi=Zrs(2);}break;case 2:if(ZJD2(C)){Zkc=Z5y2(&(((C)->Z2f)));ZIi=Zrs(1);}else if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\073')))))){
{ZK9*C1=C;T0*b1=Z4E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)((T6)((ZYD2(C,((T3)'\054')))||((T6)(ZYD2(C,((T3)'\073')))))));
}else{ZIi=Zrs(6);}break;case 3:if(Z5E2(C)){if((ZJe)!=((void*)(Zo))){{ZS3*n=((ZS3*)Zh(sizeof(*n)));*n=ZKe;Zxa1(n,ZJe,((C)->Zzm));Z3E2=((T0*)n);
}ZJe=Zo;}else{{Z_*n=((Z_*)Zh(sizeof(*n)));*n=Zlc;Z1K(n,Zkc,((C)->Zzm));Z3E2=((T0*)n);}Zkc=Zo;}if((ZUb)==((void*)(Zo))){{Z5a*n=((Z5a*)Zh(sizeof(*n)));
*n=Z_m;ZjB(n,(T2)(Zrs(2)),(T2)(Zrs(1)));ZUb=((T0*)n);}}Z6E2(ZUb,Z3E2);Z3E2=Zo;ZIi=Zrs(4);}else{ZIi=Zrs(6);}break;default:;if(ZYD2(C,((T3)'\051'))){
ZIi=Zrs(5);}else if((((C)->_cc))==(((T3)'\054'))){{ZK9*C1=C;T0*b1=Z7E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));
ZIi=Zrs(0);}else{(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));ZIi=Zrs(0);}}}}if((ZIi)==(Zrs(6))){ZzD2(C,ZvF(26,"Bad formal arguments list."));
}else if((ZUb)==((void*)(Zo))){{ZK9*C1=C;T0*b1=Z8E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}else{{ZH6*n=((ZH6*)Zh(sizeof(*n)));*n=Z8j;
Z081(n,ZUb);(C->ZAb)=((T0*)n);}((((ZA7*)(&(((C)->ZBm)))))->ZAb)=(((C)->ZAb));}}}T6 Z9E2(ZK9*C){T6 R=0;T2 _l=0;T2 _c=0;_l=((C)->ZXe);_c=((C)->ZWe);
if(ZYD2(C,((T3)'\053'))){if(ZaE2(C,Zrs(0))){R=((T6)(1));}else{ZbE2(C,_l,_c);}}else if(ZYD2(C,((T3)'\055'))){if(ZaE2(C,Zrs(-1))){R=((T6)(1));
}else{ZbE2(C,_l,_c);}}else{R=((T6)(ZaE2(C,Zrs(0))));}return R;}T6 ZcE2(ZK9*C){T6 R=0;T2 _l=0;T2 _c=0;_l=((C)->ZXe);_c=((C)->ZWe);if(ZJD2(C)){
if(ZYD2(C,((T3)'\072'))){R=((T6)(1));(C->ZAm)=ZNy2(&(((C)->Z2f)));}else{ZbE2(C,_l,_c);}}return R;}T6 ZZD2(ZK9*C){T6 R=0;R=((T6)(1));if(ZdE2(C)){
}else if(ZeE2(C)){}else if(ZfE2(C)){}else if(ZgE2(C)){}else if(ZhE2(C)){}else if(ZiE2(C)){}else if(ZjE2(C)){}else if(ZkE2(C)){}else if(ZlE2(C)){
}else{R=((T6)(0));}return R;}void ZzD2(ZK9*C,T0*a1){{T76 Z3w;ZzF((*(Z3w=ZmA2(C),&Z3w)));}{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));
}void ZbE2(ZK9*C,T2 a1,T2 a2){T76 _sp={Zo,Zo,0};(C->ZXe)=a1;(C->ZWe)=a2;(C->ZYe)=(((((T52*)((((T72*)(ZoD2()))->Z2l))))->ZPb))[a1];(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[(a2)-(Zrs(1))];
if((((C)->ZZe))!=((void*)(Zo))){_sp=(((T86*)(((C)->ZZe)))->Zxb);if((Z3)((a1)<(ZUa1(&_sp)))){(C->ZZe)=Zo;}else if((a1)==(ZUa1(&_sp))){
if((Z3)((a2)<(ZVa1(&_sp)))){(C->ZZe)=Zo;}}}}void ZmE2(ZK9*C){T0*ZLn1=Zo;T0*ZnE2=Zo;ZLn1=ZMy2(&(((C)->Z2f)));{ZD8*n=((ZD8*)Zh(sizeof(*n)));
*n=Z5l;((((ZD8*)(n)))->Zxb)=(((((ZB8*)ZLn1))->Zxb));ZnE2=((T0*)n);}ZOD2(C,(T6)(0),ZnE2,ZLn1,ZND2(C),(T6)(1));}T0*ZED2(ZK9*C){T0*R=Zo;
if(ZqD2(C,Zhy2)){Zck1((T82*)(((C)->Zem)));R=ZcA2(&(((C)->ZBm)));}else if(ZqD2(C,ZAp2)){R=ZoE2(C);}else if(ZqD2(C,Ziy2)){((((ZA7*)(&(((C)->ZBm)))))->ZGb)=(ZXD2(C));
R=ZrA2(&(((C)->ZBm)));}else if(ZqD2(C,Zwy2)){((((ZA7*)(&(((C)->ZBm)))))->ZGb)=(ZXD2(C));R=ZtA2(&(((C)->ZBm)));}else{ZzD2(C,ZvF(22,"Routine body expected."));
}return R;}T0*ZWD2(ZK9*C,T0*a1){T0*R=Zo;T0*_c=Zo;_c=ZAD2(C);if((T6)(((_c)==((void*)(Zo)))||((T6)((ZPA(((T74*)(((((T86*)_c))->ZUb)))))==(Zrs(0)))))){
R=a1;}else{{ZF4*n=((ZF4*)Zh(sizeof(*n)));*n=Zxg;Zne1(n,a1,_c);R=((T0*)n);}}return R;}T6 ZKD2(ZK9*C){T6 R=0;if(Z9y2()){(C->Zom)=ZSD2(C);
R=((T6)(1));}return R;}T0*ZCD2(ZK9*C){T0*R=Zo;T0*Zcd=Zo;T0*ZTc=Zo;T0*ZOA1=Zo;T2 ZIi=0;((((Za9*)((Za9*)(ZpE2))))->ZRb)=(Zrs(-1));while(!((Z3)((ZIi)>(Zrs(3)))))
{{int z1=ZIi;switch(z1){case 0:if((((C)->_cc))==(((T3)'\073'))){{ZK9*C1=C;T0*b1=Z0E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));
}else if((((C)->ZZe))!=((void*)(Zo))){{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=ZZi;ZfD1(n,Zo,Zo,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);
}else if(ZcE2(C)){Zcd=((C)->ZAm);ZIi=Zrs(1);}else if(ZUD2(C)){ZTc=((C)->Zom);ZIi=Zrs(2);}else{ZIi=Zrs(4);}break;case 1:if(ZYD2(C,((T3)'\073'))){
{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=ZZi;ZfD1(n,Zcd,Zo,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZIi=Zrs(0);}else if(ZcE2(C)){{Zx6*n=((Zx6*)Zh(sizeof(*n)));
*n=ZZi;ZfD1(n,Zcd,Zo,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);Zcd=((C)->ZAm);}else if(ZUD2(C)){ZTc=((C)->Zom);ZIi=Zrs(3);}else{
{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=ZZi;ZfD1(n,Zcd,Zo,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZIi=Zrs(4);}break;case 2:if(ZYD2(C,((T3)'\073'))){
{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=ZZi;ZfD1(n,Zo,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZIi=Zrs(0);}else if(ZcE2(C)){{Zx6*n=((Zx6*)Zh(sizeof(*n)));
*n=ZZi;ZfD1(n,Zo,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);Zcd=((C)->ZAm);ZIi=Zrs(1);}else if(ZUD2(C)){{Zx6*n=((Zx6*)Zh(sizeof(*n)));
*n=ZZi;ZfD1(n,Zo,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZTc=((C)->Zom);ZIi=Zrs(2);}else{{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=ZZi;
ZfD1(n,Zo,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZIi=Zrs(4);}break;default:;if(ZYD2(C,((T3)'\073'))){{Zx6*n=((Zx6*)Zh(sizeof(*n)));
*n=ZZi;ZfD1(n,Zcd,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZIi=Zrs(0);}else if(ZcE2(C)){{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=ZZi;
ZfD1(n,Zcd,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);Zcd=((C)->ZAm);ZIi=Zrs(1);}else if(ZUD2(C)){{Zx6*n=((Zx6*)Zh(sizeof(*n)));
*n=ZZi;ZfD1(n,Zcd,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZTc=((C)->Zom);ZIi=Zrs(2);}else{{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=ZZi;
ZfD1(n,Zcd,ZTc,ZAD2(C));ZOA1=((T0*)n);}ZLA((Za9*)(ZpE2),ZOA1);ZIi=Zrs(4);}}}}if(!((Z3)(((((Za9*)(ZpE2))->ZRb))<(Zrs(0))))){R=ZMA((Za9*)(ZpE2));
}return R;}T0*ZtD2(void){if(ZbP==0){ZbP=1;{{T26*n=((T26*)Zh(1));ZaP=((T0*)n);ZdP(ZeP);ZdP(ZfP);ZdP(ZgP);ZdP(ZhP);ZdP(ZiP);ZdP(ZjP);ZdP(ZkP);
ZdP(ZlP);ZdP(ZmP);ZdP(ZnP);ZdP(ZoP);ZdP(ZpP);ZdP(ZqP);ZdP(ZrP);ZdP(ZpK);ZdP(ZsP);ZdP(ZtP);ZdP(ZuP);ZdP(ZvP);ZdP(ZwP);ZdP(ZxP);ZdP(ZyP);
ZdP(ZzP);ZdP(ZAP);ZdP(ZBP);ZdP(ZCP);ZdP(ZDP);ZdP(ZEP);ZdP(ZFP);ZdP(ZGP);ZdP(ZHP);ZdP(ZIP);ZdP(ZJP);ZdP(ZKP);ZdP(ZLP);ZdP(ZMP);ZdP(ZNP);
ZdP(ZOP);ZdP(ZPP);ZdP(ZQP);ZdP(ZRP);ZdP(ZSP);ZdP(ZTP);ZdP(ZUP);ZdP(ZVP);ZdP(ZWP);ZdP(ZXP);ZdP(ZYP);ZdP(ZZP);ZdP(Z_P);ZdP(Z0Q);ZdP(Z1Q);
ZdP(Z2Q);ZdP(Z3Q);ZdP(Z4Q);ZdP(Z5Q);ZdP(Z6Q);ZdP(Z7Q);ZdP(Z8Q);ZdP(Z9Q);ZdP(ZaQ);ZdP(ZbQ);ZdP(ZcQ);ZdP(ZdJ);ZdP(ZdQ);ZdP(ZeQ);ZdP(ZfQ);
ZdP(ZgQ);ZdP(ZhQ);ZdP(ZiQ);ZdP(ZjQ);ZdP(ZkQ);ZdP(ZlQ);ZdP(ZmQ);ZdP(ZnQ);ZdP(ZoQ);ZdP(ZpQ);ZdP(ZqQ);ZdP(ZDG);ZdP(ZrQ);ZdP(ZsQ);ZdP(ZtQ);
ZdP(ZuQ);ZdP(ZvQ);ZdP(ZwQ);ZdP(ZxQ);ZdP(ZyQ);ZdP(ZzQ);ZdP(ZAQ);ZdP(ZBQ);ZdP(ZCQ);ZdP(ZDQ);ZdP(ZEQ);ZdP(ZFQ);ZdP(ZGQ);ZdP(ZHQ);ZdP(ZIQ);
ZdP(ZJQ);ZdP(ZKQ);ZdP(ZLQ);ZdP(ZMQ);ZdP(ZNQ);ZdP(ZOQ);ZdP(ZPQ);ZdP(ZQQ);ZdP(ZRQ);ZdP(ZSQ);ZdP(ZTQ);ZdP(ZUQ);ZdP(ZVQ);ZdP(ZWQ);ZdP(ZXQ);
ZdP(ZYQ);ZdP(ZZQ);ZdP(Z_Q);ZdP(Z0R);ZdP(Z1R);ZdP(Z2R);ZdP(Z3R);ZdP(Z4R);ZdP(Z5R);ZdP(Z6R);ZdP(Z7R);ZdP(Z8R);ZdP(Z9R);ZdP(ZaR);ZdP(ZbR);
ZdP(ZcR);ZdP(ZdR);ZdP(ZeR);ZdP(ZfR);ZdP(ZgR);ZdP(ZhR);ZdP(ZiR);ZdP(ZjR);ZdP(ZkR);ZdP(ZlR);ZdP(ZmR);ZdP(ZnR);ZdP(ZoR);ZdP(ZpR);ZdP(ZqR);
ZdP(ZrR);ZdP(ZsR);ZdP(ZtR);ZdP(ZuR);ZdP(ZvR);ZdP(ZwR);ZdP(ZxR);ZdP(ZyR);ZdP(ZzR);ZdP(ZAR);ZdP(ZBR);ZdP(ZCR);ZdP(ZDR);ZdP(ZER);ZdP(ZFR);
ZdP(ZGR);ZdP(ZHR);ZdP(ZIR);ZdP(ZJR);ZdP(ZKR);ZdP(ZLR);ZdP(ZMR);ZdP(ZNR);ZdP(ZOR);ZdP(ZPR);ZdP(ZQR);ZdP(ZRR);ZdP(ZSR);ZdP(ZTR);ZdP(ZUR);
ZdP(ZVR);ZdP(ZWR);ZdP(ZXR);ZdP(ZYR);ZdP(ZZR);ZdP(Z_R);ZdP(Z0S);ZdP(Z1S);ZdP(Z2S);ZdP(Z3S);ZdP(Z4S);ZdP(Z5S);ZdP(Z6S);ZdP(Z7S);ZdP(Z8S);
ZdP(Z9S);ZdP(ZaS);ZdP(ZbS);ZdP(ZcS);ZdP(ZdS);ZdP(ZeS);ZdP(ZfS);ZdP(ZgS);ZdP(ZhS);ZdP(ZiS);ZdP(ZjS);ZdP(ZkS);ZdP(ZlS);ZdP(ZmS);ZdP(ZnS);
ZdP(ZoS);}}}return ZaP;}T0*ZqE2=Zo;void ZrE2(ZK9*C){T0*ZsE2=Zo;T0*Zec=Zo;T0*Zjd=Zo;Zec=ZtE2(C);Zjd=ZAD2(C);((((ZF*)((ZF*)(ZuE2))))->ZRb)=(Zrs(-1));
while(!(!(ZvE2(C)))){(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));if((((C)->Zpm))!=((void*)(Zo))){ZCx((ZF*)(ZuE2),((C)->Zpm));ZPJ(((C)->Zpm),ZAD2(C));
}}if(!((Z3)(((((ZF*)(ZuE2))->ZRb))<(Zrs(0))))){{Z05*n=((Z05*)Zh(sizeof(*n)));*n=ZNh;ZSt1(n,Zec,Zjd,ZDx((ZF*)(ZuE2)));ZsE2=((T0*)n);}ZQj1((T82*)(((C)->Zem)),ZsE2);
}else if((Zjd)!=((void*)(Zo))){{Z05*n=((Z05*)Zh(sizeof(*n)));*n=ZNh;ZSt1(n,Zec,Zjd,Zo);ZsE2=((T0*)n);}ZQj1((T82*)(((C)->Zem)),ZsE2);}
}T6 ZwE2(ZK9*C){T6 R=0;T0*ZxE2=Zo;if(ZJD2(C)){R=((T6)(1));if(ZYD2(C,((T3)'\072'))){{ZW5*n=((ZW5*)Zh(sizeof(*n)));*n=ZFj;((((ZW5*)(n)))->Zcd)=(Z6y2(&(((C)->Z2f))));
ZxE2=((T0*)n);}if(ZyE2(C)){Z3L1(((ZW5*)ZxE2),((C)->Zvm));}else{ZzD2(C,ZzE2);}}else{{ZW5*n=((ZW5*)Zh(sizeof(*n)));*n=ZFj;{ZW5*C1=n;T0*b1=ZMy2(&(((C)->Z2f)));
Z3L1(C1,b1);}ZxE2=((T0*)n);}}}else if(ZAE2(C)){R=((T6)(1));{ZW5*n=((ZW5*)Zh(sizeof(*n)));*n=ZFj;{ZW5*C1=n;T0*b1=((C)->Zwm);Z3L1(C1,b1);
}ZxE2=((T0*)n);}}if(R){while(!(!(ZYD2(C,((T3)'\054'))))){if(ZyE2(C)){Z3L1(((ZW5*)ZxE2),((C)->Zvm));}else{ZzD2(C,ZzE2);}}ZIj1((T82*)(((C)->Zem)),ZxE2);
}return R;}void ZBE2(ZK9*C){while(!(!(ZCE2(C)))){(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}}void ZDE2(ZK9*C,T76 a1){T0*Zec=Zo;T0*ZEE2=Zo;
T0*ZFE2=Zo;Zec=ZtE2(C);ZEE2=ZAD2(C);if(ZGE2(C)){}{ZW1*n=((ZW1*)Zh(sizeof(*n)));*n=Zld;ZSW(n,a1,Zec,ZEE2,((C)->Zrm));ZFE2=((T0*)n);}Zbk1((T82*)(((C)->Zem)),ZFE2);
}T6 ZyD2(ZK9*C){T6 R=0;T2 ZIi=0;T2 _l=0;T2 _c=0;T6 ZOm=0;T6 ZPm=0;T6 ZSY1=0;T2 ZQC2=0;T2 ZRC2=0;T2 ZSC2=0;T0*ZVm=Zo;T0*ZTC2=Zo;T0*ZUC2=Zo;
T2 ZVC2=0;T2 ZWC2=0;_l=((C)->ZXe);_c=((C)->ZWe);if(ZqD2(C,Zwy2)){ZOm=((T6)(1));}if((((C)->_cc))==(((T3)'U'))){ZPm=((T6)(1));ZsD2(C);}
if((((C)->_cc))==(((T3)'\042'))){R=((T6)(1));if((T6)(((((T41*)(Z1G))->ZJk))||((T6)((((T41*)(Z1G))->ZKk))))){{T52*n=((T52*)Zh(sizeof(*n)));
*n=M52;ZRz(n,(T2)(Zrs(4)));ZVm=((T0*)n);}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z6x(n,(T2)(Zrs(32)));ZTC2=((T0*)n);}ZPz(((T52*)ZVm),ZTC2);
}((((T7*)((T7*)(ZqE2))))->Zcc)=(Zrs(0));while(!((Z3)((ZIi)>(Zrs(9))))){if((ZVm)!=((void*)(Zo))){ZZs(((T7*)ZTC2),((C)->_cc));if((((C)->_cc))==(((T3)'\n'))){
{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z6x(n,(T2)(Zrs(32)));ZTC2=((T0*)n);}ZPz(((T52*)ZVm),ZTC2);}}ZsD2(C);{int z1=ZIi;switch(z1){case 0:{int
z2=((C)->_cc);switch(z2){case 10:while(!((ZUC2)!=((void*)(Zo)))){if(((((T7*)(ZqE2))->Zcc))==(Zrs(0))){ZzD2(C,ZXC2);}else{{int z3=ZFw((T7*)(ZqE2));
switch(z3){case 9:case 32:Zex((T7*)(ZqE2),(T2)(Zrs(1)));{ZK9*C1=C;T0*b1=ZYC2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}break;case 91:
case 123:ZUC2=ZHE2;((((T7*)(((T7*)ZUC2))))->Zcc)=(Zrs(0));if((ZFw((T7*)(ZqE2)))==(((T3)'\173'))){ZZs(((T7*)ZUC2),((T3)'\175'));ZVC2=Zrs(1);
ZIi=Zrs(8);}else{ZZs(((T7*)ZUC2),((T3)'\135'));ZIi=Zrs(7);}ZXw(((T7*)ZUC2),ZqE2);ZWC2=Zrs(1);Zex(((T7*)ZUC2),(T2)(Zrs(1)));ZZs(((T7*)ZUC2),((T3)'\042'));
((((T7*)((T7*)(ZqE2))))->Zcc)=(Zrs(0));break;default:;ZzD2(C,ZXC2);}}}}break;case 34:ZIi=Zrs(11);break;case 37:ZIi=Zrs(1);break;default:;
ZZs((T7*)(ZqE2),((C)->_cc));}}break;case 1:ZIi=Zrs(0);{int z2=((C)->_cc);switch(z2){case 10:ZIi=Zrs(3);break;case 65:ZZs((T7*)(ZqE2),((T3)'\100'));
break;case 66:ZZs((T7*)(ZqE2),((T3)'\010'));break;case 67:ZZs((T7*)(ZqE2),((T3)'\136'));break;case 68:ZZs((T7*)(ZqE2),((T3)'\044'));break;
case 70:ZZs((T7*)(ZqE2),((T3)'\014'));break;case 72:ZZs((T7*)(ZqE2),((T3)'\134'));break;case 76:ZZs((T7*)(ZqE2),((T3)'\176'));break;case
78:ZZs((T7*)(ZqE2),((T3)'\n'));break;case 81:ZZs((T7*)(ZqE2),((T3)'\140'));break;case 82:ZZs((T7*)(ZqE2),((T3)'\015'));break;case 83:
ZZs((T7*)(ZqE2),((T3)'\043'));break;case 84:ZZs((T7*)(ZqE2),((T3)'\011'));break;case 85:ZZs((T7*)(ZqE2),((T3)'\000'));break;case 86:ZZs((T7*)(ZqE2),((T3)'\174'));
break;case 37:ZZs((T7*)(ZqE2),((T3)'\045'));break;case 39:ZZs((T7*)(ZqE2),((T3)'\047'));break;case 34:ZZs((T7*)(ZqE2),((T3)'\042'));break;
case 40:ZZs((T7*)(ZqE2),((T3)'\133'));break;case 41:ZZs((T7*)(ZqE2),((T3)'\135'));break;case 60:ZZs((T7*)(ZqE2),((T3)'\173'));break;case
62:ZZs((T7*)(ZqE2),((T3)'\175'));break;case 47:ZQC2=Zrs(0);ZSC2=Zrs(0);ZIi=Zrs(4);break;case 9:case 32:ZIi=Zrs(2);break;default:;ZzD2(C,Z_C2);
ZIi=Zrs(0);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 10:ZIi=Zrs(3);break;case 9:case 32:{ZK9*C1=C;T0*b1=ZYC2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}break;default:;ZzD2(C,ZvF(60,Z_o));}}break;case 3:{int z2=((C)->_cc);switch(z2){case 9:case 32:break;case 37:ZIi=Zrs(0);break;case 10:
ZzD2(C,ZXC2);break;default:;ZzD2(C,ZvF(62,Z_p));}}break;case 4:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:
case 53:case 54:case 55:case 56:case 57:ZSC2=(Z3)(((ZSC2))+(Zrs(1)));ZQC2=(Z3)((((Z3)(((ZQC2))*(Zrs(10)))))+((T2)(Zus(((C)->_cc)))));
break;case 120:if(Zfs((T6)((ZSC2)==(Zrs(1))),(T6)((ZQC2)==(Zrs(0))))){ZSC2=Zrs(0);ZIi=Zrs(5);}else{ZzD2(C,Z0D2);}break;case 85:if((ZSC2)==(Zrs(0))){
ZsD2(C);if((((C)->_cc))==(((T3)'x'))){ZIi=Zrs(6);ZRC2=Zrs(0);ZSC2=Zrs(0);}else{ZzD2(C,Z0D2);}}else{ZzD2(C,Z0D2);}break;case 47:ZZs((T7*)(ZqE2),((T3)(ZQC2)));
ZIi=Zrs(0);if((ZSC2)==(Zrs(0))){{ZK9*C1=C;T0*b1=Z1D2;{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}else if((Z3)((ZQC2)>((T2)(Z2D2)))){ZQC2=Zrs(0);
{ZK9*C1=C;T0*b1=Z3D2;{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}break;default:;ZzD2(C,Z0D2);}}break;case 5:if(Zms(((C)->_cc))){ZQC2=(Z3)((((Z3)(((ZQC2))*(Zrs(16)))))+((T2)(ZBs(((C)->_cc)))));
ZSC2=(Z3)(((ZSC2))+(Zrs(1)));if(Z0t(ZSC2)){ZZs((T7*)(ZqE2),((T3)(ZQC2)));ZQC2=Zrs(0);}}else if((((C)->_cc))==(((T3)'\057'))){ZIi=Zrs(0);
if((ZSC2)==(Zrs(0))){{ZK9*C1=C;T0*b1=Z4D2;{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}else if(ZTs(ZSC2)){{ZK9*C1=C;T0*b1=ZvF(85,ZNo);
{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}else{ZzD2(C,Z4D2);}break;case 6:if(Zms(((C)->_cc))){ZRC2=(Z3)((((Z3)(((ZRC2))*(Zrs(16)))))+((T2)(ZBs(((C)->_cc)))));
ZSC2=(Z3)(((ZSC2))+(Zrs(1)));}else if((((C)->_cc))==(((T3)'\057'))){ZIi=Zrs(0);if((ZSC2)==(Zrs(0))){{ZK9*C1=C;T0*b1=Z5D2;{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}else if((Z3)((ZSC2)>(Zrs(8)))){{ZK9*C1=C;T0*b1=ZvF(57,Zao);{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}else{Zb62((T90*)(ZIE2()));if((((void)((T90*)(ZIE2()))),Z762(ZRC2))){
Za62((T90*)(ZIE2()),ZRC2);Z962((T90*)(ZIE2()),ZqE2);}else{{ZK9*C1=C;T0*b1=ZvF(109,ZPo);{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}}
else{ZzD2(C,Z5D2);}break;case 7:{int z2=((C)->_cc);switch(z2){case 9:case 32:ZWC2=(Z3)(((ZWC2))+(Zrs(1)));break;case 10:ZZs((T7*)(ZqE2),((T3)'\n'));
ZWC2=Zrs(1);break;case 0:{T76 Z3w;ZzF((*(Z3w=ZBD2(C,_l,_c),&Z3w)));}ZzD2(C,Z6D2);break;default:;ZZs((T7*)(ZqE2),((C)->_cc));if((ZVC2)==(Zrs(0))){
ZVC2=ZWC2;}ZIi=Zrs(8);}}break;case 8:ZWC2=(Z3)(((ZWC2))+(Zrs(1)));{int z2=((C)->_cc);switch(z2){case 9:case 32:if((Z3)((ZWC2)>=(ZVC2))){
ZZs((T7*)(ZqE2),((C)->_cc));}break;case 10:ZZs((T7*)(ZqE2),((C)->_cc));ZWC2=Zrs(0);break;case 0:{T76 Z3w;ZzF((*(Z3w=ZBD2(C,_l,_c),&Z3w)));
}ZzD2(C,Z6D2);break;case 34:ZZs((T7*)(ZqE2),((C)->_cc));if(Z3x((T7*)(ZqE2),ZUC2)){ZIi=Zrs(10);}break;default:;if((Z3)((ZWC2)<(ZVC2))){
if((((C)->_cc))==((((((T7*)ZUC2))->ZPb))[Zrs(0)])){ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(9);}else{{T76 Z3w;ZzF((*(Z3w=ZBD2(C,_l,_c),&Z3w)));
}ZzD2(C,Z6D2);}}else{ZZs((T7*)(ZqE2),((C)->_cc));}}}break;default:;{int z2=((C)->_cc);switch(z2){case 0:{T76 Z3w;ZzF((*(Z3w=ZBD2(C,_l,_c),&Z3w)));
}ZzD2(C,Z6D2);break;case 34:ZZs((T7*)(ZqE2),((C)->_cc));if(Z3x((T7*)(ZqE2),ZUC2)){ZIi=Zrs(10);}break;default:;ZZs((T7*)(ZqE2),((C)->_cc));
}}}}}if((ZIi)==(Zrs(10))){{T7*C1=(T7*)(ZqE2);T0*b1=ZUC2;Zex(C1,((((T7*)b1))->Zcc));}while(!(ZSY1)){if(((((T7*)(ZqE2))->Zcc))==(Zrs(0))){
ZSY1=((T6)(1));}else{ZSY1=((T6)((ZFw((T7*)(ZqE2)))==(((T3)'\n'))));Zex((T7*)(ZqE2),(T2)(Zrs(1)));}}}if((ZVm)!=((void*)(Zo))){ZZs(((T7*)ZTC2),((T3)'\042'));
}{T76 Z3w;{T88*n=((T88*)Zh(sizeof(*n)));*n=M88;Zxj2(n,(*(Z3w=ZBD2(C,_l,_c),&Z3w)),(T6)(ZOm),(T6)(ZPm),ZqE2);(C->Zrl)=((T0*)n);}}((((T88*)((T88*)(((C)->Zrl)))))->ZVm)=(ZVm);
ZsD2(C);ZpD2(C);}else if((T6)((ZOm)||((T6)(ZPm)))){ZbE2(C,_l,_c);}return R;}T6 ZgE2(ZK9*C){T6 R=0;if(ZqD2(C,ZAy2)){if(!(((C)->Zhm))){
{T76 Z3w;ZlA2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZvF(45,"\"retry\" cannot be outside of a rescue clause."));}}{T76 Z3w;{ZS1*n=((ZS1*)Zh(sizeof(*n)));
*n=Zgd;((((ZS1*)(n)))->Zxb)=((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zum)=((T0*)n);}}R=((T6)(1));}return R;}T6 ZJE2(ZK9*C,T76
a1){T6 R=0;R=((T6)(1));if(ZKE2(C,((T3)'\074'),((T3)'\075'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZbQ,a1);(C->Zqm)=((T0*)n);}}else
if(ZKE2(C,((T3)'\076'),((T3)'\075'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,Z8Q,a1);(C->Zqm)=((T0*)n);}}else if(ZKE2(C,((T3)'\057'),((T3)'\057'))){
{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZqQ,a1);(C->Zqm)=((T0*)n);}}else if(ZKE2(C,((T3)'\134'),((T3)'\134'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));
*n=Z6n;ZCG(n,ZWP,a1);(C->Zqm)=((T0*)n);}}else if(ZYD2(C,((T3)'\053'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZkQ,a1);(C->Zqm)=((T0*)n);
}}else if(ZYD2(C,((T3)'\055'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZdJ,a1);(C->Zqm)=((T0*)n);}}else if(ZYD2(C,((T3)'\052'))){
{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZeQ,a1);(C->Zqm)=((T0*)n);}}else if(ZYD2(C,((T3)'\057'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;
ZCG(n,ZpQ,a1);(C->Zqm)=((T0*)n);}}else if(ZYD2(C,((T3)'\076'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,Z9Q,a1);(C->Zqm)=((T0*)n);
}}else if(ZYD2(C,((T3)'\074'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZcQ,a1);(C->Zqm)=((T0*)n);}}else if(ZYD2(C,((T3)'\136'))){
{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZmQ,a1);(C->Zqm)=((T0*)n);}}else if(ZqD2(C,ZDG)){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZDG,a1);
(C->Zqm)=((T0*)n);}}else if(ZqD2(C,ZaQ)){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZaQ,a1);(C->Zqm)=((T0*)n);}}else if(ZqD2(C,ZTP)){
if(ZqD2(C,ZDy2)){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZUP,a1);(C->Zqm)=((T0*)n);}}else{{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZTP,a1);
(C->Zqm)=((T0*)n);}}}else if(ZqD2(C,ZiQ)){if(ZqD2(C,Zo71)){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZjQ,a1);(C->Zqm)=((T0*)n);}}else{
{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZiQ,a1);(C->Zqm)=((T0*)n);}}}else if(ZKE2(C,((T3)'\043'),((T3)'\053'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));
*n=Z6n;ZCG(n,ZlQ,a1);(C->Zqm)=((T0*)n);}}else if(ZKE2(C,((T3)'\043'),((T3)'\055'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZdQ,a1);
(C->Zqm)=((T0*)n);}}else if(ZKE2(C,((T3)'\043'),((T3)'\052'))){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZfQ,a1);(C->Zqm)=((T0*)n);}
}else{(C->Zqm)=Zo;R=((T6)(0));}return R;}void ZLE2(ZK9*C){T0*Zxi=Zo;T76 _sp={Zo,Zo,0};T0*Zec=Zo;T0*Zlh=Zo;T0*ZME2=Zo;T2 ZIi=0;if(ZqD2(C,Zky2)){
{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}while(!((Z3)((ZIi)>(Zrs(3))))){{int z1=ZIi;switch(z1){case 0:if((((C)->_cc))==(((T3)'\173'))){
Zec=ZtE2(C);ZIi=Zrs(1);}else if((((C)->_cc))==(((T3)'\073'))){{ZK9*C1=C;T0*b1=Z0E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));
}else{if((Zlh)!=((void*)(Zo))){{Zw5*n=((Zw5*)Zh(sizeof(*n)));*n=Zmh;ZTl1(n,_sp,Zlh);Zxi=((T0*)n);}((((Zv2*)((Zv2*)(((C)->Zxm)))))->Zxi)=(Zxi);
}ZIi=Zrs(4);}break;case 1:if(ZqD2(C,Z7g1)){{Zh2*n=((Zh2*)Zh(sizeof(*n)));*n=ZYh;ZhA1(n,Zec);ZME2=((T0*)n);}if((Zlh)==((void*)(Zo))){{Zi5*n=((Zi5*)Zh(sizeof(*n)));
*n=Zch;Ziz(n,(T2)(Zrs(2)),(T2)(Zrs(1)));Zlh=((T0*)n);}}Zhz(((Zi5*)Zlh),ZME2);ZIi=Zrs(2);}else{if(ZGE2(C)){{Zh2*n=((Zh2*)Zh(sizeof(*n)));
*n=ZYh;ZiA1(n,Zec,((C)->Zrm));ZME2=((T0*)n);}if((Zlh)==((void*)(Zo))){{Zi5*n=((Zi5*)Zh(sizeof(*n)));*n=Zch;Ziz(n,(T2)(Zrs(2)),(T2)(Zrs(1)));
Zlh=((T0*)n);}}Zhz(((Zi5*)Zlh),ZME2);ZIi=Zrs(2);}else{ZIi=Zrs(3);}}break;case 2:if(ZYD2(C,((T3)'\073'))){ZIi=Zrs(0);}else if((((C)->_cc))==(((T3)'\173'))){
{ZK9*C1=C;T0*b1=Z_D2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}ZIi=Zrs(0);}else{if((Zlh)!=((void*)(Zo))){{Zw5*n=((Zw5*)Zh(sizeof(*n)));
*n=Zmh;ZTl1(n,_sp,Zlh);Zxi=((T0*)n);}((((Zv2*)((Zv2*)(((C)->Zxm)))))->Zxi)=(Zxi);}ZIi=Zrs(4);}break;default:;ZzD2(C,ZNE2);ZIi=Zrs(4);
}}}}}T6 ZJD2(ZK9*C){T6 R=0;if(((C)->Zam)){R=((T6)(ZOE2(C)));}else{R=((T6)(ZPE2(C)));}return R;}T6 ZQE2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};
T3 Zde=0;T2 ZIi=0;T2 ZRE2=0;T2 ZQC2=0;T2 ZSC2=0;if((((C)->_cc))==(((T3)'\047'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->ZXe),((C)->ZWe)),&Z3w));
}R=((T6)(1));while(!((Z3)((ZIi)>(Zrs(4))))){ZsD2(C);{int z1=ZIi;switch(z1){case 0:{int z2=((C)->_cc);switch(z2){case 37:ZIi=Zrs(1);break;
case 39:ZzD2(C,ZSE2);ZIi=Zrs(2);break;default:;Zde=((C)->_cc);ZRE2=Zrs(0);ZIi=Zrs(2);}}break;case 1:ZRE2=Zrs(1);ZIi=Zrs(2);{int z2=((C)->_cc);
switch(z2){case 65:Zde=((T3)'\100');break;case 66:Zde=((T3)'\010');break;case 67:Zde=((T3)'\136');break;case 68:Zde=((T3)'\044');break;
case 70:Zde=((T3)'\014');break;case 72:Zde=((T3)'\134');break;case 76:Zde=((T3)'\176');break;case 78:Zde=((T3)'\n');break;case 81:Zde=((T3)'\140');
break;case 82:Zde=((T3)'\015');break;case 83:Zde=((T3)'\043');break;case 84:Zde=((T3)'\011');break;case 85:Zde=((T3)'\000');break;case
86:Zde=((T3)'\174');break;case 37:Zde=((T3)'\045');break;case 39:Zde=((T3)'\047');break;case 34:Zde=((T3)'\042');break;case 40:Zde=((T3)'\133');
break;case 41:Zde=((T3)'\135');break;case 60:Zde=((T3)'\173');break;case 62:Zde=((T3)'\175');break;case 47:ZIi=Zrs(3);ZRE2=Zrs(2);break;
default:;ZzD2(C,Z_C2);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 39:ZIi=Zrs(5);break;default:;ZzD2(C,ZSE2);}}ZsD2(C);ZpD2(C);break;
case 3:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZSC2=(Z3)(((ZSC2))+(Zrs(1)));
ZQC2=(Z3)((((Z3)(((ZQC2))*(Zrs(10)))))+((T2)(Zus(((C)->_cc)))));break;case 47:ZIi=Zrs(2);if((ZSC2)==(Zrs(0))){{ZK9*C1=C;T0*b1=Z1D2;{T76
Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}else if((Z3)((ZQC2)>((T2)(Z2D2)))){ZQC2=Zrs(0);{ZK9*C1=C;T0*b1=Z3D2;{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}Zde=((T3)(ZQC2));break;case 120:if((T6)(((ZSC2)==(Zrs(1)))&&((T6)((ZQC2)==(Zrs(0)))))){ZSC2=Zrs(0);ZIi=Zrs(4);}else{ZzD2(C,Z0D2);}
break;default:;ZzD2(C,Z0D2);}}break;default:;if(Zms(((C)->_cc))){ZQC2=(Z3)((((Z3)(((ZQC2))*(Zrs(16)))))+((T2)(ZBs(((C)->_cc)))));ZSC2=(Z3)(((ZSC2))+(Zrs(1)));
}else if((((C)->_cc))==(((T3)'\057'))){ZIi=Zrs(2);if((ZSC2)!=(Zrs(2))){{ZK9*C1=C;T0*b1=ZvF(65,"You must use exactely 2 hexadecimal digits to denote a CHARACTER.");
{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}Zde=((T3)(ZQC2));}else{ZzD2(C,Z0D2);}}}}{ZN4*n=((ZN4*)Zh(sizeof(*n)));*n=ZOg;Zjg1(n,_sp,Zde,ZRE2);
(C->Zlm)=((T0*)n);}}return R;}T0*ZTE2(ZK9*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;if((a2)==((void*)(Zo))){ZzD2(C,ZvF(61,"An expression has a result value. This is not an instruction."));
}else if((a3)==((void*)(Zo))){{ZZ6*n=((ZZ6*)Zh(sizeof(*n)));*n=Zkj;Zlp1(n,a1,a2);R=((T0*)n);}}else if((ZjD1(((Zm3*)a3)))==(Zrs(1))){{ZX6*n=((ZX6*)Zh(sizeof(*n)));
*n=Zjj;ZkH1(n,a1,a2,a3);R=((T0*)n);}}else{{ZV6*n=((ZV6*)Zh(sizeof(*n)));*n=Zij;ZYG1(n,a1,a2,a3);R=((T0*)n);}}return R;}void ZUE2(ZK9*C,T0*a1){
{T76 Z3w;{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Z5d;ZNU(n,(*(Z3w=Z3L(a1),&Z3w)),a1);(C->Zim)=((T0*)n);}}}void ZVE2(ZK9*C){if((((T88*)(((C)->Zrl)))->ZOm)){
ZzF((((T88*)(((C)->Zrl)))->Zxb));{T0*b1=ZWE2;ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));}}T6 ZqD2(ZK9*C,T0*a1){T6 R=0;T2 _c=0;T2 _i=0;T2 _j=0;
_i=((C)->ZWe);_c=((((T7*)a1))->Zcc);if((Z3)(((Z3)((((Z3)((((((T7*)(((C)->ZYe)))->Zcc)))-(_i))))+(Zrs(1))))>=(_c))){(C->Z0f)=((C)->ZXe);
(C->Z1f)=_i;_j=Zrs(1);while(!((Z3)((_c)<=(Zrs(0))))){if(Zts(((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))],(((((T7*)a1))->ZPb))[(_j)-(Zrs(1))])){
_i=(Z3)(((_i))+(Zrs(1)));_j=(Z3)(((_j))+(Zrs(1)));_c=(Z3)(((_c))-(Zrs(1)));}else{_c=Zrs(-1);}}}if((_c)==(Zrs(0))){if((Z3)((_i)>((((T7*)(((C)->ZYe)))->Zcc)))){
R=((T6)(1));(C->_cc)=((T3)'\n');(C->ZWe)=_i;ZpD2(C);}else{{int z1=((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))];switch(z1){case 9:case 32:
case 45:R=((T6)(1));(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))];(C->ZWe)=_i;ZpD2(C);break;case 48:case 49:case 50:case 51:case
52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case
76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 95:case 97:case
98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:
case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:break;default:;R=((T6)(1));(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[(_i)-(Zrs(1))];
(C->ZWe)=_i;}}}}return R;}T6 ZGE2(ZK9*C){T6 R=0;T2 ZIi=0;(C->Zrm)=Zo;while(!((Z3)((ZIi)>=(Zrs(3))))){{int z1=ZIi;switch(z1){case 0:if(ZXE2(C)){
{Zx8*n=((Zx8*)Zh(sizeof(*n)));*n=Z1l;((((Zx8*)(n)))->ZBd)=(((C)->Zqm));(C->Zrm)=((T0*)n);}R=((T6)(1));ZIi=Zrs(1);}else if((((C)->_cc))==(((T3)'\054'))){
{ZK9*C1=C;T0*b1=ZYE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}else{ZIi=Zrs(3);}break;case 1:
if((((C)->_cc))==(((T3)'\054'))){(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));ZIi=Zrs(2);}else if(ZXE2(C)){ZHD2((((ZB8*)(((C)->Zqm)))->Zxb),ZZE2);
Z732((Zx8*)(((C)->Zrm)),((C)->Zqm));}else{ZIi=Zrs(3);}break;default:;if(ZXE2(C)){Z732((Zx8*)(((C)->Zrm)),((C)->Zqm));ZIi=Zrs(1);}else
if((((C)->_cc))==(((T3)'\054'))){{ZK9*C1=C;T0*b1=Z_E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));
}else{{ZK9*C1=C;T0*b1=Z0F2;{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}ZIi=Zrs(3);}}}}return R;}void ZpD2(ZK9*C){T76 _sp={Zo,Zo,0};T6 ZSY1=0;
while(!(ZSY1)){{int z1=((C)->_cc);switch(z1){case 9:case 10:case 32:ZsD2(C);break;case 45:ZsD2(C);if((((C)->_cc))==(((T3)'\055'))){if(((C)->Z_e)){
if((((C)->ZXe))==((((T72*)(ZoD2()))->Zcc))){(C->_cc)=((T3)'\000');ZSY1=((T6)(1));}else{(C->ZXe)=(Z3)(((((C)->ZXe)))+(Zrs(1)));(C->ZWe)=Zrs(1);
(C->ZYe)=(((((T52*)((((T72*)(ZoD2()))->Z2l))))->ZPb))[((C)->ZXe)];if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){(C->_cc)=((T3)'\n');}else{
(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}}}else{{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->ZXe),(Z3)(((((C)->ZWe)))-((T2)(Zrs(1))))),&Z3w));
}ZsD2(C);((((T7*)((T7*)(Zkp2))))->Zcc)=(Zrs(0));while(!((((C)->_cc))==(((T3)'\n')))){ZZs((T7*)(Zkp2),((C)->_cc));ZsD2(C);}if((((C)->ZZe))==((void*)(Zo))){
{T86*n=((T86*)Zh(sizeof(*n)));*n=M86;ZNa1(n,_sp,ZRs((T7*)(Zkp2)));(C->ZZe)=((T0*)n);}}else{ZWA(((T74*)((((T86*)(((C)->ZZe)))->ZUb))),ZRs((T7*)(Zkp2)));
}}}else{(C->_cc)=((T3)'\055');(C->ZWe)=(Z3)(((((C)->ZWe)))-(Zrs(1)));ZSY1=((T6)(1));}break;default:;ZSY1=((T6)(1));}}}}T6 Z1F2(ZK9*C){
T6 R=0;T6 Z2F2=0;if(ZqD2(C,Zht1)){{T76 Z3w;ZzF((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));}{T0*b1=ZvF(71,"This form of inheritance (expanded inheritance) is not yet implemented.");
ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}else if(ZqD2(C,ZlU)){{T76 Z3w;ZzF((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));}{T0*b1=ZvF(31,"Unexpected \"reference\" keyword.");
ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}if(Z3F2(C)){R=((T6)(1));{Zv2*n=((Zv2*)Zh(sizeof(*n)));*n=ZDi;((((Zv2*)(n)))->ZBb)=(((C)->Znm));
(C->Zxm)=((T0*)n);}if(ZqD2(C,Zyy2)){ZBE2(C);if((((C)->_cc))==(((T3)'\073'))){{ZK9*C1=C;T0*b1=ZvF(34,"Unexpected \";\" to end rename list.");
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));}Z2F2=((T6)(1));}ZLE2(C);if(ZqD2(C,ZFy2)){if(ZGE2(C)){
((((Zv2*)((Zv2*)(((C)->Zxm)))))->Zyi)=(((C)->Zrm));}Z2F2=((T6)(1));}if(ZqD2(C,Zxy2)){if(ZGE2(C)){((((Zv2*)((Zv2*)(((C)->Zxm)))))->Zzi)=(((C)->Zrm));
}Z2F2=((T6)(1));}if(ZqD2(C,ZBy2)){if(ZGE2(C)){((((Zv2*)((Zv2*)(((C)->Zxm)))))->ZAi)=(((C)->Zrm));}Z2F2=((T6)(1));}if((T6)(((T6)(((T6)(((T6)((ZqD2(C,Zyy2))||((T6)(ZqD2(C,Zky2)))))||((T6)(ZqD2(C,ZFy2)))))||((T6)(ZqD2(C,Zxy2)))))||((T6)(ZqD2(C,ZBy2))))){
{T76 Z3w;ZzF((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));}{T0*b1=ZvF(121,"Inheritance option not at a correct place. The correct order is: \"rename... export... undefine... redefine... select...\".");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}(C->_ok)=((T6)(ZqD2(C,ZEp2)));if((T6)((!(((C)->_ok)))&&((T6)(Z2F2)))){{ZK9*C1=C;T0*b1=ZvF(20,ZJq);
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}return R;}T6 ZyE2(ZK9*C){T6 R=0;if(ZJD2(C)){(C->Zvm)=ZMy2(&(((C)->Z2f)));R=((T6)(1));}else
if(ZAE2(C)){(C->Zvm)=((C)->Zwm);R=((T6)(1));}return R;}T6 Z4F2(ZK9*C,T6 a1){T6 R=0;T6 ZSY1=0;T2 _l=0;T2 _c=0;{int z1=((C)->_cc);switch(z1){
case 35:case 38:case 42:case 43:case 45:case 47:case 60:case 61:case 62:case 64:case 92:case 124:case 126:_l=((C)->ZXe);_c=((C)->ZWe);
((((T7*)((T7*)(ZqE2))))->Zcc)=(Zrs(0));R=((T6)(1));ZZs((T7*)(ZqE2),((C)->_cc));ZsD2(C);while(!(ZSY1)){{int z2=((C)->_cc);switch(z2){case
46:case 63:case 123:case 125:R=((T6)(0));ZZs((T7*)(ZqE2),((C)->_cc));ZsD2(C);break;case 35:case 38:case 42:case 43:case 45:case 47:case
60:case 61:case 62:case 64:case 92:case 94:case 124:case 126:R=((T6)(1));ZZs((T7*)(ZqE2),((C)->_cc));ZsD2(C);break;default:;ZSY1=((T6)(1));
}}}if(R){{int z2=(((T7*)(ZqE2))->Zcc);switch(z2){case 1:{int z3=((((T7*)(ZqE2))->ZPb))[Zrs(0)];switch(z3){case 42:case 43:case 45:case
47:case 60:case 61:case 62:R=((T6)(0));break;}}break;case 2:{int z3=((((T7*)(ZqE2))->ZPb))[Zrs(0)];switch(z3){case 62:{int z4=ZFw((T7*)(ZqE2));
switch(z4){case 61:case 62:R=((T6)(0));break;}}break;case 47:case 60:case 92:{int z4=ZFw((T7*)(ZqE2));switch(z4){case 47:case 61:case
92:R=((T6)(0));break;}}break;}}break;default:;R=((T6)((ZCw((T7*)(ZqE2),((T3)'\076')))!=((((T7*)(ZqE2))->Zcc))));}}}if(R){ZpD2(C);Z5F2(C,(T6)(a1),_l,_c);
}else{ZbE2(C,_l,_c);}break;}}return R;}T0*Z1E2(ZK9*C,T0*a1){T0*R=Zo;T0*_c=Zo;_c=ZAD2(C);if((T6)(((_c)==((void*)(Zo)))||((T6)((ZPA(((T74*)(((((T86*)_c))->ZUb)))))==(Zrs(0)))))){
R=a1;}else{R=Z6F2(a1,_c);}return R;}T0*ZoD2(void){if(ZGf1==0){ZGf1=1;{{T72*n=((T72*)Zh(sizeof(*n)));*n=M72;ZFf1=((T0*)n);ZIf1(n);}}}return
ZFf1;}T0*ZSD2(ZK9*C){T0*R=Zo;T76 _sp={Zo,Zo,0};_sp=((((C)->Z2f)).Zxb);if(((C)->Zfm)){{Zu7*n=((Zu7*)Zh(sizeof(*n)));*n=ZYj;((((Zu7*)(n)))->Zxb)=(_sp);
R=((T0*)n);}}else{ZzF(_sp);{T0*b1=ZvF(45,"`Result\' must only be used inside a function.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}return
R;}T6 ZlE2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};T0*ZBb=Zo;T0*Zxd=Zo;T0*Z7F2=Zo;T0*Zyd=Zo;if(ZYD2(C,((T3)'\041'))){R=((T6)(1));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(Z5E2(C)){ZBb=((C)->Zzm);Z8F2(ZBb);if(!(ZYD2(C,((T3)'\041')))){ZzD2(C,ZvF(40,"Bad creation instruction (\'!\' expected)."));}}else
if(ZYD2(C,((T3)'\041'))){}else{ZzD2(C,ZvF(48,"Bad creation instruction (type or \'!\' expected)."));}Zxd=Z9F2(C);if(ZYD2(C,((T3)'\056'))){
if(ZJD2(C)){Z7F2=ZMy2(&(((C)->Z2f)));if((((C)->_cc))==(((T3)'\050'))){Zyd=ZTE2(C,Zxd,Z7F2,ZND2(C));}else{{ZZ6*n=((ZZ6*)Zh(sizeof(*n)));
*n=Zkj;Zlp1(n,Zxd,Z7F2);Zyd=((T0*)n);}}}else{ZzD2(C,ZaF2);}}{Z23*n=((Z23*)Zh(sizeof(*n)));*n=Z1e;Zu41(n,_sp,ZBb,Zxd,Zyd);(C->Zum)=((T0*)n);
}}return R;}T6 Z3F2(ZK9*C){T6 R=0;T2 ZIi=0;T0*Zfe=Zo;T0*ZCj=Zo;if(ZbF2(C)){(C->Znm)=((C)->Zim);R=((T6)(1));}else if(ZcF2(C)){R=((T6)(1));
Zfe=((C)->Zmm);while(!((Z3)((ZIi)>(Zrs(2))))){{int z1=ZIi;switch(z1){case 0:if(ZYD2(C,((T3)'\133'))){ZIi=Zrs(1);}else{{ZT6*n=((ZT6*)Zh(sizeof(*n)));
*n=Zhj;((((ZT6*)(n)))->Zfe)=(Zfe);(C->Znm)=((T0*)n);}ZIi=Zrs(3);}break;case 1:if(Z5E2(C)){if((ZCj)==((void*)(Zo))){{ZY*n=((ZY*)Zh(sizeof(*n)));
*n=Zjc;ZSx(n,(T2)(Zrs(2)),(T2)(Zrs(1)));ZCj=((T0*)n);}}ZQx(((ZY*)ZCj),((C)->Zzm));ZIi=Zrs(2);}else if((((C)->_cc))==(((T3)'\054'))){{ZK9*C1=C;
T0*b1=Z_E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}else if((((C)->_cc))==(((T3)'\135'))){ZIi=Zrs(2);
}else{ZzD2(C,ZdF2);ZIi=Zrs(2);}break;default:;if(ZYD2(C,((T3)'\054'))){ZIi=Zrs(1);}else if((((C)->_cc))==(((T3)'\135'))){if((ZCj)==((void*)(Zo))){
{ZK9*C1=C;T0*b1=ZeF2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}{ZT6*n=((ZT6*)Zh(sizeof(*n)));*n=Zhj;((((ZT6*)(n)))->Zfe)=(Zfe);(C->Znm)=((T0*)n);
}}else{{Zk9*n=((Zk9*)Zh(sizeof(*n)));*n=ZUl;Zra2(n,Zfe,ZCj);(C->Znm)=((T0*)n);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\135'))));ZIi=Zrs(3);}else
if(Z5E2(C)){if((ZCj)==((void*)(Zo))){{ZY*n=((ZY*)Zh(sizeof(*n)));*n=Zjc;ZSx(n,(T2)(Zrs(2)),(T2)(Zrs(1)));ZCj=((T0*)n);}}ZQx(((ZY*)ZCj),((C)->Zzm));
{T76 Z3w;ZHD2((*(Z3w=Z3L(((C)->Zzm)),&Z3w)),ZZE2);}}else{ZzD2(C,ZvF(17,"Bad generic list."));ZIi=Zrs(3);}}}}}return R;}T6 ZfF2(ZK9*C){
T6 R=0;T76 _sp={Zo,Zo,0};if(ZqD2(C,ZCy2)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZYD2(C,((T3)'\050'))){(C->_ok)=((T6)(ZGE2(C)));
{Zo4*n=((Zo4*)Zh(sizeof(*n)));*n=Z0g;ZMb1(n,_sp,((C)->Zrm));(C->Zom)=((T0*)n);}if(!(ZYD2(C,((T3)'\051')))){ZzD2(C,ZvF(39,"\')\' expected to end a strip expression."));
}R=((T6)(1));}else{ZzD2(C,ZvF(35,"\'(\' expected to begin a strip list."));}}return R;}T6 ZgF2(ZK9*C,T6 a1){T6 R=0;T2 _l=0;T2 _c=0;T0*Zud=Zo;
T0*ZaM=Zo;T76 _p={Zo,Zo,0};T6 ZhF2=0;if(ZYD2(C,((T3)'\173'))){R=((T6)(1));_l=((C)->Z0f);_c=((C)->Z1f);if(ZYD2(C,((T3)'\173'))){{T76 Z3w;
ZHD2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZvF(43,Ztp));}}if(ZcF2(C)){Zud=((C)->Zmm);}if(!(ZYD2(C,((T3)'\175')))){ZzD2(C,ZvF(61,Zwo));
}if(ZYD2(C,((T3)'\175'))){{T76 Z3w;ZHD2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZvF(43,Zvn));}}ZhF2=((T6)(1));}if(ZqD2(C,ZlS)){R=((T6)(1));
if((_l)==(Zrs(0))){_l=((C)->Z0f);_c=((C)->Z1f);}}else if((Z3)((_l)>(Zrs(0)))){ZzD2(C,ZvF(32,"Precursor keyword expected here."));}if(R){
{T76 Z3w;_p=(*(Z3w=ZBD2(C,_l,_c),&Z3w));}if(ZhF2){{T76 Z3w;ZHD2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZvF(80,"Obsolete syntax: the parent should now be written after the `precursor\' keyword."));
}}else{if(ZYD2(C,((T3)'\173'))){if(ZYD2(C,((T3)'\173'))){{T76 Z3w;ZHD2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZvF(43,Ztp));}}if(ZcF2(C)){
Zud=((C)->Zmm);}if(!(ZYD2(C,((T3)'\175')))){ZzD2(C,ZvF(61,Zwo));}if(ZYD2(C,((T3)'\175'))){{T76 Z3w;ZHD2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZvF(43,Zvn));
}}}}ZaM=ZND2(C);if(ZYD2(C,((T3)'\056'))){{Zb2*n=((Zb2*)Zh(sizeof(*n)));*n=Zvd;ZAX(n,_p,Zud,ZaM);(C->Zom)=((T0*)n);}ZID2(C,(T6)(a1),((C)->Zom));
}else if(a1){{Zd8*n=((Zd8*)Zh(sizeof(*n)));*n=ZBk;Z402(n,_p,Zud,ZaM);(C->Zum)=((T0*)n);}}else{{Zb2*n=((Zb2*)Zh(sizeof(*n)));*n=Zvd;ZAX(n,_p,Zud,ZaM);
(C->Zom)=((T0*)n);}}}return R;}T6 ZiE2(ZK9*C){T6 R=0;T2 _l1=0;T2 _c1=0;T2 _l2=0;T2 _c2=0;T0*ZiF2=Zo;T0*_i=Zo;T0*_ic=Zo;T0*_vc=Zo;T0*_ue=Zo;
T0*_lb=Zo;T0*_hc=Zo;T0*ZjF2=Zo;T0*ZkF2=Zo;T0*_al=Zo;T0*ZlF2=Zo;if(ZqD2(C,Zny2)){R=((T6)(1));_l1=((C)->Z0f);_c1=((C)->Z1f);_i=ZXD2(C);
if(ZqD2(C,Z5g1)){_l2=((C)->Z0f);_c2=((C)->Z1f);_hc=ZAD2(C);_al=ZCD2(C);if((T6)(((_hc)!=((void*)(Zo)))||((T6)((_al)!=((void*)(Zo)))))){
{T76 Z3w;{Zi9*n=((Zi9*)Zh(sizeof(*n)));*n=ZTl;ZD92(n,(*(Z3w=ZBD2(C,_l2,_c2),&Z3w)),_hc,_al);_ic=((T0*)n);}}}}if(ZqD2(C,ZIy2)){ZjF2=ZAD2(C);
if(ZcE2(C)){ZlF2=((C)->ZAm);}ZkF2=ZAD2(C);if(ZUD2(C)){{ZO1*n=((ZO1*)Zh(sizeof(*n)));*n=Zed;Z3W(n,ZjF2,ZlF2,ZkF2,ZWD2(C,((C)->Zom)));_vc=((T0*)n);
}}else{{ZK9*C1=C;T0*b1=ZvF(38,"Variant (INTEGER) Expression Expected.");{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}if(ZqD2(C,ZHy2)){
if(ZUD2(C)){_ue=ZWD2(C,((C)->Zom));}else{ZzD2(C,ZvF(36,"Boolean expression expected (until)."));_ue=((C)->Zom);}}else{ZzD2(C,ZvF(37,"Keyword \"until\" expected (in a loop)."));
_ue=((C)->Zom);}if((((C)->_cc))==(((T3)'\073'))){{ZK9*C1=C;T0*b1=Z0E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));
}if(!(ZqD2(C,Z6g1))){{ZK9*C1=C;T0*b1=ZvF(36,"Keyword \"loop\" expected (in a loop).");{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}_lb=ZGD2(C,ZmF2,ZEp2);
{T76 Z3w;{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zll;ZV52(n,(*(Z3w=ZBD2(C,_l1,_c1),&Z3w)),_i,_ic,_vc,_ue,_lb);ZiF2=((T0*)n);}}(C->Zum)=ZiF2;
}return R;}T6 ZfE2(ZK9*C){T6 R=0;T0*ZnF2=Zo;if(ZqD2(C,Z3C1)){R=((T6)(1));{T76 Z3w;{Ze5*n=((Ze5*)Zh(sizeof(*n)));*n=Z8h;((((Ze5*)(n)))->Zxb)=((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));
ZnF2=((T0*)n);}}ZoF2(C,ZnF2);if(ZqD2(C,Zo71)){((((Ze5*)(((Ze5*)ZnF2))))->Zle)=(ZGD2(C,ZpF2,ZEp2));}else{if(!(ZqD2(C,ZEp2))){{ZK9*C1=C;
T0*b1=ZvF(20,ZJq);{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}(C->Zum)=ZnF2;}return R;}T0*ZqF2(T0*a1,T0*a2,T0*a3){T0*R=Zo;if((a2)==((void*)(Zo))){
R=a1;}else if((a3)==((void*)(Zo))){{ZQ1*n=((ZQ1*)Zh(sizeof(*n)));*n=Zfd;ZvW(n,a1,a2);R=((T0*)n);}}else if((ZjD1(((Zm3*)a3)))==(Zrs(1))){
{ZM1*n=((ZM1*)Zh(sizeof(*n)));*n=Zad;ZJV(n,a1,a2,a3);R=((T0*)n);}}else{{ZG9*n=((ZG9*)Zh(sizeof(*n)));*n=Z8m;Zhh2(n,a1,a2,a3);R=((T0*)n);
}}return R;}T0*ZWA2(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));*n=M36;ZQK=((T0*)n);}}}return ZQK;}T6 ZXE2(ZK9*C){T6 R=0;if(ZrF2(C)){
R=((T6)(1));}else if(ZsF2(C)){R=((T6)(1));}else if(ZJD2(C)){(C->Zqm)=ZMy2(&(((C)->Z2f)));R=((T6)(1));}return R;}void ZOD2(ZK9*C,T6 a1,T0*a2,T0*a3,T0*a4,T6
a5){if(ZYD2(C,((T3)'\056'))){if((T6)(((a2)!=((void*)(Zo)))&&((T6)(Zf11(a2))))){{T76 Z3w;ZzF((*(Z3w=ZGG(a2),&Z3w)));}{T0*b1=ZvF(27,"Void is not a valid target.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}ZID2(C,(T6)(a1),ZqF2(a2,a3,a4));}else{if(a1){(C->Zum)=ZTE2(C,a2,a3,a4);(C->Zom)=Zo;}else{(C->Zom)=ZqF2(a2,a3,a4);
(C->Zum)=Zo;}}}T6 ZYD2(ZK9*C,T3 a1){T6 R=0;if((a1)==(((C)->_cc))){(C->Z0f)=((C)->ZXe);(C->Z1f)=((C)->ZWe);R=((T6)(1));ZsD2(C);ZpD2(C);
}return R;}T6 ZKE2(ZK9*C,T3 a1,T3 a2){T6 R=0;if((a1)==(((C)->_cc))){(C->Z0f)=((C)->ZXe);(C->Z1f)=((C)->ZWe);ZsD2(C);if((a2)==(((C)->_cc))){
R=((T6)(1));ZsD2(C);ZpD2(C);}else{(C->_cc)=a1;(C->ZWe)=((C)->Z1f);}}return R;}T6 ZjE2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};T0*ZBb=Zo;T0*Zxd=Zo;
T0*Z7F2=Zo;T0*Zyd=Zo;if(ZqD2(C,ZmY)){R=((T6)(1));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZYD2(C,((T3)'\173'))){if(Z5E2(C)){
ZBb=((C)->Zzm);Z8F2(ZBb);if(!(ZYD2(C,((T3)'\175')))){ZzD2(C,ZtF2);}}else{ZzD2(C,ZvF(39,ZVo));}}Zxd=Z9F2(C);if(ZYD2(C,((T3)'\056'))){if(ZJD2(C)){
Z7F2=ZMy2(&(((C)->Z2f)));if((((C)->_cc))==(((T3)'\050'))){Zyd=ZTE2(C,Zxd,Z7F2,ZND2(C));}else{{ZZ6*n=((ZZ6*)Zh(sizeof(*n)));*n=Zkj;Zlp1(n,Zxd,Z7F2);
Zyd=((T0*)n);}}}}{Z45*n=((Z45*)Zh(sizeof(*n)));*n=Z0h;Zmi1(n,_sp,ZBb,Zxd,Zyd);(C->Zum)=((T0*)n);}}return R;}T6 ZrF2(ZK9*C){T6 R=0;if(ZqD2(C,ZXg2)){
R=((T6)(1));if((((C)->_cc))==(((T3)'\042'))){ZsD2(C);}else{{ZK9*C1=C;T0*b1=ZvF(39,"Character \'%\"\' inserted after \"prefix\".");{T76
Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}if(ZuF2(C)){}else if(ZvF2(C,(T6)(1))){}else{ZzD2(C,ZvF(30,"Prefix operator name expected."));}
if(!(ZYD2(C,((T3)'\042')))){{ZK9*C1=C;T0*b1=ZvF(24,ZKq);{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}return R;}T6 ZvE2(ZK9*C){T6 R=0;
ZuA2(&(((C)->ZBm)));if(ZqD2(C,Zoy2)){if(ZXE2(C)){R=((T6)(1));ZwF2(C);ZeA2(((C)->Zqm));}else{ZzD2(C,Z0F2);}}else if(ZXE2(C)){R=((T6)(1));
ZeA2(((C)->Zqm));}while(!(!(ZYD2(C,((T3)'\054'))))){if(ZqD2(C,Zoy2)){if(ZXE2(C)){ZwF2(C);ZeA2(((C)->Zqm));}else{ZzD2(C,ZvF(37,"Frozen feature name synonym expected."));
}}else if(ZXE2(C)){ZeA2(((C)->Zqm));}else{{ZK9*C1=C;T0*b1=ZvF(30,"Synonym feature name expected.");{T76 Z3w;ZlA2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}}if(R){Z2E2(C);if(ZYD2(C,((T3)'\072'))){if(Z5E2(C)){(C->Zfm)=((T6)(1));((((ZA7*)(&(((C)->ZBm)))))->ZBb)=(((C)->Zzm));}else{ZzD2(C,ZdF2);
}}else{(C->Zfm)=((T6)(0));}if(ZqD2(C,Zsy2)){if(ZqD2(C,ZGy2)){(C->Zpm)=ZhA2(&(((C)->ZBm)));}else if(ZxF2(C)){(C->Zpm)=ZpA2(&(((C)->ZBm)),((C)->Zkm));
}else if(ZQE2(C)){(C->Zpm)=ZnA2(&(((C)->ZBm)),((C)->Zlm));}else if(ZyD2(C)){ZVE2(C);((((T88*)((T88*)(((C)->Zrl)))))->ZOm)=((T6)(1));(C->Zpm)=ZsA2(&(((C)->ZBm)),((C)->Zrl));
}else if(ZyF2(C)){(C->Zpm)=ZqA2(&(((C)->ZBm)),((C)->Zjm));}else if(Z9E2(C)){(C->Zpm)=ZxA2(&(((C)->ZBm)),((C)->Zym));}else if(ZzF2(C)){
(C->Zpm)=ZwA2(&(((C)->ZBm)),((C)->Ztm));}else{(C->Zpm)=ZvD2(C);}}else{(C->Zpm)=ZkA2(&(((C)->ZBm)));}(C->Zfm)=((T6)(0));(C->ZAb)=Zo;}return
R;}void ZsD2(ZK9*C){if((Z3)((((C)->ZWe))<((((T7*)(((C)->ZYe)))->Zcc)))){(C->ZWe)=(Z3)(((((C)->ZWe)))+(Zrs(1)));(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[(((C)->ZWe))-(Zrs(1))];
}else if((((C)->ZWe))==((((T7*)(((C)->ZYe)))->Zcc))){(C->ZWe)=(Z3)(((((C)->ZWe)))+(Zrs(1)));(C->_cc)=((T3)'\n');}else if((((C)->ZXe))==((((T72*)(ZoD2()))->Zcc))){
(C->_cc)=((T3)'\000');}else{(C->ZXe)=(Z3)(((((C)->ZXe)))+(Zrs(1)));(C->ZWe)=Zrs(1);(C->ZYe)=(((((T52*)((((T72*)(ZoD2()))->Z2l))))->ZPb))[((C)->ZXe)];
if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}}}T0*Z_K(ZK9*C,T0*a1){
T0*R=Zo;T0*Zoc=Zo;Z7L((T36*)(ZWA2()),ZAF2);Z7L((T36*)(ZWA2()),a1);Z7L((T36*)(ZWA2()),ZBF2);ZKf1((T72*)(ZoD2()),a1);if(!(((((T72*)(ZoD2()))->Zoc))!=(Zo))){
{T0*b1=ZvF(55,"Cannot open Cecil file (use -verbose flag for details).");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}Zoc=(((T72*)(ZoD2()))->Zoc);
(C->Zdm)=ZQY((T40*)(ZCF2()),Zoc);(C->Zcm)=((T6)(1));(C->Zjg)=Zo;(C->Zfm)=((T6)(0));(C->Zgm)=((T6)(0));(C->ZZe)=Zo;(C->ZXe)=Zrs(1);(C->ZWe)=Zrs(1);
(C->ZYe)=(((((T52*)((((T72*)(ZoD2()))->Z2l))))->ZPb))[((C)->ZXe)];(C->Zem)=Zo;if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){(C->_cc)=((T3)'\n');
}else{(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}ZpD2(C);{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z6x(n,(T2)(Zrs(32)));R=((T0*)n);}while(!((T6)(((((C)->_cc))==(((T3)'\n')))||((T6)((((C)->_cc))==(((T3)'\000')))))))
{ZZs(((T7*)R),((C)->_cc));ZsD2(C);}ZpD2(C);if((((C)->_cc))==(((T3)'\000'))){{T0*b1=ZvF(49,"Empty Cecil file (use -verbose flag for details).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}return R;}T6 ZyF2(ZK9*C){T6 R=0;T2 _l=0;T2 _c=0;T6 ZSY1=0;if((T6)(((((C)->_cc))==(((T3)'0')))||((T6)((((C)->_cc))==(((T3)'1')))))){
_l=((C)->ZXe);_c=((C)->ZWe);((((T7*)((T7*)(ZqE2))))->Zcc)=(Zrs(0));ZZs((T7*)(ZqE2),((C)->_cc));while(!(ZSY1)){ZsD2(C);{int z1=((C)->_cc);
switch(z1){case 48:case 49:ZZs((T7*)(ZqE2),((C)->_cc));break;case 66:case 98:{T76 Z3w;{Zf6*n=((Zf6*)Zh(sizeof(*n)));*n=ZKm;ZBi2(n,(*(Z3w=ZBD2(C,_l,_c),&Z3w)),ZRs((T7*)(ZqE2)));
(C->Zjm)=((T0*)n);}}ZsD2(C);ZpD2(C);ZSY1=((T6)(1));R=((T6)(1));break;default:;ZbE2(C,_l,_c);ZSY1=((T6)(1));}}}}return R;}void Ziq2(ZK9*C){
(C->Zam)=((T6)(1));(((void)((T26*)(ZtD2()))));Zxm2(ZxQ);Zxm2(ZBQ);Zxm2(ZTQ);Zxm2(Z7R);Zxm2(ZlR);Zxm2(ZmR);Zxm2(ZnR);Zxm2(ZpR);Zxm2(ZqR);
Zxm2(ZrR);Zxm2(ZtR);Zxm2(ZHR);}T6 ZaE2(ZK9*C,T1 a1){T6 R=0;T2 ZIi=0;T2 _l=0;T2 _c=0;if((T6)((Zjs(((C)->_cc)))||((T6)((((C)->_cc))==(((T3)'\056')))))){
_l=((C)->ZXe);_c=((C)->ZWe);((((T7*)((T7*)(ZqE2))))->Zcc)=(Zrs(0));if((Z1)((a1)<(Zrs(0)))){ZZs((T7*)(ZqE2),((T3)'\055'));}if((((C)->_cc))==(((T3)'\056'))){
ZXw((T7*)(ZqE2),ZDF2);ZIi=Zrs(5);}else{ZZs((T7*)(ZqE2),((C)->_cc));}while(!((Z3)((ZIi)>(Zrs(11))))){ZsD2(C);{int z1=ZIi;switch(z1){case
0:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));
break;case 46:ZZs((T7*)(ZqE2),((T3)'\056'));ZIi=Zrs(4);break;default:;ZIi=Zrs(13);}}break;case 1:{int z2=((C)->_cc);switch(z2){case 48:
case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(2);break;default:;ZzD2(C,ZEF2);
}}break;case 2:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));
ZIi=Zrs(3);break;default:;ZzD2(C,ZEF2);}}break;case 3:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case
54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(0);break;default:;ZzD2(C,ZEF2);}}break;case 4:{int z2=((C)->_cc);switch(z2){
case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(6);break;case 69:
case 101:ZZs((T7*)(ZqE2),((T3)'E'));ZIi=Zrs(10);break;default:;ZIi=Zrs(12);}}break;case 5:{int z2=((C)->_cc);switch(z2){case 48:case 49:
case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(6);break;default:;ZIi=Zrs(13);}}break;
case 6:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));
break;case 69:case 101:ZZs((T7*)(ZqE2),((T3)'E'));ZIi=Zrs(10);break;case 95:ZIi=Zrs(7);break;default:;ZIi=Zrs(12);}}break;case 7:{int
z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));
ZIi=Zrs(8);break;default:;ZzD2(C,ZFF2);}}break;case 8:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case
54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(9);break;default:;ZzD2(C,ZFF2);}}break;case 9:{int z2=((C)->_cc);switch(z2){
case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(6);break;default:;
ZzD2(C,ZFF2);}}break;case 10:{int z2=((C)->_cc);switch(z2){case 43:ZIi=Zrs(11);break;case 45:ZZs((T7*)(ZqE2),((T3)'\055'));ZIi=Zrs(11);
break;case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));ZIi=Zrs(11);break;default:;
ZzD2(C,ZvF(34,"Exponent of a real value expected."));ZIi=Zrs(13);}}break;default:;{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:
case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZZs((T7*)(ZqE2),((C)->_cc));break;default:;ZIi=Zrs(12);}}}}}if((ZIi)==(Zrs(12))){
{T76 Z3w;{Zy9*n=((Zy9*)Zh(sizeof(*n)));*n=Z4m;ZgW(n,(*(Z3w=ZBD2(C,_l,_c),&Z3w)),ZRs((T7*)(ZqE2)));(C->Zym)=((T0*)n);}}R=((T6)(1));ZpD2(C);
}else{ZbE2(C,_l,_c);}}return R;}T6 ZGF2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};T0*Zpj=Zo;T0*_e=Zo;T0*Zyd=Zo;T0*ZLn1=Zo;if(ZqD2(C,ZtQ)){{T76 Z3w;
_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}R=((T6)(1));if(ZYD2(C,((T3)'\173'))){if(!(Z5E2(C))){ZzD2(C,ZvF(31,"Bad agent (BASE type expected)."));
}Zpj=((C)->Zzm);if(!(ZYD2(C,((T3)'\175')))){ZzD2(C,ZvF(25,"Bad agent (\"\175""\" expected)."));}if(!(ZYD2(C,((T3)'\056')))){ZzD2(C,ZvF(25,Z7o));
}}else if(ZYD2(C,((T3)'\050'))){if(ZUD2(C)){_e=((C)->Zom);}if(!(ZYD2(C,((T3)'\051')))){ZzD2(C,ZvF(25,"Bad agent (\")\" expected)."));
}if(!(ZYD2(C,((T3)'\056')))){ZzD2(C,ZvF(25,Z7o));}}if(!(ZJD2(C))){ZzD2(C,ZHF2);}if((_e)!=((void*)(Zo))){ZLn1=ZMy2(&(((C)->Z2f)));ZOD2(C,(T6)(0),_e,ZLn1,ZND2(C),(T6)(1));
}else if(ZRD2(C)){ZOD2(C,(T6)(0),((C)->Zom),Zo,Zo,(T6)(1));}else if((T6)(((T6)(((T6)((ZKD2(C))||((T6)(ZMD2(C)))))||((T6)(ZLD2(C)))))||((T6)(ZTD2(C))))){
ZOD2(C,(T6)(0),((C)->Zom),Zo,Zo,(T6)(0));}else{ZmE2(C);}_e=((C)->Zom);Zyd=_e;if(Zo!=(Zyd)){switch(((T0*)Zyd)->id){case 223:case 229:case
230:case 231:case 232:case 233:case 234:case 235:case 236:case 237:case 238:case 239:case 240:case 241:case 244:case 250:case 251:case
254:case 255:case 256:case 325:case 326:case 328:case 329:case 330:case 331:case 332:break;default:Zyd=Zo;}}if((Zyd)==((void*)(Zo))){
if((_e)!=((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(_e),&Z3w)));}}{T0*b1=ZHF2;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}{Z27*n=((Z27*)Zh(sizeof(*n)));
*n=Zvj;ZPI1(n,_sp,Zpj,Zyd);(C->Zom)=((T0*)n);}}return R;}T6 ZLD2(ZK9*C){T6 R=0;if(Z8y2()){(C->Zom)=ZPy2(&(((C)->Z2f)));R=((T6)(1));}return
R;}T6 ZIF2(ZK9*C){T6 R=0;T2 _l=0;T2 _c=0;T0*ZBb=Zo;T0*ZLn1=Zo;if(ZYD2(C,((T3)'\044'))){if(ZJD2(C)){if((T6)(((T6)((ZKD2(C))||((T6)(ZLD2(C)))))||((T6)(ZMD2(C))))){
{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->Zom)),&Z3w)));}{T0*b1=Zic1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else{ZLn1=ZMy2(&(((C)->Z2f)));{ZA1*n=((ZA1*)Zh(sizeof(*n)));
*n=Z5g;((((ZA1*)(n)))->ZZb)=(ZLn1);(C->Zom)=((T0*)n);}R=((T6)(1));}}else{ZzD2(C,Zic1);}}else if(ZYD2(C,((T3)'\077'))){R=((T6)(1));_l=((C)->Z0f);
_c=((C)->Z1f);{T76 Z3w;{ZG3*n=((ZG3*)Zh(sizeof(*n)));*n=ZDl;((((ZG3*)(n)))->Zxb)=((*(Z3w=ZBD2(C,_l,_c),&Z3w)));(C->Zom)=((T0*)n);}}}else
if(ZYD2(C,((T3)'\173'))){_l=((C)->Z0f);_c=((C)->Z1f);if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZBb=((C)->Zzm);if(!(ZYD2(C,((T3)'\175')))){ZzD2(C,ZtF2);
}if(ZqD2(C,ZlS)){ZbE2(C,_l,_c);}else{R=((T6)(1));{T76 Z3w;{ZG3*n=((ZG3*)Zh(sizeof(*n)));*n=ZDl;Zn82(n,(*(Z3w=ZBD2(C,_l,_c),&Z3w)),ZBb);
(C->Zom)=((T0*)n);}}}}else if(ZUD2(C)){R=((T6)(1));}return R;}T0*Z6C2(ZK9*C,T0*a1){T0*R=Zo;T2 ZKF2=0;T2 ZLF2=0;T0*Zoc=Zo;(C->Zdm)=ZQY((T40*)(ZCF2()),((((T80*)a1))->Zre));
Zoc=(((T72*)(ZoD2()))->Zoc);if((Z3)(((((T75*)(ZyF))->ZAg))>(Zrs(0)))){{T0*b1=ZvF(32,"Correct previous error(s) first.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}ZsL((T36*)(ZWA2()),(Z3)((((((ZT2*)(Z4t2))->Zcc)))+((T2)(Zrs(1)))));ZwL((T36*)(ZWA2()),((T3)'\011'));Z7L((T36*)(ZWA2()),Zoc);
ZwL((T36*)(ZWA2()),((T3)'\n'));ZKF2=(((T75*)(ZyF))->ZAg);ZLF2=(((T75*)(ZyF))->ZBg);(C->Zcm)=((T6)(1));(C->Zfm)=((T6)(0));(C->Zgm)=((T6)(0));
(C->ZZe)=Zo;(C->ZXe)=Zrs(1);(C->ZWe)=Zrs(1);(C->ZYe)=(((((T52*)((((T72*)(ZoD2()))->Z2l))))->ZPb))[((C)->ZXe)];if(((((T7*)(((C)->ZYe)))->Zcc))==(Zrs(0))){
(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZYe)))->ZPb))[Zrs(0)];}{T82*n=((T82*)Zh(sizeof(*n)));*n=M82;ZUj1(n,Zoc,((((T80*)a1))->Zre),(((T72*)(ZoD2()))->Zcg),((C)->Zdm));
(C->Zem)=((T0*)n);}ZpD2(C);ZMF2(C);(C->Zcm)=((T6)(0));Zb32((T72*)(ZoD2()));R=((C)->Zem);if((Z3)(((Z3)((((((T75*)(ZyF))->ZAg)))-(ZKF2)))>(Zrs(0)))){
ZXA2((((T75*)(ZyF))->ZAg),ZZA2);(((void)((T36*)(ZWA2()))),ZUf1(ZvF(12,"Load class \"")));(((void)((T36*)(ZWA2()))),ZUf1(Zoc));(((void)((T36*)(ZWA2()))),ZUf1(ZvF(11,"\" aborted.\n")));
R=Zo;}else if((Z3)(((Z3)((((((T75*)(ZyF))->ZBg)))-(ZLF2)))>(Zrs(0)))){{T6 ZVA2=0;if((((T36*)(ZWA2()))->ZJh)){ZVA2=((T6)(1));}else if((((T75*)(ZyF))->ZCg)){
}else{ZVA2=((T6)(1));}if(ZVA2){ZXA2((((T75*)(ZyF))->ZBg),ZYA2);}}}if((R)!=((void*)(Zo))){ZJk1(((T82*)R));}return R;}T6 ZNF2(ZK9*C,T0*a1){
T6 R=0;T2 ZIi=0;T0*ZPc=Zo;T0*ZOF2=Zo;if(ZqD2(C,ZJy2)){R=((T6)(1));{T76 Z3w;{ZT4*n=((ZT4*)Zh(sizeof(*n)));*n=ZSg;ZGg1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZAD2(C));
ZPc=((T0*)n);}}while(!((Z3)((ZIi)>(Zrs(3))))){{int z1=ZIi;switch(z1){case 0:if(ZPF2(C)){ZOF2=((C)->Zom);ZIi=Zrs(1);}else if(ZqD2(C,ZDy2)){
if((ZOF2)!=((void*)(Zo))){Zxg1(((ZT4*)ZPc),ZOF2);}((((ZT4*)(((ZT4*)ZPc))))->Z7d)=(ZXD2(C));Z671(((Zq3*)a1),ZPc);ZIi=Zrs(4);}else if((((C)->_cc))==(((T3)'\054'))){
{ZK9*C1=C;T0*b1=ZYE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}else{ZzD2(C,ZQF2);ZIi=Zrs(4);}
break;case 1:if(ZqD2(C,ZDy2)){if((ZOF2)!=((void*)(Zo))){Zxg1(((ZT4*)ZPc),ZOF2);}((((ZT4*)(((ZT4*)ZPc))))->Z7d)=(ZXD2(C));Z671(((Zq3*)a1),ZPc);
ZIi=Zrs(4);}else if(ZKE2(C,((T3)'\056'),((T3)'\056'))){ZIi=Zrs(2);}else if(ZYD2(C,((T3)'\054'))){Zxg1(((ZT4*)ZPc),ZOF2);ZOF2=Zo;ZIi=Zrs(0);
}else{ZzD2(C,ZQF2);ZIi=Zrs(4);}break;case 2:if(ZPF2(C)){ZQg1(((ZT4*)ZPc),ZOF2,((C)->Zom));ZOF2=Zo;ZIi=Zrs(3);}else{ZzD2(C,ZQF2);ZIi=Zrs(4);
}break;default:;if(ZYD2(C,((T3)'\054'))){ZIi=Zrs(0);}else if(ZqD2(C,ZDy2)){((((ZT4*)(((ZT4*)ZPc))))->Z7d)=(ZXD2(C));Z671(((Zq3*)a1),ZPc);
ZIi=Zrs(4);}else if(ZPF2(C)){ZOF2=((C)->Zom);ZHD2(((((C)->Z2f)).Zxb),ZZE2);ZIi=Zrs(1);}else{ZzD2(C,ZQF2);ZIi=Zrs(4);}}}}}return R;}void
ZoF2(ZK9*C,T0*a1){if(!(ZVD2(C,a1))){ZzD2(C,ZvF(21,"In \"if ... then ...\"."));}while(!(!(ZqD2(C,Zjy2)))){if(!(ZVD2(C,a1))){ZzD2(C,ZvF(25,"In \"elseif ... then ...\"."));
}}}T6 ZeE2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};T0*ZUb=Zo;T0*ZmJ1=Zo;if(ZqD2(C,Z8g1)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(ZYD2(C,((T3)'\050'))){{ZP*n=((ZP*)Zh(sizeof(*n)));*n=Z5c;ZJx(n,(T2)(Zrs(4)));ZUb=((T0*)n);}while(!(!(ZyD2(C)))){((((T88*)((T88*)(((C)->Zrl)))))->ZOm)=((T6)(1));
ZIx(((ZP*)ZUb),((C)->Zrl));(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}if((Z3)((((((ZP*)ZUb))->ZRb))<(Zrs(0)))){{ZK9*C1=C;T0*b1=ZvF(31,"Empty debug key list (deleted).");
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}ZUb=Zo;}if(!(ZYD2(C,((T3)'\051')))){ZzD2(C,ZvF(38,"\")\" expected to end debug string list."));
}}R=((T6)(1));{ZI1*n=((ZI1*)Zh(sizeof(*n)));*n=Z8d;ZhV(n,_sp,ZUb,ZGD2(C,ZRF2,ZEp2));ZmJ1=((T0*)n);}(C->Zum)=ZmJ1;}return R;}void ZSF2(ZK9*C){
if(ZqD2(C,Zpy2)){while(!(!(ZwE2(C)))){(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));}}}T6 ZCE2(ZK9*C){T6 R=0;T0*ZTF2=Zo;T0*ZUF2=Zo;T2 _l=0;T2
_c=0;_l=((C)->ZXe);_c=((C)->ZWe);if(ZXE2(C)){ZTF2=((C)->Zqm);if(ZqD2(C,Zey2)){if(ZXE2(C)){R=((T6)(1));{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=ZZg;
Zai1(n,ZTF2,((C)->Zqm));ZUF2=((T0*)n);}ZAB1((Zv2*)(((C)->Zxm)),ZUF2);}else{ZzD2(C,ZvF(46,"Second identifier of a \"rename\" pair expected."));
}}else{ZbE2(C,_l,_c);}}return R;}T6 ZAE2(ZK9*C){T6 R=0;if(ZxF2(C)){(C->Zwm)=((C)->Zkm);R=((T6)(1));}else if(ZQE2(C)){(C->Zwm)=((C)->Zlm);
R=((T6)(1));}else if(ZyD2(C)){(C->Zwm)=((C)->Zrl);R=((T6)(1));}else if(ZyF2(C)){(C->Zwm)=((C)->Zjm);R=((T6)(1));}else if(Z9E2(C)){(C->Zwm)=((C)->Zym);
R=((T6)(1));}else if(ZzF2(C)){(C->Zwm)=((C)->Ztm);R=((T6)(1));}return R;}T0*ZVF2(void){if(Z8C2==0){Z8C2=1;{{ZQ*n=((ZQ*)Zh(1));Z7C2=((T0*)n);
}}}return Z7C2;}T6 ZhE2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};T76 ZWF2={Zo,Zo,0};T0*_i=Zo;T0*_ec=Zo;if(ZqD2(C,Zry2)){R=((T6)(1));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(ZUD2(C)){(C->Zom)=ZWD2(C,((C)->Zom));}else{ZzD2(C,ZvF(37,"Expression expected (\"inspect ... \")."));}{Zq3*n=((Zq3*)Zh(sizeof(*n)));
*n=Zne;Zt71(n,_sp,((C)->Zom));_i=((T0*)n);}while(!(!(ZNF2(C,_i)))){}if(ZqD2(C,Zo71)){{T76 Z3w;ZWF2=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}_ec=ZGD2(C,ZXF2,ZEp2);Zu71(((Zq3*)_i),ZWF2,_ec);}else if(!(ZqD2(C,ZEp2))){{ZK9*C1=C;T0*b1=ZvF(36,"Added \"end\" for inspect instruction.");
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}(C->Zum)=_i;}return R;}T6 ZYF2(ZK9*C){T6 R=0;if(ZfF2(C)){R=((T6)(1));}else if(ZYD2(C,((T3)'\050'))){
R=((T6)(1));if(ZUD2(C)){if(ZYD2(C,((T3)'\051'))){ZOD2(C,(T6)(0),((C)->Zom),Zo,Zo,(T6)(0));}else{ZzD2(C,ZvF(27,"\')\' expected in expression."));
}}else{ZzD2(C,ZvF(20,"Expression expected."));}}else if(ZAE2(C)){(C->Zom)=((C)->Zwm);R=((T6)(1));if(ZYD2(C,((T3)'\056'))){{ZK9*C1=C;T0*b1=ZZF2;
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}ZID2(C,(T6)(0),((C)->Zom));}}else if(ZgF2(C,(T6)(0))){R=((T6)(1));}else if(Z_F2(C)){R=((T6)(1));
}else if(ZGF2(C)){R=((T6)(1));}else if(ZJD2(C)){R=((T6)(1));if(ZRD2(C)){ZOD2(C,(T6)(0),((C)->Zom),Zo,Zo,(T6)(1));}else if((T6)(((T6)(((T6)((ZMD2(C))||((T6)(ZKD2(C)))))||((T6)(ZLD2(C)))))||((T6)(ZTD2(C))))){
ZOD2(C,(T6)(0),((C)->Zom),Zo,Zo,(T6)(0));}else{ZmE2(C);}}return R;}T6 ZcF2(ZK9*C){T6 R=0;T2 _c=0;T6 ZSY1=0;T6 Zi11=0;if(Zss(((C)->_cc))){
if((((unsigned)(((C)->_cc)))>=((unsigned)(((T3)'a'))))){Zi11=((T6)(1));(C->_cc)=Zvs(((C)->_cc));}_c=((C)->ZWe);{T76 Z3w;Zdq2(&(((C)->Z2f)),(*(Z3w=ZBD2(C,((C)->ZXe),_c),&Z3w)));
}{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}while(!(ZSY1)){ZsD2(C);{int z1=((C)->_cc);switch(z1){case 48:case 49:case 50:case 51:case 52:
case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:
case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 95:{T3 b1=((C)->_cc);
ZZs((T7*)(Zeq2),b1);}break;case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case
109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:Zi11=((T6)(1));
{T3 b1=Zvs(((C)->_cc));ZZs((T7*)(Zeq2),b1);}break;default:;ZSY1=((T6)(1));}}}if(Zby2(&(((C)->Z2f)))){(C->_cc)=(((((T7*)Zeq2))->ZPb))[Zrs(0)];
(C->ZWe)=_c;}else{R=((T6)(1));ZpD2(C);if(Zi11){ZHD2(((((C)->Z2f)).Zxb),Z0G2);}(C->Zmm)=Zqp2(&(((C)->Z2f)));}}return R;}T6 ZRD2(ZK9*C){
T6 R=0;T2 Zoe=0;if((((C)->ZAb))!=((void*)(Zo))){Zoe=ZJ71((ZH6*)(((C)->ZAb)),Z6y2(&(((C)->Z2f))));if((Z3)((Zoe)>(Zrs(0)))){(C->Zom)=Z7y2(&(((C)->Z2f)),((C)->ZAb),Zoe);
R=((T6)(1));}}return R;}T0*Z1L(ZK9*C){T0*R=Zo;if(Z3F2(C)){R=((C)->Znm);}else{ZzD2(C,ZdF2);}return R;}T6 Z5E2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};
T0*Z1G2=Zo;R=((T6)(1));if(ZqD2(C,Zvh1)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZsF2(C)){{ZX4*n=((ZX4*)Zh(sizeof(*n)));
*n=ZWg;Zuh1(n,_sp,((C)->Zqm));(C->Zzm)=((T0*)n);}}else if(ZrF2(C)){{ZX4*n=((ZX4*)Zh(sizeof(*n)));*n=ZWg;Zuh1(n,_sp,((C)->Zqm));(C->Zzm)=((T0*)n);
}}else if(ZJD2(C)){if(ZMD2(C)){{Zr2*n=((Zr2*)Zh(sizeof(*n)));*n=ZId;((((Zr2*)(n)))->Zxb)=(_sp);(C->Zzm)=((T0*)n);}}else if(ZRD2(C)){Z1G2=((C)->Zom);
if(Zo!=(Z1G2)){switch(((T0*)Z1G2)->id){case 263:break;default:Z1G2=Zo;}}{Zp8*n=((Zp8*)Zh(sizeof(*n)));*n=ZWk;Z781(n,_sp,Z1G2);(C->Zzm)=((T0*)n);
}}else{{ZX4*n=((ZX4*)Zh(sizeof(*n)));*n=ZWg;Zuh1(n,_sp,ZMy2(&(((C)->Z2f))));(C->Zzm)=((T0*)n);}}}else{ZzD2(C,ZvF(82,"Anchor expected. An anchor could be `Current\', a feature name or an argument name."));
}}else if(ZqD2(C,Zht1)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(Z3F2(C)){{ZQ5*n=((ZQ5*)Zh(sizeof(*n)));*n=ZKh;Z3t1(n,_sp,((C)->Znm));
(C->Zzm)=((T0*)n);}}else{ZzD2(C,ZvF(40,"Must find a class type after \"expanded\"."));}}else if(ZqD2(C,ZlU)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(Z3F2(C)){{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Z5d;ZNU(n,_sp,((C)->Znm));(C->Zzm)=((T0*)n);}}else{ZzD2(C,ZvF(41,"Must find a class type after \"reference\"."));
}}else if(ZqD2(C,ZzS)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(Z3F2(C)){(C->Zzm)=(((void)((ZQ*)(ZVF2()))),ZVI(_sp,((C)->Znm)));
}else{ZzD2(C,ZvF(40,"Must find a class type after \"separate\"."));}}else if(ZqD2(C,ZgP)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(Z2G2(C,(T6)(0))){{ZL8*n=((ZL8*)Zh(sizeof(*n)));*n=Z9l;Zm42(n,_sp,((C)->Ztm));(C->Zzm)=((T0*)n);}}else if(ZJD2(C)){{ZJ8*n=((ZJ8*)Zh(sizeof(*n)));
*n=Z8l;Z142(n,_sp,ZMy2(&(((C)->Z2f))));(C->Zzm)=((T0*)n);}}else{ZzD2(C,ZvF(45,"Expected constant for BIT_N type declaration."));}}else
if(Z3G2(C)){(C->Zzm)=((C)->Zsm);}else if(Z3F2(C)){(C->Zzm)=((C)->Znm);}else{R=((T6)(0));}return R;}T6 Z4G2(ZK9*C,T3 a1,T3 a2){T6 R=0;
(C->Z0f)=((C)->ZXe);(C->Z1f)=((C)->ZWe);if((((C)->_cc))==(a1)){ZsD2(C);if((((C)->_cc))==(a2)){(C->_cc)=a1;(C->ZWe)=((C)->Z1f);}else{R=((T6)(1));
ZpD2(C);}}return R;}T6 ZsF2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};if(ZqD2(C,ZWg2)){R=((T6)(1));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if((((C)->_cc))==(((T3)'\042'))){ZsD2(C);}else{{ZK9*C1=C;T0*b1=ZvF(38,"Character \'%\"\' inserted after \"infix\".");{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}if(ZJE2(C,_sp)){}else if(ZvF2(C,(T6)(0))){}else{ZzD2(C,ZvF(29,"Infix operator name expected."));}if(!(ZYD2(C,((T3)'\042')))){{ZK9*C1=C;
T0*b1=ZvF(24,ZKq);{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}return R;}void Z5G2(ZK9*C){T0*ZLn1=Zo;T0*ZnE2=Zo;ZLn1=ZMy2(&(((C)->Z2f)));
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Z5l;((((ZD8*)(n)))->Zxb)=(((((ZB8*)ZLn1))->Zxb));ZnE2=((T0*)n);}ZOD2(C,(T6)(1),ZnE2,ZLn1,ZND2(C),(T6)(1));
}T6 Z3G2(ZK9*C){T6 R=0;T0*Z6G2=Zo;T0*_cn=Zo;T2 Zoe=0;if((((C)->Zjg))!=((void*)(Zo))){Zoe=Zrs(1);while(!((T6)((R)||((T6)((Z3)((Zoe)>(Ztx(((ZB*)((((Zba*)(((C)->Zjg)))->ZUb)))))))))))
{Z6G2=Zux(((ZB*)((((Zba*)(((C)->Zjg)))->ZUb))),Zoe);if(ZqD2(C,(((T80*)(((((Z38*)Z6G2))->Zkc)))->Zre))){{T76 Z3w;{T80*n=((T80*)Zh(sizeof(*n)));
*n=M80;Zb61(n,(((T80*)(((((Z38*)Z6G2))->Zkc)))->Zre),(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));_cn=((T0*)n);}}{Zr8*n=((Zr8*)Zh(sizeof(*n)));
*n=Z_k;ZGZ1(n,_cn,Z6G2,Zoe);(C->Zsm)=((T0*)n);}R=((T6)(1));}Zoe=(Z3)(((Zoe))+(Zrs(1)));}}return R;}T0*Z0L(ZK9*C){T0*R=Zo;{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Z6x(n,(T2)(Zrs(32)));R=((T0*)n);}while(!(Zks(((C)->_cc)))){ZZs(((T7*)R),((C)->_cc));ZsD2(C);}ZpD2(C);return R;}T0*ZoE2(ZK9*C){T0*R=Zo;
T0*Z7G2=Zo;T0*_l=Zo;T0*ZBc=Zo;if(!(ZyD2(C))){ZzD2(C,ZvF(47,"Bad external clause (manifest string expected)."));}ZVE2(C);ZBc=((C)->Zrl);
((((T88*)(((T88*)ZBc))))->ZOm)=((T6)(0));ZkZ1((Z07*)(ZhZ1),ZBc);if(ZnZ1((Z07*)(ZhZ1))){Z8G2(ZBc);}else if(Z8A2((Z07*)(ZhZ1),Zfs1)){{ZA9*n=((ZA9*)Zh(sizeof(*n)));
*n=Z5m;((((ZA9*)(n)))->ZBc)=(ZBc);_l=((T0*)n);}}else if(Z8A2((Z07*)(ZhZ1),Z9G2)){ZzF(((((T88*)ZBc))->Zxb));{T0*b1=ZvF(78,"Obsolete \"SmallEiffel\" keyword replaced with \"SmartEiffel\" (update your code).");
ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));{ZA9*n=((ZA9*)Zh(sizeof(*n)));*n=Z5m;((((ZA9*)(n)))->ZBc)=(ZBc);_l=((T0*)n);}}else if(ZoZ1((Z07*)(ZhZ1),ZaG2)){
{Za1*n=((Za1*)Zh(sizeof(*n)));*n=ZEc;((((Za1*)(n)))->ZBc)=(ZBc);_l=((T0*)n);}}else if(ZoZ1((Z07*)(ZhZ1),ZbG2)){{ZW7*n=((ZW7*)Zh(sizeof(*n)));
*n=Zpk;Z8Z1(n,ZBc);_l=((T0*)n);}}else if(ZoZ1((Z07*)(ZhZ1),ZcG2)){{Zs9*n=((Zs9*)Zh(sizeof(*n)));*n=Z1m;((((Zs9*)(n)))->ZBc)=(ZBc);_l=((T0*)n);
}}else{Z8G2(ZBc);}if(ZqD2(C,Zcy2)){if(!(ZyD2(C))){ZzD2(C,ZvF(26,"Bad external alias clause."));}ZVE2(C);Z7G2=(((T88*)(((C)->Zrl)))->Zre);
}R=ZgA2(&(((C)->ZBm)),_l,Z7G2);return R;}void ZdG2(T76 a1,T6 a2,T0*a3){T0*ZEz1=Zo;ZEz1=ZvF(30,"Right hand side expression of ");if(a2){
ZXw(((T7*)ZEz1),ZXg2);}else{ZXw(((T7*)ZEz1),ZWg2);}ZXw(((T7*)ZEz1),ZvF(2,Ztn));ZXw(((T7*)ZEz1),a3);ZXw(((T7*)ZEz1),ZvF(11,ZHq));ZzF(a1);
{T0*b1=ZEz1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}T6 ZeG2(ZK9*C){T6 R=0;R=((T6)(ZfG2(C)));if(R){ZgG2(C,((C)->Zom));}return R;}T0*ZuE2=Zo;
T6 ZfG2(ZK9*C){T6 R=0;R=((T6)(ZhG2(C)));if(R){ZiG2(C,((C)->Zom));}return R;}T6 ZhG2(ZK9*C){T6 R=0;R=((T6)(ZjG2(C)));if(R){ZkG2(C,((C)->Zom));
}return R;}T6 ZjG2(ZK9*C){T6 R=0;R=((T6)(ZlG2(C)));if(R){ZmG2(C,((C)->Zom));}return R;}T6 ZxF2(ZK9*C){T6 R=0;if(ZqD2(C,ZEy2)){{T76 Z3w;
{Za5*n=((Za5*)Zh(sizeof(*n)));*n=Z5h;ZpH(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zkm)=((T0*)n);}}R=((T6)(1));}else if(ZqD2(C,Zly2)){
{T76 Z3w;{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zel;ZqH(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zkm)=((T0*)n);}}R=((T6)(1));}return
R;}T6 ZlG2(ZK9*C){T6 R=0;R=((T6)(ZnG2(C)));if(R){ZoG2(C,((C)->Zom));}return R;}T6 ZnG2(ZK9*C){T6 R=0;R=((T6)(ZpG2(C)));if(R){ZqG2(C,((C)->Zom));
}return R;}T0*ZrG2=Zo;int ZsG2=0;T0*ZIE2(void){if(ZsG2==0){ZsG2=1;{{T90*n=((T90*)Zh(sizeof(*n)));*n=M90;ZrG2=((T0*)n);Z662(n,(T2)(Zrs(0)));
}}}return ZrG2;}T6 ZpG2(ZK9*C){T6 R=0;R=((T6)(ZtG2(C)));if(R){ZuG2(C,((C)->Zom));}return R;}T6 ZtG2(ZK9*C){T6 R=0;R=((T6)(ZvG2(C)));if(R){
ZwG2(C,((C)->Zom));}return R;}T6 ZvG2(ZK9*C){T6 R=0;T0*_op=Zo;T0*ZxG2=Zo;T76 _sp={Zo,Zo,0};T2 _l=0;T2 _c=0;if(ZqD2(C,ZhQ)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(ZvG2(C)){{ZI3*n=((ZI3*)Zh(sizeof(*n)));*n=ZAe;ZZ91(n,_sp,((C)->Zom));(C->Zom)=((T0*)n);}R=((T6)(1));}else{ZdG2(_sp,(T6)(1),ZhQ);}
}else if(ZYD2(C,((T3)'\053'))){_l=((C)->Z0f);_c=((C)->Z1f);if(ZaE2(C,Zrs(0))){(C->Zom)=((C)->Zym);R=((T6)(1));}else if(Z2G2(C,(T6)(0))){
(C->Zom)=((C)->Ztm);R=((T6)(1));}else{{T76 Z3w;_sp=(*(Z3w=ZBD2(C,_l,_c),&Z3w));}if(ZvG2(C)){{Zw9*n=((Zw9*)Zh(sizeof(*n)));*n=Z3m;ZPb2(n,_sp,((C)->Zom));
(C->Zom)=((T0*)n);}R=((T6)(1));}else{ZdG2(_sp,(T6)(1),ZkQ);}}}else if(ZYD2(C,((T3)'\055'))){_l=((C)->Z0f);_c=((C)->Z1f);if(ZaE2(C,Zrs(-1))){
(C->Zom)=((C)->Zym);R=((T6)(1));}else if(Z2G2(C,(T6)(1))){(C->Zom)=((C)->Ztm);R=((T6)(1));}else{{T76 Z3w;_sp=(*(Z3w=ZBD2(C,_l,_c),&Z3w));
}if(ZvG2(C)){{Zi7*n=((Zi7*)Zh(sizeof(*n)));*n=ZHj;ZjL1(n,_sp,((C)->Zom));(C->Zom)=((T0*)n);}R=((T6)(1));}else{ZdG2(_sp,(T6)(1),ZdJ);}
}}else if(Z4F2(C,(T6)(1))){_op=((C)->Zqm);if(ZvG2(C)){{ZA3*n=((ZA3*)Zh(sizeof(*n)));*n=Zye;Zt91(n,((C)->Zom),_op);ZxG2=((T0*)n);}(C->Zom)=ZxG2;
R=((T6)(1));}else{ZdG2(((((ZB8*)_op))->Zxb),(T6)(1),((((ZB8*)_op))->Zre));}}else{R=((T6)(ZyG2(C)));}return R;}T6 ZyG2(ZK9*C){T6 R=0;if(ZqD2(C,Zvy2)){
if(!(((C)->Zgm))){{T76 Z3w;ZlA2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZvF(60,"Expression \"old\" can be used in ensure clause only (VAOL.1)."));
}}if(ZYF2(C)){{ZE3*n=((ZE3*)Zh(sizeof(*n)));*n=Zkf;((((ZE3*)(n)))->ZTc)=(((C)->Zom));(C->Zom)=((T0*)n);}R=((T6)(1));}else{ZzD2(C,ZvF(32,"Expression expected after \"old\"."));
}}else{R=((T6)(ZYF2(C)));}return R;}T6 ZuF2(ZK9*C){T6 R=0;if(ZqD2(C,ZhQ)){{T76 Z3w;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z_91(n,ZhQ,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));
(C->Zqm)=((T0*)n);}}R=((T6)(1));}else if(ZYD2(C,((T3)'\053'))){{T76 Z3w;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z_91(n,ZkQ,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));
(C->Zqm)=((T0*)n);}}R=((T6)(1));}else if(ZYD2(C,((T3)'\055'))){{T76 Z3w;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z_91(n,ZdJ,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));
(C->Zqm)=((T0*)n);}}R=((T6)(1));}return R;}T6 ZkE2(ZK9*C){T6 R=0;if((T6)((ZYD2(C,((T3)'\050')))&&((T6)(ZUD2(C))))){R=((T6)(1));if(ZYD2(C,((T3)'\051'))){
ZOD2(C,(T6)(1),((C)->Zom),Zo,Zo,(T6)(0));}else{ZzD2(C,ZvF(13,"\')\' expected."));}}else if(ZgF2(C,(T6)(1))){R=((T6)(1));}else if(ZJD2(C)){
R=((T6)(1));if(ZKE2(C,((T3)'\072'),((T3)'\075'))){ZQD2(C,(T6)(1));}else if(ZKE2(C,((T3)'\077'),((T3)'\075'))){ZQD2(C,(T6)(0));}else if(ZRD2(C)){
ZOD2(C,(T6)(1),((C)->Zom),Zo,Zo,(T6)(1));}else if((T6)(((T6)((ZMD2(C))||((T6)(ZKD2(C)))))||((T6)(ZTD2(C))))){ZOD2(C,(T6)(1),((C)->Zom),Zo,Zo,(T6)(0));
}else{Z5G2(C);}}return R;}T0*ZtE2(ZK9*C){T0*R=Zo;T76 _sp={Zo,Zo,0};T0*ZUb=Zo;T2 ZIi=0;if(ZYD2(C,((T3)'\173'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}while(!((Z3)((ZIi)>(Zrs(3))))){{int z1=ZIi;switch(z1){case 0:if(ZcF2(C)){{Zy3*n=((Zy3*)Zh(sizeof(*n)));*n=Zxe;((((Zy3*)(n)))->ZBd)=(((C)->Zmm));
ZUb=((T0*)n);}ZIi=Zrs(2);}else if(ZYD2(C,((T3)'\175'))){ZIi=Zrs(4);}else if((((C)->_cc))==(((T3)'\054'))){{ZK9*C1=C;T0*b1=ZYE2;{T76 Z3w;
ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}else{ZIi=Zrs(3);}break;case 1:if(ZcF2(C)){Zf91(((Zy3*)ZUb),((C)->Zmm));
ZIi=Zrs(2);}else if((((C)->_cc))==(((T3)'\054'))){{ZK9*C1=C;T0*b1=ZYE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));
}else if((((C)->_cc))==(((T3)'\175'))){{ZK9*C1=C;T0*b1=ZzG2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\175'))));
ZIi=Zrs(4);}else{ZIi=Zrs(3);}break;case 2:if(ZYD2(C,((T3)'\054'))){ZIi=Zrs(1);}else if(ZYD2(C,((T3)'\175'))){ZIi=Zrs(4);}else if(ZcF2(C)){
ZHD2((((T80*)(((C)->Zmm)))->Zxb),ZZE2);Zf91(((Zy3*)ZUb),((C)->Zmm));}else{ZIi=Zrs(3);}break;default:;ZzD2(C,ZNE2);ZIi=Zrs(4);}}}{ZD*n=((ZD*)Zh(sizeof(*n)));
*n=ZWb;ZJF(n,_sp,ZUb);R=((T0*)n);}}else{R=ZPD2();}return R;}T6 ZPE2(ZK9*C){T6 R=0;T2 ZAG2=0;T6 ZSY1=0;T6 ZBG2=0;T6 ZCG2=0;if(Zss(((C)->_cc))){
ZAG2=((C)->ZWe);ZBG2=((T6)(1));{T76 Z3w;Zdq2(&(((C)->Z2f)),(*(Z3w=ZBD2(C,((C)->ZXe),ZAG2),&Z3w)));}{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);
}while(!(ZSY1)){ZsD2(C);{int z1=((C)->_cc);switch(z1){case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case
106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case
121:case 122:{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case
74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:ZCG2=((T6)(1));
{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}break;case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 95:
ZBG2=((T6)(0));{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}break;default:;ZSY1=((T6)(1));}}}if((T6)((ZBG2)&&((T6)(Zby2(&(((C)->Z2f))))))){
(C->_cc)=(((((T7*)Zeq2))->ZPb))[Zrs(0)];(C->ZWe)=ZAG2;}else{R=((T6)(1));ZpD2(C);if(ZCG2){if(!(((C)->Zbm))){ZHD2(((((C)->Z2f)).Zxb),ZDG2);
}}}}return R;}T0*Z9F2(ZK9*C){T0*R=Zo;if(ZJD2(C)){if(ZMD2(C)){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->Zom)),&Z3w)));}{T0*b1=ZvF(35,"Current is not a writable variable.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else if(ZRD2(C)){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->Zom)),&Z3w)));}{T0*b1=ZEG2;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));
}else if((T6)((ZKD2(C))||((T6)(ZTD2(C))))){R=((C)->Zom);}else{R=ZMy2(&(((C)->Z2f)));}}else{ZzD2(C,ZFG2);}return R;}T6 ZvF2(ZK9*C,T6 a1){
T6 R=0;T6 ZSY1=0;T2 _l=0;T2 _c=0;{int z1=((C)->_cc);switch(z1){case 35:case 38:case 42:case 43:case 45:case 47:case 60:case 61:case 62:
case 64:case 92:case 124:case 126:_l=((C)->ZXe);_c=((C)->ZWe);((((T7*)((T7*)(ZqE2))))->Zcc)=(Zrs(0));R=((T6)(1));ZZs((T7*)(ZqE2),((C)->_cc));
ZsD2(C);while(!(ZSY1)){{int z2=((C)->_cc);switch(z2){case 46:case 63:case 123:case 125:R=((T6)(0));ZZs((T7*)(ZqE2),((C)->_cc));ZsD2(C);
break;case 35:case 38:case 42:case 43:case 45:case 47:case 60:case 61:case 62:case 64:case 92:case 94:case 124:case 126:R=((T6)(1));ZZs((T7*)(ZqE2),((C)->_cc));
ZsD2(C);break;default:;ZSY1=((T6)(1));}}}if(!(R)){{T76 Z3w;ZzF((*(Z3w=ZBD2(C,((C)->ZXe),((C)->ZWe)),&Z3w)));}{T0*b1=ZGG2;ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}if((T6)((((((T7*)(ZqE2))->Zcc))==(Zrs(1)))&&((T6)((((((T7*)(ZqE2))->ZPb))[Zrs(0)])==(((T3)'\075')))))){{T76 Z3w;ZzF((*(Z3w=ZBD2(C,_l,_c),&Z3w)));
}{T0*b1=ZvF(92,"The basic = operator cannot be redefined. (This is a hard-coded builtin that we must trust.)");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));
}Z5F2(C,(T6)(a1),_l,_c);break;}}return R;}void ZDD2(ZK9*C){T0*Zkc=Zo;T0*ZJe=Zo;T0*Z3E2=Zo;T0*ZUb=Zo;T2 Zoe=0;T2 ZIi=0;while(!((Z3)((ZIi)>(Zrs(4)))))
{{int z1=ZIi;switch(z1){case 0:if(ZJD2(C)){Zkc=ZLy2(&(((C)->Z2f)));ZIi=Zrs(1);if((((C)->ZAb))!=((void*)(Zo))){Zoe=ZJ71((ZH6*)(((C)->ZAb)),((((Zz4*)Zkc))->Zre));
if((Z3)((Zoe)>(Zrs(0)))){ZzF(((((Zz4*)Zkc))->Zxb));ZlA2((((Zi1*)(Zuy(((Zn2*)((((ZH6*)(((C)->ZAb)))->Zhe))),Zoe)))->Zxb),ZHG2);}}}else
if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\073')))))){{ZK9*C1=C;T0*b1=Z4E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}(C->_ok)=((T6)((T6)((ZYD2(C,((T3)'\054')))||((T6)(ZYD2(C,((T3)'\073')))))));}else{ZIi=Zrs(5);}break;case 1:if(ZYD2(C,((T3)'\072'))){
if((ZJe)!=((void*)(Zo))){ZsA(((Zt8*)ZJe),Zkc);Zkc=Zo;}ZIi=Zrs(3);}else{if((((C)->_cc))==(((T3)'\073'))){{ZK9*C1=C;T0*b1=ZIG2;{T76 Z3w;
ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));}else{(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}if((ZJe)==((void*)(Zo))){
{Zt8*n=((Zt8*)Zh(sizeof(*n)));*n=Z0l;ZuA(n,(T2)(Zrs(2)),(T2)(Zrs(1)));ZJe=((T0*)n);}}ZsA(((Zt8*)ZJe),Zkc);Zkc=Zo;ZIi=Zrs(2);}break;case
2:if(ZJD2(C)){Zkc=ZLy2(&(((C)->Z2f)));ZIi=Zrs(1);if((((C)->ZAb))!=((void*)(Zo))){Zoe=ZJ71((ZH6*)(((C)->ZAb)),((((Zz4*)Zkc))->Zre));if((Z3)((Zoe)>(Zrs(0)))){
ZzF(((((Zz4*)Zkc))->Zxb));ZzF((((Zi1*)(Zuy(((Zn2*)((((ZH6*)(((C)->ZAb)))->Zhe))),Zoe)))->Zxb));{T0*b1=ZHG2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));
}}}else if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\073')))))){{ZK9*C1=C;T0*b1=Z4E2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}(C->_ok)=((T6)((T6)((ZYD2(C,((T3)'\054')))||((T6)(ZYD2(C,((T3)'\073')))))));}else{ZIi=Zrs(6);}break;case 3:if(Z5E2(C)){if((ZJe)!=((void*)(Zo))){
{ZS3*n=((ZS3*)Zh(sizeof(*n)));*n=ZKe;Zxa1(n,ZJe,((C)->Zzm));Z3E2=((T0*)n);}ZJe=Zo;}else{{Z_*n=((Z_*)Zh(sizeof(*n)));*n=Zlc;Z1K(n,Zkc,((C)->Zzm));
Z3E2=((T0*)n);}Zkc=Zo;}if((ZUb)==((void*)(Zo))){{Z5a*n=((Z5a*)Zh(sizeof(*n)));*n=Z_m;ZjB(n,(T2)(Zrs(2)),(T2)(Zrs(1)));ZUb=((T0*)n);}}
Z6E2(ZUb,Z3E2);ZIi=Zrs(4);}else{ZIi=Zrs(6);}break;default:;if((((C)->_cc))==(((T3)'\054'))){{ZK9*C1=C;T0*b1=ZJG2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));ZIi=Zrs(0);}else{(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));ZIi=Zrs(0);}}}}if((ZIi)==(Zrs(6))){ZzD2(C,ZvF(24,"Bad local variable list."));
}else if((ZUb)!=((void*)(Zo))){{Zo3*n=((Zo3*)Zh(sizeof(*n)));*n=Zie;{Zo3*C1=n;T0*b1=ZUb;ZR61(C1,b1);}(C->ZFb)=((T0*)n);}((((ZA7*)(&(((C)->ZBm)))))->ZFb)=(((C)->ZFb));
}}void ZwF2(ZK9*C){{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZJg2(n,((C)->Zqm));(C->Zqm)=((T0*)n);}}void Z8F2(T0*a1){if(Zs41(a1)){if(ZtY(a1)){
}else{{T76 Z3w;ZHD2((*(Z3w=Z3L(a1),&Z3w)),ZvF(58,"Explicit creation/create type mark should not be anchored."));}}}}void Z6L(ZK9*C){(C->Zcm)=((T6)(0));
Zb32((T72*)(ZoD2()));}T6 ZzF2(ZK9*C){T6 R=0;T2 _l=0;T2 _c=0;_l=((C)->ZXe);_c=((C)->ZWe);if(ZYD2(C,((T3)'\053'))){if(Z2G2(C,(T6)(0))){
R=((T6)(1));}else{ZbE2(C,_l,_c);}}else if(ZYD2(C,((T3)'\055'))){if(Z2G2(C,(T6)(1))){R=((T6)(1));}else{ZbE2(C,_l,_c);}}else if(Z2G2(C,(T6)(0))){
R=((T6)(1));}return R;}T6 ZbF2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};T0*ZYl=Zo;T0*ZKG2=Zo;T0*ZIw2=Zo;T0*ZLG2=Zo;R=((T6)(1));if(ZqD2(C,ZeP)){
{T76 Z3w;{Zk3*n=((Zk3*)Zh(sizeof(*n)));*n=Zge;ZNK(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);}}}else if(ZqD2(C,ZfP)){
{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if((T6)(((T6)((ZYD2(C,((T3)'\133')))&&((T6)(Z5E2(C)))))&&((T6)(ZYD2(C,((T3)'\135')))))){
{Ze7*n=((Ze7*)Zh(sizeof(*n)));*n=ZEj;ZOb1(n,_sp,((C)->Zzm));(C->Zim)=((T0*)n);}}else{ZzD2(C,ZvF(33,"Bad use of predefined type ARRAY."));
}}else if(ZqD2(C,ZAP)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if((T6)(((T6)((ZYD2(C,((T3)'\133')))&&((T6)(Z5E2(C)))))&&((T6)(ZYD2(C,((T3)'\135')))))){
{Z58*n=((Z58*)Zh(sizeof(*n)));*n=Zxk;Zi_1(n,_sp,((C)->Zzm));(C->Zim)=((T0*)n);}}else{ZzD2(C,ZvF(40,"Bad use of predefined type NATIVE_ARRAY."));
}}else if(ZqD2(C,ZiP)){{T76 Z3w;{Zf8*n=((Zf8*)Zh(sizeof(*n)));*n=ZCk;ZC11(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZkP)){{T76 Z3w;{Zc7*n=((Zc7*)Zh(sizeof(*n)));*n=ZBj;Zig1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZnP)){{T76 Z3w;{ZR8*n=((ZR8*)Zh(sizeof(*n)));*n=Zcl;Zg52(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZEP)){{T76 Z3w;ZUE2(C,((T0*)ZJQ1((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)))));}}else if(ZqD2(C,ZjP)){{T76 Z3w;ZUE2(C,((T0*)ZZl2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)))));
}}else if(ZqD2(C,ZlP)){{T76 Z3w;ZUE2(C,((T0*)ZOJ1((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)))));}}else if(ZqD2(C,ZyP)){{T76 Z3w;ZUE2(C,((T0*)ZLk2((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)))));
}}else if(ZqD2(C,ZLP)){{T76 Z3w;ZUE2(C,((T0*)ZJC1((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)))));}}else if(ZqD2(C,ZoP)){{T76 Z3w;ZUE2(C,((T0*)Zf52((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)))));
}}else if(ZqD2(C,ZwP)){{T76 Z3w;{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;ZMm1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZtP)){{T76 Z3w;{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;Ztl1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZuP)){{T76 Z3w;{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;Zul1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZvP)){{T76 Z3w;{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;Zvl1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZxP)){{T76 Z3w;{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;Zwl1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZsP)){{T76 Z3w;{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;ZYk2(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZBP)){{T76 Z3w;{Z67*n=((Z67*)Zh(sizeof(*n)));*n=Zxj;ZJe1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZDP)){{T76 Z3w;{ZC7*n=((ZC7*)Zh(sizeof(*n)));*n=Z2k;Z3c1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZJP)){{T76 Z3w;{Zv6*n=((Zv6*)Zh(sizeof(*n)));*n=ZXi;ZKC1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZNP)){{T76 Z3w;{ZN6*n=((ZN6*)Zh(sizeof(*n)));*n=Zdj;ZKE1(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));(C->Zim)=((T0*)n);
}}}else if(ZqD2(C,ZQP)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZYD2(C,((T3)'\133'))){if((((C)->_cc))==(((T3)'\135'))){
{ZK9*C1=C;T0*b1=ZeF2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}if(ZYD2(C,((T3)'\135'))){}}else{{ZY*n=((ZY*)Zh(sizeof(*n)));*n=Zjc;ZSx(n,(T2)(Zrs(4)),(T2)(Zrs(1)));
ZYl=((T0*)n);}while(!(ZYD2(C,((T3)'\135')))){if(Z5E2(C)){ZQx(((ZY*)ZYl),((C)->Zzm));if(!(ZYD2(C,((T3)'\054')))){if((((C)->_cc))!=(((T3)'\135'))){
{ZK9*C1=C;T0*b1=ZZE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}}}else{{T76 Z3w;ZzF((*(Z3w=ZmA2(C),&Z3w)));}{T0*b1=ZvF(32,"Incorrect TUPLE (type expected).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}}}{Zy7*n=((Zy7*)Zh(sizeof(*n)));*n=Z0k;Z2d1(n,_sp,ZYl);(C->Zim)=((T0*)n);}}else if(ZqD2(C,ZMP)){
{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(!(ZYD2(C,((T3)'\133')))){ZzD2(C,ZMG2);}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZKG2=((C)->Zzm);
if(!(ZYD2(C,((T3)'\054')))){{ZK9*C1=C;T0*b1=ZZE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZIw2=((C)->Zzm);
if(!(ZYD2(C,((T3)'\135')))){ZzD2(C,ZNG2);}{ZW9*n=((ZW9*)Zh(sizeof(*n)));*n=ZMm;{ZW9*C1=n;T76 b1=_sp;T0*b2=ZKG2;T0*b3=ZIw2;Z_I1(C1,ZGP,b1,b2,b3);
}(C->Zim)=((T0*)n);}}else if(ZqD2(C,ZGP)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(!(ZYD2(C,((T3)'\133')))){ZzD2(C,ZMG2);
}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZKG2=((C)->Zzm);if(!(ZYD2(C,((T3)'\054')))){{ZK9*C1=C;T0*b1=ZZE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZIw2=((C)->Zzm);if(!(ZYD2(C,((T3)'\135')))){ZzD2(C,ZNG2);}{ZW9*n=((ZW9*)Zh(sizeof(*n)));*n=ZMm;{ZW9*C1=n;
T76 b1=_sp;T0*b2=ZKG2;T0*b3=ZIw2;Z_I1(C1,ZGP,b1,b2,b3);}(C->Zim)=((T0*)n);}}else if(ZqD2(C,ZFP)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(!(ZYD2(C,((T3)'\133')))){ZzD2(C,ZMG2);}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZKG2=((C)->Zzm);if(!(ZYD2(C,((T3)'\054')))){{ZK9*C1=C;T0*b1=ZZE2;
{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZIw2=((C)->Zzm);if(!(ZYD2(C,((T3)'\135')))){ZzD2(C,ZNG2);}{Zs7*n=((Zs7*)Zh(sizeof(*n)));
*n=ZXj;Z0J1(n,_sp,ZKG2,ZIw2,Zo);(C->Zim)=((T0*)n);}}else if(ZqD2(C,ZrP)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(!(ZYD2(C,((T3)'\133')))){
ZzD2(C,ZMG2);}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZKG2=((C)->Zzm);if(!(ZYD2(C,((T3)'\054')))){{ZK9*C1=C;T0*b1=ZZE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZIw2=((C)->Zzm);if(!(ZYD2(C,((T3)'\054')))){{ZK9*C1=C;T0*b1=ZZE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}if(!(Z5E2(C))){ZzD2(C,ZJF2);}ZLG2=((C)->Zzm);if(!(ZYD2(C,((T3)'\135')))){ZzD2(C,ZNG2);}{Zs7*n=((Zs7*)Zh(sizeof(*n)));*n=ZXj;Z0J1(n,_sp,ZKG2,ZIw2,ZLG2);
(C->Zim)=((T0*)n);}}else{R=((T6)(0));}return R;}T6 ZPF2(ZK9*C){T6 R=0;T0*ZnE2=Zo;T0*ZLn1=Zo;if(ZJD2(C)){R=((T6)(1));ZLn1=ZMy2(&(((C)->Z2f)));
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Z5l;((((ZD8*)(n)))->Zxb)=(((((ZB8*)ZLn1))->Zxb));ZnE2=((T0*)n);}{ZQ1*n=((ZQ1*)Zh(sizeof(*n)));*n=Zfd;
ZvW(n,ZnE2,ZLn1);(C->Zom)=((T0*)n);}}else if(ZQE2(C)){R=((T6)(1));(C->Zom)=((C)->Zlm);}else if(ZzF2(C)){R=((T6)(1));(C->Zom)=((C)->Ztm);
}else if(ZyD2(C)){R=((T6)(1));(C->Zom)=((C)->Zrl);}else{ZzD2(C,ZIG);}return R;}void ZOG2(ZK9*C){T0*Z6G2=Zo;T0*ZPG2=Zo;T0*Zuk=Zo;T2 ZIi=0;
(C->Zjg)=Zo;if(ZYD2(C,((T3)'\133'))){{T76 Z3w;{Zba*n=((Zba*)Zh(sizeof(*n)));*n=Z2n;Z8k2(n,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));
(C->Zjg)=((T0*)n);}}((((T82*)((T82*)(((C)->Zem)))))->Zjg)=(((C)->Zjg));while(!((Z3)((ZIi)>(Zrs(3))))){{int z1=ZIi;switch(z1){case 0:if(ZcF2(C)){
ZPG2=((C)->Zmm);ZIi=Zrs(1);}else{ZIi=Zrs(5);}break;case 1:if(ZKE2(C,((T3)'\055'),((T3)'\076'))){ZIi=Zrs(3);}else if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\135')))))){
{Z38*n=((Z38*)Zh(sizeof(*n)));*n=Zvk;ZCZ1(n,ZPG2,Zuk);Z6G2=((T0*)n);}Zuk=Zo;Z9k2((Zba*)(((C)->Zjg)),Z6G2);{int z2=((C)->_cc);switch(z2){
case 44:ZIi=Zrs(0);break;default:;ZIi=Zrs(4);}}(C->_ok)=((T6)(ZYD2(C,((C)->_cc))));}else{ZIi=Zrs(5);}break;case 2:if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\135')))))){
{Z38*n=((Z38*)Zh(sizeof(*n)));*n=Zvk;ZCZ1(n,ZPG2,Zuk);Z6G2=((T0*)n);}Zuk=Zo;Z9k2((Zba*)(((C)->Zjg)),Z6G2);{int z2=((C)->_cc);switch(z2){
case 44:ZIi=Zrs(0);break;default:;ZIi=Zrs(4);}}(C->_ok)=((T6)(ZYD2(C,((C)->_cc))));}else{ZIi=Zrs(5);}break;default:;if(Z3G2(C)){Zuk=((C)->Zsm);
ZIi=Zrs(2);}else if(Z3F2(C)){Zuk=((C)->Znm);ZIi=Zrs(2);}else{ZzD2(C,ZvF(31,"Constraint Class name expected."));ZIi=Zrs(5);}}}}{int z1=ZIi;
switch(z1){case 4:if((Ztx(((ZB*)((((Zba*)(((C)->Zjg)))->ZUb)))))==(Zrs(0))){ZzF((((Zba*)(((C)->Zjg)))->Zxb));{T0*b1=ZvF(36,"Empty formal generic list (deleted).");
ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));(C->Zjg)=Zo;((((T82*)((T82*)(((C)->Zem)))))->Zjg)=(Zo);}break;default:;}}}}T6 ZTD2(ZK9*C){T6 R=0;
T2 Zoe=0;if((((C)->ZFb))!=((void*)(Zo))){Zoe=Zy61((Zo3*)(((C)->ZFb)),Z6y2(&(((C)->Z2f))));if((Z3)((Zoe)>(Zrs(0)))){(C->Zom)=ZKy2(&(((C)->Z2f)),((C)->ZFb),Zoe);
R=((T6)(1));}}return R;}void ZQG2(ZK9*C,T2 a1,T2 a2){T1 ZSC2=0;T11 Zde=0;T6 ZSY1=0;T6 ZTw=0;ZsD2(C);{int z1=((C)->_cc);switch(z1){case
48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:Zde=(T11)(Zus(((C)->_cc)));break;case 56:case 57:case 65:case 66:case 67:case
68:case 69:case 70:case 97:case 98:case 99:case 100:case 101:case 102:ZTw=((T6)(1));Zde=(T11)((Z1)(((ZBs(((C)->_cc))))-(Zrs(8))));break;
default:;ZzD2(C,ZvF(27,"Hexadecimal digit expected."));}}ZSC2=Zrs(1);while(!(ZSY1)){ZsD2(C);if(Zms(((C)->_cc))){Zde=(Z5)((((Z5)(((Zde))*(Zrs(16)))))+((T11)(ZBs(((C)->_cc)))));
ZSC2=(Z1)(((ZSC2))+(Zrs(1)));}else{ZSY1=((T6)(1));}}{int z1=ZSC2;switch(z1){case 2:case 4:case 8:case 16:break;default:;{T0*b1=ZvF(68,"Incorrect hexadecimal notation. Wrong number of hexadecimal digits (");
ZXw((T7*)(ZwF),b1);}{T2 b1=(T2)(ZSC2);ZQs(b1,ZwF);}ZzD2(C,ZvF(289," digits). You must use exactely 2, 4, 8 or 16 digits only. A 2 digits value denote an INTEGER_8, a 4 digits value denote an INTEGER_16, a 8 digits value denote an INTEGER_32, and, finally, a 16 digits value denote an INTEGER_64. (See examples in file \"SmartEiffel/tutorial/hexadecimal.e\".)"));
}}if(Zss(((C)->_cc))){ZzD2(C,ZvF(47,"Separator expected to end hexadecimal notation."));}{T76 Z3w;{Zs1*n=((Zs1*)Zh(sizeof(*n)));*n=ZIl;
ZQl1(n,(T6)(ZTw),ZSC2,Zde,(*(Z3w=ZBD2(C,a1,a2),&Z3w)));(C->Ztm)=((T0*)n);}}ZpD2(C);}T0*ZCF2(void){if(ZBk1==0){ZBk1=1;{{T40*n=((T40*)Zh(sizeof(*n)));
*n=M40;ZAk1=((T0*)n);ZTY(n);}}}return ZAk1;}T6 Z2G2(ZK9*C,T6 a1){T6 R=0;T2 ZIi=0;T2 _l=0;T2 _c=0;T11 Zde=0;T6 ZHl=0;T6 ZGl=0;if(Zjs(((C)->_cc))){
_l=((C)->ZXe);_c=((C)->ZWe);Zde=(T11)(-(Zps(((C)->_cc))));while(!((Z3)((ZIi)>(Zrs(7))))){ZsD2(C);{int z1=ZIi;switch(z1){case 0:{int z2=((C)->_cc);
switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zde=(Z5)((((Z5)(((Zde))*(Zrs(10)))))-((T11)(Zps(((C)->_cc)))));
ZIi=Zrs(1);break;case 95:ZIi=Zrs(4);break;case 120:if((Zde)==(Zrs(0))){ZGl=((T6)(1));}ZIi=Zrs(8);break;default:;ZIi=Zrs(8);}}break;case
1:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zde=(Z5)((((Z5)(((Zde))*(Zrs(10)))))-((T11)(Zps(((C)->_cc)))));
ZIi=Zrs(2);break;case 95:ZIi=Zrs(4);break;default:;ZIi=Zrs(8);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case
51:case 52:case 53:case 54:case 55:case 56:case 57:Zde=(Z5)((((Z5)(((Zde))*(Zrs(10)))))-((T11)(Zps(((C)->_cc)))));ZIi=Zrs(3);break;case
95:ZIi=Zrs(4);break;default:;ZIi=Zrs(8);}}break;case 3:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:
case 54:case 55:case 56:case 57:Zde=(Z5)((((Z5)(((Zde))*(Zrs(10)))))-((T11)(Zps(((C)->_cc)))));break;case 95:ZzD2(C,ZEF2);break;default:;
ZIi=Zrs(8);}}break;case 4:ZHl=((T6)(1));{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:
case 56:case 57:Zde=(Z5)((((Z5)(((Zde))*(Zrs(10)))))-((T11)(Zps(((C)->_cc)))));ZIi=Zrs(5);break;default:;ZzD2(C,ZEF2);}}break;case 5:
{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zde=(Z5)((((Z5)(((Zde))*(Zrs(10)))))-((T11)(Zps(((C)->_cc)))));
ZIi=Zrs(6);break;default:;ZzD2(C,ZEF2);}}break;case 6:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case
54:case 55:case 56:case 57:Zde=(Z5)((((Z5)(((Zde))*(Zrs(10)))))-((T11)(Zps(((C)->_cc)))));ZIi=Zrs(7);break;default:;ZzD2(C,ZEF2);}}break;
default:;{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZzD2(C,ZEF2);break;
case 95:ZIi=Zrs(4);break;default:;ZIi=Zrs(8);}}}}}if(ZGl){R=((T6)(1));ZQG2(C,_l,_c);}else if(Zss(((C)->_cc))){ZbE2(C,_l,_c);}else{R=((T6)(1));
ZpD2(C);{T76 Z3w;{Zs1*n=((Zs1*)Zh(sizeof(*n)));*n=ZIl;Zxl1(n,(T6)(ZHl),(T6)(a1),Zde,(*(Z3w=ZBD2(C,_l,_c),&Z3w)));(C->Ztm)=((T0*)n);}}
}}return R;}T6 ZOE2(ZK9*C){T6 R=0;T2 ZAG2=0;T6 ZSY1=0;if(Zss(((C)->_cc))){ZAG2=((C)->ZWe);{T76 Z3w;Zdq2(&(((C)->Z2f)),(*(Z3w=ZBD2(C,((C)->ZXe),ZAG2),&Z3w)));
}{T3 b1=Zys(((C)->_cc));ZZs((T7*)(Zeq2),b1);}while(!(ZSY1)){ZsD2(C);{int z1=((C)->_cc);switch(z1){case 97:case 98:case 99:case 100:case
101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case
116:case 117:case 118:case 119:case 120:case 121:case 122:{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}break;case 48:case 49:case 50:case 51:
case 52:case 53:case 54:case 55:case 56:case 57:case 95:{T3 b1=((C)->_cc);ZZs((T7*)(Zeq2),b1);}break;case 65:case 66:case 67:case 68:
case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:
case 86:case 87:case 88:case 89:case 90:{T3 b1=Zys(((C)->_cc));ZZs((T7*)(Zeq2),b1);}break;default:;ZSY1=((T6)(1));}}}if(Zby2(&(((C)->Z2f)))){
(C->_cc)=(((((T7*)Zeq2))->ZPb))[Zrs(0)];(C->ZWe)=ZAG2;}else{R=((T6)(1));ZpD2(C);}}return R;}void Z5F2(ZK9*C,T6 a1,T2 a2,T2 a3){T0*ZRG2=Zo;
ZRG2=(((void)((T26*)(ZtD2()))),ZAS(ZqE2));if(a1){{T76 Z3w;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z_91(n,ZRG2,(*(Z3w=ZBD2(C,a2,a3),&Z3w)));
(C->Zqm)=((T0*)n);}}}else{{T76 Z3w;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,ZRG2,(*(Z3w=ZBD2(C,a2,a3),&Z3w)));(C->Zqm)=((T0*)n);}}}
}void ZgG2(ZK9*C,T0*a1){T0*ZSG2=Zo;T76 _sp={Zo,Zo,0};if(ZqD2(C,ZaQ)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZfG2(C)){
{Zu3*n=((Zu3*)Zh(sizeof(*n)));*n=Zte;ZW81(n,a1,_sp,((C)->Zom));ZSG2=((T0*)n);}ZgG2(C,ZSG2);}else{ZlA2(_sp,ZvF(36,"Expression expected after \'implies\'."));
}}else{(C->Zom)=a1;}}void ZiG2(ZK9*C,T0*a1){T0*ZTG2=Zo;T0*ZUG2=Zo;T0*ZVG2=Zo;T76 _sp={Zo,Zo,0};if(ZqD2(C,ZiQ)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(ZqD2(C,Zo71)){if(ZhG2(C)){{ZM9*n=((ZM9*)Zh(sizeof(*n)));*n=ZDm;Zhi2(n,a1,_sp,((C)->Zom));ZTG2=((T0*)n);}ZiG2(C,ZTG2);}else{ZdG2(_sp,(T6)(0),ZjQ);
}}else{if(ZhG2(C)){{Z83*n=((Z83*)Zh(sizeof(*n)));*n=Z6e;Zi51(n,a1,_sp,((C)->Zom));ZUG2=((T0*)n);}ZiG2(C,ZUG2);}else{ZdG2(_sp,(T6)(0),ZiQ);
}}}else if(ZqD2(C,ZDG)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZhG2(C)){{ZH*n=((ZH*)Zh(sizeof(*n)));*n=Z1c;ZBG(n,a1,_sp,((C)->Zom));
ZVG2=((T0*)n);}ZiG2(C,ZVG2);}else{ZdG2(_sp,(T6)(0),ZDG);}}else{(C->Zom)=a1;}}void ZkG2(ZK9*C,T0*a1){T0*ZWG2=Zo;T0*ZXG2=Zo;T76 _sp={Zo,Zo,0};
if(ZqD2(C,ZTP)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZqD2(C,ZDy2)){if(ZjG2(C)){{Z12*n=((Z12*)Zh(sizeof(*n)));
*n=Zod;ZcX(n,a1,_sp,((C)->Zom));ZWG2=((T0*)n);}ZkG2(C,ZWG2);}else{ZdG2(_sp,(T6)(0),ZUP);}}else{if(ZjG2(C)){{Z09*n=((Z09*)Zh(sizeof(*n)));
*n=Zul;Zs62(n,a1,_sp,((C)->Zom));ZXG2=((T0*)n);}ZkG2(C,ZXG2);}else{ZdG2(_sp,(T6)(0),ZTP);}}}else{(C->Zom)=a1;}}void ZmG2(ZK9*C,T0*a1){
T0*ZYG2=Zo;T76 _sp={Zo,Zo,0};if(ZYD2(C,((T3)'\075'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZlG2(C)){{ZN2*n=((ZN2*)Zh(sizeof(*n)));
*n=ZRd;ZfW(n,a1,_sp,((C)->Zom));ZYG2=((T0*)n);}ZmG2(C,ZYG2);}else{ZdG2(_sp,(T6)(0),Z7Q);}}else if(ZKE2(C,((T3)'\057'),((T3)'\075'))){
{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZlG2(C)){{ZC9*n=((ZC9*)Zh(sizeof(*n)));*n=Z6m;Zpg2(n,a1,_sp,((C)->Zom));
ZYG2=((T0*)n);}ZmG2(C,ZYG2);}else{ZdG2(_sp,(T6)(0),ZgQ);}}else if(ZKE2(C,((T3)'\074'),((T3)'\075'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(ZlG2(C)){{ZV2*n=((ZV2*)Zh(sizeof(*n)));*n=ZXd;Zi31(n,a1,_sp,((C)->Zom));ZYG2=((T0*)n);}ZmG2(C,ZYG2);}else{ZdG2(_sp,(T6)(0),ZbQ);}
}else if(ZKE2(C,((T3)'\076'),((T3)'\075'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZlG2(C)){{ZL2*n=((ZL2*)Zh(sizeof(*n)));
*n=ZQd;ZA01(n,a1,_sp,((C)->Zom));ZYG2=((T0*)n);}ZmG2(C,ZYG2);}else{ZdG2(_sp,(T6)(0),Z8Q);}}else if(ZYD2(C,((T3)'\074'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(ZlG2(C)){{ZZ2*n=((ZZ2*)Zh(sizeof(*n)));*n=Z_d;ZQ31(n,a1,_sp,((C)->Zom));ZYG2=((T0*)n);}ZmG2(C,ZYG2);}else{ZdG2(_sp,(T6)(0),ZcQ);}
}else if(Z4G2(C,((T3)'\076'),((T3)'\076'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZlG2(C)){{ZR2*n=((ZR2*)Zh(sizeof(*n)));
*n=ZVd;ZL21(n,a1,_sp,((C)->Zom));ZYG2=((T0*)n);}ZmG2(C,ZYG2);}else{ZdG2(_sp,(T6)(0),Z9Q);}}else{(C->Zom)=a1;}}void ZoG2(ZK9*C,T0*a1){
T0*ZZG2=Zo;T0*Z_G2=Zo;T76 _sp={Zo,Zo,0};if(ZYD2(C,((T3)'\053'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZnG2(C)){
{ZC5*n=((ZC5*)Zh(sizeof(*n)));*n=Zph;Zrm1(n,a1,_sp,((C)->Zom));ZZG2=((T0*)n);}ZoG2(C,ZZG2);}else{ZdG2(_sp,(T6)(0),ZkQ);}}else if(ZYD2(C,((T3)'\055'))){
{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZnG2(C)){{ZS*n=((ZS*)Zh(sizeof(*n)));*n=Z7c;ZcJ(n,a1,_sp,((C)->Zom));Z_G2=((T0*)n);
}ZoG2(C,Z_G2);}else{ZdG2(_sp,(T6)(0),ZdJ);}}else{(C->Zom)=a1;}}void ZqG2(ZK9*C,T0*a1){T0*Z0H2=Zo;T0*Z1H2=Zo;T0*Z2H2=Zo;T0*Z3H2=Zo;T76
_sp={Zo,Zo,0};if(ZYD2(C,((T3)'\052'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZpG2(C)){{ZJ4*n=((ZJ4*)Zh(sizeof(*n)));
*n=Zzg;Z0f1(n,a1,_sp,((C)->Zom));Z0H2=((T0*)n);}ZqG2(C,Z0H2);}else{ZdG2(_sp,(T6)(0),ZeQ);}}else if(ZKE2(C,((T3)'\057'),((T3)'\057'))){
{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZpG2(C)){{Zw7*n=((Zw7*)Zh(sizeof(*n)));*n=ZZj;ZtQ1(n,a1,_sp,((C)->Zom));
Z1H2=((T0*)n);}ZqG2(C,Z1H2);}else{ZdG2(_sp,(T6)(0),ZqQ);}}else if(ZKE2(C,((T3)'\134'),((T3)'\134'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}if(ZpG2(C)){{ZF6*n=((ZF6*)Zh(sizeof(*n)));*n=Z6j;ZZD1(n,a1,_sp,((C)->Zom));Z2H2=((T0*)n);}ZqG2(C,Z2H2);}else{ZdG2(_sp,(T6)(0),ZWP);}
}else if(Z4G2(C,((T3)'\057'),((T3)'\075'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZpG2(C)){{Z89*n=((Z89*)Zh(sizeof(*n)));
*n=ZJl;ZM82(n,a1,_sp,((C)->Zom));Z3H2=((T0*)n);}ZqG2(C,Z3H2);}else{ZdG2(_sp,(T6)(0),ZpQ);}}else{(C->Zom)=a1;}}T0*ZAD2(ZK9*C){T0*R=Zo;
R=((C)->ZZe);(C->ZZe)=Zo;return R;}T0*Z5L(ZK9*C){T0*R=Zo;if(ZXE2(C)){R=((C)->Zqm);}else{ZzD2(C,Z0F2);}return R;}void Z8G2(T0*a1){ZzF(((((T88*)a1))->Zxb));
{T0*b1=ZvF(40,"Unknown external language specification.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZuG2(ZK9*C,T0*a1){T76 _sp={Zo,Zo,0};
if(ZYD2(C,((T3)'\136'))){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(ZtG2(C)){ZuG2(C,((C)->Zom));{ZI9*n=((ZI9*)Zh(sizeof(*n)));
*n=Z9m;ZMh2(n,a1,_sp,((C)->Zom));(C->Zom)=((T0*)n);}}else{ZdG2(_sp,(T6)(0),ZmQ);}}else{(C->Zom)=a1;}}T6 Z_F2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};
T0*ZBb=Zo;T0*Z7F2=Zo;T0*Zyd=Zo;T0*ZXz2=Zo;if(ZqD2(C,ZmY)){R=((T6)(1));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}if(!(ZYD2(C,((T3)'\173')))){
ZzD2(C,ZvF(37,"Bad create expression (\'\173""\' expected)."));}if(!(Z5E2(C))){ZzD2(C,ZvF(39,ZVo));}ZBb=((C)->Zzm);Z8F2(ZBb);if(!(ZYD2(C,((T3)'\175')))){
ZzD2(C,ZvF(37,"Bad create expression (\'\175""\' expected)."));}if(ZYD2(C,((T3)'\056'))){if(ZJD2(C)){Z7F2=ZMy2(&(((C)->Z2f)));{Z56*n=((Z56*)Zh(sizeof(*n)));
*n=Z_h;((((Z56*)(n)))->Zgc)=(ZBb);ZXz2=((T0*)n);}if((((C)->_cc))==(((T3)'\050'))){Zyd=ZTE2(C,ZXz2,Z7F2,ZND2(C));}else{{ZZ6*n=((ZZ6*)Zh(sizeof(*n)));
*n=Zkj;Zlp1(n,ZXz2,Z7F2);Zyd=((T0*)n);}}}}{Zj2*n=((Zj2*)Zh(sizeof(*n)));*n=Zzd;ZaY(n,_sp,ZBb,Zyd);(C->Zom)=((T0*)n);}}return R;}void ZwG2(ZK9*C,T0*a1){
T0*Z4H2=Zo;T0*Z5H2=Zo;if(Z4F2(C,(T6)(0))){Z4H2=((C)->Zqm);if(ZvG2(C)){{ZJ*n=((ZJ*)Zh(sizeof(*n)));*n=Z2c;ZSH(n,a1,Z4H2,((C)->Zom));Z5H2=((T0*)n);
}ZwG2(C,Z5H2);}else{ZdG2(((((ZB8*)Z4H2))->Zxb),(T6)(0),((((ZB8*)Z4H2))->Zre));}}else{(C->Zom)=a1;}}T6 ZdE2(ZK9*C){T6 R=0;T76 _sp={Zo,Zo,0};
T0*_hc=Zo;T0*_al=Zo;if(ZqD2(C,Zfq2)){{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}_hc=ZAD2(C);_al=ZCD2(C);if(!(ZqD2(C,ZEp2))){
ZzF(_sp);ZzD2(C,ZvF(50,"Keyword \"end\" expected at the end of check clause."));}if((T6)(((_hc)!=((void*)(Zo)))||((T6)((_al)!=((void*)(Zo)))))){
{ZP2*n=((ZP2*)Zh(sizeof(*n)));*n=ZUd;Zg21(n,_sp,_hc,_al);(C->Zum)=((T0*)n);}R=((T6)(1));}else if(ZYD2(C,((T3)'\073'))){}}return R;}T0*ZpE2=Zo;
T76 ZBD2(ZK9*C,T2 a1,T2 a2){T76 R={Zo,Zo,0};Z4j1(&R,a1,a2,((C)->Zdm),((C)->Zem));return R;}void Z6H2(ZK9*C,T76 a1,T0*a2){T0*ZUb=Zo;while(!(!(Z1F2(C))))
{if((ZUb)==((void*)(Zo))){{Z32*n=((Z32*)Zh(sizeof(*n)));*n=Zpd;Zgy(n,(T2)(Zrs(4)));ZUb=((T0*)n);}}Zfy(((Z32*)ZUb),((C)->Zxm));(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));
((((Zv2*)((Zv2*)(((C)->Zxm)))))->Zjd)=(ZAD2(C));}if((T6)(((a2)!=((void*)(Zo)))||((T6)((ZUb)!=((void*)(Zo)))))){if((ZUb)==((void*)(Zo))){
if(((((T82*)(((C)->Zem)))->Zkg))==((void*)(Zo))){((((T82*)((T82*)(((C)->Zem)))))->Zkg)=(a2);}else{ZMa1((T86*)((((T82*)(((C)->Zem)))->Zkg)),a2);
}}else{ZGk1((T82*)(((C)->Zem)),a1,a2,ZUb);}}}void ZlA2(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}void ZMF2(ZK9*C){
T76 _sp={Zo,Zo,0};T0*_hc=Zo;T0*_al=Zo;T6 Z7H2=0;T6 Z8H2=0;T6 Z9H2=0;ZSF2(C);Z9H2=((T6)(1));while(!(!(Z9H2))){if(ZqD2(C,Zhy2)){Zck1((T82*)(((C)->Zem)));
}else if(ZqD2(C,Zht1)){Zxj1((T82*)(((C)->Zem)));}else if(ZqD2(C,ZzS)){{T76 Z3w;ZzF((*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));}{T0*b1=ZvF(91,"Compiler limitation: separate classes are not yet supported. Use separate entities instead.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));Zkk1((T82*)(((C)->Zem)));}else{Z9H2=((T6)(0));}}((((T82*)((T82*)(((C)->Zem)))))->Zeg)=(ZAD2(C));
if(!(ZqD2(C,Zfy2))){ZzD2(C,ZvF(25,"Keyword \"class\" expected."));}ZaH2(C);ZOG2(C);if(ZqD2(C,Zuy2)){if(ZyD2(C)){((((T88*)((T88*)(((C)->Zrl)))))->ZOm)=((T6)(1));
((((T82*)((T82*)(((C)->Zem)))))->Zlg)=(((C)->Zrl));}else{ZzD2(C,ZvF(47,"Manifest string expected for \"obsolete\" clause."));}}((((T82*)((T82*)(((C)->Zem)))))->Zkg)=(ZAD2(C));
if(ZqD2(C,Zqy2)){Z8H2=((T6)(1));{T76 Z3w;Z6H2(C,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)),ZAD2(C));}}while(!(!((T6)((ZqD2(C,Zgy2))||((T6)(ZqD2(C,ZmY)))))))
{{T76 Z3w;ZDE2(C,(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w)));}Z8H2=((T6)(0));}while(!(!(ZqD2(C,Zmy2)))){ZrE2(C);Z8H2=((T6)(0));}Z7H2=((T6)(((C)->Z_e)));
(C->Z_e)=((T6)(0));if(ZqD2(C,Z5g1)){Z8H2=((T6)(0));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));}_hc=ZAD2(C);_al=ZCD2(C);
Zek1((T82*)(((C)->Zem)),_sp,_hc,_al);}if((T6)((ZqD2(C,ZEp2))||((T6)(Z8H2)))){(C->_ok)=((T6)(ZYD2(C,((T3)'\073'))));((((T82*)((T82*)(((C)->Zem)))))->ZEe)=(ZAD2(C));
if((((C)->_cc))!=(((T3)'\000'))){ZzD2(C,ZvF(21,"End of text expected."));}}else{ZzD2(C,ZvF(45,"Keyword \"end\" expected at the end of a class."));
}(C->Z_e)=((T6)(Z7H2));}T0*ZND2(ZK9*C){T0*R=Zo;T0*Z0j=Zo;T0*Z4e=Zo;if(ZYD2(C,((T3)'\050'))){while(!(!(ZIF2(C)))){if((Z0j)==((void*)(Zo))){
Z0j=((C)->Zom);}else{if((Z4e)==((void*)(Zo))){{ZB4*n=((ZB4*)Zh(sizeof(*n)));*n=Zbg;Zbz(n,(T2)(Zrs(4)));Z4e=((T0*)n);}}Z8z(((ZB4*)Z4e),((C)->Zom));
}if((T6)((!(ZYD2(C,((T3)'\054'))))&&((T6)((((C)->_cc))!=(((T3)'\051')))))){{ZK9*C1=C;T0*b1=ZZE2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);
}}}}if((Z0j)==((void*)(Zo))){{ZK9*C1=C;T0*b1=ZbH2;{T76 Z3w;ZHD2((*(Z3w=ZmA2(C1),&Z3w)),b1);}}}else{{Zm3*n=((Zm3*)Zh(sizeof(*n)));*n=Z1j;
ZAD1(n,Z0j,Z4e);R=((T0*)n);}}if(!(ZYD2(C,((T3)'\051')))){ZzD2(C,ZvF(35,"\')\' expected to end arguments list."));}}return R;}T6 ZUD2(ZK9*C){
T6 R=0;T76 _sp={Zo,Zo,0};T0*ZUb=Zo;if(ZKE2(C,((T3)'\074'),((T3)'\074'))){R=((T6)(1));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}while(!(!(ZUD2(C)))){if((ZUb)==((void*)(Zo))){{ZB4*n=((ZB4*)Zh(sizeof(*n)));*n=Zbg;Zbz(n,(T2)(Zrs(4)));ZUb=((T0*)n);}}Z8z(((ZB4*)ZUb),((C)->Zom));
(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}if(!(ZKE2(C,((T3)'\076'),((T3)'\076')))){ZzD2(C,ZvF(31,"End of manifest array expected."));}{Z76*n=((Z76*)Zh(sizeof(*n)));
*n=Z0i;ZxA1(n,_sp,ZUb);(C->Zom)=((T0*)n);}}else if(ZYD2(C,((T3)'\133'))){R=((T6)(1));{T76 Z3w;_sp=(*(Z3w=ZBD2(C,((C)->Z0f),((C)->Z1f)),&Z3w));
}while(!(!(ZUD2(C)))){if((ZUb)==((void*)(Zo))){{ZB4*n=((ZB4*)Zh(sizeof(*n)));*n=Zbg;Zbz(n,(T2)(Zrs(4)));ZUb=((T0*)n);}}Z8z(((ZB4*)ZUb),((C)->Zom));
(C->_ok)=((T6)(ZYD2(C,((T3)'\054'))));}if(!(ZYD2(C,((T3)'\135')))){ZzD2(C,ZvF(33,"End of TUPLE expression expected."));}{ZA5*n=((ZA5*)Zh(sizeof(*n)));
*n=Zoh;ZVl1(n,_sp,ZUb);(C->Zom)=((T0*)n);}}else{R=((T6)(ZeG2(C)));}return R;}void ZaH2(ZK9*C){T0*_cn=Zo;T0*_bc=Zo;_bc=((C)->Zem);_cn=((((T82*)_bc))->Zkc);
{T76 Z3w;((((T80*)(((T80*)_cn))))->Zxb)=((*(Z3w=ZBD2(C,((C)->ZXe),((C)->ZWe)),&Z3w)));}if(ZcF2(C)){if(((((T80*)(((C)->Zmm)))->Zre))!=((void*)(((((T80*)_cn))->Zre)))){
ZzF((((T80*)(((C)->Zmm)))->Zxb));{T0*b1=Zls1;ZXw((T7*)(ZwF),b1);}{T0*b1=((((T82*)_bc))->Zoc);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(26,"\" does not contain class \"");
ZXw((T7*)(ZwF),b1);}{T0*b1=((((T80*)_cn))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZwY;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}else{ZzD2(C,ZcH2);
}if((ZBP)==((void*)(((((T80*)_cn))->Zre)))){ZzF(((((T80*)_cn))->Zxb));{T0*b1=ZvF(26,"Cannot write such a class.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}}
#ifdef __cplusplus
}
#endif

