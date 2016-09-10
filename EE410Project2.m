% Mark Lawrence Galvan
% Project 2: Finding Total Harmonic Distortion of a Periodic Signal

% imports the given signal onto the MATLAB workspace
load('signal');
% creates time vector 
time = z(:,1);
% creates magnitude vector 
mag = z(:,2);
% calculates the omega w 
w = (2*pi)/(T);
% calculates the period
T = (time(end) - time(1));
% Calculating the fundamental harmonic
d = [];% creates an empty matrix
f = mag.*exp(-1i*w*1.*time);
d(1,1) = (trapz(time,f))/T;
n = 1;
% calculating all the harmonics with magnitude
% greater than 0.00001% of the fundamental harmonic
while (abs(d(1,n))>(.000001)*(abs(d(1,1))))
    n = n + 1;
    f1 = mag.*(exp(-1i*w*n.*time));
    d(1,n) = (trapz(time,f1))/T;  
end
thd_num = 0; 
k = 2;
% calculating the denominator as a whole
thd_den = (abs(d(1,1)))^2;
% calculating the numerator as a whole

for i = 2:n
    thd_num = (abs(d(1,i)))^2 + thd_num;
end
 

% Applying the Audio Engineer's THD formula
thd = sqrt(thd_num/thd_den)
thd_final = (thd)*(100);
sprintf('Total Harmonic Distortion is: %g percent' ,thd_final)
