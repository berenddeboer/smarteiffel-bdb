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
T6 ZDW(ZM1*C,T0*a1){T6 R=0;T2 Zet=0;if((((C)->ZZb))!=((void*)(Zo))){Zet=(((ZA3*)(((C)->ZZb)))->ZWb);while(!((T6)((R)||((T6)((Z3)((Zet)<(ZGs(0))))))))
{R=((T6)(Z5v((T7*)((((T93*)(((((ZA3*)(((C)->ZZb)))->ZUb))[Zet]))->Zse)),a1)));Zet=(Z3)(((Zet))-(ZGs(1)));}}return R;}void ZEW(T0*a1,T2
a2){if(((((T89*)(ZPM))->Zaf))==(ZGs(1))){ZFW(((ZX6*)a1),a2);}}void ZGW(ZM1*C){if((((C)->Zfd))!=((void*)(Zo))){ZHW((ZX6*)(((C)->Zfd)));
}}void ZIW(ZM1*C,T81 a1,T0*a2,T0*a3){(C->ZCb)=a1;(C->ZZb)=a2;(C->Zfd)=a3;}void ZJW(ZM1*C){if((((C)->Zfd))!=((void*)(Zo))){ZKW((ZX6*)(((C)->Zfd)));
}}T6 ZLW(ZM1*C){T6 R=0;if((((C)->Zfd))!=((void*)(Zo))){R=((T6)(ZMW((ZX6*)(((C)->Zfd)))));}return R;}void ZNW(ZM1*C,T0*a1){if((((C)->Zfd))!=((void*)(Zo))){
ZOW((ZX6*)(((C)->Zfd)),a1);}}T0*ZPW(ZM1*C,T0*a1){T0*R=Zo;if((ZZy(((T79*)(((((T91*)a1))->ZZb)))))==(ZGs(1))){R=((T0*)(C));}else{{Zp8*n=((Zp8*)Zh(sizeof(*n)));
*n=Z2l;ZzR(n,(T0*)C,a1);R=((T0*)n);}}return R;}T0*ZQW(ZM1*C,T0*a1){T0*R=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;if((((C)->Zfd))!=((void*)(Zo))){
(C->Zfd)=ZRW((ZX6*)(((C)->Zfd)),a1);}R=((T0*)(C));}else{{ZM1*n=((ZM1*)Zh(sizeof(*n)));*n=Zgd;ZIW(n,((C)->ZCb),((C)->ZZb),((C)->Zfd));
R=((T0*)n);}R=ZQW(((ZM1*)R),a1);}return R;}void ZSW(ZO1*C){ZTW(C);ZpG((((ZD8*)(((C)->Z2c)))->ZCb),((C)->ZFb),((C)->Z3c));}T0*ZUW(void){
if(ZrG==0){ZrG=1;{{ZG9*n=((ZG9*)Zh(sizeof(*n)));*n=Zfm;ZqG=((T0*)n);{ZG9*C1=n;ZhF(C1,ZGs(53));}}ZgF(((ZG9*)ZqG),ZtG);ZgF(((ZG9*)ZqG),ZuG);
ZgF(((ZG9*)ZqG),ZvG);ZgF(((ZG9*)ZqG),ZwG);ZgF(((ZG9*)ZqG),ZxG);ZgF(((ZG9*)ZqG),ZyG);ZgF(((ZG9*)ZqG),ZzG);ZgF(((ZG9*)ZqG),ZAG);ZgF(((ZG9*)ZqG),(((void)((T27*)(ZVW()))),ZCG(ZDG)));
ZgF(((ZG9*)ZqG),(((void)((T27*)(ZVW()))),ZCG(ZEG)));}}return ZqG;}T0*ZWW(ZO1*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;T0*ZGG=Zo;T0*ZHG=Zo;R=a1;if(ZIG(a2)){
if(ZIG(a3)){ZHG=Z9G(a3);ZGG=Z9G(a2);if((ZHG)!=((void*)(ZGG))){if(ZJG(a2,a3)){R=ZKG(a1,a3);if((T6)(((R)!=((void*)(a1)))&&((T6)(!(ZfF((ZG9*)(ZUW()),(((ZD8*)(((C)->Z2c)))->Zse))))))){
{T81 Zow;Z5G((*(Zow=ZLG(a1),&Zow)));}{T0*b1=ZMG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZGG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZNG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZHG;
Zmx((T7*)(Z2G),b1);}{T0*b1=ZOG;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));
}}}}return R;}T6 ZXW(ZO1*C,T0*a1){T6 R=0;T0*ZUG=Zo;if((((C)->ZFb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(ZVG((Za3*)(((C)->ZFb)),a1)));
}if(R){if((((C)->Z3c))==((void*)(Zo))){R=((T6)(ZWG(((C)->Z1c),a1)));}else if(ZXG(((C)->Z1c))){if(ZYG(((C)->Z3c),a1)){R=((T6)((ZZG(((C)->Z3c),a1))!=((void*)(Zo))));
}else{R=((T6)(0));}}else{R=((T6)(ZWG(((C)->Z1c),a1)));if(R){if((((C)->Z3c))!=((void*)(Zo))){ZUG=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Z3c)))->Z4c))))->Zof);
if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZUG))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){R=((T6)(ZYG(((C)->Z3c),ZUG)));}}}}}return R;}T0*ZYW(ZO1*C,T0*a1){
T0*R=Zo;R=Z1H((Za3*)(((C)->ZFb)),a1);if((R)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z2H((Za3*)(((C)->ZFb))),&Zow)));}{T0*b1=Z3H;Zmx((T7*)(Z2G),b1);
}Z4H(a1);ZaG((T80*)(Z4G));}return R;}T0*ZZW(ZO1*C){T0*R=Zo;T0*ZdH=Zo;T0*ZiL=Zo;(C->Z1c)=ZaH(((C)->Z1c));ZbH((Za3*)(((C)->ZFb)));if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){
R=((T0*)(C));}else if((ZmK)==((void*)((((ZD8*)(((C)->Z2c)))->Zse)))){if((T6)(((T6)((ZqU(ZGH(((C)->Z1c))))&&((T6)(Z_W(((C)->Z1c))))))&&((T6)(Z_W(((((Za3*)(((C)->ZFb))))->Z2j)))))){
{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;ZvL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);}}else{ZdH=(((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof);
if((T6)(((T6)(((T6)((((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1)))&&((T6)(Z_W(((C)->Z1c))))))&&((T6)(Z_W(((((Za3*)(((C)->ZFb))))->Z2j))))))&&((T6)(((((T85*)(((((T87*)((((ZX4*)(Z0X(((C)->Z3c))))->Zvb))))->Zpc)))->Zse))==((void*)(Z9I)))))){
{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;ZvL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);}}else{R=((T0*)(C));}}}else if(ZXG(((C)->Z1c))){if(Z_W(((((Za3*)(((C)->ZFb))))->Z2j))){
R=Z1X(C,((C)->Z3c));}else{R=((T0*)(C));}}else if(((Z3)(((((((Ze7*)((((Z23*)((((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof)))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1))){
if((T6)((Z_W(((C)->Z1c)))&&((T6)(Z_W(((((Za3*)(((C)->ZFb))))->Z2j)))))){ZdH=(((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof);ZiL=ZIL((ZZ3*)((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZUb))[ZGs(0)]),((C)->Z3c));
R=Z1X(C,ZiL);}else{R=((T0*)(C));}}else{R=((T0*)(C));}return R;}void Z2X(ZO1*C){T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){if((((C)->ZFb))!=((void*)(Zo))){
ZdH=(((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>=(ZGs(1)))){{T81
Zow;ZeH((T43*)(ZSG),(*(Zow=Z3X(C),&Zow)),((C)->Z3c),ZdH);}}}}ZgH(((C)->Z1c));if((((C)->ZFb))!=((void*)(Zo))){ZhH((Za3*)(((C)->ZFb)));
}}T0*Z1X(ZO1*C,T0*a1){T0*R=Zo;T0*Z4X=Zo;Z4X=a1;if(Zo!=(Z4X)){switch(((T0*)Z4X)->id){case 592:break;default:Z4X=Zo;}}if((T6)(((Z4X)!=((void*)(Zo)))&&((T6)(ZYG(Z4X,(((ZZ3*)(((((ZI7*)Z4X))->Znf)))->Zof)))))){
R=Z5X(((ZI7*)Z4X));}if((R)==((void*)(Zo))){R=((T0*)(C));}return R;}void ZTW(ZO1*C){if((ZiH(((C)->Z3c)))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));
}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));Z6X(Z1G(29,"Feature found is a procedure."));}}T6 Z7X(ZO1*C,T0*a1){T6 R=0;R=((T6)(ZXW(C,a1)));if(R){
R=((T6)(!(ZmH(ZnH(Z8X(C))))));}return R;}void Z9X(ZO1*C,T0*a1,T0*a2){ZqH(((C)->Z1c),a1,a2);ZrH((Za3*)(((C)->ZFb)),a1,a2);}void ZaX(ZO1*C){
{T81 Zow;Z5G((*(Zow=Z3X(C),&Zow)));}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}void ZbX(ZO1*C,T0*a1,T0*a2,T0*a3){(C->Z1c)=a1;(C->Z2c)=a2;(C->ZFb)=a3;}void ZcX(ZO1*C,T0*a1){T0*ZxH=Zo;ZxH=ZyH(((C)->Z1c),a1);
if((ZxH)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));}{T0*b1=Z1G(11,"Bad target.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));
}(C->Z1c)=ZxH;}void Z6X(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZdX(ZO1*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}{T81 Zow;
Z5G((*(Zow=Z3X(C),&Zow)));}Z3G((T80*)(Z4G));}T2 ZeX(void){T2 R=0;return R;}void ZfX(ZO1*C,T3 a1){if((a1)==(((T3)'R'))){{T81 Zow;ZDH(((C)->Z3c),(*(Zow=Z3X(C),&Zow)));
}}ZEH(((C)->Z1c),a1);ZEH(((((Za3*)(((C)->ZFb))))->Z2j),a1);}T0*Z8X(ZO1*C){T0*R=Zo;T0*ZFH=Zo;R=ZiH(((C)->Z3c));ZFH=R;if(Zo!=(ZFH)){switch(((T0*)ZFH)->id){
case 280:break;default:ZFH=Zo;}}if((ZFH)!=((void*)(Zo))){R=ZnH(ZGH(((((Za3*)(((C)->ZFb))))->Z2j)));}return R;}void ZgX(ZO1*C){T0*ZIH=Zo;
T0*ZJH=Zo;T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){ZIH=ZGH(((C)->Z1c));ZJH=Z_G(ZIH);ZdH=((((ZZ3*)ZJH))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
ZKH(((C)->Z1c),((C)->Z3c));}}ZLH(((C)->Z1c));ZMH((Za3*)(((C)->ZFb)));}T6 ZhX(ZO1*C){T6 R=0;R=((T6)(ZOH((Za3*)(((C)->ZFb)))));if(R){}else
if(ZXG(((C)->Z1c))){if((ZPH())!=((void*)(((C)->Z3c)))){R=((T6)(ZQH(((C)->Z3c))));}}else{R=((T6)(ZRH(((C)->Z1c))));}return R;}T0*ZVW(void){
if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);
ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);
ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);
ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);
ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);
ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);
ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);
ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);
ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);
ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);
ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);
ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);
ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);
ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);
}}}return ZSH;}T6 ZiX(ZO1*C){T6 R=0;if(Z0L(((C)->Z1c))){if((((C)->ZFb))!=((void*)(Zo))){R=((T6)(Z1L((Za3*)(((C)->ZFb)))));}else{R=((T6)(1));
}}return R;}T6 ZjX(ZO1*C,T0*a1){T6 R=0;R=((T6)(Z3L(ZGH(((C)->Z1c)))));R=((T6)((T6)((Z4L(((C)->Z1c),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){
if(Z5L(((Zz6*)a1),((C)->Z1c))){R=((T6)(1));}}else if((T6)((Z3L(ZGH(((C)->Z1c))))&&((T6)(!(ZXG(((C)->Z1c))))))){Z6L(((C)->Z1c));}return
R;}void ZkX(ZO1*C,T0*a1){T6 Z8L=0;T0*Z9L=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Z9L=ZnH(Z8X(C));if(ZbL(Z9L)){if(ZbL(a1)){ZcL(a1);ZdL((Z84*)(ZkH),((T3)'\050'));
{ZO1*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{ZO1*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}else{if(ZbL(a1)){{ZO1*C1=C;
ZeL((Z84*)(ZkH),(T0*)C1);}}else{if(ZfL(a1)){ZdL((Z84*)(ZkH),((T3)'\046'));ZdL((Z84*)(ZkH),((T3)'\050'));{ZO1*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);
}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{ZO1*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}}if(Z8L){ZgL((Z84*)(ZkH));}}void ZlX(ZO1*C,T0*a1){T0*ZiL=Zo;
T0*ZJH=Zo;T0*ZjL=Zo;T0*ZkL=Zo;ZjL=ZGH(((C)->Z1c));if((ZjL)!=((void*)(Zo))){ZJH=Z_G(ZjL);if((ZJH)!=((void*)(Zo))){ZkL=((((ZZ3*)ZJH))->Zvb);
ZiL=ZlL(((T87*)ZkL),ZJH,((C)->Z1c),((C)->Z2c),a1);}}if((ZiL)==((void*)(Zo))){Z5G((((ZD8*)(((C)->Z2c)))->ZCb));{T0*b1=Z1G(25,"Bad target for this call.");
Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z3c)=ZiL;}T2 ZmX(ZO1*C){T2 R=0;ZdX(C);return R;}T0*ZnX(ZO1*C,T0*a1){T0*R=Zo;T0*ZqL=Zo;
T0*ZpL=Zo;T0*ZoX=Zo;T0*ZJH=Zo;T0*Z5O=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;ZcX(C,a1);ZqL=ZGH(((C)->Z1c));ZoX=ZnH(ZqL);if(Zo!=(ZoX)){
switch(((T0*)ZoX)->id){case 296:case 298:break;default:ZoX=Zo;}}if((ZoX)!=((void*)(Zo))){ZJH=ZpX(((Z1a*)ZoX));(C->Z3c)=ZqX(((ZZ3*)ZJH),ZoX,((C)->Z2c));
(C->ZFb)=ZrX((Za3*)(((C)->ZFb)));(C->ZFb)=ZYW(C,a1);}else{(C->ZFb)=ZYW(C,a1);ZpL=ZGH(((((Za3*)(((C)->ZFb))))->Z2j));(C->Z1c)=ZWW(C,((C)->Z1c),ZqL,ZpL);
ZlX(C,a1);}if((ZoX)!=((void*)(Zo))){Z5O=(((ZD8*)(((C)->Z2c)))->Zse);if((Z5O)!=((void*)(ZQJ))){{T0*b1=Z1G(67,"You must use \"item\" to get the result of the execution of an agent.");
Zmx((T7*)(Z2G),b1);}if((Z5O)==((void*)(ZaJ))){{T0*b1=Z1G(35," (Just replace \"call\" with \"item\".)");Zmx((T7*)(Z2G),b1);}}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
ZaG((T80*)(Z4G));}{Zt4*n=((Zt4*)Zh(sizeof(*n)));*n=Zxg;ZsX(n,(T0*)C);R=((T0*)n);}}else{ZSW(C);R=((T0*)(C));}}else{{ZO1*n=((ZO1*)Zh(sizeof(*n)));
*n=Zhd;ZbX(n,((C)->Z1c),((C)->Z2c),((C)->ZFb));R=((T0*)n);}R=ZyH(R,a1);}return R;}T0*ZtX(ZO1*C){T0*R=Zo;T0*ZkL=Zo;T0*ZyL=Zo;T0*ZjL=Zo;
ZkL=ZzL(((C)->Z1c));if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),((C)->Z2c));if((ZyL)!=((void*)(Zo))){ZjL=ZBL(ZyL);if((ZjL)!=((void*)(Zo))){
R=ZCL(ZjL);}}}return R;}void ZuX(ZO1*C){if((((C)->Z3c))!=((void*)(Zo))){ZEL(((C)->Z3c));}ZFL(((C)->Z1c));if((((C)->ZFb))!=((void*)(Zo))){
ZGL((Za3*)(((C)->ZFb)));}}void ZvX(ZO1*C){T0*ZJH=Zo;T0*ZiL=Zo;ZiL=((C)->Z3c);ZJH=((((ZQ7*)ZiL))->Znf);(C->Z3c)=ZIL((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[ZGs(0)]),ZiL);
}T81 Z3X(ZO1*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((C)->Z2c)))->ZCb);return R;}void ZwX(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}
Z3G((T80*)(Z4G));}void ZxX(ZS1*C,T0*a1,T0*a2,T0*a3,T0*a4){(C->Zjd)=a1;(C->Zkd)=a2;(C->Zld)=a3;(C->Z1d)=a4;}void ZyX(ZS1*C){ZLH(((C)->Z1d));
}T6 ZzX(ZS1*C){T6 R=0;R=((T6)(ZRH(((C)->Z1d))));return R;}void ZAX(ZS1*C,T0*a1){T6 ZxR=0;ZxR=((T6)(Z4L(((C)->Z1d),a1)));}T0*ZBX(ZS1*C,T0*a1){
T0*R=Zo;T0*Z3V=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;Z3V=ZyH(((C)->Z1d),a1);if((Z3V)==((void*)(Zo))){{T81 Zow;ZwX((*(Zow=ZCX(C),&Zow)),Z1G(17,"Bad loop variant."));
}}else{(C->Z1d)=Z3V;if(!(ZzT(ZGH(((C)->Z1d))))){{T81 Zow;ZwX((*(Zow=ZLG(((C)->Z1d)),&Zow)),Z1G(38,"Expression of variant must be INTEGER."));
}}}if(((((T80*)(Z4G))->ZEg))==(ZGs(0))){R=((T0*)(C));}}else{{ZS1*n=((ZS1*)Zh(sizeof(*n)));*n=Zmd;ZxX(n,((C)->Zjd),((C)->Zkd),((C)->Zld),((C)->Z1d));
R=((T0*)n);}R=ZBX(((ZS1*)R),a1);}return R;}T81 ZCX(ZS1*C){T81 R={Zo,Zo,0};if((((C)->Zkd))!=((void*)(Zo))){R=(((Zr6*)(((C)->Zkd)))->ZCb);
}else{{T81 Zow;R=(*(Zow=ZLG(((C)->Z1d)),&Zow));}}return R;}void ZDX(ZU1*C){ZEX(C);ZpG((((ZD8*)(((C)->Z2c)))->ZCb),Zo,((C)->Z3c));}T0*ZFX(ZU1*C,T0*a1){
T0*R=Zo;T0*Z4X=Zo;Z4X=a1;if(Zo!=(Z4X)){switch(((T0*)Z4X)->id){case 592:break;default:Z4X=Zo;}}if((T6)(((Z4X)!=((void*)(Zo)))&&((T6)(ZYG(Z4X,(((ZZ3*)(((((ZI7*)Z4X))->Znf)))->Zof)))))){
R=Z5X(((ZI7*)Z4X));}if((R)==((void*)(Zo))){R=((T0*)(C));}return R;}T6 ZGX(ZU1*C,T0*a1){T6 R=0;T0*ZUG=Zo;R=((T6)(1));if(R){if((((C)->Z3c))==((void*)(Zo))){
R=((T6)(ZWG(((C)->Z1c),a1)));}else if(ZXG(((C)->Z1c))){if(ZYG(((C)->Z3c),a1)){R=((T6)((ZZG(((C)->Z3c),a1))!=((void*)(Zo))));}else{R=((T6)(0));
}}else{R=((T6)(ZWG(((C)->Z1c),a1)));if(R){if((((C)->Z3c))!=((void*)(Zo))){ZUG=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Z3c)))->Z4c))))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZUG))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
R=((T6)(ZYG(((C)->Z3c),ZUG)));}}}}}return R;}T0*ZHX(ZU1*C){T0*R=Zo;T0*ZIX=Zo;T0*ZJX=Zo;T0*ZdH=Zo;T0*ZKX=Zo;T0*ZqL=Zo;T81 ZjG={Zo,Zo,0};
T0*ZiL=Zo;(C->Z1c)=ZaH(((C)->Z1c));ZqL=ZnH(ZGH(((C)->Z1c)));ZIX=(((ZD8*)((((ZQ7*)(((C)->Z3c)))->Zpc)))->Zse);if((ZOJ)==((void*)(ZIX))){
if(ZqU(ZqL)){{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;ZvL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);}}else{{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));
*n=Zml;ZwL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);}}if(!(Z_W(((C)->Z1c)))){{T0*b1=Z1G(114,"Must use \173""GENERAL\175"".is_expanded_type with such a target expression (keep in mind that the target is not evaluated).");
Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));}ZaG((T80*)(Z4G));}}else if((ZLJ)==((void*)(ZIX))){if(ZIG(ZqL)){{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));
*n=Z5h;ZvL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);}}else{{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zml;ZwL(n,(((ZD8*)(((C)->Z2c)))->ZCb));R=((T0*)n);
}}if(!(Z_W(((C)->Z1c)))){{T0*b1=Z1G(120,"Must use \173""GENERAL\175"".is_basic_expanded_type with such a target expression (keep in mind that the target is not evaluated).");
Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));}ZaG((T80*)(Z4G));}}else if((ZNJ)==((void*)(ZIX))){ZjG=(((ZD8*)(((C)->Z2c)))->ZCb);
if(ZzT(ZqL)){{Zw1*n=((Zw1*)Zh(sizeof(*n)));*n=ZQl;ZMN(n,(T11)(ZGs(0)),ZjG);ZKX=((T0*)n);}{ZH2*n=((ZH2*)Zh(sizeof(*n)));*n=ZUd;ZLX(n,((C)->Z1c),ZjG,ZKX);
R=((T0*)n);}R=ZaH(R);}else if((T6)((ZqT(ZqL))||((T6)(ZbU(ZqL))))){{ZC9*n=((ZC9*)Zh(sizeof(*n)));*n=Zdm;ZMX(n,ZjG,ZNX);R=((T0*)n);}{ZH2*n=((ZH2*)Zh(sizeof(*n)));
*n=ZUd;ZLX(n,((C)->Z1c),ZjG,R);R=((T0*)n);}R=ZaH(R);}else if(ZmU(ZqL)){{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zml;ZwL(n,ZjG);R=((T0*)n);}{ZH2*n=((ZH2*)Zh(sizeof(*n)));
*n=ZUd;ZLX(n,((C)->Z1c),ZjG,R);R=((T0*)n);}R=ZaH(R);}else if(ZET(ZqL)){{ZH4*n=((ZH4*)Zh(sizeof(*n)));*n=ZRg;ZOX(n,ZjG,((T3)'\000'));R=((T0*)n);
}{ZH2*n=((ZH2*)Zh(sizeof(*n)));*n=ZUd;ZLX(n,((C)->Z1c),ZjG,R);R=((T0*)n);}R=ZaH(R);}else if(ZPX(ZqL)){{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;
ZvL(n,ZjG);R=((T0*)n);}}else if(ZsP(ZqL)){{ZZ4*n=((ZZ4*)Zh(sizeof(*n)));*n=Z5h;ZvL(n,ZjG);R=((T0*)n);}}else{R=((T0*)(C));}}else if((T6)(((ZfJ)==((void*)(ZIX)))&&((T6)(ZMR(ZqL))))){
ZJX=ZqL;if(Zo!=(ZJX)){switch(((T0*)ZJX)->id){case 304:case 306:break;default:ZJX=Zo;}}ZjG=(((ZD8*)(((C)->Z2c)))->ZCb);{Zw1*n=((Zw1*)Zh(sizeof(*n)));
*n=ZQl;ZMN(n,(T11)(ZQX(ZJX)),ZjG);R=((T0*)n);}}if((R)!=((void*)(Zo))){}else if((Z3)(((((T89*)(ZPM))->Zaf))>=(ZGs(2)))){R=((T0*)(C));}
else if(ZXG(((C)->Z1c))){R=ZRX(C,((C)->Z3c));}else if(Z4V(((C)->Z1c))){R=ZRX(C,((C)->Z3c));}else if(((Z3)(((((((Ze7*)((((Z23*)((((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof)))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1))){
if(Z_W(((C)->Z1c))){ZdH=(((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof);ZiL=ZIL((ZZ3*)((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZUb))[ZGs(0)]),((C)->Z3c));
R=ZRX(C,ZiL);}else{R=((T0*)(C));}}else{R=((T0*)(C));}return R;}void ZSX(ZU1*C){T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){}ZgH(((C)->Z1c));
}T0*ZRX(ZU1*C,T0*a1){T0*R=Zo;T0*ZTX=Zo;R=ZFX(C,a1);if((R)==((void*)(C))){ZTX=a1;if(Zo!=(ZTX)){switch(((T0*)ZTX)->id){case 583:break;default:
ZTX=Zo;}}if((ZTX)!=((void*)(Zo))){R=((((ZC7*)ZTX))->Zde);}}return R;}void ZEX(ZU1*C){if((ZiH(((C)->Z3c)))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));
}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));ZUX(Z1G(29,"Feature found is a procedure."));}}void ZVX(ZU1*C){T0*ZOP=Zo;ZOP=(((ZD8*)(((C)->Z2c)))->Zse);
if((ZOJ)==((void*)(ZOP))){if(ZqU(ZnH(ZGH(((C)->Z1c))))){ZdL((Z84*)(ZkH),((T3)'1'));}else{ZdL((Z84*)(ZkH),((T3)'0'));}}else if((ZLJ)==((void*)(ZOP))){
if(ZIG(ZGH(((C)->Z1c)))){ZdL((Z84*)(ZkH),((T3)'1'));}else{ZdL((Z84*)(ZkH),((T3)'0'));}}else{{ZU1*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}T6 ZWX(ZU1*C,T0*a1){
T6 R=0;R=((T6)(ZGX(C,a1)));if(R){R=((T6)(!(ZmH(ZnH(ZXX(C))))));}return R;}void ZYX(ZU1*C,T0*a1,T0*a2){ZqH(((C)->Z1c),a1,a2);}void ZZX(ZU1*C){
{T81 Zow;Z5G((*(Zow=Z_X(C),&Zow)));}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}void Z0Y(ZU1*C,T0*a1,T0*a2){(C->Z1c)=a1;(C->Z2c)=a2;}void Z1Y(ZU1*C,T0*a1){T0*ZxH=Zo;ZxH=ZyH(((C)->Z1c),a1);if((ZxH)==((void*)(Zo))){
{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));}{T0*b1=Z1G(11,"Bad target.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z1c)=ZxH;
}void ZUX(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Z2Y(ZU1*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=Z_X(C),&Zow)));
}Z3G((T80*)(Z4G));}T2 Z3Y(void){T2 R=0;return R;}void Z4Y(ZU1*C,T3 a1){if((a1)==(((T3)'R'))){{T81 Zow;ZDH(((C)->Z3c),(*(Zow=Z_X(C),&Zow)));
}}ZEH(((C)->Z1c),a1);}T0*ZXX(ZU1*C){T0*R=Zo;R=ZiH(((C)->Z3c));return R;}void Z5Y(ZU1*C){T0*ZIH=Zo;T0*ZJH=Zo;T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){
ZIH=ZGH(((C)->Z1c));ZJH=Z_G(ZIH);ZdH=((((ZZ3*)ZJH))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){
ZKH(((C)->Z1c),((C)->Z3c));}}ZLH(((C)->Z1c));}T6 Z6Y(ZU1*C){T6 R=0;if(R){}else if(ZXG(((C)->Z1c))){if((ZPH())!=((void*)(((C)->Z3c)))){
R=((T6)(ZQH(((C)->Z3c))));}}else{R=((T6)(ZRH(((C)->Z1c))));}return R;}T6 Z7Y(ZU1*C){T6 R=0;if(Z0L(((C)->Z1c))){R=((T6)(1));}return R;
}T6 Z8Y(ZU1*C,T0*a1){T6 R=0;R=((T6)(Z3L(ZGH(((C)->Z1c)))));R=((T6)((T6)((Z4L(((C)->Z1c),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z5L(((Zz6*)a1),((C)->Z1c))){
R=((T6)(1));}}else if((T6)((Z3L(ZGH(((C)->Z1c))))&&((T6)(!(ZXG(((C)->Z1c))))))){Z6L(((C)->Z1c));}return R;}T6 Z9Y(ZU1*C){T6 R=0;T0*ZiL=Zo;
T0*ZdH=Zo;if(Z_W(((C)->Z1c))){if((Z3)(((((T43*)(ZSG))->ZQk))>=(ZGs(4)))){ZiL=((C)->Z3c);ZdH=(((ZZ3*)(((((ZQ7*)ZiL))->Znf)))->Zof);if(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))==(ZGs(1))){
ZiL=ZIL((ZZ3*)((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZUb))[ZGs(0)]),ZiL);R=((T6)(ZaY(ZiL)));}}}return R;}void ZbY(ZU1*C,T0*a1){T6 Z8L=0;
T0*Z9L=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Z9L=ZnH(ZXX(C));if(ZbL(Z9L)){if(ZbL(a1)){ZcL(a1);ZdL((Z84*)(ZkH),((T3)'\050'));ZVX(C);ZdL((Z84*)(ZkH),((T3)'\051'));
}else{ZVX(C);}}else{if(ZbL(a1)){ZVX(C);}else{if(ZfL(a1)){ZdL((Z84*)(ZkH),((T3)'\046'));ZdL((Z84*)(ZkH),((T3)'\050'));ZVX(C);ZdL((Z84*)(ZkH),((T3)'\051'));
}else{ZVX(C);}}}if(Z8L){ZgL((Z84*)(ZkH));}}void ZcY(ZU1*C,T0*a1){T0*ZiL=Zo;T0*ZJH=Zo;T0*ZjL=Zo;T0*ZkL=Zo;ZjL=ZGH(((C)->Z1c));if((ZjL)!=((void*)(Zo))){
ZJH=Z_G(ZjL);if((ZJH)!=((void*)(Zo))){ZkL=((((ZZ3*)ZJH))->Zvb);ZiL=ZlL(((T87*)ZkL),ZJH,((C)->Z1c),((C)->Z2c),a1);}}if((ZiL)==((void*)(Zo))){
Z5G((((ZD8*)(((C)->Z2c)))->ZCb));{T0*b1=Z1G(25,"Bad target for this call.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z3c)=ZiL;
}T2 ZdY(ZU1*C){T2 R=0;T0*ZTX=Zo;ZTX=((C)->Z3c);if(Zo!=(ZTX)){switch(((T0*)ZTX)->id){case 583:break;default:ZTX=Zo;}}if((ZTX)==((void*)(Zo))){
Z2Y(C);}else{R=ZSU(((((ZC7*)ZTX))->Zde));}return R;}T0*ZeY(ZU1*C,T0*a1){T0*R=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;Z1Y(C,a1);
ZcY(C,a1);R=((T0*)(C));ZDX(C);}else{{ZU1*n=((ZU1*)Zh(sizeof(*n)));*n=Znd;Z0Y(n,((C)->Z1c),((C)->Z2c));R=((T0*)n);}R=ZeY(((ZU1*)R),a1);
}return R;}T0*ZfY(ZU1*C){T0*R=Zo;T0*ZkL=Zo;T0*ZyL=Zo;T0*ZjL=Zo;ZkL=ZzL(((C)->Z1c));if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),((C)->Z2c));
if((ZyL)!=((void*)(Zo))){ZjL=ZBL(ZyL);if((ZjL)!=((void*)(Zo))){R=ZCL(ZjL);}}}return R;}void ZgY(ZU1*C){if((((C)->Z3c))!=((void*)(Zo))){
ZEL(((C)->Z3c));}ZFL(((C)->Z1c));}void ZhY(ZU1*C){T0*ZJH=Zo;T0*ZiL=Zo;ZiL=((C)->Z3c);ZJH=((((ZQ7*)ZiL))->Znf);(C->Z3c)=ZIL((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[ZGs(0)]),ZiL);
}T81 Z_X(ZU1*C){T81 R={Zo,Zo,0};R=(((ZD8*)(((C)->Z2c)))->ZCb);return R;}T0*ZiY(ZW1*C,T0*a1){T0*R=Zo;{Zp8*n=((Zp8*)Zh(sizeof(*n)));*n=Z2l;
ZzR(n,(T0*)C,a1);R=((T0*)n);}return R;}T0*ZjY(ZW1*C,T0*a1){T0*R=Zo;T0*ZiL=Zo;ZiL=ZPH();if((((C)->Z3c))==((void*)(Zo))){(C->Z3c)=ZiL;R=((T0*)(C));
}else if((((C)->Z3c))==((void*)(ZiL))){R=((T0*)(C));}else{{ZW1*n=((ZW1*)Zh(sizeof(*n)));*n=Zod;((((ZW1*)(n)))->ZCb)=(((C)->ZCb));R=((T0*)n);
}R=ZjY(((ZW1*)R),a1);}return R;}void ZeV(Z_1*C,T0*a1){T0*ZiL=Zo;T0*ZkY=Zo;T0*ZJH=Zo;if((((C)->Zrd))==((void*)(Zo))){Z5G(((C)->ZCb));{T0*b1=Z1G(50,"Cannot create a class with an empty creation list.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}if((Z3)((Z8O((Zz8*)(((C)->Zrd))))>(ZGs(1)))){ZMT(a1,ZdV);Z5G(((C)->ZCb));{T0*b1=Z1G(106,"Expanded class must have no creation procedure, or only one creation procedure with no arguments (VTEC.2).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}ZJH=Z_G(a1);ZiL=ZyP(((ZZ3*)ZJH),(((Zz8*)(((C)->Zrd)))->ZGd));if((ZiL)==((void*)(Zo))){Z5G(((C)->ZCb));
{T0*b1=Z1G(23,"Creation procedure for ");Zmx((T7*)(Z2G),b1);}ZMT(a1,Z1G(11," not found."));ZaG((T80*)(Z4G));}ZkY=ZiL;if(Zo!=(ZkY)){switch(((T0*)ZkY)->id){
case 451:break;default:ZkY=Zo;}}if((ZkY)==((void*)(Zo))){Z5G(((C)->ZCb));{T81 Zow;Z5G((*(Zow=Z8G(ZiL),&Zow)));}{T0*b1=Z1G(33,Z9q);Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}if((((((ZG7*)ZkY))->ZFb))!=((void*)(Zo))){ZMT(a1,ZdV);Z5G(((C)->ZCb));{T81 Zow;Z5G((*(Zow=ZlY(((ZG7*)ZkY)),&Zow)));
}{T0*b1=Z1G(31,"Procedure found has arguments. ");Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(106,"Expanded class must have no creation procedure, or only one creation procedure with no arguments (VTEC.2).");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}T0*ZgV(Z_1*C){T0*R=Zo;if((((C)->Zrd))!=((void*)(Zo))){if(ZmY((Zz8*)(((C)->Zrd)))){R=ZWJ;}else{
R=(((ZD8*)((((Zz8*)(((C)->Zrd)))->ZGd)))->Zse);}}return R;}void ZnY(Z_1*C,T81 a1,T0*a2,T0*a3,T0*a4){(C->ZCb)=a1;(C->Zjc)=a2;(C->Zqd)=a3;
(C->Zrd)=a4;}T0*ZjV(Z_1*C,T0*a1){T0*R=Zo;T2 Zet=0;T0*Z5O=Zo;T0*ZoY=Zo;T0*ZJH=Zo;T0*ZiL=Zo;if((((C)->Zrd))!=((void*)(Zo))){ZJH=Z_G(a1);
Zet=Z8O((Zz8*)(((C)->Zrd)));while(!((T6)(((ZiL)!=((void*)(Zo)))||((T6)((Z3)((Zet)<=(ZGs(0)))))))){Z5O=Z7O((Zz8*)(((C)->Zrd)),Zet);if((((((ZD8*)Z5O))->Zse))==((void*)(ZpJ))){
ZiL=ZyP(((ZZ3*)ZJH),Z5O);ZoY=Z5O;}Zet=(Z3)(((Zet))-(ZGs(1)));}if((T6)(((ZiL)==((void*)(Zo)))&&((T6)(ZqU(a1))))){Zet=Z8O((Zz8*)(((C)->Zrd)));
while(!((T6)(((ZiL)!=((void*)(Zo)))||((T6)((Z3)((Zet)<=(ZGs(0)))))))){Z5O=Z7O((Zz8*)(((C)->Zrd)),Zet);ZiL=ZyP(((ZZ3*)ZJH),Z5O);ZoY=Z5O;
if((ZiL)!=((void*)(Zo))){if((ZAP(ZiL))!=((void*)(Zo))){ZiL=Zo;}}Zet=(Z3)(((Zet))-(ZGs(1)));}}if((ZiL)!=((void*)(Zo))){R=ZiL;if(Zo!=(R)){
switch(((T0*)R)->id){case 451:break;default:R=Zo;}}if((R)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(ZiL),&Zow)));}Z5G(((((ZD8*)ZoY))->ZCb));
{T0*b1=ZpY;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}}}return R;}T6 ZnV(Z_1*C,T0*a1){T6 R=0;if((((C)->Zrd))!=((void*)(Zo))){R=((T6)(ZqY((Zz8*)(((C)->Zrd)),a1)));
}return R;}T0*ZlV(Z_1*C,T0*a1){T0*R=Zo;if((((C)->Zrd))!=((void*)(Zo))){R=ZrY((Zz8*)(((C)->Zrd)),a1);}return R;}void ZsY(Z32*C){ZtY(C);
ZpG((((ZD8*)(((C)->Z2c)))->ZCb),((C)->ZFb),((C)->Z3c));}T0*ZuY(void){if(ZrG==0){ZrG=1;{{ZG9*n=((ZG9*)Zh(sizeof(*n)));*n=Zfm;ZqG=((T0*)n);
{ZG9*C1=n;ZhF(C1,ZGs(53));}}ZgF(((ZG9*)ZqG),ZtG);ZgF(((ZG9*)ZqG),ZuG);ZgF(((ZG9*)ZqG),ZvG);ZgF(((ZG9*)ZqG),ZwG);ZgF(((ZG9*)ZqG),ZxG);
ZgF(((ZG9*)ZqG),ZyG);ZgF(((ZG9*)ZqG),ZzG);ZgF(((ZG9*)ZqG),ZAG);ZgF(((ZG9*)ZqG),(((void)((T27*)(ZvY()))),ZCG(ZDG)));ZgF(((ZG9*)ZqG),(((void)((T27*)(ZvY()))),ZCG(ZEG)));
}}return ZqG;}T0*ZwY(Z32*C,T0*a1,T0*a2,T0*a3){T0*R=Zo;T0*ZGG=Zo;T0*ZHG=Zo;R=a1;if(ZIG(a2)){if(ZIG(a3)){ZHG=Z9G(a3);ZGG=Z9G(a2);if((ZHG)!=((void*)(ZGG))){
if(ZJG(a2,a3)){R=ZKG(a1,a3);if((T6)(((R)!=((void*)(a1)))&&((T6)(!(ZfF((ZG9*)(ZuY()),(((ZD8*)(((C)->Z2c)))->Zse))))))){{T81 Zow;Z5G((*(Zow=ZLG(a1),&Zow)));
}{T0*b1=ZMG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZGG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZNG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZHG;Zmx((T7*)(Z2G),b1);}{T0*b1=ZOG;
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}}else{((((T7*)((T7*)(Z2G))))->Zdc)=(ZGs(0));((((T82*)((T82*)(ZQG()))))->ZWb)=(ZGs(-1));}}}}return
R;}T6 ZxY(Z32*C,T0*a1){T6 R=0;T0*ZUG=Zo;if((((C)->ZFb))==((void*)(Zo))){R=((T6)(1));}else{R=((T6)(ZVG((Za3*)(((C)->ZFb)),a1)));}if(R){
if((((C)->Z3c))==((void*)(Zo))){R=((T6)(ZWG(((C)->Z1c),a1)));}else if(ZXG(((C)->Z1c))){if(ZYG(((C)->Z3c),a1)){R=((T6)((ZZG(((C)->Z3c),a1))!=((void*)(Zo))));
}else{R=((T6)(0));}}else{R=((T6)(ZWG(((C)->Z1c),a1)));if(R){if((((C)->Z3c))!=((void*)(Zo))){ZUG=(((ZZ3*)(Z_G((((ZQ7*)(((C)->Z3c)))->Z4c))))->Zof);
if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZUG))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){R=((T6)(ZYG(((C)->Z3c),ZUG)));}}}}}return R;}T0*ZyY(Z32*C,T0*a1){
T0*R=Zo;R=Z1H((Za3*)(((C)->ZFb)),a1);if((R)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z2H((Za3*)(((C)->ZFb))),&Zow)));}{T0*b1=Z3H;Zmx((T7*)(Z2G),b1);
}Z4H(a1);ZaG((T80*)(Z4G));}return R;}void ZzY(Z32*C,T0*a1,T0*a2,T0*a3){(C->Z3c)=Zo;(C->Z4c)=Zo;(C->Z1c)=a1;(C->Z2c)=a2;(C->ZFb)=a3;}T0*ZAY(Z32*C){
T0*R=Zo;if((((T43*)(ZSG))->ZRk)){R=((T0*)(C));}else{R=ZBY(C);if((R)!=((void*)(C))){Z8H((T43*)(ZSG));}}return R;}T0*ZCY(Z32*C){T0*R=Zo;
(C->Z1c)=ZaH(((C)->Z1c));ZbH((Za3*)(((C)->ZFb)));R=ZBY(C);return R;}void ZDY(Z32*C){T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){if((((C)->ZFb))!=((void*)(Zo))){
ZdH=(((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>=(ZGs(1)))){{T81
Zow;ZeH((T43*)(ZSG),(*(Zow=ZEY(C),&Zow)),((C)->Z3c),ZdH);}}}}ZgH(((C)->Z1c));if((((C)->ZFb))!=((void*)(Zo))){ZhH((Za3*)(((C)->ZFb)));
}}void ZtY(Z32*C){if((ZiH(((C)->Z3c)))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));}Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
ZFY(Z1G(29,"Feature found is a procedure."));}}T6 ZGY(Z32*C,T0*a1){T6 R=0;R=((T6)(ZxY(C,a1)));if(R){R=((T6)(!(ZmH(ZnH(ZHY(C))))));}return
R;}void ZIY(Z32*C,T0*a1,T0*a2){ZqH(((C)->Z1c),a1,a2);ZrH((Za3*)(((C)->ZFb)),a1,a2);}void ZJY(Z32*C){{T81 Zow;Z5G((*(Zow=ZEY(C),&Zow)));
}{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZKY(Z32*C,T0*a1,T81
a2,T0*a3){(C->Z1c)=a1;{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZuH(n,(ZCI),a2);(C->Z2c)=((T0*)n);}{Za3*n=((Za3*)Zh(sizeof(*n)));*n=Z3j;((((Za3*)(n)))->Z2j)=(a3);
(C->ZFb)=((T0*)n);}}void ZLY(Z32*C,T0*a1){T0*ZxH=Zo;ZxH=ZyH(((C)->Z1c),a1);if((ZxH)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZLG(((C)->Z1c)),&Zow)));
}{T0*b1=Z1G(11,"Bad target.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z1c)=ZxH;}void ZFY(T0*a1){{T0*b1=a1;Zmx((T7*)(Z2G),b1);
}ZaG((T80*)(Z4G));}void ZMY(Z32*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}{T81 Zow;Z5G((*(Zow=ZEY(C),&Zow)));}Z3G((T80*)(Z4G));}T2 ZNY(void){
T2 R=0;return R;}void ZOY(Z32*C,T3 a1){if((a1)==(((T3)'R'))){{T81 Zow;ZDH(((C)->Z3c),(*(Zow=ZEY(C),&Zow)));}}ZEH(((C)->Z1c),a1);ZEH(((((Za3*)(((C)->ZFb))))->Z2j),a1);
}T0*ZHY(Z32*C){T0*R=Zo;T0*ZFH=Zo;R=ZiH(((C)->Z3c));ZFH=R;if(Zo!=(ZFH)){switch(((T0*)ZFH)->id){case 280:break;default:ZFH=Zo;}}if((ZFH)!=((void*)(Zo))){
R=ZnH(ZGH(((((Za3*)(((C)->ZFb))))->Z2j)));}return R;}void ZPY(Z32*C){T0*ZIH=Zo;T0*ZJH=Zo;T0*ZdH=Zo;if((((C)->Z3c))!=((void*)(Zo))){ZIH=ZGH(((C)->Z1c));
ZJH=Z_G(ZIH);ZdH=((((ZZ3*)ZJH))->Zof);if((Z3)(((Z3)(((((((Ze7*)(((((Z23*)ZdH))->Zae))))->ZWb)))+(ZGs(1))))>(ZGs(1)))){ZKH(((C)->Z1c),((C)->Z3c));
}}ZLH(((C)->Z1c));ZMH((Za3*)(((C)->ZFb)));}T6 ZQY(Z32*C){T6 R=0;R=((T6)(ZOH((Za3*)(((C)->ZFb)))));if(R){}else if(ZXG(((C)->Z1c))){if((ZPH())!=((void*)(((C)->Z3c)))){
R=((T6)(ZQH(((C)->Z3c))));}}else{R=((T6)(ZRH(((C)->Z1c))));}return R;}T0*ZvY(void){if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);
ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);
ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);
ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);
ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);
ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);
ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);
ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);
ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);
ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);
ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);
ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);
ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);
ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);
ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);}}}return ZSH;}T6 ZRY(Z32*C){T6 R=0;if(Z0L(((C)->Z1c))){
if((((C)->ZFb))!=((void*)(Zo))){R=((T6)(Z1L((Za3*)(((C)->ZFb)))));}else{R=((T6)(1));}}return R;}T6 ZSY(Z32*C,T0*a1){T6 R=0;R=((T6)(Z3L(ZGH(((C)->Z1c)))));
R=((T6)((T6)((Z4L(((C)->Z1c),a1))||((T6)(R)))));if((a1)!=((void*)(Zo))){if(Z5L(((Zz6*)a1),((C)->Z1c))){R=((T6)(1));}}else if((T6)((Z3L(ZGH(((C)->Z1c))))&&((T6)(!(ZXG(((C)->Z1c))))))){
Z6L(((C)->Z1c));}return R;}void ZTY(Z32*C,T0*a1){T6 Z8L=0;T0*Z9L=Zo;Z8L=((T6)(ZaL((Z84*)(ZkH),a1)));Z9L=ZnH(ZHY(C));if(ZbL(Z9L)){if(ZbL(a1)){
ZcL(a1);ZdL((Z84*)(ZkH),((T3)'\050'));{Z32*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Z32*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);
}}}else{if(ZbL(a1)){{Z32*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}else{if(ZfL(a1)){ZdL((Z84*)(ZkH),((T3)'\046'));ZdL((Z84*)(ZkH),((T3)'\050'));
{Z32*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}ZdL((Z84*)(ZkH),((T3)'\051'));}else{{Z32*C1=C;ZeL((Z84*)(ZkH),(T0*)C1);}}}}if(Z8L){ZgL((Z84*)(ZkH));
}}void ZUY(Z32*C,T0*a1){T0*ZiL=Zo;T0*ZJH=Zo;T0*ZjL=Zo;T0*ZkL=Zo;ZjL=ZGH(((C)->Z1c));if((ZjL)!=((void*)(Zo))){ZJH=Z_G(ZjL);if((ZJH)!=((void*)(Zo))){
ZkL=((((ZZ3*)ZJH))->Zvb);ZiL=ZlL(((T87*)ZkL),ZJH,((C)->Z1c),((C)->Z2c),a1);}}if((ZiL)==((void*)(Zo))){Z5G((((ZD8*)(((C)->Z2c)))->ZCb));
{T0*b1=Z1G(25,"Bad target for this call.");Zmx((T7*)(Z2G),b1);}Z4H(a1);ZaG((T80*)(Z4G));}(C->Z3c)=ZiL;}T0*ZVY(Z32*C){T0*R=Zo;R=Zh(sizeof(*C));
*((Z32*)R)=*C;return R;}T2 ZWY(Z32*C){T2 R=0;ZMY(C);return R;}T0*ZXY(Z32*C,T0*a1){T0*R=Zo;T0*ZpL=Zo;T0*ZqL=Zo;T0*ZrL=Zo;if((((C)->Z4c))==((void*)(Zo))){
(C->Z4c)=a1;ZLY(C,a1);(C->ZFb)=ZyY(C,a1);ZqL=ZGH(((C)->Z1c));ZpL=ZGH(((((Za3*)(((C)->ZFb))))->Z2j));(C->Z1c)=ZwY(C,((C)->Z1c),ZqL,ZpL);
ZUY(C,a1);R=ZAY(C);ZsY(C);}else{ZrL=ZVY(C);ZzY(((Z32*)ZrL),((C)->Z1c),((C)->Z2c),((C)->ZFb));R=ZXY(((Z32*)ZrL),a1);}return R;}T0*ZBY(Z32*C){
T0*R=Zo;T0*ZsL=Zo;ZsL=((C)->Z1c);if(Zo!=(ZsL)){switch(((T0*)ZsL)->id){case 318:case 319:break;default:ZsL=Zo;}}if((ZsL)==((void*)(Zo))){
R=((T0*)(C));}else if(ZuL(ZsL)){R=((((Za3*)(((C)->ZFb))))->Z2j);}else{{ZZ8*n=((ZZ8*)Zh(sizeof(*n)));*n=Zml;ZwL(n,(((ZD8*)(((C)->Z2c)))->ZCb));
R=((T0*)n);}}return R;}T0*ZYY(Z32*C){T0*R=Zo;T0*ZkL=Zo;T0*ZyL=Zo;T0*ZjL=Zo;ZkL=ZzL(((C)->Z1c));if((ZkL)!=((void*)(Zo))){ZyL=ZAL(((T87*)ZkL),((C)->Z2c));
if((ZyL)!=((void*)(Zo))){ZjL=ZBL(ZyL);if((ZjL)!=((void*)(Zo))){R=ZCL(ZjL);}}}return R;}void ZZY(Z32*C){if((((C)->Z3c))!=((void*)(Zo))){
ZEL(((C)->Z3c));}ZFL(((C)->Z1c));if((((C)->ZFb))!=((void*)(Zo))){ZGL((Za3*)(((C)->ZFb)));}}void Z_Y(Z32*C){T0*ZJH=Zo;T0*ZiL=Zo;ZiL=((C)->Z3c);
ZJH=((((ZQ7*)ZiL))->Znf);(C->Z3c)=ZIL((ZZ3*)((((((Ze7*)((((Z23*)(((((ZZ3*)ZJH))->Zof)))->Zae))))->ZUb))[ZGs(0)]),ZiL);}T81 ZEY(Z32*C){
T81 R={Zo,Zo,0};R=(((ZD8*)(((C)->Z2c)))->ZCb);return R;}void Z0Z(Zd2*C){if((((C)->ZFb))!=((void*)(Zo))){ZhH((Za3*)(((C)->ZFb)));}}void
Z1Z(Zd2*C){Z2Z((Z84*)(ZkH),((C)->Z3c),((C)->ZFb));Z3Z(((C)->Z3c));Z4Z((Z84*)(ZkH));}T6 Z5Z(T0*a1){T6 R=0;return R;}void Z6Z(Zd2*C,T0*a1,T0*a2){
if((((C)->ZFb))!=((void*)(Zo))){ZrH((Za3*)(((C)->ZFb)),a1,a2);}}void Z7Z(Zd2*C){Z5G(((C)->ZCb));{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void Z8Z(Zd2*C,T81 a1,T0*a2,T0*a3){(C->ZCb)=a1;(C->ZAd)=a2;(C->ZFb)=a3;}void Z9Z(T0*a1){{T0*b1=a1;
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZaZ(Zd2*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}Z5G(((C)->ZCb));Z3G((T80*)(Z4G));}T0*ZbZ(Zd2*C){
T0*R=Zo;R=ZiH(((C)->Z3c));return R;}T0*ZcZ(Zd2*C,T0*a1){T0*R=Zo;T0*ZyL=Zo;T0*ZdZ=Zo;T0*ZeZ=Zo;ZyL=Z0X(a1);ZdZ=((((ZX4*)ZyL))->Zvb);ZeZ=((((T87*)ZdZ))->Zlg);
if((ZeZ)==((void*)(Zo))){Z5G(((C)->ZCb));Z9Z(Z1G(71,"Precursor call is allowed only when the enclosing routine is redefined."));}else{
R=ZfZ(((Z7a*)ZeZ),(T0*)C,a1);}return R;}void ZgZ(Zd2*C){if((((C)->ZFb))!=((void*)(Zo))){ZMH((Za3*)(((C)->ZFb)));}}void ZhZ(Zd2*C,T0*a1){
T0*ZKO=Zo;if((((C)->ZFb))!=((void*)(Zo))){ZKO=Z1H((Za3*)(((C)->ZFb)),a1);if((ZKO)==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z2H((Za3*)(((C)->ZFb))),&Zow)));
}{T0*b1=ZiZ;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{(C->ZFb)=ZKO;}}ZpG(((C)->ZCb),((C)->ZFb),((C)->Z3c));}T0*ZjZ(T0*a1,T0*a2){T0*R=Zo;
{ZD8*n=((ZD8*)Zh(sizeof(*n)));*n=Zfn;ZkZ(n,(T2)((((T87*)(((((ZX4*)a2))->Zvb)))->_id)),a1);R=((T0*)n);}return R;}T6 ZlZ(T0*a1){T6 R=0;
return R;}T2 ZmZ(Zd2*C){T2 R=0;ZaZ(C);return R;}T0*ZnZ(Zd2*C,T0*a1){T0*R=Zo;T0*ZoZ=Zo;T0*ZpZ=Zo;T0*ZqZ=Zo;if((((C)->Z4c))==((void*)(Zo))){
(C->Z4c)=a1;R=((T0*)(C));ZoZ=ZPH();if((ZiH(ZoZ))==((void*)(Zo))){Z5G(((C)->ZCb));Z9Z(Z1G(84,"Inside a procedure, a Precursor call must be a procedure call (not a function call)."));
}ZpZ=ZcZ(C,ZoZ);ZqZ=ZjZ(((((ZQ7*)ZoZ))->Zpc),ZpZ);(C->Z3c)=ZjD(((ZR6*)((((ZZ3*)(Z_G(a1)))->Ztg))),ZqZ);if((((C)->Z3c))==((void*)(Zo))){
{Zg7*n=((Zg7*)Zh(sizeof(*n)));*n=ZVj;ZrZ(n,a1,ZqZ,ZpZ);(C->Z3c)=((T0*)n);}}ZhZ(C,a1);}else{{Zd2*n=((Zd2*)Zh(sizeof(*n)));*n=ZBd;Z8Z(n,((C)->ZCb),((C)->ZAd),((C)->ZFb));
R=((T0*)n);}R=ZnZ(((Zd2*)R),a1);}return R;}T0*ZsZ(Zd2*C){T0*R=Zo;T0*ZyL=Zo;T0*ZjL=Zo;if((((C)->Z3c))!=((void*)(Zo))){ZyL=Z0X(((C)->Z3c));
ZjL=ZBL(ZyL);R=ZCL(ZjL);}return R;}void ZtZ(Zd2*C){if((((C)->Z3c))!=((void*)(Zo))){ZEL(((C)->Z3c));}if((((C)->ZFb))!=((void*)(Zo))){ZGL((Za3*)(((C)->ZFb)));
}}T0*ZuZ(Zj2*C,T0*a1){T0*R=Zo;T0*ZvZ=Zo;{T81 Zow;ZwZ(&(((C)->ZEd)),(*(Zow=ZrP(a1),&Zow)));}{T0*b1=ZxZ;Zmx((T7*)(ZyZ),b1);}ZvZ=a1;if(Zo!=(ZvZ)){
switch(((T0*)ZvZ)->id){case 300:break;default:ZvZ=Zo;}}{Zq9*n=((Zq9*)Zh(sizeof(*n)));*n=Z3m;ZzZ(n,ZAZ(&(((C)->ZEd))),((((Zq9*)ZvZ))->ZFj));
R=((T0*)n);}R=ZxP(R,((C)->Z4c));return R;}void ZBZ(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));}T6 ZCZ(Zj2*C,T0*a1){
T6 R=0;T0*ZDZ=Zo;T0*ZoY=Zo;T0*ZEZ=Zo;R=((T6)((T6)((ZyW(a1))&&((T6)((ZnH(a1))==((void*)(a1)))))));if((T6)((R)&&((T6)((((C)->Z3c))!=((void*)(Zo)))))){
ZDZ=(((ZQ7*)(((C)->Z3c)))->Z4c);ZEZ=(((T85*)((((T87*)(ZsO(ZDZ)))->Zpc)))->Zse);ZoY=(((ZD8*)((((ZQ7*)(((C)->Z3c)))->Zpc)))->Zse);if((ZWJ)==((void*)(ZoY))){
R=((T6)((T6)(((T6)(((T6)(((T6)(((T6)(((ZWH)==((void*)(ZEZ)))||((T6)((Z7I)==((void*)(ZEZ))))))||((T6)((ZvI)==((void*)(ZEZ))))))||((T6)((Z3I)==((void*)(ZEZ))))))||((T6)((ZwI)==((void*)(ZEZ))))))||((T6)((ZxI)==((void*)(ZEZ)))))));
}else if((Z8J)==((void*)(ZoY))){R=((T6)((ZvI)==((void*)(ZEZ))));}else if((ZMK)==((void*)(ZoY))){R=((T6)((T6)(((T6)(((ZWH)==((void*)(ZEZ)))||((T6)((Z7I)==((void*)(ZEZ))))))||((T6)((Z3I)==((void*)(ZEZ)))))));
}else{R=((T6)(0));}}return R;}void ZFZ(T81 a1,T0*a2){Z5G(a1);{T0*b1=a2;Zmx((T7*)(Z2G),b1);}Z3G((T80*)(Z4G));}T0*ZGZ(Zj2*C){T0*R=Zo;if((((C)->ZDd))!=((void*)(Zo))){
R=ZsR(((C)->ZDd));}return R;}T0*ZHZ(Zj2*C){T0*R=Zo;if((((T43*)(ZSG))->ZRk)){R=((T0*)(C));}else{R=ZIZ(C);if((R)!=((void*)(C))){Z8H((T43*)(ZSG));
}}return R;}T0*ZJZ(Zj2*C){T0*R=Zo;if(ZIG(((C)->ZGb))){R=ZKZ(((C)->ZGb),((C)->ZCb));}else{R=((T0*)(C));}return R;}void ZLZ(Zj2*C){T0*ZEQ=Zo;
ZEQ=ZGZ(C);if((ZEQ)!=((void*)(Zo))){ZhH(((Za3*)ZEQ));}}T2 ZMZ(Zj2*C){T2 R=0;if((((C)->ZDd))!=((void*)(Zo))){R=ZNZ(((C)->ZDd));}return
R;}void ZOZ(Zj2*C){if(ZbL(((C)->ZGb))){ZgM((Z84*)(ZkH),ZPZ);}ZQZ(C,((C)->ZGb));if(ZbL(((C)->ZGb))){ZdL((Z84*)(ZkH),((T3)'\051'));}}T0*ZRZ(Zj2*C,T0*a1){
T0*R=Zo;if(Z5v((T7*)((((T85*)(ZBT(a1)))->Zse)),Z1G(10,Zsp))){Z5G(((C)->ZCb));if((((C)->ZGb))==((void*)(Zo))){{T81 Zow;Z5G((*(Zow=ZrP(a1),&Zow)));
}}{T0*b1=Z1G(146,"DICTIONARY will be deferred in SmartEiffel 2. You should use HASHED_DICTIONARY instead. This instruction will actually create a HASHED_DICTIONARY.");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));R=ZuZ(C,a1);}else if(Z5v((T7*)((((T85*)(ZBT(a1)))->Zse)),Z1G(3,"SET"))){Z5G(((C)->ZCb));if((((C)->ZGb))==((void*)(Zo))){
{T81 Zow;Z5G((*(Zow=ZrP(a1),&Zow)));}}{T0*b1=Z1G(125,"SET will be deferred in SmartEiffel 2. You should use HASHED_SET instead. This instruction will actually create a HASHED_SET.");
Zmx((T7*)(Z2G),b1);}ZPG((T80*)(Z4G));R=ZSZ(C,a1);}else{R=a1;}return R;}void ZTZ(Zj2*C){Z5G(((C)->ZCb));{T0*b1=Z1G(63,"A separate target must be an argument of the enclosing routine.");
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZUZ(Zj2*C,T81 a1,T0*a2,T0*a3){(C->ZCb)=a1;(C->ZGb)=a2;(C->ZDd)=a3;}void ZVZ(T0*a1){{T0*b1=a1;
Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}void ZWZ(Zj2*C){{T0*b1=ZAH;Zmx((T7*)(Z2G),b1);}Z5G(((C)->ZCb));Z3G((T80*)(Z4G));}void ZXZ(Zj2*C,T3
a1){if((((C)->Z3c))!=((void*)(Zo))){if((a1)==(((T3)'R'))){ZDH(((C)->Z3c),((C)->ZCb));}}}void ZYZ(Zj2*C){T0*ZEQ=Zo;ZEQ=ZGZ(C);if((ZEQ)!=((void*)(Zo))){
ZMH(((Za3*)ZEQ));}}T6 ZZZ(Zj2*C){T6 R=0;T0*ZEQ=Zo;ZEQ=ZGZ(C);if((ZEQ)!=((void*)(Zo))){R=((T6)(ZOH(((Za3*)ZEQ))));}return R;}T6 Z_Z(Zj2*C){
T6 R=0;T0*Z0_=Zo;Z0_=ZHZ(C);if((Z0_)!=((void*)(C))){R=((T6)(Z0L(Z0_)));}else if((T6)(((ZGZ(C))==((void*)(Zo)))||((T6)(Z1L((Za3*)(ZGZ(C))))))){
R=((T6)(ZCZ(C,((C)->ZGb))));}return R;}void Z1_(Zj2*C,T0*a1){T0*ZjL=Zo;T0*ZsL=Zo;T0*ZtL=Zo;ZjL=ZnH(a1);if((((T43*)(ZSG))->ZRk)){}else
if((((T87*)(ZsO(ZjL)))->Zeg)){ZMT(ZjL,Z1G(14," is deferred. "));ZBZ(((C)->ZCb),Z1G(21,"Cannot create object."));}if(Z2_(a1)){ZsL=((((C)->ZCb)).Zvb);
ZtL=ZLT((T85*)(Z3_(a1)));if((ZsL)==((void*)(ZtL))){Z5G(((C)->ZCb));{T0*b1=Z1G(38,"Creation call on formal generic type (");Zmx((T7*)(Z2G),b1);
}ZMT(a1,Z1G(2,ZKn));ZaG((T80*)(Z4G));}}if(Z3L(a1)){((((T43*)((T43*)(ZSG))))->ZXk)=(1);}ZCP((ZZ3*)(Z_G(ZjL)));}T0*ZSZ(Zj2*C,T0*a1){T0*R=Zo;
T0*ZvZ=Zo;{T81 Zow;ZwZ(&(((C)->ZEd)),(*(Zow=ZrP(a1),&Zow)));}{T0*b1=Z4_;Zmx((T7*)(ZyZ),b1);}ZvZ=a1;if(Zo!=(ZvZ)){switch(((T0*)ZvZ)->id){
case 300:break;default:ZvZ=Zo;}}{Zq9*n=((Zq9*)Zh(sizeof(*n)));*n=Z3m;ZzZ(n,ZAZ(&(((C)->ZEd))),((((Zq9*)ZvZ))->ZFj));R=((T0*)n);}R=ZxP(R,((C)->Z4c));
return R;}T6 Z5_(T0*a1){T6 R=0;return R;}void ZQZ(Zj2*C,T0*a1){T0*ZJH=Zo;T6 Z6_=0;T0*ZEQ=Zo;Z6_=((T6)(((((T89*)(ZPM))->Zaf))==(ZGs(1))));
ZJH=Z_G(((C)->ZGb));ZgM((Z84*)(ZkH),Z7_);ZDM((Z84*)(ZkH),(T11)(((((ZZ3*)ZJH))->_id)));if((((C)->Z3c))!=((void*)(Zo))){ZgM((Z84*)(ZkH),(((ZD8*)((((ZQ7*)(((C)->Z3c)))->Zpc)))->Zse));
}ZdL((Z84*)(ZkH),((T3)'\050'));if(!(Z6_)){ZgM((Z84*)(ZkH),Z8_);}ZEQ=ZGZ(C);if((ZEQ)!=((void*)(Zo))){if(!(Z6_)){ZdL((Z84*)(ZkH),((T3)'\054'));
}Z9_(((Za3*)ZEQ),ZAP(((C)->Z3c)));}ZdL((Z84*)(ZkH),((T3)'\051'));}void Za_(Zj2*C,T0*a1){T0*Z5O=Zo;T0*Zb_=Zo;T0*Zc_=Zo;T0*ZEQ=Zo;T2 Zd_=0;
T0*Ze_=Zo;T0*ZJH=Zo;T0*Zf_=Zo;ZJH=Z_G(a1);if((((C)->ZDd))==((void*)(Zo))){(C->Z3c)=Zg_(((ZZ3*)ZJH));if((((C)->Z3c))!=((void*)(Zo))){}
else if(((((T87*)(ZsO(a1)))->Zmg))!=(Zo)){{T0*b1=Z1G(27,"Creation clause exists for ");Zmx((T7*)(Z2G),b1);}ZMT(a1,Z1G(2,ZPn));ZFZ(((C)->ZCb),Z1G(27,"You must use a constructor."));
}}else{Z5O=(((ZP6*)(((C)->ZDd)))->Z2c);Zc_=((((((ZD8*)Z5O))->ZCb)).Zvb);Zb_=ZsO(a1);if(Zh_(a1)){Z5O=Zi_(((T87*)Zb_),Zc_,Z5O);if((Z5O)==((void*)(Zo))){
Z5O=(((ZP6*)(((C)->ZDd)))->Z2c);Zj_(Z5O);{T0*b1=Z1G(20," Type to create is \"");Zmx((T7*)(Z2G),b1);}{T0*b1=Z9G(a1);Zmx((T7*)(Z2G),b1);
}ZVZ(Zk_);}}(C->Z3c)=ZyP(((ZZ3*)ZJH),Z5O);if((((C)->Z3c))==((void*)(Zo))){Zl_(C,Z5O);}else{Zf_=Z0X(((C)->Z3c));Zm_(Z0X(((C)->Z3c)),((((ZD8*)Z5O))->ZCb));
}if((((T43*)(ZSG))->ZRk)){}else if(!(Zn_((T87*)(((((ZZ3*)ZJH))->Zvb)),Z5O))){Z5G((((ZD8*)((((ZP6*)(((C)->ZDd)))->Z2c)))->ZCb));Z5G(((((ZD8*)Z5O))->ZCb));
{T0*b1=((((ZD8*)Z5O))->Zse);Zmx((T7*)(Z2G),b1);}{T0*b1=Z1G(32," is not in the creation list of ");Zmx((T7*)(Z2G),b1);}ZMT(a1,Z0O);ZaG((T80*)(Z4G));
}Zo_((ZZ3*)((((ZQ7*)(((C)->Z3c)))->Znf)),Z_G(((C)->Z4c)));if((ZiH(((C)->Z3c)))!=((void*)(Zo))){{T81 Zow;Z5G((*(Zow=Z8G(((C)->Z3c)),&Zow)));
}Z5G(((((ZD8*)Z5O))->ZCb));ZVZ(ZpY);}Zd_=ZMZ(C);if((Z3)((Zd_)>(ZGs(0)))){ZEQ=Z1H((Za3*)(ZGZ(C)),((C)->Z4c));if((ZEQ)==((void*)(Zo))){
{T81 Zow;ZFZ((*(Zow=Z2H((Za3*)(ZsR(((C)->ZDd)))),&Zow)),ZiZ);}}}{T81 Zow;ZpG((*(Zow=Zp_(((C)->ZDd)),&Zow)),ZEQ,((C)->Z3c));}Ze_=((C)->ZCd);
if((Ze_)==((void*)(Zo))){Ze_=(((ZP6*)(((C)->ZDd)))->Z1c);}(C->ZDd)=Zq_(((C)->ZDd),((C)->Z4c),Ze_,ZEQ,((C)->Z3c));}}T2 Zr_(Zj2*C){T2 R=0;
ZWZ(C);return R;}T0*Zs_(Zj2*C,T0*a1){T0*R=Zo;T0*ZJH=Zo;if((((C)->Z4c))==((void*)(Zo))){(C->Z4c)=a1;Zt_(C);Z1_(C,((C)->ZGb));Za_(C,((C)->ZGb));
R=ZHZ(C);ZJH=Z_G(((C)->ZGb));if(!(ZIG(((((ZZ3*)ZJH))->Z4c)))){Zu_(((ZZ3*)ZJH),((C)->Z3c));}}else{{Zj2*n=((Zj2*)Zh(sizeof(*n)));*n=ZFd;
ZUZ(n,((C)->ZCb),((C)->ZGb),((C)->ZDd));R=((T0*)n);}R=ZyH(R,a1);}return R;}T0*ZIZ(Zj2*C){T0*R=Zo;if(ZIG(((C)->ZGb))){R=ZKZ(((C)->ZGb),((C)->ZCb));
}else{R=((T0*)(C));}return R;}T0*Zv_(Zj2*C){T0*R=Zo;R=ZsO(((C)->ZGb));return R;}void Zw_(Zj2*C){if((ZGZ(C))!=((void*)(Zo))){ZGL((Za3*)(ZGZ(C)));
}}void Zl_(Zj2*C,T0*a1){Z5G((((ZD8*)((((ZP6*)(((C)->ZDd)))->Z2c)))->ZCb));Z5G(((((ZD8*)a1))->ZCb));ZVZ(Z1G(29,"Creation procedure not found."));
}void Zt_(Zj2*C){T0*ZxH=Zo;T0*Zx_=Zo;ZxH=ZxP(((C)->ZGb),((C)->Z4c));if((T6)(((ZxH)==((void*)(Zo)))||((T6)(!(ZyW(ZxH)))))){{T81 Zow;Z5G((*(Zow=ZrP(((C)->ZGb)),&Zow)));
}ZVZ(Z1G(22,"Invalid explicit type."));}else{(C->ZGb)=ZRZ(C,ZxH);}if((((C)->ZCd))!=((void*)(Zo))){Zx_=ZGH(((C)->ZCd));if(!(ZJG(((C)->ZGb),Zx_))){
ZVZ(Z1G(24," Bad explicit type mark."));}if((Z9G(((C)->ZGb)))!=((void*)(Z9G(Zx_)))){{T81 Zow;Zy_((*(Zow=ZrP(((C)->ZGb)),&Zow)),((C)->ZGb),Zx_);
}}}}T0*Zz_=Zo;T0*ZA_=Zo;int ZB_=0;T0*ZC_(void){if(ZB_==0){ZB_=1;{{T47*n=((T47*)Zh(sizeof(*n)));*n=M47;ZA_=((T0*)n);ZtD(n,(T2)(Zxt(2048)));
}}}return ZA_;}T0*ZD_=Zo;int ZE_=0;T0*ZF_(void){if(ZE_==0){ZE_=1;{{T51*n=((T51*)Zh(sizeof(*n)));*n=M51;ZD_=((T0*)n);ZG_(n);}}}return ZD_;
}T10 ZH_(T42*C,T0*a1){T10 R=0;T81 Z4W={Zo,Zo,0};if(ZrD((T47*)(ZC_()),a1)){R=ZmD((T47*)(ZC_()),a1);}else if((((C)->ZKd))==(Zxt(32764))){
{T0*b1=ZI_;Zmx((T7*)(Z2G),b1);}{T2 b1=(T2)(Zxt(32764));Z6t(b1,Z2G);}{T0*b1=ZJ_;Zmx((T7*)(Z2G),b1);}ZaG((T80*)(Z4G));}else{(C->ZKd)=(Z2)(((((C)->ZKd)))+(ZGs(1)));
R=((C)->ZKd);ZsD((T47*)(ZC_()),R,a1);}return R;}void ZK_(T42*C){ZnD((T47*)(ZC_()),(T10)(ZGs(0)),ZjI);ZnD((T47*)(ZC_()),(T10)(ZGs(1)),ZbI);
ZnD((T47*)(ZC_()),(T10)(ZGs(2)),ZeI);ZnD((T47*)(ZC_()),(T10)(ZGs(2)),ZdI);ZnD((T47*)(ZC_()),(T10)(ZGs(3)),Z1I);ZnD((T47*)(ZC_()),(T10)(ZGs(4)),ZrI);
ZnD((T47*)(ZC_()),(T10)(ZGs(4)),ZqI);ZnD((T47*)(ZC_()),(T10)(ZGs(5)),Z4I);ZnD((T47*)(ZC_()),(T10)(ZGs(5)),ZsI);ZnD((T47*)(ZC_()),(T10)(ZGs(6)),Z_H);
ZnD((T47*)(ZC_()),(T10)(ZGs(7)),ZvI);ZnD((T47*)(ZC_()),(T10)(ZGs(8)),ZlI);ZnD((T47*)(ZC_()),(T10)(ZGs(9)),ZOK);ZnD((T47*)(ZC_()),(T10)(ZGs(10)),ZcI);
ZnD((T47*)(ZC_()),(T10)(ZGs(11)),ZfI);(C->ZKd)=ZGs(11);if(!((((T43*)(ZSG))->ZTk))){ZL_(C);}}void ZL_(T42*C){T3 Zex=0;T0*ZM_=Zo;T10 ZN_=0;
T10 ZO_=0;T0*ZP_=Zo;T1 Zdx=0;T2 ZQ_=0;ZQ_=(T2)(((C)->ZKd));{T44*n=((T44*)Zh(sizeof(*n)));*n=M44;ZP_=((T0*)n);}ZR_((T38*)(ZS_()),ZP_,ZT_((T51*)(ZF_())));
if((((((T44*)ZP_))->Ztc))!=(Zo)){if(((((T44*)ZP_))->ZRh)){Zdx=ZGs(6);}while(!((Z1)((Zdx)>(ZGs(4))))){ZU_(((T44*)ZP_));if(((((T44*)ZP_))->ZRh)){
Zdx=ZGs(5);}else{Zex=((((T44*)ZP_))->ZQh);}{int z1=Zdx;switch(z1){case 0:{int z2=Zex;switch(z2){case 9:case 10:case 13:case 32:break;
case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZN_=(T10)(ZJs(Zex));Zdx=ZGs(1);break;default:;Zdx=ZGs(6);
}}break;case 1:{int z2=Zex;switch(z2){case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:ZN_=(Z2)((((Z2)(((ZN_))*(ZGs(10)))))+((T10)(ZJs(Zex))));
break;case 34:ZM_=Zz_;((((T7*)(((T7*)ZM_))))->Zdc)=(ZGs(0));Zdx=ZGs(3);break;case 9:case 32:Zdx=ZGs(2);break;default:;Zdx=ZGs(6);}}break;
case 2:{int z2=Zex;switch(z2){case 34:ZM_=Zz_;((((T7*)(((T7*)ZM_))))->Zdc)=(ZGs(0));Zdx=ZGs(3);break;case 9:case 10:case 13:case 32:break;
default:;Zdx=ZGs(6);}}break;case 3:{int z2=Zex;switch(z2){case 34:ZO_=(Z2)(((ZO_))+(ZGs(1)));if((Z3)(((T2)(ZN_))>(ZQ_))){ZM_=(((void)((T27*)(ZV_()))),ZCG(ZM_));
ZnD((T47*)(ZC_()),ZN_,ZM_);(C->ZKd)=ZCt(((C)->ZKd),ZN_);}Zdx=ZGs(4);break;case 9:case 10:case 13:Zdx=ZGs(6);break;default:;Zgt(((T7*)ZM_),Zex);
}}break;case 4:{int z2=Zex;switch(z2){case 35:Zdx=ZGs(0);break;}}break;}}}ZW_(((T44*)ZP_));if((Zdx)==(ZGs(6))){ZvP((T38*)(ZS_()),Z1G(27,"Corrupted *.id file (after "));
ZSP((T38*)(ZS_()),(T2)(ZO_));ZvP((T38*)(ZS_()),Z1G(17," correct items).\n"));}ZvP((T38*)(ZS_()),ZX_);ZSP((T38*)(ZS_()),(T2)(((C)->ZKd)));
ZvP((T38*)(ZS_()),ZY_);}}T0*ZS_(void){if(ZeP==0){ZeP=1;{{T38*n=((T38*)Zh(sizeof(*n)));*n=M38;ZdP=((T0*)n);}}}return ZdP;}T0*ZV_(void){
if(ZTH==0){ZTH=1;{{T27*n=((T27*)Zh(1));ZSH=((T0*)n);ZUH(ZVH);ZUH(ZWH);ZUH(ZXH);ZUH(ZYH);ZUH(ZZH);ZUH(Z_H);ZUH(Z0I);ZUH(Z1I);ZUH(Z2I);
ZUH(Z3I);ZUH(Z4I);ZUH(Z5I);ZUH(Z6I);ZUH(Z7I);ZUH(Z8I);ZUH(Z9I);ZUH(ZaI);ZUH(ZbI);ZUH(ZcI);ZUH(ZdI);ZUH(ZeI);ZUH(ZfI);ZUH(ZgI);ZUH(ZhI);
ZUH(ZiI);ZUH(ZjI);ZUH(ZkI);ZUH(ZlI);ZUH(ZmI);ZUH(ZnI);ZUH(ZoI);ZUH(ZpI);ZUH(ZqI);ZUH(ZrI);ZUH(ZsI);ZUH(ZtI);ZUH(ZuI);ZUH(ZvI);ZUH(ZwI);
ZUH(ZxI);ZUH(ZyI);ZUH(ZzI);ZUH(ZAI);ZUH(ZBI);ZUH(ZCI);ZUH(ZDI);ZUH(ZEI);ZUH(ZFI);ZUH(ZGI);ZUH(ZHI);ZUH(ZII);ZUH(ZJI);ZUH(ZKI);ZUH(ZLI);
ZUH(ZMI);ZUH(ZNI);ZUH(ZOI);ZUH(ZPI);ZUH(ZQI);ZUH(ZAG);ZUH(ZzG);ZUH(ZRI);ZUH(ZyG);ZUH(ZxG);ZUH(ZuG);ZUH(ZSI);ZUH(ZvG);ZUH(ZTI);ZUH(ZUI);
ZUH(ZVI);ZUH(ZWI);ZUH(ZXI);ZUH(ZtG);ZUH(ZYI);ZUH(ZZI);ZUH(Z_I);ZUH(Z0J);ZUH(Z1J);ZUH(Z2J);ZUH(ZvH);ZUH(Z3J);ZUH(Z4J);ZUH(Z5J);ZUH(Z6J);
ZUH(Z7J);ZUH(Z8J);ZUH(Z9J);ZUH(ZaJ);ZUH(ZbJ);ZUH(ZcJ);ZUH(ZdJ);ZUH(ZeJ);ZUH(ZfJ);ZUH(ZgJ);ZUH(ZhJ);ZUH(ZiJ);ZUH(ZjJ);ZUH(ZkJ);ZUH(ZlJ);
ZUH(ZmJ);ZUH(ZnJ);ZUH(ZoJ);ZUH(ZpJ);ZUH(ZqJ);ZUH(ZrJ);ZUH(ZsJ);ZUH(ZtJ);ZUH(ZuJ);ZUH(ZvJ);ZUH(ZwJ);ZUH(ZxJ);ZUH(ZyJ);ZUH(ZzJ);ZUH(ZAJ);
ZUH(ZBJ);ZUH(ZCJ);ZUH(ZDJ);ZUH(ZEJ);ZUH(ZFJ);ZUH(ZGJ);ZUH(ZHJ);ZUH(ZIJ);ZUH(ZJJ);ZUH(ZKJ);ZUH(ZLJ);ZUH(ZMJ);ZUH(ZNJ);ZUH(ZOJ);ZUH(ZwG);
ZUH(ZPJ);ZUH(ZQJ);ZUH(ZRJ);ZUH(ZSJ);ZUH(ZTJ);ZUH(ZUJ);ZUH(ZVJ);ZUH(ZWJ);ZUH(ZXJ);ZUH(ZYJ);ZUH(ZZJ);ZUH(Z_J);ZUH(Z0K);ZUH(Z1K);ZUH(Z2K);
ZUH(Z3K);ZUH(Z4K);ZUH(Z5K);ZUH(Z6K);ZUH(Z7K);ZUH(Z8K);ZUH(Z9K);ZUH(ZaK);ZUH(ZbK);ZUH(ZcK);ZUH(ZdK);ZUH(ZeK);ZUH(ZfK);ZUH(ZgK);ZUH(ZhK);
ZUH(ZiK);ZUH(ZjK);ZUH(ZkK);ZUH(ZlK);ZUH(ZmK);ZUH(ZnK);ZUH(ZoK);ZUH(ZpK);ZUH(ZqK);ZUH(ZrK);ZUH(ZsK);ZUH(ZtK);ZUH(ZuK);ZUH(ZvK);ZUH(ZwK);
ZUH(ZxK);ZUH(ZyK);ZUH(ZzK);ZUH(ZAK);ZUH(ZBK);ZUH(ZCK);ZUH(ZDK);ZUH(ZEK);ZUH(ZFK);ZUH(ZGK);ZUH(ZHK);ZUH(ZIK);ZUH(ZJK);ZUH(ZKK);ZUH(ZLK);
ZUH(ZMK);ZUH(ZXH);ZUH(ZNK);ZUH(ZOK);ZUH(ZPK);ZUH(ZQK);ZUH(ZRK);ZUH(ZSK);ZUH(ZTK);ZUH(ZUK);ZUH(ZVK);ZUH(ZWK);ZUH(ZXK);ZUH(ZYK);ZUH(ZZK);
}}}return ZSH;}T0*ZZ_(T10 a1){T0*R=Zo;R=ZpD((T47*)(ZC_()),a1);return R;}
#ifdef __cplusplus
}
#endif

