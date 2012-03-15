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
T2 Z8z(Z9a*C){T2 R=0;R=(Z3)((((Z3)(((((C)->ZWb)))-(((C)->ZXb)))))+(ZGs(1)));return R;}T0*Z9z(Z9a*C,T2 a1){T0*R=Zo;R=(((C)->ZUb))[(Z3)(((a1))-(((C)->ZXb)))];
return R;}void Zaz(Z9a*C,T0*a1){T2 Zpx=0;if((Z3)((((C)->ZVb))<((Z3)(((Z8z(C)))+(ZGs(1)))))){if((((C)->ZVb))==(ZGs(0))){Zpx=ZGs(16);(C->ZUb)=(((void)(((C)->ZUb))),((ZZa)(Zk(Zpx,sizeof(T0*)))));
(C->ZVb)=Zpx;}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Znv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;}}(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
{Z9a*C1=C;T0*b1=a1;T2 b2=((C)->ZWb);(((C1)->ZUb))[(Z3)(((b2))-(((C1)->ZXb)))]=(b1);}}void Zbz(Z9a*C,T2 a1,T2 a2){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=(((void)(((C)->ZUb))),((ZZa)(Zk(a1,sizeof(T0*)))));(C->ZVb)=a1;}(C->ZXb)=a2;(C->ZWb)=(Z3)(((a2))-(ZGs(1)));}void Zcz(ZH*C,T0*a1){
T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((Z6b)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZQv(((C)->ZUb),((C)->ZVb),Zpx);
(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void Zdz(ZH*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((Z6b)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZSv(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}T0*Zez(ZN*C,T2 a1){T0*R=Zo;Zfz(C,a1);R=(((Ze1*)(((C)->Zbc)))->ZFc);return R;}void Zfz(ZN*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){
(C->Zac)=a1;(C->Zbc)=(((Ze1*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else{Zfz(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){Zfz(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));
}}}void Zgz(ZN*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Zma Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Zma)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((Ze1*)Ziz))->ZHc);Zft=(Z3)((Zmz((ZV6*)(((((Ze1*)Ziz))->ZFc))))%(((C)->ZVb)));((((Ze1*)(((Ze1*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void Znz(ZN*C,T0*a1){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);
Zoz=Zmz(((ZV6*)a1));Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zqz((ZV6*)(((((Ze1*)Zpz))->ZFc)),a1))))))
{Zpz=((((Ze1*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){Zgz(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{Ze1*n=((Ze1*)Zh(sizeof(*n)));
*n=Z5d;Zrz(n,a1,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}}void Zsz(ZN*C,T2 a1){
T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Zma)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*Ztz(ZN*C,T0*a1){
T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((Zmz(((ZV6*)a1)))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zqz((ZV6*)(((((Ze1*)Zpz))->ZFc)),a1))))))
{Zpz=((((Ze1*)Zpz))->ZHc);}if((Zpz)!=((void*)(Zo))){R=((((Ze1*)Zpz))->ZFc);}return R;}void Zuz(ZP*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zsb)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZTw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void Zvz(ZP*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zsb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){ZVw(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void Zwz(ZR*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;ZXa Zhz=Zo;
T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((ZXa)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));
(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((ZD2*)Ziz))->ZHc);Zft=(Z3)(((((T85*)(((((ZD2*)Ziz))->ZFc)))->Zrf))%(((C)->ZVb)));
((((ZD2*)(((ZD2*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 Zxz(ZR*C,T0*a1){
T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((T85*)a1))->Zrf))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zyz((T85*)(((((ZD2*)Zpz))->ZFc)),a1))))))
{Zpz=((((ZD2*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));return R;}void Zzz(ZR*C,T0*a1){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);
Zoz=((((T85*)a1))->Zrf);Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zyz((T85*)(((((ZD2*)Zpz))->ZFc)),a1))))))
{Zpz=((((ZD2*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){Zwz(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{ZD2*n=((ZD2*)Zh(sizeof(*n)));
*n=ZSd;ZAz(n,a1,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}}void ZBz(ZR*C,T2 a1){
T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((ZXa)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T70*ZCz(void){T70*n;
n=((T70*)Zh(sizeof(*n)));*n=M70;{T70*C1=n;ZDz(C1,Zxt(193));}return n;}T0*ZEz(T70*C,T2 a1){T0*R=Zo;ZFz(C,a1);R=(((T37*)(((C)->Zbc)))->ZGc);
return R;}T0*ZGz(T70*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!(Z5v((T7*)(((((T37*)Zpz))->ZGc)),a1)))
{Zpz=((((T37*)Zpz))->ZHc);}R=((((T37*)Zpz))->ZFc);return R;}T0*ZHz(T70*C,T2 a1){T0*R=Zo;ZFz(C,a1);R=(((T37*)(((C)->Zbc)))->ZFc);return
R;}void ZIz(T70*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((T36)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}void ZFz(T70*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((T37*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{ZFz(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZFz(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void ZJz(T70*C,T0*a1){T2 Zoz=0;
T2 Zft=0;T0*Zpz=Zo;T0*ZKz=Zo;(C->Zac)=ZGs(-1);Zoz=ZBx(((T7*)a1));Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];if((Zpz)!=((void*)(Zo))){
if(Z5v((T7*)(((((T37*)Zpz))->ZGc)),a1)){(C->Zdc)=(Z3)(((((C)->Zdc)))-(ZGs(1)));Zpz=((((T37*)Zpz))->ZHc);(((C)->Z9c))[Zft]=(Zpz);}else{
ZKz=Zpz;Zpz=((((T37*)Zpz))->ZHc);while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((T37*)Zpz))->ZGc)),a1)))))){ZKz=Zpz;Zpz=((((T37*)Zpz))->ZHc);
}if((Zpz)!=((void*)(Zo))){(C->Zdc)=(Z3)(((((C)->Zdc)))-(ZGs(1)));((((T37*)(((T37*)ZKz))))->ZHc)=(((((T37*)Zpz))->ZHc));}}}}void ZLz(T70*C){
T2 Zet=0;T2 Zft=0;T2 Zpx=0;T36 Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((T36)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((T37*)Ziz))->ZHc);
Zft=(Z3)((ZBx((T7*)(((((T37*)Ziz))->ZGc))))%(((C)->ZVb)));((((T37*)(((T37*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void ZMz(T70*C){Zu();Zv(ZGs(1));}T6 ZNz(T70*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;
Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((T37*)Zpz))->ZGc)),a1))))))
{Zpz=((((T37*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));return R;}void ZOz(T70*C,T0*a1,T0*a2){ZPz(C,a1,a2);ZQz((T55*)(((C)->Zxc)),a2);
}void ZPz(T70*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);if((((C)->ZVb))==(((C)->Zdc))){ZLz(C);}Zft=(Z3)((ZBx(((T7*)a2)))%(((C)->ZVb)));
{T37*n=((T37*)Zh(sizeof(*n)));*n=M37;ZRz(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));
}void ZDz(T70*C,T2 a1){ZIz(C,a1);{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;ZSz(n,a1);(C->Zxc)=((T0*)n);}}T0*ZTz(T70*C,T0*a1){T0*R=Zo;T2 Zft=0;
T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((T37*)Zpz))->ZGc)),a1))))))
{Zpz=((((T37*)Zpz))->ZHc);}if((Zpz)!=((void*)(Zo))){R=((((T37*)Zpz))->ZFc);}return R;}void ZUz(Z81*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;
(C->ZHc)=a3;}void ZVz(Zk1*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Z1b)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=Zsv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZWz(Zk1*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Z1b)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Zuv(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void Zrz(Ze1*C,T0*a1,T0*a2){(C->ZFc)=a1;(C->ZHc)=a2;}void ZXz(Zu1*C,T0*a1){T2 ZYz=0;T2 Zpx=0;ZYz=((((Zu1*)a1))->ZWb);
if((Z3)((ZYz)>=(ZGs(0)))){Zpx=(Z3)(((ZYz))+(ZGs(1)));if((Z3)((((C)->ZVb))<(Zpx))){(C->ZUb)=((Z7b)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;
}else if((Z3)((((C)->ZVb))>(ZGs(0)))){ZTv(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));}ZVv(((C)->ZUb),((((Zu1*)a1))->ZUb),ZYz);}else
if((Z3)((((C)->ZVb))>(ZGs(0)))){ZTv(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));}(C->ZWb)=ZYz;}T6 ZZz(Zu1*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));
return R;}T6 Z_z(Zu1*C,T0*a1){T6 R=0;R=((T6)(ZZz(C,Z0A(C,a1))));return R;}void Z1A(Zu1*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Z7b)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZUv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}T2 Z0A(Zu1*C,T0*a1){T2 R=0;R=ZXv(((C)->ZUb),a1,((C)->ZWb));return R;}T0*Z2A(Zu1*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Zu1*)R)=Z6d;ZXz(((Zu1*)R),((T0*)C));return R;}void Z3A(Zu1*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Z7b)(Zk(a1,sizeof(T0*))));
(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZWv(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}T6 Z4A(ZE1*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));
return R;}T6 Z5A(ZE1*C,T0*a1){T6 R=0;R=((T6)(Z4A(C,Z6A(C,a1))));return R;}void Z7A(ZE1*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zib)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Zfw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}T2 Z6A(ZE1*C,T0*a1){T2 R=0;R=Ziw(((C)->ZUb),a1,((C)->ZWb));return R;}void Z8A(ZE1*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((Zib)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Zhw(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}void Z9A(ZQ1*C,T0*a1,T0*a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=ZBx(((T7*)a2));Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((Z81*)Zpz))->ZGc)),a2))))))
{Zpz=((((Z81*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZaA(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{Z81*n=((Z81*)Zh(sizeof(*n)));
*n=ZIc;ZUz(n,a1,a2,(((C)->Z9c))[Zft]);Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}
else{((((Z81*)(((Z81*)Zpz))))->ZFc)=(a1);}}T0*ZbA(ZQ1*C,T2 a1){T0*R=Zo;ZcA(C,a1);R=(((Z81*)(((C)->Zbc)))->ZFc);return R;}void ZcA(ZQ1*C,T2
a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;(C->Zbc)=(((Z81*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){
(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);
(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else{ZcA(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZcA(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));}}}void ZaA(ZQ1*C){T2 Zet=0;T2 Zft=0;
T2 Zpx=0;ZJa Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);(C->Z9c)=((ZJa)(Zk(Zpx,sizeof(T0*))));
Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo)))){Zjz=((((Z81*)Ziz))->ZHc);
Zft=(Z3)((ZBx((T7*)(((((Z81*)Ziz))->ZGc))))%(((C)->ZVb)));((((Z81*)(((Z81*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void ZdA(ZQ1*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((ZJa)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*ZeA(ZQ1*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZBx(((T7*)a1)))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z5v((T7*)(((((Z81*)Zpz))->ZGc)),a1)))))){Zpz=((((Z81*)Zpz))->ZHc);}if((Zpz)!=((void*)(Zo))){
R=((((Z81*)Zpz))->ZFc);}return R;}void ZfA(ZY1*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void ZgA(Z12*C,T0*a1,T0*a2){
(C->ZFc)=a1;(C->ZHc)=a2;}T6 ZhA(Z52*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));return R;
}T6 ZiA(Z52*C,T0*a1){T6 R=0;R=((T6)(ZhA(C,ZjA(C,a1))));return R;}void ZkA(Z52*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zla)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=ZIt(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}T2 ZjA(Z52*C,T0*a1){T2 R=0;R=ZMt(((C)->ZUb),a1,((C)->ZWb));return R;}void ZlA(Z52*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((Zla)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZKt(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}void ZmA(Z72*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Z0b)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=Zpv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZnA(Z72*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Z0b)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Zrv(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void ZoA(ZB2*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zta)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=Z0u(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZpA(ZB2*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zta)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Z2u(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void ZAz(ZD2*C,T0*a1,T0*a2){(C->ZFc)=a1;(C->ZHc)=a2;}void ZqA(Z43*C,T0*a1){T2 ZYz=0;T2 Zpx=0;ZYz=((((Z43*)a1))->ZWb);
if((Z3)((ZYz)>=(ZGs(0)))){Zpx=(Z3)(((ZYz))+(ZGs(1)));if((Z3)((((C)->ZVb))<(Zpx))){(C->ZUb)=((Zva)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;
}else if((Z3)((((C)->ZVb))>(ZGs(0)))){Z3u(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));}Z5u(((C)->ZUb),((((Z43*)a1))->ZUb),ZYz);}else
if((Z3)((((C)->ZVb))>(ZGs(0)))){Z3u(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));}(C->ZWb)=ZYz;}void ZrA(Z43*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){
(C->ZUb)=((Zva)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));
if((Z3)((((C)->ZWb))>=(ZGs(0)))){Z3u(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}void ZsA(Z43*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zva)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Z4u(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZtA(Z43*C,T2 a1){T2 Zpx=0;if((Z3)((a1)>((Z3)(((((C)->ZWb)))+(ZGs(1)))))){if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((Zva)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))<(a1))){Zpx=(Z3)(((((C)->ZVb)))*(ZGs(2)));while(!((Z3)((Zpx)>=(a1))))
{Zpx=(Z3)(((Zpx))*(ZGs(2)));}(C->ZUb)=Z4u(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;}}else if((a1)!=((Z3)(((((C)->ZWb)))+(ZGs(1))))){Z6u(((C)->ZUb),a1,(Z3)((((Z3)(((((C)->ZWb)))+(ZGs(1)))))-((T2)(ZGs(1)))));
}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}T0*ZuA(Z43*C){T0*R=Zo;R=Zh(sizeof(*C));*((Z43*)R)=Zce;ZqA(((Z43*)R),((T0*)C));return R;}void ZvA(Z43*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zva)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Z6u(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void ZwA(Zc3*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){(C->ZUb)=((Zdb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){
(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));if((Z3)((((C)->ZWb))>=(ZGs(0)))){Z1w(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));
}void ZxA(Zc3*C,T2 a1){T2 Zpx=0;if((Z3)((a1)>((Z3)(((((C)->ZWb)))+(ZGs(1)))))){if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zdb)(Zk(a1,sizeof(T0*))));
(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))<(a1))){Zpx=(Z3)(((((C)->ZVb)))*(ZGs(2)));while(!((Z3)((Zpx)>=(a1)))){Zpx=(Z3)(((Zpx))*(ZGs(2)));
}(C->ZUb)=Z2w(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;}}else if((a1)!=((Z3)(((((C)->ZWb)))+(ZGs(1))))){Z4w(((C)->ZUb),a1,(Z3)((((Z3)(((((C)->ZWb)))+(ZGs(1)))))-((T2)(ZGs(1)))));
}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}void ZyA(Zs1*C,T2 a1,T2 a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}T6 ZzA(Zy3*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));
return R;}T6 ZAA(Zy3*C,T0*a1){T6 R=0;R=((T6)(ZzA(C,ZBA(C,a1))));return R;}void ZCA(Zy3*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((ZHa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Zyu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}T2 ZBA(Zy3*C,T0*a1){T2 R=0;R=ZBu(((C)->ZUb),a1,((C)->ZWb));return R;}void ZDA(Zy3*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((ZHa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZAu(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}void ZEA(ZA3*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){(C->ZUb)=((Z3b)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){
(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));if((Z3)((((C)->ZWb))>=(ZGs(0)))){ZKv(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));
}void ZFA(ZA3*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Z3b)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=ZLv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZGA(ZA3*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Z3b)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZNv(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void ZHA(ZK3*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){(C->ZUb)=((Zab)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){
(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));if((Z3)((((C)->ZWb))>=(ZGs(0)))){ZYv(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));
}void ZIA(ZK3*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zab)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=ZZv(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZJA(ZK3*C,T2
a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zab)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Z0w(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));
}(C->ZWb)=ZGs(-1);}void ZKA(ZO3*C,T0*a1,T0*a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=ZLA(((T93*)a2));Zft=(Z3)((Zoz)%(((C)->ZVb)));Zpz=(((C)->Z9c))[Zft];
while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZMA((T93*)(((((Zx8*)Zpz))->ZGc)),a2)))))){Zpz=((((Zx8*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){
if((((C)->ZVb))==(((C)->Zdc))){ZNA(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{Zx8*n=((Zx8*)Zh(sizeof(*n)));*n=Zdl;ZOA(n,a1,a2,(((C)->Z9c))[Zft]);
Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}else{((((Zx8*)(((Zx8*)Zpz))))->ZFc)=(a1);
}}T0*ZPA(ZO3*C,T2 a1){T0*R=Zo;ZQA(C,a1);R=(((Zx8*)(((C)->Zbc)))->ZFc);return R;}void ZQA(ZO3*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){
(C->Zac)=a1;(C->Zbc)=(((Zx8*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else{ZQA(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZQA(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));
}}}void ZNA(ZO3*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Z8b Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Z8b)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((Zx8*)Ziz))->ZHc);Zft=(Z3)((ZLA((T93*)(((((Zx8*)Ziz))->ZGc))))%(((C)->ZVb)));((((Zx8*)(((Zx8*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void ZRA(ZO3*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Z8b)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*ZSA(ZO3*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((ZLA(((T93*)a1)))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZMA((T93*)(((((Zx8*)Zpz))->ZGc)),a1)))))){Zpz=((((Zx8*)Zpz))->ZHc);}
if((Zpz)!=((void*)(Zo))){R=((((Zx8*)Zpz))->ZFc);}return R;}void ZTA(ZQ3*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void
ZUA(ZU3*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Zkb Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Zkb)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((Zj4*)Ziz))->ZHc);Zft=(Z3)(((((T85*)(((((Zj4*)Ziz))->ZGc)))->Zrf))%(((C)->ZVb)));((((Zj4*)(((Zj4*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}void ZVA(ZU3*C,T0*a1,T0*a2){T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);
if((((C)->ZVb))==(((C)->Zdc))){ZUA(C);}Zft=(Z3)((((((T85*)a2))->Zrf))%(((C)->ZVb)));{Zj4*n=((Zj4*)Zh(sizeof(*n)));*n=Z4g;ZWA(n,a1,a2,(((C)->Z9c))[Zft]);
Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}void ZXA(ZU3*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Zkb)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}T0*ZYA(ZU3*C,T0*a1){T0*R=Zo;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((T85*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Zyz((T85*)(((((Zj4*)Zpz))->ZGc)),a1)))))){Zpz=((((Zj4*)Zpz))->ZHc);}
if((Zpz)!=((void*)(Zo))){R=((((Zj4*)Zpz))->ZFc);}return R;}void ZZA(T0*a1,T2 a2,T2 a3){T2 Z_A=0;T2 Zet=0;if((Z3)((a2)<(a3))){Zet=(Z3)((((Z3)(((a2))+((Z3)(((Z3)(((a3))-(a2)))/(ZGs(2)))))))+(ZGs(1)));
Z0B(a1,a2,Zet);Z_A=a2;Zet=(Z3)(((a2))+(ZGs(1)));while(!((Z3)((Zet)>(a3)))){if(Zvx((T7*)(Z1B(a1,Zet)),Z1B(a1,a2))){Z_A=(Z3)(((Z_A))+(ZGs(1)));
Z0B(a1,Z_A,Zet);}Zet=(Z3)(((Zet))+(ZGs(1)));}Z0B(a1,a2,Z_A);ZZA(a1,a2,(Z3)(((Z_A))-((T2)(ZGs(1)))));ZZA(a1,(Z3)(((Z_A))+((T2)(ZGs(1)))),a3);
}}void Z2B(T0*a1){if(!(Z3B(a1))){{T0*b1=a1;ZZA(b1,Z4B(b1),((((T55*)b1))->ZWb));}}}T6 Z3B(T0*a1){T6 R=0;T2 Zet=0;T2 Z5B=0;T0*Z6B=Zo;T0*Z7B=Zo;
Zet=Z4B(a1);Z5B=((((T55*)a1))->ZWb);R=((T6)(1));if((Z3)((Z5B)>(Zet))){Z6B=Z1B(a1,Zet);while(!((T6)((!(R))||((T6)((Z3)((Zet)>=(Z5B)))))))
{Zet=(Z3)(((Zet))+(ZGs(1)));Z7B=Z1B(a1,Zet);R=((T6)(Zux(((T7*)Z6B),Z7B)));Z6B=Z7B;}}return R;}void Z8B(Z04*C,T0*a1){T2 ZYz=0;T2 Zpx=0;
ZYz=((((Z04*)a1))->ZWb);if((Z3)((ZYz)>=(ZGs(0)))){Zpx=(Z3)(((ZYz))+(ZGs(1)));if((Z3)((((C)->ZVb))<(Zpx))){(C->ZUb)=((Zrb)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){ZNw(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));}ZPw(((C)->ZUb),((((Z04*)a1))->ZUb),ZYz);
}else if((Z3)((((C)->ZVb))>(ZGs(0)))){ZNw(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));}(C->ZWb)=ZYz;}void Z9B(Z04*C){Zrb ZaB=Zo;if((((C)->ZWb))==(ZGs(0))){
(C->ZUb)=ZaB;(C->ZVb)=ZGs(0);(C->ZWb)=ZGs(-1);}else{ZQw(((C)->ZUb),((C)->ZWb));(C->ZWb)=(Z3)(((((C)->ZWb)))-(ZGs(1)));}}void ZbB(Z04*C,T2
a1){ZRw(((C)->ZUb),a1,((C)->ZWb));(C->ZWb)=(Z3)(((((C)->ZWb)))-(ZGs(1)));}void ZcB(Z04*C,T0*a1){ZdB(C,a1);if((((C)->ZWb))==(ZGs(0))){
}else if((((C)->ZWb))==(ZGs(1))){ZeB(C,(T2)(ZGs(0)),(T2)(ZGs(1)));}else{ZfB(C,(T2)(ZGs(0)),(Z3)(((((C)->ZWb)))-((T2)(ZGs(1)))),(T2)(ZGs(1)));
(((C)->ZUb))[(T2)(ZGs(0))]=(a1);}}void ZfB(Z04*C,T2 a1,T2 a2,T2 a3){T0*ZgB=Zo;T2 Zet=0;if((a3)==(ZGs(0))){}else if((Z3)((a3)<(ZGs(0)))){
Zet=a1;while(!((Z3)((Zet)>(a2)))){(((C)->ZUb))[(Z3)(((Zet))+(a3))]=((((C)->ZUb))[Zet]);(((C)->ZUb))[Zet]=(ZgB);Zet=(Z3)(((Zet))+(ZGs(1)));
}}else{Zet=a2;while(!((Z3)((Zet)<(a1)))){(((C)->ZUb))[(Z3)(((Zet))+(a3))]=((((C)->ZUb))[Zet]);(((C)->ZUb))[Zet]=(ZgB);Zet=(Z3)(((Zet))-(ZGs(1)));
}}}void ZdB(Z04*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zrb)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=ZOw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZhB(Z04*C,T0*a1,T2
a2){if((a2)==((Z3)(((((C)->ZWb)))+(ZGs(1))))){ZdB(C,a1);}else{ZdB(C,a1);ZfB(C,a2,(Z3)(((((C)->ZWb)))-((T2)(ZGs(1)))),(T2)(ZGs(1)));(((C)->ZUb))[a2]=(a1);
}}T0*ZiB(Z04*C){T0*R=Zo;R=Zh(sizeof(*C));*((Z04*)R)=Zhf;Z8B(((Z04*)R),((T0*)C));return R;}void ZjB(Z04*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((Zrb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){ZSw(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}void ZeB(Z04*C,T2 a1,T2 a2){T0*ZVx=Zo;ZVx=(((C)->ZUb))[a1];(((C)->ZUb))[a1]=((((C)->ZUb))[a2]);(((C)->ZUb))[a2]=(ZVx);}T0*ZkB(Z44*C,T2
a1){T0*R=Zo;ZlB(C,a1);R=(((ZS5*)(((C)->Zbc)))->ZFc);return R;}void ZlB(Z44*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){(C->Zac)=a1;
(C->Zbc)=(((ZS5*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else{ZlB(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZlB(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));
}}}void ZmB(Z44*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Ztb Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Ztb)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((ZS5*)Ziz))->ZHc);Zft=(Z3)(((((Z64*)(((((ZS5*)Ziz))->ZFc)))->Zrf))%(((C)->ZVb)));((((ZS5*)(((ZS5*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);
(((C)->Z9c))[Zft]=(Ziz);Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZnB(Z44*C,T0*a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((((((Z64*)a1))->Zrf))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZoB((Z64*)(((((ZS5*)Zpz))->ZFc)),a1)))))){Zpz=((((ZS5*)Zpz))->ZHc);}
R=((T6)((Zpz)!=((void*)(Zo))));return R;}void ZpB(Z44*C,T0*a1){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;(C->Zac)=ZGs(-1);Zoz=((((Z64*)a1))->Zrf);Zft=(Z3)((Zoz)%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(ZoB((Z64*)(((((ZS5*)Zpz))->ZFc)),a1)))))){Zpz=((((ZS5*)Zpz))->ZHc);}
if((Zpz)==((void*)(Zo))){if((((C)->ZVb))==(((C)->Zdc))){ZmB(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{ZS5*n=((ZS5*)Zh(sizeof(*n)));*n=ZYh;ZqB(n,a1,(((C)->Z9c))[Zft]);
Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));}}void ZrB(Z44*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Ztb)(Zk(Zpx,sizeof(T0*))));
(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);}void ZsB(Zg4*C,T0*a1,T2 a2){T2 Zoz=0;T2 Zft=0;T0*Zpz=Zo;Zoz=Zbt(a2);Zft=(Z3)((Zoz)%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z_s(((((Z25*)Zpz))->ZGc),a2)))))){Zpz=((((Z25*)Zpz))->ZHc);}if((Zpz)==((void*)(Zo))){
if((((C)->ZVb))==(((C)->Zdc))){ZtB(C);Zft=(Z3)((Zoz)%(((C)->ZVb)));}{Z25*n=((Z25*)Zh(sizeof(*n)));*n=Z7h;ZuB(n,a1,a2,(((C)->Z9c))[Zft]);
Zpz=((T0*)n);}(((C)->Z9c))[Zft]=(Zpz);(C->Zdc)=(Z3)(((((C)->Zdc)))+(ZGs(1)));(C->Zac)=ZGs(-1);}else{((((Z25*)(((Z25*)Zpz))))->ZFc)=(a1);
}}T0*ZvB(Zg4*C,T2 a1){T0*R=Zo;ZwB(C,a1);R=(((Z25*)(((C)->Zbc)))->ZFc);return R;}void ZwB(Zg4*C,T2 a1){if((a1)==((Z3)(((((C)->Zac)))+(ZGs(1))))){
(C->Zac)=a1;(C->Zbc)=(((Z25*)(((C)->Zbc)))->ZHc);while(!((((C)->Zbc))!=((void*)(Zo)))){(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];
}}else if((a1)==(((C)->Zac))){}else if((a1)==(ZGs(1))){(C->Zac)=ZGs(1);(C->Zcc)=ZGs(0);(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];while(!((((C)->Zbc))!=((void*)(Zo))))
{(C->Zcc)=(Z3)(((((C)->Zcc)))+(ZGs(1)));(C->Zbc)=(((C)->Z9c))[((C)->Zcc)];}}else{ZwB(C,(T2)(ZGs(1)));while(!((((C)->Zac))==(a1))){ZwB(C,(Z3)(((((C)->Zac)))+((T2)(ZGs(1)))));
}}}void ZtB(Zg4*C){T2 Zet=0;T2 Zft=0;T2 Zpx=0;Zjb Zhz=Zo;T0*Ziz=Zo;T0*Zjz=Zo;int Zkz=0;Zpx=Zlz((Z3)(((((C)->ZVb)))+(ZGs(1))));Zhz=((C)->Z9c);
(C->Z9c)=((Zjb)(Zk(Zpx,sizeof(T0*))));Zet=(Z3)(((((C)->ZVb)))-(ZGs(1)));(C->ZVb)=Zpx;while(!((Z3)((Zet)<(ZGs(0))))){Ziz=(Zhz)[Zet];while(!((Ziz)==((void*)(Zo))))
{Zjz=((((Z25*)Ziz))->ZHc);Zft=(Z3)((Zbt(((((Z25*)Ziz))->ZGc)))%(((C)->ZVb)));((((Z25*)(((Z25*)Ziz))))->ZHc)=((((C)->Z9c))[Zft]);(((C)->Z9c))[Zft]=(Ziz);
Ziz=Zjz;}Zet=(Z3)(((Zet))-(ZGs(1)));}(C->Zac)=ZGs(-1);}T6 ZxB(Zg4*C,T2 a1){T6 R=0;T2 Zft=0;T0*Zpz=Zo;Zft=(Z3)((Zbt(a1))%(((C)->ZVb)));
Zpz=(((C)->Z9c))[Zft];while(!((T6)(((Zpz)==((void*)(Zo)))||((T6)(Z_s(((((Z25*)Zpz))->ZGc),a1)))))){Zpz=((((Z25*)Zpz))->ZHc);}R=((T6)((Zpz)!=((void*)(Zo))));
return R;}void ZyB(Zg4*C,T2 a1){T2 Zpx=0;int Zkz=0;Zpx=Zlz(a1);(C->Z9c)=((Zjb)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;(C->Zac)=ZGs(-1);(C->Zdc)=ZGs(0);
}void ZRz(T37*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;}void ZWA(Zj4*C,T0*a1,T0*a2,T0*a3){(C->ZFc)=a1;(C->ZGc)=a2;(C->ZHc)=a3;
}T0*ZzB(T55*C){T0*R=Zo;R=(((C)->ZUb))[((C)->ZWb)];return R;}T6 ZAB(T55*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));
return R;}T2 ZBB(T55*C,T0*a1){T2 R=0;R=Z9v(((C)->ZUb),a1,((C)->ZWb));return R;}void ZCB(T55*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){(C->ZUb)=((T63)(Zk(a1,sizeof(T0*))));
(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));if((Z3)((((C)->ZWb))>=(ZGs(0)))){Z6v(((C)->ZUb),((C)->ZWb));
}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}T0*ZDB(T55*C){T0*R=Zo;{Z_7*n=((Z_7*)Zh(sizeof(*n)));*n=Zzk;ZEB(n,(T0*)C);R=((T0*)n);}return R;}T6 ZFB(T55*C,T0*a1){
T6 R=0;R=((T6)(ZAB(C,ZBB(C,a1))));return R;}T6 ZGB(T55*C,T0*a1){T6 R=0;R=((T6)(ZAB(C,ZHB(C,a1))));return R;}void ZQz(T55*C,T0*a1){T2 Zpx=0;
if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){
(C->ZUb)=((T63)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Z7v(((C)->ZUb),((C)->ZVb),Zpx);
(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZIB(T55*C,T2 a1){T2 Zpx=0;if((Z3)((a1)>((Z3)(((((C)->ZWb)))+(ZGs(1)))))){
if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((T63)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))<(a1))){Zpx=(Z3)(((((C)->ZVb)))*(ZGs(2)));
while(!((Z3)((Zpx)>=(a1)))){Zpx=(Z3)(((Zpx))*(ZGs(2)));}(C->ZUb)=Z7v(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;}}else if((a1)!=((Z3)(((((C)->ZWb)))+(ZGs(1))))){
Zav(((C)->ZUb),a1,(Z3)((((Z3)(((((C)->ZWb)))+(ZGs(1)))))-((T2)(ZGs(1)))));}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}T2 ZHB(T55*C,T0*a1){T2 R=0;
R=Zbv(((C)->ZUb),a1,((C)->ZWb));return R;}void ZSz(T55*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((T63)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;
}else if((Z3)((((C)->ZVb))>(a1))){Zav(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void ZJB(T55*C,T0*a1){T2 Zwv=0;T2 Zxv=0;
T2 ZKB=0;ZSz(C,ZLB(a1));(C->ZWb)=(Z3)(((ZLB(a1)))-(ZGs(1)));Zwv=ZGs(0);Zxv=Z4B(a1);ZKB=((((T55*)a1))->ZWb);while(!((Z3)((Zxv)>(ZKB))))
{(((C)->ZUb))[Zwv]=(Z1B(a1,Zxv));Zwv=(Z3)(((Zwv))+(ZGs(1)));Zxv=(Z3)(((Zxv))+(ZGs(1)));}}void ZMB(T55*C,T2 a1,T2 a2){T0*ZVx=Zo;ZVx=(((C)->ZUb))[a1];
(((C)->ZUb))[a1]=((((C)->ZUb))[a2]);(((C)->ZUb))[a2]=(ZVx);}void ZNB(Zp4*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zhb)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Zcw(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZOB(Zp4*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zhb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){Zew(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void ZPB(Zr4*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zgb)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Z9w(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}void ZQB(Zr4*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((Zgb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else
if((Z3)((((C)->ZVb))>(a1))){Zbw(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}T6 ZRB(Zv4*C,T2 a1){T6 R=0;R=((T6)((T6)(((Z3)((ZGs(0))<=(a1)))&&((T6)((Z3)((a1)<=(((C)->ZWb))))))));
return R;}T6 ZSB(Zv4*C,T0*a1){T6 R=0;R=((T6)(ZRB(C,ZTB(C,a1))));return R;}void ZUB(Zv4*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){
(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((Zeb)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);
}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));(C->ZUb)=Z5w(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}
(((C)->ZUb))[((C)->ZWb)]=(a1);}T2 ZTB(Zv4*C,T0*a1){T2 R=0;R=Z8w(((C)->ZUb),a1,((C)->ZWb));return R;}void ZVB(Zv4*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){
(C->ZUb)=((Zeb)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Z7w(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);
}void ZWB(ZB4*C,T0*a1){T2 ZYz=0;T2 Zpx=0;ZYz=((((ZB4*)a1))->ZWb);if((Z3)((ZYz)>=(ZGs(0)))){Zpx=(Z3)(((ZYz))+(ZGs(1)));if((Z3)((((C)->ZVb))<(Zpx))){
(C->ZUb)=((ZQa)(Zk(Zpx,sizeof(T0*))));(C->ZVb)=Zpx;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){ZYu(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));
}Z_u(((C)->ZUb),((((ZB4*)a1))->ZUb),ZYz);}else if((Z3)((((C)->ZVb))>(ZGs(0)))){ZYu(((C)->ZUb),(Z3)(((((C)->ZVb)))-((T2)(ZGs(1)))));}(C->ZWb)=ZYz;
}void ZXB(ZB4*C,T0*a1){T2 Zpx=0;if((Z3)(((Z3)(((((C)->ZWb)))+(ZGs(1))))<=((Z3)(((((C)->ZVb)))-(ZGs(1)))))){(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));
}else if((((C)->ZVb))==(ZGs(0))){(C->ZUb)=((ZQa)(Zk(ZGs(2),sizeof(T0*))));(C->ZVb)=ZGs(2);(C->ZWb)=ZGs(0);}else{Zpx=(Z3)(((ZGs(2)))*(((C)->ZVb)));
(C->ZUb)=ZZu(((C)->ZUb),((C)->ZVb),Zpx);(C->ZVb)=Zpx;(C->ZWb)=(Z3)(((((C)->ZWb)))+(ZGs(1)));}(((C)->ZUb))[((C)->ZWb)]=(a1);}T0*ZYB(ZB4*C){
T0*R=Zo;R=Zh(sizeof(*C));*((ZB4*)R)=ZBg;ZWB(((ZB4*)R),((T0*)C));return R;}void ZZB(ZB4*C,T2 a1){if((Z3)((((C)->ZVb))<(a1))){(C->ZUb)=((ZQa)(Zk(a1,sizeof(T0*))));
(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(a1))){Z0v(((C)->ZUb),(T2)(ZGs(0)),((C)->ZWb));}(C->ZWb)=ZGs(-1);}void Z_B(ZD4*C,T2 a1){if((Z3)((a1)>(((C)->ZVb)))){
(C->ZUb)=((ZSa)(Zk(a1,sizeof(T0*))));(C->ZVb)=a1;}else if((Z3)((((C)->ZVb))>(ZGs(0)))){(C->ZWb)=Z3t(((C)->ZWb),(Z3)(((a1))-(ZGs(1))));
if((Z3)((((C)->ZWb))>=(ZGs(0)))){Z3v(((C)->ZUb),((C)->ZWb));}}(C->ZWb)=(Z3)(((a1))-(ZGs(1)));}
#ifdef __cplusplus
}
#endif

