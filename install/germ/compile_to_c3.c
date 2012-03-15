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
void Zzy(Zp2*C,T0*a1){T2 ZZw=0;(C->ZSb)=((((Zp2*)a1))->ZSb);(C->ZRb)=((((Zp2*)a1))->ZRb);ZZw=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));
if((Z3)((((C)->ZQb))<(ZZw))){(C->ZPb)=((Zna)(Zk(ZZw,sizeof(T0*))));(C->ZQb)=ZZw;}if((Z3)((ZZw)>(Zrs(0)))){ZEt(((C)->ZPb),((((Zp2*)a1))->ZPb),(Z3)(((ZZw))-((T2)(Zrs(1)))));
}}T2 ZAy(Zp2*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));return R;}T0*ZBy(Zp2*C,T2 a1){T0*R=Zo;R=(((C)->ZPb))[(Z3)(((a1))-(((C)->ZSb)))];
return R;}void ZCy(Zp2*C,T0*a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((ZAy(C)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((Zna)(Zk(Z_w,sizeof(T0*))));
(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZDt(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
{Zp2*C1=C;T0*b1=a1;T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}T0*ZDy(Zp2*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zp2*)R)=ZHd;
Zzy(((Zp2*)R),((T0*)C));return R;}void ZEy(Zp2*C,T2 a1,T2 a2){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zna)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;
}(C->ZSb)=a2;(C->ZRb)=(Z3)(((a2))-(Zrs(1)));}void ZFy(Zt2*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZJa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zwu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZGy(Zt2*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((ZJa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){Zyu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void ZHy(Zz2*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zob)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zyw(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZIy(Zz2*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zob)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){ZAw(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}T6 ZJy(ZF2*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));
return R;}T6 ZKy(ZF2*C,T0*a1){T6 R=0;R=((T6)(ZJy(C,ZLy(C,a1))));return R;}void ZMy(ZF2*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZDa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zfu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}T2 ZLy(ZF2*C,T0*a1){T2 R=0;R=Ziu(((C)->ZPb),a1,((C)->ZRb));return R;}void ZNy(ZF2*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((ZDa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Zhu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}T6 ZOy(ZC3*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));return R;}T6 ZPy(ZC3*C,T0*a1){T6
R=0;R=((T6)(ZOy(C,ZQy(C,a1))));return R;}void ZRy(ZC3*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZGa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zou(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}T2 ZQy(ZC3*C,T0*a1){T2 R=0;R=Zru(((C)->ZPb),a1,((C)->ZRb));return R;}void ZSy(ZC3*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((ZGa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Zqu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}void ZTy(ZC3*C,T2 a1,T2 a2){T0*Zsx=Zo;Zsx=(((C)->ZPb))[a1];(((C)->ZPb))[a1]=((((C)->ZPb))[a2]);(((C)->ZPb))[a2]=(Zsx);}T6 ZUy(Z34*C,T2
a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));return R;}T6 ZVy(Z34*C,T0*a1){T6 R=0;R=((T6)(ZUy(C,ZWy(C,a1))));
return R;}void ZXy(Z34*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zha)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=Zqt(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}T2 ZWy(Z34*C,T0*a1){
T2 R=0;R=Ztt(((C)->ZPb),a1,((C)->ZRb));return R;}void ZYy(Z34*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zha)(Zk(a1,sizeof(T0*))));
(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Zst(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void ZZy(Z54*C,T0*a1){T2 Z_w=0;
if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){
(C->ZPb)=((ZHa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zsu(((C)->ZPb),((C)->ZQb),Z_w);
(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z_y(Z54*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((ZHa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Zvu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}void Z0z(Zq4*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zpa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=ZIt(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z1z(Zq4*C,T2
a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zpa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZKt(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));
}(C->ZRb)=Zrs(-1);}void Z2z(Zt4*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Z4b)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=Zvv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z3z(Zt4*C,T2
a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Z4b)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Zxv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));
}(C->ZRb)=Zrs(-1);}void Z4z(Zv4*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zib)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=ZZv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z5z(Zv4*C,T2
a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zib)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Z0w(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));
}(C->ZRb)=Zrs(-1);}void Z6z(ZB4*C,T0*a1){T2 Zyx=0;T2 Z_w=0;Zyx=((((ZB4*)a1))->ZRb);if((Z3)((Zyx)>=(Zrs(0)))){Z_w=(Z3)(((Zyx))+(Zrs(1)));
if((Z3)((((C)->ZQb))<(Z_w))){(C->ZPb)=((Zra)(Zk(Z_w,sizeof(T0*))));(C->ZQb)=Z_w;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){ZLt(((C)->ZPb),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));
}ZNt(((C)->ZPb),((((ZB4*)a1))->ZPb),Zyx);}else if((Z3)((((C)->ZQb))>(Zrs(0)))){ZLt(((C)->ZPb),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));}(C->ZRb)=Zyx;
}void Z7z(ZB4*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){(C->ZPb)=((Zra)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){
(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));if((Z3)((((C)->ZRb))>=(Zrs(0)))){ZLt(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));
}void Z8z(ZB4*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zra)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=ZMt(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z9z(ZB4*C,T2
a1){T2 Z_w=0;if((Z3)((a1)>((Z3)(((((C)->ZRb)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zra)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;
}else if((Z3)((((C)->ZQb))<(a1))){Z_w=(Z3)(((((C)->ZQb)))*(Zrs(2)));while(!((Z3)((Z_w)>=(a1)))){Z_w=(Z3)(((Z_w))*(Zrs(2)));}(C->ZPb)=ZMt(((C)->ZPb),((C)->ZQb),Z_w);
(C->ZQb)=Z_w;}}else if((a1)!=((Z3)(((((C)->ZRb)))+(Zrs(1))))){ZOt(((C)->ZPb),a1,(Z3)((((Z3)(((((C)->ZRb)))+(Zrs(1)))))-((T2)(Zrs(1)))));
}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}T0*Zaz(ZB4*C){T0*R=Zo;R=Zh(sizeof(*C));*((ZB4*)R)=Zbg;Z6z(((ZB4*)R),((T0*)C));return R;}void Zbz(ZB4*C,T2
a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zra)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZOt(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));
}(C->ZRb)=Zrs(-1);}void Zcz(ZP4*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){(C->ZPb)=((ZOa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){
(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));if((Z3)((((C)->ZRb))>=(Zrs(0)))){ZLu(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));
}void Zdz(Z65*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zsa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=ZPt(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void Zez(Z65*C,T2
a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zsa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZRt(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));
}(C->ZRb)=Zrs(-1);}T2 Zfz(Zi5*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));return R;}T0*Zgz(Zi5*C,T2 a1){T0*R=Zo;
R=(((C)->ZPb))[(Z3)(((a1))-(((C)->ZSb)))];return R;}void Zhz(Zi5*C,T0*a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((Zfz(C)))+(Zrs(1)))))){
if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((Zta)(Zk(Z_w,sizeof(T0*))));(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZSt(((C)->ZPb),((C)->ZQb),Z_w);
(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));{Zi5*C1=C;T0*b1=a1;T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}}void Ziz(Zi5*C,T2 a1,T2 a2){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zta)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}(C->ZSb)=a2;(C->ZRb)=(Z3)(((a2))-(Zrs(1)));
}void Zjz(Zo5*C,T0*a1){T2 Zyx=0;T2 Z_w=0;Zyx=((((Zo5*)a1))->ZRb);if((Z3)((Zyx)>=(Zrs(0)))){Z_w=(Z3)(((Zyx))+(Zrs(1)));if((Z3)((((C)->ZQb))<(Z_w))){
(C->ZPb)=((ZMa)(Zk(Z_w,sizeof(T0*))));(C->ZQb)=Z_w;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){ZFu(((C)->ZPb),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));
}ZHu(((C)->ZPb),((((Zo5*)a1))->ZPb),Zyx);}else if((Z3)((((C)->ZQb))>(Zrs(0)))){ZFu(((C)->ZPb),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));}(C->ZRb)=Zyx;
}void Zkz(Zo5*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZMa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=ZGu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}T0*Zlz(Zo5*C){
T0*R=Zo;R=Zh(sizeof(*C));*((Zo5*)R)=Zgh;Zjz(((Zo5*)R),((T0*)C));return R;}void Zmz(Zo5*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((ZMa)(Zk(a1,sizeof(T0*))));
(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZIu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}T2 Znz(Zq5*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));
return R;}void Zoz(Zq5*C,T0*a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((Znz(C)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((ZNa)(Zk(Z_w,sizeof(T0*))));
(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZJu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
{Zq5*C1=C;T0*b1=a1;T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}void Zpz(Zq5*C,T2 a1,T2 a2){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((ZNa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}(C->ZSb)=a2;(C->ZRb)=(Z3)(((a2))-(Zrs(1)));}void Zqz(Zu5*C,T6 a1,T2 a2){if((Z3)((((C)->ZRb))<(a2))){
if((a2)==((Z3)(((((C)->ZRb)))+(Zrs(1))))){Zrz(C,(T6)(a1));}else{Zsz(C,((C)->ZSb),a2);{Zu5*C1=C;T6 b1=(T6)(a1);T2 b2=a2;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=((T6)(b1));
}}}else if((Z3)((a2)<(((C)->ZSb)))){Zsz(C,a2,((C)->ZRb));{Zu5*C1=C;T6 b1=(T6)(a1);T2 b2=a2;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=((T6)(b1));
}}else{{Zu5*C1=C;T6 b1=(T6)(a1);T2 b2=a2;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=((T6)(b1));}}}T2 Ztz(Zu5*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));
return R;}T6 Zuz(Zu5*C,T2 a1){T6 R=0;R=((T6)((((C)->ZPb))[(Z3)(((a1))-(((C)->ZSb)))]));return R;}void Zvz(Zu5*C,T2 a1,T2 a2){T2 ZOx=0;
(C->ZSb)=a1;(C->ZRb)=a2;ZOx=(Z3)((((Z3)(((a2))-(a1))))+(Zrs(1)));if((Z3)((ZOx)>(Zrs(0)))){if((Z3)((((C)->ZQb))<(ZOx))){(C->ZPb)=((Zxa)(Zk(ZOx,sizeof(T6))));
(C->ZQb)=ZOx;}else{{Zu5*C1=C;T6 ZPx=0;{Zu5*C2=C1;T6 c1=(T6)(ZPx);Z3u(((C2)->ZPb),(T6)(c1),(Z3)(((((C2)->ZRb)))-(((C2)->ZSb))));}}}}}void
Zrz(Zu5*C,T6 a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((Ztz(C)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((Zxa)(Zk(Z_w,sizeof(T6))));
(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Z0u(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
{Zu5*C1=C;T6 b1=(T6)(a1);T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=((T6)(b1));}}void Zsz(Zu5*C,T2 a1,T2 a2){T2 ZOx=0;
T2 Zoy=0;T2 Zpy=0;ZOx=(Z3)((((Z3)(((a2))-(a1))))+(Zrs(1)));if((Z3)((ZOx)>(Zrs(0)))){if((Z3)((ZOx)>(((C)->ZQb)))){if((((C)->ZQb))==(Zrs(0))){
(C->ZPb)=((Zxa)(Zk(ZOx,sizeof(T6))));(C->ZQb)=ZOx;}else{(C->ZPb)=Z0u(((C)->ZPb),((C)->ZQb),ZOx);(C->ZQb)=ZOx;}}Zoy=(Z3)(((((C)->ZSb)))-(a1));
Zpy=(Z3)((((Z3)(((ZSs(a2,((C)->ZRb))))-(ZNs(a1,((C)->ZSb))))))+(Zrs(1)));if((Z3)((Zpy)>(Zrs(0)))){if((Zoy)==(Zrs(0))){if((Z3)((Zpy)<(((C)->ZQb)))){
Z4u(((C)->ZPb),Zpy,(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));}}else if((Z3)((Zoy)<(Zrs(0)))){Z2u(((C)->ZPb),-(Zoy),(Z3)((((Z3)(((Zpy))-(Zoy))))-((T2)(Zrs(1)))),Zoy);
if((Z3)((Zpy)<(((C)->ZQb)))){Z4u(((C)->ZPb),Zpy,(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));}}else{Z2u(((C)->ZPb),(T2)(Zrs(0)),(Z3)(((Zpy))-((T2)(Zrs(1)))),Zoy);
Z4u(((C)->ZPb),(T2)(Zrs(0)),(Z3)(((Zoy))-((T2)(Zrs(1)))));if((Z3)(((Z3)(((Zpy))+(Zoy)))<(((C)->ZQb)))){Z4u(((C)->ZPb),(Z3)(((Zpy))+(Zoy)),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));
}}}else{Z4u(((C)->ZPb),(T2)(Zrs(0)),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));}}(C->ZSb)=a1;(C->ZRb)=a2;}T2 Zwz(T77*C,T76 a1){T2 R=0;R=Z2w(((C)->ZPb),a1,((C)->ZRb));
return R;}void Zxz(T77*C){T79 Z3y=Zo;if((((C)->ZRb))==(Zrs(0))){(C->ZPb)=Z3y;(C->ZQb)=Zrs(0);(C->ZRb)=Zrs(-1);}else{Z6w(((C)->ZPb),((C)->ZRb));
(C->ZRb)=(Z3)(((((C)->ZRb)))-(Zrs(1)));}}T76 Zyz(T77*C,T2 a1){T76 R={Zo,Zo,0};{T76 Z3w;R=(*(Z3w=(((C)->ZPb))[a1],&Z3w));}return R;}T6
Zzz(T77*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));return R;}void ZAz(T77*C,T2 a1){Z9w(((C)->ZPb),a1,((C)->ZRb));
(C->ZRb)=(Z3)(((((C)->ZRb)))-(Zrs(1)));}T6 ZBz(T77*C,T76 a1){T6 R=0;R=((T6)(Zzz(C,ZCz(C,a1))));return R;}void ZDz(T77*C,T76 a1){T2 Z_w=0;
if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){
(C->ZPb)=((T79)(Zk(Zrs(2),sizeof(T76))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Z4w(((C)->ZPb),((C)->ZQb),Z_w);
(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}{T76 Z7w=a1;Z8w((((C)->ZPb))+(((C)->ZRb)),&(Z7w),sizeof(T76));}}T76 ZEz(T77*C){T76
R={Zo,Zo,0};{T76 Z3w;R=(*(Z3w=(((C)->ZPb))[Zrs(0)],&Z3w));}return R;}T2 ZCz(T77*C,T76 a1){T2 R=0;R=Zbw(((C)->ZPb),a1,((C)->ZRb));return
R;}void ZFz(T77*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((T79)(Zk(a1,sizeof(T76))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){
Zaw(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}T0*ZGz(T52*C){T0*R=Zo;R=(((C)->ZPb))[((C)->ZRb)];return R;}T6 ZHz(T52*C,T2
a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));return R;}T2 ZIz(T52*C,T0*a1){T2 R=0;R=ZRu(((C)->ZPb),a1,((C)->ZRb));
return R;}void ZJz(T52*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){(C->ZPb)=((T59)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){
(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));if((Z3)((((C)->ZRb))>=(Zrs(0)))){ZOu(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));
}T0*ZKz(T52*C){T0*R=Zo;{Z_7*n=((Z_7*)Zh(sizeof(*n)));*n=Zsk;ZLz(n,(T0*)C);R=((T0*)n);}return R;}T6 ZMz(T52*C,T0*a1){T6 R=0;R=((T6)(ZHz(C,ZIz(C,a1))));
return R;}T6 ZNz(T52*C,T0*a1){T6 R=0;R=((T6)(ZHz(C,ZOz(C,a1))));return R;}void ZPz(T52*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((T59)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZPu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZQz(T52*C,T2 a1){T2 Z_w=0;if((Z3)((a1)>((Z3)(((((C)->ZRb)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){
(C->ZPb)=((T59)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))<(a1))){Z_w=(Z3)(((((C)->ZQb)))*(Zrs(2)));while(!((Z3)((Z_w)>=(a1))))
{Z_w=(Z3)(((Z_w))*(Zrs(2)));}(C->ZPb)=ZPu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}else if((a1)!=((Z3)(((((C)->ZRb)))+(Zrs(1))))){ZSu(((C)->ZPb),a1,(Z3)((((Z3)(((((C)->ZRb)))+(Zrs(1)))))-((T2)(Zrs(1)))));
}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}T2 ZOz(T52*C,T0*a1){T2 R=0;R=ZTu(((C)->ZPb),a1,((C)->ZRb));return R;}void ZRz(T52*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((T59)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZSu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}void ZSz(T52*C,T0*a1){T2 _i1=0;T2 _i2=0;T2 _up=0;ZRz(C,ZTz(a1));(C->ZRb)=(Z3)(((ZTz(a1)))-(Zrs(1)));_i1=Zrs(0);_i2=ZUz(a1);_up=((((T52*)a1))->ZRb);
while(!((Z3)((_i2)>(_up)))){(((C)->ZPb))[_i1]=(ZVz(a1,_i2));_i1=(Z3)(((_i1))+(Zrs(1)));_i2=(Z3)(((_i2))+(Zrs(1)));}}void ZWz(T52*C,T2
a1,T2 a2){T0*Zsx=Zo;Zsx=(((C)->ZPb))[a1];(((C)->ZPb))[a1]=((((C)->ZPb))[a2]);(((C)->ZPb))[a2]=(Zsx);}T0*ZXz(Z_5*C){T0*R=Zo;R=(((C)->ZPb))[((C)->ZRb)];
return R;}T6 ZYz(Z_5*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));return R;}void ZZz(Z_5*C,T2
a1){if((Z3)((a1)>(((C)->ZQb)))){(C->ZPb)=((ZEa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));
if((Z3)((((C)->ZRb))>=(Zrs(0)))){Zju(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}void Z_z(Z_5*C){(C->ZRb)=(Z3)(((((C)->ZRb)))-(Zrs(1)));
}T6 Z0A(Z_5*C,T0*a1){T6 R=0;R=((T6)(ZYz(C,Z1A(C,a1))));return R;}void Z2A(Z_5*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZEa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zku(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z3A(Z_5*C,T2 a1){T2 Z_w=0;if((Z3)((a1)>((Z3)(((((C)->ZRb)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){
(C->ZPb)=((ZEa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))<(a1))){Z_w=(Z3)(((((C)->ZQb)))*(Zrs(2)));while(!((Z3)((Z_w)>=(a1))))
{Z_w=(Z3)(((Z_w))*(Zrs(2)));}(C->ZPb)=Zku(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}else if((a1)!=((Z3)(((((C)->ZRb)))+(Zrs(1))))){Zmu(((C)->ZPb),a1,(Z3)((((Z3)(((((C)->ZRb)))+(Zrs(1)))))-((T2)(Zrs(1)))));
}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}T2 Z1A(Z_5*C,T0*a1){T2 R=0;R=Znu(((C)->ZPb),a1,((C)->ZRb));return R;}void Z4A(Z_5*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((ZEa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Zmu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}T2 Z5A(Z36*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));return R;}T0*Z6A(Z36*C,T2 a1){T0*R=Zo;R=(((C)->ZPb))[(Z3)(((a1))-(((C)->ZSb)))];
return R;}void Z7A(Z36*C,T0*a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((Z5A(C)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((Zka)(Zk(Z_w,sizeof(T0*))));
(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zxt(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
{Z36*C1=C;T0*b1=a1;T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}void Z8A(Z36*C,T2 a1,T2 a2){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((Zka)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}(C->ZSb)=a2;(C->ZRb)=(Z3)(((a2))-(Zrs(1)));}T6 Z9A(Zp6*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));
return R;}T6 ZaA(Zp6*C,T0*a1){T6 R=0;R=((T6)(Z9A(C,ZbA(C,a1))));return R;}void ZcA(Zp6*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zgb)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZVv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}T2 ZbA(Zp6*C,T0*a1){T2 R=0;R=ZYv(((C)->ZPb),a1,((C)->ZRb));return R;}void ZdA(Zp6*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((Zgb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZXv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}void ZeA(ZR6*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zma)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=ZAt(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZfA(ZR6*C,T2
a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zma)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZCt(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));
}(C->ZRb)=Zrs(-1);}void ZgA(Za7*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){(C->ZPb)=((Zbb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){
(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));if((Z3)((((C)->ZRb))>=(Zrs(0)))){ZHv(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));
}void ZhA(Za7*C,T2 a1){T2 Z_w=0;if((Z3)((a1)>((Z3)(((((C)->ZRb)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zbb)(Zk(a1,sizeof(T0*))));
(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))<(a1))){Z_w=(Z3)(((((C)->ZQb)))*(Zrs(2)));while(!((Z3)((Z_w)>=(a1)))){Z_w=(Z3)(((Z_w))*(Zrs(2)));
}(C->ZPb)=ZIv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}else if((a1)!=((Z3)(((((C)->ZRb)))+(Zrs(1))))){ZKv(((C)->ZPb),a1,(Z3)((((Z3)(((((C)->ZRb)))+(Zrs(1)))))-((T2)(Zrs(1)))));
}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}void ZiA(Z18*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZRa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZUu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZjA(Z18*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((ZRa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){ZWu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void ZkA(Z78*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZZa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Z6v(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZlA(Z78*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((ZZa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){Z8v(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void ZmA(T91*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){
(C->ZPb)=((T93)(Zk(a1,sizeof(T10))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));
if((Z3)((((C)->ZRb))>=(Zrs(0)))){ZCu(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}void ZnA(T91*C,T10 a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((T93)(Zk(Zrs(2),sizeof(T10))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZDu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZoA(Zt8*C,T0*a1){T2 ZZw=0;(C->ZSb)=((((Zt8*)a1))->ZSb);(C->ZRb)=((((Zt8*)a1))->ZRb);ZZw=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));
if((Z3)((((C)->ZQb))<(ZZw))){(C->ZPb)=((Zjb)(Zk(ZZw,sizeof(T0*))));(C->ZQb)=ZZw;}if((Z3)((ZZw)>(Zrs(0)))){Zdw(((C)->ZPb),((((Zt8*)a1))->ZPb),(Z3)(((ZZw))-((T2)(Zrs(1)))));
}}T2 ZpA(Zt8*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));return R;}T0*ZqA(Zt8*C,T2 a1){T0*R=Zo;R=(((C)->ZPb))[(Z3)(((a1))-(((C)->ZSb)))];
return R;}void ZrA(Zt8*C,T2 a1,T2 a2){T2 ZOx=0;(C->ZSb)=a1;(C->ZRb)=a2;ZOx=(Z3)((((Z3)(((a2))-(a1))))+(Zrs(1)));if((Z3)((ZOx)>(Zrs(0)))){
if((Z3)((((C)->ZQb))<(ZOx))){(C->ZPb)=((Zjb)(Zk(ZOx,sizeof(T0*))));(C->ZQb)=ZOx;}else{{Zt8*C1=C;T0*ZPx=Zo;{Zt8*C2=C1;T0*c1=ZPx;Zew(((C2)->ZPb),c1,(Z3)(((((C2)->ZRb)))-(((C2)->ZSb))));
}}}}}void ZsA(Zt8*C,T0*a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((ZpA(C)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((Zjb)(Zk(Z_w,sizeof(T0*))));
(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zcw(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
{Zt8*C1=C;T0*b1=a1;T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}T0*ZtA(Zt8*C){T0*R=Zo;R=Zh(sizeof(*C));*((Zt8*)R)=Z0l;
ZoA(((Zt8*)R),((T0*)C));return R;}void ZuA(Zt8*C,T2 a1,T2 a2){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zjb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;
}(C->ZSb)=a2;(C->ZRb)=(Z3)(((a2))-(Zrs(1)));}void ZvA(T94*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){(C->ZPb)=((T96)(Zk(a1,sizeof(T2))));(C->ZQb)=a1;
}else if((Z3)((((C)->ZQb))>(Zrs(0)))){(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));if((Z3)((((C)->ZRb))>=(Zrs(0)))){Ziw(((C)->ZPb),((C)->ZRb));
}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}void ZwA(T94*C,T2 a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((T96)(Zk(Zrs(2),sizeof(T2))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zjw(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZxA(T94*C,T2 a1){T2 Z_w=0;if((Z3)((a1)>((Z3)(((((C)->ZRb)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){
(C->ZPb)=((T96)(Zk(a1,sizeof(T2))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))<(a1))){Z_w=(Z3)(((((C)->ZQb)))*(Zrs(2)));while(!((Z3)((Z_w)>=(a1))))
{Z_w=(Z3)(((Z_w))*(Zrs(2)));}(C->ZPb)=Zjw(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}else if((a1)!=((Z3)(((((C)->ZRb)))+(Zrs(1))))){Znw(((C)->ZPb),a1,(Z3)((((Z3)(((((C)->ZRb)))+(Zrs(1)))))-((T2)(Zrs(1)))));
}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}T2 ZyA(T94*C,T2 a1){T2 R=0;R=Zow(((C)->ZPb),a1,((C)->ZRb));return R;}void ZzA(T94*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((T96)(Zk(a1,sizeof(T2))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Znw(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}void ZAA(ZP8*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zmb)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));
(C->ZPb)=Zpw(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZBA(ZP8*C,T2
a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zmb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){Zrw(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));
}(C->ZRb)=Zrs(-1);}T2 ZCA(ZT8*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));return R;}T0*ZDA(ZT8*C,T2 a1){T0*R=Zo;
R=(((C)->ZPb))[(Z3)(((a1))-(((C)->ZSb)))];return R;}void ZEA(ZT8*C,T0*a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((ZCA(C)))+(Zrs(1)))))){
if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((Zfb)(Zk(Z_w,sizeof(T0*))));(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZSv(((C)->ZPb),((C)->ZQb),Z_w);
(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));{ZT8*C1=C;T0*b1=a1;T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}}void ZFA(ZT8*C,T2 a1,T2 a2){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zfb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}(C->ZSb)=a2;(C->ZRb)=(Z3)(((a2))-(Zrs(1)));
}void ZGA(ZT8*C,T2 a1,T2 a2){T0*Zsx=Zo;Zsx=ZDA(C,a1);{ZT8*C1=C;T0*b1=ZDA(C,a2);T2 b2=a1;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}{ZT8*C1=C;T0*b1=Zsx;T2 b2=a2;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}void ZHA(Za9*C,T0*a1){T2 Zyx=0;T2 Z_w=0;Zyx=((((Za9*)a1))->ZRb);
if((Z3)((Zyx)>=(Zrs(0)))){Z_w=(Z3)(((Zyx))+(Zrs(1)));if((Z3)((((C)->ZQb))<(Z_w))){(C->ZPb)=((Z5b)(Zk(Z_w,sizeof(T0*))));(C->ZQb)=Z_w;
}else if((Z3)((((C)->ZQb))>(Zrs(0)))){Zyv(((C)->ZPb),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));}ZAv(((C)->ZPb),((((Za9*)a1))->ZPb),Zyx);}else
if((Z3)((((C)->ZQb))>(Zrs(0)))){Zyv(((C)->ZPb),(Z3)(((((C)->ZQb)))-((T2)(Zrs(1)))));}(C->ZRb)=Zyx;}T6 ZIA(Za9*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));
return R;}T6 ZJA(Za9*C,T0*a1){T6 R=0;R=((T6)(ZIA(C,ZKA(C,a1))));return R;}void ZLA(Za9*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Z5b)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Zzv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}T2 ZKA(Za9*C,T0*a1){T2 R=0;R=ZCv(((C)->ZPb),a1,((C)->ZRb));return R;}T0*ZMA(Za9*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Za9*)R)=ZNl;ZHA(((Za9*)R),((T0*)C));return R;}void ZNA(Za9*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Z5b)(Zk(a1,sizeof(T0*))));
(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZBv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void ZOA(T74*C,T0*a1){T2 ZZw=0;
(C->ZSb)=((((T74*)a1))->ZSb);(C->ZRb)=((((T74*)a1))->ZRb);ZZw=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));if((Z3)((((C)->ZQb))<(ZZw))){
(C->ZPb)=((T59)(Zk(ZZw,sizeof(T0*))));(C->ZQb)=ZZw;}if((Z3)((ZZw)>(Zrs(0)))){ZQu(((C)->ZPb),((((T74*)a1))->ZPb),(Z3)(((ZZw))-((T2)(Zrs(1)))));
}}T2 ZPA(T74*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZRb)))-(((C)->ZSb)))))+(Zrs(1)));return R;}T0*ZQA(T74*C,T2 a1){T0*R=Zo;R=(((C)->ZPb))[(Z3)(((a1))-(((C)->ZSb)))];
return R;}T6 ZRA(T74*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((((C)->ZSb))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));return R;}T2 ZSA(T74*C,T0*a1){
T2 R=0;R=(Z3)(((((C)->ZSb)))+(ZRu(((C)->ZPb),a1,(Z3)(((((C)->ZRb)))-(((C)->ZSb))))));return R;}T6 ZOw(T74*C){T6 R=0;R=((T6)((Z3)((((C)->ZRb))<(((C)->ZSb)))));
return R;}T6 ZTA(T74*C,T0*a1){T6 R=0;R=((T6)(ZRA(C,ZSA(C,a1))));return R;}T6 ZUA(T74*C,T0*a1){T6 R=0;R=((T6)(ZRA(C,ZVA(C,a1))));return
R;}void ZWA(T74*C,T0*a1){T2 Z_w=0;if((Z3)((((C)->ZQb))<((Z3)(((ZPA(C)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){Z_w=Zrs(16);(C->ZPb)=((T59)(Zk(Z_w,sizeof(T0*))));
(C->ZQb)=Z_w;}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZPu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));
{T74*C1=C;T0*b1=a1;T2 b2=((C)->ZRb);(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}}void ZMw(T74*C){(C->ZRb)=(Z3)(((((C)->ZSb)))-(Zrs(1)));
}T2 ZVA(T74*C,T0*a1){T2 R=0;R=(Z3)(((((C)->ZSb)))+(ZTu(((C)->ZPb),a1,(Z3)(((((C)->ZRb)))-(((C)->ZSb))))));return R;}T0*ZPw(T74*C){T0*R=Zo;
R=Zh(sizeof(*C));*((T74*)R)=M74;ZOA(((T74*)R),((T0*)C));return R;}void ZXA(T74*C,T2 a1,T2 a2){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((T59)(Zk(a1,sizeof(T0*))));
(C->ZQb)=a1;}(C->ZSb)=a2;(C->ZRb)=(Z3)(((a2))-(Zrs(1)));}void ZYA(T74*C,T2 a1,T2 a2){T0*Zsx=Zo;Zsx=ZQA(C,a1);{T74*C1=C;T0*b1=ZQA(C,a2);
T2 b2=a1;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);}{T74*C1=C;T0*b1=Zsx;T2 b2=a2;(((C1)->ZPb))[(Z3)(((b2))-(((C1)->ZSb)))]=(b1);
}}void ZZA(Zc9*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){(C->ZPb)=((Zza)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){
(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));if((Z3)((((C)->ZRb))>=(Zrs(0)))){Z5u(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));
}void Z_A(Zc9*C,T2 a1){T2 Z_w=0;if((Z3)((a1)>((Z3)(((((C)->ZRb)))+(Zrs(1)))))){if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zza)(Zk(a1,sizeof(T0*))));
(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))<(a1))){Z_w=(Z3)(((((C)->ZQb)))*(Zrs(2)));while(!((Z3)((Z_w)>=(a1)))){Z_w=(Z3)(((Z_w))*(Zrs(2)));
}(C->ZPb)=Z6u(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;}}else if((a1)!=((Z3)(((((C)->ZRb)))+(Zrs(1))))){Z8u(((C)->ZPb),a1,(Z3)((((Z3)(((((C)->ZRb)))+(Zrs(1)))))-((T2)(Zrs(1)))));
}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}void Z0B(Zg9*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((ZSa)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZXu(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z1B(Zg9*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((ZSa)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){ZZu(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void Z2B(Zq9*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Z_a)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=Z9v(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z3B(Zq9*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Z_a)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){Zbv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void Z4B(ZE9*C,T2 a1){if((Z3)((a1)>(((C)->ZQb)))){
(C->ZPb)=((Z8b)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(Zrs(0)))){(C->ZRb)=ZNs(((C)->ZRb),(Z3)(((a1))-(Zrs(1))));
if((Z3)((((C)->ZRb))>=(Zrs(0)))){ZDv(((C)->ZPb),((C)->ZRb));}}(C->ZRb)=(Z3)(((a1))-(Zrs(1)));}void Z5B(ZE9*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Z8b)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZEv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z6B(ZE9*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Z8b)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){ZGv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void Z7B(ZQ9*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zfb)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZSv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void Z8B(ZQ9*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zfb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){ZUv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}void Z9B(ZS9*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zeb)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZPv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}void ZaB(ZS9*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){(C->ZPb)=((Zeb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else
if((Z3)((((C)->ZQb))>(a1))){ZRv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);}T6 ZbB(ZU9*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((Zrs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZRb))))))));
return R;}T6 ZcB(ZU9*C,T0*a1){T6 R=0;R=((T6)(ZbB(C,ZdB(C,a1))));return R;}void ZeB(ZU9*C,T0*a1){T2 Z_w=0;if((Z3)(((Z3)(((((C)->ZRb)))+(Zrs(1))))<=((Z3)(((((C)->ZQb)))-(Zrs(1)))))){
(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}else if((((C)->ZQb))==(Zrs(0))){(C->ZPb)=((Zcb)(Zk(Zrs(2),sizeof(T0*))));(C->ZQb)=Zrs(2);(C->ZRb)=Zrs(0);
}else{Z_w=(Z3)(((Zrs(2)))*(((C)->ZQb)));(C->ZPb)=ZLv(((C)->ZPb),((C)->ZQb),Z_w);(C->ZQb)=Z_w;(C->ZRb)=(Z3)(((((C)->ZRb)))+(Zrs(1)));}
(((C)->ZPb))[((C)->ZRb)]=(a1);}T2 ZdB(ZU9*C,T0*a1){T2 R=0;R=ZOv(((C)->ZPb),a1,((C)->ZRb));return R;}void ZfB(ZU9*C,T2 a1){if((Z3)((((C)->ZQb))<(a1))){
(C->ZPb)=((Zcb)(Zk(a1,sizeof(T0*))));(C->ZQb)=a1;}else if((Z3)((((C)->ZQb))>(a1))){ZNv(((C)->ZPb),(T2)(Zrs(0)),((C)->ZRb));}(C->ZRb)=Zrs(-1);
}
#ifdef __cplusplus
}
#endif

