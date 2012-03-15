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
void Zhg1(ZN4*C){{Zc7*n=((Zc7*)Zh(sizeof(*n)));*n=ZBj;Zig1(n,((C)->Zxb));(C->Zgc)=((T0*)n);}}void ZiW(ZN4*C,T76 a1,T3 a2){Zjg1(C,a1,a2,Zrs(0));
Zhg1(C);}T0*Zkg1=Zo;void Zlg1(ZN4*C){Z7I((Zi4*)(ZsG),Zmg1);if((T6)((Zss(((C)->Zde)))||((T6)(Zjs(((C)->Zde)))))){ZcH((Zi4*)(ZsG),((C)->Zde));
}else if((((C)->Zde))==(((T3)'\n'))){ZcH((Zi4*)(ZsG),((T3)'\134'));ZcH((Zi4*)(ZsG),((T3)'n'));}else{ZcH((Zi4*)(ZsG),((T3)'\134'));((((T7*)((T7*)(Zkg1))))->Zcc)=(Zrs(0));
ZCs((Zqs)(Zos(((C)->Zde))),Zkg1);Z7I((Zi4*)(ZsG),Zkg1);}Z7I((Zi4*)(ZsG),Zng1);}void Zog1(ZN4*C){ZzF(((C)->Zxb));{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void Zjg1(ZN4*C,T76 a1,T3 a2,T2 a3){(C->Zxb)=a1;(C->Zde)=a2;((((ZN4*)(C)))->ZNg)=(a3);}T6 Zpg1(T0*a1){
T6 R=0;return R;}T2 Zqg1(ZN4*C){T2 R=0;R=(T2)(Zos(((C)->Zde)));return R;}T0*Zrg1(ZN4*C,T0*a1){T0*R=Zo;R=((T0*)(C));if((((C)->Zgc))==((void*)(Zo))){
Zhg1(C);}return R;}T0*Zsg1(ZN4*C){T0*R=Zo;if((((C)->Zgc))!=((void*)(Zo))){R=ZbK(((C)->Zgc));}return R;}void Z601(ZT4*C,T0*a1){T2 _i=0;
T0*Ztg1=Zo;(C->Zxb)=((((ZT4*)a1))->Zxb);(C->ZUb)=ZDy((Zp2*)(((((ZT4*)a1))->ZUb)));_i=(((Zp2*)(((C)->ZUb)))->ZSb);while(!((Z3)((_i)>((((Zp2*)(((C)->ZUb)))->ZRb)))))
{Ztg1=Zug1(ZBy((Zp2*)(((C)->ZUb)),_i));((((Zm1*)(((Zm1*)Ztg1))))->ZPc)=(Zo);{Zp2*C1=(Zp2*)(((C)->ZUb));T0*b1=Ztg1;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}_i=(Z3)(((_i))+(Zrs(1)));}(C->ZCb)=((((ZT4*)a1))->ZCb);(C->Z7d)=((((ZT4*)a1))->Z7d);}void ZrT(ZT4*C,T2 a1){if((((C)->Z7d))!=((void*)(Zo))){
(C->Z7d)=Z471((Z47*)(((C)->Z7d)));}Z_61(((Zq3*)((((ZD2*)(((C)->Zje)))->ZMd))),((C)->Z7d));}void Zvg1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;
ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}void ZI_(ZT4*C){if((((C)->Z7d))!=((void*)(Zo))){Z271((Z47*)(((C)->Z7d)));}}void ZK_(ZT4*C,T0*a1,T0*a2){
T2 _i=0;_i=(((Zp2*)(((C)->ZUb)))->ZSb);while(!((Z3)((_i)>((((Zp2*)(((C)->ZUb)))->ZRb))))){Zwg1(ZBy((Zp2*)(((C)->ZUb)),_i),_i,a1,a2);_i=(Z3)(((_i))+(Zrs(1)));
}if((((C)->Z7d))!=((void*)(Zo))){(C->Z7d)=Z471((Z47*)(((C)->Z7d)));}}void Zxg1(ZT4*C,T0*a1){T0*Zyg1=Zo;{Zm1*n=((Zm1*)Zh(sizeof(*n)));
*n=ZVc;((((Zm1*)(n)))->ZTc)=(a1);Zyg1=((T0*)n);}if((((C)->ZUb))==((void*)(Zo))){{Zp2*n=((Zp2*)Zh(sizeof(*n)));*n=ZHd;ZEy(n,(T2)(Zrs(4)),(T2)(Zrs(1)));
(C->ZUb)=((T0*)n);}}ZCy((Zp2*)(((C)->ZUb)),Zyg1);}T6 ZM_(ZT4*C,T2 a1){T6 R=0;T2 _i=0;if((T6)(((T6)(((((C)->ZRg))!=((void*)(Zo)))&&((T6)((Z3)((a1)>=(Zly((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb))))))))&&((T6)((Z3)((a1)<=(Zly((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZRb)))))))){
_i=(((Z72*)(((C)->ZRg)))->ZSb);while(!((T6)((R)||((T6)((Z3)((_i)>((((Z72*)(((C)->ZRg)))->ZRb)))))))){R=((T6)(Zfs((T6)((Z3)((Zly((Z72*)(((C)->ZRg)),_i))<=(a1))),(T6)((Z3)((a1)<=(Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+(Zrs(1))))))))));
_i=(Z3)(((_i))+(Zrs(2)));}}return R;}void ZP_(ZT4*C){T2 _bi=0;Z7I((Zi4*)(ZsG),Zzg1);_bi=(((Z72*)(((C)->ZRg)))->ZSb);while(!((Z3)((_bi)>((((Z72*)(((C)->ZRg)))->ZRb)))))
{ZcH((Zi4*)(ZsG),((T3)'\050'));if((Zly((Z72*)(((C)->ZRg)),_bi))==(Zly((Z72*)(((C)->ZRg)),(Z3)(((_bi))+(Zrs(1)))))){ZtI((Zi4*)(ZsG),(T11)(Zly((Z72*)(((C)->ZRg)),_bi)));
Z7I((Zi4*)(ZsG),ZAg1);Zf71((Zi4*)(ZsG));}else{ZcH((Zi4*)(ZsG),((T3)'\050'));ZtI((Zi4*)(ZsG),(T11)(Zly((Z72*)(((C)->ZRg)),_bi)));Z7I((Zi4*)(ZsG),ZBg1);
Zf71((Zi4*)(ZsG));Z7I((Zi4*)(ZsG),ZCg1);Zf71((Zi4*)(ZsG));Z7I((Zi4*)(ZsG),ZDg1);ZtI((Zi4*)(ZsG),(T11)(Zly((Z72*)(((C)->ZRg)),(Z3)(((_bi))+((T2)(Zrs(1)))))));
ZcH((Zi4*)(ZsG),((T3)'\051'));}ZcH((Zi4*)(ZsG),((T3)'\051'));_bi=(Z3)(((_bi))+(Zrs(2)));if((Z3)((_bi)<((((Z72*)(((C)->ZRg)))->ZRb)))){
Z7I((Zi4*)(ZsG),ZEg1);}}Z7I((Zi4*)(ZsG),ZFg1);if((((C)->Z7d))!=((void*)(Zo))){ZgV((Z47*)(((C)->Z7d)));}Z7I((Zi4*)(ZsG),ZdI);}T6 ZS_(ZT4*C,T0*a1){
T6 R=0;R=((T6)((T6)(((((C)->Z7d))==((void*)(Zo)))||((T6)(Zs71((Z47*)(((C)->Z7d)),a1))))));return R;}T6 ZU_(ZT4*C,T2 a1,T2 a2){T6 R=0;
T2 _i=0;if((T6)(((T6)(((((C)->ZRg))!=((void*)(Zo)))&&((T6)((Z3)((a2)>=(Zly((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb))))))))&&((T6)((Z3)((a1)<=(Zly((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZRb)))))))){
_i=(((Z72*)(((C)->ZRg)))->ZSb);while(!((T6)((R)||((T6)((Z3)((_i)>((((Z72*)(((C)->ZRg)))->ZRb)))))))){R=((T6)(Zfs((T6)((Z3)((Zly((Z72*)(((C)->ZRg)),_i))<=(a2))),(T6)((Z3)((a1)<=(Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+(Zrs(1))))))))));
_i=(Z3)(((_i))+(Zrs(2)));}}return R;}void ZGg1(ZT4*C,T76 a1,T0*a2){(C->Zxb)=a1;(C->ZCb)=a2;}void ZJT(ZT4*C,T0*a1){T2 _i=0;T2 _v=0;_v=((((Zm1*)a1))->ZUc);
if(ZL_(((ZD2*)((((Zq3*)(((((ZD2*)(((C)->Zje))))->ZMd)))->Zje))),_v)){{T76 Z3w;ZHg1(C,_v,(*(Z3w=ZOT(((Zm1*)a1)),&Z3w)));}}else if((((C)->ZRg))==((void*)(Zo))){
{Z72*n=((Z72*)Zh(sizeof(*n)));*n=Zrd;Zmy(n,(T2)(Zft(501)),(T2)(Zft(502)));(C->ZRg)=((T0*)n);}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=(((Z72*)(((C)->ZRg)))->ZSb);
(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=(((Z72*)(((C)->ZRg)))->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}}else{_i=ZIg1(C,_v);if((_i)==((((Z72*)(((C)->ZRg)))->ZSb))){if((_v)==((Z3)(((Zly((Z72*)(((C)->ZRg)),_i)))-(Zrs(1))))){{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_v;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else{Zny((Z72*)(((C)->ZRg)),(Z3)((((((Z72*)(((C)->ZRg)))->ZSb)))-((T2)(Zrs(2)))),(((Z72*)(((C)->ZRg)))->ZRb));
{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=(((Z72*)(((C)->ZRg)))->ZSb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_v;T2 b2=(Z3)((((((Z72*)(((C)->ZRg)))->ZSb)))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}}else if((Z3)((_i)>((((Z72*)(((C)->ZRg)))->ZRb)))){
if((_v)==((Z3)(((Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1))))))+(Zrs(1))))){{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=(Z3)(((_i))-((T2)(Zrs(1))));
(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else{Zny((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb),(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))+((T2)(Zrs(2)))));
{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=(((Z72*)(((C)->ZRg)))->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}}else{if(Zfs((T6)((_v)==((Z3)(((Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1))))))+(Zrs(1))))),(T6)((_v)==((Z3)(((Zly((Z72*)(((C)->ZRg)),_i)))-(Zrs(1))))))){
{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+((T2)(Zrs(1)))));T2 b2=(Z3)(((_i))-((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}while(!((Z3)((_i)>((Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-(Zrs(2))))))){{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+((T2)(Zrs(2)))));
T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+((T2)(Zrs(3)))));
T2 b2=(Z3)(((_i))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}_i=(Z3)(((_i))+(Zrs(2)));}Zny((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb),(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-((T2)(Zrs(2)))));
}else if((_v)==((Z3)(((Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1))))))+(Zrs(1))))){{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=(Z3)(((_i))-((T2)(Zrs(1))));
(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else if((_v)==((Z3)(((Zly((Z72*)(((C)->ZRg)),_i)))-(Zrs(1))))){{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_v;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else{Zny((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb),(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))+((T2)(Zrs(2)))));
_i=(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-(Zrs(1)));while(!((Z3)((_v)>(Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1)))))))){{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-((T2)(Zrs(2)))));T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-((T2)(Zrs(1)))));T2 b2=(Z3)(((_i))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}_i=(Z3)(((_i))-(Zrs(2)));}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_v;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_v;T2 b2=(Z3)(((_i))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}}}}void ZyT(ZT4*C,T0*a1){T2 _l=0;T2 _u=0;
T2 _i=0;_l=((((Zk1*)a1))->ZQc);_u=((((Zk1*)a1))->ZRc);if((Z3)((_l)>=(_u))){{T76 Z3w;Zvg1((*(Z3w=ZDT(((Zk1*)a1)),&Z3w)),ZvF(17,"Not a good slice."));
}}else if(ZT_(((ZD2*)((((Zq3*)(((((ZD2*)(((C)->Zje))))->ZMd)))->Zje))),_l,_u)){_i=_l;while(!(ZL_(((ZD2*)((((Zq3*)(((((ZD2*)(((C)->Zje))))->ZMd)))->Zje))),_i)))
{if((_i)==(_l)){_l=(Z3)(((_l))+(Zrs(1)));_i=_u;}else{_u=(Z3)(((_u))-(Zrs(1)));_i=_l;}}{T76 Z3w;ZHg1(C,_i,(*(Z3w=ZDT(((Zk1*)a1)),&Z3w)));
}}else if((((C)->ZRg))==((void*)(Zo))){{Z72*n=((Z72*)Zh(sizeof(*n)));*n=Zrd;Zmy(n,(T2)(Zft(501)),(T2)(Zft(502)));(C->ZRg)=((T0*)n);}{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_l;T2 b2=(((Z72*)(((C)->ZRg)))->ZSb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_u;T2 b2=(((Z72*)(((C)->ZRg)))->ZRb);
(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else{_i=ZIg1(C,_l);if((_i)==((((Z72*)(((C)->ZRg)))->ZSb))){if((_u)==((Z3)(((Zly((Z72*)(((C)->ZRg)),_i)))-(Zrs(1))))){
{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_l;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else{Zny((Z72*)(((C)->ZRg)),(Z3)((((((Z72*)(((C)->ZRg)))->ZSb)))-((T2)(Zrs(2)))),(((Z72*)(((C)->ZRg)))->ZRb));
{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_l;T2 b2=(((Z72*)(((C)->ZRg)))->ZSb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_u;T2 b2=(Z3)((((((Z72*)(((C)->ZRg)))->ZSb)))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}}else if((Z3)((_i)>((((Z72*)(((C)->ZRg)))->ZRb)))){
if((_l)==((Z3)(((Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1))))))+(Zrs(1))))){{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_u;T2 b2=(Z3)(((_i))-((T2)(Zrs(1))));
(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else{Zny((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb),(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))+((T2)(Zrs(2)))));
{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_l;T2 b2=(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_u;T2 b2=(((Z72*)(((C)->ZRg)))->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}}else{if(Zfs((T6)((_l)==((Z3)(((Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1))))))+(Zrs(1))))),(T6)((_u)==((Z3)(((Zly((Z72*)(((C)->ZRg)),_i)))-(Zrs(1))))))){
{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+((T2)(Zrs(1)))));T2 b2=(Z3)(((_i))-((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}while(!((Z3)((_i)>((Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-(Zrs(2))))))){{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+((T2)(Zrs(2)))));
T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+((T2)(Zrs(3)))));
T2 b2=(Z3)(((_i))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}_i=(Z3)(((_i))+(Zrs(2)));}Zny((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb),(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-((T2)(Zrs(2)))));
}else if((_l)==((Z3)(((Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1))))))+(Zrs(1))))){{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_u;T2 b2=(Z3)(((_i))-((T2)(Zrs(1))));
(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else if((_u)==((Z3)(((Zly((Z72*)(((C)->ZRg)),_i)))-(Zrs(1))))){{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_l;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}else{Zny((Z72*)(((C)->ZRg)),(((Z72*)(((C)->ZRg)))->ZSb),(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))+((T2)(Zrs(2)))));
_i=(Z3)((((((Z72*)(((C)->ZRg)))->ZRb)))-(Zrs(1)));while(!((Z3)((_l)>(Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-(Zrs(1)))))))){{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-((T2)(Zrs(2)))));T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))-((T2)(Zrs(1)))));T2 b2=(Z3)(((_i))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}_i=(Z3)(((_i))-(Zrs(2)));}{Z72*C1=(Z72*)(((C)->ZRg));T2 b1=_l;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{Z72*C1=(Z72*)(((C)->ZRg));
T2 b1=_u;T2 b2=(Z3)(((_i))+((T2)(Zrs(1))));(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}}}}void ZJg1(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}T0*ZX_(ZT4*C,T0*a1){T0*R=Zo;T0*_ct=Zo;T2 _ne=0;T2 _i=0;T0*Ztg1=Zo;if((((C)->Zje))==((void*)(Zo))){_ne=(((T75*)(ZyF))->ZAg);
(C->Zje)=a1;if((((C)->ZUb))==((void*)(Zo))){ZzF((((Zq3*)(((((ZD2*)(((C)->Zje))))->ZMd)))->Zxb));Zvg1(((C)->Zxb),ZKg1);}else{_i=(((Zp2*)(((C)->ZUb)))->ZSb);
while(!((T6)(((Z3)((_i)>((((Zp2*)(((C)->ZUb)))->ZRb))))||((T6)((Z3)(((Z3)((((((T75*)(ZyF))->ZAg)))-(_ne)))>(Zrs(0)))))))){Ztg1=ZLg1(ZBy((Zp2*)(((C)->ZUb)),_i),(T0*)C);
if((Ztg1)==((void*)(Zo))){Zvg1(((C)->Zxb),ZMg1);}else{{Zp2*C1=(Zp2*)(((C)->ZUb));T0*b1=Ztg1;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}}_i=(Z3)(((_i))+(Zrs(1)));}}if((((C)->Z7d))!=((void*)(Zo))){_ct=(((ZS7*)(ZWG()))->Z0c);(C->Z7d)=ZqV((Z47*)(((C)->Z7d)),_ct);if((((C)->Z7d))==((void*)(Zo))){
Zvg1(((C)->Zxb),ZMg1);}}R=((T0*)(C));}else{{ZT4*n=((ZT4*)Zh(sizeof(*n)));*n=ZSg;Z601(n,(T0*)C);R=((T0*)n);}R=ZX_(((ZT4*)R),a1);}return
R;}T0*Z101(ZT4*C,T0*a1){T0*R=Zo;T0*_ct=Zo;T2 _ne=0;T2 _i=0;T0*Ztg1=Zo;if((((C)->Zje))==((void*)(Zo))){_ne=(((T75*)(ZyF))->ZAg);(C->Zje)=a1;
if((((C)->ZUb))==((void*)(Zo))){ZzF((((Zq3*)(((((ZD2*)(((C)->Zje))))->ZMd)))->Zxb));Zvg1(((C)->Zxb),ZKg1);}else{_i=(((Zp2*)(((C)->ZUb)))->ZSb);
while(!((T6)(((Z3)((_i)>((((Zp2*)(((C)->ZUb)))->ZRb))))||((T6)((Z3)(((Z3)((((((T75*)(ZyF))->ZAg)))-(_ne)))>(Zrs(0)))))))){Ztg1=ZNg1(ZBy((Zp2*)(((C)->ZUb)),_i),(T0*)C);
if((Ztg1)==((void*)(Zo))){Zvg1(((C)->Zxb),ZMg1);}else{{Zp2*C1=(Zp2*)(((C)->ZUb));T0*b1=Ztg1;T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}}_i=(Z3)(((_i))+(Zrs(1)));}}if((((C)->Z7d))!=((void*)(Zo))){_ct=(((ZS7*)(ZWG()))->Z0c);(C->Z7d)=ZqV((Z47*)(((C)->Z7d)),_ct);if((((C)->Z7d))==((void*)(Zo))){
Zvg1(((C)->Zxb),ZMg1);}}R=((T0*)(C));}else{{ZT4*n=((ZT4*)Zh(sizeof(*n)));*n=ZSg;Z601(n,(T0*)C);R=((T0*)n);}R=Z101(((ZT4*)R),a1);}return
R;}void Z301(ZT4*C){if((((C)->Z7d))!=((void*)(Zo))){ZjV((Z47*)(((C)->Z7d)));}}T6 Z501(ZT4*C){T6 R=0;if((((C)->Z7d))!=((void*)(Zo))){R=((T6)(ZlV((Z47*)(((C)->Z7d)))));
}return R;}void Z801(ZT4*C,T0*a1){T2 _i=0;if((((C)->Z7d))!=((void*)(Zo))){ZnV((Z47*)(((C)->Z7d)),a1);}_i=(((Zp2*)(((C)->ZUb)))->ZRb);
while(!((Z3)((_i)<((((Zp2*)(((C)->ZUb)))->ZSb))))){ZOg1(ZBy((Zp2*)(((C)->ZUb)),_i),a1);_i=(Z3)(((_i))-(Zrs(1)));}}T0*Za01(ZT4*C,T0*a1){
T0*R=Zo;T0*_ct=Zo;T2 _ne=0;T2 _i=0;T0*Ztg1=Zo;if((((C)->Zje))==((void*)(Zo))){_ne=(((T75*)(ZyF))->ZAg);(C->Zje)=a1;if((((C)->ZUb))==((void*)(Zo))){
ZzF((((Zq3*)(((((ZD2*)(((C)->Zje))))->ZMd)))->Zxb));Zvg1(((C)->Zxb),ZKg1);}else{_i=(((Zp2*)(((C)->ZUb)))->ZSb);while(!((T6)(((Z3)((_i)>((((Zp2*)(((C)->ZUb)))->ZRb))))||((T6)((Z3)(((Z3)((((((T75*)(ZyF))->ZAg)))-(_ne)))>(Zrs(0))))))))
{Ztg1=ZPg1(ZBy((Zp2*)(((C)->ZUb)),_i),(T0*)C);if((Ztg1)==((void*)(Zo))){Zvg1(((C)->Zxb),ZMg1);}else{{Zp2*C1=(Zp2*)(((C)->ZUb));T0*b1=Ztg1;
T2 b2=_i;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}_i=(Z3)(((_i))+(Zrs(1)));}}if((((C)->Z7d))!=((void*)(Zo))){_ct=(((ZS7*)(ZWG()))->Z0c);
(C->Z7d)=ZqV((Z47*)(((C)->Z7d)),_ct);if((((C)->Z7d))==((void*)(Zo))){Zvg1(((C)->Zxb),ZMg1);}}R=((T0*)(C));}else{{ZT4*n=((ZT4*)Zh(sizeof(*n)));
*n=ZSg;Z601(n,(T0*)C);R=((T0*)n);}R=Za01(((ZT4*)R),a1);}return R;}T2 ZIg1(ZT4*C,T2 a1){T2 R=0;R=(((Z72*)(((C)->ZRg)))->ZSb);while(!((T6)(((Z3)((R)>((((Z72*)(((C)->ZRg)))->ZRb))))||((T6)((Z3)((a1)<(Zly((Z72*)(((C)->ZRg)),R))))))))
{R=(Z3)(((R))+(Zrs(2)));}return R;}void ZHg1(ZT4*C,T2 a1,T76 a2){ZzF((((Zq3*)(((((ZD2*)(((C)->Zje))))->ZMd)))->Zxb));{T0*b1=ZvF(34,"Second occurrence for this value (");
ZXw((T7*)(ZwF),b1);}{T0*b1=ZPs(a1);ZXw((T7*)(ZwF),b1);}Zvg1(a2,ZvF(22,") in the same inspect."));}T2 Zd01(ZT4*C){T2 R=0;T2 _i=0;T2 Zc01=0;
if((((C)->ZRg))!=((void*)(Zo))){_i=(((Z72*)(((C)->ZRg)))->ZSb);while(!((Z3)((_i)>((((Z72*)(((C)->ZRg)))->ZRb))))){Zc01=(Z3)((((Z3)(((Zly((Z72*)(((C)->ZRg)),(Z3)(((_i))+(Zrs(1))))))-(Zly((Z72*)(((C)->ZRg)),_i)))))+(Zrs(1)));
if((Z3)((Zc01)>(R))){R=Zc01;}_i=(Z3)(((_i))+(Zrs(2)));}}return R;}void ZQg1(ZT4*C,T0*a1,T0*a2){T0*Zyg1=Zo;if(ZIT(a1)){{T76 Z3w;ZzF((*(Z3w=ZGG(a1),&Z3w)));
}ZJg1(ZRg1);}else if(ZIT(a2)){{T76 Z3w;ZzF((*(Z3w=ZGG(a2),&Z3w)));}ZJg1(ZSg1);}else{{Zk1*n=((Zk1*)Zh(sizeof(*n)));*n=ZSc;ZsT(n,a1,a2);
Zyg1=((T0*)n);}if((((C)->ZUb))==((void*)(Zo))){{Zp2*n=((Zp2*)Zh(sizeof(*n)));*n=ZHd;ZEy(n,(T2)(Zrs(4)),(T2)(Zrs(1)));(C->ZUb)=((T0*)n);
}}ZCy((Zp2*)(((C)->ZUb)),Zyg1);}}void Zf01(ZT4*C){T2 _bi=0;T2 _v=0;_bi=(((Z72*)(((C)->ZRg)))->ZSb);while(!((Z3)((_bi)>((((Z72*)(((C)->ZRg)))->ZRb)))))
{_v=Zly((Z72*)(((C)->ZRg)),_bi);while(!((Z3)((_v)>(Zly((Z72*)(((C)->ZRg)),(Z3)(((_bi))+(Zrs(1)))))))){Z7I((Zi4*)(ZsG),ZTg1);ZtI((Zi4*)(ZsG),(T11)(_v));
Z7I((Zi4*)(ZsG),ZUg1);_v=(Z3)(((_v))+(Zrs(1)));}_bi=(Z3)(((_bi))+(Zrs(2)));}if((((C)->Z7d))!=((void*)(Zo))){ZgV((Z47*)(((C)->Z7d)));}
Z7I((Zi4*)(ZsG),ZVg1);}void ZWg1(ZX4*C,T0*a1){Z8Z(((C)->ZNc),a1);}void ZXg1(ZX4*C,T0*a1){if(ZYg1(C)){ZXw(((T7*)a1),Z9N);ZZs(((T7*)a1),((T3)'\052'));
}else{ZZg1(C,a1);}}T0*Z_g1(ZX4*C){T0*R=Zo;if(Z0h1(C)){R=ZbN(((C)->ZNc));}else{Z1h1(C);}return R;}T6 Z2h1(ZX4*C){T6 R=0;R=((T6)(ZeN(((C)->ZNc))));
return R;}T0*Z3h1=Zo;T0*Z4h1(ZX4*C){T0*R=Zo;if((((C)->ZNc))!=((void*)(Zo))){R=ZDF(((C)->ZNc));}return R;}T6 Z5h1(ZX4*C){T6 R=0;R=((T6)(ZgN(((C)->ZNc))));
return R;}T2 Z6h1(ZX4*C){T2 R=0;R=ZjZ(((C)->ZNc));return R;}void ZZg1(ZX4*C,T0*a1){ZXU(((C)->ZNc),a1);}T6 Z7h1(void){T6 R=0;return R;
}T6 Z8h1(ZX4*C){T6 R=0;T0*ZCO=Zo;ZCO=Zo;R=((T6)((ZCO)!=((void*)(Zo))));return R;}void Z9h1(ZX4*C,T0*a1){ZXw(((T7*)a1),ZDO);ZQs(Zah1(C),a1);
}T6 Zbh1(ZX4*C){T6 R=0;T0*_rt=Zo;if((((C)->ZNc))!=(Zo)){_rt=((C)->ZNc);if((C)==((void*)(_rt))){if((ZvG(_rt))==((void*)(_rt))){R=((T6)((ZFO(_rt))==((void*)(ZDF(_rt)))));
}}}return R;}void Zch1(ZX4*C,T0*a1){ZqZ(((C)->ZNc),a1);}void Zdh1(ZX4*C,T0*a1,T0*a2){(C->Zxb)=((((ZX4*)a1))->Zxb);(C->ZUg)=((((ZX4*)a1))->ZUg);
(C->ZVg)=((((ZX4*)a1))->ZVg);(C->ZKc)=((((ZX4*)a1))->ZKc);(C->ZNc)=a2;}T6 Zeh1(ZX4*C){T6 R=0;R=((T6)(ZHO(((C)->ZNc))));return R;}T2 Zah1(ZX4*C){
T2 R=0;R=(((Ze4*)(Zfh1(C)))->_id);return R;}void Zgh1(ZX4*C){((((T7*)((T7*)(ZJO))))->Zcc)=(Zrs(0));ZZs((T7*)(ZJO),((T3)'\050'));Zhh1(C,ZJO);
ZZs((T7*)(ZJO),((T3)'\051'));Z7I((Zi4*)(ZsG),ZJO);}T6 Zih1(ZX4*C){T6 R=0;R=((T6)(ZTO(((C)->ZNc))));return R;}T6 Zjh1(ZX4*C){T6 R=0;R=((T6)(ZVO(((C)->ZNc))));
return R;}void Zkh1(ZX4*C){ZzZ(((C)->ZNc));}T6 Zlh1(ZX4*C){T6 R=0;R=((T6)(ZBZ(((C)->ZNc))));return R;}T0*Zmh1(ZX4*C){T0*R=Zo;T0*_bc=Zo;
T0*_rt=Zo;if((((C)->ZNc))!=((void*)(Zo))){R=ZLU(((C)->ZNc));}else{if((((C)->ZVg))==((void*)(Zo))){_bc=((((C)->Zxb)).Zqb);(C->ZVg)=ZuH(((T82*)_bc),((C)->ZUg));
if((((C)->ZVg))!=((void*)(Zo))){_rt=ZvH(((C)->ZVg));}if((_rt)==((void*)(Zo))){if((((C)->ZVg))!=((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGJ(((C)->ZVg)),&Z3w)));
}}{T0*b1=Znh1;ZXw((T7*)(ZwF),b1);}ZzF(((C)->Zxb));ZEF((T75*)(ZyF));}}_rt=ZvH(((C)->ZVg));R=ZLU(_rt);}return R;}void Z1h1(ZX4*C){ZsS((T0*)C,ZvF(19," is (not) generic \?"));
ZEF((T75*)(ZyF));}void Zoh1(ZX4*C,T0*a1){ZEZ(((C)->ZNc),a1);}T6 Zph1(ZX4*C,T0*a1){T6 R=0;R=((T6)(Zqh1(C,a1)));return R;}void Zrh1(ZX4*C){
{T76 Z3w;if(!Ztb((((C)->Zxb)),((*(Z3w=ZEz((T77*)(Zsh1)),&Z3w))))){((((T77*)((T77*)(Zsh1))))->ZRb)=(Zrs(-1));}}}T6 Zth1(ZX4*C){T6 R=0;
R=((T6)(Z1P(((C)->ZNc))));return R;}void Zuh1(ZX4*C,T76 a1,T0*a2){(C->Zxb)=a1;(C->ZUg)=a2;ZBw((T7*)(Z3h1),Zvh1);ZZs((T7*)(Z3h1),((T3)'\040'));
Zwh1((ZB8*)(((C)->ZUg)),Z3h1);(C->ZKc)=(((void)((T26*)(Zxh1()))),ZAS(Z3h1));}T0*Zyh1(ZX4*C){T0*R=Zo;R=Z3P(((C)->ZNc));return R;}void Zzh1(T0*a1){
{T0*b1=a1;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}T6 ZAh1(ZX4*C){T6 R=0;R=((T6)(Z6P(((C)->ZNc))));return R;}T6 ZBh1(ZX4*C){T6 R=0;R=((T6)(Z5T(((C)->ZNc))));
return R;}T6 ZCh1(ZX4*C){T6 R=0;R=((T6)(Z9P(((C)->ZNc))));return R;}void ZDh1(ZX4*C,T0*a1){ZMZ(((C)->ZNc),a1);}T0*Zxh1(void){if(ZbP==0){ZbP=1;{
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
ZdP(ZdS);ZdP(ZeS);ZdP(ZfS);ZdP(ZgS);ZdP(ZhS);ZdP(ZiS);ZdP(ZjS);ZdP(ZkS);ZdP(ZlS);ZdP(ZmS);ZdP(ZnS);ZdP(ZoS);}}}return ZaP;}T0*ZEh1(ZX4*C){
T0*R=Zo;T0*ZqS=Zo;if((((C)->ZIc))!=((void*)(Zo))){R=((C)->ZIc);}else{ZqS=Zyh1(C);if((ZqS)!=((void*)(Zo))){(C->ZIc)=ZrS(((T80*)ZqS));R=((C)->ZIc);
}else{{T0*b1=ZvF(27,"Cannot find Base Class for ");ZXw((T7*)(ZwF),b1);}ZsS((T0*)C,ZMJ);ZEF((T75*)(ZyF));}}return R;}T0*ZFh1(ZX4*C,T76
a1){T0*R=Zo;if(ZYg1(C)){{ZH4*n=((ZH4*)Zh(sizeof(*n)));*n=Zyg;((((ZH4*)(n)))->Zxb)=(a1);R=((T0*)n);}}else if(Zth1(C)){{Zs1*n=((Zs1*)Zh(sizeof(*n)));
*n=ZIl;ZxJ(n,(T11)(Zrs(0)),a1);R=((T0*)n);}}else if(ZGh1(C)){{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zel;ZqH(n,a1);R=((T0*)n);}}else if(ZAh1(C)){
{ZN4*n=((ZN4*)Zh(sizeof(*n)));*n=ZOg;ZiW(n,a1,((T3)'\000'));R=((T0*)n);}}else if((T6)((Zih1(C))||((T6)(ZHh1(C))))){{Zy9*n=((Zy9*)Zh(sizeof(*n)));
*n=Z4m;ZRZ(n,a1,(T5)(0.0),(T0*)C);R=((T0*)n);}}return R;}T6 ZIh1(ZX4*C){T6 R=0;R=((T6)(ZjW(((C)->ZNc))));return R;}void ZJh1(ZX4*C,T0*a1){
ZZs(((T7*)a1),((T3)'\045'));if(ZYg1(C)){ZZs(((T7*)a1),((T3)'R'));}else{ZZs(((T7*)a1),((T3)'E'));}ZQs(Zah1(C),a1);ZZs(((T7*)a1),((T3)'\045'));
}T6 ZKh1(ZX4*C){T6 R=0;R=((T6)(ZeH(((C)->ZNc))));return R;}T6 ZYg1(ZX4*C){T6 R=0;R=((T6)(ZaH(((C)->ZNc))));return R;}T6 ZLh1(ZX4*C){T6
R=0;T0*ZyS=Zo;ZyS=Zo;R=((T6)((ZyS)!=((void*)(Zo))));return R;}void ZMh1(ZX4*C){ZXZ(((C)->ZNc));}void ZNh1(ZX4*C){ZZZ(((C)->ZNc));}void
Zhh1(ZX4*C,T0*a1){ZNS(((C)->ZNc),a1);}T0*ZOh1(ZX4*C,T0*a1){T0*R=Zo;R=Z0_(((C)->ZNc),a1);return R;}T0*Zsh1=Zo;T6 Z0h1(ZX4*C){T6 R=0;R=((T6)(ZQS(((C)->ZNc))));
return R;}T6 ZHh1(ZX4*C){T6 R=0;R=((T6)(ZSS(((C)->ZNc))));return R;}void ZPh1(ZX4*C,T0*a1){ZUS(a1,ZVS);if(ZYg1(C)){ZUS(a1,ZWS);}else{
ZUS(a1,Z2_);}ZXS(a1,((T3)'\n'));}T6 ZQh1(ZX4*C){T6 R=0;R=((T6)(Z4_(((C)->ZNc))));return R;}T6 ZRh1(ZX4*C,T0*a1){T6 R=0;T0*Z181=Zo;if(ZSh1(a1)){
Z181=a1;if(Zo!=(Z181)){switch(((T0*)Z181)->id){case 264:break;default:Z181=Zo;}}if(((((ZB8*)(((C)->ZUg)))->Zre))==((void*)((((ZB8*)(((((ZX4*)Z181))->ZUg)))->Zre)))){
R=((T6)(1));}else{R=((T6)(ZYF(((C)->ZNc),a1)));}}else{R=((T6)(ZYF(((C)->ZNc),a1)));}if(!(R)){ZzF(((C)->Zxb));}return R;}T0*ZTh1(ZX4*C){
T0*R=Zo;if(!(ZMF(&(((C)->Zxb))))){R=Z0T(&(((C)->Zxb)));}return R;}T0*ZUh1(ZX4*C){T0*R=Zo;R=ZKI(((C)->ZNc));return R;}T6 ZGh1(ZX4*C){T6
R=0;R=((T6)(Z2T(((C)->ZNc))));return R;}void ZVh1(ZX4*C){T2 _i=0;if((Z3)(((((T77*)(Zsh1))->ZRb))<(Zrs(0)))){ZDz((T77*)(Zsh1),((C)->Zxb));
}else if((T6)((ZBz((T77*)(Zsh1),((C)->Zxb)))&&((T6)((Z3)((Zwz((T77*)(Zsh1),((C)->Zxb)))>(Zrs(2))))))){{T76 Z3w;ZzF((*(Z3w=ZEz((T77*)(Zsh1)),&Z3w)));
}{T0*b1=ZvF(61,"Unable to compute this anchored type mark (see next message).");ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));_i=Zrs(0);while(!((Z3)((_i)>((((T77*)(Zsh1))->ZRb)))))
{{T76 Z3w;ZzF((*(Z3w=Zyz((T77*)(Zsh1),_i),&Z3w)));}_i=(Z3)(((_i))+(Zrs(1)));}Zzh1(Z581);}else{ZDz((T77*)(Zsh1),((C)->Zxb));}}T0*ZWh1(ZX4*C,T0*a1){
T0*R=Zo;T0*_rc=Zo;T0*_rt=Zo;ZVh1(C);_rc=Z8G(a1);_rt=ZXh1(((Ze4*)_rc),((C)->ZUg),a1);Zrh1(C);if((((C)->ZNc))==((void*)(Zo))){(C->ZNc)=_rt;
R=((T0*)(C));}else if((T6)(((((C)->ZNc))==((void*)(_rt)))||((T6)((ZDF(((C)->ZNc)))==((void*)(ZDF(_rt))))))){R=((T0*)(C));}else{{ZX4*n=((ZX4*)Zh(sizeof(*n)));
*n=ZWg;Zdh1(n,(T0*)C,_rt);R=((T0*)n);}}return R;}T6 Zqh1(ZX4*C,T0*a1){T6 R=0;T2 _i=0;T0*ZYh1=Zo;T0*ZZh1=Zo;T0*Z_h1=Zo;_i=Zrs(1);ZYh1=ZWh1(C,(((Ze4*)((((((ZC3*)(((((Zc3*)a1))->Z9e))))->ZPb))[(_i)-(Zrs(1))]))->Z0c));
Z_h1=ZDF(ZYh1);R=((T6)(1));_i=(Z3)(((_i))+(Zrs(1)));while(!((T6)((!(R))||((T6)((Z3)((_i)>((Z3)(((((((ZC3*)(((((Zc3*)a1))->Z9e))))->ZRb)))+(Zrs(1))))))))))
{ZZh1=ZWh1(C,(((Ze4*)((((((ZC3*)(((((Zc3*)a1))->Z9e))))->ZPb))[(_i)-(Zrs(1))]))->Z0c));R=((T6)((Z_h1)==((void*)(ZDF(ZZh1)))));_i=(Z3)(((_i))+(Zrs(1)));
}return R;}T0*Z0i1(ZX4*C){T0*R=Zo;T0*Z9T=Zo;Z9T=Zmh1(C);if((Z9T)!=((void*)(Zo))){R=ZrS(((T80*)Z9T));}return R;}T6 Z1i1(ZX4*C){T6 R=0;
R=((T6)(ZbT(((C)->ZNc))));return R;}T0*Zfh1(ZX4*C){T0*R=Zo;if((((C)->ZJc))!=((void*)(Zo))){R=((C)->ZJc);}else if((((C)->ZNc))!=(Zo)){
(C->ZJc)=ZdT(((C)->ZNc));R=((C)->ZJc);}return R;}void Z2i1(ZX4*C){Zc_(((C)->ZNc));}void Z3i1(ZX4*C){Ze_(((C)->ZNc));}void Z4i1(ZX4*C){
ZfT(((C)->ZNc));}void Z5i1(ZX4*C){Zh_(((C)->ZNc));}T6 Z6i1(ZX4*C){T6 R=0;R=((T6)(Z2H(((C)->ZNc))));return R;}T6 Z7i1(ZX4*C){T6 R=0;R=((T6)(ZXF(((C)->ZNc))));
return R;}T0*Z8i1(ZX4*C,T0*a1){T0*R=Zo;R=ZiT(((C)->ZNc),a1);return R;}void Z9i1(ZX4*C,T0*a1){ZXw(((T7*)a1),ZZN);ZQs(Zah1(C),a1);ZZs(((T7*)a1),((T3)'\050'));
ZZs(((T7*)a1),((T3)'\051'));}void Zai1(ZZ4*C,T0*a1,T0*a2){if((((((ZB8*)a1))->Zre))==((void*)(((((ZB8*)a2))->Zre)))){ZzF(((((ZB8*)a1))->Zxb));
ZzF(((((ZB8*)a2))->Zxb));{T0*b1=ZvF(40,"New name and old name must be different.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}(C->ZYg)=a1;
(C->ZXg)=a2;}void Zbi1(Z45*C,T0*a1){T0*_rc=Zo;T0*Z641=Zo;_rc=Z8G(a1);if((Z3)(((((T84*)(ZFI))->Zcf))>=(Zrs(2)))){Z741((Zi4*)(ZsG),((C)->Zxb));
}ZcH((Zi4*)(ZsG),((T3)'\173'));Z841((Zh8*)(Zci1()),_rc);Za41((Zi4*)(ZsG),a1);Z641=((C)->Zxd);if(Zo!=(Z641)){switch(((T0*)Z641)->id){case
257:break;default:Z641=Zo;}}if((T6)(((Z641)!=((void*)(Zo)))&&((T6)(Zb41(((Zu7*)Z641)))))){Z7I((Zi4*)(ZsG),Zc41(((Zu7*)Z641)));Z7I((Zi4*)(ZsG),Zd41);
}}void Zdi1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));}T6 Zei1(Z45*C,T0*a1){T6 R=0;T0*ZWX=Zo;T0*ZTW=Zo;T0*ZXX=Zo;
R=((T6)((T6)((Z7V(a1))&&((T6)((ZvG(a1))==((void*)(a1)))))));if((T6)((R)&&((T6)((((C)->Z_b))!=((void*)(Zo)))))){ZWX=(((ZS7*)(((C)->Z_b)))->Z0c);
ZXX=(((T80*)((((T82*)(ZbK(ZWX)))->Zkc)))->Zre);ZTW=(((ZB8*)((((ZS7*)(((C)->Z_b)))->Zkc)))->Zre);if((ZkR)==((void*)(ZTW))){R=((T6)((T6)(((T6)(((T6)(((T6)(((T6)(((ZfP)==((void*)(ZXX)))||((T6)((ZqP)==((void*)(ZXX))))))||((T6)((ZNP)==((void*)(ZXX))))))||((T6)((ZmP)==((void*)(ZXX))))))||((T6)((ZOP)==((void*)(ZXX))))))||((T6)((ZPP)==((void*)(ZXX)))))));
}else if((ZwQ)==((void*)(ZTW))){R=((T6)((ZNP)==((void*)(ZXX))));}else if((ZaS)==((void*)(ZTW))){R=((T6)((T6)(((T6)(((ZfP)==((void*)(ZXX)))||((T6)((ZqP)==((void*)(ZXX))))))||((T6)((ZmP)==((void*)(ZXX)))))));
}else{R=((T6)(0));}}return R;}void Zfi1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}T0*Zgi1(Z45*C){T0*R=Zo;
if((((C)->Zyd))!=((void*)(Zo))){R=ZVM(((C)->Zyd));}return R;}void Zhi1(Z45*C){T0*ZaM=Zo;ZaM=Zgi1(C);if((ZaM)!=((void*)(Zo))){ZpG(((Zm3*)ZaM));
}}T2 Zii1(Z45*C){T2 R=0;if((((C)->Zyd))!=((void*)(Zo))){R=Z5Y(((C)->Zyd));}return R;}void Zji1(Z45*C){T0*_t=Zo;T0*ZPW=Zo;T6 Zl41=0;_t=((C)->ZBb);
if((_t)==((void*)(Zo))){_t=ZvG(ZOG(((C)->Zxd)));}if(ZaH(_t)){Zbi1(C,_t);if((((C)->Z_b))!=((void*)(Zo))){Zm41((Zi4*)(ZsG),((C)->Z_b),Zgi1(C));
ZvX(((C)->Z_b));if(Zl41){Zn41((Zi4*)(ZsG));}ZwX((Zi4*)(ZsG));}Zki1(C,_t);}else{ZI01(((C)->Zxd));ZcH((Zi4*)(ZsG),((T3)'\075'));ZcH((Zi4*)(ZsG),((T3)'M'));
ZtI((Zi4*)(ZsG),(T11)(ZuI(_t)));Z7I((Zi4*)(ZsG),Z8M);if((((C)->Z_b))!=((void*)(Zo))){ZPW=((C)->Z_b);if(Zo!=(ZPW)){switch(((T0*)ZPW)->id){
case 435:break;default:ZPW=Zo;}}Zp41((Zi4*)(ZsG),ZPW,((C)->Zxd),Zo);}}}void Zki1(Z45*C,T0*a1){T0*Z641=Zo;Z641=((C)->Zxd);if(Zo!=(Z641)){
switch(((T0*)Z641)->id){case 257:break;default:Z641=Zo;}}if((T6)(((Z641)==((void*)(Zo)))||((T6)(!(Zb41(((Zu7*)Z641))))))){ZI01(((C)->Zxd));
Z7I((Zi4*)(ZsG),Zq41);}if(Z9H((Zi4*)(ZsG),a1)){ZcH((Zi4*)(ZsG),((T3)'n'));ZfH((Zi4*)(ZsG));ZcH((Zi4*)(ZsG),((T3)'\073'));}ZcH((Zi4*)(ZsG),((T3)'\175'));
ZcH((Zi4*)(ZsG),((T3)'\n'));}T6 Zli1(Z45*C,T0*a1){T6 R=0;T0*_t=Zo;if((((C)->ZBb))!=((void*)(Zo))){_t=((C)->ZBb);}else{_t=ZOG(((C)->Zxd));
}if(Zs41(_t)){}else if(ZQS(_t)){}else{if((((C)->Zyd))==((void*)(Zo))){R=((T6)(Z7G(((C)->Zxd),a1)));}else{R=((T6)(Zt41(((C)->Zyd),a1)));
}}return R;}void Zmi1(Z45*C,T76 a1,T0*a2,T0*a3,T0*a4){(C->Zxb)=a1;(C->ZBb)=a2;(C->Zxd)=a3;(C->Zyd)=a4;}void Zni1(T0*a1){{T0*b1=a1;ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}T0*Zci1(void){if(ZDI==0){ZDI=1;{{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZGk;ZCI=((T0*)n);}}}return ZCI;}void Zoi1(Z45*C){
T0*ZaM=Zo;ZaM=Zgi1(C);if((ZaM)!=((void*)(Zo))){ZTG(((Zm3*)ZaM));}}T6 Zpi1(Z45*C){T6 R=0;T0*ZaM=Zo;if(ZYG(((C)->Zxd))){R=((T6)(1));}else
if((((C)->Z_b))!=((void*)(Zo))){ZaM=Zgi1(C);if((ZaM)!=((void*)(Zo))){R=((T6)(ZVG(((Zm3*)ZaM))));}}return R;}T6 Zqi1(Z45*C){T6 R=0;T0*_t=Zo;
if(Z_G(((C)->Zxd))){if((T6)(((Zgi1(C))==((void*)(Zo)))||((T6)(Z0H((Zm3*)(Zgi1(C))))))){_t=((C)->ZBb);if((_t)==((void*)(Zo))){_t=ZOG(((C)->Zxd));
}R=((T6)(Zei1(C,_t)));}}return R;}void Zri1(Z45*C,T0*a1){T0*_rt=Zo;T0*ZmH=Zo;T0*ZnH=Zo;_rt=ZvG(a1);if((((T41*)(Z1G))->ZJk)){}else if((((T82*)(ZbK(_rt)))->Zfg)){
ZsS(_rt,ZvF(14," is deferred. "));Zdi1(((C)->Zxb),ZvF(21,"Cannot create object."));}if(ZiY(a1)){ZmH=((((C)->Zxb)).Zqb);ZnH=ZrS((T80*)(ZjY(a1)));
if((ZmH)==((void*)(ZnH))){ZzF(((C)->Zxb));{T0*b1=ZvF(38,"Creation call on formal generic type (");ZXw((T7*)(ZwF),b1);}ZsS(a1,ZvF(2,ZCn));
ZEF((T75*)(ZyF));}}if(Z2H(a1)){((((T41*)((T41*)(Z1G))))->ZPk)=(1);}ZeL((Ze4*)(Z8G(_rt)));}void Zsi1(Z45*C,T0*a1){T0*_w=Zo;_w=ZFG(((C)->Zxd),a1);
if((_w)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGG(((C)->Zxd)),&Z3w)));}Zni1(ZvF(33,"Bad writable target for creation."));}else{(C->Zxd)=_w;
}}void Zti1(Z45*C,T0*a1){T0*_fn=Zo;T0*ZqY=Zo;T0*ZAf=Zo;T0*ZaM=Zo;T2 ZrY=0;T0*_w=Zo;T0*_rc=Zo;T0*_bf=Zo;_rc=Z8G(a1);if((((C)->Zyd))==((void*)(Zo))){
(C->Z_b)=ZsY(((Ze4*)_rc));if((((C)->Z_b))!=((void*)(Zo))){}else if(((((T82*)(ZbK(a1)))->Zng))!=(Zo)){{T0*b1=ZvF(27,"Creation clause exists for ");
ZXw((T7*)(ZwF),b1);}ZsS(a1,ZvF(2,ZHn));Zfi1(((C)->Zxb),ZvF(27,"You must use a constructor."));}}else{_fn=(((ZZ6*)(((C)->Zyd)))->ZZb);
ZAf=((((((ZB8*)_fn))->Zxb)).Zqb);ZqY=ZbK(a1);if(ZtY(a1)){_fn=ZuY(((T82*)ZqY),ZAf,_fn);if((_fn)==((void*)(Zo))){_fn=(((ZZ6*)(((C)->Zyd)))->ZZb);
ZvY(_fn);{T0*b1=ZvF(20," Type to create is \"");ZXw((T7*)(ZwF),b1);}{T0*b1=ZDF(a1);ZXw((T7*)(ZwF),b1);}Zni1(ZwY);}}(C->Z_b)=ZaL(((Ze4*)_rc),_fn);
if((((C)->Z_b))==((void*)(Zo))){Zui1(C,_fn);}else{_bf=ZyV(((C)->Z_b));ZyY(ZyV(((C)->Z_b)),((((ZB8*)_fn))->Zxb));}if((((T41*)(Z1G))->ZJk)){
}else if(!(ZzY((T82*)(((((Ze4*)_rc))->Zqb)),_fn))){ZzF((((ZB8*)((((ZZ6*)(((C)->Zyd)))->ZZb)))->Zxb));ZzF(((((ZB8*)_fn))->Zxb));{T0*b1=((((ZB8*)_fn))->Zre);
ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(32," is not in the creation list of ");ZXw((T7*)(ZwF),b1);}ZsS(a1,ZMJ);ZEF((T75*)(ZyF));}ZAY((Ze4*)((((ZS7*)(((C)->Z_b)))->Znf)),Z8G(((C)->Z0c)));
if((ZqG(((C)->Z_b)))!=((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZCF(((C)->Z_b)),&Z3w)));}ZzF(((((ZB8*)_fn))->Zxb));Zni1(ZUW);}ZrY=Zii1(C);if((Z3)((ZrY)>(Zrs(0)))){
ZaM=ZaG((Zm3*)(Zgi1(C)),((C)->Z0c));if((ZaM)==((void*)(Zo))){{T76 Z3w;Zfi1((*(Z3w=ZbG((Zm3*)(ZVM(((C)->Zyd)))),&Z3w)),ZJX);}}}{T76 Z3w;
ZTF((*(Z3w=ZBY(((C)->Zyd)),&Z3w)),ZaM,((C)->Z_b));}_w=((C)->Zxd);if((_w)==((void*)(Zo))){_w=(((ZZ6*)(((C)->Zyd)))->ZYb);}(C->Zyd)=ZCY(((C)->Zyd),((C)->Z0c),_w,ZaM,((C)->Z_b));
}}T0*Zvi1(Z45*C,T0*a1){T0*R=Zo;{Zn8*n=((Zn8*)Zh(sizeof(*n)));*n=ZVk;Z1N(n,(T0*)C,a1);R=((T0*)n);}return R;}T0*Zwi1(Z45*C,T0*a1){T0*R=Zo;
T0*_t=Zo;if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;Zsi1(C,a1);if((((C)->ZBb))!=((void*)(Zo))){Zxi1(C);_t=((C)->ZBb);}else{_t=ZOG(((C)->Zxd));
}Zri1(C,_t);Zti1(C,_t);R=((T0*)(C));}else{{Z45*n=((Z45*)Zh(sizeof(*n)));*n=Z0h;Zmi1(n,((C)->Zxb),((C)->ZBb),((C)->Zxd),((C)->Zyd));R=((T0*)n);
}R=Zwi1(((Z45*)R),a1);}return R;}void Zyi1(Z45*C){T0*ZaM=Zo;ZaM=Zgi1(C);if((ZaM)!=((void*)(Zo))){ZAH(((Zm3*)ZaM));}}void Zui1(Z45*C,T0*a1){
ZzF((((ZB8*)((((ZZ6*)(((C)->Zyd)))->ZZb)))->Zxb));ZzF(((((ZB8*)a1))->Zxb));Zni1(ZvF(29,"Creation procedure not found."));}void Zxi1(Z45*C){
T0*_t=Zo;T0*ZAl=Zo;_t=Z9L(((C)->ZBb),((C)->Z0c));if((T6)(((_t)==((void*)(Zo)))||((T6)(!(Z7V(_t)))))){{T76 Z3w;ZzF((*(Z3w=Z3L(((C)->ZBb)),&Z3w)));
}Zni1(ZvF(22,"Invalid explicit type."));}else{(C->ZBb)=_t;}if((((C)->Zxd))!=((void*)(Zo))){ZAl=ZOG(((C)->Zxd));if(!(ZYF(((C)->ZBb),ZAl))){
Zni1(ZvF(24," Bad explicit type mark."));}if((ZDF(((C)->ZBb)))!=((void*)(ZDF(ZAl)))){{T76 Z3w;ZJY((*(Z3w=Z3L(((C)->ZBb)),&Z3w)),((C)->ZBb),ZAl);
}}}}T6 Zv81(T82*C,T0*a1){T6 R=0;Zzi1((ZB8*)(ZAi1()),a1);R=((T6)(Zfc1(C,ZAi1())));return R;}T0*ZBi1(T82*C,T0*a1,T0*a2){T0*R=Zo;T0*ZCi1=Zo;
if((((T84*)(ZFI))->Z8f)){ZCi1=ZkC((Z03*)(((C)->Zsg)),a2);if((ZCi1)==((void*)(Zo))){{ZV4*n=((ZV4*)Zh(sizeof(*n)));*n=ZTg;{ZV4*C1=n;ZwD(C1,Zft(193));
}ZCi1=((T0*)n);}ZhC((Z03*)(((C)->Zsg)),ZCi1,a2);}R=ZxD(((ZV4*)ZCi1),a1);if((R)==((void*)(Zo))){R=ZDi1(C,a1,a2);ZsD(((ZV4*)ZCi1),R,a1);
}}else{R=ZDi1(C,a1,a2);}return R;}T0*ZEi1(T82*C,T0*a1,T0*a2){T0*R=Zo;if((((C)->Zmg))==((void*)(Zo))){if(!(ZFi1(C))){R=ZGi1((T82*)(ZHi1()),a1,a2);
}}else{R=ZIi1((Z3a*)(((C)->Zmg)),a1,a2);}return R;}T0*ZJi1(T82*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;if((((C)->Zmg))==((void*)(Zo))){R=ZJi1((T82*)(ZHi1()),a1,a2,a3);
}else{R=ZKi1((Z3a*)(((C)->Zmg)),a1,a2,a3);}return R;}void ZLi1(T82*C){T2 _i=0;ZXy((Z34*)(ZMi1),(T0*)C);if((((((Z34*)(ZMi1))->ZPb))[Zrs(0)])==((void*)(C))){
{T0*b1=ZvF(26,"Cyclic inheritance graph: ");ZXw((T7*)(ZwF),b1);}_i=Zrs(0);while(!((Z3)((_i)>((((Z34*)(ZMi1))->ZRb))))){{T0*b1=(((T80*)((((T82*)(((((Z34*)(ZMi1))->ZPb))[_i]))->Zkc)))->Zre);
ZXw((T7*)(ZwF),b1);}if((Z3)((_i)<((((Z34*)(ZMi1))->ZRb)))){{T0*b1=ZvF(2,ZEn);ZXw((T7*)(ZwF),b1);}}_i=(Z3)(((_i))+(Zrs(1)));}{T0*b1=ZvF(5,", ...");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}else if((((C)->Zmg))!=((void*)(Zo))){ZNi1((Z3a*)(((C)->Zmg)));}}T0*ZOi1=Zo;int ZPi1=0;T0*ZHi1(void){
if(ZPi1==0){ZPi1=1;{T0*_cn=Zo;{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Z721(n,ZeP);_cn=((T0*)n);}ZOi1=Z821(_cn);}}return ZOi1;}T0*ZQi1(T82*C,T0*a1){
T0*R=Zo;T0*_ct=Zo;ZAK((Zr6*)(ZRi1()));_ct=((((ZS7*)a1))->Z0c);ZSi1(C,((((ZS7*)a1))->Zkc));R=ZBK((Zr6*)(ZRi1()),a1,_ct);return R;}T0*ZTi1(T82*C,T0*a1){
T0*R=Zo;if((((C)->Zmg))==((void*)(Zo))){if(!(ZFi1(C))){R=ZuH((T82*)(ZHi1()),a1);}}else{R=ZUi1((Z3a*)(((C)->Zmg)),a1);}return R;}T0*ZVi1(void){
if(ZKK==0){ZKK=1;{T76 ZMK={Zo,Zo,0};{Zk3*n=((Zk3*)Zh(sizeof(*n)));*n=Zge;ZJK=((T0*)n);ZNK(n,ZMK);}}}return ZJK;}void ZWi1(T76 a1,T0*a2){
ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));}T0*ZuY(T82*C,T0*a1,T0*a2){T0*R=Zo;if((C)==((void*)(a1))){R=a2;}else{R=ZBi1(((T82*)a1),(T0*)C,a2);
if((R)==((void*)(Zo))){ZzF(((((ZB8*)a2))->Zxb));{T0*b1=ZXi1;ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)a2))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(8,"\" from \"");
ZXw((T7*)(ZwF),b1);}{T0*b1=(((T80*)(((((T82*)a1))->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(16,"\" not found in \"");ZXw((T7*)(ZwF),b1);
}{T0*b1=(((T80*)(((C)->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(2,Zwn);ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}return R;}T6 ZzY(T82*C,T0*a1){
T6 R=0;T0*_cc=Zo;T0*_bc=Zo;T0*_cn=Zo;T0*_cl=Zo;if((((C)->Zng))==((void*)(Zo))){{T0*b1=(((T80*)(((C)->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);
}{T0*b1=ZYi1;ZXw((T7*)(ZwF),b1);}ZzF(((((ZB8*)a1))->Zxb));ZxF((T75*)(ZyF));}else{_cc=ZZT((Zo1*)(((C)->Zng)),a1);if((_cc)==((void*)(Zo))){
{T0*b1=ZXi1;ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)a1))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZZi1;ZXw((T7*)(ZwF),b1);}{T0*b1=(((T80*)(((C)->Zkc)))->Zre);
ZXw((T7*)(ZwF),b1);}ZzF(((((ZB8*)a1))->Zxb));{T0*b1=ZvF(41,". This creation call is thus not allowed.");ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));
}else{R=((T6)(1));_bc=Z_i1(((ZB8*)a1));if((_bc)!=((void*)(Zo))){_cn=((((T82*)_bc))->Zkc);_cl=((((ZW1*)_cc))->Zec);R=((T6)(ZuF(((ZD*)_cl),_cn)));
if(!(R)){ZzF(((((ZB8*)a1))->Zxb));{T0*b1=ZvF(89,"Forbidden creation call (i.e. exportation rules violated). Creation is only allowed from ");
ZXw((T7*)(ZwF),b1);}{T0*b1=ZAF(((ZD*)_cl));ZXw((T7*)(ZwF),b1);}ZBF(((ZD*)_cl));{T3 b1=((T3)'\056');ZZs((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));
}}}}return R;}T6 Z0j1(T82*C){T6 R=0;if((((C)->Zqg))==(Zrs(0))){(C->Zqg)=Z1j1((T84*)(ZFI),(T0*)C);}R=((T6)((Z3)((((C)->Zqg))>=(Zrs(6)))));
return R;}T6 Z2j1(T82*C){T6 R=0;R=((T6)(((((T80*)(((C)->Zkc)))->Zre))==((void*)(ZeP))));return R;}void Z3j1(T82*C,T0*a1,T0*a2){T76 _sp={Zo,Zo,0};
T0*_at=Zo;T0*_er=Zo;T0*_n=Zo;T0*Zj81=Zo;T0*Zxb1=Zo;T0*_rf=Zo;T0*_rc=Zo;_rc=ZWV(((ZW9*)a1));Zzi1((ZB8*)(ZAi1()),ZeR);_rf=Z8E(((Zj6*)(((((Ze4*)_rc))->Zug))),ZAi1());
if((_rf)==((void*)(Zo))){{T76*C1=&_sp;T0*b1=(T0*)C;Z4j1(C1,(T2)(Zrs(1)),(T2)(Zrs(1)),((((T82*)b1))->_id),b1);}{Zi1*n=((Zi1*)Zh(sizeof(*n)));
*n=Zse;ZA81(n,_sp,ZrQ);Zj81=((T0*)n);}{Zy7*n=((Zy7*)Zh(sizeof(*n)));*n=Z0k;Z2d1(n,_sp,Zo);_at=((T0*)n);}{ZH6*n=((ZH6*)Zh(sizeof(*n)));
*n=Z8j;Z081(n,Z5j1(1,((T0*)Z0K(Zj81,_at))));Zxb1=((T0*)n);}{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z6j1(n,ZeR,_sp);_n=((T0*)n);}{Zq7*n=((Zq7*)Zh(sizeof(*n)));
*n=ZTj;Z7j1(n,((T0*)Z8j1(_n)),Zxb1,a2,Zo,Zo,Zo,((T0*)Z9j1()),Zo);_er=((T0*)n);}_rf=Zaj1(((Zq7*)_er),a1,_n);Zbj1(((ZS7*)_rf));}}T0*Zcj1(T82*C){
T0*R=Zo;Zdj1(C);R=ZST((Zo1*)(((C)->Zng)));return R;}T0*ZGi1(T82*C,T0*a1,T0*a2){T0*R=Zo;T0*ZQX=Zo;T0*Zej1=Zo;T0*Zfj1=Zo;T0*Zgj1=Zo;T2 _i=0;
T0*Zhj1=Zo;R=ZED((Z25*)(((C)->Zug)),a2);if((R)!=((void*)(Zo))){ZQX=ZEi1(C,a1,a2);if((ZQX)!=((void*)(Zo))){Zij1(a1,ZQX,R);Zej1=ZQX;if(Zo!=(Zej1)){
switch(((T0*)Zej1)->id){case 338:case 344:case 345:case 346:case 350:case 351:case 352:case 353:break;default:Zej1=Zo;}}if((Zej1)!=((void*)(Zo))){
{T76 Z3w;ZzF((*(Z3w=ZGJ(ZQX),&Z3w)));}{T76 Z3w;ZzF((*(Z3w=ZGJ(R),&Z3w)));}{T0*b1=ZvF(37,"Constant feature cannot be redefined.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}Zfj1=((((Z85*)ZQX))->Zfc);_i=ZSJ(((Zx8*)Zfj1));while(!((Z3)((_i)<(Zrs(1))))){Zgj1=ZRJ(((Zx8*)Zfj1),_i);if(Zjj1(((ZB8*)Zgj1))){
if((((((ZB8*)Zgj1))->Z3n))==((void*)(((((ZB8*)a2))->Z3n)))){ZzF(((((ZB8*)Zgj1))->Zxb));{T76 Z3w;ZzF((*(Z3w=ZGJ(R),&Z3w)));}{T0*b1=ZvF(33,"Cannot redefine a frozen feature.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}_i=(Z3)(((_i))-(Zrs(1)));}if(!(Zkj1(R,ZQX,a1))){Zhj1=R;if(Zo!=(Zhj1)){switch(((T0*)Zhj1)->id){
case 420:break;default:Zhj1=Zo;}}if((T6)(((Zhj1)!=((void*)(Zo)))&&((T6)(Zlj1(((ZN8*)Zhj1)))))){}else{{T76 Z3w;ZzF((*(Z3w=ZGJ(ZQX),&Z3w)));
}{T76 Z3w;ZzF((*(Z3w=ZGJ(R),&Z3w)));}{T0*b1=ZvF(39,"Incompatible headings for redefinition.");ZXw((T7*)(ZwF),b1);}ZdG(((((Ze4*)a1))->Z0c));
ZEF((T75*)(ZyF));}}if(Zmj1(ZQX)){}else if(Znj1(C,a2)){}else{{T76 Z3w;ZzF((*(Z3w=ZGJ(R),&Z3w)));}{T76 Z3w;ZzF((*(Z3w=ZGJ(ZQX),&Z3w)));
}{T0*b1=ZvF(24,"Invalid redefinition in ");ZXw((T7*)(ZwF),b1);}{T0*b1=(((T80*)(((C)->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(20,". Missing redefine \?");
ZXw((T7*)(ZwF),b1);}ZxF((T75*)(ZyF));}}}else{R=ZEi1(C,a1,a2);}return R;}void Zoj1(T76 a1,T0*a2){ZzF(a1);{T0*b1=a2;ZXw((T7*)(ZwF),b1);
}ZxF((T75*)(ZyF));}void Zdj1(T82*C){if((((C)->Zng))==((void*)(Zo))){ZzF((((T80*)(((C)->Zkc)))->Zxb));{T0*b1=ZvF(51,"Bad root class (this class has no creation clause).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}T6 Znj1(T82*C,T0*a1){T6 R=0;if((((C)->Zmg))!=((void*)(Zo))){R=((T6)(Zpj1((Z3a*)(((C)->Zmg)),a1)));
}return R;}T0*Zqj1(T82*C,T0*a1){T0*R=Zo;T0*_ct=Zo;Z4K((Zr6*)(ZRi1()));_ct=((((ZS7*)a1))->Z0c);ZSi1(C,((((ZS7*)a1))->Zkc));R=ZkK((Zr6*)(ZRi1()),a1,_ct);
return R;}T0*Zrj1=Zo;int Zsj1=0;T0*Ztj1(void){if(Zsj1==0){Zsj1=1;{T0*_cn=Zo;{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Z721(n,ZpK);_cn=((T0*)n);
}Zrj1=Z821(_cn);}}return Zrj1;}T6 ZtD(T82*C,T0*a1){T6 R=0;R=((T6)((C)==((void*)(a1))));return R;}T6 Zuj1(T82*C,T0*a1){T6 R=0;if((((C)->Ztg))==((void*)(Zo))){
{T52*n=((T52*)Zh(sizeof(*n)));*n=M52;ZRz(n,(T2)(Zrs(4)));(C->Ztg)=((T0*)n);}ZPz((T52*)(((C)->Ztg)),a1);}else if(ZNz((T52*)(((C)->Ztg)),a1)){
R=((T6)(1));}else{ZPz((T52*)(((C)->Ztg)),a1);}return R;}void ZWc1(T82*C,T0*a1){(C->Zoc)=a1;{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Z721(n,a1);
(C->Zkc)=((T0*)n);}(C->_id)=ZQY((T40*)(Zvj1()),a1);Zwj1(C);}void Zxj1(T82*C){if(((C)->Zfg)){{T82*C1=C;Zoj1((((T80*)(((C1)->Zkc)))->Zxb),Zyj1);
}}else if(((C)->Zhg)){Zoj1((((T80*)(((C)->Zkc)))->Zxb),Zzj1);}(C->Zgg)=((T6)(1));}T0*ZAj1(T82*C,T0*a1){T0*R=Zo;T0*_f=Zo;_f=ZED((Z25*)(((C)->Zug)),a1);
if((_f)!=((void*)(Zo))){R=((((Z85*)_f))->Zec);}else if(ZFi1(C)){}else if((((C)->Zmg))==((void*)(Zo))){R=ZAj1((T82*)(ZHi1()),a1);}else{
R=ZBj1((Z3a*)(((C)->Zmg)),a1);}return R;}T0*ZCj1=Zo;int ZDj1=0;T0*ZRi1(void){if(ZDj1==0){ZDj1=1;{{Zr6*n=((Zr6*)Zh(sizeof(*n)));*n=ZVi;
ZCj1=((T0*)n);}}}return ZCj1;}T6 ZEj1(T82*C){T6 R=0;if((((C)->Zqg))==(Zrs(0))){(C->Zqg)=Z1j1((T84*)(ZFI),(T0*)C);}R=((T6)((Z3)((((C)->Zqg))>=(Zrs(4)))));
return R;}void ZFj1(T82*C,T0*a1){T76 _sp={Zo,Zo,0};T0*_at=Zo;T0*_er=Zo;T0*_n=Zo;T0*Zj81=Zo;T0*Zxb1=Zo;T0*_rf=Zo;T0*_rc=Zo;_rc=ZWV(((ZW9*)a1));
Zzi1((ZB8*)(ZAi1()),ZyQ);_rf=Z8E(((Zj6*)(((((Ze4*)_rc))->Zug))),ZAi1());if((_rf)==((void*)(Zo))){{T76*C1=&_sp;T0*b1=(T0*)C;Z4j1(C1,(T2)(Zrs(1)),(T2)(Zrs(1)),((((T82*)b1))->_id),b1);
}{Zi1*n=((Zi1*)Zh(sizeof(*n)));*n=Zse;ZA81(n,_sp,ZrQ);Zj81=((T0*)n);}{Zy7*n=((Zy7*)Zh(sizeof(*n)));*n=Z0k;Z2d1(n,_sp,Zo);_at=((T0*)n);
}{ZH6*n=((ZH6*)Zh(sizeof(*n)));*n=Z8j;Z081(n,Z5j1(1,((T0*)Z0K(Zj81,_at))));Zxb1=((T0*)n);}{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Z6j1(n,ZyQ,_sp);
_n=((T0*)n);}{Z85*n=((Z85*)Zh(sizeof(*n)));*n=Z4h;ZGj1(n,((T0*)Z8j1(_n)),Zxb1,Zo,Zo,Zo,((T0*)Z9j1()),Zo);_er=((T0*)n);}_rf=ZHj1(((Z85*)_er),a1,_n);
Zbj1(((ZS7*)_rf));}}void ZIj1(T82*C,T0*a1){if((((C)->Zdg))==((void*)(Zo))){{ZY7*n=((ZY7*)Zh(sizeof(*n)));*n=Zqk;ZJj1(n,a1);(C->Zdg)=((T0*)n);
}}else{Zoz(((Zq5*)((((ZY7*)(((C)->Zdg)))->ZUb))),a1);}}void ZKj1(T82*C,T0*a1){T0*_rf=Zo;if(((C)->Zfg)){ZsS(a1,ZEd1);{T0*b1=ZvF(48," A deferred class must not be expanded (VTEC.1).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}if((((C)->Zng))!=((void*)(Zo))){ZPT((Zo1*)(((C)->Zng)),a1);}_rf=ZLj1(C,a1);}T6 ZMj1(T82*C){T6 R=0;
R=((T6)(((((T80*)(((C)->Zkc)))->Zre))==((void*)(ZBP))));return R;}T0*ZNj1(T82*C,T0*a1,T0*a2){T0*R=Zo;if((C)==((void*)(a1))){R=a2;}else{
if((((C)->Zmg))==((void*)(Zo))){R=ZuY((T82*)(ZHi1()),a1,a2);}else{((((Z32*)((Z32*)(ZOj1))))->ZRb)=(Zrs(-1));R=ZKi1((Z3a*)(((C)->Zmg)),ZOj1,a1,a2);
}}return R;}T0*ZPj1(T82*C){T0*R=Zo;Zzi1((ZB8*)(ZAi1()),ZKQ);R=ZyD((Z25*)(((C)->Zug)),ZAi1());return R;}void ZQj1(T82*C,T0*a1){if((((C)->Zog))==((void*)(Zo))){
{ZO9*n=((ZO9*)Zh(sizeof(*n)));*n=ZFm;ZRj1(n,a1);(C->Zog)=((T0*)n);}}else{ZFy(((Zt2*)((((ZO9*)(((C)->Zog)))->ZUb))),a1);}}T6 ZSj1(T82*C,T0*a1,T0*a2){
T6 R=0;if((((C)->Zmg))!=((void*)(Zo))){R=((T6)(ZTj1((Z3a*)(((C)->Zmg)),ZvG(a1),ZvG(a2))));}return R;}T0*ZOj1=Zo;void ZUj1(T82*C,T0*a1,T0*a2,T0*a3,T10
a4){(C->_id)=a4;(C->Zoc)=a1;(C->Zcg)=a3;{T80*n=((T80*)Zh(sizeof(*n)));*n=M80;Z721(n,a2);(C->Zkc)=((T0*)n);}Zwj1(C);}void ZVj1(T82*C){
if((((C)->Zjg))!=((void*)(Zo))){ZWj1((Zba*)(((C)->Zjg)));}}T0*ZXj1(T82*C,T0*a1,T0*a2){T0*R=Zo;T0*ZYj1=Zo;T0*_p=Zo;T0*ZZj1=Zo;T0*ZUJ=Zo;
ZYj1=Ztj1();if((C)!=((void*)(ZYj1))){_p=Z_j1(((T82*)ZYj1));if((_p)!=((void*)(Zo))){ZZj1=((((Zx8*)(((((Z9a*)_p))->Zfc))))->ZBd);ZUJ=ZuY(C,ZYj1,ZZj1);
if((((((ZB8*)ZUJ))->Zre))!=((void*)(((((ZB8*)a2))->Zre)))){_p=ZGi1(C,a1,ZUJ);if(Zo!=(_p)){switch(((T0*)_p)->id){case 406:break;default:
_p=Zo;}}if((_p)!=((void*)(Zo))){R=Z0k1(((Z9a*)_p),a1,ZUJ);}}}}return R;}T0*ZLj1(T82*C,T0*a1){T0*R=Zo;if((((C)->Zng))!=((void*)(Zo))){
R=ZVT((Zo1*)(((C)->Zng)),a1);}return R;}T6 Z1k1(T82*C){T6 R=0;if((((C)->Zqg))==(Zrs(0))){(C->Zqg)=Z1j1((T84*)(ZFI),(T0*)C);}R=((T6)((Z3)((((C)->Zqg))>=(Zrs(3)))));
return R;}T0*Z2k1(T82*C,T0*a1,T0*a2){T0*R=Zo;if((C)==((void*)(a1))){R=a2;}else if((((C)->Zmg))!=((void*)(Zo))){R=Z3k1((Z3a*)(((C)->Zmg)),a1,a2);
}else{R=Z2k1(((T82*)a1),a1,a2);if((R)==((void*)(Zo))){R=a2;ZzF(((((ZB8*)a2))->Zxb));{T0*b1=(((T80*)(((((T82*)a1))->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);
}{T0*b1=Z4k1;ZXw((T7*)(ZwF),b1);}{T0*b1=(((T80*)(((C)->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=Z5k1;ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));
}}return R;}T0*ZDi1(T82*C,T0*a1,T0*a2){T0*R=Zo;if(ZAD(((Z25*)(((C)->Zug))),a2)){if((((C)->Zmg))==((void*)(Zo))){R=ZNj1(((T82*)a1),(T0*)C,a2);
}else{R=Z6k1((Z3a*)(((C)->Zmg)),a1,a2);if((R)==((void*)(Zo))){R=ZNj1(((T82*)a1),(T0*)C,a2);}}}else if((((C)->Zmg))!=((void*)(Zo))){R=Z6k1((Z3a*)(((C)->Zmg)),a1,a2);
}else if(ZFi1(C)){}else{R=ZBi1((T82*)(ZHi1()),a1,a2);}return R;}void Zij1(T0*a1,T0*a2,T0*a3){T0*Zhj1=Zo;T0*_ct=Zo;T0*ZYh1=Zo;T0*ZZh1=Zo;
Zhj1=a2;if(Zo!=(Zhj1)){switch(((T0*)Zhj1)->id){case 420:break;default:Zhj1=Zo;}}if((Zhj1)!=((void*)(Zo))){Zhj1=a3;if(Zo!=(Zhj1)){switch(((T0*)Zhj1)->id){
case 420:break;default:Zhj1=Zo;}}if((Zhj1)==((void*)(Zo))){Z7k1(a2,a3,ZvF(61,"An attribute must be redefined as an attribute only (VDRD.6)."));
}else{_ct=((((Ze4*)a1))->Z0c);ZYh1=Z9L(ZvH(a2),_ct);ZZh1=Z9L(ZvH(a3),_ct);if(ZaH(ZYh1)){if(ZaH(ZZh1)){}else if(Zlj1(((ZN8*)Zhj1))){}else{
Z7k1(a2,a3,Z8k1);}}else if(ZaH(ZZh1)){Z7k1(a2,a3,Z8k1);}}}}void Z7k1(T0*a1,T0*a2,T0*a3){{T76 Z3w;ZzF((*(Z3w=ZGJ(a1),&Z3w)));}{T76 Z3w;
ZzF((*(Z3w=ZGJ(a2),&Z3w)));}{T0*b1=ZvF(18,"Bad redefinition. ");ZXw((T7*)(ZwF),b1);}{T0*b1=a3;ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}T6
ZnI(T82*C,T0*a1){T6 R=0;T0*Z9k1=Zo;if(ZID((Zk5*)(((C)->Zvg)),a1)){R=((T6)(ZGD((Zk5*)(((C)->Zvg)),a1)));}else{Z9k1=(((T80*)(((((T82*)a1))->Zkc)))->Zre);
if((Z9k1)==((void*)(ZeP))){R=((T6)(1));}else if((Z9k1)==((void*)(ZCP))){R=((T6)(1));}else if((((C)->Zmg))!=((void*)(Zo))){R=((T6)(Zak1((Z3a*)(((C)->Zmg)),a1)));
}else if((Z9k1)==((void*)(ZpK))){R=((T6)(1));}else if((Z9k1)==((void*)(ZBP))){}else if(ZMj1(C)){R=((T6)(1));}ZJD((Zk5*)(((C)->Zvg)),(T6)(R),a1);
}return R;}void Zbk1(T82*C,T0*a1){if((((C)->Zng))==((void*)(Zo))){{Zo1*n=((Zo1*)Zh(sizeof(*n)));*n=ZWc;ZUT(n,a1);(C->Zng)=((T0*)n);}}
else{Z0B(((Zg9*)((((Zo1*)(((C)->Zng)))->ZUb))),a1);}}T6 Zfc1(T82*C,T0*a1){T6 R=0;R=((T6)((ZuH(C,a1))!=((void*)(Zo))));return R;}T0*Z_j1(T82*C){
T0*R=Zo;Zzi1((ZB8*)(ZAi1()),ZOQ);if(ZAD((Z25*)(((C)->Zug)),ZAi1())){R=ZyD((Z25*)(((C)->Zug)),ZAi1());if(Zo!=(R)){switch(((T0*)R)->id){
case 406:break;default:R=Zo;}}}return R;}void Zck1(T82*C){if(((C)->Zgg)){{T82*C1=C;Zoj1((((T80*)(((C1)->Zkc)))->Zxb),Zyj1);}}else if(((C)->Zhg)){
Zoj1((((T80*)(((C)->Zkc)))->Zxb),Zdk1);}(C->Zfg)=((T6)(1));}void Zek1(T82*C,T76 a1,T0*a2,T0*a3){if((T6)(((a2)!=((void*)(Zo)))||((T6)((a3)!=((void*)(Zo)))))){
{Zh6*n=((Zh6*)Zh(sizeof(*n)));*n=Zvi;Zfk1(n,a1,a2,a3);(C->Zpg)=((T0*)n);}}}T0*Zgk1(T82*C,T0*a1){T0*R=Zo;T0*_rc=Zo;T0*_f=Zo;if((((C)->Zjg))!=(Zo)){
{T0*b1=(((T80*)(((C)->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(52," cannot be a root class since it is a generic class.");ZXw((T7*)(ZwF),b1);
}ZEF((T75*)(ZyF));}if(((C)->Zfg)){{T0*b1=(((T80*)(((C)->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(53," cannot be a root class since it is a deferred class.");
ZXw((T7*)(ZwF),b1);}ZoK((T75*)(ZyF));}_rc=Zhk1(((C)->Zkc));ZeL(((Ze4*)_rc));_f=ZGi1(C,_rc,a1);if((_f)==((void*)(Zo))){ZzF(((((ZB8*)a1))->Zxb));
{T0*b1=ZvF(25,"Root procedure not found.");ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}R=_f;if(Zo!=(R)){switch(((T0*)R)->id){case 406:break;
default:R=Zo;}}if((R)==((void*)(Zo))){{T76 Z3w;ZzF((*(Z3w=ZGJ(_f),&Z3w)));}{T0*b1=ZvF(50,"Invalid Root. Only procedure are allowed (VGCC.6).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}return R;}void Zik1(T82*C,T0*a1){if((((C)->Zmg))!=((void*)(Zo))){Zjk1((Z3a*)(((C)->Zmg)),a1);}if((((C)->Zpg))!=((void*)(Zo))){
ZxK((Zr6*)(ZRi1()),((C)->Zpg));}}T6 ZFi1(T82*C){T6 R=0;R=((T6)(((((T80*)(((C)->Zkc)))->Zre))==((void*)(ZpK))));return R;}T0*ZuH(T82*C,T0*a1){
T0*R=Zo;R=ZED((Z25*)(((C)->Zug)),a1);if((R)==((void*)(Zo))){R=ZTi1(C,a1);}return R;}void Zkk1(T82*C){if(((C)->Zgg)){Zoj1((((T80*)(((C)->Zkc)))->Zxb),Zlk1);
}else if(((C)->Zfg)){Zoj1((((T80*)(((C)->Zkc)))->Zxb),Zmk1);}(C->Zhg)=((T6)(1));Z7T(C);}T6 Znk1(T82*C){T6 R=0;if((((C)->Zqg))==(Zrs(0))){
(C->Zqg)=Z1j1((T84*)(ZFI),(T0*)C);}R=((T6)((Z3)((((C)->Zqg))>=(Zrs(5)))));return R;}T0*Zok1=Zo;int Zpk1=0;T0*ZAi1(void){if(Zpk1==0){Zpk1=1;{
{ZB8*n=((ZB8*)Zh(sizeof(*n)));*n=Z6n;Zok1=((T0*)n);Zzi1(n,ZWR);}}}return Zok1;}void ZEJ(T82*C,T0*a1){{T0*b1=ZvF(26,"Problem with undefine of \"");
ZXw((T7*)(ZwF),b1);}{T0*b1=((((ZB8*)a1))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(6,"\" in \"");ZXw((T7*)(ZwF),b1);}{T0*b1=(((T80*)(((C)->Zkc)))->Zre);
ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(2,Zwn);ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void Zwj1(T82*C){(C->Zrf)=(((T80*)(((C)->Zkc)))->Zrf);Zqk1((T41*)(Z1G),(T0*)C);
{Z25*n=((Z25*)Zh(sizeof(*n)));*n=Z_g;{Z25*C1=n;ZDD(C1,Zft(193));}(C->Zug)=((T0*)n);}{Zk5*n=((Zk5*)Zh(sizeof(*n)));*n=Zdh;ZLD(n,(T2)(Zft(256)));
(C->Zvg)=((T0*)n);}if((((T84*)(ZFI))->Z8f)){{Z03*n=((Z03*)Zh(sizeof(*n)));*n=Z0e;ZjC(n,(T2)(Zft(1024)));(C->Zsg)=((T0*)n);}}}void Zrk1(T82*C,T0*a1){
if((((C)->Zlg))!=((void*)(Zo))){if((((T41*)(Z1G))->ZJk)){}else if((((T41*)(Z1G))->ZKk)){}else{ZzF(((((T80*)a1))->Zxb));{T0*b1=Zsk1;ZXw((T7*)(ZwF),b1);
}{T0*b1=(((T80*)(((C)->Zkc)))->Zre);ZXw((T7*)(ZwF),b1);}{T0*b1=Ztk1;ZXw((T7*)(ZwF),b1);}{T0*b1=(((T88*)(((C)->Zlg)))->Zre);ZXw((T7*)(ZwF),b1);
}ZzF((((T80*)(((C)->Zkc)))->Zxb));ZoK((T75*)(ZyF));}}}T0*Zuk1(T82*C,T0*a1){T0*R=Zo;Zdj1(C);R=ZXT((Zo1*)(((C)->Zng)),a1);if((R)==((void*)(Zo))){
ZzF((((T80*)(((C)->Zkc)))->Zxb));{T0*b1=ZvF(26,"Bad root procedure name (\"");ZXw((T7*)(ZwF),b1);}{T0*b1=a1;ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(45,"\" is not a creation procedure of this class).");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}return R;}void Z7T(T82*C){if(((C)->Zgg)){Zoj1((((T80*)(((C)->Zkc)))->Zxb),Zvk1);}(C->Zig)=((T6)(1));
}T0*ZMi1=Zo;T0*ZhH(T82*C,T0*a1,T0*a2,T0*a3,T0*a4){T0*R=Zo;T0*Zwk1=Zo;T0*_bc=Zo;T0*Zxk1=Zo;T0*Zyk1=Zo;T0*ZqS=Zo;T0*ZlH=Zo;T0*_lf=Zo;T0*Z181=Zo;
T0*_cl=Zo;Zyk1=a3;ZlH=ZOG(a2);if((T6)((ZtY(ZlH))&&((T6)((ZDF(ZlH))==((void*)(ZDF(a4))))))){{T76 Z3w;Zwk1=(((*(Z3w=ZGG(a2),&Z3w))).Zqb);
}Zyk1=ZuY(C,Zwk1,a3);}else if(ZSh1(ZlH)){Z181=ZlH;if(Zo!=(Z181)){switch(((T0*)Z181)->id){case 264:break;default:Z181=Zo;}}Zxk1=((((ZX4*)Z181))->ZUg);
_bc=((((((ZB8*)Zxk1))->Zxb)).Zqb);_lf=ZuH(((T82*)_bc),Zxk1);Zwk1=ZwH(ZvH(_lf));if((Zwk1)!=((void*)(Zo))){_bc=ZbK(ZOG(a2));if((T6)(((_bc)==((void*)(Zwk1)))||((T6)(ZnI(((T82*)_bc),Zwk1))))){
if(Zfc1(((T82*)Zwk1),a3)){Zyk1=ZuY(((T82*)_bc),Zwk1,a3);}}}}else{Zwk1=ZtH(a2);if((Zwk1)!=((void*)(Zo))){if((T6)(((C)==((void*)(Zwk1)))||((T6)(ZnI(C,Zwk1))))){
if(Zfc1(((T82*)Zwk1),a3)){Zyk1=ZuY(C,Zwk1,a3);}}}}R=ZaL(((Ze4*)a1),Zyk1);if((R)==((void*)(Zo))){ZvY(a3);ZEF((T75*)(ZyF));}if(!(Z4G(a2))){
ZqS=(((T82*)(ZbK(a4)))->Zkc);_cl=Zzk1(R);if(!(ZuF(((ZD*)_cl),ZqS))){ZzF(((((ZB8*)a3))->Zxb));{T0*b1=ZvF(77,"Forbidden call (i.e. exportation rules violated) when the type of Current is ");
ZXw((T7*)(ZwF),b1);}{T0*b1=ZDF(a4);ZXw((T7*)(ZwF),b1);}{T0*b1=ZvF(42,". (See the next error report for details.)");ZXw((T7*)(ZwF),b1);
}ZxF((T75*)(ZyF));{T76 Z3w;ZzF((*(Z3w=ZCF(R),&Z3w)));}{T0*b1=ZvF(33,"This feature is only exported to ");ZXw((T7*)(ZwF),b1);}{T0*b1=ZAF(((ZD*)_cl));
ZXw((T7*)(ZwF),b1);}ZBF(((ZD*)_cl));{T3 b1=((T3)'\056');ZZs((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}}ZyY(ZyV(R),((((ZB8*)a3))->Zxb));return
R;}T0*ZAk1=Zo;int ZBk1=0;T0*Zvj1(void){if(ZBk1==0){ZBk1=1;{{T40*n=((T40*)Zh(sizeof(*n)));*n=M40;ZAk1=((T0*)n);ZTY(n);}}}return ZAk1;}
void ZCk1(T82*C,T0*a1){ZUS(a1,ZDk1);ZUS(a1,(((T80*)(((C)->Zkc)))->Zre));ZUS(a1,ZEk1);if((((C)->Zmg))!=((void*)(Zo))){ZFk1((Z3a*)(((C)->Zmg)),a1);
}else{ZXS(a1,((T3)'0'));}ZXS(a1,((T3)'\n'));}void ZGk1(T82*C,T76 a1,T0*a2,T0*a3){{Z3a*n=((Z3a*)Zh(sizeof(*n)));*n=ZZm;ZHk1(n,(T0*)C,a1,a2,a3);
(C->Zmg)=((T0*)n);}}void ZSi1(T82*C,T0*a1){T0*_ef=Zo;_ef=ZED((Z25*)(((C)->Zug)),a1);if((_ef)!=((void*)(Zo))){ZeK((Zr6*)(ZRi1()),_ef);
}if((((C)->Zmg))==((void*)(Zo))){if(!(ZFi1(C))){ZSi1((T82*)(ZHi1()),a1);}}else{ZIk1((Z3a*)(((C)->Zmg)),a1);}}void ZJk1(T82*C){if((((C)->Zog))!=((void*)(Zo))){
ZKk1((ZO9*)(((C)->Zog)),((C)->Zug));}if((((C)->Zmg))!=((void*)(Zo))){if(!((((T41*)(Z1G))->ZKk))){ZLk1((Z3a*)(((C)->Zmg)));((((Z34*)((Z34*)(ZMi1))))->ZRb)=(Zrs(-1));
ZXy((Z34*)(ZMi1),(T0*)C);ZNi1((Z3a*)(((C)->Zmg)));ZMk1((Z3a*)(((C)->Zmg)));}}if((((C)->ZEe))!=((void*)(Zo))){ZLa1((T86*)(((C)->ZEe)),((C)->Zkc));
}if((T6)((((C)->Zfg))&&((T6)((((C)->Zng))!=((void*)(Zo)))))){ZzF((((T80*)(((C)->Zkc)))->Zxb));{T76 Z3w;ZWi1((*(Z3w=Z0U((Zo1*)(((C)->Zng))),&Z3w)),ZNk1);
}}(C->Zrg)=((T6)(ZOk1((T84*)(ZFI),(T0*)C)));}T0*ZPk1(T82*C,T0*a1,T0*a2){T0*R=Zo;T2 _c1=0;T2 _c2=0;T0*ZnH=Zo;T0*ZQk1=Zo;T0*ZRk1=Zo;if(Z2j1(C)){
R=a1;}else if((ZDF(a1))==((void*)(ZDF(a2)))){R=a1;}else{ZQk1=((C)->Zmg);if((ZQk1)==((void*)(Zo))){R=ZVi1();}else{ZnH=ZbK(a2);ZRk1=((((T82*)ZnH))->Zmg);
if((ZRk1)==((void*)(Zo))){R=ZVi1();}else{_c1=(Z3)(((((((Z32*)(((((Z3a*)ZQk1))->ZUb))))->ZRb)))+(Zrs(1)));_c2=(Z3)(((((((Z32*)(((((Z3a*)ZRk1))->ZUb))))->ZRb)))+(Zrs(1)));
if((Z3)((_c1)<(_c2))){R=ZSk1(((Z3a*)ZQk1),a1,a2);}else{R=ZSk1(((Z3a*)ZRk1),a2,a1);}}}}return R;}T6 Zq21(T82*C){T6 R=0;if((((C)->Zqg))==(Zrs(0))){
(C->Zqg)=Z1j1((T84*)(ZFI),(T0*)C);}R=((T6)((Z3)((((C)->Zqg))>=(Zrs(7)))));return R;}void ZTk1(Za5*C){ZzF(((C)->Zxb));{T0*b1=ZvF(63,"A separate target must be an argument of the enclosing routine.");
ZXw((T7*)(ZwF),b1);}ZEF((T75*)(ZyF));}void ZpH(Za5*C,T76 a1){(C->Zxb)=a1;{Zf8*n=((Zf8*)Zh(sizeof(*n)));*n=ZCk;ZC11(n,((C)->Zxb));(C->Zgc)=((T0*)n);
}}T6 ZUk1(T0*a1){T6 R=0;return R;}T0*ZVk1(Za5*C){T0*R=Zo;if((((C)->Zgc))!=((void*)(Zo))){R=ZbK(((C)->Zgc));}return R;}void ZWk1(Ze5*C,T0*a1,T0*a2){
T0*ZXk1=Zo;{Zx2*n=((Zx2*)Zh(sizeof(*n)));*n=ZFi;ZYk1(n,a1,a2);ZXk1=((T0*)n);}if((((C)->Z7h))==((void*)(Zo))){{ZB2*n=((ZB2*)Zh(sizeof(*n)));
*n=ZLd;Zv_(n,ZXk1);(C->Z7h)=((T0*)n);}}else{Zjy(((Z52*)((((ZB2*)(((C)->Z7h)))->ZUb))),ZXk1);}}void ZZk1(Ze5*C){Zm_((ZB2*)(((C)->Z7h)));
if((((C)->Zle))!=((void*)(Zo))){Z271((Z47*)(((C)->Zle)));}}void Z_k1(Ze5*C,T0*a1,T2 a2){Zo_((ZB2*)(((C)->Z7h)),(T0*)C);if((((C)->Zle))!=((void*)(Zo))){
(C->Zle)=Z471((Z47*)(((C)->Zle)));}if(((Z3)(((((((Z52*)((((ZB2*)(((C)->Z7h)))->ZUb))))->ZRb)))+(Zrs(1))))==(Zrs(0))){ZeV(((Z47*)a1),a2);
if((((C)->Zle))!=((void*)(Zo))){Z571(((Z47*)a1),((C)->Zle),a2);}}}void Z0l1(Ze5*C){T2 Z1l1=0;Z7I((Zi4*)(ZsG),Z2l1);Z1l1=Zq_((ZB2*)(((C)->Z7h)));
{int z1=Z1l1;switch(z1){case 26:Z7I((Zi4*)(ZsG),Z3l1);if((((C)->Zle))!=((void*)(Zo))){ZgV((Z47*)(((C)->Zle)));}break;case 27:break;default:;
if((((C)->Zle))!=((void*)(Zo))){Z7I((Zi4*)(ZsG),Zo71);Z7I((Zi4*)(ZsG),Z4l1);ZgV((Z47*)(((C)->Zle)));Z7I((Zi4*)(ZsG),ZdI);}}}Z7I((Zi4*)(ZsG),Z5l1);
}T6 Z6l1(Ze5*C,T0*a1){T6 R=0;R=((T6)((T6)((Zt_((ZB2*)(((C)->Z7h)),a1))&&((T6)((T6)(((((C)->Zle))==((void*)(Zo)))||((T6)(Zs71((Z47*)(((C)->Zle)),a1)))))))));
return R;}void Z7l1(Ze5*C){Zw_((ZB2*)(((C)->Z7h)));if((((C)->Zle))!=((void*)(Zo))){ZjV((Z47*)(((C)->Zle)));}}T6 Z8l1(Ze5*C){T6 R=0;if(Zy_((ZB2*)(((C)->Z7h)))){
R=((T6)(1));}else if((((C)->Zle))!=((void*)(Zo))){R=((T6)(ZlV((Z47*)(((C)->Zle)))));}return R;}void Z9l1(Ze5*C,T0*a1){ZA_((ZB2*)(((C)->Z7h)),a1);
if((((C)->Zle))!=((void*)(Zo))){ZnV((Z47*)(((C)->Zle)),a1);}}T0*Zal1(Ze5*C){T0*R=Zo;R=Zh(sizeof(*C));*((Ze5*)R)=*C;return R;}T0*Zbl1(Ze5*C,T0*a1){
T0*R=Zo;if((ZPA(((T74*)(((((T86*)a1))->ZUb)))))==(Zrs(1))){R=((T0*)(C));}else{{Zn8*n=((Zn8*)Zh(sizeof(*n)));*n=ZVk;Z1N(n,(T0*)C,a1);R=((T0*)n);
}}return R;}T0*Zcl1(Ze5*C,T0*a1){T0*R=Zo;T2 _ne=0;T0*Zdl1=Zo;T0*_ec=Zo;_ne=(((T75*)(ZyF))->ZAg);if((((C)->Z0c))==((void*)(Zo))){(C->Z0c)=a1;
Zdl1=ZC_((ZB2*)(((C)->Z7h)),a1);if((Zdl1)==((void*)(Zo))){}else{(C->Z7h)=Zdl1;}if((T6)((((Z3)((((((T75*)(ZyF))->ZAg)))-(_ne)))==(Zrs(0)))&&((T6)((((C)->Zle))!=((void*)(Zo)))))){
_ec=ZqV((Z47*)(((C)->Zle)),a1);if((_ec)==((void*)(Zo))){}else{(C->Zle)=_ec;}}if((Zdl1)!=((void*)(Zo))){R=((T0*)(C));}}else{R=Zal1(C);
((((Ze5*)(((Ze5*)R))))->Z0c)=(Zo);R=Zcl1(((Ze5*)R),a1);}return R;}
#ifdef __cplusplus
}
#endif

