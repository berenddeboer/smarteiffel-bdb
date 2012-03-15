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
T0*Zel1(Zg5*C,T0*a1,T0*a2){T0*R=Zo;{ZM3*n=((ZM3*)Zh(sizeof(*n)));*n=ZFe;Zha1(n,a1,((C)->ZAb),((C)->ZEb),((C)->ZDe),a2);R=((T0*)n);}return
R;}void Zfl1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T6 Zgl1(Zg5*C,T0*a1,T0*a2){T6 R=0;if((Zo)!=((void*)(ZvH(a1)))){
{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;Zfl1((*(Z3w=Zhl1(C),&Z3w)),ZHJ);}}if((((C)->ZAb))!=((void*)(ZIJ(a1)))){if((T6)(((((C)->ZAb))==((void*)(Zo)))||((T6)((ZIJ(a1))==((void*)(Zo)))))){
{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;Zfl1((*(Z3w=Zhl1(C),&Z3w)),ZJJ);}}else if((Zty(((Zn2*)((((ZH6*)(((C)->ZAb)))->Zhe)))))!=(Zty(((Zn2*)((((ZH6*)(ZIJ(a1)))->Zhe)))))){
{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;Zfl1((*(Z3w=Zhl1(C),&Z3w)),Zla1);}}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){
if((((C)->ZAb))!=((void*)(Zo))){if(!(Zn81((ZH6*)(((C)->ZAb)),ZIJ(a1),a2))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;ZzF((*(Z3w=Zhl1(C),&Z3w)));
}{T0*b1=ZLJ;ZXw((T7*)(ZwF),b1);}{T0*b1=ZDF(((((Ze4*)a2))->Z0c));ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}
}}R=((T6)(((((T75*)(ZyF))->ZAg))==(Zrs(0))));if(R){Zil1(C,a1);}return R;}void Zil1(Zg5*C,T0*a1){if((((T41*)(Z1G))->ZJk)){if((((C)->ZCb))==((void*)(Zo))){
(C->ZCb)=ZOJ(a1);}else if((ZOJ(a1))==((void*)(Zo))){ZPJ(a1,((C)->ZCb));}}}void Zjl1(Zg5*C,T0*a1){T2 _i=0;T0*_fn=Zo;T0*_f=Zo;(C->Zqb)=(((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),Zrs(1))))->Zxb)).Zqb);
_i=Zrs(1);while(!((Z3)((_i)>(ZSJ((Zx8*)(((C)->Zfc))))))){_fn=ZRJ((Zx8*)(((C)->Zfc)),_i);_f=ZED(((Z25*)a1),_fn);if((_f)!=((void*)(Zo))){
_fn=((((Zx8*)(((((Z85*)_f))->Zfc))))->ZBd);ZzF(((((ZB8*)_fn))->Zxb));ZzF((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),_i)))->Zxb));{T0*b1=ZvF(29,"Double definition of feature ");
ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)_fn))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}else{ZBD(((Z25*)a1),(T0*)C,_fn);
}_i=(Z3)(((_i))+(Zrs(1)));}}void Zkl1(Zg5*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5){((((Zg5*)(C)))->Zfc)=(a1);(C->ZCb)=a4;(C->ZAb)=a2;(C->ZDb)=a3;
(C->ZEb)=a5;}T0*Zll1(Zg5*C,T0*a1,T0*a2){T0*R=Zo;T0*ZUJ=Zo;ZzF(((((ZB8*)a1))->Zxb));ZUJ=ZVJ((Zx8*)(((C)->Zfc)),((((ZB8*)a1))->Z3n));if((ZUJ)!=((void*)(Zo))){
ZWJ(((ZB8*)ZUJ),a2);}((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));R=Zel1(C,a1,a2);if((R)!=((void*)(Zo))){
((((ZM3*)(((ZM3*)R))))->Zec)=(((C)->Zec));Zil1(C,R);}else{ZEJ(((T82*)a2),a1);}return R;}void Zml1(Zg5*C,T0*a1,T0*a2,T0*a3,T0*a4,T0*a5,T0*a6,T0*a7){
Zkl1(C,a1,a2,a3,a4,a5);(C->ZFb)=a6;(C->ZGb)=a7;(C->Zah)=Zrs(34);}void Znl1(Zg5*C,T76 a1){if((((C)->ZDb))!=((void*)(Zo))){if(!((((T41*)(Z1G))->ZJk))){
ZzF(a1);{T0*b1=ZvF(27,"This feature is obsolete :\n");ZXw((T7*)(ZwF),b1);}{T0*b1=(((T88*)(((C)->ZDb)))->Zre);ZXw((T7*)(ZwF),b1);}{T76
Z3w;ZzF((*(Z3w=Zhl1(C),&Z3w)));}ZoK((T75*)(ZyF));}}}T0*Zol1(Zg5*C,T0*a1,T0*a2){T0*R=Zo;{ZM7*n=((ZM7*)Zh(sizeof(*n)));*n=Zck;Zpl1(n,a1,a2,(T0*)C);
R=((T0*)n);}return R;}void Zql1(Zg5*C,T0*a1){if((T6)(((a1)!=((void*)(Zo)))&&((T6)((Z3)((ZPA(((T74*)(((((T86*)a1))->ZUb)))))>(Zrs(1))))))){
(C->ZEe)=a1;}}T6 Zrl1(Zg5*C,T0*a1){T6 R=0;R=((T6)((ZvH(a1))!=((void*)(Zo))));if(R){{T0*b1=ZHJ;ZXw((T7*)(ZwF),b1);}}else{if((((C)->ZAb))==((void*)(Zo))){
R=((T6)((ZIJ(a1))!=((void*)(Zo))));}else{R=((T6)((ZIJ(a1))==((void*)(Zo))));}if(R){{T0*b1=ZJJ;ZXw((T7*)(ZwF),b1);}}else if((((C)->ZAb))==((void*)(Zo))){
}else if((Zty(((Zn2*)((((ZH6*)(((C)->ZAb)))->Zhe)))))!=(Zty(((Zn2*)((((ZH6*)(ZIJ(a1)))->Zhe)))))){{T0*b1=Zla1;ZXw((T7*)(ZwF),b1);}R=((T6)(1));
}}Zil1(C,a1);return R;}T76 Zhl1(Zg5*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((((Zx8*)(((C)->Zfc))))->ZBd)))->Zxb);return R;}void Zsl1(Zs1*C){{int
z1=((C)->ZFl);switch(z1){case 8:{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;Ztl1(n,((C)->Zxb));(C->Zgc)=((T0*)n);}break;case 16:{Zs5*n=((Zs5*)Zh(sizeof(*n)));
*n=Zjh;Zul1(n,((C)->Zxb));(C->Zgc)=((T0*)n);}break;case 32:{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;Zvl1(n,((C)->Zxb));(C->Zgc)=((T0*)n);
}break;default:;{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zjh;Zwl1(n,((C)->Zxb));(C->Zgc)=((T0*)n);}}}}void Zxl1(Zs1*C,T6 a1,T6 a2,T11 a3,T76 a4){
(C->ZHl)=((T6)(a1));(C->Zxb)=a4;if(a2){(C->ZEl)=a3;if((Z5)((((C)->ZEl))>=(Zht))){(C->ZFl)=Zrs(8);}else if((Z5)((((C)->ZEl))>=(Zet))){
(C->ZFl)=Zrs(16);}else if((Z5)((((C)->ZEl))>=(Zct))){(C->ZFl)=Zrs(32);}else{(C->ZFl)=Zrs(64);}}else{(C->ZEl)=-(a3);if((Z5)((((C)->ZEl))<=(Zrs(127)))){
(C->ZFl)=Zrs(8);}else if((Z5)((((C)->ZEl))<=(Zft(32767)))){(C->ZFl)=Zrs(16);}else if((Z5)((((C)->ZEl))<=(ZXs(2147483647)))){(C->ZFl)=Zrs(32);
}else{(C->ZFl)=Zrs(64);}}}T0*Zyl1=Zo;void Zzl1(Zs1*C){if(((C)->ZGl)){ZBw((T7*)(Zyl1),ZAl1);ZBl1(C,Zyl1);ZXw((T7*)(Zyl1),ZCl1);Z7I((Zi4*)(ZsG),Zyl1);
}if((((C)->ZEl))==(Zht)){Z7I((Zi4*)(ZsG),ZDl1);}else if((((C)->ZEl))==(Zet)){Z7I((Zi4*)(ZsG),ZEl1);}else if((((C)->ZEl))==(Zct)){Z7I((Zi4*)(ZsG),ZFl1);
}else if((((C)->ZEl))==(ZGl1)){Z7I((Zi4*)(ZsG),ZHl1);}else{Z7I((Zi4*)(ZsG),ZIl1);ZtI((Zi4*)(ZsG),(T11)(((C)->ZFl)));Z7I((Zi4*)(ZsG),ZJl1);
ZtI((Zi4*)(ZsG),((C)->ZEl));ZcH((Zi4*)(ZsG),((T3)'\051'));}}void ZKl1(Zs1*C){ZzF(((C)->Zxb));{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZxJ(Zs1*C,T11 a1,T76 a2){if((Z5)((a1)>=(Zrs(0)))){Zxl1(C,(T6)(0),(T6)(0),-(a1),a2);}else{Zxl1(C,(T6)(0),(T6)(1),a1,a2);
}Zsl1(C);}void ZBl1(Zs1*C,T0*a1){T2 _i=0;if(((C)->ZGl)){ZZs(((T7*)a1),((T3)'0'));ZZs(((T7*)a1),((T3)'x'));{int z1=((C)->ZFl);switch(z1){
case 8:ZHs(((Zqs)(((C)->ZEl))),a1);break;case 16:Zot(((ZLl1)(((C)->ZEl))),a1);break;case 32:Z1t(((ZWs)(((C)->ZEl))),a1);break;default:;
Zit(((C)->ZEl),a1);}}}else{Z9t(((C)->ZEl),a1);if(((C)->ZHl)){_i=(Z3)(((((((T7*)a1))->Zcc)))-(Zrs(2)));while(!((Z3)((_i)<=(Zrs(1))))){
ZHw(((T7*)a1),((T3)'\137'),_i);_i=(Z3)(((_i))-(Zrs(3)));}}}}T0*ZMl1(Zs1*C){T0*R=Zo;{Zy9*n=((Zy9*)Zh(sizeof(*n)));*n=Z4m;ZgW(n,((C)->Zxb),Z8t(((C)->ZEl)));
R=((T0*)n);}return R;}T6 ZNl1(T0*a1){T6 R=0;return R;}T0*ZOl1(Zs1*C,T0*a1){T0*R=Zo;R=((T0*)(C));if((((C)->Zgc))==((void*)(Zo))){Zsl1(C);
}return R;}T0*ZPl1(Zs1*C){T0*R=Zo;if((((C)->Zgc))!=((void*)(Zo))){R=ZbK(((C)->Zgc));}return R;}void ZQl1(Zs1*C,T6 a1,T1 a2,T11 a3,T76
a4){(C->ZGl)=((T6)(1));(C->ZEl)=a3;{int z1=a2;switch(z1){case 2:(C->ZFl)=Zrs(8);if(a1){(C->ZEl)=(T11)((((Zqs)(a3))|Zht));}break;case 4:
(C->ZFl)=Zrs(16);if(a1){(C->ZEl)=(T11)((((ZLl1)(a3))|Zet));}break;case 8:(C->ZFl)=Zrs(32);if(a1){(C->ZEl)=(T11)((((ZWs)(a3))|Zct));}break;
default:;(C->ZFl)=Zrs(64);if(a1){(C->ZEl)=(a3|ZGl1);}}}}T0*ZRl1(Zw5*C,T0*a1){T0*R=Zo;T2 _i=0;T0*_ei=Zo;_i=(((Zi5*)(((C)->Zlh)))->ZRb);
while(!((_i)==(Zrs(0)))){_ei=Zgz((Zi5*)(((C)->Zlh)),_i);if(ZSl1(((Zh2*)_ei),a1)){if((R)==((void*)(Zo))){R=((((Zh2*)_ei))->Zec);}else{
R=ZNF(((ZD*)R),((((Zh2*)_ei))->Zec));}}_i=(Z3)(((_i))-(Zrs(1)));}return R;}void ZTl1(Zw5*C,T76 a1,T0*a2){(C->Zxb)=a1;(C->Zlh)=a2;}T0*ZdU(ZA5*C,T0*a1){
T0*R=Zo;T2 _i=0;T0*_e=Zo;T0*ZYl=Zo;T0*_l=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;if((((C)->ZUb))!=((void*)(Zo))){{ZY*n=((ZY*)Zh(sizeof(*n)));
*n=Zjc;ZSx(n,(Z3)((((((ZB4*)(((C)->ZUb)))->ZRb)))+(Zrs(1))),(T2)(Zrs(1)));ZYl=((T0*)n);}_i=Zrs(0);while(!((Z3)((_i)>((((ZB4*)(((C)->ZUb)))->ZRb)))))
{_e=ZFG(((((ZB4*)(((C)->ZUb)))->ZPb))[_i],a1);if((_e)==((void*)(Zo))){ZzF(((C)->Zxb));{T76 Z3w;ZUl1((*(Z3w=ZGG(((((ZB4*)(((C)->ZUb)))->ZPb))[_i]),&Z3w)),ZvF(28,"Bad expression inside TUPLE."));
}_i=(Z3)((((((ZB4*)(((C)->ZUb)))->ZRb)))+(Zrs(1)));}else{((((ZB4*)(((C)->ZUb)))->ZPb))[_i]=(_e);ZQx(((ZY*)ZYl),ZvG(ZOG(_e)));_i=(Z3)(((_i))+(Zrs(1)));
}}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){{Zy7*n=((Zy7*)Zh(sizeof(*n)));*n=Z0k;Z2d1(n,((C)->Zxb),ZYl);(C->Zgc)=((T0*)n);}(C->Zgc)=ZBd1((Zy7*)(((C)->Zgc)),a1);
R=((T0*)(C));}}else{_l=((C)->ZUb);if((_l)!=((void*)(Zo))){_l=Zaz(((ZB4*)_l));}{ZA5*n=((ZA5*)Zh(sizeof(*n)));*n=Zoh;ZVl1(n,((C)->Zxb),_l);
R=((T0*)n);}R=ZWl1(((ZA5*)R),a1);}return R;}void ZUl1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}void ZXl1(ZA5*C){
T2 _i=0;if((((C)->ZUb))!=((void*)(Zo))){_i=(((ZB4*)(((C)->ZUb)))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){ZoG(((((ZB4*)(((C)->ZUb)))->ZPb))[_i]);
_i=(Z3)(((_i))-(Zrs(1)));}}}void ZYl1(ZA5*C){T2 _i=0;T0*_e=Zo;T0*_t=Zo;Z7I((Zi4*)(ZsG),ZZl1);ZtI((Zi4*)(ZsG),(T11)(ZSc1((Zy7*)(((C)->Zgc)))));
ZcH((Zi4*)(ZsG),((T3)'\050'));if((((C)->ZUb))!=((void*)(Zo))){_i=Zrs(0);while(!((Z3)((_i)>((((ZB4*)(((C)->ZUb)))->ZRb))))){_e=((((ZB4*)(((C)->ZUb)))->ZPb))[_i];
_t=ZOG(_e);Z3U(_e,_t);if((Z3)((_i)<((((ZB4*)(((C)->ZUb)))->ZRb)))){ZcH((Zi4*)(ZsG),((T3)'\054'));ZcH((Zi4*)(ZsG),((T3)'\n'));}_i=(Z3)(((_i))+(Zrs(1)));
}}ZcH((Zi4*)(ZsG),((T3)'\051'));}T6 Z_l1(ZA5*C,T0*a1){T6 R=0;T2 _i=0;R=((T6)(1));if((((C)->ZUb))!=((void*)(Zo))){_i=(((ZB4*)(((C)->ZUb)))->ZRb);
while(!((T6)((!(R))||((T6)((Z3)((_i)<(Zrs(0)))))))){R=((T6)(Z7G(((((ZB4*)(((C)->ZUb)))->ZPb))[_i],a1)));_i=(Z3)(((_i))-(Zrs(1)));}}return
R;}void Z0m1(ZA5*C,T0*a1,T0*a2){T2 _i=0;if((((C)->ZUb))!=((void*)(Zo))){_i=(((ZB4*)(((C)->ZUb)))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){
ZyG(((((ZB4*)(((C)->ZUb)))->ZPb))[_i],a1,a2);_i=(Z3)(((_i))-(Zrs(1)));}}}void Z1m1(ZA5*C){ZzF(((C)->Zxb));{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZVl1(ZA5*C,T76 a1,T0*a2){(C->Zxb)=a1;(C->ZUb)=a2;}void Z2m1(ZA5*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);
}ZzF(((C)->Zxb));ZxF((T75*)(ZyF));}void Z3m1(ZA5*C,T3 a1){T2 _i=0;T0*_e=Zo;if((((C)->ZUb))!=((void*)(Zo))){_i=(((ZB4*)(((C)->ZUb)))->ZRb);
while(!((Z3)((_i)<(Zrs(0))))){_e=((((ZB4*)(((C)->ZUb)))->ZPb))[_i];ZMG(_e,a1);_i=(Z3)(((_i))-(Zrs(1)));}}}void Z4m1(ZA5*C){T2 _i=0;if((((C)->ZUb))!=((void*)(Zo))){
_i=(((ZB4*)(((C)->ZUb)))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){ZSG(((((ZB4*)(((C)->ZUb)))->ZPb))[_i]);_i=(Z3)(((_i))-(Zrs(1)));}}}T6 Z5m1(ZA5*C){
T6 R=0;T2 _i=0;if((((C)->ZUb))!=((void*)(Zo))){_i=(((ZB4*)(((C)->ZUb)))->ZRb);while(!((T6)(((Z3)((_i)<(Zrs(0))))||((T6)(R))))){R=((T6)(ZYG(((((ZB4*)(((C)->ZUb)))->ZPb))[_i])));
_i=(Z3)(((_i))-(Zrs(1)));}}return R;}T6 Z6m1(void){T6 R=0;return R;}T6 Z7m1(T0*a1){T6 R=0;return R;}void Z8m1(ZA5*C,T0*a1){ZcH((Zi4*)(ZsG),((T3)'\050'));
ZbH(a1);ZYl1(C);ZcH((Zi4*)(ZsG),((T3)'\051'));}T2 Z9m1(ZA5*C){T2 R=0;Z2m1(C);return R;}T0*ZWl1(ZA5*C,T0*a1){T0*R=Zo;R=ZdU(C,a1);if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){
ZeL((Ze4*)(Z6d1((Zy7*)(((((ZA5*)R))->Zgc)))));}return R;}void Zam1(ZA5*C){T2 _i=0;if((((C)->ZUb))!=((void*)(Zo))){_i=(((ZB4*)(((C)->ZUb)))->ZRb);
while(!((Z3)((_i)<(Zrs(0))))){ZzH(((((ZB4*)(((C)->ZUb)))->ZPb))[_i]);_i=(Z3)(((_i))-(Zrs(1)));}}}void Zbm1(ZC5*C){Zcm1(C);ZTF((((ZB8*)(((C)->ZZb)))->Zxb),((C)->ZAb),((C)->Z_b));
}T0*Zdm1(T0*a1,T0*a2,T0*a3){T0*R=Zo;T0*ZVF=Zo;T0*ZWF=Zo;R=a1;if(ZXF(a2)){if(ZXF(a3)){ZWF=ZDF(a3);ZVF=ZDF(a2);if((ZWF)!=((void*)(ZVF))){
if(ZYF(a2,a3)){R=ZZF(a1,a3);}else{((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));}}}}return R;}T6 Zem1(ZC5*C,T0*a1){
T6 R=0;T0*_tr=Zo;if((((C)->ZAb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(Z3G((Zm3*)(((C)->ZAb)),a1)));}if(R){if((((C)->Z_b))==((void*)(Zo))){
}else if(Z4G(((C)->ZYb))){if(Z5G(((C)->Z_b),a1)){R=((T6)((Z6G(((C)->Z_b),a1))!=((void*)(Zo))));}else{R=((T6)(0));}}else{R=((T6)(Z7G(((C)->ZYb),a1)));
if(R){if((((C)->Z_b))!=((void*)(Zo))){_tr=(((Ze4*)(Z8G((((ZS7*)(((C)->Z_b)))->Z0c))))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)_tr))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
R=((T6)(Z5G(((C)->Z_b),_tr)));}}}}}return R;}T0*Zfm1(ZC5*C,T0*a1){T0*R=Zo;R=ZaG((Zm3*)(((C)->ZAb)),a1);if((R)==((void*)(Zo))){{T76 Z3w;
ZzF((*(Z3w=ZbG((Zm3*)(((C)->ZAb))),&Z3w)));}{T0*b1=ZcG;ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}return R;}void Zgm1(ZC5*C,T0*a1,T0*a2,T0*a3){
(C->ZYb)=a1;(C->ZZb)=a2;(C->ZAb)=a3;}T0*Zhm1(ZC5*C){T0*R=Zo;if((((T41*)(Z1G))->ZJk)){R=((T0*)(C));}else{R=Zim1(C);if((R)!=((void*)(C))){
ZhG((T41*)(Z1G));}}return R;}T0*Zjm1(ZC5*C){T0*R=Zo;(C->ZYb)=ZjG(((C)->ZYb));ZkG((Zm3*)(((C)->ZAb)));R=Zim1(C);return R;}void Zkm1(ZC5*C){
T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){if((((C)->ZAb))!=((void*)(Zo))){Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>=(Zrs(1)))){
{T76 Z3w;ZmG((T41*)(Z1G),(*(Z3w=Zlm1(C),&Z3w)),((C)->Z_b),Zof);}}}}ZoG(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){ZpG((Zm3*)(((C)->ZAb)));
}}void Zcm1(ZC5*C){if((ZqG(((C)->Z_b)))==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZCF(((C)->Z_b)),&Z3w)));}ZzF((((ZB8*)(((C)->ZZb)))->Zxb));
Zmm1(ZvF(29,"Feature found is a procedure."));}}T6 Znm1(ZC5*C,T0*a1){T6 R=0;R=((T6)(Zem1(C,a1)));if(R){R=((T6)(!(ZuG(ZvG(Zom1(C))))));
}return R;}void Zpm1(ZC5*C,T0*a1,T0*a2){ZyG(((C)->ZYb),a1,a2);ZzG((Zm3*)(((C)->ZAb)),a1,a2);}void Zqm1(ZC5*C){{T76 Z3w;ZzF((*(Z3w=Zlm1(C),&Z3w)));
}{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void Zrm1(ZC5*C,T0*a1,T76
a2,T0*a3){(C->ZYb)=a1;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,(ZkQ),a2);(C->ZZb)=((T0*)n);}{Zm3*n=((Zm3*)Zh(sizeof(*n)));*n=Z1j;((((Zm3*)(n)))->Z0j)=(a3);
(C->ZAb)=((T0*)n);}}void Zsm1(ZC5*C,T0*a1){T0*_t=Zo;_t=ZFG(((C)->ZYb),a1);if((_t)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZYb)),&Z3w)));
}{T0*b1=ZvF(11,"Bad target.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}(C->ZYb)=_t;}void Zmm1(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}void Ztm1(ZC5*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=Zlm1(C),&Z3w)));}ZxF((T75*)(ZyF));}T2 Zum1(ZC5*C){
T2 R=0;if(Z1P(Zom1(C))){R=ZhJ(((C)->ZYb));if((R)==(Zrs(-1))){R=ZhJ(((((Zm3*)(((C)->ZAb))))->Z0j));}else if((Z3)((R)>(Zrs(0)))){if((Z3)((ZhJ(((((Zm3*)(((C)->ZAb))))->Z0j)))>=(Zrs(0)))){
R=Zrs(0);}}}return R;}void Zvm1(ZC5*C,T0*a1){ZcH((Zi4*)(ZsG),((T3)'\050'));ZjJ(((C)->ZYb),a1);ZcH((Zi4*)(ZsG),((T3)'\051'));ZcH((Zi4*)(ZsG),((T3)'\053'));
ZcH((Zi4*)(ZsG),((T3)'\050'));ZjJ(((((Zm3*)(((C)->ZAb))))->Z0j),a1);ZcH((Zi4*)(ZsG),((T3)'\051'));}void Zwm1(ZC5*C,T3 a1){if((a1)==(((T3)'R'))){
{T76 Z3w;ZLG(((C)->Z_b),(*(Z3w=Zlm1(C),&Z3w)));}}ZMG(((C)->ZYb),a1);ZMG(((((Zm3*)(((C)->ZAb))))->Z0j),a1);}T0*Zom1(ZC5*C){T0*R=Zo;T0*ZNG=Zo;
R=ZqG(((C)->Z_b));ZNG=R;if(Zo!=(ZNG)){switch(((T0*)ZNG)->id){case 267:break;default:ZNG=Zo;}}if((ZNG)!=((void*)(Zo))){R=ZvG(ZOG(((((Zm3*)(((C)->ZAb))))->Z0j)));
}return R;}void Zxm1(ZC5*C){T0*ZQG=Zo;T0*_rc=Zo;T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){ZQG=ZOG(((C)->ZYb));_rc=Z8G(ZQG);Zof=((((Ze4*)_rc))->Zof);
if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){ZRG(((C)->ZYb),((C)->Z_b));}}ZSG(((C)->ZYb));ZTG((Zm3*)(((C)->ZAb)));
}T6 Zym1(ZC5*C){T6 R=0;R=((T6)(ZVG((Zm3*)(((C)->ZAb)))));if(R){}else if(Z4G(((C)->ZYb))){if((ZWG())!=((void*)(((C)->Z_b)))){R=((T6)(ZXG(((C)->Z_b))));
}}else{R=((T6)(ZYG(((C)->ZYb))));}return R;}T6 Zzm1(ZC5*C){T6 R=0;if(Z_G(((C)->ZYb))){if((((C)->ZAb))!=((void*)(Zo))){R=((T6)(Z0H((Zm3*)(((C)->ZAb)))));
}else{R=((T6)(1));}}return R;}T6 ZAm1(ZC5*C,T0*a1){T6 R=0;R=((T6)(Z2H(ZOG(((C)->ZYb)))));R=((T6)((T6)((Z3H(((C)->ZYb),a1))||((T6)(R)))));
if((a1)!=((void*)(Zo))){if(Z4H(((ZH6*)a1),((C)->ZYb))){R=((T6)(1));}}else if((T6)((Z2H(ZOG(((C)->ZYb))))&&((T6)(!(Z4G(((C)->ZYb))))))){
Z5H(((C)->ZYb));}return R;}void ZBm1(ZC5*C,T0*a1){T6 Z7H=0;T0*Z8H=Zo;Z7H=((T6)(Z9H((Zi4*)(ZsG),a1)));Z8H=ZvG(Zom1(C));if(ZaH(Z8H)){if(ZaH(a1)){
ZbH(a1);ZcH((Zi4*)(ZsG),((T3)'\050'));{ZC5*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}ZcH((Zi4*)(ZsG),((T3)'\051'));}else{{ZC5*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);
}}}else{if(ZaH(a1)){{ZC5*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}else{if(ZeH(a1)){ZcH((Zi4*)(ZsG),((T3)'\046'));ZcH((Zi4*)(ZsG),((T3)'\050'));
{ZC5*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}ZcH((Zi4*)(ZsG),((T3)'\051'));}else{{ZC5*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}}}if(Z7H){ZfH((Zi4*)(ZsG));
}}void ZCm1(ZC5*C,T0*a1){T0*_rf=Zo;T0*_rc=Zo;T0*_rt=Zo;T0*_bc=Zo;_rt=ZOG(((C)->ZYb));if((_rt)!=((void*)(Zo))){_rc=Z8G(_rt);if((_rc)!=((void*)(Zo))){
_bc=((((Ze4*)_rc))->Zqb);_rf=ZhH(((T82*)_bc),_rc,((C)->ZYb),((C)->ZZb),a1);}}if((_rf)==((void*)(Zo))){ZzF((((ZB8*)(((C)->ZZb)))->Zxb));
{T0*b1=ZvF(25,"Bad target for this call.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}(C->Z_b)=_rf;}T2 ZDm1(ZC5*C){T2 R=0;Ztm1(C);
return R;}T0*ZEm1(ZC5*C,T0*a1){T0*R=Zo;T0*ZkH=Zo;T0*ZlH=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;Zsm1(C,a1);(C->ZAb)=Zfm1(C,a1);
ZlH=ZOG(((C)->ZYb));ZkH=ZOG(((((Zm3*)(((C)->ZAb))))->Z0j));(C->ZYb)=Zdm1(((C)->ZYb),ZlH,ZkH);ZCm1(C,a1);R=Zhm1(C);Zbm1(C);}else{{ZC5*n=((ZC5*)Zh(sizeof(*n)));
*n=Zph;Zgm1(n,((C)->ZYb),((C)->ZZb),((C)->ZAb));R=((T0*)n);}R=ZFG(R,a1);}return R;}T0*Zim1(ZC5*C){T0*R=Zo;T0*ZtJ=Zo;T0*ZuJ=Zo;T11 _v1=0;
T11 _v2=0;T11 _r=0;T6 ZvJ=0;ZtJ=((C)->ZYb);if(Zo!=(ZtJ)){switch(((T0*)ZtJ)->id){case 249:break;default:ZtJ=Zo;}}if((ZtJ)==((void*)(Zo))){
R=((T0*)(C));}else{ZuJ=((((Zm3*)(((C)->ZAb))))->Z0j);if(Zo!=(ZuJ)){switch(((T0*)ZuJ)->id){case 249:break;default:ZuJ=Zo;}}if((ZuJ)==((void*)(Zo))){
R=((T0*)(C));}else{_v1=((((Zs1*)ZtJ))->ZEl);_v2=((((Zs1*)ZuJ))->ZEl);_r=(Z5)((_v1)+(_v2));if((Z5)((_v1)>=(Zrs(0)))){if((Z5)((_v2)>=(Zrs(0)))){
ZvJ=((T6)((Z5)((_r)<(Zrs(0)))));}}else if((Z5)((_v2)<(Zrs(0)))){ZvJ=((T6)((Z5)((_r)>(Zrs(0)))));}if(ZvJ){{T0*b1=ZwJ;ZXw((T7*)(ZwF),b1);
}ZzF((((ZB8*)(((C)->ZZb)))->Zxb));ZEF((T75*)(ZyF));}{Zs1*n=((Zs1*)Zh(sizeof(*n)));*n=ZIl;ZxJ(n,_r,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);
}}}return R;}T0*ZFm1(ZC5*C){T0*R=Zo;T0*_bc=Zo;T0*ZsH=Zo;T0*_rt=Zo;_bc=ZtH(((C)->ZYb));if((_bc)!=((void*)(Zo))){ZsH=ZuH(((T82*)_bc),((C)->ZZb));
if((ZsH)!=((void*)(Zo))){_rt=ZvH(ZsH);if((_rt)!=((void*)(Zo))){R=ZwH(_rt);}}}return R;}void ZGm1(ZC5*C){if((((C)->Z_b))!=((void*)(Zo))){
ZyH(((C)->Z_b));}ZzH(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){ZAH((Zm3*)(((C)->ZAb)));}}void ZHm1(ZC5*C){T0*_rc=Zo;T0*_rf=Zo;_rf=((C)->Z_b);
_rc=((((ZS7*)_rf))->Znf);(C->Z_b)=ZCH((Ze4*)((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZPb))[Zrs(0)]),_rf);}T76 Zlm1(ZC5*C){
T76 R={Zo,Zo,0};R=(((ZB8*)(((C)->ZZb)))->Zxb);return R;}T0*ZIm1(ZE5*C,T0*a1,T0*a2){T0*R=Zo;{T76 Z3w;ZzF((*(Z3w=ZJm1(C),&Z3w)));}ZKm1(((((ZB8*)a1))->Zxb),ZvF(42,"An attribute must not be undefined (VDUS)."));
ZEJ(((T82*)a2),a1);return R;}void ZLm1(ZE5*C,T0*a1,T0*a2,T2 a3){T0*Zfj1=Zo;T76 _sp={Zo,Zo,0};T0*Z3V=Zo;T0*_ic=Zo;(C->Zqb)=a1;{Zx8*n=((Zx8*)Zh(sizeof(*n)));
*n=Z1l;((((Zx8*)(n)))->ZBd)=(a2);Zfj1=((T0*)n);}{T76*C1=&_sp;T0*b1=a1;Z4j1(C1,(T2)(Zrs(1)),(T2)(Zrs(1)),((((T82*)b1))->_id),b1);}{Zs5*n=((Zs5*)Zh(sizeof(*n)));
*n=Zjh;ZMm1(n,_sp);Z3V=((T0*)n);}{Zs1*n=((Zs1*)Zh(sizeof(*n)));*n=ZIl;ZxJ(n,(T11)(a3),_sp);_ic=((T0*)n);}ZNm1(C,Zfj1,Z3V,_ic);(C->Zec)=ZOm1();
}void ZKm1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T6 ZPm1(ZE5*C,T0*a1,T0*a2){T6 R=0;if((((C)->Zgc))!=((void*)(ZvH(a1)))){
if((T6)(((((C)->Zgc))==((void*)(Zo)))||((T6)((ZvH(a1))==((void*)(Zo)))))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;ZKm1((*(Z3w=ZJm1(C),&Z3w)),ZHJ);
}}}if((Zo)!=((void*)(ZIJ(a1)))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;ZKm1((*(Z3w=ZJm1(C),&Z3w)),ZJJ);}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){
if((((C)->Zgc))!=((void*)(Zo))){if(!(ZKJ(ZvH(a1),((C)->Zgc),a2,(T6)(0)))){{T0*b1=ZLJ;ZXw((T7*)(ZwF),b1);}{T0*b1=ZDF(((((Ze4*)a2))->Z0c));
ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){}R=((T6)(((((T75*)(ZyF))->ZAg))==(Zrs(0))));
if(R){ZQm1(C,a1);}return R;}void ZQm1(ZE5*C,T0*a1){if((((T41*)(Z1G))->ZJk)){if((((C)->ZCb))==((void*)(Zo))){(C->ZCb)=ZOJ(a1);}else if((ZOJ(a1))==((void*)(Zo))){
ZPJ(a1,((C)->ZCb));}}}void ZRm1(ZE5*C,T0*a1){T2 _i=0;T0*_fn=Zo;T0*_f=Zo;(C->Zqb)=(((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),Zrs(1))))->Zxb)).Zqb);
_i=Zrs(1);while(!((Z3)((_i)>(ZSJ((Zx8*)(((C)->Zfc))))))){_fn=ZRJ((Zx8*)(((C)->Zfc)),_i);_f=ZED(((Z25*)a1),_fn);if((_f)!=((void*)(Zo))){
_fn=((((Zx8*)(((((Z85*)_f))->Zfc))))->ZBd);ZzF(((((ZB8*)_fn))->Zxb));ZzF((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),_i)))->Zxb));{T0*b1=ZvF(29,"Double definition of feature ");
ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)_fn))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}else{ZBD(((Z25*)a1),(T0*)C,_fn);
}_i=(Z3)(((_i))+(Zrs(1)));}}T0*ZSm1(ZE5*C,T0*a1,T0*a2){T0*R=Zo;T0*ZUJ=Zo;ZzF(((((ZB8*)a1))->Zxb));ZUJ=ZVJ((Zx8*)(((C)->Zfc)),((((ZB8*)a1))->Z3n));
if((ZUJ)!=((void*)(Zo))){ZWJ(((ZB8*)ZUJ),a2);}((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));R=ZIm1(C,a1,a2);
if((R)!=((void*)(Zo))){((((ZM3*)(((ZM3*)R))))->Zec)=(((C)->Zec));ZQm1(C,R);}else{ZEJ(((T82*)a2),a1);}return R;}void ZNm1(ZE5*C,T0*a1,T0*a2,T0*a3){
((((ZE5*)(C)))->Zfc)=(a1);(C->Zgc)=a2;(C->Zhc)=a3;}T0*ZTm1(ZE5*C,T0*a1,T0*a2){T0*R=Zo;T0*_rc=Zo;_rc=Z8G(a1);R=Z8E(((Zj6*)(((((Ze4*)_rc))->Zug))),a2);
if(Zo!=(R)){switch(((T0*)R)->id){case 556:break;default:R=Zo;}}if((R)==((void*)(Zo))){{ZE7*n=((ZE7*)Zh(sizeof(*n)));*n=Z4k;ZZJ(n,a1,a2,(T0*)C);
R=((T0*)n);}}return R;}T0*ZUm1=Zo;int ZVm1=0;T0*ZOm1(void){if(ZVm1==0){ZVm1=1;{{ZD*n=((ZD*)Zh(sizeof(*n)));*n=ZWb;ZUm1=((T0*)n);}}}return
ZUm1;}T6 ZWm1(ZE5*C,T0*a1){T6 R=0;if((((C)->Zgc))==((void*)(Zo))){R=((T6)((ZvH(a1))!=((void*)(Zo))));}else{R=((T6)((ZvH(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZHJ;ZXw((T7*)(ZwF),b1);}}else{R=((T6)((ZIJ(a1))!=((void*)(Zo))));if(R){{T0*b1=ZJJ;ZXw((T7*)(ZwF),b1);}}}ZQm1(C,a1);return
R;}T76 ZJm1(ZE5*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((((Zx8*)(((C)->Zfc))))->ZBd)))->Zxb);return R;}void ZXm1(Ze4*C,T0*a1){T6 ZlY=0;T0*ZYm1=Zo;
T0*ZZm1=Zo;T0*ZaM=Zo;T6 Zl41=0;ZlY=((T6)(((((T84*)(ZFI))->Zcf))==(Zrs(1))));ZYm1=Z_m1;((((T7*)(((T7*)ZYm1))))->Zcc)=(Zrs(0));if(ZaH(((C)->Z0c))){
ZNS(((C)->Z0c),ZYm1);}else{ZXU(((C)->Z0c),ZYm1);ZZs(((T7*)ZYm1),((T3)'\040'));}ZXw(((T7*)ZYm1),ZmY);ZQs(((C)->_id),ZYm1);if((a1)!=((void*)(Zo))){
ZXw(((T7*)ZYm1),(((ZB8*)(((((ZS7*)a1))->Zkc)))->Zre));}ZZs(((T7*)ZYm1),((T3)'\050'));if((a1)!=((void*)(Zo))){ZaM=ZcL(a1);}if(ZlY){if((ZaM)!=((void*)(Zo))){
ZH71(((ZH6*)ZaM),ZYm1);}else{ZXw(((T7*)ZYm1),Z0n1);}}else{ZXw(((T7*)ZYm1),Z1n1);if((ZaM)!=((void*)(Zo))){ZZs(((T7*)ZYm1),((T3)'\054'));
ZH71(((ZH6*)ZaM),ZYm1);}}ZZs(((T7*)ZYm1),((T3)'\051'));ZyI((Zi4*)(ZsG),ZYm1);ZZm1=Z_m1;((((T7*)(((T7*)ZZm1))))->Zcc)=(Zrs(0));if(ZaH(((C)->Z0c))){
ZNS(((C)->Z0c),ZZm1);}else{ZEZ(((C)->Z0c),ZYm1);}ZXw(((T7*)ZZm1),Z2n1);Z7I((Zi4*)(ZsG),ZZm1);if(!(ZlY)){Z7I((Zi4*)(ZsG),Z3n1);}if(ZaH(((C)->Z0c))){
Z4n1((Zh8*)(Z5n1()),Z6n1,(T0*)C);}else{Z7I((Zi4*)(ZsG),Z7n1);ZtI((Zi4*)(ZsG),(T11)(((C)->_id)));Z7I((Zi4*)(ZsG),Z8n1);}if((a1)!=((void*)(Zo))){
Z9n1((Zi4*)(ZsG),a1);ZyH(a1);Zl41=((T6)(Zan1((Zi4*)(ZsG))));ZvX(a1);if(Zl41){Zn41((Zi4*)(ZsG));}ZwX((Zi4*)(ZsG));}Z7I((Zi4*)(ZsG),Zbn1);
}void Zcn1(Ze4*C,T0*a1,T0*a2){{T0*b1=Zdn1;ZXw((T7*)(ZwF),b1);}{T0*b1=((C)->ZMc);ZXw((T7*)(ZwF),b1);}{T0*b1=Zen1;ZXw((T7*)(ZwF),b1);}Zfn1(a2);
{T0*b1=Zgn1;ZXw((T7*)(ZwF),b1);}{T0*b1=(((T80*)(((((T82*)a1))->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}Zhn1(((((ZB8*)a2))->Zxb),ZMJ);}T6 Zin1(Ze4*C){
T6 R=0;T2 _i=0;T0*_wa=Zo;T0*ZCb1=Zo;T0*_t=Zo;_wa=ZKS(C);if((_wa)!=((void*)(Zo))){_i=((((ZT8*)_wa))->ZRb);while(!((T6)((R)||((T6)((_i)==(Zrs(0)))))))
{ZCb1=ZDA(((ZT8*)_wa),_i);_t=((((ZG7*)ZCb1))->Zgc);R=((T6)(ZBZ(_t)));_i=(Z3)(((_i))-(Zrs(1)));}}return R;}void Zjn1(Ze4*C,T0*a1){T2 _i=0;
T2 _t=0;T0*Zkn1=Zo;T0*ZBb=Zo;T0*_s=Zo;T0*ZCb1=Zo;T0*Zln1=Zo;ZCb1=a1;if(Zo!=(ZCb1)){switch(((T0*)ZCb1)->id){case 165:break;default:ZCb1=Zo;
}}Zln1=a1;if(Zo!=(Zln1)){switch(((T0*)Zln1)->id){case 502:break;default:Zln1=Zo;}}Zkn1=((C)->Zof);{int z1=(Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1)));
switch(z1){case 0:break;case 1:ZBb=(((Ze4*)((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZPb))[Zrs(0)]))->Z0c);_s=Zmn1(ZBb);_t=ZuI(ZBb);if(Z5T(ZBb)){
Z7I((Zi4*)(ZsG),Znn1);}else{Z7I((Zi4*)(ZsG),Zon1);}Z7I((Zi4*)(ZsG),Zpn1);ZtI((Zi4*)(ZsG),(T11)(_t));Z7I((Zi4*)(ZsG),Zqn1);Z7I((Zi4*)(ZsG),_s);
Z7I((Zi4*)(ZsG),Zrn1);ZzZ(ZBb);Z7I((Zi4*)(ZsG),Zsn1);Z7I((Zi4*)(ZsG),_s);Z7I((Zi4*)(ZsG),Ztn1);if((ZCb1)!=((void*)(Zo))){Zun1(((ZG7*)ZCb1));
}else{{T0*b1=Zln1;Z7I((Zi4*)(ZsG),Zvn1(ZyV(b1)));}}Z7I((Zi4*)(ZsG),Zwn1);break;default:;Z7I((Zi4*)(ZsG),Zxn1);if((ZCb1)!=((void*)(Zo))){
Zun1(((ZG7*)ZCb1));}else{{T0*b1=Zln1;Z7I((Zi4*)(ZsG),Zvn1(ZyV(b1)));}}Z7I((Zi4*)(ZsG),Zyn1);_i=Zrs(1);while(!((Z3)((_i)>((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1)))))))
{_t=ZuI((((Ze4*)((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZPb))[(_i)-(Zrs(1))]))->Z0c));Z7I((Zi4*)(ZsG),Zzn1);ZtI((Zi4*)(ZsG),(T11)(_t));
Z7I((Zi4*)(ZsG),ZAn1);_i=(Z3)(((_i))+(Zrs(1)));}Z7I((Zi4*)(ZsG),ZBn1);}}}T0*Z_m1=Zo;T0*Zmn1(T0*a1){T0*R=Zo;R=ZCn1;ZBw(((T7*)R),ZDn1);
ZQs(ZuI(a1),R);if(ZaH(a1)){ZZs(((T7*)R),((T3)'\052'));}return R;}T0*Zgc1(Ze4*C,T0*a1){T0*R=Zo;T0*ZUJ=Zo;T0*ZFX=Zo;ZFX=((((((ZB8*)a1))->Zxb)).Zqb);
ZUJ=ZuY((T82*)(((C)->Zqb)),ZFX,a1);if((ZUJ)!=((void*)(a1))){ZzF(((((ZB8*)a1))->Zxb));R=ZEn1(C,ZUJ);((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));
((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));}else{R=ZEn1(C,ZUJ);}return R;}void ZGY(Ze4*C,T0*a1){if((((C)->ZAh))==((void*)(Zo))){{Z_5*n=((Z_5*)Zh(sizeof(*n)));
*n=ZWh;Z4A(n,(T2)(Zrs(4)));(C->ZAh)=((T0*)n);}}if((a1)!=((void*)(Zo))){if(!(Z0A((Z_5*)(((C)->ZAh)),a1))){Z2A((Z_5*)(((C)->ZAh)),a1);}
}}void ZFn1(T0*a1){T2 ZGn1=0;T2 ZHn1=0;T2 ZIn1=0;T6 ZJn1=0;ZHn1=((((ZT8*)a1))->ZRb);ZGn1=Zrs(1);ZJn1=((T6)(1));while(!(!(ZJn1))){ZJn1=((T6)(0));
if((Z3)(((Z3)(((ZHn1))-(ZGn1)))>(Zrs(0)))){ZIn1=(Z3)(((ZGn1))+(Zrs(1)));while(!((Z3)((ZIn1)>(ZHn1)))){if(ZKn1(ZDA(((ZT8*)a1),(Z3)(((ZIn1))-((T2)(Zrs(1))))),ZDA(((ZT8*)a1),ZIn1))){
ZGA(((ZT8*)a1),(Z3)(((ZIn1))-((T2)(Zrs(1)))),ZIn1);ZJn1=((T6)(1));}ZIn1=(Z3)(((ZIn1))+(Zrs(1)));}ZHn1=(Z3)(((ZHn1))-(Zrs(1)));}if((T6)((ZJn1)&&((T6)((Z3)(((Z3)(((ZHn1))-(ZGn1)))>(Zrs(0))))))){
ZJn1=((T6)(0));ZIn1=(Z3)(((ZHn1))-(Zrs(1)));while(!((Z3)((ZIn1)<(ZGn1)))){if(ZKn1(ZDA(((ZT8*)a1),ZIn1),ZDA(((ZT8*)a1),(Z3)(((ZIn1))+((T2)(Zrs(1))))))){
ZGA(((ZT8*)a1),ZIn1,(Z3)(((ZIn1))+((T2)(Zrs(1)))));ZJn1=((T6)(1));}ZIn1=(Z3)(((ZIn1))-(Zrs(1)));}ZGn1=(Z3)(((ZGn1))+(Zrs(1)));}}}void
Zhd1(Ze4*C,T0*a1,T0*a2){T2 Zcc=0;T2 _i=0;T0*Zkc=Zo;T76 _sp={Zo,Zo,0};T0*ZLn1=Zo;T0*ZMn1=Zo;T0*_rf=Zo;if(!(Z5E((Zj6*)(((C)->Zug)),ZNn1()))){
if((a2)!=((void*)(Zo))){Zcc=ZLx(((ZY*)a2));}{T76*C1=&_sp;T0*b1=Zrd1(((Zy7*)a1));Z4j1(C1,(T2)(Zrs(1)),(T2)(Zrs(1)),((((T82*)b1))->_id),b1);
}{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z6j1(n,ZDQ,_sp);ZLn1=((T0*)n);}{ZE5*n=((ZE5*)Zh(sizeof(*n)));*n=Zqh;ZLm1(n,Zrd1(((Zy7*)a1)),ZLn1,Zcc);
ZMn1=((T0*)n);}_rf=ZTm1(((ZE5*)ZMn1),a1,ZLn1);if((Z3)((Zcc)>=(Zrs(1)))){ZOn1(a1,ZZQ,ZMx(((ZY*)a2),(T2)(Zrs(1))),(T2)(Zrs(1)));}if((Z3)((Zcc)>=(Zrs(2)))){
ZOn1(a1,ZJR,ZMx(((ZY*)a2),(T2)(Zrs(2))),(T2)(Zrs(2)));}if((Z3)((Zcc)>=(Zrs(3)))){ZOn1(a1,ZXR,ZMx(((ZY*)a2),(T2)(Zrs(3))),(T2)(Zrs(3)));
}if((Z3)((Zcc)>=(Zrs(4)))){ZOn1(a1,Z1R,ZMx(((ZY*)a2),(T2)(Zrs(4))),(T2)(Zrs(4)));}if((Z3)((Zcc)>=(Zrs(5)))){ZOn1(a1,ZYQ,ZMx(((ZY*)a2),(T2)(Zrs(5))),(T2)(Zrs(5)));
}_i=Zrs(6);while(!((Z3)((_i)>(Zcc)))){{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Z6x(n,(T2)(Zrs(8)));Zkc=((T0*)n);}ZBw(((T7*)Zkc),ZPn1);ZQs(_i,Zkc);
Zkc=(((void)((T26*)(ZQn1()))),ZAS(Zkc));ZOn1(a1,Zkc,ZMx(((ZY*)a2),_i),_i);_i=(Z3)(((_i))+(Zrs(1)));}}}void ZNN(Ze4*C,T6 a1,T0*a2){T0*ZCb1=Zo;
T0*_t=Zo;T0*_rc=Zo;T2 _i=0;((((ZQ9*)((ZQ9*)(ZRn1))))->ZRb)=(Zrs(-1));((((ZQ9*)((ZQ9*)(ZSn1))))->ZRb)=(Zrs(-1));if((ZKS(C))!=((void*)(Zo))){
_i=(((ZT8*)(ZKS(C)))->ZRb);while(!((_i)==(Zrs(0)))){ZCb1=ZDA((ZT8*)(ZKS(C)),_i);_t=((((ZG7*)ZCb1))->Zgc);if(ZBZ(_t)){_rc=Z8G(_t);((((ZQ9*)((ZQ9*)(ZTn1))))->ZRb)=(Zrs(-1));
Z7B((ZQ9*)(ZTn1),ZCb1);if(ZUn1(((Ze4*)_rc),(T0*)C)){Z7B((ZQ9*)(ZSn1),ZCb1);}else{Z7B((ZQ9*)(ZRn1),ZCb1);}}_i=(Z3)(((_i))-(Zrs(1)));}}
if((T6)(((Z3)(((((ZQ9*)(ZRn1))->ZRb))<(Zrs(0))))&&((T6)((Z3)(((((ZQ9*)(ZSn1))->ZRb))<(Zrs(0))))))){ZVn1(C,a2);}else{if((Z3)(((((ZQ9*)(ZSn1))->ZRb))>=(Zrs(0)))){
ZXw(((T7*)a2),ZWn1);}if(!(a1)){ZXw(((T7*)a2),ZXn1);ZQs(((C)->_id),a2);ZXw(((T7*)a2),ZYn1);}ZVn1(C,a2);_i=(((ZQ9*)(ZRn1))->ZRb);while(!((Z3)((_i)<(Zrs(0)))))
{ZCb1=((((ZQ9*)(ZRn1))->ZPb))[_i];ZZn1(C,a2,ZCb1);_i=(Z3)(((_i))-(Zrs(1)));}_i=(((ZQ9*)(ZSn1))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){ZCb1=((((ZQ9*)(ZSn1))->ZPb))[_i];
_t=((((ZG7*)ZCb1))->Zgc);_rc=Z8G(_t);((((ZQ9*)((ZQ9*)(ZTn1))))->ZRb)=(Zrs(-1));Z7B((ZQ9*)(ZTn1),ZCb1);if(ZUn1(((Ze4*)_rc),(T0*)C)){}if((T6)(((T6)(((T6)(((_i)==(Zrs(0)))&&((T6)(((Z3)((((((ZQ9*)(ZTn1))->ZRb)))+(Zrs(1))))==(Zrs(1))))))&&((T6)(((Z3)(((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1))))))&&((T6)(((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZPb))[(Zrs(1))-(Zrs(1))])==((void*)(C)))))){
ZXw(((T7*)a2),Z_n1);ZXw(((T7*)a2),(((ZB8*)(((((ZG7*)ZCb1))->Zkc)))->Zre));ZXw(((T7*)a2),Z0o1);if(a1){ZXw(((T7*)a2),Z1o1);ZQs(((C)->_id),a2);
ZXw(((T7*)a2),Z2o1);}else{ZZs(((T7*)a2),((T3)'\051'));}ZXw(((T7*)a2),Z3o1);}else{ZZn1(C,a2,ZCb1);}_i=(Z3)(((_i))-(Zrs(1)));}if(!(a1)){
ZZs(((T7*)a2),((T3)'\175'));}}}T2 Z4o1(Ze4*C){T2 R=0;T0*_wa=Zo;T0*_a=Zo;T2 _i=0;if(ZKN(C)){R=sizeof(T2);}_wa=ZKS(C);if((_wa)!=((void*)(Zo))){
_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){_a=ZDA(((ZT8*)_wa),_i);R=(Z3)(((R))+(ZjZ(((((ZG7*)_a))->Zgc))));_i=(Z3)(((_i))-(Zrs(1)));
}}if((R)==(Zrs(0))){R=Zrs(1);}return R;}T6 ZUn1(Ze4*C,T0*a1){T6 R=0;if((C)==((void*)(a1))){R=((T6)(1));}return R;}void ZVn1(Ze4*C,T0*a1){
if(ZaH(((C)->Z0c))){ZXw(((T7*)a1),Z5o1);ZQs(((C)->_id),a1);ZXw(((T7*)a1),Z6o1);}}void Zhn1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);
}ZxF((T75*)(ZyF));}T0*Z7o1(void){if(Zsj1==0){Zsj1=1;{T0*_cn=Zo;{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Z721(n,ZpK);_cn=((T0*)n);}Zrj1=Z821(_cn);
}}return Zrj1;}T6 ZVB(Ze4*C,T0*a1){T6 R=0;R=((T6)((C)==((void*)(a1))));return R;}T0*Z8o1=Zo;int Z9o1=0;T0*ZNn1(void){if(Z9o1==0){Z9o1=1;{
{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z8o1=((T0*)n);Zzi1(n,ZDQ);}}}return Z8o1;}void ZZn1(Ze4*C,T0*a1,T0*a2){ZBw((T7*)(Zao1),Zbo1);ZXw((T7*)(Zao1),(((ZB8*)(((((ZG7*)a2))->Zkc)))->Zre));
ZXw((T7*)(Zao1),ZAl1);ZQs(Zco1(C,a2),Zao1);ZXw((T7*)(Zao1),ZCl1);(((void)((Zh8*)(Z5n1()))),Zdo1(a1,Zao1,Z8G(((((ZG7*)a2))->Zgc))));}void
Zeo1(Ze4*C,T0*a1){if(((C)->Zth)){ZqZ(((C)->Z0c),a1);}}T0*ZXh1(Ze4*C,T0*a1,T0*a2){T0*R=Zo;T0*ZUJ=Zo;T0*ZFX=Zo;T0*_rf=Zo;T0*_f=Zo;T0*_bc=Zo;
ZFX=((((((ZB8*)a1))->Zxb)).Zqb);ZUJ=ZuY((T82*)(((C)->Zqb)),ZFX,a1);_rf=Z8E((Zj6*)(((C)->Zug)),ZUJ);if((_rf)!=((void*)(Zo))){R=ZqG(_rf);
if(Z7V(R)){R=ZvG(R);}else{R=Z9L(R,((C)->Z0c));R=ZvG(R);}}else{_bc=((C)->Zqb);_f=ZGi1(((T82*)_bc),(T0*)C,ZUJ);if((_f)==((void*)(Zo))){
Zcn1(C,_bc,ZUJ);ZzF(((((ZB8*)a1))->Zxb));ZzF(((((ZB8*)ZUJ))->Zxb));Zfo1(ZvF(18," Anchor not found."));}else{R=ZvH(_f);if((R)==((void*)(Zo))){
{T76 Z3w;ZzF((*(Z3w=ZGJ(_f),&Z3w)));}ZzF(((((ZB8*)a1))->Zxb));ZzF(((((ZB8*)ZUJ))->Zxb));Zfo1(ZvF(29," Anchor found is a procedure."));
}else{R=Z9L(R,((C)->Z0c));R=ZvG(R);}}}return R;}T0*ZSn1=Zo;T0*Zgo1(void){if(ZDj1==0){ZDj1=1;{{Zr6*n=((Zr6*)Zh(sizeof(*n)));*n=ZVi;ZCj1=((T0*)n);
}}}return ZCj1;}T6 Zho1(Ze4*C,T0*a1){T6 R=0;T0*ZLn1=Zo;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Zzi1(n,a1);ZLn1=((T0*)n);}R=((T6)(Z5E((Zj6*)(((C)->Zug)),ZLn1)));
return R;}T6 ZKn1(T0*a1,T0*a2){T6 R=0;T0*ZmH=Zo;T0*ZnH=Zo;T0*Zio1=Zo;T0*Zjo1=Zo;T0*Zko1=Zo;T0*Zlo1=Zo;if((((((ZG7*)a1))->Z5k))!=(((((ZG7*)a2))->Z5k))){
R=((T6)((Z3)((((((ZG7*)a1))->Z5k))<(((((ZG7*)a2))->Z5k)))));}else{Zio1=((((ZG7*)a1))->ZPj);Zjo1=((((ZG7*)a2))->ZPj);ZmH=((((Z85*)Zio1))->Zqb);
ZnH=((((Z85*)Zjo1))->Zqb);Zko1=((((T82*)ZmH))->Zkc);Zlo1=((((T82*)ZnH))->Zkc);if((((((T80*)Zko1))->Zre))==((void*)(((((T80*)Zlo1))->Zre)))){
{T76 Zo61;T76 Z3w;R=((T6)(Zmo1(&((*(Zo61=ZGJ(Zio1),&Zo61))),(*(Z3w=ZGJ(Zjo1),&Z3w)))));}}else if(Zd91(((T80*)Zlo1),Zko1)){R=((T6)(1));
}else if(Zd91(((T80*)Zko1),Zlo1)){}else if((((((T82*)ZmH))->Zmg))==((void*)(Zo))){if((((((T82*)ZnH))->Zmg))==((void*)(Zo))){R=((T6)(Z5x((T7*)(((((T80*)Zko1))->Zre)),((((T80*)Zlo1))->Zre))));
}else{R=((T6)(1));}}else if((((((T82*)ZnH))->Zmg))==((void*)(Zo))){}else{R=((T6)((Z3)(((Z3)(((((((Z32*)((((Z3a*)(((((T82*)ZnH))->Zmg)))->ZUb))))->ZRb)))+(Zrs(1))))<((Z3)(((((((Z32*)((((Z3a*)(((((T82*)ZmH))->Zmg)))->ZUb))))->ZRb)))+(Zrs(1)))))));
}}return R;}T0*Zno1(Ze4*C){T0*R=Zo;T0*Zoo1=Zo;T0*_bc=Zo;Zoo1=Zpo1();if((Zoo1)!=((void*)(Zo))){_bc=((C)->Zqb);if((T6)(((Zoo1)!=((void*)(_bc)))&&((T6)(ZnI(((T82*)_bc),Zoo1))))){
if(Zv81(((T82*)_bc),ZSQ)){R=Zw81(C,ZSQ);if(Zo!=(R)){switch(((T0*)R)->id){case 435:break;default:R=Zo;}}if((R)!=((void*)(Zo))){R=Zqo1(((ZI7*)R));
}}}}return R;}void Zro1(Ze4*C){T0*_rf=Zo;T2 _i=0;T0*_c=Zo;_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc))))){_rf=Z2E((Zj6*)(((C)->Zug)),_i);
_c=Zso1(_rf);if((_c)!=((void*)(Zo))){Z271(((Z47*)_c));}_i=(Z3)(((_i))+(Zrs(1)));}}void Zto1(Ze4*C){T0*_rf=Zo;T2 _i=0;_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc)))))
{_rf=Z2E((Zj6*)(((C)->Zug)),_i);Zuo1(_rf);_i=(Z3)(((_i))+(Zrs(1)));}}void Zvo1(Ze4*C,T0*a1){T2 _i=0;T0*_wa=Zo;T0*ZCb1=Zo;T0*_t=Zo;T0*Zkc=Zo;
T0*Zkn1=Zo;if(ZaH(((C)->Z0c))){ZXw(((T7*)a1),Zwo1);ZNS(((C)->Z0c),a1);ZZs(((T7*)a1),((T3)'\040'));{Zh8*C1=(Zh8*)(Z5n1());T0*b1=Zxo1;T0*b2=a1;
T0*b3=(T0*)C;Zyo1(C1,b1,b2,b3,Zo);}ZXw(((T7*)a1),Zzo1);}else{ZXw(((T7*)a1),ZAo1);ZNS(((C)->Z0c),a1);ZXw(((T7*)a1),ZBo1);}_wa=ZKS(C);if((_wa)!=((void*)(Zo))){
_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){ZCb1=ZDA(((ZT8*)_wa),_i);Zkc=(((ZB8*)(((((ZG7*)ZCb1))->Zkc)))->Zre);_t=ZvG(((((ZG7*)ZCb1))->Zgc));
if(ZaH(_t)){Zkn1=(((Ze4*)(Z8G(_t)))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(0)))){ZXw(((T7*)a1),ZCo1);
ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZDo1);ZXw(((T7*)a1),Zkc);ZZs(((T7*)a1),((T3)'\075'));Zkn1=(((Ze4*)(Z8G(_t)))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
ZZs(((T7*)a1),((T3)'X'));ZQs((((Ze4*)(((((Zc3*)Zkn1))->Z7e)))->_id),a1);}else{ZZs(((T7*)a1),((T3)'r'));ZQs((((Ze4*)((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZPb))[Zrs(0)]))->_id),a1);
}ZXw(((T7*)a1),ZEo1);if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZXw(((T7*)a1),ZFo1);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
ZXw(((T7*)a1),ZGo1);}}if(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1))){ZZs(((T7*)a1),((T3)'\050'));ZNS((((Ze4*)((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZPb))[Zrs(0)]))->Z0c),a1);
ZZs(((T7*)a1),((T3)'\051'));}ZXw(((T7*)a1),ZHo1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZIo1);}}else if(ZuG(_t)){if((Zw81(C,ZAQ))==((void*)(Zo))){
ZsS(_t,ZJo1);ZxF((T75*)(ZyF));{T76 Z3w;ZzF((*(Z3w=ZKo1(((ZG7*)ZCb1)),&Z3w)));}{T0*b1=ZLo1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}ZXw(((T7*)a1),ZMo1);
ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZNo1);ZQs(ZuI(_t),a1);ZXw(((T7*)a1),ZOo1);if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZXw(((T7*)a1),ZFo1);
}ZXw(((T7*)a1),ZPo1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZQo1);}else if(ZjW(_t)){}else if(Z4_(_t)){ZXw(((T7*)a1),ZRo1);ZXw(((T7*)a1),Zkc);
ZXw(((T7*)a1),ZSo1);ZQs(ZuI(_t),a1);ZXw(((T7*)a1),ZTo1);if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZXw(((T7*)a1),ZFo1);}ZXw(((T7*)a1),ZUo1);
ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZVo1);}_i=(Z3)(((_i))-(Zrs(1)));}}if(Z4_(((C)->Z0c))){ZXw(((T7*)a1),ZWo1);}ZZs(((T7*)a1),((T3)'\175'));
ZZs(((T7*)a1),((T3)'\n'));}T0*ZXo1(Ze4*C){T0*R=Zo;R=Zgc1(C,((((Zx8*)((((Z85*)(ZPj1((T82*)(Z7o1()))))->Zfc))))->ZBd));return R;}T0*Zao1=Zo;
void ZAY(Ze4*C,T0*a1){T2 _i=0;_i=ZQy((ZC3*)(((C)->Zxh)),a1);if((Z3)((_i)>((((ZC3*)(((C)->Zxh)))->ZRb)))){ZRy((ZC3*)(((C)->Zxh)),a1);}
}void ZYo1(Ze4*C,T2 a1){T2 _i=0;T0*Z221=Zo;T0*Z321=Zo;T2 Zo11=0;T2 ZGT=0;if(((C)->Zuh)){}else if(!(((C)->Zth))){(C->Zuh)=((T6)(1));}else
if((a1)==(Zrs(0))){ZZo1(C);}else{_i=(((ZC3*)(((C)->Zxh)))->ZRb);if((Z3)((_i)>=(Zrs(0)))){Z221=((T0*)(C));Zo11=(Z3)(((_i))+(Zrs(1)));while(!((_i)==(Zrs(0))))
{Z321=((((ZC3*)(((C)->Zxh)))->ZPb))[_i];if(!(((((Ze4*)Z321))->Zuh))){ZGT=(Z3)((((((ZC3*)(((((Ze4*)Z321))->Zxh)))->ZRb)))+(Zrs(1)));if((Z3)((ZGT)>(Zo11))){
Z221=Z321;Zo11=ZGT;}}_i=(Z3)(((_i))-(Zrs(1)));}if((Z221)==((void*)(C))){ZZo1(C);}else{ZYo1(((Ze4*)Z221),(Z3)(((a1))-((T2)(Zrs(1)))));
}}}}void ZZo1(Ze4*C){T2 ZTf=0;T2 Zqg=0;T2 _i=0;T0*_rf=Zo;(C->Zuh)=((T6)(1));ZTf=(((Zj6*)(((C)->Zug)))->Zcc);Zqg=(((T82*)(((C)->Zqb)))->Zqg);
if((Z3)((Zqg)<(Zrs(3)))){}else if((Z3)((Zqg)<(Zrs(4)))){ZTf=(Z3)(((ZTf))+((Z3)((ZTf)/(Zrs(4)))));}else if((Zqg)==(Zrs(4))){ZTf=(Z3)(((ZTf))+((Z3)((ZTf)/(Zrs(3)))));
}if((Z3)((Zqg)>=(Zrs(5)))){if((((C)->Zpg))!=((void*)(Zo))){ZTf=(Z3)(((ZTf))+(Zrs(2)));}}Z_o1((Zi4*)(ZsG),ZTf);if((((C)->ZAh))!=((void*)(Zo))){
if((Z3)(((((Z_5*)(((C)->ZAh)))->ZRb))<(Zrs(0)))){ZXm1(C,Zo);}else{_i=(((Z_5*)(((C)->ZAh)))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){_rf=((((Z_5*)(((C)->ZAh)))->ZPb))[_i];
ZXm1(C,_rf);_i=(Z3)(((_i))-(Zrs(1)));}}}ZwL((T36*)(Z0p1()),((T3)'\011'));Z7L((T36*)(Z0p1()),((C)->ZMc));Z7L((T36*)(Z0p1()),Z1p1);ZsL((T36*)(Z0p1()),(((Zj6*)(((C)->Zug)))->Zcc));
Z7L((T36*)(Z0p1()),Z2p1);_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc))))){_rf=Z2E((Zj6*)(((C)->Zug)),_i);Z3p1(_rf);_i=(Z3)(((_i))+(Zrs(1)));
}if((((C)->Zpg))!=((void*)(Zo))){Z4p1((Zh6*)(((C)->Zpg)));}}T0*ZaL(Ze4*C,T0*a1){T0*R=Zo;T0*_f=Zo;T0*_bc=Zo;R=Z8E((Zj6*)(((C)->Zug)),a1);
if((R)==((void*)(Zo))){_bc=((C)->Zqb);_f=ZGi1(((T82*)_bc),(T0*)C,a1);if((_f)==((void*)(Zo))){Zcn1(C,_bc,a1);}else{R=Z8E((Zj6*)(((C)->Zug)),a1);
if((R)==((void*)(Zo))){R=Z5p1(_f,((C)->Z0c),a1);if((R)==((void*)(Zo))){Zcn1(C,_bc,a1);}}}}return R;}void Z6p1(Ze4*C){T0*_rf=Zo;T2 _i=0;
T0*ZCb1=Zo;T0*_rc=Zo;_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc))))){_rf=Z2E((Zj6*)(((C)->Zug)),_i);Z7p1(_rf);ZCb1=_rf;if(Zo!=(ZCb1)){
switch(((T0*)ZCb1)->id){case 165:break;default:ZCb1=Zo;}}if((ZCb1)!=((void*)(Zo))){_rc=Z8G(((((ZG7*)ZCb1))->Zgc));if(((C)->Zyh)){Z8p1(((Ze4*)_rc));
}if(((C)->Zzh)){Z9p1(((Ze4*)_rc));}}_i=(Z3)(((_i))+(Zrs(1)));}Zap1((Zh8*)(Z5n1()),(T0*)C);Zbp1(C);if(((C)->Zyh)){if(ZuG(((C)->Z0c))){
_rf=Zw81(C,ZRQ);}else{_rf=Zw81(C,ZQQ);ZUK(_rf);}}if(((C)->Zzh)){if(ZuG(((C)->Z0c))){_rf=Zw81(C,ZPQ);}else{_rf=Zw81(C,Z9R);ZUK(_rf);}}
}T0*ZCH(Ze4*C,T0*a1){T0*R=Zo;T0*_fn=Zo;T0*Zcp1=Zo;T0*Zdp1=Zo;Zcp1=((((ZS7*)a1))->Z0c);if((C)==((void*)(Z8G(Zcp1)))){R=a1;}else{Zdp1=((C)->Z0c);
if(Zo!=(Zdp1)){switch(((T0*)Zdp1)->id){case 277:break;default:Zdp1=Zo;}}if((Zdp1)!=((void*)(Zo))){_fn=((((ZS7*)a1))->Zkc);}else{_fn=ZuY((T82*)(((C)->Zqb)),ZbK(Zcp1),((((ZS7*)a1))->Zkc));
}R=ZEn1(C,_fn);}return R;}void Zep1(Ze4*C,T0*a1,T0*a2){T2 _i=0;T0*_gl=Zo;(C->ZMc)=a2;(C->Zrf)=Zbx(((T7*)a2));{Zj6*n=((Zj6*)Zh(sizeof(*n)));
*n=ZGi;{Zj6*C1=n;Z7E(C1,Zft(193));}(C->Zug)=((T0*)n);}Z8D((Z14*)(Zfp1),(T0*)C,a2);(C->Zuh)=((T6)(1));(C->Z0c)=a1;{ZC3*n=((ZC3*)Zh(sizeof(*n)));
*n=Zze;ZSy(n,(T2)(Zrs(16)));(C->Zxh)=((T0*)n);}(C->Zqb)=ZbK(a1);(C->Zfe)=Z3P(a1);(C->_id)=(T2)(ZQY((T40*)(Zgp1()),a2));ZhG((T41*)(Z1G));
{Zc3*n=((Zc3*)Zh(sizeof(*n)));*n=Zae;Zz51(n,(T0*)C);(C->Zof)=((T0*)n);}if(Z5T(a1)){ZeL(C);ZKj1((T82*)(((C)->Zqb)),a1);}if(ZQS(a1)){_gl=ZbN(a1);
_i=((((ZY*)_gl))->ZSb);while(!((Z3)((_i)>(((((ZY*)_gl))->ZRb))))){if((Z8G(ZMx(((ZY*)_gl),_i)))!=((void*)(Zo))){}_i=(Z3)(((_i))+(Zrs(1)));
}}}void Z5V(Ze4*C,T0*a1){T0*_wa=Zo;T2 _i=0;T0*ZCb1=Zo;T0*_t=Zo;T6 Zhp1=0;_wa=ZKS(C);Zhp1=((T6)((T6)(((((T41*)(Z1G))->ZPk))&&((T6)((((T82*)(((C)->Zqb)))->Zhg))))));
if((_wa)==((void*)(Zo))){if(ZKN(C)){ZZs(((T7*)a1),((T3)'\173'));ZQs(((C)->_id),a1);if(Zhp1){ZZs(((T7*)a1),((T3)'\054'));ZXw(((T7*)a1),ZxO);
}ZZs(((T7*)a1),((T3)'\175'));}else if(Zhp1){ZZs(((T7*)a1),((T3)'\173'));ZXw(((T7*)a1),ZxO);ZZs(((T7*)a1),((T3)'\175'));}else{Z8Z(((C)->Z0c),a1);
}}else{ZZs(((T7*)a1),((T3)'\173'));if(ZKN(C)){ZQs(((C)->_id),a1);ZZs(((T7*)a1),((T3)'\054'));}if(Zhp1){ZXw(((T7*)a1),ZxO);ZZs(((T7*)a1),((T3)'\054'));
}_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){ZCb1=ZDA(((ZT8*)_wa),_i);_t=((((ZG7*)ZCb1))->Zgc);Z8Z(_t,a1);_i=(Z3)(((_i))-(Zrs(1)));
if((Z3)((_i)>(Zrs(0)))){ZZs(((T7*)a1),((T3)'\054'));}}ZZs(((T7*)a1),((T3)'\175'));}}T0*Zip1(Ze4*C,T0*a1){T0*R=Zo;T0*Zjp1=Zo;T0*ZYb=Zo;
T0*Zkp1=Zo;Zjp1=ZXj1((T82*)(((C)->Zqb)),(T0*)C,a1);if((Zjp1)!=((void*)(Zo))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Z5l;((((ZD8*)(n)))->Zxb)=(((((ZB8*)a1))->Zxb));
ZYb=((T0*)n);}{ZZ6*n=((ZZ6*)Zh(sizeof(*n)));*n=Zkj;Zlp1(n,ZYb,((((ZI7*)Zjp1))->Zkc));Zkp1=((T0*)n);}{Z47*n=((Z47*)Zh(sizeof(*n)));*n=Zwj;
Zmp1(n,Zo,Zkp1,Zo);R=((T0*)n);}}return R;}void Zfo1(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void Znp1(Ze4*C){T2 _i=0;T0*Zop1=Zo;
T6 ZBL=0;T0*_rf=Zo;T0*_ct=Zo;T0*_t=Zo;T0*ZCb1=Zo;T0*Zln1=Zo;T0*_s=Zo;if(((C)->Zth)){_ct=((C)->Z0c);Z_o1((Zi4*)(ZsG),(T2)(Zrs(1)));Zop1=Zpp1;
ZBw(((T7*)Zop1),Zqp1);ZQs(((C)->_id),Zop1);ZXw(((T7*)Zop1),Zrp1);ZQs(ZuI(_ct),Zop1);if(ZaH(_ct)){ZZs(((T7*)Zop1),((T3)'\052'));}ZXw(((T7*)Zop1),Zsp1);
ZyI((Zi4*)(ZsG),Zop1);Z7I((Zi4*)(ZsG),Ztp1);if(ZuG(_ct)){_t=((((ZY*)(ZbN(_ct)))->ZPb))[Zrs(0)];_s=ZvF(16,ZHo);((((T7*)(((T7*)_s))))->Zcc)=(Zrs(0));
ZXU(_t,_s);Z7I((Zi4*)(ZsG),Zup1);ZtI((Zi4*)(ZsG),(T11)(ZuI(_t)));if(Z5T(_t)){Z7I((Zi4*)(ZsG),Zvp1);}else{Z7I((Zi4*)(ZsG),Zwp1);}Z7I((Zi4*)(ZsG),Zxp1);
Z7I((Zi4*)(ZsG),_s);Z7I((Zi4*)(ZsG),Zyp1);}else{Z7I((Zi4*)(ZsG),Zzp1);ZBL=((T6)(0));_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc)))))
{_rf=Z2E((Zj6*)(((C)->Zug)),_i);ZCb1=_rf;if(Zo!=(ZCb1)){switch(((T0*)ZCb1)->id){case 165:break;default:ZCb1=Zo;}}if((ZCb1)!=((void*)(Zo))){
if(ZBL){Z7I((Zi4*)(ZsG),ZAp1);}else{ZBL=((T6)(1));}ZBp1(((ZG7*)ZCb1));}else{Zln1=_rf;if(Zo!=(Zln1)){switch(((T0*)Zln1)->id){case 502:
break;default:Zln1=Zo;}}if((Zln1)!=((void*)(Zo))){if(ZBL){Z7I((Zi4*)(ZsG),ZCp1);}else{ZBL=((T6)(1));}ZDp1(((ZO7*)Zln1));}}_i=(Z3)(((_i))+(Zrs(1)));
}}Z7I((Zi4*)(ZsG),ZEp1);}}T0*ZsY(Ze4*C){T0*R=Zo;T0*_bc=Zo;_bc=((C)->Zqb);R=ZLj1((T82*)(((C)->Zqb)),((C)->Z0c));return R;}T0*ZFp1=Zo;T0*Z5n1(void){
if(ZDI==0){ZDI=1;{{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZGk;ZCI=((T0*)n);}}}return ZCI;}T0*Z0p1(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));
*n=M36;ZQK=((T0*)n);}}}return ZQK;}void ZGp1(Ze4*C){T0*_rf=Zo;T2 _i=0;T0*_rc=Zo;T0*_rt=Zo;_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc)))))
{_rf=Z2E((Zj6*)(((C)->Zug)),_i);ZHp1(_rf);_rt=ZqG(_rf);if((_rt)!=((void*)(Zo))){if(ZVO(_rt)){}else{_rc=Z8G(_rt);}}_i=(Z3)(((_i))+(Zrs(1)));
}if((((C)->Zpg))!=((void*)(Zo))){ZIp1((Zh6*)(((C)->Zpg)));}}T2 Zco1(Ze4*C,T0*a1){T2 R=0;T0*_wa=Zo;T0*_t=Zo;T2 _i=0;if(ZKN(C)){R=sizeof(T1);
}_wa=ZKS(C);_i=((((ZT8*)_wa))->ZRb);while(!((ZDA(((ZT8*)_wa),_i))==((void*)(a1)))){_t=(((ZG7*)(ZDA(((ZT8*)_wa),_i)))->Zgc);R=(Z3)(((R))+(ZjZ(_t)));
_i=(Z3)(((_i))-(Zrs(1)));}return R;}void ZJp1(Ze4*C,T0*a1){if(((C)->Zth)){ZMZ(((C)->Z0c),a1);}}void ZeL(Ze4*C){if(!(((C)->Zth))){(C->Zth)=((T6)(1));
if((((T82*)(((C)->Zqb)))->Zhg)){((((T41*)((T41*)(Z1G))))->ZPk)=(1);}(C->Zuh)=((T6)(0));ZKp1((T0*)C,((C)->Zof));ZhG((T41*)(Z1G));}}T0*ZQn1(void){
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
ZaP;}void Zbp1(Ze4*C){T0*_ct=Zo;if(!(((C)->ZCh))){(C->ZCh)=((T6)(1));_ct=((C)->Z0c);if((T6)(((T6)((Znk1((T82*)(ZbK(_ct))))&&((T6)(((C)->Zth)))))||((T6)((((T41*)(Z1G))->ZJk))))){
ZdK((Zr6*)(Zgo1()));Zik1((T82*)(((C)->Zqb)),(T0*)C);(C->Zpg)=Z8K((Zr6*)(Zgo1()),_ct);}}}void ZLp1(Ze4*C,T0*a1){T2 _i=0;T0*_wa=Zo;T0*ZCb1=Zo;
T0*_ct=Zo;T0*_t=Zo;T0*Zkc=Zo;T6 ZMp1=0;T0*Zkn1=Zo;_ct=((C)->Z0c);ZXw(((T7*)a1),ZNp1);if(ZaH(_ct)){ZMp1=((T6)(ZKN((Ze4*)(Z8G(_ct)))));
if(ZMp1){ZXw(((T7*)a1),ZOp1);}ZXw(((T7*)a1),ZPp1);}ZXw(((T7*)a1),ZQp1);ZNS(_ct,a1);ZXw(((T7*)a1),ZRp1);if(ZaH(_ct)){ZXw(((T7*)a1),ZSp1);
}else{ZXw(((T7*)a1),ZTp1);}ZXw(((T7*)a1),ZUp1);_wa=ZKS(C);if((_wa)!=((void*)(Zo))){_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){ZCb1=ZDA(((ZT8*)_wa),_i);
Zkc=(((ZB8*)(((((ZG7*)ZCb1))->Zkc)))->Zre);_t=ZvG(((((ZG7*)ZCb1))->Zgc));if(ZXF(_t)){ZXw(((T7*)a1),ZVp1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZWp1);
ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZVo1);}_i=(Z3)(((_i))-(Zrs(1)));}_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){ZCb1=ZDA(((ZT8*)_wa),_i);
Zkc=(((ZB8*)(((((ZG7*)ZCb1))->Zkc)))->Zre);_t=ZvG(((((ZG7*)ZCb1))->Zgc));if(ZaH(_t)){Zkn1=(((Ze4*)(Z8G(_t)))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(0)))){
ZXw(((T7*)a1),ZXp1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZYp1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZZp1);if(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1))){
_t=(((Ze4*)((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZPb))[Zrs(0)]))->Z0c);ZZs(((T7*)a1),((T3)'r'));}else{ZZs(((T7*)a1),((T3)'X'));}ZQs(ZuI(_t),a1);
ZXw(((T7*)a1),Z_p1);if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZXw(((T7*)a1),ZFo1);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
ZXw(((T7*)a1),ZGo1);}}if(((Z3)(((((((ZC3*)(((((Zc3*)Zkn1))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1))){ZZs(((T7*)a1),((T3)'\050'));ZNS(_t,a1);
ZZs(((T7*)a1),((T3)'\051'));}ZXw(((T7*)a1),Z0q1);}}else if(ZuG(_t)){if((Zw81(C,ZAQ))==((void*)(Zo))){ZsS(_t,ZJo1);ZxF((T75*)(ZyF));{T76
Z3w;ZzF((*(Z3w=ZKo1(((ZG7*)ZCb1)),&Z3w)));}{T0*b1=ZLo1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}ZXw(((T7*)a1),Z1q1);ZQs(ZuI(_t),a1);ZXw(((T7*)a1),Z2q1);
if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZXw(((T7*)a1),ZFo1);}ZXw(((T7*)a1),Z3q1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),Z4q1);ZXw(((T7*)a1),Zkc);
ZXw(((T7*)a1),Z5q1);}else if(ZjW(_t)){}else if(Z4_(_t)){ZXw(((T7*)a1),Z1q1);ZQs(ZuI(_t),a1);ZXw(((T7*)a1),Z6q1);if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){
ZXw(((T7*)a1),ZFo1);}ZXw(((T7*)a1),Z7q1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),Z8q1);ZXw(((T7*)a1),Zkc);ZXw(((T7*)a1),ZGM);}_i=(Z3)(((_i))-(Zrs(1)));
}}if(ZMp1){ZXw(((T7*)a1),ZdI);}ZXw(((T7*)a1),Z9q1);}T0*ZTn1=Zo;void Zaq1(Ze4*C){T2 _i=0;T6 ZBL=0;T0*_rf=Zo;T0*_ct=Zo;T0*ZCb1=Zo;T0*Zln1=Zo;
if(((C)->Zth)){_ct=((C)->Z0c);Z7I((Zi4*)(ZsG),Zbq1);ZtI((Zi4*)(ZsG),(T11)(ZuI(_ct)));Z7I((Zi4*)(ZsG),Zcq1);ZBL=((T6)(0));_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc)))))
{_rf=Z2E((Zj6*)(((C)->Zug)),_i);ZCb1=_rf;if(Zo!=(ZCb1)){switch(((T0*)ZCb1)->id){case 165:break;default:ZCb1=Zo;}}Zln1=_rf;if(Zo!=(Zln1)){
switch(((T0*)Zln1)->id){case 502:break;default:Zln1=Zo;}}if((T6)(((ZCb1)!=((void*)(Zo)))||((T6)((Zln1)!=((void*)(Zo)))))){if(ZBL){Z7I((Zi4*)(ZsG),Zdq1);
}else{ZcH((Zi4*)(ZsG),((T3)'\042'));ZBL=((T6)(1));}Z7I((Zi4*)(ZsG),(((ZB8*)(((((ZS7*)_rf))->Zkc)))->Zre));}_i=(Z3)(((_i))+(Zrs(1)));}
if(!(ZBL)){Z7I((Zi4*)(ZsG),Zeq1);}else{ZcH((Zi4*)(ZsG),((T3)'\042'));}Z7I((Zi4*)(ZsG),Zfq1);}}void Zgq1(Ze4*C){if(((C)->Zth)){Z_o1((Zi4*)(ZsG),(T2)(Zrs(1)));
ZXZ(((C)->Z0c));}}void Zhq1(Ze4*C){if(((C)->Zth)){Z_o1((Zi4*)(ZsG),(T2)(Zrs(4)));ZZZ(((C)->Z0c));}}T0*ZRn1=Zo;void ZSN(Ze4*C,T0*a1){ZXw(((T7*)a1),Z0O);
ZQs(((C)->_id),a1);ZXw(((T7*)a1),Ziq1);ZQs(((C)->_id),a1);ZXw(((T7*)a1),Zjq1);ZQs(((C)->_id),a1);ZXw(((T7*)a1),Zkq1);ZQs(((C)->_id),a1);
ZXw(((T7*)a1),Zlq1);ZNN(C,(T6)(1),a1);ZXw(((T7*)a1),Zmq1);}T0*ZKS(Ze4*C){T0*R=Zo;T0*ZCb1=Zo;T2 _i=0;if((((C)->ZBh))==((void*)(Zo))){_i=Zrs(1);
while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc))))){ZCb1=Z2E((Zj6*)(((C)->Zug)),_i);if(Zo!=(ZCb1)){switch(((T0*)ZCb1)->id){case 165:break;
default:ZCb1=Zo;}}if((ZCb1)!=((void*)(Zo))){if((((C)->ZBh))==((void*)(Zo))){{ZT8*n=((ZT8*)Zh(sizeof(*n)));*n=Zdl;ZFA(n,(T2)(Zrs(4)),(T2)(Zrs(1)));
(C->ZBh)=((T0*)n);}}ZEA((ZT8*)(((C)->ZBh)),ZCb1);}_i=(Z3)(((_i))+(Zrs(1)));}if((((C)->ZBh))!=((void*)(Zo))){ZFn1(((C)->ZBh));}}R=((C)->ZBh);
return R;}T6 Znq1(Ze4*C){T6 R=0;T2 _i=0;T0*_rc=Zo;_i=(Z3)(((((((ZC3*)((((Zc3*)(((C)->Zof)))->Z9e))))->ZRb)))+(Zrs(1)));while(!((T6)((R)||((T6)((_i)==(Zrs(0)))))))
{_rc=(((((ZC3*)((((Zc3*)(((C)->Zof)))->Z9e))))->ZPb))[(_i)-(Zrs(1))];if((_rc)==((void*)(C))){R=((T6)(Zin1(C)));}else{R=((T6)(ZBZ(((((Ze4*)_rc))->Z0c))));
}_i=(Z3)(((_i))-(Zrs(1)));}return R;}T0*Zgp1(void){if(ZBk1==0){ZBk1=1;{{T40*n=((T40*)Zh(sizeof(*n)));*n=M40;ZAk1=((T0*)n);ZTY(n);}}}return
ZAk1;}void Zoq1(Ze4*C,T0*a1){T0*_ct=Zo;_ct=((C)->Z0c);ZUS(a1,Zpq1);ZJ51(a1,(T11)(((C)->_id)));ZXS(a1,((T3)'\040'));Zqq1(_ct,a1);if(ZaH(_ct)){
ZUS(a1,Zrq1);if(((C)->Zth)){ZUS(a1,Zsq1);if((T6)((ZaH(_ct))&&((T6)(!(ZKN(C)))))){ZUS(a1,Ztq1);}else{ZUS(a1,Zuq1);}}else{ZUS(a1,Zvq1);
}ZXS(a1,((T3)'\n'));ZH51((Zc3*)(((C)->Zof)),a1);}}void Zwq1(Ze4*C,T76 a1){T2 _i=0;T0*_rf=Zo;(C->Zvh)=((T6)(1));_i=(((Zj6*)(((C)->Zug)))->Zcc);
while(!((Z3)((_i)<(Zrs(1))))){_rf=Z2E((Zj6*)(((C)->Zug)),_i);if(!(Zxq1(_rf))){Zyq1(_rf,a1);}_i=(Z3)(((_i))-(Zrs(1)));}(C->Zvh)=((T6)(0));
}void Z9p1(Ze4*C){T2 _i=0;T0*_rc=Zo;if(!(((C)->Zzh))){ZhG((T41*)(Z1G));(C->Zzh)=((T6)(1));((((T41*)((T41*)(Z1G))))->ZOk)=(1);}_i=(Z3)(((((((ZC3*)((((Zc3*)(((C)->Zof)))->Z9e))))->ZRb)))+(Zrs(1)));
while(!((_i)==(Zrs(0)))){_rc=(((((ZC3*)((((Zc3*)(((C)->Zof)))->Z9e))))->ZPb))[(_i)-(Zrs(1))];if(!(((((Ze4*)_rc))->Zzh))){Z9p1(((Ze4*)_rc));
}_i=(Z3)(((_i))-(Zrs(1)));}}void Zzq1(Ze4*C,T0*a1){T0*ZCb1=Zo;T2 _i=0;_i=Zrs(1);while(!((Z3)((_i)>((((Zj6*)(((C)->Zug)))->Zcc))))){ZCb1=Z2E((Zj6*)(((C)->Zug)),_i);
if(Zo!=(ZCb1)){switch(((T0*)ZCb1)->id){case 165:break;default:ZCb1=Zo;}}if((ZCb1)!=((void*)(Zo))){ZCb1=ZaL(((Ze4*)a1),((((ZG7*)ZCb1))->Zkc));
if(Zo!=(ZCb1)){switch(((T0*)ZCb1)->id){case 165:break;default:ZCb1=Zo;}}}_i=(Z3)(((_i))+(Zrs(1)));}}T0*ZEn1(Ze4*C,T0*a1){T0*R=Zo;R=ZaL(C,a1);
if((R)==((void*)(Zo))){ZzF(((((ZB8*)a1))->Zxb));{T0*b1=ZAq1;ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)a1))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZBq1;
ZXw((T7*)(ZwF),b1);}ZsS(((C)->Z0c),ZMJ);ZEF((T75*)(ZyF));}return R;}void ZOn1(T0*a1,T0*a2,T0*a3,T2 a4){T76 _sp={Zo,Zo,0};T0*_bc=Zo;T0*_wa=Zo;
T0*ZLn1=Zo;T0*ZCq1=Zo;T0*ZCb1=Zo;T0*_rf=Zo;T0*ZDq1=Zo;T0*_aw=Zo;_bc=ZbK(a1);{T76*C1=&_sp;T0*b1=_bc;Z4j1(C1,(T2)(Zrs(1)),(T2)(Zrs(1)),((((T82*)b1))->_id),b1);
}{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z6j1(n,a2,_sp);ZLn1=((T0*)n);}{ZN8*n=((ZN8*)Zh(sizeof(*n)));*n=Zal;ZEq1(n,_bc,ZLn1,a3);_wa=((T0*)n);
}ZCb1=ZFq1(((ZN8*)_wa),a1,ZLn1);((((ZG7*)(((ZG7*)ZCb1))))->Z5k)=(a4);((((ZB8*)(((ZB8*)ZLn1))))->Z4n)=(ZCb1);ZDq1=Zpx(((T7*)ZGq1),a2);
ZDq1=(((void)((T26*)(ZQn1()))),ZAS(ZDq1));{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z6j1(n,ZDq1,_sp);ZCq1=((T0*)n);}{Z9a*n=((Z9a*)Zh(sizeof(*n)));
*n=Z1n;ZHq1(n,_bc,ZCq1,ZLn1);_aw=((T0*)n);}_rf=ZIq1(((Z9a*)_aw),a1,ZCq1);}void Z8p1(Ze4*C){T2 _i=0;T0*_rc=Zo;if(!(((C)->Zyh))){ZhG((T41*)(Z1G));
(C->Zyh)=((T6)(1));((((T41*)((T41*)(Z1G))))->ZOk)=(1);}_i=(Z3)(((((((ZC3*)((((Zc3*)(((C)->Zof)))->Z9e))))->ZRb)))+(Zrs(1)));while(!((_i)==(Zrs(0))))
{_rc=(((((ZC3*)((((Zc3*)(((C)->Zof)))->Z9e))))->ZPb))[(_i)-(Zrs(1))];if(!(((((Ze4*)_rc))->Zyh))){Z8p1(((Ze4*)_rc));}_i=(Z3)(((_i))-(Zrs(1)));
}}T0*ZXV(Ze4*C,T0*a1,T0*a2){T0*R=Zo;R=Z8E((Zj6*)(((C)->Zug)),a2);if((R)==((void*)(Zo))){ZJq1(a1);R=Z8E((Zj6*)(((C)->Zug)),a2);}if((R)==((void*)(Zo))){
ZzF(((((ZB8*)a2))->Zxb));{T0*b1=ZvF(34,"There is no such feature in class ");ZXw((T7*)(ZwF),b1);}{T0*b1=(((T80*)((((T82*)(ZKq1(a1)))->Zkc)))->Zre);
ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(110,". (Feature \"call\" is available for all agents and feature \"item\" is available only for FUNCTION or PREDICATE.)");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}return R;}void ZLq1(Ze4*C){if(((C)->Zth)){if((Z3)((((C)->ZDh))<(Zrs(1)))){Zc_(((C)->Z0c));(C->ZDh)=Zrs(1);
}}}T6 ZKN(Ze4*C){T6 R=0;if((((C)->Zwh))==(Zrs(0))){if(Z5T(((C)->Z0c))){(C->Zwh)=Zrs(-1);}else if(Z2H(((C)->Z0c))){(C->Zwh)=Zrs(1);}else
if(((C)->Zth)){if(((((T84*)(ZFI))->Zcf))==(Zrs(1))){if(ZMq1((T0*)C)){(C->Zwh)=Zrs(1);}else{(C->Zwh)=Zrs(-1);}}else{(C->Zwh)=Zrs(1);}}
}R=((T6)((((C)->Zwh))==(Zrs(1))));return R;}void ZNq1(Ze4*C){if(((C)->Zth)){if((Z3)((((C)->ZDh))<(Zrs(2)))){Ze_(((C)->Z0c));(C->ZDh)=Zrs(2);
}}}void ZOq1(Ze4*C){T2 _i=0;T0*ZPq1=Zo;if(((C)->Zth)){if((Z3)((((C)->ZDh))<(Zrs(3)))){if((T6)((Z4_(((C)->Z0c)))&&((T6)((ZKS(C))!=((void*)(Zo)))))){
_i=(((ZT8*)(ZKS(C)))->ZRb);while(!((_i)==(Zrs(0)))){ZPq1=(((ZG7*)(ZDA((ZT8*)(ZKS(C)),_i)))->Zgc);if(Z5T(ZPq1)){ZOq1((Ze4*)(Z8G(ZPq1)));
}_i=(Z3)(((_i))-(Zrs(1)));}}ZfT(((C)->Z0c));(C->ZDh)=Zrs(3);}}}void ZQq1(Ze4*C){if(((C)->Zth)){if((Z3)((((C)->ZDh))<(Zrs(4)))){Zh_(((C)->Z0c));
(C->ZDh)=Zrs(4);}}}T0*Zw81(Ze4*C,T0*a1){T0*R=Zo;T0*ZLn1=Zo;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Zzi1(n,a1);ZLn1=((T0*)n);}R=Z8E((Zj6*)(((C)->Zug)),ZLn1);
if((R)==((void*)(Zo))){R=ZaL(C,ZLn1);}return R;}void ZwS(Ze4*C){T0*ZZm1=Zo;T0*_ct=Zo;T0*_t=Zo;T2 _i=0;T0*_wa=Zo;T0*ZCb1=Zo;ZZm1=Z_m1;
((((T7*)(((T7*)ZZm1))))->Zcc)=(Zrs(0));_ct=((C)->Z0c);ZBw((T7*)(Zao1),ZRq1);ZQs(((C)->_id),Zao1);ZXw((T7*)(Zao1),ZSq1);ZQs(((C)->_id),Zao1);
if(ZaH(_ct)){ZZs((T7*)(Zao1),((T3)'\052'));}ZXw((T7*)(Zao1),ZTq1);if(ZaH(_ct)){ZXw(((T7*)ZZm1),ZUq1);}ZXw(((T7*)ZZm1),ZVq1);ZXw(((T7*)ZZm1),((C)->ZMc));
ZXw(((T7*)ZZm1),ZWq1);if((T6)((ZaH(_ct))||((T6)(ZuG(_ct))))){ZXw(((T7*)ZZm1),ZXq1);}_wa=ZKS(C);if((_wa)!=((void*)(Zo))){ZXw(((T7*)ZZm1),ZYq1);
_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){ZCb1=ZDA(((ZT8*)_wa),_i);_t=((((ZG7*)ZCb1))->Zgc);ZXw(((T7*)ZZm1),ZZq1);ZXw(((T7*)ZZm1),(((ZB8*)(((((ZG7*)ZCb1))->Zkc)))->Zre));
ZXw(((T7*)ZZm1),Z_q1);if(Z5T(_t)){ZQs(ZuI(_t),ZZm1);ZXw(((T7*)ZZm1),Z0r1);}else if(ZbT(_t)){ZXw(((T7*)ZZm1),Z1r1);}else{ZXw(((T7*)ZZm1),Z2r1);
}ZXw(((T7*)ZZm1),Z3r1);if((T6)((Z2H(_ct))&&((T6)(!((((T82*)(ZbK(_ct)))->Zhg)))))){ZXw(((T7*)ZZm1),Z4r1);}else if(ZaH(_ct)){ZXw(((T7*)ZZm1),Z5r1);
}else{ZZs(((T7*)ZZm1),((T3)'\056'));}ZZs(((T7*)ZZm1),((T3)'\137'));ZXw(((T7*)ZZm1),(((ZB8*)(((((ZG7*)ZCb1))->Zkc)))->Zre));ZXw(((T7*)ZZm1),Z6r1);
_i=(Z3)(((_i))-(Zrs(1)));if((Z3)((_i)>(Zrs(0)))){ZXw(((T7*)ZZm1),Z7r1);}}ZXw(((T7*)ZZm1),Z8r1);}ZGN((Zi4*)(ZsG),Zao1,ZZm1);}T0*Z9r1(ZO5*C){
T0*R=Zo;R=ZOG(((C)->ZGh));return R;}void Zar1(ZO5*C){ZoG(((C)->ZHh));}void Zbr1(ZO5*C,T0*a1,T2 a2){(C->ZHh)=ZjG(((C)->ZHh));}void Zcr1(ZO5*C){
T0*Zof=Zo;T0*Zdr1=Zo;T2 _i=0;if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){{T76 Z3w;Z741((Zi4*)(ZsG),(*(Z3w=Zer1(C),&Z3w)));}}Z7I((Zi4*)(ZsG),Zfr1);
if(Z5T(ZvG(Zgr1(C)))){{T76 Z3w;ZzF((*(Z3w=Zer1(C),&Z3w)));}Zhr1(ZvF(45,"Right-hand side expanded Not Yet Implemented."));}Zof=(((Ze4*)(Z8G(Z9r1(C))))->Zof);
if(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(0))){if(!(ZxV(((C)->ZHh)))){ZI01(((C)->ZHh));Z7I((Zi4*)(ZsG),Z8M);
}ZI01(((C)->ZGh));Z7I((Zi4*)(ZsG),Zir1);}else if(Z4G(((C)->ZHh))){if(ZUB(((ZK1*)(((((Zc3*)Zof))->Z8e))),Z8G(ZOG(((C)->ZHh))))){ZI01(((C)->ZGh));
Z7I((Zi4*)(ZsG),Zjr1);ZI01(((C)->ZHh));Z7I((Zi4*)(ZsG),ZGM);}else{ZI01(((C)->ZGh));Z7I((Zi4*)(ZsG),Zir1);}}else if((T6)((((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1)))&&((T6)(!(ZKN((Ze4*)((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZPb))[Zrs(0)]))))))){
ZI01(((C)->ZGh));ZcH((Zi4*)(ZsG),((T3)'\075'));Zdr1=(((Ze4*)(Z8G(Zgr1(C))))->Zof);if((T6)((((Z3)(((((((ZC3*)(((((Zc3*)Zdr1))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1)))&&((T6)(((((((ZC3*)(((((Zc3*)Zdr1))->Z9e))))->ZPb))[Zrs(0)])==((void*)((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZPb))[Zrs(0)])))))){
}else{Z7I((Zi4*)(ZsG),ZxO);ZcH((Zi4*)(ZsG),((T3)'\073'));}ZI01(((C)->ZHh));Z7I((Zi4*)(ZsG),Z8M);}else{ZI01(((C)->ZGh));ZcH((Zi4*)(ZsG),((T3)'\075'));
if(Z4G(((C)->ZHh))){Z7I((Zi4*)(ZsG),Zkr1);}ZI01(((C)->ZHh));Z7I((Zi4*)(ZsG),Zlr1);ZI01(((C)->ZGh));Z7I((Zi4*)(ZsG),Zmr1);if((T6)(((T6)(((((T41*)(Z1G))->ZPk))&&((T6)(!(Z2H(ZOG(((C)->ZGh))))))))&&((T6)(Z2H(ZOG(((C)->ZHh))))))){
Z7I((Zi4*)(ZsG),Znr1);Z7I((Zi4*)(ZsG),Zor1);ZI01(((C)->ZGh));Z7I((Zi4*)(ZsG),Zpr1);ZI01(((C)->ZGh));Z7I((Zi4*)(ZsG),Zqr1);ZI01(((C)->ZGh));
Z7I((Zi4*)(ZsG),Zrr1);}Z7I((Zi4*)(ZsG),Zsr1);ZI01(((C)->ZGh));Z7I((Zi4*)(ZsG),Ztr1);Z7I((Zi4*)(ZsG),Zur1);_i=Zrs(1);while(!((Z3)((_i)>((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1)))))))
{Z7I((Zi4*)(ZsG),Zvr1);ZtI((Zi4*)(ZsG),(T11)((((Ze4*)((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZPb))[(_i)-(Zrs(1))]))->_id)));ZcH((Zi4*)(ZsG),((T3)'\072'));
_i=(Z3)(((_i))+(Zrs(1)));}Z7I((Zi4*)(ZsG),Zwr1);ZI01(((C)->ZGh));Z7I((Zi4*)(ZsG),Zxr1);}}T6 Zyr1(ZO5*C,T0*a1){T6 R=0;if(Zy81(ZOG(((C)->ZGh)),a1)){
if(Zy81(ZOG(((C)->ZHh)),a1)){if(Z7G(((C)->ZGh),a1)){if(Z7G(((C)->ZHh),a1)){R=((T6)(1));}}}}return R;}void Zzr1(ZO5*C,T0*a1,T0*a2){(C->ZGh)=a1;
(C->ZHh)=a2;}void Zhr1(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZAr1(ZO5*C){ZSG(((C)->ZHh));}T6 ZBr1(ZO5*C){T6 R=0;
if(ZYG(((C)->ZGh))){R=((T6)(1));}else{R=((T6)(ZYG(((C)->ZHh))));}return R;}T6 ZCr1(ZO5*C){T6 R=0;if(Z_G(((C)->ZGh))){R=((T6)(Z_G(((C)->ZHh))));
}return R;}void ZDr1(ZO5*C,T0*a1){T6 Z_M=0;Z_M=((T6)(Z3H(((C)->ZGh),a1)));Z_M=((T6)(Z3H(((C)->ZHh),a1)));}T0*ZEr1(ZO5*C,T0*a1){T0*R=Zo;
{Zn8*n=((Zn8*)Zh(sizeof(*n)));*n=ZVk;Z1N(n,(T0*)C,a1);R=((T0*)n);}return R;}T0*ZFr1(ZO5*C,T0*a1){T0*R=Zo;T0*_e=Zo;T6 ZGr1=0;T6 ZHr1=0;
if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;_e=ZFG(((C)->ZGh),a1);if((_e)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZGh)),&Z3w)));
}{T0*b1=ZIr1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}(C->ZGh)=_e;_e=ZFG(((C)->ZHh),a1);if((_e)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZHh)),&Z3w)));
}{T0*b1=ZJr1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}(C->ZHh)=_e;if(!(ZaH(ZvG(Z9r1(C))))){ZsS(ZvG(Z9r1(C)),ZvF(25," is not a reference Type."));
{T76 Z3w;ZzF((*(Z3w=Zer1(C),&Z3w)));}{T0*b1=ZvF(35," Invalid reverse assignment (VJRV).");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}if(Z4G(((C)->ZHh))){
}else if(!(ZYF(ZvG(Z9r1(C)),ZvG(Zgr1(C))))){ZGr1=((T6)(1));}else if(ZYF(ZvG(Zgr1(C)),ZvG(Z9r1(C)))){if((T6)(((T6)((!(ZtY(Z9r1(C))))&&((T6)(!(ZiY(Zgr1(C)))))))&&((T6)(!(ZiY(Z9r1(C))))))){
ZHr1=((T6)(1));}}else{((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));}if(ZGr1){{T76 Z3w;ZzF((*(Z3w=Zer1(C),&Z3w)));
}{T0*b1=ZvF(440,"Invalid assignment attempt. The left-hand side expression must conforms with the right-hand side. Note: the previous constraint is more strict than ETL is, but, the SmartEiffel team is convinced that this is better for your safety to enforce this extra constraint. If you cannot work around, feel free to post your problem in our mailing list. If you agree with us, feel free to help us to convince other people (Wed Mar 19 2003). D.Colnet.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}if(ZHr1){ZsS(Zgr1(C),ZvF(6," is a "));ZsS(Z9r1(C),ZvF(55,". Simple assignment is allowed (\"\?=\" is not necessary)."));
{T76 Z3w;ZzF((*(Z3w=Zer1(C),&Z3w)));}ZoK((T75*)(ZyF));}{T76 Z3w;ZJY((*(Z3w=ZGG(((C)->ZHh)),&Z3w)),ZOG(((C)->ZHh)),Z9r1(C));}R=((T0*)(C));
}else{{ZO5*n=((ZO5*)Zh(sizeof(*n)));*n=ZIh;Zzr1(n,((C)->ZGh),((C)->ZHh));R=((T0*)n);}R=ZFr1(((ZO5*)R),a1);}return R;}void ZKr1(ZO5*C){
ZzH(((C)->ZHh));}T0*Zgr1(ZO5*C){T0*R=Zo;R=ZOG(((C)->ZHh));return R;}T76 Zer1(ZO5*C){T76 R={Zo,Zo,0};{T76 Z3w;R=(*(Z3w=ZGG(((C)->ZGh)),&Z3w));
}return R;}
#ifdef __cplusplus
}
#endif

