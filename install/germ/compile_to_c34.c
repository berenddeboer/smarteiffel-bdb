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
T0*Z_G2(ZQ9*C){T0*R=Zo;T6 Zd22=0;T0*ZOP=Zo;T0*ZWF=Zo;(C->ZYe)=Zo;(C->ZWe)=ZGs(1);(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(ZIJ2()))->Zal))))->ZUb))[((C)->ZWe)];
if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}ZJJ2(C);while(!(Zd22))
{if((((C)->_cc))==(((T3)'\000'))){Zd22=((T6)(1));}else if(ZKJ2(C,ZdE2)){Zd22=((T6)(1));{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zwx(n,(T2)(ZGs(32)));
ZOP=((T0*)n);}while(!(ZGx(((T7*)ZLJ2),((C)->_cc)))){Zgt(((T7*)ZOP),((C)->_cc));ZMJ2(C);}{T85*n=((T85*)Zh(sizeof(*n)));*n=M85;Zb41(n,(((void)((T27*)(ZNJ2()))),ZCG(ZOP)));
ZWF=((T0*)n);}}else{while(!(ZGx(((T7*)ZOJ2),((C)->_cc)))){ZMJ2(C);}ZJJ2(C);}}if((ZWF)==((void*)(Zo))){{T0*b1=Z1G(38,"Unable to find a class definition in \"");
Zmx((T7*)(Z2G),b1);}{T0*b1=(((T77*)(ZIJ2()))->Ztc);Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(2,ZEn);Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}R=ZkI2(C,ZWF);
return R;}T0*ZPJ2(ZQ9*C){T0*R=Zo;T81 ZjG={Zo,Zo,0};T0*ZQJ2=Zo;T0*ZRJ2=Zo;T0*ZSJ2=Zo;T6 ZTJ2=0;T6 ZUJ2=0;if(ZKJ2(C,ZsE2)){if(ZVJ2(C)){
((((T93*)((T93*)(((C)->Zzl)))))->ZXm)=((T6)(1));((((Zy7*)(&(((C)->ZLm)))))->ZIb)=(((C)->Zzl));}else{ZWJ2(C,Z1G(34,"Obsolete manifest string expected."));
}}((((Zy7*)(&(((C)->ZLm)))))->ZHb)=(ZXJ2(C));if(ZKJ2(C,ZJi1)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}ZTJ2=((T6)(ZKJ2(C,ZN91)));
ZQJ2=ZXJ2(C);ZyG2(&(((C)->ZLm)),ZjG,(T6)(ZTJ2),ZQJ2,ZZJ2(C));}if(ZKJ2(C,ZrE2)){Z_J2(C);}R=Z0K2(C);if(ZKJ2(C,ZKi1)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}(C->Zqm)=((T6)(1));ZUJ2=((T6)(ZKJ2(C,ZBE2)));ZQJ2=ZXJ2(C);ZRJ2=ZZJ2(C);if((T6)(((ZQJ2)!=((void*)(Zo)))||((T6)((ZRJ2)!=((void*)(Zo)))))){
{Z11*n=((Z11*)Zh(sizeof(*n)));*n=Zsc;ZBp2(n,ZjG,(T6)(ZUJ2),ZQJ2,ZRJ2);ZSJ2=((T0*)n);}}((((ZX4*)(((ZX4*)R))))->ZFe)=(ZSJ2);(C->Zqm)=((T6)(0));
}if(ZKJ2(C,ZxE2)){(C->Zrm)=((T6)(1));Z1K2(R,Z2K2(C,ZxE2,Z4v2));(C->Zrm)=((T6)(0));}else if(ZKJ2(C,Z4v2)){if(ZDu2((T89*)(ZPM))){{T81 Zow;
ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}((((ZX4*)(((ZX4*)R))))->ZEe)=(ZjG);}}else{{ZQ9*C1=C;T0*b1=Z1G(35,"A routine must be ended with \"end\".");
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}(C->ZKb)=Zo;return R;}void Z4K2(ZQ9*C,T6 a1,T0*a2){T0*Z3r1=Zo;T0*ZDt2=Zo;if(Z5K2(C)){if((T6)(((T6)((Z6K2(C))||((T6)(Z7K2(C)))))||((T6)(Z8K2(C))))){
{T81 Zow;ZmG2((*(Zow=ZLG(((C)->Zym)),&Zow)),Z1G(38,"This name must not appear after a dot."));}}Z3r1=ZKE2(&(((C)->ZEd)));ZDt2=Z9K2(C);
ZaK2(C,(T6)(a1),a2,Z3r1,ZDt2,(T6)(0));}else{ZWJ2(C,Z1G(32,"Identifier expected after a dot."));}}T0*ZbK2(void){if(Zcq1==0){Zcq1=1;{{ZD*n=((ZD*)Zh(sizeof(*n)));
*n=Z0c;Zbq1=((T0*)n);}}}return Zbq1;}T6 Z8K2(ZQ9*C){T6 R=0;if(ZOE2()){{Zl8*n=((Zl8*)Zh(sizeof(*n)));*n=ZPk;((((Zl8*)(n)))->ZCb)=(((((C)->ZEd)).ZCb));
(C->Zym)=((T0*)n);}R=((T6)(1));}return R;}void ZcK2(ZQ9*C,T6 a1){T0*ZdK2=Zo;T0*ZXd2=Zo;if(Z8K2(C)){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Zym)),&Zow)));
}{T0*b1=Z1G(26,"Must not affect `Current\'.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else if(Z7K2(C)){Z5G(((((C)->ZEd)).ZCb));{T0*b1=Z1G(23,"Must not affect `Void\'.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else if(ZeK2(C)){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Zym)),&Zow)));}{T0*b1=Z1G(34,"Must not affect a formal argument.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{if(Z7E2()){ZdK2=ZfK2(C);}else if(ZgK2(C)){ZdK2=((C)->Zym);}else{ZdK2=ZKE2(&(((C)->ZEd)));}
if(ZhK2(C)){ZXd2=((C)->Zym);if(a1){{Zi9*n=((Zi9*)Zh(sizeof(*n)));*n=Z_l;ZuL1(n,ZdK2,ZXd2);(C->ZEm)=((T0*)n);}}else{{Zy5*n=((Zy5*)Zh(sizeof(*n)));
*n=ZGh;Z2v1(n,ZdK2,ZXd2);(C->ZEm)=((T0*)n);}}}else{ZWJ2(C,Z1G(51,"Right hand side expression expected for assignment."));}}}T6 ZiK2(ZQ9*C,T0*a1){
T6 R=0;T0*Z0_=Zo;if(ZhK2(C)){R=((T6)(1));Z0_=ZjK2(C,((C)->Zym));if(!(ZKJ2(C,ZBE2))){{ZQ9*C1=C;T0*b1=Z1G(13,"Added \"then\".");{T81 Zow;
Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}Z6o1(((Z45*)a1),Z0_,ZkK2(C));}return R;}void Z7H2(T2 a1,T0*a2){if((Z3)((a1)>(ZGs(0)))){(((void)((T38*)(Z6H2()))),Zzi1(ZcB2));
(((void)((T38*)(Z6H2()))),ZYv1(a1));(((void)((T38*)(Z6H2()))),Zzi1(a2));}}T81 ZnG2(ZQ9*C){T81 R={Zo,Zo,0};{T81 Zow;R=(*(Zow=ZYJ2(C,((C)->ZWe),((C)->ZVe)),&Zow));
}return R;}void Z3K2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}T0*ZkK2(ZQ9*C){T0*R=Zo;T0*ZQJ2=Zo;T0*ZaN1=Zo;
ZQJ2=ZXJ2(C);(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));while(!(!(ZmK2(C)))){ZaN1=((C)->ZEm);if((((C)->_cc))==(((T3)'\050'))){{ZQ9*C1=C;T0*b1=ZnK2;
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));while(!((((C)->_cc))!=(((T3)'\073')))){{ZQ9*C1=C;T0*b1=ZoK2;
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){ZaN1=ZpK2(C,ZaN1);
if((R)==((void*)(Zo))){{ZX6*n=((ZX6*)Zh(sizeof(*n)));*n=Zzj;Z4N1(n,ZQJ2,ZaN1);R=((T0*)n);}}else{Z5N1(((ZX6*)R),ZaN1);}}}if((T6)(((ZQJ2)!=((void*)(Zo)))&&((T6)((R)==((void*)(Zo)))))){
{ZX6*n=((ZX6*)Zh(sizeof(*n)));*n=Zzj;((((ZX6*)(n)))->ZHb)=(ZQJ2);R=((T0*)n);}}return R;}T0*Z2K2(ZQ9*C,T0*a1,T0*a2){T0*R=Zo;T0*ZQJ2=Zo;
T0*ZaN1=Zo;ZQJ2=ZXJ2(C);(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));while(!(!(ZmK2(C)))){ZaN1=((C)->ZEm);if((((C)->_cc))==(((T3)'\050'))){{ZQ9*C1=C;
T0*b1=ZnK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));while(!((((C)->_cc))!=(((T3)'\073')))){{ZQ9*C1=C;
T0*b1=ZoK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){ZaN1=ZpK2(C,ZaN1);
if((R)==((void*)(Zo))){{ZX6*n=((ZX6*)Zh(sizeof(*n)));*n=Zzj;Z4N1(n,ZQJ2,ZaN1);R=((T0*)n);}}else{Z5N1(((ZX6*)R),ZaN1);}}}if(!(ZKJ2(C,a2))){
{T0*b1=Z1G(13,"In compound (");Zmx((T7*)(Z2G),b1);}{T0*b1=a1;Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(27,"). Instruction or keyword \"");Zmx((T7*)(Z2G),b1);
}{T0*b1=a2;Zmx((T7*)(Z2G),b1);}ZWJ2(C,Z1G(11,ZWq));}if((T6)(((ZQJ2)!=((void*)(Zo)))&&((T6)((R)==((void*)(Zo)))))){{ZX6*n=((ZX6*)Zh(sizeof(*n)));
*n=Zzj;((((ZX6*)(n)))->ZHb)=(ZQJ2);R=((T0*)n);}}return R;}void ZqK2(ZQ9*C){T0*ZIX=Zo;T0*ZrK2=Zo;T0*ZsK2=Zo;T0*ZqV=Zo;T2 Zdx=0;(C->ZFb)=Zo;
if(ZlK2(C,((T3)'\050'))){while(!((Z3)((Zdx)>(ZGs(4))))){{int z1=Zdx;switch(z1){case 0:if(Z5K2(C)){ZIX=Z3E2(&(((C)->ZEd)));Zdx=ZGs(1);
}else if(ZlK2(C,((T3)'\051'))){Zdx=ZGs(5);}else{Zdx=ZGs(6);}break;case 1:if(ZlK2(C,((T3)'\072'))){if((ZrK2)!=((void*)(Zo))){Zmy(((Zl2*)ZrK2),ZIX);
ZIX=Zo;}Zdx=ZGs(3);}else{(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));if((ZrK2)==((void*)(Zo))){{Zl2*n=((Zl2*)Zh(sizeof(*n)));*n=ZLd;Zoy(n,(T2)(ZGs(2)),(T2)(ZGs(1)));
ZrK2=((T0*)n);}}Zmy(((Zl2*)ZrK2),ZIX);ZIX=Zo;Zdx=ZGs(2);}break;case 2:if(Z5K2(C)){ZIX=Z3E2(&(((C)->ZEd)));Zdx=ZGs(1);}else if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\073')))))){
{ZQ9*C1=C;T0*b1=ZtK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)((T6)((ZlK2(C,((T3)'\054')))||((T6)(ZlK2(C,((T3)'\073')))))));
}else{Zdx=ZGs(6);}break;case 3:if(ZuK2(C)){if((ZrK2)!=((void*)(Zo))){{ZI3*n=((ZI3*)Zh(sizeof(*n)));*n=ZLe;Z4d1(n,ZrK2,((C)->ZJm));ZsK2=((T0*)n);
}ZrK2=Zo;}else{{Z_*n=((Z_*)Zh(sizeof(*n)));*n=Zqc;ZiO(n,ZIX,((C)->ZJm));ZsK2=((T0*)n);}ZIX=Zo;}if((ZqV)==((void*)(Zo))){{Z9a*n=((Z9a*)Zh(sizeof(*n)));
*n=Z7n;Zbz(n,(T2)(ZGs(2)),(T2)(ZGs(1)));ZqV=((T0*)n);}}ZvK2(ZqV,ZsK2);ZsK2=Zo;Zdx=ZGs(4);}else{Zdx=ZGs(6);}break;default:;if(ZlK2(C,((T3)'\051'))){
Zdx=ZGs(5);}else if((((C)->_cc))==(((T3)'\054'))){{ZQ9*C1=C;T0*b1=ZwK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));
Zdx=ZGs(0);}else{(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));Zdx=ZGs(0);}}}}if((Zdx)==(ZGs(6))){ZWJ2(C,Z1G(26,"Bad formal arguments list."));
}else if((ZqV)==((void*)(Zo))){{ZQ9*C1=C;T0*b1=ZxK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}else{{Zz6*n=((Zz6*)Zh(sizeof(*n)));*n=Zbj;
Zra1(n,ZqV);(C->ZFb)=((T0*)n);}((((Zy7*)(&(((C)->ZLm)))))->ZFb)=(((C)->ZFb));}}}T6 ZyK2(ZQ9*C){T6 R=0;T2 Z7Q=0;T2 ZXw=0;Z7Q=((C)->ZWe);
ZXw=((C)->ZVe);if(ZlK2(C,((T3)'\053'))){if(ZzK2(C,ZGs(0))){R=((T6)(1));}else{ZAK2(C,Z7Q,ZXw);}}else if(ZlK2(C,((T3)'\055'))){if(ZzK2(C,ZGs(-1))){
R=((T6)(1));}else{ZAK2(C,Z7Q,ZXw);}}else{R=((T6)(ZzK2(C,ZGs(0))));}return R;}T6 ZBK2(ZQ9*C){T6 R=0;T2 Z7Q=0;T2 ZXw=0;Z7Q=((C)->ZWe);ZXw=((C)->ZVe);
if(Z5K2(C)){if(ZlK2(C,((T3)'\072'))){R=((T6)(1));(C->ZKm)=ZLE2(&(((C)->ZEd)));}else{ZAK2(C,Z7Q,ZXw);}}return R;}T6 ZmK2(ZQ9*C){T6 R=0;
R=((T6)(1));if(ZCK2(C)){}else if(ZDK2(C)){}else if(ZEK2(C)){}else if(ZFK2(C)){}else if(ZGK2(C)){}else if(ZHK2(C)){}else if(ZIK2(C)){}
else if(ZJK2(C)){}else if(ZKK2(C)){}else{R=((T6)(0));}return R;}void ZWJ2(ZQ9*C,T0*a1){{T81 Zow;Z5G((*(Zow=ZnG2(C),&Zow)));}{T0*b1=a1;
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZAK2(ZQ9*C,T2 a1,T2 a2){T81 ZjG={Zo,Zo,0};(C->ZWe)=a1;(C->ZVe)=a2;(C->ZXe)=(((((T55*)((((T77*)(ZIJ2()))->Zal))))->ZUb))[a1];
(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[(a2)-(ZGs(1))];if((((C)->ZYe))!=((void*)(Zo))){ZjG=(((T91*)(((C)->ZYe)))->ZCb);if((Z3)((a1)<(Zrd1(&ZjG)))){
(C->ZYe)=Zo;}else if((a1)==(Zrd1(&ZjG))){if((Z3)((a2)<(Zsd1(&ZjG)))){(C->ZYe)=Zo;}}}}void ZLK2(ZQ9*C){T0*Z3r1=Zo;T0*ZMK2=Zo;Z3r1=ZKE2(&(((C)->ZEd)));
{ZH8*n=((ZH8*)Zh(sizeof(*n)));*n=Zel;((((ZH8*)(n)))->ZCb)=(((((ZD8*)Z3r1))->ZCb));ZMK2=((T0*)n);}ZaK2(C,(T6)(0),ZMK2,Z3r1,Z9K2(C),(T6)(1));
}T0*Z0K2(ZQ9*C){T0*R=Zo;if(ZKJ2(C,ZfE2)){Zdn1((T87*)(((C)->Zom)));R=ZdG2(&(((C)->ZLm)));}else if(ZKJ2(C,Z0v2)){R=ZNK2(C);}else if(ZKJ2(C,ZgE2)){
((((Zy7*)(&(((C)->ZLm)))))->ZLb)=(ZkK2(C));R=ZuG2(&(((C)->ZLm)));}else if(ZKJ2(C,ZuE2)){((((Zy7*)(&(((C)->ZLm)))))->ZLb)=(ZkK2(C));R=ZwG2(&(((C)->ZLm)));
}else{ZWJ2(C,Z1G(22,"Routine body expected."));}return R;}T0*ZjK2(ZQ9*C,T0*a1){T0*R=Zo;T0*ZXw=Zo;ZXw=ZXJ2(C);if((T6)(((ZXw)==((void*)(Zo)))||((T6)((ZZy(((T79*)(((((T91*)ZXw))->ZZb)))))==(ZGs(0)))))){
R=a1;}else{{Zx4*n=((Zx4*)Zh(sizeof(*n)));*n=Zzg;ZXg1(n,a1,ZXw);R=((T0*)n);}}return R;}T6 Z6K2(ZQ9*C){T6 R=0;if(Z7E2()){(C->Zym)=ZfK2(C);
R=((T6)(1));}return R;}T0*ZZJ2(ZQ9*C){T0*R=Zo;T0*ZEQ1=Zo;T0*Z0_=Zo;T0*ZwE1=Zo;T2 Zdx=0;((((Zu1*)((Zu1*)(ZOK2()))))->ZWb)=(ZGs(-1));while(!((Z3)((Zdx)>(ZGs(3)))))
{{int z1=Zdx;switch(z1){case 0:if((((C)->_cc))==(((T3)'\073'))){{ZQ9*C1=C;T0*b1=ZoK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));
}else if((((C)->ZYe))!=((void*)(Zo))){{Zn6*n=((Zn6*)Zh(sizeof(*n)));*n=Z0j;Z1H1(n,Zo,Zo,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);
}else if(ZBK2(C)){ZEQ1=((C)->ZKm);Zdx=ZGs(1);}else if(ZhK2(C)){Z0_=((C)->Zym);Zdx=ZGs(2);}else{Zdx=ZGs(4);}break;case 1:if(ZlK2(C,((T3)'\073'))){
{Zn6*n=((Zn6*)Zh(sizeof(*n)));*n=Z0j;Z1H1(n,ZEQ1,Zo,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Zdx=ZGs(0);}else if(ZBK2(C)){{Zn6*n=((Zn6*)Zh(sizeof(*n)));
*n=Z0j;Z1H1(n,ZEQ1,Zo,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);ZEQ1=((C)->ZKm);}else if(ZhK2(C)){Z0_=((C)->Zym);Zdx=ZGs(3);}else{
{Zn6*n=((Zn6*)Zh(sizeof(*n)));*n=Z0j;Z1H1(n,ZEQ1,Zo,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Zdx=ZGs(4);}break;case 2:if(ZlK2(C,((T3)'\073'))){
{Zn6*n=((Zn6*)Zh(sizeof(*n)));*n=Z0j;Z1H1(n,Zo,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Zdx=ZGs(0);}else if(ZBK2(C)){{Zn6*n=((Zn6*)Zh(sizeof(*n)));
*n=Z0j;Z1H1(n,Zo,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);ZEQ1=((C)->ZKm);Zdx=ZGs(1);}else if(ZhK2(C)){{Zn6*n=((Zn6*)Zh(sizeof(*n)));
*n=Z0j;Z1H1(n,Zo,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Z0_=((C)->Zym);Zdx=ZGs(2);}else{{Zn6*n=((Zn6*)Zh(sizeof(*n)));*n=Z0j;
Z1H1(n,Zo,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Zdx=ZGs(4);}break;default:;if(ZlK2(C,((T3)'\073'))){{Zn6*n=((Zn6*)Zh(sizeof(*n)));
*n=Z0j;Z1H1(n,ZEQ1,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Zdx=ZGs(0);}else if(ZBK2(C)){{Zn6*n=((Zn6*)Zh(sizeof(*n)));*n=Z0j;
Z1H1(n,ZEQ1,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);ZEQ1=((C)->ZKm);Zdx=ZGs(1);}else if(ZhK2(C)){{Zn6*n=((Zn6*)Zh(sizeof(*n)));
*n=Z0j;Z1H1(n,ZEQ1,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Z0_=((C)->Zym);Zdx=ZGs(2);}else{{Zn6*n=((Zn6*)Zh(sizeof(*n)));
*n=Z0j;Z1H1(n,ZEQ1,Z0_,ZXJ2(C));ZwE1=((T0*)n);}Z1A((Zu1*)(ZOK2()),ZwE1);Zdx=ZGs(4);}}}}if(!((Z3)(((((Zu1*)(ZOK2()))->ZWb))<(ZGs(0))))){
R=Z2A((Zu1*)(ZOK2()));}return R;}T0*ZNJ2(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);
ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);
ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);
ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);
ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);
ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);
ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);
ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);
ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);
ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);
ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);
ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);
ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);
ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);
ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T0*ZPK2=Zo;void ZQK2(ZQ9*C){T0*ZRK2=Zo;T0*ZSK2=Zo;T0*ZK_1=Zo;ZSK2=ZTK2(C);
ZK_1=ZXJ2(C);((((ZY9*)((ZY9*)(ZUK2()))))->ZWb)=(ZGs(-1));while(!(!(ZVK2(C)))){(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));if((((C)->Zzm))!=((void*)(Zo))){
ZEF((ZY9*)(ZUK2()),((C)->Zzm));Z3O(((C)->Zzm),ZXJ2(C));}}if(!((Z3)(((((ZY9*)(ZUK2()))->ZWb))<(ZGs(0))))){{ZT4*n=((ZT4*)Zh(sizeof(*n)));
*n=ZOh;Zkx1(n,ZSK2,ZK_1,ZFF((ZY9*)(ZUK2())));ZRK2=((T0*)n);}ZPm1((T87*)(((C)->Zom)),ZRK2);}else if((ZK_1)!=((void*)(Zo))){{ZT4*n=((ZT4*)Zh(sizeof(*n)));
*n=ZOh;Zkx1(n,ZSK2,ZK_1,Zo);ZRK2=((T0*)n);}ZPm1((T87*)(((C)->Zom)),ZRK2);}}T6 ZWK2(ZQ9*C){T6 R=0;T0*ZXK2=Zo;if(Z5K2(C)){R=((T6)(1));if(ZlK2(C,((T3)'\072'))){
{ZM5*n=((ZM5*)Zh(sizeof(*n)));*n=ZIj;((((ZM5*)(n)))->Zkd)=(Z4E2(&(((C)->ZEd))));ZXK2=((T0*)n);}if(ZYK2(C)){Z5P1(((ZM5*)ZXK2),((C)->ZFm));
}else{ZWJ2(C,ZZK2);}}else{{ZM5*n=((ZM5*)Zh(sizeof(*n)));*n=ZIj;{ZM5*C1=n;T0*b1=ZKE2(&(((C)->ZEd)));Z5P1(C1,b1);}ZXK2=((T0*)n);}}}else
if(Z_K2(C)){R=((T6)(1));{ZM5*n=((ZM5*)Zh(sizeof(*n)));*n=ZIj;{ZM5*C1=n;T0*b1=((C)->ZGm);Z5P1(C1,b1);}ZXK2=((T0*)n);}}if(R){while(!(!(ZlK2(C,((T3)'\054')))))
{if(ZYK2(C)){Z5P1(((ZM5*)ZXK2),((C)->ZFm));}else{ZWJ2(C,ZZK2);}}ZHm1((T87*)(((C)->Zom)),ZXK2);}return R;}void Z0L2(ZQ9*C){while(!(!(Z1L2(C))))
{(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}}void Z2L2(ZQ9*C,T81 a1){T0*ZSK2=Zo;T0*Z3L2=Zo;T0*Z4L2=Zo;ZSK2=ZTK2(C);Z3L2=ZXJ2(C);if(Z5L2(C)){
}{Z_1*n=((Z_1*)Zh(sizeof(*n)));*n=Zsd;ZnY(n,a1,ZSK2,Z3L2,((C)->ZBm));Z4L2=((T0*)n);}Zcn1((T87*)(((C)->Zom)),Z4L2);}T6 ZVJ2(ZQ9*C){T6 R=0;
T2 Zdx=0;T2 Z7Q=0;T2 ZXw=0;T6 Z7J2=0;T6 Z8J2=0;T6 Zd22=0;T2 Z9J2=0;T2 ZaJ2=0;T2 ZbJ2=0;T0*Z6L2=Zo;T0*ZcJ2=Zo;T0*ZdJ2=Zo;T2 ZeJ2=0;T2 ZfJ2=0;
Z7Q=((C)->ZWe);ZXw=((C)->ZVe);if(ZKJ2(C,ZuE2)){Z7J2=((T6)(1));}if((((C)->_cc))==(((T3)'U'))){Z8J2=((T6)(1));ZMJ2(C);}if((((C)->_cc))==(((T3)'\042'))){
R=((T6)(1));if((T6)(((((T43*)(ZSG))->ZRk))||((T6)((((T43*)(ZSG))->ZSk))))){{T55*n=((T55*)Zh(sizeof(*n)));*n=M55;ZSz(n,(T2)(ZGs(4)));Z6L2=((T0*)n);
}{T7*n=((T7*)Zh(sizeof(*n)));*n=M7;Zwx(n,(T2)(ZGs(32)));ZcJ2=((T0*)n);}ZQz(((T55*)Z6L2),ZcJ2);}((((T7*)((T7*)(ZPK2))))->Zdc)=(ZGs(0));
while(!((Z3)((Zdx)>(ZGs(9))))){if((Z6L2)!=((void*)(Zo))){Zgt(((T7*)ZcJ2),((C)->_cc));if((((C)->_cc))==(((T3)'\n'))){{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Zwx(n,(T2)(ZGs(32)));ZcJ2=((T0*)n);}ZQz(((T55*)Z6L2),ZcJ2);}}ZMJ2(C);{int z1=Zdx;switch(z1){case 0:{int z2=((C)->_cc);switch(z2){
case 10:while(!((ZdJ2)!=((void*)(Zo)))){if(((((T7*)(ZPK2))->Zdc))==(ZGs(0))){ZWJ2(C,ZgJ2);}else{{int z3=Z0x((T7*)(ZPK2));switch(z3){case
9:case 32:ZFx((T7*)(ZPK2),(T2)(ZGs(1)));{ZQ9*C1=C;T0*b1=ZhJ2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}break;case 91:case 123:ZdJ2=Z7L2;
((((T7*)(((T7*)ZdJ2))))->Zdc)=(ZGs(0));if((Z0x((T7*)(ZPK2)))==(((T3)'\173'))){Zgt(((T7*)ZdJ2),((T3)'\175'));ZeJ2=ZGs(1);Zdx=ZGs(8);}else{
Zgt(((T7*)ZdJ2),((T3)'\135'));Zdx=ZGs(7);}Zmx(((T7*)ZdJ2),ZPK2);ZfJ2=ZGs(1);ZFx(((T7*)ZdJ2),(T2)(ZGs(1)));Zgt(((T7*)ZdJ2),((T3)'\042'));
((((T7*)((T7*)(ZPK2))))->Zdc)=(ZGs(0));break;default:;ZWJ2(C,ZgJ2);}}}}break;case 34:Zdx=ZGs(11);break;case 37:Zdx=ZGs(1);break;default:;
Zgt((T7*)(ZPK2),((C)->_cc));}}break;case 1:Zdx=ZGs(0);{int z2=((C)->_cc);switch(z2){case 10:Zdx=ZGs(3);break;case 65:Zgt((T7*)(ZPK2),((T3)'\100'));
break;case 66:Zgt((T7*)(ZPK2),((T3)'\010'));break;case 67:Zgt((T7*)(ZPK2),((T3)'\136'));break;case 68:Zgt((T7*)(ZPK2),((T3)'\044'));break;
case 70:Zgt((T7*)(ZPK2),((T3)'\014'));break;case 72:Zgt((T7*)(ZPK2),((T3)'\134'));break;case 76:Zgt((T7*)(ZPK2),((T3)'\176'));break;case
78:Zgt((T7*)(ZPK2),((T3)'\n'));break;case 81:Zgt((T7*)(ZPK2),((T3)'\140'));break;case 82:Zgt((T7*)(ZPK2),((T3)'\015'));break;case 83:
Zgt((T7*)(ZPK2),((T3)'\043'));break;case 84:Zgt((T7*)(ZPK2),((T3)'\011'));break;case 85:Zgt((T7*)(ZPK2),((T3)'\000'));break;case 86:Zgt((T7*)(ZPK2),((T3)'\174'));
break;case 37:Zgt((T7*)(ZPK2),((T3)'\045'));break;case 39:Zgt((T7*)(ZPK2),((T3)'\047'));break;case 34:Zgt((T7*)(ZPK2),((T3)'\042'));break;
case 40:Zgt((T7*)(ZPK2),((T3)'\133'));break;case 41:Zgt((T7*)(ZPK2),((T3)'\135'));break;case 60:Zgt((T7*)(ZPK2),((T3)'\173'));break;case
62:Zgt((T7*)(ZPK2),((T3)'\175'));break;case 47:Z9J2=ZGs(0);ZbJ2=ZGs(0);Zdx=ZGs(4);break;case 9:case 32:Zdx=ZGs(2);break;default:;ZWJ2(C,ZjJ2);
Zdx=ZGs(0);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 10:Zdx=ZGs(3);break;case 9:case 32:{ZQ9*C1=C;T0*b1=ZhJ2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}break;default:;ZWJ2(C,Z1G(60,Z8p));}}break;case 3:{int z2=((C)->_cc);switch(z2){case 9:case 32:break;case 37:Zdx=ZGs(0);break;case 10:
ZWJ2(C,ZgJ2);break;default:;ZWJ2(C,Z1G(62,Zbq));}}break;case 4:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:
case 53:case 54:case 55:case 56:case 57:ZbJ2=(Z3)(((ZbJ2))+(ZGs(1)));if((Z3)((Z9J2)<((T2)((Z2)(((Z2)((((Z2)(((ZmJ2))+(ZGs(10)))))+((T10)(ZJs(((C)->_cc))))))/(ZGs(10))))))){
Z9J2=(Z3)((((Z3)(((Z9J2))*(ZGs(10)))))+((T2)(ZJs(((C)->_cc)))));}else{Z9J2=(T2)((Z2)(((ZmJ2))+(ZGs(1))));}break;case 120:if(Zus((T6)((ZbJ2)==(ZGs(1))),(T6)((Z9J2)==(ZGs(0))))){
ZbJ2=ZGs(0);Zdx=ZGs(5);}else{ZWJ2(C,ZkJ2);}break;case 85:if((ZbJ2)==(ZGs(0))){ZMJ2(C);if((((C)->_cc))==(((T3)'x'))){Zdx=ZGs(6);ZaJ2=ZGs(0);
ZbJ2=ZGs(0);}else{ZWJ2(C,ZkJ2);}}else{ZWJ2(C,ZkJ2);}break;case 47:Zdx=ZGs(0);if((ZbJ2)==(ZGs(0))){{ZQ9*C1=C;T0*b1=ZlJ2;{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}else if((Z3)((Z9J2)>((T2)(ZmJ2)))){Z9J2=ZGs(0);{ZQ9*C1=C;T0*b1=ZnJ2;{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);}}}else{Zgt((T7*)(ZPK2),((T3)(Z9J2)));
}break;default:;ZWJ2(C,ZkJ2);}}break;case 5:if(ZBs(((C)->_cc))){Z9J2=(Z3)((((Z3)(((Z9J2))*(ZGs(16)))))+((T2)(ZQs(((C)->_cc)))));ZbJ2=(Z3)(((ZbJ2))+(ZGs(1)));
if(Z2t(ZbJ2)){Zgt((T7*)(ZPK2),((T3)(Z9J2)));Z9J2=ZGs(0);}}else if((((C)->_cc))==(((T3)'\057'))){Zdx=ZGs(0);if((ZbJ2)==(ZGs(0))){{ZQ9*C1=C;
T0*b1=ZoJ2;{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);}}}else if(Z9t(ZbJ2)){{ZQ9*C1=C;T0*b1=Z1G(85,ZVo);{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}}else{ZWJ2(C,ZoJ2);}break;case 6:if(ZBs(((C)->_cc))){ZaJ2=(Z3)((((Z3)(((ZaJ2))*(ZGs(16)))))+((T2)(ZQs(((C)->_cc)))));ZbJ2=(Z3)(((ZbJ2))+(ZGs(1)));
}else if((((C)->_cc))==(((T3)'\057'))){Zdx=ZGs(0);if((ZbJ2)==(ZGs(0))){{ZQ9*C1=C;T0*b1=ZpJ2;{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}else if((Z3)((ZbJ2)>(ZGs(8)))){{ZQ9*C1=C;T0*b1=Z1G(57,Zio);{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);}}}else{ZDa2((T95*)(Z8L2()));if((((void)((T95*)(Z8L2()))),Zza2(ZaJ2))){
ZCa2((T95*)(Z8L2()),ZaJ2);ZBa2((T95*)(Z8L2()),ZPK2);}else{{ZQ9*C1=C;T0*b1=Z1G(109,ZXo);{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);}}}}}
else{ZWJ2(C,ZpJ2);}break;case 7:{int z2=((C)->_cc);switch(z2){case 9:case 32:ZfJ2=(Z3)(((ZfJ2))+(ZGs(1)));break;case 10:Zgt((T7*)(ZPK2),((T3)'\n'));
ZfJ2=ZGs(1);break;case 0:{T81 Zow;Z5G((*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)));}ZWJ2(C,ZqJ2);break;default:;Zgt((T7*)(ZPK2),((C)->_cc));ZeJ2=ZfJ2;
Zdx=ZGs(8);}}break;case 8:ZfJ2=(Z3)(((ZfJ2))+(ZGs(1)));{int z2=((C)->_cc);switch(z2){case 9:case 32:if((Z3)((ZfJ2)>=(ZeJ2))){Zgt((T7*)(ZPK2),((C)->_cc));
}break;case 10:Zgt((T7*)(ZPK2),((C)->_cc));ZfJ2=ZGs(0);break;case 0:{T81 Zow;Z5G((*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)));}ZWJ2(C,ZqJ2);break;case
34:Zgt((T7*)(ZPK2),((C)->_cc));if(Ztx((T7*)(ZPK2),ZdJ2)){Zdx=ZGs(10);}break;default:;if((Z3)((ZfJ2)<(ZeJ2))){if((((C)->_cc))==((((((T7*)ZdJ2))->ZUb))[ZGs(0)])){
Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(9);}else{{T81 Zow;Z5G((*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)));}ZWJ2(C,ZqJ2);}}else{Zgt((T7*)(ZPK2),((C)->_cc));
}}}break;default:;{int z2=((C)->_cc);switch(z2){case 0:{T81 Zow;Z5G((*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)));}ZWJ2(C,ZqJ2);break;case 34:Zgt((T7*)(ZPK2),((C)->_cc));
if(Ztx((T7*)(ZPK2),ZdJ2)){Zdx=ZGs(10);}break;default:;Zgt((T7*)(ZPK2),((C)->_cc));}}}}}if((Zdx)==(ZGs(10))){{T7*C1=(T7*)(ZPK2);T0*b1=ZdJ2;
ZFx(C1,((((T7*)b1))->Zdc));}while(!(Zd22)){if(((((T7*)(ZPK2))->Zdc))==(ZGs(0))){Zd22=((T6)(1));}else{Zd22=((T6)((Z0x((T7*)(ZPK2)))==(((T3)'\n'))));
ZFx((T7*)(ZPK2),(T2)(ZGs(1)));}}}if((Z6L2)!=((void*)(Zo))){Zgt(((T7*)ZcJ2),((T3)'\042'));}{T81 Zow;{T93*n=((T93*)Zh(sizeof(*n)));*n=M93;
Zho2(n,(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)),(T6)(Z7J2),(T6)(Z8J2),ZPK2);(C->Zzl)=((T0*)n);}}((((T93*)((T93*)(((C)->Zzl)))))->Z3n)=(Z6L2);ZMJ2(C);
ZJJ2(C);}else if((T6)((Z7J2)||((T6)(Z8J2)))){ZAK2(C,Z7Q,ZXw);}return R;}T6 ZFK2(ZQ9*C){T6 R=0;if(ZKJ2(C,ZyE2)){if(!(((C)->Zrm))){{T81
Zow;ZmG2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z1G(45,"\"retry\" cannot be outside of a rescue clause."));}}{T81 Zow;{ZW1*n=((ZW1*)Zh(sizeof(*n)));
*n=Zod;((((ZW1*)(n)))->ZCb)=((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->ZEm)=((T0*)n);}}R=((T6)(1));}return R;}T6 Z9L2(ZQ9*C,T81
a1){T6 R=0;R=((T6)(1));if(ZaL2(C,((T3)'\074'),((T3)'\075'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZyG,a1);(C->ZAm)=((T0*)n);}}else
if(ZaL2(C,((T3)'\076'),((T3)'\075'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZAG,a1);(C->ZAm)=((T0*)n);}}else if(ZaL2(C,((T3)'\057'),((T3)'\057'))){
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,Z2J,a1);(C->ZAm)=((T0*)n);}}else if(ZaL2(C,((T3)'\134'),((T3)'\134'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));
*n=Zfn;ZuH(n,ZEI,a1);(C->ZAm)=((T0*)n);}}else if(ZlK2(C,((T3)'\053'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZtG,a1);(C->ZAm)=((T0*)n);
}}else if(ZlK2(C,((T3)'\055'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZuG,a1);(C->ZAm)=((T0*)n);}}else if(ZlK2(C,((T3)'\052'))){
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZvG,a1);(C->ZAm)=((T0*)n);}}else if(ZlK2(C,((T3)'\057'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;
ZuH(n,Z1J,a1);(C->ZAm)=((T0*)n);}}else if(ZlK2(C,((T3)'\076'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZzG,a1);(C->ZAm)=((T0*)n);
}}else if(ZlK2(C,((T3)'\074'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZxG,a1);(C->ZAm)=((T0*)n);}}else if(ZlK2(C,((T3)'\136'))){
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZZI,a1);(C->ZAm)=((T0*)n);}}else if(ZKJ2(C,ZvH)){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZvH,a1);
(C->ZAm)=((T0*)n);}}else if(ZKJ2(C,ZRI)){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZRI,a1);(C->ZAm)=((T0*)n);}}else if(ZKJ2(C,ZBI)){
if(ZKJ2(C,ZBE2)){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZCI,a1);(C->ZAm)=((T0*)n);}}else{{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZBI,a1);
(C->ZAm)=((T0*)n);}}}else if(ZKJ2(C,ZWI)){if(ZKJ2(C,ZN91)){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZXI,a1);(C->ZAm)=((T0*)n);}}else{
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZWI,a1);(C->ZAm)=((T0*)n);}}}else if(ZaL2(C,((T3)'\043'),((T3)'\053'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));
*n=Zfn;ZuH(n,ZYI,a1);(C->ZAm)=((T0*)n);}}else if(ZaL2(C,((T3)'\043'),((T3)'\055'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZSI,a1);
(C->ZAm)=((T0*)n);}}else if(ZaL2(C,((T3)'\043'),((T3)'\052'))){{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZTI,a1);(C->ZAm)=((T0*)n);}
}else{(C->ZAm)=Zo;R=((T6)(0));}return R;}void ZbL2(ZQ9*C){T0*ZcL2=Zo;T81 ZjG={Zo,Zo,0};T0*ZSK2=Zo;T0*ZdL2=Zo;T0*ZeL2=Zo;T2 Zdx=0;if(ZKJ2(C,ZiE2)){
{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}while(!((Z3)((Zdx)>(ZGs(3))))){{int z1=Zdx;switch(z1){case 0:if((((C)->_cc))==(((T3)'\173'))){
ZSK2=ZTK2(C);Zdx=ZGs(1);}else if((((C)->_cc))==(((T3)'\073'))){{ZQ9*C1=C;T0*b1=ZoK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));
}else{if((ZdL2)!=((void*)(Zo))){{Zk5*n=((Zk5*)Zh(sizeof(*n)));*n=Zmh;Z6p1(n,ZjG,ZdL2);ZcL2=((T0*)n);}((((Zr2*)((Zr2*)(((C)->ZHm)))))->ZAi)=(ZcL2);
}Zdx=ZGs(4);}break;case 1:if(ZKJ2(C,ZNi1)){{Zh2*n=((Zh2*)Zh(sizeof(*n)));*n=Z_h;Z_D1(n,ZSK2);ZeL2=((T0*)n);}if((ZdL2)==((void*)(Zo))){
{Z85*n=((Z85*)Zh(sizeof(*n)));*n=Zdh;Zyy(n,(T2)(ZGs(2)),(T2)(ZGs(1)));ZdL2=((T0*)n);}}Zxy(((Z85*)ZdL2),ZeL2);Zdx=ZGs(2);}else{if(Z5L2(C)){
{Zh2*n=((Zh2*)Zh(sizeof(*n)));*n=Z_h;Z0E1(n,ZSK2,((C)->ZBm));ZeL2=((T0*)n);}if((ZdL2)==((void*)(Zo))){{Z85*n=((Z85*)Zh(sizeof(*n)));*n=Zdh;
Zyy(n,(T2)(ZGs(2)),(T2)(ZGs(1)));ZdL2=((T0*)n);}}Zxy(((Z85*)ZdL2),ZeL2);Zdx=ZGs(2);}else{Zdx=ZGs(3);}}break;case 2:if(ZlK2(C,((T3)'\073'))){
Zdx=ZGs(0);}else if((((C)->_cc))==(((T3)'\173'))){{ZQ9*C1=C;T0*b1=ZnK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}Zdx=ZGs(0);}else{if((ZdL2)!=((void*)(Zo))){
{Zk5*n=((Zk5*)Zh(sizeof(*n)));*n=Zmh;Z6p1(n,ZjG,ZdL2);ZcL2=((T0*)n);}((((Zr2*)((Zr2*)(((C)->ZHm)))))->ZAi)=(ZcL2);}Zdx=ZGs(4);}break;
default:;ZWJ2(C,ZfL2);Zdx=ZGs(4);}}}}}T6 Z5K2(ZQ9*C){T6 R=0;if(((C)->Zkm)){R=((T6)(ZgL2(C)));}else{R=((T6)(ZhL2(C)));}return R;}T6 ZiL2(ZQ9*C){
T6 R=0;T81 ZjG={Zo,Zo,0};T3 ZUs=0;T2 Zdx=0;T2 ZjL2=0;T2 Z9J2=0;T2 ZbJ2=0;if((((C)->_cc))==(((T3)'\047'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->ZWe),((C)->ZVe)),&Zow));
}R=((T6)(1));while(!((Z3)((Zdx)>(ZGs(4))))){ZMJ2(C);{int z1=Zdx;switch(z1){case 0:{int z2=((C)->_cc);switch(z2){case 37:Zdx=ZGs(1);break;
case 39:ZWJ2(C,ZkL2);Zdx=ZGs(2);break;default:;ZUs=((C)->_cc);ZjL2=ZGs(0);Zdx=ZGs(2);}}break;case 1:ZjL2=ZGs(1);Zdx=ZGs(2);{int z2=((C)->_cc);
switch(z2){case 65:ZUs=((T3)'\100');break;case 66:ZUs=((T3)'\010');break;case 67:ZUs=((T3)'\136');break;case 68:ZUs=((T3)'\044');break;
case 70:ZUs=((T3)'\014');break;case 72:ZUs=((T3)'\134');break;case 76:ZUs=((T3)'\176');break;case 78:ZUs=((T3)'\n');break;case 81:ZUs=((T3)'\140');
break;case 82:ZUs=((T3)'\015');break;case 83:ZUs=((T3)'\043');break;case 84:ZUs=((T3)'\011');break;case 85:ZUs=((T3)'\000');break;case
86:ZUs=((T3)'\174');break;case 37:ZUs=((T3)'\045');break;case 39:ZUs=((T3)'\047');break;case 34:ZUs=((T3)'\042');break;case 40:ZUs=((T3)'\133');
break;case 41:ZUs=((T3)'\135');break;case 60:ZUs=((T3)'\173');break;case 62:ZUs=((T3)'\175');break;case 47:Zdx=ZGs(3);ZjL2=ZGs(2);break;
default:;ZWJ2(C,ZjJ2);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 39:Zdx=ZGs(5);break;default:;ZWJ2(C,ZkL2);}}ZMJ2(C);ZJJ2(C);break;
case 3:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZbJ2=(Z3)(((ZbJ2))+(ZGs(1)));
Z9J2=(Z3)((((Z3)(((Z9J2))*(ZGs(10)))))+((T2)(ZJs(((C)->_cc)))));break;case 47:Zdx=ZGs(2);if((ZbJ2)==(ZGs(0))){{ZQ9*C1=C;T0*b1=ZlJ2;{T81
Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);}}}else if((Z3)((Z9J2)>((T2)(ZmJ2)))){Z9J2=ZGs(0);{ZQ9*C1=C;T0*b1=ZnJ2;{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}ZUs=((T3)(Z9J2));break;case 120:if((T6)(((ZbJ2)==(ZGs(1)))&&((T6)((Z9J2)==(ZGs(0)))))){ZbJ2=ZGs(0);Zdx=ZGs(4);}else{ZWJ2(C,ZkJ2);}
break;default:;ZWJ2(C,ZkJ2);}}break;default:;if(ZBs(((C)->_cc))){Z9J2=(Z3)((((Z3)(((Z9J2))*(ZGs(16)))))+((T2)(ZQs(((C)->_cc)))));ZbJ2=(Z3)(((ZbJ2))+(ZGs(1)));
}else if((((C)->_cc))==(((T3)'\057'))){Zdx=ZGs(2);if((ZbJ2)!=(ZGs(2))){{ZQ9*C1=C;T0*b1=Z1G(65,"You must use exactely 2 hexadecimal digits to denote a CHARACTER.");
{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);}}}ZUs=((T3)(Z9J2));}else{ZWJ2(C,ZkJ2);}}}}{ZH4*n=((ZH4*)Zh(sizeof(*n)));*n=ZRg;Z_i1(n,ZjG,ZUs,ZjL2);
(C->Zvm)=((T0*)n);}}return R;}T0*ZlL2(ZQ9*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;if((a2)==((void*)(Zo))){ZWJ2(C,Z1G(61,"An expression has a result value. This is not an instruction."));
}else if((a3)==((void*)(Zo))){{ZP6*n=((ZP6*)Zh(sizeof(*n)));*n=Zmj;ZKs1(n,a1,a2);R=((T0*)n);}}else if((Z5H1(((Za3*)a3)))==(ZGs(1))){{ZN6*n=((ZN6*)Zh(sizeof(*n)));
*n=Zlj;ZjL1(n,a1,a2,a3);R=((T0*)n);}}else{{ZL6*n=((ZL6*)Zh(sizeof(*n)));*n=Zkj;ZXK1(n,a1,a2,a3);R=((T0*)n);}}return R;}void ZmL2(ZQ9*C,T0*a1){
{T81 Zow;{ZK1*n=((ZK1*)Zh(sizeof(*n)));*n=Zed;ZcW(n,(*(Zow=ZrP(a1),&Zow)),a1);(C->Zsm)=((T0*)n);}}}void ZnL2(ZQ9*C){if((((T93*)(((C)->Zzl)))->ZXm)){
Z5G((((T93*)(((C)->Zzl)))->ZCb));{T0*b1=ZoL2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}}T6 ZKJ2(ZQ9*C,T0*a1){T6 R=0;T2 ZXw=0;T2 Zet=0;T2 Z3x=0;
T6 Zdv2=0;Zet=((C)->ZVe);ZXw=((((T7*)a1))->Zdc);if((Z3)(((Z3)((((Z3)((((((T7*)(((C)->ZXe)))->Zdc)))-(Zet))))+(ZGs(1))))>=(ZXw))){(C->Z_e)=((C)->ZWe);
(C->Z0f)=Zet;Z3x=ZGs(1);while(!((Z3)((ZXw)<=(ZGs(0))))){if((((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))])==((((((T7*)a1))->ZUb))[(Z3x)-(ZGs(1))])){
Zet=(Z3)(((Zet))+(ZGs(1)));Z3x=(Z3)(((Z3x))+(ZGs(1)));ZXw=(Z3)(((ZXw))-(ZGs(1)));}else if(ZIs(((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))],(((((T7*)a1))->ZUb))[(Z3x)-(ZGs(1))])){
Zet=(Z3)(((Zet))+(ZGs(1)));Z3x=(Z3)(((Z3x))+(ZGs(1)));ZXw=(Z3)(((ZXw))-(ZGs(1)));Zdv2=((T6)(1));}else{ZXw=ZGs(-1);}}}if((ZXw)==(ZGs(0))){
if((Z3)((Zet)>((((T7*)(((C)->ZXe)))->Zdc)))){R=((T6)(1));(C->_cc)=((T3)'\n');(C->ZVe)=Zet;ZJJ2(C);}else{{int z1=((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))];
switch(z1){case 9:case 32:case 45:R=((T6)(1));(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))];(C->ZVe)=Zet;ZJJ2(C);break;case 48:
case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:
case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:
case 90:case 95:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case
110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:break;default:;R=((T6)(1));
(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[(Zet)-(ZGs(1))];(C->ZVe)=Zet;}}}}if(Zus((T6)(Zus((T6)(R),(T6)(Zdv2))),(T6)((a1)!=((void*)(ZKV))))){
{T81 Zow;Z5G((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));}{T0*b1=Zev2;Zmx((T7*)(Z2G),b1);}{T0*b1=a1;Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(1,"\'");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}return R;}T6 Z5L2(ZQ9*C){T6 R=0;T2 Zdx=0;(C->ZBm)=Zo;while(!((Z3)((Zdx)>=(ZGs(3))))){{int z1=Zdx;
switch(z1){case 0:if(ZpL2(C)){{Zz8*n=((Zz8*)Zh(sizeof(*n)));*n=Z9l;((((Zz8*)(n)))->ZGd)=(((C)->ZAm));(C->ZBm)=((T0*)n);}if(Z5v((T7*)((((ZD8*)(((C)->ZAm)))->Zse)),ZqL2)){
Z3K2((((ZD8*)(((C)->ZAm)))->ZCb),ZrL2);}R=((T6)(1));Zdx=ZGs(1);}else if((((C)->_cc))==(((T3)'\054'))){{ZQ9*C1=C;T0*b1=ZsL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}else{Zdx=ZGs(3);}break;case 1:if((((C)->_cc))==(((T3)'\054'))){(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));
Zdx=ZGs(2);}else if(ZpL2(C)){Z3K2((((ZD8*)(((C)->ZAm)))->ZCb),ZtL2);Zw72((Zz8*)(((C)->ZBm)),((C)->ZAm));if(Z5v((T7*)((((ZD8*)(((C)->ZAm)))->Zse)),ZuL2)){
Z3K2((((ZD8*)(((C)->ZAm)))->ZCb),ZvL2);}}else{Zdx=ZGs(3);}break;default:;if(ZpL2(C)){Zw72((Zz8*)(((C)->ZBm)),((C)->ZAm));if(Z5v((T7*)((((ZD8*)(((C)->ZAm)))->Zse)),ZwL2)){
Z3K2((((ZD8*)(((C)->ZAm)))->ZCb),ZxL2);}Zdx=ZGs(1);}else if((((C)->_cc))==(((T3)'\054'))){{ZQ9*C1=C;T0*b1=ZyL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}else{{ZQ9*C1=C;T0*b1=ZzL2;{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);}}Zdx=ZGs(3);}}}}return R;
}void ZJJ2(ZQ9*C){T81 ZjG={Zo,Zo,0};T6 Zd22=0;while(!(Zd22)){{int z1=((C)->_cc);switch(z1){case 9:case 10:case 32:ZMJ2(C);break;case 45:
ZMJ2(C);if((((C)->_cc))==(((T3)'\055'))){if(((C)->ZZe)){if((((C)->ZWe))==((((T77*)(ZIJ2()))->Zdc))){(C->_cc)=((T3)'\000');Zd22=((T6)(1));
}else{(C->ZWe)=(Z3)(((((C)->ZWe)))+(ZGs(1)));(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(ZIJ2()))->Zal))))->ZUb))[((C)->ZWe)];if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){
(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}}}else{{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->ZWe),(Z3)(((((C)->ZVe)))-((T2)(ZGs(1))))),&Zow));
}ZMJ2(C);((((T7*)((T7*)(ZLu2))))->Zdc)=(ZGs(0));while(!((((C)->_cc))==(((T3)'\n')))){Zgt((T7*)(ZLu2),((C)->_cc));ZMJ2(C);}if((((C)->ZYe))==((void*)(Zo))){
{T91*n=((T91*)Zh(sizeof(*n)));*n=M91;Zkd1(n,ZjG,Z7t((T7*)(ZLu2)));(C->ZYe)=((T0*)n);}}else{Z5z(((T79*)((((T91*)(((C)->ZYe)))->ZZb))),Z7t((T7*)(ZLu2)));
}}}else{(C->_cc)=((T3)'\055');(C->ZVe)=(Z3)(((((C)->ZVe)))-(ZGs(1)));Zd22=((T6)(1));}break;default:;Zd22=((T6)(1));}}}}T6 ZAL2(ZQ9*C){
T6 R=0;T6 ZBL2=0;if(ZKJ2(C,ZJw1)){{T81 Zow;Z5G((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));}{T0*b1=Z1G(43,"Use \"insert\" instead of \"inherit expanded\".");
Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}if(ZCL2(C)){R=((T6)(1));{Zr2*n=((Zr2*)Zh(sizeof(*n)));*n=ZGi;((((Zr2*)(n)))->ZGb)=(((C)->Zxm));
(C->ZHm)=((T0*)n);}if(ZKJ2(C,ZwE2)){Z0L2(C);if((((C)->_cc))==(((T3)'\073'))){{ZQ9*C1=C;T0*b1=Z1G(34,"Unexpected \";\" to end rename list.");
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));}ZBL2=((T6)(1));}ZbL2(C);if(ZKJ2(C,ZDE2)){if(Z5L2(C)){
((((Zr2*)((Zr2*)(((C)->ZHm)))))->ZBi)=(((C)->ZBm));}ZBL2=((T6)(1));}if(ZKJ2(C,ZvE2)){if(Z5L2(C)){((((Zr2*)((Zr2*)(((C)->ZHm)))))->ZCi)=(((C)->ZBm));
}ZBL2=((T6)(1));}if(ZKJ2(C,ZzE2)){if(Z5L2(C)){((((Zr2*)((Zr2*)(((C)->ZHm)))))->ZDi)=(((C)->ZBm));}ZBL2=((T6)(1));}if((T6)(((T6)(((T6)(((T6)((ZKJ2(C,ZwE2))||((T6)(ZKJ2(C,ZiE2)))))||((T6)(ZKJ2(C,ZDE2)))))||((T6)(ZKJ2(C,ZvE2)))))||((T6)(ZKJ2(C,ZzE2))))){
{T81 Zow;Z5G((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));}{T0*b1=Z1G(121,"Inheritance option not at a correct place. The correct order is: \"rename... export... undefine... redefine... select...\".");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}(C->_ok)=((T6)(ZKJ2(C,Z4v2)));if((T6)((!(((C)->_ok)))&&((T6)(ZBL2)))){{ZQ9*C1=C;T0*b1=Z1G(20,ZYq);
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}}return R;}T6 ZYK2(ZQ9*C){T6 R=0;if(Z5K2(C)){(C->ZFm)=ZKE2(&(((C)->ZEd)));R=((T6)(1));}else
if(Z_K2(C)){(C->ZFm)=((C)->ZGm);R=((T6)(1));}return R;}T6 ZDL2(ZQ9*C,T6 a1){T6 R=0;T6 Zd22=0;T2 Z7Q=0;T2 ZXw=0;{int z1=((C)->_cc);switch(z1){
case 35:case 38:case 42:case 43:case 45:case 47:case 60:case 61:case 62:case 64:case 92:case 124:case 126:Z7Q=((C)->ZWe);ZXw=((C)->ZVe);
((((T7*)((T7*)(ZPK2))))->Zdc)=(ZGs(0));R=((T6)(1));Zgt((T7*)(ZPK2),((C)->_cc));ZMJ2(C);while(!(Zd22)){{int z2=((C)->_cc);switch(z2){case
46:case 63:case 123:case 125:R=((T6)(0));Zgt((T7*)(ZPK2),((C)->_cc));ZMJ2(C);break;case 35:case 38:case 42:case 43:case 45:case 47:case
60:case 61:case 62:case 64:case 92:case 94:case 124:case 126:R=((T6)(1));Zgt((T7*)(ZPK2),((C)->_cc));ZMJ2(C);break;default:;Zd22=((T6)(1));
}}}if(R){{int z2=(((T7*)(ZPK2))->Zdc);switch(z2){case 1:{int z3=((((T7*)(ZPK2))->ZUb))[ZGs(0)];switch(z3){case 42:case 43:case 45:case
47:case 60:case 61:case 62:R=((T6)(0));break;}}break;case 2:{int z3=((((T7*)(ZPK2))->ZUb))[ZGs(0)];switch(z3){case 62:{int z4=Z0x((T7*)(ZPK2));
switch(z4){case 61:case 62:R=((T6)(0));break;}}break;case 47:case 60:case 92:{int z4=Z0x((T7*)(ZPK2));switch(z4){case 47:case 61:case
92:R=((T6)(0));break;}}break;}}break;default:;R=((T6)((ZYw((T7*)(ZPK2),((T3)'\076')))!=((((T7*)(ZPK2))->Zdc))));}}}if(R){ZJJ2(C);ZEL2(C,(T6)(a1),Z7Q,ZXw);
}else{ZAK2(C,Z7Q,ZXw);}break;}}return R;}T0*ZpK2(ZQ9*C,T0*a1){T0*R=Zo;T0*ZXw=Zo;ZXw=ZXJ2(C);if((T6)(((ZXw)==((void*)(Zo)))||((T6)((ZZy(((T79*)(((((T91*)ZXw))->ZZb)))))==(ZGs(0)))))){
R=a1;}else{R=ZFL2(a1,ZXw);}return R;}T0*ZIJ2(void){if(Zli1==0){Zli1=1;{{T77*n=((T77*)Zh(sizeof(*n)));*n=M77;Zki1=((T0*)n);Zni1(n);}}}
return Zki1;}T0*ZfK2(ZQ9*C){T0*R=Zo;T81 ZjG={Zo,Zo,0};ZjG=((((C)->ZEd)).ZCb);if(((C)->Zpm)){{Zq7*n=((Zq7*)Zh(sizeof(*n)));*n=Z2k;((((Zq7*)(n)))->ZCb)=(ZjG);
R=((T0*)n);}}else{Z5G(ZjG);{T0*b1=Z1G(45,"`Result\' must only be used inside a function.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}return
R;}T6 ZKK2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};T0*ZDq1=Zo;T0*ZdK2=Zo;T0*ZGL2=Zo;T0*ZHL2=Zo;if(ZlK2(C,((T3)'\041'))){R=((T6)(1));{T81 Zow;
ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZuK2(C)){ZDq1=((C)->ZJm);ZIL2(ZDq1);if(!(ZlK2(C,((T3)'\041')))){ZWJ2(C,Z1G(40,"Bad creation instruction (\'!\' expected)."));
}}else if(ZlK2(C,((T3)'\041'))){}else{ZWJ2(C,Z1G(48,"Bad creation instruction (type or \'!\' expected)."));}ZdK2=ZJL2(C);if(ZlK2(C,((T3)'\056'))){
if(Z5K2(C)){ZGL2=ZKE2(&(((C)->ZEd)));if((((C)->_cc))==(((T3)'\050'))){ZHL2=ZlL2(C,ZdK2,ZGL2,Z9K2(C));}else{{ZP6*n=((ZP6*)Zh(sizeof(*n)));
*n=Zmj;ZKs1(n,ZdK2,ZGL2);ZHL2=((T0*)n);}}}else{ZWJ2(C,ZKL2);}}{ZT2*n=((ZT2*)Zh(sizeof(*n)));*n=Z2e;ZK61(n,ZjG,ZDq1,ZdK2,ZHL2);(C->ZEm)=((T0*)n);
}}return R;}T6 ZCL2(ZQ9*C){T6 R=0;T2 Zdx=0;T0*ZLL2=Zo;T0*ZML2=Zo;if(ZNL2(C)){(C->Zxm)=((C)->Zsm);R=((T6)(1));}else if(ZOL2(C)){R=((T6)(1));
ZLL2=((C)->Zwm);while(!((Z3)((Zdx)>(ZGs(2))))){{int z1=Zdx;switch(z1){case 0:if(ZlK2(C,((T3)'\133'))){Zdx=ZGs(1);}else{{ZJ6*n=((ZJ6*)Zh(sizeof(*n)));
*n=Zjj;((((ZJ6*)(n)))->Zfe)=(ZLL2);(C->Zxm)=((T0*)n);}Zdx=ZGs(3);}break;case 1:if(ZuK2(C)){if((ZML2)==((void*)(Zo))){{ZY*n=((ZY*)Zh(sizeof(*n)));
*n=Zoc;Z7y(n,(T2)(ZGs(2)),(T2)(ZGs(1)));ZML2=((T0*)n);}}Z5y(((ZY*)ZML2),((C)->ZJm));Zdx=ZGs(2);}else if((((C)->_cc))==(((T3)'\054'))){
{ZQ9*C1=C;T0*b1=ZyL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}else if((((C)->_cc))==(((T3)'\135'))){
Zdx=ZGs(2);}else{ZWJ2(C,ZPL2);Zdx=ZGs(2);}break;default:;if(ZlK2(C,((T3)'\054'))){Zdx=ZGs(1);}else if((((C)->_cc))==(((T3)'\135'))){if((ZML2)==((void*)(Zo))){
{ZQ9*C1=C;T0*b1=ZQL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}{ZJ6*n=((ZJ6*)Zh(sizeof(*n)));*n=Zjj;((((ZJ6*)(n)))->Zfe)=(ZLL2);(C->Zxm)=((T0*)n);
}}else{{Zq9*n=((Zq9*)Zh(sizeof(*n)));*n=Z3m;ZzZ(n,ZLL2,ZML2);(C->Zxm)=((T0*)n);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\135'))));Zdx=ZGs(3);}else
if(ZuK2(C)){if((ZML2)==((void*)(Zo))){{ZY*n=((ZY*)Zh(sizeof(*n)));*n=Zoc;Z7y(n,(T2)(ZGs(2)),(T2)(ZGs(1)));ZML2=((T0*)n);}}Z5y(((ZY*)ZML2),((C)->ZJm));
{T81 Zow;Z3K2((*(Zow=ZrP(((C)->ZJm)),&Zow)),ZtL2);}}else{ZWJ2(C,Z1G(17,"Bad generic list."));Zdx=ZGs(3);}}}}}return R;}T6 ZRL2(ZQ9*C){
T6 R=0;T81 ZjG={Zo,Zo,0};if(ZKJ2(C,ZAE2)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZlK2(C,((T3)'\050'))){(C->_ok)=((T6)(Z5L2(C)));
{Ze4*n=((Ze4*)Zh(sizeof(*n)));*n=Z1g;Zke1(n,ZjG,((C)->ZBm));(C->Zym)=((T0*)n);}if(!(ZlK2(C,((T3)'\051')))){ZWJ2(C,Z1G(39,"\')\' expected to end a strip expression."));
}R=((T6)(1));}else{ZWJ2(C,Z1G(35,"\'(\' expected to begin a strip list."));}}return R;}T6 ZSL2(ZQ9*C,T6 a1){T6 R=0;T2 Z7Q=0;T2 ZXw=0;
T0*ZLo2=Zo;T0*ZEQ=Zo;T81 Z4W={Zo,Zo,0};T6 ZTL2=0;if(ZlK2(C,((T3)'\173'))){R=((T6)(1));Z7Q=((C)->Z_e);ZXw=((C)->Z0f);if(ZlK2(C,((T3)'\173'))){
{T81 Zow;Z3K2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z1G(43,ZFp));}}if(ZOL2(C)){ZLo2=((C)->Zwm);}if(!(ZlK2(C,((T3)'\175')))){ZWJ2(C,Z1G(61,ZEo));
}if(ZlK2(C,((T3)'\175'))){{T81 Zow;Z3K2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z1G(43,ZDn));}}ZTL2=((T6)(1));}if(ZKJ2(C,ZWK)){R=((T6)(1));
if((Z7Q)==(ZGs(0))){Z7Q=((C)->Z_e);ZXw=((C)->Z0f);}}else if((Z3)((Z7Q)>(ZGs(0)))){ZWJ2(C,Z1G(32,"Precursor keyword expected here."));
}if(R){{T81 Zow;Z4W=(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow));}if(ZTL2){{T81 Zow;Z3K2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z1G(80,"Obsolete syntax: the parent should now be written after the `precursor\' keyword."));
}}else{if(ZlK2(C,((T3)'\173'))){if(ZlK2(C,((T3)'\173'))){{T81 Zow;Z3K2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z1G(43,ZFp));}}if(ZOL2(C)){
ZLo2=((C)->Zwm);}if(!(ZlK2(C,((T3)'\175')))){ZWJ2(C,Z1G(61,ZEo));}if(ZlK2(C,((T3)'\175'))){{T81 Zow;Z3K2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z1G(43,ZDn));
}}}}ZEQ=Z9K2(C);if(ZlK2(C,((T3)'\056'))){{Zd2*n=((Zd2*)Zh(sizeof(*n)));*n=ZBd;Z8Z(n,Z4W,ZLo2,ZEQ);(C->Zym)=((T0*)n);}Z4K2(C,(T6)(a1),((C)->Zym));
}else if(a1){{Zf8*n=((Zf8*)Zh(sizeof(*n)));*n=ZJk;Zq42(n,Z4W,ZLo2,ZEQ);(C->ZEm)=((T0*)n);}}else{{Zd2*n=((Zd2*)Zh(sizeof(*n)));*n=ZBd;
Z8Z(n,Z4W,ZLo2,ZEQ);(C->Zym)=((T0*)n);}}}return R;}T6 ZHK2(ZQ9*C){T6 R=0;T2 ZUL2=0;T2 ZZn1=0;T2 ZVL2=0;T2 Z_n1=0;T0*ZWL2=Zo;T0*Zet=Zo;
T0*ZKX=Zo;T0*ZXL2=Zo;T0*Zua2=Zo;T0*ZYL2=Zo;T0*ZQJ2=Zo;T0*ZZL2=Zo;T0*Z_L2=Zo;T0*ZRJ2=Zo;T0*Z0M2=Zo;if(ZKJ2(C,ZlE2)){R=((T6)(1));ZUL2=((C)->Z_e);
ZZn1=((C)->Z0f);Zet=ZkK2(C);if(ZKJ2(C,ZLi1)){ZVL2=((C)->Z_e);Z_n1=((C)->Z0f);ZQJ2=ZXJ2(C);ZRJ2=ZZJ2(C);if((T6)(((ZQJ2)!=((void*)(Zo)))||((T6)((ZRJ2)!=((void*)(Zo)))))){
{T81 Zow;{Zm9*n=((Zm9*)Zh(sizeof(*n)));*n=Z1m;Zje2(n,(*(Zow=ZYJ2(C,ZVL2,Z_n1),&Zow)),ZQJ2,ZRJ2);ZKX=((T0*)n);}}}}if(ZKJ2(C,ZGE2)){ZZL2=ZXJ2(C);
if(ZBK2(C)){Z0M2=((C)->ZKm);}Z_L2=ZXJ2(C);if(ZhK2(C)){{ZS1*n=((ZS1*)Zh(sizeof(*n)));*n=Zmd;ZxX(n,ZZL2,Z0M2,Z_L2,ZjK2(C,((C)->Zym)));ZXL2=((T0*)n);
}}else{{ZQ9*C1=C;T0*b1=Z1G(38,"Variant (INTEGER) Expression Expected.");{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}}if(ZKJ2(C,ZFE2)){
if(ZhK2(C)){Zua2=ZjK2(C,((C)->Zym));}else{ZWJ2(C,Z1G(36,"Boolean expression expected (until)."));Zua2=((C)->Zym);}}else{ZWJ2(C,Z1G(37,"Keyword \"until\" expected (in a loop)."));
Zua2=((C)->Zym);}if((((C)->_cc))==(((T3)'\073'))){{ZQ9*C1=C;T0*b1=ZoK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));
}if(!(ZKJ2(C,ZMi1))){{ZQ9*C1=C;T0*b1=Z1G(36,"Keyword \"loop\" expected (in a loop).");{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}ZYL2=Z2K2(C,Z1M2,Z4v2);
{T81 Zow;{Z09*n=((Z09*)Zh(sizeof(*n)));*n=Ztl;Zla2(n,(*(Zow=ZYJ2(C,ZUL2,ZZn1),&Zow)),Zet,ZKX,ZXL2,Zua2,ZYL2);ZWL2=((T0*)n);}}(C->ZEm)=ZWL2;
}return R;}T6 ZEK2(ZQ9*C){T6 R=0;T0*Z2M2=Zo;if(ZKJ2(C,ZNF1)){R=((T6)(1));{T81 Zow;{Z45*n=((Z45*)Zh(sizeof(*n)));*n=Z9h;((((Z45*)(n)))->ZCb)=((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));
Z2M2=((T0*)n);}}Z3M2(C,Z2M2);if(ZKJ2(C,ZN91)){((((Z45*)(((Z45*)Z2M2))))->Zme)=(Z2K2(C,Z4M2,Z4v2));}else{if(!(ZKJ2(C,Z4v2))){{ZQ9*C1=C;
T0*b1=Z1G(20,ZYq);{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}}(C->ZEm)=Z2M2;}return R;}T0*Z5M2(T0*a1,T0*a2,T0*a3){T0*R=Zo;if((a2)==((void*)(Zo))){
R=a1;}else if((a3)==((void*)(Zo))){{ZU1*n=((ZU1*)Zh(sizeof(*n)));*n=Znd;Z0Y(n,a1,a2);R=((T0*)n);}}else if((Z5H1(((Za3*)a3)))==(ZGs(1))){
{ZO1*n=((ZO1*)Zh(sizeof(*n)));*n=Zhd;ZbX(n,a1,a2,a3);R=((T0*)n);}}else{{ZM9*n=((ZM9*)Zh(sizeof(*n)));*n=Zim;ZWl2(n,a1,a2,a3);R=((T0*)n);
}}return R;}T0*Z6H2(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}T6 ZpL2(ZQ9*C){T6 R=0;if(Z6M2(C)){
R=((T6)(1));}else if(Z7M2(C)){R=((T6)(1));}else if(Z5K2(C)){(C->ZAm)=ZKE2(&(((C)->ZEd)));R=((T6)(1));}return R;}void ZaK2(ZQ9*C,T6 a1,T0*a2,T0*a3,T0*a4,T6
a5){if(ZlK2(C,((T3)'\056'))){if((T6)(((a2)!=((void*)(Zo)))&&((T6)(Ze31(a2))))){{T81 Zow;Z5G((*(Zow=ZLG(a2),&Zow)));}{T0*b1=Z1G(27,"Void is not a valid target.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Z4K2(C,(T6)(a1),Z5M2(a2,a3,a4));}else{if(a1){(C->ZEm)=ZlL2(C,a2,a3,a4);(C->Zym)=Zo;}else{(C->Zym)=Z5M2(a2,a3,a4);
(C->ZEm)=Zo;}}}T6 ZlK2(ZQ9*C,T3 a1){T6 R=0;if((a1)==(((C)->_cc))){(C->Z_e)=((C)->ZWe);(C->Z0f)=((C)->ZVe);R=((T6)(1));ZMJ2(C);ZJJ2(C);
}return R;}T6 ZaL2(ZQ9*C,T3 a1,T3 a2){T6 R=0;if((a1)==(((C)->_cc))){(C->Z_e)=((C)->ZWe);(C->Z0f)=((C)->ZVe);ZMJ2(C);if((a2)==(((C)->_cc))){
R=((T6)(1));ZMJ2(C);ZJJ2(C);}else{(C->_cc)=a1;(C->ZVe)=((C)->Z0f);}}return R;}T6 ZIK2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};T0*ZDq1=Zo;T0*ZdK2=Zo;
T0*ZGL2=Zo;T0*ZHL2=Zo;if(ZKJ2(C,Z7_)){R=((T6)(1));{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZlK2(C,((T3)'\173'))){
if(ZuK2(C)){ZDq1=((C)->ZJm);ZIL2(ZDq1);if(!(ZlK2(C,((T3)'\175')))){ZWJ2(C,Z8M2);}}else{ZWJ2(C,Z1G(39,Z2p));}}ZdK2=ZJL2(C);if(ZlK2(C,((T3)'\056'))){
if(Z5K2(C)){ZGL2=ZKE2(&(((C)->ZEd)));if((((C)->_cc))==(((T3)'\050'))){ZHL2=ZlL2(C,ZdK2,ZGL2,Z9K2(C));}else{{ZP6*n=((ZP6*)Zh(sizeof(*n)));
*n=Zmj;ZKs1(n,ZdK2,ZGL2);ZHL2=((T0*)n);}}}}{ZV4*n=((ZV4*)Zh(sizeof(*n)));*n=Z1h;Zal1(n,ZjG,ZDq1,ZdK2,ZHL2);(C->ZEm)=((T0*)n);}}return
R;}T6 Z6M2(ZQ9*C){T6 R=0;if(ZKJ2(C,Zlp2)){R=((T6)(1));if((((C)->_cc))==(((T3)'\042'))){ZMJ2(C);}else{{ZQ9*C1=C;T0*b1=Z1G(39,"Character \'%\"\' inserted after \"prefix\".");
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}if(Z9M2(C)){}else if(ZaM2(C,(T6)(1))){}else{ZWJ2(C,Z1G(30,"Prefix operator name expected."));
}if(!(ZlK2(C,((T3)'\042')))){{ZQ9*C1=C;T0*b1=Z1G(24,ZZq);{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}}return R;}T6 ZVK2(ZQ9*C){T6 R=0;
ZxG2(&(((C)->ZLm)));if(ZKJ2(C,ZmE2)){if(ZpL2(C)){R=((T6)(1));ZbM2(C);ZfG2(((C)->ZAm));}else{ZWJ2(C,ZzL2);}}else if(ZpL2(C)){R=((T6)(1));
ZfG2(((C)->ZAm));}while(!(!(ZlK2(C,((T3)'\054'))))){if(ZKJ2(C,ZmE2)){if(ZpL2(C)){ZbM2(C);ZfG2(((C)->ZAm));}else{ZWJ2(C,Z1G(37,"Frozen feature name synonym expected."));
}}else if(ZpL2(C)){ZfG2(((C)->ZAm));}else{{ZQ9*C1=C;T0*b1=Z1G(30,"Synonym feature name expected.");{T81 Zow;ZmG2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}}if(R){ZqK2(C);if(ZlK2(C,((T3)'\072'))){if(ZuK2(C)){(C->Zpm)=((T6)(1));((((Zy7*)(&(((C)->ZLm)))))->ZGb)=(((C)->ZJm));}else{ZWJ2(C,ZPL2);
}}else{(C->Zpm)=((T6)(0));}if(ZKJ2(C,ZqE2)){if(ZKJ2(C,ZEE2)){(C->Zzm)=ZiG2(&(((C)->ZLm)));}else if(ZcM2(C)){(C->Zzm)=ZsG2(&(((C)->ZLm)),((C)->Zum));
}else if(ZiL2(C)){(C->Zzm)=ZqG2(&(((C)->ZLm)),((C)->Zvm));}else if(ZVJ2(C)){ZnL2(C);((((T93*)((T93*)(((C)->Zzl)))))->ZXm)=((T6)(1));(C->Zzm)=ZvG2(&(((C)->ZLm)),((C)->Zzl));
}else if(ZdM2(C)){(C->Zzm)=ZtG2(&(((C)->ZLm)),((C)->Ztm));}else if(ZyK2(C)){(C->Zzm)=ZCG2(&(((C)->ZLm)),((C)->ZIm));}else if(ZeM2(C)){
(C->Zzm)=ZzG2(&(((C)->ZLm)),((C)->ZDm));}else{(C->Zzm)=ZPJ2(C);}}else{(C->Zzm)=ZlG2(&(((C)->ZLm)));}(C->Zpm)=((T6)(0));(C->ZFb)=Zo;}return
R;}void ZMJ2(ZQ9*C){if((Z3)((((C)->ZVe))<((((T7*)(((C)->ZXe)))->Zdc)))){(C->ZVe)=(Z3)(((((C)->ZVe)))+(ZGs(1)));(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[(((C)->ZVe))-(ZGs(1))];
}else if((((C)->ZVe))==((((T7*)(((C)->ZXe)))->Zdc))){(C->ZVe)=(Z3)(((((C)->ZVe)))+(ZGs(1)));(C->_cc)=((T3)'\n');}else if((((C)->ZWe))==((((T77*)(ZIJ2()))->Zdc))){
(C->_cc)=((T3)'\000');}else{(C->ZWe)=(Z3)(((((C)->ZWe)))+(ZGs(1)));(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(ZIJ2()))->Zal))))->ZUb))[((C)->ZWe)];
if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}}}void ZNv2(ZQ9*C){
(C->Zlm)=((T6)(1));{T0*b1=ZfM2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}T0*ZnP(ZQ9*C,T0*a1){T0*R=Zo;T0*Zfz2=Zo;ZvP((T38*)(Z6H2()),ZgM2);
ZvP((T38*)(Z6H2()),a1);ZvP((T38*)(Z6H2()),ZhM2);Zpi1((T77*)(ZIJ2()),a1);if(!(((((T77*)(ZIJ2()))->Ztc))!=(Zo))){{T0*b1=Z1G(55,"Cannot open Cecil file (use -verbose flag for details).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}Zfz2=(((T77*)(ZIJ2()))->Ztc);(C->Znm)=ZH_((T42*)(ZiM2()),Zfz2);(C->Zmm)=((T6)(1));(C->Zig)=Zo;(C->Zpm)=((T6)(0));
(C->Zqm)=((T6)(0));(C->ZYe)=Zo;(C->ZWe)=ZGs(1);(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(ZIJ2()))->Zal))))->ZUb))[((C)->ZWe)];(C->Zom)=Zo;
if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}ZJJ2(C);{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Zwx(n,(T2)(ZGs(32)));R=((T0*)n);}while(!((T6)(((((C)->_cc))==(((T3)'\n')))||((T6)((((C)->_cc))==(((T3)'\000'))))))){Zgt(((T7*)R),((C)->_cc));
ZMJ2(C);}ZJJ2(C);if((((C)->_cc))==(((T3)'\000'))){{T0*b1=Z1G(49,"Empty Cecil file (use -verbose flag for details).");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}return R;}T6 ZdM2(ZQ9*C){T6 R=0;T2 Z7Q=0;T2 ZXw=0;T6 Zd22=0;if((T6)(((((C)->_cc))==(((T3)'0')))||((T6)((((C)->_cc))==(((T3)'1')))))){
Z7Q=((C)->ZWe);ZXw=((C)->ZVe);((((T7*)((T7*)(ZPK2))))->Zdc)=(ZGs(0));Zgt((T7*)(ZPK2),((C)->_cc));while(!(Zd22)){ZMJ2(C);{int z1=((C)->_cc);
switch(z1){case 48:case 49:Zgt((T7*)(ZPK2),((C)->_cc));break;case 66:case 98:{T81 Zow;{Z56*n=((Z56*)Zh(sizeof(*n)));*n=ZSm;Zln2(n,(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)),Z7t((T7*)(ZPK2)));
(C->Ztm)=((T0*)n);}}ZMJ2(C);ZJJ2(C);Zd22=((T6)(1));R=((T6)(1));break;default:;ZAK2(C,Z7Q,ZXw);Zd22=((T6)(1));}}}}return R;}void ZLv2(ZQ9*C){
(C->Zkm)=((T6)(1));(((void)((T27*)(ZNJ2()))));ZDl2(Z9J);ZDl2(ZdJ);ZDl2(ZvJ);ZDl2(ZKJ);ZDl2(ZXJ);ZDl2(ZYJ);ZDl2(ZZJ);ZDl2(Z0K);ZDl2(Z1K);
ZDl2(Z2K);ZDl2(Z4K);ZDl2(ZiK);{T0*b1=ZjM2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}T6 ZzK2(ZQ9*C,T1 a1){T6 R=0;T2 Zdx=0;T2 Z7Q=0;T2 ZXw=0;
if((T6)((Zys(((C)->_cc)))||((T6)((((C)->_cc))==(((T3)'\056')))))){Z7Q=((C)->ZWe);ZXw=((C)->ZVe);((((T7*)((T7*)(ZPK2))))->Zdc)=(ZGs(0));
if((Z1)((a1)<(ZGs(0)))){Zgt((T7*)(ZPK2),((T3)'\055'));}if((((C)->_cc))==(((T3)'\056'))){Zmx((T7*)(ZPK2),ZkM2);Zdx=ZGs(5);}else{Zgt((T7*)(ZPK2),((C)->_cc));
}while(!((Z3)((Zdx)>(ZGs(11))))){ZMJ2(C);{int z1=Zdx;switch(z1){case 0:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:
case 52:case 53:case 54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));break;case 46:Zgt((T7*)(ZPK2),((T3)'\056'));Zdx=ZGs(4);break;
default:;Zdx=ZGs(13);}}break;case 1:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case
56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(2);break;default:;ZWJ2(C,ZlM2);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 48:case
49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(3);break;default:;ZWJ2(C,ZlM2);
}}break;case 3:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));
Zdx=ZGs(0);break;default:;ZWJ2(C,ZlM2);}}break;case 4:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case
54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(6);break;case 69:case 101:Zgt((T7*)(ZPK2),((T3)'E'));Zdx=ZGs(10);break;
default:;Zdx=ZGs(12);}}break;case 5:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case
56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(6);break;default:;Zdx=ZGs(13);}}break;case 6:{int z2=((C)->_cc);switch(z2){case 48:case
49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));break;case 69:case 101:Zgt((T7*)(ZPK2),((T3)'E'));
Zdx=ZGs(10);break;case 95:Zdx=ZGs(7);break;default:;Zdx=ZGs(12);}}break;case 7:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:
case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(8);break;default:;ZWJ2(C,ZmM2);}}break;case
8:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));
Zdx=ZGs(9);break;default:;ZWJ2(C,ZmM2);}}break;case 9:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case
54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(6);break;default:;ZWJ2(C,ZmM2);}}break;case 10:{int z2=((C)->_cc);switch(z2){
case 43:Zdx=ZGs(11);break;case 45:Zgt((T7*)(ZPK2),((T3)'\055'));Zdx=ZGs(11);break;case 48:case 49:case 50:case 51:case 52:case 53:case
54:case 55:case 56:case 57:Zgt((T7*)(ZPK2),((C)->_cc));Zdx=ZGs(11);break;default:;ZWJ2(C,Z1G(34,"Exponent of a real value expected."));
Zdx=ZGs(13);}}break;default:;{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case
57:Zgt((T7*)(ZPK2),((C)->_cc));break;default:;Zdx=ZGs(12);}}}}}if((Zdx)==(ZGs(12))){{T81 Zow;{ZC9*n=((ZC9*)Zh(sizeof(*n)));*n=Zdm;ZMX(n,(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)),Z7t((T7*)(ZPK2)));
(C->ZIm)=((T0*)n);}}R=((T6)(1));ZJJ2(C);}else{ZAK2(C,Z7Q,ZXw);}}return R;}T6 ZnM2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};T0*Zfx=Zo;T0*Z3V=Zo;
T0*ZHL2=Zo;T0*Z3r1=Zo;if(ZKJ2(C,Z5J)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}R=((T6)(1));if(ZlK2(C,((T3)'\173'))){
if(!(ZuK2(C))){ZWJ2(C,Z1G(31,"Bad agent (BASE type expected)."));}Zfx=((C)->ZJm);if(!(ZlK2(C,((T3)'\175')))){ZWJ2(C,Z1G(25,"Bad agent (\"\175""\" expected)."));
}if(!(ZlK2(C,((T3)'\056')))){ZWJ2(C,Z1G(25,Zfo));}}else if(ZlK2(C,((T3)'\050'))){if(ZhK2(C)){Z3V=((C)->Zym);}if(!(ZlK2(C,((T3)'\051')))){
ZWJ2(C,Z1G(25,"Bad agent (\")\" expected)."));}if(!(ZlK2(C,((T3)'\056')))){ZWJ2(C,Z1G(25,Zfo));}}if(!(Z5K2(C))){ZWJ2(C,ZoM2);}if((Z3V)!=((void*)(Zo))){
Z3r1=ZKE2(&(((C)->ZEd)));ZaK2(C,(T6)(0),Z3V,Z3r1,Z9K2(C),(T6)(1));}else if(ZeK2(C)){ZaK2(C,(T6)(0),((C)->Zym),Zo,Zo,(T6)(1));}else if((T6)(((T6)(((T6)((Z6K2(C))||((T6)(Z8K2(C)))))||((T6)(Z7K2(C)))))||((T6)(ZgK2(C))))){
ZaK2(C,(T6)(0),((C)->Zym),Zo,Zo,(T6)(0));}else{ZLK2(C);}Z3V=((C)->Zym);ZHL2=Z3V;if(Zo!=(ZHL2)){switch(((T0*)ZHL2)->id){case 236:case 242:case
243:case 244:case 245:case 246:case 247:case 248:case 249:case 250:case 251:case 252:case 253:case 254:case 257:case 263:case 264:case
267:case 268:case 269:case 338:case 339:case 341:case 342:case 343:case 344:case 345:break;default:ZHL2=Zo;}}if((ZHL2)==((void*)(Zo))){
if((Z3V)!=((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(Z3V),&Zow)));}}{T0*b1=ZoM2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}{ZV6*n=((ZV6*)Zh(sizeof(*n)));
*n=Zyj;ZPM1(n,ZjG,Zfx,ZHL2);(C->Zym)=((T0*)n);}}return R;}T6 Z7K2(ZQ9*C){T6 R=0;if(Z6E2()){(C->Zym)=ZNE2(&(((C)->ZEd)));R=((T6)(1));}
return R;}T6 ZpM2(ZQ9*C){T6 R=0;T2 Z7Q=0;T2 ZXw=0;T0*ZDq1=Zo;T0*Z3r1=Zo;if(ZlK2(C,((T3)'\044'))){if(Z5K2(C)){if((T6)(((T6)((Z6K2(C))||((T6)(Z7K2(C)))))||((T6)(Z8K2(C))))){
{T81 Zow;Z5G((*(Zow=ZLG(((C)->Zym)),&Zow)));}{T0*b1=ZSe1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{Z3r1=ZKE2(&(((C)->ZEd)));{ZG1*n=((ZG1*)Zh(sizeof(*n)));
*n=Z5g;((((ZG1*)(n)))->Z2c)=(Z3r1);(C->Zym)=((T0*)n);}R=((T6)(1));}}else{ZWJ2(C,ZSe1);}}else if(ZlK2(C,((T3)'\077'))){R=((T6)(1));Z7Q=((C)->Z_e);
ZXw=((C)->Z0f);{T81 Zow;{Zu3*n=((Zu3*)Zh(sizeof(*n)));*n=ZLl;((((Zu3*)(n)))->ZCb)=((*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)));(C->Zym)=((T0*)n);}
}}else if(ZlK2(C,((T3)'\173'))){Z7Q=((C)->Z_e);ZXw=((C)->Z0f);if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZDq1=((C)->ZJm);if(!(ZlK2(C,((T3)'\175')))){
ZWJ2(C,Z8M2);}if(ZKJ2(C,ZWK)){ZAK2(C,Z7Q,ZXw);}else{R=((T6)(1));{T81 Zow;{Zu3*n=((Zu3*)Zh(sizeof(*n)));*n=ZLl;Z0d2(n,(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)),ZDq1);
(C->Zym)=((T0*)n);}}}}else if(ZhK2(C)){R=((T6)(1));}return R;}T0*ZkI2(ZQ9*C,T0*a1){T0*R=Zo;T2 ZrM2=0;T2 ZsM2=0;T0*Zfz2=Zo;(C->Znm)=ZH_((T42*)(ZiM2()),((((T85*)a1))->Zse));
Zfz2=(((T77*)(ZIJ2()))->Ztc);if((Z3)(((((T80*)(Z4G))->ZEg))>(ZGs(0)))){{T0*b1=Z1G(32,"Correct previous error(s) first.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}ZSP((T38*)(Z6H2()),(Z3)((((((ZO5*)(ZDy2()))->Zdc)))+((T2)(ZGs(1)))));ZWP((T38*)(Z6H2()),((T3)'\011'));ZvP((T38*)(Z6H2()),Zfz2);
ZWP((T38*)(Z6H2()),((T3)'\n'));ZrM2=(((T80*)(Z4G))->ZEg);ZsM2=(((T80*)(Z4G))->ZFg);(C->Zmm)=((T6)(1));(C->Zpm)=((T6)(0));(C->Zqm)=((T6)(0));
(C->ZYe)=Zo;(C->ZWe)=ZGs(1);(C->ZVe)=ZGs(1);(C->ZXe)=(((((T55*)((((T77*)(ZIJ2()))->Zal))))->ZUb))[((C)->ZWe)];if(((((T7*)(((C)->ZXe)))->Zdc))==(ZGs(0))){
(C->_cc)=((T3)'\n');}else{(C->_cc)=((((T7*)(((C)->ZXe)))->ZUb))[ZGs(0)];}{T87*n=((T87*)Zh(sizeof(*n)));*n=M87;ZVm1(n,Zfz2,((((T85*)a1))->Zse),(((T77*)(ZIJ2()))->Zbg),((C)->Znm));
(C->Zom)=((T0*)n);}ZJJ2(C);ZtM2(C);(C->Zmm)=((T6)(0));ZA72((T77*)(ZIJ2()));R=((C)->Zom);if((Z3)(((Z3)((((((T80*)(Z4G))->ZEg)))-(ZrM2)))>(ZGs(0)))){
Z7H2((((T80*)(Z4G))->ZEg),Z9H2);(((void)((T38*)(Z6H2()))),Zzi1(Z1G(12,"Load class \"")));(((void)((T38*)(Z6H2()))),Zzi1(Zfz2));(((void)((T38*)(Z6H2()))),Zzi1(Z1G(11,"\" aborted.\n")));
R=Zo;}else if((Z3)(((Z3)((((((T80*)(Z4G))->ZFg)))-(ZsM2)))>(ZGs(0)))){{T6 Z5H2=0;if((((T38*)(Z6H2()))->ZKh)){Z5H2=((T6)(1));}else if((((T80*)(Z4G))->ZGg)){
}else{Z5H2=((T6)(1));}if(Z5H2){Z7H2((((T80*)(Z4G))->ZFg),Z8H2);}}}if((R)!=((void*)(Zo))){ZSn1(((T87*)R));}return R;}T6 ZuM2(ZQ9*C,T0*a1){
T6 R=0;T2 Zdx=0;T0*ZP11=Zo;T0*ZvM2=Zo;if(ZKJ2(C,ZHE2)){R=((T6)(1));{T81 Zow;{ZN4*n=((ZN4*)Zh(sizeof(*n)));*n=ZVg;Znj1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),ZXJ2(C));
ZP11=((T0*)n);}}while(!((Z3)((Zdx)>(ZGs(3))))){{int z1=Zdx;switch(z1){case 0:if(ZwM2(C)){ZvM2=((C)->Zym);Zdx=ZGs(1);}else if(ZKJ2(C,ZBE2)){
if((ZvM2)!=((void*)(Zo))){Zdj1(((ZN4*)ZP11),ZvM2);}((((ZN4*)(((ZN4*)ZP11))))->Zfd)=(ZkK2(C));Zu91(((Zg3*)a1),ZP11);Zdx=ZGs(4);}else if((((C)->_cc))==(((T3)'\054'))){
{ZQ9*C1=C;T0*b1=ZsL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}else{ZWJ2(C,ZxM2);Zdx=ZGs(4);}
break;case 1:if(ZKJ2(C,ZBE2)){if((ZvM2)!=((void*)(Zo))){Zdj1(((ZN4*)ZP11),ZvM2);}((((ZN4*)(((ZN4*)ZP11))))->Zfd)=(ZkK2(C));Zu91(((Zg3*)a1),ZP11);
Zdx=ZGs(4);}else if(ZaL2(C,((T3)'\056'),((T3)'\056'))){Zdx=ZGs(2);}else if(ZlK2(C,((T3)'\054'))){Zdj1(((ZN4*)ZP11),ZvM2);ZvM2=Zo;Zdx=ZGs(0);
}else{ZWJ2(C,ZxM2);Zdx=ZGs(4);}break;case 2:if(ZwM2(C)){Zzj1(((ZN4*)ZP11),ZvM2,((C)->Zym));ZvM2=Zo;Zdx=ZGs(3);}else{ZWJ2(C,ZxM2);Zdx=ZGs(4);
}break;default:;if(ZlK2(C,((T3)'\054'))){Zdx=ZGs(0);}else if(ZKJ2(C,ZBE2)){((((ZN4*)(((ZN4*)ZP11))))->Zfd)=(ZkK2(C));Zu91(((Zg3*)a1),ZP11);
Zdx=ZGs(4);}else if(ZwM2(C)){ZvM2=((C)->Zym);Z3K2(((((C)->ZEd)).ZCb),ZtL2);Zdx=ZGs(1);}else{ZWJ2(C,ZxM2);Zdx=ZGs(4);}}}}}return R;}void
Z3M2(ZQ9*C,T0*a1){if(!(ZiK2(C,a1))){ZWJ2(C,Z1G(21,"In \"if ... then ...\"."));}while(!(!(ZKJ2(C,ZhE2)))){if(!(ZiK2(C,a1))){ZWJ2(C,Z1G(25,"In \"elseif ... then ...\"."));
}}}T6 ZDK2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};T0*ZqV=Zo;T0*ZnN1=Zo;if(ZKJ2(C,ZOi1)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(ZlK2(C,((T3)'\050'))){{ZA3*n=((ZA3*)Zh(sizeof(*n)));*n=ZCe;ZGA(n,(T2)(ZGs(4)));ZqV=((T0*)n);}while(!(!(ZVJ2(C)))){((((T93*)((T93*)(((C)->Zzl)))))->ZXm)=((T6)(1));
ZFA(((ZA3*)ZqV),((C)->Zzl));(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}if((Z3)((((((ZA3*)ZqV))->ZWb))<(ZGs(0)))){{ZQ9*C1=C;T0*b1=Z1G(31,"Empty debug key list (deleted).");
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}ZqV=Zo;}if(!(ZlK2(C,((T3)'\051')))){ZWJ2(C,Z1G(38,"\")\" expected to end debug string list."));
}}R=((T6)(1));{ZM1*n=((ZM1*)Zh(sizeof(*n)));*n=Zgd;ZIW(n,ZjG,ZqV,Z2K2(C,ZyM2,Z4v2));ZnN1=((T0*)n);}(C->ZEm)=ZnN1;}return R;}void ZzM2(ZQ9*C){
if(ZKJ2(C,ZnE2)){while(!(!(ZWK2(C)))){(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));}}}T6 Z1L2(ZQ9*C){T6 R=0;T0*ZAM2=Zo;T0*ZBM2=Zo;T2 Z7Q=0;T2
ZXw=0;Z7Q=((C)->ZWe);ZXw=((C)->ZVe);if(ZpL2(C)){ZAM2=((C)->ZAm);if(ZKJ2(C,ZcE2)){if(ZpL2(C)){R=((T6)(1));{ZR4*n=((ZR4*)Zh(sizeof(*n)));
*n=Z0h;ZWk1(n,ZAM2,((C)->ZAm));ZBM2=((T0*)n);}ZjF1((Zr2*)(((C)->ZHm)),ZBM2);}else{ZWJ2(C,Z1G(46,"Second identifier of a \"rename\" pair expected."));
}}else{ZAK2(C,Z7Q,ZXw);}}return R;}T6 Z_K2(ZQ9*C){T6 R=0;if(ZcM2(C)){(C->ZGm)=((C)->Zum);R=((T6)(1));}else if(ZiL2(C)){(C->ZGm)=((C)->Zvm);
R=((T6)(1));}else if(ZVJ2(C)){(C->ZGm)=((C)->Zzl);R=((T6)(1));}else if(ZdM2(C)){(C->ZGm)=((C)->Ztm);R=((T6)(1));}else if(ZyK2(C)){(C->ZGm)=((C)->ZIm);
R=((T6)(1));}else if(ZeM2(C)){(C->ZGm)=((C)->ZDm);R=((T6)(1));}return R;}T0*ZCM2(void){if(ZqI2==0){ZqI2=1;{{ZS*n=((ZS*)Zh(1));ZpI2=((T0*)n);
}}}return ZpI2;}T6 ZGK2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};T81 ZDM2={Zo,Zo,0};T0*Zet=Zo;T0*Zpo1=Zo;if(ZKJ2(C,ZpE2)){R=((T6)(1));{T81 Zow;
ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZhK2(C)){(C->Zym)=ZjK2(C,((C)->Zym));}else{ZWJ2(C,Z1G(37,"Expression expected (\"inspect ... \")."));
}{Zg3*n=((Zg3*)Zh(sizeof(*n)));*n=Zoe;ZS91(n,ZjG,((C)->Zym));Zet=((T0*)n);}while(!(!(ZuM2(C,Zet)))){}if(ZKJ2(C,ZN91)){{T81 Zow;ZDM2=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}Zpo1=Z2K2(C,ZEM2,Z4v2);ZT91(((Zg3*)Zet),ZDM2,Zpo1);}else if(!(ZKJ2(C,Z4v2))){{ZQ9*C1=C;T0*b1=Z1G(36,"Added \"end\" for inspect instruction.");
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}(C->ZEm)=Zet;}return R;}T6 ZFM2(ZQ9*C){T6 R=0;if(ZRL2(C)){R=((T6)(1));}else if(ZlK2(C,((T3)'\050'))){
R=((T6)(1));if(ZhK2(C)){if(ZlK2(C,((T3)'\051'))){ZaK2(C,(T6)(0),((C)->Zym),Zo,Zo,(T6)(0));}else{ZWJ2(C,Z1G(27,"\')\' expected in expression."));
}}else{ZWJ2(C,Z1G(20,"Expression expected."));}}else if(Z_K2(C)){(C->Zym)=((C)->ZGm);R=((T6)(1));if(ZlK2(C,((T3)'\056'))){{ZQ9*C1=C;T0*b1=ZGM2;
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}Z4K2(C,(T6)(0),((C)->Zym));}}else if(ZSL2(C,(T6)(0))){R=((T6)(1));}else if(ZHM2(C)){R=((T6)(1));
}else if(ZnM2(C)){R=((T6)(1));}else if(Z5K2(C)){R=((T6)(1));if(ZeK2(C)){ZaK2(C,(T6)(0),((C)->Zym),Zo,Zo,(T6)(1));}else if((T6)(((T6)(((T6)((Z8K2(C))||((T6)(Z6K2(C)))))||((T6)(Z7K2(C)))))||((T6)(ZgK2(C))))){
ZaK2(C,(T6)(0),((C)->Zym),Zo,Zo,(T6)(0));}else{ZLK2(C);}}return R;}T6 ZOL2(ZQ9*C){T6 R=0;T2 ZXw=0;T6 Zd22=0;T6 Zj31=0;if(ZHs(((C)->_cc))){
if((((unsigned)(((C)->_cc)))>=((unsigned)(((T3)'a'))))){Zj31=((T6)(1));(C->_cc)=ZKs(((C)->_cc));}ZXw=((C)->ZVe);{T81 Zow;ZwZ(&(((C)->ZEd)),(*(Zow=ZYJ2(C,((C)->ZWe),ZXw),&Zow)));
}{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}while(!(Zd22)){ZMJ2(C);{int z1=((C)->_cc);switch(z1){case 48:case 49:case 50:case 51:case 52:case
53:case 54:case 55:case 56:case 57:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case
77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:case 95:{T3 b1=((C)->_cc);
Zgt((T7*)(ZyZ),b1);}break;case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case
109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:Zj31=((T6)(1));
{T3 b1=ZKs(((C)->_cc));Zgt((T7*)(ZyZ),b1);}break;default:;Zd22=((T6)(1));}}}if(Z9E2(&(((C)->ZEd)))){(C->_cc)=(((((T7*)ZyZ))->ZUb))[ZGs(0)];
(C->ZVe)=ZXw;}else{R=((T6)(1));ZJJ2(C);if(Zj31){Z3K2(((((C)->ZEd)).ZCb),ZIM2);}(C->Zwm)=ZAZ(&(((C)->ZEd)));}}return R;}T6 ZeK2(ZQ9*C){
T6 R=0;T2 Zwa1=0;if((((C)->ZFb))!=((void*)(Zo))){Zwa1=Z9a1((Zz6*)(((C)->ZFb)),Z4E2(&(((C)->ZEd))));if((Z3)((Zwa1)>(ZGs(0)))){(C->Zym)=Z5E2(&(((C)->ZEd)),((C)->ZFb),Zwa1);
R=((T6)(1));}}return R;}T0*ZpP(ZQ9*C){T0*R=Zo;if(ZCL2(C)){R=((C)->Zxm);}else{ZWJ2(C,ZPL2);}return R;}T6 ZuK2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};
T0*ZJM2=Zo;R=((T6)(1));if(ZKJ2(C,Zek1)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z7M2(C)){{ZP4*n=((ZP4*)Zh(sizeof(*n)));
*n=ZYg;Zdk1(n,ZjG,((C)->ZAm));(C->ZJm)=((T0*)n);}}else if(Z6M2(C)){{ZP4*n=((ZP4*)Zh(sizeof(*n)));*n=ZYg;Zdk1(n,ZjG,((C)->ZAm));(C->ZJm)=((T0*)n);
}}else if(Z5K2(C)){if(Z8K2(C)){{Zp2*n=((Zp2*)Zh(sizeof(*n)));*n=ZNd;((((Zp2*)(n)))->ZCb)=(ZjG);(C->ZJm)=((T0*)n);}}else if(ZeK2(C)){ZJM2=((C)->Zym);
if(Zo!=(ZJM2)){switch(((T0*)ZJM2)->id){case 276:break;default:ZJM2=Zo;}}{Zr8*n=((Zr8*)Zh(sizeof(*n)));*n=Z3l;ZAa1(n,ZjG,ZJM2);(C->ZJm)=((T0*)n);
}}else{{ZP4*n=((ZP4*)Zh(sizeof(*n)));*n=ZYg;Zdk1(n,ZjG,ZKE2(&(((C)->ZEd))));(C->ZJm)=((T0*)n);}}}else{ZWJ2(C,Z1G(82,"Anchor expected. An anchor could be `Current\', a feature name or an argument name."));
}}else if(ZKJ2(C,ZJw1)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZCL2(C)){{ZG5*n=((ZG5*)Zh(sizeof(*n)));*n=ZLh;Zvw1(n,ZjG,((C)->Zxm));
(C->ZJm)=((T0*)n);}Z3K2(ZjG,Z1G(101,"\'expanded\' type marks are deprecated, and will not be suported in SE 2. Use expanded classes instead."));
}else{ZWJ2(C,Z1G(40,"Must find a class type after \"expanded\"."));}}else if(ZKJ2(C,ZKV)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(ZCL2(C)){{ZK1*n=((ZK1*)Zh(sizeof(*n)));*n=Zed;ZcW(n,ZjG,((C)->Zxm));(C->ZJm)=((T0*)n);}Z3K2(ZjG,Z1G(101,"\'reference\' type marks are deprecated, and will not be suported in SE 2. Use REFERENCE class instead."));
}else if((T6)(((T6)((ZlK2(C,((T3)'\133')))&&((T6)(ZuK2(C)))))&&((T6)(ZlK2(C,((T3)'\135')))))){ZwZ(&(((C)->ZEd)),ZjG);{T0*b1=Z1G(9,"REFERENCE");
Zmx((T7*)(ZyZ),b1);}{Zq9*n=((Zq9*)Zh(sizeof(*n)));*n=Z3m;ZzZ(n,ZAZ(&(((C)->ZEd))),ZKM2(1,((C)->ZJm)));(C->ZJm)=((T0*)n);}}else{ZWJ2(C,Z1G(50,"Bad formal argument for predefined type REFERENCE."));
}}else if(ZKJ2(C,ZTT)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZCL2(C)){(C->ZJm)=(((void)((ZS*)(ZCM2()))),Z4N(ZjG,((C)->Zxm)));
}else{ZWJ2(C,Z1G(40,"Must find a class type after \"separate\"."));}}else if(ZKJ2(C,ZYH)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(ZLM2(C,(T6)(0))){{ZP8*n=((ZP8*)Zh(sizeof(*n)));*n=Zil;ZN82(n,ZjG,((C)->ZDm));(C->ZJm)=((T0*)n);}}else if(Z5K2(C)){{ZN8*n=((ZN8*)Zh(sizeof(*n)));
*n=Zhl;Zs82(n,ZjG,ZKE2(&(((C)->ZEd))));(C->ZJm)=((T0*)n);}}else{ZWJ2(C,Z1G(45,"Expected constant for BIT_N type declaration."));}}else
if(ZMM2(C)){(C->ZJm)=((C)->ZCm);}else if(ZCL2(C)){(C->ZJm)=((C)->Zxm);}else{R=((T6)(0));}return R;}T6 ZNM2(ZQ9*C,T3 a1,T3 a2){T6 R=0;
(C->Z_e)=((C)->ZWe);(C->Z0f)=((C)->ZVe);if((((C)->_cc))==(a1)){ZMJ2(C);if((((C)->_cc))==(a2)){(C->_cc)=a1;(C->ZVe)=((C)->Z0f);}else{R=((T6)(1));
ZJJ2(C);}}return R;}T6 Z7M2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};if(ZKJ2(C,Zkp2)){R=((T6)(1));{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if((((C)->_cc))==(((T3)'\042'))){ZMJ2(C);}else{{ZQ9*C1=C;T0*b1=Z1G(38,"Character \'%\"\' inserted after \"infix\".");{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}if(Z9L2(C,ZjG)){}else if(ZaM2(C,(T6)(0))){}else{ZWJ2(C,Z1G(29,"Infix operator name expected."));}if(!(ZlK2(C,((T3)'\042')))){{ZQ9*C1=C;
T0*b1=Z1G(24,ZZq);{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}}return R;}void ZOM2(ZQ9*C){T0*Z3r1=Zo;T0*ZMK2=Zo;Z3r1=ZKE2(&(((C)->ZEd)));
{ZH8*n=((ZH8*)Zh(sizeof(*n)));*n=Zel;((((ZH8*)(n)))->ZCb)=(((((ZD8*)Z3r1))->ZCb));ZMK2=((T0*)n);}ZaK2(C,(T6)(1),ZMK2,Z3r1,Z9K2(C),(T6)(1));
}T6 ZMM2(ZQ9*C){T6 R=0;T0*ZPM2=Zo;T0*ZWF=Zo;T2 Zwa1=0;if((((C)->Zig))!=((void*)(Zo))){Zwa1=ZGs(1);while(!((T6)((R)||((T6)((Z3)((Zwa1)>(ZWx(((ZB*)((((Zha*)(((C)->Zig)))->ZZb)))))))))))
{ZPM2=ZXx(((ZB*)((((Zha*)(((C)->Zig)))->ZZb))),Zwa1);if(ZKJ2(C,(((T85*)(((((Z18*)ZPM2))->Zpc)))->Zse))){{T81 Zow;{T85*n=((T85*)Zh(sizeof(*n)));
*n=M85;Zu81(n,(((T85*)(((((Z18*)ZPM2))->Zpc)))->Zse),(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));ZWF=((T0*)n);}}{Zt8*n=((Zt8*)Zh(sizeof(*n)));
*n=Z7l;Z132(n,ZWF,ZPM2,Zwa1);(C->ZCm)=((T0*)n);}R=((T6)(1));}Zwa1=(Z3)(((Zwa1))+(ZGs(1)));}}return R;}T0*ZoP(ZQ9*C){T0*R=Zo;{T7*n=((T7*)Zh(sizeof(*n)));
*n=M7;Zwx(n,(T2)(ZGs(32)));R=((T0*)n);}while(!(Zzs(((C)->_cc)))){Zgt(((T7*)R),((C)->_cc));ZMJ2(C);}ZJJ2(C);return R;}T0*ZNK2(ZQ9*C){T0*R=Zo;
T0*ZQM2=Zo;T0*Z7Q=Zo;T0*ZRM2=Zo;if(!(ZVJ2(C))){ZWJ2(C,Z1G(47,"Bad external clause (manifest string expected)."));}ZnL2(C);ZRM2=((C)->Zzl);
((((T93*)(((T93*)ZRM2))))->ZXm)=((T6)(0));ZG22((ZT6*)(ZD22),ZRM2);if(ZJ22((ZT6*)(ZD22))){ZSM2(ZRM2);}else if(Z9G2((ZT6*)(ZD22),ZIv1)){
{ZE9*n=((ZE9*)Zh(sizeof(*n)));*n=Zem;((((ZE9*)(n)))->ZJc)=(ZRM2);Z7Q=((T0*)n);}}else if(Z9G2((ZT6*)(ZD22),ZTM2)){Z5G(((((T93*)ZRM2))->ZCb));
{T0*b1=Z1G(78,"Obsolete \"SmallEiffel\" keyword replaced with \"SmartEiffel\" (update your code).");Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));
{ZE9*n=((ZE9*)Zh(sizeof(*n)));*n=Zem;((((ZE9*)(n)))->ZJc)=(ZRM2);Z7Q=((T0*)n);}}else if(ZK22((ZT6*)(ZD22),ZUM2)){{Za1*n=((Za1*)Zh(sizeof(*n)));
*n=ZMc;((((Za1*)(n)))->ZJc)=(ZRM2);Z7Q=((T0*)n);}}else if(ZK22((ZT6*)(ZD22),ZVM2)){{ZW7*n=((ZW7*)Zh(sizeof(*n)));*n=Zwk;Zt22(n,ZRM2);
Z7Q=((T0*)n);}}else if(ZK22((ZT6*)(ZD22),ZWM2)){{Zw9*n=((Zw9*)Zh(sizeof(*n)));*n=Zam;((((Zw9*)(n)))->ZJc)=(ZRM2);Z7Q=((T0*)n);}}else{
ZSM2(ZRM2);}if(ZKJ2(C,ZaE2)){if(!(ZVJ2(C))){ZWJ2(C,Z1G(26,"Bad external alias clause."));}ZnL2(C);ZQM2=(((T93*)(((C)->Zzl)))->Zse);}R=ZhG2(&(((C)->ZLm)),Z7Q,ZQM2);
return R;}void ZXM2(T81 a1,T6 a2,T0*a3){T0*ZkD1=Zo;ZkD1=Z1G(30,"Right hand side expression of ");if(a2){Zmx(((T7*)ZkD1),Zlp2);}else{Zmx(((T7*)ZkD1),Zkp2);
}Zmx(((T7*)ZkD1),Z1G(2,ZBn));Zmx(((T7*)ZkD1),a3);Zmx(((T7*)ZkD1),Z1G(11,ZWq));Z5G(a1);{T0*b1=ZkD1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));
}T6 ZYM2(ZQ9*C){T6 R=0;R=((T6)(ZZM2(C)));if(R){Z_M2(C,((C)->Zym));}return R;}T0*Z0N2=Zo;int Z1N2=0;T0*ZUK2(void){if(Z1N2==0){Z1N2=1;{
{ZY9*n=((ZY9*)Zh(sizeof(*n)));*n=ZTm;Z0N2=((T0*)n);ZGF(n,(T2)(Zxt(256)));}}}return Z0N2;}T6 ZZM2(ZQ9*C){T6 R=0;R=((T6)(Z2N2(C)));if(R){
Z3N2(C,((C)->Zym));}return R;}T6 Z2N2(ZQ9*C){T6 R=0;R=((T6)(Z4N2(C)));if(R){Z5N2(C,((C)->Zym));}return R;}T6 Z4N2(ZQ9*C){T6 R=0;R=((T6)(Z6N2(C)));
if(R){Z7N2(C,((C)->Zym));}return R;}T6 ZcM2(ZQ9*C){T6 R=0;if(ZKJ2(C,ZCE2)){{T81 Zow;{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;ZvL(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));
(C->Zum)=((T0*)n);}}R=((T6)(1));}else if(ZKJ2(C,ZjE2)){{T81 Zow;{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zml;ZwL(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));
(C->Zum)=((T0*)n);}}R=((T6)(1));}return R;}T6 Z6N2(ZQ9*C){T6 R=0;R=((T6)(Z8N2(C)));if(R){Z9N2(C,((C)->Zym));}return R;}T6 Z8N2(ZQ9*C){
T6 R=0;R=((T6)(ZaN2(C)));if(R){ZbN2(C,((C)->Zym));}return R;}T0*ZcN2=Zo;int ZdN2=0;T0*Z8L2(void){if(ZdN2==0){ZdN2=1;{{T95*n=((T95*)Zh(sizeof(*n)));
*n=M95;ZcN2=((T0*)n);Zya2(n,(T2)(ZGs(0)));}}}return ZcN2;}T6 ZaN2(ZQ9*C){T6 R=0;R=((T6)(ZeN2(C)));if(R){ZfN2(C,((C)->Zym));}return R;
}T6 ZeN2(ZQ9*C){T6 R=0;R=((T6)(ZgN2(C)));if(R){ZhN2(C,((C)->Zym));}return R;}T6 ZgN2(ZQ9*C){T6 R=0;T0*ZiN2=Zo;T0*ZjN2=Zo;T81 ZjG={Zo,Zo,0};
T2 Z7Q=0;T2 ZXw=0;if(ZKJ2(C,ZVI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZgN2(C)){{Zw3*n=((Zw3*)Zh(sizeof(*n)));
*n=ZAe;Zvc1(n,ZjG,((C)->Zym));(C->Zym)=((T0*)n);}R=((T6)(1));}else{ZXM2(ZjG,(T6)(1),ZVI);}}else if(ZlK2(C,((T3)'\053'))){Z7Q=((C)->Z_e);
ZXw=((C)->Z0f);if(ZzK2(C,ZGs(0))){(C->Zym)=((C)->ZIm);R=((T6)(1));}else if(ZLM2(C,(T6)(0))){(C->Zym)=((C)->ZDm);R=((T6)(1));}else{{T81
Zow;ZjG=(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow));}if(ZgN2(C)){{ZA9*n=((ZA9*)Zh(sizeof(*n)));*n=Zcm;Zvg2(n,ZjG,((C)->Zym));(C->Zym)=((T0*)n);}R=((T6)(1));
}else{ZXM2(ZjG,(T6)(1),ZtG);}}}else if(ZlK2(C,((T3)'\055'))){Z7Q=((C)->Z_e);ZXw=((C)->Z0f);if(ZzK2(C,ZGs(-1))){(C->Zym)=((C)->ZIm);R=((T6)(1));
}else if(ZLM2(C,(T6)(1))){(C->Zym)=((C)->ZDm);R=((T6)(1));}else{{T81 Zow;ZjG=(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow));}if(ZgN2(C)){{Za7*n=((Za7*)Zh(sizeof(*n)));
*n=ZKj;ZlP1(n,ZjG,((C)->Zym));(C->Zym)=((T0*)n);}R=((T6)(1));}else{ZXM2(ZjG,(T6)(1),ZuG);}}}else if(ZDL2(C,(T6)(1))){ZiN2=((C)->ZAm);
if(ZgN2(C)){{Zq3*n=((Zq3*)Zh(sizeof(*n)));*n=Zze;ZZb1(n,((C)->Zym),ZiN2);ZjN2=((T0*)n);}(C->Zym)=ZjN2;R=((T6)(1));}else{ZXM2(((((ZD8*)ZiN2))->ZCb),(T6)(1),((((ZD8*)ZiN2))->Zse));
}}else{R=((T6)(ZkN2(C)));}return R;}T6 ZkN2(ZQ9*C){T6 R=0;if(ZKJ2(C,ZtE2)){if(!(((C)->Zqm))){{T81 Zow;ZmG2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z1G(60,"Expression \"old\" can be used in ensure clause only (VAOL.1)."));
}}if(ZFM2(C)){{Zs3*n=((Zs3*)Zh(sizeof(*n)));*n=Zkf;((((Zs3*)(n)))->Z1d)=(((C)->Zym));(C->Zym)=((T0*)n);}R=((T6)(1));}else{ZWJ2(C,Z1G(32,"Expression expected after \"old\"."));
}}else{R=((T6)(ZFM2(C)));}return R;}T6 Z9M2(ZQ9*C){T6 R=0;if(ZKJ2(C,ZVI)){{T81 Zow;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Zwc1(n,ZVI,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));
(C->ZAm)=((T0*)n);}}R=((T6)(1));}else if(ZlK2(C,((T3)'\053'))){{T81 Zow;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Zwc1(n,ZtG,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));
(C->ZAm)=((T0*)n);}}R=((T6)(1));}else if(ZlK2(C,((T3)'\055'))){{T81 Zow;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Zwc1(n,ZuG,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));
(C->ZAm)=((T0*)n);}}R=((T6)(1));}return R;}T6 ZJK2(ZQ9*C){T6 R=0;if((T6)((ZlK2(C,((T3)'\050')))&&((T6)(ZhK2(C))))){R=((T6)(1));if(ZlK2(C,((T3)'\051'))){
ZaK2(C,(T6)(1),((C)->Zym),Zo,Zo,(T6)(0));}else{ZWJ2(C,Z1G(13,"\')\' expected."));}}else if(ZSL2(C,(T6)(1))){R=((T6)(1));}else if(Z5K2(C)){
R=((T6)(1));if(ZaL2(C,((T3)'\072'),((T3)'\075'))){ZcK2(C,(T6)(1));}else if(ZaL2(C,((T3)'\077'),((T3)'\075'))){ZcK2(C,(T6)(0));}else if(ZeK2(C)){
ZaK2(C,(T6)(1),((C)->Zym),Zo,Zo,(T6)(1));}else if((T6)(((T6)((Z8K2(C))||((T6)(Z6K2(C)))))||((T6)(ZgK2(C))))){ZaK2(C,(T6)(1),((C)->Zym),Zo,Zo,(T6)(0));
}else{ZOM2(C);}}return R;}T0*ZTK2(ZQ9*C){T0*R=Zo;T81 ZjG={Zo,Zo,0};T0*ZqV=Zo;T2 Zdx=0;if(ZlK2(C,((T3)'\173'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}while(!((Z3)((Zdx)>(ZGs(3))))){{int z1=Zdx;switch(z1){case 0:if(ZOL2(C)){{Zo3*n=((Zo3*)Zh(sizeof(*n)));*n=Zye;((((Zo3*)(n)))->ZGd)=(((C)->Zwm));
ZqV=((T0*)n);}Zdx=ZGs(2);}else if(ZlK2(C,((T3)'\175'))){Zdx=ZGs(4);}else if((((C)->_cc))==(((T3)'\054'))){{ZQ9*C1=C;T0*b1=ZsL2;{T81 Zow;
Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}else{Zdx=ZGs(3);}break;case 1:if(ZOL2(C)){ZLb1(((Zo3*)ZqV),((C)->Zwm));
Zdx=ZGs(2);}else if((((C)->_cc))==(((T3)'\054'))){{ZQ9*C1=C;T0*b1=ZsL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));
}else if((((C)->_cc))==(((T3)'\175'))){{ZQ9*C1=C;T0*b1=ZlN2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\175'))));
Zdx=ZGs(4);}else{Zdx=ZGs(3);}break;case 2:if(ZlK2(C,((T3)'\054'))){Zdx=ZGs(1);}else if(ZlK2(C,((T3)'\175'))){Zdx=ZGs(4);}else if(ZOL2(C)){
Z3K2((((T85*)(((C)->Zwm)))->ZCb),ZtL2);ZLb1(((Zo3*)ZqV),((C)->Zwm));}else{Zdx=ZGs(3);}break;default:;ZWJ2(C,ZfL2);Zdx=ZGs(4);}}}{ZD*n=((ZD*)Zh(sizeof(*n)));
*n=Z0c;ZfG(n,ZjG,ZqV);R=((T0*)n);}}else{R=ZbK2();}return R;}T6 ZhL2(ZQ9*C){T6 R=0;T2 ZmN2=0;T6 Zd22=0;T6 ZnN2=0;T6 ZoN2=0;if(ZHs(((C)->_cc))){
ZmN2=((C)->ZVe);ZnN2=((T6)(1));{T81 Zow;ZwZ(&(((C)->ZEd)),(*(Zow=ZYJ2(C,((C)->ZWe),ZmN2),&Zow)));}{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);
}while(!(Zd22)){ZMJ2(C);{int z1=((C)->_cc);switch(z1){case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:case
106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case
121:case 122:{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}break;case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case
74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:case 90:ZoN2=((T6)(1));
{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}break;case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 95:ZnN2=((T6)(0));
{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}break;default:;Zd22=((T6)(1));}}}if((T6)((ZnN2)&&((T6)(Z9E2(&(((C)->ZEd))))))){(C->_cc)=(((((T7*)ZyZ))->ZUb))[ZGs(0)];
(C->ZVe)=ZmN2;}else{R=((T6)(1));ZJJ2(C);if(ZoN2){if(!(((C)->Zlm))){Z3K2(((((C)->ZEd)).ZCb),ZpN2);}}}}return R;}T0*ZJL2(ZQ9*C){T0*R=Zo;
if(Z5K2(C)){if(Z8K2(C)){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Zym)),&Zow)));}{T0*b1=Z1G(35,"Current is not a writable variable.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}else if(ZeK2(C)){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Zym)),&Zow)));}{T0*b1=ZqN2;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else
if((T6)((Z6K2(C))||((T6)(ZgK2(C))))){R=((C)->Zym);}else{R=ZKE2(&(((C)->ZEd)));}}else{ZWJ2(C,ZrN2);}return R;}T6 ZaM2(ZQ9*C,T6 a1){T6 R=0;
T6 Zd22=0;T2 Z7Q=0;T2 ZXw=0;{int z1=((C)->_cc);switch(z1){case 35:case 38:case 42:case 43:case 45:case 47:case 60:case 61:case 62:case
64:case 92:case 124:case 126:Z7Q=((C)->ZWe);ZXw=((C)->ZVe);((((T7*)((T7*)(ZPK2))))->Zdc)=(ZGs(0));R=((T6)(1));Zgt((T7*)(ZPK2),((C)->_cc));
ZMJ2(C);while(!(Zd22)){{int z2=((C)->_cc);switch(z2){case 46:case 63:case 123:case 125:R=((T6)(0));Zgt((T7*)(ZPK2),((C)->_cc));ZMJ2(C);
break;case 35:case 38:case 42:case 43:case 45:case 47:case 60:case 61:case 62:case 64:case 92:case 94:case 124:case 126:R=((T6)(1));Zgt((T7*)(ZPK2),((C)->_cc));
ZMJ2(C);break;default:;Zd22=((T6)(1));}}}if(!(R)){{T81 Zow;Z5G((*(Zow=ZYJ2(C,((C)->ZWe),((C)->ZVe)),&Zow)));}{T0*b1=ZsN2;Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}if((T6)((((((T7*)(ZPK2))->Zdc))==(ZGs(1)))&&((T6)((((((T7*)(ZPK2))->ZUb))[ZGs(0)])==(((T3)'\075')))))){{T81 Zow;Z5G((*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)));
}{T0*b1=Z1G(92,"The basic = operator cannot be redefined. (This is a hard-coded builtin that we must trust.)");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));
}ZEL2(C,(T6)(a1),Z7Q,ZXw);break;}}return R;}void Z_J2(ZQ9*C){T0*ZIX=Zo;T0*ZrK2=Zo;T0*ZsK2=Zo;T0*ZqV=Zo;T2 Zwa1=0;T2 Zdx=0;while(!((Z3)((Zdx)>(ZGs(4)))))
{{int z1=Zdx;switch(z1){case 0:if(Z5K2(C)){ZIX=ZJE2(&(((C)->ZEd)));Zdx=ZGs(1);if((((C)->ZFb))!=((void*)(Zo))){Zwa1=Z9a1((Zz6*)(((C)->ZFb)),((((Zn4*)ZIX))->Zse));
if((Z3)((Zwa1)>(ZGs(0)))){Z5G(((((Zn4*)ZIX))->ZCb));ZmG2((((Zi1*)(Zky(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie))),Zwa1)))->ZCb),ZtN2);}}}else
if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\073')))))){{ZQ9*C1=C;T0*b1=ZtK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}(C->_ok)=((T6)((T6)((ZlK2(C,((T3)'\054')))||((T6)(ZlK2(C,((T3)'\073')))))));}else{Zdx=ZGs(5);}break;case 1:if(ZlK2(C,((T3)'\072'))){
if((ZrK2)!=((void*)(Zo))){ZQy(((Zv8*)ZrK2),ZIX);ZIX=Zo;}Zdx=ZGs(3);}else{if((((C)->_cc))==(((T3)'\073'))){{ZQ9*C1=C;T0*b1=ZuN2;{T81 Zow;
Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));}else{(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}if((ZrK2)==((void*)(Zo))){
{Zv8*n=((Zv8*)Zh(sizeof(*n)));*n=Z8l;ZSy(n,(T2)(ZGs(2)),(T2)(ZGs(1)));ZrK2=((T0*)n);}}ZQy(((Zv8*)ZrK2),ZIX);ZIX=Zo;Zdx=ZGs(2);}break;
case 2:if(Z5K2(C)){ZIX=ZJE2(&(((C)->ZEd)));Zdx=ZGs(1);if((((C)->ZFb))!=((void*)(Zo))){Zwa1=Z9a1((Zz6*)(((C)->ZFb)),((((Zn4*)ZIX))->Zse));
if((Z3)((Zwa1)>(ZGs(0)))){Z5G(((((Zn4*)ZIX))->ZCb));Z5G((((Zi1*)(Zky(((Zl2*)((((Zz6*)(((C)->ZFb)))->Zie))),Zwa1)))->ZCb));{T0*b1=ZtN2;
Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}}}else if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\073')))))){{ZQ9*C1=C;
T0*b1=ZtK2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)((T6)((ZlK2(C,((T3)'\054')))||((T6)(ZlK2(C,((T3)'\073')))))));}else{
Zdx=ZGs(6);}break;case 3:if(ZuK2(C)){if((ZrK2)!=((void*)(Zo))){{ZI3*n=((ZI3*)Zh(sizeof(*n)));*n=ZLe;Z4d1(n,ZrK2,((C)->ZJm));ZsK2=((T0*)n);
}ZrK2=Zo;}else{{Z_*n=((Z_*)Zh(sizeof(*n)));*n=Zqc;ZiO(n,ZIX,((C)->ZJm));ZsK2=((T0*)n);}ZIX=Zo;}if((ZqV)==((void*)(Zo))){{Z9a*n=((Z9a*)Zh(sizeof(*n)));
*n=Z7n;Zbz(n,(T2)(ZGs(2)),(T2)(ZGs(1)));ZqV=((T0*)n);}}ZvK2(ZqV,ZsK2);Zdx=ZGs(4);}else{Zdx=ZGs(6);}break;default:;if((((C)->_cc))==(((T3)'\054'))){
{ZQ9*C1=C;T0*b1=ZvN2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));Zdx=ZGs(0);}else{(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));
Zdx=ZGs(0);}}}}if((Zdx)==(ZGs(6))){ZWJ2(C,Z1G(24,"Bad local variable list."));}else if((ZqV)!=((void*)(Zo))){{Ze3*n=((Ze3*)Zh(sizeof(*n)));
*n=Zje;{Ze3*C1=n;T0*b1=ZqV;Zd91(C1,b1);}(C->ZKb)=((T0*)n);}((((Zy7*)(&(((C)->ZLm)))))->ZKb)=(((C)->ZKb));}}void ZbM2(ZQ9*C){{ZD8*n=((ZD8*)Zh(sizeof(*n)));
*n=Zfn;Z9p2(n,((C)->ZAm));(C->ZAm)=((T0*)n);}}void ZIL2(T0*a1){if(ZI61(a1)){if(Zh_(a1)){}else{{T81 Zow;Z3K2((*(Zow=ZrP(a1),&Zow)),Z1G(58,"Explicit creation/create type mark should not be anchored."));
}}}}void ZuP(ZQ9*C){(C->Zmm)=((T6)(0));ZA72((T77*)(ZIJ2()));}T6 ZeM2(ZQ9*C){T6 R=0;T2 Z7Q=0;T2 ZXw=0;Z7Q=((C)->ZWe);ZXw=((C)->ZVe);if(ZlK2(C,((T3)'\053'))){
if(ZLM2(C,(T6)(0))){R=((T6)(1));}else{ZAK2(C,Z7Q,ZXw);}}else if(ZlK2(C,((T3)'\055'))){if(ZLM2(C,(T6)(1))){R=((T6)(1));}else{ZAK2(C,Z7Q,ZXw);
}}else if(ZLM2(C,(T6)(0))){R=((T6)(1));}return R;}T6 ZNL2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};T0*Z7p1=Zo;T0*ZwN2=Zo;T0*ZyC2=Zo;T0*ZxN2=Zo;
R=((T6)(1));if(ZKJ2(C,ZVH)){{T81 Zow;{Z83*n=((Z83*)Zh(sizeof(*n)));*n=Zge;ZaP(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);
}}}else if(ZKJ2(C,ZWH)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if((T6)(((T6)((ZlK2(C,((T3)'\133')))&&((T6)(ZuK2(C)))))&&((T6)(ZlK2(C,((T3)'\135')))))){
{Z67*n=((Z67*)Zh(sizeof(*n)));*n=ZHj;Zme1(n,ZjG,((C)->ZJm));(C->Zsm)=((T0*)n);}}else{ZWJ2(C,Z1G(33,"Bad use of predefined type ARRAY."));
}}else if(ZKJ2(C,ZiI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if((T6)(((T6)((ZlK2(C,((T3)'\133')))&&((T6)(ZuK2(C)))))&&((T6)(ZlK2(C,((T3)'\135')))))){
{Z78*n=((Z78*)Zh(sizeof(*n)));*n=ZFk;ZE32(n,ZjG,((C)->ZJm));(C->Zsm)=((T0*)n);}}else{ZWJ2(C,Z1G(40,"Bad use of predefined type NATIVE_ARRAY."));
}}else if(ZKJ2(C,Z_H)){{T81 Zow;{Zh8*n=((Zh8*)Zh(sizeof(*n)));*n=ZKk;ZD31(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);
}}}else if(ZKJ2(C,Z1I)){{T81 Zow;{Z47*n=((Z47*)Zh(sizeof(*n)));*n=ZEj;ZZi1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);
}}}else if(ZKJ2(C,Z4I)){{T81 Zow;{ZT8*n=((ZT8*)Zh(sizeof(*n)));*n=Zkl;ZH92(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z4I);(C->Zsm)=((T0*)n);
}}}else if(ZKJ2(C,ZsI)){{T81 Zow;{ZT8*n=((ZT8*)Zh(sizeof(*n)));*n=Zkl;ZH92(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),ZsI);(C->Zsm)=((T0*)n);
}}}else if(ZKJ2(C,ZmI)){{T81 Zow;ZmL2(C,((T0*)ZSU1((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)))));}}else if(ZKJ2(C,Z0I)){{T81 Zow;ZmL2(C,((T0*)Zgr2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)))));
}}else if(ZKJ2(C,Z2I)){{T81 Zow;ZmL2(C,((T0*)ZQN1((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)))));}}else if(ZKJ2(C,ZgI)){{T81 Zow;ZmL2(C,((T0*)Z3q2((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)))));
}}else if(ZKJ2(C,ZtI)){{T81 Zow;ZmL2(C,((T0*)ZvG1((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),ZrI)));}}else if(ZKJ2(C,Z5I)){{T81 Zow;
ZmL2(C,((T0*)ZG92((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),Z4I)));}}else if(ZKJ2(C,ZeI)){{T81 Zow;{Zg5*n=((Zg5*)Zh(sizeof(*n)));*n=Zjh;
Z3q1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZbI)){{T81 Zow;{Zg5*n=((Zg5*)Zh(sizeof(*n)));
*n=Zjh;ZFo1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZcI)){{T81 Zow;{Zg5*n=((Zg5*)Zh(sizeof(*n)));
*n=Zjh;ZGo1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZdI)){{T81 Zow;{Zg5*n=((Zg5*)Zh(sizeof(*n)));
*n=Zjh;ZHo1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZfI)){{T81 Zow;{Zg5*n=((Zg5*)Zh(sizeof(*n)));
*n=Zjh;ZIo1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZaI)){{T81 Zow;{Zg5*n=((Zg5*)Zh(sizeof(*n)));
*n=Zjh;Zgq2(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZjI)){{T81 Zow;{ZZ6*n=((ZZ6*)Zh(sizeof(*n)));
*n=ZAj;Zih1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZlI)){{T81 Zow;{ZA7*n=((ZA7*)Zh(sizeof(*n)));
*n=Z8k;ZDe1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZrI)){{T81 Zow;{Zl6*n=((Zl6*)Zh(sizeof(*n)));
*n=ZZi;ZwG1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),ZrI);(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZqI)){{T81 Zow;{Zl6*n=((Zl6*)Zh(sizeof(*n)));
*n=ZZi;ZwG1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),ZqI);(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZvI)){{T81 Zow;{ZF6*n=((ZF6*)Zh(sizeof(*n)));
*n=Zgj;ZFI1(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));(C->Zsm)=((T0*)n);}}}else if(ZKJ2(C,ZyI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(ZlK2(C,((T3)'\133'))){if((((C)->_cc))==(((T3)'\135'))){{ZQ9*C1=C;T0*b1=ZQL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}if(ZlK2(C,((T3)'\135'))){
}}else{{ZY*n=((ZY*)Zh(sizeof(*n)));*n=Zoc;Z7y(n,(T2)(ZGs(4)),(T2)(ZGs(1)));Z7p1=((T0*)n);}while(!(ZlK2(C,((T3)'\135')))){if(ZuK2(C)){
Z5y(((ZY*)Z7p1),((C)->ZJm));if(!(ZlK2(C,((T3)'\054')))){if((((C)->_cc))!=(((T3)'\135'))){{ZQ9*C1=C;T0*b1=ZtL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}}}else{{T81 Zow;Z5G((*(Zow=ZnG2(C),&Zow)));}{T0*b1=Z1G(32,"Incorrect TUPLE (type expected).");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));
}}}}{Zw7*n=((Zw7*)Zh(sizeof(*n)));*n=Z6k;ZCf1(n,ZjG,Z7p1);(C->Zsm)=((T0*)n);}}else if(ZKJ2(C,ZuI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(!(ZlK2(C,((T3)'\133')))){ZWJ2(C,ZyN2);}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZwN2=((C)->ZJm);if(!(ZlK2(C,((T3)'\054')))){{ZQ9*C1=C;T0*b1=ZtL2;
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZyC2=((C)->ZJm);if(!(ZlK2(C,((T3)'\135')))){ZWJ2(C,ZzN2);}{Z1a*n=((Z1a*)Zh(sizeof(*n)));
*n=ZVm;{Z1a*C1=n;T81 b1=ZjG;T0*b2=ZwN2;T0*b3=ZyC2;Z_M1(C1,ZoI,b1,b2,b3);}(C->Zsm)=((T0*)n);}}else if(ZKJ2(C,ZoI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(!(ZlK2(C,((T3)'\133')))){ZWJ2(C,ZyN2);}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZwN2=((C)->ZJm);if(!(ZlK2(C,((T3)'\054')))){{ZQ9*C1=C;T0*b1=ZtL2;
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZyC2=((C)->ZJm);if(!(ZlK2(C,((T3)'\135')))){ZWJ2(C,ZzN2);}{Z1a*n=((Z1a*)Zh(sizeof(*n)));
*n=ZVm;{Z1a*C1=n;T81 b1=ZjG;T0*b2=ZwN2;T0*b3=ZyC2;Z_M1(C1,ZoI,b1,b2,b3);}(C->Zsm)=((T0*)n);}}else if(ZKJ2(C,ZnI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(!(ZlK2(C,((T3)'\133')))){ZWJ2(C,ZyN2);}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZwN2=((C)->ZJm);if(!(ZlK2(C,((T3)'\054')))){{ZQ9*C1=C;T0*b1=ZtL2;
{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZyC2=((C)->ZJm);if(!(ZlK2(C,((T3)'\135')))){ZWJ2(C,ZzN2);}{Zm7*n=((Zm7*)Zh(sizeof(*n)));
*n=Z0k;Z0N1(n,ZjG,ZwN2,ZyC2,Zo);(C->Zsm)=((T0*)n);}}else if(ZKJ2(C,Z8I)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(!(ZlK2(C,((T3)'\133')))){
ZWJ2(C,ZyN2);}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZwN2=((C)->ZJm);if(!(ZlK2(C,((T3)'\054')))){{ZQ9*C1=C;T0*b1=ZtL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZyC2=((C)->ZJm);if(!(ZlK2(C,((T3)'\054')))){{ZQ9*C1=C;T0*b1=ZtL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}if(!(ZuK2(C))){ZWJ2(C,ZqM2);}ZxN2=((C)->ZJm);if(!(ZlK2(C,((T3)'\135')))){ZWJ2(C,ZzN2);}{Zm7*n=((Zm7*)Zh(sizeof(*n)));*n=Z0k;Z0N1(n,ZjG,ZwN2,ZyC2,ZxN2);
(C->Zsm)=((T0*)n);}}else{R=((T6)(0));}return R;}T6 ZwM2(ZQ9*C){T6 R=0;T0*ZMK2=Zo;T0*Z3r1=Zo;if(Z5K2(C)){R=((T6)(1));Z3r1=ZKE2(&(((C)->ZEd)));
{ZH8*n=((ZH8*)Zh(sizeof(*n)));*n=Zel;((((ZH8*)(n)))->ZCb)=(((((ZD8*)Z3r1))->ZCb));ZMK2=((T0*)n);}{ZU1*n=((ZU1*)Zh(sizeof(*n)));*n=Znd;
Z0Y(n,ZMK2,Z3r1);(C->Zym)=((T0*)n);}}else if(ZiL2(C)){R=((T6)(1));(C->Zym)=((C)->Zvm);}else if(ZeM2(C)){R=((T6)(1));(C->Zym)=((C)->ZDm);
}else if(ZVJ2(C)){R=((T6)(1));(C->Zym)=((C)->Zzl);}else{ZWJ2(C,ZAH);}return R;}void ZAN2(ZQ9*C){T0*ZPM2=Zo;T0*ZBN2=Zo;T0*ZCN2=Zo;T2 Zdx=0;
(C->Zig)=Zo;if(ZlK2(C,((T3)'\133'))){{T81 Zow;{Zha*n=((Zha*)Zh(sizeof(*n)));*n=Zbn;Z4p2(n,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));
(C->Zig)=((T0*)n);}}((((T87*)((T87*)(((C)->Zom)))))->Zig)=(((C)->Zig));while(!((Z3)((Zdx)>(ZGs(3))))){{int z1=Zdx;switch(z1){case 0:if(ZOL2(C)){
ZBN2=((C)->Zwm);Zdx=ZGs(1);}else{Zdx=ZGs(5);}break;case 1:if(ZaL2(C,((T3)'\055'),((T3)'\076'))){Zdx=ZGs(3);}else if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\135')))))){
{Z18*n=((Z18*)Zh(sizeof(*n)));*n=ZBk;ZY22(n,ZBN2,ZCN2);ZPM2=((T0*)n);}ZCN2=Zo;Z5p2((Zha*)(((C)->Zig)),ZPM2);{int z2=((C)->_cc);switch(z2){
case 44:Zdx=ZGs(0);break;default:;Zdx=ZGs(4);}}(C->_ok)=((T6)(ZlK2(C,((C)->_cc))));}else{Zdx=ZGs(5);}break;case 2:if((T6)(((((C)->_cc))==(((T3)'\054')))||((T6)((((C)->_cc))==(((T3)'\135')))))){
{Z18*n=((Z18*)Zh(sizeof(*n)));*n=ZBk;ZY22(n,ZBN2,ZCN2);ZPM2=((T0*)n);}ZCN2=Zo;Z5p2((Zha*)(((C)->Zig)),ZPM2);{int z2=((C)->_cc);switch(z2){
case 44:Zdx=ZGs(0);break;default:;Zdx=ZGs(4);}}(C->_ok)=((T6)(ZlK2(C,((C)->_cc))));}else{Zdx=ZGs(5);}break;default:;if(ZMM2(C)){ZCN2=((C)->ZCm);
Zdx=ZGs(2);}else if(ZCL2(C)){ZCN2=((C)->Zxm);Zdx=ZGs(2);}else{ZWJ2(C,Z1G(31,"Constraint Class name expected."));Zdx=ZGs(5);}}}}{int z1=Zdx;
switch(z1){case 4:if((ZWx(((ZB*)((((Zha*)(((C)->Zig)))->ZZb)))))==(ZGs(0))){Z5G((((Zha*)(((C)->Zig)))->ZCb));{T0*b1=Z1G(36,"Empty formal generic list (deleted).");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));(C->Zig)=Zo;((((T87*)((T87*)(((C)->Zom)))))->Zig)=(Zo);}break;default:;}}}}T6 ZgK2(ZQ9*C){T6 R=0;
T2 Zwa1=0;if((((C)->ZKb))!=((void*)(Zo))){Zwa1=ZR81((Ze3*)(((C)->ZKb)),Z4E2(&(((C)->ZEd))));if((Z3)((Zwa1)>(ZGs(0)))){(C->Zym)=ZIE2(&(((C)->ZEd)),((C)->ZKb),Zwa1);
R=((T6)(1));}}return R;}void ZDN2(ZQ9*C,T2 a1,T2 a2){T1 ZbJ2=0;T11 ZUs=0;T6 Zd22=0;T6 Zix=0;ZMJ2(C);{int z1=((C)->_cc);switch(z1){case
48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:ZUs=(T11)(ZJs(((C)->_cc)));break;case 56:case 57:case 65:case 66:case 67:case
68:case 69:case 70:case 97:case 98:case 99:case 100:case 101:case 102:Zix=((T6)(1));ZUs=(T11)((Z1)(((ZQs(((C)->_cc))))-(ZGs(8))));break;
default:;ZWJ2(C,Z1G(27,"Hexadecimal digit expected."));}}ZbJ2=ZGs(1);while(!(Zd22)){ZMJ2(C);if(ZBs(((C)->_cc))){ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(16)))))+((T11)(ZQs(((C)->_cc)))));
ZbJ2=(Z1)(((ZbJ2))+(ZGs(1)));}else{Zd22=((T6)(1));}}{int z1=ZbJ2;switch(z1){case 2:case 4:case 8:case 16:break;default:;{T0*b1=Z1G(68,"Incorrect hexadecimal notation. Wrong number of hexadecimal digits (");
Zmx((T7*)(Z2G),b1);}{T2 b1=(T2)(ZbJ2);Z6t(b1,Z2G);}ZWJ2(C,Z1G(289," digits). You must use exactely 2, 4, 8 or 16 digits only. A 2 digits value denote an INTEGER_8, a 4 digits value denote an INTEGER_16, a 8 digits value denote an INTEGER_32, and, finally, a 16 digits value denote an INTEGER_64. (See examples in file \"SmartEiffel/tutorial/hexadecimal.e\".)"));
}}if(ZHs(((C)->_cc))){ZWJ2(C,Z1G(47,"Separator expected to end hexadecimal notation."));}{T81 Zow;{Zw1*n=((Zw1*)Zh(sizeof(*n)));*n=ZQl;
Z2p1(n,(T6)(Zix),ZbJ2,ZUs,(*(Zow=ZYJ2(C,a1,a2),&Zow)));(C->ZDm)=((T0*)n);}}ZJJ2(C);}T0*ZiM2(void){if(ZJn1==0){ZJn1=1;{{T42*n=((T42*)Zh(sizeof(*n)));
*n=M42;ZIn1=((T0*)n);ZK_(n);}}}return ZIn1;}T6 ZLM2(ZQ9*C,T6 a1){T6 R=0;T2 Zdx=0;T2 Z7Q=0;T2 ZXw=0;T11 ZUs=0;T6 ZEN2=0;T6 ZFN2=0;if(Zys(((C)->_cc))){
Z7Q=((C)->ZWe);ZXw=((C)->ZVe);ZUs=(T11)(-(ZEs(((C)->_cc))));while(!((Z3)((Zdx)>(ZGs(7))))){ZMJ2(C);{int z1=Zdx;switch(z1){case 0:{int
z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(10)))))-((T11)(ZEs(((C)->_cc)))));
Zdx=ZGs(1);break;case 95:Zdx=ZGs(4);break;case 120:if((ZUs)==(ZGs(0))){ZFN2=((T6)(1));}Zdx=ZGs(8);break;default:;Zdx=ZGs(8);}}break;case
1:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(10)))))-((T11)(ZEs(((C)->_cc)))));
Zdx=ZGs(2);break;case 95:Zdx=ZGs(4);break;default:;Zdx=ZGs(8);}}break;case 2:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case
51:case 52:case 53:case 54:case 55:case 56:case 57:ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(10)))))-((T11)(ZEs(((C)->_cc)))));Zdx=ZGs(3);break;case
95:Zdx=ZGs(4);break;default:;Zdx=ZGs(8);}}break;case 3:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:
case 54:case 55:case 56:case 57:ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(10)))))-((T11)(ZEs(((C)->_cc)))));break;case 95:ZWJ2(C,ZlM2);break;default:;
Zdx=ZGs(8);}}break;case 4:ZEN2=((T6)(1));{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:
case 56:case 57:ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(10)))))-((T11)(ZEs(((C)->_cc)))));Zdx=ZGs(5);break;default:;ZWJ2(C,ZlM2);}}break;case 5:
{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(10)))))-((T11)(ZEs(((C)->_cc)))));
Zdx=ZGs(6);break;default:;ZWJ2(C,ZlM2);}}break;case 6:{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case
54:case 55:case 56:case 57:ZUs=(Z5)((((Z5)(((ZUs))*(ZGs(10)))))-((T11)(ZEs(((C)->_cc)))));Zdx=ZGs(7);break;default:;ZWJ2(C,ZlM2);}}break;
default:;{int z2=((C)->_cc);switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZWJ2(C,ZlM2);break;
case 95:Zdx=ZGs(4);break;default:;Zdx=ZGs(8);}}}}}if(ZFN2){R=((T6)(1));ZDN2(C,Z7Q,ZXw);}else if(ZHs(((C)->_cc))){ZAK2(C,Z7Q,ZXw);}else{
R=((T6)(1));ZJJ2(C);{T81 Zow;{Zw1*n=((Zw1*)Zh(sizeof(*n)));*n=ZQl;ZJo1(n,(T6)(ZEN2),(T6)(a1),ZUs,(*(Zow=ZYJ2(C,Z7Q,ZXw),&Zow)));(C->ZDm)=((T0*)n);
}}}}return R;}T6 ZgL2(ZQ9*C){T6 R=0;T2 ZmN2=0;T6 Zd22=0;if(ZHs(((C)->_cc))){ZmN2=((C)->ZVe);{T81 Zow;ZwZ(&(((C)->ZEd)),(*(Zow=ZYJ2(C,((C)->ZWe),ZmN2),&Zow)));
}{T3 b1=ZNs(((C)->_cc));Zgt((T7*)(ZyZ),b1);}while(!(Zd22)){ZMJ2(C);{int z1=((C)->_cc);switch(z1){case 97:case 98:case 99:case 100:case
101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:case 109:case 110:case 111:case 112:case 113:case 114:case 115:case
116:case 117:case 118:case 119:case 120:case 121:case 122:{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}break;case 48:case 49:case 50:case 51:
case 52:case 53:case 54:case 55:case 56:case 57:case 95:{T3 b1=((C)->_cc);Zgt((T7*)(ZyZ),b1);}break;case 65:case 66:case 67:case 68:case
69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:case 80:case 81:case 82:case 83:case 84:case 85:case
86:case 87:case 88:case 89:case 90:{T3 b1=ZNs(((C)->_cc));Zgt((T7*)(ZyZ),b1);}break;default:;Zd22=((T6)(1));}}}if(Z9E2(&(((C)->ZEd)))){
(C->_cc)=(((((T7*)ZyZ))->ZUb))[ZGs(0)];(C->ZVe)=ZmN2;}else{R=((T6)(1));ZJJ2(C);}}return R;}void ZEL2(ZQ9*C,T6 a1,T2 a2,T2 a3){T0*ZGN2=Zo;
ZGN2=(((void)((T27*)(ZNJ2()))),ZCG(ZPK2));if(a1){{T81 Zow;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;Zwc1(n,ZGN2,(*(Zow=ZYJ2(C,a2,a3),&Zow)));
(C->ZAm)=((T0*)n);}}}else{{T81 Zow;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,ZGN2,(*(Zow=ZYJ2(C,a2,a3),&Zow)));(C->ZAm)=((T0*)n);}}}
}void Z_M2(ZQ9*C,T0*a1){T0*ZHN2=Zo;T81 ZjG={Zo,Zo,0};if(ZKJ2(C,ZRI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZZM2(C)){
{Zk3*n=((Zk3*)Zh(sizeof(*n)));*n=Zue;Zqb1(n,a1,ZjG,((C)->Zym));ZHN2=((T0*)n);}Z_M2(C,ZHN2);}else{ZmG2(ZjG,Z1G(36,"Expression expected after \'implies\'."));
}}else{(C->Zym)=a1;}}void Z3N2(ZQ9*C,T0*a1){T0*ZIN2=Zo;T0*ZJN2=Zo;T0*ZKN2=Zo;T81 ZjG={Zo,Zo,0};if(ZKJ2(C,ZWI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(ZKJ2(C,ZN91)){if(Z2N2(C)){{ZU9*n=((ZU9*)Zh(sizeof(*n)));*n=ZOm;Z0n2(n,a1,ZjG,((C)->Zym));ZIN2=((T0*)n);}Z3N2(C,ZIN2);}else{ZXM2(ZjG,(T6)(0),ZXI);
}}else{if(Z2N2(C)){{ZZ2*n=((ZZ2*)Zh(sizeof(*n)));*n=Z7e;ZA71(n,a1,ZjG,((C)->Zym));ZJN2=((T0*)n);}Z3N2(C,ZJN2);}else{ZXM2(ZjG,(T6)(0),ZWI);
}}}else if(ZKJ2(C,ZvH)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z2N2(C)){{ZF*n=((ZF*)Zh(sizeof(*n)));*n=Z5c;ZtH(n,a1,ZjG,((C)->Zym));
ZKN2=((T0*)n);}Z3N2(C,ZKN2);}else{ZXM2(ZjG,(T6)(0),ZvH);}}else{(C->Zym)=a1;}}void Z5N2(ZQ9*C,T0*a1){T0*ZLN2=Zo;T0*ZMN2=Zo;T81 ZjG={Zo,Zo,0};
if(ZKJ2(C,ZBI)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZKJ2(C,ZBE2)){if(Z4N2(C)){{Z32*n=((Z32*)Zh(sizeof(*n)));
*n=Zud;ZKY(n,a1,ZjG,((C)->Zym));ZLN2=((T0*)n);}Z5N2(C,ZLN2);}else{ZXM2(ZjG,(T6)(0),ZCI);}}else{if(Z4N2(C)){{Z29*n=((Z29*)Zh(sizeof(*n)));
*n=ZCl;ZWa2(n,a1,ZjG,((C)->Zym));ZMN2=((T0*)n);}Z5N2(C,ZMN2);}else{ZXM2(ZjG,(T6)(0),ZBI);}}}else{(C->Zym)=a1;}}void Z7N2(ZQ9*C,T0*a1){
T0*ZNN2=Zo;T81 ZjG={Zo,Zo,0};if(ZlK2(C,((T3)'\075'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z6N2(C)){{ZH2*n=((ZH2*)Zh(sizeof(*n)));
*n=ZUd;ZLX(n,a1,ZjG,((C)->Zym));ZNN2=((T0*)n);}Z7N2(C,ZNN2);}else{ZXM2(ZjG,(T6)(0),ZQI);}}else if(ZaL2(C,((T3)'\057'),((T3)'\075'))){
{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z6N2(C)){{ZI9*n=((ZI9*)Zh(sizeof(*n)));*n=Zgm;Zcl2(n,a1,ZjG,((C)->Zym));
ZNN2=((T0*)n);}Z7N2(C,ZNN2);}else{ZXM2(ZjG,(T6)(0),ZUI);}}else if(ZaL2(C,((T3)'\074'),((T3)'\075'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(Z6N2(C)){{ZN2*n=((ZN2*)Zh(sizeof(*n)));*n=ZZd;Zr51(n,a1,ZjG,((C)->Zym));ZNN2=((T0*)n);}Z7N2(C,ZNN2);}else{ZXM2(ZjG,(T6)(0),ZyG);}
}else if(ZaL2(C,((T3)'\076'),((T3)'\075'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z6N2(C)){{ZF2*n=((ZF2*)Zh(sizeof(*n)));
*n=ZTd;Zv21(n,a1,ZjG,((C)->Zym));ZNN2=((T0*)n);}Z7N2(C,ZNN2);}else{ZXM2(ZjG,(T6)(0),ZAG);}}else if(ZlK2(C,((T3)'\074'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(Z6N2(C)){{ZR2*n=((ZR2*)Zh(sizeof(*n)));*n=Z1e;Z161(n,a1,ZjG,((C)->Zym));ZNN2=((T0*)n);}Z7N2(C,ZNN2);}else{ZXM2(ZjG,(T6)(0),ZxG);}
}else if(ZNM2(C,((T3)'\076'),((T3)'\076'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z6N2(C)){{ZL2*n=((ZL2*)Zh(sizeof(*n)));
*n=ZYd;ZR41(n,a1,ZjG,((C)->Zym));ZNN2=((T0*)n);}Z7N2(C,ZNN2);}else{ZXM2(ZjG,(T6)(0),ZzG);}}else{(C->Zym)=a1;}}void Z9N2(ZQ9*C,T0*a1){
T0*ZON2=Zo;T0*ZPN2=Zo;T81 ZjG={Zo,Zo,0};if(ZlK2(C,((T3)'\053'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z8N2(C)){
{Zo5*n=((Zo5*)Zh(sizeof(*n)));*n=Zoh;ZIp1(n,a1,ZjG,((C)->Zym));ZON2=((T0*)n);}Z9N2(C,ZON2);}else{ZXM2(ZjG,(T6)(0),ZtG);}}else if(ZlK2(C,((T3)'\055'))){
{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(Z8N2(C)){{ZU*n=((ZU*)Zh(sizeof(*n)));*n=Zic;ZoN(n,a1,ZjG,((C)->Zym));ZPN2=((T0*)n);
}Z9N2(C,ZPN2);}else{ZXM2(ZjG,(T6)(0),ZuG);}}else{(C->Zym)=a1;}}void ZbN2(ZQ9*C,T0*a1){T0*ZQN2=Zo;T0*ZRN2=Zo;T0*ZSN2=Zo;T0*ZTN2=Zo;T81
ZjG={Zo,Zo,0};if(ZlK2(C,((T3)'\052'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZaN2(C)){{ZF4*n=((ZF4*)Zh(sizeof(*n)));
*n=ZDg;ZCh1(n,a1,ZjG,((C)->Zym));ZQN2=((T0*)n);}ZbN2(C,ZQN2);}else{ZXM2(ZjG,(T6)(0),ZvG);}}else if(ZaL2(C,((T3)'\057'),((T3)'\057'))){
{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZaN2(C)){{Zu7*n=((Zu7*)Zh(sizeof(*n)));*n=Z4k;ZBU1(n,a1,ZjG,((C)->Zym));
ZRN2=((T0*)n);}ZbN2(C,ZRN2);}else{ZXM2(ZjG,(T6)(0),Z2J);}}else if(ZaL2(C,((T3)'\134'),((T3)'\134'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}if(ZaN2(C)){{Zx6*n=((Zx6*)Zh(sizeof(*n)));*n=Z9j;ZTH1(n,a1,ZjG,((C)->Zym));ZSN2=((T0*)n);}ZbN2(C,ZSN2);}else{ZXM2(ZjG,(T6)(0),ZEI);}
}else if(ZNM2(C,((T3)'\057'),((T3)'\075'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZaN2(C)){{Ze9*n=((Ze9*)Zh(sizeof(*n)));
*n=ZTl;Zrd2(n,a1,ZjG,((C)->Zym));ZTN2=((T0*)n);}ZbN2(C,ZTN2);}else{ZXM2(ZjG,(T6)(0),Z1J);}}else{(C->Zym)=a1;}}T0*ZXJ2(ZQ9*C){T0*R=Zo;
R=((C)->ZYe);(C->ZYe)=Zo;return R;}T0*ZtP(ZQ9*C){T0*R=Zo;if(ZpL2(C)){R=((C)->ZAm);}else{ZWJ2(C,ZzL2);}return R;}void ZSM2(T0*a1){Z5G(((((T93*)a1))->ZCb));
{T0*b1=Z1G(40,"Unknown external language specification.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZfN2(ZQ9*C,T0*a1){T81 ZjG={Zo,Zo,0};
if(ZlK2(C,((T3)'\136'))){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(ZeN2(C)){ZfN2(C,((C)->Zym));{ZO9*n=((ZO9*)Zh(sizeof(*n)));
*n=Zjm;Zsm2(n,a1,ZjG,((C)->Zym));(C->Zym)=((T0*)n);}}else{ZXM2(ZjG,(T6)(0),ZZI);}}else{(C->Zym)=a1;}}T6 ZHM2(ZQ9*C){T6 R=0;T81 ZjG={Zo,Zo,0};
T0*ZDq1=Zo;T0*ZGL2=Zo;T0*ZHL2=Zo;T0*ZWF2=Zo;if(ZKJ2(C,Z7_)){R=((T6)(1));{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}if(!(ZlK2(C,((T3)'\173')))){
ZWJ2(C,Z1G(37,"Bad create expression (\'\173""\' expected)."));}if(!(ZuK2(C))){ZWJ2(C,Z1G(39,Z2p));}ZDq1=((C)->ZJm);ZIL2(ZDq1);if(!(ZlK2(C,((T3)'\175')))){
ZWJ2(C,Z1G(37,"Bad create expression (\'\175""\' expected)."));}if(ZlK2(C,((T3)'\056'))){if(Z5K2(C)){ZGL2=ZKE2(&(((C)->ZEd)));{ZY5*n=((ZY5*)Zh(sizeof(*n)));
*n=Z1i;((((ZY5*)(n)))->Zlc)=(ZDq1);ZWF2=((T0*)n);}if((((C)->_cc))==(((T3)'\050'))){ZHL2=ZlL2(C,ZWF2,ZGL2,Z9K2(C));}else{{ZP6*n=((ZP6*)Zh(sizeof(*n)));
*n=Zmj;ZKs1(n,ZWF2,ZGL2);ZHL2=((T0*)n);}}}}{Zj2*n=((Zj2*)Zh(sizeof(*n)));*n=ZFd;ZUZ(n,ZjG,ZDq1,ZHL2);(C->Zym)=((T0*)n);}}return R;}void
ZhN2(ZQ9*C,T0*a1){T0*ZUN2=Zo;T0*ZVN2=Zo;if(ZDL2(C,(T6)(0))){ZUN2=((C)->ZAm);if(ZgN2(C)){{ZJ*n=((ZJ*)Zh(sizeof(*n)));*n=Z7c;Z_L(n,a1,ZUN2,((C)->Zym));
ZVN2=((T0*)n);}ZhN2(C,ZVN2);}else{ZXM2(((((ZD8*)ZUN2))->ZCb),(T6)(0),((((ZD8*)ZUN2))->Zse));}}else{(C->Zym)=a1;}}T6 ZCK2(ZQ9*C){T6 R=0;
T81 ZjG={Zo,Zo,0};T0*ZQJ2=Zo;T0*ZRJ2=Zo;if(ZKJ2(C,ZGv2)){{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}ZQJ2=ZXJ2(C);ZRJ2=ZZJ2(C);
if(!(ZKJ2(C,Z4v2))){Z5G(ZjG);ZWJ2(C,Z1G(50,"Keyword \"end\" expected at the end of check clause."));}if((T6)(((ZQJ2)!=((void*)(Zo)))||((T6)((ZRJ2)!=((void*)(Zo)))))){
{ZJ2*n=((ZJ2*)Zh(sizeof(*n)));*n=ZXd;Zk41(n,ZjG,ZQJ2,ZRJ2);(C->ZEm)=((T0*)n);}R=((T6)(1));}else if(ZlK2(C,((T3)'\073'))){}}return R;}
T0*ZWN2=Zo;int ZXN2=0;T0*ZOK2(void){if(ZXN2==0){ZXN2=1;{{Zu1*n=((Zu1*)Zh(sizeof(*n)));*n=Z6d;ZWN2=((T0*)n);Z3A(n,(T2)(ZGs(32)));}}}return
ZWN2;}T81 ZYJ2(ZQ9*C,T2 a1,T2 a2){T81 R={Zo,Zo,0};Z3m1(&R,a1,a2,((C)->Znm),((C)->Zom));return R;}void ZYN2(ZQ9*C,T81 a1,T0*a2){T0*ZqV=Zo;
while(!(!(ZAL2(C)))){if((ZqV)==((void*)(Zo))){{Zd8*n=((Zd8*)Zh(sizeof(*n)));*n=ZIk;ZsE(n,(T2)(ZGs(4)));ZqV=((T0*)n);}}ZrE(((Zd8*)ZqV),((C)->ZHm));
(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));((((Zr2*)((Zr2*)(((C)->ZHm)))))->Zqd)=(ZXJ2(C));}if((T6)(((a2)!=((void*)(Zo)))||((T6)((ZqV)!=((void*)(Zo)))))){
if((ZqV)==((void*)(Zo))){if(((((T87*)(((C)->Zom)))->Zjg))==((void*)(Zo))){((((T87*)((T87*)(((C)->Zom)))))->Zjg)=(a2);}else{Zjd1((T91*)((((T87*)(((C)->Zom)))->Zjg)),a2);
}}else{ZOn1((T87*)(((C)->Zom)),a1,a2,ZqV);}}}void ZmG2(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}void ZtM2(ZQ9*C){
T81 ZjG={Zo,Zo,0};T0*ZQJ2=Zo;T0*ZRJ2=Zo;T6 ZZN2=0;T6 Z_N2=0;T6 Z0O2=0;ZzM2(C);Z0O2=((T6)(1));while(!(!(Z0O2))){if(ZKJ2(C,ZfE2)){Zdn1((T87*)(((C)->Zom)));
}else if(ZKJ2(C,ZJw1)){Zwm1((T87*)(((C)->Zom)));}else if(ZKJ2(C,ZTT)){{T81 Zow;Z5G((*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));}{T0*b1=Z1G(91,"Compiler limitation: separate classes are not yet supported. Use separate entities instead.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));Zln1((T87*)(((C)->Zom)));}else{Z0O2=((T6)(0));}}((((T87*)((T87*)(((C)->Zom)))))->Zdg)=(ZXJ2(C));
if(!(ZKJ2(C,ZdE2))){ZWJ2(C,Z1G(25,"Keyword \"class\" expected."));}Z1O2(C);ZAN2(C);if(ZKJ2(C,ZsE2)){if(ZVJ2(C)){((((T93*)((T93*)(((C)->Zzl)))))->ZXm)=((T6)(1));
((((T87*)((T87*)(((C)->Zom)))))->Zkg)=(((C)->Zzl));}else{ZWJ2(C,Z1G(47,"Manifest string expected for \"obsolete\" clause."));}}((((T87*)((T87*)(((C)->Zom)))))->Zjg)=(ZXJ2(C));
if(ZKJ2(C,ZoE2)){Z_N2=((T6)(1));{T81 Zow;ZYN2(C,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)),ZXJ2(C));}}while(!(!((T6)((ZKJ2(C,ZeE2))||((T6)(ZKJ2(C,Z7_)))))))
{{T81 Zow;Z2L2(C,(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow)));}Z_N2=((T6)(0));}while(!(!(ZKJ2(C,ZkE2)))){ZQK2(C);Z_N2=((T6)(0));}ZZN2=((T6)(((C)->ZZe)));
(C->ZZe)=((T6)(0));if(ZKJ2(C,ZLi1)){Z_N2=((T6)(0));{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));}ZQJ2=ZXJ2(C);ZRJ2=ZZJ2(C);
Zfn1((T87*)(((C)->Zom)),ZjG,ZQJ2,ZRJ2);}if((T6)((ZKJ2(C,Z4v2))||((T6)(Z_N2)))){(C->_ok)=((T6)(ZlK2(C,((T3)'\073'))));((((T87*)((T87*)(((C)->Zom)))))->ZGe)=(ZXJ2(C));
if((((C)->_cc))!=(((T3)'\000'))){ZWJ2(C,Z1G(21,"End of text expected."));}}else{ZWJ2(C,Z1G(45,"Keyword \"end\" expected at the end of a class."));
}(C->ZZe)=((T6)(ZZN2));}T0*Z9K2(ZQ9*C){T0*R=Zo;T0*Z2O2=Zo;T0*Z6G2=Zo;if(ZlK2(C,((T3)'\050'))){while(!(!(ZpM2(C)))){if((Z2O2)==((void*)(Zo))){
Z2O2=((C)->Zym);}else{if((Z6G2)==((void*)(Zo))){{Z43*n=((Z43*)Zh(sizeof(*n)));*n=Zce;ZvA(n,(T2)(ZGs(4)));Z6G2=((T0*)n);}}ZsA(((Z43*)Z6G2),((C)->Zym));
}if((T6)((!(ZlK2(C,((T3)'\054'))))&&((T6)((((C)->_cc))!=(((T3)'\051')))))){{ZQ9*C1=C;T0*b1=ZtL2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);
}}}}if((Z2O2)==((void*)(Zo))){{ZQ9*C1=C;T0*b1=Z3O2;{T81 Zow;Z3K2((*(Zow=ZnG2(C1),&Zow)),b1);}}}else{{Za3*n=((Za3*)Zh(sizeof(*n)));*n=Z3j;
ZnH1(n,Z2O2,Z6G2);R=((T0*)n);}}if(!(ZlK2(C,((T3)'\051')))){ZWJ2(C,Z1G(35,"\')\' expected to end arguments list."));}}return R;}T6 ZhK2(ZQ9*C){
T6 R=0;T81 ZjG={Zo,Zo,0};T0*ZqV=Zo;if(ZaL2(C,((T3)'\074'),((T3)'\074'))){R=((T6)(1));{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}while(!(!(ZhK2(C)))){if((ZqV)==((void*)(Zo))){{Z43*n=((Z43*)Zh(sizeof(*n)));*n=Zce;ZvA(n,(T2)(ZGs(4)));ZqV=((T0*)n);}}ZsA(((Z43*)ZqV),((C)->Zym));
(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}if(!(ZaL2(C,((T3)'\076'),((T3)'\076')))){ZWJ2(C,Z1G(31,"End of manifest array expected."));}{Z_5*n=((Z_5*)Zh(sizeof(*n)));
*n=Z2i;ZfE1(n,ZjG,ZqV);(C->Zym)=((T0*)n);}}else if(ZlK2(C,((T3)'\133'))){R=((T6)(1));{T81 Zow;ZjG=(*(Zow=ZYJ2(C,((C)->Z_e),((C)->Z0f)),&Zow));
}while(!(!(ZhK2(C)))){if((ZqV)==((void*)(Zo))){{Z43*n=((Z43*)Zh(sizeof(*n)));*n=Zce;ZvA(n,(T2)(ZGs(4)));ZqV=((T0*)n);}}ZsA(((Z43*)ZqV),((C)->Zym));
(C->_ok)=((T6)(ZlK2(C,((T3)'\054'))));}if(!(ZlK2(C,((T3)'\135')))){ZWJ2(C,Z1G(33,"End of TUPLE expression expected."));}{Zm5*n=((Zm5*)Zh(sizeof(*n)));
*n=Znh;Z9p1(n,ZjG,ZqV);(C->Zym)=((T0*)n);}}else{R=((T6)(ZYM2(C)));}return R;}void Z1O2(ZQ9*C){T0*ZWF=Zo;T0*ZkL=Zo;ZkL=((C)->Zom);ZWF=((((T87*)ZkL))->Zpc);
{T81 Zow;((((T85*)(((T85*)ZWF))))->ZCb)=((*(Zow=ZYJ2(C,((C)->ZWe),((C)->ZVe)),&Zow)));}if(ZOL2(C)){if(((((T85*)(((C)->Zwm)))->Zse))!=((void*)(((((T85*)ZWF))->Zse)))){
Z5G((((T85*)(((C)->Zwm)))->ZCb));{T0*b1=ZOv1;Zmx((T7*)(Z2G),b1);}{T0*b1=((((T87*)ZkL))->Ztc);Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(26,"\" does not contain class \"");
Zmx((T7*)(Z2G),b1);}{T0*b1=((((T85*)ZWF))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Zk_;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}else{ZWJ2(C,Z4O2);
}if((ZjI)==((void*)(((((T85*)ZWF))->Zse)))){Z5G(((((T85*)ZWF))->ZCb));{T0*b1=Z1G(26,"Cannot write such a class.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}}
#ifdef __cplusplus
}
#endif

