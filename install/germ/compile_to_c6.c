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
T0*ZBJ(ZW*C,T0*a1,T0*a2){T0*R=Zo;{T76 Z3w;ZzF((*(Z3w=ZCJ(C),&Z3w)));}ZDJ(((((ZB8*)a1))->Zxb),ZvF(42,"An attribute must not be undefined (VDUS)."));
ZEJ(((T82*)a2),a1);return R;}void ZDJ(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T6 ZFJ(ZW*C,T0*a1,T0*a2){
T6 R=0;if((((C)->Zgc))!=((void*)(ZvH(a1)))){if((T6)(((((C)->Zgc))==((void*)(Zo)))||((T6)((ZvH(a1))==((void*)(Zo)))))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));
}{T76 Z3w;ZDJ((*(Z3w=ZCJ(C),&Z3w)),ZHJ);}}}if((Zo)!=((void*)(ZIJ(a1)))){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;ZDJ((*(Z3w=ZCJ(C),&Z3w)),ZJJ);
}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){if((((C)->Zgc))!=((void*)(Zo))){if(!(ZKJ(ZvH(a1),((C)->Zgc),a2,(T6)(0)))){{T0*b1=ZLJ;ZXw((T7*)(ZwF),b1);
}{T0*b1=ZDF(((((Ze4*)a2))->Z0c));ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}}}if(((((T75*)(ZyF))->ZAg))==(Zrs(0))){
}R=((T6)(((((T75*)(ZyF))->ZAg))==(Zrs(0))));if(R){ZNJ(C,a1);}return R;}void ZNJ(ZW*C,T0*a1){if((((T41*)(Z1G))->ZJk)){if((((C)->ZCb))==((void*)(Zo))){
(C->ZCb)=ZOJ(a1);}else if((ZOJ(a1))==((void*)(Zo))){ZPJ(a1,((C)->ZCb));}}}void ZQJ(ZW*C,T0*a1){T2 _i=0;T0*_fn=Zo;T0*_f=Zo;(C->Zqb)=(((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),Zrs(1))))->Zxb)).Zqb);
_i=Zrs(1);while(!((Z3)((_i)>(ZSJ((Zx8*)(((C)->Zfc))))))){_fn=ZRJ((Zx8*)(((C)->Zfc)),_i);_f=ZED(((Z25*)a1),_fn);if((_f)!=((void*)(Zo))){
_fn=((((Zx8*)(((((Z85*)_f))->Zfc))))->ZBd);ZzF(((((ZB8*)_fn))->Zxb));ZzF((((ZB8*)(ZRJ((Zx8*)(((C)->Zfc)),_i)))->Zxb));{T0*b1=ZvF(29,"Double definition of feature ");
ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)_fn))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZMJ;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}else{ZBD(((Z25*)a1),(T0*)C,_fn);
}_i=(Z3)(((_i))+(Zrs(1)));}}T0*ZTJ(ZW*C,T0*a1,T0*a2){T0*R=Zo;T0*ZUJ=Zo;ZzF(((((ZB8*)a1))->Zxb));ZUJ=ZVJ((Zx8*)(((C)->Zfc)),((((ZB8*)a1))->Z3n));
if((ZUJ)!=((void*)(Zo))){ZWJ(((ZB8*)ZUJ),a2);}((((T7*)((T7*)(ZwF))))->Zcc)=(Zrs(0));((((T77*)((T77*)(Z_F))))->ZRb)=(Zrs(-1));R=ZBJ(C,a1,a2);
if((R)!=((void*)(Zo))){((((ZM3*)(((ZM3*)R))))->Zec)=(((C)->Zec));ZNJ(C,R);}else{ZEJ(((T82*)a2),a1);}return R;}void ZXJ(ZW*C,T0*a1,T0*a2,T0*a3){
((((ZW*)(C)))->Zfc)=(a1);(C->Zgc)=a2;(C->Zhc)=a3;}T0*ZYJ(ZW*C,T0*a1,T0*a2){T0*R=Zo;T0*_rc=Zo;_rc=Z8G(a1);R=Z8E(((Zj6*)(((((Ze4*)_rc))->Zug))),a2);
if(Zo!=(R)){switch(((T0*)R)->id){case 556:break;default:R=Zo;}}if((R)==((void*)(Zo))){{ZE7*n=((ZE7*)Zh(sizeof(*n)));*n=Z4k;ZZJ(n,a1,a2,(T0*)C);
R=((T0*)n);}}return R;}T6 Z_J(ZW*C,T0*a1){T6 R=0;if((((C)->Zgc))==((void*)(Zo))){R=((T6)((ZvH(a1))!=((void*)(Zo))));}else{R=((T6)((ZvH(a1))==((void*)(Zo))));
}if(R){{T0*b1=ZHJ;ZXw((T7*)(ZwF),b1);}}else{R=((T6)((ZIJ(a1))!=((void*)(Zo))));if(R){{T0*b1=ZJJ;ZXw((T7*)(ZwF),b1);}}}ZNJ(C,a1);return
R;}T76 ZCJ(ZW*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((((Zx8*)(((C)->Zfc))))->ZBd)))->Zxb);return R;}Z_*Z0K(T0*a1,T0*a2){Z_*n;n=((Z_*)Zh(sizeof(*n)));
*n=Zlc;Z1K(n,a1,a2);return n;}void Z1K(Z_*C,T0*a1,T0*a2){(C->Zkc)=a1;((((Zi1*)((Zi1*)(((C)->Zkc)))))->Zgc)=(a2);}void Z2K(Z_*C,T0*a1){
Z3K(a1,((C)->Zkc));}void Z4K(Zr6*C){((((Za9*)((Za9*)(Z5K))))->ZRb)=(Zrs(-1));((((Z65*)((Z65*)(Z6K))))->ZRb)=(Zrs(-1));(C->ZCb)=Zo;(C->ZUi)=((T6)(1));
}void Z7K(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T0*Z8K(Zr6*C,T0*a1){T0*R=Zo;T0*_r=Zo;T76 Z9K={Zo,Zo,0};
_r=ZaK(Z5K,a1,Zo,((T3)'\137'));if((_r)!=((void*)(Zo))){ZhG((T41*)(Z1G));Z9K=(((T80*)((((T82*)(ZbK(a1)))->Zkc)))->Zxb);{Zh6*n=((Zh6*)Zh(sizeof(*n)));
*n=Zvi;ZcK(n,Z9K,_r,a1,Zo);R=((T0*)n);}((((Zh6*)(((Zh6*)R))))->ZCb)=(((C)->ZCb));}return R;}T0*Z6K=Zo;void ZdK(Zr6*C){((((Za9*)((Za9*)(Z5K))))->ZRb)=(Zrs(-1));
(C->ZCb)=Zo;}void ZeK(Zr6*C,T0*a1){T0*_er=Zo;T0*_ee=Zo;if(((C)->ZUi)){_er=ZfK(a1);if((_er)!=((void*)(Zo))){if((((C)->ZCb))==((void*)(Zo))){
(C->ZCb)=((((Zf2*)_er))->ZCb);}ZgK(((Zf2*)_er),Z5K);Zdz((Z65*)(Z6K),_er);}}else{_ee=ZhK(a1);if((_ee)!=((void*)(Zo))){if((((C)->ZCb))==((void*)(Zo))){
(C->ZCb)=((((Z11*)_ee))->ZCb);}ZiK(((Z11*)_ee),Z5K);ZkA((Z78*)(ZjK),_ee);}}}T0*Z5K=Zo;T0*ZjK=Zo;T0*ZkK(Zr6*C,T0*a1,T0*a2){T0*R=Zo;T2 _i=0;
T2 _c=0;T76 _sp={Zo,Zo,0};T0*_bc=Zo;T0*ZmH=Zo;T0*ZnH=Zo;T0*_a=Zo;T0*_r=Zo;T0*_r2=Zo;T0*_er=Zo;T0*ZlK=Zo;T0*ZmK=Zo;_c=(Z3)((((((Z65*)(Z6K))->ZRb)))+(Zrs(1)));
if((_c)==(Zrs(1))){ZlK=((((Z65*)(Z6K))->ZPb))[Zrs(0)];if(((((Zf2*)ZlK))->ZOl)){{T0*b1=ZnK;ZXw((T7*)(ZwF),b1);}ZzF(((((Zf2*)ZlK))->Zxb));
ZoK((T75*)(ZyF));}}else if((Z3)((_c)>(Zrs(1)))){_c=(((Z65*)(Z6K))->ZRb);ZmK=((((Z65*)(Z6K))->ZPb))[_c];ZnH=((((((Zf2*)ZmK))->Zxb)).Zqb);
while(!((_c)==(Zrs(0)))){ZlK=ZmK;ZmH=ZnH;_c=(Z3)(((_c))-(Zrs(1)));ZmK=((((Z65*)(Z6K))->ZPb))[_c];ZnH=((((((Zf2*)ZmK))->Zxb)).Zqb);if((ZmH)==((void*)(ZnH))){
}else if(((((T80*)(((((T82*)ZnH))->Zkc)))->Zre))==((void*)(ZpK))){}else if(ZnI(((T82*)ZnH),ZmH)){if(!(((((Zf2*)ZmK))->ZOl))){{T0*b1=ZqK;
ZXw((T7*)(ZwF),b1);}ZzF(((((Zf2*)ZmK))->Zxb));ZoK((T75*)(ZyF));{T0*b1=ZrK;ZXw((T7*)(ZwF),b1);}ZzF(((((Zf2*)ZlK))->Zxb));ZoK((T75*)(ZyF));
}}}}(C->ZUi)=((T6)(0));_r=ZaK(Z5K,a2,a1,((T3)'R'));if((_r)!=((void*)(Zo))){{Za9*n=((Za9*)Zh(sizeof(*n)));*n=ZNl;ZNA(n,(Z3)(((((((Za9*)_r))->ZRb)))+(Zrs(1))));
_r2=((T0*)n);}_a=(((((Za9*)_r))->ZPb))[Zrs(0)];ZLA(((Za9*)_r2),_a);{T76 Z3w;_sp=(*(Z3w=ZsK(((Zx6*)_a)),&Z3w));}_bc=((_sp).Zqb);_i=Zrs(1);
{T76 Z3w;while(!((T6)(((Z3)((_i)>(((((Za9*)_r))->ZRb))))||((T6)(((((*(Z3w=ZsK((Zx6*)((((((Za9*)_r))->ZPb))[_i])),&Z3w))).Zqb))!=((void*)(_bc)))))))
{ZLA(((Za9*)_r2),(((((Za9*)_r))->ZPb))[_i]);_i=(Z3)(((_i))+(Zrs(1)));}}{Zf2*n=((Zf2*)Zh(sizeof(*n)));*n=ZPl;ZtK(n,_sp,_r2,a2,a1);_er=((T0*)n);
}{ZN*n=((ZN*)Zh(sizeof(*n)));*n=Z4c;ZhI(n,_er);R=((T0*)n);}while(!((Z3)((_i)>(((((Za9*)_r))->ZRb))))){{Za9*n=((Za9*)Zh(sizeof(*n)));*n=ZNl;
ZNA(n,(Z3)(((((((Za9*)_r))->ZRb)))+(Zrs(1))));_r2=((T0*)n);}_a=(((((Za9*)_r))->ZPb))[_i];ZLA(((Za9*)_r2),_a);{T76 Z3w;_sp=(*(Z3w=ZsK(((Zx6*)_a)),&Z3w));
}_bc=((_sp).Zqb);_i=(Z3)(((_i))+(Zrs(1)));{T76 Z3w;while(!((T6)(((Z3)((_i)>(((((Za9*)_r))->ZRb))))||((T6)(((((*(Z3w=ZsK((Zx6*)((((((Za9*)_r))->ZPb))[_i])),&Z3w))).Zqb))!=((void*)(_bc)))))))
{ZLA(((Za9*)_r2),(((((Za9*)_r))->ZPb))[_i]);_i=(Z3)(((_i))+(Zrs(1)));}}{Zf2*n=((Zf2*)Zh(sizeof(*n)));*n=ZPl;ZtK(n,_sp,_r2,a2,a1);_er=((T0*)n);
}ZmI(((ZN*)R),_er);}}return R;}T0*ZaK(T0*a1,T0*a2,T0*a3,T3 a4){T0*R=Zo;T2 _i=0;T0*_a=Zo;if(!((Z3)((((((Za9*)a1))->ZRb))<(Zrs(0))))){R=ZMA(((Za9*)a1));
_i=((((Za9*)R))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){{T0*b1=a3;Z2A((Z_5*)(ZuK),b1);}_a=ZvK((Zx6*)((((((Za9*)R))->ZPb))[_i]),a2,a4);if((_a)==((void*)(Zo))){
{T76 Z3w;Z7K((*(Z3w=ZsK((Zx6*)((((((Za9*)R))->ZPb))[_i])),&Z3w)),ZwK);}}else{(((((Za9*)R))->ZPb))[_i]=(_a);}Z_z((Z_5*)(ZuK));_i=(Z3)(((_i))-(Zrs(1)));
}}return R;}void ZxK(Zr6*C,T0*a1){T0*ZyK=Zo;T0*_bc=Zo;T0*ZnH=Zo;ZzK(((Zh6*)a1),Z5K);ZyK=((((Zh6*)a1))->ZCb);if((((C)->ZCb))==((void*)(Zo))){
(C->ZCb)=ZyK;}else if((ZyK)==((void*)(Zo))){}else{_bc=(((((T86*)(((C)->ZCb)))->Zxb)).Zqb);ZnH=((((((T86*)ZyK))->Zxb)).Zqb);if((T6)(((ZnH)==((void*)(_bc)))||((T6)(ZnI(((T82*)ZnH),_bc))))){
(C->ZCb)=ZyK;}}}void ZAK(Zr6*C){((((Za9*)((Za9*)(Z5K))))->ZRb)=(Zrs(-1));((((Z78*)((Z78*)(ZjK))))->ZRb)=(Zrs(-1));(C->ZCb)=Zo;}T0*ZBK(Zr6*C,T0*a1,T0*a2){
T0*R=Zo;T0*_r=Zo;T76 Z9K={Zo,Zo,0};T2 _c=0;T0*ZCK=Zo;T0*ZDK=Zo;T0*ZmH=Zo;T0*ZnH=Zo;_c=(Z3)((((((Z78*)(ZjK))->ZRb)))+(Zrs(1)));if((_c)==(Zrs(1))){
ZCK=((((Z78*)(ZjK))->ZPb))[Zrs(0)];if(((((Z11*)ZCK))->Zmc)){{T0*b1=ZEK;ZXw((T7*)(ZwF),b1);}ZzF(((((Z11*)ZCK))->Zxb));ZoK((T75*)(ZyF));
}}else if((Z3)((_c)>(Zrs(1)))){_c=(((Z78*)(ZjK))->ZRb);ZDK=((((Z78*)(ZjK))->ZPb))[_c];ZnH=((((((Z11*)ZDK))->Zxb)).Zqb);while(!((_c)==(Zrs(0))))
{ZCK=ZDK;ZmH=ZnH;_c=(Z3)(((_c))-(Zrs(1)));ZDK=((((Z78*)(ZjK))->ZPb))[_c];ZnH=((((((Z11*)ZDK))->Zxb)).Zqb);if((ZmH)==((void*)(ZnH))){}
else if(((((T80*)(((((T82*)ZnH))->Zkc)))->Zre))==((void*)(ZpK))){}else if(ZnI(((T82*)ZnH),ZmH)){if(!(((((Z11*)ZDK))->Zmc))){{T0*b1=ZFK;
ZXw((T7*)(ZwF),b1);}ZzF(((((Z11*)ZDK))->Zxb));ZoK((T75*)(ZyF));{T0*b1=ZGK;ZXw((T7*)(ZwF),b1);}ZzF(((((Z11*)ZCK))->Zxb));ZoK((T75*)(ZyF));
}}}}_r=ZaK(Z5K,a2,a1,((T3)'E'));if((_r)!=((void*)(Zo))){Z9K=(((T80*)((((T82*)(ZbK(a2)))->Zkc)))->Zxb);{Z11*n=((Z11*)Zh(sizeof(*n)));*n=Znc;
ZHK(n,Z9K,_r,a2,a1);R=((T0*)n);}((((Z11*)(((Z11*)R))))->ZCb)=(((C)->ZCb));}return R;}Z31*ZIK(T0*a1){Z31*n;n=((Z31*)Zh(sizeof(*n)));*n=Zrc;
((((Z31*)(n)))->Zoc)=(a1);return n;}T0*ZJK=Zo;int ZKK=0;T0*ZLK(void){if(ZKK==0){ZKK=1;{T76 ZMK={Zo,Zo,0};{Zk3*n=((Zk3*)Zh(sizeof(*n)));
*n=Zge;ZJK=((T0*)n);ZNK(n,ZMK);}}}return ZJK;}T0*ZOK=Zo;T0*ZPK=Zo;T0*ZQK=Zo;int ZRK=0;T0*ZSK(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));
*n=M36;ZQK=((T0*)n);}}}return ZQK;}void ZTK(Z31*C){T2 _i=0;T0*_rf=Zo;if((((C)->Zqc))!=((void*)(Zo))){_i=(((Zv4*)(((C)->Zqc)))->ZRb);while(!((Z3)((_i)<(Zrs(0)))))
{_rf=(((Zw3*)(((((Zv4*)(((C)->Zqc)))->ZPb))[_i]))->ZCd);ZUK(_rf);_i=(Z3)(((_i))-(Zrs(1)));}}}void ZVK(Z31*C){T0*ZWK=Zo;T0*_rt=Zo;T0*ZXK=Zo;
T0*ZYK=Zo;T0*_fn=Zo;T0*ZZK=Zo;T0*_rf=Zo;T2 _i=0;T0*_rc=Zo;{Zv4*n=((Zv4*)Zh(sizeof(*n)));*n=Z4g;Z5z(n,(T2)(Zrs(4)));(C->Zqc)=((T0*)n);
}(C->Zpc)=Z_K((ZK9*)(ZOK),((C)->Zoc));{Zl2*n=((Zl2*)Zh(sizeof(*n)));*n=ZAd;Zry(n,(T2)(Zrs(4)));ZYK=((T0*)n);}while(!(((((ZK9*)(ZOK))->_cc))==(((T3)'\000'))))
{ZWK=Zwe(Z0L((ZK9*)(ZOK)),ZZK);Z4z((Zv4*)(((C)->Zqc)),ZWK);_rt=Z1L((ZK9*)(ZOK));if(!(Z2L(_rt))){{T0*b1=ZvF(67,"All type marks used in a cecil file have to be static (no anchors).");
ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=Z3L(_rt),&Z3w)));}ZEF((T75*)(ZyF));}ZXK=_rt;if(Zo!=(ZXK)){switch(((T0*)ZXK)->id){case 282:break;
default:ZXK=Zo;}}if((T6)((Z4L(_rt))||((T6)((ZXK)!=((void*)(Zo)))))){{T0*b1=ZvF(211,"Cannot use agents type marks or TUPLE type marks inside cecil files (SmartEiffel limitation, sorry). To work around, just use an extra Eiffel routine/object to perform agent or TUPLE manipulation in pure Eiffel.");
ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=Z3L(_rt),&Z3w)));}ZEF((T75*)(ZyF));}_fn=Z5L((ZK9*)(ZOK));Zqy(((Zl2*)ZYK),ZEd(_rt,_fn));}Z6L((ZK9*)(ZOK));
Z7L((T36*)(ZSK()),Z8L);_i=Zrs(0);while(!((Z3)((_i)>(((((Zl2*)ZYK))->ZRb))))){_rt=(((Zu1*)((((((Zl2*)ZYK))->ZPb))[_i]))->ZBd);_fn=(((Zu1*)((((((Zl2*)ZYK))->ZPb))[_i]))->ZCd);
_rt=Z9L(_rt,ZLK());_rc=Z8G(_rt);_rf=ZaL(((Ze4*)_rc),_fn);if((_rf)==((void*)(Zo))){ZzF(((((ZB8*)_fn))->Zxb));{T0*b1=ZvF(42,"Error while loading feature of cecil file.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}{T76 Z3w;ZbL((*(Z3w=ZCF(_rf),&Z3w)),ZcL(_rf),ZqG(_rf));}if(ZdL(_rf)){}else if(((Z3)(((((((ZC3*)((((Zc3*)(((((Ze4*)_rc))->Zof)))->Z9e))))->ZRb)))+(Zrs(1))))==(Zrs(0))){
ZeL(((Ze4*)_rc));}ZfL(_rf);((((Zw3*)((Zw3*)(((((Zv4*)(((C)->Zqc)))->ZPb))[_i]))))->ZCd)=(_rf);_i=(Z3)(((_i))+(Zrs(1)));}}void ZgL(Z31*C){
T2 _i=0;T0*ZWK=Zo;if((((C)->Zqc))!=((void*)(Zo))){Z7L((T36*)(ZSK()),ZhL);ZiL((Zi4*)(ZsG),((C)->Zpc));_i=(((Zv4*)(((C)->Zqc)))->ZRb);while(!((Z3)((_i)<(Zrs(0)))))
{ZWK=((((Zv4*)(((C)->Zqc)))->ZPb))[_i];ZjL(((((Zw3*)ZWK))->ZBd),((((Zw3*)ZWK))->ZCd));_i=(Z3)(((_i))-(Zrs(1)));}ZkL((Zi4*)(ZsG));}}void
ZlL(Z61*C){T2 _i=0;if((((C)->Zyc))==((void*)(Zo))){{ZP4*n=((ZP4*)Zh(sizeof(*n)));*n=ZPg;Zcz(n,(Z3)(((((C)->Zuc)))+((T2)(Zrs(2)))));(C->Zyc)=((T0*)n);
}}else{Zcz((ZP4*)(((C)->Zyc)),(Z3)(((((C)->Zuc)))+((T2)(Zrs(2)))));}_i=(((ZP4*)(((C)->Zyc)))->ZRb);while(!((Z3)((_i)<(Zrs(0))))){((((ZP4*)(((C)->Zyc)))->ZPb))[_i]=(((T0*)ZUD()));
_i=(Z3)(((_i))-(Zrs(1)));}}T0*ZmL=Zo;T2 ZnL(Z61*C,T0*a1,T2 a2,T2 a3){T2 R=0;T2 _i=0;if((((((T7*)a1))->Zcc))==(Zrs(0))){R=((C)->Zvc);}
else{R=ZoL(C,Zrs(-1),(((((T7*)a1))->ZPb))[(a2)-(Zrs(1))]);_i=(Z3)(((a2))+(Zrs(1)));while(!((T6)(((Z3)((_i)>(a3)))||((T6)((R)==(Zrs(-1)))))))
{R=ZoL(C,R,(((((T7*)a1))->ZPb))[(_i)-(Zrs(1))]);_i=(Z3)(((_i))+(Zrs(1)));}}return R;}void ZpL(Z61*C,T0*a1){T2 _i=0;T2 _j=0;T2 _n=0;T2
_st=0;T0*_s=Zo;Z7L((T36*)(ZqL()),ZrL);ZsL((T36*)(ZqL()),((C)->_id));Z7L((T36*)(ZqL()),ZtL);ZsL((T36*)(ZqL()),(Z3)(((((C)->Zuc)))+((T2)(Zrs(1)))));
Z7L((T36*)(ZqL()),ZuL);_i=ZUz(a1);while(!((Z3)((_i)>(((((T52*)a1))->ZRb))))){_s=ZVz(a1,_i);Z7L((T36*)(ZqL()),ZvF(2,"\011""\""));Z7L((T36*)(ZqL()),_s);
Z7L((T36*)(ZqL()),ZvL);if((((((T7*)_s))->Zcc))==(Zrs(0))){_st=((C)->Zvc);}else{_st=Zrs(-1);_n=((((T7*)_s))->Zcc);_j=Zrs(1);while(!((Z3)((_j)>(_n))))
{if((Z3)((_j)>(Zrs(1)))){ZwL((T36*)(ZqL()),((T3)'\054'));}_st=ZoL(C,_st,(((((T7*)_s))->ZPb))[(_j)-(Zrs(1))]);ZsL((T36*)(ZqL()),_st);_j=(Z3)(((_j))+(Zrs(1)));
}}Z7L((T36*)(ZqL()),ZxL);ZyL((T37*)(ZlF));ZsL((T36*)(ZqL()),ZtE((Zb8*)(((C)->Zwc)),_st));ZzL((T36*)(ZqL()));_i=(Z3)(((_i))+(Zrs(1)));
}}T0*ZqL(void){if(ZRK==0){ZRK=1;{{T36*n=((T36*)Zh(sizeof(*n)));*n=M36;ZQK=((T0*)n);}}}return ZQK;}void ZAL(Z61*C){T3 _c=0;T3 _k=0;T2 _i=0;
T2 _j=0;T6 ZBL=0;T6 ZCL=0;T0*_s=Zo;T2 ZDL=0;T2 ZEL=0;T2 ZFL=0;ZvA((T94*)(ZGL),(Z3)((((((T52*)(((C)->Zxc)))->ZRb)))+(Zrs(1))));{T94*C1=(T94*)(ZGL);
T2 b1=Zrs(-1);Zmw(((C1)->ZPb),b1,((C1)->ZRb));}(C->Zuc)=Zrs(0);ZFL=Zrs(-1);ZDL=(((T52*)(((C)->Zxc)))->ZRb);ZBL=((T6)(1));_i=Zrs(1);while(!(!(ZBL)))
{ZBL=((T6)(0));ZCL=((T6)(1));_j=Zrs(0);while(!((Z3)((_j)>((((T52*)(((C)->Zxc)))->ZRb))))){_s=((((T52*)(((C)->Zxc)))->ZPb))[_j];if((T6)((!(((C)->Ztc)))&&((T6)((((((T7*)_s))->Zcc))==(Zrs(0)))))){
(C->Ztc)=((T6)(1));(C->Zvc)=_j;}if((ZEL)!=(((((T94*)(ZGL))->ZPb))[_j])){ZEL=((((T94*)(ZGL))->ZPb))[_j];ZCL=((T6)(1));}if((Z3)((_i)>(((((T7*)_s))->Zcc)))){
ZCL=((T6)(1));}else{ZBL=((T6)(1));_k=(((((T7*)_s))->ZPb))[(_i)-(Zrs(1))];if((_i)==(((((T7*)_s))->Zcc))){ZFL=_j;_c=_k;}else if((T6)((ZCL)||((T6)((_c)!=(_k))))){
ZDL=(Z3)(((ZDL))+(Zrs(1)));ZFL=ZDL;_c=_k;}ZCL=((T6)(0));((((T94*)(ZGL))->ZPb))[_j]=(ZFL);}_j=(Z3)(((_j))+(Zrs(1)));}_i=(Z3)(((_i))+(Zrs(1)));
}(C->Zuc)=ZDL;}T0*ZHL=Zo;T2 ZoL(Z61*C,T2 a1,T3 a2){T2 R=0;T2 _i=0;T0*_l=Zo;_l=(((((ZP4*)(((C)->Zyc))))->ZPb))[(a1)+(Zrs(1))];R=Zrs(-1);
_i=Zrs(1);while(!((T6)(((R)!=(Zrs(-1)))||((T6)((Z3)((_i)>(((((ZY5*)_l))->ZRb)))))))){if(((((Z_3*)(ZWD(((ZY5*)_l),_i)))->ZBd))==(a2)){
R=(((Z_3*)(ZWD(((ZY5*)_l),_i)))->ZCd);}_i=(Z3)(((_i))+(Zrs(1)));}return R;}T0*ZGL=Zo;void ZIL(Z61*C){T3 _c=0;T3 _k=0;T2 _i=0;T2 _j=0;
T6 ZBL=0;T6 ZCL=0;T0*_s=Zo;T2 ZDL=0;T2 ZEL=0;T2 ZFL=0;ZvA((T94*)(ZGL),(Z3)((((((T52*)(((C)->Zxc)))->ZRb)))+(Zrs(1))));{T94*C1=(T94*)(ZGL);
T2 b1=Zrs(-1);Zmw(((C1)->ZPb),b1,((C1)->ZRb));}ZFL=Zrs(-1);ZDL=(((T52*)(((C)->Zxc)))->ZRb);ZBL=((T6)(1));_i=Zrs(1);while(!(!(ZBL))){ZBL=((T6)(0));
ZCL=((T6)(1));_j=Zrs(0);while(!((Z3)((_j)>((((T52*)(((C)->Zxc)))->ZRb))))){_s=((((T52*)(((C)->Zxc)))->ZPb))[_j];if((ZEL)!=(((((T94*)(ZGL))->ZPb))[_j])){
ZEL=((((T94*)(ZGL))->ZPb))[_j];ZCL=((T6)(1));}if((Z3)((_i)>(((((T7*)_s))->Zcc)))){ZCL=((T6)(1));}else{ZBL=((T6)(1));_k=(((((T7*)_s))->ZPb))[(_i)-(Zrs(1))];
if((_i)==(((((T7*)_s))->Zcc))){ZFL=_j;_c=_k;{Z61*C1=C;T2 b1=ZFL;T2 b2=ZEL;T3 b3=_k;ZYD((ZY5*)((((((ZP4*)(((C1)->Zyc))))->ZPb))[(b2)+(Zrs(1))]),ZOe(b3,
b1));}}else if((T6)((ZCL)||((T6)((_c)!=(_k))))){ZDL=(Z3)(((ZDL))+(Zrs(1)));ZFL=ZDL;_c=_k;{Z61*C1=C;T2 b1=ZFL;T2 b2=ZEL;T3 b3=_k;ZYD((ZY5*)((((((ZP4*)(((C1)->Zyc))))->ZPb))[(b2)+(Zrs(1))]),ZOe(b3,
b1));}}ZCL=((T6)(0));((((T94*)(ZGL))->ZPb))[_j]=(ZFL);}_j=(Z3)(((_j))+(Zrs(1)));}_i=(Z3)(((_i))+(Zrs(1)));}}void ZJL(Z61*C,T0*a1){int
_cs=0;ZKL((Zn6*)(ZHL));(C->_id)=(((Zn6*)(ZHL))->Zde);{T52*n=((T52*)Zh(sizeof(*n)));*n=M52;ZSz(n,a1);(C->Zxc)=((T0*)n);}ZgD(((C)->Zxc));
ZAL(C);ZlL(C);ZIL(C);ZLL(C,a1);ZpL(C,a1);}void ZLL(Z61*C,T0*a1){T2 ZML=0;T2 ZNL=0;T0*_s=Zo;if((((C)->Zwc))==((void*)(Zo))){{Zb8*n=((Zb8*)Zh(sizeof(*n)));
*n=ZAk;ZxE(n,(Z3)((((((T52*)(((C)->Zxc)))->ZRb)))+(Zrs(1))));(C->Zwc)=((T0*)n);}}else{ZwE((Zb8*)(((C)->Zwc)));}ZNL=ZUz(a1);while(!((Z3)((ZNL)>(((((T52*)a1))->ZRb)))))
{_s=ZVz(a1,ZNL);ZML=ZnL(C,_s,(T2)(Zrs(1)),((((T7*)_s))->Zcc));ZuE((Zb8*)(((C)->Zwc)),ZNL,ZML);ZNL=(Z3)(((ZNL))+(Zrs(1)));}}T0*ZOL=Zo;
T2 ZPL(Za1*C,T2 a1,T0*a2){T2 R=0;T0*ZQL=Zo;T2 _i=0;T3 _c=0;((((T7*)((T7*)(ZRL))))->Zcc)=(Zrs(0));ZZs((T7*)(ZRL),(((((T7*)a2))->ZPb))[(a1)-(Zrs(1))]);
_i=(Z3)(((a1))+(Zrs(1)));while(!((T6)(((Z3)((_i)>(((((T7*)a2))->Zcc))))||((T6)((Z3)((R)>(_i))))))){_c=(((((T7*)a2))->ZPb))[(_i)-(Zrs(1))];
{int z1=_c;switch(z1){case 34:case 62:ZZs((T7*)(ZRL),_c);ZQL=ZRs((T7*)(ZRL));if(!(ZMz((T52*)(ZSL),ZQL))){ZPz((T52*)(ZSL),ZQL);{Zi4*C1=(Zi4*)(ZsG);
T0*b1=ZQL;ZTL(((C1)->ZJf),b1);}}R=(Z3)(((_i))+(Zrs(1)));break;default:;ZZs((T7*)(ZRL),_c);_i=(Z3)(((_i))+(Zrs(1)));}}}if((R)==(Zrs(0))){
R=ZUL(C,_i,a2,(T2)(Zrs(20)));}return R;}T0*ZRL=Zo;void ZVL(Za1*C,T0*a1){T0*_er=Zo;T2 ZWL=0;_er=((((ZS7*)a1))->ZPj);if(!(ZKy((ZF2*)(ZXL),_er))){
ZMy((ZF2*)(ZXL),_er);ZYL(((ZS7*)a1),_er);((((T7*)((T7*)(ZOL))))->Zcc)=(Zrs(0));ZXw((T7*)(ZOL),ZZL);Z_L(((((ZS7*)a1))->Zgc),ZOL);ZZs((T7*)(ZOL),((T3)'\051'));
if((((((ZS7*)a1))->ZAb))!=((void*)(Zo))){ZWL=Zty(((Zn2*)((((ZH6*)(((((ZS7*)a1))->ZAb)))->Zhe))));}Z0M(C,ZWL,(((T88*)(((C)->ZBc)))->Zre),_er);
ZXw((T7*)(ZOL),Z1M);Z7I((Zi4*)(ZsG),ZOL);}}void Z2M(Za1*C,T0*a1,T0*a2,T0*a3){Z3M(C,a1,a2,a3);Z4M((Zi4*)(ZsG),(T0*)C);(C->ZDc)=a1;}void
Z5M(T0*a1,T0*a2,T0*a3){if(((((T84*)(ZFI))->Zcf))==(Zrs(1))){Z6M(((((ZQ7*)a1))->ZPj),Z7M(((ZQ7*)a1)));Z7I((Zi4*)(ZsG),Z8M);}else{Z9M(((ZQ7*)a1));
}}void Z0M(Za1*C,T2 a1,T0*a2,T0*a3){T2 _i=0;T2 ZIi=0;T2 ZaM=0;T2 ZbM=0;T3 _c=0;_i=Zrs(4);while(!((Z3)((_i)>(((((T7*)a2))->Zcc))))){_c=(((((T7*)a2))->ZPb))[(_i)-(Zrs(1))];
{int z1=ZIi;switch(z1){case 0:{int z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 91:_i=(Z3)(((_i))+(Zrs(1)));
ZIi=Zrs(1);break;default:;_i=ZUL(C,_i,a2,ZIi);}}break;case 1:if((T6)(((T6)(((_c)==(((T3)'\040')))||((T6)((_c)==(((T3)'\011'))))))||((T6)((_c)==(((T3)'\n')))))){
_i=(Z3)(((_i))+(Zrs(1)));}else if((_i)==(Z1x(((T7*)a2),ZcM,_i))){_i=(Z3)(((_i))+(Zrs(7)));_i=ZdM(C,_i,a2);ZXw((T7*)(ZOL),ZeM);ZXw((T7*)(ZOL),ZfM(((Z85*)a3)));
ZIi=Zrs(2);}else if((_i)==(Z1x(((T7*)a2),ZgM,_i))){_i=(Z3)(((_i))+(Zrs(4)));ZXw((T7*)(ZOL),ZhM);_i=ZdM(C,_i,a2);ZIi=Zrs(3);}else if((_i)==(Z1x(((T7*)a2),ZiM,_i))){
_i=(Z3)(((_i))+(Zrs(7)));ZXw((T7*)(ZOL),ZjM);_i=ZdM(C,_i,a2);ZXw((T7*)(ZOL),ZkM);if((T6)(((ZaM)!=(Zrs(0)))||((T6)((a1)!=(Zrs(1)))))){
_i=ZUL(C,_i,a2,ZIi);}else{ZIi=Zrs(4);}}else if((_i)==(Z1x(((T7*)a2),ZlM,_i))){_i=ZUL(C,_i,a2,ZIi);}else{ZaM=(Z3)(((ZaM))+(Zrs(1)));ZXw((T7*)(ZOL),ZmM);
_i=ZdM(C,_i,a2);ZXw((T7*)(ZOL),ZnM);ZXw((T7*)(ZOL),ZfM(((Z85*)a3)));ZIi=Zrs(5);}break;case 2:{int z2=_c;switch(z2){case 9:case 10:case
32:_i=(Z3)(((_i))+(Zrs(1)));break;case 93:_i=(Z3)(((_i))+(Zrs(1)));ZIi=Zrs(8);break;default:;_i=ZUL(C,_i,a2,ZIi);}}break;case 3:{int z2=_c;
switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 93:_i=(Z3)(((_i))+(Zrs(1)));ZIi=Zrs(6);break;default:;_i=ZUL(C,_i,a2,ZIi);
}}break;case 4:{int z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 93:_i=(Z3)(((_i))+(Zrs(1)));ZIi=Zrs(10);
break;default:;_i=ZUL(C,_i,a2,ZIi);}}break;case 5:{int z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 93:
_i=(Z3)(((_i))+(Zrs(1)));ZIi=Zrs(7);break;default:;_i=ZUL(C,_i,a2,ZIi);}}break;case 6:{int z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));
break;case 40:_i=ZoM(C,_i,a2,ZaM,a1);ZIi=Zrs(13);break;default:;_i=ZUL(C,_i,a2,ZIi);}}break;case 7:{int z2=_c;switch(z2){case 9:case 10:
case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 40:_i=ZoM(C,_i,a2,ZaM,a1);ZIi=Zrs(11);break;default:;_i=ZUL(C,_i,a2,ZIi);}}break;case 8:{int
z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 40:_i=ZoM(C,_i,a2,ZaM,a1);ZIi=Zrs(9);break;default:;_i=ZUL(C,_i,a2,ZIi);
}}break;case 9:_i=(Z3)(((_i))+(Zrs(1)));break;case 10:{int z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case
40:ZbM=(Z3)(((ZbM))+(Zrs(1)));_i=(Z3)(((_i))+(Zrs(1)));break;case 41:if((Z3)((ZbM)>(Zrs(1)))){_i=ZUL(C,_i,a2,ZIi);}else{_i=(Z3)(((_i))+(Zrs(1)));
}break;default:;_i=ZUL(C,_i,a2,ZIi);}}break;case 11:{int z2=_c;switch(z2){case 58:ZIi=Zrs(12);break;case 124:ZIi=Zrs(13);break;}}_i=(Z3)(((_i))+(Zrs(1)));
break;case 12:{int z2=_c;switch(z2){case 124:ZIi=Zrs(13);break;}}_i=(Z3)(((_i))+(Zrs(1)));break;default:;{int z2=_c;switch(z2){case 9:
case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 34:case 60:_i=ZPL(C,_i,a2);break;case 44:_i=(Z3)(((_i))+(Zrs(1)));break;default:;
_i=ZUL(C,_i,a2,ZIi);}}}}}}T0*ZXL=Zo;void Z3M(Za1*C,T0*a1,T0*a2,T0*a3){{ZS7*C1=((ZS7*)a1);T76 b1=(((T88*)(((C)->ZBc)))->Zxb);ZpM(C1,b1,((C1)->ZPj));
}if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){((((T7*)((T7*)(ZOL))))->Zcc)=(Zrs(0));ZZs((T7*)(ZOL),((T3)'R'));ZZs((T7*)(ZOL),((T3)'\075'));
ZqM(((((ZS7*)a1))->ZPj),ZrM(((ZS7*)a1)));ZsM(((ZS7*)a1),ZOL);}}void ZtM(Za1*C,T0*a1,T0*a2,T0*a3){{ZQ7*C1=((ZQ7*)a1);T76 b1=(((T88*)(((C)->ZBc)))->Zxb);
ZuM(C1,b1,((C1)->ZPj));}if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){((((T7*)((T7*)(ZOL))))->Zcc)=(Zrs(0));ZqM(((((ZQ7*)a1))->ZPj),Z7M(((ZQ7*)a1)));
ZvM(((ZQ7*)a1),ZOL);}}void ZwM(Za1*C,T0*a1,T0*a2,T0*a3){ZtM(C,a1,a2,a3);Z4M((Zi4*)(ZsG),(T0*)C);(C->ZCc)=a1;}void Z6M(T0*a1,T2 a2){T6
ZxM=0;T6 ZyM=0;ZxM=((T6)(0));if(!(ZxM)){ZyM=((T6)(ZzM((Zi4*)(ZsG))));if(ZyM){ZcH((Zi4*)(ZsG),((T3)'\054'));}}Z7I((Zi4*)(ZsG),ZAM(((Z85*)a1)));
ZcH((Zi4*)(ZsG),((T3)'\050'));if(ZxM){ZBM((Zi4*)(ZsG));}if((Z3)((a2)>(Zrs(0)))){if(ZxM){ZcH((Zi4*)(ZsG),((T3)'\054'));}ZCM((Zi4*)(ZsG));
}ZcH((Zi4*)(ZsG),((T3)'\051'));if((T6)((!(ZxM))&&((T6)(ZyM)))){ZcH((Zi4*)(ZsG),((T3)'\051'));}}void ZDM(Za1*C){if((((C)->ZDc))!=((void*)(Zo))){
ZVL(C,((C)->ZDc));}else{ZEM(C,((C)->ZCc));}}T6 ZFM(T0*a1){T6 R=0;return R;}void ZqM(T0*a1,T2 a2){T2 _i=0;ZXw((T7*)(ZOL),ZAM(((Z85*)a1)));
ZZs((T7*)(ZOL),((T3)'\050'));_i=Zrs(1);while(!((Z3)((_i)>(a2)))){ZZs((T7*)(ZOL),((T3)'a'));ZQs(_i,ZOL);_i=(Z3)(((_i))+(Zrs(1)));if((Z3)((_i)<=(a2))){
ZZs((T7*)(ZOL),((T3)'\054'));}}ZXw((T7*)(ZOL),ZGM);}T2 ZoM(Za1*C,T2 a1,T0*a2,T2 a3,T2 a4){T2 R=0;T2 _i=0;T2 ZbM=0;T2 _a=0;T2 ZIi=0;T3
_c=0;_a=a3;ZIi=Zrs(40);ZZs((T7*)(ZOL),((T3)'\050'));_i=(Z3)(((a1))+(Zrs(1)));while(!((T6)(((Z3)((_i)>(((((T7*)a2))->Zcc))))||((T6)((Z3)((R)>(_i)))))))
{_c=(((((T7*)a2))->ZPb))[(_i)-(Zrs(1))];{int z1=ZIi;switch(z1){case 40:{int z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));
break;case 41:R=(Z3)(((_i))+(Zrs(1)));break;default:;ZZs((T7*)(ZOL),((T3)'\050'));ZIi=Zrs(41);}}break;default:;{int z2=_c;switch(z2){
case 44:_i=(Z3)(((_i))+(Zrs(1)));ZZs((T7*)(ZOL),((T3)'\051'));_a=(Z3)(((_a))+(Zrs(1)));ZZs((T7*)(ZOL),((T3)'a'));ZQs(_a,ZOL);if((Z3)((_a)<(a4))){
ZZs((T7*)(ZOL),((T3)'\054'));}ZIi=Zrs(40);break;case 40:ZZs((T7*)(ZOL),_c);ZbM=(Z3)(((ZbM))+(Zrs(1)));_i=(Z3)(((_i))+(Zrs(1)));break;
case 41:if((ZbM)==(Zrs(0))){ZZs((T7*)(ZOL),((T3)'\051'));_a=(Z3)(((_a))+(Zrs(1)));ZZs((T7*)(ZOL),((T3)'a'));ZQs(_a,ZOL);R=(Z3)(((_i))+(Zrs(1)));
}else{ZZs((T7*)(ZOL),_c);ZbM=(Z3)(((ZbM))-(Zrs(1)));_i=(Z3)(((_i))+(Zrs(1)));}break;default:;ZZs((T7*)(ZOL),_c);_i=(Z3)(((_i))+(Zrs(1)));
}}}}}ZZs((T7*)(ZOL),((T3)'\051'));if((T6)(((R)==(Zrs(0)))||((T6)((_a)!=(a4))))){R=ZUL(C,_i,a2,ZIi);}return R;}T0*ZSL=Zo;void ZHM(T0*a1,T0*a2,T0*a3){
if(((((T84*)(ZFI))->Zcf))==(Zrs(1))){Z6M(((((ZS7*)a1))->ZPj),ZrM(((ZS7*)a1)));}else{ZIM(((ZS7*)a1));}}T2 ZdM(Za1*C,T2 a1,T0*a2){T2 R=0;
T2 _i=0;T2 ZIi=0;T3 _c=0;ZIi=Zrs(30);_i=a1;while(!((T6)(((Z3)((_i)>(((((T7*)a2))->Zcc))))||((T6)((Z3)((ZIi)>(Zrs(32)))))))){_c=(((((T7*)a2))->ZPb))[(_i)-(Zrs(1))];
{int z1=ZIi;switch(z1){case 30:{int z2=_c;switch(z2){case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 34:case 40:case 41:case
60:case 62:_i=ZUL(C,_i,a2,ZIi);break;default:;ZIi=Zrs(31);}}break;case 31:{int z2=_c;switch(z2){case 9:case 10:case 32:ZIi=Zrs(32);break;
case 34:case 60:_i=ZPL(C,_i,a2);ZIi=Zrs(33);break;default:;ZZs((T7*)(ZOL),_c);_i=(Z3)(((_i))+(Zrs(1)));}}break;default:;{int z2=_c;switch(z2){
case 9:case 10:case 32:_i=(Z3)(((_i))+(Zrs(1)));break;case 34:case 60:_i=ZPL(C,_i,a2);ZIi=Zrs(33);break;default:;_i=ZUL(C,_i,a2,ZIi);
}}}}}R=_i;return R;}void ZEM(Za1*C,T0*a1){T0*_er=Zo;T2 ZWL=0;_er=((((ZQ7*)a1))->ZPj);if(!(ZKy((ZF2*)(ZXL),_er))){ZMy((ZF2*)(ZXL),_er);
ZJM(((ZQ7*)a1),_er);((((T7*)((T7*)(ZOL))))->Zcc)=(Zrs(0));if((((((ZQ7*)a1))->ZAb))!=((void*)(Zo))){ZWL=Zty(((Zn2*)((((ZH6*)(((((ZQ7*)a1))->ZAb)))->Zhe))));
}Z0M(C,ZWL,(((T88*)(((C)->ZBc)))->Zre),_er);ZXw((T7*)(ZOL),ZKM);Z7I((Zi4*)(ZsG),ZOL);}}T2 ZUL(Za1*C,T2 a1,T0*a2,T2 a3){T2 R=0;if((((C)->ZCc))!=((void*)(Zo))){
{T76 Z3w;ZzF((*(Z3w=ZLM((Z85*)((((ZQ7*)(((C)->ZCc)))->ZPj))),&Z3w)));}}else{{T76 Z3w;ZzF((*(Z3w=ZMM((Zq7*)((((ZS7*)(((C)->ZDc)))->ZPj))),&Z3w)));
}}{T0*b1=ZvF(41,"Bad external \"C++\" definition.\nexternal \"");ZXw((T7*)(ZwF),b1);}{T0*b1=a2;ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(11,"\"\n_________");
ZXw((T7*)(ZwF),b1);}R=Zrs(1);while(!((Z3)((R)>(a1)))){{T3 b1=((T3)'\137');ZZs((T7*)(ZwF),b1);}R=(Z3)(((R))+(Zrs(1)));}{T3 b1=((T3)'\136');
ZZs((T7*)(ZwF),b1);}{T0*b1=ZvF(90,"\nSee SmartEiffel/tutorial/external/C++ directory for more information.\n (Internal state = ");ZXw((T7*)(ZwF),b1);
}{T0*b1=ZPs(a3);ZXw((T7*)(ZwF),b1);}{T3 b1=((T3)'\051');ZZs((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));R=(Z3)(((((((T7*)a2))->Zcc)))+(Zrs(1)));
return R;}T76 ZNM(Za1*C){T76 R={Zo,Zo,0};R=(((T88*)(((C)->ZBc)))->Zxb);return R;}void ZOM(Zc1*C){T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){
if((((C)->ZAb))!=((void*)(Zo))){Zof=(((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>=(Zrs(1)))){
{T76 Z3w;ZmG((T41*)(Z1G),(*(Z3w=ZPM(C),&Z3w)),((C)->Z_b),Zof);}}}}ZoG(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){ZpG((Zm3*)(((C)->ZAb)));
}}void ZQM(Zc1*C){ZRM((Zo9*)(((C)->ZGc)),((C)->ZYb));ZcH((Zi4*)(ZsG),((T3)'\073'));ZcH((Zi4*)(ZsG),((T3)'\n'));}T0*ZSM=Zo;T6 ZTM(T0*a1){
T6 R=0;return R;}void ZUM(Zc1*C,T0*a1){(C->ZFc)=a1;(C->ZYb)=(((ZZ6*)(((C)->ZFc)))->ZYb);(C->ZZb)=(((ZZ6*)(((C)->ZFc)))->ZZb);(C->ZAb)=ZVM(((C)->ZFc));
(C->Z_b)=(((ZZ6*)(((C)->ZFc)))->Z_b);(C->ZGc)=ZWM(((C)->ZAb),((C)->Z_b));}void ZXM(Zc1*C){T0*ZQG=Zo;T0*_rc=Zo;T0*Zof=Zo;if((((C)->Z_b))!=((void*)(Zo))){
ZQG=ZOG(((C)->ZYb));_rc=Z8G(ZQG);Zof=((((Ze4*)_rc))->Zof);if((Z3)(((Z3)(((((((ZC3*)(((((Zc3*)Zof))->Z9e))))->ZRb)))+(Zrs(1))))>(Zrs(1)))){
ZRG(((C)->ZYb),((C)->Z_b));}}ZSG(((C)->ZYb));ZTG((Zm3*)(((C)->ZAb)));}T6 ZYM(Zc1*C){T6 R=0;R=((T6)(ZVG((Zm3*)(((C)->ZAb)))));if(R){}else
if(Z4G(((C)->ZYb))){if((ZWG())!=((void*)(((C)->Z_b)))){R=((T6)(ZXG(((C)->Z_b))));}}else{R=((T6)(ZYG(((C)->ZYb))));}return R;}void ZZM(Zc1*C,T0*a1){
T6 Z_M=0;if((T6)((!(Z4G(((C)->ZYb))))&&((T6)(Z2H(ZOG(((C)->ZYb))))))){if((a1)!=((void*)(Zo))){Z_M=((T6)(Z4H(((ZH6*)a1),(((ZZ6*)(((C)->ZFc)))->ZYb))));
}else{Z5H(((C)->ZYb));}}}T0*Z0N(Zc1*C,T0*a1){T0*R=Zo;{Zn8*n=((Zn8*)Zh(sizeof(*n)));*n=ZVk;Z1N(n,(T0*)C,a1);R=((T0*)n);}return R;}T0*Z2N(Zc1*C,T0*a1){
T0*R=Zo;R=Z3N(((C)->ZFc),a1);return R;}void Z4N(Zc1*C){if((((C)->Z_b))!=((void*)(Zo))){ZyH(((C)->Z_b));}ZzH(((C)->ZYb));if((((C)->ZAb))!=((void*)(Zo))){
ZAH((Zm3*)(((C)->ZAb)));}}T76 ZPM(Zc1*C){T76 R={Zo,Zo,0};R=(((ZB8*)(((C)->ZZb)))->Zxb);return R;}void Z5N(Zg1*C,T0*a1){ZXw(((T7*)a1),Z6N);
ZQs(Z7N(C),a1);}void Z8N(T0*a1){ZXw(((T7*)a1),Z9N);ZZs(((T7*)a1),((T3)'\052'));}T0*ZaN(Zg1*C){T0*R=Zo;R=ZbN(((C)->ZLc));return R;}T0*ZcN=Zo;
T6 ZdN(Zg1*C){T6 R=0;R=((T6)(ZeN(((C)->ZLc))));return R;}T6 ZfN(Zg1*C){T6 R=0;R=((T6)(ZgN(((C)->ZLc))));return R;}T2 ZhN(void){T2 R=0;
R=(Z3)(((sizeof(T1)))+((Z3)(((Zrs(2)))*(sizeof(T8)))));return R;}void ZiN(Zg1*C,T0*a1){ZXw(((T7*)a1),ZjN);ZQs(Z7N(C),a1);}void ZkN(T76
a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T6 ZlN(void){T6 R=0;return R;}void ZmN(Zg1*C){T0*_rc=Zo;T2 ZnN=0;T6
ZoN=0;_rc=ZpN(C);ZnN=((((Ze4*)_rc))->_id);ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));ZXw((T7*)(ZqN),ZrN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZsN);
ZBw((T7*)(ZcN),ZtN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZuN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZvN);Z5N(C,ZcN);ZXw((T7*)(ZcN),ZwN);(((void)((Zh8*)(ZxN()))),ZyN(ZcN,ZzN,ZpN(C)));
ZXw((T7*)(ZcN),ZAN);ZBN(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZBN(C,ZcN);ZXw((T7*)(ZcN),ZCN);(((void)((Zh8*)(ZxN()))),ZyN(ZcN,ZDN,ZpN(C)));ZXw((T7*)(ZcN),ZEN);
ZBN(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZBN(C,ZcN);ZXw((T7*)(ZcN),ZFN);ZGN((Zi4*)(ZsG),ZqN,ZcN);ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));
ZHN(C,ZqN);ZXw((T7*)(ZqN),ZIN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZJN);((((T7*)((T7*)(ZcN))))->Zcc)=(Zrs(0));ZoN=((T6)((T6)((ZKN(((Ze4*)_rc)))&&((T6)((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2))))))));
if(ZoN){ZXw((T7*)(ZcN),ZLN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZMN);}ZNN(((Ze4*)_rc),(T6)(0),ZcN);if(ZoN){ZXw((T7*)(ZcN),ZON);}ZGN((Zi4*)(ZsG),ZqN,ZcN);
ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));ZPN(C,ZqN);ZXw((T7*)(ZqN),ZQN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZRN);((((T7*)((T7*)(ZcN))))->Zcc)=(Zrs(0));
ZSN(((Ze4*)_rc),ZcN);ZGN((Zi4*)(ZsG),ZqN,ZcN);ZBw((T7*)(ZqN),ZTN);ZQs(ZnN,ZqN);ZBw((T7*)(ZcN),ZUN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZVN);ZQs(ZnN,ZcN);
ZXw((T7*)(ZcN),ZWN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZXN);ZYN((Zi4*)(ZsG),ZqN,ZcN);((((T7*)((T7*)(ZqN))))->Zcc)=(Zrs(0));ZZs((T7*)(ZqN),((T3)'T'));
ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));ZXw((T7*)(ZqN),ZZN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),Z_N);ZBw((T7*)(ZcN),Z0O);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),Z1O);
if((((Zh8*)(ZxN()))->ZEk)){Z2O(C,ZcN);ZXw((T7*)(ZcN),Z3O);}ZXw((T7*)(ZcN),Z4O);Z5O(C,ZcN);ZXw((T7*)(ZcN),Z6O);Z5O(C,ZcN);ZXw((T7*)(ZcN),Z7O);
Z5N(C,ZcN);ZXw((T7*)(ZcN),Z8O);ZBN(C,ZcN);ZXw((T7*)(ZcN),Z9O);ZBN(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZBN(C,ZcN);ZXw((T7*)(ZcN),ZaO);Z5O(C,ZcN);
ZXw((T7*)(ZcN),ZbO);Z5O(C,ZcN);ZXw((T7*)(ZcN),ZcO);ZiN(C,ZcN);ZXw((T7*)(ZcN),ZdO);Z5N(C,ZcN);ZXw((T7*)(ZcN),ZeO);ZBN(C,ZcN);ZXw((T7*)(ZcN),ZfO);
ZBN(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZBN(C,ZcN);ZXw((T7*)(ZcN),ZgO);ZiN(C,ZcN);ZXw((T7*)(ZcN),ZhO);ZiN(C,ZcN);ZXw((T7*)(ZcN),ZiO);ZQs(ZnN,ZcN);
ZXw((T7*)(ZcN),Z8M);Z5N(C,ZcN);ZXw((T7*)(ZcN),ZjO);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZkO);ZiN(C,ZcN);ZXw((T7*)(ZcN),ZlO);Z5O(C,ZcN);ZXw((T7*)(ZcN),ZiO);
ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZmO);Z5N(C,ZcN);ZXw((T7*)(ZcN),ZnO);ZXw((T7*)(ZcN),ZoO);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),Z8M);ZXw((T7*)(ZcN),ZpO);
ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZqO);ZGN((Zi4*)(ZsG),ZqN,ZcN);}void ZrO(Zg1*C){T0*_rc=Zo;T2 ZnN=0;_rc=ZpN(C);ZnN=((((Ze4*)_rc))->_id);ZBw((T7*)(ZqN),ZsO);
ZXw((T7*)(ZqN),ZtO);ZZs((T7*)(ZqN),((T3)'\040'));ZZs((T7*)(ZqN),((T3)'B'));ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\040'));ZXw((T7*)(ZqN),Z0O);
ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),Z8M);ZXw((T7*)(ZqN),ZtO);ZZs((T7*)(ZqN),((T3)'\040'));ZZs((T7*)(ZqN),((T3)'B'));ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZuO);
ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZvO);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZwO);Z7I((Zi4*)(ZsG),ZqN);ZBw((T7*)(ZqN),Z0O);ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));
Z5N(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);ZBw((T7*)(ZqN),ZyO);ZZs((T7*)(ZqN),((T3)'\040'));Z5O(C,ZqN);ZzO((Zi4*)(ZsG),ZqN,((T3)'0'));ZBw((T7*)(ZqN),ZAO);
ZiN(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);ZBw((T7*)(ZqN),Z0O);ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));ZBN(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);
if((((Zh8*)(ZxN()))->ZEk)){ZBw((T7*)(ZqN),ZyO);ZZs((T7*)(ZqN),((T3)'\040'));Z2O(C,ZqN);ZzO((Zi4*)(ZsG),ZqN,((T3)'0'));}}T6 ZBO(Zg1*C){
T6 R=0;T0*ZCO=Zo;ZCO=Zo;R=((T6)((ZCO)!=((void*)(Zo))));return R;}void ZHN(Zg1*C,T0*a1){ZXw(((T7*)a1),ZDO);ZQs(Z7N(C),a1);}T6 ZEO(Zg1*C){
T6 R=0;T0*_rt=Zo;if((((C)->ZNc))!=(Zo)){_rt=((C)->ZNc);if((C)==((void*)(_rt))){if((ZvG(_rt))==((void*)(_rt))){R=((T6)((ZFO(_rt))==((void*)(ZDF(_rt)))));
}}}return R;}T6 ZGO(Zg1*C){T6 R=0;R=((T6)(ZHO(((C)->ZLc))));return R;}T2 Z7N(Zg1*C){T2 R=0;R=(((Ze4*)(ZpN(C)))->_id);return R;}void ZIO(Zg1*C){
((((T7*)((T7*)(ZJO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZJO),((T3)'\050'));ZKO(C,ZJO);ZZs((T7*)(ZJO),((T3)'\051'));Z7I((Zi4*)(ZsG),ZJO);}void
ZLO(Zg1*C,T0*a1){ZXw(((T7*)a1),ZMO);Z2O(C,a1);ZXw(((T7*)a1),ZNO);ZXw(((T7*)a1),((C)->ZMc));ZXw(((T7*)a1),ZOO);Z2O(C,a1);ZZs(((T7*)a1),((T3)'\054'));
Z5O(C,a1);ZXw(((T7*)a1),ZPO);}void ZQO(Zg1*C,T0*a1,T0*a2){(C->Zxb)=((((Zg1*)a1))->Zxb);(C->ZKc)=((((Zg1*)a1))->ZKc);(C->ZLc)=a2;if(Z2H(((C)->ZLc))){
(C->ZMc)=ZDF(((C)->ZLc));(C->ZNc)=((C)->ZLc);}else{(C->ZMc)=ZRO(ZDF(((C)->ZLc)));(C->ZNc)=((T0*)(C));}}T6 ZSO(Zg1*C){T6 R=0;R=((T6)(ZTO(((C)->ZLc))));
return R;}T6 ZUO(Zg1*C){T6 R=0;R=((T6)(ZVO(((C)->ZLc))));return R;}void ZWO(Zg1*C){T2 ZXO=0;ZXO=Z7N(C);((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));
ZXw((T7*)(ZYO),ZsO);ZXw((T7*)(ZYO),ZtO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'S'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\040'));
ZZs((T7*)(ZYO),((T3)'T'));ZQs(ZXO,ZYO);ZXw((T7*)(ZYO),Z8M);Z7I((Zi4*)(ZsG),ZYO);}T0*ZYO=Zo;T6 ZZO(Zg1*C,T0*a1){T6 R=0;R=((T6)(Z_O(((C)->ZLc),a1)));
return R;}T6 Z0P(Zg1*C){T6 R=0;R=((T6)(Z1P(((C)->ZLc))));return R;}void ZWI(Zg1*C,T76 a1,T0*a2){(C->Zxb)=a1;(C->ZLc)=a2;(C->ZKc)=ZRO(ZFO(((C)->ZLc)));
}T0*Z2P(Zg1*C){T0*R=Zo;R=Z3P(((C)->ZLc));return R;}void Z4P(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}T6 Z5P(Zg1*C){T6 R=0;
R=((T6)(Z6P(((C)->ZLc))));return R;}T8 Z7P(void){T8 R=Zo;return R;}T0*ZxN(void){if(ZDI==0){ZDI=1;{{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZGk;
ZCI=((T0*)n);}}}return ZCI;}T6 Z8P(Zg1*C){T6 R=0;R=((T6)(Z9P(((C)->ZLc))));return R;}T0*ZaP=Zo;int ZbP=0;T0*ZcP(void){if(ZbP==0){ZbP=1;{
{T26*n=((T26*)Zh(1));ZaP=((T0*)n);ZdP(ZeP);ZdP(ZfP);ZdP(ZgP);ZdP(ZhP);ZdP(ZiP);ZdP(ZjP);ZdP(ZkP);ZdP(ZlP);ZdP(ZmP);ZdP(ZnP);ZdP(ZoP);
ZdP(ZpP);ZdP(ZqP);ZdP(ZrP);ZdP(ZpK);ZdP(ZsP);ZdP(ZtP);ZdP(ZuP);ZdP(ZvP);ZdP(ZwP);ZdP(ZxP);ZdP(ZyP);ZdP(ZzP);ZdP(ZAP);ZdP(ZBP);ZdP(ZCP);
ZdP(ZDP);ZdP(ZEP);ZdP(ZFP);ZdP(ZGP);ZdP(ZHP);ZdP(ZIP);ZdP(ZJP);ZdP(ZKP);ZdP(ZLP);ZdP(ZMP);ZdP(ZNP);ZdP(ZOP);ZdP(ZPP);ZdP(ZQP);ZdP(ZRP);
ZdP(ZSP);ZdP(ZTP);ZdP(ZUP);ZdP(ZVP);ZdP(ZWP);ZdP(ZXP);ZdP(ZYP);ZdP(ZZP);ZdP(Z_P);ZdP(Z0Q);ZdP(Z1Q);ZdP(Z2Q);ZdP(Z3Q);ZdP(Z4Q);ZdP(Z5Q);
ZdP(Z6Q);ZdP(Z7Q);ZdP(Z8Q);ZdP(Z9Q);ZdP(ZaQ);ZdP(ZbQ);ZdP(ZcQ);ZdP(ZdJ);ZdP(ZdQ);ZdP(ZeQ);ZdP(ZfQ);ZdP(ZgQ);ZdP(ZhQ);ZdP(ZiQ);ZdP(ZjQ);
ZdP(ZkQ);ZdP(ZlQ);ZdP(ZmQ);ZdP(ZnQ);ZdP(ZoQ);ZdP(ZpQ);ZdP(ZqQ);ZdP(ZDG);ZdP(ZrQ);ZdP(ZsQ);ZdP(ZtQ);ZdP(ZuQ);ZdP(ZvQ);ZdP(ZwQ);ZdP(ZxQ);
ZdP(ZyQ);ZdP(ZzQ);ZdP(ZAQ);ZdP(ZBQ);ZdP(ZCQ);ZdP(ZDQ);ZdP(ZEQ);ZdP(ZFQ);ZdP(ZGQ);ZdP(ZHQ);ZdP(ZIQ);ZdP(ZJQ);ZdP(ZKQ);ZdP(ZLQ);ZdP(ZMQ);
ZdP(ZNQ);ZdP(ZOQ);ZdP(ZPQ);ZdP(ZQQ);ZdP(ZRQ);ZdP(ZSQ);ZdP(ZTQ);ZdP(ZUQ);ZdP(ZVQ);ZdP(ZWQ);ZdP(ZXQ);ZdP(ZYQ);ZdP(ZZQ);ZdP(Z_Q);ZdP(Z0R);
ZdP(Z1R);ZdP(Z2R);ZdP(Z3R);ZdP(Z4R);ZdP(Z5R);ZdP(Z6R);ZdP(Z7R);ZdP(Z8R);ZdP(Z9R);ZdP(ZaR);ZdP(ZbR);ZdP(ZcR);ZdP(ZdR);ZdP(ZeR);ZdP(ZfR);
ZdP(ZgR);ZdP(ZhR);ZdP(ZiR);ZdP(ZjR);ZdP(ZkR);ZdP(ZlR);ZdP(ZmR);ZdP(ZnR);ZdP(ZoR);ZdP(ZpR);ZdP(ZqR);ZdP(ZrR);ZdP(ZsR);ZdP(ZtR);ZdP(ZuR);
ZdP(ZvR);ZdP(ZwR);ZdP(ZxR);ZdP(ZyR);ZdP(ZzR);ZdP(ZAR);ZdP(ZBR);ZdP(ZCR);ZdP(ZDR);ZdP(ZER);ZdP(ZFR);ZdP(ZGR);ZdP(ZHR);ZdP(ZIR);ZdP(ZJR);
ZdP(ZKR);ZdP(ZLR);ZdP(ZMR);ZdP(ZNR);ZdP(ZOR);ZdP(ZPR);ZdP(ZQR);ZdP(ZRR);ZdP(ZSR);ZdP(ZTR);ZdP(ZUR);ZdP(ZVR);ZdP(ZWR);ZdP(ZXR);ZdP(ZYR);
ZdP(ZZR);ZdP(Z_R);ZdP(Z0S);ZdP(Z1S);ZdP(Z2S);ZdP(Z3S);ZdP(Z4S);ZdP(Z5S);ZdP(Z6S);ZdP(Z7S);ZdP(Z8S);ZdP(Z9S);ZdP(ZaS);ZdP(ZbS);ZdP(ZcS);
ZdP(ZdS);ZdP(ZeS);ZdP(ZfS);ZdP(ZgS);ZdP(ZhS);ZdP(ZiS);ZdP(ZjS);ZdP(ZkS);ZdP(ZlS);ZdP(ZmS);ZdP(ZnS);ZdP(ZoS);}}}return ZaP;}T0*ZpS(Zg1*C){
T0*R=Zo;T0*ZqS=Zo;if((((C)->ZIc))!=((void*)(Zo))){R=((C)->ZIc);}else{ZqS=Z2P(C);if((ZqS)!=((void*)(Zo))){(C->ZIc)=ZrS(((T80*)ZqS));R=((C)->ZIc);
}else{{T0*b1=ZvF(27,"Cannot find Base Class for ");ZXw((T7*)(ZwF),b1);}ZsS((T0*)C,ZMJ);ZEF((T75*)(ZyF));}}return R;}T0*ZtS(T76 a1){T0*R=Zo;
{ZH4*n=((ZH4*)Zh(sizeof(*n)));*n=Zyg;((((ZH4*)(n)))->Zxb)=(a1);R=((T0*)n);}return R;}void ZuS(Zg1*C,T0*a1){ZZs(((T7*)a1),((T3)'\045'));
ZZs(((T7*)a1),((T3)'R'));ZQs(Z7N(C),a1);ZZs(((T7*)a1),((T3)'\045'));}void ZvS(Zg1*C){if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZwS((Ze4*)(ZpN(C)));
}}T0*ZJO=Zo;T6 ZxS(Zg1*C){T6 R=0;T0*ZyS=Zo;ZyS=Zo;R=((T6)((ZyS)!=((void*)(Zo))));return R;}void ZKO(Zg1*C,T0*a1){ZZs(((T7*)a1),((T3)'T'));
ZQs(Z7N(C),a1);ZZs(((T7*)a1),((T3)'\052'));}T0*ZRO(T0*a1){T0*R=Zo;ZBw((T7*)(ZYO),ZzS);ZZs((T7*)(ZYO),((T3)'\040'));ZXw((T7*)(ZYO),a1);
R=(((void)((T26*)(ZcP()))),ZAS(ZYO));return R;}void ZBN(Zg1*C,T0*a1){ZXw(((T7*)a1),ZBS);ZQs(Z7N(C),a1);}void ZCS(Zg1*C){T2 ZXO=0;T0*_rc=Zo;
_rc=ZpN(C);ZXO=((((Ze4*)_rc))->_id);((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZYO),((T3)'T'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\040'));
ZZs((T7*)(ZYO),((T3)'M'));ZQs(ZXO,ZYO);ZDS((Zi4*)(ZsG),ZYO);ZES((Zi4*)(ZsG));((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZYO),((T3)'\173'));
ZQs(Z7N(C),ZYO);ZXw((T7*)(ZYO),ZFS);ZXw((T7*)(ZYO),Z8M);Z7I((Zi4*)(ZsG),ZYO);ZGS((Zi4*)(ZsG));}void ZPN(Zg1*C,T0*a1){ZXw(((T7*)a1),ZHS);
ZQs(Z7N(C),a1);}T0*ZIS(T0*a1,T0*a2){T0*R=Zo;{Zg1*n=((Zg1*)Zh(sizeof(*n)));*n=ZOc;ZQO(n,a1,a2);R=((T0*)n);}return R;}void ZJS(Zg1*C){T0*_wa=Zo;
T2 ZXO=0;ZXO=Z7N(C);_wa=ZKS((Ze4*)(ZpN(C)));ZBw((T7*)(ZYO),ZtO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'S'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\173'));
if(ZKN((Ze4*)(ZpN(C)))){ZXw((T7*)(ZYO),ZLS);}ZXw((T7*)(ZYO),ZMS);ZNS(((C)->ZLc),ZYO);ZXw((T7*)(ZYO),ZOS);ZXw((T7*)(ZYO),Z8M);Z7I((Zi4*)(ZsG),ZYO);
}T6 ZPS(Zg1*C){T6 R=0;R=((T6)(ZQS(((C)->ZLc))));return R;}T6 ZRS(Zg1*C){T6 R=0;R=((T6)(ZSS(((C)->ZLc))));return R;}void ZTS(T0*a1){ZUS(a1,ZVS);
ZUS(a1,ZWS);ZXS(a1,((T3)'\n'));}T6 ZYS(Zg1*C,T0*a1){T6 R=0;if(Z2H(a1)){R=((T6)((T6)(((((C)->ZLc))==((void*)(a1)))||((T6)(ZYF(((C)->ZLc),a1))))));
}if(!(R)){ZZS((T0*)C,a1);}return R;}T0*Z_S(Zg1*C){T0*R=Zo;if(!(ZMF(&(((C)->Zxb))))){R=Z0T(&(((C)->Zxb)));}return R;}T6 Z1T(Zg1*C){T6 R=0;
R=((T6)(Z2T(((C)->ZLc))));return R;}T0*Z3T(Zg1*C,T0*a1){T0*R=Zo;T0*_m=Zo;if((((T82*)(ZbK(((C)->ZLc))))->Zfg)){ZkN(((C)->Zxb),Z4T);}else
if(Z5T(((C)->ZLc))){ZkN(((C)->Zxb),Z6T);}Z7T((T82*)(ZbK(((C)->ZLc))));if((((C)->ZNc))==((void*)(C))){R=((T0*)(C));}else if((((C)->ZNc))==((void*)(((C)->ZLc)))){
R=((T0*)(C));}else{_m=Z9L(((C)->ZLc),a1);if((_m)==((void*)(Zo))){ZzF(((C)->Zxb));Z4P(ZvF(26,"Bad outside separate type."));}if((((C)->ZNc))!=((void*)(Zo))){
R=ZIS((T0*)C,ZvG(_m));}else if(Z2H(_m)){(C->ZNc)=_m;(C->ZMc)=ZDF(_m);R=((T0*)(C));}else if((((C)->ZLc))==((void*)(ZvG(_m)))){(C->ZMc)=ZRO(ZDF(_m));
(C->ZNc)=((T0*)(C));R=((T0*)(C));}else{(C->ZMc)=ZRO(ZDF(_m));(C->ZNc)=ZIS((T0*)C,ZvG(_m));R=((T0*)(C));}ZeL((Ze4*)(Z8G(((C)->ZLc))));
ZeL((Ze4*)(Z8G(((((Zg1*)R))->ZNc))));}return R;}T0*Z8T(Zg1*C){T0*R=Zo;T0*Z9T=Zo;Z9T=Z2P(C);if((Z9T)!=((void*)(Zo))){R=ZrS(((T80*)Z9T));
}return R;}T6 ZaT(Zg1*C){T6 R=0;R=((T6)(ZbT(((C)->ZLc))));return R;}void Z5O(Zg1*C,T0*a1){ZXw(((T7*)a1),ZcT);ZQs(Z7N(C),a1);}T0*ZpN(Zg1*C){
T0*R=Zo;if((((C)->ZJc))!=((void*)(Zo))){R=((C)->ZJc);}else if((((C)->ZNc))!=(Zo)){(C->ZJc)=ZdT(((C)->ZNc));R=((C)->ZJc);}return R;}void
ZeT(Zg1*C){if((((C)->ZNc))==((void*)(C))){ZJS(C);}else{ZfT(((C)->ZNc));}ZCS(C);}void ZgT(Zg1*C,T0*a1){ZBN(C,a1);ZZs(((T7*)a1),((T3)'\075'));
ZXw(((T7*)a1),ZxO);ZXw(((T7*)a1),Z8M);}T0*ZhT(Zg1*C,T0*a1){T0*R=Zo;if((((C)->ZMc))==((void*)(ZDF(a1)))){R=((C)->ZNc);}else{R=ZvG(ZiT(((C)->ZLc),a1));
}return R;}void Z2O(Zg1*C,T0*a1){ZXw(((T7*)a1),ZjT);ZQs(Z7N(C),a1);}void ZkT(Zg1*C,T0*a1){ZXw(((T7*)a1),ZZN);ZQs(Z7N(C),a1);ZZs(((T7*)a1),((T3)'\050'));
ZZs(((T7*)a1),((T3)'\051'));}T0*ZqN=Zo;void ZlT(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}void ZmT(Zk1*C,T2
a1,T0*a2,T0*a3){T0*ZnT=Zo;T0*ZoT=Zo;T0*ZpT=Zo;T0*ZqT=Zo;(C->ZSb)=ZjG(((C)->ZSb));(C->ZRb)=ZjG(((C)->ZRb));if((a2)!=((void*)(Zo))){ZnT=((C)->ZSb);
if(Zo!=(ZnT)){switch(((T0*)ZnT)->id){case 307:break;default:ZnT=Zo;}}ZoT=((C)->ZRb);if(Zo!=(ZoT)){switch(((T0*)ZoT)->id){case 307:break;
default:ZoT=Zo;}}if((T6)(((ZnT)!=((void*)(Zo)))&&((T6)((ZoT)!=((void*)(Zo)))))){if(Zls(((((ZN4*)a2))->Zde),((((ZN4*)ZnT))->Zde),((((ZN4*)ZoT))->Zde))){
ZrT((ZT4*)(((C)->ZPc)),a1);}}}else if((a3)!=((void*)(Zo))){ZpT=((C)->ZSb);if(Zo!=(ZpT)){switch(((T0*)ZpT)->id){case 249:break;default:
ZpT=Zo;}}ZqT=((C)->ZRb);if(Zo!=(ZqT)){switch(((T0*)ZqT)->id){case 249:break;default:ZqT=Zo;}}if((T6)(((ZpT)!=((void*)(Zo)))&&((T6)((ZqT)!=((void*)(Zo)))))){
if(Z7t(((((Zs1*)a3))->ZEl),((((Zs1*)ZpT))->ZEl),((((Zs1*)ZqT))->ZEl))){ZrT((ZT4*)(((C)->ZPc)),a1);}}}}void ZsT(Zk1*C,T0*a1,T0*a2){(C->ZSb)=a1;
(C->ZRb)=a2;}void ZtT(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}T0*ZuT(T0*a1){T0*R=Zo;ZtT(ZvF(107,"Unexpected runnable slice with string. This message should not appear: please contact the SmartEiffel team."));
return R;}T0*ZvT(Zk1*C,T0*a1){T0*R=Zo;T0*_ct=Zo;T0*_v=Zo;if((((C)->ZPc))==((void*)(Zo))){(C->ZPc)=a1;_ct=(((ZS7*)(ZWG()))->Z0c);_v=ZFG(((C)->ZSb),_ct);
if((T6)(((_v)!=((void*)(Zo)))&&((T6)(Z6P(ZOG(_v)))))){(C->ZSb)=_v;(C->ZQc)=ZwT(((C)->ZSb));}else{{T76 Z3w;ZlT((*(Z3w=ZGG(((C)->ZSb)),&Z3w)),ZxT);
}}_v=ZFG(((C)->ZRb),_ct);if((T6)(((_v)!=((void*)(Zo)))&&((T6)(Z6P(ZOG(_v)))))){(C->ZRb)=_v;(C->ZRc)=ZwT(((C)->ZRb));}else{{T76 Z3w;ZlT((*(Z3w=ZGG(((C)->ZRb)),&Z3w)),ZxT);
}}ZyT((ZT4*)(((C)->ZPc)),(T0*)C);R=((T0*)(C));}else{{Zk1*n=((Zk1*)Zh(sizeof(*n)));*n=ZSc;ZsT(n,((C)->ZSb),((C)->ZRb));R=((T0*)n);}R=ZvT(((Zk1*)R),a1);
}return R;}void ZzT(Zk1*C,T0*a1){T6 Z_M=0;if((((C)->ZSb))!=((void*)(Zo))){Z_M=((T6)(Z3H(((C)->ZSb),a1)));}if((((C)->ZRb))!=((void*)(Zo))){
Z_M=((T6)(Z3H(((C)->ZRb),a1)));}}T0*ZAT(Zk1*C,T0*a1){T0*R=Zo;T0*_ct=Zo;T0*_v=Zo;if((((C)->ZPc))==((void*)(Zo))){(C->ZPc)=a1;_ct=(((ZS7*)(ZWG()))->Z0c);
_v=ZFG(((C)->ZSb),_ct);if((T6)(((_v)!=((void*)(Zo)))&&((T6)(Z1P(ZOG(_v)))))){(C->ZSb)=_v;(C->ZQc)=ZwT(((C)->ZSb));}else{{T76 Z3w;ZlT((*(Z3w=ZGG(((C)->ZSb)),&Z3w)),ZBT);
}}_v=ZFG(((C)->ZRb),_ct);if((T6)(((_v)!=((void*)(Zo)))&&((T6)(Z1P(ZOG(_v)))))){(C->ZRb)=_v;(C->ZRc)=ZwT(((C)->ZRb));}else{{T76 Z3w;ZlT((*(Z3w=ZGG(((C)->ZRb)),&Z3w)),ZBT);
}}ZyT((ZT4*)(((C)->ZPc)),(T0*)C);R=((T0*)(C));}else{{Zk1*n=((Zk1*)Zh(sizeof(*n)));*n=ZSc;ZsT(n,((C)->ZSb),((C)->ZRb));R=((T0*)n);}R=ZAT(((Zk1*)R),a1);
}return R;}T0*ZCT(Zk1*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zk1*)R)=*C;return R;}T76 ZDT(Zk1*C){T76 R={Zo,Zo,0};{T76 Z3w;R=(*(Z3w=ZGG(((C)->ZSb)),&Z3w));
}return R;}void ZET(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}void ZFT(Zm1*C,T2 a1,T0*a2,T0*a3){T0*ZGT=Zo;
T0*ZuJ=Zo;(C->ZTc)=ZjG(((C)->ZTc));if((a2)!=((void*)(Zo))){ZGT=((C)->ZTc);if(Zo!=(ZGT)){switch(((T0*)ZGT)->id){case 307:break;default:
ZGT=Zo;}}if((ZGT)!=((void*)(Zo))){if((((((ZN4*)a2))->Zde))==(((((ZN4*)ZGT))->Zde))){ZrT((ZT4*)(((C)->ZPc)),a1);}}}else if((a3)!=((void*)(Zo))){
ZuJ=((C)->ZTc);if(Zo!=(ZuJ)){switch(((T0*)ZuJ)->id){case 249:break;default:ZuJ=Zo;}}if((ZuJ)!=((void*)(Zo))){if((((((Zs1*)a3))->ZEl))==(((((Zs1*)ZuJ))->ZEl))){
ZrT((ZT4*)(((C)->ZPc)),a1);}}}}T0*ZHT(Zm1*C,T0*a1){T0*R=Zo;T0*_ct=Zo;T0*_e=Zo;if((((C)->ZPc))==((void*)(Zo))){(C->ZPc)=a1;_ct=(((ZS7*)(ZWG()))->Z0c);
_e=ZFG(((C)->ZTc),_ct);if((T6)(((_e)!=((void*)(Zo)))&&((T6)(ZIT(_e))))){(C->ZTc)=_e;ZJT((ZT4*)(((C)->ZPc)),(T0*)C);}else{{T76 Z3w;ZET((*(Z3w=ZGG(((C)->ZTc)),&Z3w)),ZBT);
}}R=((T0*)(C));}else{{Zm1*n=((Zm1*)Zh(sizeof(*n)));*n=ZVc;((((Zm1*)(n)))->ZTc)=(((C)->ZTc));R=((T0*)n);}R=ZHT(((Zm1*)R),a1);}return R;
}T0*ZKT(Zm1*C,T0*a1){T0*R=Zo;T0*_ct=Zo;T0*_e=Zo;if((((C)->ZPc))==((void*)(Zo))){(C->ZPc)=a1;_ct=(((ZS7*)(ZWG()))->Z0c);_e=ZFG(((C)->ZTc),_ct);
if((T6)(((_e)!=((void*)(Zo)))&&((T6)(Z6P(ZOG(_e)))))){(C->ZTc)=_e;(C->ZUc)=ZwT(((C)->ZTc));ZJT((ZT4*)(((C)->ZPc)),(T0*)C);}else{{T76 Z3w;
ZET((*(Z3w=ZGG(((C)->ZTc)),&Z3w)),ZxT);}}R=((T0*)(C));}else{{Zm1*n=((Zm1*)Zh(sizeof(*n)));*n=ZVc;((((Zm1*)(n)))->ZTc)=(((C)->ZTc));R=((T0*)n);
}R=ZKT(((Zm1*)R),a1);}return R;}void ZLT(Zm1*C,T0*a1){T6 Z_M=0;if((((C)->ZTc))!=((void*)(Zo))){Z_M=((T6)(Z3H(((C)->ZTc),a1)));}}T0*ZMT(Zm1*C,T0*a1){
T0*R=Zo;T0*_ct=Zo;T0*_e=Zo;if((((C)->ZPc))==((void*)(Zo))){(C->ZPc)=a1;_ct=(((ZS7*)(ZWG()))->Z0c);_e=ZFG(((C)->ZTc),_ct);if((T6)(((_e)!=((void*)(Zo)))&&((T6)(Z1P(ZOG(_e)))))){
(C->ZTc)=_e;(C->ZUc)=ZwT(((C)->ZTc));ZJT((ZT4*)(((C)->ZPc)),(T0*)C);}else{{T76 Z3w;ZET((*(Z3w=ZGG(((C)->ZTc)),&Z3w)),ZBT);}}R=((T0*)(C));
}else{{Zm1*n=((Zm1*)Zh(sizeof(*n)));*n=ZVc;((((Zm1*)(n)))->ZTc)=(((C)->ZTc));R=((T0*)n);}R=ZMT(((Zm1*)R),a1);}return R;}T0*ZNT(Zm1*C){
T0*R=Zo;R=Zh(sizeof(*C));*((Zm1*)R)=*C;return R;}T76 ZOT(Zm1*C){T76 R={Zo,Zo,0};{T76 Z3w;R=(*(Z3w=ZGG(((C)->ZTc)),&Z3w));}return R;}void
ZPT(Zo1*C,T0*a1){T2 ZSb=0;if((Z3)(((Z3)((((((Zg9*)(((C)->ZUb)))->ZRb)))+(Zrs(1))))>(Zrs(1)))){ZsS(a1,ZQT);ZSb=Zrs(0);ZzF((((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[ZSb]))->Zxb));
ZSb=(Z3)(((ZSb))+(Zrs(1)));ZzF((((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[ZSb]))->Zxb));{T0*b1=ZvF(106,"Expanded class must have no creation procedure, or only one creation procedure with no arguments (VTEC.2).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}ZRT((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[Zrs(0)]),a1);}T0*ZST(Zo1*C){T0*R=Zo;T2 _i=0;_i=(((Zg9*)(((C)->ZUb)))->ZRb);
while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((_i)<(Zrs(0)))))))){R=ZTT((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[_i]));if((R)!=((void*)(ZkR))){
R=Zo;}_i=(Z3)(((_i))-(Zrs(1)));}_i=Zrs(0);while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((_i)>((((Zg9*)(((C)->ZUb)))->ZRb)))))))){R=ZTT((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[_i]));
_i=(Z3)(((_i))+(Zrs(1)));}return R;}void ZUT(Zo1*C,T0*a1){{Zg9*n=((Zg9*)Zh(sizeof(*n)));*n=ZSl;Z1B(n,(T2)(Zrs(4)));(C->ZUb)=((T0*)n);
}Z0B((Zg9*)(((C)->ZUb)),a1);}T0*ZVT(Zo1*C,T0*a1){T0*R=Zo;T2 _i=0;_i=(((Zg9*)(((C)->ZUb)))->ZRb);while(!((T6)(((R)!=((void*)(Zo)))||((T6)((Z3)((_i)<(Zrs(0))))))))
{R=ZWT((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[_i]),a1);_i=(Z3)(((_i))-(Zrs(1)));}return R;}T0*ZXT(Zo1*C,T0*a1){T0*R=Zo;T2 _i=0;_i=(((Zg9*)(((C)->ZUb)))->ZRb);
while(!((T6)(((Z3)((_i)<(Zrs(0))))||((T6)((R)!=((void*)(Zo))))))){R=ZYT((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[_i]),a1);_i=(Z3)(((_i))-(Zrs(1)));
}return R;}T0*ZZT(Zo1*C,T0*a1){T0*R=Zo;T2 _i=0;_i=Zrs(0);while(!((T6)(((Z3)((_i)>((((Zg9*)(((C)->ZUb)))->ZRb))))||((T6)(Z_T((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[_i]),a1))))))
{_i=(Z3)(((_i))+(Zrs(1)));}if((Z3)((_i)<=((((Zg9*)(((C)->ZUb)))->ZRb)))){R=((((Zg9*)(((C)->ZUb)))->ZPb))[_i];}return R;}T76 Z0U(Zo1*C){
T76 R={Zo,Zo,0};R=(((ZW1*)(((((Zg9*)(((C)->ZUb)))->ZPb))[Zrs(0)]))->Zxb);return R;}T2 Z1U(Zw1*C){T2 R=0;T0*ZUb=Zo;ZUb=(((ZA5*)(((C)->Z_c)))->ZUb);
if((ZUb)!=((void*)(Zo))){R=(Z3)(((((((ZB4*)ZUb))->ZRb)))+(Zrs(1)));}return R;}void Z2U(Zw1*C){T2 _i=0;T0*ZUb=Zo;T0*_e=Zo;ZUb=(((ZA5*)(((C)->Z_c)))->ZUb);
if((ZUb)!=((void*)(Zo))){while(!((Z3)((_i)>(((((ZB4*)ZUb))->ZRb))))){_e=(((((ZB4*)ZUb))->ZPb))[_i];Z3U(_e,ZOG(_e));if((Z3)((_i)<(((((ZB4*)ZUb))->ZRb)))){
ZcH((Zi4*)(ZsG),((T3)'\054'));}_i=(Z3)(((_i))+(Zrs(1)));}}}T6 Z4U(T0*a1){T6 R=0;return R;}void Z5U(Zw1*C,T0*a1,T2 a2){T0*ZUb=Zo;ZUb=(((ZA5*)(((C)->Z_c)))->ZUb);
(((((ZB4*)ZUb))->ZPb))[(Z3)(((a2))-((T2)(Zrs(1))))]=(a1);}void Z6U(Zw1*C){{T76 Z3w;ZzF((*(Z3w=Z7U(C),&Z3w)));}{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void Z8U(Zw1*C){{T0*b1=ZIG;ZXw((T7*)(ZwF),b1);}{T76 Z3w;ZzF((*(Z3w=Z7U(C),&Z3w)));}ZxF((T75*)(ZyF));
}T0*Z9U(Zw1*C,T2 a1){T0*R=Zo;T0*ZUb=Zo;ZUb=(((ZA5*)(((C)->Z_c)))->ZUb);R=(((((ZB4*)ZUb))->ZPb))[(Z3)(((a1))-(Zrs(1)))];return R;}T6 ZaU(T0*a1){
T6 R=0;return R;}T2 ZbU(Zw1*C){T2 R=0;Z8U(C);return R;}T0*ZcU(Zw1*C,T0*a1){T0*R=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;(C->Z_c)=ZdU((ZA5*)(((C)->Z_c)),a1);
R=((T0*)(C));}else{{Zw1*n=((Zw1*)Zh(sizeof(*n)));*n=Z0d;((((Zw1*)(n)))->Z_c)=(((C)->Z_c));R=((T0*)n);}R=ZcU(((Zw1*)R),a1);}return R;}
T76 Z7U(Zw1*C){T76 R={Zo,Zo,0};R=(((ZA5*)(((C)->Z_c)))->Zxb);return R;}void ZeU(ZE1*C,T0*a1){ZXw(((T7*)a1),Z6N);ZQs(ZfU(C),a1);}void ZgU(T0*a1){
ZXw(((T7*)a1),Z9N);ZZs(((T7*)a1),((T3)'\052'));}T0*ZhU(ZE1*C){T0*R=Zo;R=ZbN(((C)->Z2d));return R;}T0*ZiU(ZE1*C){T0*R=Zo;T0*ZjU=Zo;R=((C)->Z3d);
if((R)==((void*)(Zo))){ZjU=ZFO(((C)->Z2d));R=ZkU;ZBw(((T7*)R),ZlU);ZZs(((T7*)R),((T3)'\040'));ZXw(((T7*)R),ZjU);R=(((void)((T26*)(ZmU()))),ZAS(R));
(C->Z3d)=R;}return R;}T0*ZnU(ZE1*C){T0*R=Zo;R=ZFO(ZoU(C));return R;}void ZpU(ZE1*C,T76 a1,T0*a2,T0*a3,T0*a4){(C->Zxb)=a1;(C->Z2d)=a2;
(C->Z3d)=a3;(C->Z4d)=a4;}void ZqU(ZE1*C,T0*a1){ZXw(((T7*)a1),ZjN);ZQs(ZfU(C),a1);}T6 ZrU(void){T6 R=0;return R;}void ZsU(ZE1*C){T0*_rc=Zo;
T2 ZnN=0;T6 ZoN=0;_rc=ZtU(C);ZnN=((((Ze4*)_rc))->_id);ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));ZXw((T7*)(ZqN),ZrN);ZQs(ZnN,ZqN);
ZXw((T7*)(ZqN),ZsN);ZBw((T7*)(ZcN),ZtN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZuN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZvN);ZeU(C,ZcN);ZXw((T7*)(ZcN),ZwN);
(((void)((Zh8*)(ZuU()))),ZyN(ZcN,ZzN,ZtU(C)));ZXw((T7*)(ZcN),ZAN);ZvU(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZvU(C,ZcN);ZXw((T7*)(ZcN),ZCN);(((void)((Zh8*)(ZuU()))),ZyN(ZcN,ZDN,ZtU(C)));
ZXw((T7*)(ZcN),ZEN);ZvU(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZvU(C,ZcN);ZXw((T7*)(ZcN),ZFN);ZGN((Zi4*)(ZsG),ZqN,ZcN);ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));
ZwU(C,ZqN);ZXw((T7*)(ZqN),ZIN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZJN);((((T7*)((T7*)(ZcN))))->Zcc)=(Zrs(0));ZoN=((T6)((T6)((ZKN(((Ze4*)_rc)))&&((T6)((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2))))))));
if(ZoN){ZXw((T7*)(ZcN),ZLN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZMN);}ZNN(((Ze4*)_rc),(T6)(0),ZcN);if(ZoN){ZXw((T7*)(ZcN),ZON);}ZGN((Zi4*)(ZsG),ZqN,ZcN);
ZBw((T7*)(ZqN),Z9N);ZZs((T7*)(ZqN),((T3)'\040'));ZxU(C,ZqN);ZXw((T7*)(ZqN),ZQN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZRN);((((T7*)((T7*)(ZcN))))->Zcc)=(Zrs(0));
ZSN(((Ze4*)_rc),ZcN);ZGN((Zi4*)(ZsG),ZqN,ZcN);ZBw((T7*)(ZqN),ZTN);ZQs(ZnN,ZqN);ZBw((T7*)(ZcN),ZUN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZVN);ZQs(ZnN,ZcN);
ZXw((T7*)(ZcN),ZWN);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZXN);ZYN((Zi4*)(ZsG),ZqN,ZcN);((((T7*)((T7*)(ZqN))))->Zcc)=(Zrs(0));ZZs((T7*)(ZqN),((T3)'T'));
ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));ZXw((T7*)(ZqN),ZZN);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),Z_N);ZBw((T7*)(ZcN),Z0O);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),Z1O);
if((((Zh8*)(ZuU()))->ZEk)){ZyU(C,ZcN);ZXw((T7*)(ZcN),Z3O);}ZXw((T7*)(ZcN),Z4O);ZzU(C,ZcN);ZXw((T7*)(ZcN),Z6O);ZzU(C,ZcN);ZXw((T7*)(ZcN),Z7O);
ZeU(C,ZcN);ZXw((T7*)(ZcN),Z8O);ZvU(C,ZcN);ZXw((T7*)(ZcN),Z9O);ZvU(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZvU(C,ZcN);ZXw((T7*)(ZcN),ZaO);ZzU(C,ZcN);
ZXw((T7*)(ZcN),ZbO);ZzU(C,ZcN);ZXw((T7*)(ZcN),ZcO);ZqU(C,ZcN);ZXw((T7*)(ZcN),ZdO);ZeU(C,ZcN);ZXw((T7*)(ZcN),ZeO);ZvU(C,ZcN);ZXw((T7*)(ZcN),ZfO);
ZvU(C,ZcN);ZXw((T7*)(ZcN),Z8M);ZvU(C,ZcN);ZXw((T7*)(ZcN),ZgO);ZqU(C,ZcN);ZXw((T7*)(ZcN),ZhO);ZqU(C,ZcN);ZXw((T7*)(ZcN),ZiO);ZQs(ZnN,ZcN);
ZXw((T7*)(ZcN),Z8M);ZeU(C,ZcN);ZXw((T7*)(ZcN),ZjO);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZkO);ZqU(C,ZcN);ZXw((T7*)(ZcN),ZlO);ZzU(C,ZcN);ZXw((T7*)(ZcN),ZiO);
ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZmO);ZeU(C,ZcN);ZXw((T7*)(ZcN),ZnO);if(ZAU(C)){ZXw((T7*)(ZcN),ZoO);ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),Z8M);}ZXw((T7*)(ZcN),ZpO);
ZQs(ZnN,ZcN);ZXw((T7*)(ZcN),ZqO);ZGN((Zi4*)(ZsG),ZqN,ZcN);}void ZBU(ZE1*C){T0*_rc=Zo;T2 ZnN=0;_rc=ZtU(C);ZnN=((((Ze4*)_rc))->_id);ZBw((T7*)(ZqN),ZsO);
ZXw((T7*)(ZqN),ZtO);ZZs((T7*)(ZqN),((T3)'\040'));ZZs((T7*)(ZqN),((T3)'B'));ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\040'));ZXw((T7*)(ZqN),Z0O);
ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),Z8M);ZXw((T7*)(ZqN),ZtO);ZZs((T7*)(ZqN),((T3)'\040'));ZZs((T7*)(ZqN),((T3)'B'));ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZuO);
ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZvO);ZQs(ZnN,ZqN);ZXw((T7*)(ZqN),ZwO);Z7I((Zi4*)(ZsG),ZqN);ZBw((T7*)(ZqN),Z0O);ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));
ZeU(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);ZBw((T7*)(ZqN),ZyO);ZZs((T7*)(ZqN),((T3)'\040'));ZzU(C,ZqN);ZzO((Zi4*)(ZsG),ZqN,((T3)'0'));ZBw((T7*)(ZqN),ZAO);
ZqU(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);ZBw((T7*)(ZqN),Z0O);ZQs(ZnN,ZqN);ZZs((T7*)(ZqN),((T3)'\052'));ZvU(C,ZqN);ZYN((Zi4*)(ZsG),ZqN,ZxO);
if((((Zh8*)(ZuU()))->ZEk)){ZBw((T7*)(ZqN),ZyO);ZZs((T7*)(ZqN),((T3)'\040'));ZyU(C,ZqN);ZzO((Zi4*)(ZsG),ZqN,((T3)'0'));}}T6 ZCU(ZE1*C){
T6 R=0;T0*ZCO=Zo;ZCO=Zo;R=((T6)((ZCO)!=((void*)(Zo))));return R;}void ZwU(ZE1*C,T0*a1){ZXw(((T7*)a1),ZDO);ZQs(ZfU(C),a1);}T6 ZDU(ZE1*C){
T6 R=0;T0*_rt=Zo;if(ZEU(C)){_rt=ZoU(C);if((C)==((void*)(_rt))){if((ZvG(_rt))==((void*)(_rt))){R=((T6)((ZFO(_rt))==((void*)(ZDF(_rt)))));
}}}return R;}T2 ZfU(ZE1*C){T2 R=0;R=(((Ze4*)(ZtU(C)))->_id);return R;}T2 ZFU(void){T2 R=0;T8 _p=Zo;R=sizeof(T8);return R;}void ZGU(ZE1*C){
((((T7*)((T7*)(ZJO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZJO),((T3)'\050'));ZHU(C,ZJO);ZZs((T7*)(ZJO),((T3)'\051'));Z7I((Zi4*)(ZsG),ZJO);}void
ZIU(ZE1*C,T0*a1){ZXw(((T7*)a1),ZMO);ZyU(C,a1);ZXw(((T7*)a1),ZNO);ZXw(((T7*)a1),ZnU(C));ZXw(((T7*)a1),ZOO);ZyU(C,a1);ZZs(((T7*)a1),((T3)'\054'));
ZzU(C,a1);ZXw(((T7*)a1),ZPO);}void ZJU(ZE1*C){T2 ZXO=0;ZXO=ZfU(C);((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));if(ZAU(C)){ZXw((T7*)(ZYO),ZsO);
ZXw((T7*)(ZYO),ZtO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'S'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'T'));
ZQs(ZXO,ZYO);ZXw((T7*)(ZYO),Z8M);}else{ZXw((T7*)(ZYO),ZsO);ZXw((T7*)(ZYO),Z9N);ZZs((T7*)(ZYO),((T3)'\052'));ZZs((T7*)(ZYO),((T3)'T'));
ZQs(ZXO,ZYO);ZXw((T7*)(ZYO),Z8M);}Z7I((Zi4*)(ZsG),ZYO);}T0*ZKU(ZE1*C){T0*R=Zo;R=ZLU(((C)->Z2d));return R;}T6 ZMU(ZE1*C,T0*a1){T6 R=0;
R=((T6)(Z_O(((C)->Z2d),a1)));return R;}void ZNU(ZE1*C,T76 a1,T0*a2){(C->Zxb)=a1;(C->Z2d)=a2;if(ZeN(a2)){{T76 Z3w;ZOU((*(Z3w=Z3L(a2),&Z3w)));
}}}T0*ZPU(ZE1*C){T0*R=Zo;R=Z3P(((C)->Z2d));return R;}T0*ZoU(ZE1*C){T0*R=Zo;if(ZEU(C)){R=((C)->Z4d);}return R;}T0*ZuU(void){if(ZDI==0){ZDI=1;{
{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZGk;ZCI=((T0*)n);}}}return ZCI;}T0*ZmU(void){if(ZbP==0){ZbP=1;{{T26*n=((T26*)Zh(1));ZaP=((T0*)n);ZdP(ZeP);
ZdP(ZfP);ZdP(ZgP);ZdP(ZhP);ZdP(ZiP);ZdP(ZjP);ZdP(ZkP);ZdP(ZlP);ZdP(ZmP);ZdP(ZnP);ZdP(ZoP);ZdP(ZpP);ZdP(ZqP);ZdP(ZrP);ZdP(ZpK);ZdP(ZsP);
ZdP(ZtP);ZdP(ZuP);ZdP(ZvP);ZdP(ZwP);ZdP(ZxP);ZdP(ZyP);ZdP(ZzP);ZdP(ZAP);ZdP(ZBP);ZdP(ZCP);ZdP(ZDP);ZdP(ZEP);ZdP(ZFP);ZdP(ZGP);ZdP(ZHP);
ZdP(ZIP);ZdP(ZJP);ZdP(ZKP);ZdP(ZLP);ZdP(ZMP);ZdP(ZNP);ZdP(ZOP);ZdP(ZPP);ZdP(ZQP);ZdP(ZRP);ZdP(ZSP);ZdP(ZTP);ZdP(ZUP);ZdP(ZVP);ZdP(ZWP);
ZdP(ZXP);ZdP(ZYP);ZdP(ZZP);ZdP(Z_P);ZdP(Z0Q);ZdP(Z1Q);ZdP(Z2Q);ZdP(Z3Q);ZdP(Z4Q);ZdP(Z5Q);ZdP(Z6Q);ZdP(Z7Q);ZdP(Z8Q);ZdP(Z9Q);ZdP(ZaQ);
ZdP(ZbQ);ZdP(ZcQ);ZdP(ZdJ);ZdP(ZdQ);ZdP(ZeQ);ZdP(ZfQ);ZdP(ZgQ);ZdP(ZhQ);ZdP(ZiQ);ZdP(ZjQ);ZdP(ZkQ);ZdP(ZlQ);ZdP(ZmQ);ZdP(ZnQ);ZdP(ZoQ);
ZdP(ZpQ);ZdP(ZqQ);ZdP(ZDG);ZdP(ZrQ);ZdP(ZsQ);ZdP(ZtQ);ZdP(ZuQ);ZdP(ZvQ);ZdP(ZwQ);ZdP(ZxQ);ZdP(ZyQ);ZdP(ZzQ);ZdP(ZAQ);ZdP(ZBQ);ZdP(ZCQ);
ZdP(ZDQ);ZdP(ZEQ);ZdP(ZFQ);ZdP(ZGQ);ZdP(ZHQ);ZdP(ZIQ);ZdP(ZJQ);ZdP(ZKQ);ZdP(ZLQ);ZdP(ZMQ);ZdP(ZNQ);ZdP(ZOQ);ZdP(ZPQ);ZdP(ZQQ);ZdP(ZRQ);
ZdP(ZSQ);ZdP(ZTQ);ZdP(ZUQ);ZdP(ZVQ);ZdP(ZWQ);ZdP(ZXQ);ZdP(ZYQ);ZdP(ZZQ);ZdP(Z_Q);ZdP(Z0R);ZdP(Z1R);ZdP(Z2R);ZdP(Z3R);ZdP(Z4R);ZdP(Z5R);
ZdP(Z6R);ZdP(Z7R);ZdP(Z8R);ZdP(Z9R);ZdP(ZaR);ZdP(ZbR);ZdP(ZcR);ZdP(ZdR);ZdP(ZeR);ZdP(ZfR);ZdP(ZgR);ZdP(ZhR);ZdP(ZiR);ZdP(ZjR);ZdP(ZkR);
ZdP(ZlR);ZdP(ZmR);ZdP(ZnR);ZdP(ZoR);ZdP(ZpR);ZdP(ZqR);ZdP(ZrR);ZdP(ZsR);ZdP(ZtR);ZdP(ZuR);ZdP(ZvR);ZdP(ZwR);ZdP(ZxR);ZdP(ZyR);ZdP(ZzR);
ZdP(ZAR);ZdP(ZBR);ZdP(ZCR);ZdP(ZDR);ZdP(ZER);ZdP(ZFR);ZdP(ZGR);ZdP(ZHR);ZdP(ZIR);ZdP(ZJR);ZdP(ZKR);ZdP(ZLR);ZdP(ZMR);ZdP(ZNR);ZdP(ZOR);
ZdP(ZPR);ZdP(ZQR);ZdP(ZRR);ZdP(ZSR);ZdP(ZTR);ZdP(ZUR);ZdP(ZVR);ZdP(ZWR);ZdP(ZXR);ZdP(ZYR);ZdP(ZZR);ZdP(Z_R);ZdP(Z0S);ZdP(Z1S);ZdP(Z2S);
ZdP(Z3S);ZdP(Z4S);ZdP(Z5S);ZdP(Z6S);ZdP(Z7S);ZdP(Z8S);ZdP(Z9S);ZdP(ZaS);ZdP(ZbS);ZdP(ZcS);ZdP(ZdS);ZdP(ZeS);ZdP(ZfS);ZdP(ZgS);ZdP(ZhS);
ZdP(ZiS);ZdP(ZjS);ZdP(ZkS);ZdP(ZlS);ZdP(ZmS);ZdP(ZnS);ZdP(ZoS);}}}return ZaP;}T0*ZQU(ZE1*C){T0*R=Zo;T0*ZqS=Zo;if((((C)->ZIc))!=((void*)(Zo))){
R=((C)->ZIc);}else{ZqS=ZPU(C);if((ZqS)!=((void*)(Zo))){(C->ZIc)=ZrS(((T80*)ZqS));R=((C)->ZIc);}else{{T0*b1=ZvF(27,"Cannot find Base Class for ");
ZXw((T7*)(ZwF),b1);}ZsS((T0*)C,ZMJ);ZEF((T75*)(ZyF));}}return R;}T0*ZRU(T76 a1){T0*R=Zo;{ZH4*n=((ZH4*)Zh(sizeof(*n)));*n=Zyg;((((ZH4*)(n)))->Zxb)=(a1);
R=((T0*)n);}return R;}void ZSU(ZE1*C,T0*a1){ZZs(((T7*)a1),((T3)'\045'));ZZs(((T7*)a1),((T3)'R'));ZQs(ZfU(C),a1);ZZs(((T7*)a1),((T3)'\045'));
}void ZTU(ZE1*C){if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){ZwS((Ze4*)(ZtU(C)));}}T6 ZAU(ZE1*C){T6 R=0;if(ZKN((Ze4*)(ZtU(C)))){R=((T6)(1));
}else{R=((T6)((ZKS((Ze4*)(ZtU(C))))!=((void*)(Zo))));}return R;}T6 ZUU(ZE1*C){T6 R=0;T0*ZyS=Zo;ZyS=Zo;R=((T6)((ZyS)!=((void*)(Zo))));
return R;}void ZHU(ZE1*C,T0*a1){ZZs(((T7*)a1),((T3)'T'));ZQs(ZfU(C),a1);ZZs(((T7*)a1),((T3)'\052'));}void ZvU(ZE1*C,T0*a1){ZXw(((T7*)a1),ZBS);
ZQs(ZfU(C),a1);}void ZxU(ZE1*C,T0*a1){ZXw(((T7*)a1),ZHS);ZQs(ZfU(C),a1);}void ZVU(ZE1*C){T0*_wa=Zo;T2 _i=0;T2 ZXO=0;T0*_a=Zo;T0*_t=Zo;
ZXO=ZfU(C);_wa=ZKS((Ze4*)(ZtU(C)));ZBw((T7*)(ZYO),ZtO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'S'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\173'));
if(ZKN((Ze4*)(ZtU(C)))){ZXw((T7*)(ZYO),ZWU);}if((_wa)!=((void*)(Zo))){_i=((((ZT8*)_wa))->ZRb);while(!((_i)==(Zrs(0)))){_a=ZDA(((ZT8*)_wa),_i);
_t=ZvG(((((ZG7*)_a))->Zgc));ZXU(_t,ZYO);ZZs((T7*)(ZYO),((T3)'\040'));ZZs((T7*)(ZYO),((T3)'\137'));ZXw((T7*)(ZYO),(((ZB8*)(((((ZG7*)_a))->Zkc)))->Zre));
ZZs((T7*)(ZYO),((T3)'\073'));_i=(Z3)(((_i))-(Zrs(1)));}}ZZs((T7*)(ZYO),((T3)'\175'));ZXw((T7*)(ZYO),Z8M);Z7I((Zi4*)(ZsG),ZYO);}T6 ZYU(ZE1*C){
T6 R=0;R=((T6)(ZQS(((C)->Z2d))));return R;}void ZZU(T0*a1){ZUS(a1,ZVS);ZUS(a1,ZWS);ZXS(a1,((T3)'\n'));}T6 Z_U(ZE1*C,T0*a1){T6 R=0;if((ZnU(C))==((void*)(ZDF(a1)))){
R=((T6)(1));}else{R=((T6)(ZYF(((C)->Z2d),a1)));}if(!(R)){ZZS((T0*)C,a1);}return R;}T0*Z0V(ZE1*C){T0*R=Zo;if(!(ZMF(&(((C)->Zxb))))){R=Z0T(&(((C)->Zxb)));
}return R;}T0*Z1V(ZE1*C,T0*a1){T0*R=Zo;T0*_et=Zo;T0*_rt=Zo;T0*Z2V=Zo;T0*Z3V=Zo;_et=Z9L(((C)->Z2d),a1);Z2V=ZDF(_et);if((Z2V)==((void*)(ZxP))){
Z3V=ZvG(_et);if(Zo!=(Z3V)){switch(((T0*)Z3V)->id){case 279:break;default:Z3V=Zo;}}if((((((Zs5*)Z3V))->Zih))==(Zrs(65))){ZzF(((C)->Zxb));
{T0*b1=ZvF(53,"Type \"reference INTEGER_GENERAL\" is not valid (CTCR).");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}if((Z2V)==((void*)(ZHP))){
ZzF(((C)->Zxb));{T0*b1=ZvF(50,"Type reference \"REAL_GENERAL\" is not valid (CTCR).");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}if(ZeN(_et)){
{T76 Z3w;ZOU((*(Z3w=Z3L(_et),&Z3w)));}}if((_et)==((void*)(((C)->Z2d)))){if((((C)->Z4d))==((void*)(Zo))){if(Z5T(_et)){(C->Z4d)=((T0*)(C));
}else{(C->Z4d)=_et;}R=((T0*)(C));}else if((((C)->Z4d))==((void*)(C))){if(Z5T(_et)){R=((T0*)(C));}else{{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Z5d;
ZNU(n,((C)->Zxb),_et);R=((T0*)n);}R=Z1V(((ZE1*)R),a1);}}else{{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Z5d;ZNU(n,((C)->Zxb),ZvG(_et));_rt=((T0*)n);
}{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Z5d;ZpU(n,((C)->Zxb),_et,((C)->Z3d),_rt);R=((T0*)n);}}}else{{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Z5d;ZNU(n,((C)->Zxb),ZvG(_et));
_rt=((T0*)n);}{ZE1*n=((ZE1*)Zh(sizeof(*n)));*n=Z5d;ZpU(n,((C)->Zxb),_et,((C)->Z3d),_rt);R=((T0*)n);}}return R;}void Z4V(ZE1*C){T2 ZXO=0;
T0*_rc=Zo;_rc=ZtU(C);ZXO=((((Ze4*)_rc))->_id);((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZYO),((T3)'T'));ZQs(ZXO,ZYO);ZZs((T7*)(ZYO),((T3)'\040'));
ZZs((T7*)(ZYO),((T3)'M'));ZQs(ZXO,ZYO);ZDS((Zi4*)(ZsG),ZYO);ZES((Zi4*)(ZsG));((((T7*)((T7*)(ZYO))))->Zcc)=(Zrs(0));Z5V(((Ze4*)_rc),ZYO);
ZXw((T7*)(ZYO),Z8M);Z7I((Zi4*)(ZsG),ZYO);ZGS((Zi4*)(ZsG));}T0*Z6V(ZE1*C){T0*R=Zo;T0*Z9T=Zo;Z9T=ZKU(C);if((Z9T)!=((void*)(Zo))){R=ZrS(((T80*)Z9T));
}return R;}void ZzU(ZE1*C,T0*a1){ZXw(((T7*)a1),ZcT);ZQs(ZfU(C),a1);}T0*ZtU(ZE1*C){T0*R=Zo;if((((C)->ZJc))!=((void*)(Zo))){R=((C)->ZJc);
}else if(ZEU(C)){(C->ZJc)=ZdT(ZoU(C));R=((C)->ZJc);}return R;}T6 ZEU(ZE1*C){T6 R=0;if((((C)->Z4d))!=((void*)(Zo))){R=((T6)(1));}else if(Z7V(((C)->Z2d))){
(C->Z4d)=((T0*)(C));R=((T6)(1));}return R;}void Z8V(ZE1*C){if(ZAU(C)){ZVU(C);}Z4V(C);ZTU(C);}void Z9V(ZE1*C,T0*a1){ZvU(C,a1);ZZs(((T7*)a1),((T3)'\075'));
ZXw(((T7*)a1),ZxO);ZXw(((T7*)a1),Z8M);}T0*ZaV(ZE1*C,T0*a1){T0*R=Zo;if((ZnU(C))==((void*)(ZDF(a1)))){R=((T0*)(C));}else{R=ZiT(((C)->Z2d),a1);
}return R;}void ZyU(ZE1*C,T0*a1){ZXw(((T7*)a1),ZjT);ZQs(ZfU(C),a1);}void ZbV(ZE1*C,T0*a1){ZXw(((T7*)a1),ZZN);ZQs(ZfU(C),a1);ZZs(((T7*)a1),((T3)'\050'));
ZZs(((T7*)a1),((T3)'\051'));}
#ifdef __cplusplus
}
#endif

