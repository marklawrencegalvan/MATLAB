% Name: Mark Lawrence Galvan (818661916)
% EE 410 - Professor Ashrafi
% April 6, 2016
% Project #1 MATLAB
 
% The signal starts at -2 to 2
T = 2-(-2);
% Dividing the time vector into 10,000 segments for 
% acceptable accuracy
step = T/10000;
% Generating the time vector "t" ending with the 
% vector interval [-2,2]
t = -2:step:2;
% -2 <= t < -1
p1 = (t>=(-2)) & (t<(-1));
% -1 <= t < 0
p2 = (t>=(-1)) & (t<0);
% 0 <= t < 1
p3 = (t>=0) & (t<1);
% 1 <= t < 2
p4 = (t>=1) & (t<2);
% Defining and plotting the signal
h_of_t = p1.*(cos((pi*t)/2))+p2.*(1+t)+p3.*(t.^3+1)+p4.*(2+sin(2*pi*t));
%figure;
%plot(t,h_of_t)
%title of the graph and labels of the axis
%title('Graph of h()t');
%xlabel('time t');
%ylabel('h(t)');

% Integration from -2 to 1
T1 = 1-(-2);
step1 = T1/10000;
t1 = -2:step1:1;
p11 = (t1>=(-2)) & (t1<(-1));
p21 = (t1>=(-1)) & (t1<0);
p31 = (t1>=0) & (t1<1);
h_of_t11 = p11.*(cos((pi*t1)/2))+p21.*(1+t1)+p31.*(t1.^3+1);
I1 = trapz(t1,h_of_t11)

% Integration from -2 to 2
T2 = 2-(-2);
step2 = T2/10000;
t2 = -2:step2:2;
p12 = (t2>=(-2)) & (t2<(-1));
p22 = (t2>=(-1)) & (t2<0);
p32 = (t2>=0) & (t2<1);
p42 = (t2>=1) & (2<=2);
h_of_t12 = p12.*(cos((pi*t2)/2))+p22.*(1+t2)+p32.*(t2.^3+1)+p42.*(2+sin(2*pi*t2));
I2 = trapz(t2,h_of_t12)

% Integration from -0.5 to 1.5
T3 = (1.5)-(-0.5);
step3 = T3/10000;
t3 = -0.5:step3:1.5;
p13 = (t3>=(-0.5)) & (t3<(0));
p23 = (t3>=(0)) & (t3<1);
p33 = (t3>=1) & (t3<=1.5);
h_of_t13 = p13.*(1+t3)+p23.*(t3.^3+1)+p33.*(2+sin(2*pi*t3));
I3 = trapz(t3,h_of_t13)

% Integration from -2 to 0
T4 = 0-(-2);
step4 = T4/10000;
t4 = -2:step4:0;
p14 = (t4>=(-2)) & (t4<(-1));
p24 = (t4>=(-1)) & (t4<=0);
h_of_t14 = p14.*(cos((pi*t4)/2))+p24.*(1+t4);
I4 = trapz(t4,h_of_t14.*cos(pi*t4))

