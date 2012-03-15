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
T0*ZH41(Z43*C,T0*a1,T0*a2){T0*R=Zo;{T76 Z3w;ZzF((*(Z3w=ZI41(C),&Z3w)));}ZJ41(((((ZB8*)a1))->Zxb),ZvF(42,"An attribute must not be undefined (VDUS)."));
ZEJ(((T82*)a2),a1);return R;}void ZJ41(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T6 ZK41(Z43*C,T0*a1,T0*a2){
T6 R=0;if((((C)->Zgc))!=((void*)(ZvH(a1)))){if((T6)(((((C)->Zgc))==((void*)(Zo)))||((T6)((ZvH(a1))==((void*)(Zo)))))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));
}{T76 Z3w;ZJ41((*(Z3w=ZI41(C),&Z3w)),ZHJ);}}}if((Zo)!=((void*)(ZIJ(a1)))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;ZJ41((*(Z3w=ZI41(C),&Z3w)),ZJJ);
}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){if((((C)->Zgc))!=((void*)(Zo))){if(!(ZKJ(ZvH(a1),((C)->Zgc),a2,(T6)(0)))){{T0*b1=ZLJ;ZXw((T7*)(ZwF),b1);
}{T0*b1=ZDF(((((Ze4*)a2))->Z0c));ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){
}R=((T6)(((((T75*)(ZyF))->ZAg))==(Zrs(0))));if(R){ZL41(C,a1);}return R;}void ZL41(Z43*C,T0*a1){if((((T41*)(Z1G))->ZJk)){if((((C)->ZCb))==((void*)(Zo))){
(C->ZCb)=ZOJ(a1);}else if((ZOJ(a1))==((void*)(Zo))){ZPJ(a1,((C)->ZCb));}}}void ZM41(Z43*C,T0*a1){T2 _i=0;T0*_fn=Zo;T0*_f=Zo;(C->Zqb)=(((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),Zrs(1))))->Zxb)).Zqb);
_i=Zrs(1);while(!((Z3)((_i)>(ZSJ((Zx8*)(((C)->Zfc))))))){_fn=ZRJ((Zx8*)(((C)->Zfc)),_i);_f=ZED(((Z25*)a1),_fn);if((_f)!=((void*)(Zo))){
_fn=((((Zx8*)(((((Z85*)_f))->Zfc))))->ZBd);ZzF(((((ZB8*)_fn))->Zxb));ZzF((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),_i)))->Zxb));{T0*b1=ZvF(29,"Double definition of feature ");
ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)_fn))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}else{ZBD(((Z25*)a1),(T0*)C,_fn);
}_i=(Z3)(((_i))+(Zrs(1)));}}T0*ZN41(Z43*C,T0*a1,T0*a2){T0*R=Zo;T0*ZUJ=Zo;ZzF(((((ZB8*)a1))->Zxb));ZUJ=ZVJ((Zx8*)(((C)->Zfc)),((((ZB8*)a1))->Z3n));
if((ZUJ)!=((void*)(Zo))){ZWJ(((ZB8*)ZUJ),a2);}((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));R=ZH41(C,a1,a2);
if((R)!=((void*)(Zo))){((((ZM3*)(((ZM3*)R))))->Zec)=(((C)->Zec));ZL41(C,R);}else{ZEJ(((T82*)a2),a1);}return R;}void ZO41(Z43*C,T0*a1,T0*a2,T0*a3){
((((Z43*)(C)))->Zfc)=(a1);(C->Zgc)=a2;(C->Zhc)=a3;}T0*ZP41(Z43*C,T0*a1,T0*a2){T0*R=Zo;T0*_rc=Zo;_rc=Z8G(a1);R=Z8E(((Zj6*)(((((Ze4*)_rc))->Zug))),a2);
if(Zo!=(R)){switch(((T0*)R)->id){case 556:break;default:R=Zo;}}if((R)==((void*)(Zo))){{ZE7*n=((ZE7*)Zh(sizeof(*n)));*n=Z4k;ZZJ(n,a1,a2,(T0*)C);
R=((T0*)n);}}return R;}T6 ZQ41(Z43*C,T0*a1){T6 R=0;if((((C)->Zgc))==((void*)(Zo))){R=((T6)((ZvH(a1))!=((void*)(Zo))));}else{R=((T6)((ZvH(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZHJ;ZXw((T7*)(ZwF),b1);}}else{R=((T6)((ZIJ(a1))!=((void*)(Zo))));if(R){{T0*b1=ZJJ;ZXw((T7*)(ZwF),b1);}}}ZL41(C,a1);return
R;}T76 ZI41(Z43*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((((Zx8*)(((C)->Zfc))))->ZBd)))->Zxb);return R;}T0*ZR41(Z63*C,T0*a1,T0*a2){T0*R=Zo;{T76
Z3w;ZzF((*(Z3w=ZS41(C),&Z3w)));}ZT41(((((ZB8*)a1))->Zxb),ZvF(42,"An attribute must not be undefined (VDUS)."));ZEJ(((T82*)a2),a1);return
R;}void ZT41(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T6 ZU41(Z63*C,T0*a1,T0*a2){T6 R=0;if((((C)->Zgc))!=((void*)(ZvH(a1)))){
if((T6)(((((C)->Zgc))==((void*)(Zo)))||((T6)((ZvH(a1))==((void*)(Zo)))))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;ZT41((*(Z3w=ZS41(C),&Z3w)),ZHJ);
}}}if((Zo)!=((void*)(ZIJ(a1)))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;ZT41((*(Z3w=ZS41(C),&Z3w)),ZJJ);}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){
if((((C)->Zgc))!=((void*)(Zo))){if(!(ZKJ(ZvH(a1),((C)->Zgc),a2,(T6)(0)))){{T0*b1=ZLJ;ZXw((T7*)(ZwF),b1);}{T0*b1=ZDF(((((Ze4*)a2))->Z0c));
ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){}R=((T6)(((((T75*)(ZyF))->ZAg))==(Zrs(0))));
if(R){ZV41(C,a1);}return R;}void ZV41(Z63*C,T0*a1){if((((T41*)(Z1G))->ZJk)){if((((C)->ZCb))==((void*)(Zo))){(C->ZCb)=ZOJ(a1);}else if((ZOJ(a1))==((void*)(Zo))){
ZPJ(a1,((C)->ZCb));}}}void ZW41(Z63*C,T0*a1){T2 _i=0;T0*_fn=Zo;T0*_f=Zo;(C->Zqb)=(((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),Zrs(1))))->Zxb)).Zqb);
_i=Zrs(1);while(!((Z3)((_i)>(ZSJ((Zx8*)(((C)->Zfc))))))){_fn=ZRJ((Zx8*)(((C)->Zfc)),_i);_f=ZED(((Z25*)a1),_fn);if((_f)!=((void*)(Zo))){
_fn=((((Zx8*)(((((Z85*)_f))->Zfc))))->ZBd);ZzF(((((ZB8*)_fn))->Zxb));ZzF((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),_i)))->Zxb));{T0*b1=ZvF(29,"Double definition of feature ");
ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)_fn))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}else{ZBD(((Z25*)a1),(T0*)C,_fn);
}_i=(Z3)(((_i))+(Zrs(1)));}}T0*ZX41(Z63*C,T0*a1,T0*a2){T0*R=Zo;T0*ZUJ=Zo;ZzF(((((ZB8*)a1))->Zxb));ZUJ=ZVJ((Zx8*)(((C)->Zfc)),((((ZB8*)a1))->Z3n));
if((ZUJ)!=((void*)(Zo))){ZWJ(((ZB8*)ZUJ),a2);}((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));R=ZR41(C,a1,a2);
if((R)!=((void*)(Zo))){((((ZM3*)(((ZM3*)R))))->Zec)=(((C)->Zec));ZV41(C,R);}else{ZEJ(((T82*)a2),a1);}return R;}void ZY41(Z63*C,T0*a1,T0*a2,T0*a3){
T2 _i=0;((((Z63*)(C)))->Zfc)=(a1);(C->Zgc)=a2;(C->Z3e)=a3;_i=ZSJ((Zx8*)(((C)->Zfc)));if((Z3)((_i)>(Zrs(1)))){_i=(Z3)(((_i))-(Zrs(1)));
{ZP*n=((ZP*)Zh(sizeof(*n)));*n=Z5c;ZHx(n,_i);(C->Z4e)=((T0*)n);}while(!((_i)==(Zrs(0)))){_i=(Z3)(((_i))-(Zrs(1)));((((ZP*)(((C)->Z4e)))->ZPb))[_i]=(ZZ41(((T88*)a3)));
}}}T0*Z_41(Z63*C,T2 a1){T0*R=Zo;if((a1)==(Zrs(1))){R=((C)->Z3e);}else{R=((((ZP*)(((C)->Z4e)))->ZPb))[(Z3)(((a1))-(Zrs(2)))];}return R;
}T0*Z051(Z63*C,T0*a1,T0*a2){T0*R=Zo;T0*_rc=Zo;_rc=Z8G(a1);R=Z8E(((Zj6*)(((((Ze4*)_rc))->Zug))),a2);if(Zo!=(R)){switch(((T0*)R)->id){case
556:break;default:R=Zo;}}if((R)==((void*)(Zo))){{ZE7*n=((ZE7*)Zh(sizeof(*n)));*n=Z4k;ZZJ(n,a1,a2,(T0*)C);R=((T0*)n);}}return R;}T6 Z151(Z63*C,T0*a1){
T6 R=0;if((((C)->Zgc))==((void*)(Zo))){R=((T6)((ZvH(a1))!=((void*)(Zo))));}else{R=((T6)((ZvH(a1))==((void*)(Zo))));}if(R){{T0*b1=ZHJ;
ZXw((T7*)(ZwF),b1);}}else{R=((T6)((ZIJ(a1))!=((void*)(Zo))));if(R){{T0*b1=ZJJ;ZXw((T7*)(ZwF),b1);}}}ZV41(C,a1);return R;}T76 ZS41(Z63*C){
T76 R={Zo,Zo,0};R=(((ZB8*)(((((Zx8*)(((C)->Zfc))))->ZBd)))->Zxb);return R;}void Z251(Z83*C){Z351(C);ZTF((((ZB8*)(((C)->ZZb)))->Zxb),((C)->ZAb),((C)->Z_b));
}T0*Z451(T0*a1,T0*a2,T0*a3){T0*R=Zo;T0*ZVF=Zo;T0*ZWF=Zo;R=a1;if(ZXF(a2)){if(ZXF(a3)){ZWF=ZDF(a3);ZVF=ZDF(a2);if((ZWF)!=((void*)(ZVF))){
if(ZYF(a2,a3)){R=ZZF(a1,a3);}else{((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));}}}}return R;}T6 Z551(Z83*C,T0*a1){
T6 R=0;T0*_tr=Zo;if((((C)->ZAb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(Z3G((Zm3*)(((C)->ZAb)),a1)));}if(R){if((((C)->Z_b))==((void*)(Zo))){
}else if(Z4G(((C)->ZYb))){if(Z5G(((C)->Z_b),a1)){R=((T6)((Z6G(((C)->Z_b),a1))!=((void*)(Zo))));}else{R=((T6)(0));}}else{R=((T6)(Z7G(((C)->ZYb),a1)));
if(R){if((((C)->Z_b))!=((void*)(Zo))){_tr=(((Ze4*)(Z8G((((ZS7*)(((C)->Z_b)))->Z0c))))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)_tr))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
R=((T6)(Z5G(((C)->Z_b),_tr)));}}}}}return R;}T0*Z651(Z83*C,T0*a1){T0*R=Zo;R=ZaG((Zm3*)(((C)->ZAb)),a1);if((R)==((void*)(Zo))){{T76 Z3w;
ZzF((*(Z3w=ZbG((Zm3*)(((C)->ZAb))),&Z3w)));}{T0*b1=ZcG;ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}return R;}void Z751(Z83*C,T0*a1,T0*a2,T0*a3){
(C->ZYb)=a1;(C->ZZb)=a2;(C->ZAb)=a3;}T0*Z851(Z83*C){T0*R=Zo;if((((T41*)(Z1G))->ZJk)){R=((T0*)(C));}else{R=Z951(C);if((R)!=((void*)(C))){
ZhG((T41*)(Z1G));}}return R;}T0*Za51(Z83*C){T0*R=Zo;(C->ZYb)=ZjG(((C)->ZYb));ZkG((Zm3*)(((C)->ZAb)));R=Z951(C);return R;}void Zb51(Z83*C){
T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){if((((C)->ZAb))!=((void*)(Zo))){Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>=(Zrs(1)))){
{T76 Z3w;ZmG((T41*)(Z1G),(*(Z3w=Zc51(C),&Z3w)),((C)->Z_b),Zof);}}}}ZoG(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){ZpG((Zm3*)(((C)->ZAb)));
}}void Z351(Z83*C){if((ZqG(((C)->Z_b)))==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZCF(((C)->Z_b)),&Z3w)));}ZzF((((ZB8*)(((C)->ZZb)))->Zxb));
Zd51(ZvF(29,"Feature found is a procedure."));}}T6 Ze51(Z83*C,T0*a1){T6 R=0;R=((T6)(Z551(C,a1)));if(R){R=((T6)(!(ZuG(ZvG(Zf51(C))))));
}return R;}void Zg51(Z83*C,T0*a1,T0*a2){ZyG(((C)->ZYb),a1,a2);ZzG((Zm3*)(((C)->ZAb)),a1,a2);}void Zh51(Z83*C){{T76 Z3w;ZzF((*(Z3w=Zc51(C),&Z3w)));
}{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void Zi51(Z83*C,T0*a1,T76
a2,T0*a3){(C->ZYb)=a1;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,(ZiQ),a2);(C->ZZb)=((T0*)n);}{Zm3*n=((Zm3*)Zh(sizeof(*n)));*n=Z1j;((((Zm3*)(n)))->Z0j)=(a3);
(C->ZAb)=((T0*)n);}}void Zj51(Z83*C,T0*a1){T0*_t=Zo;_t=ZFG(((C)->ZYb),a1);if((_t)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZYb)),&Z3w)));
}{T0*b1=ZvF(11,"Bad target.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}(C->ZYb)=_t;}void Zd51(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}void Zk51(Z83*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=Zc51(C),&Z3w)));}ZxF((T75*)(ZyF));}T2 Zl51(void){
T2 R=0;return R;}void Zm51(Z83*C,T3 a1){if((a1)==(((T3)'R'))){{T76 Z3w;ZLG(((C)->Z_b),(*(Z3w=Zc51(C),&Z3w)));}}ZMG(((C)->ZYb),a1);ZMG(((((Zm3*)(((C)->ZAb))))->Z0j),a1);
}T0*Zf51(Z83*C){T0*R=Zo;T0*ZNG=Zo;R=ZqG(((C)->Z_b));ZNG=R;if(Zo!=(ZNG)){switch(((T0*)ZNG)->id){case 267:break;default:ZNG=Zo;}}if((ZNG)!=((void*)(Zo))){
R=ZvG(ZOG(((((Zm3*)(((C)->ZAb))))->Z0j)));}return R;}void Zn51(Z83*C){T0*ZQG=Zo;T0*_rc=Zo;T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){ZQG=ZOG(((C)->ZYb));
_rc=Z8G(ZQG);Zof=((((Ze4*)_rc))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){ZRG(((C)->ZYb),((C)->Z_b));
}}ZSG(((C)->ZYb));ZTG((Zm3*)(((C)->ZAb)));}T6 Zo51(Z83*C){T6 R=0;R=((T6)(ZVG((Zm3*)(((C)->ZAb)))));if(R){}else if(Z4G(((C)->ZYb))){if((ZWG())!=((void*)(((C)->Z_b)))){
R=((T6)(ZXG(((C)->Z_b))));}}else{R=((T6)(ZYG(((C)->ZYb))));}return R;}T6 Zp51(Z83*C){T6 R=0;if(Z_G(((C)->ZYb))){if((((C)->ZAb))!=((void*)(Zo))){
R=((T6)(Z0H((Zm3*)(((C)->ZAb)))));}else{R=((T6)(1));}}return R;}T6 Zq51(Z83*C,T0*a1){T6 R=0;R=((T6)(Z2H(ZOG(((C)->ZYb)))));R=((T6)((T6)((Z3H(((C)->ZYb),a1))||((T6)(R)))));
if((a1)!=((void*)(Zo))){if(Z4H(((ZH6*)a1),((C)->ZYb))){R=((T6)(1));}}else if((T6)((Z2H(ZOG(((C)->ZYb))))&&((T6)(!(Z4G(((C)->ZYb))))))){
Z5H(((C)->ZYb));}return R;}void Zr51(Z83*C,T0*a1){T6 Z7H=0;T0*Z8H=Zo;Z7H=((T6)(Z9H((Zi4*)(ZsG),a1)));Z8H=ZvG(Zf51(C));if(ZaH(Z8H)){if(ZaH(a1)){
ZbH(a1);ZcH((Zi4*)(ZsG),((T3)'\050'));{Z83*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}ZcH((Zi4*)(ZsG),((T3)'\051'));}else{{Z83*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);
}}}else{if(ZaH(a1)){{Z83*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}else{if(ZeH(a1)){ZcH((Zi4*)(ZsG),((T3)'\046'));ZcH((Zi4*)(ZsG),((T3)'\050'));
{Z83*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}ZcH((Zi4*)(ZsG),((T3)'\051'));}else{{Z83*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}}}if(Z7H){ZfH((Zi4*)(ZsG));
}}void Zs51(Z83*C,T0*a1){T0*_rf=Zo;T0*_rc=Zo;T0*_rt=Zo;T0*_bc=Zo;_rt=ZOG(((C)->ZYb));if((_rt)!=((void*)(Zo))){_rc=Z8G(_rt);if((_rc)!=((void*)(Zo))){
_bc=((((Ze4*)_rc))->Zqb);_rf=ZhH(((T82*)_bc),_rc,((C)->ZYb),((C)->ZZb),a1);}}if((_rf)==((void*)(Zo))){ZzF((((ZB8*)(((C)->ZZb)))->Zxb));
{T0*b1=ZvF(25,"Bad target for this call.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}(C->Z_b)=_rf;}T2 Zt51(Z83*C){T2 R=0;Zk51(C);
return R;}T0*Zu51(Z83*C,T0*a1){T0*R=Zo;T0*ZkH=Zo;T0*ZlH=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;Zj51(C,a1);(C->ZAb)=Z651(C,a1);
ZlH=ZOG(((C)->ZYb));ZkH=ZOG(((((Zm3*)(((C)->ZAb))))->Z0j));(C->ZYb)=Z451(((C)->ZYb),ZlH,ZkH);Zs51(C,a1);R=Z851(C);Z251(C);}else{{Z83*n=((Z83*)Zh(sizeof(*n)));
*n=Z6e;Z751(n,((C)->ZYb),((C)->ZZb),((C)->ZAb));R=((T0*)n);}R=ZFG(R,a1);}return R;}T0*Z951(Z83*C){T0*R=Zo;T0*ZmH=Zo;T0*ZnH=Zo;ZmH=((C)->ZYb);
if(Zo!=(ZmH)){switch(((T0*)ZmH)->id){case 305:case 306:break;default:ZmH=Zo;}}if((ZmH)==((void*)(Zo))){R=((T0*)(C));}else{ZnH=((((Zm3*)(((C)->ZAb))))->Z0j);
if(Zo!=(ZnH)){switch(((T0*)ZnH)->id){case 305:case 306:break;default:ZnH=Zo;}}if((ZnH)==((void*)(Zo))){if((T6)((ZoH(ZmH))&&((T6)(ZxV(((((Zm3*)(((C)->ZAb))))->Z0j)))))){
{Za5*n=((Za5*)Zh(sizeof(*n)));*n=Z5h;ZpH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}else{R=((T0*)(C));}}else{if(Zis((T6)(ZoH(ZmH)),(T6)(ZoH(ZnH)))){
{Za5*n=((Za5*)Zh(sizeof(*n)));*n=Z5h;ZpH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}else{{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zel;ZqH(n,(((ZB8*)(((C)->ZZb)))->Zxb));
R=((T0*)n);}}}}return R;}T0*Zv51(Z83*C){T0*R=Zo;T0*_bc=Zo;T0*ZsH=Zo;T0*_rt=Zo;_bc=ZtH(((C)->ZYb));if((_bc)!=((void*)(Zo))){ZsH=ZuH(((T82*)_bc),((C)->ZZb));
if((ZsH)!=((void*)(Zo))){_rt=ZvH(ZsH);if((_rt)!=((void*)(Zo))){R=ZwH(_rt);}}}return R;}void Zw51(Z83*C){if((((C)->Z_b))!=((void*)(Zo))){
ZyH(((C)->Z_b));}ZzH(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){ZAH((Zm3*)(((C)->ZAb)));}}void Zx51(Z83*C){T0*_rc=Zo;T0*_rf=Zo;_rf=((C)->Z_b);
_rc=((((ZS7*)_rf))->Znf);(C->Z_b)=ZCH((Ze4*)((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZPb))[Zrs(0)]),_rf);}T76 Zc51(Z83*C){
T76 R={Zo,Zo,0};R=(((ZB8*)(((C)->ZZb)))->Zxb);return R;}void Zy51(Zc3*C,T0*a1){T2 _i=0;ZWB((ZK1*)(((C)->Z8e)),a1);_i=(((ZC3*)(((C)->Z9e)))->ZRb);
ZRy((ZC3*)(((C)->Z9e)),a1);while(!((T6)(((Z3)((_i)<(Zrs(0))))||((T6)((Z3)(((((Ze4*)(((((ZC3*)(((C)->Z9e)))->ZPb))[_i]))->_id))<(((((Ze4*)a1))->_id))))))))
{ZTy((ZC3*)(((C)->Z9e)),_i,(Z3)(((_i))+((T2)(Zrs(1)))));_i=(Z3)(((_i))-(Zrs(1)));}}void Zz51(Zc3*C,T0*a1){(C->Z7e)=a1;{ZC3*n=((ZC3*)Zh(sizeof(*n)));
*n=Zze;ZSy(n,(T2)(Zrs(64)));(C->Z9e)=((T0*)n);}{ZK1*n=((ZK1*)Zh(sizeof(*n)));*n=Z9d;{ZK1*C1=n;ZYB(C1,Zrs(53));}(C->Z8e)=((T0*)n);}}T2
ZA51(Zc3*C,T76 a1,T0*a2){T2 R=0;T2 _i=0;T0*ZB51=Zo;T0*_rc=Zo;ZB51=((((Zc3*)a2))->Z9e);_i=((((ZC3*)ZB51))->ZRb);while(!((Z3)((_i)<(Zrs(0)))))
{_rc=(((((ZC3*)ZB51))->ZPb))[_i];if(!(ZUB((ZK1*)(((C)->Z8e)),_rc))){if(ZYF(((((Ze4*)_rc))->Z0c),(((Ze4*)(((C)->Z7e)))->Z0c))){ZC51(C,a1,_rc);
R=(Z3)(((R))+(Zrs(1)));}else{((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));}}_i=(Z3)(((_i))-(Zrs(1)));
}return R;}void ZC51(Zc3*C,T76 a1,T0*a2){T2 _i=0;T0*_t1=Zo;T0*_t2=Zo;T6 Z_M=0;T0*ZD51=Zo;T0*ZE51=Zo;ZhG((T41*)(Z1G));Zy51(C,a2);if((a2)!=((void*)(((C)->Z7e)))){
_t1=((((Ze4*)a2))->Z0c);_t2=(((Ze4*)(((C)->Z7e)))->Z0c);if(ZQS(_t1)){if(ZQS(_t2)){if((ZbK(_t1))==((void*)(ZbK(_t2)))){ZD51=ZbN(_t1);ZE51=ZbN(_t2);
_i=((((ZY*)ZE51))->ZRb);while(!((Z3)((_i)<(((((ZY*)ZE51))->ZSb))))){ZF51(a1,ZMx(((ZY*)ZD51),_i),ZMx(((ZY*)ZE51),_i));_i=(Z3)(((_i))-(Zrs(1)));
}}else{Z_M=((T6)(ZG51(((Z3a*)((((T82*)(ZbK(_t1)))->Zmg))),a1,_t1,_t2)));}}}else if(ZQS(_t2)){Z_M=((T6)(ZG51(((Z3a*)((((T82*)(ZbK(_t1)))->Zmg))),a1,_t1,_t2)));
}}}void ZH51(Zc3*C,T0*a1){T2 _c=0;T2 _i=0;T0*_rc=Zo;_c=(Z3)((((((ZC3*)(((C)->Z9e)))->ZRb)))+(Zrs(1)));ZUS(a1,ZI51);ZJ51(a1,(T11)(_c));
ZXS(a1,((T3)'\n'));if((Z3)((_c)>(Zrs(0)))){ZUS(a1,ZK51);_i=Zrs(0);while(!((_i)==(_c))){_rc=((((ZC3*)(((C)->Z9e)))->ZPb))[_i];ZXS(a1,((T3)'\011'));
ZUS(a1,((((Ze4*)_rc))->ZMc));ZXS(a1,((T3)'\040'));ZXS(a1,((T3)'\050'));ZJ51(a1,(T11)(((((Ze4*)_rc))->_id)));ZXS(a1,((T3)'\051'));ZXS(a1,((T3)'\n'));
_i=(Z3)(((_i))+(Zrs(1)));}}}void ZL51(Zi3*C,T2 a1){T3 _c=0;_c=((((T7*)(((C)->Zde)))->ZPb))[(a1)-(Zrs(1))];{int z1=_c;switch(z1){case 48:
case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:
case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 97:
case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:
case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:((((T7*)(((C)->Zde)))->ZPb))[(a1)-(Zrs(1))]=(((T3)((Z2)(((Zos(_c)))+((T10)(Zrs(1)))))));
break;case 57:((((T7*)(((C)->Zde)))->ZPb))[(a1)-(Zrs(1))]=(((T3)'a'));break;case 122:((((T7*)(((C)->Zde)))->ZPb))[(a1)-(Zrs(1))]=(((T3)'A'));
break;case 90:((((T7*)(((C)->Zde)))->ZPb))[(a1)-(Zrs(1))]=(((T3)'\137'));break;default:;((((T7*)(((C)->Zde)))->ZPb))[(a1)-(Zrs(1))]=(((T3)'0'));
if((a1)==((((T7*)(((C)->Zde)))->Zcc))){ZZs((T7*)(((C)->Zde)),((T3)'1'));}else{ZL51(C,(Z3)(((a1))+((T2)(Zrs(1)))));}}}}void ZM51(Zk3*C,T0*a1){
ZXw(((T7*)a1),Z6N);ZQs(ZN51(C),a1);}void ZO51(T0*a1){ZXw(((T7*)a1),Z9N);ZZs(((T7*)a1),((T3)'\052'));}T0*ZP51(Zk3*C){T0*R=Zo;ZQ51(C);return
R;}void ZR51(Zk3*C,T0*a1){ZXw(((T7*)a1),ZjN);ZQs(ZN51(C),a1);}void ZS51(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));
}T6 ZT51(void){T6 R=0;return R;}void ZU51(Zk3*C){T0*_rc=Zo;T2 ZnN=0;T6 ZoN=0;_rc=ZV51(C);ZnN=((((Ze4*)_rc))->_id);ZBw((T7*)(ZqN),Z9N);
ZZs((T7*)(ZqN),((T3)'\040'));ZXw((T7*)(ZqN),ZrN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZsN);ZBw((T7*)(ZcN),ZtN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZuN);
ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZvN);ZM51(C,ZcN);ZXw((T7*)(ZcN),ZwN);(((void)((Zh8*)(ZW51()))),ZyN(ZcN,ZzN,ZV51(C)));ZXw((T7*)(ZcN),ZAN);
ZX51(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZX51(C,ZcN);ZXw((T7*)(ZcN),ZCN);(((void)((Zh8*)(ZW51()))),ZyN(ZcN,ZDN,ZV51(C)));ZXw((T7*)(ZcN),ZEN);ZX51(C,ZcN);
ZXw((T7*)(ZcN),Z8M);ZX51(C,ZcN);ZXw((T7*)(ZcN),ZFN);ZGN((Zi4*)(ZsG),ZqN,ZcN);ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));ZY51(C,ZqN);
ZXw((T7*)(ZqN),ZIN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZJN);((((T7*)((T7*)(ZcN))))->Zcc)=(Zrs(0));ZoN=((T6)((T6)((ZKN(((Ze4*)_rc)))&&((T6)((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2))))))));
if(ZoN){ZXw((T7*)(ZcN),ZLN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZMN);}ZNN(((Ze4*)_rc),(T6)(0),ZcN);if(ZoN){ZXw((T7*)(ZcN),ZON);}ZGN((Zi4*)(ZsG),ZqN,ZcN);
ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));ZZ51(C,ZqN);ZXw((T7*)(ZqN),ZQN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZRN);((((T7*)((T7*)(ZcN))))->Zcc)=(Zrs(0));
ZSN(((Ze4*)_rc),ZcN);ZGN((Zi4*)(ZsG),ZqN,ZcN);ZBw((T7*)(ZqN),ZTN);ZQs(ZnN,ZqN);ZBw((T7*)(ZcN),ZUN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZVN);ZQs(ZnN,ZcN);
ZXw((T7*)(ZcN),ZWN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZXN);ZYN((Zi4*)(ZsG),ZqN,ZcN);((((T7*)((T7*)(ZqN))))->Zcc)=(Zrs(0));ZZs((T7*)(ZqN),((T3)'T'));
ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));ZXw((T7*)(ZqN),ZZN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),Z_N);ZBw((T7*)(ZcN),Z0O);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),Z1O);
if((((Zh8*)(ZW51()))->ZEk)){Z_51(C,ZcN);ZXw((T7*)(ZcN),Z3O);}ZXw((T7*)(ZcN),Z4O);Z061(C,ZcN);ZXw((T7*)(ZcN),Z6O);Z061(C,ZcN);ZXw((T7*)(ZcN),Z7O);
ZM51(C,ZcN);ZXw((T7*)(ZcN),Z8O);ZX51(C,ZcN);ZXw((T7*)(ZcN),Z9O);ZX51(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZX51(C,ZcN);ZXw((T7*)(ZcN),ZaO);Z061(C,ZcN);
ZXw((T7*)(ZcN),ZbO);Z061(C,ZcN);ZXw((T7*)(ZcN),ZcO);ZR51(C,ZcN);ZXw((T7*)(ZcN),ZdO);ZM51(C,ZcN);ZXw((T7*)(ZcN),ZeO);ZX51(C,ZcN);ZXw((T7*)(ZcN),ZfO);
ZX51(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZX51(C,ZcN);ZXw((T7*)(ZcN),ZgO);ZR51(C,ZcN);ZXw((T7*)(ZcN),ZhO);ZR51(C,ZcN);ZXw((T7*)(ZcN),ZiO);ZQs(ZnN,ZcN);
ZXw((T7*)(ZcN),Z8M);ZM51(C,ZcN);ZXw((T7*)(ZcN),ZjO);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZkO);ZR51(C,ZcN);ZXw((T7*)(ZcN),ZlO);Z061(C,ZcN);ZXw((T7*)(ZcN),ZiO);
ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZmO);ZM51(C,ZcN);ZXw((T7*)(ZcN),ZnO);if(Z161(C)){ZXw((T7*)(ZcN),ZoO);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),Z8M);}ZXw((T7*)(ZcN),ZpO);
ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZqO);ZGN((Zi4*)(ZsG),ZqN,ZcN);}void Z261(Zk3*C){T0*_rc=Zo;T2 ZnN=0;_rc=ZV51(C);ZnN=((((Ze4*)_rc))->_id);ZBw((T7*)(ZqN),ZsO);
ZXw((T7*)(ZqN),ZtO);ZZs((T7*)(ZqN),((T3)'\040'));ZZs((T7*)(ZqN),((T3)'B'));ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\040'));ZXw((T7*)(ZqN),Z0O);
ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),Z8M);ZXw((T7*)(ZqN),ZtO);ZZs((T7*)(ZqN),((T3)'\040'));ZZs((T7*)(ZqN),((T3)'B'));ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZuO);
ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZvO);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZwO);Z7I((Zi4*)(ZsG),ZqN);ZBw((T7*)(ZqN),Z0O);ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));
ZM51(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);ZBw((T7*)(ZqN),ZyO);ZZs((T7*)(ZqN),((T3)'\040'));Z061(C,ZqN);ZzO((Zi4*)(ZsG),ZqN,((T3)'0'));ZBw((T7*)(ZqN),ZAO);
ZR51(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);ZBw((T7*)(ZqN),Z0O);ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));ZX51(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);
if((((Zh8*)(ZW51()))->ZEk)){ZBw((T7*)(ZqN),ZyO);ZZs((T7*)(ZqN),((T3)'\040'));Z_51(C,ZqN);ZzO((Zi4*)(ZsG),ZqN,((T3)'0'));}}T6 Z361(Zk3*C){
T6 R=0;T0*ZCO=Zo;ZCO=Zo;R=((T6)((ZCO)!=((void*)(Zo))));return R;}void ZY51(Zk3*C,T0*a1){ZXw(((T7*)a1),ZDO);ZQs(ZN51(C),a1);}T6 Z461(Zk3*C){
T6 R=0;T0*_rt=Zo;_rt=((T0*)(C));if((C)==((void*)(_rt))){if((ZvG(_rt))==((void*)(_rt))){R=((T6)((ZFO(_rt))==((void*)(ZDF(_rt)))));}}return
R;}T2 ZN51(Zk3*C){T2 R=0;R=(T2)((((T82*)(Z561(C)))->_id));return R;}T2 Z661(void){T2 R=0;T8 _p=Zo;R=sizeof(T8);return R;}void Z761(Zk3*C){
((((T7*)((T7*)(ZJO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZJO),((T3)'\050'));Z861(C,ZJO);ZZs((T7*)(ZJO),((T3)'\051'));Z7I((Zi4*)(ZsG),ZJO);}void
Z961(Zk3*C,T0*a1){ZXw(((T7*)a1),ZMO);Z_51(C,a1);ZXw(((T7*)a1),ZNO);ZXw(((T7*)a1),(ZeP));ZXw(((T7*)a1),ZOO);Z_51(C,a1);ZZs(((T7*)a1),((T3)'\054'));
Z061(C,a1);ZXw(((T7*)a1),ZPO);}void Za61(Zk3*C){T2 ZXO=0;ZXO=ZN51(C);((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));if(Z161(C)){ZXw((T7*)(ZYO),ZsO);
ZXw((T7*)(ZYO),ZtO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'S'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'T'));
ZQs(ZXO,ZYO);ZXw((T7*)(ZYO),Z8M);}else{ZXw((T7*)(ZYO),ZsO);ZXw((T7*)(ZYO),Z9N);ZZs((T7*)(ZYO),((T3)'\052'));ZZs((T7*)(ZYO),((T3)'T'));
ZQs(ZXO,ZYO);ZXw((T7*)(ZYO),Z8M);}Z7I((Zi4*)(ZsG),ZYO);}void ZQ51(Zk3*C){ZsS((T0*)C,ZvF(19," is (not) generic \?"));ZEF((T75*)(ZyF));
}void ZNK(Zk3*C,T76 a1){{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Zb61(n,ZeP,a1);(C->Zfe)=((T0*)n);}}void Zc61(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}T0*ZW51(void){if(ZDI==0){ZDI=1;{{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZGk;ZCI=((T0*)n);}}}return ZCI;}T0*Zd61(T76 a1){T0*R=Zo;
{ZH4*n=((ZH4*)Zh(sizeof(*n)));*n=Zyg;((((ZH4*)(n)))->Zxb)=(a1);R=((T0*)n);}return R;}T0*Z561(Zk3*C){T0*R=Zo;T0*ZqS=Zo;if((((C)->ZIc))!=((void*)(Zo))){
R=((C)->ZIc);}else{ZqS=((C)->Zfe);if((ZqS)!=((void*)(Zo))){(C->ZIc)=ZrS(((T80*)ZqS));R=((C)->ZIc);}else{{T0*b1=ZvF(27,"Cannot find Base Class for ");
ZXw((T7*)(ZwF),b1);}ZsS((T0*)C,ZMJ);ZEF((T75*)(ZyF));}}return R;}void Ze61(Zk3*C,T0*a1){ZZs(((T7*)a1),((T3)'\045'));ZZs(((T7*)a1),((T3)'R'));
ZQs(ZN51(C),a1);ZZs(((T7*)a1),((T3)'\045'));}void Zf61(Zk3*C){if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZwS((Ze4*)(ZV51(C)));}}int Zg61=0;
void Zh61(Zk3*C){if(Zg61==0){Zg61=1;{T0*_bc=Zo;T0*_rc=Zo;_bc=Z561(C);if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){_rc=ZV51(C);}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){
if(((((T82*)_bc))->Zgg)){{T76 Z3w;ZS51((*(Z3w=Zi61(C),&Z3w)),ZvF(25,"ANY must not be expanded."));}}}}}}T6 Z161(Zk3*C){T6 R=0;if(ZKN((Ze4*)(ZV51(C)))){
R=((T6)(1));}else{R=((T6)((ZKS((Ze4*)(ZV51(C))))!=((void*)(Zo))));}return R;}T6 Zj61(Zk3*C){T6 R=0;T0*ZyS=Zo;ZyS=Zo;R=((T6)((ZyS)!=((void*)(Zo))));
return R;}void Z861(Zk3*C,T0*a1){ZZs(((T7*)a1),((T3)'T'));ZQs(ZN51(C),a1);ZZs(((T7*)a1),((T3)'\052'));}void ZX51(Zk3*C,T0*a1){ZXw(((T7*)a1),ZBS);
ZQs(ZN51(C),a1);}void ZZ51(Zk3*C,T0*a1){ZXw(((T7*)a1),ZHS);ZQs(ZN51(C),a1);}void Zk61(Zk3*C){T0*_wa=Zo;T2 _i=0;T2 ZXO=0;T0*_a=Zo;T0*_t=Zo;
ZXO=ZN51(C);_wa=ZKS((Ze4*)(ZV51(C)));ZBw((T7*)(ZYO),ZtO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'S'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\173'));
if(ZKN((Ze4*)(ZV51(C)))){ZXw((T7*)(ZYO),ZWU);}if((_wa)!=((void*)(Zo))){_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){_a=ZDA(((ZT8*)_wa),_i);
_t=ZvG(((((ZG7*)_a))->Zgc));ZXU(_t,ZYO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'\137'));ZXw((T7*)(ZYO),(((ZB8*)(((((ZG7*)_a))->Zkc)))->Zre));
ZZs((T7*)(ZYO),((T3)'\073'));_i=(Z3)(((_i))-(Zrs(1)));}}ZZs((T7*)(ZYO),((T3)'\175'));ZXw((T7*)(ZYO),Z8M);Z7I((Zi4*)(ZsG),ZYO);}void Zl61(T0*a1){
ZUS(a1,ZVS);ZUS(a1,ZWS);ZXS(a1,((T3)'\n'));}T6 Zm61(Zk3*C,T0*a1){T6 R=0;if(ZgN(a1)){R=((T6)(1));}else if(ZVO(a1)){}else{if(Z2H(a1)){R=((T6)((Z561(C))==((void*)(ZbK(a1)))));
}if(!(R)){R=((T6)(ZnI((T82*)(Z561(C)),ZbK(a1))));}}if(!(R)){ZZS((T0*)C,a1);}return R;}T0*Zn61(Zk3*C){T0*R=Zo;{T76 Z3w;if(!(ZMF(&((*(Z3w=Zi61(C),&Z3w)))))){
{T76 Zo61;R=Z0T(&((*(Zo61=Zi61(C),&Zo61))));}}}return R;}T0*Zp61(Zk3*C,T0*a1){T0*R=Zo;R=((T0*)(C));Zh61(C);return R;}void Zq61(Zk3*C){
T2 ZXO=0;T0*_rc=Zo;_rc=ZV51(C);ZXO=((((Ze4*)_rc))->_id);((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZYO),((T3)'T'));ZQs(ZXO,ZYO);
ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'M'));ZQs(ZXO,ZYO);ZDS((Zi4*)(ZsG),ZYO);ZES((Zi4*)(ZsG));((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));
Z5V(((Ze4*)_rc),ZYO);ZXw((T7*)(ZYO),Z8M);Z7I((Zi4*)(ZsG),ZYO);ZGS((Zi4*)(ZsG));}T0*Zr61(Zk3*C){T0*R=Zo;T0*Z9T=Zo;Z9T=((C)->Zfe);if((Z9T)!=((void*)(Zo))){
R=ZrS(((T80*)Z9T));}return R;}T0*ZV51(Zk3*C){T0*R=Zo;if((((C)->ZJc))!=((void*)(Zo))){R=((C)->ZJc);}else{(C->ZJc)=ZdT(((T0*)(C)));R=((C)->ZJc);
}return R;}void Z061(Zk3*C,T0*a1){ZXw(((T7*)a1),ZcT);ZQs(ZN51(C),a1);}void Zs61(Zk3*C){if(Z161(C)){Zk61(C);}Zq61(C);Zf61(C);}T76 Zi61(Zk3*C){
T76 R={Zo,Zo,0};R=(((T80*)(((C)->Zfe)))->Zxb);return R;}void Zt61(Zk3*C,T0*a1){ZX51(C,a1);ZZs(((T7*)a1),((T3)'\075'));ZXw(((T7*)a1),ZxO);
ZXw(((T7*)a1),Z8M);}void Z_51(Zk3*C,T0*a1){ZXw(((T7*)a1),ZjT);ZQs(ZN51(C),a1);}void Zu61(Zk3*C,T0*a1){ZXw(((T7*)a1),ZZN);ZQs(ZN51(C),a1);
ZZs(((T7*)a1),((T3)'\050'));ZZs(((T7*)a1),((T3)'\051'));}void Zv61(Zo3*C,T0*a1){T2 _i=0;_i=ZpA(((Zt8*)(((C)->Zhe))));while(!((_i)==(Zrs(0))))
{{Zz4*C1=(Zz4*)(ZqA(((Zt8*)(((C)->Zhe))),_i));T0*b1=a1;Zw61(C1,b1,Zx61);}_i=(Z3)(((_i))-(Zrs(1)));}}T2 Zy61(Zo3*C,T0*a1){T2 R=0;R=ZpA(((Zt8*)(((C)->Zhe))));
while(!((T6)(((R)==(Zrs(0)))||((T6)((a1)==((void*)((((Zz4*)(ZqA(((Zt8*)(((C)->Zhe))),R)))->Zre)))))))){R=(Z3)(((R))-(Zrs(1)));}return
R;}void Zz61(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T6 ZA61(Zo3*C,T0*a1){T6 R=0;T2 _i=0;T0*_n1=Zo;T0*_n2=Zo;
T0*_t=Zo;R=((T6)(1));_i=ZpA(((Zt8*)(((C)->Zhe))));while(!((T6)((!(R))||((T6)((_i)==(Zrs(0))))))){_t=ZB61(C,_i);if(Z7V(_t)){if((ZvG(_t))!=((void*)(_t))){
R=((T6)(0));}else if((Z9L(_t,a1))!=((void*)(_t))){R=((T6)(0));}}else{R=((T6)(0));}_i=(Z3)(((_i))-(Zrs(1)));}if(R){_i=ZpA(((Zt8*)(((C)->Zhe))));
while(!((_i)==(Zrs(0)))){_n1=ZqA((Zt8*)(((C)->Zhe)),_i);_n2=ZC61(((Zz4*)_n1),a1);if((_n2)==((void*)(Zo))){Zz61(((((Zz4*)_n1))->Zxb),ZD61);
_i=Zrs(0);}else{_i=(Z3)(((_i))-(Zrs(1)));}}Zv61(C,a1);}return R;}T0*ZB61(Zo3*C,T2 a1){T0*R=Zo;R=(((Zz4*)(ZqA(((Zt8*)(((C)->Zhe))),a1)))->Zgc);
return R;}void ZE61(Zo3*C,T0*a1,T0*a2){T2 _i=0;T2 _c=0;T0*_n=Zo;T0*Zre=Zo;_i=Zrs(1);_c=ZpA(((Zt8*)(((C)->Zhe))));while(!((Z3)((_i)>(_c))))
{_n=ZqA(((Zt8*)(((C)->Zhe))),_i);if(ZF61(((Zz4*)_n))){Zre=((((Zz4*)_n))->Zre);ZXw(((T7*)a1),Zre);ZXw(((T7*)a2),ZG61);ZXw(((T7*)a2),Zre);
ZZs(((T7*)a2),((T3)'\054'));ZH61(ZB61(C,_i),a1);}_i=(Z3)(((_i))+(Zrs(1)));}}void ZI61(Zo3*C,T6 a1){T2 _i=0;T2 _c=0;_i=Zrs(1);_c=ZpA(((Zt8*)(((C)->Zhe))));
while(!((Z3)((_i)>(_c)))){ZJ61((Zz4*)(ZqA(((Zt8*)(((C)->Zhe))),_i)),(T6)(a1));_i=(Z3)(((_i))+(Zrs(1)));}}void ZK61(Zo3*C){T2 _i=0;_i=ZpA(((Zt8*)(((C)->Zhe))));
while(!((_i)==(Zrs(0)))){ZL61((Zi4*)(ZsG));ZJ61((Zz4*)(ZqA(((Zt8*)(((C)->Zhe))),_i)),(T6)(0));ZM61((Zi4*)(ZsG));_i=(Z3)(((_i))-(Zrs(1)));
}}void ZN61(Zo3*C,T0*a1){T2 _i=0;T0*_n2=Zo;_i=(((Zt8*)(((C)->Zhe)))->ZSb);while(!((ZqA((Zt8*)(((C)->Zhe)),_i))==((void*)(Zo)))){_n2=ZqA((Zt8*)(((C)->Zhe)),_i);
if((((((Zz4*)_n2))->Zre))==((void*)(((((Zz4*)a1))->Zre)))){ZzF(((((Zz4*)a1))->Zxb));ZzF(((((Zz4*)_n2))->Zxb));{T0*b1=ZvF(24,"Same name appears twice.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}_i=(Z3)(((_i))+(Zrs(1)));}{Zt8*C1=(Zt8*)(((C)->Zhe));T0*b1=a1;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}((((Zz4*)(((Zz4*)a1))))->Zoe)=(_i);}void ZO61(Zo3*C,T0*a1){T2 _i=0;T0*_n1=Zo;T0*_n2=Zo;(C->Zhe)=ZtA((Zt8*)(((C)->Zhe)));_i=(((Zt8*)(((C)->Zhe)))->ZRb);
while(!((Z3)((_i)<((((Zt8*)(((C)->Zhe)))->ZSb))))){_n1=ZqA((Zt8*)(((C)->Zhe)),_i);_n2=ZC61(((Zz4*)_n1),a1);if((_n2)==((void*)(Zo))){Zz61(((((Zz4*)_n1))->Zxb),ZD61);
}else{{Zt8*C1=(Zt8*)(((C)->Zhe));T0*b1=_n2;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}_i=(Z3)(((_i))-(Zrs(1)));}}T6 ZP61(Zo3*C){
T6 R=0;T2 _i=0;T0*_lt=Zo;T0*ZPW=Zo;R=((T6)(1));_i=ZpA(((Zt8*)(((C)->Zhe))));while(!((T6)((!(R))||((T6)((_i)==(Zrs(0))))))){_lt=ZB61(C,_i);
if(Z4_(_lt)){ZPW=ZsY((Ze4*)(Z8G(_lt)));if((ZPW)!=((void*)(Zo))){R=((T6)(ZQ61(((ZI7*)ZPW))));}}_i=(Z3)(((_i))-(Zrs(1)));}return R;}void
ZR61(Zo3*C,T0*a1){T2 _il=0;T2 ZS61=0;(C->ZUb)=a1;_il=(((Z5a*)(((C)->ZUb)))->ZRb);while(!((Z3)((_il)<((((Z5a*)(((C)->ZUb)))->ZSb))))){
ZS61=(Z3)(((ZS61))+(ZT61(ZU61(((C)->ZUb),_il))));_il=(Z3)(((_il))-(Zrs(1)));}{Zt8*n=((Zt8*)Zh(sizeof(*n)));*n=Z0l;ZrA(n,(T2)(Zrs(1)),ZS61);
(C->Zhe)=((T0*)n);}_il=(((Z5a*)(((C)->ZUb)))->ZSb);while(!((Z3)((_il)>((((Z5a*)(((C)->ZUb)))->ZRb))))){ZV61(ZU61(((C)->ZUb),_il),(T0*)C);
_il=(Z3)(((_il))+(Zrs(1)));}}void ZW61(Zo3*C){T2 _i=0;T0*_t=Zo;T0*ZPW=Zo;_i=ZpA(((Zt8*)(((C)->Zhe))));while(!((_i)==(Zrs(0)))){_t=ZvG(ZB61(C,_i));
if(Z5T(_t)){if(!(ZXF(_t))){ZPW=ZsY((Ze4*)(Z8G(_t)));if((ZPW)!=((void*)(Zo))){Zp41((Zi4*)(ZsG),ZPW,ZqA(((Zt8*)(((C)->Zhe))),_i),Zo);}}
}_i=(Z3)(((_i))-(Zrs(1)));}}T0*ZX61(Zo3*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zo3*)R)=*C;return R;}T0*ZY61(Zo3*C,T0*a1){T0*R=Zo;if(ZA61(C,a1)){
R=((T0*)(C));}else{R=ZX61(C);ZO61(((Zo3*)R),a1);Zv61(((Zo3*)R),a1);}return R;}T6 ZZ61(Zo3*C){T6 R=0;T2 _i=0;_i=ZpA(((Zt8*)(((C)->Zhe))));
while(!((T6)((R)||((T6)((_i)==(Zrs(0))))))){R=((T6)(ZF61((Zz4*)(ZqA(((Zt8*)(((C)->Zhe))),_i)))));_i=(Z3)(((_i))-(Zrs(1)));}return R;}
void Z_61(Zq3*C,T0*a1){(C->Zle)=a1;(C->Zje)=Zo;}void Z071(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}void Z171(Zq3*C){
ZoG(((C)->ZTc));if((((C)->Zje))!=((void*)(Zo))){ZH_((ZD2*)(((C)->Zje)));}if((((C)->Zle))!=((void*)(Zo))){Z271((Z47*)(((C)->Zle)));}}void
Z371(Zq3*C,T0*a1,T2 a2){T0*_cc=Zo;T0*_ic=Zo;(C->ZTc)=ZjG(((C)->ZTc));_cc=((C)->ZTc);if(Zo!=(_cc)){switch(((T0*)_cc)->id){case 307:break;
default:_cc=Zo;}}_ic=((C)->ZTc);if(Zo!=(_ic)){switch(((T0*)_ic)->id){case 249:break;default:_ic=Zo;}}if((((C)->Zje))!=((void*)(Zo))){
ZJ_((ZD2*)(((C)->Zje)),_cc,_ic);if((T6)(((_cc)!=((void*)(Zo)))||((T6)((_ic)!=((void*)(Zo)))))){if((((C)->Zje))!=((void*)(Zo))){if(!(ZMF(&(((C)->Zke))))){
(C->Zje)=Zo;}}}}if((((C)->Zle))!=((void*)(Zo))){(C->Zle)=Z471((Z47*)(((C)->Zle)));}if((((C)->Zje))==((void*)(Zo))){if(ZxV(((C)->ZTc))){
ZeV(((Z47*)a1),a2);if((((C)->Zle))!=((void*)(Zo))){Z571(((Z47*)a1),((C)->Zle),a2);}}}}void Z671(Zq3*C,T0*a1){if((((C)->Zje))==((void*)(Zo))){
{ZD2*n=((ZD2*)Zh(sizeof(*n)));*n=ZNd;ZV_(n,a1);(C->Zje)=((T0*)n);}}else{Zkz(((Zo5*)((((ZD2*)(((C)->Zje)))->ZUb))),a1);}}T0*Z771=Zo;int
Z871=0;T0*Z971(void){if(Z871==0){Z871=1;{{Zk4*n=((Zk4*)Zh(sizeof(*n)));*n=ZYf;Z771=((T0*)n);}}}return Z771;}void Za71(Zq3*C){T6 Zb71=0;
T6 ZTd=0;if((((C)->Zme))!=((void*)(Zo))){Zc71((Z29*)(((C)->Zme)),(T0*)C);}else{Zb71=((T6)((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))));ZTd=((T6)((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(7)))));
Zd71((Zi4*)(ZsG));Z7I((Zi4*)(ZsG),Ze71);Zf71((Zi4*)(ZsG));ZcH((Zi4*)(ZsG),((T3)'\075'));if(ZTd){ZcH((Zi4*)(ZsG),((T3)'\050'));{T76 Z3w;
Zg71((Zi4*)(ZsG),(*(Z3w=ZGG(((C)->ZTc)),&Z3w)));}ZcH((Zi4*)(ZsG),((T3)'\054'));}ZI01(((C)->ZTc));if(ZTd){ZcH((Zi4*)(ZsG),((T3)'\051'));
}Z7I((Zi4*)(ZsG),Z8M);if((((C)->Zje))==((void*)(Zo))){if(ZMF(&(((C)->Zke)))){if(Zb71){Zh71((Zk4*)(Z971()),((C)->Zxb));}}else if((((C)->Zle))!=((void*)(Zo))){
ZgV((Z47*)(((C)->Zle)));}}else if(Zi71(C)){Z7I((Zi4*)(ZsG),Zj71);Zf71((Zi4*)(ZsG));Z7I((Zi4*)(ZsG),Zk71);Ze01((ZD2*)(((C)->Zje)),((C)->Zke));
if(ZMF(&(((C)->Zke)))){if(Zb71){Z7I((Zi4*)(ZsG),Zl71);Zh71((Zk4*)(Z971()),((C)->Zxb));}}else if((((C)->Zle))!=((void*)(Zo))){Z7I((Zi4*)(ZsG),Zm71);
ZgV((Z47*)(((C)->Zle)));}Z7I((Zi4*)(ZsG),Zn71);}else{ZN_((ZD2*)(((C)->Zje)),((C)->Zke));if(ZMF(&(((C)->Zke)))){if(Zb71){ZcH((Zi4*)(ZsG),((T3)'\040'));
Z7I((Zi4*)(ZsG),Zo71);ZcH((Zi4*)(ZsG),((T3)'\173'));Zh71((Zk4*)(Z971()),((C)->Zxb));ZcH((Zi4*)(ZsG),((T3)'\175'));}}else if((((C)->Zle))!=((void*)(Zo))){
ZcH((Zi4*)(ZsG),((T3)'\040'));Z7I((Zi4*)(ZsG),Zo71);ZcH((Zi4*)(ZsG),((T3)'\173'));ZgV((Z47*)(((C)->Zle)));ZcH((Zi4*)(ZsG),((T3)'\175'));
}}Z7I((Zi4*)(ZsG),Zp71);Zq71((Zi4*)(ZsG));}}T6 Zr71(Zq3*C,T0*a1){T6 R=0;if(Z7G(((C)->ZTc),a1)){if((T6)(((((C)->Zje))==((void*)(Zo)))||((T6)(ZR_((ZD2*)(((C)->Zje)),a1))))){
if((T6)(((((C)->Zle))==((void*)(Zo)))||((T6)(Zs71((Z47*)(((C)->Zle)),a1))))){R=((T6)(1));}}}return R;}void Zt71(Zq3*C,T76 a1,T0*a2){(C->Zxb)=a1;
(C->ZTc)=a2;}void Zu71(Zq3*C,T76 a1,T0*a2){(C->Zke)=a1;(C->Zle)=a2;}void Zv71(Zq3*C){ZSG(((C)->ZTc));if((((C)->Zje))!=((void*)(Zo))){
Z201((ZD2*)(((C)->Zje)));}if((((C)->Zle))!=((void*)(Zo))){ZjV((Z47*)(((C)->Zle)));}}T6 Zw71(Zq3*C){T6 R=0;R=((T6)((T6)((R)||((T6)(ZYG(((C)->ZTc)))))));
if((((C)->Zje))!=((void*)(Zo))){R=((T6)((T6)((R)||((T6)(Z401((ZD2*)(((C)->Zje))))))));}if((((C)->Zle))!=((void*)(Zo))){R=((T6)((T6)((R)||((T6)(ZlV((Z47*)(((C)->Zle))))))));
}return R;}void Zx71(Zq3*C,T0*a1){T6 Z_M=0;Z_M=((T6)(Z3H(((C)->ZTc),a1)));if((((C)->Zje))!=((void*)(Zo))){Z701((ZD2*)(((C)->Zje)),a1);
}}T0*Zy71(Zq3*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zq3*)R)=*C;return R;}T0*Zz71(Zq3*C,T0*a1){T0*R=Zo;if((ZPA(((T74*)(((((T86*)a1))->ZUb)))))==(Zrs(1))){
R=((T0*)(C));}else{{Zn8*n=((Zn8*)Zh(sizeof(*n)));*n=ZVk;Z1N(n,(T0*)C,a1);R=((T0*)n);}}return R;}T6 Zi71(Zq3*C){T6 R=0;if((Z3)((Zb01((ZD2*)(((C)->Zje))))<=(Zrs(32)))){
R=((T6)(1));}return R;}T0*ZA71(Zq3*C,T0*a1){T0*R=Zo;T0*_e=Zo;T0*_te=Zo;T0*_wl=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;_e=ZFG(((C)->ZTc),a1);
if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){(C->ZTc)=_e;_te=ZOG(_e);}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){if(Z6P(_te)){if((((C)->Zje))!=((void*)(Zo))){
(C->Zje)=Z001((ZD2*)(((C)->Zje)),(T0*)C);if((((C)->Zje))==((void*)(Zo))){Z071(((C)->Zxb),ZB71);}}}else if(Z1P(_te)){if((((C)->Zje))!=((void*)(Zo))){
(C->Zje)=Z901((ZD2*)(((C)->Zje)),(T0*)C);if((((C)->Zje))==((void*)(Zo))){Z071(((C)->Zxb),ZB71);}}}else if(ZbT(_te)){if((((C)->Zje))!=((void*)(Zo))){
{Z29*n=((Z29*)Zh(sizeof(*n)));*n=Zyl;ZC71(n,(T0*)C);(C->Zme)=((T0*)n);}(C->Zje)=ZW_((ZD2*)(((C)->Zje)),(T0*)C);if((((C)->Zje))==((void*)(Zo))){
Z071(((C)->Zxb),ZB71);}}}else{{T0*b1=ZvF(48,"Expression must be INTEGER, CHARACTER or STRING.");ZXw((T7*)(ZwF),b1);}ZsS(_te,ZvF(16," is not allowed."));
ZzF(((C)->Zxb));ZxF((T75*)(ZyF));}}if((((C)->Zle))!=((void*)(Zo))){(C->Zle)=ZqV((Z47*)(((C)->Zle)),a1);}R=((T0*)(C));}else{R=Zy71(C);
if((((C)->Zje))!=((void*)(Zo))){{ZD2*n=((ZD2*)Zh(sizeof(*n)));*n=ZNd;Z__(n,((C)->Zje));_wl=((T0*)n);}((((Zq3*)(((Zq3*)R))))->Zje)=(_wl);
}((((Zq3*)(((Zq3*)R))))->Z0c)=(Zo);R=ZA71(((Zq3*)R),a1);}return R;}void ZD71(Zq3*C){ZzH(((C)->ZTc));}void ZE71(ZH6*C,T0*a1){T2 _i=0;_i=Zty(((Zn2*)(((C)->Zhe))));
while(!((_i)==(Zrs(0)))){{Zi1*C1=(Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),_i));T0*b1=a1;ZF71(C1,b1,ZG71);}_i=(Z3)(((_i))-(Zrs(1)));}}void ZH71(ZH6*C,T0*a1){
T2 _i=0;T0*_t=Zo;_i=Zrs(1);while(!((Z3)((_i)>(Zty(((Zn2*)(((C)->Zhe)))))))){_t=ZvG(ZI71(C,_i));ZEZ(_t,a1);ZZs(((T7*)a1),((T3)'\040'));
ZZs(((T7*)a1),((T3)'a'));ZQs(_i,a1);_i=(Z3)(((_i))+(Zrs(1)));if((Z3)((_i)<=(Zty(((Zn2*)(((C)->Zhe))))))){ZZs(((T7*)a1),((T3)'\054'));
}}}T2 ZJ71(ZH6*C,T0*a1){T2 R=0;R=Zty(((Zn2*)(((C)->Zhe))));while(!((T6)(((R)==(Zrs(0)))||((T6)((a1)==((void*)((((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),R)))->Zre))))))))
{R=(Z3)(((R))-(Zrs(1)));}return R;}void ZK71(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T0*ZL71(ZH6*C,T76 a1){
T0*R=Zo;T2 _i=0;T2 _c=0;{Zm3*n=((Zm3*)Zh(sizeof(*n)));*n=Z1j;((((Zm3*)(n)))->Z0j)=(((T0*)ZM71(a1)));R=((T0*)n);}_i=Zrs(2);_c=Zty(((Zn2*)(((C)->Zhe))));
while(!((Z3)((_i)>(_c)))){ZN71(((Zm3*)R),((T0*)ZM71(a1)));_i=(Z3)(((_i))+(Zrs(1)));}return R;}T6 ZO71(ZH6*C,T0*a1){T6 R=0;T2 _i=0;T0*_n1=Zo;
T0*_n2=Zo;T0*_t=Zo;R=((T6)(1));_i=Zty(((Zn2*)(((C)->Zhe))));while(!((T6)((!(R))||((T6)((_i)==(Zrs(0))))))){_t=ZI71(C,_i);if(Z7V(_t)){
if((ZvG(_t))!=((void*)(_t))){R=((T6)(0));}else if((Z9L(_t,a1))!=((void*)(_t))){R=((T6)(0));}}else{R=((T6)(0));}_i=(Z3)(((_i))-(Zrs(1)));
}if(R){_i=Zty(((Zn2*)(((C)->Zhe))));while(!((_i)==(Zrs(0)))){_n1=Zuy((Zn2*)(((C)->Zhe)),_i);_n2=ZP71(((Zi1*)_n1),a1);if((_n2)==((void*)(Zo))){
ZK71(((((Zi1*)_n1))->Zxb),ZD61);_i=Zrs(0);}else{_i=(Z3)(((_i))-(Zrs(1)));}}ZE71(C,a1);}return R;}void ZQ71(ZH6*C,T0*a1,T0*a2){*((ZH6*)(C))=*((ZH6*)(a1));
ZR71(C,a2);ZE71(C,a2);}T0*ZI71(ZH6*C,T2 a1){T0*R=Zo;R=(((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),a1)))->Zgc);return R;}void ZS71(ZH6*C){T0*_t=Zo;
T2 _i=0;T2 _n=0;((((T7*)((T7*)(ZT71))))->Zcc)=(Zrs(0));ZcH((Zi4*)(ZsG),((T3)'\173'));_i=Zrs(1);while(!((Z3)((_i)>(Zty(((Zn2*)(((C)->Zhe))))))))
{_t=ZvG(ZI71(C,_i));if(Z2H(_t)){Z7I((Zi4*)(ZsG),ZU71);ZXw((T7*)(ZT71),ZV71);ZQs(_n,ZT71);ZXw((T7*)(ZT71),ZW71);ZQs(_i,ZT71);ZXw((T7*)(ZT71),ZX71);
_n=(Z3)(((_n))+(Zrs(1)));}_i=(Z3)(((_i))+(Zrs(1)));}Z7I((Zi4*)(ZsG),ZY71);Z7I((Zi4*)(ZsG),ZT71);(C->Z7j)=_n;}T0*ZT71=Zo;void ZZ71(ZH6*C,T0*a1,T0*a2){
T2 _i=0;T0*_t=Zo;_i=Zrs(1);while(!((Z3)((_i)>(Zty(((Zn2*)(((C)->Zhe)))))))){_t=ZvG(ZI71(C,_i));ZXw(((T7*)a1),(((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),_i)))->Zre));
ZH61(_t,a1);ZXw(((T7*)a2),Z_71);ZQs(_i,a2);ZZs(((T7*)a2),((T3)'\054'));_i=(Z3)(((_i))+(Zrs(1)));}}void Z081(ZH6*C,T0*a1){T0*_an=Zo;T0*Z181=Zo;
T0*Z281=Zo;T0*ZNG=Zo;T0*Z381=Zo;T2 _i=0;T2 Zoe=0;Z481(C,a1);_i=Zty(((Zn2*)(((C)->Zhe))));while(!((_i)==(Zrs(0)))){_an=Zuy(((Zn2*)(((C)->Zhe))),_i);
Z181=((((Zi1*)_an))->Zgc);if(Zo!=(Z181)){switch(((T0*)Z181)->id){case 264:break;default:Z181=Zo;}}if((Z181)!=((void*)(Zo))){Zoe=ZJ71(C,(((ZB8*)(((((ZX4*)Z181))->ZUg)))->Zre));
if((Zoe)==(_i)){ZzF(((((ZX4*)Z181))->Zxb));{T0*b1=Z581;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else if((Z3)((Zoe)>(Zrs(0)))){{Zs3*n=((Zs3*)Zh(sizeof(*n)));
*n=Zqe;Z681(n,(((ZB8*)(((((ZX4*)Z181))->ZUg)))->Zxb),(T0*)C,Zoe);Z281=((T0*)n);}{Zp8*n=((Zp8*)Zh(sizeof(*n)));*n=ZWk;Z781(n,((((ZX4*)Z181))->Zxb),Z281);
ZNG=((T0*)n);}((((Zi1*)(((Zi1*)_an))))->Zgc)=(ZNG);}}_i=(Z3)(((_i))-(Zrs(1)));}if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(7)))){_i=Zty(((Zn2*)(((C)->Zhe))));
while(!((_i)==(Zrs(0)))){ZNG=(((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),_i)))->Zgc);if(Zo!=(ZNG)){switch(((T0*)ZNG)->id){case 267:break;default:
ZNG=Zo;}}if((ZNG)!=((void*)(Zo))){Zoe=ZJ71(C,Z881((Zs3*)(((((Zp8*)ZNG))->ZUg))));Z381=(((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),Zoe)))->Zgc);
if(Zo!=(Z381)){switch(((T0*)Z381)->id){case 267:break;default:Z381=Zo;}}if((Z381)!=((void*)(Zo))){ZzF(((((Zp8*)ZNG))->Zxb));ZzF(((((Zp8*)Z381))->Zxb));
{T0*b1=Z581;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}_i=(Z3)(((_i))-(Zrs(1)));}}}void Z981(ZH6*C){Z7I((Zi4*)(ZsG),Za81);ZtI((Zi4*)(ZsG),(T11)(((C)->Z7j)));
Z7I((Zi4*)(ZsG),Zb81);}void Zc81(ZH6*C){T2 _i=0;T0*_t=Zo;_i=Zrs(1);while(!((Z3)((_i)>(Zty(((Zn2*)(((C)->Zhe)))))))){_t=ZvG(ZI71(C,_i));
((((T7*)((T7*)(ZT71))))->Zcc)=(Zrs(0));ZEZ(_t,ZT71);ZZs((T7*)(ZT71),((T3)'\040'));Z7I((Zi4*)(ZsG),ZT71);ZL61((Zi4*)(ZsG));Zd81((Zi4*)(ZsG),_i);
ZM61((Zi4*)(ZsG));ZcH((Zi4*)(ZsG),((T3)'\075'));Ze81((Zi4*)(ZsG),_i);Z7I((Zi4*)(ZsG),Z8M);_i=(Z3)(((_i))+(Zrs(1)));}}void Zf81(ZH6*C,T0*a1){
T2 _i=0;T2 _c=0;_i=Zrs(1);_c=Zty(((Zn2*)(((C)->Zhe))));while(!((Z3)((_i)>(_c)))){Zg81((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),_i)),a1);_i=(Z3)(((_i))+(Zrs(1)));
}}void Zh81(ZH6*C,T0*a1){T2 _i=0;T0*_n2=Zo;_i=(((Zn2*)(((C)->Zhe)))->ZSb);while(!((Zuy((Zn2*)(((C)->Zhe)),_i))==((void*)(Zo)))){_n2=Zuy((Zn2*)(((C)->Zhe)),_i);
if((((((Zi1*)_n2))->Zre))==((void*)(((((Zi1*)a1))->Zre)))){ZzF(((((Zi1*)a1))->Zxb));ZzF(((((Zi1*)_n2))->Zxb));{T0*b1=ZvF(24,"Same name appears twice.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}_i=(Z3)(((_i))+(Zrs(1)));}{Zn2*C1=(Zn2*)(((C)->Zhe));T0*b1=a1;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}((((Zi1*)(((Zi1*)a1))))->Zoe)=(_i);}void Zi81(ZH6*C,T0*a1){T2 _i=0;T0*_t=Zo;_i=Zrs(1);while(!((Z3)((_i)>(Zty(((Zn2*)(((C)->Zhe))))))))
{_t=ZvG(ZI71(C,_i));Z_L(_t,a1);ZZs(((T7*)a1),((T3)'\040'));ZZs(((T7*)a1),((T3)'a'));ZQs(_i,a1);_i=(Z3)(((_i))+(Zrs(1)));if((Z3)((_i)<=(Zty(((Zn2*)(((C)->Zhe))))))){
ZZs(((T7*)a1),((T3)'\054'));}}}T6 Z4H(ZH6*C,T0*a1){T6 R=0;T2 _i=0;T0*Zj81=Zo;T6 Zk81=0;Zj81=a1;if(Zo!=(Zj81)){switch(((T0*)Zj81)->id){
case 157:case 263:break;default:Zj81=Zo;}}if((T6)(((T6)(((Zj81)!=((void*)(Zo)))&&((T6)(Z2H(ZOG(a1))))))&&((T6)(!(Z4G(a1)))))){_i=Zty(((Zn2*)(((C)->Zhe))));
while(!((Z3)((_i)<(Zrs(1))))){Zk81=((T6)((T6)((Zk81)||((T6)((Zl81(Zj81))==((void*)((((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),_i)))->Zre))))))));
if((((void)((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),_i)))),Zm81((T0*)C))){R=((T6)(1));}_i=(Z3)(((_i))-(Zrs(1)));}if(!(Zk81)){Z5H(a1);}}else{_i=Zty(((Zn2*)(((C)->Zhe))));
while(!((Z3)((_i)<(Zrs(1))))){if((((void)((Zi1*)(Zuy(((Zn2*)(((C)->Zhe))),_i)))),Zm81((T0*)C))){R=((T6)(1));}_i=(Z3)(((_i))-(Zrs(1)));
}}return R;}void ZR71(ZH6*C,T0*a1){T2 _i=0;T0*_n1=Zo;T0*_n2=Zo;(C->Zhe)=Zxy((Zn2*)(((C)->Zhe)));_i=(((Zn2*)(((C)->Zhe)))->ZRb);while(!((Z3)((_i)<((((Zn2*)(((C)->Zhe)))->ZSb)))))
{_n1=Zuy((Zn2*)(((C)->Zhe)),_i);_n2=ZP71(((Zi1*)_n1),a1);if((_n2)==((void*)(Zo))){ZK71(((((Zi1*)_n1))->Zxb),ZD61);}else{{Zn2*C1=(Zn2*)(((C)->Zhe));
T0*b1=_n2;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}_i=(Z3)(((_i))-(Zrs(1)));}}T6 Zn81(ZH6*C,T0*a1,T0*a2){T6 R=0;T2 _i=0;
T0*_t1=Zo;T0*_t2=Zo;_i=Zty(((Zn2*)(((C)->Zhe))));if((Zty(((Zn2*)(((((ZH6*)a1))->Zhe)))))!=(_i)){{T76 Z3w;ZzF((*(Z3w=Zo81(((ZH6*)a1)),&Z3w)));
}{T76 Z3w;ZK71((*(Z3w=Zo81(C),&Z3w)),ZvF(24,"Bad number of arguments."));}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){R=((T6)(1));while(!((T6)((!(R))||((T6)((_i)==(Zrs(0)))))))
{_t1=ZI71(C,_i);_t2=ZI71(((ZH6*)a1),_i);if(!(ZKJ(_t2,_t1,a2,(T6)(1)))){R=((T6)(0));ZxF((T75*)(ZyF));{T76 Z3w;ZzF((*(Z3w=Z3L(_t1),&Z3w)));
}{T76 Z3w;ZzF((*(Z3w=Z3L(_t2),&Z3w)));}{T0*b1=ZvF(22,"Incompatible types in ");ZXw((T7*)(ZwF),b1);}{T0*b1=ZDF(((((Ze4*)a2))->Z0c));ZXw((T7*)(ZwF),b1);
}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}_i=(Z3)(((_i))-(Zrs(1)));}}return R;}void Z481(ZH6*C,T0*a1){T2 _il=0;T2 ZS61=0;(C->ZUb)=a1;
_il=(((Z5a*)(((C)->ZUb)))->ZRb);while(!((Z3)((_il)<((((Z5a*)(((C)->ZUb)))->ZSb))))){ZS61=(Z3)(((ZS61))+(ZT61(ZU61(((C)->ZUb),_il))));
_il=(Z3)(((_il))-(Zrs(1)));}{Zn2*n=((Zn2*)Zh(sizeof(*n)));*n=ZGd;Zvy(n,(T2)(Zrs(1)),ZS61);(C->Zhe)=((T0*)n);}_il=(((Z5a*)(((C)->ZUb)))->ZSb);
while(!((Z3)((_il)>((((Z5a*)(((C)->ZUb)))->ZRb))))){ZV61(ZU61(((C)->ZUb),_il),(T0*)C);_il=(Z3)(((_il))+(Zrs(1)));}}T6 Zp81(ZH6*C){T6 R=0;
T2 _i=0;_i=(((Zn2*)(((C)->Zhe)))->ZRb);while(!((T6)((R)||((T6)((Z3)((_i)<((((Zn2*)(((C)->Zhe)))->ZSb)))))))){R=((T6)(ZtY((((Zi1*)(Zuy((Zn2*)(((C)->Zhe)),_i)))->Zgc))));
_i=(Z3)(((_i))-(Zrs(1)));}return R;}void Zq81(ZH6*C){Z7I((Zi4*)(ZsG),Zr81);ZtI((Zi4*)(ZsG),(T11)(((C)->Z7j)));Z7I((Zi4*)(ZsG),Zs81);}
T76 Zo81(ZH6*C){T76 R={Zo,Zo,0};R=(((Zi1*)(((((Zn2*)(((C)->Zhe)))->ZPb))[Zrs(0)]))->Zxb);return R;}T0*Zt81(Zi1*C){T0*R=Zo;R=((((C)->Zxb)).Zqb);
return R;}void Zu81(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}void ZF71(Zi1*C,T0*a1,T0*a2){T0*_rf=Zo;T0*_rc=Zo;
T0*_bc=Zo;_bc=Zt81(C);if(Zv81(((T82*)_bc),((C)->Zre))){_rc=Z8G(a1);_rf=Zw81(((Ze4*)_rc),((C)->Zre));if((_rf)!=((void*)(Zo))){{T76 Z3w;
ZzF((*(Z3w=ZCF(_rf),&Z3w)));}}Zu81(((C)->Zxb),a2);}}T6 Zx81(Zi1*C,T0*a1){T6 R=0;if(Zy81(((C)->Zgc),a1)){R=((T6)(1));}return R;}void Zz81(Zi1*C){
ZzF(((C)->Zxb));{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));
}void ZA81(Zi1*C,T76 a1,T0*a2){(C->Zxb)=a1;(C->Zre)=a2;}void ZB81(Zi1*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}ZzF(((C)->Zxb));ZxF((T75*)(ZyF));
}void Zg81(Zi1*C,T0*a1){T0*_t=Zo;_t=ZvG(((C)->Zgc));ZXU(_t,a1);ZZs(((T7*)a1),((T3)'\040'));ZZs(((T7*)a1),((T3)'\137'));ZXw(((T7*)a1),((C)->Zre));
ZZs(((T7*)a1),((T3)'\073'));}T6 Zm81(T0*a1){T6 R=0;return R;}void ZC81(Zi1*C,T0*a1){T6 Z7H=0;T0*_rt=Zo;Z7H=((T6)(Z9H((Zi4*)(ZsG),a1)));
_rt=ZvG(((C)->Zgc));if(ZaH(_rt)){if(ZaH(a1)){ZcH((Zi4*)(ZsG),((T3)'\050'));ZbH(a1);Zd81((Zi4*)(ZsG),((C)->Zoe));ZcH((Zi4*)(ZsG),((T3)'\051'));
}else{Zd81((Zi4*)(ZsG),((C)->Zoe));}}else if(ZaH(a1)){Zd81((Zi4*)(ZsG),((C)->Zoe));}else if(Z4_(_rt)){if(!(ZjW(_rt))){ZcH((Zi4*)(ZsG),((T3)'\046'));
}Zd81((Zi4*)(ZsG),((C)->Zoe));}else{Zd81((Zi4*)(ZsG),((C)->Zoe));}if(Z7H){ZfH((Zi4*)(ZsG));}}T0*ZD81(Zi1*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Zi1*)R)=*C;return R;}T2 ZE81(Zi1*C){T2 R=0;ZB81(C);return R;}T0*ZP71(Zi1*C,T0*a1){T0*R=Zo;T0*_rt=Zo;_rt=Z9L(((C)->Zgc),a1);if((_rt)==((void*)(Zo))){
{T76 Z3w;ZzF((*(Z3w=Z3L(((C)->Zgc)),&Z3w)));}Zu81(((C)->Zxb),ZcG);}if((((C)->Zgc))==((void*)(_rt))){R=((T0*)(C));}else{R=ZD81(C);((((Zi1*)(((Zi1*)R))))->Zgc)=(_rt);
}return R;}T0*ZF81(Zi1*C){T0*R=Zo;R=ZwH(((C)->Zgc));return R;}
#ifdef __cplusplus
}
#endif

