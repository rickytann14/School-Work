clear all
close all
t=0:.00001:0.01;
x=3*sin(600*pi*t)+4*cos(4000*pi*t);
subplot(2,3,1)
plot(t,x);
title('A. Original Signal');
grid on;

%%Frequency response of the samples
subplot(2,3,2);
x_fft=abs(fft(x, 1024));
plot(x_fft)
title('C. Frequency Spectrum of Original Signal');

%%sampling at 100Hz
subplot(2,3,3)
Fs=100; %%Fs is the sampling reate
Ts=1/Fs; %%Fs is teh sampling frequency
delta=zeros(1, length(t));
delta(mod(t,Ts)==00)=1; %%sampling signal
x_s=x.*delta; %%multiple with impulse train, train on 1's and 0's
x_s=x_s(x_s~=0); %%pick samples that are non-zeros
stem(0:length(x_s)-1, x_s);
title('B. Sampled Signal at 100Hz');
grid on;

%% Signal through low pass filter
%%x=3*sin(600*pi*t)+4*cos(4000*pi*t); %%original signal
subplot(2,3,4);
plot(x)
title('D. Low pass filter Signal');
x_fft=(fft(x,512)); %%frequency spectrum

x_fft(500:512)=0; %%supress high band
x_rec=(ifft(x_fft, 1024)); %%get the time respose back
subplot(2,3,5);
plot(abs(x_rec));
title('E. Filtered Signal');
