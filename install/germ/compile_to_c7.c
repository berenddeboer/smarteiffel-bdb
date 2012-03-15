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
T6 ZcV(ZI1*C,T0*a1){T6 R=0;T2 _i=0;if((((C)->ZUb))!=((void*)(Zo))){_i=(((ZP*)(((C)->ZUb)))->ZRb);while(!((T6)((R)||((T6)((Z3)((_i)<(Zrs(0))))))))
{R=((T6)(ZNu((T7*)((((T88*)(((((ZP*)(((C)->ZUb)))->ZPb))[_i]))->Zre)),a1)));_i=(Z3)(((_i))-(Zrs(1)));}}return R;}void ZdV(T0*a1,T2 a2){
if(((((T84*)(ZFI))->Zcf))==(Zrs(1))){ZeV(((Z47*)a1),a2);}}void ZfV(ZI1*C){if((((C)->Z7d))!=((void*)(Zo))){ZgV((Z47*)(((C)->Z7d)));}}void
ZhV(ZI1*C,T76 a1,T0*a2,T0*a3){(C->Zxb)=a1;(C->ZUb)=a2;(C->Z7d)=a3;}void ZiV(ZI1*C){if((((C)->Z7d))!=((void*)(Zo))){ZjV((Z47*)(((C)->Z7d)));
}}T6 ZkV(ZI1*C){T6 R=0;if((((C)->Z7d))!=((void*)(Zo))){R=((T6)(ZlV((Z47*)(((C)->Z7d)))));}return R;}void ZmV(ZI1*C,T0*a1){if((((C)->Z7d))!=((void*)(Zo))){
ZnV((Z47*)(((C)->Z7d)),a1);}}T0*ZoV(ZI1*C,T0*a1){T0*R=Zo;if((ZPA(((T74*)(((((T86*)a1))->ZUb)))))==(Zrs(1))){R=((T0*)(C));}else{{Zn8*n=((Zn8*)Zh(sizeof(*n)));
*n=ZVk;Z1N(n,(T0*)C,a1);R=((T0*)n);}}return R;}T0*ZpV(ZI1*C,T0*a1){T0*R=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;if((((C)->Z7d))!=((void*)(Zo))){
(C->Z7d)=ZqV((Z47*)(((C)->Z7d)),a1);}R=((T0*)(C));}else{{ZI1*n=((ZI1*)Zh(sizeof(*n)));*n=Z8d;ZhV(n,((C)->Zxb),((C)->ZUb),((C)->Z7d));
R=((T0*)n);}R=ZpV(((ZI1*)R),a1);}return R;}void ZrV(ZM1*C){ZsV(C);ZTF((((ZB8*)(((C)->ZZb)))->Zxb),((C)->ZAb),((C)->Z_b));}T0*ZtV(T0*a1,T0*a2,T0*a3){
T0*R=Zo;T0*ZVF=Zo;T0*ZWF=Zo;R=a1;if(ZXF(a2)){if(ZXF(a3)){ZWF=ZDF(a3);ZVF=ZDF(a2);if((ZWF)!=((void*)(ZVF))){if(ZYF(a2,a3)){R=ZZF(a1,a3);
}else{((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));}}}}return R;}T6 ZuV(ZM1*C,T0*a1){T6 R=0;T0*_tr=Zo;
if((((C)->ZAb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(Z3G((Zm3*)(((C)->ZAb)),a1)));}if(R){if((((C)->Z_b))==((void*)(Zo))){}else if(Z4G(((C)->ZYb))){
if(Z5G(((C)->Z_b),a1)){R=((T6)((Z6G(((C)->Z_b),a1))!=((void*)(Zo))));}else{R=((T6)(0));}}else{R=((T6)(Z7G(((C)->ZYb),a1)));if(R){if((((C)->Z_b))!=((void*)(Zo))){
_tr=(((Ze4*)(Z8G((((ZS7*)(((C)->Z_b)))->Z0c))))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)_tr))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
R=((T6)(Z5G(((C)->Z_b),_tr)));}}}}}return R;}T0*ZvV(ZM1*C,T0*a1){T0*R=Zo;R=ZaG((Zm3*)(((C)->ZAb)),a1);if((R)==((void*)(Zo))){{T76 Z3w;
ZzF((*(Z3w=ZbG((Zm3*)(((C)->ZAb))),&Z3w)));}{T0*b1=ZcG;ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}return R;}T0*ZwV(ZM1*C){T0*R=Zo;
T0*Zof=Zo;T0*_rf=Zo;(C->ZYb)=ZjG(((C)->ZYb));ZkG((Zm3*)(((C)->ZAb)));if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){R=((T0*)(C));}else if((ZLR)==((void*)((((ZB8*)(((C)->ZZb)))->Zre)))){
if((T6)(((T6)((Z5T(ZOG(((C)->ZYb))))&&((T6)(ZxV(((C)->ZYb))))))&&((T6)(ZxV(((((Zm3*)(((C)->ZAb))))->Z0j)))))){{Za5*n=((Za5*)Zh(sizeof(*n)));
*n=Z5h;ZpH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}else{Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);if((T6)(((T6)(((T6)((((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1)))&&((T6)(ZxV(((C)->ZYb))))))&&((T6)(ZxV(((((Zm3*)(((C)->ZAb))))->Z0j))))))&&((T6)(((((T80*)(((((T82*)((((Z85*)(ZyV(((C)->Z_b))))->Zqb))))->Zkc)))->Zre))==((void*)(ZpK)))))){
{Za5*n=((Za5*)Zh(sizeof(*n)));*n=Z5h;ZpH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}else{R=((T0*)(C));}}}else if(Z4G(((C)->ZYb))){if(ZxV(((((Zm3*)(((C)->ZAb))))->Z0j))){
R=ZzV(C,((C)->Z_b));}else{R=((T0*)(C));}}else if(((Z3)(((((((ZC3*)((((Zc3*)((((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof)))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1))){
if((T6)((ZxV(((C)->ZYb)))&&((T6)(ZxV(((((Zm3*)(((C)->ZAb))))->Z0j)))))){Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);_rf=ZCH((Ze4*)((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZPb))[Zrs(0)]),((C)->Z_b));
R=ZzV(C,_rf);}else{R=((T0*)(C));}}else{R=((T0*)(C));}return R;}void ZAV(ZM1*C){T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){if((((C)->ZAb))!=((void*)(Zo))){
Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>=(Zrs(1)))){{T76
Z3w;ZmG((T41*)(Z1G),(*(Z3w=ZBV(C),&Z3w)),((C)->Z_b),Zof);}}}}ZoG(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){ZpG((Zm3*)(((C)->ZAb)));
}}T0*ZzV(ZM1*C,T0*a1){T0*R=Zo;T0*ZCV=Zo;ZCV=a1;if(Zo!=(ZCV)){switch(((T0*)ZCV)->id){case 565:break;default:ZCV=Zo;}}if((ZCV)!=((void*)(Zo))){
R=ZDV(((ZK7*)ZCV));}if((R)==((void*)(Zo))){R=((T0*)(C));}return R;}void ZsV(ZM1*C){if((ZqG(((C)->Z_b)))==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZCF(((C)->Z_b)),&Z3w)));
}ZzF((((ZB8*)(((C)->ZZb)))->Zxb));ZEV(ZvF(29,"Feature found is a procedure."));}}T6 ZFV(ZM1*C,T0*a1){T6 R=0;R=((T6)(ZuV(C,a1)));if(R){
R=((T6)(!(ZuG(ZvG(ZGV(C))))));}return R;}void ZHV(ZM1*C,T0*a1,T0*a2){ZyG(((C)->ZYb),a1,a2);ZzG((Zm3*)(((C)->ZAb)),a1,a2);}void ZIV(ZM1*C){
{T76 Z3w;ZzF((*(Z3w=ZBV(C),&Z3w)));}{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}void ZJV(ZM1*C,T0*a1,T0*a2,T0*a3){(C->ZYb)=a1;(C->ZZb)=a2;(C->ZAb)=a3;}void ZKV(ZM1*C,T0*a1){T0*_t=Zo;_t=ZFG(((C)->ZYb),a1);
if((_t)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZYb)),&Z3w)));}{T0*b1=ZvF(11,"Bad target.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));
}(C->ZYb)=_t;}void ZEV(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZLV(ZM1*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}{T76 Z3w;
ZzF((*(Z3w=ZBV(C),&Z3w)));}ZxF((T75*)(ZyF));}T2 ZMV(void){T2 R=0;return R;}void ZNV(ZM1*C,T3 a1){if((a1)==(((T3)'R'))){{T76 Z3w;ZLG(((C)->Z_b),(*(Z3w=ZBV(C),&Z3w)));
}}ZMG(((C)->ZYb),a1);ZMG(((((Zm3*)(((C)->ZAb))))->Z0j),a1);}T0*ZGV(ZM1*C){T0*R=Zo;T0*ZNG=Zo;R=ZqG(((C)->Z_b));ZNG=R;if(Zo!=(ZNG)){switch(((T0*)ZNG)->id){
case 267:break;default:ZNG=Zo;}}if((ZNG)!=((void*)(Zo))){R=ZvG(ZOG(((((Zm3*)(((C)->ZAb))))->Z0j)));}return R;}void ZOV(ZM1*C){T0*ZQG=Zo;
T0*_rc=Zo;T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){ZQG=ZOG(((C)->ZYb));_rc=Z8G(ZQG);Zof=((((Ze4*)_rc))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
ZRG(((C)->ZYb),((C)->Z_b));}}ZSG(((C)->ZYb));ZTG((Zm3*)(((C)->ZAb)));}T6 ZPV(ZM1*C){T6 R=0;R=((T6)(ZVG((Zm3*)(((C)->ZAb)))));if(R){}else
if(Z4G(((C)->ZYb))){if((ZWG())!=((void*)(((C)->Z_b)))){R=((T6)(ZXG(((C)->Z_b))));}}else{R=((T6)(ZYG(((C)->ZYb))));}return R;}T6 ZQV(ZM1*C){
T6 R=0;if(Z_G(((C)->ZYb))){if((((C)->ZAb))!=((void*)(Zo))){R=((T6)(Z0H((Zm3*)(((C)->ZAb)))));}else{R=((T6)(1));}}return R;}T6 ZRV(ZM1*C,T0*a1){
T6 R=0;R=((T6)(Z2H(ZOG(((C)->ZYb)))));R=((T6)((T6)((Z3H(((C)->ZYb),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z4H(((ZH6*)a1),((C)->ZYb))){
R=((T6)(1));}}else if((T6)((Z2H(ZOG(((C)->ZYb))))&&((T6)(!(Z4G(((C)->ZYb))))))){Z5H(((C)->ZYb));}return R;}void ZSV(ZM1*C,T0*a1){T6 Z7H=0;
T0*Z8H=Zo;Z7H=((T6)(Z9H((Zi4*)(ZsG),a1)));Z8H=ZvG(ZGV(C));if(ZaH(Z8H)){if(ZaH(a1)){ZbH(a1);ZcH((Zi4*)(ZsG),((T3)'\050'));{ZM1*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);
}ZcH((Zi4*)(ZsG),((T3)'\051'));}else{{ZM1*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}}else{if(ZaH(a1)){{ZM1*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}else{
if(ZeH(a1)){ZcH((Zi4*)(ZsG),((T3)'\046'));ZcH((Zi4*)(ZsG),((T3)'\050'));{ZM1*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}ZcH((Zi4*)(ZsG),((T3)'\051'));
}else{{ZM1*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}}}if(Z7H){ZfH((Zi4*)(ZsG));}}void ZTV(ZM1*C,T0*a1){T0*_rf=Zo;T0*_rc=Zo;T0*_rt=Zo;T0*_bc=Zo;
_rt=ZOG(((C)->ZYb));if((_rt)!=((void*)(Zo))){_rc=Z8G(_rt);if((_rc)!=((void*)(Zo))){_bc=((((Ze4*)_rc))->Zqb);_rf=ZhH(((T82*)_bc),_rc,((C)->ZYb),((C)->ZZb),a1);
}}if((_rf)==((void*)(Zo))){ZzF((((ZB8*)(((C)->ZZb)))->Zxb));{T0*b1=ZvF(25,"Bad target for this call.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));
}(C->Z_b)=_rf;}T2 ZUV(ZM1*C){T2 R=0;ZLV(C);return R;}T0*ZVV(ZM1*C,T0*a1){T0*R=Zo;T0*ZlH=Zo;T0*ZkH=Zo;T0*ZXl=Zo;T0*_rc=Zo;T0*_fn=Zo;if((((C)->Z0c))==((void*)(Zo))){
(C->Z0c)=a1;ZKV(C,a1);ZlH=ZOG(((C)->ZYb));ZXl=ZvG(ZlH);if(Zo!=(ZXl)){switch(((T0*)ZXl)->id){case 283:case 285:break;default:ZXl=Zo;}}
if((ZXl)!=((void*)(Zo))){_rc=ZWV(((ZW9*)ZXl));(C->Z_b)=ZXV(((Ze4*)_rc),ZXl,((C)->ZZb));(C->ZAb)=ZYV((Zm3*)(((C)->ZAb)));(C->ZAb)=ZvV(C,a1);
}else{(C->ZAb)=ZvV(C,a1);ZkH=ZOG(((((Zm3*)(((C)->ZAb))))->Z0j));(C->ZYb)=ZtV(((C)->ZYb),ZlH,ZkH);ZTV(C,a1);}if((ZXl)!=((void*)(Zo))){
_fn=(((ZB8*)(((C)->ZZb)))->Zre);if((_fn)!=((void*)(ZeR))){{T0*b1=ZvF(67,"You must use \"item\" to get the result of the execution of an agent.");
ZXw((T7*)(ZwF),b1);}if((_fn)==((void*)(ZyQ))){{T0*b1=ZvF(35," (Just replace \"call\" with \"item\".)");ZXw((T7*)(ZwF),b1);}}ZzF((((ZB8*)(((C)->ZZb)))->Zxb));
ZEF((T75*)(ZyF));}{ZD4*n=((ZD4*)Zh(sizeof(*n)));*n=Zwg;ZZV(n,(T0*)C);R=((T0*)n);}}else{ZrV(C);R=((T0*)(C));}}else{{ZM1*n=((ZM1*)Zh(sizeof(*n)));
*n=Zad;ZJV(n,((C)->ZYb),((C)->ZZb),((C)->ZAb));R=((T0*)n);}R=ZFG(R,a1);}return R;}T0*Z_V(ZM1*C){T0*R=Zo;T0*_bc=Zo;T0*ZsH=Zo;T0*_rt=Zo;
_bc=ZtH(((C)->ZYb));if((_bc)!=((void*)(Zo))){ZsH=ZuH(((T82*)_bc),((C)->ZZb));if((ZsH)!=((void*)(Zo))){_rt=ZvH(ZsH);if((_rt)!=((void*)(Zo))){
R=ZwH(_rt);}}}return R;}void Z0W(ZM1*C){if((((C)->Z_b))!=((void*)(Zo))){ZyH(((C)->Z_b));}ZzH(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){
ZAH((Zm3*)(((C)->ZAb)));}}void Z1W(ZM1*C){T0*_rc=Zo;T0*_rf=Zo;_rf=((C)->Z_b);_rc=((((ZS7*)_rf))->Znf);(C->Z_b)=ZCH((Ze4*)((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZPb))[Zrs(0)]),_rf);
}T76 ZBV(ZM1*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((C)->ZZb)))->Zxb);return R;}void Z2W(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}
ZxF((T75*)(ZyF));}void Z3W(ZO1*C,T0*a1,T0*a2,T0*a3,T0*a4){(C->Zbd)=a1;(C->Zcd)=a2;(C->Zdd)=a3;(C->ZTc)=a4;}void Z4W(ZO1*C){ZSG(((C)->ZTc));
}T6 Z5W(ZO1*C){T6 R=0;R=((T6)(ZYG(((C)->ZTc))));return R;}void Z6W(ZO1*C,T0*a1){T6 Z_M=0;Z_M=((T6)(Z3H(((C)->ZTc),a1)));}T0*Z7W(ZO1*C,T0*a1){
T0*R=Zo;T0*_e=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;_e=ZFG(((C)->ZTc),a1);if((_e)==((void*)(Zo))){{T76 Z3w;Z2W((*(Z3w=Z8W(C),&Z3w)),ZvF(17,"Bad loop variant."));
}}else{(C->ZTc)=_e;if(!(Z1P(ZOG(((C)->ZTc))))){{T76 Z3w;Z2W((*(Z3w=ZGG(((C)->ZTc)),&Z3w)),ZvF(38,"Expression of variant must be INTEGER."));
}}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){R=((T0*)(C));}}else{{ZO1*n=((ZO1*)Zh(sizeof(*n)));*n=Zed;Z3W(n,((C)->Zbd),((C)->Zcd),((C)->Zdd),((C)->ZTc));
R=((T0*)n);}R=Z7W(((ZO1*)R),a1);}return R;}T76 Z8W(ZO1*C){T76 R={Zo,Zo,0};if((((C)->Zcd))!=((void*)(Zo))){R=(((ZB6*)(((C)->Zcd)))->Zxb);
}else{{T76 Z3w;R=(*(Z3w=ZGG(((C)->ZTc)),&Z3w));}}return R;}void Z9W(ZQ1*C){ZaW(C);ZTF((((ZB8*)(((C)->ZZb)))->Zxb),Zo,((C)->Z_b));}T0*ZbW(ZQ1*C,T0*a1){
T0*R=Zo;T0*ZCV=Zo;ZCV=a1;if(Zo!=(ZCV)){switch(((T0*)ZCV)->id){case 565:break;default:ZCV=Zo;}}if((ZCV)!=((void*)(Zo))){R=ZDV(((ZK7*)ZCV));
}if((R)==((void*)(Zo))){R=((T0*)(C));}return R;}T6 ZcW(ZQ1*C,T0*a1){T6 R=0;T0*_tr=Zo;R=((T6)(1));if(R){if((((C)->Z_b))==((void*)(Zo))){
}else if(Z4G(((C)->ZYb))){if(Z5G(((C)->Z_b),a1)){R=((T6)((Z6G(((C)->Z_b),a1))!=((void*)(Zo))));}else{R=((T6)(0));}}else{R=((T6)(Z7G(((C)->ZYb),a1)));
if(R){if((((C)->Z_b))!=((void*)(Zo))){_tr=(((Ze4*)(Z8G((((ZS7*)(((C)->Z_b)))->Z0c))))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)_tr))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
R=((T6)(Z5G(((C)->Z_b),_tr)));}}}}}return R;}T0*ZdW(ZQ1*C){T0*R=Zo;T0*Zkc=Zo;T0*ZeW=Zo;T0*Zof=Zo;T0*_ic=Zo;T0*ZlH=Zo;T76 _sp={Zo,Zo,0};
T0*_rf=Zo;(C->ZYb)=ZjG(((C)->ZYb));ZlH=ZvG(ZOG(((C)->ZYb)));Zkc=(((ZB8*)((((ZS7*)(((C)->Z_b)))->Zkc)))->Zre);if((ZbR)==((void*)(Zkc))){
if(Z5T(ZlH)){{Za5*n=((Za5*)Zh(sizeof(*n)));*n=Z5h;ZpH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}else{{ZX8*n=((ZX8*)Zh(sizeof(*n)));
*n=Zel;ZqH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}if(!(ZxV(((C)->ZYb)))){{T0*b1=ZvF(114,"Must use \173""GENERAL\175"".is_expanded_type with such a target expression (keep in mind that the target is not evaluated).");
ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZYb)),&Z3w)));}ZEF((T75*)(ZyF));}}else if((Z8R)==((void*)(Zkc))){if(ZXF(ZlH)){{Za5*n=((Za5*)Zh(sizeof(*n)));
*n=Z5h;ZpH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}else{{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zel;ZqH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);
}}if(!(ZxV(((C)->ZYb)))){{T0*b1=ZvF(120,"Must use \173""GENERAL\175"".is_basic_expanded_type with such a target expression (keep in mind that the target is not evaluated).");
ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZYb)),&Z3w)));}ZEF((T75*)(ZyF));}}else if((ZaR)==((void*)(Zkc))){_sp=(((ZB8*)(((C)->ZZb)))->Zxb);
if(Z1P(ZlH)){{Zs1*n=((Zs1*)Zh(sizeof(*n)));*n=ZIl;ZxJ(n,(T11)(Zrs(0)),_sp);_ic=((T0*)n);}{ZN2*n=((ZN2*)Zh(sizeof(*n)));*n=ZRd;ZfW(n,((C)->ZYb),_sp,_ic);
R=((T0*)n);}R=ZjG(R);}else if((T6)((ZTO(ZlH))||((T6)(ZSS(ZlH))))){{Zy9*n=((Zy9*)Zh(sizeof(*n)));*n=Z4m;ZgW(n,_sp,ZhW);R=((T0*)n);}{ZN2*n=((ZN2*)Zh(sizeof(*n)));
*n=ZRd;ZfW(n,((C)->ZYb),_sp,R);R=((T0*)n);}R=ZjG(R);}else if(Z2T(ZlH)){{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zel;ZqH(n,_sp);R=((T0*)n);}{ZN2*n=((ZN2*)Zh(sizeof(*n)));
*n=ZRd;ZfW(n,((C)->ZYb),_sp,R);R=((T0*)n);}R=ZjG(R);}else if(Z6P(ZlH)){{ZN4*n=((ZN4*)Zh(sizeof(*n)));*n=ZOg;ZiW(n,_sp,((T3)'\000'));R=((T0*)n);
}{ZN2*n=((ZN2*)Zh(sizeof(*n)));*n=ZRd;ZfW(n,((C)->ZYb),_sp,R);R=((T0*)n);}R=ZjG(R);}else if(ZjW(ZlH)){{Za5*n=((Za5*)Zh(sizeof(*n)));*n=Z5h;
ZpH(n,_sp);R=((T0*)n);}}else if(Z4L(ZlH)){{Za5*n=((Za5*)Zh(sizeof(*n)));*n=Z5h;ZpH(n,_sp);R=((T0*)n);}}else{R=((T0*)(C));}}else if((T6)(((ZDQ)==((void*)(Zkc)))&&((T6)(ZeN(ZlH))))){
ZeW=ZlH;if(Zo!=(ZeW)){switch(((T0*)ZeW)->id){case 291:case 293:break;default:ZeW=Zo;}}_sp=(((ZB8*)(((C)->ZZb)))->Zxb);{Zs1*n=((Zs1*)Zh(sizeof(*n)));
*n=ZIl;ZxJ(n,(T11)(ZkW(ZeW)),_sp);R=((T0*)n);}}if((R)!=((void*)(Zo))){}else if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){R=((T0*)(C));}
else if(Z4G(((C)->ZYb))){R=ZlW(C,((C)->Z_b));}else if(ZIT(((C)->ZYb))){R=ZlW(C,((C)->Z_b));}else if(((Z3)(((((((ZC3*)((((Zc3*)((((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof)))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1))){
if(ZxV(((C)->ZYb))){Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);_rf=ZCH((Ze4*)((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZPb))[Zrs(0)]),((C)->Z_b));
R=ZlW(C,_rf);}else{R=((T0*)(C));}}else{R=((T0*)(C));}return R;}void ZmW(ZQ1*C){T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){}ZoG(((C)->ZYb));
}T0*ZlW(ZQ1*C,T0*a1){T0*R=Zo;T0*ZnW=Zo;R=ZbW(C,a1);if((R)==((void*)(C))){ZnW=a1;if(Zo!=(ZnW)){switch(((T0*)ZnW)->id){case 556:break;default:
ZnW=Zo;}}if((ZnW)!=((void*)(Zo))){R=((((ZE7*)ZnW))->Zde);}}return R;}void ZaW(ZQ1*C){if((ZqG(((C)->Z_b)))==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZCF(((C)->Z_b)),&Z3w)));
}ZzF((((ZB8*)(((C)->ZZb)))->Zxb));ZoW(ZvF(29,"Feature found is a procedure."));}}void ZpW(ZQ1*C){T0*_n=Zo;_n=(((ZB8*)(((C)->ZZb)))->Zre);
if((ZbR)==((void*)(_n))){if(Z5T(ZvG(ZOG(((C)->ZYb))))){ZcH((Zi4*)(ZsG),((T3)'1'));}else{ZcH((Zi4*)(ZsG),((T3)'0'));}}else if((Z8R)==((void*)(_n))){
if(ZXF(ZOG(((C)->ZYb)))){ZcH((Zi4*)(ZsG),((T3)'1'));}else{ZcH((Zi4*)(ZsG),((T3)'0'));}}else{{ZQ1*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}}T6 ZqW(ZQ1*C,T0*a1){
T6 R=0;R=((T6)(ZcW(C,a1)));if(R){R=((T6)(!(ZuG(ZvG(ZrW(C))))));}return R;}void ZsW(ZQ1*C,T0*a1,T0*a2){ZyG(((C)->ZYb),a1,a2);}void ZtW(ZQ1*C){
{T76 Z3w;ZzF((*(Z3w=ZuW(C),&Z3w)));}{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}void ZvW(ZQ1*C,T0*a1,T0*a2){(C->ZYb)=a1;(C->ZZb)=a2;}void ZwW(ZQ1*C,T0*a1){T0*_t=Zo;_t=ZFG(((C)->ZYb),a1);if((_t)==((void*)(Zo))){
{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZYb)),&Z3w)));}{T0*b1=ZvF(11,"Bad target.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}(C->ZYb)=_t;}
void ZoW(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZxW(ZQ1*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=ZuW(C),&Z3w)));
}ZxF((T75*)(ZyF));}T2 ZyW(void){T2 R=0;return R;}void ZzW(ZQ1*C,T3 a1){if((a1)==(((T3)'R'))){{T76 Z3w;ZLG(((C)->Z_b),(*(Z3w=ZuW(C),&Z3w)));
}}ZMG(((C)->ZYb),a1);}T0*ZrW(ZQ1*C){T0*R=Zo;R=ZqG(((C)->Z_b));return R;}void ZAW(ZQ1*C){T0*ZQG=Zo;T0*_rc=Zo;T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){
ZQG=ZOG(((C)->ZYb));_rc=Z8G(ZQG);Zof=((((Ze4*)_rc))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
ZRG(((C)->ZYb),((C)->Z_b));}}ZSG(((C)->ZYb));}T6 ZBW(ZQ1*C){T6 R=0;if(R){}else if(Z4G(((C)->ZYb))){if((ZWG())!=((void*)(((C)->Z_b)))){
R=((T6)(ZXG(((C)->Z_b))));}}else{R=((T6)(ZYG(((C)->ZYb))));}return R;}T6 ZCW(ZQ1*C){T6 R=0;if(Z_G(((C)->ZYb))){R=((T6)(1));}return R;
}T6 ZDW(ZQ1*C,T0*a1){T6 R=0;R=((T6)(Z2H(ZOG(((C)->ZYb)))));R=((T6)((T6)((Z3H(((C)->ZYb),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z4H(((ZH6*)a1),((C)->ZYb))){
R=((T6)(1));}}else if((T6)((Z2H(ZOG(((C)->ZYb))))&&((T6)(!(Z4G(((C)->ZYb))))))){Z5H(((C)->ZYb));}return R;}T6 ZEW(ZQ1*C){T6 R=0;T0*_rf=Zo;
T0*Zof=Zo;if(ZxV(((C)->ZYb))){if((Z3)(((((T41*)(Z1G))->ZIk))>=(Zrs(4)))){_rf=((C)->Z_b);Zof=(((Ze4*)(((((ZS7*)_rf))->Znf)))->Zof);if(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(1))){
_rf=ZCH((Ze4*)((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZPb))[Zrs(0)]),_rf);R=((T6)(ZFW(_rf)));}}}return R;}void ZGW(ZQ1*C,T0*a1){T6 Z7H=0;
T0*Z8H=Zo;Z7H=((T6)(Z9H((Zi4*)(ZsG),a1)));Z8H=ZvG(ZrW(C));if(ZaH(Z8H)){if(ZaH(a1)){ZbH(a1);ZcH((Zi4*)(ZsG),((T3)'\050'));ZpW(C);ZcH((Zi4*)(ZsG),((T3)'\051'));
}else{ZpW(C);}}else{if(ZaH(a1)){ZpW(C);}else{if(ZeH(a1)){ZcH((Zi4*)(ZsG),((T3)'\046'));ZcH((Zi4*)(ZsG),((T3)'\050'));ZpW(C);ZcH((Zi4*)(ZsG),((T3)'\051'));
}else{ZpW(C);}}}if(Z7H){ZfH((Zi4*)(ZsG));}}void ZHW(ZQ1*C,T0*a1){T0*_rf=Zo;T0*_rc=Zo;T0*_rt=Zo;T0*_bc=Zo;_rt=ZOG(((C)->ZYb));if((_rt)!=((void*)(Zo))){
_rc=Z8G(_rt);if((_rc)!=((void*)(Zo))){_bc=((((Ze4*)_rc))->Zqb);_rf=ZhH(((T82*)_bc),_rc,((C)->ZYb),((C)->ZZb),a1);}}if((_rf)==((void*)(Zo))){
ZzF((((ZB8*)(((C)->ZZb)))->Zxb));{T0*b1=ZvF(25,"Bad target for this call.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}(C->Z_b)=_rf;
}T2 ZIW(ZQ1*C){T2 R=0;T0*ZnW=Zo;ZnW=((C)->Z_b);if(Zo!=(ZnW)){switch(((T0*)ZnW)->id){case 556:break;default:ZnW=Zo;}}if((ZnW)==((void*)(Zo))){
ZxW(C);}else{R=ZwT(((((ZE7*)ZnW))->Zde));}return R;}T0*ZJW(ZQ1*C,T0*a1){T0*R=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;ZwW(C,a1);
ZHW(C,a1);R=((T0*)(C));Z9W(C);}else{{ZQ1*n=((ZQ1*)Zh(sizeof(*n)));*n=Zfd;ZvW(n,((C)->ZYb),((C)->ZZb));R=((T0*)n);}R=ZJW(((ZQ1*)R),a1);
}return R;}T0*ZKW(ZQ1*C){T0*R=Zo;T0*_bc=Zo;T0*ZsH=Zo;T0*_rt=Zo;_bc=ZtH(((C)->ZYb));if((_bc)!=((void*)(Zo))){ZsH=ZuH(((T82*)_bc),((C)->ZZb));
if((ZsH)!=((void*)(Zo))){_rt=ZvH(ZsH);if((_rt)!=((void*)(Zo))){R=ZwH(_rt);}}}return R;}void ZLW(ZQ1*C){if((((C)->Z_b))!=((void*)(Zo))){
ZyH(((C)->Z_b));}ZzH(((C)->ZYb));}void ZMW(ZQ1*C){T0*_rc=Zo;T0*_rf=Zo;_rf=((C)->Z_b);_rc=((((ZS7*)_rf))->Znf);(C->Z_b)=ZCH((Ze4*)((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZPb))[Zrs(0)]),_rf);
}T76 ZuW(ZQ1*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((C)->ZZb)))->Zxb);return R;}T0*ZNW(ZS1*C,T0*a1){T0*R=Zo;{Zn8*n=((Zn8*)Zh(sizeof(*n)));*n=ZVk;
Z1N(n,(T0*)C,a1);R=((T0*)n);}return R;}T0*ZOW(ZS1*C,T0*a1){T0*R=Zo;T0*_rf=Zo;_rf=ZWG();if((((C)->Z_b))==((void*)(Zo))){(C->Z_b)=_rf;R=((T0*)(C));
}else if((((C)->Z_b))==((void*)(_rf))){R=((T0*)(C));}else{{ZS1*n=((ZS1*)Zh(sizeof(*n)));*n=Zgd;((((ZS1*)(n)))->Zxb)=(((C)->Zxb));R=((T0*)n);
}R=ZOW(((ZS1*)R),a1);}return R;}void ZRT(ZW1*C,T0*a1){T0*_rf=Zo;T0*ZPW=Zo;T0*_rc=Zo;if((((C)->Zkd))==((void*)(Zo))){ZzF(((C)->Zxb));{T0*b1=ZvF(50,"Cannot create a class with an empty creation list.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}if((Z3)((ZSJ((Zx8*)(((C)->Zkd))))>(Zrs(1)))){ZsS(a1,ZQT);ZzF(((C)->Zxb));{T0*b1=ZvF(106,"Expanded class must have no creation procedure, or only one creation procedure with no arguments (VTEC.2).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}_rc=Z8G(a1);_rf=ZaL(((Ze4*)_rc),(((Zx8*)(((C)->Zkd)))->ZBd));if((_rf)==((void*)(Zo))){ZzF(((C)->Zxb));
{T0*b1=ZvF(23,"Creation procedure for ");ZXw((T7*)(ZwF),b1);}ZsS(a1,ZvF(11," not found."));ZEF((T75*)(ZyF));}ZPW=_rf;if(Zo!=(ZPW)){switch(((T0*)ZPW)->id){
case 435:break;default:ZPW=Zo;}}if((ZPW)==((void*)(Zo))){ZzF(((C)->Zxb));{T76 Z3w;ZzF((*(Z3w=ZCF(_rf),&Z3w)));}{T0*b1=ZvF(33,ZYp);ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}if((((((ZI7*)ZPW))->ZAb))!=((void*)(Zo))){ZsS(a1,ZQT);ZzF(((C)->Zxb));{T76 Z3w;ZzF((*(Z3w=ZQW(((ZI7*)ZPW)),&Z3w)));
}{T0*b1=ZvF(31,"Procedure found has arguments. ");ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(106,"Expanded class must have no creation procedure, or only one creation procedure with no arguments (VTEC.2).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}T0*ZTT(ZW1*C){T0*R=Zo;if((((C)->Zkd))!=((void*)(Zo))){if(ZRW((Zx8*)(((C)->Zkd)))){R=ZkR;}else{
R=(((ZB8*)((((Zx8*)(((C)->Zkd)))->ZBd)))->Zre);}}return R;}void ZSW(ZW1*C,T76 a1,T0*a2,T0*a3,T0*a4){(C->Zxb)=a1;(C->Zec)=a2;(C->Zjd)=a3;
(C->Zkd)=a4;}T0*ZWT(ZW1*C,T0*a1){T0*R=Zo;T2 _i=0;T0*_fn=Zo;T0*ZTW=Zo;T0*_rc=Zo;T0*_rf=Zo;if((((C)->Zkd))!=((void*)(Zo))){_rc=Z8G(a1);
_i=ZSJ((Zx8*)(((C)->Zkd)));while(!((T6)(((_rf)!=((void*)(Zo)))||((T6)((Z3)((_i)<=(Zrs(0)))))))){_fn=ZRJ((Zx8*)(((C)->Zkd)),_i);if((((((ZB8*)_fn))->Zre))==((void*)(ZNQ))){
_rf=ZaL(((Ze4*)_rc),_fn);ZTW=_fn;}_i=(Z3)(((_i))-(Zrs(1)));}if((T6)(((_rf)==((void*)(Zo)))&&((T6)(Z5T(a1))))){_i=ZSJ((Zx8*)(((C)->Zkd)));
while(!((T6)(((_rf)!=((void*)(Zo)))||((T6)((Z3)((_i)<=(Zrs(0)))))))){_fn=ZRJ((Zx8*)(((C)->Zkd)),_i);_rf=ZaL(((Ze4*)_rc),_fn);ZTW=_fn;
if((_rf)!=((void*)(Zo))){if((ZcL(_rf))!=((void*)(Zo))){_rf=Zo;}}_i=(Z3)(((_i))-(Zrs(1)));}}if((_rf)!=((void*)(Zo))){R=_rf;if(Zo!=(R)){
switch(((T0*)R)->id){case 435:break;default:R=Zo;}}if((R)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZCF(_rf),&Z3w)));}ZzF(((((ZB8*)ZTW))->Zxb));
{T0*b1=ZUW;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}}return R;}T6 Z_T(ZW1*C,T0*a1){T6 R=0;if((((C)->Zkd))!=((void*)(Zo))){R=((T6)(ZVW((Zx8*)(((C)->Zkd)),a1)));
}return R;}T0*ZYT(ZW1*C,T0*a1){T0*R=Zo;if((((C)->Zkd))!=((void*)(Zo))){R=ZWW((Zx8*)(((C)->Zkd)),a1);}return R;}void ZXW(Z12*C){ZYW(C);
ZTF((((ZB8*)(((C)->ZZb)))->Zxb),((C)->ZAb),((C)->Z_b));}T0*ZZW(T0*a1,T0*a2,T0*a3){T0*R=Zo;T0*ZVF=Zo;T0*ZWF=Zo;R=a1;if(ZXF(a2)){if(ZXF(a3)){
ZWF=ZDF(a3);ZVF=ZDF(a2);if((ZWF)!=((void*)(ZVF))){if(ZYF(a2,a3)){R=ZZF(a1,a3);}else{((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));
}}}}return R;}T6 Z_W(Z12*C,T0*a1){T6 R=0;T0*_tr=Zo;if((((C)->ZAb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(Z3G((Zm3*)(((C)->ZAb)),a1)));
}if(R){if((((C)->Z_b))==((void*)(Zo))){}else if(Z4G(((C)->ZYb))){if(Z5G(((C)->Z_b),a1)){R=((T6)((Z6G(((C)->Z_b),a1))!=((void*)(Zo))));
}else{R=((T6)(0));}}else{R=((T6)(Z7G(((C)->ZYb),a1)));if(R){if((((C)->Z_b))!=((void*)(Zo))){_tr=(((Ze4*)(Z8G((((ZS7*)(((C)->Z_b)))->Z0c))))->Zof);
if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)_tr))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){R=((T6)(Z5G(((C)->Z_b),_tr)));}}}}}return R;}T0*Z0X(Z12*C,T0*a1){
T0*R=Zo;R=ZaG((Zm3*)(((C)->ZAb)),a1);if((R)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZbG((Zm3*)(((C)->ZAb))),&Z3w)));}{T0*b1=ZcG;ZXw((T7*)(ZwF),b1);
}ZdG(a1);ZEF((T75*)(ZyF));}return R;}void Z1X(Z12*C,T0*a1,T0*a2,T0*a3){(C->ZYb)=a1;(C->ZZb)=a2;(C->ZAb)=a3;}T0*Z2X(Z12*C){T0*R=Zo;if((((T41*)(Z1G))->ZJk)){
R=((T0*)(C));}else{R=Z3X(C);if((R)!=((void*)(C))){ZhG((T41*)(Z1G));}}return R;}T0*Z4X(Z12*C){T0*R=Zo;(C->ZYb)=ZjG(((C)->ZYb));ZkG((Zm3*)(((C)->ZAb)));
R=Z3X(C);return R;}void Z5X(Z12*C){T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){if((((C)->ZAb))!=((void*)(Zo))){Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);
if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>=(Zrs(1)))){{T76 Z3w;ZmG((T41*)(Z1G),(*(Z3w=Z6X(C),&Z3w)),((C)->Z_b),Zof);
}}}}ZoG(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){ZpG((Zm3*)(((C)->ZAb)));}}void ZYW(Z12*C){if((ZqG(((C)->Z_b)))==((void*)(Zo))){{T76
Z3w;ZzF((*(Z3w=ZCF(((C)->Z_b)),&Z3w)));}ZzF((((ZB8*)(((C)->ZZb)))->Zxb));Z7X(ZvF(29,"Feature found is a procedure."));}}T6 Z8X(Z12*C,T0*a1){
T6 R=0;R=((T6)(Z_W(C,a1)));if(R){R=((T6)(!(ZuG(ZvG(Z9X(C))))));}return R;}void ZaX(Z12*C,T0*a1,T0*a2){ZyG(((C)->ZYb),a1,a2);ZzG((Zm3*)(((C)->ZAb)),a1,a2);
}void ZbX(Z12*C){{T76 Z3w;ZzF((*(Z3w=Z6X(C),&Z3w)));}{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZcX(Z12*C,T0*a1,T76 a2,T0*a3){(C->ZYb)=a1;{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZCG(n,(ZUP),a2);
(C->ZZb)=((T0*)n);}{Zm3*n=((Zm3*)Zh(sizeof(*n)));*n=Z1j;((((Zm3*)(n)))->Z0j)=(a3);(C->ZAb)=((T0*)n);}}void ZdX(Z12*C,T0*a1){T0*_t=Zo;
_t=ZFG(((C)->ZYb),a1);if((_t)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->ZYb)),&Z3w)));}{T0*b1=ZvF(11,"Bad target.");ZXw((T7*)(ZwF),b1);
}ZdG(a1);ZEF((T75*)(ZyF));}(C->ZYb)=_t;}void Z7X(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZeX(Z12*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);
}{T76 Z3w;ZzF((*(Z3w=Z6X(C),&Z3w)));}ZxF((T75*)(ZyF));}T2 ZfX(void){T2 R=0;return R;}void ZgX(Z12*C,T3 a1){if((a1)==(((T3)'R'))){{T76
Z3w;ZLG(((C)->Z_b),(*(Z3w=Z6X(C),&Z3w)));}}ZMG(((C)->ZYb),a1);ZMG(((((Zm3*)(((C)->ZAb))))->Z0j),a1);}T0*Z9X(Z12*C){T0*R=Zo;T0*ZNG=Zo;
R=ZqG(((C)->Z_b));ZNG=R;if(Zo!=(ZNG)){switch(((T0*)ZNG)->id){case 267:break;default:ZNG=Zo;}}if((ZNG)!=((void*)(Zo))){R=ZvG(ZOG(((((Zm3*)(((C)->ZAb))))->Z0j)));
}return R;}void ZhX(Z12*C){T0*ZQG=Zo;T0*_rc=Zo;T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){ZQG=ZOG(((C)->ZYb));_rc=Z8G(ZQG);Zof=((((Ze4*)_rc))->Zof);
if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){ZRG(((C)->ZYb),((C)->Z_b));}}ZSG(((C)->ZYb));ZTG((Zm3*)(((C)->ZAb)));
}T6 ZiX(Z12*C){T6 R=0;R=((T6)(ZVG((Zm3*)(((C)->ZAb)))));if(R){}else if(Z4G(((C)->ZYb))){if((ZWG())!=((void*)(((C)->Z_b)))){R=((T6)(ZXG(((C)->Z_b))));
}}else{R=((T6)(ZYG(((C)->ZYb))));}return R;}T6 ZjX(Z12*C){T6 R=0;if(Z_G(((C)->ZYb))){if((((C)->ZAb))!=((void*)(Zo))){R=((T6)(Z0H((Zm3*)(((C)->ZAb)))));
}else{R=((T6)(1));}}return R;}T6 ZkX(Z12*C,T0*a1){T6 R=0;R=((T6)(Z2H(ZOG(((C)->ZYb)))));R=((T6)((T6)((Z3H(((C)->ZYb),a1))||((T6)(R)))));
if((a1)!=((void*)(Zo))){if(Z4H(((ZH6*)a1),((C)->ZYb))){R=((T6)(1));}}else if((T6)((Z2H(ZOG(((C)->ZYb))))&&((T6)(!(Z4G(((C)->ZYb))))))){
Z5H(((C)->ZYb));}return R;}void ZlX(Z12*C,T0*a1){T6 Z7H=0;T0*Z8H=Zo;Z7H=((T6)(Z9H((Zi4*)(ZsG),a1)));Z8H=ZvG(Z9X(C));if(ZaH(Z8H)){if(ZaH(a1)){
ZbH(a1);ZcH((Zi4*)(ZsG),((T3)'\050'));{Z12*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}ZcH((Zi4*)(ZsG),((T3)'\051'));}else{{Z12*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);
}}}else{if(ZaH(a1)){{Z12*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}else{if(ZeH(a1)){ZcH((Zi4*)(ZsG),((T3)'\046'));ZcH((Zi4*)(ZsG),((T3)'\050'));
{Z12*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}ZcH((Zi4*)(ZsG),((T3)'\051'));}else{{Z12*C1=C;ZdH((Zi4*)(ZsG),(T0*)C1);}}}}if(Z7H){ZfH((Zi4*)(ZsG));
}}void ZmX(Z12*C,T0*a1){T0*_rf=Zo;T0*_rc=Zo;T0*_rt=Zo;T0*_bc=Zo;_rt=ZOG(((C)->ZYb));if((_rt)!=((void*)(Zo))){_rc=Z8G(_rt);if((_rc)!=((void*)(Zo))){
_bc=((((Ze4*)_rc))->Zqb);_rf=ZhH(((T82*)_bc),_rc,((C)->ZYb),((C)->ZZb),a1);}}if((_rf)==((void*)(Zo))){ZzF((((ZB8*)(((C)->ZZb)))->Zxb));
{T0*b1=ZvF(25,"Bad target for this call.");ZXw((T7*)(ZwF),b1);}ZdG(a1);ZEF((T75*)(ZyF));}(C->Z_b)=_rf;}T2 ZnX(Z12*C){T2 R=0;ZeX(C);return
R;}T0*ZoX(Z12*C,T0*a1){T0*R=Zo;T0*ZkH=Zo;T0*ZlH=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;ZdX(C,a1);(C->ZAb)=Z0X(C,a1);ZlH=ZOG(((C)->ZYb));
ZkH=ZOG(((((Zm3*)(((C)->ZAb))))->Z0j));(C->ZYb)=ZZW(((C)->ZYb),ZlH,ZkH);ZmX(C,a1);R=Z2X(C);ZXW(C);}else{{Z12*n=((Z12*)Zh(sizeof(*n)));
*n=Zod;Z1X(n,((C)->ZYb),((C)->ZZb),((C)->ZAb));R=((T0*)n);}R=ZFG(R,a1);}return R;}T0*Z3X(Z12*C){T0*R=Zo;T0*ZmH=Zo;ZmH=((C)->ZYb);if(Zo!=(ZmH)){
switch(((T0*)ZmH)->id){case 305:case 306:break;default:ZmH=Zo;}}if((ZmH)==((void*)(Zo))){R=((T0*)(C));}else if(ZoH(ZmH)){R=((((Zm3*)(((C)->ZAb))))->Z0j);
}else{{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zel;ZqH(n,(((ZB8*)(((C)->ZZb)))->Zxb));R=((T0*)n);}}return R;}T0*ZpX(Z12*C){T0*R=Zo;T0*_bc=Zo;
T0*ZsH=Zo;T0*_rt=Zo;_bc=ZtH(((C)->ZYb));if((_bc)!=((void*)(Zo))){ZsH=ZuH(((T82*)_bc),((C)->ZZb));if((ZsH)!=((void*)(Zo))){_rt=ZvH(ZsH);
if((_rt)!=((void*)(Zo))){R=ZwH(_rt);}}}return R;}void ZqX(Z12*C){if((((C)->Z_b))!=((void*)(Zo))){ZyH(((C)->Z_b));}ZzH(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){
ZAH((Zm3*)(((C)->ZAb)));}}void ZrX(Z12*C){T0*_rc=Zo;T0*_rf=Zo;_rf=((C)->Z_b);_rc=((((ZS7*)_rf))->Znf);(C->Z_b)=ZCH((Ze4*)((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZPb))[Zrs(0)]),_rf);
}T76 Z6X(Z12*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((C)->ZZb)))->Zxb);return R;}void ZsX(Zb2*C){if((((C)->ZAb))!=((void*)(Zo))){ZpG((Zm3*)(((C)->ZAb)));
}}void ZtX(Zb2*C){ZuX((Zi4*)(ZsG),((C)->Z_b),((C)->ZAb));ZvX(((C)->Z_b));ZwX((Zi4*)(ZsG));}T6 ZxX(T0*a1){T6 R=0;return R;}void ZyX(Zb2*C,T0*a1,T0*a2){
if((((C)->ZAb))!=((void*)(Zo))){ZzG((Zm3*)(((C)->ZAb)),a1,a2);}}void ZzX(Zb2*C){ZzF(((C)->Zxb));{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZAX(Zb2*C,T76 a1,T0*a2,T0*a3){(C->Zxb)=a1;(C->Zud)=a2;(C->ZAb)=a3;}void ZBX(T0*a1){{T0*b1=a1;
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZCX(Zb2*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}ZzF(((C)->Zxb));ZxF((T75*)(ZyF));}T0*ZDX(Zb2*C){
T0*R=Zo;R=ZqG(((C)->Z_b));return R;}T0*ZEX(Zb2*C,T0*a1){T0*R=Zo;T0*ZsH=Zo;T0*ZFX=Zo;T0*_pl=Zo;ZsH=ZyV(a1);ZFX=((((Z85*)ZsH))->Zqb);_pl=((((T82*)ZFX))->Zmg);
if((_pl)==((void*)(Zo))){ZzF(((C)->Zxb));ZBX(ZvF(71,"Precursor call is allowed only when the enclosing routine is redefined."));}else{
R=ZGX(((Z3a*)_pl),(T0*)C,a1);}return R;}void ZHX(Zb2*C){if((((C)->ZAb))!=((void*)(Zo))){ZTG((Zm3*)(((C)->ZAb)));}}void ZIX(Zb2*C,T0*a1){
T0*_a=Zo;if((((C)->ZAb))!=((void*)(Zo))){_a=ZaG((Zm3*)(((C)->ZAb)),a1);if((_a)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZbG((Zm3*)(((C)->ZAb))),&Z3w)));
}{T0*b1=ZJX;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else{(C->ZAb)=_a;}}ZTF(((C)->Zxb),((C)->ZAb),((C)->Z_b));}T0*ZKX(T0*a1,T0*a2){T0*R=Zo;
{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;ZLX(n,(T2)((((T82*)(((((Z85*)a2))->Zqb)))->_id)),a1);R=((T0*)n);}return R;}T6 ZMX(T0*a1){T6 R=0;
return R;}T2 ZNX(Zb2*C){T2 R=0;ZCX(C);return R;}T0*ZOX(Zb2*C,T0*a1){T0*R=Zo;T0*ZPX=Zo;T0*ZQX=Zo;T0*_pn=Zo;if((((C)->Z0c))==((void*)(Zo))){
(C->Z0c)=a1;R=((T0*)(C));ZPX=ZWG();if((ZqG(ZPX))==((void*)(Zo))){ZzF(((C)->Zxb));ZBX(ZvF(84,"Inside a procedure, a Precursor call must be a procedure call (not a function call)."));
}ZQX=ZEX(C,ZPX);_pn=ZKX(((((ZS7*)ZPX))->Zkc),ZQX);(C->Z_b)=Z8E(((Zj6*)((((Ze4*)(Z8G(a1)))->Zug))),_pn);if((((C)->Z_b))==((void*)(Zo))){
{Zm7*n=((Zm7*)Zh(sizeof(*n)));*n=ZRj;ZRX(n,a1,_pn,ZQX);(C->Z_b)=((T0*)n);}}ZIX(C,a1);}else{{Zb2*n=((Zb2*)Zh(sizeof(*n)));*n=Zvd;ZAX(n,((C)->Zxb),((C)->Zud),((C)->ZAb));
R=((T0*)n);}R=ZOX(((Zb2*)R),a1);}return R;}T0*ZSX(Zb2*C){T0*R=Zo;T0*ZsH=Zo;T0*_rt=Zo;if((((C)->Z_b))!=((void*)(Zo))){ZsH=ZyV(((C)->Z_b));
_rt=ZvH(ZsH);R=ZwH(_rt);}return R;}void ZTX(Zb2*C){if((((C)->Z_b))!=((void*)(Zo))){ZyH(((C)->Z_b));}if((((C)->ZAb))!=((void*)(Zo))){ZAH((Zm3*)(((C)->ZAb)));
}}void ZUX(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));}T6 ZVX(Zj2*C,T0*a1){T6 R=0;T0*ZWX=Zo;T0*ZTW=Zo;T0*ZXX=Zo;
R=((T6)((T6)((Z7V(a1))&&((T6)((ZvG(a1))==((void*)(a1)))))));if((T6)((R)&&((T6)((((C)->Z_b))!=((void*)(Zo)))))){ZWX=(((ZS7*)(((C)->Z_b)))->Z0c);
ZXX=(((T80*)((((T82*)(ZbK(ZWX)))->Zkc)))->Zre);ZTW=(((ZB8*)((((ZS7*)(((C)->Z_b)))->Zkc)))->Zre);if((ZkR)==((void*)(ZTW))){R=((T6)((T6)(((T6)(((T6)(((T6)(((T6)(((ZfP)==((void*)(ZXX)))||((T6)((ZqP)==((void*)(ZXX))))))||((T6)((ZNP)==((void*)(ZXX))))))||((T6)((ZmP)==((void*)(ZXX))))))||((T6)((ZOP)==((void*)(ZXX))))))||((T6)((ZPP)==((void*)(ZXX)))))));
}else if((ZwQ)==((void*)(ZTW))){R=((T6)((ZNP)==((void*)(ZXX))));}else if((ZaS)==((void*)(ZTW))){R=((T6)((T6)(((T6)(((ZfP)==((void*)(ZXX)))||((T6)((ZqP)==((void*)(ZXX))))))||((T6)((ZmP)==((void*)(ZXX)))))));
}else{R=((T6)(0));}}return R;}void ZYX(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T0*ZZX(Zj2*C){T0*R=Zo;if((((C)->Zyd))!=((void*)(Zo))){
R=ZVM(((C)->Zyd));}return R;}T0*Z_X(Zj2*C){T0*R=Zo;if((((T41*)(Z1G))->ZJk)){R=((T0*)(C));}else{R=Z0Y(C);if((R)!=((void*)(C))){ZhG((T41*)(Z1G));
}}return R;}T0*Z1Y(Zj2*C){T0*R=Zo;if(ZXF(((C)->ZBb))){R=Z2Y(((C)->ZBb),((C)->Zxb));}else{R=((T0*)(C));}return R;}void Z3Y(Zj2*C){T0*ZaM=Zo;
ZaM=ZZX(C);if((ZaM)!=((void*)(Zo))){ZpG(((Zm3*)ZaM));}}T2 Z4Y(Zj2*C){T2 R=0;if((((C)->Zyd))!=((void*)(Zo))){R=Z5Y(((C)->Zyd));}return
R;}void Z6Y(Zj2*C){if(ZaH(((C)->ZBb))){Z7I((Zi4*)(ZsG),Z7Y);}Z8Y(C,((C)->ZBb));if(ZaH(((C)->ZBb))){ZcH((Zi4*)(ZsG),((T3)'\051'));}}void
Z9Y(Zj2*C){ZzF(((C)->Zxb));{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));
}void ZaY(Zj2*C,T76 a1,T0*a2,T0*a3){(C->Zxb)=a1;(C->ZBb)=a2;(C->Zyd)=a3;}void ZbY(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));
}void ZcY(Zj2*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}ZzF(((C)->Zxb));ZxF((T75*)(ZyF));}void ZdY(Zj2*C,T3 a1){if((((C)->Z_b))!=((void*)(Zo))){
if((a1)==(((T3)'R'))){ZLG(((C)->Z_b),((C)->Zxb));}}}void ZeY(Zj2*C){T0*ZaM=Zo;ZaM=ZZX(C);if((ZaM)!=((void*)(Zo))){ZTG(((Zm3*)ZaM));}}
T6 ZfY(Zj2*C){T6 R=0;T0*ZaM=Zo;ZaM=ZZX(C);if((ZaM)!=((void*)(Zo))){R=((T6)(ZVG(((Zm3*)ZaM))));}return R;}T6 ZgY(Zj2*C){T6 R=0;T0*ZTc=Zo;
ZTc=Z_X(C);if((ZTc)!=((void*)(C))){R=((T6)(Z_G(ZTc)));}else if((T6)(((ZZX(C))==((void*)(Zo)))||((T6)(Z0H((Zm3*)(ZZX(C))))))){R=((T6)(ZVX(C,((C)->ZBb))));
}return R;}void ZhY(Zj2*C,T0*a1){T0*_rt=Zo;T0*ZmH=Zo;T0*ZnH=Zo;_rt=ZvG(a1);if((((T41*)(Z1G))->ZJk)){}else if((((T82*)(ZbK(_rt)))->Zfg)){
ZsS(_rt,ZvF(14," is deferred. "));ZUX(((C)->Zxb),ZvF(21,"Cannot create object."));}if(ZiY(a1)){ZmH=((((C)->Zxb)).Zqb);ZnH=ZrS((T80*)(ZjY(a1)));
if((ZmH)==((void*)(ZnH))){ZzF(((C)->Zxb));{T0*b1=ZvF(38,"Creation call on formal generic type (");ZXw((T7*)(ZwF),b1);}ZsS(a1,ZvF(2,ZCn));
ZEF((T75*)(ZyF));}}if(Z2H(a1)){((((T41*)((T41*)(Z1G))))->ZPk)=(1);}ZeL((Ze4*)(Z8G(_rt)));}T6 ZkY(T0*a1){T6 R=0;return R;}void Z8Y(Zj2*C,T0*a1){
T0*_rc=Zo;T6 ZlY=0;T0*ZaM=Zo;ZlY=((T6)(((((T84*)(ZFI))->Zcf))==(Zrs(1))));_rc=Z8G(((C)->ZBb));Z7I((Zi4*)(ZsG),ZmY);ZtI((Zi4*)(ZsG),(T11)(((((Ze4*)_rc))->_id)));
if((((C)->Z_b))!=((void*)(Zo))){Z7I((Zi4*)(ZsG),(((ZB8*)((((ZS7*)(((C)->Z_b)))->Zkc)))->Zre));}ZcH((Zi4*)(ZsG),((T3)'\050'));if(!(ZlY)){
Z7I((Zi4*)(ZsG),ZnY);}ZaM=ZZX(C);if((ZaM)!=((void*)(Zo))){if(!(ZlY)){ZcH((Zi4*)(ZsG),((T3)'\054'));}ZoY(((Zm3*)ZaM),ZcL(((C)->Z_b)));
}ZcH((Zi4*)(ZsG),((T3)'\051'));}void ZpY(Zj2*C,T0*a1){T0*_fn=Zo;T0*ZqY=Zo;T0*ZAf=Zo;T0*ZaM=Zo;T2 ZrY=0;T0*_w=Zo;T0*_rc=Zo;T0*_bf=Zo;_rc=Z8G(a1);
if((((C)->Zyd))==((void*)(Zo))){(C->Z_b)=ZsY(((Ze4*)_rc));if((((C)->Z_b))!=((void*)(Zo))){}else if(((((T82*)(ZbK(a1)))->Zng))!=(Zo)){
{T0*b1=ZvF(27,"Creation clause exists for ");ZXw((T7*)(ZwF),b1);}ZsS(a1,ZvF(2,ZHn));ZYX(((C)->Zxb),ZvF(27,"You must use a constructor."));
}}else{_fn=(((ZZ6*)(((C)->Zyd)))->ZZb);ZAf=((((((ZB8*)_fn))->Zxb)).Zqb);ZqY=ZbK(a1);if(ZtY(a1)){_fn=ZuY(((T82*)ZqY),ZAf,_fn);if((_fn)==((void*)(Zo))){
_fn=(((ZZ6*)(((C)->Zyd)))->ZZb);ZvY(_fn);{T0*b1=ZvF(20," Type to create is \"");ZXw((T7*)(ZwF),b1);}{T0*b1=ZDF(a1);ZXw((T7*)(ZwF),b1);
}ZbY(ZwY);}}(C->Z_b)=ZaL(((Ze4*)_rc),_fn);if((((C)->Z_b))==((void*)(Zo))){ZxY(C,_fn);}else{_bf=ZyV(((C)->Z_b));ZyY(ZyV(((C)->Z_b)),((((ZB8*)_fn))->Zxb));
}if((((T41*)(Z1G))->ZJk)){}else if(!(ZzY((T82*)(((((Ze4*)_rc))->Zqb)),_fn))){ZzF((((ZB8*)((((ZZ6*)(((C)->Zyd)))->ZZb)))->Zxb));ZzF(((((ZB8*)_fn))->Zxb));
{T0*b1=((((ZB8*)_fn))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(32," is not in the creation list of ");ZXw((T7*)(ZwF),b1);}ZsS(a1,ZMJ);ZEF((T75*)(ZyF));
}ZAY((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)),Z8G(((C)->Z0c)));if((ZqG(((C)->Z_b)))!=((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZCF(((C)->Z_b)),&Z3w)));
}ZzF(((((ZB8*)_fn))->Zxb));ZbY(ZUW);}ZrY=Z4Y(C);if((Z3)((ZrY)>(Zrs(0)))){ZaM=ZaG((Zm3*)(ZZX(C)),((C)->Z0c));if((ZaM)==((void*)(Zo))){
{T76 Z3w;ZYX((*(Z3w=ZbG((Zm3*)(ZVM(((C)->Zyd)))),&Z3w)),ZJX);}}}{T76 Z3w;ZTF((*(Z3w=ZBY(((C)->Zyd)),&Z3w)),ZaM,((C)->Z_b));}_w=((C)->Zxd);
if((_w)==((void*)(Zo))){_w=(((ZZ6*)(((C)->Zyd)))->ZYb);}(C->Zyd)=ZCY(((C)->Zyd),((C)->Z0c),_w,ZaM,((C)->Z_b));}}T2 ZDY(Zj2*C){T2 R=0;
ZcY(C);return R;}T0*ZEY(Zj2*C,T0*a1){T0*R=Zo;T0*_rc=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;ZFY(C);ZhY(C,((C)->ZBb));ZpY(C,((C)->ZBb));
R=Z_X(C);_rc=Z8G(((C)->ZBb));if(!(ZXF(((((Ze4*)_rc))->Z0c)))){ZGY(((Ze4*)_rc),((C)->Z_b));}}else{{Zj2*n=((Zj2*)Zh(sizeof(*n)));*n=Zzd;
ZaY(n,((C)->Zxb),((C)->ZBb),((C)->Zyd));R=((T0*)n);}R=ZFG(R,a1);}return R;}T0*Z0Y(Zj2*C){T0*R=Zo;if(ZXF(((C)->ZBb))){R=Z2Y(((C)->ZBb),((C)->Zxb));
}else{R=((T0*)(C));}return R;}T0*ZHY(Zj2*C){T0*R=Zo;R=ZbK(((C)->ZBb));return R;}void ZIY(Zj2*C){if((ZZX(C))!=((void*)(Zo))){ZAH((Zm3*)(ZZX(C)));
}}void ZxY(Zj2*C,T0*a1){ZzF((((ZB8*)((((ZZ6*)(((C)->Zyd)))->ZZb)))->Zxb));ZzF(((((ZB8*)a1))->Zxb));ZbY(ZvF(29,"Creation procedure not found."));
}void ZFY(Zj2*C){T0*_t=Zo;T0*ZAl=Zo;_t=Z9L(((C)->ZBb),((C)->Z0c));if((T6)(((_t)==((void*)(Zo)))||((T6)(!(Z7V(_t)))))){{T76 Z3w;ZzF((*(Z3w=Z3L(((C)->ZBb)),&Z3w)));
}ZbY(ZvF(22,"Invalid explicit type."));}else{(C->ZBb)=_t;}if((((C)->Zxd))!=((void*)(Zo))){ZAl=ZOG(((C)->Zxd));if(!(ZYF(((C)->ZBb),ZAl))){
ZbY(ZvF(24," Bad explicit type mark."));}if((ZDF(((C)->ZBb)))!=((void*)(ZDF(ZAl)))){{T76 Z3w;ZJY((*(Z3w=Z3L(((C)->ZBb)),&Z3w)),((C)->ZBb),ZAl);
}}}}T0*ZKY=Zo;T0*ZLY=Zo;T0*ZMY=Zo;int ZNY=0;T0*ZOY(void){if(ZNY==0){ZNY=1;{{T48*n=((T48*)Zh(sizeof(*n)));*n=M48;ZMY=((T0*)n);ZPY(n);}
}}return ZMY;}T10 ZQY(T40*C,T0*a1){T10 R=0;T76 _p={Zo,Zo,0};if(ZHC((T45*)(ZLY),a1)){R=ZBC((T45*)(ZLY),a1);}else if((((C)->ZFd))==(Zft(32764))){
{T0*b1=ZRY;ZXw((T7*)(ZwF),b1);}{T2 b1=(T2)(Zft(32764));ZQs(b1,ZwF);}{T0*b1=ZSY;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else{(C->ZFd)=(Z2)(((((C)->ZFd)))+(Zrs(1)));
R=((C)->ZFd);ZIC((T45*)(ZLY),R,a1);}return R;}void ZTY(T40*C){ZCC((T45*)(ZLY),(T10)(Zrs(0)),ZBP);ZCC((T45*)(ZLY),(T10)(Zrs(1)),ZtP);ZCC((T45*)(ZLY),(T10)(Zrs(2)),ZwP);
ZCC((T45*)(ZLY),(T10)(Zrs(2)),ZvP);ZCC((T45*)(ZLY),(T10)(Zrs(3)),ZkP);ZCC((T45*)(ZLY),(T10)(Zrs(4)),ZJP);ZCC((T45*)(ZLY),(T10)(Zrs(5)),ZnP);
ZCC((T45*)(ZLY),(T10)(Zrs(6)),ZiP);ZCC((T45*)(ZLY),(T10)(Zrs(7)),ZNP);ZCC((T45*)(ZLY),(T10)(Zrs(8)),ZDP);ZCC((T45*)(ZLY),(T10)(Zrs(9)),ZdS);
ZCC((T45*)(ZLY),(T10)(Zrs(10)),ZuP);ZCC((T45*)(ZLY),(T10)(Zrs(11)),ZxP);(C->ZFd)=Zrs(11);if(!((((T41*)(Z1G))->ZLk))){ZUY(C);}}void ZUY(T40*C){
T3 _cc=0;T0*ZVY=Zo;T10 _id=0;T10 ZWY=0;T0*ZXY=Zo;T1 ZIi=0;T2 ZYY=0;ZYY=(T2)(((C)->ZFd));{T42*n=((T42*)Zh(sizeof(*n)));*n=M42;ZXY=((T0*)n);
}ZZY((T36*)(Z_Y()),ZXY,Z0Z((T48*)(ZOY())));if((((((T42*)ZXY))->Zoc))!=(Zo)){if(((((T42*)ZXY))->ZPh)){ZIi=Zrs(6);}while(!((Z1)((ZIi)>(Zrs(4)))))
{Z1Z(((T42*)ZXY));if(((((T42*)ZXY))->ZPh)){ZIi=Zrs(5);}else{_cc=((((T42*)ZXY))->ZOh);}{int z1=ZIi;switch(z1){case 0:{int z2=_cc;switch(z2){
case 9:case 10:case 13:case 32:break;case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:_id=(T10)(Zus(_cc));
ZIi=Zrs(1);break;default:;ZIi=Zrs(6);}}break;case 1:{int z2=_cc;switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case
55:case 56:case 57:_id=(Z2)((((Z2)(((_id))*(Zrs(10)))))+((T10)(Zus(_cc))));break;case 34:ZVY=ZKY;((((T7*)(((T7*)ZVY))))->Zcc)=(Zrs(0));
ZIi=Zrs(3);break;case 9:case 32:ZIi=Zrs(2);break;default:;ZIi=Zrs(6);}}break;case 2:{int z2=_cc;switch(z2){case 34:ZVY=ZKY;((((T7*)(((T7*)ZVY))))->Zcc)=(Zrs(0));
ZIi=Zrs(3);break;case 9:case 10:case 13:case 32:break;default:;ZIi=Zrs(6);}}break;case 3:{int z2=_cc;switch(z2){case 34:ZWY=(Z2)(((ZWY))+(Zrs(1)));
if((Z3)(((T2)(_id))>(ZYY))){ZVY=(((void)((T26*)(Z2Z()))),ZAS(ZVY));ZCC((T45*)(ZLY),_id,ZVY);(C->ZFd)=Zkt(((C)->ZFd),_id);}ZIi=Zrs(4);
break;case 9:case 10:case 13:ZIi=Zrs(6);break;default:;ZZs(((T7*)ZVY),_cc);}}break;case 4:{int z2=_cc;switch(z2){case 35:ZIi=Zrs(0);break;
}}break;}}}Z3Z(((T42*)ZXY));if((ZIi)==(Zrs(6))){Z7L((T36*)(Z_Y()),ZvF(27,"Corrupted *.id file (after "));ZsL((T36*)(Z_Y()),(T2)(ZWY));
Z7L((T36*)(Z_Y()),ZvF(17," correct items).\n"));}Z7L((T36*)(Z_Y()),Z4Z);ZsL((T36*)(Z_Y()),(T2)(((C)->ZFd)));Z7L((T36*)(Z_Y()),Z5Z);}}
T0*Z_Y(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));*n=M36;ZQK=((T0*)n);}}}return ZQK;}T0*Z2Z(void){if(ZbP==0){ZbP=1;{{T26*n=((T26*)Zh(1));
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
ZdP(ZgS);ZdP(ZhS);ZdP(ZiS);ZdP(ZjS);ZdP(ZkS);ZdP(ZlS);ZdP(ZmS);ZdP(ZnS);ZdP(ZoS);}}}return ZaP;}T0*Z6Z(T10 a1){T0*R=Zo;R=ZFC((T45*)(ZLY),a1);
return R;}void Z7Z(Zr2*C,T0*a1){Z8Z(((C)->ZNc),a1);}void Z9Z(Zr2*C,T0*a1){if(ZaZ(C)){ZXw(((T7*)a1),Z9N);ZZs(((T7*)a1),((T3)'\052'));}
else{ZbZ(C,a1);}}T0*ZcZ(Zr2*C){T0*R=Zo;if(ZdZ(C)){R=ZbN(((C)->ZNc));}else{ZeZ(C);}return R;}T6 ZfZ(Zr2*C){T6 R=0;R=((T6)(ZeN(((C)->ZNc))));
return R;}T0*ZgZ(Zr2*C){T0*R=Zo;if((((C)->ZNc))!=((void*)(Zo))){R=ZDF(((C)->ZNc));}return R;}T6 ZhZ(Zr2*C){T6 R=0;R=((T6)(ZgN(((C)->ZNc))));
return R;}T2 ZiZ(Zr2*C){T2 R=0;R=ZjZ(((C)->ZNc));return R;}void ZbZ(Zr2*C,T0*a1){ZXU(((C)->ZNc),a1);}T6 ZkZ(void){T6 R=0;return R;}T6
ZlZ(Zr2*C){T6 R=0;T0*ZCO=Zo;ZCO=Zo;R=((T6)((ZCO)!=((void*)(Zo))));return R;}void ZmZ(Zr2*C,T0*a1){ZXw(((T7*)a1),ZDO);ZQs(ZnZ(C),a1);}
T6 ZoZ(Zr2*C){T6 R=0;T0*_rt=Zo;if((((C)->ZNc))!=(Zo)){_rt=((C)->ZNc);if((C)==((void*)(_rt))){if((ZvG(_rt))==((void*)(_rt))){R=((T6)((ZFO(_rt))==((void*)(ZDF(_rt)))));
}}}return R;}void ZpZ(Zr2*C,T0*a1){ZqZ(((C)->ZNc),a1);}void ZrZ(Zr2*C,T0*a1,T0*a2){(C->Zxb)=((((Zr2*)a1))->Zxb);(C->ZNc)=a2;}T6 ZsZ(Zr2*C){
T6 R=0;R=((T6)(ZHO(((C)->ZNc))));return R;}T2 ZnZ(Zr2*C){T2 R=0;R=(((Ze4*)(ZtZ(C)))->_id);return R;}void ZuZ(Zr2*C){((((T7*)((T7*)(ZJO))))->Zcc)=(Zrs(0));
ZZs((T7*)(ZJO),((T3)'\050'));ZvZ(C,ZJO);ZZs((T7*)(ZJO),((T3)'\051'));Z7I((Zi4*)(ZsG),ZJO);}T6 ZwZ(Zr2*C){T6 R=0;R=((T6)(ZTO(((C)->ZNc))));
return R;}T6 ZxZ(Zr2*C){T6 R=0;R=((T6)(ZVO(((C)->ZNc))));return R;}void ZyZ(Zr2*C){ZzZ(((C)->ZNc));}T6 ZAZ(Zr2*C){T6 R=0;R=((T6)(ZBZ(((C)->ZNc))));
return R;}T0*ZCZ(Zr2*C){T0*R=Zo;R=Z0T(&(((C)->Zxb)));return R;}void ZeZ(Zr2*C){ZsS((T0*)C,ZvF(19," is (not) generic \?"));ZEF((T75*)(ZyF));
}void ZDZ(Zr2*C,T0*a1){ZEZ(((C)->ZNc),a1);}T6 ZFZ(T0*a1){T6 R=0;return R;}T6 ZGZ(Zr2*C){T6 R=0;R=((T6)(Z1P(((C)->ZNc))));return R;}T0*ZHZ(Zr2*C){
T0*R=Zo;R=Z3P(((C)->ZNc));return R;}T6 ZIZ(Zr2*C){T6 R=0;R=((T6)(Z6P(((C)->ZNc))));return R;}T6 ZJZ(Zr2*C){T6 R=0;R=((T6)(Z5T(((C)->ZNc))));
return R;}T6 ZKZ(Zr2*C){T6 R=0;R=((T6)(Z9P(((C)->ZNc))));return R;}void ZLZ(Zr2*C,T0*a1){ZMZ(((C)->ZNc),a1);}T0*ZNZ(Zr2*C){T0*R=Zo;T0*ZqS=Zo;
if((((C)->ZIc))!=((void*)(Zo))){R=((C)->ZIc);}else{ZqS=ZHZ(C);if((ZqS)!=((void*)(Zo))){(C->ZIc)=ZrS(((T80*)ZqS));R=((C)->ZIc);}else{{T0*b1=ZvF(27,"Cannot find Base Class for ");
ZXw((T7*)(ZwF),b1);}ZsS((T0*)C,ZMJ);ZEF((T75*)(ZyF));}}return R;}T0*ZOZ(Zr2*C,T76 a1){T0*R=Zo;if(ZaZ(C)){{ZH4*n=((ZH4*)Zh(sizeof(*n)));
*n=Zyg;((((ZH4*)(n)))->Zxb)=(a1);R=((T0*)n);}}else if(ZGZ(C)){{Zs1*n=((Zs1*)Zh(sizeof(*n)));*n=ZIl;ZxJ(n,(T11)(Zrs(0)),a1);R=((T0*)n);
}}else if(ZPZ(C)){{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zel;ZqH(n,a1);R=((T0*)n);}}else if(ZIZ(C)){{ZN4*n=((ZN4*)Zh(sizeof(*n)));*n=ZOg;ZiW(n,a1,((T3)'\000'));
R=((T0*)n);}}else if((T6)((ZwZ(C))||((T6)(ZQZ(C))))){{Zy9*n=((Zy9*)Zh(sizeof(*n)));*n=Z4m;ZRZ(n,a1,(T5)(0.0),(T0*)C);R=((T0*)n);}}return
R;}T6 ZSZ(Zr2*C){T6 R=0;R=((T6)(ZjW(((C)->ZNc))));return R;}void ZTZ(Zr2*C,T0*a1){ZZs(((T7*)a1),((T3)'\045'));if(ZaZ(C)){ZZs(((T7*)a1),((T3)'R'));
}else{ZZs(((T7*)a1),((T3)'E'));}ZQs(ZnZ(C),a1);ZZs(((T7*)a1),((T3)'\045'));}T6 ZUZ(Zr2*C){T6 R=0;R=((T6)(ZeH(((C)->ZNc))));return R;}
T6 ZaZ(Zr2*C){T6 R=0;R=((T6)(ZaH(((C)->ZNc))));return R;}T6 ZVZ(Zr2*C){T6 R=0;T0*ZyS=Zo;ZyS=Zo;R=((T6)((ZyS)!=((void*)(Zo))));return R;
}void ZWZ(Zr2*C){ZXZ(((C)->ZNc));}void ZYZ(Zr2*C){ZZZ(((C)->ZNc));}void ZvZ(Zr2*C,T0*a1){ZNS(((C)->ZNc),a1);}T0*Z_Z(Zr2*C,T0*a1){T0*R=Zo;
R=Z0_(((C)->ZNc),a1);return R;}T6 ZdZ(Zr2*C){T6 R=0;R=((T6)(ZQS(((C)->ZNc))));return R;}T6 ZQZ(Zr2*C){T6 R=0;R=((T6)(ZSS(((C)->ZNc))));
return R;}void Z1_(Zr2*C,T0*a1){ZUS(a1,ZVS);if(ZaZ(C)){ZUS(a1,ZWS);}else{ZUS(a1,Z2_);}ZXS(a1,((T3)'\n'));}T6 Z3_(Zr2*C){T6 R=0;R=((T6)(Z4_(((C)->ZNc))));
return R;}T6 Z5_(Zr2*C,T0*a1){T6 R=0;R=((T6)(ZYF(((C)->ZNc),a1)));if(!(R)){ZzF(((C)->Zxb));}return R;}T0*Z6_(Zr2*C){T0*R=Zo;if(!(ZMF(&(((C)->Zxb))))){
R=Z0T(&(((C)->Zxb)));}return R;}T0*Z7_(Zr2*C){T0*R=Zo;R=ZKI(((C)->ZNc));return R;}T6 ZPZ(Zr2*C){T6 R=0;R=((T6)(Z2T(((C)->ZNc))));return
R;}T0*Z8_(Zr2*C,T0*a1){T0*R=Zo;if((((C)->ZNc))==((void*)(Zo))){(C->ZNc)=a1;R=((T0*)(C));}else if((((C)->ZNc))==((void*)(a1))){R=((T0*)(C));
}else{{Zr2*n=((Zr2*)Zh(sizeof(*n)));*n=ZId;ZrZ(n,(T0*)C,a1);R=((T0*)n);}}return R;}T0*Z9_(Zr2*C){T0*R=Zo;T0*Z9T=Zo;Z9T=ZCZ(C);if((Z9T)!=((void*)(Zo))){
R=ZrS(((T80*)Z9T));}return R;}T6 Za_(Zr2*C){T6 R=0;R=((T6)(ZbT(((C)->ZNc))));return R;}T0*ZtZ(Zr2*C){T0*R=Zo;if((((C)->ZJc))!=((void*)(Zo))){
R=((C)->ZJc);}else if((((C)->ZNc))!=(Zo)){(C->ZJc)=ZdT(((C)->ZNc));R=((C)->ZJc);}return R;}void Zb_(Zr2*C){Zc_(((C)->ZNc));}void Zd_(Zr2*C){
Ze_(((C)->ZNc));}void Zf_(Zr2*C){ZfT(((C)->ZNc));}void Zg_(Zr2*C){Zh_(((C)->ZNc));}T6 Zi_(Zr2*C){T6 R=0;R=((T6)(Z2H(((C)->ZNc))));return
R;}T6 Zj_(Zr2*C){T6 R=0;R=((T6)(ZXF(((C)->ZNc))));return R;}T0*Zk_(Zr2*C,T0*a1){T0*R=Zo;R=ZiT(((C)->ZNc),a1);return R;}void Zl_(Zr2*C,T0*a1){
ZXw(((T7*)a1),ZZN);ZQs(ZnZ(C),a1);ZZs(((T7*)a1),((T3)'\050'));ZZs(((T7*)a1),((T3)'\051'));}
#ifdef __cplusplus
}
#endif

