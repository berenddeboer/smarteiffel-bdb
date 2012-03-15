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
void Z0C(ZJ4*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((ZVa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=Zfv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void Z1C(ZJ4*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((ZVa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Zhv(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}T0*Z2C(ZL4*C,T2 a1){T0*R=Zo;Z3C(C,a1);R=(((Zs5*)(((C)->Zbc)))->ZFc);return R;}void Z3C(ZL4*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){
(C->Zac)=a1;(C->Zbc)=(((Zs5*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else{Z3C(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){Z3C(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));
}}}void Z4C(ZL4*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Z4b Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Z4b)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((Zs5*)Ziz))->ZHc);Zft=(Z3)((ZBx((T7*)(((((Zs5*)Ziz))->ZGc))))%(((C)->ZVb)));((((Zs5*)(((Zs5*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 Z5C(ZL4*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((Zs5*)Zpz))->ZGc)),a1)))))){Zpz=((((Zs5*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));
return R;}void Z6C(ZL4*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){Z4C(C);}Zft=(Z3)((ZBx(((T7*)a2)))%(((C)->ZVb)));
{Zs5*n=((Zs5*)Zh(sizeof(*n)));*n=Zqh;Z7C(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));
}void Z8C(ZL4*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Z4b)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}void Z9C(Z05*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zqb)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=ZKw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZaC(Z05*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zqb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZMw(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void ZuB(Z25*C,T0*a1,T2 a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void ZbC(T99*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){
(C->ZUb)=((Zob)(Zk(a1,sizeof(T2))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));
if((Z3)((((C)->ZWb))>=(ZGs(0)))){ZDw(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}void ZcC(T99*C,T2 a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zob)(Zk(ZGs(2),sizeof(T2))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZEw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZdC(T99*C,T2 a1){T2 Zpx=0;if((Z3)((a1)>((Z3)(((((C)->ZWb)))+(ZGs(1)))))){if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((Zob)(Zk(a1,sizeof(T2))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))<(a1))){Zpx=(Z3)(((((C)->ZVb)))*(ZGs(2)));while(!((Z3)((Zpx)>=(a1))))
{Zpx=(Z3)(((Zpx))*(ZGs(2)));}(C->ZUb)=ZEw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;}}else if((a1)!=((Z3)(((((C)->ZWb)))+(ZGs(1))))){ZIw(((C)->ZUb),a1,(Z3)((((Z3)(((((C)->ZWb)))+(ZGs(1)))))-((T2)(ZGs(1)))));
}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}T2 ZeC(T99*C,T2 a1){T2 R=0;R=ZJw(((C)->ZUb),a1,((C)->ZWb));return R;}void ZfC(T99*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((Zob)(Zk(a1,sizeof(T2))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZIw(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}T6 ZgC(Za5*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((T87*)a1))->Zrf))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!(ZhC((T87*)(((((Z03*)Zpz))->ZGc)),a1)))
{Zpz=((((Z03*)Zpz))->ZHc);}R=((T6)(((((Z03*)Zpz))->ZFc)));return R;}void ZiC(Za5*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;ZCa Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;
int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((ZCa)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));
(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((Z03*)Ziz))->ZHc);Zft=(Z3)(((((T87*)(((((Z03*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));
((((Z03*)(((Z03*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZjC(Za5*C,T0*a1){
T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((T87*)a1))->Zrf))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZhC((T87*)(((((Z03*)Zpz))->ZGc)),a1))))))
{Zpz=((((Z03*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));return R;}void ZkC(Za5*C,T6 a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){
ZiC(C);}Zft=(Z3)((((((T87*)a2))->Zrf))%(((C)->ZVb)));{Z03*n=((Z03*)Zh(sizeof(*n)));*n=ZQm;ZlC(n,(T6)(a1),a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);
}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}void ZmC(Za5*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((ZCa)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}void Z7C(Zs5*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void ZnC(Zw5*C,T0*a1,T0*a2,T0*a3){
(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void ZoC(ZA5*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){(C->ZUb)=((ZDa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;
}else if((Z3)((((C)->ZVb))>(ZGs(0)))){(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));if((Z3)((((C)->ZWb))>=(ZGs(0)))){Zou(((C)->ZUb),((C)->ZWb));
}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}void ZpC(ZA5*C,T2 a1){T2 Zpx=0;if((Z3)((a1)>((Z3)(((((C)->ZWb)))+(ZGs(1)))))){if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((ZDa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))<(a1))){Zpx=(Z3)(((((C)->ZVb)))*(ZGs(2)));while(!((Z3)((Zpx)>=(a1))))
{Zpx=(Z3)(((Zpx))*(ZGs(2)));}(C->ZUb)=Zpu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;}}else if((a1)!=((Z3)(((((C)->ZWb)))+(ZGs(1))))){Zru(((C)->ZUb),a1,(Z3)((((Z3)(((((C)->ZWb)))+(ZGs(1)))))-((T2)(ZGs(1)))));
}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}void ZqC(ZC5*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((ZUa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Zcv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZrC(ZC5*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((ZUa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){Zev(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void ZsC(ZE5*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zwa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Z7u(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZtC(ZE5*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zwa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){Z9u(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void ZuC(ZO5*C,T0*a1,T0*a2){T2 Zoz=0;T2 Zft=0;
T0*Zpz=Zo;Zoz=((((T85*)a2))->Zrf);Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zyz((T85*)(((((Zw5*)Zpz))->ZGc)),a2))))))
{Zpz=((((Zw5*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZvC(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{Zw5*n=((Zw5*)Zh(sizeof(*n)));
*n=ZDh;ZnC(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}
else{((((Zw5*)(((Zw5*)Zpz))))->ZFc)=(a1);}}T0*ZwC(ZO5*C,T2 a1){T0*R=Zo;ZxC(C,a1);R=(((Zw5*)(((C)->Zbc)))->ZFc);return R;}void ZxC(ZO5*C,T2
a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((Zw5*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){
(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{ZxC(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZxC(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void ZvC(ZO5*C){T2 Zet=0;T2 Zft=0;
T2 Zpx=0;Z2b Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((Z2b)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((Zw5*)Ziz))->ZHc);
Zft=(Z3)(((((T85*)(((((Zw5*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));((((Zw5*)(((Zw5*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void ZyC(ZO5*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Z2b)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*ZzC(ZO5*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((T85*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zyz((T85*)(((((Zw5*)Zpz))->ZGc)),a1)))))){Zpz=((((Zw5*)Zpz))->ZHc);}
if((Zpz)!=((void*)(Zo))){R=((((Zw5*)Zpz))->ZFc);}return R;}void ZqB(ZS5*C,T0*a1,T0*a2){(C->ZFc)=a1;(C->ZHc)=a2;}void ZAC(ZU5*C,T0*a1){
T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((Zqa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZTt(((C)->ZUb),((C)->ZVb),Zpx);
(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZBC(ZU5*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((Zqa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZVt(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}ZQ5*ZCC(void){ZQ5*n;n=((ZQ5*)Zh(sizeof(*n)));*n=Zwi;ZDC(n);return n;}T0*ZEC(ZQ5*C,T2 a1){T0*R=Zo;if((a1)!=(((C)->Zui))){ZFC(C,a1);}R=(((Zb8*)(((C)->Zvi)))->ZFc);
return R;}void ZDC(ZQ5*C){(C->Zsi)=Zo;(C->ZWb)=ZGs(0);(C->Zti)=Zo;(C->Zui)=ZGs(0);(C->Zvi)=Zo;}void ZGC(ZQ5*C,T0*a1){T0*ZHC=Zo;if((((C)->Zsi))==((void*)(Zo))){
{Zb8*n=((Zb8*)Zh(sizeof(*n)));*n=ZHk;ZIC(n,a1,Zo);(C->Zsi)=((T0*)n);}(C->ZWb)=ZGs(1);(C->Zti)=((C)->Zsi);(C->Zui)=ZGs(1);(C->Zvi)=((C)->Zsi);
}else{{Zb8*n=((Zb8*)Zh(sizeof(*n)));*n=ZHk;ZIC(n,a1,Zo);ZHC=((T0*)n);}((((Zb8*)((Zb8*)(((C)->Zti)))))->ZHc)=(ZHC);(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
(C->Zti)=ZHC;}}void ZFC(ZQ5*C,T2 a1){if((Z3)((((C)->Zui))>(a1))){(C->Zui)=ZGs(1);(C->Zvi)=((C)->Zsi);}while(!((a1)==(((C)->Zui)))){(C->Zvi)=(((Zb8*)(((C)->Zvi)))->ZHc);
(C->Zui)=(Z3)(((((C)->Zui)))+(ZGs(1)));}}void ZJC(T49*C,T10 a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}T0*ZKC(Z96*C,T2 a1){
T0*R=Zo;ZLC(C,a1);R=(((Z26*)(((C)->Zbc)))->ZGc);return R;}void ZMC(Z96*C,T0*a1,T0*a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=ZBx(((T7*)a2));
Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((Z26*)Zpz))->ZGc)),a2))))))
{Zpz=((((Z26*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZNC(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{Z26*n=((Z26*)Zh(sizeof(*n)));
*n=ZDk;ZOC(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}
else{((((Z26*)(((Z26*)Zpz))))->ZFc)=(a1);}}T0*ZPC(Z96*C,T2 a1){T0*R=Zo;ZLC(C,a1);R=(((Z26*)(((C)->Zbc)))->ZFc);return R;}void ZLC(Z96*C,T2
a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((Z26*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){
(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{ZLC(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZLC(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void ZNC(Z96*C){T2 Zet=0;T2 Zft=0;
T2 Zpx=0;ZTa Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((ZTa)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((Z26*)Ziz))->ZHc);
Zft=(Z3)((ZBx((T7*)(((((Z26*)Ziz))->ZGc))))%(((C)->ZVb)));((((Z26*)(((Z26*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZQC(Z96*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((Z26*)Zpz))->ZGc)),a1)))))){Zpz=((((Z26*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));
return R;}void ZRC(Z96*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((ZTa)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}void ZSC(T96*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){(C->ZUb)=((T98)(Zk(a1,sizeof(T10))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){
(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));if((Z3)((((C)->ZWb))>=(ZGs(0)))){ZVu(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));
}void ZTC(T96*C,T10 a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((T98)(Zk(ZGs(2),sizeof(T10))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=ZWu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZUC(Zb6*C,T0*a1){
T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((ZLa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZLu(((C)->ZUb),((C)->ZVb),Zpx);
(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZVC(Zb6*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((ZLa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZOu(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}void ZWC(Zd6*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}T0*ZXC(Zp6*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((ZD8*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!(ZYC((ZD8*)(((((Zt6*)Zpz))->ZGc)),a1))){Zpz=((((Zt6*)Zpz))->ZHc);}R=((((Zt6*)Zpz))->ZFc);return R;}void ZZC(Zp6*C){
T2 Zet=0;T2 Zft=0;T2 Zpx=0;ZWa Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((ZWa)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((Zt6*)Ziz))->ZHc);
Zft=(Z3)(((((ZD8*)(((((Zt6*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));((((Zt6*)(((Zt6*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 Z_C(Zp6*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((ZD8*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZYC((ZD8*)(((((Zt6*)Zpz))->ZGc)),a1)))))){Zpz=((((Zt6*)Zpz))->ZHc);}
R=((T6)((Zpz)!=((void*)(Zo))));return R;}void Z0D(Zp6*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){
ZZC(C);}Zft=(Z3)((((((ZD8*)a2))->Zrf))%(((C)->ZVb)));{Zt6*n=((Zt6*)Zh(sizeof(*n)));*n=Zdk;Z1D(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);
}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}void Z2D(Zp6*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((ZWa)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*Z3D(Zp6*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((ZD8*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZYC((ZD8*)(((((Zt6*)Zpz))->ZGc)),a1)))))){Zpz=((((Zt6*)Zpz))->ZHc);}
if((Zpz)!=((void*)(Zo))){R=((((Zt6*)Zpz))->ZFc);}return R;}void Z4D(Zv6*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((ZFa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Zsu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void Z5D(Zv6*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((ZFa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){Zuu(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void Z6D(T75*C){(C->Zij)=(Z3)(((((C)->Zij)))+(ZGs(1)));
}T0*Z7D(T75*C){T0*R=Zo;R=Z8D(((C)->Zhj),((C)->Zij));return R;}void Z9D(T75*C,T0*a1){(C->Zhj)=a1;(C->Zij)=ZGs(1);}T6 ZaD(T75*C){T6 R=0;
R=((T6)((Z3)((((C)->Zij))>((((T32*)(((C)->Zhj)))->Zdc)))));return R;}void ZbD(ZR6*C,T0*a1,T0*a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=((((ZD8*)a2))->Zrf);
Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZYC((ZD8*)(((((ZQ3*)Zpz))->ZGc)),a2))))))
{Zpz=((((ZQ3*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZcD(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{ZQ3*n=((ZQ3*)Zh(sizeof(*n)));
*n=ZQe;ZTA(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}
else{((((ZQ3*)(((ZQ3*)Zpz))))->ZFc)=(a1);}}T0*ZdD(ZR6*C,T2 a1){T0*R=Zo;ZeD(C,a1);R=(((ZQ3*)(((C)->Zbc)))->ZFc);return R;}void ZeD(ZR6*C,T2
a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((ZQ3*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){
(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{ZeD(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZeD(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void ZfD(ZR6*C,T0*a1){T2 Zoz=0;
T2 Zft=0;T0*Zpz=Zo;T0*ZKz=Zo;(C->Zac)=ZGs(-1);Zoz=((((ZD8*)a1))->Zrf);Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];if((Zpz)!=((void*)(Zo))){
if(ZYC((ZD8*)(((((ZQ3*)Zpz))->ZGc)),a1)){(C->Zdc)=(Z3)(((((C)->Zdc)))-(ZGs(1)));Zpz=((((ZQ3*)Zpz))->ZHc);(((C)->Z9c))[Zft]=(Zpz);}else{
ZKz=Zpz;Zpz=((((ZQ3*)Zpz))->ZHc);while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZYC((ZD8*)(((((ZQ3*)Zpz))->ZGc)),a1)))))){ZKz=Zpz;Zpz=((((ZQ3*)Zpz))->ZHc);
}if((Zpz)!=((void*)(Zo))){(C->Zdc)=(Z3)(((((C)->Zdc)))-(ZGs(1)));((((ZQ3*)(((ZQ3*)ZKz))))->ZHc)=(((((ZQ3*)Zpz))->ZHc));}}}}void ZcD(ZR6*C){
T2 Zet=0;T2 Zft=0;T2 Zpx=0;Z9b Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((Z9b)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((ZQ3*)Ziz))->ZHc);
Zft=(Z3)(((((ZD8*)(((((ZQ3*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));((((ZQ3*)(((ZQ3*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZgD(ZR6*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((ZD8*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZYC((ZD8*)(((((ZQ3*)Zpz))->ZGc)),a1)))))){Zpz=((((ZQ3*)Zpz))->ZHc);}
R=((T6)((Zpz)!=((void*)(Zo))));return R;}void ZhD(ZR6*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){
ZcD(C);}Zft=(Z3)((((((ZD8*)a2))->Zrf))%(((C)->ZVb)));{ZQ3*n=((ZQ3*)Zh(sizeof(*n)));*n=ZQe;ZTA(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);
}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}void ZiD(ZR6*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Z9b)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*ZjD(ZR6*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((ZD8*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZYC((ZD8*)(((((ZQ3*)Zpz))->ZGc)),a1)))))){Zpz=((((ZQ3*)Zpz))->ZHc);}
if((Zpz)!=((void*)(Zo))){R=((((ZQ3*)Zpz))->ZFc);}return R;}T0*ZkD(T47*C,T2 a1){T0*R=Zo;ZlD(C,a1);R=(((T49*)(((C)->Zbc)))->ZGc);return
R;}T10 ZmD(T47*C,T0*a1){T10 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!(Z5v((T7*)(((((T49*)Zpz))->ZGc)),a1)))
{Zpz=((((T49*)Zpz))->ZHc);}R=((((T49*)Zpz))->ZFc);return R;}void ZnD(T47*C,T10 a1,T0*a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=ZBx(((T7*)a2));
Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((T49*)Zpz))->ZGc)),a2))))))
{Zpz=((((T49*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZoD(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{T49*n=((T49*)Zh(sizeof(*n)));
*n=M49;ZJC(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}
else{((((T49*)(((T49*)Zpz))))->ZFc)=(a1);}}T0*ZpD(T47*C,T10 a1){T0*R=Zo;T2 Zet=0;Zet=ZGs(1);while(!((a1)==(ZqD(C,Zet)))){Zet=(Z3)(((Zet))+(ZGs(1)));
}R=(((T49*)(((C)->Zbc)))->ZGc);return R;}T10 ZqD(T47*C,T2 a1){T10 R=0;ZlD(C,a1);R=(((T49*)(((C)->Zbc)))->ZFc);return R;}void ZlD(T47*C,T2
a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((T49*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){
(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{ZlD(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZlD(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void ZoD(T47*C){T2 Zet=0;T2 Zft=0;
T2 Zpx=0;T50 Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((T50)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((T49*)Ziz))->ZHc);
Zft=(Z3)((ZBx((T7*)(((((T49*)Ziz))->ZGc))))%(((C)->ZVb)));((((T49*)(((T49*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZrD(T47*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((T49*)Zpz))->ZGc)),a1)))))){Zpz=((((T49*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));
return R;}void ZsD(T47*C,T10 a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){ZoD(C);}Zft=(Z3)((ZBx(((T7*)a2)))%(((C)->ZVb)));
{T49*n=((T49*)Zh(sizeof(*n)));*n=M49;ZJC(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));
}void ZtD(T47*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((T50)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}void ZuD(Z07*C,T0*a1,T0*a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=((((T87*)a2))->Zrf);Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZhC((T87*)(((((Z87*)Zpz))->ZGc)),a2))))))
{Zpz=((((Z87*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZvD(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{Z87*n=((Z87*)Zh(sizeof(*n)));
*n=ZJj;ZwD(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}
else{((((Z87*)(((Z87*)Zpz))))->ZFc)=(a1);}}void ZvD(Z07*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Zfb Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));
Zhz=((C)->Z9c);(C->Z9c)=((Zfb)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];
while(!((Ziz)==((void*)(Zo)))){Zjz=((((Z87*)Ziz))->ZHc);Zft=(Z3)(((((T87*)(((((Z87*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));((((Z87*)(((Z87*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void ZxD(Z07*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Zfb)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*ZyD(Z07*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((T87*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZhC((T87*)(((((Z87*)Zpz))->ZGc)),a1)))))){Zpz=((((Z87*)Zpz))->ZHc);}
if((Zpz)!=((void*)(Zo))){R=((((Z87*)Zpz))->ZFc);}return R;}T0*ZzD(Z27*C,T2 a1){T0*R=Zo;ZAD(C,a1);R=(((ZH6*)(((C)->Zbc)))->ZFc);return
R;}void ZAD(Z27*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((ZH6*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{ZAD(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZAD(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void ZBD(Z27*C){T2 Zet=0;T2 Zft=0;
T2 Zpx=0;Z_a Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((Z_a)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((ZH6*)Ziz))->ZHc);
Zft=(Z3)((ZBx(((T7*)((((Zu9*)(((((ZH6*)Ziz))->ZFc)))->Zuk)))))%(((C)->ZVb)));((((ZH6*)(((ZH6*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void ZCD(Z27*C,T0*a1){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);Zoz=ZBx(((T7*)(((((Zu9*)a1))->Zuk))));
Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZDD((Zu9*)(((((ZH6*)Zpz))->ZFc)),a1))))))
{Zpz=((((ZH6*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZBD(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{ZH6*n=((ZH6*)Zh(sizeof(*n)));
*n=ZWl;ZED(n,a1,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}}void ZFD(Z27*C,T2 a1){
T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Z_a)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}void ZGD(ZI1*C,T0*a1,T0*a2,T0*a3){
(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void ZwD(Z87*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}T6 ZHD(Ze7*C,T2 a1){T6 R=0;
R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));return R;}T6 ZID(Ze7*C,T0*a1){T6 R=0;R=((T6)(ZHD(C,ZJD(C,a1))));
return R;}void ZKD(Ze7*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((ZKa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=ZHu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}T2 ZJD(Ze7*C,T0*a1){
T2 R=0;R=ZKu(((C)->ZUb),a1,((C)->ZWb));return R;}void ZLD(Ze7*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((ZKa)(Zk(a1,sizeof(T0*))));
(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZJu(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void ZMD(Ze7*C,T2 a1,T2 a2){
T0*ZVx=Zo;ZVx=(((C)->ZUb))[a1];(((C)->ZUb))[a1]=((((C)->ZUb))[a2]);(((C)->ZUb))[a2]=(ZVx);}T2 ZND(Zo7*C,T0*a1){T2 R=0;T2 Zft=0;T0*Zpz=Zo;
Zft=(Z3)((((((T85*)a1))->Zrf))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!(Zyz((T85*)(((((ZX8*)Zpz))->ZGc)),a1))){Zpz=((((ZX8*)Zpz))->ZHc);
}R=((((ZX8*)Zpz))->ZFc);return R;}void ZOD(Zo7*C,T2 a1,T0*a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=((((T85*)a2))->Zrf);Zft=(Z3)((Zoz)%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zyz((T85*)(((((ZX8*)Zpz))->ZGc)),a2)))))){Zpz=((((ZX8*)Zpz))->ZHc);}
if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZPD(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{ZX8*n=((ZX8*)Zh(sizeof(*n)));*n=Zgn;ZQD(n,a1,a2,(((C)->Z9c))[Zft]);
Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}else{((((ZX8*)(((ZX8*)Zpz))))->ZFc)=(a1);
}}void ZPD(Zo7*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Zcb Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Zcb)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((ZX8*)Ziz))->ZHc);Zft=(Z3)(((((T85*)(((((ZX8*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));((((ZX8*)(((ZX8*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZRD(Zo7*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((T85*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zyz((T85*)(((((ZX8*)Zpz))->ZGc)),a1)))))){Zpz=((((ZX8*)Zpz))->ZHc);}
R=((T6)((Zpz)!=((void*)(Zo))));return R;}T0*ZSD(Zo7*C,T0*a1){T0*R=Zo;T0*Zpz=Zo;Zpz=(((C)->Z9c))[(Z3)((((((T85*)a1))->Zrf))%(((C)->ZVb)))];
R=((((ZX8*)Zpz))->ZGc);while(!(Zyz(((T85*)R),a1))){Zpz=((((ZX8*)Zpz))->ZHc);R=((((ZX8*)Zpz))->ZGc);}return R;}void ZTD(Zo7*C,T2 a1){T2
Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Zcb)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*ZUD(Zs7*C,T2 a1){
T0*R=Zo;ZVD(C,a1);R=(((ZI1*)(((C)->Zbc)))->ZFc);return R;}void ZVD(Zs7*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;
(C->Zbc)=(((ZI1*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else{ZVD(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZVD(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));
}}}void ZWD(Zs7*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Zua Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Zua)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((ZI1*)Ziz))->ZHc);Zft=(Z3)((ZBx((T7*)(((((ZI1*)Ziz))->ZGc))))%(((C)->ZVb)));((((ZI1*)(((ZI1*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZXD(Zs7*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((ZI1*)Zpz))->ZGc)),a1)))))){Zpz=((((ZI1*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));
return R;}void ZYD(Zs7*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){ZWD(C);}Zft=(Z3)((ZBx(((T7*)a2)))%(((C)->ZVb)));
{ZI1*n=((ZI1*)Zh(sizeof(*n)));*n=ZDj;ZGD(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));
}void ZZD(Zs7*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Zua)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}void Z1D(Zt6*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void Z_D(ZS7*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Znb)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZAw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void Z0E(ZS7*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Znb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){ZCw(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void Z1E(Z_7*C){(C->Zij)=(Z3)(((((C)->Zij)))+(ZGs(1)));
}T0*Z2E(Z_7*C){T0*R=Zo;R=Z1B(((C)->Zyk),((C)->Zij));return R;}void ZEB(Z_7*C,T0*a1){(C->Zyk)=a1;(C->Zij)=Z4B(((C)->Zyk));}T6 Z3E(Z_7*C){
T6 R=0;R=((T6)(!(Z4E(((C)->Zyk),((C)->Zij)))));return R;}T0*Z5E(Z38*C,T2 a1){T0*R=Zo;Z6E(C,a1);R=(((Zu5*)(((C)->Zbc)))->ZFc);return R;
}void Z6E(Z38*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((Zu5*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{Z6E(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){Z6E(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void Z7E(Z38*C){T2 Zet=0;T2 Zft=0;
T2 Zpx=0;ZPa Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((ZPa)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((Zu5*)Ziz))->ZHc);
Zft=(Z3)((ZBx((T7*)(((((Zu5*)Ziz))->ZGc))))%(((C)->ZVb)));((((Zu5*)(((Zu5*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 Z8E(Z38*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((Zu5*)Zpz))->ZGc)),a1)))))){Zpz=((((Zu5*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));
return R;}void Z9E(Z38*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){Z7E(C);}Zft=(Z3)((ZBx(((T7*)a2)))%(((C)->ZVb)));
{Zu5*n=((Zu5*)Zh(sizeof(*n)));*n=ZUl;ZaE(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));
}void ZbE(Z38*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((ZPa)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}void ZOC(Z26*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}T0*ZcE(Z58*C){T0*R=Zo;R=(((C)->ZUb))[((C)->ZWb)];return R;}T6
ZdE(Z58*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));return R;}void ZeE(Z58*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){
(C->ZUb)=((ZIa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));
if((Z3)((((C)->ZWb))>=(ZGs(0)))){ZCu(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}void ZfE(Z58*C){(C->ZWb)=(Z3)(((((C)->ZWb)))-(ZGs(1)));
}T6 ZgE(Z58*C,T0*a1){T6 R=0;R=((T6)(ZdE(C,ZhE(C,a1))));return R;}void ZiE(Z58*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((ZIa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZDu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZjE(Z58*C,T2 a1){T2 Zpx=0;if((Z3)((a1)>((Z3)(((((C)->ZWb)))+(ZGs(1)))))){if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((ZIa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))<(a1))){Zpx=(Z3)(((((C)->ZVb)))*(ZGs(2)));while(!((Z3)((Zpx)>=(a1))))
{Zpx=(Z3)(((Zpx))*(ZGs(2)));}(C->ZUb)=ZDu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;}}else if((a1)!=((Z3)(((((C)->ZWb)))+(ZGs(1))))){ZFu(((C)->ZUb),a1,(Z3)((((Z3)(((((C)->ZWb)))+(ZGs(1)))))-((T2)(ZGs(1)))));
}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}T2 ZhE(Z58*C,T0*a1){T2 R=0;R=ZGu(((C)->ZUb),a1,((C)->ZWb));return R;}void ZkE(Z58*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((ZIa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZFu(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}void ZlE(Z98*C,T2 a1){Zhu(((C)->ZUb),a1,((C)->ZWb));(C->ZWb)=(Z3)(((((C)->ZWb)))-(ZGs(1)));}void ZmE(Z98*C){(C->ZWb)=(Z3)(((((C)->ZWb)))-(ZGs(1)));
}void ZnE(Z98*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zza)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=Zfu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZoE(Z98*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zza)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Ziu(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void ZIC(Zb8*C,T0*a1,T0*a2){(C->ZFc)=a1;(C->ZHc)=a2;}T0*ZpE(Zd8*C){T0*R=Zo;R=(((C)->ZUb))[((C)->ZWb)];return R;}void
ZqE(Zd8*C){(C->ZWb)=(Z3)(((((C)->ZWb)))-(ZGs(1)));}void ZrE(Zd8*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zya)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Zcu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZsE(Zd8*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zya)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){Zeu(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void ZtE(ZF8*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Zub
Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((Zub)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));
(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((Zd6*)Ziz))->ZHc);Zft=(Z3)(((((ZD8*)(((((Zd6*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));
((((Zd6*)(((Zd6*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void
ZuE(ZF8*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){ZtE(C);}Zft=(Z3)((((((ZD8*)a2))->Zrf))%(((C)->ZVb)));
{Zd6*n=((Zd6*)Zh(sizeof(*n)));*n=ZKi;ZWC(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));
}void ZvE(ZF8*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Zub)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}T0*ZwE(ZF8*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((ZD8*)a1))->Zrf))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZYC((ZD8*)(((((Zd6*)Zpz))->ZGc)),a1))))))
{Zpz=((((Zd6*)Zpz))->ZHc);}if((Zpz)!=((void*)(Zo))){R=((((Zd6*)Zpz))->ZFc);}return R;}void ZOA(Zx8*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;
(C->ZHc)=a3;}
#ifdef __cplusplus
}
#endif

